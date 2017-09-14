

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "HelloWorldTopicQuery.h"

/* ========================================================================= */
const char *HelloWorldTopicQueryTYPENAME = "HelloWorldTopicQuery";

DDS_TypeCode* HelloWorldTopicQuery_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode HelloWorldTopicQuery_g_tc_message_string = DDS_INITIALIZE_STRING_TYPECODE((255));
    static DDS_TypeCode_Member HelloWorldTopicQuery_g_tc_members[2]=
    {

        {
            (char *)"id",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"message",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode HelloWorldTopicQuery_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"HelloWorldTopicQuery", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            HelloWorldTopicQuery_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for HelloWorldTopicQuery*/

    if (is_initialized) {
        return &HelloWorldTopicQuery_g_tc;
    }

    HelloWorldTopicQuery_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    HelloWorldTopicQuery_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&HelloWorldTopicQuery_g_tc_message_string;

    is_initialized = RTI_TRUE;

    return &HelloWorldTopicQuery_g_tc;
}

RTIBool HelloWorldTopicQuery_initialize(
    HelloWorldTopicQuery* sample) {
    return HelloWorldTopicQuery_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool HelloWorldTopicQuery_initialize_ex(
    HelloWorldTopicQuery* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return HelloWorldTopicQuery_initialize_w_params(
        sample,&allocParams);

}

RTIBool HelloWorldTopicQuery_initialize_w_params(
    HelloWorldTopicQuery* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->message= DDS_String_alloc ((255));
        if (sample->message == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->message!= NULL) { 
            sample->message[0] = '\0';
        }
    }

    return RTI_TRUE;
}

void HelloWorldTopicQuery_finalize(
    HelloWorldTopicQuery* sample)
{

    HelloWorldTopicQuery_finalize_ex(sample,RTI_TRUE);
}

void HelloWorldTopicQuery_finalize_ex(
    HelloWorldTopicQuery* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    HelloWorldTopicQuery_finalize_w_params(
        sample,&deallocParams);
}

void HelloWorldTopicQuery_finalize_w_params(
    HelloWorldTopicQuery* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->message != NULL) {
        DDS_String_free(sample->message);
        sample->message=NULL;

    }
}

void HelloWorldTopicQuery_finalize_optional_members(
    HelloWorldTopicQuery* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool HelloWorldTopicQuery_copy(
    HelloWorldTopicQuery* dst,
    const HelloWorldTopicQuery* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyLong (
        &dst->id, &src->id)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyStringEx (
        &dst->message, src->message, 
        (255) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'HelloWorldTopicQuery' sequence class.
*/
#define T HelloWorldTopicQuery
#define TSeq HelloWorldTopicQuerySeq

#define T_initialize_w_params HelloWorldTopicQuery_initialize_w_params

#define T_finalize_w_params   HelloWorldTopicQuery_finalize_w_params
#define T_copy       HelloWorldTopicQuery_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

