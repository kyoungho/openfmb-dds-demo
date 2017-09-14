
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

struct DDS_TypeCode;

using namespace System;
using namespace DDS;

public ref struct HelloWorldTopicQuery
:  public DDS::ICopyable<HelloWorldTopicQuery^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::Int32 id;
    System::String^ message;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    HelloWorldTopicQuery();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(HelloWorldTopicQuery^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;

}; // class HelloWorldTopicQuery

public ref class HelloWorldTopicQuerySeq sealed
: public DDS::UserRefSequence<HelloWorldTopicQuery^> {
  public:
    HelloWorldTopicQuerySeq() :
        DDS::UserRefSequence<HelloWorldTopicQuery^>() {
            // empty
    }
    HelloWorldTopicQuerySeq(System::Int32 max) :
        DDS::UserRefSequence<HelloWorldTopicQuery^>(max) {
            // empty
    }
    HelloWorldTopicQuerySeq(HelloWorldTopicQuerySeq^ src) :
        DDS::UserRefSequence<HelloWorldTopicQuery^>(src) {
            // empty
    }
};

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* HelloWorldTopicQuery_get_typecode();

