=====================================================
RTI Connext (formerly, RTI Data Distribution Service)
News Example Application
=====================================================

Welcome to Connext.


Compiling this Example
----------------------

Before compiling make sure that the environment variable NDDSHOME is defined 
and that it refers to your RTI Connext installation directory. 

To build this example on Windows, open the appropriate solution file for your
version of Microsoft Visual Studio in the win32 directory.

To build this example on a UNIX-based system, type the following in a command
shell:

  > gmake -f make/makefile_News_<architecture>


Running this Example
--------------------
To run this example on Windows, type the following in two different command
shells, either on the same machine or on different machines:

  > objs\<architecture>\News.exe sub [arguments]
  > objs\<architecture>\News.exe pub [arguments]

To run this example on a UNIX-based system, type the following in two
different command shells, either on the same machine or on different machines:

  > objs/<architecture>/News sub [arguments]
  > objs/<architecture>/News pub [arguments]

For more information, please consult your "Getting Started Guide."

Optional arguments
===================
-h | --help : shows help message
-v | --verbose : Increase output verbosity (can be repeated)
-d | --domain <domainID> : Sets the DDS domain ID [default=%d]
-r | --runSeconds <integer> : Sets the number of seconds to run [default=20]
-f | --filterExpression <SQL> : Sets a content filter on the data
