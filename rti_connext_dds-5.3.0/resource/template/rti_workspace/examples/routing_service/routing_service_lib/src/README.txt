********************************
*** Linux type architectures ***
********************************

On the host and target machines, set the environment variable NDDSHOME to your
RTI Connext DDS installation directory.

For example:

> setenv NDDSHOME /opt/RTI/ndds.x.y.z

On the host machine, compile by typing

> gmake -f make/Makefile.<architecture>

On the target machine, add NDDSHOME/lib/<architecture> to your LD_LIBRARY_PATH
so that the contained libraries can be loaded by your OS.

For example:

> setenv LD_LIBRARY_PATH ${NDDSHOME}/lib/<architecture>

Run the application from the example directory. For example:

cd ~/rti_workspace/<RTI Connext version>/examples/routing_service/routing_service_lib
./objs/<architecture>/RunRoutingService src/MyString.xml

Run a publisher on domain 0 and a subscriber on domain 1; the subscriber will
receive the data being published on domain 1.

*******************************
***      Visual Studio      ***
*******************************

Set the environment variable NDDSHOME to your RTI Connext DDS

installation directory.
Also add NDDSHOME/lib/<architecture> to your PATH so that the contained
libraries can be loaded by your OS.

> set NDDSHOME="c:\Program Files (x86)\RTI\ndds.x.y.z"
> set PATH=%NDDSHOME%/lib/<architecture>;%PATH%

Open the Visual Studio solution in the directory routing_service_lib\windows

Build the solution. 

You can run from Visual Studio or from a command line:

> routing_service_lib\windows\objs\<architecture>\RunRoutingService.exe [configuration-file]



*******************************
*** pentiumInty10.0.2.pcx86 ***
*******************************

We are providing an integrity project file as example. 

Before compiling please set the following macros:

 - __OS_DIR
 - __NDDSHOME

in RunRoutingService_pentiumInty10.0.2.pcx86.gpj

Compile the project using MULTI.

Run the executable on your target.

Run a publisher on domain 0 and a subscriber on domain 1; the subscriber will
receive the data being published on domain 1.

