

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef HelloWorldTopicQuery_1885117055_h
#define HelloWorldTopicQuery_1885117055_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *HelloWorldTopicQueryTYPENAME;

typedef struct HelloWorldTopicQuery {

    DDS_Long   id ;
    DDS_Char *   message ;

} HelloWorldTopicQuery ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* HelloWorldTopicQuery_get_typecode(void); /* Type code */

DDS_SEQUENCE(HelloWorldTopicQuerySeq, HelloWorldTopicQuery);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize(
    HelloWorldTopicQuery* self);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize_ex(
    HelloWorldTopicQuery* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize_w_params(
    HelloWorldTopicQuery* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize(
    HelloWorldTopicQuery* self);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_ex(
    HelloWorldTopicQuery* self,RTIBool deletePointers);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_w_params(
    HelloWorldTopicQuery* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_optional_members(
    HelloWorldTopicQuery* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_copy(
    HelloWorldTopicQuery* dst,
    const HelloWorldTopicQuery* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* HelloWorldTopicQuery */

