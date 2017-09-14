using System;
using System.Collections.Generic;
using System.Text;
using DDS;

public class HelloWorldTopicQueryPublisher {
    private HelloWorldTopicQueryPublisherParams input_params;
    private DomainParticipant participant;
    private HelloWorldTopicQueryDataWriter writer;  
    private HelloWorldTopicQuery instance;

    HelloWorldTopicQueryPublisher(
            HelloWorldTopicQueryPublisherParams in_params) {
        
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
        /* Topic. */
        Topic topic = this.participant.create_topic(
                    "Example HelloWorldTopicQuery", 
                    HelloWorldTopicQueryTypeSupport.get_type_name(), 
                    DomainParticipant.TOPIC_QOS_DEFAULT, 
                    null, 
                    StatusMask.STATUS_MASK_NONE);
        if (topic == null) {
            this.stop();
            throw new ApplicationException("create_topic error");
        }
        /* 
         * QoS configuration to enable TopicQueries in DataWriter is in file 
         * USER_QOS_PROFILES.xml. 
         */
        this.writer = (HelloWorldTopicQueryDataWriter) 
                this.participant.create_datawriter_with_profile(
                    topic,
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null,
                    StatusMask.STATUS_MASK_NONE);

        if (this.writer == null) {
            this.stop();
            throw new ApplicationException("create_datawriter error");
        }

        /* Instance. */
        this.instance = HelloWorldTopicQueryTypeSupport.create_data();
        if (this.instance == null) {
            this.stop();
            throw new ApplicationException(
                "HelloWorldTopicQueryTypeSupport.create_data error");
        }              
                
    }

    private void writeSample(int count) {
        Console.Out.WriteLine("Writing HelloWorldTopicQuery, count " + ++count);
        /* Modify the instance to be written here. */
        if (this.input_params.lowerInstanceId >= 0) {
            this.instance.id = this.input_params.upperInstanceId < 0
                    ? count % (this.input_params.lowerInstanceId + 1)
                    : count % (this.input_params.upperInstanceId 
                        - this.input_params.lowerInstanceId);
        } else {
            this.instance.id = count;
        }
        this.instance.message = "count: " + count;
        InstanceHandle_t instance_handle = InstanceHandle_t.HANDLE_NIL;
        try {
            this.writer.write(instance, ref instance_handle);
        } catch (DDS.Exception e) {
            Console.WriteLine("write error {0}", e);
        }
    }

    /**
     * Writing logic of the application.
     * 
     * There are two write phases:
     * - A single initial burst of initialBurstSize samples.
     * - A periodic phase that writes up to sentSampleCount samples every
     *  writePeriod.
     * 
     * @see HelloWorldTopicQueryPublisherParams
     */
    public void start() {
            
        /* Initial burst */
        int count;
        for (count = 0; count < this.input_params.initialBurstSize; count++) {
            this.writeSample(count);
        }
        
        /* Periodic send. */
        while ((this.input_params.sentSampleCount < 0 ||
                    count < this.input_params.sentSampleCount)) {            
            System.Threading.Thread.Sleep(this.input_params.writePeriod.sec * 1000);
            this.writeSample(count);
            count++;
        }

        /* Delete data sample */
        try {
            HelloWorldTopicQueryTypeSupport.delete_data(this.instance);
        } catch (DDS.Exception e) {
            Console.WriteLine(
                "HelloWorldTopicQueryTypeSupport.delete_data error: {0}", e);
        }
    }

    /**
     * Performs the deletion of the DDS entities.
     */
    public void stop() {        
        Console.Out.WriteLine("Shutting down...");        
        if (this.participant != null) {
            this.participant.delete_contained_entities();
            this.writer = null;
            DomainParticipantFactory.get_instance().delete_participant(
                    ref this.participant);
            this.participant = null;
        }
        Console.Out.WriteLine("Done");
    }  

    public static void Main(string[] args) {

        HelloWorldTopicQueryPublisherParams appParams = 
            new HelloWorldTopicQueryPublisherParams();
        try { 
             HelloWorldTopicQueryPublisherParams.parseCommandLine(
                     appParams, 
                     args);
        } catch (ArgumentException e) {
            Console.Out.WriteLine(e.ToString());
            HelloWorldTopicQueryPublisherParams.printUsage();
            System.Environment.Exit(1);
        }
        try {
            HelloWorldTopicQueryPublisher publisherApp =
                    new HelloWorldTopicQueryPublisher(appParams);
            publisherApp.start();
            publisherApp.stop();
        } catch (DDS.Exception) {
            System.Environment.Exit(1);
        }

    }
}

/**
 * Configuration options of the publisher application.
 */
public class HelloWorldTopicQueryPublisherParams
{

    /* Domain id the participant belongs to. */
    public int domainId = 0;
    /* Number of samples the application writes before shuting down. */
    public int sentSampleCount = -1;
    /* Selects the instance Id range the application writes samples for. */
    public int lowerInstanceId = 0;
    public int upperInstanceId = -1;
    /* Write period. */
    public Duration_t writePeriod = Duration_t.from_seconds(4);
    /* Number of samples the application writes in burst mode before periodic. */
    public int initialBurstSize = 0;

    public HelloWorldTopicQueryPublisherParams() { }

    static public void parseCommandLine(
            HelloWorldTopicQueryPublisherParams in_params,
            String[] args)
    {

        for (int i = 0; i < args.Length; i++)
        {
            switch (args[i])
            {
                case "-d":
                case "-domainId":
                    in_params.domainId = Int32.Parse(args[++i]);
                    break;
                case "-c":
                case "-sampleCount":
                    in_params.sentSampleCount = Int32.Parse(args[++i]);
                    break;
                case "-l":
                case "-lowInstanceId":
                    in_params.lowerInstanceId = Int32.Parse(args[++i]);
                    break;
                case "-u":
                case "-upperInstanceId":
                    in_params.upperInstanceId = Int32.Parse(args[++i]);
                    break;
                case "-p":
                case "-period":
                    in_params.writePeriod = Duration_t.from_seconds(
                            UInt32.Parse(args[++i]));
                    break;
                case "-b":
                case "-burst":
                    in_params.initialBurstSize = Int32.Parse(args[++i]);
                    break;
                default:
                    throw new ArgumentException("Unrecognized option " + "'" + args[i] + "'");
            }
        }
    }

    static public void printUsage()
    {
        StringBuilder format = new StringBuilder();
        format.Append("Usage: HelloWorldTopicQueryPublisher [options]\n");
        format.Append("\t-d <domainId>              default: 0\n");
        format.Append("\t-c <count>                 default: -1 (infinite)\n");
        format.Append("\t-l <lowerInstanceId>       default: 0-\n");
        format.Append("\t-u <upperInstanceId>       default: -1 (no upper limit)\n");
        format.Append("\t-p <period>                default: 4s\n");
        format.Append("\t-b <burstSize>             default: 0\n");
        Console.Out.WriteLine(format);
    }

}