
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Message.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef Message_793628338_h
#define Message_793628338_h

#include "MessageC.h"


#ifdef __cplusplus
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#endif


        
extern const char *DateTimeTYPENAME;



#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DateTime_get_typecode(); /* Type code */
    
DDS_SEQUENCE(DateTimeSeq, DateTime);


NDDSUSERDllExport 
RTIBool DateTime_initialize(
        DateTime* self);

NDDSUSERDllExport 
RTIBool DateTime_initialize_ex(
        DateTime* self,RTIBool allocatePointers,RTIBool allocateMemory);
        
NDDSUSERDllExport
RTIBool DateTime_initialize_w_params(
        DateTime* self,
        const struct DDS_TypeAllocationParams_t * allocParams);

NDDSUSERDllExport 
void DateTime_finalize(
        DateTime* self);

NDDSUSERDllExport 
void DateTime_finalize_ex(
        DateTime* self,RTIBool deletePointers);
        
NDDSUSERDllExport
void DateTime_finalize_w_params(
        DateTime* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport 
RTIBool DateTime_copy(
        DateTime* dst,
        const DateTime* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *MessageTextTYPENAME;



#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* MessageText_get_typecode(); /* Type code */
    

NDDSUSERDllExport 
RTIBool MessageText_initialize(
        MessageText* self);

NDDSUSERDllExport 
RTIBool MessageText_initialize_ex(
        MessageText* self,RTIBool allocatePointers,RTIBool allocateMemory);
        
NDDSUSERDllExport
RTIBool MessageText_initialize_w_params(
        MessageText* self,
        const struct DDS_TypeAllocationParams_t * allocParams);

NDDSUSERDllExport 
void MessageText_finalize(
        MessageText* self);

NDDSUSERDllExport 
void MessageText_finalize_ex(
        MessageText* self,RTIBool deletePointers);
        
NDDSUSERDllExport
void MessageText_finalize_w_params(
        MessageText* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport 
RTIBool MessageText_copy(
        MessageText* dst,
        const MessageText* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *MessageTYPENAME;



#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols. */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* Message_get_typecode(); /* Type code */
    
DDS_SEQUENCE(MessageSeq, Message);


NDDSUSERDllExport 
RTIBool Message_initialize(
        Message* self);

NDDSUSERDllExport 
RTIBool Message_initialize_ex(
        Message* self,RTIBool allocatePointers,RTIBool allocateMemory);
        
NDDSUSERDllExport
RTIBool Message_initialize_w_params(
        Message* self,
        const struct DDS_TypeAllocationParams_t * allocParams);

NDDSUSERDllExport 
void Message_finalize(
        Message* self);

NDDSUSERDllExport 
void Message_finalize_ex(
        Message* self,RTIBool deletePointers);
        
NDDSUSERDllExport
void Message_finalize_w_params(
        Message* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport 
RTIBool Message_copy(
        Message* dst,
        const Message* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* Message_793628338_h */
