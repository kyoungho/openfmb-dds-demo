/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_dll.h    generated by: makeheader    Thu Jun 22 14:16:59 2017
 *
 *		built from:	dll.ifc
 */

#ifndef reda_dll_h
#define reda_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_reda_DLL_EXPORT)
    #define REDADllExport __declspec( dllexport )
  #else
    #define REDADllExport
  #endif /* RTI_reda_DLL_EXPORT */

  #if defined(RTI_reda_DLL_VARIABLE) 
    #if defined(RTI_reda_DLL_EXPORT)
      #define REDADllVariable __declspec( dllexport )
    #else
      #define REDADllVariable __declspec( dllimport )
    #endif /* RTI_reda_DLL_EXPORT */
  #else 
    #define REDADllVariable
  #endif /* RTI_reda_DLL_VARIABLE */
#else
  #define REDADllExport
  #define REDADllVariable
#endif /* RTI_WIN32 || RTI_WINCE */


#endif /* reda_dll_h */
