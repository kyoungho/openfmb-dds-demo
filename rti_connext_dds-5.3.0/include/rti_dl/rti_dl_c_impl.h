/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rti_dl_c_impl.h    generated by: makeheader    Thu Jun 22 14:18:43 2017
 *
 *		built from:	c_impl.ifc
 */

#ifndef rti_dl_c_impl_h
#define rti_dl_c_impl_h



#ifndef rti_dl_dll_c_h
  #include "rti_dl/rti_dl_dll_c.h"
#endif
#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef log_common_h
  #include "log/log_common.h"
#endif
#ifndef log_dll_h
  #include "log/log_dll.h"
#endif
#ifndef osapi_type_h
    #include "osapi/osapi_type.h"
#endif
#ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
#endif
#ifndef ndds_c_h
    #include "ndds/ndds_c.h"
#endif
#ifndef reda_concurrentQueue_h
    #include "reda/reda_concurrentQueue.h"
#endif
#ifndef osapi_semaphore_h
    #include "osapi/semaphore.h"
#endif
/*#ifndef reda_concurrentQueue_impl_h
    #include "reda/reda_concurrentQueue_impl.h"
#endif
*/


#ifdef __cplusplus
   extern "C" {
#endif

#define NUM_TOPICS 4


struct RTI_DL_Options {

    /*e
     *  If this field is not null, this is the
     *  DomainParticipant that will be used to create DDS entities
     *  (Topics, Publishers, Subscribers, DataWriters, & DataReaders) needed
     *  by the Distributed Logger. The default value is NULL.
     */
    DDS_DomainParticipant *domainParticipant;
    
    /*i
     * If false, the Distributed Logger instance will be created as disabled.
     * This means that no logging will actually happen until this is set back to
     * an enabled state.
     */
    RTIBool enabled;

    /*e
     * If true, remote administration Topics will be created and
     * used. If false, they will not be created. The default value
     * is true.
     */
    RTIBool remoteAdministrationEnabled;

    /*e
     * The initial filter level. The IDL file contains the predefined filter 
     * levels, such as RTI_DL_INFO_LEVEL. Use one of these
     * constants to set this field. It is possible to use other values, but that
     * is an advanced use-case which is not fully supported at this time. The
     * default value is RTI_DL_TRACE_LEVEL.
     */
    int filterLevel;

    /*e
     * The DDS domain ID to be used. This value is only used if
     * domainParticipant is NULL. The default value is 0.
     */
    unsigned int domainId;

    /*e
     * The QoS library name to use when creating DDS entities. It is up to the
     * application to ensure that this library is available at run time for the
     * Distributed Logger to use. The default value is NULL.
     */
    char * qosLibrary;

    /*e
     * The QoS profile name to use when creating DDS entities. It is up to the
     * application to ensure that this profile is available at run time for the
     * Distributed Logger to use. The default value is NULL.
     */
    char * qosProfile;

    /*e
     * This field controls the size of the queue used to temporarily store log
     * messages from the application until they can be written out to
     * DDS. The default value is RTI_DL_DEFAULT_QUEUE_SIZE.
     */
    unsigned int queueSize;
    
    /*e
     * The settings for the thread that the Distributed Logger uses to read log
     * messages from the queue and publish them into DDS. The default values are
     * specified in file dds_c_infrastructure.h.
     */
    struct DDS_ThreadSettings_t threadSettings;

    /*e
     * This string is sent along on the state Topic and can help identify
     * different applications within a system. You can use this field however
     * you think it will help you most. The default value is NULL.
     */
    char * applicationKind;

    /*
        RTIBool loggingStdout;
        RTIBool loggingStderr;
    */
    /*e
     * If true, Distributed Logger prints the log messages recieved to the 
     * stdout. The default value is FALSE.
     */
    RTIBool echoToStdout;


    /*i
     * If set to true, all log messages produced by infrastructure code will be
     * logged by Distributed Logger as well. The default value is TRUE.
     */
    RTIBool logInfrastructureMessages;
};

struct RTI_DL_DDSEntities {
 
    /*i
     * Indicates whether the associated participant was created by this object
     * or if it was passed to us from somewhere else. This will control whether
     * or not the participant is deleted during cleanup.
     */
    RTIBool participantCreatedLocally;

    /*i
     * The C <code>DomainParticipantFactory</code> which plugs us into DDS.
     */
    DDS_DomainParticipantFactory *factory;

    /*i
     * The <code>DomainParticipant</code> which plugs us into DDS.
     */
    DDS_DomainParticipant *domainParticipant;
    
    /*i
     * The <code>Topic</code> object for log messages.
     */
    DDS_Topic *logTopic;
    
    /*i
     * Our <code>Publisher</code> instance. This object has its own 
     * <code>Publisher</code> instance to avoid threading issues with other
     * <code>DataWriter</code>s in the system (i.e. gaining access to an
     * exclusive area).
     */
    DDS_Publisher *publisher;
    
    /*i
     * Our <code>Subscriber</code> instance. This object has its own 
     * <code>Subscriber</code> instance to avoid threading issues with other
     * <code>DataReader</code>s in the system (i.e. gaining access to an
     * exclusive area).
     */
    DDS_Subscriber *subscriber;
    
    /*i
     * The <code>DataWriter</code> to which log messages are written.
     */
    struct RTI_DL_LogMessageDataWriter *logMessageWriter;
    
    /*i
     * The <code>Topic<code> object for state information.
     */
    DDS_Topic *stateTopic;
    
    /*i
     * The <code>DataWriter</code> to which the logger's state is written.
     */
    struct RTI_DL_ADMIN_StateDataWriter *stateWriter;
    
    /*i
     * The listener for the state <code>DataWriter</code>.
     */
    struct DDS_DataWriterListener stateWriterListener;
    
    /*i
     * The <code>Topic<code> object for command requests.
     */
    DDS_Topic *commandRequestTopic;
    
    /*i
     * The <code>ContentFilteredTopic<code> object for command requests. This
     * filters out commands which are not intended for this instance.
     */
    DDS_ContentFilteredTopic *commandRequestContentFilteredTopic;
    
    /*i
     * The <code>DataReader</code> from which remote commands are read.
     */
    struct RTI_DL_ADMIN_CommandRequestDataReader *commandRequestReader;
    
    /*i
     * The <code>Topic<code> object for command responses.
     */
    DDS_Topic *commandResponseTopic;
    
    /*i
     * The <code>DataWriter</code> to which we write command responses.
     */
    struct RTI_DL_ADMIN_CommandResponseDataWriter *commandResponseWriter;
    
    /*i
     * Storage for all of the locally-created <code>Topic</code> objects. This
     * is used to make cleanup easier.
     */
    DDS_Topic *locallyCreatedTopics[NUM_TOPICS];
    
    /*i
     * The RTPS host id associated with this instance. This comes directly from
     * the <code>DomainParticipant</code> with which this instances is 
     * associated.
     */
    int rtpsHostId;
    
    /*i
     * The RTPS application id associated with this instance. This comes 
     * directly from the <code>DomainParticipant</code> with which this instance 
     * is associated.
     */
    int rtpsAppId;
    
    /*i
     * The QoS library name to use when creating DDS entities.
     */
    const char *qosLibrary;
    
    /*i
     * The QoS profile name to use when creating DDS entities.
     */
    const char *qosProfile;
};

struct RTI_DL_MessageQueue;

struct RTI_DL_LogMessageWriteThread {
     struct RTIOsapiThread* thread;
     struct RTI_DL_MessageQueue * q;
     NDDS_Config_Logger *rtiLogger;
     NDDS_Config_LogVerbosity logVerbosity;
     RTIBool shouldRun;
     RTIBool exitRun;
     struct RTI_DL_LogMessageDataWriter *logMessageWriter;
     RTI_UINT32 threadId;
};

struct RTI_DL_DistLogger {
    /*i
     * The <code>Options</code> used to configure the behavior of the 
     * Distributed Logger.
     */
    struct RTI_DL_Options *options;
    
    /*i
     * The current filter level.
     */
    int filterLevel;
    
    /*i
     * This object contains all of the DDS entities used by the Distributed
     * Logger.
     */
    struct RTI_DL_DDSEntities * _ddsEntities;
    
    /*i
     * This fields holds the current logger state.
     */
    struct RTI_DL_ADMIN_State *state;
    
    /*i
     * The DDS instance handle for the <code>loggerState</code>.
     */
    DDS_InstanceHandle_t loggerStateInstanceHandle;
    
    /*i
     * This object writes the log messages to DDS.
     */
    struct RTI_DL_LogMessageWriteThread *logMessageWriteThread;

    struct RTI_DL_MessageQueue * q;
    
    /*i
     * The <code>LoggerDevice</code> used to capture DDS log messages.
     */
    struct RTI_DL_DistLogger_localDevice *ddsLoggerDevice;

    /*i
     * To avoid a call to new every time we write a message
     */
    struct RTIClock *clock;
};

extern RTIDLCDllExport RTIBool RTI_DL_DistLogger_isDistLoggerRunning();


#ifdef __cplusplus
    };
#endif

#endif /* rti_dl_c_impl_h */
