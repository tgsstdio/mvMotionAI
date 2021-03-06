/**
 * \file mvMotionAI-Utilities.cpp
 *
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
 */

#include <mv/mvMotionAI-Utilities.h>

#include <cmath>
#include <cstdlib>

 /*
 * Code taken from OpenSteer Utilities.h (2002-2004)
 * on the 20/06/2006
 * ----------------------------------------------------------------------------
 * Functions to encapsulate cross-platform differences for several cmath
 * functions.  Specifically, the C++ standard says that these functions are
 * in the std namespace (std::sqrt, etc.)  Apparently the MS VC6 compiler (or
 * its header files) do not implement this correctly and the function names
 * are in the global namespace.  We hope these -XXX versions are a temporary
 * expedient, to be removed later.
 *
 * moved these functions out into .cpp function
 */

/* TODO (White 2#1#): Include high precision as well */
// TODO : include automake's config.h
// #ifdef WIN32 is MVC++ 6 tag - to VISUAL_C_VER_6

//#define MV_LARGE_PRIME_NUMBER_FOR_RAND_DIV (32749)

MV_GLOBAL_FUNC_PREFIX mvFloat mvFloor (mvFloat x)
{
#ifdef VISUAL_C_VER_6
   #ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
      return floor (x);
   #else
      return floorf(x)
   #endif
#else
   return std::floor(x);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvSqrt (mvFloat x)
{
#ifdef VISUAL_C_VER_6
   #ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
      return sqrt (x);
   #else
      return sqrtf (x);
   #endif
#else
   return std::sqrt(x);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvSin (mvFloat x)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) sin (x);
#else
   return std::sin(x);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvCos (mvFloat x)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) cos (x);
#else
   return std::cos(x);
#endif
}

//inline float mvAbs (mvFloat x)           {return abs (x);}
//inline int mvAbs (int x)            {return abs (x);}

MV_GLOBAL_FUNC_PREFIX mvFloat mvMax (mvFloat x, mvFloat y)
{
   return (x > y) ? x : y;
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvMin (mvFloat x, mvFloat y)
{
   return (x < y) ? x : y;
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvArcCos(mvFloat theta)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) acos(theta);
#else
   return std::acos(theta);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvArcSin(mvFloat theta)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) asin(theta);
#else
   return std::asin(theta);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvArcTan(mvFloat theta)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) atan(theta);
#else
   return std::atan(theta);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvFMod(mvFloat num, mvFloat denom)
{
#ifdef VISUAL_C_VER_6
   return (mvFloat) fmod(num, denom);
#else
   return std::fmod(num, denom);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvModf(mvFloat x, mvFloat* intPart)
{
#ifdef VISUAL_C_VER_6
   #ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
      return modf(x, intPart);
   #else
      return modff(x, intPart);
   #endif
#else
   return std::modf(x, intPart);
#endif
}

MV_GLOBAL_FUNC_PREFIX mvFloat mvRandNormalised()
{
   mvIndex value = rand();
   mvFloat temp = (mvFloat) value;
   temp /= RAND_MAX;
   return temp;
}


