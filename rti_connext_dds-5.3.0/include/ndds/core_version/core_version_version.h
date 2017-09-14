/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)core_version_version.h    generated by: makeheader    Thu Jun 22 14:17:39 2017
 *
 *		built from:	version.ifc
 */

#ifndef core_version_version_h
#define core_version_version_h


  #ifndef rtilib_endian_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef core_version_dll_h
    #include "core_version/core_version_dll.h"
  #endif
  #ifndef core_version_version_impl_h
    #include "core_version/core_version_version_impl.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct VERSLibraryVersion {
    /*e @brief  The major release version number. */
    RTI_INT32 majorVersion;
    
    /*e @brief  The minor release version number. */
    RTI_INT32 minorVersion;
    
    /*e @brief  The release letter. */
    char  releaseLetter;
    
    /*e @brief  The build number. */
    RTI_INT32 buildVersion;
};

extern VERSDllExport
const struct VERSLibraryVersion* VERSLibraryVersion_getCoreVersion(void);

extern VERSDllExport
const char* VERSLibraryVersion_coreVersionToString(void);

extern VERSDllExport
const char* VERSLibraryVersion_getBuildNumberString();


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* core_version_version_h */
