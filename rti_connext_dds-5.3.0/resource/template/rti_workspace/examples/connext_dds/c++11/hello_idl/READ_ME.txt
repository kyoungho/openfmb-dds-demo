=====================================================
RTI Connext Hello_idl Example Application
=====================================================

Welcome to Connext.


Generating Source Code
----------------------
All of the required source code has been shipped however if you should wish to
change the data sent, edit the HelloWorld.idl file and re-generate the type
support and plugin files by entering the following at a command prompt:

on Unix:   rtiddsgen -language C++11 -stl -ppDisable -d src -replace src/HelloWorld.idl
on Windows: rtiddsgen -language C++11 -stl -ppDisable -d src -replace src\HelloWorld.idl

If your compiler doesn't support C++11, you can change the language for C++03.
The flag -stl is optional, it will generate code with STL types for the type
definition and type plugin.

Compiling this Example
----------------------

Before compiling make sure that the environment variable NDDSHOME is defined 
and that it refers to your RTI Connext installation directory. 

To build this example on Windows, open the appropriate solution file for your
version of Microsoft Visual Studio in the win32 directory.

To build this example on a UNIX-based system, type the following in a command
shell:

  > gmake -f make/makefile_Hello_<architecture>


Running this Example
--------------------
This example application is configured by the file USER_QOS_PROFILES.xml
located in this directory. You can modify this file to change the example's
behavior, or you can replace it entirely with the contents of one of the
example files in the example/QoS/ directory.

To run this example on Windows, type the following in two different command
shells, either on the same machine or on different machines:

  > objs\<architecture>\Hello.exe sub [arguments]
  > objs\<architecture>\Hello.exe pub [arguments]

To run this example on a UNIX-based system, type the following in two
different command shells, either on the same machine or on different machines:

  > objs/<architecture>/Hello sub [arguments]
  > objs/<architecture>/Hello pub [arguments]

For more information, please consult your "Getting Started Guide."

Optional arguments
===================
-h | --help : shows help message
-v | --verbose : Increase output verbosity (can be repeated)
-d | --domain <domainID> : Sets the DDS domain ID [default=%d]
-t | --topic <name>  :  Sets topic name [default=%s]
-s | --size <num> : Sets payload size in bytes [default=%d]
-c | --sampleCount <num> : Sets number of samples to send/receive [default=0(UNLIMITED)]
