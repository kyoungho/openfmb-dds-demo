=====================================================
RTI Connext Hello_idl Example Application
=====================================================

Welcome to Connext.


Setting up the Environment
--------------------------
Set the NDDSHOME environment variable to your RTI Connext installation
directory.  Set the PATH environment variable to include
%NDDSHOME%\lib\<architecture> where <architecture> is your Connext DDS
architecture, e.g. x64Win64VS2015.

Generating Source Code
----------------------
All of the required source code has been shipped however if you should wish to
change the data sent, edit the HelloWorld.idl file and re-generate the type
support and plugin files by entering the following at a command prompt:

    rtiddsgen -language C# -ppDisable -d src -replace src\HelloWorld.idl


Compiling this Example
----------------------
To build this example, open the appropriate solution file for your 
architecture in the win32 directory.  Select the desired configuration
and build the publisher and subscriber projects.


Running this Example
--------------------
This example application is configured by the file USER_QOS_PROFILES.xml
located in this directory. You can modify this file to change the example's
behavior, or you can replace it entirely with the contents of one of the
example files in the <path to examples>/connext_dds/qos/ directory.

  > bin\[x64\][Debug|Release]-VS<vs_version>\HelloWorld_publisher.exe 
  > bin\[x64\][Debug|Release]-VS<vs_version>\HelloWorld_subscriber.exe

For more information, please consult your "Getting Started Guide."

Optional arguments
===================
-h | --help : shows help message
-v | --verbose : Increase output verbosity (can be repeated)
-d | --domain <domainID> : Sets the DDS domain ID [default=%d]
-t | --topic <name>  :  Sets topic name [default=%s]
-s | --size <num> : Sets payload size in bytes [default=%d]
-c | --sampleCount <num> : Sets number of samples to send/receive [default=0(UNLIMITED)]

