/* HelloWorld_publisher.cxx

   A publication of data of type HelloWorld

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language C++ -example <arch> HelloWorld.idl

   Example publication of type HelloWorld automatically generated by 
   'rtiddsgen'. To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription on the same domain used for RTI Connext with the command
       objs/<arch>/HelloWorld_subscriber <domain_id> <sample_count>
                
   (3) Start the publication on the same domain used for RTI Connext with the command
       objs/<arch>/HelloWorld_publisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.

                                   
   Example:
        
       To run the example application on domain <domain_id>:
                          
       On Unix: 
       
       objs/<arch>/HelloWorld_publisher <domain_id> 
       objs/<arch>/HelloWorld_subscriber <domain_id> 
                            
       On Windows:
       
       objs\<arch>\HelloWorld_publisher <domain_id>  
       objs\<arch>\HelloWorld_subscriber <domain_id>    

       
modification history
------------ -------       
*/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_cpp.h"
#include "HelloWorld.h"
#include "HelloWorldSupport.h"

/* define this to enable security using DTLS */
/*#define USE_SECURITY*/

/* set this value to the address of your WAN Rendezvous server */
#define WAN_SERVER "127.0.0.1"

/* your publisher and subscriber should have unique IDs */
#define WAN_ID "1"

/* String length defined in the IDL */
#define MSG_LENGTH 128

#ifdef RTI_WIN32
#define RTI_SNPRINTF        sprintf_s
#else
#define RTI_SNPRINTF        snprintf
#endif

/* Delete all entities */
static int publisher_shutdown(
    DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
       domain participant factory for people who want to release memory used
       by the participant factory and singleton. Uncomment the following
       block of code for clean destruction of the singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
*/
    return status;
}

extern "C" int publisher_main(int domainId, int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    HelloWorldDataWriter *HelloWorld_writer = NULL;
    HelloWorld *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    struct DDS_Duration_t send_period = {4,0};

    struct DDS_DomainParticipantQos participant_qos;

    /* Get default participant QoS from participant factory */
    retcode = DDSDomainParticipantFactory::get_instance()->get_default_participant_qos(
        participant_qos);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to get default participant qos\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Disable builtin transports */
    participant_qos.transport_builtin.mask = DDS_TRANSPORTBUILTIN_MASK_NONE;

    /* Set up property Qos to load plugin */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.load_plugins", "dds.transport.wan_plugin.wan", 
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.load_plugins\n");
        publisher_shutdown(participant);
    }

    /* library */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.library",
        "nddstransportwan",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.library\n");
        publisher_shutdown(participant);
    }

    /* create function */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property,
        "dds.transport.wan_plugin.wan.create_function",
        "NDDS_Transport_WAN_create",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.create_function\n");
        publisher_shutdown(participant);
    }

    /* plugin properties */
#ifdef USE_SECURITY
    fprintf(stderr, "Enabling secure WAN transport\n");
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.enable_security", "1",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.enable_security\n");
        publisher_shutdown(participant);
    }
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.tls.verify.ca_file", "cacert.pem",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.tls.verify.ca_file\n");
        publisher_shutdown(participant);
    }
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.tls.identity.certificate_chain_file",
        "peer1.pem", DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.tls.identity.certificate_chain_file\n");
        publisher_shutdown(participant);
    }
#endif /* USE_SECURITY */

    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.server", WAN_SERVER,
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.server\n");
        publisher_shutdown(participant);
    }

    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.wan_plugin.wan.transport_instance_id", WAN_ID,
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.wan_plugin.wan.transport_instance_id\n");
        publisher_shutdown(participant);
    }

    participant = DDSTheParticipantFactory->create_participant(
        domainId, participant_qos,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize publisher QoS, use
       participant->get_default_publisher_qos() */
    publisher = participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        fprintf(stderr, "create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = HelloWorldTypeSupport::get_type_name();
    retcode = HelloWorldTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use
       participant->get_default_topic_qos() */
    topic = participant->create_topic(
        "Example HelloWorld",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        fprintf(stderr, "create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize data writer QoS, use
       publisher->get_default_datawriter_qos() */
    writer = publisher->create_datawriter(
        topic, DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        fprintf(stderr, "create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    HelloWorld_writer = HelloWorldDataWriter::narrow(writer);
    if (HelloWorld_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = HelloWorldTypeSupport::create_data();
    if (instance == NULL) {
        fprintf(stderr, "HelloWorldTypeSupport::create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* For data type that has key, if the same instance is going to be
       written multiple times, initialize the key here
       and register the keyed instance prior to writing */
/*
    instance_handle = HelloWorld_writer->register_instance(*instance);
*/

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        printf("Writing HelloWorld to WAN, count %d\n", count);
        fflush(stdout);

        /* Modify the data to be sent here */
        RTI_SNPRINTF(
                instance->msg,
                MSG_LENGTH,
                "Hello Wide Area World! (%d)",
                count);
        instance->msg[MSG_LENGTH-1] = '\0';

        retcode = HelloWorld_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d\n", retcode);
        }

        NDDSUtility::sleep(send_period);
    }

/*
    retcode = HelloWorld_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        printf("unregister instance error %d\n", retcode);
    }
*/

    /* Delete data sample */
    retcode = HelloWorldTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "HelloWorldTypeSupport::delete_data error %d\n", retcode);
    }

    /* Delete all entities */
    return publisher_shutdown(participant);
}

#if defined(RTI_WINCE)
int wmain(int argc, wchar_t** argv)
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */ 
    
    if (argc >= 2) {
        domainId = _wtoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = _wtoi(argv[2]);
    }
    
    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return publisher_main(domainId, sample_count);
}

#elif !(defined(RTI_VXWORKS) && !defined(__RTP__)) && !defined(RTI_PSOS)
int main(int argc, char *argv[])
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        domainId = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return publisher_main(domainId, sample_count);
}
#endif