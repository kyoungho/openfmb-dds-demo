
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
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

#include "HelloWorldTopicQuery.h"

/* ========================================================================= */
HelloWorldTopicQuery::HelloWorldTopicQuery() {
    id = 0;
    message = "";
}

void HelloWorldTopicQuery::clear(){
    id = 0;
    message = "";
}

System::Boolean HelloWorldTopicQuery::copy_from(HelloWorldTopicQuery^ src) {

    HelloWorldTopicQuery^ dst = this;

    dst->id = src->id;
    dst->message = src->message;
    return true;
}

Boolean HelloWorldTopicQuery::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    HelloWorldTopicQuery^ otherObj =
    dynamic_cast<HelloWorldTopicQuery^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (id != otherObj->id) {
        return false;
    }
    if (!message->Equals(otherObj->message)) {
        return false;
    }
    return true;
}

DDS::TypeCode^ HelloWorldTopicQuery::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(HelloWorldTopicQuery_get_typecode());
    }
    return _typecode;
}

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
