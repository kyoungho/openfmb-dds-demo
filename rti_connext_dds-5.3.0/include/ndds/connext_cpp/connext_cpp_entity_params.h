/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)connext_cpp_entity_params.h    generated by: makeheader    Thu Jun 22 14:18:46 2017
 *
 *		built from:	entity_params.ifcxx
 */

#ifndef connext_cpp_entity_params_h
#define connext_cpp_entity_params_h



#include <string>

#include "connext_cpp/connext_cpp_dll.h"

#ifndef ndds_namespace_cpp_h
  #include "ndds/ndds_namespace_cpp.h"
#endif

namespace connext {
namespace details {

using namespace DDS;

// ===========================================================================
// class EntityParams:
// entity_params.ifcxx declares EntityParams, which , which is
// a common base of RequesterParams and ReplierParams.

class XMQCPPDllExport EntityParams {
public:

    explicit EntityParams(DDSDomainParticipant * participant);

    /************* Getters *************/
    /* 
       This class has getters only because the setters are in the
       derived classes. Derived class setter return a reference
       to the derived type so those setters can't be moved here.
    */

    DomainParticipant * participant() const;

    const std::string & service_name() const;
    const std::string & request_topic_name() const;
    const std::string & reply_topic_name() const;
    const std::string & qos_library_name() const;
    const std::string & qos_profile_name() const;

    const DDS_DataWriterQos * datawriter_qos() const;
    const DDS_DataReaderQos * datareader_qos() const;

    Publisher * publisher() const;
    Subscriber * subscriber() const;

    TypeSupport * datawriter_type_support() const;
    TypeSupport * datareader_type_support() const;

    virtual void validate() const;

    virtual ~EntityParams();

protected:
    DomainParticipant * _participant;

    std::string _service_name;
    std::string _request_topic_name;
    std::string _reply_topic_name;
    std::string _qos_library_name;
    std::string _qos_profile_name;

    const DDS_DataWriterQos * _datawriter_qos;
    const DDS_DataReaderQos * _datareader_qos;

    Publisher * _publisher;
    Subscriber * _subscriber;

    TypeSupport * _datawriter_type_support;
    TypeSupport * _datareader_type_support;
};

} // namespace details
} // namespace connext


#endif /* connext_cpp_entity_params_h */
