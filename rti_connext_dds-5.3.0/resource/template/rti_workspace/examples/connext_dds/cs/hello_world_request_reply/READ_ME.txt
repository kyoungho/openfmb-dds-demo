=====================================================
RTI Connext Hello_world_request_reply Example Application
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

To run this example, type the following in two different command shells,
either on the same machine or on different machines:

  bin\[x64\]<Debug|Release>-VS<vs_version>\PrimeNumberReplier.exe [<domain_id>]
  bin\[x64\]<Debug|Release>-VS<vs_version>\PrimeNumberRequester.exe <n> [<primes_per_reply> [<domain_id>]]

For example, if you are running the release 64-bit version of
Visual Studio 2015 requester the command is: 

  bin\x64\Release-VS2015\PrimeNumberRequester.exe <n> [<primes_per_reply> [<domain_id>]]

The Requester and the Replier are configured by the file USER_QOS_PROFILES.xml
located in this directory. You can modify this file to change the example's
behavior.

For more information on using Requesters and Repliers, please consult the 
RTI Core Libraries and Utilities Getting Started Guide and User's Manual.

