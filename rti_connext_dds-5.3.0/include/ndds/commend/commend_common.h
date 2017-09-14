/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_common.h    generated by: makeheader    Thu Jun 22 14:17:26 2017
 *
 *		built from:	common.ifc
 */

#ifndef commend_common_h
#define commend_common_h



 #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
 #endif

  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


#define COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX (RTI_NETIO_RTPS_LOCATOR_LIST_MAX_SIZE)
#define COMMEND_COMMON_APP_IPADDRESS_REDUCED_COUNT_MAX (RTI_NETIO_RTPS_LOCATOR_REDUCED_LIST_MAX_SIZE)

#define COMMEND_COMMON_WR_LIST_DEFAULT { \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID  \
}

#define COMMEND_COMMON_WR_REDUCED_LIST_DEFAULT { \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID, \
        REDA_WEAK_REFERENCE_INVALID  \
}


#define COMMENDFilterSignature_bit(__signature) \
	(0x80000000 >> (__signature))


#define COMMEND_LENGTH_AUTO -2

extern COMMENDDllExport int COMMEND_calculateAppendedSize(int testType, int suffixSize, int suffixAlignment);

extern COMMENDDllExport int COMMEND_calculateAppendedAlignment(int testType, int suffixSize, int suffixAlignment);

extern COMMENDDllExport void* COMMEND_calculateAppendedPtr(void* entityPtr, int testType, int suffixSize, int suffixAlignment);


typedef enum {
    COMMEND_PROTOCOL_ACK_MODE,
    COMMEND_AUTO_APP_ACK_MODE,
    COMMEND_ORDERED_APP_ACK_MODE,
    COMMEND_EXPLICIT_APP_ACK_MODE
} COMMENDAppAckMode;


typedef enum {
	COMMEND_SEND_WINDOW_RESIZE_PUSH_PULL_RATIO_MODE,
	COMMEND_SEND_WINDOW_RESIZE_NACK_MODE
} COMMENDSendWindowResizeMode;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

    #include "commend/commend_common_impl.h"

#endif /* commend_common_h */
