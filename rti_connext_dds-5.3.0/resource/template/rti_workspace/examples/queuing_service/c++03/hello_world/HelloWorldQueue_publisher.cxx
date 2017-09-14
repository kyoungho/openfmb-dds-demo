/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <iterator>

#include <rti/util/util.hpp> // for sleep()
#include <rti/config/Logger.hpp> // verbosity
#include <rti/core/ListenerBinder.hpp>

#include <rti/queuing/rtiqueuing.hpp> // single include for all the queuing API

#include "HelloWorldQueue.hpp"

using namespace rti::queuing;
using namespace dds::core;

typedef QueueRequester<HelloWorldRequest, HelloWorldReply> HelloQueueRequester;

#define MINIMUM_SLEEPING_TIME_MSEC 15  

/* You can take and acknowledge samples from the listener using on_reply_available 
 * method. */
bool USE_LISTENER_TO_ACKNOWLEDGE_SAMPLES = true; 


double get_throughput(
        dds::domain::DomainParticipant participant, 
        int messages, 
        dds::core::Time start_time) 
{
    dds::core::Time time = participant.current_time();
    return 1000.0 * ((double) messages) / ((double) (time-start_time).to_millisecs());
}

void set_burst_size_and_sleep_time_msec(
    int * burst_size,
    double * sleep_time_msec,
    double sample_rate,
    double burst_time)  
{
    /* The relation: 
     *      sample_rate = burst_size * (1000 / (sleep_time_msec + burst_time))
     * applies with the constraint that the sleep time should not be 
     * shorter than MINIMUM_SLEEPING_TIME_MSEC */
    
    *sleep_time_msec = (1000.0 / sample_rate) - burst_time;

    if (*sleep_time_msec < (double) MINIMUM_SLEEPING_TIME_MSEC) {
        *sleep_time_msec = (double) MINIMUM_SLEEPING_TIME_MSEC;
        *burst_size = (sample_rate *
                      (burst_time + (double) MINIMUM_SLEEPING_TIME_MSEC) / 1000.0);
    } else {
        *burst_size = 1;
    }
}


class HelloWorldRequesterParams {
public:    
    HelloWorldRequesterParams() 
      : domain_id(0),
        shared_subscriber_name("SharedSubscriber"),
        request_queue_topic_name("HelloWorldTopic"),
        request_count(0),  // infinite loop
        sample_rate(1000),  // messages / second
        payload_size(32),
        profile_name(""),
        qos_library(""),
        entity_name("") ,
        wait_for_ack(true),
        discovery_time(0),
        verbose(false)
    {
        
    }
      
    void print_usage() 
    {
        std::cout << "Usage: " <<  std::endl;
        std::cout << "\t-d <domainId>              default: 0" <<  std::endl;
        std::cout << "\t-e <entityName>            default: <none>" <<  std::endl;
        std::cout << "\t-r <sharedSubscriberName>  default: SharedSubscriber" <<  std::endl;
        std::cout << "\t-q <requestQueueTopicName> default: HelloWorldTopic" <<  std::endl;
        std::cout << "\t-p <qosProfileName>        default: <none>" <<  std::endl;
        std::cout << "\t-c <requestCount>          default: 0 - UNLIMITED -" <<  std::endl;
        std::cout << "\t-s <requestPerSecond>      default: 1000" <<  std::endl;
        std::cout << "\t-l <requestPayloadLength>  default: 32" <<  std::endl;
        std::cout << "\t-g                         Use generated type. default: Use Built-in Octets" <<  std::endl;
        std::cout << "\t-a <waitForAck>            default: 1" <<  std::endl;
        std::cout << "\t-v                         Verbose mode. default: No verbose mode" <<  std::endl;
    }  
    
    int domain_id;
    std::string shared_subscriber_name;
    std::string request_queue_topic_name;
    int request_count;
    double sample_rate;
    int payload_size;
    std::string profile_name;
    std::string qos_library;
    std::string entity_name;
    bool wait_for_ack;
    int discovery_time;
    bool verbose;
};




typedef dds::sub::LoanedSamples<HelloWorldReply>  LoanedReplySamples;


void receive_and_acknowledge_samples(HelloQueueRequester& requester, int* received) 
{
    LoanedReplySamples samples = requester.take_replies();

    for (LoanedReplySamples::iterator sample_it = samples.begin();
         sample_it != samples.end(); ++sample_it) 
    {
        if (sample_it->info().valid()) {
            requester.acknowledge_reply(sample_it->info(), true);

            if (*received % 1000 == 0) {
                std::cout << "Received reply " <<
                              sample_it->data().messageId() <<  std::endl;
            }
            ++(*received);
        }
    } 
}


class HelloRequesterListener: public QueueRequesterListener<HelloWorldRequest, HelloWorldReply> {
public:
    int acknowledged;
    int accepted;
    int rejected;
    int request_instances;
    int reply_instances;
    int received;
    
    HelloRequesterListener()
      : acknowledged(0),
        accepted(0),
        rejected(0),
        request_instances(0),
        reply_instances(0),
        received(0)
    {
 
    }
    
    ~HelloRequesterListener()
    {
        
    }

    void on_request_acknowledged(
        HelloQueueRequester& requester, 
        const rti::pub::AcknowledgmentInfo &info) 
    {
        if (is_positive_ack(info.response_data())) {
            accepted++;
        } else {
            rejected++;
        }  
        acknowledged++;
    }
    

    void on_reply_available(
        HelloQueueRequester& requester) 
    {
        if (USE_LISTENER_TO_ACKNOWLEDGE_SAMPLES) {
            receive_and_acknowledge_samples(requester, &received);
        }
    }


    void on_request_shared_reader_queue_matched(
        HelloQueueRequester& requester,
        const dds::core::status::PublicationMatchedStatus& status) 
    {
        request_instances++;
        std::cout << "Queuing Service request queue discovered."  << std::endl;
    }
    
    void on_reply_shared_reader_queue_matched(
        HelloQueueRequester& requester,
        const dds::core::status::SubscriptionMatchedStatus& status)
    {
        reply_instances++;
        std::cout << "Queuing Service reply queue discovered."  << std::endl;
    }
};




void publisher_main(HelloWorldRequesterParams& params)
{        
    // Retrieve domain participant QoS
    dds::domain::qos::DomainParticipantQos participant_qos = 
            QosProvider::Default()->participant_qos(
                params.qos_library + "::" + params.profile_name);
    
    // Create the participant
    dds::domain::DomainParticipant participant(params.domain_id, participant_qos);
    
    // Create requester parameters
    QueueRequesterParams params_request(participant);
    params_request.request_topic_name(params.request_queue_topic_name)
                  .shared_subscriber_name(params.shared_subscriber_name)
                  .qos_profile(params.qos_library, params.profile_name)
                  .entity_name(params.entity_name)
                  .enable_wait_for_ack(params.wait_for_ack);
    
    // Create a disabled queue requester bound to a listener
    HelloRequesterListener requester_listener; 
    HelloQueueRequester requester(params_request, false); 
    rti::core::ListenerBinder<HelloQueueRequester> requester_listener_binder =
        rti::core::bind_listener(
           requester,
           &requester_listener); 
    
    // Enable queue requester 
    requester->enable();
    
    // Wait until discovering a Queuing Service
    std::cout << "Waiting to discover Queuing Service .." << std::endl;
    while (!requester.has_matching_request_reader_queue() ||
           !requester.has_matching_reply_reader_queue())
    {
        rti::util::sleep(Duration(1));
    }
    std::cout << "Queuing Service discovered .."  << std::endl;
   
    // Calculate initial burst size and sleep time
    int burst_size; // messages sent between two sleep periods
    double sleep_time_msec; 
    double burst_time = 0;
    set_burst_size_and_sleep_time_msec(
            &burst_size, &sleep_time_msec, params.sample_rate, burst_time);
    
    // Create request sample 
    HelloWorldRequest request_sample;
    
    // Set payload size
    request_sample.payload().resize(params.payload_size);
    
    // Send requests
    int received = 0;
    int count;
    dds::core::Time start_time = participant.current_time();
    std::cout << "Sending... " << std::endl;
    for (count = 0; count < params.request_count || params.request_count == 0; count++) {
        // Modify the data to be written here
        request_sample.messageId(count);
        // Send a sequence with payload_size octet elements, each element equal to count % 256
        request_sample.payload(std::vector<u_char>(params.payload_size, count % 256));
        
        // Print count and tune up throughput each 1000 samples
        if (count % 1000 == 0) {
            std::cout << "Sent requests " << count  << std::endl;
            // tune up to achieve desired throughput
            double sample_rate = 
                    get_throughput(participant, received, start_time);
            if (sample_rate > 0) {
                burst_time += (sample_rate < params.sample_rate)? 1 : -1;
                
                set_burst_size_and_sleep_time_msec(
                        &burst_size, &sleep_time_msec, params.sample_rate, burst_time);
            }
        }
        
        // Send request message
        requester.send_request(request_sample);
        
        // Wait for acknowledgments 
        if (params.wait_for_ack) {
            if ((requester_listener.acknowledged < count - 20)) {
                try {
                    requester.wait_for_acknowledgments(
                        dds::core::Duration::from_millisecs(MINIMUM_SLEEPING_TIME_MSEC));
                } catch (...) {}
            }
        }
        
        if (USE_LISTENER_TO_ACKNOWLEDGE_SAMPLES) {
            received = requester_listener.received;
        } else {
            receive_and_acknowledge_samples(requester, &received);
        }
        
        // Sleep
        if (count % burst_size == 0) 
        {
            rti::util::sleep(dds::core::Duration::from_millisecs(sleep_time_msec));
        }
    }
    
    
    // Calculate send throughput 
    std::cout << "Actual send throughput: " << count << " " <<
            get_throughput(participant, count, start_time) << " msg/s" <<
            std::endl;
    
    
    // wait for the remaining replays
    std::cout << "Waiting for all the replies .." << std::endl;
    while (received < requester_listener.accepted)
    {
        if (USE_LISTENER_TO_ACKNOWLEDGE_SAMPLES) {
            received = requester_listener.received;
        } else {
            receive_and_acknowledge_samples(requester, &received);
        }
        
        rti::util::sleep(Duration(1));
    }
    
    // Calculate send throughput 
    std::cout << "Actual round trip throughput: " << 
            get_throughput(participant, count, start_time) << " msg/s" << std::endl;
}

int main(int argc, char *argv[])
{
    HelloWorldRequesterParams params;
    
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i],"-d")) {
            if (i == argc-1) {
                std::cout << "Expected <domainId>"  << std::endl;
                params.print_usage();
                return -1;
            }
            params.domain_id = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-e")) {
            if (i == argc-1) {
                std::cout << "Expected <entityName>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.entity_name = argv[++i];  
        } else if (!strcmp(argv[i],"-r")) {
            if (i == argc-1) {
                std::cout << "Expected <sharedSubscriberName>>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.shared_subscriber_name = argv[++i];    
        } else if (!strcmp(argv[i],"-q")) {
            if (i == argc-1) {
                std::cout << "Expected <requestQueueTopicName>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.request_queue_topic_name = argv[++i];
        } else if (!strcmp(argv[i],"-c")) {
            if (i == argc-1) {
                std::cout << "Expected <requestCount>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.request_count = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-s")) {
            if (i == argc-1) {
                std::cout << "Expected <requestPerSecond>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.sample_rate = atof(argv[++i]);
        } else if (!strcmp(argv[i],"-l")) {
            if (i == argc-1) {
                std::cout << "Expected <samplePayloadLength>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.payload_size = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-a")) {
            if (i == argc-1) {
                std::cout << "Expected <swaitForAck>" << std::endl;
                params.print_usage();
                return -1;
            }
            params.wait_for_ack = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-v")) {
            params.verbose = true;
        } else if (!strcmp(argv[i],"-p")) {
            char profileName[128];
            char * profileNamePtr;
            
            if (i == argc-1) {
                std::cout << "Expected <qosProfileName>" << std::endl;
                params.print_usage();
                return -1;
            }
            strcpy(profileName,argv[++i]);
            profileNamePtr = strstr(profileName,"::");

            if (profileNamePtr == NULL) {
                std::cout << "Expected <qosProfileName> as <libraryName>::<profileName>" << std::endl;
                params.print_usage();
                return -1;
            }

            *profileNamePtr = 0;
            profileNamePtr+=2;

            params.profile_name = profileNamePtr;
            params.qos_library = profileName; 
        } else {
            std::cout << "Unknown option: " << argv[i] << std::endl;
            params.print_usage();
            return -1;
        }
    } 

    if (params.verbose) {
        rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);
    }

    try {
        publisher_main(params);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

