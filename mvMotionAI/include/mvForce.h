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

#include "mvMotionAI-Types.h"
//#include "Vec3.h"
#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_

/**
 * \class mvForce
 *
 * \brief environmental elements which act on bodies in the
 * world system
 *
 * Log
 *
 *version     date  comments
 *
 *00-01-16  15/10/06 - updated mvEnum to 3 enums
 *
 *00-01-05  22/5/06  - replaces c++ types with mv types,
 *                   change Vec3 to mvVec3
 *
 *00-01-00  22/5/06  - initialised forces
 */

// TODO : added waypoint index to list
// TODO : remove count from list
// TODO : make force a superclass

static const mvCount MV_MAX_NO_OF_FORCE_VARIABLES = 3;
class mvForce
{
   private:
      void initLengthParameter(mvFloat length);
      mvErrorEnum initialiseForce(mvOptionEnum fType);
      mvCount getNoOfParameters(mvParamEnum paramFlag);
      mvCount getNoOfForceVariables();
      //mvEnum initialiseForceVariables(mvEnum fType);
      mvOptionEnum forceType;
	   mvVec3 centralVector;
	   mvFloat* variables;
      mvOptionEnum enableFlag;
      mvCount count;

   public:
      mvForce(mvOptionEnum fType);
      mvForce(mvOptionEnum fType, mvFloat fx, mvFloat fy, mvFloat fz);
      mvOptionEnum toggleEnableFlag();
      mvOptionEnum getEnableFlag() const;
      mvOptionEnum setEnableFlag(mvOptionEnum option);
      mvOptionEnum getType() const;
      const mvVec3& getVector() const;
      void incrementCount();
      void decrementCount();
      bool isGlobalForce();
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* dest);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* dest);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* dest, mvCount* size);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvForce();
};

#endif
