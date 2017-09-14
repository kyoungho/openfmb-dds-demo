/* ****************************************************************************
 *         (c) Copyright, Real-Time Innovations, All rights reserved.       
 *                                                                          
 *         Permission to modify and use for internal purposes granted.      
 * This software is provided "as is", without warranty, express or implied. 
 *                                                                          
 * ****************************************************************************
 */
using System;
using System.IO;
using System.Threading;

namespace Hello {
    /**
     * A container for the running options (defined through the command-line 
     * arguments)
     */
    public class CommandLineArguments {
        /* Command line defaults */
        public const int DEFAULT_DOMAIN_ID = 0;
        public const int DEFAULT_PAYLOAD = 1024;
        public const String APPLICATION_NAME = "Hello";

        /* This is the name of the topic used for our test */
        public const String DEFAULT_TOPIC_NAME = "Hello IDL";

        /* Application running mode */
        public const int APP_MODE_UNDEFINED = 0;
        public const int APP_MODE_PUBLISHER = 1;
        public const int APP_MODE_SUBSCRIBER = 2;

        /* The maximum value for Domain ID. The effective value depends on the QoS,
         * in particular to the value of the field:
         *              DDS_RtpsWellKnownPorts_t.domainId_gain
         * The default value is 250, so we just limit to that statically so we can
         * check the validity before attempting to create the domain participant.
         */
        public const int DOMAIN_ID_MAX = 250;

        public int domain_id;
        public int mode;
        public int dataSize;
        public int sampleCount;
        public int verbose;    /* 0=no verbose, 1=app verbose, 2=DDS */
        public String topicName;

        public CommandLineArguments() {
            domain_id = DEFAULT_DOMAIN_ID;
            mode = APP_MODE_UNDEFINED;
            dataSize = DEFAULT_PAYLOAD;
            sampleCount = 0;
            verbose = 0;
            topicName = DEFAULT_TOPIC_NAME;
        }
    }
    
    /**
     * Manage the subscription for the data published in the Hello example 
     */
    class HelloSubscriber : DDS.DataReaderListener {
        private const int POLL_PERIOD_MILLISEC = 1000; /* In seconds */
        private const int ONE_MEGABYTE = 1024 * 1024;

        private int _theVerbose;
        private int _theSampleId = 0;       // Last received sample ID
        private int _thePayloadSize = 0;    // Set only when received the 1st sample
        private int _theSampleLost = 0;     // Counter for sample lost
        private int _theSampleRcvdCount = 0; /* Counter of samples received */
        private int _theSampleRcvdMax = 0;   /* Maximum number of samples to receive */

        private HelloWorldSeq _dataSeq = new HelloWorldSeq();
        private DDS.SampleInfoSeq _infoSeq = new DDS.SampleInfoSeq();
        private HelloWorldDataReader _reader = null;

        public HelloSubscriber(DDS.DomainParticipant participant,
                            DDS.Topic topic,
                            int verbose,
                            int sampleCount) {
            _theVerbose = verbose;
            _theSampleRcvdMax = sampleCount;

            /* Create the publisher. 
             * Just like the participant, if you want to customize the subscriber QoS,
             * use DDS.DomainParticipant.get_default_subscriber_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             *     DDS.DomainParticipant.SUBSCRIBER_QOS_DEFAULT.
             * For more info on publisher API, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSSubscriberModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating subscriber...");
            }
            DDS.Subscriber subscriber = participant.create_subscriber(
                            DDS.DomainParticipant.SUBSCRIBER_QOS_DEFAULT,
                            null,           // listener
                            DDS.StatusMask.STATUS_MASK_NONE);
            if (subscriber == null) {
                Console.WriteLine("! Unable to create DDS Subscriber");
                return;
            }

            /* Creates the DDS Data reader. 
             * Just like before, if you want to customize the reader QoS,
             * use DDS.Subscriber.get_default_datareader_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             * DDS_DATAREADER_QOS_DEFAULT.
             * For more data reader API info, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSReaderModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating the data reader...");
            }
            _reader = (HelloWorldDataReader)
                            subscriber.create_datareader(
                            topic,
                            DDS.Subscriber.DATAREADER_QOS_DEFAULT,
                            this,
                            DDS.StatusMask.STATUS_MASK_ALL);
            if (_reader == null) {
                Console.Error.WriteLine("! Unable to create DDS Data Reader");
                return;
            }
        }

        /**************************************************************************
         * Waits for the application to terminate. Data samples are received from
         * the DDS thread. This thread simply periodically prints on screen the
         * statistics of the data received.
         */
        public void waitForTermination() {
            /* Statistics variables */
            int stat_first_sequence_id = 0;         /* ID of first sample */
            DateTime time_now;                      /* Time for every iteration */
            DateTime start_time;                    /* Time of first iteration w/samples */
            int stat_delta_time_sec;                /* Num. secs since first sample */
            int last_sample_id = 0;                 /* Copy of the last sample_id */
            int last_sample_lost = 0;               /* Copy of the last sample_lost */
            int prev_sample_id = 0;                 /* ID of sample lost on prev. iteration */
            int prev_sample_lost = 0;               /* Sample lost of prev. iteration */
            int stat_total_samples = 0;             /* Total # of msgs received */
            int stat_samples_lost;                  /* Samples lost for the last period */
            float stat_total_sample_per_sec = 0;
            float stat_current_sample_per_sec = 0;
            float stat_throughput = 0;

            /* Initialize start_time */
            start_time = DateTime.Now;

            Console.WriteLine("");
            /*      12345678|1234567890|1234567890|1234567890|1234567890|1234567890|1234567890 */
            Console.WriteLine("Sec.from   |Total     |Total Lost|Curr Lost|Average      |Current   |Current");
            Console.WriteLine("start      |samples   |samples   |samples  |smpls/sec    |smpls/sec |Mb/sec");
            Console.WriteLine("-----------+----------+----------+---------+-------------+----------+----------");

            for (; ; ) {
                try {
                    Thread.Sleep(POLL_PERIOD_MILLISEC);

                    if (_theSampleRcvdMax != 0 && (_theSampleRcvdCount >= _theSampleRcvdMax)) {
                        Console.WriteLine("Received " + _theSampleRcvdCount + " samples.");
                        _reader.set_listener(null, DDS.StatusMask.STATUS_MASK_NONE); 
                        break;
                    }

                    /* If the last sample_id received is < than the older one received,
                     * it is because the publisher has restarted or there are two publishers
                     * in the system.
                     * In this case the stats won't be correct, so terminate the application
                     */
                    if (_theSampleId < last_sample_id) {
                        Console.WriteLine("Detected multiple publishers, or the publisher was restarted.");
                        Console.WriteLine("If you have multiple publishers on the network or you restart");
                        Console.WriteLine("the publisher, the statistics produced won't be accurate.");
                        break;
                    }

                    /* Make a copy of the last sample received */
                    last_sample_id = _theSampleId;
                    last_sample_lost = _theSampleLost;
                    time_now = DateTime.Now;
                    if (last_sample_id == 0) {
                        if (_theVerbose > 0) {
                            Console.WriteLine("No data...");
                        }
                        /* No data */
                        continue;
                    }

                    /* If this is the first sample received, mark the sample ID and 
                       get the time */
                    if (stat_first_sequence_id == 0) {
                        stat_first_sequence_id = last_sample_id;
                        start_time = DateTime.Now;
                        /* Don't consider this iteration in the statistics, as it is
                         * not meaningful.
                         */
                        prev_sample_id = last_sample_id;
                        prev_sample_lost = last_sample_lost;
                        continue;
                    }

                    /* Then calculate the statistics */
                    stat_delta_time_sec = (int)((TimeSpan)(time_now - start_time)).TotalSeconds;
                    stat_total_samples = last_sample_id - stat_first_sequence_id - last_sample_lost;
                    stat_total_sample_per_sec = (float)stat_total_samples / (float)stat_delta_time_sec;
                    stat_current_sample_per_sec = (float)(last_sample_id - prev_sample_id)
                                        / (POLL_PERIOD_MILLISEC / 1000);
                    stat_samples_lost = last_sample_lost - prev_sample_lost;
                    stat_throughput =
                        _thePayloadSize *
                        stat_current_sample_per_sec *
                        8.0f /
                        ONE_MEGABYTE;

                    Console.WriteLine("{0,11} {1,10} {2,10} {3,9} {4,13:F} {5,10:F} {6,10:F}",
                            stat_delta_time_sec,
                            stat_total_samples,
                            last_sample_lost,
                            stat_samples_lost,
                            stat_total_sample_per_sec,
                            stat_current_sample_per_sec,
                            stat_throughput);
                    prev_sample_id = last_sample_id;
                    prev_sample_lost = last_sample_lost;

                }
                catch (ThreadInterruptedException) { }
            }
        }

        /**************************************************************************
         * Called for every valid sample received from DDS. 
         * This simply copy the
         * received data in the class properties to be processed by the main
         * thread (running waitForTermination).
         * @param instance an instance of the data just received. 
         */
        private void _processData(HelloWorld instance) {
            _theSampleId = instance.sampleId;
            ++_theSampleRcvdCount;
            if (_thePayloadSize == 0) {
                _thePayloadSize = instance.payload.length;
            }
        }


        /* ************************************************************************
         * Implementation of the methods described in DataReaderListener interface
         * ************************************************************************
         */
        public override void on_data_available(DDS.DataReader reader) {
            HelloWorldDataReader HelloWorldReader = (HelloWorldDataReader)reader;
            if (_theSampleRcvdMax != 0 && 
                (_theSampleRcvdCount >= _theSampleRcvdMax)) {
                return;
            }
            try {
                HelloWorldReader.take(_dataSeq,
                                _infoSeq,
                                DDS.ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                                DDS.SampleStateKind.ANY_SAMPLE_STATE,
                                DDS.ViewStateKind.ANY_VIEW_STATE,
                                DDS.InstanceStateKind.ANY_INSTANCE_STATE);
                for (int i = 0; i < _dataSeq.length; ++i) {
                    DDS.SampleInfo info = (DDS.SampleInfo)_infoSeq.get_at(i);
                    if (info.valid_data) {
                        _processData((HelloWorld)_dataSeq.get_at(i));
                    }
                }
            } catch (DDS.Retcode_NoData) {
                /* No data to process */
                if (_theVerbose > 0) {
                    Console.WriteLine("No data to process.");
                }
            } finally {
                HelloWorldReader.return_loan(_dataSeq, _infoSeq);
            }
        }

        public override void on_sample_lost(DDS.DataReader reader,
                                ref DDS.SampleLostStatus status) {
            ++_theSampleLost;
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: sample lost.");
            }
        }

        public override void on_requested_deadline_missed(DDS.DataReader reader,
                            ref DDS.RequestedDeadlineMissedStatus status) {
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: requested deadline missed.");
            }
        }

        public override void on_requested_incompatible_qos(DDS.DataReader reader,
                            DDS.RequestedIncompatibleQosStatus status) {
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: requested incompatible Qos.");
            }
        }

        public override void on_sample_rejected(DDS.DataReader reader,
                           ref DDS.SampleRejectedStatus status) {
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: sample rejected.");
            }
        }

        public override void on_liveliness_changed(DDS.DataReader reader,
                            ref DDS.LivelinessChangedStatus status) {
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: liveliness changed.");
            }
        }

        public override void on_subscription_matched(DDS.DataReader reader,
                           ref DDS.SubscriptionMatchedStatus status) {
            if (_theVerbose > 0) {
                Console.WriteLine("->Callback: subscription matched.");
            }
        }
    } // HelloSubscriber

    public class Hello {
        /*****************************************************************************/
        /* startApplication                                                          */
        /*                                                                           */
        /* Creates the DDS Domain Participant, then delegates the execution to the   */
        /* correct pub/sub function.                                                 */
        /* If entity creation is successful, this function does not return.          */
        /*                                                                           */
        /* Input:                                                                    */
        /*   arg: pointer to the CommandLineArguments structure                      */
        /*                                                                           */
        /*****************************************************************************/
        private static void startApplication(CommandLineArguments arg)
    {
        Console.WriteLine("# The output below depends on the QoS profile");
        Console.WriteLine("# provided to this application.");
        Console.WriteLine("# -> For more information on the provided example");
        Console.WriteLine("#    profiles, please see the Getting Started Guide.");
        Console.WriteLine("# -> For detailed product performance metrics, visit");
        Console.WriteLine("#    http://www.rti.com/products/data_distribution/index.html");
        Console.WriteLine("#    and click on Benchmarks.\n");

        /* This example creates DDS entities using the default QoS.
         * The default QoS can be modified in two ways:
         * 1. By placing a file called 'USER_QOS_PROFILES.xml' in the directory
         *    where the application is launched.
         * 2. By setting the environment variable 'NDDS_QOS_PROFILES' to point
         *    to a valid file containing NDDS QoS profile definitions.
         *
         * This section check if a QoS profile file is accessible, and prints
         * a warning if that's not true.
         */

        /* First look in the current directory to see if the USER_QOS_PROFILES.xml
         * file exist.
         */
        try
        {
            if (!File.Exists("USER_QOS_PROFILES.xml"))
            {
                /* Then look for the environment variable 'NDDS_QOS_PROFILES'... 
                 */
                String enVal = System.Environment.GetEnvironmentVariable("NDDS_QOS_PROFILES");
                if ((enVal == null) || !File.Exists(enVal))
                {
                    Console.WriteLine("! Warning:");
                    Console.WriteLine("! Default QoS profile definition file not found");
                    Console.WriteLine("! The application will use the DDS default QoS.");
                    Console.WriteLine("! If you want to use different QoS, make sure you have the QoS definition file");
                    Console.WriteLine("! (USER_QOS_PROFILES.xml) in the current working directory");
                    Console.WriteLine("! or set the environment variable NDDS_QOS_PROFILES to point");
                    Console.WriteLine("! to a file containing the default QoS profile");
                }
            }
        }
        catch (FileNotFoundException) { }
        /* If you need to customize any DDS factory QoS, uncomment the following
        * code:
        *
        try {
            DDS.DomainParticipantFactoryQos factoryQos = new DDS.DomainParticipantFactoryQos();
            DDS.DomainParticipantFactory.get_instance().get_qos(factoryQos);
            // Modify the factory QoS here

            DDS.DomainParticipantFactory.get_instance().set_qos(factoryQos);
        }
        catch (DDS.Exception e) {
            Console.Error.WriteLine("An error occurred while changing factory QoS: " + e);
        }
        */

        /* Creates the DDS Domain Participant.
         * The following command will create a DDS Domain participant
         * without installing any status callback listener.
         * If you want to create a domain participant with different QoS,
         * use DDS_DomainParticipantFactory_get_default_participant_qos
         * to obtain a copy of the default participant QoS, change them,
         * then use them instead of DDS_PARTICIPANT_QOS_DEFAULT:
         *
           DDS.DomainParticipantQos myQos = new DDS.DomainParticipantQos();
           DDS.DomainParticipantFactory.get_instance().get_default_participant_qos(myQos);

           // Modify here the participant Qos

           // Then create the domain participant using 'myQos' instead of
           //     DDS.DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT

         *
         * Note: for more info on the domain participant API see:
         *     $NDDSHOME/doc/html/api_dotnet/group__DDSDomainParticipantModule.html
         */

        if (arg.verbose > 1)
        {
            Console.WriteLine("Creating domain participant...");
        }

        DDS.DomainParticipant participant = DDS.DomainParticipantFactory.get_instance().create_participant(
                            arg.domain_id,
                            DDS.DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                            null, /* Listener */
                            DDS.StatusMask.STATUS_MASK_NONE);
        if (participant == null)
        {
            Console.Error.WriteLine("! Unable to create DDS domain participant");
            return;
        }

        /* Registers the type used in this example with the domain participant.
         * For more information on user-defined data types:
         *     $NDDSHOME/doc/html/api_dotnet/group__DDSUserDataModule.html
         */
        if (arg.verbose > 0)
        {
            Console.WriteLine("Registering the type...");
        }
        try
        {
            HelloWorldTypeSupport.register_type(
                                    participant,
                                    HelloWorldTypeSupport.get_type_name());
        }
        catch (DDS.Exception e)
        {
            Console.Error.WriteLine("! Unable to register '" + HelloWorldTypeSupport.get_type_name() +
                                    "' data type: " + e);
            return;
        }

        /* Creates the topic.
         * The following command will create the topic without
         * installing any status callback listener.
         * If you want to create a topic with different QoS,
         * use DDS.DomainParticipant.get_default_topic_qos
         * to obtain a copy of the default topic QoS, change them,
         * then use them instead of DDS_TOPIC_QOS_DEFAULT:
         *
        {
            DDS.TopicQos myQos = new DDS.TopicQos();
            participant.get_default_topic_qos(myQos);

            // Modify here the topic Qos

            // Then create the topic using 'myQos'...
        }
         *
         * Note: for more info on the topic API see:
         *     $NDDSHOME/doc/html/api_dotnet/group__DDSTopicEntityModule.html
         */

        if (arg.verbose > 0)
        {
            Console.WriteLine("Creating the topic....");
        }

        DDS.Topic topic = participant.create_topic(
                            arg.topicName,
                            HelloWorldTypeSupport.get_type_name(),
                            DDS.DomainParticipant.TOPIC_QOS_DEFAULT,
                            null, /* Listener */
                            DDS.StatusMask.STATUS_MASK_NONE);
        if (topic == null)
        {
            Console.Error.WriteLine("! Unable to create topic '" + arg.topicName);
            return;
        }


        HelloSubscriber subscriber = new HelloSubscriber(
                            participant,
                            topic,
                            arg.verbose,
                            arg.sampleCount);
            subscriber.waitForTermination();

        /* Shutdown when sample count is set */
        if (participant != null)
        {
            participant.delete_contained_entities();
            DDS.DomainParticipantFactory.get_instance().delete_participant(
                ref participant);
        }
    }

    /*****************************************************************************/
    /* usage                                                                     */
    /*                                                                           */
    /* Prints help on command line arguments accepted by this application        */
    /*****************************************************************************/
    public static void usage()
    {
        Console.WriteLine("Usage:");
        Console.WriteLine("    HelloWorld_subscriber [arguments]");
        Console.WriteLine("Where arguments are:");
        Console.WriteLine("    -h | --help               Shows this page");
        Console.WriteLine("    -v | --verbose            Increase output verbosity (can be repeated)");
        Console.WriteLine("    -d | --domain <domainID>  Sets the DDS domain ID [default=" + CommandLineArguments.DEFAULT_DOMAIN_ID + "]");
        Console.WriteLine("    -t | --topic <name>       Sets topic name [default=[" + CommandLineArguments.DEFAULT_TOPIC_NAME + "]");
        Console.WriteLine("    -s | --size <num>         Sets payload size in bytes [default=" + CommandLineArguments.DEFAULT_PAYLOAD + "]");
        Console.WriteLine("    -c | --sampleCount <num>  Sets the number of sample to send/receive [default=0(UNLIMITED)]");
        Console.WriteLine("");
    }

    /**************************************************************************
     * A simple method used to check if there are enough command line args
     */
    public static Boolean ensure_one_more_arguement(int i, String[] args, string argName)
    {
        if (i + 2 > args.Length)
        {
            usage();
            Console.WriteLine("! Error: missing value for " + argName + " argument");
            return false;
        }
        return true;
    }


    /*****************************************************************************/
    /* main                                                                      */
    /*                                                                           */
    /* Application main entry point                                              */
    /*****************************************************************************/
    public static void Main(string[] argv)
    {
        CommandLineArguments args = new CommandLineArguments();

        Console.WriteLine("Hello Example Application");
        Console.WriteLine("Copyright 2008 Real-Time Innovations, Inc.");

        /* Parse the arguments */
        for (int i = 0; i < argv.Length; ++i)
        {
            if (argv[i].Equals("-h") || argv[i].Equals("--help"))
            {
                usage();
                return;
            }

            if (argv[i].Equals("-v") || argv[i].Equals("--verbose"))
            {
                ++args.verbose;
                continue;
            }

            if (argv[i].Equals("-d") || argv[i].Equals("--domain"))
            {
                if (!(ensure_one_more_arguement(i, argv, "--domain")))
                {
                    return;
                }
                args.domain_id = Int32.Parse(argv[++i]);
                if (args.domain_id < 0 || args.domain_id > CommandLineArguments.DOMAIN_ID_MAX)
                {
                    usage();
                    Console.Error.WriteLine("! Invalid DDS Domain ID: " + args.domain_id);
                    Console.Error.WriteLine("! The domain ID must be between 0 and " +
                            CommandLineArguments.DOMAIN_ID_MAX + " (inclusive)");
                    return;
                }
                continue;
            }

            if (argv[i].Equals("-s") || argv[i].Equals("--size"))
            {
                if (!ensure_one_more_arguement(i, argv, "--size"))
                {
                    return;
                }
                args.dataSize = Int32.Parse(argv[++i]);
                if (args.dataSize <= 0)
                {
                    usage();
                    Console.Error.WriteLine("! Invalid value for --size argument: " +
                    args.dataSize);
                    return;
                }
                if (args.dataSize > HELLODDS_MAX_PAYLOAD_SIZE.VALUE)
                {
                    usage();
                    Console.Error.WriteLine("! Invalid value for --size argument: " +
                            args.dataSize + "data too big (max value is " +
                            HELLODDS_MAX_PAYLOAD_SIZE.VALUE + ")");
                }
                continue;
            }
            if (argv[i].Equals("-t") || argv[i].Equals("--topic"))
            {
                if (!ensure_one_more_arguement(i, argv, "--topic"))
                {
                    return;
                }
                args.topicName = argv[++i];
                continue;
            }
            if (argv[i].Equals("-c") || argv[i].Equals("--sampleCount"))
            {
                if (!ensure_one_more_arguement(i, argv, "--sampleCount"))
                {
                    return;
                }
                args.sampleCount = Int32.Parse(argv[++i]);
                if (args.sampleCount < 0)
                {
                    usage();
                    Console.Error.WriteLine("! Invalid value for --sampleCount argument: " +
                    args.sampleCount);
                    return;
                }
                continue;
            }
            /* Else, it is an invalid argument */
            usage();
            Console.Error.WriteLine("! Unknown argument " + argv[i]);
            return;
        } /* foreach argument */

        if (args.verbose > 0)
        {
            DDS.ProductVersion_t prodVersion =
                NDDS.ConfigVersion.get_instance().get_product_version();
            Console.WriteLine("Running with the following arguments:");
            Console.WriteLine("    Verbosity level.. : " + args.verbose);
            Console.WriteLine("    Payload size..... : " + args.dataSize);
            Console.WriteLine("    Sample count..... : " + args.sampleCount);
            Console.WriteLine("    Domain ID........ : " + args.domain_id);
            Console.WriteLine("    Topic name....... : " + args.topicName);
            Console.WriteLine("RTI Product Version.. : " + prodVersion.major + "." +
                                prodVersion.minor + prodVersion.release +
                                "(rev " + prodVersion.release + ")");

            /* Alternatively, you can print all the components of the 
             * NDDS.ConfigVersion object with a single call to:
             *       NDDS.ConfigVersion.get_instance().to_string()
             */
        }

        /* If the verbosity is bigger than 1, also turn on RTI DDS status logging
         * For more info, see: 
         *      $NDDSHOME/doc/html/api_dotnet/group__NDDSConfigModule.html
         */
        if (args.verbose > 1)
        {
            NDDS.ConfigLogger.get_instance().set_verbosity_by_category(
                NDDS.LogCategory.NDDS_CONFIG_LOG_CATEGORY_API,
                NDDS.LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        }

        /* Finally, starts the application */
        startApplication(args);

        /* startApplication terminates if sample count is set */
        Console.WriteLine("Done.");
        return;
    }
}
}
