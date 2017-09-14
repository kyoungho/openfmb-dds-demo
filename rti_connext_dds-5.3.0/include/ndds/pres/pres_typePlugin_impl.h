/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_typePlugin_impl.h    generated by: makeheader    Thu Jun 22 14:17:31 2017
 *
 *		built from:	typePlugin_impl.ifc
 */

#ifndef pres_typePlugin_impl_h
#define pres_typePlugin_impl_h


#ifdef __cplusplus
    extern "C" {
#endif

/*i \dref_PROPERTY_VALUE_MAX_LENGTH
 */
#define PRES_TYPE_PLUGIN_PROPERTY_VALUE_MAX_STATIC_LENGTH 512

/*i \dref_MAX_BUILTIN_TYPES
 */
#define PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES 4

/* builtin type names.
   note: This names must be consistent with the Java values. If you modify
         these values you have to modify Java ones.
*/
#define PRES_TYPE_PLUGIN_BUILTIN_TYPE_STRING_TYPE_NAME "DDS::String"
#define PRES_TYPE_PLUGIN_BUILTIN_TYPE_OCTETS_TYPE_NAME "DDS::Octets"
#define PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_STRING_TYPE_NAME "DDS::KeyedString"
#define PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_OCTETS_TYPE_NAME "DDS::KeyedOctets"

typedef struct PRESTypePluginBuiltinTypeInfo {
    const char * typeName;
    const char * maxSizeProperty;
    const char * allocSizeProperty;
    const char * maxKeySizeProperty;
    const char * allocKeySizeProperty;
    int maxSizeDefaultValue;
    int maxKeySizeDefaultValue;
}PRESTypePluginBuiltinTypeInfo;

 extern PRESDllVariable const 
PRESTypePluginBuiltinTypeInfo PRES_TYPE_PLUGIN_BUILTIN_TYPE_INFO [PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES];


/*i \dref_TypePluginBuiltinTypeKind
 */

typedef enum PRESTypePluginBuiltinTypeKind{
    PRES_TYPE_PLUGIN_BUILTIN_TYPE_STRING_KIND = 0,
    PRES_TYPE_PLUGIN_BUILTIN_TYPE_OCTETS_KIND = 1,
    PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_STRING_KIND = 2,
    PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_OCTETS_KIND = 3
} PRESTypePluginBuiltinTypeKind;


/*i \dref_TypePluginDefaultParticipantBuiltinTypeConfigData
 */

struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData {
    int _maxSize [PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES];
    int _maxKeySize [PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES];
    int _allocSize [PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES];
    int _allocKeySize [PRES_TYPE_PLUGIN_MAX_BUILTIN_TYPES];
    struct RTICdrTypeCode * typeCode;
};


/*i \dref_TypePluginDefaultEndpointBuiltinTypeConfigData
 */

struct PRESTypePluginDefaultEndpointBuiltinTypeConfigData {
    int _allocSize;
    int _allocKeySize;
    int _maxSize;
    int _maxKeySize;
};



#define PRES_TYPE_PLUGIN_ACCEPT_UNKNOWN_ENUM_VALUE "dds.sample_assignability.accept_unknown_enum_value"
#define PRES_TYPE_PLUGIN_ACCEPT_UNKNOWN_UNION_DISCRIMINATOR "dds.sample_assignability.accept_unknown_union_discriminator"

/* The following property is used mostly for test purposes and it will force
 * the calculation of the keyhash using MD5 independently of the size of the
 * serialized key.
 */
#define PRES_TYPE_PLUGIN_FORCE_MD5_KEYHASH "dds.type_plugin.force_md5_keyhash"



typedef unsigned int (*PRESTypePluginGetEncodedSerializedSampleSizeFnc)(
    void *participant,
    unsigned int serializedSampleSize);



struct PRESTypePluginDefaultParticipantData {
    struct REDAFastBufferPool * _pool;    
    int                         _writerBufferDynamicMaxSize; /* -1=not set, 0=unlimited */
    int                         _writerBufferDynamicCurrSize;/* Current size */
    int                         _batchingEnabled;            /* -1=not set, 1=batch enabled, 0=batch disabled */
    RTIBool                     _odbcWriterHistory;          /* Indicates whether or not the participant writers will use by default ODBC WH */
    int                         _odbcInitCacheSize;          /* Initial cache size for ODBC writer history: -1 if not set */
    void* userData;
    void *_dotnetPluginData;  /* used by dotnet api */
    struct PRESTypePluginSampleAssignabilityProperty _assignabilityProperty;

    /* Security related fields */
    void *_participant;
    PRESTypePluginGetEncodedSerializedSampleSizeFnc
            _getEncodedSerializedSampleSize;
};




struct PRESTypePluginDefaultEndpointData {
    struct PRESTypePluginPool * _pool;
    struct RTICdrStream _md5Stream;
    void * _sample;
    unsigned int _maxSizeSerializedKey;
    unsigned int _maxSizeSerializedSample;
    /* 
     * This member is used to fix CODEGEN-796 and CODEGENII-479 in which the
     * get_serialized_sample_size type plugin function may not return the right
     * value
     */
    unsigned int _baseAlignment;
    struct PRESTypePluginDefaultParticipantData *_participantData;
    struct PRESTypePluginSampleAssignabilityProperty _assignabilityProperty;
    void* userData;
    void *_dotnetPluginData;  /* used by dotnet api */

    /* When set to RTI_TRUE the keyhash calculated by the to_keyhash TypePlugin
     * function will always be based on applying MD5 to the serialized key.
     *
     * This value is set to true for DataWriters and DataReaders where
     * <topic_rule>/<data_protection_kind> is set to ENCRYPT in the
     * corresponding governance file.
     *
     * For testing purposes, this property can also be set to true when setting
     * the property dds.type_plugin.force_md5_keyhash to "true"
     */
    RTIBool _forceMD5KeyHash;
};


#define PRESTypePluginDefaultEndpointData_getMD5Stream(epd) \
    &((struct PRESTypePluginDefaultEndpointData *)epd)->_md5Stream

#define PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(epd) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_maxSizeSerializedKey
        
#define PRESTypePluginDefaultEndpointData_getMaxSizeSerializedSample(epd) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_maxSizeSerializedSample

#define PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, maxSizeSerializedSample) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_maxSizeSerializedSample = maxSizeSerializedSample

#define PRESTypePluginDefaultEndpointData_getTempSample(epd) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_sample

#define PRESTypePluginDefaultEndpointData_getPool(epd) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_pool

#define PRESTypePluginDefaultEndpointData_getAssignabilityProperty(epd) \
    &((const struct PRESTypePluginDefaultEndpointData *)epd)->_assignabilityProperty

#define PRESTypePluginDefaultEndpointData_forceMD5KeyHash(epd) \
    ((const struct PRESTypePluginDefaultEndpointData *)epd)->_forceMD5KeyHash

#define PRESTypePluginDefaultEndpointData_setAssignabilityProperty(epd, ap) \
    ((struct PRESTypePluginDefaultEndpointData *)epd)->_assignabilityProperty = *(ap)

#define PRESTypePluginDefaultEndpointData_getAlignment(epd, currentSize) \
    ((currentSize)-((struct PRESTypePluginDefaultEndpointData *) epd)->_baseAlignment)

#define PRESTypePluginDefaultEndpointData_setBaseAlignment(epd, alignment) \
    (((struct PRESTypePluginDefaultEndpointData *) epd)->_baseAlignment = (alignment))

#define PRESTypePluginDefaultParticipantBuiltinTypeConfigData_getMaxSize(btd,kind) \
    ((struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData *)btd)->_maxSize[kind]

#define PRESTypePluginDefaultParticipantBuiltinTypeConfigData_getMaxKeySize(btd,kind) \
    ((struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData *)btd)->_maxKeySize[kind]

#define PRESTypePluginDefaultParticipantBuiltinTypeConfigData_getAllocSize(btd,kind) \
    ((struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData *)btd)->_allocSize[kind]

#define PRESTypePluginDefaultParticipantBuiltinTypeConfigData_getAllocKeySize(btd,kind) \
    ((struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData *)btd)->_allocKeySize[kind]

#define PRESTypePluginDefaultEndpointBuiltinTypeConfigData_getAllocSize(btd) \
    ((struct PRESTypePluginDefaultEndpointBuiltinTypeConfigData *)btd)->_allocSize

#define PRESTypePluginDefaultEndpointBuiltinTypeConfigData_getAllocKeySize(btd) \
    ((struct PRESTypePluginDefaultEndpointBuiltinTypeConfigData *)btd)->_allocKeySize

#define PRESTypePluginBuiltinType_isKeyedType(kind) \
    ((kind == PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_STRING_KIND) || \
    (kind == PRES_TYPE_PLUGIN_BUILTIN_TYPE_KEYED_OCTETS_KIND))

extern PRESDllExport RTIBool
PRESTypePluginDefaultEndpointBuiltinTypeConfigData_initialize (
    struct PRESTypePluginDefaultEndpointBuiltinTypeConfigData * builtinTypeData,
    struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData * participantBuiltinTypeData,
    const struct PRESTypePluginEndpointInfo *endpointInfo,
    const PRESTypePluginBuiltinTypeKind builtinTypeKind);


extern PRESDllExport RTIBool
PRESTypePluginDefaultParticipantBuiltinTypeConfigData_initialize (
    struct PRESTypePluginDefaultParticipantBuiltinTypeConfigData * participantBuiltinTypeData,
    const struct PRESTypePluginParticipantInfo *participantInfo,
    const PRESTypePluginBuiltinTypeKind builtinTypeKind);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pres_typePlugin_impl_h */
