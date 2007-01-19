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

#include "mvMotionAI-Utilities.h"
#include <cmath>

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
// #ifdef WIN32 is MVC++ 6 tag

mvFloat mvFloor (mvFloat x)
{
#ifdef WIN32
   return floor (x);
#else
   return std::floor(x);
#endif
}

mvFloat mvSqrt (mvFloat x)
{
#ifdef WIN32
   return sqrt (x);
#else
   return std::sqrt(x);
#endif
}

mvFloat mvSin (mvFloat x)
{
#ifdef WIN32
   return sin (x);
#else
   return std::sin(x);
#endif
}

mvFloat mvCos (mvFloat x)
{
#ifdef WIN32
   return cos (x);
#else
   return std::cos(x);
#endif
}

//inline float mvAbs (mvFloat x)           {return abs (x);}
//inline int mvAbs (int x)            {return abs (x);}

mvFloat mvMax (mvFloat x, mvFloat y)
{
   return (x > y) ? x : y;
}

mvFloat mvMin (mvFloat x, mvFloat y)
{
   return (x < y) ? x : y;
}

mvFloat mvArcCos(mvFloat theta)
{
#ifdef WIN32
   return acos(theta);
#else
   return std::acos(theta);
#endif
}

mvFloat mvArcSin(mvFloat theta)
{
#ifdef WIN32
   return asin(theta);
#else
   return std::asin(theta);
#endif
}

mvFloat mvArcTan(mvFloat theta)
{
#ifdef WIN32
   return atan(theta);
#else
   return std::atan(theta);
#endif
}

mvFloat mvFMod(mvFloat num, mvFloat denom)
{
//#ifdef WIN32
  // return fmod(num, denom);
//#else
   return std::fmod(num, denom);
//#endif
}

mvFloat mvModf(mvFloat x, mvFloat* intPart)
{
//#ifdef WIN32
  // return modf(x, intPart);
//#else
   return std::modf(x, intPart);
//#endif
}


