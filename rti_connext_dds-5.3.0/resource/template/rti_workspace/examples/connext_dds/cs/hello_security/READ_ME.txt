=====================================================
RTI Connext Hello_security Example Application
=====================================================


Setting up the Environment
--------------------------
Set the NDDSHOME environment variable to your RTI Connext installation
directory.  Set the PATH environment variable to include
%NDDSHOME%\lib\<architecture> where <architecture> is your Connext DDS
architecture, e.g. x64Win64VS2015.  Set the RTI_OPENSSLHOME environment
variable to your OpenSSL installation_directory.  Make sure your PATH
includes the directory %RTI_OPENSSLHOME%\<architecture>\release\bin
or wherever ssleay32.dll and libeay32.dll reside.

Compiling this Example
----------------------
Open the appropriate solution file for your version of Microsoft Visual
Studio in the win32 directory.  Build each project in the solution.

Running this Example
--------------------
To run this example type the following in two different command shells,
either on the same machine or on different machines:

  > bin\[Debug|Release]-VS<vs_version>\HelloWorld_subscriber.exe
  > bin\[Debug|Release]-VS<vs_version>\HelloWorld_publisher.exe

Accepted parameters
-------------------
This example is a modified version of an rtiddsgen generated HelloWorld application.
It has been modified to use security profiles.  The first two parameters are the
domain ID and sample count as in the hello_world example.  This example uses
ECDSA-ECDH by default. To run this example using DSA-DH or
RSA-ECDH, add the third command-line argument "dsa" or "rsa", respectively.

Troubleshooting this Example
============================
If you see the following error:

Cryptography_encrypt:error:0607B083:lib(6):func(123):reason(131)

you are likely linking against an older version of OpenSSL. You need version
1.0.1c or later.

If you see the following error:

Authentication_get_certificate:failed to verify certificate

your certificates have likely expired. You need to regenerate the peer{1,2,3}.pem 
or peer{1,2,3}dsa.pem files following the instructions in the html documentation
under DomainParticipantSecurityQosPolicy certificate.

If you see the following error:

OPENSSL_Uplink(10115000,08): no OPENSSL_Applink

you likely need to make sure your PATH includes the directory
%RTI_OPENSSLHOME%\<architecture>\release\bin, or wherever
ssleay32.dll and libeay32.dll reside.

For more information, please consult the "RTI Security Plugins Getting Started
Guide".
