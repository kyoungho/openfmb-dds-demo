==========================================================================
 Example Code -- Sending commands to RTI Queuing Service via Request/Reply
==========================================================================

See Chapter 5 in Queuing Service User's Manual for details on
Remote Administration

Compiling this Example
=======================
1. Before compiling or running the example, make sure the environment variable 
   NDDSHOME is set to the directory where your version of RTI Connext DDS is 
   installed.

2. This example requires you to generate code from two different IDL files:
   * ServiceAdmin.idl contains the CommandRequest and CommandReply types
     used by RTI Queuing Service. You will need to use the -example 
     command-line option to generate the executable's Visual Studio projects. 
   * QueuingServiceTypes.idl contains the types required to parse
     the CommandReply sent by Queuing Service after executing some commands.

   Run rtiddsgen with the -example option and the target architecture of your 
   choice (e.g., i86Win32VS2010) on ServiceAdmin.idl. 
   Do NOT use the -replace option.

   For example, assuming you want to generate an example for the architecture 
   i86Win32VS2010, run:

   $(NDDSHOME)/bin/rtiddsgen.bat -example <arch> -language C++ -namespace -unboundedSupport -ppDisable ServiceAdmin.idl

   After running rtiddsgen, you will see messages that look like this:

	WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be 
	overwritten : C:\Users\test\Documents\rti_workspace\5.2.0\examples\queuing_service\
	cs\remoteConfig\ServiceAdmin_publisher.cxx

   This is normal output and is only informing you that the publisher code has
   not been replaced, which is fine since all the source files for the example 
   are already provided.

3. Run rtiddsgen on QueuingServiceTypes.idl:

   $(NDDSHOME)/bin/rtiddsgen.bat -language C++ -namespace -unboundedSupport -ppDisable QueuingServiceTypes.idl

4. Open the makefile/solution generated at step 2 and add the files generated in the 
   previous.

   4.a Unix/Makefile:
   	- Open the generated makefile and add QueuingServiceTypes.cxx QueuingServiceTypesPlugin.cxx QueuingServiceTypesSupport.cxx to the
	COMMONSOURCES variable

	- Add "-lrticonnextmsgcppz" to the LIBS variable just before the "-lnddscppz" library
	
   4.b Visual studio:

	- Add the generated C++ support files for QueuingServiceTypes.idl 
         (QueuingServiceTypes*) to the ServiceAdmin_publisher project 
        (Project > Add existing item)

	- Since RTI Connext Messaging is required, you need to add the the library rticonnextmsgcpp[z][d].lib to the ServiceAdmin_publisher
	properties (Project Properties > Configuration Properties > Linker > Input >  Additional dependencies)
 

The solution file generates two executables: a publisher and a subscriber. 
This example only needs the publisher executable, which represents a 
Queuing Service command requester.


Running the C++ Example
======================

1. This example requires RTI Queuing Service. For instance, you can run the RemoteConfigQS configuration
	provided in the C++ hello_world example:

       rtiqueuingservice -cfgFile <hello_world C++ example path>/QsHelloWorld.xml -cfgName RemoteConfigQS

2. In a command prompt window, run the publisher/requester application.

       objs/<architecture>/ServiceAdmin_publisher.exe [args]

   [args] can be: 
	-d <domainId> -q <serviceName> -o <profileName> [create|delete|get] <resourceIdentifier> {command options}
	-d <domainId>     default: 1
	-q <serviceName>  default: RemoteConfigQS
	-o <profileName>  default: <none>
	{create options}: -s <sessionName> -p <topicName> -t <typeName> -r <replyTypeName>
	-s <sessionName>    default: Session
	-p <topicName>      default: HelloWorldTopic
	-t <typeName>       default: HelloWorld
	{delete options}: <sampleSelector>
	{get options}:    <sampleSelector>

   You must enter create, delete, or get, followed by a [resourceIdentifier] (which is 
   described in the Queuing Service User's Manual).
 
   create   Creates a new shared reader queue. 
            After "create [resourceIdentifier]" you may specify the following (all are optional):
            -s <sessionName>   Name of session to be used by created queue. (Default: Session)
            -p <topicName>     Topic/queue name. (Default:HelloWorldTopic)
            -t <typeName>      Type of the Topic/queue. (Default: HelloWorld)

   delete   Deletes an existing resource specified by the resource identifier.
            After "delete [resourceIdentifier]" you may specify the following (optional):
            [sampleSelector]  When the resource identifies messages in the queues, 
                              the sample selector allows you to specify the subset
                              of messages in the queue that will be deleted. (Default: empty)

   get      Retrieves an existing resource specified by the resource identifier.
            After "get [resourceIdentifier]" you may specify the following (optional):         
            [sampleSelector]  When the resource identifies messages in the queues, 
                              the sample selector allows you to specify the subset 
                              of messages in the queue that will be retrieved. (Default: empty)
Workflow Use Case
==================

The following steps show how to use the different available commands
and the expected results.

1. Start RTI Queuing Service with remote administration enabled. For instance, 
   you can use the configuration file from the RTI Queuing Service hello_world C++ example:

     rtiqueuingservice -cfgFile <hello_world example path>/QsHelloWorld.xml -cfgName RemoteConfigQS

2. Create a SharedReaderQueue in an existing SharedSubscriber. You can use the 
   topic and type names used by your producer and consumer application:

     ServiceAdmin_publisher.exe  \
	  create /domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber \
	  -p HelloWorldTopic -t HelloWorld 

3. List all the available queues in the running Queuing service instance. This 
   should show you all the queues that were initially in the configuration plus
   the one you just created in step 2:

     ServiceAdmin_publisher.exe get /data

4. Run your producer application and send some messages to the recently created 
   queue. (See the Hello World example for details on how to do this.).

5. Retrieve the status of the queue. Make sure that the retrieved status 
   information is accurate:
	
     ServiceAdmin_publisher.exe get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/status

6. Get all the undelivered messages from the recently created queue. Since 
   there are no consumers, you should get as many messages as you sent in step 4:

     ServiceAdmin_publisher.exe get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS"

7. Delete all the messages from the recently created queue:

     ServiceAdmin_publisher.exe delete \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS"

8. Get all the messages from the recently created queue. Since you flushed the queue in 
   the previous step, you should get no messages:

     ServiceAdmin_publisher.exe get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS OR @sample_queue_status=SENT_MESSAGE_STATUS" 

9. Delete the recently created queue:

     ServiceAdmin_publisher.exe delete \
       /domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic

10. List all the available queues in the running Queuing Service instance. This should only show 
    you the queues that were initially in the configuration when the service was loaded:

	ServiceAdmin_publisher.exe get /data


