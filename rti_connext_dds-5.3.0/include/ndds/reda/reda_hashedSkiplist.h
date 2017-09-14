/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_hashedSkiplist.h    generated by: makeheader    Thu Jun 22 14:17:00 2017
 *
 *		built from:	hashedSkiplist.ifc
 */

#ifndef reda_hashedSkiplist_h
#define reda_hashedSkiplist_h


  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef reda_hash_h
    #include "reda/reda_hash.h"
  #endif
  #ifndef reda_skiplist_h
    #include "reda/reda_skiplist.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAHashedSkiplist; /* forward declare to appease compiler */

extern REDADllExport void 
REDAHashedSkiplist_deleteNode(const struct REDAHashedSkiplist *self,
		              struct REDASkiplistNode *node);

extern REDADllExport void 
REDAHashedSkiplist_delete(struct REDAHashedSkiplist *self);


  #define REDA_HASHED_SKIPLIST_BUCKET_COUNT_MIN (4)

extern REDADllExport struct REDAHashedSkiplist *
REDAHashedSkiplist_new(const struct REDASkiplistDescription *desc,
                       REDAOrderedDataTypeCompareFunction cmp,
                       const struct REDAHashDefinition *hashDefinition);

extern REDADllExport void
REDAHashedSkiplist_gotoTopNode(const struct REDAHashedSkiplist *self,
                               const struct REDASkiplistNode **node);

extern REDADllExport RTIBool
REDAHashedSkiplist_gotoNextNode(struct REDAHashedSkiplist *self,
                                const struct REDASkiplistNode **node);

extern REDADllExport int 
REDAHashedSkiplist_getNodeCount(const struct REDAHashedSkiplist *self);

extern REDADllExport 
void 
REDAHashedSkiplist_findNode(const struct REDAHashedSkiplist *self,
                            const struct REDASkiplistNode **answer,
                            RTIBool *preciseMatch,	
                            void *searchUserData);

extern REDADllExport const struct REDASkiplistNode *
REDAHashedSkiplist_assertNodeEA(struct REDAHashedSkiplist *self, 
                                RTIBool *alreadyExists, 
                                void *userData, char userChar);

extern REDADllExport const struct REDASkiplistNode *
REDAHashedSkiplist_removeNodeEA(struct REDAHashedSkiplist *self, 
                                void *searchUserData);

extern REDADllExport 
void REDAHashedSkiplist_clearEA(struct REDAHashedSkiplist *self);


struct REDAHashedSkiplistInfo {
    void*  hashedSkiplistId;
    int    nodeCount;
    int    hashBucketCount;
    struct REDASkiplistInfo **hashBucketInfo;
    int    memoryConsumption;
};

extern REDADllExport struct REDAHashedSkiplistInfo *
REDAHashedSkiplistInfo_new(struct REDAHashedSkiplist *hashedSkiplist);

extern REDADllExport void
REDAHashedSkiplistInfo_delete(struct REDAHashedSkiplistInfo *info);

extern REDADllExport void
REDAHashedSkiplistInfo_print(struct REDAHashedSkiplistInfo *info,
    int indent, int verbosity);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
  #include "reda/reda_hashedSkiplist_impl.h"

#endif /* reda_hashedSkiplist_h */
