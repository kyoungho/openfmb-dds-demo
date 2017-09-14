/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)clock_interface.h    generated by: makeheader    Thu Jun 22 14:16:54 2017
 *
 *		built from:	interface.ifc
 */

#ifndef clock_interface_h
#define clock_interface_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTINtpTime; /* forward declare to appease the compiler */

struct RTIClock; /* forward declare to appease the compiler */

typedef RTIBool (*RTIClockTimeGetFunction)(struct RTIClock *me,
						  struct RTINtpTime *now);

typedef RTIBool (*RTIClockResolutionGetFunction)(
    const struct RTIClock *me, struct RTINtpTime *resolution);

typedef RTIBool (*RTIClockRequiredCallPeriodGetFunction)(
    const struct RTIClock *me, struct RTINtpTime *period);

typedef RTIBool (*RTIClockResetFunction)(struct RTIClock *me);

struct RTIClock {
    /*e Function pointer to get time*/
    RTIClockTimeGetFunction getTime;
    /*e Function pointer to get clock resolution */
    RTIClockResolutionGetFunction getResolution;
    /*e Function pointer to get required call period */
    RTIClockRequiredCallPeriodGetFunction getRequiredCallPeriod;
    /*e Function pointer to reset clock */
    RTIClockResetFunction reset;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* clock_interface_h */
