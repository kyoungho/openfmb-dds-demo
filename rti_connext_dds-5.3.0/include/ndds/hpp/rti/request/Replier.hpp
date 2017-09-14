/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_REPLIER_HPP_
#define RTI_REQUEST_REPLIER_HPP_

#include <rti/request/detail/ReplierImpl.hpp>

namespace rti { namespace request {

/**
 * @ingroup ReplierModule
 * @headerfile rti/request/Replier.hpp
 * -
 */
template <typename RequestType, typename ReplyType>
class Replier
    : public dds::core::Reference< detail::ReplierImpl<RequestType, ReplyType> > {
public:

    typedef detail::ReplierImpl<RequestType, ReplyType> Delegate;
    typedef dds::core::Reference<Delegate> Base;


    OMG_DDS_REF_TYPE(Replier, dds::core::Reference, Delegate);

    /**
     * -
     */
    explicit Replier(const ReplierParams& params)
        : Base(new Delegate(params))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * -
     */
    Replier(
        dds::domain::DomainParticipant participant,
        const std::string& service_name)
        : Base(new Delegate(
            ReplierParams(participant).service_name(service_name)))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * -
     */
    void send_reply(
        const ReplyType& data,
        const rti::core::SampleIdentity& related_request_id)
    {
        this->delegate()->send_reply(data, related_request_id);
    }

    /**
     * -
     */
    dds::sub::LoanedSamples<RequestType> receive_requests(
        const dds::core::Duration& max_wait)
    {
        return this->delegate()->receive_requests(1, max_wait);
    }


    /**
     * -
     */
    dds::sub::LoanedSamples<RequestType> receive_requests(
        int min_count,
        const dds::core::Duration& max_wait)
    {
        return this->delegate()->receive_requests(min_count, max_wait);
    }

    /**
     * -
     */
    dds::sub::DataReader<RequestType> request_datareader() const
    {
        return this->delegate()->request_datareader();
    }

    /**
     * -
     */
    dds::pub::DataWriter<ReplyType> reply_datawriter() const
    {
        return this->delegate()->reply_datawriter();
    }
};

} } // namespace rti::request

#endif // RTI_REQUEST_REPLIER_HPP_
