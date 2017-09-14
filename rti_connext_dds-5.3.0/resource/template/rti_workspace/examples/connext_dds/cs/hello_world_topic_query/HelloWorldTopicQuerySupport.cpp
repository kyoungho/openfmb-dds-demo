/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "HelloWorldTopicQuerySupport.h"
#include "HelloWorldTopicQueryPlugin.h"

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#pragma managed

using namespace System;
using namespace DDS;

/* ========================================================================= */

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryDataWriter
// ---------------------------------------------------------------------------

HelloWorldTopicQueryDataWriter::HelloWorldTopicQueryDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<HelloWorldTopicQuery^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryDataReader
// ---------------------------------------------------------------------------

HelloWorldTopicQueryDataReader::HelloWorldTopicQueryDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<HelloWorldTopicQuery^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// HelloWorldTopicQueryTypeSupport
// ---------------------------------------------------------------------------

HelloWorldTopicQueryTypeSupport::HelloWorldTopicQueryTypeSupport()
: DDS::TypedTypeSupport<HelloWorldTopicQuery^>(
    HelloWorldTopicQueryPlugin::get_instance()) {

    _type_plugin = HelloWorldTopicQueryPlugin::get_instance();
}

void HelloWorldTopicQueryTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void HelloWorldTopicQueryTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

HelloWorldTopicQuery^ HelloWorldTopicQueryTypeSupport::create_data() {
    return gcnew HelloWorldTopicQuery();
}

HelloWorldTopicQuery^ HelloWorldTopicQueryTypeSupport::create_data_untyped() {
    return create_data();
}

void HelloWorldTopicQueryTypeSupport::delete_data(
    HelloWorldTopicQuery^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void HelloWorldTopicQueryTypeSupport::print_data(HelloWorldTopicQuery^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void HelloWorldTopicQueryTypeSupport::copy_data(
    HelloWorldTopicQuery^ dst, HelloWorldTopicQuery^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void HelloWorldTopicQueryTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    HelloWorldTopicQuery^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void HelloWorldTopicQueryTypeSupport::deserialize_data_from_cdr_buffer(
    HelloWorldTopicQuery^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

System::String^ HelloWorldTopicQueryTypeSupport::data_to_string(
    HelloWorldTopicQuery ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ HelloWorldTopicQueryTypeSupport::data_to_string(
    HelloWorldTopicQuery ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

DDS::TypeCode^ HelloWorldTopicQueryTypeSupport::get_typecode() {
    return  HelloWorldTopicQuery::get_typecode();
}

System::String^ HelloWorldTopicQueryTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ HelloWorldTopicQueryTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ HelloWorldTopicQueryTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew HelloWorldTopicQueryDataReader(impl);
}

DDS::DataWriter^ HelloWorldTopicQueryTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew HelloWorldTopicQueryDataWriter(impl);
}

HelloWorldTopicQueryTypeSupport^
HelloWorldTopicQueryTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew HelloWorldTopicQueryTypeSupport();
    }
    return _singleton;
}
