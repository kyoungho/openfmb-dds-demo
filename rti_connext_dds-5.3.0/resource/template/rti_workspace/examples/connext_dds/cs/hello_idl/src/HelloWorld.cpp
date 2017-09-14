
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#pragma managed

using namespace System;
using namespace System::Collections;
using namespace DDS;

#include "HelloWorld.h"

/* ========================================================================= */
HelloWorld::HelloWorld() {
    prefix = "";
    sampleId = 0;
    payload = gcnew DDS::ByteSeq ((HELLODDS_MAX_PAYLOAD_SIZE::VALUE));
}

void HelloWorld::clear(){
    prefix = "";
    sampleId = 0;
    payload->length=0;
}

System::Boolean HelloWorld::copy_from(HelloWorld^ src) {

    HelloWorld^ dst = this;

    dst->prefix = src->prefix;
    dst->sampleId = src->sampleId;
    if (!dst->payload->copy_from(src->payload)) {
        return false;
    }
    return true;
}

Boolean HelloWorld::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    HelloWorld^ otherObj =
    dynamic_cast<HelloWorld^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (!prefix->Equals(otherObj->prefix)) {
        return false;
    }
    if (sampleId != otherObj->sampleId) {
        return false;
    }
    if (!payload->Equals(otherObj->payload)) {
        return false;
    }
    return true;
}

DDS::TypeCode^ HelloWorld::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(HelloWorld_get_typecode());
    }
    return _typecode;
}

DDS_TypeCode* HelloWorld_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode HelloWorld_g_tc_prefix_string = DDS_INITIALIZE_STRING_TYPECODE(((HELLODDS_MAX_STRING_SIZE::VALUE)));
    static DDS_TypeCode HelloWorld_g_tc_payload_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((HELLODDS_MAX_PAYLOAD_SIZE::VALUE)),NULL);
    static DDS_TypeCode_Member HelloWorld_g_tc_members[3]=
    {

        {
            (char *)"prefix",/* Member name */
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
            (char *)"sampleId",/* Member name */
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
        }, 
        {
            (char *)"payload",/* Member name */
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
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode HelloWorld_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"HelloWorld", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            HelloWorld_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for HelloWorld*/

    if (is_initialized) {
        return &HelloWorld_g_tc;
    }

    HelloWorld_g_tc_payload_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    HelloWorld_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&HelloWorld_g_tc_prefix_string;

    HelloWorld_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    HelloWorld_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& HelloWorld_g_tc_payload_sequence;

    is_initialized = RTI_TRUE;

    return &HelloWorld_g_tc;
}
