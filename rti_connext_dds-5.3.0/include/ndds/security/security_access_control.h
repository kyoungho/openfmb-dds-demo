/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)security_access_control.h    generated by: makeheader    Thu Jun 22 14:19:32 2017
 *
 *		built from:	access_control.ifc
 */

#ifndef security_access_control_h
#define security_access_control_h


#ifndef security_dll_h
  #include "security/security_dll.h"
#endif
#ifndef dds_c_trustPlugins_h
  #include "dds_c/dds_c_trust_plugins.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define RTI_SECURITY_ACCESS_CONTROL_PROPERTY_PREFIX "access_control."
#define RTI_SECURITY_PERMISSIONS_AUTHORITY_FILE_PROPERTY \
    RTI_SECURITY_ACCESS_CONTROL_PROPERTY_PREFIX "permissions_authority_file"
#define RTI_SECURITY_ALTERNATIVE_PERMISSIONS_AUTHORITY_FILES_PROPERTY \
    RTI_SECURITY_ACCESS_CONTROL_PROPERTY_PREFIX "alternative_permissions_authority_files"
#define RTI_SECURITY_PERMISSIONS_FILE_PROPERTY \
    RTI_SECURITY_ACCESS_CONTROL_PROPERTY_PREFIX "permissions_file"
#define RTI_SECURITY_GOVERNANCE_FILE_PROPERTY \
    RTI_SECURITY_ACCESS_CONTROL_PROPERTY_PREFIX "governance_file"


typedef DDS_ProtectionKind RTI_Security_ProtectionKind;


#define RTI_SECURITY_NONE_PROTECTION_KIND DDS_NONE_PROTECTION_KIND
#define RTI_SECURITY_SIGN_PROTECTION_KIND DDS_SIGN_PROTECTION_KIND
#define RTI_SECURITY_ENCRYPT_PROTECTION_KIND DDS_TRANSFORM_PROTECTION_KIND


#ifdef __cplusplus
}    /* extern "C" */
#endif

#endif /* security_access_control_h */