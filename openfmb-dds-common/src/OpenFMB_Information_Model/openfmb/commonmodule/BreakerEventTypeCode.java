
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

package OpenFMB_Information_Model.openfmb.commonmodule;

import com.rti.dds.typecode.*;

public class  BreakerEventTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        int __i=0;
        StructMember sm[]=new StructMember[6];

        sm[__i]=new  StructMember("isBlocked", false, (short)-1,  false,(TypeCode) TypeCode.TC_BOOLEAN,0 ,true);__i++;
        sm[__i]=new  StructMember("type", false, (short)-1,  false,(TypeCode) OpenFMB_Information_Model.openfmb.commonmodule.SwitchEventKindTypeCode.VALUE,1 , false);__i++;
        sm[__i]=new  StructMember("normalOpen", false, (short)-1,  false,(TypeCode) TypeCode.TC_BOOLEAN,2 ,true);__i++;
        sm[__i]=new  StructMember("timestamp", false, (short)-1,  false,(TypeCode) UML_Extension.dateTimeTypeCode.VALUE,3 ,true);__i++;
        sm[__i]=new  StructMember("qualityFlag", false, (short)-1,  false,(TypeCode) OpenFMB_Information_Model.openfmb.commonmodule.HexBinary16TypeCode.VALUE,4 ,true);__i++;
        sm[__i]=new  StructMember("typeExtension", false, (short)-1,  false,(TypeCode) new TypeCode(TCKind.TK_STRING,255),5 ,true);__i++;

        tc = TypeCodeFactory.TheTypeCodeFactory.create_struct_tc("OpenFMB_Information_Model::openfmb::commonmodule::BreakerEvent",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  sm);        
        return tc;
    }
}

