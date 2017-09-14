/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_cpp_subscription.h    generated by: makeheader    Thu Jun 22 14:17:53 2017
 *
 *		built from:	subscription.ifcxx
 */

#ifndef dds_cpp_subscription_h
#define dds_cpp_subscription_h


  #include <stdio.h>

  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif
  #ifndef dds_cpp_infrastructure_h
     #include "dds_cpp/dds_cpp_infrastructure.h"
  #endif
  #ifndef dds_c_subscription_h
     #include "dds_c/dds_c_subscription.h"
  #endif

class DDSDataReader;

class DDSStringDataReader;

class DDSKeyedStringDataReader;

class DDSOctetsDataReader;

class DDSKeyedOctetsDataReader;

typedef DDSDataReader* DDSDataReader_ptr;


DDS_SEQUENCE(DDSDataReaderSeq, DDSDataReader_ptr);

class DDSCPPDllExport DDSDataReaderListener : public virtual DDSListener {
  // --- <<interface>> DDSDataReaderListener: -----------------------
  public:

    /*e \dref_DataReaderListener_on_requested_deadline_missed
     */
    virtual void on_requested_deadline_missed(DDSDataReader* reader,
        const DDS_RequestedDeadlineMissedStatus& status);

    /*e \dref_DataReaderListener_on_liveliness_changed
     */
    virtual void on_liveliness_changed(DDSDataReader* reader,
        const DDS_LivelinessChangedStatus& status);

    /*e \dref_DataReaderListener_on_requested_incompatible_qos
     */
    virtual void on_requested_incompatible_qos(DDSDataReader* reader,
        const DDS_RequestedIncompatibleQosStatus& status);

    /*e \dref_DataReaderListener_on_sample_rejected
     */
    virtual void on_sample_rejected(DDSDataReader* reader, 
        const DDS_SampleRejectedStatus& status);

    /*e \dref_DataReaderListener_on_data_available
     */
    virtual void on_data_available(DDSDataReader* reader);

    /*e \dref_DataReaderListener_on_sample_lost
     */
    virtual void on_sample_lost(DDSDataReader* reader,
        const DDS_SampleLostStatus& status);

    /*e \dref_DataReaderListener_on_subscription_matched
     */
    virtual void on_subscription_matched(DDSDataReader* reader,
        const DDS_SubscriptionMatchedStatus& status);

  public: 

    virtual ~DDSDataReaderListener();
};

class DDSSubscriber;

class DDSCPPDllExport DDSSubscriberListener : public virtual DDSDataReaderListener {
  public: 

    /*e \dref_SubscriberListener_on_data_on_readers
     */
    virtual void on_data_on_readers(DDSSubscriber* sub);

  public: 

    virtual ~DDSSubscriberListener();
};

class DDSCPPDllExport DDSReadCondition : public DDSCondition {
  public: 

    /*e  \dref_ReadCondition_get_sample_state_mask
     */
    virtual DDS_SampleStateMask get_sample_state_mask() 
        = 0;

    /*e  \dref_ReadCondition_get_view_state_mask
     */
    virtual DDS_ViewStateMask get_view_state_mask() 
        = 0;

    /*e  \dref_ReadCondition_get_instance_state_mask
     */
    virtual DDS_InstanceStateMask get_instance_state_mask() 
        = 0;

    /*e  \dref_ReadCondition_get_instance_state_mask
     */
    virtual DDS_StreamKindMask get_stream_kind_mask()
        = 0;

    /*e  \dref_ReadCondition_get_datareader
     */
    virtual DDSDataReader* get_datareader() 
        = 0;

  protected:

    virtual ~DDSReadCondition();	
};

class DDSCPPDllExport DDSQueryCondition : public DDSReadCondition {
  public: 

    /*e \dref_QueryCondition_get_query_expression
     */
    virtual const char* get_query_expression() 
        = 0;

    /*e \dref_QueryCondition_get_query_parameters
     */
    virtual DDS_ReturnCode_t get_query_parameters(
        DDS_StringSeq& query_parameters)
        = 0;

    /*e \dref_QueryCondition_set_query_parameters
     */
    virtual DDS_ReturnCode_t set_query_parameters(
	const DDS_StringSeq& query_parameters)
        = 0;

  protected:

    virtual ~DDSQueryCondition();	
};

class DDSCPPDllExport DDSIndexCondition : public DDSReadCondition {
  
  protected:

    virtual ~DDSIndexCondition();	
};

class DDSSubscriber;

typedef DDSSubscriber* DDSSubscriber_ptr;


DDS_SEQUENCE(DDSSubscriberSeq, DDSSubscriber_ptr);

class DDSTopicDescription;

class DDSDomainParticipant;

class DDSCPPDllExport DDSSubscriber : public DDSDomainEntity {
  // --- eXtension methods: --------------------------------------------
  public:

    /*e \dref_Subscriber_get_default_datareader_qos
     */
    virtual DDS_ReturnCode_t get_default_datareader_qos(
        DDS_DataReaderQos& qos)
        = 0;

    /*i \dref_Subscriber_get_default_datareader_qos_w_topic_name
     */
    virtual DDS_ReturnCode_t get_default_datareader_qos_w_topic_name(
        DDS_DataReaderQos& qos,
        const char *topic_name)
        = 0;
    
    /*e \dref_Subscriber_set_default_datareader_qos
     */
    virtual DDS_ReturnCode_t set_default_datareader_qos(
        const DDS_DataReaderQos& qos)
        = 0;

    /*e \dref_Subscriber_set_default_datareader_qos_with_profile
     */
    virtual DDS_ReturnCode_t set_default_datareader_qos_with_profile(
        const char * library_name,
	const char * profile_name)
        = 0;

    /*e \dref_Subscriber_set_default_library
     */
    virtual DDS_ReturnCode_t set_default_library(
        const char *library_name)
        = 0;

    /*e \dref_Subscriber_get_default_library
     */
    virtual const char * get_default_library()
        = 0;

    /*e \dref_Subscriber_set_default_profile
     */
    virtual DDS_ReturnCode_t set_default_profile(
	const char *library_name,
        const char *profile_name)
        = 0;

    /*e \dref_Subscriber_get_default_profile
     */
    virtual const char * get_default_profile()
        = 0;

    /*e \dref_Subscriber_get_default_profile_library
     */
    virtual const char * get_default_profile_library()
        = 0;

  // --- <<interface>> DDSSubscriber: ----------------------------------
  public:

    /*e \dref_Subscriber_create_datareader
     */
    virtual DDSDataReader* create_datareader(
        DDSTopicDescription* topic,
        const DDS_DataReaderQos& qos,
        DDSDataReaderListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_Subscriber_create_datareader_with_profile
     */
    virtual DDSDataReader* create_datareader_with_profile(
        DDSTopicDescription* topic,
        const char *library_name,
        const char *profile_name,
        DDSDataReaderListener* listener,
	DDS_StatusMask mask)
        = 0;

    /*e \dref_Subscriber_delete_datareader
     */
    virtual DDS_ReturnCode_t delete_datareader(
        DDSDataReader* a_datareader)
        = 0;

    /*e \dref_Subscriber_delete_contained_entities
     */
    virtual DDS_ReturnCode_t delete_contained_entities()
        = 0;

    /*e \dref_Subscriber_lookup_datareader
     */
    virtual DDSDataReader* lookup_datareader(const char* topic_name)
        = 0;

    /*e \dref_Subscriber_begin_access
      */
    virtual DDS_ReturnCode_t begin_access()
        = 0;

    /*e \dref_Subscriber_end_access
     */
    virtual DDS_ReturnCode_t end_access()
        = 0;

    /*e \dref_Subscriber_get_datareaders
     */
    virtual DDS_ReturnCode_t get_datareaders(
	DDSDataReaderSeq& readers,
	DDS_SampleStateMask sample_states,
	DDS_ViewStateMask view_states,
	DDS_InstanceStateMask instance_states)
        = 0;
    
    /*e \dref_Subscriber_get_all_datareaders
    */
    virtual DDS_ReturnCode_t get_all_datareaders(
	DDSDataReaderSeq& readers)
        = 0;

    /*e \dref_Subscriber_notify_datareaders
     */
    virtual DDS_ReturnCode_t notify_datareaders()
        = 0;

    /*e \dref_Subscriber_get_participant
     */
    virtual DDSDomainParticipant* get_participant()
        = 0;

    /*e \dref_Subscriber_copy_from_topic_qos
     */
    virtual DDS_ReturnCode_t copy_from_topic_qos(
	DDS_DataReaderQos& datareader_qos, const DDS_TopicQos& topic_qos)
        = 0;

  // --- <<interface>> DDSEntity: -------------------------------------
  public:

    /*e \dref_Subscriber_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(const DDS_SubscriberQos& qos)
        = 0;

    /*e \dref_Subscriber_set_qos_with_profile
     */
    virtual DDS_ReturnCode_t set_qos_with_profile(
	const char *library_name,
	const char *profile_name)
        = 0;

    /*e \dref_Subscriber_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(DDS_SubscriberQos& qos)
        = 0;

    /*e \dref_Subscriber_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(DDSSubscriberListener* l, 
        DDS_StatusMask mask = DDS_STATUS_MASK_ALL)
        = 0;

    /*e \dref_Subscriber_get_listener
     */
    virtual DDSSubscriberListener* get_listener()
	    = 0;
  
  // --- <<impl>> eXtensions: ------------------------------------------
  public:
      virtual DDS_Subscriber* get_c_subscriberI() 
        = 0;
    
  // --- << entity configuration>>: -------------------------------------
  public:
    /*e \dref_Subscriber_lookup_datareader_by_name
     */
      virtual DDSDataReader * lookup_datareader_by_name(
        const char * datareader_name) 
        = 0;


  // --- <<lifecycle>>: ----------------------------------------------  
  protected: 

    virtual ~DDSSubscriber();
};

struct DDS_PublicationBuiltinTopicData;

class DDSCPPDllExport DDSTopicQuery;

class DDSCPPDllExport DDSDataReader : public DDSDomainEntity {
  // --- <<interface>> DDSDataReader: ----------------------------------
  public:

    virtual DDSEntity_impl* get_impl_EntityI() {
	return _impl->get_impl_EntityI();
    }

    virtual DDS_DataReader* get_c_datareaderI() {
        return _impl->get_c_datareaderI();
    }

    /*e \dref_DataReader_create_readcondition
     */
    virtual DDSReadCondition* create_readcondition(
	DDS_SampleStateMask sample_states, 
	DDS_ViewStateMask view_states,
	DDS_InstanceStateMask instance_states) {
	return _impl->create_readcondition(sample_states, view_states,
					   instance_states);
    }

    /*e \dref_DataReader_create_readcondition_w_params
     */
    virtual DDSReadCondition* create_readcondition_w_params(
        DDS_ReadConditionParams &params) {
        return _impl->create_readcondition_w_params(params);
    }

    /*e \dref_DataReader_create_querycondition
     */
    virtual DDSQueryCondition* create_querycondition(
	DDS_SampleStateMask sample_states, 
	DDS_ViewStateMask view_states,
	DDS_InstanceStateMask instance_states,
	const char* query_expression,
	const struct DDS_StringSeq& query_parameters) {
	return _impl->create_querycondition(sample_states, view_states,
					    instance_states, query_expression,
					    query_parameters);
    }

    /*e \dref_DataReader_create_querycondition_w_params
     */
    virtual DDSQueryCondition* create_querycondition_w_params(
        DDS_QueryConditionParams &params) {
        return _impl->create_querycondition_w_params(params);
    }

    virtual DDSIndexCondition* create_indexcondition(
        DDS_SampleStateMask sample_states, 
        DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states,
        const char* index_name,
        DDS_SampleInfo & sample_info) {
        return _impl->create_indexcondition(sample_states, view_states,
                                            instance_states, index_name,
                                            sample_info);

    }

    virtual DDS_ReturnCode_t create_correlation_index(
        const char* index_name) {
        return _impl->create_correlation_index(index_name);

    }

    virtual DDS_ReturnCode_t create_related_sample_identity_index(
        const char* index_name) {
        return _impl->create_related_sample_identity_index(index_name);

    }

    virtual DDS_ReturnCode_t delete_index(
        const char* index_name) {
        return _impl->delete_index(index_name);

    }

    /*e \dref_DataReader_delete_readcondition
     */
    virtual DDS_ReturnCode_t delete_readcondition(
	DDSReadCondition* condition) {
	return _impl->delete_readcondition(condition);
    }

    /*e \dref_DataReader_delete_contained_entities
     */
    virtual DDS_ReturnCode_t delete_contained_entities() {
	return _impl->delete_contained_entities();
    }

    /*e \dref_DataReader_wait_for_historical_data
     */
    virtual DDS_ReturnCode_t wait_for_historical_data(
	const DDS_Duration_t& max_wait) {
	return _impl->wait_for_historical_data(max_wait);
    }
    
    /*e \dref_DataReader_acknowledge_sample
     */                                                     
    virtual DDS_ReturnCode_t acknowledge_sample(
            const DDS_SampleInfo & sample_info) {
        return _impl->acknowledge_sample(sample_info);          
    }

    /*e \dref_DataReader_acknowledge_all
     */        
    virtual DDS_ReturnCode_t acknowledge_all() {
        return _impl->acknowledge_all();
    }

    /*e \dref_DataReader_acknowledge_sample_w_response
     */                                                     
    virtual DDS_ReturnCode_t acknowledge_sample(
        const DDS_SampleInfo & sample_info,
        const DDS_AckResponseData_t & response_data) {
        return _impl->acknowledge_sample(sample_info, response_data);          
    }

    /*e \dref_DataReader_acknowledge_all_w_response
     */                                                     
    virtual DDS_ReturnCode_t acknowledge_all(
        const DDS_AckResponseData_t & response_data) {
        return _impl->acknowledge_all(response_data);
    }

    /*i \dref_DataReader_set_last_publication_sequence_number
     */                                                     
    virtual DDS_ReturnCode_t set_last_publication_sequence_number(
        const DDS_InstanceHandle_t & publication_handle,
        int offset_mode,
        const struct DDS_SequenceNumber_t & sequence_number) {
        return _impl->set_last_publication_sequence_number(publication_handle,
                                                        offset_mode,
                                                        sequence_number);
    }

    /*e \dref_DataReader_get_matched_publications
     */
    virtual DDS_ReturnCode_t get_matched_publications(
	DDS_InstanceHandleSeq& publication_handles) {
	return _impl->get_matched_publications(publication_handles);
    }

    /*e \dref_DataReader_get_matched_publication_data
     */
    virtual DDS_ReturnCode_t get_matched_publication_data(
	DDS_PublicationBuiltinTopicData& publication_data,
	const DDS_InstanceHandle_t& publication_handle) {
	return _impl->get_matched_publication_data(publication_data,
						   publication_handle);
    }

    /*e \dref_DataReader_get_matched_publication_participant_data
     */
    virtual DDS_ReturnCode_t get_matched_publication_participant_data(
	DDS_ParticipantBuiltinTopicData& participant_data,
	const DDS_InstanceHandle_t& publication_handle) {
	return _impl->get_matched_publication_participant_data(
           participant_data, publication_handle);
    }

    /*e \dref_DataReader_get_topicdescription
     */
    virtual DDSTopicDescription* get_topicdescription() {
	return _impl->get_topicdescription();
    }

    /*e \dref_DataReader_get_subscriber
     */
    virtual DDSSubscriber* get_subscriber() {
	return _impl->get_subscriber();
    }

    /*e \dref_DataReader_get_sample_rejected_status  
     */
    virtual DDS_ReturnCode_t get_sample_rejected_status(
            DDS_SampleRejectedStatus& status) {
        return _impl->get_sample_rejected_status(status);
    }

    /*e \dref_DataReader_get_liveliness_changed_status
     */
    virtual DDS_ReturnCode_t get_liveliness_changed_status(
            DDS_LivelinessChangedStatus& status) {
        return _impl->get_liveliness_changed_status(status);
    }

    /*e \dref_DataReader_get_requested_deadline_missed_status
     */
    virtual DDS_ReturnCode_t get_requested_deadline_missed_status(
            DDS_RequestedDeadlineMissedStatus& status) {
        return _impl->get_requested_deadline_missed_status(status);
    }

    /*e \dref_DataReader_get_requested_incompatible_qos_status
     */
    virtual DDS_ReturnCode_t get_requested_incompatible_qos_status(
            DDS_RequestedIncompatibleQosStatus& status) {
        return _impl->get_requested_incompatible_qos_status(status);
    }

    /*e \dref_DataReader_get_sample_lost_status
     */
    virtual DDS_ReturnCode_t get_sample_lost_status(
            DDS_SampleLostStatus& status) {
        return _impl->get_sample_lost_status(status);
    }

    /*e \dref_DataReader_get_subscription_matched_status
     */
    virtual DDS_ReturnCode_t get_subscription_matched_status(
            DDS_SubscriptionMatchedStatus& status) {
        return _impl->get_subscription_matched_status(status);
    }

    /*e \dref_DataReader_get_datareader_cache_status
     */
    virtual DDS_ReturnCode_t get_datareader_cache_status(
            DDS_DataReaderCacheStatus& status) {
        return _impl->get_datareader_cache_status(status);
    }

    /*e \dref_DataReader_get_datareader_protocol_status
     */
    virtual DDS_ReturnCode_t get_datareader_protocol_status(
            DDS_DataReaderProtocolStatus& status) {
        return _impl->get_datareader_protocol_status(status);
    }

    /*e \dref_DataReader_get_matched_publication_datareader_protocol_status
     */
    virtual DDS_ReturnCode_t get_matched_publication_datareader_protocol_status(
            DDS_DataReaderProtocolStatus& status,
            const DDS_InstanceHandle_t& publication_handle) {
        return _impl->get_matched_publication_datareader_protocol_status(
            status,
            publication_handle);
    }

    /*e \dref_DataReader_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(const DDS_DataReaderQos& qos) {
	return _impl->set_qos(qos);
    }

    /*e \dref_DataReader_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(DDS_DataReaderQos& qos) {
        return _impl->get_qos(qos);
    }

    /*e \dref_DataReader_set_qos_with_profile
     */
    virtual DDS_ReturnCode_t set_qos_with_profile(
        const char *library_name,
        const char *profile_name){

	return _impl->set_qos_with_profile(library_name, profile_name);
    }

    /*e \dref_DataReader_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(DDSDataReaderListener* l, 
                DDS_StatusMask mask = DDS_STATUS_MASK_ALL) {
	return _impl->set_listener(l, mask);
    }

    /*e \dref_DataReader_get_listener
     */
    virtual DDSDataReaderListener* get_listener() {
	return _impl->get_listener();
    }
    
    /*e \dref_DataReader_create_topic_query
     */
    virtual DDSTopicQuery* create_topic_query(
        const DDS_TopicQuerySelection& selection) {
        return _impl->create_topic_query(selection);
    }
        
    /*e \dref_DataReader_delete_topic_query
     */
    virtual DDS_ReturnCode_t delete_topic_query(DDSTopicQuery* query) {
        return _impl->delete_topic_query(query);
    }

    /*e \dref_DataReader_lookup_topic_query
     */
    virtual DDSTopicQuery* lookup_topic_query(const DDS_GUID_t& guid) {
        return _impl->lookup_topic_query(guid);
    }
   
  public:

    virtual DDS_Boolean compare_typeI(const char * typeToCompare) {
        return _impl->compare_typeI(typeToCompare);
    }

    static void deleteI(DDSDataReader *reader);

  public:

    virtual DDS_ReturnCode_t enable() {
	return _impl->enable();
    }

    virtual DDS_ReturnCode_t lock() {
        return _impl->lock();
    }

    virtual DDS_ReturnCode_t unlock() {
        return _impl->unlock();
    }

    virtual DDSStatusCondition* get_statuscondition() {
        return _impl->get_statuscondition();
    }

    virtual DDS_StatusMask get_status_changes() {
	return _impl->get_status_changes();
    }

    virtual DDS_InstanceHandle_t get_instance_handle() {
        return _impl->get_instance_handle();
    }

  protected:

    virtual ~DDSDataReader();

  protected:


    /*
      These are implemented in the "type-specific" FooDataReader
      generated classes: [see DDS_DATA_READER() in dds_data.h]
      
      DDS_ReturnCode_t read(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t take(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t read_w_condition(DDSDataSeq& received_data,
      DDS_SampleInfoSeq& info_seq,
      DDS_Long max_samples,
      DDSReadCondition* condition);
    
      DDS_ReturnCode_t take_w_condition(DDSDataSeq& received_data,
      DDS_SampleInfoSeq& info_seq,
      DDS_Long max_samples,
      DDSReadCondition* condition);

      DDS_ReturnCode_t read_next_sample(DDSData& received_data,
      DDSSampleInfo& sample_info);

      DDS_ReturnCode_t take_next_sample(DDSData& received_data,
      DDSSampleInfo& sample_info);
    
      DDS_ReturnCode_t read_instance(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& a_handle,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t take_instance(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& a_handle,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t read_next_instance(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& previous_handle,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t take_next_instance(DDSDataSeq& received_data,
      DDSSampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& previous_handle,
      DDS_SampleStateMask sample_states, 
      DDS_ViewStateMask view_states, 
      DDS_InstanceStateMask instance_states);

      DDS_ReturnCode_t read_next_instance_w_condition(DDSDataSeq& received_data,
      DDS_SampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& previous_handle,
      DDSReadCondition* condition);
    
      DDS_ReturnCode_t take_next_instance_w_condition(DDSDataSeq& received_data,
      DDS_SampleInfoSeq& info_seq,
      DDS_Long max_samples,
      const DDS_InstanceHandle_t& previous_handle,
      DDSReadCondition* condition);

      DDS_ReturnCode_t return_loan(DDSDataSeq& received_data,
				   DDS_SampleInfoSeq& info_seq) {

      DDS_ReturnCode_t get_key_value(Data& key_holder, 
    			             const DDS_InstanceHandle_t handle);

      DDS_InstanceHandle_t lookup_instance(const Foo& instance_data);
    */

    virtual DDS_ReturnCode_t read_or_take_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
        DDS_Long max_samples,
        DDS_SampleStateMask sample_states, DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states,
        bool take) {
	return _impl->read_or_take_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, sample_states,
	    view_states, instance_states, take);
    }

    virtual DDS_ReturnCode_t read_or_take_w_condition_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
        DDS_Long max_samples,
        DDSReadCondition* condition,
        bool take) {
    return _impl->read_or_take_w_condition_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, condition,
	    take);
    }

    virtual DDS_ReturnCode_t read_or_take_next_sample_untypedI(
        void* received_data,
        DDS_SampleInfo& sample_info,
        bool take) {
	return _impl->read_or_take_next_sample_untypedI(
	    received_data, sample_info,
	    take);
    }

    virtual DDS_ReturnCode_t read_or_take_instance_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
        DDS_Long max_samples,
        const DDS_InstanceHandle_t& a_handle,
        DDS_SampleStateMask sample_states, DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states,
        bool take) {
    return _impl->read_or_take_instance_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, a_handle, sample_states,
	    view_states, instance_states, take);
    }

    virtual DDS_ReturnCode_t read_or_take_instance_w_condition_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
        DDS_Long max_samples,
        const DDS_InstanceHandle_t& previous_handle,
        DDSReadCondition* condition,
        bool take) {
    return _impl->read_or_take_instance_w_condition_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, previous_handle, condition,
	    take);
    }

    virtual DDS_ReturnCode_t read_or_take_next_instance_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
        DDS_Long max_samples,
        const DDS_InstanceHandle_t& previous_handle,
        DDS_SampleStateMask sample_states, DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states,
        bool take) {
    return _impl->read_or_take_next_instance_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, previous_handle, sample_states,
	    view_states, instance_states, take);
    }

    virtual DDS_ReturnCode_t read_or_take_next_instance_w_condition_untypedI(
        DDS_Boolean* is_loan,
        void*** received_data,
        int* data_count, DDS_SampleInfoSeq& info_seq,
        DDS_Long data_seq_len, DDS_Long data_seq_max_len,
        DDS_Boolean data_seq_has_ownership,
        void* data_seq_contiguous_buffer_for_copy,
        int data_size,
    	DDS_Long max_samples,
        const DDS_InstanceHandle_t& previous_handle,
        DDSReadCondition* condition,
        bool take) {
    return _impl->read_or_take_next_instance_w_condition_untypedI(
	    is_loan, received_data, data_count, info_seq,
	    data_seq_len, data_seq_max_len, data_seq_has_ownership,
	    data_seq_contiguous_buffer_for_copy,
	    data_size,
	    max_samples, previous_handle, condition,
	    take);
    }

    virtual DDS_ReturnCode_t return_loan_untypedI(void** received_data,
						  int data_count,
						  DDS_SampleInfoSeq& info_seq) {
	return _impl->return_loan_untypedI(received_data, data_count, info_seq);
    }

    virtual DDS_ReturnCode_t get_key_value_untypedI(
	void* key_holder,
	const DDS_InstanceHandle_t& handle) {
	return _impl->get_key_value_untypedI(key_holder, handle);
    }

    virtual DDS_InstanceHandle_t lookup_instance_untypedI(
        const void* key_holder) {
        return _impl->lookup_instance_untypedI(key_holder);
    }
    
    virtual void* create_data_untypedI(void) {
        return NULL;
    }
    
    virtual DDS_Boolean delete_data_untypedI(void * /* sample */) {
        return DDS_BOOLEAN_FALSE;
    }
    
    virtual DDS_Boolean lock_data_untypedI(void * /* sample */) {
        return DDS_BOOLEAN_FALSE;
    }
    
    virtual DDS_Boolean unlock_data_untypedI(void * /* sample */) {
            return DDS_BOOLEAN_FALSE;
    }
    
  protected:
    DDSDataReader(DDSDataReader* impl) : _impl(impl) {}

  private:
    DDSDataReader* _impl;
};

class DDSTopicQuery_impl;

class DDSCPPDllExport DDSTopicQuery {
  // --- <<interface>> DDSTopicQuery: ----------------------------------
  public:
    /*e \dref_TopicQuery_get_guid
     */
    virtual DDS_ReturnCode_t get_guid(DDS_GUID_t& guid) {
        return _impl->get_guid(guid);
    }

    virtual DDS_TopicQuery* get_c_topicqueryI() {
        return _impl->get_c_topicqueryI();
    }
    virtual DDSTopicQuery_impl* get_impl_topicqueryI() {
        return _impl->get_impl_topicqueryI();
    }

  protected:
    DDSTopicQuery(DDSTopicQuery* impl) : _impl(impl) {}
    virtual ~DDSTopicQuery() {}

  private:
    DDSTopicQuery* _impl;
};

class DDSCPPDllExport DDSTopicQueryHelper {
  // --- <<interface>> DDSTopicQuery: ----------------------------------
  public:
    /*e \dref_TopicQueryHelper_topic_query_data_from_service_request
     */
     static DDS_Boolean topic_query_data_from_service_request(
        DDS_TopicQueryData& topic_query_data,
        const DDS_ServiceRequest& service_request);

  private:
    DDSTopicQueryHelper(){}
    ~DDSTopicQueryHelper() {}

};

#endif /* dds_cpp_subscription_h */
