                    

/* HelloWorldSubscriber.java

   A publication of data of type HelloWorld

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language java -example <arch> HelloWorld.idl

   Example publication of type HelloWorld automatically generated by 
   'rtiddsgen' To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription on the same domain used for RTI Connext with the command
       java HelloWorldSubscriber <domain_id> <sample_count>

   (3) Start the publication on the same domain used for RTI Connext with the command
       java HelloWorldPublisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.
              
                                   
   Example:
        
       To run the example application on domain <domain_id>:
            
       Ensure that $(NDDSHOME)/lib/<arch> is on the dynamic library path for
       Java.                       
       
        On Unix: 
             add $(NDDSHOME)/lib/<arch> to the 'LD_LIBRARY_PATH' environment
             variable
                                         
        On Windows:
                    add $(NDDSHOME)\lib\<arch> to the 'Path' environment variable
                        

       Run the Java applications:
       
        java -Djava.ext.dirs=$NDDSHOME/class HelloWorldPublisher <domain_id>

        java -Djava.ext.dirs=$NDDSHOME/class HelloWorldSubscriber <domain_id>  
       
       
modification history
------------ -------   
*/

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.subscription.*;
import com.rti.dds.topic.*;
import com.rti.ndds.config.*;

// ===========================================================================

public class HelloWorldSubscriber {
    // -----------------------------------------------------------------------
    // Public Methods
    // -----------------------------------------------------------------------
    
    public static void main(String[] args) {
        // --- Get domain ID --- //
        int domainId = 0;
        if (args.length >= 1) {
            domainId = Integer.valueOf(args[0]).intValue();
        }
        
        // -- Get max loop count; 0 means infinite loop --- //
        int sampleCount = 0;
        if (args.length >= 2) {
            sampleCount = Integer.valueOf(args[1]).intValue();
        }
        
        
        /* Uncomment this to turn on additional logging
        Logger.get_instance().set_verbosity_by_category(
            LogCategory.NDDS_CONFIG_LOG_CATEGORY_API,
            LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        */
        
        // --- Run --- //
        subscriberMain(domainId, sampleCount);
    }
    
    
    
    // -----------------------------------------------------------------------
    // Private Methods
    // -----------------------------------------------------------------------
    
    // --- Constructors: -----------------------------------------------------
    
    private HelloWorldSubscriber() {
        super();
    }
    
    
    // -----------------------------------------------------------------------
    
    private static void subscriberMain(int domainId, int sampleCount) {

        DomainParticipant participant = null;
        Subscriber subscriber = null;
        Topic topic = null;
        DataReaderListener listener = null;
        HelloWorldDataReader reader = null;
        DomainParticipantQos participant_qos = new DomainParticipantQos();

        try {

            // --- Create participant --- //
                       
            /* Get default participant QoS from participant factory */
            DomainParticipantFactory.TheParticipantFactory.get_default_participant_qos(
                participant_qos);

            /* Disable builtin transports */
            participant_qos.transport_builtin.mask =
                TransportBuiltinKind.MASK_NONE;

            /* Set up property QoS to load plugin */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.load_plugins",
                "dds.transport.DTLS.dtls1", false);

            /* library */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.DTLS.dtls1.library",
                "nddstransporttls", false);

            /* create function */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.DTLS.dtls1.create_function",
                "NDDS_Transport_DTLS_create", false);

            /* certificate authority */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.DTLS.dtls1.tls.verify.ca_file",
                "cacert.pem", false);

            /* certificate chain */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.DTLS.dtls1.tls.identity.certificate_chain_file",
                "peer2.pem", false);

            participant = DomainParticipantFactory.TheParticipantFactory.
                create_participant(
                    domainId, participant_qos,
                    null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant == null) {
                System.err.println("create_participant error\n");
                return;
            }                         

            // --- Create subscriber --- //

            /* To customize subscriber QoS, use
               participant.get_default_subscriber_qos() */
            subscriber = participant.create_subscriber(
                DomainParticipant.SUBSCRIBER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (subscriber == null) {
                System.err.println("create_subscriber error\n");
                return;
            }     
                
            // --- Create topic --- //
        
            /* Register type before creating topic */
            String typeName = HelloWorldTypeSupport.get_type_name(); 
            HelloWorldTypeSupport.register_type(participant, typeName);

            /* To customize topic QoS, use
               participant.get_default_topic_qos() */
            topic = participant.create_topic(
                "Example HelloWorld",
                typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic == null) {
                System.err.println("create_topic error\n");
                return;
            }                     
        
            // --- Create reader --- //

            listener = new HelloWorldListener();

            /* To customize data reader QoS, use
               subscriber.get_default_datareader_qos() */
            reader = (HelloWorldDataReader)
                subscriber.create_datareader(
                    topic, Subscriber.DATAREADER_QOS_DEFAULT, listener,
                    StatusKind.STATUS_MASK_ALL);
            if (reader == null) {
                System.err.println("create_datareader error\n");
                return;
            }                         
        
            // --- Wait for data --- //

            final long receivePeriodSec = 4;

            for (int count = 0;
                 (sampleCount == 0) || (count < sampleCount);
                 ++count) {
                System.out.println("HelloWorld subscriber sleeping for "
                                   + receivePeriodSec + " sec...");
                try {
                    Thread.sleep(receivePeriodSec * 1000);  // in millisec
                } catch (InterruptedException ix) {
                    System.err.println("INTERRUPTED");
                    break;
                }
            }
        } finally {

            // --- Shutdown --- //

            if(participant != null) {
                participant.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                    delete_participant(participant);
            }
            /* RTI Connext provides finalize_instance()
               method for people who want to release memory used by the
               participant factory singleton. Uncomment the following block of
               code for clean destruction of the participant factory
               singleton. */
            //DomainParticipantFactory.finalize_instance();
        }
    }
    
    // -----------------------------------------------------------------------
    // Private Types
    // -----------------------------------------------------------------------
    
    // =======================================================================
    
    private static class HelloWorldListener extends DataReaderAdapter {
            
        HelloWorldSeq _dataSeq = new HelloWorldSeq();
        SampleInfoSeq _infoSeq = new SampleInfoSeq();

        public void on_data_available(DataReader reader) {
            HelloWorldDataReader HelloWorldReader =
                (HelloWorldDataReader)reader;
            
            try {
                HelloWorldReader.take(
                    _dataSeq, _infoSeq,
                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    SampleStateKind.ANY_SAMPLE_STATE,
                    ViewStateKind.ANY_VIEW_STATE,
                    InstanceStateKind.ANY_INSTANCE_STATE);

                for(int i = 0; i < _dataSeq.size(); ++i) {
                    SampleInfo info = (SampleInfo)_infoSeq.get(i);

                    if (info.valid_data) {
                        System.out.println(
                            ((HelloWorld)_dataSeq.get(i)).toString("Received",0));


                    }
                }
            } catch (RETCODE_NO_DATA noData) {
                // No data to process
            } finally {
                HelloWorldReader.return_loan(_dataSeq, _infoSeq);
            }
        }
    }
}

