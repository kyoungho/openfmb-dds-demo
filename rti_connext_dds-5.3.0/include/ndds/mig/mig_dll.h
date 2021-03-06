/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)mig_dll.h    generated by: makeheader    Thu Jun 22 14:17:21 2017
 *
 *		built from:	dll.ifc
 */

#ifndef mig_dll_h
#define mig_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_mig_DLL_EXPORT)
    #define MIGDllExport __declspec( dllexport )
  #else
    #define MIGDllExport
  #endif /* RTI_mig_DLL_EXPORT */

  #if defined(RTI_mig_DLL_VARIABLE) 
    #if defined(RTI_mig_DLL_EXPORT)
      #define MIGDllVariable __declspec( dllexport )
    #else
      #define MIGDllVariable __declspec( dllimport )
    #endif /* RTI_mig_DLL_EXPORT */
  #else 
    #define MIGDllVariable
  #endif /* RTI_mig_DLL_VARIABLE */
#else
  #define MIGDllExport
  #define MIGDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */


#endif /* mig_dll_h */
