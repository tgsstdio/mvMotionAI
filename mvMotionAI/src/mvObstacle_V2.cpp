/**
 * \file mvObstacle_V2.cpp
 * \class mvObstacle
 *
 * \brief Static objects that the bodies (mvBody) should avoid (NOT IMPLEMENTED)
 * \author David Young
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

/** \brief blah blah
 *
 */
mvObstacle::mvObstacle(mvOptionEnum oShape, mvOptionEnum oType,\
   mvFloat x, mvFloat y, mvFloat z)
{
   setShape(oShape);
   setType(oType);
   setPosition(x,y,z);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setPosition(temp);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setPosition(const mvVec3& value)
{
   obPosition = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvFloat mvObstacle::getX() const
{
   return obPosition.getX();
}

/** \brief blah blah
 *
 */
mvFloat mvObstacle::getY() const
{
   return obPosition.getY();
}

/** \brief blah blah
 *
 */
mvFloat mvObstacle::getZ() const
{
   return obPosition.getZ();
}

/** \brief blah blah
 *
 */
void mvObstacle::setX(mvFloat x)
{
   obPosition.setX(x);
}

/** \brief blah blah
 *
 */
void mvObstacle::setY(mvFloat y)
{
   obPosition.setY(y);
}

/** \brief blah blah
 *
 */
void mvObstacle::setZ(mvFloat z)
{
   obPosition.setZ(z);
}

/** \brief blah blah
 *
 */
const mvVec3& mvObstacle::getPosition() const
{
   return obPosition;
}

/** \brief blah blah
 *
 */
mvOptionEnum mvObstacle::getType() const
{
   return obType;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setType(mvOptionEnum oType)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setShape(mvOptionEnum oShape)
{
   return obShape.setType(oShape);
}

/** \brief blah blah
 *
 */
mvConstShapePtr mvObstacle::getShape() const
{
   return &obShape;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::getParametero(mvParamEnum paramFlag,\
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
         error = obShape.getParametero(paramFlag, option);
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::getParameterv(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setParameteri(mvParamEnum paramFlag, mvIndex index)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      case MV_TYPE:
         return setType(option);
      default:
         error = obShape.setParametero(paramFlag, option);

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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setParameterf(mvParamEnum paramFlag, mvFloat num)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvObstacle::setParameterv(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvObstacle::~mvObstacle()
{

}
