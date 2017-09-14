=====================================================
RTI Connext Hello_dynamic Example Application
=====================================================

Welcome to Connext.


Setting up the Environment
--------------------------
Set the NDDSHOME environment variable to your RTI Connext installation
directory.  Set the PATH environment variable to include
%NDDSHOME%\lib\<architecture> where <architecture> is your Connext DDS
architecture, e.g. x64Win64VS2015.

Compiling this Example
----------------------
To build this example, open the appropriate solution file for your version of
Microsoft Visual Studio in the win32 directory.


Running this Example
--------------------
This example application is configured by the file USER_QOS_PROFILES.xml
located in this directory. You can modify this file to change the example's
behavior, or you can replace it entirely with the contents of one of the
example files in the <path to examples>/connext_dds/qos/ directory.

To run this example, type the following in two different command shells,
either on the same machine or on different machines:

  > bin\[Debug|Release]-VS<vs_version>\Hello.exe sub [arguments]
  > bin\[Debug|Release]-VS<vs_version>\Hello.exe pub [arguments]

For example, if you are running the Release 64-bit Visual Studio 2015 publisher
the command is: 

   > bin\x64\Release-vs2015\Hello.exe pub

For more information, please consult your "Getting Started Guide."

Optional arguments
===================
-h | --help : shows help message
-v | --verbose : Increase output verbosity (can be repeated)
-d | --domain <domainID> : Sets the DDS domain ID [default=%d]
-t | --topic <name>  :  Sets topic name [default=%s]
-s | --size <num> : Sets payload size in bytes [default=%d]
-c | --sampleCount <num> : Sets number of samples to send/receive [default=0(UNLIMITED)]

