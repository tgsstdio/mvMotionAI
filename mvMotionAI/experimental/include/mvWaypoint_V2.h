#ifndef MVWAYPOINT_V2_H_INCLUDED
#define MVWAYPOINT_V2_H_INCLUDED

#include "mvMotionAI-Types.h"

#ifdef MV_FILE_HEADER_TAG_
/**
 * \file mvWaypoint.h
 *
 * Copyright (c) 2006 , 2007 David Young.
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
#endif

#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_SHAPE_HEADER_FILE_H_

class mvWaypoint_V2
{
   private:
      mvVec3 wpPosition;
      mvShape wpShape;

   public:
      mvWaypoint_V2(mvOptionEnum wshape, mvFloat x, mvFloat y, mvFloat z);

      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;

      void setX(mvFloat x);
      void setY(mvFloat y);
      void setZ(mvFloat z);
      const mvVec3& getPosition() const;

      mvErrorEnum setPosition(mvFloat x, mvFloat y, mvFloat z);
      mvErrorEnum setPositionByVec3(const mvVec3& value);

      mvErrorEnum setShape(mvOptionEnum oShape);
      mvConstShapePtr getShape() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvWaypoint_V2();
};

#endif // MVWAYPOINT_V2_H_INCLUDED
