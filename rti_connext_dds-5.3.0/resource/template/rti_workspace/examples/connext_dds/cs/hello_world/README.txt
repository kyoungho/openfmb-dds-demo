======================
C# Hello World Example
======================

An example publication and subscription pair to send and receive simple strings.

Purpose
=======

This example shows how to perform basic publish-subscribe communication.

For convenience, complete source code and sample makefiles for several
architectures have been provided.  you may also generate your own
makefile or project file with rtiddsgen if you want to run the example
in other architectures.

Optional
--------
If you do not wish to use the supplied projects you may use rtiddsgen to
generate solution and project files for your machine's architecture and compiler.
For example, if both the publisher and the subscriber application
will run on 64-bit Windows machines and you want to compile with Visual Studio
2015 run rtiddsgen for the x64Win64VS2015 architecture:

rtiddsgen -language C# -example x64Win64VS2015 src\HelloWorld.idl

This will create solution, project files & type support files in the
src directory.  You may get messages saying that some files already exist and
will not be replaced. You can safely ignore those messages since all the
source files for this example are already provided.  You may specify
an alternate output with the -d option of rtiddsgen.


Setting up the Environment
--------------------------
Set the NDDSHOME environment variable to your RTI Connext installation
directory.  Set the PATH environment variable to include
%NDDSHOME%\lib\<architecture> where <architecture> is your Connext DDS
architecture, e.g. x64Win64VS2015.

Compiling this Example
----------------------
1. Open the solution file for your architecture with Visual Studio.

2. In Visual Studio, select the Mixed Platforms Release configuration in the standard 
   toolbar.

3. From the Build menu, select Build Solution. This will build the 
   HelloWorld_type, HelloWorld_publisher and HelloWorld_subscriber projects.

Running this Example
--------------------

1. After compiling, you will find the application executables in 
   the 'bin\Release' directory created by rtiddsgen. 

2. Open two command prompt windows in the 'bin\Release' directory.

3. Run the subscriber by typing the following at a command prompt:

   bin\[x64\]<Debug|Release>-VS<vs_version>\HelloWorld_subscriber.exe <Domain_ID> <Number_of_Samples>

   (The two optional arguments are explained below.)

4. Run the publisher by typing the following at the other command prompt:

   bin\[x64\]<Debug|Release>-VS<vs_version>\HelloWorld_publisher.exe <Domain_ID> <Number_of_Samples>


Both applications accept two optional arguments:

<Domain_ID>: In order for the two applications to communicate, 
             they have to use the same domain ID number. By default, 
             both Hello World applications use domain ID 0. 

             If you want to use a specific domain ID, enter it as the first 
             argument (valid IDs are >=0). If you are sharing a machine with 
             others, you may want to use separate domain IDs.

<Number_of_Samples>: In the publishing application, the second parameter is 
                     the number of samples to publish before terminating. 
                     
                     In the subscribing application, the second parameter is 
                     the number of 4-second intervals for which it will 
                     sleep/awake before terminating.
Optional
========

You can specify the list of nodes that you want to talk to in an environment 
variable or a file called NDDS_DISCOVERY_PEERS. If your platform does not 
support multicast, or has multicast disabled by default, you must set this
list.

Please consult the Platform Notes and online documentation for details.
