/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)event_jobDispatcher.h    generated by: makeheader    Thu Jun 22 14:17:09 2017
 *
 *		built from:	jobDispatcher.ifc
 */

#ifndef event_jobDispatcher_h
#define event_jobDispatcher_h


  #ifndef event_dll_h
    #include "event/event_dll.h"
  #endif
  #ifndef event_generator_h
    #include "event/event_generator.h"
  #endif
  #ifndef event_activeObject_h
    #include "event/event_activeObject.h"
  #endif
  #ifndef reda_worker_h
    #include "reda/reda_worker.h"
  #endif
  #ifndef osapi_threadFactory_h
    #include "osapi/osapi_threadFactory.h"
  #endif
  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef reda_orderedDataType_h
    #include "reda/reda_orderedDataType.h"
  #endif
  #ifndef clock_interface_h
    #include "clock/clock_interface.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDASkiplist;

struct REDAWorkerFactory;

struct RTIEventJobDispatcher;

struct RTIEventJobDispatcherThread;

struct RTIEventJobDispatcherTokenBucket;

struct RTIEventJobDispatcherAgent;

struct RTIEventJobDispatcherGroup;

struct RTIEventJobDispatcherDefinedJob;

typedef enum {
    /*e Job is successfully defined.
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_DEFINE_RESULT_SUCCESS,
    /*e Job could not be defined (possible that job queue limit is reached).
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_DEFINE_RESULT_FAILED,
    /*e Job is not re-defined because an identical job already exists.
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_DEFINE_RESULT_EXISTS
} RTIEventJobDispatcherJobDefineResult;

typedef enum {
    /*e Job is successfully scheduled.
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_SCHEDULE_RESULT_SUCCESS,
    /*e Job could not be scheduled (possible that job queue limit is reached).
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_SCHEDULE_RESULT_FAILED,
    /*e Job is not re-scheduled because an identical job already exists.
    */
     RTI_EVENT_JOB_DISPATCHER_JOB_SCHEDULE_RESULT_EXISTS
} RTIEventJobDispatcherJobScheduleResult;

typedef void (* RTIEventJobDispatcherListenerCallback)(
    struct RTIEventActiveObject *obj, void *param, struct REDAWorker *worker);

struct RTIEventJobDispatcherListener {
    /*e Called each time when a thread is started.
    */
    RTIEventJobDispatcherListenerCallback onStarted;
    /*e User-defined param for onStarted.
    */
    void *onStartedParam;
    /*e Called each time when a thread is stopped.
    */
    RTIEventJobDispatcherListenerCallback onStopped;
    /*e User-defined param for onStopped.
    */
    void *onStoppedParam;
};


#define RTI_EVENT_JOB_DISPATCHER_LISTENER_DEFAULT { \
    NULL, NULL, NULL, NULL \
}

struct RTIEventJobDispatcherProperty {
    /*e A passive job dispatcher can only create passive threads and buckets. */
    RTIBool isPassive;

    /*e Growth property of the number of jobs defined to the Dispatcher.
    */
    struct REDAFastBufferPoolGrowthProperty definedJobsGrowth;
    /*e Growth property of the number of jobs scheduled/dispatched to the Dispatcher.
    */
    struct REDAFastBufferPoolGrowthProperty scheduledJobsGrowth;
    /*e Growth property of different priority levels the job groups can belong to.
    */
    struct REDAFastBufferPoolGrowthProperty agentsGrowth;
    /*e Growth property of the number of agents user can create.
    */
    struct REDAFastBufferPoolGrowthProperty groupsGrowth;
    /*e Growth property of the number of of execution threads user can create.
    */
    struct REDAFastBufferPoolGrowthProperty threadsGrowth;
    /*e Growth property of the number of token buckets user can create.
    */
    struct REDAFastBufferPoolGrowthProperty bucketsGrowth;

    /*e domainId  Used to give a meaningful name to the thread */
    int domainId;
    /*e Either the App Id or the participant indexUsed to give a meaningful 
    name to the thread */
    RTI_UINT32 threadAppId;
    /*e Specifies if the previous field is the App Id or the participant index
    Used to give a meaningful name to the thread */
    RTIBool participantIndexSpecified;
};


#define RTI_EVENT_JOB_DISPATCHER_PROPERTY_DEFAULT { \
    RTI_FALSE, /* isPassive */ \
    {20, REDA_FAST_BUFFER_POOL_UNLIMITED, 20}, /* definedJobsGrowth */ \
    {50, REDA_FAST_BUFFER_POOL_UNLIMITED, 50}, /* scheduledJobsGrowth */ \
    {10, REDA_FAST_BUFFER_POOL_UNLIMITED, 10}, /* agentsGrowth */ \
    {10, REDA_FAST_BUFFER_POOL_UNLIMITED, 10}, /* groupsGrowth */ \
    {3, REDA_FAST_BUFFER_POOL_UNLIMITED, 3}, /* threadsGrowth */ \
    {3, REDA_FAST_BUFFER_POOL_UNLIMITED, 3}, /* bucketsGrowth */ \
    0, /* domainId */ \
    0, /* threadAppId */ \
    RTI_FALSE /* participantIndexSpecified */ \
}

struct RTIEventJobDispatcherThreadProperty {
    /*e A passive thread is not really a thread (ie, no thread is spawned). It is
        merely a collection of agents to be run. These agents are run on-demand
        when RTIEventJobDispatcher_executionThreadAgents() is called, and they
        run in the context of the caller. Passive threads also do not call
        the dispatcher listener callbacks. */
    RTIBool isPassive;

    /*e Dispatcher thread is an active object. */
    struct RTIEventActiveObjectProperty active;
};


#define RTI_EVENT_JOB_DISPATCHER_THREAD_PROPERTY_DEFAULT { \
    RTI_FALSE, /* isPassive */ \
    RTI_EVENT_ACTIVE_OBJECT_PROPERTY_DEFAULT /* active */ \
}


#define RTI_EVENT_JOB_DISPATCHER_UNBOUNDED_TOKENS (-1)

struct RTIEventJobDispatcherTokenBucketProperty {
    /*e A passive token bucket does not install an periodic event to add tokens.
        Instead, tokens are only added when user calls RTIEventJobDispatcher_addTokens(). 
        Passive token bucket honors all other properties, except the tokenPeriod is variable
        based on the user call-rate. */
    RTIBool isPassive;
    /*e Units can only be given in batches of tokens; this determines the size of that batch.
        Use RTI_EVENT_JOB_DISPATCHER_UNBOUNDED_TOKENS to allow a single token to serve any number
        of units.
    */
    int unitsPerToken;
    /*e Max tokens (units) the bucket can carry (save); use RTI_EVENT_JOB_DISPATCHER_UNBOUNDED_TOKENS for unlimited.
    */
    int maxTokens;
    /*e The number of tokens to add to the bucket per period. Use RTI_EVENT_JOB_DISPATCHER_UNBOUNDED_TOKENS to 
        always have maxTokens available.
    */
    int tokensAddedPerPeriod;
    /*e The number of tokens to leak (lose) from the bucket per period after each periodic token distribution.
        Use RTI_EVENT_JOB_DISPATCHER_UNBOUNDED_TOKENS to leak all tokens.
    */
    int tokensLeakedPerPeriod;
    /*e The period to add tokens.
    */
    struct RTINtpTime tokenPeriod;
};


#define RTI_EVENT_JOB_DISPATCHER_TOKEN_BUCKET_PROPERTY_DEFAULT { \
    RTI_FALSE, /* isPassive */ \
    2, /* unitsPerToken */ \
    REDA_FAST_BUFFER_POOL_UNLIMITED, /* maxTokens */ \
    5, /* tokensAddedPerPeriod */ \
    0, /* tokensLeakedPerPeriod */ \
    {1, 0} /* tokenPeriod */ \
}

struct RTIEventJobDispatcherAgentProperty {
    void *dummy;
};


#define RTI_EVENT_JOB_DISPATCHER_AGENT_PROPERTY_DEFAULT { \
   NULL \
}

typedef enum {
    /*e If job queue is full, replace the oldest but unstarted job from the same group.
    */
    RTI_EVENT_GROUP_PRUNING_SCHEME_OLDEST_UNSTARTED,
    /*e If job queue is full, wait for the specified timeout value for available job space.
    */
    RTI_EVENT_GROUP_PRUNING_SCHEME_WAIT_FOR_TIMEOUT
} RTIEventJobDispatcherGroupPruningScheme;

typedef enum {
    /*e Do not call the group callback. 
    RTI_EVENT_GROUP_CALLBACK_MASK_NONE = 0x0,
    */
    /*e Callback whenever a job from the group has completed. This is called
        only if every scheduled instance of this job is run to completion.
    */
    RTI_EVENT_GROUP_CALLBACK_MASK_JOB_COMPLETED = 0x1,
    /*e Callback whenever a job from the group has completed. This is called
        only after every scheduled instance of this job has terminated. However,
        at least one scheduled instance was interrupted - either because agent
        was removed before execution, job group removed in the middle of execution,
        etc.
    */
    RTI_EVENT_GROUP_CALLBACK_MASK_JOB_INTERRUPTED = 0x2,
    /*e Callback whenever a job from the group has been pruned.
    */
    RTI_EVENT_GROUP_CALLBACK_MASK_JOB_PRUNED = 0x4,
    /*e Callback when all jobs from the group has terminated (completed, interrupted, or pruned).
    */
    RTI_EVENT_GROUP_CALLBACK_MASK_ALL_JOBS_TERMINATED = 0x8,
    /*e Callback when all jobs from the group has terminated (completed, interrupted, or pruned) 
        but only if previous posting to the group has failed.
    */
    RTI_EVENT_GROUP_CALLBACK_MASK_ALL_JOBS_TERMINATED_AND_FAILED = 0x16
    /*e Callback when any of the conditions occur.
    RTI_EVENT_GROUP_CALLBACK_MASK_ALL = 0xffffffff
    */
} RTIEventJobDispatcherGroupCallbackMask;


#define RTI_EVENT_GROUP_CALLBACK_MASK_NONE   ((RTIEventJobDispatcherGroupCallbackMask) 0)


#define RTI_EVENT_GROUP_CALLBACK_MASK_ALL    (~RTI_EVENT_GROUP_CALLBACK_MASK_NONE)

struct RTIEventJobDispatcherGroupProperty {
    /*e Soft limit on the number of jobs that can be defined using this group. Actual
        resources are still drawn from buffer pool based on the definedJobsGrowth field
        in RTIEventJobDispatcherProperty. Use REDA_FAST_BUFFER_POOL_UNLIMITED for unlimited.
    */
    int maxJobs;
    /*e Determines the pruning scheme used when job queue is full. Job queue can
        be full when the Scheduker property values jobsGrowth or maxJobsPerGroup
        limits are reached.
    */
    RTIEventJobDispatcherGroupPruningScheme pruningScheme;    

    /*e Determines when the group callback is exercised.
    */
    RTIEventJobDispatcherGroupCallbackMask callbackMask;
};


#define RTI_EVENT_JOB_DISPATCHER_GROUP_PROPERTY_DEFAULT { \
    REDA_FAST_BUFFER_POOL_UNLIMITED, /* maxJobs */ \
    RTI_EVENT_GROUP_PRUNING_SCHEME_WAIT_FOR_TIMEOUT, /* pruningScheme */ \
    RTI_EVENT_GROUP_CALLBACK_MASK_NONE /* callbackMask */ \
}

extern RTIEventDllExport 
RTIBool RTIEventJobDispatcher_delete(
    struct RTIEventJobDispatcher *me, struct REDAWorker *worker);

extern RTIEventDllExport 
struct RTIEventJobDispatcher *RTIEventJobDispatcher_new(
    struct RTIClock *clock,
    struct RTIEventGenerator *generator,
    struct REDAWorkerFactory *workerFactory,
    struct RTIOsapiThreadFactory *threadFactory,
    REDAOrderedDataTypeCompareFunction bucketCompareFnc,
    REDAOrderedDataTypeCompareFunction threadCompareFnc,
    REDAOrderedDataTypeCompareFunction groupCompareFnc,
    struct RTIEventJobDispatcherListener *listener,
    const struct RTIEventJobDispatcherProperty *property, struct REDAWorker *worker);

extern RTIEventDllExport 
RTIBool RTIEventJobDispatcher_preShutdownWakeup(
    struct RTIEventJobDispatcher *me, struct REDAWorker *worker);

extern RTIEventDllExport 
RTIBool RTIEventJobDispatcher_shutdown(
    struct RTIEventJobDispatcher *me, struct REDAWorker *worker);


/*e \ingroup RTIEventJobDispatcherClass
  @brief Size of storage.
 */
#define  RTI_EVENT_JOB_DISPATCHER_STORAGE_LENGTH (8)
/*e \ingroup RTIEventJobDispatcherClass
  @brief Size of priority.
 */
#define  RTI_EVENT_JOB_DISPATCHER_PRIORITY_LENGTH (4)

struct RTIEventJobDispatcherStorage {
    void *field[ RTI_EVENT_JOB_DISPATCHER_STORAGE_LENGTH];
};

struct RTIEventJobDispatcherJobPriority {
    /*e The Dispatcher does not interpret job priority in any way. They are passed
        as input parameters to the priorityCompareFnc defined in RTIEventJobDispatcher_assertTokenBucket.
        Therefore, user is free to define and store anything in the array. However,
        the contents must be shallow-copiable. That is, memcpy(dest, priority, sizeof(priority))
        must work.
    */
    int priority[ RTI_EVENT_JOB_DISPATCHER_PRIORITY_LENGTH];
};

typedef void (* RTIEventJobDispatcherPriorityCopyFunction)(
    struct RTIEventJobDispatcherJobPriority *dst, const void *src);

struct RTIEventJobDispatcherJobInfo {
    /*e Group storage as defined when creating the group. The pointer address is
        immutable, although the user may alter the field data.
    */
    struct RTIEventJobDispatcherStorage *groupStorage;
    /*e Job storage as defined when defining the job. The pointer address is
        immutable, although the user may alter the field data.
    */
    struct RTIEventJobDispatcherStorage *jobStorage;
    /*e Schedule storage as defined when scheduling the job. The pointer address is
        immutable, although the user may alter the field data.
    */
    struct RTIEventJobDispatcherStorage *scheduleStorage;
    /*e Number of additional units the job still needs after this run. Ie, the
        original units requested on the job less units received thus far.
        
        User should decrement this value to reflect the amount of units consumed
        by the job. The job continues to run until all requested units are fulfilled. 
        The job can also terminate the job early, prior to receiving all units,
        by setting unitsRequested to 0.
    */
    int unitsRequested;
};


typedef int (* RTIEventJobDispatcherAgentFunction)(
    struct RTIEventJobDispatcherStorage *bucketStorage, 
    struct RTIEventJobDispatcherStorage *threadStorage, 
    struct RTIEventJobDispatcherStorage *agentStorage, 
    int unitsReceived, struct REDASkiplist *jobInfoList, struct REDAWorker *worker);


typedef void (* RTIEventJobDispatcherGroupCallback)(
    struct RTIEventJobDispatcherGroup *jobGroup, 
    struct RTIEventJobDispatcherStorage *groupStorage, 
    struct RTIEventJobDispatcherStorage *jobStorage, 
    RTIEventJobDispatcherGroupCallbackMask status, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_detachThread(
        struct RTIEventJobDispatcher *me,
        struct RTIEventJobDispatcherThread *executionThread,
        struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_removeThread(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherThread *executionThread, struct REDAWorker *worker);

extern RTIEventDllExport
struct RTIEventJobDispatcherThread *RTIEventJobDispatcher_assertThread(
    struct RTIEventJobDispatcher *me, const struct RTIEventJobDispatcherStorage *threadStorage, 
    struct REDAExclusiveArea *eaBeforeAgentFncs,
    const struct RTIEventJobDispatcherThreadProperty *property, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_executeThreadAgents(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherThread *executionThread, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_removeTokenBucket(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherTokenBucket *tokenBucket, struct REDAWorker *worker);

extern RTIEventDllExport
struct RTIEventJobDispatcherTokenBucket *RTIEventJobDispatcher_assertTokenBucket(
    struct RTIEventJobDispatcher *me, 
    REDAOrderedDataTypeCompareFunction agentCompareFnc,
    REDAOrderedDataTypeCompareFunction agentPriorityCompareFnc,
    REDAOrderedDataTypeCompareFunction jobPriorityCompareFnc,
    RTIEventJobDispatcherPriorityCopyFunction priorityCopyFnc,
    const struct RTIEventJobDispatcherStorage *bucketStorage, 
    const struct RTIEventJobDispatcherTokenBucketProperty *property,
    struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_getTokenBucketProperty(
    struct RTIEventJobDispatcher *me, 
    struct RTIEventJobDispatcherTokenBucket *tokenBucket,
    struct RTIEventJobDispatcherTokenBucketProperty *property, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_setTokenBucketProperty(
    struct RTIEventJobDispatcher *me, 
    struct RTIEventJobDispatcherTokenBucket *tokenBucket,
    const struct RTIEventJobDispatcherTokenBucketProperty *property, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_addTokens(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherTokenBucket *tokenBucket,
    struct REDAWorker *worker);

extern RTIEventDllExport
void RTIEventJobDispatcher_getJobPriorityAttribute(
    struct RTIEventJobDispatcher *me, 
    struct RTIEventJobDispatcherAgent *agent,
    struct RTIEventJobDispatcherJobPriority *dst, const void *src);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_removeAgent(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherAgent *jobAgent, struct REDAWorker *worker);

extern RTIEventDllExport
struct RTIEventJobDispatcherAgent *RTIEventJobDispatcher_assertAgent(
    struct RTIEventJobDispatcher *me,
    struct RTIEventJobDispatcherTokenBucket *tokenBucket,
    struct RTIEventJobDispatcherThread *executionThread,
    RTIEventJobDispatcherAgentFunction agentFnc,
    const struct RTIEventJobDispatcherStorage *agentStorage,
    const struct RTIEventJobDispatcherAgentProperty *property,
    struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_removeGroup(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherGroup *jobGroup, struct REDAWorker *worker);

extern RTIEventDllExport
struct RTIEventJobDispatcherGroup *RTIEventJobDispatcher_assertGroup(
    struct RTIEventJobDispatcher *me,
    REDAOrderedDataTypeCompareFunction jobCompareFnc,
    RTIEventJobDispatcherGroupCallback groupCallbackFnc,
    const struct RTIEventJobDispatcherStorage *groupStorage,
    const struct RTIEventJobDispatcherGroupProperty *property,
    struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_finalizeJob(
    struct RTIEventJobDispatcher *me, struct RTIEventJobDispatcherDefinedJob *definedJob, struct REDAWorker *worker);

extern RTIEventDllExport
struct RTIEventJobDispatcherDefinedJob *RTIEventJobDispatcher_defineJob(
    struct RTIEventJobDispatcher *me, RTIEventJobDispatcherJobDefineResult *result, 
    struct RTIEventJobDispatcherGroup *jobGroup,
    int unitsRequested, const struct RTINtpTime *pruningTimeout, 
    const struct RTIEventJobDispatcherStorage *jobStorage, struct REDAWorker *worker);

extern RTIEventDllExport
RTIBool RTIEventJobDispatcher_retrieveJobInfo(
    struct RTIEventJobDispatcher *me, RTIBool *jobExists, 
    int *unitsRequested,
    struct RTIEventJobDispatcherStorage *jobStorage, 
    struct RTIEventJobDispatcherGroup *jobGroup, int index,
    RTIBool inGroupCallback,
    struct REDAWorker *worker);

extern RTIEventDllExport
void RTIEventJobDispatcher_scheduleJob(
    struct RTIEventJobDispatcher *me, RTIEventJobDispatcherJobScheduleResult *result, 
    struct RTIEventJobDispatcherAgent *jobAgent,
    struct RTIEventJobDispatcherDefinedJob *definedJob,
    const struct RTIEventJobDispatcherJobPriority *jobPriority,
    RTIBool allowDuplicateJob,
    int *unitsRequested,
    const struct RTIEventJobDispatcherStorage *scheduleStorage, struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* event_jobDispatcher_h */
