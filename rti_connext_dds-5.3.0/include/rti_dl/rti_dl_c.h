/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rti_dl_c.h    generated by: makeheader    Thu Jun 22 14:18:43 2017
 *
 *		built from:	c.ifc
 */

#ifndef rti_dl_c_h
#define rti_dl_c_h


#ifndef rti_dl_dll_c_h
  #include "rti_dl/rti_dl_dll_c.h"
#endif
#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef log_dll_h
  #include "log/log_dll.h"
#endif
#ifndef osapi_type_h
    #include "osapi/osapi_type.h"
#endif
#ifndef ndds_c_h
    #include "ndds/ndds_c.h"
#endif

#ifndef ndds_config_c_h
    #include "ndds/ndds_config_c.h"
#endif

#include "dds_c/dds_c_log_impl.h"
#include "dds_c/dds_c_infrastructure.h"

#ifdef __cplusplus
    extern "C" {
#endif

#define RTI_DL_DEFAULT_QUEUE_SIZE  128
#define RTI_DL_DEFAULT_DOMAIN_ID 0
/*#define VERBOSITY*/

#define COMMAND_REQUEST_CONTENT_FILTERED_TOPIC_EXPRESSION   "targetHostAndAppId.rtps_host_id = %0 and targetHostAndAppId.rtps_app_id = %1"
#define COMMAND_REQUEST_CONTENT_FILTERED_TOPIC_NAME     "CommandRequestContentFilteredTopic"

/*
 * DDS_Time_t initializer is hardcoded to avoid compilation issues in
 * Integrity platforms.
 */
#define RTI_DL_DistLogger_MessageParams_INITIALIZER {0, NULL, NULL, {-1, 0}}


typedef struct RTI_DL_Options RTI_DL_Options; /*Predefinition for the compiler*/

typedef struct RTI_DL_DDSEntities RTI_DL_DDSEntities; /*Predefinition for the compiler*/

typedef struct RTI_DL_DistLogger RTI_DL_DistLogger; /*Predefinition for the compiler*/

extern RTIDLCDllExport RTI_DL_DistLogger * RTI_DL_DistLogger_getInstance();

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_DistLogger_setFilterLevel(
        RTI_DL_DistLogger *self, DDS_Long newLevel);

extern RTIDLCDllExport RTIBool RTI_DL_DistLogger_setOptions(RTI_DL_Options *options);

extern RTIDLCDllExport RTIBool RTI_DL_DistLogger_setRTILoggerPrintFormat(
        RTI_DL_DistLogger *self, NDDS_Config_LogPrintFormat logPrintFormat);

extern RTIDLCDllExport void RTI_DL_DistLogger_setRTILoggerVerbosityByCategory(
        RTI_DL_DistLogger *self, NDDS_Config_LogCategory category,
        NDDS_Config_LogVerbosity verbosity);

struct RTI_DL_DistLogger_MessageParams {
    /*ce
     *  The level of the log message.
     */
    int log_level;

    /*ce
     *  The message to log. It must be non-NULL.
     */
    const char *message;

    /*ce
     *  The category of the log message.
     */
    const char *category;

    /*ce
     *  The timestamp with which the message will be logged.
     */
    struct DDS_Time_t timestamp;
};

extern RTIDLCDllExport void RTI_DL_DistLogger_logMessageWithLevelCategory(
        RTI_DL_DistLogger *self, int logLevel, const char *message,
        const char *category);

extern RTIDLCDllExport void RTI_DL_DistLogger_logMessageWithParams(
        RTI_DL_DistLogger *self,
        const struct RTI_DL_DistLogger_MessageParams *params);

extern RTIDLCDllExport void RTI_DL_DistLogger_fatal(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_severe(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_error(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_warning(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_notice(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_info(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_debug(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_trace(RTI_DL_DistLogger *self,
        const char *message);

extern RTIDLCDllExport void RTI_DL_DistLogger_log(RTI_DL_DistLogger *self,
        int logLevel, const char *message);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_DistLogger_finalizeInstance();

extern RTIDLCDllExport void RTI_DL_Utility_sleep(int ms);

typedef struct RTI_DL_LogMessageWriteThread LogMessageWriteThread;

extern RTIDLCDllExport RTI_DL_Options * RTI_DL_Options_createDefault();

extern RTIDLCDllExport RTIBool RTI_DL_Options_copy(RTI_DL_Options * self,
        const RTI_DL_Options * other);

extern RTIDLCDllExport DDS_DomainParticipant *
                RTI_DL_Options_getDomainParticipant(RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setDomainParticipant(
        RTI_DL_Options * self, DDS_DomainParticipant * domainParticipant);

extern RTIDLCDllExport RTIBool RTI_DL_Options_getLogInfrastructureMessages(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t
        RTI_DL_Options_setLogInfrastructureMessages(RTI_DL_Options * self,
                RTIBool log);

extern RTIDLCDllExport RTIBool RTI_DL_Options_isRemoteAdministrationEnabled(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t
        RTI_DL_Options_setRemoteAdministrationEnabled(RTI_DL_Options * self,
                RTIBool enabled);

extern RTIDLCDllExport int RTI_DL_Options_getFilterLevel(RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setFilterLevel(
        RTI_DL_Options * self, int filterLevel);

extern RTIDLCDllExport int RTI_DL_Options_getDomainId(RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setDomainId(
        RTI_DL_Options * self, int domainId);

extern RTIDLCDllExport char * RTI_DL_Options_getQosLibrary(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setQosLibrary(
        RTI_DL_Options * self, const char *qosLibrary);

extern RTIDLCDllExport char * RTI_DL_Options_getQosProfile(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setQosProfile(
        RTI_DL_Options * self, const char *qosProfile);

extern RTIDLCDllExport int RTI_DL_Options_getQueueSize(RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setQueueSize(
        RTI_DL_Options * self, int queueSize);

extern RTIDLCDllExport struct DDS_ThreadSettings_t *
                        RTI_DL_Options_getThreadSettings(RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setThreadSettings(
        RTI_DL_Options * self,
        const struct DDS_ThreadSettings_t * threadSettings);

extern RTIDLCDllExport char * RTI_DL_Options_getApplicationKind(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setApplicationKind(
        RTI_DL_Options * self, const char *applicationKind);

extern RTIDLCDllExport RTIBool RTI_DL_Options_getEchoToStdout(
        RTI_DL_Options * self);

extern RTIDLCDllExport DDS_ReturnCode_t RTI_DL_Options_setEchoToStdout(
        RTI_DL_Options * self, RTIBool echoToStdout);

extern RTIDLCDllExport RTI_DL_Options* RTI_DL_Options_delete(
        RTI_DL_Options *self);


#ifdef __cplusplus
    };
#endif

#endif /* rti_dl_c_h */
