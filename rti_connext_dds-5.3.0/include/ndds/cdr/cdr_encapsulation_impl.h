/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)cdr_encapsulation_impl.h    generated by: makeheader    Thu Jun 22 14:17:12 2017
 *
 *		built from:	encapsulation_impl.ifc
 */

#ifndef cdr_encapsulation_impl_h
#define cdr_encapsulation_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#define RTICdrEncapsulation_validEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE || \
 (_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE || \
 (_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE || \
 (_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE)?RTI_TRUE:RTI_FALSE)

#define RTICdrEncapsulation_validCdrEncapsulation(_id, _opts, _sopts) \
((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE || \
(_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE)

#define RTICdrEncapsulation_validParameterCdrEncapsulation(_id, _opts, _sopts) \
((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE || \
(_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE)
 
/* ----------------------------------------------------------------- */
/* Extensible types definitions                                      */
/* ----------------------------------------------------------------- */

#define RTICdrParameterId_stripOutFlags(pId) \
    (*(pId)) = ((*(pId)) & 0x3FFF)

#define RTICdrLongParameterId_stripOutFlags(pId) \
    (*(pId)) = ((*(pId)) & 0x0FFFFFFF)



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* cdr_encapsulation_impl_h */
