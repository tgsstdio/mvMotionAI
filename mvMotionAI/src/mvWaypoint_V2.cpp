/**
 * \file mvWaypoint_V2.cpp
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
#include "mvWaypoint_V2.h"

mvWaypoint_V2::mvWaypoint_V2(mvOptionEnum wshape, mvFloat x, mvFloat y,\
   mvFloat z)
{
   setPosition(x,y,z);
   setShape(wshape);
}

mvFloat mvWaypoint_V2::getX() const
{
   return wpPosition.getX();
}

mvFloat mvWaypoint_V2::getY() const
{
   return wpPosition.getY();
}

mvFloat mvWaypoint_V2::getZ() const
{
   return wpPosition.getZ();
}

void mvWaypoint_V2::setX(mvFloat x)
{
   wpPosition.setX(x);
}

void mvWaypoint_V2::setY(mvFloat y)
{
   wpPosition.setY(y);
}

void mvWaypoint_V2::setZ(mvFloat z)
{
   wpPosition.setZ(z);
}

const mvVec3& mvWaypoint_V2::getPosition() const
{
   return wpPosition;
}

mvErrorEnum mvWaypoint_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setPositionByVec3(temp);
}

mvErrorEnum mvWaypoint_V2::setPositionByVec3(const mvVec3& value)
{
   wpPosition = value;
   return MV_NO_ERROR;
}

mvErrorEnum mvWaypoint_V2::setShape(mvOptionEnum shape)
{
   return wpShape.setType(shape);
}

mvConstShapePtr mvWaypoint_V2::getShape() const
{
   return &wpShape;
}

mvErrorEnum mvWaypoint_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   mvErrorEnum error;

   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   error = wpShape.getParameteri(paramFlag, index);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvWaypoint_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   mvErrorEnum error;

   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   error = wpShape.getParameter(paramFlag, option);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
}

mvErrorEnum mvWaypoint_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   mvErrorEnum error;

   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   error = wpShape.getParameterf(paramFlag, num);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
}

mvErrorEnum mvWaypoint_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   mvErrorEnum error;

   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_POSITION:
         numArray[0] = getX();
         numArray[1] = getY();
         numArray[2] = getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      default:
         error = wpShape.getParameterv(paramFlag, numArray, noOfParameters);

         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }

         error = getParameterf(paramFlag, numArray);
         if (error == MV_NO_ERROR)
         {
            *noOfParameters = 1;
         }
         else
         {
            *noOfParameters = 0;
         }
         return error;

   }
}

mvErrorEnum mvWaypoint_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error;

   error = wpShape.setParameteri(paramFlag, index);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvWaypoint_V2::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error;

   error = wpShape.setParameter(paramFlag, option);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }

}

mvErrorEnum mvWaypoint_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error;

   error = wpShape.setParameterf(paramFlag, num);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvWaypoint_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   mvErrorEnum error;

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_POSITION:
         return setPosition(numArray[0], numArray[1], numArray[2]);
      default:
         error = wpShape.setParameterv(paramFlag, numArray);

         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }

         return setParameterf(paramFlag, numArray[0]);
   }
}

mvWaypoint_V2::~mvWaypoint_V2()
{

}

