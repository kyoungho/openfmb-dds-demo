/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_REPLIERPARAMS_HPP_
#define RTI_REQUEST_REPLIERPARAMS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <rti/request/detail/EntityParams.hpp>

namespace rti { namespace request {

class ReplierParams
    : public detail::EntityParamsWithSetters<ReplierParams> {
public:

    /**
     * \dref_RequesterParams_new
     */
    explicit ReplierParams(dds::domain::DomainParticipant participant)
        : detail::EntityParamsWithSetters<ReplierParams>(participant)
    {
    }

    ~ReplierParams()
    {
    }
};

} }

#endif // RTI_REQUEST_REPLIERPARAMS_HPP_
