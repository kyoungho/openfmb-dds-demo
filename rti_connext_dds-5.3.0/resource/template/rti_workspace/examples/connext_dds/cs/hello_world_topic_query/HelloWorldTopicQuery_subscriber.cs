using System;
using System.Collections.Generic;
using System.Text;
using DDS;

public class HelloWorldTopicQuerySubscriber {

    private HelloWorldTopicQuerySubscriberParams input_params;
    private DomainParticipant participant;
    private HelloWorldTopicQueryDataReader reader;
    private WaitSet waitSet;
    private ReadCondition topicQueryReadCondition;
    private ReadCondition liveStreamReadCondition;
    private int sampleCount;

    static readonly Duration_t READ_PERIOD = Duration_t.from_seconds(2);
    
    HelloWorldTopicQuerySubscriber(
            HelloWorldTopicQuerySubscriberParams in_params) {
        
        this.input_params = in_params;                
        
        /* Participant. */
        this.participant = DomainParticipantFactory.get_instance().
                create_participant_with_profile(
                    this.input_params.domainId,
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null,
                    StatusMask.STATUS_MASK_NONE);
        if (this.participant == null) {
            this.stop();
            throw new ApplicationException("create_participant error");
        }
        try {
            HelloWorldTopicQueryTypeSupport.register_type(
                    this.participant,
                    HelloWorldTopicQueryTypeSupport.get_type_name());
        } catch (DDS.Exception e) {
            Console.WriteLine("register_type error {0}", e);
            this.stop();
            throw new ApplicationException("register_type error");
        }
        /* Topic and CFT if required. */
        ITopicDescription topicDescription = (ITopicDescription) 
                this.participant.create_topic(
                    "Example HelloWorldTopicQuery", 
                    HelloWorldTopicQueryTypeSupport.get_type_name(), 
                    DomainParticipant.TOPIC_QOS_DEFAULT, 
                    null, 
                    StatusMask.STATUS_MASK_NONE);

        if (topicDescription == null) {
            this.stop();
            throw new ApplicationException("create_topic error");
        }
        
        if (input_params.subscribedInstanceId >= 0) {
            topicDescription = (ITopicDescription) 
                    this.participant.create_contentfilteredtopic(
                        "HelloWorldTopicQuerySubscriber_cft", 
                        (Topic) topicDescription,
                        "id = " + input_params.subscribedInstanceId, 
                        new StringSeq(0));            
        }
        if (topicDescription == null) {
            this.stop();
            throw new ApplicationException(
                "create_contentfilteredtopic error");
        }
        
        /* 
         * QoS configuration to enable TopicQueries in DataReader is in file 
         * USER_QOS_PROFILES.xml.
         */                               
        this.reader = (HelloWorldTopicQueryDataReader )
                this.participant.create_datareader_with_profile(
                    topicDescription, 
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null, 
                    StatusMask.STATUS_MASK_NONE);
        if (this.reader == null) {
            this.stop();
            throw new ApplicationException("create_datareader error");
        }               
        
        /* WaitSet and Conditions. */
        this.waitSet = new WaitSet(); 

        /* Read Condition for TQ stream only. */
        ReadConditionParams readConditionParams = new ReadConditionParams();
        readConditionParams.stream_kinds = StreamKind.TOPIC_QUERY_STREAM;
        this.topicQueryReadCondition = 
                this.reader.create_readcondition_w_params(readConditionParams);
        if (this.topicQueryReadCondition == null) {
            this.stop();
            throw new ApplicationException(
                "create topic query stream read condition error");
        }                
        /* Read Condition for live stream. */
        readConditionParams.stream_kinds = StreamKind.LIVE_STREAM;
        this.liveStreamReadCondition =
                this.reader.create_readcondition_w_params(readConditionParams);
        if (this.liveStreamReadCondition == null) {
            this.stop();
            throw new ApplicationException(
                "create topic query stream read condition error");
        }
    }

    /**
     * Takes the available samples and prints their content.
     * 
     * The operation will determine whether a sample belongs to a TopicQuery
     * stream or to the live stream, and print a header accordingly.
     * 
     * return True if more samples are expected or false otherwise.
     */
    private Boolean processSamples(ReadCondition readCondition) {
        HelloWorldTopicQuerySeq receivedSamples = 
            new HelloWorldTopicQuerySeq();
        SampleInfoSeq sampleInfos = new SampleInfoSeq();
        try {
            this.reader.take_w_condition(
                    receivedSamples,
                    sampleInfos,
                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    readCondition);
            for (int i = 0; i < receivedSamples.length; i++) {
                HelloWorldTopicQuery sample = 
                    (HelloWorldTopicQuery) receivedSamples.get_at(i);
                SampleInfo info = (SampleInfo) sampleInfos.get_at(i);
                HelloWorldTopicQuerySubscriber.printReceivedSample(
                    sample, info);
                this.sampleCount++;
                /*
                 * If we are processing samples for a TopicQuery, we may 
                 * indicate that no more samples are expected if the 
                 * corresponding flag is present. Note that such flag will be 
                 * set by each DataWriter that accepts the TopicQuery. This 
                 * example assumes that an instance is published by only one
                 * DataWriter.
                 */   
                Boolean isLastTopicQuerySample = 
                        (info.flag 
                        & ((int)(SampleFlagBits.INTERMEDIATE_TOPIC_QUERY_SAMPLE))) == 0;
                Boolean isTopicQuerySample =
                    !info.topic_query_guid.Equals(GUID_t.GUID_UNKNOWN);
                if (isTopicQuerySample && 
                        isLastTopicQuerySample &&
                        this.input_params.subscribedInstanceId >= 0) {             
                    return false;
                }
            }
        } catch (Retcode_NoData ) {
        } finally {
            this.reader.return_loan(receivedSamples, sampleInfos);
        }
        
        return true;
    }

    /**
     * Waits and processes samples for a maximum amount of time.
     */
    private void waitForSamples(Duration_t waitTime)  {
        
        ConditionSeq activeConditions = new ConditionSeq();
        while (waitTime.sec > 0 && waitTime.nanosec >= 0) {
            try {
                long startTime = DateTime.Now.Ticks;
                this.waitSet.wait(activeConditions, waitTime);
                for (int i = 0; i < activeConditions.length; i++) {
                    if (!this.processSamples(
                        (ReadCondition)activeConditions.get_at(i))) {
                        return;
                    }
                }
                
                waitTime = Duration_t.from_nanos(
                    ((ulong)waitTime.sec * 1000000000UL + waitTime.nanosec) -
                    ((ulong)(DateTime.Now.Ticks - startTime)) * (100UL));
            }
            catch (Retcode_Timeout ) {
                break;
            }
        }
    }

    /**
     * Waits until the specified number of samples have been received and 
     * processed.
     */
    private void waitForSamples(int maxSampleCount) {
        
        ConditionSeq activeConditions = new ConditionSeq();

        while (maxSampleCount < 0 || this.sampleCount < maxSampleCount) {
            try {
                this.waitSet.wait(activeConditions, READ_PERIOD);
                for (int i = 0; i < activeConditions.length; i++) {
                    this.processSamples((ReadCondition)activeConditions.get_at(i));
                }
            }
            catch (Retcode_Timeout ) {
            }
        }
    }

    /**
     * Reading logic of the application.
     *
     * There are two phases: 
     * - An initial phase in which the application processes only TopicQuery
     * samples for up to topicQueryWaitDuration.
     * - A periodic read phase in which the application processes both 
     * TopicQuery and live samples for up to receivedSampleCount samples.
     */
    public void start() {
                        
        /* 
         * Create a TopicQuery to receive the samples published before the
         * creation of this reader. 
         */
        TopicQuerySelection selection;
        /* Explicitly set the expression when the DataReader does not use a CFT. */
        if (this.input_params.subscribedInstanceId < 0) {
            selection = DataReader.TOPIC_QUERY_SELECTION_SELECT_ALL;            
        } else {
            selection = DataReader.TOPIC_QUERY_SELECTION_USE_READER_CONTENT_FILTER;
        }
        TopicQuery topicQuery = this.reader.create_topic_query(selection);
        if (topicQuery == null) {
            throw new System.Exception("create topic query error");
        }               
        
        /* Get first TopicQuery samples. */
        this.waitSet.attach_condition(this.topicQueryReadCondition);
        
        Console.Out.WriteLine("HelloWorldTopicQuerySubscriber waiting" +
                " for the first sample");
        this.waitForSamples(this.input_params.topicQueryWaitDuration);   
        /* Read both live and topic query samples. */
        this.waitSet.attach_condition(this.liveStreamReadCondition);
        /* Wait until all of the samples have been received. */
        this.waitForSamples(this.input_params.receivedSampleCount);      
    }

    /**
     * Performs the deletion of the DDS entities.
     */
    public void stop() {        
        Console.Out.WriteLine("Shutting down...");
        if (this.reader != null) {
            /* Delete any existing ReadCondition and TopicQuery. */
            this.reader.delete_contained_entities();
        }
        if (this.participant != null) {
            this.participant.delete_contained_entities();
            this.reader = null;
            DomainParticipantFactory.get_instance().delete_participant(
                    ref this.participant);
            this.participant = null;
        }
        Console.Out.WriteLine("Done");
    }

    private static void printReceivedSample(
            HelloWorldTopicQuery sample,
            SampleInfo info) {   
        StringBuilder output = new StringBuilder();
        if (!info.topic_query_guid.Equals(GUID_t.GUID_UNKNOWN)) {
            output.Append("Received TopicQuery sample with GUID ");
            output.Append(info.topic_query_guid.ToString() + ":");
        } else {
            output.Append("Received live sample");
        }
        output.Append("\n\tid: " + sample.id.ToString());
        output.Append("\n\tmessage: " + sample.message);
        Console.Out.WriteLine(output);
    }

    public static void Main(String[] args) {
        
        HelloWorldTopicQuerySubscriberParams appParams = 
                new HelloWorldTopicQuerySubscriberParams();
        try { 
             HelloWorldTopicQuerySubscriberParams.parseCommandLine(
                     appParams, 
                     args);
        }
        catch (ArgumentException e) {
            Console.Out.WriteLine(e.ToString());
            HelloWorldTopicQuerySubscriberParams.printUsage();
            System.Environment.Exit(1);
        }
        try {
            HelloWorldTopicQuerySubscriber subscriberApp =
                    new HelloWorldTopicQuerySubscriber(appParams);

            subscriberApp.start();
            subscriberApp.stop();
        } catch (DDS.Exception) {
            System.Environment.Exit(1);
        }
    }    
}

/**
 * Configuration options of the subscriber application.
 */
public class HelloWorldTopicQuerySubscriberParams {

    /* Domain id the participant belongs to. */
    public int domainId = 0;
    /* 
     * Indicates the  number of samples the application shall receive
     * before shutting down. 
     */
    public int receivedSampleCount = -1;
    /* Selects the instance that the application wants to receive data for. */
    public int subscribedInstanceId = -1;
    /* 
     * Indicates an initial time interval the application waits for reception of
     * TopicQuery samples before reading live data. 
     */
    public Duration_t topicQueryWaitDuration = Duration_t.from_seconds(0);
    
    public HelloWorldTopicQuerySubscriberParams () {}

    public static void parseCommandLine(
            HelloWorldTopicQuerySubscriberParams in_params, 
            String[] args) {

        for (int i = 0; i < args.Length; i++) {
            switch (args[i]) {
                case "-d":
                case "-domainId":
                    in_params.domainId = Int32.Parse(args[++i]);
                    break;
                case "-c":
                case "-sampleCount":
                    in_params.receivedSampleCount = Int32.Parse(args[++i]);
                    break;
                case "-i":
                case "-instanceId":
                    in_params.subscribedInstanceId = Int32.Parse(args[++i]);
                    break;
                case "-t":
                case "-topicQueryWaitMax":
                    in_params.topicQueryWaitDuration = Duration_t.from_seconds(
                            UInt32.Parse(args[++i]));
                    break;
                default:
                    throw new ArgumentException(
                            "Unrecognized option " + "'" + args[i] +  "'");
            }
        }
    }
    
    static public void printUsage() {
        StringBuilder format = new StringBuilder();
        format.Append("Usage: HelloWorldTopicQuerySubscriber [options]\n");
        format.Append("\t-d <domainId>              default: 0\n");
        format.Append("\t-c <count>                 default: -1 (infinite)\n");
        format.Append("\t-i <instanceId>            default: -1 (all)\n");
        format.Append("\t-t <topicQueryWaitMax>     default: 0s\n");
        Console.Out.WriteLine(format);   
    }

}


