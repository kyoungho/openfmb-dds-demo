/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef RTIBOOST_PREDEF_COMPILER_EDG_H
#define RTIBOOST_PREDEF_COMPILER_EDG_H

#include <rtiboost/predef/version_number.h>
#include <rtiboost/predef/make.h>

/*`
[heading `RTIBOOST_COMP_EDG`]

[@http://en.wikipedia.org/wiki/Edison_Design_Group EDG C++ Frontend] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__EDG__`] [__predef_detection__]]

    [[`__EDG_VERSION__`] [V.R.0]]
    ]
 */

#define RTIBOOST_COMP_EDG RTIBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__EDG__)
#   define RTIBOOST_COMP_EDG_DETECTION RTIBOOST_PREDEF_MAKE_10_VRR(__EDG_VERSION__)
#endif

#ifdef RTIBOOST_COMP_EDG_DETECTION
#   if defined(RTIBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define RTIBOOST_COMP_EDG_EMULATED RTIBOOST_COMP_EDG_DETECTION
#   else
#       undef RTIBOOST_COMP_EDG
#       define RTIBOOST_COMP_EDG RTIBOOST_COMP_EDG_DETECTION
#   endif
#   define RTIBOOST_COMP_EDG_AVAILABLE
#   include <rtiboost/predef/detail/comp_detected.h>
#endif

#define RTIBOOST_COMP_EDG_NAME "EDG C++ Frontend"

#endif

#include <rtiboost/predef/detail/test.h>
RTIBOOST_PREDEF_DECLARE_TEST(RTIBOOST_COMP_EDG,RTIBOOST_COMP_EDG_NAME)

#ifdef RTIBOOST_COMP_EDG_EMULATED
#include <rtiboost/predef/detail/test.h>
RTIBOOST_PREDEF_DECLARE_TEST(RTIBOOST_COMP_EDG_EMULATED,RTIBOOST_COMP_EDG_NAME)
#endif
