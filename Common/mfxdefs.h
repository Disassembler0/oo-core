/* ****************************************************************************** *\

INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or nondisclosure
agreement with Intel Corporation and may not be copied or disclosed except in
accordance with the terms of that agreement
Copyright(c) 2007-2009 Intel Corporation. All Rights Reserved.

File Name: mfxdefs.h

\* ****************************************************************************** */
#ifndef __MFXDEFS_H__
#define __MFXDEFS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef unsigned char       mfxU8;
typedef char                mfxI8;
typedef short               mfxI16;
typedef unsigned short      mfxU16;
typedef unsigned int        mfxU32;
typedef int                 mfxI32;
typedef unsigned long       mfxUL32;
typedef long                mfxL32;
typedef float               mfxF32;
typedef double              mfxF64;
typedef unsigned __int64    mfxU64;         /* Linux compatibility */
typedef __int64             mfxI64;
typedef void*               mfxHDL;
typedef mfxHDL              mfxMemId;

typedef struct {
    mfxI16  x;
    mfxI16  y;
} mfxI16Pair;

/*********************************************************************************\
Error message
\*********************************************************************************/
typedef enum
{
    /* no error */
    MFX_ERR_NONE                        = 0,    /* no error */

    /* reserved for unexpected errors */
    MFX_ERR_UNKNOWN                     = -1,   /* unknown error. */

    /* error codes <0 */
    MFX_ERR_NULL_PTR                    = -2,   /* null pointer */
    MFX_ERR_UNSUPPORTED                 = -3,   /* undeveloped feature */
    MFX_ERR_MEMORY_ALLOC                = -4,   /* failed to allocate memory */
    MFX_ERR_NOT_ENOUGH_BUFFER           = -5,   /* insufficient buffer at input/output */
    MFX_ERR_INVALID_HANDLE              = -6,   /* invalid handle */
    MFX_ERR_LOCK_MEMORY                 = -7,   /* failed to lock the memory block */
    MFX_ERR_NOT_INITIALIZED             = -8,   /* member function called before initialization */
    MFX_ERR_NOT_FOUND                   = -9,   /* the specified object is not found */
    MFX_ERR_MORE_DATA                   = -10,  /* expect more data at input */
    MFX_ERR_MORE_SURFACE                = -11,  /* expect more surface at output */
    MFX_ERR_ABORTED                     = -12,  /* operation aborted */
    MFX_ERR_DEVICE_LOST                 = -13,  /* lose the HW acceleration device */
    MFX_ERR_INCOMPATIBLE_VIDEO_PARAM    = -14,  /* incompatible video parameters */
    MFX_ERR_INVALID_VIDEO_PARAM         = -15,  /* invalid video parameters */
    MFX_ERR_UNDEFINED_BEHAVIOR          = -16,  /* undefined behavior */
    MFX_ERR_DEVICE_FAILED               = -17,  /* device operation failure */

    /* warnings >0 */
    MFX_WRN_IN_EXECUTION                = 1,    /* the previous asynchrous operation is in execution */
    MFX_WRN_DEVICE_BUSY                 = 2,    /* the HW acceleration device is busy */
    MFX_WRN_VIDEO_PARAM_CHANGED         = 3,    /* the video parameters are changed during decoding */
    MFX_WRN_PARTIAL_ACCELERATION        = 4,    /* SW is used */
    MFX_WRN_INCOMPATIBLE_VIDEO_PARAM    = 5,    /* incompatible video parameters */
    MFX_WRN_VALUE_NOT_CHANGED           = 6     /* the value is saturated based on its valid range */

} mfxStatus;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MFXDEFS_H__ */
