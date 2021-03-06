/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)security_dll.h    generated by: makeheader    Thu Jun 22 14:19:32 2017
 *
 *		built from:	dll.ifc
 */

#ifndef security_dll_h
#define security_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_security_DLL_EXPORT)
    #define RTISecurityDllExport __declspec( dllexport )
  #else
    #define RTISecurityDllExport
  #endif /* DDS_Security_DLL_EXPORT */

  #if defined(RTI_security_DLL_VARIABLE) 
    #if defined(RTI_security_DLL_EXPORT)
      #define RTISecurityDllVariable __declspec( dllexport )
    #else
      #define RTISecurityDllVariable __declspec( dllimport )
    #endif /* DDS_Security_DLL_EXPORT */
  #else 
    #define RTISecurityDllVariable
  #endif /* DDS_Security_DLL_VARIABLE */
#else
  #define RTISecurityDllExport
  #define RTISecurityDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */


#endif /* security_dll_h */
