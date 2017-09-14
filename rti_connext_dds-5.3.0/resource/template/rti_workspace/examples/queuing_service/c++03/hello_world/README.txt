===========================================================================
 Example Code -- HelloWorld example of interaction with RTI Queuing Service
===========================================================================

This example is a modified version of the helloWorld example that can
be generated using rtiddsgen with the -example command-line option.
The original example was modified to use create a QueueRequester and 
a QueueReplier that communicate with RTI Queuing Service.

The example works with rtiddsgen generated types.

Building Modern C++ Example
===========================

Before compiling or running the example, make sure the environment variable 
NDDSHOME is defined and it refers to your RTI Connext DDS installation directory. 

Run rtiddsgen with the -example option and the target architecture of your 
choice (e.g., x64Linux2.6gcc4.4.5).
 
Do not use the -replace option. Do not replace the following files included 
with this example:
- HelloWorldQueue_publisher.cxx
- HelloWorldQueue_subscriber.cxx
- USER_QOS_PROFILES.xml

This example also shows the unbounded sequence and string feature. This requires
you to generate the code with the -unboundedSupport option.

For example, assuming you want to generate an example for the architecture 
x64Linux2.6gcc4.4.5, run:

   rtiddsgen -language C++03 -example x64Linux2.6gcc4.4.5 -ppDisable 
             -unboundedSupport HelloWorldQueue.idl

After running rtiddsgen, you will see messages that look like this:

	WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be 
	overwritten : C:\Users\test\Documents\rti_workspace\5.2.0\examples\queuing_service\
	CPP2\helloWorld\HelloWorldQueue_subscriber.cxx
	WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be 
	overwritten : C:\Users\test\Documents\rti_workspace\5.2.0\examples\queuing_service\
	CPP2\helloWorld\HelloWorldQueue_publisher.cxx

This is normal output and is only informing you that the publisher code has
not been replaced, which is fine since all the source files for the example are
already provided.

The generated projects will include the publisher and subscriber files 
(HelloWorldQueue_publisher.cxx and HelloWorldQueue_subscriber.cxx).


Command-Line Parameters
=======================

HelloWorldQueue_publisher
Usage: 
-d <domainId>              default: 0
-e <entityName>            default: <none>
-r <sharedSubscriberName>  default: SharedSubscriber
-q <requestQueueTopicName> default: HelloWorldTopic
-p <qosProfileName>        default: <none>
-c <requestCount>          default: 0 - UNLIMITED -
-s <requestPerSecond>      default: 1000
-l <requestPayloadLength>  default: 32
-a <waitForAck>            default: 1

HelloWorldQueue_subscriber
Usage: 
-d <domainId>              default: 0
-e <entityName>            default: <none>
-r <sharedSubscriberName>  default: SharedSubscriber
-q <requestQueueTopicName> default: HelloWorldTopic
-p <qosProfileName>        default: <none>


Running Modern C++ Example
==========================

NOTE: When running the following scenarios, you might see some "Cannot reach locator" 
messages. These messages are harmless and expected. They appear due to the fact 
that in this example RTI Queuing Service has multiple transports enabled while publisher 
and subscriber applications have only one transport enabled at a time in each scenario.

** Scenario 1: 1Requester/1Replier/1QS UDP VOLATILE **

1. This example requires RTI Queuing Service. In one terminal, from 
   the example installation directory, enter:

   %NDDSHOME%\bin\rtiqueuingservice.bat -cfgFile QsHelloWorld.xml 
          -cfgName HelloWorldQS

2. On another terminal, run the subscriber.

   The executable is here:

   objs/x64Linux2.6gcc4.4.5/HelloWorldQueue_subscriber

3. On another terminal, run the publisher. 

   The executable is here:

   objs/x64Linux2.6gcc4.4.5/HelloWorldQueue_publisher 

   To change publication rate use -s
   To change data size use -l

** Scenario 2: 1Requester/1Replier/1QS UDP PERSISTENT **

1. Delete any previously created database files in the example directory.
2. Run RTI Queuing Service using -cfgName HelloWorldQSPersistence.
3. Run the publisher. 
4. Run the subscriber.

** Scenario 3: 1Requester/1Replier/2ReplicatedQS UDP VOLATILE **

1. Run two RTI Queuing Service instances using -cfgName HelloWorldQSReplication.
2. Run the publisher. 
3. Run the subscriber.

** Scenario 4: 1Requester/1Replier/2ReplicatedQS UDP PERSISTENT **

1. Delete any previously created database files in the example directory.
2. Run two RTI Queuing Service instances using -cfgName HelloWorldQSPersistenceReplication.
   Make sure you use different -appName argument for each of the instances (e.g. instance1 and instance2)
3. Run the publisher. 
4. Run the subscriber.

** Scenario 5: 1Requester/1Replier/1QS TCP from Requester-to-QS UDP from QS-to-Replier VOLATILE **

1. Edit the file QsHelloWorld.xml and replace the Queuing Service IP address 
   in the transport property "dds.transport.tcp.public_address" with
   the IP address where Queuing Service is running. Do not remove the port from the IP address.
   
2. Run one RTI Queuing Service instance using -cfgName HelloWorldQS.

3. Run the publisher using the QoS profile (parameter -p) HelloWorldQueue_Library::HelloWorldQueue_ProfileTCPLargeData.

   You will also have to set the initial peers to point to the QS. For example:

   set NDDS_DISCOVERY_PEERS=tcpv4_wan://<Queuing Service IP>:15000

4. Run the subscriber using the QoS profile HelloWorldQueue_Library::HelloWorldQueue_ProfileTCPLargeData.

   You will also have to set the initial peers to point to the QS. For example:

   set NDDS_DISCOVERY_PEERS=tcpv4_wan://<Queuing Service IP>:15000
