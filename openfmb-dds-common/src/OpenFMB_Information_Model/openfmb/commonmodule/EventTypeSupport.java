
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

package OpenFMB_Information_Model.openfmb.commonmodule;

import com.rti.dds.cdr.CdrEncapsulation;
import com.rti.dds.cdr.CdrInputStream;
import com.rti.dds.cdr.CdrOutputStream;
import com.rti.dds.cdr.CdrPrimitiveType;
import com.rti.dds.cdr.CdrBuffer;
import com.rti.dds.cdr.CdrHelper;
import com.rti.dds.cdr.CdrMemberInfo;
import com.rti.dds.domain.DomainParticipant;
import com.rti.dds.publication.DataWriter;
import com.rti.dds.publication.DataWriterListener;
import com.rti.dds.subscription.DataReader;
import com.rti.dds.subscription.DataReaderListener;
import com.rti.dds.topic.KeyHash_t;
import com.rti.dds.topic.TypeSupportImpl;
import com.rti.dds.topic.TypeSupportType;
import com.rti.dds.util.Sequence;
import com.rti.dds.topic.DefaultEndpointData;
import com.rti.dds.topic.SampleAssignabilityProperty;
import com.rti.dds.infrastructure.RETCODE_ERROR;

import com.rti.dds.infrastructure.*;
import com.rti.dds.topic.TypeSupportParticipantInfo;
import com.rti.dds.topic.TypeSupportEndpointInfo;
import com.rti.dds.topic.PrintFormatProperty;
import com.rti.dds.typecode.TypeCode;
import com.rti.dds.cdr.IllegalCdrStateException;

import com.rti.dds.infrastructure.Copyable;

/**
* A collection of useful methods for dealing with objects of type
* Event
*/

public class EventTypeSupport extends TypeSupportImpl {
    // -----------------------------------------------------------------------
    // Private Fields
    // -----------------------------------------------------------------------

    private static final String TYPE_NAME = "OpenFMB_Information_Model::openfmb::commonmodule::Event";

    private static final char[] PLUGIN_VERSION = {2, 0, 0, 0};     
    private static final EventTypeSupport _singleton
    = new EventTypeSupport();

    // -----------------------------------------------------------------------
    // Public Methods
    // -----------------------------------------------------------------------

    // --- External methods: -------------------------------------------------
    /* The methods in this section are for use by users of RTI Connext
    */

    public static String get_type_name() {
        return _singleton.get_type_nameI();
    }

    public static void register_type(DomainParticipant participant,
    String type_name) {
        _singleton.register_typeI(participant, type_name);
    }

    public static void unregister_type(DomainParticipant participant,
    String type_name) {
        _singleton.unregister_typeI(participant, type_name);
    }

    /* The methods in this section are for use by RTI Connext
    * itself and by the code generated by rtiddsgen for other types.
    * They should be used directly or modified only by advanced users and are
    * subject to change in future versions of RTI Connext.
    */
    public static EventTypeSupport get_instance() {
        return _singleton;
    }

    public static EventTypeSupport getInstance() {
        return get_instance();
    }

    public static TypeCode getTypeCode(){
        return EventTypeCode.VALUE;
    }

    public Object create_data() {
        return Event.create();
    }

    public void destroy_data(Object data) {
        return;
    }
    public Object create_key() {
        return new Event();
    }

    public void destroy_key(Object key) {
        return;
    }
    public Class get_type() {
        return Event.class;
    }

    /**
    * This is a concrete implementation of this method inherited from the base class.
    * This method will perform a deep copy of <code>source</code> into
    * <code>destination</code>.
    * 
    * @param src The Object which contains the data to be copied.
    * @return Returns <code>destination</code>.
    * @exception NullPointerException If <code>destination</code> or 
    * <code>source</code> is null.
    * @exception ClassCastException If either <code>destination</code> or
    * <code>this</code> is not a <code>Event</code>
    * type.
    */
    public Object copy_data(Object destination, Object source) {

        Event typedDst = (Event) destination;
        Event typedSrc = (Event) source;

        return typedDst.copy_from(typedSrc);

    }

    public long get_serialized_sample_max_size(Object endpoint_data,boolean include_encapsulation,short encapsulation_id,long currentAlignment) {
        long origAlignment = currentAlignment;
        long encapsulation_size = currentAlignment;

        if(include_encapsulation) {
            if (!CdrEncapsulation.isValidEncapsulationKind(encapsulation_id)) {
                throw new RETCODE_ERROR("Unsupported encapsulation");
            }

            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size -= currentAlignment;
            currentAlignment = 0;
            origAlignment = 0;
        } 

        currentAlignment += OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().get_serialized_sample_max_size(endpoint_data,false,encapsulation_id,currentAlignment);

        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 12);
        currentAlignment += CdrPrimitiveType.LONG.getMaxSizeSerialized(0 );

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        currentAlignment += CdrPrimitiveType.getStringMaxSizeSerialized(currentAlignment, (255)+1);
        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 12);
        currentAlignment += CdrPrimitiveType.getStringMaxSizeSerialized(0, (255)+1);

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 12);
        currentAlignment += CdrPrimitiveType.getStringMaxSizeSerialized(0, (255)+1);

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        if (include_encapsulation) {
            currentAlignment += encapsulation_size;
        }
        return  currentAlignment - origAlignment;
    }

    public long get_serialized_sample_min_size(Object endpoint_data,boolean include_encapsulation,short encapsulation_id,long currentAlignment) {

        long origAlignment = currentAlignment;
        long encapsulation_size = currentAlignment;

        if(include_encapsulation) {
            if (!CdrEncapsulation.isValidEncapsulationKind(encapsulation_id)) {
                throw new RETCODE_ERROR("Unsupported encapsulation");
            }

            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size -= currentAlignment;
            currentAlignment = 0;
            origAlignment = 0;
        } 

        currentAlignment += OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().get_serialized_sample_min_size(endpoint_data,false,encapsulation_id,currentAlignment);
        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 4);

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        currentAlignment += CdrPrimitiveType.getStringMaxSizeSerialized(currentAlignment, 1);
        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 12);

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        currentAlignment += (CdrPrimitiveType.getPadSize(currentAlignment, 4) + 12);

        currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);

        if (include_encapsulation) {
            currentAlignment += encapsulation_size;
        }
        return  currentAlignment - origAlignment;

    }

    public long get_serialized_sample_size(
        Object endpoint_data, boolean include_encapsulation, 
        short encapsulation_id, long currentAlignment,
        Object sample) 
    {

        Event typedSrc = (Event) sample;
        DefaultEndpointData epd = ((DefaultEndpointData) endpoint_data) ;
        long origAlignment = currentAlignment;
        long encapsulation_size = currentAlignment;

        if(include_encapsulation) {
            if (!CdrEncapsulation.isValidEncapsulationKind(encapsulation_id)) {
                throw new RETCODE_ERROR("Unsupported encapsulation");
            }

            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size -= currentAlignment;
            currentAlignment = 0;
            origAlignment = 0;
            epd.setBaseAlignment(currentAlignment);
        } 

        currentAlignment += OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().get_serialized_sample_size(
            endpoint_data, false, encapsulation_id, currentAlignment, sample);

        currentAlignment += (CdrPrimitiveType.getPadSize(epd.getAlignment(currentAlignment), 4) + 4);
        epd.setBaseAlignment(currentAlignment);
        if (typedSrc.timestamp != null) {

            currentAlignment  +=  CdrPrimitiveType.LONG.getMaxSizeSerialized(epd.getAlignment(currentAlignment));

            currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        }

        currentAlignment  +=  CdrPrimitiveType.getStringSerializedSize(epd.getAlignment(currentAlignment), typedSrc.type );
        currentAlignment += (CdrPrimitiveType.getPadSize(epd.getAlignment(currentAlignment), 4) + 12);
        epd.setBaseAlignment(currentAlignment);
        if (typedSrc.value != null) {

            currentAlignment  +=  CdrPrimitiveType.getStringSerializedSize(epd.getAlignment(currentAlignment), typedSrc.value );

            currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        }
        currentAlignment += (CdrPrimitiveType.getPadSize(epd.getAlignment(currentAlignment), 4) + 12);
        epd.setBaseAlignment(currentAlignment);
        if (typedSrc.typeExtension != null) {

            currentAlignment  +=  CdrPrimitiveType.getStringSerializedSize(epd.getAlignment(currentAlignment), typedSrc.typeExtension );

            currentAlignment += CdrPrimitiveType.getPadSize(currentAlignment, 4);
        }

        if (include_encapsulation) {
            currentAlignment += encapsulation_size;
        }
        return currentAlignment - origAlignment;
    }

    public long get_serialized_key_max_size(
        Object endpoint_data,
        boolean include_encapsulation, 
        short encapsulation_id,
        long currentAlignment) 
    {
        long origAlignment = currentAlignment;
        long encapsulation_size = currentAlignment;

        if(include_encapsulation) {
            if (!CdrEncapsulation.isValidEncapsulationKind(encapsulation_id)) {
                throw new RETCODE_ERROR("Unsupported encapsulation");
            }

            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size += CdrPrimitiveType.SHORT.getMaxSizeSerialized(encapsulation_size);
            encapsulation_size -= currentAlignment;
            currentAlignment = 0;
            origAlignment = 0;
        } 

        currentAlignment += get_serialized_sample_max_size(
            endpoint_data,false,encapsulation_id,currentAlignment);
        if (include_encapsulation) {
            currentAlignment += encapsulation_size;
        }

        return currentAlignment - origAlignment;
    }

    public void serialize(Object endpoint_data,Object src, CdrOutputStream dst,boolean serialize_encapsulation,
    short encapsulation_id, boolean serialize_sample, Object endpoint_plugin_qos) {
        int position = 0;
        long memberId = 0;
        int memberLengthPosition = 0;
        boolean skipListEndId_tmp = false;
        long maxLength = 0;
        DefaultEndpointData epd = (DefaultEndpointData) endpoint_data;

        if (!dst.isDirty()) {

            dst.setDirtyBit(true);
            maxLength = epd.get_serialized_max_size();

            if (maxLength > 65535) {
                dst.useExtendedMemberId = true;
            }
            else{
                dst.useExtendedMemberId = false;
            }
        }

        if(serialize_encapsulation) {
            dst.serializeAndSetCdrEncapsulation(encapsulation_id);

            position = dst.resetAlignment();

        }

        if(serialize_sample) {

            Event typedSrc = (Event) src;

            OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().serialize(endpoint_data,src,dst,false,encapsulation_id,serialize_sample,endpoint_plugin_qos);

            memberId = 3;
            memberLengthPosition = dst.writeMemberId((short)memberId);
            if (typedSrc.timestamp != null) {
                dst.writeLong(typedSrc.timestamp);
            }
            dst.writeMemberLength(memberLengthPosition, false);

            dst.writeString(typedSrc.type,255);

            memberId = 5;
            if (dst.useExtendedMemberId == true) {
                memberLengthPosition = dst.writeMemberId((int)memberId);
            } else {
                memberLengthPosition = dst.writeMemberId((short)memberId);
            }
            if (typedSrc.value != null) {
                dst.writeString(typedSrc.value,255);
            }
            if (dst.useExtendedMemberId == true) {
                dst.writeMemberLength(memberLengthPosition, true);
            } else {
                dst.writeMemberLength(memberLengthPosition, false);
            }

            memberId = 6;
            if (dst.useExtendedMemberId == true) {
                memberLengthPosition = dst.writeMemberId((int)memberId);
            } else {
                memberLengthPosition = dst.writeMemberId((short)memberId);
            }
            if (typedSrc.typeExtension != null) {
                dst.writeString(typedSrc.typeExtension,255);
            }
            if (dst.useExtendedMemberId == true) {
                dst.writeMemberLength(memberLengthPosition, true);
            } else {
                dst.writeMemberLength(memberLengthPosition, false);
            }
        }

        if (serialize_encapsulation) {
            dst.restoreAlignment(position);
        }

    }
    public long serialize_to_cdr_buffer(
        byte[] buffer,
        long length,
        Event src)
    {
        return super.serialize_to_cdr_buffer(buffer,length,src);
    }

    public void serialize_key(
        Object endpoint_data,
        Object src,
        CdrOutputStream dst,
        boolean serialize_encapsulation,
        short encapsulation_id,
        boolean serialize_key,
        Object endpoint_plugin_qos) 
    {
        int position = 0;

        if (serialize_encapsulation) {
            dst.serializeAndSetCdrEncapsulation(encapsulation_id);

            position = dst.resetAlignment();
        }

        if (serialize_key) {

            Event typedSrc = (Event) src;    
            serialize(endpoint_data, src, dst, false, CdrEncapsulation.CDR_ENCAPSULATION_ID_CDR_BE, true, endpoint_plugin_qos);

        }

        if (serialize_encapsulation) {
            dst.restoreAlignment(position);
        }
    }

    public Object deserialize_sample(
        Object endpoint_data,
        Object dst, 
        CdrInputStream src, boolean deserialize_encapsulation,
        boolean deserialize_sample,
        Object endpoint_plugin_qos) 
    {
        int position = 0;
        CdrMemberInfo memberInfo;
        long length = 0;
        boolean end = false;
        int tmpPosition, tmpSize;
        long tmpLength;

        if(deserialize_encapsulation) {
            src.deserializeAndSetCdrEncapsulation();

            position = src.resetAlignment();
        }

        if(deserialize_sample) {

            Event typedDst = (Event) dst;
            typedDst.clear();      
            OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().deserialize_sample(endpoint_data,dst,src,false,deserialize_sample,endpoint_plugin_qos);

            try{

                memberInfo = src.readMemberInfo();
                tmpPosition = src.getBuffer().currentPosition();
                tmpSize = src.getBuffer().getSize(); 
                tmpLength = memberInfo.length;
                src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
                if (tmpLength > 0) {

                    typedDst.timestamp = src.readLong();
                }
                else {
                    typedDst.timestamp = null;
                }
                src.getBuffer().setDesBufferSize(tmpSize);
                src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

                typedDst.type = src.readString(255);

                memberInfo = src.readMemberInfo();
                tmpPosition = src.getBuffer().currentPosition();
                tmpSize = src.getBuffer().getSize(); 
                tmpLength = memberInfo.length;
                src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
                if (tmpLength > 0) {

                    typedDst.value = src.readString(255);
                }
                else {
                    typedDst.value = null;
                }
                src.getBuffer().setDesBufferSize(tmpSize);
                src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

                memberInfo = src.readMemberInfo();
                tmpPosition = src.getBuffer().currentPosition();
                tmpSize = src.getBuffer().getSize(); 
                tmpLength = memberInfo.length;
                src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
                if (tmpLength > 0) {

                    typedDst.typeExtension = src.readString(255);
                }
                else {
                    typedDst.typeExtension = null;
                }
                src.getBuffer().setDesBufferSize(tmpSize);
                src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

            } catch (IllegalCdrStateException stateEx) {
                if (src.available() >= CdrEncapsulation.CDR_ENCAPSULATION_PARAMETER_ID_ALIGNMENT) {
                    throw new RETCODE_ERROR("Error deserializing sample! Remainder: " + src.available() + "\n" +
                    "Exception caused by: " + stateEx.getMessage());
                }
            } catch (Exception ex) {
                throw new RETCODE_ERROR(ex.getMessage());        
            }

        }
        if (deserialize_encapsulation) {
            src.restoreAlignment(position);
        }

        return dst;
    }

    public void deserialize_from_cdr_buffer(
        Event dst,
        byte[] buffer,
        long length) 
    {
        super.deserialize_from_cdr_buffer(dst,buffer,length);
    }

    public String data_to_string(
        Event sample,
        PrintFormatProperty property) 
    {
        return super.data_to_string(sample, property);
    }

    public String data_to_string(
        Event sample) 
    {
        return super.data_to_string(sample);
    }

    public Object deserialize_key_sample(
        Object endpoint_data,
        Object dst,
        CdrInputStream src,
        boolean deserialize_encapsulation,
        boolean deserialize_key,
        Object endpoint_plugin_qos) 
    {
        int position = 0;
        CdrMemberInfo memberInfo;
        long length = 0;
        boolean end = false;
        int tmpPosition, tmpSize;
        long tmpLength;

        if(deserialize_encapsulation) {
            src.deserializeAndSetCdrEncapsulation();

            position = src.resetAlignment();
        }

        if(deserialize_key) {

            Event typedDst = (Event) dst;

            deserialize_sample(endpoint_data, dst, src, false, true, endpoint_plugin_qos);

        }
        if (deserialize_encapsulation) {
            src.restoreAlignment(position);
        }

        return dst;
    }

    public void skip(Object endpoint_data, 
    CdrInputStream src,
    boolean skip_encapsulation, 
    boolean skip_sample, 
    Object endpoint_plugin_qos)
    {
        int position = 0;
        CdrMemberInfo memberInfo;
        long length = 0;
        boolean end = false;
        int tmpPosition, tmpSize;
        long tmpLength;

        if (skip_encapsulation) {
            src.skipEncapsulation();

            position = src.resetAlignment();
        }

        if (skip_sample) {

            OpenFMB_Information_Model.openfmb.commonmodule.IdentifiedObjectTypeSupport.get_instance().skip(endpoint_data, src, false, true, endpoint_plugin_qos);

            memberInfo = src.readMemberInfo();
            tmpPosition = src.getBuffer().currentPosition();
            tmpSize = src.getBuffer().getSize(); 
            tmpLength = memberInfo.length;
            src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
            if (tmpLength > 0) {
                src.skipLong();
            }
            src.getBuffer().setDesBufferSize(tmpSize);
            src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

            src.skipString();

            memberInfo = src.readMemberInfo();
            tmpPosition = src.getBuffer().currentPosition();
            tmpSize = src.getBuffer().getSize(); 
            tmpLength = memberInfo.length;
            src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
            if (tmpLength > 0) {
                src.skipString();
            }
            src.getBuffer().setDesBufferSize(tmpSize);
            src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

            memberInfo = src.readMemberInfo();
            tmpPosition = src.getBuffer().currentPosition();
            tmpSize = src.getBuffer().getSize(); 
            tmpLength = memberInfo.length;
            src.getBuffer().setDesBufferSize((int)(tmpPosition + memberInfo.length));
            if (tmpLength > 0) {
                src.skipString();
            }
            src.getBuffer().setDesBufferSize(tmpSize);
            src.getBuffer().setCurrentPosition((int)(tmpPosition + tmpLength));

        }

        if (skip_encapsulation) {
            src.restoreAlignment(position);
        }
    }

    public Object serialized_sample_to_key(
        Object endpoint_data,
        Object sample,
        CdrInputStream src, 
        boolean deserialize_encapsulation,  
        boolean deserialize_key, 
        Object endpoint_plugin_qos) 
    {

        int position = 0;
        CdrMemberInfo memberInfo;
        long length = 0;
        boolean end = false;
        int tmpPosition, tmpSize;
        long tmpLength;

        if(deserialize_encapsulation) {
            src.deserializeAndSetCdrEncapsulation();

            position = src.resetAlignment();
        }

        if (deserialize_key) {

            Event typedDst = (Event) sample;

            deserialize_sample(
                endpoint_data, sample, src, false,
                true, endpoint_plugin_qos);

        }

        if (deserialize_encapsulation) {
            src.restoreAlignment(position);
        }

        return sample;
    }

    // -----------------------------------------------------------------------
    // Callbacks
    // -----------------------------------------------------------------------
    public Object on_participant_attached(Object registration_data,
    TypeSupportParticipantInfo participant_info,
    boolean top_level_registration,
    Object container_plugin_context,
    TypeCode type_code) {
        return super.on_participant_attached(
            registration_data, participant_info, top_level_registration,
            container_plugin_context, type_code);
    }

    public void on_participant_detached(Object participant_data) {
        super.on_participant_detached(participant_data);
    }

    public Object on_endpoint_attached(Object participantData,
    TypeSupportEndpointInfo endpoint_info,
    boolean top_level_registration,
    Object container_plugin_context) {
        return super.on_endpoint_attached(
            participantData,  endpoint_info,  
            top_level_registration, container_plugin_context);        
    }

    public void on_endpoint_detached(Object endpoint_data) {
        super.on_endpoint_detached(endpoint_data);
    }
    // -----------------------------------------------------------------------
    // Protected Methods
    // -----------------------------------------------------------------------

    protected DataWriter create_datawriter(long native_writer,
    DataWriterListener listener,
    int mask) {
        return null;

    }

    protected DataReader create_datareader(long native_reader,
    DataReaderListener listener,
    int mask) {

        return null;

    }

    // -----------------------------------------------------------------------
    // Constructor
    // -----------------------------------------------------------------------

    protected EventTypeSupport() {

        /* If the user data type supports keys, then the second argument
        to the constructor below should be true.  Otherwise it should
        be false. */        

        super(TYPE_NAME, false,EventTypeCode.VALUE,Event.class,TypeSupportType.TST_STRUCT, PLUGIN_VERSION);

    }

    protected EventTypeSupport (boolean enableKeySupport) {

        super(TYPE_NAME, enableKeySupport,EventTypeCode.VALUE,Event.class,TypeSupportType.TST_STRUCT, PLUGIN_VERSION);
    }
}

