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

typedef QueueReplier<HelloWorldRequest, HelloWorldReply> HelloQueueReplier;

/* You can take samples and reply from the listener using on_request_available 
 * method.  */
bool USE_LISTENER_TO_REPLY = false; 


void take_requests_and_send_replies(HelloQueueReplier& replier, int* received)
{
    dds::sub::LoanedSamples<HelloWorldRequest> samples = replier.take_requests();

    for (dds::sub::LoanedSamples<HelloWorldRequest>::iterator sample_it = samples.begin();
            sample_it != samples.end();
            ++sample_it) 
    {
        if (sample_it->info().valid()) {
            if (++(*received) % 1000 == 0) {
                std::cout << "Received request "  << sample_it->data().messageId() <<
                             ", sending reply" << std::endl;
            }
            replier.acknowledge_request(sample_it->info(), true);

            // Send reply
            HelloWorldReply reply; 
            reply.messageId(sample_it->data().messageId());
            reply.payload(sample_it->data().payload());

            replier.send_reply(reply, sample_it->info());                
       }
    } 
}



class HelloWorldReplierParams {
public:    
    HelloWorldReplierParams() 
      : domain_id(0),
        shared_subscriber_name("SharedSubscriber"),
        request_queue_topic_name("HelloWorldTopic"),
        profile_name(""),
        qos_library(""),
        entity_name(""),
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
        std::cout << "\t-v                         Verbose mode. default: No verbose mode" <<  std::endl;
    }  
    
    int domain_id;
    std::string shared_subscriber_name;
    std::string request_queue_topic_name;
    std::string profile_name;
    std::string qos_library;
    std::string entity_name;
    bool verbose;
};



class HelloReplierListener: public QueueReplierListener<HelloWorldRequest, HelloWorldReply> {
public:
    int acknowledged;
    int accepted;
    int rejected;
    int request_instances;
    int reply_instances;
    int received;
    
    HelloReplierListener()
      : acknowledged(0),
        accepted(0),
        rejected(0),
        request_instances(0),
        reply_instances(0),
        received(0)
    {
 
    }
    
    ~HelloReplierListener()
    {
        
    }

  void on_reply_acknowledged(
        HelloQueueReplier& replier, 
        const rti::pub::AcknowledgmentInfo &info) 
    {
        if (is_positive_ack(info.response_data())) {
            accepted++;
        } else {
            rejected++;
        }
        acknowledged++;
    }
    

    void on_request_available(
        HelloQueueReplier& replier) 
    {
        if (USE_LISTENER_TO_REPLY) {
            take_requests_and_send_replies(replier, &received);
        }
    }
    
    void on_request_shared_reader_queue_matched(
        HelloQueueReplier& replier,
        const dds::core::status::SubscriptionMatchedStatus& status)
    {
        request_instances++;
        std::cout << "Queuing Service request queue discovered."  << std::endl;
    }
    
    void on_reply_shared_reader_queue_matched(
        HelloQueueReplier& replier,
        const dds::core::status::PublicationMatchedStatus& status) 
    {
        reply_instances++;
        std::cout << "Queuing Service reply queue discovered."  << std::endl;
    }
};


void publisher_main(HelloWorldReplierParams& params)
{        
    // Retrieve domain participant QoS
    dds::domain::qos::DomainParticipantQos participant_qos = 
            QosProvider::Default()->participant_qos(
                params.qos_library + "::" + params.profile_name);
    
    // Create the participant
    dds::domain::DomainParticipant participant(params.domain_id, participant_qos);
    
    // Create replier parameters
    QueueReplierParams params_reply(participant);
    params_reply.request_topic_name(params.request_queue_topic_name)
               .shared_subscriber_name(params.shared_subscriber_name)
               .qos_profile(params.qos_library, params.profile_name)
               .entity_name(params.entity_name);
    
    // Create a disabled queue replier bound to a listener
    HelloReplierListener replier_listener; 
    HelloQueueReplier replier(params_reply, false); 
    rti::core::ListenerBinder<HelloQueueReplier> replier_listener_binder =
        rti::core::bind_listener(
           replier,
           &replier_listener); 
    
    // Enable queue replier 
    replier->enable();
    
    // Wait until discovering a Queuing Service
    std::cout << "Waiting to discover Queuing Service .." << std::endl;
    while (!replier.has_matching_request_reader_queue() ||
           !replier.has_matching_reply_reader_queue())
    {
        rti::util::sleep(Duration(1));
    }
    std::cout << "Queuing Service discovered .."  << std::endl;

    int received = 0;
    while (true)
    {
        if (USE_LISTENER_TO_REPLY) {
            rti::util::sleep(Duration(5));
            received = replier_listener.received;
        } else {
            replier.wait_for_requests(Duration(5));
            take_requests_and_send_replies(replier, &received);
        }
    }
}

int main(int argc, char *argv[])
{
    HelloWorldReplierParams params;

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
        std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

