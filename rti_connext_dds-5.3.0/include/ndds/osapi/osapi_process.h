/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_process.h    generated by: makeheader    Thu Jun 22 14:16:50 2017
 *
 *		built from:	process.ifc
 */

#ifndef osapi_process_h
#define osapi_process_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

extern RTIOsapiDllExport RTI_UINT64 RTIOsapiProcess_getId();

extern RTIOsapiDllExport RTIBool RTIOsapiProcess_isAlive(RTI_UINT64 pidIn);


struct RTIOsapiProcessMemoryInfo {
    /*e @brief Resident memory size */
    RTI_UINT64 physicalMemory;
    /*e @brief Virtual memory size */
    RTI_UINT64 totalMemory;
};


#define RTIOsapiProcessMemoryInfo_INITIALIZER \
{ \
    0, \
    0 \
}

extern RTIOsapiDllExport
RTIBool RTIOsapiProcess_getMemoryInfo(struct RTIOsapiProcessMemoryInfo *info);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_process_h */
