=====================================================
RTI Connext News Example Application
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
To build this, open the appropriate solution file for your version of
Microsoft Visual Studio in the win32 directory.


Running this Example
--------------------
To run this example, type the following in two different command shells,
either on the same machine or on different machines:

  > bin\[Release|Debug]-VS<vs_version>\News.exe sub [arguments]
  > bin\[Release|Debug]-VS<vs_version>\News.exe pub [arguments]

For more information, please consult your "Getting Started Guide."

Optional arguments
===================
-h | --help : shows help message
-v | --verbose : Increase output verbosity (can be repeated)
-d | --domain <domainID> : Sets the DDS domain ID [default=%d]
-r | --runSeconds <integer> : Sets the number of seconds to run [default=20]
-f | --filterExpression <SQL> : Sets a content filter on the data
