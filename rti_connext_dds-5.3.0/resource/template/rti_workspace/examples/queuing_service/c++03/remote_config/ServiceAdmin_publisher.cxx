/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <sstream>
#include <iomanip>

#include <rti/util/util.hpp> // for sleep()
#include <rti/config/Logger.hpp> // verbosity
#include <rti/core/ListenerBinder.hpp>
#include <rti/queuing/rtiqueuing.hpp> // single include for all the queuing API
#include <rti/request/rtirequest.hpp>

#include "ServiceAdmin.hpp"
#include "QueuingServiceTypes.hpp"


using namespace rti::request;
using namespace dds::core;
using namespace RTI::Service::Admin;
using namespace RTI::QueuingService::Monitoring;

unsigned int WAIT_TIMEOUT_SEC_MAX = 10;
unsigned int MAX_WAIT = 20;


class QueueParameters {
public:    
    QueueParameters() 
      : session_name("Session"),
        topic_name("HelloWorldTopic"),      
        type_name("HelloWorldRequest"),   
        reply_type_name("HelloWorldReply")              
    {
        
    }
      
    std::string session_name;
    std::string topic_name;
    std::string type_name;
    std::string reply_type_name;
};


class RemoteConfigParams {
public:    
    RemoteConfigParams()
        : domain_id(1),
          target_service("RemoteConfigQS"),
          qos_library("HelloWorldQueue_Library"),    
          profile_name("HelloWorldQueue_Profile"),  
          action(CommandActionKind::RTI_SERVICE_COMMAND_ACTION_CREATE),
          resource_identifier("/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber"),
          sample_selector("")         
    {
        
    }
    
    void print_usage() {
        std::cout <<  "Usage: -d <domainId> -q <serviceName> -o <profileName> [create|delete|get] <resource_identifier> {command options}" << std::endl;
        std::cout <<  "-d <domainId>     default: 1" << std::endl;
        std::cout <<  "-q <serviceName>  default: RemoteConfigQS" << std::endl;
        std::cout <<  "-o <profileName>  default: <none>" << std::endl;
        std::cout <<  "{create options}: -s <sessionName> -p <topicName> -t <typeName> -r <replyTypeName>" << std::endl;
        std::cout <<  "-s <sessionName>    default: Session" << std::endl;
        std::cout <<  "-p <topicName>      default: HelloWorldTopic" << std::endl;
        std::cout <<  "-t <typeName>       default: HelloWorld" << std::endl;
        std::cout <<  "-r <replyTypeName>  default: HelloWorld" << std::endl;
        std::cout <<  "{delete options}: <sampleSelector>" << std::endl;
        std::cout <<  "{get options}:    <sampleSelector>" << std::endl;
    }  
    
    int domain_id;
    EntityName target_service;
    std::string qos_library;
    std::string profile_name;
    CommandActionKind action;
    ResourceIdentifier resource_identifier;
    StringBody sample_selector;
    QueueParameters queue_params;
};



std::string create_queue_snippet(const QueueParameters& queue_params) 
{	
    std::ostringstream stream;
    stream << "str://\"<shared_reader_queue name=\"" << queue_params.topic_name <<
        "\" session=\"" << queue_params.session_name << "\">\n";
    stream << "<datareader_qos base_name=\"HelloWorldQS_Library::HelloWorldQS_Profile\"/>\n";
    stream << "<datawriter_qos base_name=\"HelloWorldQS_Library::HelloWorldQS_ProfileLargeData\"/>\n"; 
    stream << "<topic_name>" << queue_params.topic_name << "</topic_name>\n";
    stream << "<type_name>" << queue_params.type_name << "</type_name>\n";
    stream << "<reply_type>" << queue_params.reply_type_name << "</reply_type>\n";
    stream << "<queue_qos>\n";
    stream << "<resource_limits>\n";
    stream << "<queue_allocation_settings>\n";
    stream << "<max_count>10000</max_count>\n";
    stream << "</queue_allocation_settings>\n";
    stream << "</resource_limits>";
    stream << "<distribution>\n";       
    stream << "<kind>ROUND_ROBIN</kind>\n";
    stream << "<property>\n";
    stream << "<value>\n";
    stream << "<element>\n";
    stream << "<name>UNACKED_THRESHOLD</name>\n";
    stream << "<value>5</value>\n";
    stream << "</element>\n";
    stream << "</value>\n";
    stream << "</property>\n";
    stream << "</distribution>\n";
    stream << "<reliability>\n";
    stream << "<app_ack_sample_to_producer>1</app_ack_sample_to_producer>\n";
    stream << "</reliability>\n";
    stream << "<redelivery>\n";
    stream << "<max_delivery_retries>6</max_delivery_retries>\n";
    stream << "<response_timeout>\n";
    stream << "<duration>\n";
    stream << "<sec>30</sec>\n";
    stream << "<nanosec>0</nanosec>\n";
    stream << "</duration>\n";
    stream << "</response_timeout>\n";
    stream << "</redelivery>\n";
    stream << "</queue_qos>\n";
    stream << "</shared_reader_queue>\""; 
    return stream.str();
}

bool check_string_end(
            const std::string& full_string, 
            const std::string& ending) 
{    
    if (ending.size() > full_string.size()) { 
        return false; 
    }
    return std::equal(ending.rbegin(), ending.rend(), full_string.rbegin());
}


std::string sample_identity_to_string(
        RTI::QueuingService::SampleIdentity_t sample_identity) 
{
    std::ostringstream stream;
    stream << "writer GUID: ";
    for (int i = 0; i < 16; i++) {
        stream << std::uppercase << std::hex << std::setfill('0') 
               << std::setw(2) << (int) sample_identity.writer_guid().value()[i];
        if ((i < 15) && (i % 2 == 1)) { stream << ":"; }
    }
    stream << std::dec << "  SN: (" << sample_identity.sequence_number().high() 
           << "," << sample_identity.sequence_number().low() << ")\n"; 
    return stream.str();
}


dds::domain::DomainParticipant create_participant(
        int domain_id,
        const std::string& qos_library,
        const std::string& profile_name)
{
    dds::domain::qos::DomainParticipantQos participant_qos = 
            QosProvider::Default()->participant_qos(qos_library + "::" + profile_name);
    
    dds::domain::DomainParticipant participant(domain_id, participant_qos);
    return participant;
}


class ServiceAdminRequesterExample {
public:

    ServiceAdminRequesterExample(
        int domain_id,
        const std::string& qos_library,
        const std::string& profile_name) 
            : participant(create_participant(domain_id, qos_library, profile_name))
    {
        
    }
              
    void run_example(
            const std::string& qos_library,
            const std::string& profile_name,
            const EntityName& target_service, 
            const CommandActionKind& action,
            const ResourceIdentifier& resource_identifier,
            const StringBody& sample_selector,
            const QueueParameters& queue_params)
    { 
        // get QoS
        dds::pub::qos::DataWriterQos writer_qos =
                QosProvider::Default()->datawriter_qos(qos_library + "::" + profile_name);
        dds::sub::qos::DataReaderQos reader_qos =
                QosProvider::Default()->datareader_qos(qos_library + "::" + profile_name);
 
 
        // create requester params
        rti::request::RequesterParams requester_params(participant);
        requester_params.request_topic_name(COMMAND_REQUEST_TOPIC_NAME);
        requester_params.reply_topic_name(COMMAND_REPLY_TOPIC_NAME);
        requester_params.datareader_qos(reader_qos);
        requester_params.datawriter_qos(writer_qos);
    
        // create requester  
        rti::request::Requester<CommandRequest, CommandReply> requester(requester_params);
      
         // Wait for Queuing Service Discovery
        dds::core::status::PublicationMatchedStatus matched_status;
        unsigned int wait_count = 0;

        std::cout << "Waiting for a matching QS..." << std::endl;
        while (matched_status.current_count() < 1 && wait_count < WAIT_TIMEOUT_SEC_MAX) {
            matched_status = requester.request_datawriter().publication_matched_status();
            wait_count++;
            rti::util::sleep(Duration(1));
        }

        if (matched_status.current_count() < 1)
        {
            throw dds::core::Error("No matching QS found.");
        }
        
        CommandRequest request;
        //dds::sub::Sample<CommandRequest> request;
         
        request.service(ServiceKind::RTI_SERVICE_QUEUING_SERVICE);
        request.service_name(target_service);
        request.action(action);
        request.resource_identifier(resource_identifier); 
        
        // set the request body for the actions that require it
        if (action == CommandActionKind::RTI_SERVICE_COMMAND_ACTION_CREATE) {
            request.string_body(create_queue_snippet(queue_params));
        } else {
            request.string_body(sample_selector);
        }
        
        requester.send_request(request);
        std::cout << "Command request sent" << std::endl;
        std::cout << "		target service: " << request.service_name() << std::endl;
        std::cout << "		action: " << request.action() << std::endl;
        std::cout << "		resource: " << request.resource_identifier() << "\n" << std::endl;
        std::cout << request.string_body() << "\n" << std::endl;
        
        bool expecting_more_replies = true;
        while (expecting_more_replies) {
            typedef dds::sub::LoanedSamples<CommandReply>::iterator iterator;
            dds::sub::LoanedSamples<CommandReply> replies =
                requester.receive_replies(Duration(MAX_WAIT));

            /* When receive_replies times out,
            * it returns an empty reply collection
            */
            if (replies.length() == 0) {
                throw dds::core::Error("Timed out waiting for replies");
                return;
            }

            /* Print the replies received */
            for (iterator it = replies.begin(); it != replies.end(); ++it) {
                if (it->info().valid()) {
                    if (it->data().retcode() ==
                        CommandReplyRetcode::RTI_SERVICE_COMMAND_REPLY_OK) 
                    {
                        std::cout << "\nCommand returned: " 
                                  << it->data().string_body() << std::endl;
                        if (action == CommandActionKind::RTI_SERVICE_COMMAND_ACTION_GET) 
                        {
                            handle_reply_for_get_request(resource_identifier, it->data());
                        } else {
                            std::cout << "COMMAND REPLY OK" << std::endl;
                        }
                    } else { 
                        std::cout << "COMMAND REPLY RECEIVED" << std::endl;
                        std::cout << "Unsuccessful command returned value " 
                                  << it->data().retcode() << "." << std::endl;
                        rti::util::sleep(Duration(10));
                        throw dds::core::Error("Error in replier");
                    }
                    if ((it->info()->flag() & 
                        rti::core::SampleFlag::intermediate_reply_sequence()) == 0)
                    {
                        expecting_more_replies = false;
                    }
                }
            }

            /* We don't need to call replies.return_loan(); the destructor
            * takes care of doing it every time replies goes out of scope
            */
        }
        std::cout << "\nDone" << std::endl;
    }
    
    
    void handle_reply_for_get_request(
            const ResourceIdentifier& resource_identifier,
            const CommandReply& reply) 
    {
        std::vector<char> cdr_buffer(reply.octet_body().begin(), reply.octet_body().end());

        if (check_string_end(resource_identifier, "status")) {
            SharedReaderQueueStatus queue_status;

            dds::topic::topic_type_support<SharedReaderQueueStatus>::from_cdr_buffer( 
                    queue_status,
                    cdr_buffer);
            std::cout << queue_status << std::endl; 
        } else if (check_string_end(resource_identifier, "data")) {
            ServiceData service_data;
            dds::topic::topic_type_support<ServiceData>::from_cdr_buffer( 
                    service_data,
                    cdr_buffer);
            if (service_data.shared_reader_queue_data_list().size() == 0) {
                std::cout << "\nno queues in service" << std::endl;
            } else {
                for (int i = 0; i < service_data.shared_reader_queue_data_list().size(); i++){
                    std::cout << "\nqueue[" << i << "]:" << std::endl;
                    SharedReaderQueueData queueData = 
                            service_data.shared_reader_queue_data_list()[i];
                    std::cout << queueData << std::endl;
                }
            }
        } else if (check_string_end(resource_identifier, "message")) {
            //if length is zero then no messages with the specified
            //attributes were found in the queue
            if (reply.octet_body().size() == 0) {
                return;
            }
            RTI::QueuingService::Message message;   
            
            dds::topic::topic_type_support<RTI::QueuingService::Message>::from_cdr_buffer( 
                    message,
                    cdr_buffer);

            std::cout << "\nretrieved message:" << std::endl;
            std::cout << "  status: " <<  message.status() << std::endl;
            std::cout << "  identity: " << sample_identity_to_string(message.original_virtual_sample_identity());
           
            /*
             * Use here the type Impl generated for your app to retrieve the 
             * application data, that is in the sample_buffer field. You have to
             * add the generated files to your makefile.
             * 
             * i.e: 
             * HelloWorldRequest helloWorldRequest;
             * dds::topic::topic_type_support<HelloWorldRequest>::from_cdr_buffer(
             *         helloWorldRequest, 
             *         message.sample_buffer());
             * std::cout << helloWorldRequest << std::endl;
             */  
        }
    }
    

    
private:
    dds::domain::DomainParticipant participant;
};


int serviceadmin_main(const RemoteConfigParams& parameters)
{
    try {
        ServiceAdminRequesterExample(
                parameters.domain_id, 
                parameters.qos_library, 
                parameters.profile_name)
            .run_example(
                parameters.qos_library, 
                parameters.profile_name,
                parameters.target_service, 
                parameters.action, 
                parameters.resource_identifier, 
                parameters.sample_selector, 
                parameters.queue_params);
        return 0;
    } catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return -1;
    }
}


int main(int argc, char *argv[])
{
    bool isActionFound =  false;
    bool isResourceIdentifierFound = false;
    bool isSelectorFound = false; 
    
    /* Default values */
    RemoteConfigParams parameters;
    
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i],"-d")) {
            if (i == argc-1) {
                std::cout << "Expected <domainId>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.domain_id = atoi(argv[++i]);
        } else if (!strcmp(argv[i],"-q")) {
            if (i == argc-1) {
                std::cout << "Expected <serviceName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.target_service = argv[++i];
        } else if (!strcmp(argv[i],"-o")) {
            char profileName[128];
            char * profileNamePtr;
            
            if (i == argc-1) {
                std::cout << "Expected <qosProfileName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            strncpy(profileName,argv[++i],128);
            profileNamePtr = strstr(profileName,"::");
            if (profileNamePtr == NULL) {
                std::cout << "Expected <qosProfileName> as <libraryName>::<profileName>" 
                          << std::endl;
                parameters.print_usage();
                return -1;
            }
            *profileNamePtr = 0;
            profileNamePtr+=2;
            parameters.profile_name = profileNamePtr;
            parameters.qos_library = profileName;
        } else if (!strcmp(argv[i],"-s")) {
            if (i == argc-1) {
                std::cout << "Expected <sessionName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.queue_params.session_name = argv[++i];
        } else if (!strcmp(argv[i],"-p")) {
            if (i == argc-1) {
                std::cout << "Expected <topicName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.queue_params.topic_name = argv[++i];
        } else if (!strcmp(argv[i],"-t")) {
            if (i == argc-1) {
                std::cout << "Expected <typeName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.queue_params.type_name = argv[++i];
        } else if (!strcmp(argv[i],"-r")) {
            if (i == argc-1) {
                std::cout <<  "Expected <replyTypeName>" << std::endl;
                parameters.print_usage();
                return -1;
            }
            parameters.queue_params.reply_type_name = argv[++i];
        } else if (!isActionFound) {
            if (!strcmp(argv[i],"create")) {
                parameters.resource_identifier = 
                    "/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber";
                parameters.action = CommandActionKind::RTI_SERVICE_COMMAND_ACTION_CREATE;
            } else if (!strcmp(argv[i],"delete")) {
                parameters.resource_identifier =
                    "/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/SharedReaderQueue";
                parameters.action = CommandActionKind::RTI_SERVICE_COMMAND_ACTION_DELETE;
            } else if (!strcmp(argv[i],"get")) {
                parameters.action = CommandActionKind::RTI_SERVICE_COMMAND_ACTION_GET;
                parameters.resource_identifier = "/data";
            } else {
                parameters.print_usage();
                std::cout << "Unsupported command action." << std::endl;
                return -1;
            }
            isActionFound = true;
        } else if (!isResourceIdentifierFound)  {
            parameters.resource_identifier = argv[i];
            isResourceIdentifierFound = true;
        } else if (!isSelectorFound) {
            parameters.sample_selector = argv[i];
            isSelectorFound = true;
        } else {
            std::cout << "unrecognized program option" << std::endl;
            parameters.print_usage();
            return -1;  
        } 
    }
    
    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        return serviceadmin_main(parameters);
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

