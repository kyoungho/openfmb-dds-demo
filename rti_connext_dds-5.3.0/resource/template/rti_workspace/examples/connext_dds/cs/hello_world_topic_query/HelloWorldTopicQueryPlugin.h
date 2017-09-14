/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

#include "HelloWorldTopicQuery.h"

/* ------------------------------------------------------------------------
* Type: HelloWorldTopicQuery
* ------------------------------------------------------------------------ */

public ref class HelloWorldTopicQueryPlugin :
DefaultTypePlugin<HelloWorldTopicQuery^> {
    // --- Support methods: ------------------------------------------------------
  public:
    void print_data(
        HelloWorldTopicQuery^ sample,
        System::String^ desc,
        System::UInt32 indent);

    // --- (De)Serialize methods: ------------------------------------------------
  public:
    virtual System::Boolean serialize(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ sample,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    virtual System::Boolean deserialize_sample(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ sample,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample, 
        System::Object^ endpoint_plugin_qos) override;

    System::Boolean skip(
        TypePluginDefaultEndpointData^ endpoint_data,
        CdrStream% stream,
        System::Boolean skip_encapsulation,  
        System::Boolean skip_sample, 
        System::Object^ endpoint_plugin_qos);

    virtual System::UInt32 get_serialized_sample_max_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size) override;

    virtual System::UInt32 get_serialized_sample_min_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size) override;

    virtual System::UInt32 get_serialized_sample_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        Boolean include_encapsulation,
        UInt16 encapsulation_id,
        UInt32 current_alignment,
        HelloWorldTopicQuery^ sample) override;

    // ---  Key Management functions: --------------------------------------------
  public:
    virtual System::UInt32 get_serialized_key_max_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 current_alignment) override;

    virtual System::Boolean serialize_key(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ key,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    virtual System::Boolean deserialize_key_sample(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ key,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    System::Boolean serialized_sample_to_key(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ sample,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_key,
        System::Object^ endpoint_plugin_qos);

    virtual System::Boolean instance_to_key(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ key,
        HelloWorldTopicQuery^ instance) override;

    virtual System::Boolean key_to_instance(
        TypePluginDefaultEndpointData^ endpoint_data,
        HelloWorldTopicQuery^ instance,
        HelloWorldTopicQuery^ key) override;

    virtual System::Boolean serialized_sample_to_key_hash(
        TypePluginDefaultEndpointData^ endpoint_data,
        CdrStream% stream,
        KeyHash_t% key_hash,
        System::Boolean deserialize_encapsulation,
        System::Object^ endpoint_plugin_qos) override;

    // ---  Plug-in lifecycle management methods: --------------------------------
  public:
    static HelloWorldTopicQueryPlugin^ get_instance();

    static void dispose();

  private:
    HelloWorldTopicQueryPlugin()
    : DefaultTypePlugin(
        "HelloWorldTopicQuery",

        true, //keyed     
        false, // use RTPS-compliant alignment
        HelloWorldTopicQuery::get_typecode() ) {
        // empty
    }

    static HelloWorldTopicQueryPlugin^ _singleton;
};

