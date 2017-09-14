/* HelloWorld_subscriber.cxx

   A subscription example

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language C++ -example <arch> HelloWorld.idl

   Example subscription of type HelloWorld automatically generated by 
   'rtiddsgen'. To test them follow these steps:

   (1) Compile this file and the example publication.

   (2) Start the subscription on the same domain used for RTI Connext with the command
       objs/<arch>/HelloWorld_subscriber <domain_id> <sample_count>

   (3) Start the publication on the same domain used for RTI Connext
       with the command
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

/* uncomment to use DTLS static libs */
/*#define USE_STATIC_LINK*/
#ifdef USE_STATIC_LINK
#include "transport_tls/transport_tls_plugin.h"
#endif

class HelloWorldListener : public DDSDataReaderListener {
  public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}
    
    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}
    
    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* reader);
};

void HelloWorldListener::on_data_available(DDSDataReader* reader)
{
    HelloWorldDataReader *HelloWorld_reader = NULL;
    HelloWorldSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    HelloWorld_reader = HelloWorldDataReader::narrow(reader);
    if (HelloWorld_reader == NULL) {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = HelloWorld_reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {
            HelloWorldTypeSupport::print_data(&data_seq[i]);
            fflush(stdout);
        }
    }

    retcode = HelloWorld_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}

/* Delete all entities */
static int subscriber_shutdown(
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
       by the participant factory singleton. Uncomment the following block of
       code for clean destruction of the singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
*/
    return status;
}

extern "C" int subscriber_main(int domainId, int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    HelloWorldListener *reader_listener = NULL; 
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    struct DDS_Duration_t receive_period = {4,0};
    int status = 0;

    struct DDS_DomainParticipantQos participant_qos;

    /* Get default participant QoS from participant factory */
    retcode = DDSDomainParticipantFactory::get_instance()->get_default_participant_qos(
        participant_qos);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to get default participant qos\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Disable builtin transports */
    participant_qos.transport_builtin.mask = DDS_TRANSPORTBUILTIN_MASK_NONE;

    /* Set up property Qos to load plugin */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.load_plugins", "dds.transport.DTLS.dtls1", 
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.load_plugins\n");
        subscriber_shutdown(participant);
    }

#ifdef USE_STATIC_LINK
    /* create function ptr */
    retcode = DDSPropertyQosPolicyHelper::add_pointer_property(
        participant_qos.property,
        "dds.transport.DTLS.dtls1.create_function_ptr",
        (void *)NDDS_Transport_DTLS_create);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.DTLS.dtls1.create_function_ptr\n");
        subscriber_shutdown(participant);
    }
#else
    /* library */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.DTLS.dtls1.library",
        "nddstransporttls",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.DTLS.dtls1.library\n");
        subscriber_shutdown(participant);
    }

    /* create function */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property,
        "dds.transport.DTLS.dtls1.create_function",
        "NDDS_Transport_DTLS_create",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.DTLS.dtls1.create_function\n");
        subscriber_shutdown(participant);
    }
#endif

    /* certificate authority */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.DTLS.dtls1.tls.verify.ca_file", "cacert.pem",
        DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.DTLS.dtls1.tls.verify.ca_file\n");
        subscriber_shutdown(participant);
    }

    /* certificate chain */
    retcode = DDSPropertyQosPolicyHelper::add_property(
        participant_qos.property, 
        "dds.transport.DTLS.dtls1.tls.identity.certificate_chain_file",
        "peer2.pem", DDS_BOOLEAN_FALSE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "Failed to add property dds.transport.DTLS.dtls1.tls.identity.certificate_chain_file\n");
        subscriber_shutdown(participant);
    }

    participant = DDSTheParticipantFactory->create_participant(
        domainId, participant_qos,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* To customize subscriber QoS, use
       participant->get_default_subscriber_qos() */
    subscriber = participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        fprintf(stderr, "create_subscriber error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = HelloWorldTypeSupport::get_type_name();
    retcode = HelloWorldTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        subscriber_shutdown(participant);
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
        subscriber_shutdown(participant);
        return -1;
    }

    /* Create data reader listener */
    reader_listener = new HelloWorldListener();
    if (reader_listener ==  NULL) {
        fprintf(stderr, "listener instantiation error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* To customize data reader QoS, use
       subscriber->get_default_datareader_qos() */
    reader = subscriber->create_datareader(
        topic, DDS_DATAREADER_QOS_DEFAULT, reader_listener,
        DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        fprintf(stderr, "create_datareader error\n");
        subscriber_shutdown(participant);
        delete reader_listener;
        return -1;
    }

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        printf("HelloWorld subscriber sleeping for %d sec...\n",
               receive_period.sec);
        fflush(stdout);

        NDDSUtility::sleep(receive_period);
    }

    /* Delete all entities */
    status = subscriber_shutdown(participant);
    delete reader_listener;

    return status;
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
                                  
    return subscriber_main(domainId, sample_count);
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
                                  
    return subscriber_main(domainId, sample_count);
}
#endif
