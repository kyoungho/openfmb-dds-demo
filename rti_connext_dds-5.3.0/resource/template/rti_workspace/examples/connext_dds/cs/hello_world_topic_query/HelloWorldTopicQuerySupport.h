/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

#include "HelloWorldTopicQuery.h"

class DDSDataWriter;
class DDSDataReader;

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryTypeSupport
// ---------------------------------------------------------------------------

ref class HelloWorldTopicQueryPlugin;

/* A collection of useful methods for dealing with objects of type
* HelloWorldTopicQuery.
*/
public ref class HelloWorldTopicQueryTypeSupport
: public DDS::TypedTypeSupport<HelloWorldTopicQuery^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "HelloWorldTopicQuery";

    // --- Public Methods: ---------------------------------------------------
  public:
    /* Get the default name of this type.
    *
    * An application can choose to register a type under any name, so
    * calling this method is strictly optional.
    */
    static System::String^ get_type_name();

    /* Register this type with the given participant under the given logical
    * name. This type must be registered before a Topic can be created that
    * uses it.
    */
    static void register_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Unregister this type from the given participant, where it was
    * previously registered under the given name. No further Topic creation
    * using this type will be possible.
    *
    * Unregistration allows some middleware resources to be reclaimed.
    */
    static void unregister_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Create an instance of the HelloWorldTopicQuery type.
    */
    static HelloWorldTopicQuery^ create_data();

    /* If instances of the HelloWorldTopicQuery type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(HelloWorldTopicQuery^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(HelloWorldTopicQuery^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        HelloWorldTopicQuery^ dst_data,
        HelloWorldTopicQuery^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        HelloWorldTopicQuery^ a_data);

    static void deserialize_data_from_cdr_buffer(
        HelloWorldTopicQuery^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    static System::String^ data_to_string(
        HelloWorldTopicQuery ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        HelloWorldTopicQuery ^sample);

    static DDS::TypeCode^ get_typecode();

    // --- Implementation: ---------------------------------------------------
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
  public:
    virtual System::String^ get_type_name_untyped() override;
    virtual DDS::DataReader^ create_datareaderI(
        System::IntPtr impl) override;
    virtual DDS::DataWriter^ create_datawriterI(
        System::IntPtr impl) override;

    virtual HelloWorldTopicQuery^ create_data_untyped() override;

  public:
    static HelloWorldTopicQueryTypeSupport^ get_instance();

    HelloWorldTopicQueryTypeSupport();

  private:
    static HelloWorldTopicQueryTypeSupport^ _singleton;
    HelloWorldTopicQueryPlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the HelloWorldTopicQuery type.
*/
public ref class HelloWorldTopicQueryDataReader :
public DDS::TypedDataReader<HelloWorldTopicQuery^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    HelloWorldTopicQueryDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the HelloWorldTopicQuery user type.
*/
public ref class HelloWorldTopicQueryDataWriter :
public DDS::TypedDataWriter<HelloWorldTopicQuery^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    HelloWorldTopicQueryDataWriter(System::IntPtr impl);
};
