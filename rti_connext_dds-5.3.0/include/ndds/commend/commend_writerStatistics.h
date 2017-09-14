/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_writerStatistics.h    generated by: makeheader    Thu Jun 22 14:17:26 2017
 *
 *		built from:	writerStatistics.ifc
 */

#ifndef commend_writerStatistics_h
#define commend_writerStatistics_h



#include "osapi/osapi_type.h"

#ifndef commend_dll_h
    #include "commend/commend_dll.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct COMMENDWriterServiceLocalWriterStatistics {
    RTI_INT64 samplesPushedCount;
    RTI_INT64 samplesPushedCountChange;
    RTI_INT64 samplesPushedBytes;
    RTI_INT64 samplesPushedBytesChange;
    RTI_INT64 samplesFilteredCount;
    RTI_INT64 samplesFilteredCountChange;
    RTI_INT64 samplesFilteredBytes;
    RTI_INT64 samplesFilteredBytesChange;
    RTI_INT64 heartbeatsSentCount;
    RTI_INT64 heartbeatsSentCountChange;
    RTI_INT64 heartbeatsSentBytes;
    RTI_INT64 heartbeatsSentBytesChange;
    RTI_INT64 samplesPulledCount;
    RTI_INT64 samplesPulledCountChange;
    RTI_INT64 samplesPulledBytes;
    RTI_INT64 samplesPulledBytesChange;
    RTI_INT64 acksReceivedCount;
    RTI_INT64 acksReceivedCountChange;
    RTI_INT64 acksReceivedBytes;
    RTI_INT64 acksReceivedBytesChange;
    RTI_INT64 nacksReceivedCount;
    RTI_INT64 nacksReceivedCountChange;
    RTI_INT64 nacksReceivedBytes;
    RTI_INT64 nacksReceivedBytesChange;
    RTI_INT64 gapsSentCount;
    RTI_INT64 gapsSentCountChange;
    RTI_INT64 gapsSentBytes;
    RTI_INT64 gapsSentBytesChange;
    RTI_INT64 samplesRejectedCount;
    RTI_INT64 samplesRejectedCountChange;
    RTI_INT32 sendWindowSize;
    struct REDASequenceNumber firstAvailableSampleSequenceNumber;
    struct REDASequenceNumber lastAvailableSampleSequenceNumber;
    struct REDASequenceNumber firstUnacknowledgedSampleSequenceNumber;
    struct REDASequenceNumber firstAvailableSampleVirtualSequenceNumber;
    struct REDASequenceNumber lastAvailableSampleVirtualSequenceNumber;
    struct REDASequenceNumber firstUnacknowledgedSampleVirtualSequenceNumber;
    struct MIGRtpsGuid firstUnacknowledgedSampleSubscriptionHandle;
    struct REDASequenceNumber firstUnelapsedKeepDurationSampleSequenceNumber;

};


#define COMMEND_WRITER_SERVICE_LOCAL_WRITER_STATISTICS_INITIALIZER { \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
MIG_RTPS_GUID_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN \
}

struct COMMENDWriterServiceMatchedReaderStatistics {
    RTI_INT64 samplesPushedCount;
    RTI_INT64 samplesPushedCountChange;
    RTI_INT64 samplesPushedBytes;
    RTI_INT64 samplesPushedBytesChange;
    RTI_INT64 samplesFilteredCount;
    RTI_INT64 samplesFilteredCountChange;
    RTI_INT64 samplesFilteredBytes;
    RTI_INT64 samplesFilteredBytesChange;
    RTI_INT64 heartbeatsSentCount;
    RTI_INT64 heartbeatsSentCountChange;
    RTI_INT64 heartbeatsSentBytes;
    RTI_INT64 heartbeatsSentBytesChange;
    RTI_INT64 samplesPulledCount;
    RTI_INT64 samplesPulledCountChange;
    RTI_INT64 samplesPulledBytes;
    RTI_INT64 samplesPulledBytesChange;
    RTI_INT64 acksReceivedCount;
    RTI_INT64 acksReceivedCountChange;
    RTI_INT64 acksReceivedBytes;
    RTI_INT64 acksReceivedBytesChange;
    RTI_INT64 nacksReceivedCount;
    RTI_INT64 nacksReceivedCountChange;
    RTI_INT64 nacksReceivedBytes;
    RTI_INT64 nacksReceivedBytesChange;
    RTI_INT64 gapsSentCount;
    RTI_INT64 gapsSentCountChange;
    RTI_INT64 gapsSentBytes;
    RTI_INT64 gapsSentBytesChange;
    RTI_INT64 samplesRejectedCount;
    RTI_INT64 samplesRejectedCountChange;
    struct REDASequenceNumber firstAvailableSampleSequenceNumber;
    struct REDASequenceNumber lastAvailableSampleSequenceNumber;
    struct REDASequenceNumber firstUnacknowledgedSampleSequenceNumber;
    struct REDASequenceNumber firstAvailableSampleVirtualSequenceNumber;
    struct REDASequenceNumber lastAvailableSampleVirtualSequenceNumber;
    struct REDASequenceNumber firstUnacknowledgedSampleVirtualSequenceNumber;
    struct MIGRtpsGuid firstUnacknowledgedSampleSubscriptionHandle;
    struct REDASequenceNumber firstUnelapsedKeepDurationSampleSequenceNumber;
};


#define COMMEND_WRITER_SERVICE_MATCHED_READER_STATISTICS_INITIALIZER { \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN, \
MIG_RTPS_GUID_UNKNOWN, \
REDA_SEQUENCE_NUMBER_UNKNOWN \
}

struct COMMENDWriterServiceMatchedDestinationStatistics {
    RTI_INT64 samplesPushedCount;
    RTI_INT64 samplesPushedCountChange;
    RTI_INT64 samplesPushedBytes;
    RTI_INT64 samplesPushedBytesChange;
    RTI_INT64 samplesFilteredCount;
    RTI_INT64 samplesFilteredCountChange;
    RTI_INT64 samplesFilteredBytes;
    RTI_INT64 samplesFilteredBytesChange;
    RTI_INT64 heartbeatsSentCount;
    RTI_INT64 heartbeatsSentCountChange;
    RTI_INT64 heartbeatsSentBytes;
    RTI_INT64 heartbeatsSentBytesChange;
    RTI_INT64 samplesPulledCount;
    RTI_INT64 samplesPulledCountChange;
    RTI_INT64 samplesPulledBytes;
    RTI_INT64 samplesPulledBytesChange;
    RTI_INT64 gapsSentCount;
    RTI_INT64 gapsSentCountChange;
    RTI_INT64 gapsSentBytes;
    RTI_INT64 gapsSentBytesChange;
};


#define COMMEND_WRITER_SERVICE_MATCHED_DESTINATION_STATISTICS_INITIALIZER { \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0  \
}

typedef RTI_UINT32 COMMENDWriterStatisticsChangedBitmap;


#define COMMEND_WRITER_STATISTICS_NO_FLAG (0x00000000)
#define COMMEND_WRITER_STATISTICS_GAP_SENT_FLAG (0x00000001 << 0)
#define COMMEND_WRITER_STATISTICS_SAMPLE_SENT_FLAG (0x00000001 << 1)
#define COMMEND_WRITER_STATISTICS_SAMPLE_FILTERED_FLAG (0x00000001 << 2)
#define COMMEND_WRITER_STATISTICS_SAMPLE_RESENT_FLAG (0x00000001 << 3)
#define COMMEND_WRITER_STATISTICS_HEARTBEAT_SENT_FLAG (0x00000001 << 4)
#define COMMEND_WRITER_STATISTICS_ACK_RECEIVED_FLAG (0x00000001 << 5)
#define COMMEND_WRITER_STATISTICS_NACK_RECEIVED_FLAG (0x00000001 << 6)
#define COMMEND_WRITER_STATISTICS_SAMPLE_REJECTED_FLAG (0x00000001 << 7)

extern COMMENDDllExport 
void COMMENDWriterService_addLocalWriterStatistics(
    struct COMMENDWriterServiceLocalWriterStatistics *sum,
    struct COMMENDWriterServiceLocalWriterStatistics *in1,
    struct COMMENDWriterServiceLocalWriterStatistics *in2);

extern COMMENDDllExport 
void COMMENDWriterService_addMatchedReaderStatistics(
    struct COMMENDWriterServiceMatchedReaderStatistics *sum,
    struct COMMENDWriterServiceMatchedReaderStatistics *in1,
    struct COMMENDWriterServiceMatchedReaderStatistics *in2);

extern COMMENDDllExport 
void COMMENDWriterService_addMatchedDestinationStatistics(
    struct COMMENDWriterServiceMatchedDestinationStatistics *sum,
    struct COMMENDWriterServiceMatchedDestinationStatistics *in1,
    struct COMMENDWriterServiceMatchedDestinationStatistics *in2);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

    #include "commend/commend_writerStatistics_impl.h"

#endif /* commend_writerStatistics_h */