========================================
RTI Connext Hello_world_xml_compiled Example Application
========================================

Welcome to Connext.

This example is a modified version of the helloWorld example that can
be generated using rtiddsgen with the -example command-line option.


Setting up the Environment
--------------------------
Set the NDDSHOME environment variable to your RTI Connext installation
directory.  Set the PATH environment variable to include
%NDDSHOME%\lib\<architecture> where <architecture> is your Connext DDS
architecture, e.g. i86Win32VS2013.

Compiling this Example
----------------------
Use rtiddsgen to generate the solution and project files for your
version of Visual Studio. For example, if both the publisher and the
subscriber application will be compiled with Visual Studio 2013,
run rtiddsgen for the i86Win32VS2013 architecture:

%NDDSHOME\bin\rtiddsgen -language C# -example i86Win32VS2013 HelloWorld.idl

NOTE: You may get messages saying that some files already exist and will
not be replaced. You can safely ignore those messages, since all the
source files for this example are already provided.


Open the solution file for your architecture with Visual Studio. Build the
two projects, HelloWorld_publisher and HelloWorld_subscriber, with the 
Win32 Release setting (or Win32 Debug settings if you prefer).

Running this Example
--------------------

1.  In your library search path, you MUST have the location of 
    the RTI Connext DDS shared libraries, because the applications
    will load the shared object dynamically when they start.

2. On one machine, run the publisher:

   The executable may receive one arguments:
   - Number of samples to send

   bin\[x64\]<Debug|Release>-VS<vs_version>\HelloWorld_publisher.exe 


4. On another machine or terminal, run the subscriber:

   The executable may receive one argument:
   - Number of samples to receive

   bin\[x64\]<Debug|Release>-VS<vs_version>\HelloWorld_subscriber.exe
