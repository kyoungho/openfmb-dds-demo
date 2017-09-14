/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_factory_plugin_impl.h    generated by: makeheader    Thu Jun 22 14:17:48 2017
 *
 *		built from:	factory_plugin_impl.ifc
 */

#ifndef dds_c_factory_plugin_impl_h
#define dds_c_factory_plugin_impl_h


  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_common_h
    #include "dds_c/dds_c_common.h"
  #endif

  #ifndef dds_c_dynamicdata_h
    #include "dds_c/dds_c_dynamicdata.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


typedef DDS_ReturnCode_t 
(*DDS_ProxyTypeSupport_RegisterTypeFunction)( 
                                        DDS_DomainParticipant * participant, 
                                        const char * edTypeName,
                                        void * userData);

typedef void 
(*DDS_ProxyTypeSupport_DeleteUserDataFunction) (void * userData);


struct DDS_ProxyTypeSupport {

    DDS_ProxyTypeSupport_RegisterTypeFunction registerType;

    DDS_ProxyTypeSupport_DeleteUserDataFunction deleteUserData;
    
    void * userData;

};

extern DDSCDllExport
struct DDS_ProxyTypeSupport * DDS_ProxyTypeSupport_new();

extern DDSCDllExport
void DDS_ProxyTypeSupport_delete(struct DDS_ProxyTypeSupport * self);

typedef void* DDS_FactoryPluginUserTypeInfo;

typedef void* ListenerInfo;

typedef DDS_DomainParticipant *
(*DDS_FactoryPluginSupport_CreateParticipantFunction)(
                                DDS_DomainId_t domainId,
                                const struct DDS_DomainParticipantQos * qos,
                                const ListenerInfo listenerInfo,
                                DDS_StatusMask mask);

typedef DDS_ReturnCode_t
(*DDS_FactoryPluginSupport_DeleteParticipantFunction)(
                                DDS_DomainParticipant * participant);

typedef DDS_Publisher * 
(*DDS_FactoryPluginSupport_CreatePublisherFunction)(
                                DDS_DomainParticipant * participant,
                                const struct DDS_PublisherQos * qos,
                                const ListenerInfo listenerInfo,
                                DDS_StatusMask mask);

typedef DDS_Publisher *
(*DDS_FactoryPluginSupport_GetImplicitPublisherFunction)(
                               DDS_DomainParticipant * participant);

typedef DDS_Subscriber *
(*DDS_FactoryPluginSupport_CreateSubscriberFunction)(
                               DDS_DomainParticipant * participant,
                               const struct DDS_SubscriberQos * qos,
                               const ListenerInfo listenerInfo,
                               DDS_StatusMask mask);

typedef DDS_Subscriber *
(*DDS_FactoryPluginSupport_GetImplicitSubscriberFunction)(
                               DDS_DomainParticipant * participant);

typedef DDS_Topic *
(*DDS_FactoryPluginSupport_CreateTopicFunction)(
                                DDS_DomainParticipant * participant,
                                const char * topic_name,
                                const char * type_name,
                                const struct DDS_TopicQos* qos,
                                const ListenerInfo listenerInfo,
                                DDS_StatusMask mask);

typedef DDS_TopicDescription *
(*DDS_FactoryPluginSupport_CreateContentFilteredTopicFunction)(
                                DDS_DomainParticipant * participant,
                                const char * name,
                                DDS_Topic * related_topic,
                                const char * filter_expression,
                                const struct DDS_StringSeq * filter_parameters,
                                const char * filter_name);

typedef DDS_DataWriter *
(*DDS_FactoryPluginSupport_CreateDataWriterFunction)(
                                DDS_Publisher * publishery,
                                DDS_Topic * topic,
                                const struct DDS_DataWriterQos * qos,
                                const ListenerInfo listenerInfo,
                                DDS_StatusMask mask);

typedef DDS_DataReader * 
(*DDS_FactoryPluginSupport_CreateDataReaderFunction)(
                                DDS_Subscriber * subscriber,
                                DDS_TopicDescription * topicDescription,
                                const struct DDS_DataReaderQos * qos,
                                const ListenerInfo listenerInfo,
                                DDS_StatusMask mask);

typedef struct DDS_ProxyTypeSupport * 
(*DDS_FactoryPluginSupport_CreateUserProxyTypeSupportFunction) (
                            DDS_FactoryPluginUserTypeInfo userTypeInfo);

typedef struct DDS_ProxyTypeSupport *
(*DDS_FactoryPluginSupport_CreateDynamicDataProxyTypeSupportFunction) (
                            const DDS_TypeCode * typeCode,
                            const struct DDS_DynamicDataTypeProperty_t * ddProperties);

struct DDS_FactoryPluginSupport {
    
      
    DDS_FactoryPluginSupport_CreateParticipantFunction 
                                        createParticipant;
    
    DDS_FactoryPluginSupport_DeleteParticipantFunction
                                        deleteParticipant;
    
    DDS_FactoryPluginSupport_CreatePublisherFunction 
                                        createPublisher;
    
    DDS_FactoryPluginSupport_GetImplicitPublisherFunction
                                        getImplicitPublisher;
    
    DDS_FactoryPluginSupport_CreateSubscriberFunction 
                                        createSubscriber;
    
    DDS_FactoryPluginSupport_GetImplicitSubscriberFunction 
                                        getImplicitSubscriber;
    
    DDS_FactoryPluginSupport_CreateTopicFunction 
                                        createTopic;
    
    DDS_FactoryPluginSupport_CreateContentFilteredTopicFunction
                                        createContentFilteredTopic;
    
    DDS_FactoryPluginSupport_CreateDataWriterFunction 
                                        createWriter;
    
    DDS_FactoryPluginSupport_CreateDataReaderFunction 
                                        createReader;
    
    DDS_FactoryPluginSupport_CreateDynamicDataProxyTypeSupportFunction 
                                          createDynamicDataProxyTypeSupport;
    
    DDS_FactoryPluginSupport_CreateUserProxyTypeSupportFunction 
                                          createUserProxyTypeSupport;
    
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_factory_plugin_impl_h */
