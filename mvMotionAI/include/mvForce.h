/**
 *\file mvForce.h
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
#ifndef _MV_MOTIONAI_FORCE_H
#define _MV_MOTIONAI_FORCE_H

#include "mvVec3.h"
#include "mvMotionAI-Types.h"
//#include "Vec3.h"
#include "mvEnum.h"

/**
 * \class mvForce
 *
 * \brief environmental elements which act on bodies in the
 * world system
 *
 * Log
 *
 *version     date  comments
 *00-01-05  22/5/06  - replaces c++ types with mv types,
 *                   change Vec3 to mvVec3
 *
 *00-01-00  22/5/06  - initialised forces
 */

class mvForce
{
   private:
      void initLengthParameter(mvFloat length);
      mvEnum initialiseForce(mvEnum fType);
      mvCount getNoOfParameters(mvEnum paramFlag);
      mvCount getNoOfForceVariables();
      //mvEnum initialiseForceVariables(mvEnum fType);
      mvEnum forceType;
	   mvVec3 centralVector;
	   mvFloat* variables;
      mvEnum enableFlag;
      mvCount count;

   public:
      mvForce(mvEnum fType);
      mvForce(mvEnum fType, mvFloat fx, mvFloat fy, mvFloat fz);
      mvEnum toggleEnableFlag();
      mvEnum getEnableFlag() const;
      mvEnum setEnableFlag(mvEnum option);
      mvEnum getType() const;
      const mvVec3& getVector() const;
      void incrementCount();
      void decrementCount();
      mvEnum isGlobalForce();
      mvEnum getParameter(mvEnum paramFlag, mvEnum* dest);
      mvEnum getParameterf(mvEnum paramFlag, mvFloat* dest);
      mvEnum getParameterv(mvEnum paramFlag, mvFloat* dest, mvCount* size);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      ~mvForce();
};

#endif
