/**
 * Copyright (c) 2006, 2007 David Young.
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
#include "mvShape.h"

static const mvCount MV_MAX_NO_OF_DIMENSIONS = 4;
static const mvIndex MV_CIRCULAR_RADIUS_INDEX = 0;
static const mvIndex MV_AACYLINDER_LENGTH_INDEX = 1;
static const mvIndex MV_AABOX_X_INDEX = 0;
static const mvIndex MV_AABOX_Y_INDEX = 1;
static const mvIndex MV_AABOX_Z_INDEX = 2;

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   mvCount noOfDimensions;
   mvIndex i;

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_SHAPE_DIMENSIONS:
         switch(shapeFlag)
         {
            case MV_AABOX:
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_ANY_PLANE:
            case MV_XY_PLANE:
            case MV_XZ_PLANE:
            case MV_YZ_PLANE:
               noOfDimensions = this->getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  dimensions[i] = numArray[i];
               }
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_PLANE_NORMAL:
         switch(shapeFlag)
         {
            case MV_ANY_PLANE:
               noOfDimensions = this->getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  dimensions[i] = numArray[i];
               }
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      default:
         return setParameterf(paramFlag, numArray[0]);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvIndex tempIndex;

   switch (paramFlag)
   {
      case MV_LENGTH:
         switch(shapeFlag)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_AACYLINDER_LENGTH_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_RADIUS:
         switch(shapeFlag)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_CIRCULAR_RADIUS_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_X_WIDTH:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_X_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_X_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_Y_HEIGHT:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Y_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_Y_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_Z_DEPTH:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Z_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_Z_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      default:
         return MV_INVALID_SHAPE_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_SHAPE:
         return setType(option);
      default:
         return MV_INVALID_SHAPE_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_SHAPE_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   mvErrorEnum error;
   mvCount noOfDimensions;
   mvIndex i;

   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }


   if (numArray == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_SHAPE_DIMENSIONS:
         switch(shapeFlag)
         {
            case MV_AABOX:
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
               noOfDimensions = this->getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  numArray[i] = dimensions[i];
               }
               *noOfParameters = noOfDimensions;
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_PLANE_NORMAL:
         switch(shapeFlag)
         {
            case MV_ANY_PLANE:
               noOfDimensions = this->getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  numArray[i] = dimensions[i];
               }
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      default:
         error = getParameterf(paramFlag,&numArray[0]);
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

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   mvIndex tempIndex;

   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_LENGTH:
         switch(shapeFlag)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_AACYLINDER_LENGTH_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_RADIUS:
         switch(shapeFlag)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_CIRCULAR_RADIUS_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_X_WIDTH:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_X_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            case MV_X_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_Y_HEIGHT:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Y_INDEX;
               return MV_NO_ERROR;
            case MV_Y_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      case MV_Z_DEPTH:
         switch(shapeFlag)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Z_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            case MV_Z_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INCORRECT_SHAPE_TYPE;
         }
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
   const
{
   if (option == MV_NULL)
      return MV_OPTION_ENUM_DEST_IS_NULL;

   switch (paramFlag)
   {
      case MV_SHAPE:
         *option = getType();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_SHAPE_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::getParameteri(mvParamEnum paramFlag, mvIndex* index)
   const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_NO_OF_SHAPE_DIMENSIONS:
         *index = getNoOfDimensions();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_SHAPE_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvOptionEnum mvShape::getType() const
{
   return shapeFlag;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvShape::~mvShape()
{
   if (dimensions != MV_NULL)
   {
      delete [] dimensions;
      dimensions = MV_NULL;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvShape::mvShape(mvOptionEnum sType)
{
   dimensions = MV_NULL;
   setType(sType);
}

mvShape::mvShape(const mvShape& rhs)
{
   mvOptionEnum shapeType = rhs.getType();
   setType(shapeType);
}

const mvShape& mvShape::operator=(const mvShape& rhs)
{
   mvOptionEnum shapeType = rhs.getType();
   setType(shapeType);
   return *this;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvCount mvShape::getNoOfDimensions() const
{
   static const mvCount MV_NO_OF_AABOX_DIMENSIONS = 3;
   static const mvCount MV_NO_OF_AACYLINDER_DIMENSIONS = 2;
   static const mvCount MV_NO_OF_SPHERE_DIMENSIONS = 1;
   static const mvCount MV_NO_OF_ANY_PLANE_DIMENSIONS = 3;
   static const mvCount MV_NO_DIMENSIONS = 0;

   switch(shapeFlag)
   {
      case MV_SPHERE:
         return MV_NO_OF_SPHERE_DIMENSIONS;
      case MV_AABOX:
         return MV_NO_OF_AABOX_DIMENSIONS;
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         return MV_NO_OF_AACYLINDER_DIMENSIONS;
      case MV_ANY_PLANE:
         return MV_NO_OF_ANY_PLANE_DIMENSIONS;
      default:
         return MV_NO_DIMENSIONS;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvShape::setType(mvOptionEnum type)
{
   mvFloat tempDims[MV_MAX_NO_OF_DIMENSIONS];
   mvIndex i;
   mvCount noOfDimensions;
   bool firstTime[MV_MAX_NO_OF_DIMENSIONS];

   for (i = 0; i < MV_MAX_NO_OF_DIMENSIONS; i++)
   {
      firstTime[i] = true;
   }

   if (dimensions != MV_NULL)
   {
      noOfDimensions = getNoOfDimensions();
      for (i = 0; i < noOfDimensions; i++)
      {
         tempDims[i] = dimensions[i];
         firstTime[i] = false;
      }
      delete [] dimensions;
      dimensions = MV_NULL;
   }

   switch(type)
   {
      case MV_AABOX:
      case MV_SPHERE:
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
      case MV_ANY_PLANE:
      case MV_XY_PLANE:
      case MV_XZ_PLANE:
      case MV_YZ_PLANE:
         shapeFlag = type;
         break;
      default:
         shapeFlag = MV_NON_SHAPE;
         return MV_INVALID_SHAPE_PARAMETER;
   }

   noOfDimensions = getNoOfDimensions();
   if (noOfDimensions > 0)
   {
      dimensions = new mvFloat[noOfDimensions];
   }

   for (i = 0; i < noOfDimensions; i++)
   {
      if (firstTime[i])
      {
         dimensions[i] = 1;
      }
      else
      {
         dimensions[i] = tempDims[i];
      }
   }

   return MV_NO_ERROR;
}
