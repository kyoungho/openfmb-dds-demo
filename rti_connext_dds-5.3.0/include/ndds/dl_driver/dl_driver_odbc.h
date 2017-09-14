/* (c) Copyright 2003-2015, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dl_driver_odbc.h    generated by: makeheader    Thu Jun 22 14:16:53 2017
 *
 *		built from:	odbc.ifc
 */

#ifndef dl_driver_odbc_h
#define dl_driver_odbc_h



#include "osapi/osapi_type.h"
#include "dl_driver/dl_driver_dll.h"

#if defined(RTI_WIN32) || defined(RTI_WINCE)
#include <windows.h>
#endif

#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

/* The following types are defined in the newer odbc include files
   from Microsoft
*/
#if defined (RTI_WIN32) && !defined (RTI_64BIT)
#ifndef SQLROWSETSIZE
#define SQLROWSETSIZE   SQLUINTEGER
#define SQLLEN          SQLINTEGER
#define SQLROWOFFSET    SQLINTEGER
#define SQLROWCOUNT     SQLUINTEGER
#define SQLULEN         SQLUINTEGER
#define SQLSETPOSIROW   SQLUSMALLINT  
#endif
#endif

/* this is not defined in the unixOdbc header file for Odbc 2.0 */
#ifndef SQL_C_BIGINT
#define SQL_C_BIGINT    -25
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/* ODBC API */

#if (defined (RTI_WIN32) || defined (RTI_WINCE)) && !defined (RTI_64BIT)


typedef FARPROC SQLAllocConnectFcn;

typedef FARPROC SQLAllocEnvFcn;

typedef FARPROC SQLAllocStmtFcn;

typedef FARPROC SQLBindColFcn;

typedef FARPROC SQLBindParameterFcn;

typedef FARPROC SQLConnectFcn;

typedef FARPROC SQLDisconnectFcn;

typedef FARPROC SQLDriverConnectFcn;

typedef FARPROC SQLExecDirectFcn;

typedef FARPROC SQLExecuteFcn;

typedef FARPROC SQLErrorFcn;

typedef FARPROC SQLFetchFcn;

typedef FARPROC SQLFreeConnectFcn;

typedef FARPROC SQLFreeEnvFcn;

typedef FARPROC SQLFreeStmtFcn;

typedef FARPROC SQLGetInfoFcn;

typedef FARPROC SQLPrepareFcn;

typedef FARPROC SQLRowCountFcn;

typedef FARPROC SQLSetConnectOptionFcn;

typedef FARPROC SQLTransactFcn;


#else


typedef SQLRETURN (*SQLAllocConnectFcn)(
    SQLHENV EnvironmentHandle,
    SQLHDBC *ConnectionHandle);


typedef SQLRETURN (*SQLAllocEnvFcn)(
    SQLHENV *EnvironmentHandle);


typedef SQLRETURN (*SQLAllocStmtFcn)(
    SQLHDBC ConnectionHandle,
    SQLHSTMT *StatementHandle);


typedef SQLRETURN (*SQLBindColFcn)(
    SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber,
    SQLSMALLINT TargetType,
    SQLPOINTER TargetValue,
    SQLLEN BufferLength,
    SQLLEN *StrLen_or_Ind);


typedef SQLRETURN (*SQLBindParameterFcn)(
     SQLHSTMT StatementHandle,
     SQLUSMALLINT ParameterNumber,
     SQLSMALLINT InputOutputType,
     SQLSMALLINT ValueType,
     SQLSMALLINT ParameterType,
     SQLULEN ColumnSize,
     SQLSMALLINT DecimalDigits,
     SQLPOINTER ParameterValuePtr,
     SQLLEN BufferLength,
     SQLLEN *StrLen_or_IndPtr);


typedef SQLRETURN (*SQLConnectFcn)(
    SQLHDBC ConnectionHandle,
    SQLCHAR *DSN,
    SQLSMALLINT dsnBufferLength,
    SQLCHAR *UID,
    SQLSMALLINT uidBufferLength,
    SQLCHAR *AuthStr,
    SQLSMALLINT authStrBufferLength);


typedef SQLRETURN (*SQLDisconnectFcn)(
    SQLHDBC ConnectionHandle);


typedef SQLRETURN (*SQLDriverConnectFcn)(
     SQLHDBC ConnectionHandle,
     SQLHWND WindowHandle,
     SQLCHAR *InConnectionString,
     SQLSMALLINT StringLength1,
     SQLCHAR *OutConnectionString,
     SQLSMALLINT BufferLength,
     SQLSMALLINT *StringLength2Ptr,
     SQLUSMALLINT DriverCompletion);


typedef SQLRETURN (*SQLExecDirectFcn)(
    SQLHSTMT StatementHandle,
    SQLCHAR *SqlString, 
    SQLINTEGER TextLength);


typedef SQLRETURN (*SQLExecuteFcn)(
    SQLHSTMT StatementHandle);


typedef SQLRETURN (*SQLErrorFcn)(
    SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, 
    SQLHSTMT StatementHandle,
    SQLCHAR *Sqlstate, 
    SQLINTEGER *NativeError,
    SQLCHAR *MessageText, 
    SQLSMALLINT BufferLength,
    SQLSMALLINT *TextLength);


typedef SQLRETURN (*SQLFetchFcn)(
    SQLHSTMT StatementHandle);


typedef SQLRETURN (*SQLFreeConnectFcn)(
    SQLHDBC ConnectionHandle);


typedef SQLRETURN (*SQLFreeEnvFcn)(
    SQLHENV EnvironmentHandle);


typedef SQLRETURN (*SQLFreeStmtFcn)(
    SQLHSTMT StatementHandle,
    SQLUSMALLINT Option);


typedef SQLRETURN (*SQLGetInfoFcn)(
     SQLHDBC ConnectionHandle,
     SQLUSMALLINT InfoType,
     SQLPOINTER InfoValuePtr,
     SQLSMALLINT BufferLength,
     SQLSMALLINT * StringLengthPtr);


typedef SQLRETURN (*SQLPrepareFcn)(
    SQLHSTMT StatementHandle,
    SQLCHAR *StatementText, 
    SQLINTEGER TextLength);


typedef SQLRETURN (*SQLRowCountFcn)(
    SQLHSTMT StatementHandle,
    SQLLEN *RowCount);


typedef SQLRETURN (*SQLSetConnectOptionFcn)(
    SQLHDBC ConnectionHandle,
    SQLUSMALLINT Option,
    SQLULEN Value);


typedef SQLRETURN (*SQLTransactFcn)(
    SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, 
    SQLUSMALLINT CompletionType);


#endif


struct DLDRIVEROdbc {    
    void * _libHandle;
    SQLAllocConnectFcn      allocConnectFcn;
    SQLAllocEnvFcn          allocEnvFcn;
    SQLAllocStmtFcn         allocStmtFcn;
    SQLBindColFcn           bindColFcn;
    SQLBindParameterFcn     bindParameterFcn;
    SQLConnectFcn           connectFcn;
    SQLDisconnectFcn        disconnectFcn;
    SQLErrorFcn             errorFcn;
    SQLExecDirectFcn        execDirectFcn;
    SQLExecuteFcn           executeFcn;
    SQLFetchFcn             fetchFcn;
    SQLFreeConnectFcn       freeConnectFcn;
    SQLFreeEnvFcn           freeEnvFcn;
    SQLFreeStmtFcn          freeStmtFcn;
    SQLGetInfoFcn	    getInfoFcn;
    SQLPrepareFcn           prepareFcn;
    SQLRowCountFcn          rowCountFcn;
    SQLSetConnectOptionFcn  setConnectOptionFcn;
    SQLTransactFcn          transactFcn;
};


#define DLDRIVER_ODBC_INITIALIZER \
    { \
        NULL, /* libraryHandle */ \
        NULL, /* SQLAllocConnectFcn */ \
        NULL, /* SQLAllocEnvFcn */ \
        NULL, /* SQLAllocStmtFcn */ \
        NULL, /* SQLBindColFcn */ \
        NULL, /* SQLBindParameterFcn */ \
        NULL, /* SQLConnectFcn */ \
        NULL, /* SQLDisconnectFcn */ \
        NULL, /* SQLErrorFcn */ \
        NULL, /* SQLExecDirectFcn */ \
        NULL, /* SQLExecuteFcn */ \
        NULL, /* SQLFetchFcn */ \
        NULL, /* SQLFreeConnectFcn */ \
        NULL, /* SQLFreeEnvFcn */ \
        NULL, /* SQLFreeStmtFcn */ \
        NULL, /* SQLPrepareFcn */ \
        NULL, /* SQLRowCountFcn */ \
        NULL, /* SQLSetConnectOptionFcn */ \
        NULL  /* SQLTransactFcn */ \
    }


struct DLDRIVEROdbcVersion {
    RTI_INT32 major;
    RTI_INT32 minor;
};


#define DLDRIVER_ODBC_VERSION_INITIALIZER \
    { \
        0, /* major */ \
        0  /* minor */ \
    }

extern DLDRIVERDllExport
RTIBool DLDRIVEROdbc_load(struct DLDRIVEROdbc * self,const char * libName);

extern DLDRIVERDllExport
RTIBool DLDRIVEROdbc_unload(struct DLDRIVEROdbc * self);

extern DLDRIVERDllExport
RTIBool DLDRIVEROdbcHelper_getDatabaseVersion(struct DLDRIVEROdbcVersion * dbmsVersion, struct DLDRIVEROdbc * self, SQLHDBC hdbc);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dl_driver_odbc_h */
