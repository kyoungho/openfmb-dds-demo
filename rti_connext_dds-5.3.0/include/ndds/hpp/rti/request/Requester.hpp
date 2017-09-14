/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_REQUESTER_HPP_
#define RTI_REQUEST_REQUESTER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <rti/request/detail/RequesterImpl.hpp>

namespace rti { namespace request {

/**
 * @ingroup RequesterModule
 * @headerfile rti/request/Requester.hpp
 * @brief Requester class
 */
template <typename RequestType, typename ReplyType>
class Requester
    : public dds::core::Reference< detail::RequesterImpl<RequestType, ReplyType> > {
public:

    typedef detail::RequesterImpl<RequestType, ReplyType> Delegate;
    typedef dds::core::Reference<Delegate> Base;


    OMG_DDS_REF_TYPE(Requester, dds::core::Reference, Delegate);

    /**
     * -
     */
    explicit Requester(const RequesterParams& params)
        : Base(new Delegate(params))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * -
     */
    Requester(
        dds::domain::DomainParticipant participant,
        const std::string& service_name)
        : Base(new Delegate(
            RequesterParams(participant).service_name(service_name)))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * -
     */
    rti::core::SampleIdentity send_request(const RequestType& data)
    {
        return this->delegate()->send_request(data);
    }

    /**
     * -
     */
    dds::sub::LoanedSamples<ReplyType> take_replies(
            const rti::core::SampleIdentity& related_request_id)
    {
        return this->delegate()->take_replies(related_request_id);
    }

    /**
     * -
     */
    dds::sub::LoanedSamples<ReplyType> receive_replies(
        const dds::core::Duration& max_wait)
    {
        return this->delegate()->receive_replies(max_wait);
    }

    /**
     * -
     */
    bool wait_for_replies(const dds::core::Duration& max_wait)
    {
        return this->delegate()->wait_for_replies(1, max_wait);
    }

    /**
     * -
     */
    bool wait_for_replies(int min_count, const dds::core::Duration& max_wait)
    {
        return this->delegate()->wait_for_replies(min_count, max_wait);
    }

    /**
     * -
     */
    bool wait_for_replies(
        int min_count,
        const dds::core::Duration& max_wait,
        const rti::core::SampleIdentity& related_request_id)
    {
        return this->delegate()->wait_for_replies(
            min_count,
            max_wait,
            related_request_id);
    }

    /**
     * -
     */
    dds::pub::DataWriter<RequestType> request_datawriter() const
    {
        return this->delegate()->request_datawriter();
    }

    /**
     * -
     */
    dds::sub::DataReader<ReplyType> reply_datareader() const
    {
        return this->delegate()->reply_datareader();
    }
};

} } // namespace rti::request

#endif // RTI_REQUEST_REQUESTER_HPP_
