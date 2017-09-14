/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)writer_history_odbc.h    generated by: makeheader    Thu Jun 22 14:17:30 2017
 *
 *		built from:	odbc.ifc
 */

#ifndef writer_history_odbc_h
#define writer_history_odbc_h



#ifndef writer_history_dll_h
#include "writer_history/writer_history_dll.h"
#endif

#ifndef writer_history_interface_h
#include "writer_history/writer_history_interface.h"
#endif

/*e
  \defgroup WriterHistoryOdbcPluginModule Writer History ODBC Plugin
  \ingroup WriterHistoryModule

  \brief Writer History ODBC plugin implementation.
*/


/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Maximum length of a DSN.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DSN_MAX_LENGTH 512

/*e \ingroup WriterHistoryObdcPluginModule
  \brief Maximum length of an ODBC driver library.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_LIBNAME_MAX_LENGTH 255

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure a Odbc dsn.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DSN_ATTRIBUTE_NAME "dsn"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure an Odbc username.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_USERNAME_ATTRIBUTE_NAME "username"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure an Odbc password.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_PASSWORD_ATTRIBUTE_NAME "password"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure an Odbc driver.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DRIVER_ATTRIBUTE_NAME "driver"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure an Odbc driver.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DRIVER_PTR_ATTRIBUTE_NAME "driver_ptr"

/*e
  \brief Name of the property used to configure shared/exclusive connection handles.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_SHARED_ATTRIBUTE_NAME "shared"

/*e
  \brief Name of the property used to configure the timeout used for the mutexes.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_TIMEOUT_ATTRIBUTE_NAME "timeout"


/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure the maximum size of the instance cache.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_INSTANCE_CACHE_MAX_SIZE_ATTRIBUTE_NAME "instance_cache_max_size"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure the initial size of the instance cache.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_INSTANCE_CACHE_INIT_SIZE_ATTRIBUTE_NAME "instance_cache_init_size"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure the maximum size of the instance cache.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_SAMPLE_CACHE_MAX_SIZE_ATTRIBUTE_NAME "sample_cache_max_size"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to configure the initial size of the instance cache.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_SAMPLE_CACHE_INIT_SIZE_ATTRIBUTE_NAME "sample_cache_init_size"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to determine whether or not the writer history state will be stored 
  in memory or in the database
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_IN_MEMORY_STATE_ATTRIBUTE_NAME "in_memory_state"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to determine if the database storage associated to a WH will be cleaned up
  after the data writer deletion.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_CLEANUP_ATTRIBUTE_NAME "cleanup_on_destroy"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to determine if the database storage associated to a WH will be
  restored if the tables already exist on WH creation.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_RESTORE_ATTRIBUTE_NAME "restore"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief The maximum size of a sample in the database
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_PERSISTENT_DATABASE_SAMPLE_BUFFER_MAX_SIZE_ATTRIBUTE_NAME "database_sample_buffer_max_size"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to control the frecuency (in millisecs)
  at which data is comitted into disk.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_CHECKPOINT_PERIOD_ATTRIBUTE_NAME "checkpoint_period"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to control the frecuency (in samples)
  at which data is comitted into disk.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_CHECKPOINT_VOLUME_ATTRIBUTE_NAME "checkpoint_volume"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief Name of the attribute used to control the frecuency (in millisecs)
  at which the appack state of the samples is updated.
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_ACK_PERIOD_ATTRIBUTE_NAME "ack_period"

/*e \ingroup WriterHistoryOdbcPluginModule
  \brief This parameter is used to specify the maximum number of intervals in a durable
  subscription. This parameter only affects the persistent state.
 
  If the value is 0, the state of the durable subscriptions will not be supported
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DURSUB_MAX_INTERVALS_ATTRIBUTE_NAME "durable_subscription_max_intervals"

/*e \ingroup WriterHistoryOdbcPluginModule 
*/
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_READ_BATCH_ATTRIBUTE_NAME "read_batch"

/*e \ingroup WriterHistoryOdbcPluginModule
 * \brief This parameter specifies the maximum size of the cache that the
 * plugin uses when autopurgeDisposedInstanceDelay is enabled to remember
 * which instances are in disposed state without having to query the DB.
 *
 * A size of zero disables the cache and forces DB queries always.
 *
 */
#define NDDS_WRITERHISTORY_ODBC_PLUGIN_DISPOSED_INSTANCE_CACHE_MAX_SIZE_ATTRIBUTE_NAME "disposed_cache_max_size"

#ifdef __cplusplus
    extern "C" {
#endif


extern WRITERHISTORYDllExport 
RTI_INT32 NDDS_WriterHistory_OdbcPlugin_create(
    struct NDDS_WriterHistory_Plugin ** plugin_out);



#ifdef __cplusplus
    }	/* extern "C" */
#endif


#endif /* writer_history_odbc_h */
