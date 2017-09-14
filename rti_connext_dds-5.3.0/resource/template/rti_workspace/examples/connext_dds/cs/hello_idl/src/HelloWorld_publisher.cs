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

namespace Hello {
    public class CommandLineArguments
    {
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

        public CommandLineArguments()
        {
            domain_id = DEFAULT_DOMAIN_ID;
            mode = APP_MODE_UNDEFINED;
            dataSize = DEFAULT_PAYLOAD;
            sampleCount = 0;
            verbose = 0;
            topicName = DEFAULT_TOPIC_NAME;
        }
    }
    /**
     * Manage the data publication for the Hello example 
     */
    class HelloPublisher {
        /* Maximum consecutive write error after stopping the write process */
        private const int MAX_CONSECUTIVE_WRITE_ERROR = 5;

        private HelloWorldDataWriter _theDataWriter;
        private int _theDataSize;
        private int _theVerbose;
        private int _theSampleCount;


        // ************************************************************************

        /**
         * Builds a new HelloPublisher object and initialize the inner DDS 
         * entities.
         * This method only creates the entities, but it does not actually write
         * the data.
         * To write the data, use the method writeSamples().
         *  
         * @param participant the DDS Domain participant
         * @param topic       the DDS topic 
         * @param verbose     an integer to control the output verbosity
         * @param dataSize    the size of the payload data
         */

        public HelloPublisher(DDS.DomainParticipant participant,
                              DDS.Topic topic,
                              int verbose,
                              int dataSize,
                              int sampleCount) {
            _theDataSize = dataSize;
            _theVerbose = verbose;
             _theSampleCount = sampleCount;

            /** Create the publisher. 
             * Just like the participant, if you want to customize the publisher QoS,
             * use DDS.DomainParticipant.get_default_publisher_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             *     DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT.
             * For more info on publisher API, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSPublisherModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating publisher...");
            }
            DDS.Publisher publisher = participant.create_publisher(
                            DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT,
                            null, /* Listener */
                            DDS.StatusMask.STATUS_MASK_NONE);
            if (publisher == null) {
                Console.Error.WriteLine("! Unable to create DDS Publisher");
                return;
            }

            /* Creates the DDS Data writer. 
             * Just like before, if you want to customize the writer QoS,
             * use DDS.Publisher.get_default_datawriter_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             * DDS_DATAWRITER_QOS_DEFAULT.
             * For more data writer API info, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSWriterModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating the data writer...");
            }
            _theDataWriter = (HelloWorldDataWriter)
                publisher.create_datawriter(topic,
                                DDS.Publisher.DATAWRITER_QOS_DEFAULT,
                                null, /* Listener */
                                DDS.StatusMask.STATUS_MASK_NONE);
            if (_theDataWriter == null) {
                Console.Error.WriteLine("! Unable to create DDS data writer");
                return;
            }
        }

        // ************************************************************************

        /**
         * Writes samples to DDS. This method never returns.
         */
        public void writeSamples() {
            HelloWorld instance = new HelloWorld();

            /* Initialize the data */
            instance.prefix = "Hello world";
            instance.payload.ensure_length(_theDataSize, _theDataSize);
            byte[] arr = instance.payload.buffer;
            for (int i = 0; i < _theDataSize; ++i) {
                arr[i] = (byte)(i % 0xff);
            }
            Console.WriteLine("Sending data...");
            int consecutiveErrors = 0;
            for (instance.sampleId = 0; ;
                ++(instance.sampleId)) {
                try {
                    _theDataWriter.write(instance, ref DDS.InstanceHandle_t.HANDLE_NIL);
                    /* Always clear the error count in case of successful write */
                    consecutiveErrors = 0;
                }
                catch (DDS.Retcode_Error e) {
                    Console.Error.WriteLine("! Write error " +
                            e.GetType() + ": " + e.Message);
                    if (++consecutiveErrors > MAX_CONSECUTIVE_WRITE_ERROR) {
                        Console.WriteLine("! Reached maximum number of failure, stopping writer...");
                        return;
                    }
                }
                if (_theVerbose > 0 && (instance.sampleId % 10000) == 0) {
                    Console.WriteLine("Sent " +
                        instance.sampleId + " samples...");
                }
                 if (_theSampleCount != 0 && (instance.sampleId >= _theSampleCount)) {
                    Console.WriteLine("Sent " + instance.sampleId + " samples.");
                    break;
                }
            }
        }
    }
    public class Hello
    {
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


            HelloPublisher publisher = new HelloPublisher(
                                participant,
                                topic,
                                arg.verbose,
                                arg.dataSize,
                                arg.sampleCount);
                publisher.writeSamples();

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
            Console.WriteLine("    HelloWorld_publisher [arguments]");
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

            /* Ensure there are enough arguments in the command line */

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