
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

package com.rti.hello.idl;

import com.rti.dds.typecode.*;

public class  HelloWorldTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        int __i=0;
        StructMember sm[]=new StructMember[3];

        sm[__i]=new  StructMember("sender", false, (short)-1, true,(TypeCode) new TypeCode(TCKind.TK_STRING,(com.rti.hello.idl.MAX_NAME_LEN.VALUE)),0 , false);__i++;
        sm[__i]=new  StructMember("message", false, (short)-1,  false,(TypeCode) new TypeCode(TCKind.TK_STRING,(com.rti.hello.idl.MAX_MSG_LEN.VALUE)),1 , false);__i++;
        sm[__i]=new  StructMember("count", false, (short)-1,  false,(TypeCode) TypeCode.TC_LONG,2 , false);__i++;

        tc = TypeCodeFactory.TheTypeCodeFactory.create_struct_tc("HelloWorld",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  sm);        
        return tc;
    }
}

