/**
 * \file mvWaypoint_V2.cpp
 * \class mvWaypoint
 * \brief A point/volume in mvMotionAI space
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
#include <mv/mvWaypoint_V2.h>

/** \brief blah blah
 *
 */
mvWaypoint::mvWaypoint(mvOptionEnum wshape, mvFloat x, mvFloat y,\
   mvFloat z)
{
   setPosition(x,y,z);
   setShape(wshape);
}

/** \brief blah blah
 *
 */
mvFloat mvWaypoint::getX() const
{
   return wpPosition.getX();
}

/** \brief blah blah
 *
 */
mvFloat mvWaypoint::getY() const
{
   return wpPosition.getY();
}

/** \brief blah blah
 *
 */
mvFloat mvWaypoint::getZ() const
{
   return wpPosition.getZ();
}

/** \brief blah blah
 *
 */
void mvWaypoint::setX(mvFloat x)
{
   wpPosition.setX(x);
}

/** \brief blah blah
 *
 */
void mvWaypoint::setY(mvFloat y)
{
   wpPosition.setY(y);
}

/** \brief blah blah
 *
 */
void mvWaypoint::setZ(mvFloat z)
{
   wpPosition.setZ(z);
}

/** \brief blah blah
 *
 */
const mvVec3& mvWaypoint::getPosition() const
{
   return wpPosition;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   const mvVec3 temp(x,y,z);
   return setPosition(temp);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setPosition(const mvVec3& value)
{
   wpPosition = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setShape(mvOptionEnum shape)
{
   return wpShape.setType(shape);
}

/** \brief blah blah
 *
 */
mvConstShapePtr mvWaypoint::getShape() const
{
   return &wpShape;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   mvErrorEnum error;

   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   error = wpShape.getParametero(paramFlag, option);
   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::getParameterv(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setParameteri(mvParamEnum paramFlag, mvIndex index)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error;

   error = wpShape.setParametero(paramFlag, option);

   if (error != MV_INVALID_SHAPE_PARAMETER)
   {
      return error;
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }

}

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setParameterf(mvParamEnum paramFlag, mvFloat num)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWaypoint::setParameterv(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvWaypoint::~mvWaypoint()
{

}

