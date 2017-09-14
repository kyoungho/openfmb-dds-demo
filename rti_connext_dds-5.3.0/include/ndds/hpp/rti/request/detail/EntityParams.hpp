/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_DETAIL_ENTITYPARAMS_HPP_
#define RTI_REQUEST_DETAIL_ENTITYPARAMS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>
#include <dds/core/Optional.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/sub/Subscriber.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/pub/Publisher.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>

namespace rti { namespace request { namespace detail {

class EntityParams {
public:
    explicit EntityParams(dds::domain::DomainParticipant participant)
        : participant_(participant),
          publisher_(dds::core::null),
          subscriber_(dds::core::null)
    {
    }

    virtual ~EntityParams()
    {
    }

    // --- Getters: -----------------------------------------------------------

    dds::domain::DomainParticipant participant() const
    {
        return participant_;
    }

    const std::string& service_name() const
    {
        return service_name_;
    }

    const std::string& request_topic_name() const
    {
        return request_topic_name_;
    }

    const std::string& reply_topic_name() const
    {
        return reply_topic_name_;
    }

    const dds::core::optional<dds::pub::qos::DataWriterQos>& datawriter_qos() const
    {
        return datawriter_qos_;
    }

    const dds::core::optional<dds::sub::qos::DataReaderQos>& datareader_qos() const
    {
        return datareader_qos_;
    }

    dds::pub::Publisher publisher() const
    {
        return publisher_;
    }

    dds::sub::Subscriber subscriber() const
    {
        return subscriber_;
    }
    
    virtual void validate() const 
    {
        if (subscriber_ != dds::core::null) {
            if (subscriber_.participant() != participant_) {
                throw dds::core::InvalidArgumentError(
                        "The subscriber belongs to a different participant");
            }
        }
        if (publisher_ != dds::core::null) {
            if (publisher_.participant() != participant_) {
                throw dds::core::InvalidArgumentError(
                        "The publisher belongs to a different participant");
            }
        }
        
        if (request_topic_name_.empty()) {
            throw dds::core::InvalidArgumentError("request topic name is required");
        }
    }

protected:
    dds::domain::DomainParticipant participant_;

    std::string service_name_;
    std::string request_topic_name_;
    std::string reply_topic_name_;

    dds::core::optional<dds::pub::qos::DataWriterQos> datawriter_qos_;
    dds::core::optional<dds::sub::qos::DataReaderQos> datareader_qos_;
    
    dds::pub::Publisher publisher_;
    dds::sub::Subscriber subscriber_;
};

// Adds getters returning *this (cast to ActualEntity, the class that will
// inherit from this one).
template <typename ActualEntity>
class EntityParamsWithSetters : public EntityParams {
public:

    explicit EntityParamsWithSetters(dds::domain::DomainParticipant participant)
        : EntityParams(participant)
    {
    }

    using EntityParams::validate;

    // --- Getters: -----------------------------------------------------------

    using EntityParams::participant;
    using EntityParams::service_name;
    using EntityParams::request_topic_name;
    using EntityParams::reply_topic_name;
    using EntityParams::datawriter_qos;
    using EntityParams::datareader_qos;
    using EntityParams::publisher;
    using EntityParams::subscriber;

    // --- Setters: -----------------------------------------------------------

    ActualEntity& participant(dds::domain::DomainParticipant participant)
    {
        participant_ = participant;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_service_name
     */
    ActualEntity& service_name(const std::string& name)
    {
        service_name_ = name;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_request_topic_name
     */
    ActualEntity& request_topic_name(const std::string& name)
    {
        request_topic_name_ = name;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_reply_topic_name
     */
    ActualEntity& reply_topic_name(const std::string& name)
    {
        reply_topic_name_ = name;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_datawriter_qos
     */
    ActualEntity& datawriter_qos(const dds::core::optional<dds::pub::qos::DataWriterQos>& qos)
    {
        datawriter_qos_ = qos;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_datareader_qos
     */
    ActualEntity& datareader_qos(const dds::core::optional<dds::sub::qos::DataReaderQos>& qos)
    {
        datareader_qos_ = qos;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_publisher
     */
    ActualEntity& publisher(dds::pub::Publisher publisher)
    {
        publisher_ = publisher;
        return static_cast<ActualEntity&>(*this);
    }

    /**
     * \dref_DerivedClass_subscriber
     */
    ActualEntity& subscriber(dds::sub::Subscriber subscriber)
    {
        subscriber_ = subscriber;
        return static_cast<ActualEntity&>(*this);
    }
};

} } } // namespace rti::request::detail

#endif // RTI_REQUEST_DETAIL_ENTITYPARAMS_HPP_
