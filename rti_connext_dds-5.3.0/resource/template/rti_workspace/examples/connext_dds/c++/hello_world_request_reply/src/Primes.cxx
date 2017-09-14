

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
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

#include "Primes.h"

#include <new>

/* ========================================================================= */
const char *PrimeNumberRequestTYPENAME = "PrimeNumberRequest";

DDS_TypeCode* PrimeNumberRequest_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member PrimeNumberRequest_g_tc_members[2]=
    {

        {
            (char *)"n",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"primes_per_reply",/* Member name */
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

    static DDS_TypeCode PrimeNumberRequest_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"PrimeNumberRequest", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            PrimeNumberRequest_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for PrimeNumberRequest*/

    if (is_initialized) {
        return &PrimeNumberRequest_g_tc;
    }

    PrimeNumberRequest_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    PrimeNumberRequest_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &PrimeNumberRequest_g_tc;
}

RTIBool PrimeNumberRequest_initialize(
    PrimeNumberRequest* sample) {
    return PrimeNumberRequest_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool PrimeNumberRequest_initialize_ex(
    PrimeNumberRequest* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberRequest_initialize_w_params(
        sample,&allocParams);

}

RTIBool PrimeNumberRequest_initialize_w_params(
    PrimeNumberRequest* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->n)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->primes_per_reply)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void PrimeNumberRequest_finalize(
    PrimeNumberRequest* sample)
{

    PrimeNumberRequest_finalize_ex(sample,RTI_TRUE);
}

void PrimeNumberRequest_finalize_ex(
    PrimeNumberRequest* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberRequest_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberRequest_finalize_w_params(
    PrimeNumberRequest* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void PrimeNumberRequest_finalize_optional_members(
    PrimeNumberRequest* sample, RTIBool deletePointers)
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

RTIBool PrimeNumberRequest_copy(
    PrimeNumberRequest* dst,
    const PrimeNumberRequest* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->n, &src->n)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->primes_per_reply, &src->primes_per_reply)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberRequest' sequence class.
*/
#define T PrimeNumberRequest
#define TSeq PrimeNumberRequestSeq

#define T_initialize_w_params PrimeNumberRequest_initialize_w_params

#define T_finalize_w_params   PrimeNumberRequest_finalize_w_params
#define T_copy       PrimeNumberRequest_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *PrimeNumberCalculationStatusTYPENAME = "PrimeNumberCalculationStatus";

DDS_TypeCode* PrimeNumberCalculationStatus_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member PrimeNumberCalculationStatus_g_tc_members[3]=
    {

        {
            (char *)"REPLY_IN_PROGRESS",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            REPLY_IN_PROGRESS, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"REPLY_COMPLETED",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            REPLY_COMPLETED, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"REPLY_ERROR",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            REPLY_ERROR, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode PrimeNumberCalculationStatus_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"PrimeNumberCalculationStatus", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            PrimeNumberCalculationStatus_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for PrimeNumberCalculationStatus*/

    if (is_initialized) {
        return &PrimeNumberCalculationStatus_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &PrimeNumberCalculationStatus_g_tc;
}

RTIBool PrimeNumberCalculationStatus_initialize(
    PrimeNumberCalculationStatus* sample) {
    *sample = REPLY_IN_PROGRESS;
    return RTI_TRUE;
}

RTIBool PrimeNumberCalculationStatus_initialize_ex(
    PrimeNumberCalculationStatus* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberCalculationStatus_initialize_w_params(
        sample,&allocParams);

}

RTIBool PrimeNumberCalculationStatus_initialize_w_params(
    PrimeNumberCalculationStatus* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = REPLY_IN_PROGRESS;
    return RTI_TRUE;
}

void PrimeNumberCalculationStatus_finalize(
    PrimeNumberCalculationStatus* sample)
{

    if (sample==NULL) {
        return;
    }
}

void PrimeNumberCalculationStatus_finalize_ex(
    PrimeNumberCalculationStatus* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberCalculationStatus_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberCalculationStatus_finalize_w_params(
    PrimeNumberCalculationStatus* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void PrimeNumberCalculationStatus_finalize_optional_members(
    PrimeNumberCalculationStatus* sample, RTIBool deletePointers)
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

RTIBool PrimeNumberCalculationStatus_copy(
    PrimeNumberCalculationStatus* dst,
    const PrimeNumberCalculationStatus* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberCalculationStatus' sequence class.
*/
#define T PrimeNumberCalculationStatus
#define TSeq PrimeNumberCalculationStatusSeq

#define T_initialize_w_params PrimeNumberCalculationStatus_initialize_w_params

#define T_finalize_w_params   PrimeNumberCalculationStatus_finalize_w_params
#define T_copy       PrimeNumberCalculationStatus_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *PrimeNumberReplyTYPENAME = "PrimeNumberReply";

DDS_TypeCode* PrimeNumberReply_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PrimeNumberReply_g_tc_primes_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((PRIME_SEQUENCE_MAX_LENGTH)),NULL);
    static DDS_TypeCode_Member PrimeNumberReply_g_tc_members[2]=
    {

        {
            (char *)"primes",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"status",/* Member name */
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

    static DDS_TypeCode PrimeNumberReply_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"PrimeNumberReply", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            PrimeNumberReply_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for PrimeNumberReply*/

    if (is_initialized) {
        return &PrimeNumberReply_g_tc;
    }

    PrimeNumberReply_g_tc_primes_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    PrimeNumberReply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& PrimeNumberReply_g_tc_primes_sequence;
    PrimeNumberReply_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)PrimeNumberCalculationStatus_get_typecode();

    is_initialized = RTI_TRUE;

    return &PrimeNumberReply_g_tc;
}

RTIBool PrimeNumberReply_initialize(
    PrimeNumberReply* sample) {
    return PrimeNumberReply_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool PrimeNumberReply_initialize_ex(
    PrimeNumberReply* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberReply_initialize_w_params(
        sample,&allocParams);

}

RTIBool PrimeNumberReply_initialize_w_params(
    PrimeNumberReply* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        DDS_LongSeq_initialize(&sample->primes  );
        DDS_LongSeq_set_absolute_maximum(&sample->primes , ((PRIME_SEQUENCE_MAX_LENGTH)));
        if (!DDS_LongSeq_set_maximum(&sample->primes , ((PRIME_SEQUENCE_MAX_LENGTH)))) {
            return RTI_FALSE;
        }
    } else { 
        DDS_LongSeq_set_length(&sample->primes, 0);
    }
    if (!PrimeNumberCalculationStatus_initialize_w_params(&sample->status,
    allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void PrimeNumberReply_finalize(
    PrimeNumberReply* sample)
{

    PrimeNumberReply_finalize_ex(sample,RTI_TRUE);
}

void PrimeNumberReply_finalize_ex(
    PrimeNumberReply* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberReply_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberReply_finalize_w_params(
    PrimeNumberReply* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    DDS_LongSeq_finalize(&sample->primes);

    PrimeNumberCalculationStatus_finalize_w_params(&sample->status,deallocParams);

}

void PrimeNumberReply_finalize_optional_members(
    PrimeNumberReply* sample, RTIBool deletePointers)
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

    PrimeNumberCalculationStatus_finalize_optional_members(&sample->status, deallocParams->delete_pointers);
}

RTIBool PrimeNumberReply_copy(
    PrimeNumberReply* dst,
    const PrimeNumberReply* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!DDS_LongSeq_copy(&dst->primes ,
        &src->primes )) {
            return RTI_FALSE;
        }
        if (!PrimeNumberCalculationStatus_copy(
            &dst->status,(const PrimeNumberCalculationStatus*)&src->status)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberReply' sequence class.
*/
#define T PrimeNumberReply
#define TSeq PrimeNumberReplySeq

#define T_initialize_w_params PrimeNumberReply_initialize_w_params

#define T_finalize_w_params   PrimeNumberReply_finalize_w_params
#define T_copy       PrimeNumberReply_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

