/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_test.h    generated by: makeheader    Thu Jun 22 14:17:17 2017
 *
 *		built from:	test.ifc
 */

#ifndef netio_test_h
#define netio_test_h


  #ifndef test_setting_h
    #include "test/test_setting.h"
  #endif
  #ifndef clock_interface_h
    #include "clock/clock_interface.h"
  #endif
  #ifndef netio_common_h
    #include "netio/netio_common.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTINetioTestSetting {
    struct RTITestSetting parent;
    int nicCount;
};

extern RTIBool RTINetioTester_start(
    int beginSubmoduleTestIndex, int beginUnitTestIndex, 
    int endSubmoduleTestIndex, int endUnitTestIndex,
    RTILogBitmap instrumentationMask, RTIBool ignoreFailure, RTIBool rtnet,
    int nicCount);

extern RTIBool RTINetioTester_calculateClockOverhead(struct RTIClock *clock,
						     double *overhead);

extern void RTINetioTester_printLatency(
    int configuration,
    double sigma_sendTraversalTime,
    double sigma_sendTraversalTimeCompensated,
    double sigma_sendTraversalTimeSquared,
    double sigma_receiveTraversalTime,
    double sigma_receiveTraversalTimeCompensated,
    double sigma_receiveTraversalTimeSquared,
    double sigma_latency, double sigma_latencyCompensated,
    double sigma_latencySquared, int sampleCount);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "netio/netio_test_impl.h"

#endif /* netio_test_h */
