/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_readerStatistics.h    generated by: makeheader    Thu Jun 22 14:17:32 2017
 *
 *		built from:	readerStatistics.ifc
 */

#ifndef pres_readerStatistics_h
#define pres_readerStatistics_h


#include "osapi/osapi_type.h"
#include "commend/commend_readerStatistics.h"

#ifdef __cplusplus
    extern "C" {
#endif

struct PRESPsDataReaderCacheStatus {
    /* number of samples stored in reader queue */
    RTI_INT64 sampleCount;
    /* peak number of samples stored in reader queue */
    RTI_INT64 sampleCountPeak;
    /* peak number of matched remote writers */
    RTI_INT64 remoteWriterCountPeak;
    /* number of samples dropped from reader-side content filtering */
    RTI_INT64 contentFilterDropCount;
    RTI_INT64 contentFilterDropCountChange;
    RTI_INT64 contentFilterDropBytes;
    RTI_INT64 contentFilterDropBytesChange;

    RTI_INT64 timeBasedFilterDropCount;
    RTI_INT64 timeBasedFilterDropCountChange;
    RTI_INT64 timeBasedFilterDropBytes;
    RTI_INT64 timeBasedFilterDropBytesChange;
};


#define PRES_PS_DATAREADER_CACHE_STATUS_INITIALIZER { \
    0, /* sampleCount */ \
    0, /* sampleCountPeak */ \
    0, /* remoteWriterCountPeak */ \
    0, /* contentFilterDropCount */ \
    0, /* contentFilterDropCountChange */ \
    0, /* contentFilterDropBytes */ \
    0, /* contentFilterDropBytesChange */ \
    0, /* timeBasedFilterDropCount */ \
    0, /* timeBasedFilterDropCountChange */ \
    0, /* timeBasedFilterDropBytes */ \
    0 /* timeBasedFilterDropBytesChange */ \
}

struct PRESPsReaderLocalReaderStatistics {
    struct COMMENDReaderServiceLocalReaderStatistics commendStats;
    struct PRESPsDataReaderCacheStatus presStats;
};


#define PRES_PS_READER_LOCAL_READER_STATISTICS_INITIALIZER { \
COMMEND_READER_SERVICE_LOCAL_READER_STATISTICS_INITIALIZER, \
PRES_PS_DATAREADER_CACHE_STATUS_INITIALIZER \
}

struct PRESPsReaderMatchedWriterStatistics {
    struct COMMENDReaderServiceMatchedWriterStatistics commendStats;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pres_readerStatistics_h */
