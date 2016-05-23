/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include <fstream>
#include <string>

#ifdef GPP_DLL_EXPORT
#ifdef WIN32
#ifdef GPP_BUILD
#define GPP_EXPORT __declspec(dllexport)
#else
#define GPP_EXPORT __declspec(dllimport)
#endif
#else
#define GPP_EXPORT
#endif
#else
#define GPP_EXPORT
#endif

#ifndef NULL
#define NULL 0
#endif

#define GPPFREEPOINTER(pointer) if ((pointer) != NULL) { delete (pointer); (pointer) = NULL; }
#define GPPFREEARRAY(pointer) if ((pointer) != NULL) { delete [](pointer); (pointer) = NULL; }

// Error Codes
#define GPP_NO_ERROR           0
#define GPP_EMPTY_INPUT       -1
#define GPP_INVALID_INPUT     -2
#define GPP_INVALID_RESULT    -3
#define GPP_NOT_ENOUGH_INPUT  -4
#define GPP_NOT_INITIALIZED   -5
#define GPP_API_IS_NOT_AVAILABLE -6
#define GPP_DATA_IS_CORRUPT   -7

#define REALDOUBLE
namespace GPP
{
#ifdef REALDOUBLE
    typedef double Real;
#else
    typedef float Real;
#endif
    typedef int Int;
    typedef unsigned int UInt;
    typedef long long LongInt;
    typedef unsigned long long ULongInt;
    typedef int ErrorCode;
    extern GPP_EXPORT const Real REAL_TOL;
    extern GPP_EXPORT const Real REAL_LARGE;
    extern GPP_EXPORT const Int INT_LARGE;    
    extern GPP_EXPORT const UInt UINT_LARGE;    
    extern GPP_EXPORT const Real PI;
    extern GPP_EXPORT const Real ONE_RADIAN;

    // Reset progress value before calling api
    extern GPP_EXPORT void ResetApiProgress(void);

    // Get progress value when running api
    // progress value range: [0, 1]
    extern GPP_EXPORT Real GetApiProgress(void);

    // Active library steps:
    // 1. Get registrationKey from your computer: std::string registrationKey = GetRegistrationKey();
    // 2. Send registrationKey to threepark@163.com and get activationKey
    // 3. SetActivationKey(activationKey)

    // Every computer has one registration key
    extern GPP_EXPORT std::string GetRegistrationKey(void);

    extern GPP_EXPORT bool SetActivationKey(std::string key);
}
