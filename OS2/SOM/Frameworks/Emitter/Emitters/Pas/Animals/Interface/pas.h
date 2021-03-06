
/*
 * This file was generated by the SOM Compiler.
 * FileName: pas.h.
 * Generated using:
 *     SOM Precompiler somipc: 2.29.1.17
 *     SOM Emitter emith: 2.47
 */

/*
 *         File:    Pascal.idl
 *       Author:    SOMObjects Emitter Framework
 *     Contents:    Generic framework logic class for Pascal.
 *         Date:    Tue Sep 21 20:16:43 2004.
 */


#ifndef SOM_PascalEmitter_h
#define SOM_PascalEmitter_h


#include <som.h>

/*
 * -- This emitter treats Method Tokens as Thunks by default.
 * -- Use the sc modifier "nothunks" to change this default
 */
#undef somresolve_
#define somresolve_(obj,mToken) ((somMethodProc*)((void)obj, mToken))

/*
 * Define the class name as an object type
 */
#ifndef PascalEmitter
#define PascalEmitter SOMObject
#endif
#include <scemit.h>

/*
 * Start of bindings for IDL types
 */

#ifndef SOMClass
    #define SOMClass SOMObject
#endif /* SOMClass */
#ifndef SOMStringTableC
    #define SOMStringTableC SOMObject
#endif /* SOMStringTableC */
#ifndef SOMTEntryC
    #define SOMTEntryC SOMObject
#endif /* SOMTEntryC */
#ifndef SOMTEmitC
    #define SOMTEmitC SOMObject
#endif /* SOMTEmitC */
#ifndef SOMTMetaClassEntryC
    #define SOMTMetaClassEntryC SOMObject
#endif /* SOMTMetaClassEntryC */
#ifndef SOMTAttributeEntryC
    #define SOMTAttributeEntryC SOMObject
#endif /* SOMTAttributeEntryC */
#ifndef SOMTTypedefEntryC
    #define SOMTTypedefEntryC SOMObject
#endif /* SOMTTypedefEntryC */
#ifndef SOMTBaseClassEntryC
    #define SOMTBaseClassEntryC SOMObject
#endif /* SOMTBaseClassEntryC */
#ifndef SOMTPassthruEntryC
    #define SOMTPassthruEntryC SOMObject
#endif /* SOMTPassthruEntryC */
#ifndef SOMTDataEntryC
    #define SOMTDataEntryC SOMObject
#endif /* SOMTDataEntryC */
#ifndef SOMTMethodEntryC
    #define SOMTMethodEntryC SOMObject
#endif /* SOMTMethodEntryC */
#ifndef SOMTClassEntryC
    #define SOMTClassEntryC SOMObject
#endif /* SOMTClassEntryC */
#ifndef SOMTModuleEntryC
    #define SOMTModuleEntryC SOMObject
#endif /* SOMTModuleEntryC */
#ifndef SOMTParameterEntryC
    #define SOMTParameterEntryC SOMObject
#endif /* SOMTParameterEntryC */
#ifndef SOMTStructEntryC
    #define SOMTStructEntryC SOMObject
#endif /* SOMTStructEntryC */
#ifndef SOMTUnionEntryC
    #define SOMTUnionEntryC SOMObject
#endif /* SOMTUnionEntryC */
#ifndef SOMTEnumEntryC
    #define SOMTEnumEntryC SOMObject
#endif /* SOMTEnumEntryC */
#ifndef SOMTConstEntryC
    #define SOMTConstEntryC SOMObject
#endif /* SOMTConstEntryC */
#ifndef SOMTSequenceEntryC
    #define SOMTSequenceEntryC SOMObject
#endif /* SOMTSequenceEntryC */
#ifndef SOMTStringEntryC
    #define SOMTStringEntryC SOMObject
#endif /* SOMTStringEntryC */
#ifndef SOMTEnumNameEntryC
    #define SOMTEnumNameEntryC SOMObject
#endif /* SOMTEnumNameEntryC */
#ifndef SOMTCommonEntryC
    #define SOMTCommonEntryC SOMObject
#endif /* SOMTCommonEntryC */
#ifndef SOMTUserDefinedTypeEntryC
    #define SOMTUserDefinedTypeEntryC SOMObject
#endif /* SOMTUserDefinedTypeEntryC */
#define PascalEmitter_dtTypedef 1 /* 0x0001 */
#define PascalEmitter_dtStruct 2 /* 0x0002 */
#define PascalEmitter_dtUnion 3 /* 0x0003 */
#define PascalEmitter_dtSequence 4 /* 0x0004 */
#define PascalEmitter_dtPTypedef 5 /* 0x0005 */
#define PascalEmitter_dtEnum 6 /* 0x0006 */
#define PascalEmitter_dtClass 7 /* 0x0007 */
#define PascalEmitter_dtTypeMask 15 /* 0x000F */
#define PascalEmitter_dtFunction 16 /* 0x0010 */
#define PascalEmitter_dtProcedure 32 /* 0x0020 */
#define PascalEmitter_dtMethodMask 240 /* 0x00F0 */
#define PascalEmitter_dtConst 256 /* 0x0100 */
#define PascalEmitter_dtAttrib 512 /* 0x0200 */
typedef
struct PascalEmitter_struct_LinkItem {
SOMTEntryC* Obj;
char * FieldName;
long  PtrDeep;
long  ArrayDim;
long  ArrayLen[32];
void*  TypeItem;
/*
 *  PTYPEITEM
 */

long  MethodParamClassFl;
char * MethodParamClassName;
} PascalEmitter_struct_LinkItem;
typedef
struct PascalEmitter_struct_LinkItem PascalEmitter_LINKITEM;
typedef
struct PascalEmitter_struct_LinkItem* PascalEmitter_PLINKITEM;
#ifndef _IDL_SEQUENCE_PascalEmitter_PLINKITEM_defined
#define _IDL_SEQUENCE_PascalEmitter_PLINKITEM_defined
typedef struct {
    unsigned long _maximum;
    unsigned long _length;
    PascalEmitter_PLINKITEM *_buffer;
} _IDL_SEQUENCE_PascalEmitter_PLINKITEM;
#endif /* _IDL_SEQUENCE_PascalEmitter_PLINKITEM_defined */ 
typedef
struct PascalEmitter_struct_TypeItem {
long  DefType;
SOMTEntryC* Obj;
long  PtrFlag;
char * Name;
char * Comment;
long  BindCount;
_IDL_SEQUENCE_PascalEmitter_PLINKITEM LinkItems;
} PascalEmitter_struct_TypeItem;
typedef
struct PascalEmitter_struct_TypeItem PascalEmitter_TYPEITEM;
typedef
struct PascalEmitter_struct_TypeItem* PascalEmitter_PTYPEITEM;
#ifndef _IDL_SEQUENCE_PascalEmitter_PTYPEITEM_defined
#define _IDL_SEQUENCE_PascalEmitter_PTYPEITEM_defined
typedef struct {
    unsigned long _maximum;
    unsigned long _length;
    PascalEmitter_PTYPEITEM *_buffer;
} _IDL_SEQUENCE_PascalEmitter_PTYPEITEM;
#endif /* _IDL_SEQUENCE_PascalEmitter_PTYPEITEM_defined */ 

#ifndef SOM_DONT_USE_SHORT_NAMES
#ifndef SOMTGD_dtTypedef
    #ifdef dtTypedef
        #undef dtTypedef
        #define SOMTGD_dtTypedef 1
    #else
        #define dtTypedef PascalEmitter_dtTypedef
    #endif /* dtTypedef */
#endif /* SOMTGD_dtTypedef */
#ifndef SOMTGD_dtStruct
    #ifdef dtStruct
        #undef dtStruct
        #define SOMTGD_dtStruct 1
    #else
        #define dtStruct PascalEmitter_dtStruct
    #endif /* dtStruct */
#endif /* SOMTGD_dtStruct */
#ifndef SOMTGD_dtUnion
    #ifdef dtUnion
        #undef dtUnion
        #define SOMTGD_dtUnion 1
    #else
        #define dtUnion PascalEmitter_dtUnion
    #endif /* dtUnion */
#endif /* SOMTGD_dtUnion */
#ifndef SOMTGD_dtSequence
    #ifdef dtSequence
        #undef dtSequence
        #define SOMTGD_dtSequence 1
    #else
        #define dtSequence PascalEmitter_dtSequence
    #endif /* dtSequence */
#endif /* SOMTGD_dtSequence */
#ifndef SOMTGD_dtPTypedef
    #ifdef dtPTypedef
        #undef dtPTypedef
        #define SOMTGD_dtPTypedef 1
    #else
        #define dtPTypedef PascalEmitter_dtPTypedef
    #endif /* dtPTypedef */
#endif /* SOMTGD_dtPTypedef */
#ifndef SOMTGD_dtEnum
    #ifdef dtEnum
        #undef dtEnum
        #define SOMTGD_dtEnum 1
    #else
        #define dtEnum PascalEmitter_dtEnum
    #endif /* dtEnum */
#endif /* SOMTGD_dtEnum */
#ifndef SOMTGD_dtClass
    #ifdef dtClass
        #undef dtClass
        #define SOMTGD_dtClass 1
    #else
        #define dtClass PascalEmitter_dtClass
    #endif /* dtClass */
#endif /* SOMTGD_dtClass */
#ifndef SOMTGD_dtTypeMask
    #ifdef dtTypeMask
        #undef dtTypeMask
        #define SOMTGD_dtTypeMask 1
    #else
        #define dtTypeMask PascalEmitter_dtTypeMask
    #endif /* dtTypeMask */
#endif /* SOMTGD_dtTypeMask */
#ifndef SOMTGD_dtFunction
    #ifdef dtFunction
        #undef dtFunction
        #define SOMTGD_dtFunction 1
    #else
        #define dtFunction PascalEmitter_dtFunction
    #endif /* dtFunction */
#endif /* SOMTGD_dtFunction */
#ifndef SOMTGD_dtProcedure
    #ifdef dtProcedure
        #undef dtProcedure
        #define SOMTGD_dtProcedure 1
    #else
        #define dtProcedure PascalEmitter_dtProcedure
    #endif /* dtProcedure */
#endif /* SOMTGD_dtProcedure */
#ifndef SOMTGD_dtMethodMask
    #ifdef dtMethodMask
        #undef dtMethodMask
        #define SOMTGD_dtMethodMask 1
    #else
        #define dtMethodMask PascalEmitter_dtMethodMask
    #endif /* dtMethodMask */
#endif /* SOMTGD_dtMethodMask */
#ifndef SOMTGD_dtConst
    #ifdef dtConst
        #undef dtConst
        #define SOMTGD_dtConst 1
    #else
        #define dtConst PascalEmitter_dtConst
    #endif /* dtConst */
#endif /* SOMTGD_dtConst */
#ifndef SOMTGD_dtAttrib
    #ifdef dtAttrib
        #undef dtAttrib
        #define SOMTGD_dtAttrib 1
    #else
        #define dtAttrib PascalEmitter_dtAttrib
    #endif /* dtAttrib */
#endif /* SOMTGD_dtAttrib */
#ifndef SOMTGD_struct_LinkItem
    #ifdef struct_LinkItem
        #undef struct_LinkItem
        #define SOMTGD_struct_LinkItem 1
    #else
        #define struct_LinkItem PascalEmitter_struct_LinkItem
    #endif /* struct_LinkItem */
#endif /* SOMTGD_struct_LinkItem */

#ifndef SOM_DONT_USE_SHORT_NAMES
#ifndef SOMTGD_LINKITEM
    #ifdef LINKITEM
        #undef LINKITEM
        #define SOMTGD_LINKITEM 1
    #else
        #define LINKITEM PascalEmitter_LINKITEM
    #endif /* LINKITEM */
#endif /* SOMTGD_LINKITEM */
#endif /* SOM_DONT_USE_SHORT_NAMES */

#ifndef SOM_DONT_USE_SHORT_NAMES
#ifndef SOMTGD_PLINKITEM
    #ifdef PLINKITEM
        #undef PLINKITEM
        #define SOMTGD_PLINKITEM 1
    #else
        #define PLINKITEM PascalEmitter_PLINKITEM
    #endif /* PLINKITEM */
#endif /* SOMTGD_PLINKITEM */
#endif /* SOM_DONT_USE_SHORT_NAMES */
#ifndef SOMTGD__IDL_SEQUENCE_PLINKITEM
    #ifdef _IDL_SEQUENCE_PLINKITEM
        #undef _IDL_SEQUENCE_PLINKITEM
        #define SOMTGD__IDL_SEQUENCE_PLINKITEM 1
    #else
        #define _IDL_SEQUENCE_PLINKITEM _IDL_SEQUENCE_PascalEmitter_PLINKITEM
    #endif /* _IDL_SEQUENCE_PLINKITEM */
#endif /* SOMTGD__IDL_SEQUENCE_PLINKITEM */
#ifndef SOMTGD_struct_TypeItem
    #ifdef struct_TypeItem
        #undef struct_TypeItem
        #define SOMTGD_struct_TypeItem 1
    #else
        #define struct_TypeItem PascalEmitter_struct_TypeItem
    #endif /* struct_TypeItem */
#endif /* SOMTGD_struct_TypeItem */

#ifndef SOM_DONT_USE_SHORT_NAMES
#ifndef SOMTGD_TYPEITEM
    #ifdef TYPEITEM
        #undef TYPEITEM
        #define SOMTGD_TYPEITEM 1
    #else
        #define TYPEITEM PascalEmitter_TYPEITEM
    #endif /* TYPEITEM */
#endif /* SOMTGD_TYPEITEM */
#endif /* SOM_DONT_USE_SHORT_NAMES */

#ifndef SOM_DONT_USE_SHORT_NAMES
#ifndef SOMTGD_PTYPEITEM
    #ifdef PTYPEITEM
        #undef PTYPEITEM
        #define SOMTGD_PTYPEITEM 1
    #else
        #define PTYPEITEM PascalEmitter_PTYPEITEM
    #endif /* PTYPEITEM */
#endif /* SOMTGD_PTYPEITEM */
#endif /* SOM_DONT_USE_SHORT_NAMES */
#ifndef SOMTGD__IDL_SEQUENCE_PTYPEITEM
    #ifdef _IDL_SEQUENCE_PTYPEITEM
        #undef _IDL_SEQUENCE_PTYPEITEM
        #define SOMTGD__IDL_SEQUENCE_PTYPEITEM 1
    #else
        #define _IDL_SEQUENCE_PTYPEITEM _IDL_SEQUENCE_PascalEmitter_PTYPEITEM
    #endif /* _IDL_SEQUENCE_PTYPEITEM */
#endif /* SOMTGD__IDL_SEQUENCE_PTYPEITEM */
#endif /* SOM_DONT_USE_SHORT_NAMES */

/*
 * End of bindings for IDL types.
 */

#define PascalEmitter_MajorVersion 0
#define PascalEmitter_MinorVersion 0

/*
 * External name shortening if required
 */
#ifdef SOM_USE_SHORT_EXTERNAL_NAMES
#define PascalEmitterNewClass c
#pragma linkage(c, system)
#define PascalEmitterClassData d
#define PascalEmitterCClassData x
#endif /* SOM_USE_SHORT_EXTERNAL_NAMES */
/*--------------Migration------------*/
#define PascalEmitter_classObj PascalEmitterClassData.classObject
#define _PascalEmitter PascalEmitter_classObj

/*
 * Declare the class creation procedure
 */
SOMEXTERN SOMClass * SOMLINK PascalEmitterNewClass(integer4 somtmajorVersion,
		integer4 somtminorVersion);
#pragma linkage(PascalEmitterNewClass, system)

/*
 * Declare the class data structure
 */
SOMEXTERN struct PascalEmitterClassDataStructure {
	SOMClass *classObject;
	somMToken somtGetTypedef;
	somMToken somtGetStruct;
	somMToken somtGetUnion;
	somMToken somtGetSequence;
	somMToken somtGetMethodParamTypes;
	somMToken somtGetAttribute;
	somMToken somtGetConstant;
	somMToken somtGetEnum;
	somMToken somtEmitMethodImplementationProlog;
	somMToken somtEmitMethodImplementation;
	somMToken somtEmitNULLFn;
} SOMDLINK PascalEmitterClassData;

/*
 * Declare the C specific class data structure
 */
SOMEXTERN struct PascalEmitterCClassDataStructure {
	somMethodTabs parentMtab;
	somDToken instanceDataToken;
} SOMDLINK PascalEmitterCClassData;

/*
 * New and Renew macros for PascalEmitter
 */
#define PascalEmitterNew() \
   ( _PascalEmitter ? \
	_somNew(_PascalEmitter) \
	: ( PascalEmitterNewClass(\
		PascalEmitter_MajorVersion, \
		PascalEmitter_MinorVersion),\
	   _somNew(_PascalEmitter)))
#define PascalEmitterRenew(buf) \
   ( _PascalEmitter ? \
	_somRenew(_PascalEmitter, buf) \
	: ( PascalEmitterNewClass(\
		PascalEmitter_MajorVersion, \
		PascalEmitter_MinorVersion),\
	   _somRenew(_PascalEmitter, buf)))

/*
 * Override method: somtGenerateSections
 */
#define PascalEmitter_somtGenerateSections(somSelf) \
	SOMTEmitC_somtGenerateSections(somSelf)

/*
 * Override method: somtEmitMethod
 */
#define PascalEmitter_somtEmitMethod(somSelf,entry) \
	SOMTEmitC_somtEmitMethod(somSelf,entry)

/*
 * Override method: somtEmitAttribute
 */
#define PascalEmitter_somtEmitAttribute(somSelf,att) \
	SOMTEmitC_somtEmitAttribute(somSelf,att)

/*
 * Override method: somtEmitInterface
 */
#define PascalEmitter_somtEmitInterface(somSelf,intfc) \
	SOMTEmitC_somtEmitInterface(somSelf,intfc)

/*
 * Override method: somtEmitConstant
 */
#define PascalEmitter_somtEmitConstant(somSelf,con) \
	SOMTEmitC_somtEmitConstant(somSelf,con)

/*
 * Override method: somtEmitEnum
 */
#define PascalEmitter_somtEmitEnum(somSelf,en) \
	SOMTEmitC_somtEmitEnum(somSelf,en)

/*
 * Override method: somtEmitClass
 */
#define PascalEmitter_somtEmitClass(somSelf) \
	SOMTEmitC_somtEmitClass(somSelf)

/*
 * New Method: somtGetTypedef
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetTypedef(PascalEmitter *somSelf, 
		SOMTTypedefEntryC* td);
#pragma linkage(somTP_PascalEmitter_somtGetTypedef, system)
typedef somTP_PascalEmitter_somtGetTypedef *somTD_PascalEmitter_somtGetTypedef;
/*
 *  ���� ������� ⨯��.
 */
#define somMD_PascalEmitter_somtGetTypedef "::PascalEmitter::somtGetTypedef"
#define PascalEmitter_somtGetTypedef(somSelf,td) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetTypedef) \
	(somSelf,td))
#ifndef SOMGD_somtGetTypedef
    #if (defined(_somtGetTypedef) || defined(__somtGetTypedef))
        #undef _somtGetTypedef
        #undef __somtGetTypedef
        #define SOMGD_somtGetTypedef 1
    #else
        #define _somtGetTypedef PascalEmitter_somtGetTypedef
    #endif /* _somtGetTypedef */
#endif /* SOMGD_somtGetTypedef */

/*
 * New Method: somtGetStruct
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetStruct(PascalEmitter *somSelf, 
		SOMTStructEntryC* struc);
#pragma linkage(somTP_PascalEmitter_somtGetStruct, system)
typedef somTP_PascalEmitter_somtGetStruct *somTD_PascalEmitter_somtGetStruct;
/*
 *  ���� ������� �������.
 */
#define somMD_PascalEmitter_somtGetStruct "::PascalEmitter::somtGetStruct"
#define PascalEmitter_somtGetStruct(somSelf,struc) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetStruct) \
	(somSelf,struc))
#ifndef SOMGD_somtGetStruct
    #if (defined(_somtGetStruct) || defined(__somtGetStruct))
        #undef _somtGetStruct
        #undef __somtGetStruct
        #define SOMGD_somtGetStruct 1
    #else
        #define _somtGetStruct PascalEmitter_somtGetStruct
    #endif /* _somtGetStruct */
#endif /* SOMGD_somtGetStruct */

/*
 * New Method: somtGetUnion
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetUnion(PascalEmitter *somSelf, 
		SOMTUnionEntryC* un);
#pragma linkage(somTP_PascalEmitter_somtGetUnion, system)
typedef somTP_PascalEmitter_somtGetUnion *somTD_PascalEmitter_somtGetUnion;
/*
 *  ���� ������� ��ꥤ������.
 */
#define somMD_PascalEmitter_somtGetUnion "::PascalEmitter::somtGetUnion"
#define PascalEmitter_somtGetUnion(somSelf,un) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetUnion) \
	(somSelf,un))
#ifndef SOMGD_somtGetUnion
    #if (defined(_somtGetUnion) || defined(__somtGetUnion))
        #undef _somtGetUnion
        #undef __somtGetUnion
        #define SOMGD_somtGetUnion 1
    #else
        #define _somtGetUnion PascalEmitter_somtGetUnion
    #endif /* _somtGetUnion */
#endif /* SOMGD_somtGetUnion */

/*
 * New Method: somtGetMethodParamTypes
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetMethodParamTypes(PascalEmitter *somSelf, 
		SOMTMethodEntryC* me);
#pragma linkage(somTP_PascalEmitter_somtGetMethodParamTypes, system)
typedef somTP_PascalEmitter_somtGetMethodParamTypes *somTD_PascalEmitter_somtGetMethodParamTypes;
/*
 *  ���� ��ࠬ��஢ �㭪権.
 */
#define somMD_PascalEmitter_somtGetMethodParamTypes "::PascalEmitter::somtGetMethodParamTypes"
#define PascalEmitter_somtGetMethodParamTypes(somSelf,me) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetMethodParamTypes) \
	(somSelf,me))
#ifndef SOMGD_somtGetMethodParamTypes
    #if (defined(_somtGetMethodParamTypes) || defined(__somtGetMethodParamTypes))
        #undef _somtGetMethodParamTypes
        #undef __somtGetMethodParamTypes
        #define SOMGD_somtGetMethodParamTypes 1
    #else
        #define _somtGetMethodParamTypes PascalEmitter_somtGetMethodParamTypes
    #endif /* _somtGetMethodParamTypes */
#endif /* SOMGD_somtGetMethodParamTypes */

/*
 * New Method: somtGetAttribute
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetAttribute(PascalEmitter *somSelf, 
		SOMTAttributeEntryC* att);
#pragma linkage(somTP_PascalEmitter_somtGetAttribute, system)
typedef somTP_PascalEmitter_somtGetAttribute *somTD_PascalEmitter_somtGetAttribute;
/*
 *  ���� ��ਡ�⮢ �����.
 */
#define somMD_PascalEmitter_somtGetAttribute "::PascalEmitter::somtGetAttribute"
#define PascalEmitter_somtGetAttribute(somSelf,att) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetAttribute) \
	(somSelf,att))
#ifndef SOMGD_somtGetAttribute
    #if (defined(_somtGetAttribute) || defined(__somtGetAttribute))
        #undef _somtGetAttribute
        #undef __somtGetAttribute
        #define SOMGD_somtGetAttribute 1
    #else
        #define _somtGetAttribute PascalEmitter_somtGetAttribute
    #endif /* _somtGetAttribute */
#endif /* SOMGD_somtGetAttribute */

/*
 * New Method: somtGetConstant
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetConstant(PascalEmitter *somSelf, 
		SOMTConstEntryC* con);
#pragma linkage(somTP_PascalEmitter_somtGetConstant, system)
typedef somTP_PascalEmitter_somtGetConstant *somTD_PascalEmitter_somtGetConstant;
/*
 *  ���� ⨯�� ����⠭�.
 */
#define somMD_PascalEmitter_somtGetConstant "::PascalEmitter::somtGetConstant"
#define PascalEmitter_somtGetConstant(somSelf,con) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetConstant) \
	(somSelf,con))
#ifndef SOMGD_somtGetConstant
    #if (defined(_somtGetConstant) || defined(__somtGetConstant))
        #undef _somtGetConstant
        #undef __somtGetConstant
        #define SOMGD_somtGetConstant 1
    #else
        #define _somtGetConstant PascalEmitter_somtGetConstant
    #endif /* _somtGetConstant */
#endif /* SOMGD_somtGetConstant */

/*
 * New Method: somtGetEnum
 */
typedef void   SOMLINK somTP_PascalEmitter_somtGetEnum(PascalEmitter *somSelf, 
		SOMTEnumEntryC* en);
#pragma linkage(somTP_PascalEmitter_somtGetEnum, system)
typedef somTP_PascalEmitter_somtGetEnum *somTD_PascalEmitter_somtGetEnum;
/*
 *  ���� ����᫥���.
 */
#define somMD_PascalEmitter_somtGetEnum "::PascalEmitter::somtGetEnum"
#define PascalEmitter_somtGetEnum(somSelf,en) \
    (SOM_Resolve(somSelf, PascalEmitter, somtGetEnum) \
	(somSelf,en))
#ifndef SOMGD_somtGetEnum
    #if (defined(_somtGetEnum) || defined(__somtGetEnum))
        #undef _somtGetEnum
        #undef __somtGetEnum
        #define SOMGD_somtGetEnum 1
    #else
        #define _somtGetEnum PascalEmitter_somtGetEnum
    #endif /* _somtGetEnum */
#endif /* SOMGD_somtGetEnum */

/*
 * New Method: somtEmitNULLFn
 */
typedef void   SOMLINK somTP_PascalEmitter_somtEmitNULLFn(PascalEmitter *somSelf, 
		SOMTEntryC* entry);
#pragma linkage(somTP_PascalEmitter_somtEmitNULLFn, system)
typedef somTP_PascalEmitter_somtEmitNULLFn *somTD_PascalEmitter_somtEmitNULLFn;
/*
 *  "�����誠".
 */
#define somMD_PascalEmitter_somtEmitNULLFn "::PascalEmitter::somtEmitNULLFn"
#define PascalEmitter_somtEmitNULLFn(somSelf,entry) \
    (SOM_Resolve(somSelf, PascalEmitter, somtEmitNULLFn) \
	(somSelf,entry))
#ifndef SOMGD_somtEmitNULLFn
    #if (defined(_somtEmitNULLFn) || defined(__somtEmitNULLFn))
        #undef _somtEmitNULLFn
        #undef __somtEmitNULLFn
        #define SOMGD_somtEmitNULLFn 1
    #else
        #define _somtEmitNULLFn PascalEmitter_somtEmitNULLFn
    #endif /* _somtEmitNULLFn */
#endif /* SOMGD_somtEmitNULLFn */

/*
 * New Method: somtEmitMethodImplementationProlog
 */
typedef void   SOMLINK somTP_PascalEmitter_somtEmitMethodImplementationProlog(PascalEmitter *somSelf);
#pragma linkage(somTP_PascalEmitter_somtEmitMethodImplementationProlog, system)
typedef somTP_PascalEmitter_somtEmitMethodImplementationProlog *somTD_PascalEmitter_somtEmitMethodImplementationProlog;
/*
 *  ��������� ��⮤�� ����� (ᥪ�� ��᪠�� 'implementation')
 */
#define somMD_PascalEmitter_somtEmitMethodImplementationProlog "::PascalEmitter::somtEmitMethodImplementationProlog"
#define PascalEmitter_somtEmitMethodImplementationProlog(somSelf) \
    (SOM_Resolve(somSelf, PascalEmitter, somtEmitMethodImplementationProlog) \
	(somSelf))
#ifndef SOMGD_somtEmitMethodImplementationProlog
    #if (defined(_somtEmitMethodImplementationProlog) || defined(__somtEmitMethodImplementationProlog))
        #undef _somtEmitMethodImplementationProlog
        #undef __somtEmitMethodImplementationProlog
        #define SOMGD_somtEmitMethodImplementationProlog 1
    #else
        #define _somtEmitMethodImplementationProlog PascalEmitter_somtEmitMethodImplementationProlog
    #endif /* _somtEmitMethodImplementationProlog */
#endif /* SOMGD_somtEmitMethodImplementationProlog */

/*
 * New Method: somtEmitMethodImplementation
 */
typedef void   SOMLINK somTP_PascalEmitter_somtEmitMethodImplementation(PascalEmitter *somSelf, 
		SOMTMethodEntryC* entry);
#pragma linkage(somTP_PascalEmitter_somtEmitMethodImplementation, system)
typedef somTP_PascalEmitter_somtEmitMethodImplementation *somTD_PascalEmitter_somtEmitMethodImplementation;
/*
 *  ��������� ��⮤� �����
 */
#define somMD_PascalEmitter_somtEmitMethodImplementation "::PascalEmitter::somtEmitMethodImplementation"
#define PascalEmitter_somtEmitMethodImplementation(somSelf,entry) \
    (SOM_Resolve(somSelf, PascalEmitter, somtEmitMethodImplementation) \
	(somSelf,entry))
#ifndef SOMGD_somtEmitMethodImplementation
    #if (defined(_somtEmitMethodImplementation) || defined(__somtEmitMethodImplementation))
        #undef _somtEmitMethodImplementation
        #undef __somtEmitMethodImplementation
        #define SOMGD_somtEmitMethodImplementation 1
    #else
        #define _somtEmitMethodImplementation PascalEmitter_somtEmitMethodImplementation
    #endif /* _somtEmitMethodImplementation */
#endif /* SOMGD_somtEmitMethodImplementation */
#ifndef SOM_DONT_USE_INHERITED_MACROS
#define PascalEmitter__get_somtTemplate SOMTEmitC__get_somtTemplate
#define PascalEmitter__set_somtTemplate SOMTEmitC__set_somtTemplate
#define PascalEmitter__get_somtTargetFile SOMTEmitC__get_somtTargetFile
#define PascalEmitter__set_somtTargetFile SOMTEmitC__set_somtTargetFile
#define PascalEmitter__get_somtTargetClass SOMTEmitC__get_somtTargetClass
#define PascalEmitter__set_somtTargetClass SOMTEmitC__set_somtTargetClass
#define PascalEmitter__get_somtTargetModule SOMTEmitC__get_somtTargetModule
#define PascalEmitter__set_somtTargetModule SOMTEmitC__set_somtTargetModule
#define PascalEmitter__get_somtTargetType SOMTEmitC__get_somtTargetType
#define PascalEmitter__set_somtTargetType SOMTEmitC__set_somtTargetType
#define PascalEmitter__get_somtEmitterName SOMTEmitC__get_somtEmitterName
#define PascalEmitter__set_somtEmitterName SOMTEmitC__set_somtEmitterName
#define PascalEmitter_somtOpenSymbolsFile SOMTEmitC_somtOpenSymbolsFile
#define PascalEmitter_somtSetPredefinedSymbols SOMTEmitC_somtSetPredefinedSymbols
#define PascalEmitter_somtFileSymbols SOMTEmitC_somtFileSymbols
#define PascalEmitter_somtEmitProlog SOMTEmitC_somtEmitProlog
#define PascalEmitter_somtEmitBaseIncludesProlog SOMTEmitC_somtEmitBaseIncludesProlog
#define PascalEmitter_somtEmitBaseIncludes SOMTEmitC_somtEmitBaseIncludes
#define PascalEmitter_somtEmitBaseIncludesEpilog SOMTEmitC_somtEmitBaseIncludesEpilog
#define PascalEmitter_somtEmitMetaInclude SOMTEmitC_somtEmitMetaInclude
#define PascalEmitter_somtEmitMeta SOMTEmitC_somtEmitMeta
#define PascalEmitter_somtEmitBaseProlog SOMTEmitC_somtEmitBaseProlog
#define PascalEmitter_somtEmitBase SOMTEmitC_somtEmitBase
#define PascalEmitter_somtEmitBaseEpilog SOMTEmitC_somtEmitBaseEpilog
#define PascalEmitter_somtEmitPassthruProlog SOMTEmitC_somtEmitPassthruProlog
#define PascalEmitter_somtEmitPassthru SOMTEmitC_somtEmitPassthru
#define PascalEmitter_somtEmitPassthruEpilog SOMTEmitC_somtEmitPassthruEpilog
#define PascalEmitter_somtEmitRelease SOMTEmitC_somtEmitRelease
#define PascalEmitter_somtEmitDataProlog SOMTEmitC_somtEmitDataProlog
#define PascalEmitter_somtEmitData SOMTEmitC_somtEmitData
#define PascalEmitter_somtEmitDataEpilog SOMTEmitC_somtEmitDataEpilog
#define PascalEmitter_somtEmitAttributeProlog SOMTEmitC_somtEmitAttributeProlog
#define PascalEmitter_somtEmitAttributeEpilog SOMTEmitC_somtEmitAttributeEpilog
#define PascalEmitter_somtEmitConstantProlog SOMTEmitC_somtEmitConstantProlog
#define PascalEmitter_somtEmitConstantEpilog SOMTEmitC_somtEmitConstantEpilog
#define PascalEmitter_somtEmitTypedefProlog SOMTEmitC_somtEmitTypedefProlog
#define PascalEmitter_somtEmitTypedef SOMTEmitC_somtEmitTypedef
#define PascalEmitter_somtEmitTypedefEpilog SOMTEmitC_somtEmitTypedefEpilog
#define PascalEmitter_somtEmitStructProlog SOMTEmitC_somtEmitStructProlog
#define PascalEmitter_somtEmitStruct SOMTEmitC_somtEmitStruct
#define PascalEmitter_somtEmitStructEpilog SOMTEmitC_somtEmitStructEpilog
#define PascalEmitter_somtEmitUnionProlog SOMTEmitC_somtEmitUnionProlog
#define PascalEmitter_somtEmitUnion SOMTEmitC_somtEmitUnion
#define PascalEmitter_somtEmitUnionEpilog SOMTEmitC_somtEmitUnionEpilog
#define PascalEmitter_somtEmitEnumProlog SOMTEmitC_somtEmitEnumProlog
#define PascalEmitter_somtEmitEnumEpilog SOMTEmitC_somtEmitEnumEpilog
#define PascalEmitter_somtEmitInterfaceProlog SOMTEmitC_somtEmitInterfaceProlog
#define PascalEmitter_somtEmitInterfaceEpilog SOMTEmitC_somtEmitInterfaceEpilog
#define PascalEmitter_somtEmitModuleProlog SOMTEmitC_somtEmitModuleProlog
#define PascalEmitter_somtEmitModule SOMTEmitC_somtEmitModule
#define PascalEmitter_somtEmitModuleEpilog SOMTEmitC_somtEmitModuleEpilog
#define PascalEmitter_somtEmitMethodsProlog SOMTEmitC_somtEmitMethodsProlog
#define PascalEmitter_somtEmitMethods SOMTEmitC_somtEmitMethods
#define PascalEmitter_somtEmitMethodsEpilog SOMTEmitC_somtEmitMethodsEpilog
#define PascalEmitter_somtEmitEpilog SOMTEmitC_somtEmitEpilog
#define PascalEmitter_somtScanBases SOMTEmitC_somtScanBases
#define PascalEmitter_somtCheckVisibility SOMTEmitC_somtCheckVisibility
#define PascalEmitter_somtNew SOMTEmitC_somtNew
#define PascalEmitter_somtImplemented SOMTEmitC_somtImplemented
#define PascalEmitter_somtOverridden SOMTEmitC_somtOverridden
#define PascalEmitter_somtInherited SOMTEmitC_somtInherited
#define PascalEmitter_somtAllVisible SOMTEmitC_somtAllVisible
#define PascalEmitter_somtAll SOMTEmitC_somtAll
#define PascalEmitter_somtNewNoProc SOMTEmitC_somtNewNoProc
#define PascalEmitter_somtPrivOrPub SOMTEmitC_somtPrivOrPub
#define PascalEmitter_somtNewProc SOMTEmitC_somtNewProc
#define PascalEmitter_somtLink SOMTEmitC_somtLink
#define PascalEmitter_somtVA SOMTEmitC_somtVA
#define PascalEmitter_somtScanMethods SOMTEmitC_somtScanMethods
#define PascalEmitter_somtScanConstants SOMTEmitC_somtScanConstants
#define PascalEmitter_somtScanTypedefs SOMTEmitC_somtScanTypedefs
#define PascalEmitter_somtScanStructs SOMTEmitC_somtScanStructs
#define PascalEmitter_somtScanUnions SOMTEmitC_somtScanUnions
#define PascalEmitter_somtScanEnums SOMTEmitC_somtScanEnums
#define PascalEmitter_somtScanData SOMTEmitC_somtScanData
#define PascalEmitter_somtScanAttributes SOMTEmitC_somtScanAttributes
#define PascalEmitter_somtScanInterfaces SOMTEmitC_somtScanInterfaces
#define PascalEmitter_somtScanModules SOMTEmitC_somtScanModules
#define PascalEmitter_somtScanPassthru SOMTEmitC_somtScanPassthru
#define PascalEmitter_somtEmitFullPassthru SOMTEmitC_somtEmitFullPassthru
#define PascalEmitter_somtScanDataF SOMTEmitC_somtScanDataF
#define PascalEmitter_somtScanBasesF SOMTEmitC_somtScanBasesF
#define PascalEmitter_somtGetGlobalModifierValue SOMTEmitC_somtGetGlobalModifierValue
#define PascalEmitter_somtGetFirstGlobalDefinition SOMTEmitC_somtGetFirstGlobalDefinition
#define PascalEmitter_somtGetNextGlobalDefinition SOMTEmitC_somtGetNextGlobalDefinition
#define PascalEmitter_somInit SOMObject_somInit
#define PascalEmitter_somUninit SOMObject_somUninit
#define PascalEmitter_somDumpSelfInt SOMObject_somDumpSelfInt
#define PascalEmitter_somDefaultInit SOMObject_somDefaultInit
#define PascalEmitter_somDestruct SOMObject_somDestruct
#define PascalEmitter_somDefaultCopyInit SOMObject_somDefaultCopyInit
#define PascalEmitter_somDefaultAssign SOMObject_somDefaultAssign
#define PascalEmitter_somDefaultConstCopyInit SOMObject_somDefaultConstCopyInit
#define PascalEmitter_somDefaultVCopyInit SOMObject_somDefaultVCopyInit
#define PascalEmitter_somDefaultConstVCopyInit SOMObject_somDefaultConstVCopyInit
#define PascalEmitter_somDefaultConstAssign SOMObject_somDefaultConstAssign
#define PascalEmitter_somDefaultVAssign SOMObject_somDefaultVAssign
#define PascalEmitter_somDefaultConstVAssign SOMObject_somDefaultConstVAssign
#define PascalEmitter_somFree SOMObject_somFree
#define PascalEmitter_somGetClass SOMObject_somGetClass
#define PascalEmitter_somGetClassName SOMObject_somGetClassName
#define PascalEmitter_somGetSize SOMObject_somGetSize
#define PascalEmitter_somIsA SOMObject_somIsA
#define PascalEmitter_somIsInstanceOf SOMObject_somIsInstanceOf
#define PascalEmitter_somRespondsTo SOMObject_somRespondsTo
#define PascalEmitter_somDispatch SOMObject_somDispatch
#define PascalEmitter_somClassDispatch SOMObject_somClassDispatch
#define PascalEmitter_somCastObj SOMObject_somCastObj
#define PascalEmitter_somResetObj SOMObject_somResetObj
#define PascalEmitter_somDispatchV SOMObject_somDispatchV
#define PascalEmitter_somDispatchL SOMObject_somDispatchL
#define PascalEmitter_somDispatchA SOMObject_somDispatchA
#define PascalEmitter_somDispatchD SOMObject_somDispatchD
#define PascalEmitter_somPrintSelf SOMObject_somPrintSelf
#define PascalEmitter_somDumpSelf SOMObject_somDumpSelf
#endif /* SOM_DONT_USE_INHERITED_MACROS */

#endif       /* SOM_PascalEmitter_h */
