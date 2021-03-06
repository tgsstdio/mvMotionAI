/**
 *\file mvMotionAI-Utilities.h
 * Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Log        Date      Comments
 *
 *00-01-21  22/11/06    - added arc cos/tan/tan to mvMotionAI-Utilities
 *
 *00-01-16  22/05/06    - edit functions to include new enumerations of mvEnums.h
 *
 *00-01-00  22/05/06    - Headers file : Template functions are hard to split
 *
 */
#ifndef MV_MOTIONAI_UTILITIES_H_
#define MV_MOTIONAI_UTILITIES_H_

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/*
 * Math functions
 */
MV_GLOBAL_FUNC_PREFIX mvFloat mvFloor (mvFloat x);
MV_GLOBAL_FUNC_PREFIX mvFloat mvSqrt (mvFloat x);
MV_GLOBAL_FUNC_PREFIX mvFloat mvSin (mvFloat x);
MV_GLOBAL_FUNC_PREFIX mvFloat mvCos (mvFloat x);
MV_GLOBAL_FUNC_PREFIX mvFloat mvAbs (mvFloat x);
//inline int   mvAbs (int x);
MV_GLOBAL_FUNC_PREFIX mvFloat mvMax (mvFloat x, mvFloat y);
MV_GLOBAL_FUNC_PREFIX mvFloat mvMin (mvFloat x, mvFloat y);
MV_GLOBAL_FUNC_PREFIX mvFloat mvRandNormalised();

MV_GLOBAL_FUNC_PREFIX mvFloat mvArcCos(mvFloat theta);
MV_GLOBAL_FUNC_PREFIX mvFloat mvArcSin(mvFloat theta);
MV_GLOBAL_FUNC_PREFIX mvFloat mvArcTan(mvFloat theta);
MV_GLOBAL_FUNC_PREFIX mvFloat mvFMod(mvFloat num, mvFloat denom);
MV_GLOBAL_FUNC_PREFIX mvFloat mvModf(mvFloat x, mvFloat* intPart);

#ifndef MV_WIDE_STRING_CHAR
#define mvInitConstString(s)
#else
#define mvInitConstString(s) Ls
#endif

MV_GLOBAL_FUNC_PREFIX mvIndex mvStringCompare(mvConstStringPtr str1, mvConstStringPtr str2);

#endif
