
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Message.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#include "Message.h"



#ifdef __cplusplus
    #ifndef ndds_cpp_h
        #include "ndds/ndds_cpp.h"
    #endif
    #ifndef dds_c_log_impl_h              
        #include "dds_c/dds_c_log_impl.h"                                
    #endif                
#else
    #ifndef ndds_c_h
        #include "ndds/ndds_c.h"
    #endif
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

    
        
const char *DateTimeTYPENAME = "DateTime";

    /* ========================================================================= */

DDS_TypeCode* DateTime_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DateTime_g_tc_members[6]=
    {
        {
            (char *)"year",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"month",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"day",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"hour",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"minute",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"second",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DateTime_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DateTime", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DateTime_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DateTime*/

    if (is_initialized) {
        return &DateTime_g_tc;
    }


    DateTime_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DateTime_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DateTime_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DateTime_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DateTime_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DateTime_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &DateTime_g_tc;
}



RTIBool DateTime_initialize(
    DateTime* sample) {
    return ::DateTime_initialize_ex(sample, RTI_TRUE, RTI_TRUE);
}
        
RTIBool DateTime_initialize_ex(
    DateTime* sample, RTIBool allocatePointers, RTIBool allocateMemory)
{

    if (allocatePointers == RTI_FALSE) {};
    if (allocateMemory == RTI_FALSE) {};
    if (sample == NULL) {
        return RTI_FALSE;
    };


    
    if (!RTICdrType_initLong(&sample->year)) {
        return RTI_FALSE;
    }            
                
    if (!RTICdrType_initLong(&sample->month)) {
        return RTI_FALSE;
    }            
                
    if (!RTICdrType_initLong(&sample->day)) {
        return RTI_FALSE;
    }            
                
    if (!RTICdrType_initLong(&sample->hour)) {
        return RTI_FALSE;
    }            
                
    if (!RTICdrType_initLong(&sample->minute)) {
        return RTI_FALSE;
    }            
                
    if (!RTICdrType_initLong(&sample->second)) {
        return RTI_FALSE;
    }            
            
    return RTI_TRUE;
}

RTIBool DateTime_initialize_w_params(
        DateTime* sample,
        const struct DDS_TypeAllocationParams_t * allocParams)
{
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    return ::DateTime_initialize_ex(
        sample, allocParams->allocate_pointers, allocParams->allocate_memory);
}

void DateTime_finalize(
    DateTime* sample)
{
    ::DateTime_finalize_ex(sample,RTI_TRUE);
}
        
void DateTime_finalize_ex(
    DateTime* sample,RTIBool deletePointers)
{

    if (sample == NULL) {
        return;
    };
    if (deletePointers == RTI_FALSE) {};

 
}

void DateTime_finalize_w_params(
        DateTime* sample,
        const struct DDS_TypeDeallocationParams_t * deallocParams)
{
    if (deallocParams == NULL) {
        return;
    }
    ::DateTime_finalize_ex(
        sample,deallocParams->delete_pointers);
}

RTIBool DateTime_copy(
    DateTime* dst,
    const DateTime* src)
{
    
    if (!RTICdrType_copyLong(
        &dst->year,&src->year)) {
        return RTI_FALSE;
    }                        
                
    if (!RTICdrType_copyLong(
        &dst->month,&src->month)) {
        return RTI_FALSE;
    }                        
                
    if (!RTICdrType_copyLong(
        &dst->day,&src->day)) {
        return RTI_FALSE;
    }                        
                
    if (!RTICdrType_copyLong(
        &dst->hour,&src->hour)) {
        return RTI_FALSE;
    }                        
                
    if (!RTICdrType_copyLong(
        &dst->minute,&src->minute)) {
        return RTI_FALSE;
    }                        
                
    if (!RTICdrType_copyLong(
        &dst->second,&src->second)) {
        return RTI_FALSE;
    }                        
            

    return RTI_TRUE;
}


        
/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DateTime' sequence class.
*/
#define T DateTime
#define TSeq DateTimeSeq
#define T_initialize_ex ::DateTime_initialize_ex
#define T_finalize_ex   ::DateTime_finalize_ex
#define T_copy       ::DateTime_copy
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T



/* ----------------------------------------------------------------- */

    
        
const char *MessageTextTYPENAME = "MessageText";

    /* ========================================================================= */

DDS_TypeCode* MessageText_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode MessageText_g_tc_string = DDS_INITIALIZE_STRING_TYPECODE((MSG_MAX_LENGTH));

    static DDS_TypeCode MessageText_g_tc =
    {{
        DDS_TK_ALIAS, /* Kind*/
        DDS_BOOLEAN_FALSE, /* Is a pointer? */
        -1, /* Ignored */
        (char *)"MessageText", /* Name */
        NULL, /* Content type code is assigned later */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for MessageText */

    if (is_initialized) {
        return &MessageText_g_tc;
    }

    MessageText_g_tc._data._typeCode = (RTICdrTypeCode *)&MessageText_g_tc_string; /* Content type code */

    is_initialized = RTI_TRUE;

    return &MessageText_g_tc;
}



RTIBool MessageText_initialize(
    MessageText* sample) {
    return ::MessageText_initialize_ex(sample, RTI_TRUE, RTI_TRUE);
}
        
RTIBool MessageText_initialize_ex(
    MessageText* sample, RTIBool allocatePointers, RTIBool allocateMemory)
{

    if (allocatePointers == RTI_FALSE) {};
    if (allocateMemory == RTI_FALSE) {};
    if (sample == NULL) {
        return RTI_FALSE;
    };


     
    
    if (((CORBA::Char *&)*sample)!=NULL){
        CORBA::string_free((CORBA::Char *&)*sample);
    }
    
    ((CORBA::Char *&)*sample)=(CORBA::Char *)CORBA::string_alloc(((MSG_MAX_LENGTH)));
    
    if (((CORBA::Char *&)*sample) == NULL) {    
        return RTI_FALSE;
    }
    
    memset((CORBA::Char *&)*sample,'x',((MSG_MAX_LENGTH)));
    ((CORBA::Char *&)*sample)[((MSG_MAX_LENGTH))] = '\0';
            
    return RTI_TRUE;
}

RTIBool MessageText_initialize_w_params(
        MessageText* sample,
        const struct DDS_TypeAllocationParams_t * allocParams)
{
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    return ::MessageText_initialize_ex(
        sample, allocParams->allocate_pointers, allocParams->allocate_memory);
}

void MessageText_finalize(
    MessageText* sample)
{
    ::MessageText_finalize_ex(sample,RTI_TRUE);
}
        
void MessageText_finalize_ex(
    MessageText* sample,RTIBool deletePointers)
{

    if (sample == NULL) {
        return;
    };
    if (deletePointers == RTI_FALSE) {};


    CORBA::string_free((CORBA::Char *&)*sample);
    ((CORBA::Char *&)*sample)=(CORBA::Char *)NULL;
             
}

void MessageText_finalize_w_params(
        MessageText* sample,
        const struct DDS_TypeDeallocationParams_t * deallocParams)
{
    if (deallocParams == NULL) {
        return;
    }
    ::MessageText_finalize_ex(
        sample,deallocParams->delete_pointers);
}

RTIBool MessageText_copy(
    MessageText* dst,
    const MessageText* src)
{
            
    *dst = *src;
            

    return RTI_TRUE;
}



/* ----------------------------------------------------------------- */

    
        
const char *MessageTYPENAME = "Message";

    /* ========================================================================= */

DDS_TypeCode* Message_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member Message_g_tc_members[2]=
    {
        {
            (char *)"time",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        },
        {
            (char *)"msg",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Message_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"Message", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        Message_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for Message*/

    if (is_initialized) {
        return &Message_g_tc;
    }


    Message_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)DateTime_get_typecode();
    Message_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)MessageText_get_typecode();

    is_initialized = RTI_TRUE;

    return &Message_g_tc;
}



RTIBool Message_initialize(
    Message* sample) {
    return ::Message_initialize_ex(sample, RTI_TRUE, RTI_TRUE);
}
        
RTIBool Message_initialize_ex(
    Message* sample, RTIBool allocatePointers, RTIBool allocateMemory)
{

    if (allocatePointers == RTI_FALSE) {};
    if (allocateMemory == RTI_FALSE) {};
    if (sample == NULL) {
        return RTI_FALSE;
    };



    if (!DateTime_initialize(&(DateTime&)sample->time)) {
        return RTI_FALSE;
    }
                 
    
    if (((CORBA::Char *&)sample->msg)!=NULL){
        CORBA::string_free((CORBA::Char *&)sample->msg);
    }
    
    ((CORBA::Char *&)sample->msg)=(CORBA::Char *)CORBA::string_alloc(((MSG_MAX_LENGTH)));
    
    if (((CORBA::Char *&)sample->msg) == NULL) {    
        return RTI_FALSE;
    }
    
    memset((CORBA::Char *&)sample->msg,'x',((MSG_MAX_LENGTH)));
    ((CORBA::Char *&)sample->msg)[((MSG_MAX_LENGTH))] = '\0';
            
    return RTI_TRUE;
}

RTIBool Message_initialize_w_params(
        Message* sample,
        const struct DDS_TypeAllocationParams_t * allocParams)
{
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    return ::Message_initialize_ex(
        sample, allocParams->allocate_pointers, allocParams->allocate_memory);
}

void Message_finalize(
    Message* sample)
{
    ::Message_finalize_ex(sample,RTI_TRUE);
}
        
void Message_finalize_ex(
    Message* sample,RTIBool deletePointers)
{

    if (sample == NULL) {
        return;
    };
    if (deletePointers == RTI_FALSE) {};


    DateTime_finalize(&(DateTime&)sample->time);
            
    CORBA::string_free((CORBA::Char *&)sample->msg);
    ((CORBA::Char *&)sample->msg)=(CORBA::Char *)NULL;
             
}

void Message_finalize_w_params(
        Message* sample,
        const struct DDS_TypeDeallocationParams_t * deallocParams)
{
    if (deallocParams == NULL) {
        return;
    }
    ::Message_finalize_ex(
        sample,deallocParams->delete_pointers);
}

RTIBool Message_copy(
    Message* dst,
    const Message* src)
{
    
    if (!DateTime_copy(
        &(DateTime&)dst->time,&(DateTime&)src->time)) {
        return RTI_FALSE;
    }
                        
    dst->msg = src->msg;
            

    return RTI_TRUE;
}


        
/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'Message' sequence class.
*/
#define T Message
#define TSeq MessageSeq
#define T_initialize_ex ::Message_initialize_ex
#define T_finalize_ex   ::Message_finalize_ex
#define T_copy       ::Message_copy
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T



/* ----------------------------------------------------------------- */

