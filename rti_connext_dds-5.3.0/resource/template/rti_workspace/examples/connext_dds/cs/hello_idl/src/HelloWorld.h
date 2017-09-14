
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

struct DDS_TypeCode;

using namespace System;
using namespace DDS;

public ref class HELLODDS_MAX_PAYLOAD_SIZE sealed {
  public:
    static const System::Int32 VALUE =
    8192;

  private:
    HELLODDS_MAX_PAYLOAD_SIZE() {}
};

public ref class HELLODDS_MAX_STRING_SIZE sealed {
  public:
    static const System::Int32 VALUE =
    64;

  private:
    HELLODDS_MAX_STRING_SIZE() {}
};

public ref struct HelloWorld
:  public DDS::ICopyable<HelloWorld^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ prefix;
    System::Int32 sampleId;
    DDS::ByteSeq^ payload; 

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    HelloWorld();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(HelloWorld^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;

}; // class HelloWorld

public ref class HelloWorldSeq sealed
: public DDS::UserRefSequence<HelloWorld^> {
  public:
    HelloWorldSeq() :
        DDS::UserRefSequence<HelloWorld^>() {
            // empty
    }
    HelloWorldSeq(System::Int32 max) :
        DDS::UserRefSequence<HelloWorld^>(max) {
            // empty
    }
    HelloWorldSeq(HelloWorldSeq^ src) :
        DDS::UserRefSequence<HelloWorld^>(src) {
            // empty
    }
};

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* HelloWorld_get_typecode();

