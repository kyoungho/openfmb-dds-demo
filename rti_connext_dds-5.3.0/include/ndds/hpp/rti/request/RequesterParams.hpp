/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_REQUEST_REQUESTERPARAMS_HPP_
#define RTI_REQUEST_REQUESTERPARAMS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <rti/request/detail/EntityParams.hpp>

namespace rti { namespace request {

class RequesterParams
    : public detail::EntityParamsWithSetters<RequesterParams> {
public:

    /**
     * \dref_RequesterParams_new
     */
    explicit RequesterParams(dds::domain::DomainParticipant participant)
        : detail::EntityParamsWithSetters<RequesterParams>(participant)
    {
    }

    ~RequesterParams()
    {
    }
};

} }

#endif // RTI_REQUEST_REQUESTERPARAMS_HPP_
