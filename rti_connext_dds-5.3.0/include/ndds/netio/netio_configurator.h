/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_configurator.h    generated by: makeheader    Thu Jun 22 14:17:17 2017
 *
 *		built from:	configurator.ifc
 */

#ifndef netio_configurator_h
#define netio_configurator_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
  #endif
  #ifndef netio_dll_h
    #include "netio/netio_dll.h"
  #endif
  #ifndef transport_interface_h
    #include "transport/transport_interface.h"
  #endif
  #ifndef netio_common_h
    #include "netio/netio_common.h"
  #endif
  #ifndef transport_udpv4_h
    #include "transport/transport_udpv4.h"
  #endif
  #ifndef transport_shmem_h
    #include "transport/transport_shmem.h"
  #endif
  #ifndef transport_intra_h
    #include "transport/transport_intra.h"
  #endif
  #ifndef transport_udpv6_h
    #include "transport/transport_udpv6.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAWorker;

struct REDAExclusiveArea;

struct REDAWeakReference;

struct REDADatabase;

struct RTIEventActiveObjectListener;

struct RTINetioConfiguratorListener;


struct RTINetioConfiguratorProperty {
    /*e @brief Control size of the transport plugin table. */
    struct REDAFastBufferPoolGrowthProperty pluginGrowth;

    /*e @brief Control size of the send route table. */
    struct REDAFastBufferPoolGrowthProperty sendRouteGrowth;

    /*e @brief Control size of the receive route table. */
    struct REDAFastBufferPoolGrowthProperty receiveRouteGrowth;

    /*e @brief Address separator

      This character is used to separate the network address portion from
      a transport specific address in an address string.

      @see RTINetioConfigurator_populateLocatorsFromAddressString()
     */
    char addressSeparator;

    /*e @brief Locator separator

      This character is used to separate the alias portion from
      the address portion in a locator string.

      @see RTINetioConfigurator_populateLocatorsFromLocatorString()
     */
    char locatorSeparator[4];
    
    /* Indicates if the SHMEM and IPv6 plugins used 510 locator kinds or 520 
     * locator kinds. This variable is used by methods such as isShmemTransport
     */
    RTIBool use510CompatibleLocatorKinds;
};


#define RTI_NETIO_CONFIGURATOR_PROPERTY_DEFAULT {     \
  REDA_FAST_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT, /* pluginGrowth */ \
  {4, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED},\
  {4, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED},\
  '#' /* address separator */, \
  "://" /* locator separator */, \
  RTI_FALSE, \
}


struct RTINetioConfigurator;

extern RTINetioDllExport
struct RTINetioConfigurator* RTINetioConfigurator_new(
    const struct RTINetioConfiguratorProperty *propertyIn,
    struct REDADatabase *databaseIn,
    struct REDAExclusiveArea *tableEAIn,
    struct RTIEventActiveObjectListener *shutdownListenerIn,
    struct REDAWorker *worker);

extern RTINetioDllExport void
RTINetioConfigurator_delete(struct RTINetioConfigurator *me,
                            struct REDAWorker *worker);

extern RTINetioDllExport void
RTINetioConfigurator_getProperty(
    struct RTINetioConfigurator *me,
    struct RTINetioConfiguratorProperty *propertyOut,
    struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_setProperty(
    struct RTINetioConfigurator *me,
    const struct RTINetioConfiguratorProperty *property,
    struct REDAWorker *worker);

extern RTINetioDllExport
RTIBool RTINetioConfigurator_shutdown(
        struct RTINetioConfigurator* me,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_installTransportPlugin(
                struct RTINetioConfigurator* me,
                struct REDAWeakReference* pluginHandleOut,
                NDDS_Transport_Plugin* pluginInstanceIn,
                const struct RTINetioAliasList* aliasListIn,
                const NDDS_Transport_Address_t* networkAddressIn,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_uninstallTransportPlugin(
                struct RTINetioConfigurator* me,
                const struct REDAWeakReference* pluginHandleIn,
                struct REDAWorker* worker);

extern RTINetioDllExport 
RTIBool
RTINetioConfigurator_getInstalledTransportPluginCount(
    struct RTINetioConfigurator* me,
    int *count_out,
    struct REDAWorker *worker);

extern RTINetioDllExport 
RTIBool
RTINetioConfigurator_getInstalledTransportPlugins(
    struct RTINetioConfigurator* me,
    NDDS_Transport_Plugin **pluginsOut,
    int *countIn,
    struct REDAWorker *worker);

extern RTINetioDllExport 
const NDDS_Transport_Plugin * 
RTINetioConfigurator_getTransportPluginByClass(
    struct RTINetioConfigurator *me,
    NDDS_Transport_ClassId_t classId,
    struct REDAWorker *worker);

extern RTINetioDllExport 
const char * 
RTINetioConfigurator_getTransportClassName(
    struct RTINetioConfigurator *me,
    NDDS_Transport_ClassId_t classId,
    struct REDAWorker *worker);

extern RTINetioDllExport
RTIBool 
RTINetioConfigurator_isShmemTransport(
    struct RTINetioConfigurator *me,
    NDDS_Transport_ClassId_t classId,
    struct REDAWorker *worker);

extern RTINetioDllExport
NDDS_Transport_ClassId_t 
RTINetioConfigurator_getShmemTransportClassId(
    struct RTINetioConfigurator *me,
    struct REDAWorker *worker);

extern RTINetioDllExport 
RTIBool 
RTINetioConfigurator_isUdpv6Transport(
    struct RTINetioConfigurator *me,
    NDDS_Transport_ClassId_t classId,
    struct REDAWorker *worker);

extern RTINetioDllExport
RTIBool
RTINetioConfigurator_isLocalLocator(
    struct RTINetioConfigurator *me,
    const struct RTINetioLocator *locator,
    struct REDAWorker *worker);

extern RTINetioDllExport
NDDS_Transport_ClassId_t 
RTINetioConfigurator_getUdpv6TransportClassId(
    struct RTINetioConfigurator *me,
    struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_queryTransportPlugin(
                struct RTINetioConfigurator* me,
		struct RTINetioAliasList* aliasListOut,
		NDDS_Transport_Address_t* networkAddressOut,
		struct REDAWeakReference* pluginHandleOut,
		const NDDS_Transport_Plugin* pluginInstanceIn,
		struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_addDestinationRoute(
        struct RTINetioConfigurator *me,
        NDDS_Transport_ClassId_t serviceTransportClassIn,
        const struct RTINetioAddressFilter *serviceAddressRangeIn,
        const struct REDAWeakReference *pluginHandleIn,
        const struct RTINetioLocator* relayLocatorIn,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_removeDestinationRoutes(
        struct RTINetioConfigurator *me,
        const struct REDAWeakReference *pluginHandleIn,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_addEntryportRoute(
        struct RTINetioConfigurator *me,
        const struct RTINetioAddressFilter *serviceAddressRangeIn,
        const struct REDAWeakReference *pluginHandleIn,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_removeEntryportRoutes(
        struct RTINetioConfigurator *me,
        const struct REDAWeakReference *pluginHandleIn,
        struct REDAWorker *worker);

extern RTIBool RTINetioDllExport
RTINetioConfigurator_addDefaultRoutes(
        struct RTINetioConfigurator *me,
        struct REDAWorker *worker);

extern RTIBool RTINetioDllExport
RTINetioConfigurator_removeDefaultRoutes(
        struct RTINetioConfigurator *me,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_queryInterfaces(
                struct RTINetioConfigurator *me,
		RTIBool* foundMoreInterfacesThanProvidedForOut,
                NDDS_Transport_Interface_t *interfaceArrayOut,
                int* interfaceCountOut,
                const struct RTINetioAliasList* aliasListIn,
                int interfaceArraySizeIn,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_getMinMaxMessageSize(
                struct RTINetioConfigurator *me,
                const struct RTINetioAliasList* aliasListIn,
                int* messageSizeOut,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_getMaxMaxMessageSize(
                struct RTINetioConfigurator *me,
                int* messageSizeOut,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_getTransportInfo(
                struct RTINetioConfigurator *me,          
                struct RTINetioTransportInfo *transportProperty,
                int *length,
                int maximum,
                struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_populateUnicastLocators(
                const struct RTINetioConfigurator *me,
                RTIBool* foundMoreThanProvidedForOut,
                int* locatorArrayLengthInOut,
                struct RTINetioLocator *locatorArrayInOut,
                int locatorArrayCapacityIn,
                const struct RTINetioAliasList* unicastPluginAliasesIn,
                RTI_INT32 portIn,
                const struct RTINetioAliasList* enabledPluginAliasesIn,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_populateLocators(
    const struct RTINetioConfigurator *me,
    RTIBool* foundMoreThanProvidedForOut,
    int* locatorArrayLengthInOut,
    struct RTINetioLocator *locatorArrayInOut,
    int locatorArrayCapacityIn,
    const NDDS_Transport_Address_t* networkAddressIn,
    const char* transportAddressStringIn,
    RTI_INT32 portIn,
    const struct RTINetioAliasList* pluginAliasesIn,
    const struct RTINetioAliasList* enabledPluginAliasesIn,
    RTIBool mustBeAllowedByEntryportRoutingtTableIn,
    RTIBool mustBeAllowedByDestinationRoutingtTableIn,
    RTIBool mustBeMulticastIn,
    struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_populateLocatorsFromAddressString(
    const struct RTINetioConfigurator *me,
    RTIBool* foundMoreThanProvidedForOut,
    int* locatorArrayLengthInOut,
    struct RTINetioLocator *locatorArrayInOut,
    int locatorArrayCapacityIn,
    const char* addressStringIn,
    RTI_INT32 portIn,
    const struct RTINetioAliasList* pluginAliasesIn,
    const struct RTINetioAliasList* enabledPluginAliasesIn,
    RTIBool mustBeAllowedByEntryportRoutingtTableIn,
    RTIBool mustBeAllowedByDestinationRoutingtTableIn,
    RTIBool mustBeMulticastIn,
    struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_populateLocatorsFromLocatorString(
    const struct RTINetioConfigurator *me,
    RTIBool* foundMoreThanProvidedForOut,
    int* locatorArrayLengthInOut,
    struct RTINetioLocator *locatorArrayInOut,
    int locatorArrayCapacityIn,
    const char* locatorStringIn,
    RTI_INT32 defaultPortIn,
    struct RTINetioAliasList* defaultAliasIn,
    const struct RTINetioAliasList* enabledPluginAliasesIn,
    RTIBool mustBeAllowedByEntryportRoutingtTableIn,
    RTIBool mustBeAllowedByDestinationRoutingtTableIn,
    RTIBool mustBeMulticastIn,
    struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfigurator_splitLocatorString(
    const char **aliasStrOut,
    const char **addressStrOut,
    char *aliasStrCopyInOut,
    const char *locatorStringIn,
    const char *locatorSeparator);

extern RTINetioDllExport NDDS_Transport_Plugin* 
RTINetioConfigurator_getTransportPluginFromAlias(
    const struct RTINetioConfigurator *me,
    NDDS_Transport_Address_t* pluginNetworkAddressOut,
    const struct RTINetioAliasList* pluginAliasIn,
    struct REDAWorker* worker);

extern RTINetioDllExport 
NDDS_Transport_ClassId_t
RTINetioConfigurator_getTransportClassFromAlias(
        const struct RTINetioConfigurator *me,
        const struct RTINetioAliasList *pluginAliasIn,
        struct REDAWorker *worker);

typedef void (*RTINetioConfiguratorListenerOnAfterInstall)(
    struct RTINetioConfiguratorListener *me,
    const struct REDAWeakReference *pluginHandleIn,
    NDDS_Transport_Plugin *transportIn,
    const struct RTINetioAliasList *aliasListIn,
    const struct RTINetioAddressFilter *serviceRangeIn,
    struct REDAWorker *worker);

typedef RTIBool (*RTINetioConfiguratorListenerOnBeforeUninstall)(
    struct RTINetioConfiguratorListener *me,
    const struct REDAWeakReference *pluginHandleIn,
    NDDS_Transport_Plugin *transportIn, struct REDAWorker *worker);

struct RTINetioConfiguratorListener {
    /*e Start using the new transport plugin in the configurator */
    RTINetioConfiguratorListenerOnAfterInstall      onAfterTransportPluginInstall;
    /*e Stop using the transport plugin about to be uninstalled
        from the configurator
    */
    RTINetioConfiguratorListenerOnBeforeUninstall onBeforeTransportPluginUninstall;
};

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_assembleFullyQualifiedAddress(
                NDDS_Transport_Address_t* fullyQualifiedAddressOut,
                const NDDS_Transport_Address_t* networkAddressIn,
                const NDDS_Transport_Address_t* transportAddressIn,
                int transportAddressBitCountIn);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_disassembleFullyQualifiedAddress(
                NDDS_Transport_Address_t* networkAddressOut,
                NDDS_Transport_Address_t* transportAddressOut,
                const NDDS_Transport_Address_t* fullyQualifiedAddressIn,
                int transportAddressBitCountIn);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_generateDefaultNetworkAddress96(
               NDDS_Transport_Address_t* networkAddressOut,
               NDDS_Transport_ClassId_t transportClassIdIn,
               RTI_UINT32 rtpsHostIdIn,
               RTI_UINT32 rtpsAppIdIn,
               RTI_UINT32 rtpsInstanceIdIn, /*RTPS.2.0*/
               RTI_UINT32 pluginInstanceIdIn);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_populateEntryports(
                struct RTINetioConfigurator *configuratorIn,
                struct RTINetioLocatorInfo *entryportArrayOut,
                int* entryportCountOut,
                int entryportArraySizeIn,
                const struct RTINetioAliasList* aliasListIn,
                NDDS_Transport_Port_t portIn,
                int cosIn,
                struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_cleanupTransportPlugin(
               struct RTINetioConfigurator *configuratorIn,
               struct REDAWeakReference* pluginHandleIn,
               struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_cleanupTransportPluginsByAlias(
               struct RTINetioConfigurator *configuratorIn,
               const struct RTINetioAliasList* pluginAliasIn,
               struct REDAWorker* worker);

extern RTINetioDllExport RTIBool
RTINetioConfiguratorUtil_isShmemPluginValid(
               struct RTINetioConfigurator *configuratorIn,
               NDDS_Transport_Plugin **pluginOut,
               struct REDAWorker* worker);

extern RTINetioDllExport NDDS_Transport_Plugin*
RTINetioConfiguratorUtil_setupIntraPlugin(
               struct REDAWeakReference* pluginHandleOut,
               NDDS_Transport_Address_t* networkAddressInOut,
               struct RTINetioConfigurator *configuratorIn,
               RTI_UINT32 rtpsHostIdIn,
               RTI_UINT32 rtpsAppIdIn,
               RTI_UINT32 rtpsInstanceIdIn, /*RTPS.2.0*/
               struct RTIClock *clockIn,
               struct RTINetioAliasList* aliasListIn,
               struct NDDS_Transport_Intra_Property_t* propertyIn,
               struct REDAWorker* worker);

extern RTINetioDllExport NDDS_Transport_Plugin*
RTINetioConfiguratorUtil_setupShmemPlugin(
               struct REDAWeakReference* pluginHandleOut,
               NDDS_Transport_Address_t* networkAddressInOut,
               struct RTINetioConfigurator *configuratorIn,
               RTI_UINT32 rtpsHostIdIn,
               struct RTIClock *clockIn,
               struct RTINetioAliasList* aliasListIn,
               struct NDDS_Transport_Shmem_Property_t* propertyIn,
               struct REDAWorker* worker);

extern RTINetioDllExport NDDS_Transport_Plugin*
RTINetioConfiguratorUtil_setupUDPv4Plugin(
               struct REDAWeakReference* pluginHandleOut,
               struct RTINetioConfigurator *configuratorIn,
               struct RTIClock *clockIn,
               struct NDDS_Transport_UDPv4_SocketFactory *socketFactoryIn,
               struct RTINetioAliasList* aliasListIn,
               struct NDDS_Transport_UDPv4_Property_t* propertyIn,
               struct REDAWorker* worker);

extern RTINetioDllExport NDDS_Transport_Plugin*
RTINetioConfiguratorUtil_setupUDPv6Plugin(
               struct REDAWeakReference* pluginHandleOut,
               struct RTINetioConfigurator *configuratorIn,
               struct RTIClock *clockIn,
               struct NDDS_Transport_UDPv6_SocketFactory *socketFactoryIn,
               struct RTINetioAliasList* aliasListIn,
               struct NDDS_Transport_UDPv6_Property_t* propertyIn,
               struct REDAWorker* worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* netio_configurator_h */
