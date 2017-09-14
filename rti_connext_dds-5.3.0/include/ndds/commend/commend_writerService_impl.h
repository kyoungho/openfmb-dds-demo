/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_writerService_impl.h    generated by: makeheader    Thu Jun 22 14:17:26 2017
 *
 *		built from:	writerService_impl.ifc
 */

#ifndef commend_writerService_impl_h
#define commend_writerService_impl_h


#ifndef osapi_bufferUtils_h
  #include "osapi/osapi_bufferUtils.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


#define COMMENDWriterServiceProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from, sizeof(struct COMMENDWriterServiceProperty))


#define COMMENDWriterServiceRemoteReaderProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from,                                \
              sizeof(struct COMMENDWriterServiceRemoteReaderProperty))


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_writerService_impl_h */
