
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

package OpenFMB_Information_Model.openfmb.commonmodule;

import com.rti.dds.typecode.*;

public class  RegulatorEventKindTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        int i=0;
        EnumMember em[] = new EnumMember[4];

        int[] ordinals = RegulatorEventKind.getOrdinals();
        for (i=0;i<4;i++) {
            em[i]=new EnumMember(RegulatorEventKind.valueOf(ordinals[i]).toString(),ordinals[i]);
        }

        tc = TypeCodeFactory.TheTypeCodeFactory.create_enum_tc("OpenFMB_Information_Model::openfmb::commonmodule::RegulatorEventKind",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  em);        
        return tc;
    }
}

