//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// The aim of this header is just to include <complex> but to do
// so in a way that does not result in recursive inclusion of
// the Boost TR1 components if boost/tr1/tr1/complex is in the
// include search path.  We have to do this to avoid circular
// dependencies:
//

#ifndef RTIBOOST_CONFIG_COMPLEX
#  define RTIBOOST_CONFIG_COMPLEX

#  ifndef RTIBOOST_TR1_NO_RECURSION
#     define RTIBOOST_TR1_NO_RECURSION
#     define RTIBOOST_CONFIG_NO_COMPLEX_RECURSION
#  endif

#  include <complex>

#  ifdef RTIBOOST_CONFIG_NO_COMPLEX_RECURSION
#     undef RTIBOOST_TR1_NO_RECURSION
#     undef RTIBOOST_CONFIG_NO_COMPLEX_RECURSION
#  endif

#endif