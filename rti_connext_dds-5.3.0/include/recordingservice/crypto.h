/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/******************************************************************************
 * $Id$
 *
 * (c) Copyright, Real-Time Innovations, Copyright 2007
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 *
 * Author: juan@rti.com
 *
 *****************************************************************************/
#ifndef crypto_h
#define crypto_h

#include "dds_c/dds_c_common.h"


typedef struct RTIRecorder_CryptoProvider RTIRecorder_CryptoProvider;

/**
 * This method is used by Recorder to obtain the master key for this recording
 * session.
 */
typedef DDS_Boolean (*CryptoProvider_obtainMasterKeyMethod)(
        RTIRecorder_CryptoProvider * self);

/**
 * This method is used by Recorder to get a copy of the master key, after it has
 * been obtained. The out octet buffer parameter must be cleared up after the
 * key has been used.
 */
typedef DDS_Boolean (*CryptoProvider_getMasterKeyMethod)(
        RTIRecorder_CryptoProvider * self, DDS_Octet * keyOut);

/**
 * Obtain a session key for the creation of the table named 'tableName'.
 */
typedef DDS_Boolean (*CryptoProvider_generateKeyForTableMethod)(
        RTIRecorder_CryptoProvider * self, const char * tableName,
        DDS_Octet * keyOut);

/* Length of the master key in bytes (32 bytes - 256 bits) */
#define RTIRecorder_CryptoProvider_MASTERKEY_SIZE 32
/* Length of the master key in bytes (16 bytes - 128 bits) */
#define RTIRecorder_CryptoProvider_TABLEKEY_SIZE 16

/* AES-GCM: length of authentication tag */
#define AES_GCM_TAG_LENGTH 16
/* Block size in GCM is 128 bits */
#define AES_GCM_CIPHER_BLOCK_SIZE 16
/* Default IV (initialization vector) for GCM implementations is 12 bytes */
#define AES_GCM_DEFAULT_IV_LENGTH 12

/**
 * Interface for obtaining cryptographic material for the current recording
 * session.
 */
struct RTIRecorder_CryptoProvider {
    /**
     * The ID of the crypto provider. This will be used by Recording Service to
     * distinguish between different implementations of the built-in
     * cryptography providers.
     */
    int id;
    /**
     * The method to obtain the master key.
     */
    CryptoProvider_obtainMasterKeyMethod obtainMasterKey;
    /**
     * The method to get a copy of the master key once it has been obtained.
     */
    CryptoProvider_getMasterKeyMethod getMasterKey;
    /**
     * The method to generate a key for a table.
     */
    CryptoProvider_generateKeyForTableMethod generateKeyForTable;
};

/**
 * Interface for methods that create CryptoProvider instances.
 */
typedef RTIRecorder_CryptoProvider * (*RTIRecorder_CryptoProvider_newMethod)();

/**
 * Interface for methods that delete CryptoProvider instances.
 */
typedef void (*RTIRecorder_CryptoProvider_deleteMethod)(
        RTIRecorder_CryptoProvider * self);

typedef struct RTIRecorder_CryptoProviderFactory {
    RTIRecorder_CryptoProvider_newMethod cryptoProviderNewMethod;
    RTIRecorder_CryptoProvider_deleteMethod cryptoProviderDeleteMethod;
    void * libraryHandle;
} RTIRecorder_CryptoProviderFactory;


#endif

/* End of file $Id$ */

