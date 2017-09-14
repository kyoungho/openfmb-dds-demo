/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)ndds_transport_cpp.h    generated by: makeheader    Thu Jun 22 14:17:54 2017
 *
 *		built from:	ndds_transport_cpp.ifcxx
 */

#ifndef ndds_transport_cpp_h
#define ndds_transport_cpp_h


#ifndef dds_cpp_dll_h
  #include "dds_cpp/dds_cpp_dll.h"
#endif
#ifndef ndds_transport_c_h
  #include "ndds/ndds_transport_c.h"
#endif
#ifndef dds_cpp_domain_h
  #include "dds_cpp/dds_cpp_domain.h"
#endif

class DDSCPPDllExport NDDSTransportSupport {
  public:
    /*e \dref_Transport_Support_register_transport */
    static NDDS_Transport_Handle_t register_transport(
                   DDSDomainParticipant* participant_in,
                   NDDS_Transport_Plugin* transport_in,
                   const DDS_StringSeq& aliases_in,
                   const NDDS_Transport_Address_t& network_address_in);

    /*e \dref_Transport_Support_lookup_transport */
    static NDDS_Transport_Handle_t lookup_transport(
                   DDSDomainParticipant* participant_in,
		   DDS_StringSeq& aliases_out,
		   NDDS_Transport_Address_t& network_address_out,
                   NDDS_Transport_Plugin* transport_in);
            
    /*e \dref_Transport_Support_add_send_route */                   
    static DDS_ReturnCode_t add_send_route(
               const NDDS_Transport_Handle_t& transport_handle_in,
               const NDDS_Transport_Address_t& address_range_in,
               DDS_Long address_range_bit_count_in);
               
    /*e \dref_Transport_Support_add_receive_route */                   
    static DDS_ReturnCode_t add_receive_route(
                  const NDDS_Transport_Handle_t& transport_handle_in,
                  const NDDS_Transport_Address_t& address_range_in,
                  DDS_Long address_range_bit_count_in);     
                  
    /*e \dref_Transport_Support_get_builtin_transport_property */
    static DDS_ReturnCode_t get_builtin_transport_property(
           DDSDomainParticipant* participant_in,
           DDS_TransportBuiltinKind builtin_transport_kind_in,
           struct NDDS_Transport_Property_t& builtin_transport_property_inout);
           
    /*e \dref_Transport_Support_set_builtin_transport_property */
    static DDS_ReturnCode_t set_builtin_transport_property(
        DDSDomainParticipant* participant_in,
        DDS_TransportBuiltinKind builtin_transport_kind_in,
        const struct NDDS_Transport_Property_t& builtin_transport_property_in); 
    
    /*e \dref_Transport_Support_get_transport_plugin */
    static NDDS_Transport_Plugin* get_transport_plugin(
           DDSDomainParticipant* participant_in,
           const char* alias_in);                                                                
};

#endif /* ndds_transport_cpp_h */
