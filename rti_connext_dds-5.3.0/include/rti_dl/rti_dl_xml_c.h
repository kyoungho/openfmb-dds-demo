/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rti_dl_xml_c.h    generated by: makeheader    Thu Jun 22 14:18:44 2017
 *
 *		built from:	xml_c.ifc
 */

#ifndef rti_dl_xml_c_h
#define rti_dl_xml_c_h


#ifndef rti_dl_dll_c_h
  #include "rti_dl/rti_dl_dll_c.h"
#endif
#ifndef rti_dl_c_h
  #include "rti_dl/rti_dl_c.h"
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

#ifndef dds_c_xml_h
    #include "dds_c/dds_c_xml.h"
#endif


/* ------------------------------------------------------------ */
/*i
 * @defgroup RTI_DL_XMLConfig RTI DL XML Configuration API
 *
 * @brief This API contains the functions necessary by the RTI infrastructure
 * services and tools to use the RTI Distributed Logger.
 *
 * This API can be used for internal development when integrating RTI
 * Distributed Logger in the XML configuration of their application or service.
*/
/* ------------------------------------------------------------ */

/*i
 * @ingroup RTI_DL_XMLConfig
 * @brief The top level tag text for the Distributed Logger XML configuration
 * extension class. This constant is intended to be used by applications and
 * services using the Distributed Logger XML configuration capabilities when
 * registering the XML extension class with their RTI XML Parser instances.
 */
#define RTI_DL_XML_TOP_LEVEL_TAG "distributed_logger"

typedef void (*RTI_DL_XMLConfig_ParseErrorLogFunction)(const char * logMessage, 
        const char * methodName, const unsigned int lineNumber);


struct RTI_DL_XMLConfig;

typedef struct RTI_DL_XMLConfig RTI_DL_XMLConfig;

extern RTIDLCDllExport struct DDS_XMLExtensionClass * RTI_DL_XMLConfig_createXMLExtensionClass(
        RTI_DL_XMLConfig_ParseErrorLogFunction parseErrorFunction);

extern RTIDLCDllExport void RTI_DL_XMLConfig_destroyXMLExtensionClass(
        struct DDS_XMLExtensionClass * extensionClass);

extern RTIDLCDllExport const RTI_DL_XMLConfig * RTI_DL_XMLConfig_getXMLConfigFromXMLRoot(
        struct DDS_XMLObject * rootObject);

extern RTIDLCDllExport struct DDS_XMLObject * RTI_DL_XMLConfig_getDLXMLObjectFromRoot(
        struct DDS_XMLObject * rootObject);

extern RTIDLCDllExport RTIBool RTI_DL_XMLConfig_startWithXMLConfiguration(
        DDS_DomainParticipant * domainParticipant, 
        RTI_DL_Options * options, 
        const char * applicationKind);

extern RTIDLCDllExport RTI_DL_Options * RTI_DL_XMLConfig_getDLOptions(
        const struct RTI_DL_XMLConfig * self);

#endif /* rti_dl_xml_c_h */
