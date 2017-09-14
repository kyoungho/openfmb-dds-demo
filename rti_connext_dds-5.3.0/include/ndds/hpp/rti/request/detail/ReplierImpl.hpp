/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_DETAIL_REPLIERIMPL_HPP_
#define RTI_REQUEST_DETAIL_REPLIERIMPL_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <rti/core/detail/SelfReference.hpp>
#include <rti/request/detail/GenericSender.hpp>
#include <rti/request/detail/GenericReceiver.hpp>
#include <rti/request/ReplierParams.hpp>

namespace rti { namespace request { namespace detail {

template <typename T>
dds::topic::TopicDescription<T> get_replier_request_topic(
    const rti::request::ReplierParams& params);

template <typename T>
dds::topic::Topic<T> get_replier_reply_topic(
    const rti::request::ReplierParams& params);

OMG_DDS_API
rti::pub::WriteParams get_write_params_for_related_request(
    const rti::core::SampleIdentity& related_request_id);

/**
 */
template <typename RequestType, typename ReplyType>
class ReplierImpl
    : public rti::core::detail::RetainableType<ReplierImpl<RequestType, ReplyType> > {
public:

    explicit ReplierImpl(const rti::request::ReplierParams& params)
        : sender_(params, get_replier_reply_topic<ReplyType>(params)),
          receiver_(params, get_replier_request_topic<RequestType>(params))
    {
    }

    void send_reply(
        const ReplyType& data,
        const rti::core::SampleIdentity& related_request_id)
    {
        rti::pub::WriteParams write_params =
            get_write_params_for_related_request(related_request_id);
        sender_.write(data, write_params);
    }

    dds::sub::LoanedSamples<RequestType> receive_requests(
        int min_count, const dds::core::Duration& max_wait)
    {
        return receiver_.receive_samples(min_count, max_wait);
    }

    dds::pub::DataWriter<ReplyType> reply_datawriter() const
    {
        return sender_.writer();
    }

    dds::sub::DataReader<RequestType> request_datareader() const
    {
        return receiver_.reader();
    }

private:
    detail::GenericSender<ReplyType> sender_;
    detail::GenericReceiver<RequestType> receiver_;
};


template <typename T>
dds::topic::TopicDescription<T> get_replier_request_topic(
    const rti::request::ReplierParams& params)
{
    return get_or_create_topic<T>(
        params.participant(),
        get_request_topic_name(params),
        true);
}

template <typename T>
dds::topic::Topic<T> get_replier_reply_topic(
    const rti::request::ReplierParams& params)
{
    dds::topic::TopicDescription<T> topic_desc = get_or_create_topic<T>(
        params.participant(),
        get_reply_topic_name(params),
        false);

    return dds::core::polymorphic_cast<dds::topic::Topic<T> >(topic_desc);
}

} } } // namespace rti::request::detail

#endif // RTI_REQUEST_DETAIL_REPLIERIMPL_HPP_
