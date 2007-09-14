/**
 * \file mvObstacle_V2.cpp
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
#include <mv/mvObstacle_V2.h>

mvObstacle_V2::mvObstacle_V2(mvOptionEnum oShape, mvOptionEnum oType,\
   mvFloat x, mvFloat y, mvFloat z)
{
   setShape(oShape);
   setType(oType);
   setPosition(x,y,z);
}

mvErrorEnum mvObstacle_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setPositionByVec3(temp);
}

mvErrorEnum mvObstacle_V2::setPositionByVec3(const mvVec3& value)
{
   obPosition = value;
   return MV_NO_ERROR;
}

mvFloat mvObstacle_V2::getX() const
{
   return obPosition.getX();
}

mvFloat mvObstacle_V2::getY() const
{
   return obPosition.getY();
}

mvFloat mvObstacle_V2::getZ() const
{
   return obPosition.getZ();
}

void mvObstacle_V2::setX(mvFloat x)
{
   obPosition.setX(x);
}

void mvObstacle_V2::setY(mvFloat y)
{
   obPosition.setY(y);
}

void mvObstacle_V2::setZ(mvFloat z)
{
   obPosition.setZ(z);
}

const mvVec3& mvObstacle_V2::getPosition() const
{
   return obPosition;
}

mvOptionEnum mvObstacle_V2::getType() const
{
   return obType;
}

mvErrorEnum mvObstacle_V2::setType(mvOptionEnum oType)
{
   switch(oType)
   {
      case MV_AIR_OBSTACLE:
      case MV_SOLID_OBSTACLE:
      case MV_LIQUID_OBSTACLE:
         obType = oType;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_OBSTACLE_TYPE;
   }
}

mvErrorEnum mvObstacle_V2::setShape(mvOptionEnum oShape)
{
   return obShape.setType(oShape);
}

mvConstShapePtr mvObstacle_V2::getShape() const
{
   return &obShape;
}

mvErrorEnum mvObstacle_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   mvErrorEnum error;

   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   // pass onto shape
   error = obShape.getParameteri(paramFlag, index);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_OBSTACLE_PARAMETER;
   }
}

mvErrorEnum mvObstacle_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      case MV_TYPE:
         *option = getType();
         return MV_NO_ERROR;
      default:
         // pass onto shape
         error = obShape.getParameter(paramFlag, option);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }
         else
         {
            return MV_INVALID_OBSTACLE_PARAMETER;
         }
   }
}

mvErrorEnum mvObstacle_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   mvErrorEnum error;

   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   // pass onto shape
   error = obShape.getParameterf(paramFlag, num);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_OBSTACLE_PARAMETER;
   }
}

mvErrorEnum mvObstacle_V2::getParameterv(mvParamEnum paramFlag,\
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
         // pass onto shape
         error = obShape.getParameterv(paramFlag, numArray, noOfParameters);
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

mvErrorEnum mvObstacle_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error;

   error = obShape.setParameteri(paramFlag, index);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_OBSTACLE_PARAMETER;
   }
}

mvErrorEnum mvObstacle_V2::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      case MV_TYPE:
         return setType(option);
      default:
         error = obShape.setParameter(paramFlag, option);

         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }
         else
         {
            return MV_INVALID_OBSTACLE_PARAMETER;
         }
   }
}

mvErrorEnum mvObstacle_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error;

   error = obShape.setParameterf(paramFlag, num);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_OBSTACLE_PARAMETER;
   }
}

mvErrorEnum mvObstacle_V2::setParameterv(mvParamEnum paramFlag,\
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
         error = obShape.setParameterv(paramFlag, numArray);

         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }

         return setParameterf(paramFlag, numArray[0]);
   }
}

mvObstacle_V2::~mvObstacle_V2()
{

}
