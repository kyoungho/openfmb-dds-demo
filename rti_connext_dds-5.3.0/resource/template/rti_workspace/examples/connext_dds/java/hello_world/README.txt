========================
Java Hello World Example
========================

An example publication and subscription pair to send and receive simple strings.

Purpose
=======

This example shows how to perform basic publish-subscribe communication.

How to compile and run
======================

Make sure the environment variable NDDSHOME is defined before compiling
or running the example.

Before compiling, make sure that the desired version of javac compiler
is in your PATH environment variable.

Compiling this Example
----------------------
To build this example on Windows, type the following in a command shell:

  > build

To build this example on a UNIX-based system, type the following in a command
shell:

  > ./build.sh

To remove all the generated files (.class files), just delete the 'objs'
directory. 

On Unix:
  > rm -Rf objs

On Windows
  > RD /S /Q OBJS

Running this Example
--------------------
To run this example on Windows, type the following in two different command
shells, either on the same machine or on different machines:

  > runSub <Domain_ID> <Number_of_Samples>
  > runPub <Domain_ID> <Number_of_Samples>

To run this example on a UNIX-based system, type the following in two
different command shells, either on the same machine or on different machines:

  > ./runSub.sh <Domain_ID> <Number_of_Samples>
  > ./runPub.sh <Domain_ID> <Number_of_Samples>

If you are running on a 64-bit UNIX-based system, you may need to set
RTI_JAVA_OPTION to -d64 before running the above commands.

For more information, please consult your "Getting Started Guide."

Optional
========
You can specify the list of nodes that you want to talk to in an environment 
variable or a file called NDDS_DISCOVERY_PEERS. If your platform does not 
support multicast, or has multicast disabled by default, you must set this
list.

Please consult the Platform Notes and online documentation for details.

Both applications accept two optional arguments:

<Domain_ID>: 
In order for the two applications to communicate, they have to use the 
same domain ID number. By default, both Hello World applications use
domain ID 0. 

If you want to use a specific domain ID, enter it as the first argument 
(valid IDs are >=0). If you are sharing a machine with others, you may
want to use separate domain IDs.

<Number_of_Samples>: 
In the publishing application, the second parameter is used as the number of
samples to publish before terminating. 
In the subscribing application, the second parameter is used as the number of
4-second intervals for which it will sleep/awake before terminating.
