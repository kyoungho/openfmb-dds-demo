/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)routingservice_service.h    generated by: makeheader    Thu Jun 22 14:19:51 2017
 *
 *		built from:	service.ifc
 */

#ifndef routingservice_service_h
#define routingservice_service_h


  #ifndef routingservice_dll_h
    #include "routingservice/routingservice_dll.h"
  #endif
  #ifndef ndds_transport_c_h
    #include "ndds/ndds_transport_c.h"
  #endif
  #ifndef routingservice_adapter_h
    #include "routingservice/routingservice_adapter.h"
  #endif
  #ifdef __cplusplus
      extern "C" {
  #endif


typedef void (*RTI_RoutingServiceRemoteShutdownHook_OnShutdownFunction)(
        void *shutdownHookData);


struct RTI_RoutingServiceRemoteShutdownHook {
    /* @brief a place holder for implementors */
    void *shutdown_hook_data;
    /* @brief handles the remote shutdown command */
    RTI_RoutingServiceRemoteShutdownHook_OnShutdownFunction on_shutdown;
};


#define RTI_RoutingServiceRemoteShutdownHook_INITIALIZER {NULL, NULL}


struct RTI_RoutingService;


struct RTI_RoutingServiceTransportConfig {
    /*e 
     * @brief An alias defined in the XML configuration to refer to a transport
     */
    char * alias;
    /*e 
     * @brief Pointer to the function to load the transport 
     */
    NDDS_Transport_create_plugin create_function;
};


struct RTI_RoutingServiceProperty {
    /*e
     * 
     * @brief Path to an RTI Routing Service configuration file
     *
     * If not \c NULL, this file is loaded; otherwise,
     * if \c cfg_strings is not \c NULL, that XML code is loaded 
     *
     * \default NULL.
     */
    char * cfg_file;

    /*e
     * @brief XML configuration represented as strings
     * 
     * An array of strings that altogether make up an
     * XML document to configure RTI Routing Service. This parameter is used
     * only if \ref cfg_file is \c NULL.
     *
     * For example: 
     *
     * \code
     * int MY_ROUTING_SERVICE_CFG_SIZE = 3;
     * const char * MY_ROUTING_SERVICE_CFG[MY_ROUTING_SERVICE_CFG_SIZE] = 
     *                          {"<dds><routing_service>",
     *                           "<domain_route><participant_1><domai",
     *                           "n_id>0...</dds>"};
     *
     * property.cfg_strings = MY_ROUTING_SERVICE_CFG;
     * property.cfg_strings_count = MY_ROUTING_SERVICE_CFG_SIZE;
     * \endcode
     * 
     * The reason for using an array instead of one single string is to
     * get around the limited size of literal strings in C.
     * In general, if you create the XML string dynamically 
     * using one single string in the array, 
     * setting \ref cfg_strings_count to 1 is enough:
     *
     * \code
     * property.cfg_strings = malloc(sizeof(char *));
     * property.cfg_strings[0] = "<dds><routing_service>...</dds>";
     * property.cfg_strings_count = 1;
     * \endcode
     *
     * If your target system doesn't support a file system, you can use
     * XML strings to configure the service. To ease this process, a
     * utility is shipped to generate a C string array from a text file.
     * You can find this utility in 
     * [RTI Routing Service installation directory]/resource/perl/cStringifyFile.pl
     *
     * \default NULL.
     */
    const char ** cfg_strings;

    /*e
     * @brief Size of the array \ref cfg_strings
     *
     * \default 0.
     */
    int cfg_strings_count;

    /*e
     * @brief The name of the Routing Service instance to run
     *
     * This is the name used to find the &lt;routing_service&gt;
     * XML tag in the configuration file; the name that will
     * be used to refer to this execution in remote administration and
     * monitoring.
     *
     * \default NULL (use RTI_RoutingService)
     */
    char * service_name;

    /*e
     * @brief Assigns a name to the execution of the RTI Routing Service.
     *
     * Remote commands and status information will refer to the routing
     * service using this name. 
     * In addition, the name of DomainParticipants created by RTI
     * Routing Service will be based on this name.
     *
     * \default service_name if this value is different than NULL. Otherwise,
     * "RTI_Routing_Service".
     */
    char * application_name;
    
    /*e
     * @brief Defines the service kind an instance of RTI Routing Service 
     * represents.
     * This is used to differentiate services that use RTI Routing Service as
     * foundation framework. It allows, among others, remote administration 
     * requests to a specific service kind.
     * 
     * \default RTI_SERVICE_ROUTING_SERVICE
     */
    int service_kind;

    /*e
     * @brief The verbosity of the service
     *
     * Values:
     *  <ul>
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_SILENT
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_EXCEPTIONS
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_WARNINGS
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_INFO
     *  </ul>
     *
     * \default RTI_ROUTING_SERVICE_LOG_VERBOSITY_EXCEPTIONS
     */
    int service_verbosity;
    /*e
     * @brief The verbosity of \ndds core libraries
     *
     * Values:
     *  <ul>
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_SILENT
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_EXCEPTIONS
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_WARNINGS
     *  <li> \ref RTI_ROUTING_SERVICE_LOG_VERBOSITY_INFO
     *  </ul>
     *
     * \default RTI_ROUTING_SERVICE_LOG_VERBOSITY_EXCEPTIONS
     */
    int dds_verbosity;

    /*e
     * @brief Value that is added to the domain IDs of the
     *        domain routes in the XML configuration.
     *
     * By using this, an XML file can use relative domain IDs.
     *
     * \default 0     
     */
    int domain_id_base;

    /*e
     * @brief Not used. It must be NULL.
     *
     * \default NULL         
     */
    char * executable_path;

    /*e
     * @brief This path is used to look for transformation libraries.
     *
     * If the transformation class libraries specified in the XML file don't
     * contain a full path, RTI Routing Service looks for them in this 
     * directory if not NULL.
     *
     * \default NULL         
     */
    char * transformation_search_path;

    /*e
     * @brief Set this to true to if you do not want RTI Routing Service enabled when 
     *        \ref RTI_RoutingService_start is called.
     * 
     * RTI Routing Service can be enabled afterwards through 
     * remote administration.
     * 
     * \default DDS_BOOLEAN_FALSE
     */
    DDS_Boolean dont_start_service;

    /*e
     * @brief Set this to true to enable remote administration
     * or false to disable it.
     * 
     * \default DDS_BOOLEAN_FALSE
     */
    DDS_Boolean enable_administration;

    /*e
     * @brief If \ref enable_administration is true, this is
     * the domain ID to use for remote administration.
     *
     * Takes precedence over the XML configuration.
     * If \ref enable_administration is false, this value is not used
     * even if remote administration is enabled in the XML configuration.
     * 
     * \default 0
     */
    int administration_domain_id;

    /*e
     * @brief Set it to true to enable remote monitoring
     * or false to disable it.
     * 
     * \default DDS_BOOLEAN_FALSE
     */
    DDS_Boolean enable_monitoring;

    /*e
     * @brief If \ref enable_monitoring is true, this is
     * the domain ID to use for remote monitoring.
     *
     * Takes precedence over the XML configuration.
     * If \ref enable_monitoring is false, this value is not used,
     * even if remote monitoring is enabled in the XML configuration.
     * 
     * \default 0
     */
    int monitoring_domain_id;
    
    /*e
     * @brief Set it to true to avoid loading the
     * standard files usually loaded by RTI Routing Service.
     *
     * Only the configuration in \ref cfg_file or \ref cfg_strings will be loaded.
     * 
     * \default DDS_BOOLEAN_FALSE
     */
    DDS_Boolean skip_default_files;

    /*e
     * @brief Set this to true to append the host name and process ID
     * to the RTI Routing Service execution name.
     *
     * Used to get unique names for remote administration and monitoring.
     * 
     * \default DDS_BOOLEAN_FALSE     
     */
    DDS_Boolean identify_execution;

    /*e
     * @brief Transports to be loaded by \ndds.
     * 
     * @see \ref registered_transports_count
     *
     * @pre Maximum 8 transports
     */
    struct RTI_RoutingServiceTransportConfig registered_transports[8];

    /*e
     * @brief Number of transports configured in \ref registered_transports.
     *
     * @pre Minimum 0 (no custom transport to load), maximum 8.
     * 
     * \default 0
     */
    int registered_transports_count;

    /*e
     * @brief Set this to true to make RTI Routing Service compatible with
     * RTI Data Distribution 4.2e.
     *
     * \default DDS_BOOLEAN_FALSE
     */
    DDS_Boolean use_42e_alignment;

    /*e
     * 
     * @brief Path to an RTI Routing Service license  file
     *
     * If not \c NULL, this file is checked for a valid license; otherwise,
     * default location will be used. This parameter is not used in
     * unlicensed versions. 
     *
     * \default NULL.
     */
    char * license_file_name;
};



#define RTI_RoutingServiceProperty_INITIALIZER {\
    NULL,                           /* cfg_file */                      \
    NULL,                           /* cfg_strings */                   \
    0,                              /* cfg_strings_count */             \
    NULL,                           /* service_name */                  \
    NULL,                           /* application_name */              \
    0,                              /* service_kind */                  \
    1,                              /* service_verbosity */             \
    1,                              /* dds_verbosity */                 \
    0,                              /* domain_id_base */                \
    NULL,                           /* executable_path */               \
    NULL,                           /* transformation_search_path */    \
    RTI_FALSE,                      /* dont_start_service */            \
    RTI_FALSE,                      /* enable_administration */         \
    0,                              /* administration_domain_id */      \
    RTI_FALSE,                      /* enable_monitoring */             \
    0,                              /* monitoring_domain_id */          \
    RTI_FALSE,                      /* skip_default_files */            \
    RTI_FALSE,                      /* identify_execution */            \
    {                               /* registered_transports */         \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}, \
        {NULL,NULL}  \
    },\
    0,                              /* registered_transport_count */    \
    RTI_FALSE,                      /* use_42e_alignment */             \
    NULL                            /* license_file_name */             \
}

extern ROUTERDllVariable
const struct RTI_RoutingServiceProperty  RTI_ROUTING_SERVICE_PROPERTY_DEFAULT;

extern ROUTERDllVariable
const int  RTI_ROUTING_SERVICE_LOG_VERBOSITY_INFO;

extern ROUTERDllVariable
const int  RTI_ROUTING_SERVICE_LOG_VERBOSITY_WARNINGS;

extern ROUTERDllVariable
const int  RTI_ROUTING_SERVICE_LOG_VERBOSITY_EXCEPTIONS;

extern ROUTERDllVariable
const int  RTI_ROUTING_SERVICE_LOG_VERBOSITY_SILENT;

extern ROUTERDllExport 
struct RTI_RoutingService * RTI_RoutingService_new(struct RTI_RoutingServiceProperty * property);

extern ROUTERDllExport 
void RTI_RoutingService_delete(struct RTI_RoutingService * self);

extern ROUTERDllExport 
DDS_Boolean RTI_RoutingService_start(struct RTI_RoutingService * self);

extern ROUTERDllExport 
DDS_Boolean RTI_RoutingService_stop(struct RTI_RoutingService * self);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingService_attach_adapter_plugin(
    struct RTI_RoutingService * self,
    void * adapter,
    const char * plugin_name);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingService_create_entity(
    struct RTI_RoutingService * self,
    const char * parent_name,
    const char * file_name,
    const char * xml_snippet);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingService_delete_entity(
    struct RTI_RoutingService * self,
    const char * entity_name);

extern ROUTERDllExport
char * RTI_RoutingService_get_configuration(
    struct RTI_RoutingService * self);

extern ROUTERDllExport
void RTI_RoutingService_free_string(char * str);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingService_set_remote_shutdown_hook(
        struct RTI_RoutingService * self,
        const struct RTI_RoutingServiceRemoteShutdownHook * shutdown_hook);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingService_finalize_globals();


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* routingservice_service_h */
