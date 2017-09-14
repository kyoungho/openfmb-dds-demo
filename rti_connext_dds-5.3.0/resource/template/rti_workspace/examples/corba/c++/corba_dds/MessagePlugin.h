
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Message.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef MessagePlugin_793628338_h
#define MessagePlugin_793628338_h

#include "Message.h"



struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif


#define DateTimePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DateTimePlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DateTimePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DateTimePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 
#define DateTimePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DateTimePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DateTime*
DateTimePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DateTime *
DateTimePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DateTime *
DateTimePluginSupport_create_data();

NDDSUSERDllExport extern RTIBool 
DateTimePluginSupport_copy_data(
    DateTime *out,
    const DateTime *in);
    
NDDSUSERDllExport extern void 
DateTimePluginSupport_destroy_data_w_params(
    DateTime *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DateTimePluginSupport_destroy_data_ex(
    DateTime *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DateTimePluginSupport_destroy_data(
    DateTime *sample);

NDDSUSERDllExport extern void 
DateTimePluginSupport_print_data(
    const DateTime *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DateTimePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DateTimePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DateTimePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DateTimePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DateTimePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DateTime *out,
    const DateTime *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DateTimePlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const DateTime *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DateTimePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DateTime *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DateTimePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DateTime **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool DateTimePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DateTimePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
DateTimePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int DateTimePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size,
    const DateTime * sample);

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DateTimePlugin_get_key_kind();

NDDSUSERDllExport extern unsigned int 
DateTimePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DateTimePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DateTime *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DateTimePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DateTime * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DateTimePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DateTime ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DateTimePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DateTime *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DateTimePlugin_new();

NDDSUSERDllExport extern void
DateTimePlugin_delete(struct PRESTypePlugin *);


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


#define MessageTextPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define MessageTextPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define MessageTextPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define MessageTextPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 
#define MessageTextPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define MessageTextPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern MessageText*
MessageTextPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern MessageText *
MessageTextPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern MessageText *
MessageTextPluginSupport_create_data();

NDDSUSERDllExport extern RTIBool 
MessageTextPluginSupport_copy_data(
    MessageText *out,
    const MessageText *in);
    
NDDSUSERDllExport extern void 
MessageTextPluginSupport_destroy_data_w_params(
    MessageText *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
MessageTextPluginSupport_destroy_data_ex(
    MessageText *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
MessageTextPluginSupport_destroy_data(
    MessageText *sample);

NDDSUSERDllExport extern void 
MessageTextPluginSupport_print_data(
    const MessageText *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
MessageTextPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
MessageTextPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
MessageTextPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
MessageTextPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
MessageTextPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    MessageText *out,
    const MessageText *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
MessageTextPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const MessageText *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MessageTextPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    MessageText *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool MessageTextPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
MessageTextPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
MessageTextPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int MessageTextPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size,
    const MessageText * sample);

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
MessageTextPlugin_get_key_kind();

NDDSUSERDllExport extern unsigned int 
MessageTextPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
MessageTextPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const MessageText *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MessageTextPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    MessageText * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
MessageTextPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    MessageText *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);



#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif


#define MessagePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define MessagePlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define MessagePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define MessagePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 
#define MessagePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define MessagePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Message*
MessagePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Message *
MessagePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Message *
MessagePluginSupport_create_data();

NDDSUSERDllExport extern RTIBool 
MessagePluginSupport_copy_data(
    Message *out,
    const Message *in);
    
NDDSUSERDllExport extern void 
MessagePluginSupport_destroy_data_w_params(
    Message *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
MessagePluginSupport_destroy_data_ex(
    Message *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
MessagePluginSupport_destroy_data(
    Message *sample);

NDDSUSERDllExport extern void 
MessagePluginSupport_print_data(
    const Message *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
MessagePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
MessagePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
MessagePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
MessagePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
MessagePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Message *out,
    const Message *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
MessagePlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Message *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MessagePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    Message *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
MessagePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Message **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool MessagePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
MessagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int 
MessagePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size);

NDDSUSERDllExport extern unsigned int MessagePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int size,
    const Message * sample);

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
MessagePlugin_get_key_kind();

NDDSUSERDllExport extern unsigned int 
MessagePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
MessagePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const Message *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
MessagePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    Message * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
MessagePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Message ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
MessagePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    Message *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
MessagePlugin_new();

NDDSUSERDllExport extern void
MessagePlugin_delete(struct PRESTypePlugin *);


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif



#endif /* MessagePlugin_793628338_h */
