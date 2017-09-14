=====================================================
RTI Connext HelloWorld_xml_dynamic Example Application
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

  > bin\x64\<Debug|Release>-vs<vs_version>\Hello.exe pub
	The executable may receive one additional argument:
    - Number of samples to send

  > bin\x64\<Debug|Release>-vs<vs_version>\Hello.exe sub
	The executable may receive one additional argument:
    - Number of samples to receive

For more information, please consult your "Getting Started Guide."
