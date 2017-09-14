/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_interfaceTracker.h    generated by: makeheader    Thu Jun 22 14:16:50 2017
 *
 *		built from:	interfaceTracker.ifc
 */

#ifndef osapi_interfaceTracker_h
#define osapi_interfaceTracker_h


    #ifndef osapi_dll_h
        #include "osapi/osapi_dll.h"
    #endif

    #ifndef osapi_interfaces_h
        #include "osapi/osapi_interfaces.h"
    #endif

    #ifdef __cplusplus
        extern "C" {
    #endif

typedef enum  {
        RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_DELETED,
        RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_NEW,
        RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_CHANGED
} RTIOsapiInterfaceTrackerEventKind;


#define RTIOsapiInterfaceTrackerEventKind_toString(ek)  \
    (ek==RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_DELETED ? "DELETED" : \
     (ek==RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_NEW ? "NEW" :   \
      (ek==RTI_OSAPI_INTERFACE_TRACKER_EVENT_KIND_INTERFACE_CHANGED ? "CHANGED" \
              : "<UNKNOWN>")))


struct RTIOsapiInterfaceTrackerEvent {
    RTIOsapiInterfaceTrackerEventKind kind;
    RTIOsapiSocket_InterfaceDescription * sourceInterface;
};

typedef enum {
    RTI_OSAPI_INTERFACE_TRACKER_DETECTION_KIND_AUTO,
    RTI_OSAPI_INTERFACE_TRACKER_DETECTION_KIND_POLLING,
    RTI_OSAPI_INTERFACE_TRACKER_DETECTION_KIND_OS_NOTIFICATION
} RTIOsapiInterfaceTrackerDetectionKind;


struct RTIOsapiInterfaceTrackerProperty {
    RTIOsapiSocketAFKind addressFamilyKind;
    RTIOsapiInterfaceTrackerDetectionKind detectionKind;
    unsigned int interfaceMask;
    /* milliseconds */
    unsigned int interfacePollPeriod;
};


struct RTIOsapiInterfaceTrackerListener;

 
struct RTIOsapiInterfaceTracker;


typedef void (*RTIOsapiInterfaceTracker_OnInterfaceChangeCallback)(
                void * listenerData,
                struct RTIOsapiInterfaceTracker * interfaceTracker,
                const struct RTIOsapiInterfaceTrackerEvent * trackerEvent);


#define RTI_OSAPI_INTERFACE_TRACKER_EVENT_INITIALIZER { 0, NULL }
#define RTI_OSAPI_INTERFACE_TRACKER_PROPERTY_DEFAULT { RTI_OSAPI_SOCKET_AF_INET, RTI_OSAPI_INTERFACE_TRACKER_DETECTION_KIND_AUTO, 0, 1000 }
#define RTI_OSAPI_INTERFACE_TRACKER_LISTENER_INITIALIZER { NULL, NULL }


struct RTIOsapiInterfaceTrackerListener {
    void * listenerData;
    RTIOsapiInterfaceTracker_OnInterfaceChangeCallback  onInterfaceChange;
};

extern RTIOsapiDllExport 
struct RTIOsapiInterfaceTracker * RTIOsapiInterfaceTracker_new(
            const struct RTIOsapiInterfaceTrackerListener * listener, 
            const struct RTIOsapiInterfaceTrackerProperty * property);

extern RTIOsapiDllExport
void RTIOsapiInterfaceTracker_delete(struct RTIOsapiInterfaceTracker * self);

extern RTIOsapiDllExport
RTIBool RTIOsapiInterfaceTracker_loanInterfaceArray(
            struct RTIOsapiInterfaceTracker * self, 
            struct RTIOsapiSocket_InterfaceDescription ** interfaceArray,
            int * interfaceCount);

extern RTIOsapiDllExport
void RTIOsapiInterfaceTracker_returnInterfaceArrayLoan(
            struct RTIOsapiInterfaceTracker * self);


    #ifdef __cplusplus
	}	/* extern "C" */
    #endif

#endif /* osapi_interfaceTracker_h */
