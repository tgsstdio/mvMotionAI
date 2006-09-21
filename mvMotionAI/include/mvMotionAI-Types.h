/**
 *\file mvMotionAI-Types.h
 * Copyright (c) 2006 David Young.
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
 */
#ifndef MV_MOTIONAI_TYPES_H_
#define MV_MOTIONAI_TYPES_H_

/**
 * changes the values of
 * data type in the system
 */

/**
 * FLOATING POINT - used in Vec3 and other places
 */

#ifndef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
#define MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT 1
/** comment this line below changes the float type to double **/
#undef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
#endif

#ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
typedef double mvFloat;
#else
typedef float mvFloat;
#endif

/**
 * INDEXES & COUNT - used in mvVec3 and other places
 */

#define MV_MOTIONAI_INDEX_TYPE_INTEGER 0
#define MV_MOTIONAI_INDEX_TYPE_SHORT 1
#define MV_MOTIONAI_INDEX_TYPE_LONG 2

// alter this value to change the type
#ifndef MV_MOTIONAI_INDEX_TYPE
#define MV_MOTIONAI_INDEX_TYPE MV_MOTIONAI_INDEX_TYPE_INTEGER
#endif

#if MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_SHORT
typedef short mvIndex;
typedef short mvCount;
#elif MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_LONG
typedef long mvIndex;
typedef long mvCount;
#else
typedef int mvIndex;
typedef int mvCount;
#endif

#endif
