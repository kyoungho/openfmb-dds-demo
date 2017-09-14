/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "PrimesSupport.h"
#include "PrimesPlugin.h"

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#pragma managed

using namespace System;
using namespace DDS;

/* ========================================================================= */

// ---------------------------------------------------------------------------
// FooDataWriter
// ---------------------------------------------------------------------------

FooDataWriter::FooDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<Foo^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// FooDataReader
// ---------------------------------------------------------------------------

FooDataReader::FooDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<Foo^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// FooTypeSupport
// ---------------------------------------------------------------------------

FooTypeSupport::FooTypeSupport()
: DDS::TypedTypeSupport<Foo^>(
    FooPlugin::get_instance()) {

    _type_plugin = FooPlugin::get_instance();
}

void FooTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void FooTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

Foo^ FooTypeSupport::create_data() {
    return gcnew Foo();
}

Foo^ FooTypeSupport::create_data_untyped() {
    return create_data();
}

void FooTypeSupport::delete_data(
    Foo^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void FooTypeSupport::print_data(Foo^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void FooTypeSupport::copy_data(
    Foo^ dst, Foo^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void FooTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Foo^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void FooTypeSupport::deserialize_data_from_cdr_buffer(
    Foo^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

System::String^ FooTypeSupport::data_to_string(
    Foo ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ FooTypeSupport::data_to_string(
    Foo ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

DDS::TypeCode^ FooTypeSupport::get_typecode() {
    return  Foo::get_typecode();
}

System::String^ FooTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ FooTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ FooTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew FooDataReader(impl);
}

DDS::DataWriter^ FooTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew FooDataWriter(impl);
}

FooTypeSupport^
FooTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew FooTypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// BarDataWriter
// ---------------------------------------------------------------------------

BarDataWriter::BarDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<Bar^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BarDataReader
// ---------------------------------------------------------------------------

BarDataReader::BarDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<Bar^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BarTypeSupport
// ---------------------------------------------------------------------------

BarTypeSupport::BarTypeSupport()
: DDS::TypedTypeSupport<Bar^>(
    BarPlugin::get_instance()) {

    _type_plugin = BarPlugin::get_instance();
}

void BarTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void BarTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

Bar^ BarTypeSupport::create_data() {
    return gcnew Bar();
}

Bar^ BarTypeSupport::create_data_untyped() {
    return create_data();
}

void BarTypeSupport::delete_data(
    Bar^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void BarTypeSupport::print_data(Bar^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void BarTypeSupport::copy_data(
    Bar^ dst, Bar^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void BarTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Bar^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void BarTypeSupport::deserialize_data_from_cdr_buffer(
    Bar^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

System::String^ BarTypeSupport::data_to_string(
    Bar ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ BarTypeSupport::data_to_string(
    Bar ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

DDS::TypeCode^ BarTypeSupport::get_typecode() {
    return  Bar::get_typecode();
}

System::String^ BarTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ BarTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ BarTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew BarDataReader(impl);
}

DDS::DataWriter^ BarTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew BarDataWriter(impl);
}

BarTypeSupport^
BarTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew BarTypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// PrimeNumberRequestDataWriter
// ---------------------------------------------------------------------------

PrimeNumberRequestDataWriter::PrimeNumberRequestDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<PrimeNumberRequest^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// PrimeNumberRequestDataReader
// ---------------------------------------------------------------------------

PrimeNumberRequestDataReader::PrimeNumberRequestDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<PrimeNumberRequest^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// PrimeNumberRequestTypeSupport
// ---------------------------------------------------------------------------

PrimeNumberRequestTypeSupport::PrimeNumberRequestTypeSupport()
: DDS::TypedTypeSupport<PrimeNumberRequest^>(
    PrimeNumberRequestPlugin::get_instance()) {

    _type_plugin = PrimeNumberRequestPlugin::get_instance();
}

void PrimeNumberRequestTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void PrimeNumberRequestTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

PrimeNumberRequest^ PrimeNumberRequestTypeSupport::create_data() {
    return gcnew PrimeNumberRequest();
}

PrimeNumberRequest^ PrimeNumberRequestTypeSupport::create_data_untyped() {
    return create_data();
}

void PrimeNumberRequestTypeSupport::delete_data(
    PrimeNumberRequest^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void PrimeNumberRequestTypeSupport::print_data(PrimeNumberRequest^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void PrimeNumberRequestTypeSupport::copy_data(
    PrimeNumberRequest^ dst, PrimeNumberRequest^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void PrimeNumberRequestTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    PrimeNumberRequest^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void PrimeNumberRequestTypeSupport::deserialize_data_from_cdr_buffer(
    PrimeNumberRequest^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

System::String^ PrimeNumberRequestTypeSupport::data_to_string(
    PrimeNumberRequest ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ PrimeNumberRequestTypeSupport::data_to_string(
    PrimeNumberRequest ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

DDS::TypeCode^ PrimeNumberRequestTypeSupport::get_typecode() {
    return  PrimeNumberRequest::get_typecode();
}

System::String^ PrimeNumberRequestTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ PrimeNumberRequestTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ PrimeNumberRequestTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew PrimeNumberRequestDataReader(impl);
}

DDS::DataWriter^ PrimeNumberRequestTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew PrimeNumberRequestDataWriter(impl);
}

PrimeNumberRequestTypeSupport^
PrimeNumberRequestTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew PrimeNumberRequestTypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// PrimeNumberReplyDataWriter
// ---------------------------------------------------------------------------

PrimeNumberReplyDataWriter::PrimeNumberReplyDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<PrimeNumberReply^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// PrimeNumberReplyDataReader
// ---------------------------------------------------------------------------

PrimeNumberReplyDataReader::PrimeNumberReplyDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<PrimeNumberReply^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// PrimeNumberReplyTypeSupport
// ---------------------------------------------------------------------------

PrimeNumberReplyTypeSupport::PrimeNumberReplyTypeSupport()
: DDS::TypedTypeSupport<PrimeNumberReply^>(
    PrimeNumberReplyPlugin::get_instance()) {

    _type_plugin = PrimeNumberReplyPlugin::get_instance();
}

void PrimeNumberReplyTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void PrimeNumberReplyTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

PrimeNumberReply^ PrimeNumberReplyTypeSupport::create_data() {
    return gcnew PrimeNumberReply();
}

PrimeNumberReply^ PrimeNumberReplyTypeSupport::create_data_untyped() {
    return create_data();
}

void PrimeNumberReplyTypeSupport::delete_data(
    PrimeNumberReply^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void PrimeNumberReplyTypeSupport::print_data(PrimeNumberReply^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void PrimeNumberReplyTypeSupport::copy_data(
    PrimeNumberReply^ dst, PrimeNumberReply^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void PrimeNumberReplyTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    PrimeNumberReply^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void PrimeNumberReplyTypeSupport::deserialize_data_from_cdr_buffer(
    PrimeNumberReply^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

System::String^ PrimeNumberReplyTypeSupport::data_to_string(
    PrimeNumberReply ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ PrimeNumberReplyTypeSupport::data_to_string(
    PrimeNumberReply ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

DDS::TypeCode^ PrimeNumberReplyTypeSupport::get_typecode() {
    return  PrimeNumberReply::get_typecode();
}

System::String^ PrimeNumberReplyTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ PrimeNumberReplyTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ PrimeNumberReplyTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew PrimeNumberReplyDataReader(impl);
}

DDS::DataWriter^ PrimeNumberReplyTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew PrimeNumberReplyDataWriter(impl);
}

PrimeNumberReplyTypeSupport^
PrimeNumberReplyTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew PrimeNumberReplyTypeSupport();
    }
    return _singleton;
}
