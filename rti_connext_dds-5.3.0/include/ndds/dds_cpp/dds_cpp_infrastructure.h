/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_cpp_infrastructure.h    generated by: makeheader    Thu Jun 22 14:17:53 2017
 *
 *		built from:	infrastructure.ifcxx
 */

#ifndef dds_cpp_infrastructure_h
#define dds_cpp_infrastructure_h


  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif
  #ifndef dds_cpp_sequence_h
    #include "dds_cpp/dds_cpp_sequence.h"
  #endif
  #ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
  #endif
  #include <string>

 
class DDSCPPDllExport DDSListener {
  public:
    /*i
     * Don't instantiate DDSListener directly; instantiate an application-
     * specific subclass of one of the entity-specific listener types (e.g.
     * DDSDataReaderListener).
     * 
     * Unfortunately, we didn't define this ctor explicitly before, so we
     * can't declare it protected now: it could break someone.
     */
    DDSListener();
    virtual ~DDSListener();
};

class DDSCondition;

typedef DDSCondition* DDSCondition_ptr;


DDS_SEQUENCE(DDSConditionSeq, DDSCondition_ptr);

class DDSCPPDllExport DDSConditionHandler {
  // --- <<interface>> DDSConditionHandler: -----------------------
  public:

    /*e \dref_ConditionHandler_on_condition_triggered
     */
    virtual void on_condition_triggered(
            DDSCondition *condition) = 0;

  public:

    virtual ~DDSConditionHandler();
};

class DDSCondition_impl;

class DDSCPPDllExport DDSCondition {
  public: 
    
    /*i
      @brief Get the underlying implementation class object.     
     */   
    virtual DDSCondition_impl* get_impl_ConditionI()
        = 0;
    
  public:

    /*i
     * @brief Get the underlying C-API condition
     */
    virtual DDS_Condition* get_c_condition();

    /*e \dref_Condition_get_trigger_value
     */
    virtual DDS_Boolean get_trigger_value()
        = 0;

    /*e \dref_Condition_set_handler
     */
    virtual DDS_ReturnCode_t set_handler(DDSConditionHandler *handler);

    /*e \dref_Condition_get_handler
     */
    virtual DDSConditionHandler * get_handler();

    /*e \dref_Condition_dispatch
     */
    virtual void dispatch();
    
  protected: 
    
    virtual ~DDSCondition();
};

class DDSGuardCondition_impl;

class DDSDomainParticipantFactory;

class DDSCPPDllExport DDSGuardCondition : public DDSCondition {
  public: 
    
    /*i
      @brief Get the underlying implementation class object.      
     */
    virtual DDSCondition_impl* get_impl_ConditionI();
    
  public: 
    
    /*e \copydoc DDSCondition::get_trigger_value
     */
    virtual DDS_Boolean get_trigger_value();
    
    /*e \dref_GuardCondition_set_trigger_value
     */
    virtual DDS_ReturnCode_t set_trigger_value(DDS_Boolean value);
    
  public:

    /*e \dref_GuardCondition_new
     */
    DDSGuardCondition();

    /*i \dref_GuardCondition_new_w_factory
     */
    DDSGuardCondition(DDSDomainParticipantFactory * factory);
    
    /*e \dref_GuardCondition_delete
     */
    virtual ~DDSGuardCondition();
    
  protected:
    
    /*i 
      @brief Constructor that delegates implementation to an underlying
      implementation object object.
    
      This class assumes "ownership" of the \p impl object.
    
      @param impl underlying implementation object.
     */
    DDSGuardCondition(DDSGuardCondition_impl* impl);
    
  private: 
    
    /*i
      @brief The underlying implementation object owned by this class.
     */
    DDSGuardCondition_impl* _impl; // implementation object instance
};

class DDSStatusCondition_impl;

class DDSEntity;

class DDSCPPDllExport DDSStatusCondition : public DDSCondition {
  public: 
    
    /*e \dref_StatusCondition_get_enabled_statuses
     */
    virtual DDS_StatusMask get_enabled_statuses() 
        = 0;
    
    /*e \dref_StatusCondition_set_enabled_statuses
     */
    virtual DDS_ReturnCode_t set_enabled_statuses(
        DDS_StatusMask mask)
        = 0;

    /*e \dref_StatusCondition_get_entity
     */
    virtual DDSEntity* get_entity()
        = 0;
    
  protected:
    
    virtual ~DDSStatusCondition();
};

class DDSWaitSet_impl;

class DDSCPPDllExport DDSWaitSet {
  public:
    
    /*i
      @brief Get the underlying implementation class object.    
     */
    virtual DDSWaitSet_impl* get_impl_WaitSetI();

    /*i
      @brief Swap with other
     */
    virtual void swap(DDSWaitSet& other);
    
  public: 
    
    /*e \dref_WaitSet_wait
     */
    virtual DDS_ReturnCode_t wait(DDSConditionSeq& active_conditions, 
                const DDS_Duration_t& timeout);
    
    /*e \dref_WaitSet_attach_condition
     */
    virtual DDS_ReturnCode_t attach_condition(DDSCondition* cond);
    
    /*e \dref_WaitSet_detach_condition
     */
    virtual DDS_ReturnCode_t detach_condition(DDSCondition* cond);

    /*e \dref_WaitSet_get_conditions
     */
    virtual DDS_ReturnCode_t get_conditions(
	DDSConditionSeq& attached_conditions);

    /*e \dref_WaitSet_set_property */
    virtual DDS_ReturnCode_t set_property(
	const DDS_WaitSetProperty_t &prop);
    
    /*e \dref_WaitSet_get_property */
    virtual DDS_ReturnCode_t get_property(
	DDS_WaitSetProperty_t &prop);
  public:
    
    /*e \dref_WaitSet_delete
     */
    virtual ~DDSWaitSet();
    
    /*e \dref_WaitSet_new
     */
    DDSWaitSet();

    /*e \dref_WaitSet_new_ex
     */
    DDSWaitSet(const DDS_WaitSetProperty_t &prop);

    /*i \dref_WaitSet_new_w_factory
    */
    DDSWaitSet(DDSDomainParticipantFactory * factory, 
               const DDS_WaitSetProperty_t &prop);

  protected:
    
    /*i
      @brief Constructor that delegates implementation to an underlying
      implementation object object.
    
      This class assumes "ownership" of the \p impl object.
    
      @param impl underlying implementation object.     
     */
    DDSWaitSet(DDSWaitSet_impl* impl);
    
  private: 
    
    /*i
      @brief The underlying implementation object owned by this class.
     */
    DDSWaitSet_impl* _impl;
};

class DDSEntity_impl;

class DDSCPPDllExport DDSEntity {
  public:
    
    /*i
      @brief Get the underlying implementation class object.     
     */
    virtual DDSEntity_impl* get_impl_EntityI()
        = 0;
    
  public: 
    
    /*e \dref_Entity_enable
     */
    virtual DDS_ReturnCode_t enable()
        = 0;
    
    /*e \dref_Entity_get_statuscondition
     */
    virtual DDSStatusCondition* get_statuscondition()
        = 0;
    
    /*e \dref_Entity_get_status_changes
     */
    virtual DDS_StatusMask get_status_changes()
        = 0;
    
    /*e \dref_Entity_get_instance_handle
     */
    virtual DDS_InstanceHandle_t get_instance_handle()
        = 0;

    /*i \dref_Entity_lock
     */    
    virtual DDS_ReturnCode_t lock()
        = 0;

    /*i \dref_Entity_unlock
    */    
    virtual DDS_ReturnCode_t unlock()
        = 0;
        
  protected: 
    
    virtual ~DDSEntity();
};

class DDSCPPDllExport DDSDomainEntity : public DDSEntity {
  protected:
    virtual ~DDSDomainEntity();
};

class DDSCPPDllExport DDSPropertyQosPolicyHelper {
  public:
    /*e \dref_PropertyQosPolicyHelper_get_number_of_properties
    */
    static DDS_Long get_number_of_properties(DDS_PropertyQosPolicy& policy);
    /*e \dref_PropertyQosPolicyHelper_assert_property
    */
    static DDS_ReturnCode_t assert_property(DDS_PropertyQosPolicy& policy,
					    const char *name,const char *value,
					    DDS_Boolean propagate);
    /*e \dref_PropertyQosPolicyHelper_add_property
    */
    static DDS_ReturnCode_t add_property(DDS_PropertyQosPolicy& policy,
					const char *name,const char *value,
					DDS_Boolean propagate);

    /*e \dref_PropertyQosPolicyHelper_assert_pointer_property
    */
    static DDS_ReturnCode_t assert_pointer_property(
            DDS_PropertyQosPolicy& policy,
            const char *name,
            const void *pointer);

    /*e \dref_PropertyQosPolicyHelper_add_pointer_property
    */
    static DDS_ReturnCode_t add_pointer_property(
            DDS_PropertyQosPolicy& policy,
            const char *name,
            const void *pointer);

    /*e \dref_PropertyQosPolicyHelper_lookup_property
    */
    static struct DDS_Property_t* lookup_property(DDS_PropertyQosPolicy& policy,
						const char *name);
    /*e \dref_PropertyQosPolicyHelper_remove_property
    */
    static DDS_ReturnCode_t remove_property(DDS_PropertyQosPolicy& policy,
					const char *name);
    /*e \dref_PropertyQosPolicyHelper_get_properties
    */
    static DDS_ReturnCode_t get_properties(DDS_PropertyQosPolicy& policy,
					struct DDS_PropertySeq& properties,
					const char *name_prefix);
};



#if defined(RTI_WIN32) || defined(RTI_WINCE)
#undef DDSCDllExport
#define DDSCDllExport DDSCPPDllExport
#endif

DDS_SEQUENCE(DDS_StdStringSeq, std::string);

#if defined(RTI_WIN32) || defined(RTI_WINCE)
#undef DDSCDllExport
#define DDSCDllExport
#endif


 
typedef DDS_ThreadFactory_OnSpawnedFunction DDSThreadFactory_OnSpawnedFunction;

class DDSCPPDllExport DDSThreadFactory {
  
public:
    
    /*e \dref_ThreadFactory_create_thread
     */
    virtual void* create_thread(
            const char * thread_name,
            const struct DDS_ThreadSettings_t & settings,
            DDSThreadFactory_OnSpawnedFunction on_spawned,
            void * thread_param) = 0;
    
    /*e \dref_ThreadFactory_delete_thread
     */
    virtual void delete_thread(void * thread) = 0;
    
    virtual ~DDSThreadFactory() {};
};

#endif /* dds_cpp_infrastructure_h */
