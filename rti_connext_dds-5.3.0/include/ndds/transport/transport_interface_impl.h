/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_interface_impl.h    generated by: makeheader    Thu Jun 22 14:17:14 2017
 *
 *		built from:	interface_impl.ifc
 */

#ifndef transport_interface_impl_h
#define transport_interface_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#define NDDS_Transport_Plugin_is_valid(transport)  \
    ((transport)                             != NULL && \
     (transport)->property                   != NULL && \
     (transport)->send                       != NULL && \
     (transport)->receive_rEA                != NULL && \
     (transport)->unblock_receive_rrEA       != NULL && \
     (transport)->create_recvresource_rrEA   != NULL && \
     (transport)->destroy_recvresource_rrEA  != NULL && \
     (transport)->share_recvresource_rrEA    != NULL && \
     (transport)->unshare_recvresource_rrEA  != NULL && \
     (transport)->create_sendresource_srEA   != NULL && \
     (transport)->destroy_sendresource_srEA  != NULL && \
     (transport)->share_sendresource_srEA    != NULL && \
     (transport)->unshare_sendresource_srEA  != NULL && \
     (transport)->get_class_name_cEA         != NULL && \
     (transport)->string_to_address_cEA      != NULL && \
     (transport)->get_receive_interfaces_cEA != NULL && \
     (transport)->register_listener_cEA      != NULL && \
     (transport)->delete_cEA                 != NULL \
   )

#define NDDS_Transport_Plugin_initialize( \
     self, \
     property_in, \
     send_in, \
     receive_rEA_in, \
     return_loaned_buffer_rEA_in, \
     unblock_receive_rrEA_in, \
     create_recvresource_rrEA_in, \
     destroy_recvresource_rrEA_in, \
     share_recvresource_rrEA_in, \
     unshare_recvresource_rrEA_in, \
     create_sendresource_srEA_in, \
     destroy_sendresource_srEA_in, \
     share_sendresource_srEA_in, \
     unshare_sendresource_srEA_in, \
     get_class_name_cEA_in, \
     string_to_address_cEA_in, \
     get_receive_interfaces_cEA_in, \
     register_listener_cEA_in, \
     delete_cEA_in) \
    (self)->property = property_in;       \
    (self)->send = send_in;      \
    (self)->receive_rEA = receive_rEA_in; \
    (self)->return_loaned_buffer_rEA = return_loaned_buffer_rEA_in; \
    (self)->unblock_receive_rrEA  = unblock_receive_rrEA_in; \
    (self)->create_recvresource_rrEA = create_recvresource_rrEA_in; \
    (self)->destroy_recvresource_rrEA = destroy_recvresource_rrEA_in; \
    (self)->share_recvresource_rrEA = share_recvresource_rrEA_in; \
    (self)->unshare_recvresource_rrEA = unshare_recvresource_rrEA_in; \
    (self)->create_sendresource_srEA = create_sendresource_srEA_in; \
    (self)->destroy_sendresource_srEA = destroy_sendresource_srEA_in; \
    (self)->share_sendresource_srEA = share_sendresource_srEA_in; \
    (self)->unshare_sendresource_srEA = unshare_sendresource_srEA_in; \
    (self)->get_class_name_cEA = get_class_name_cEA_in; \
    (self)->string_to_address_cEA = string_to_address_cEA_in; \
    (self)->get_receive_interfaces_cEA = get_receive_interfaces_cEA_in; \
    (self)->register_listener_cEA = register_listener_cEA_in; \
    (self)->delete_cEA = delete_cEA_in; 
    
        
#define NDDS_Transport_Plugin_get_classid(xport)    \
     (xport)->property->classid
     
#define NDDS_Transport_Plugin_is_polled(xport) \
    (((xport)->property->properties_bitmap & NDDS_TRANSPORT_PROPERTY_BIT_POLLED) != 0)

#define NDDS_Transport_Plugin_is_blocking !NDDS_Transport_Plugin_is_polled

#define NDDS_Transport_Plugin_get_message_size_max(xport) \
    (xport)->property->message_size_max

#define NDDS_Transport_Plugin_get_class_id(xport) \
    (xport)->property->classid



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_interface_impl_h */
