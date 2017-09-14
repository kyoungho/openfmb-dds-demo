/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)connext_c_log.h    generated by: makeheader    Thu Jun 22 14:18:45 2017
 *
 *		built from:	log.ifc
 */

#ifndef connext_c_log_h
#define connext_c_log_h


  #ifndef xqm_c_dll_h
    #include "connext_c/connext_c_dll.h"
  #endif  


#ifndef log_common_h
   #include "log/log_common.h"
#endif


#ifdef __cplusplus
    extern "C" {
#endif


  #define SUBMODULE_XMQ_DUMMY                    (0 << 10)


  #define XMQ_SUBMODULE_MASK_DUMMY                    (0x0001)


  #define XMQ_SUBMODULE_MASK_ALL                        (0xFFFFFF)

extern XMQCDllExport void
XMQLog_getBitmaps(RTILogBitmap *submoduleMask,
		  RTILogBitmap *instrumentationMask);

extern XMQCDllExport void
XMQLog_setBitmaps(RTILogBitmap submoduleMask,
		  RTILogBitmap instrumentationMask);

extern XMQCDllExport
void XMQLog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* connext_c_log_h */
