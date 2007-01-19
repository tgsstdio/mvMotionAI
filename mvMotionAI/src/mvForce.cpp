/**
 * \file mvForce.cpp
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

#include "mvForce.h"

/**
      mvEnum forceType;
    Vec3 centralVector;
    mvFloat* variables;
      mvEnum enableFlag;
**/

static const mvIndex MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0;
static const mvIndex MV_FORCE_QUANTITY_VARIABLE_INDEX = 0;
static const mvIndex MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 1;
static const mvIndex MV_FORCE_GRAVITY_CONSTANT_VARIABLE_INDEX = 2;
static const mvIndex MV_FORCE_SPEED_VARIABLE_INDEX = 0;
static const mvCount MV_NO_OF_INVALID_OPTION_PARAMETERS = 0;

mvCount mvForce::getNoOfForceVariables()
{
   static const mvCount MV_NO_OF_GRAVITY_VARIABLES = 1;
   static const mvCount MV_NO_OF_UNIFORM_FORCE_VARIABLES = 1;
   static const mvCount MV_NO_OF_DIRECTION_POINT_FORCE_VARIABLES = 1;
   static const mvCount MV_NO_OF_GRAVITY_POINT_VARIABLES = 3;
   static const mvCount MV_NO_OF_FORCE_FIELD_VARIABLES = 0;
   static const mvCount MV_NO_OF_UNIFORM_SHIFT_VARIABLES = 1;
   static const mvCount MV_NO_OF_DIRECTION_POINT_SHIFT_VARIABLES = 1;
   static const mvCount MV_NO_OF_DRAG_SHIFT_VARIABLES = 1;
   static const mvCount MV_NO_OF_DRAG_ACCELERATION_VARIABLES = 1;
   static const mvCount MV_NO_OF_INVALID_FORCE_TYPE_VARIABLES = 0;
   static const mvCount MV_NO_OF_NULL_FORCE_TYPE_VARIABLES = 0;

   switch(forceType)
   {
      case MV_UNIFORM_ACCELERATION:
      case MV_GRAVITY:
         return MV_NO_OF_GRAVITY_VARIABLES;
      case MV_UNIFORM_FORCE:
         return MV_NO_OF_UNIFORM_FORCE_VARIABLES;
      case MV_DRAG_FORCE:
      case MV_UNIFORM_SHIFT:
         return MV_NO_OF_UNIFORM_SHIFT_VARIABLES;
      case MV_DRAG_SHIFT:
         return MV_NO_OF_DRAG_SHIFT_VARIABLES;
      case MV_DIRECTION_SHIFT_TO_POINT:
         return MV_NO_OF_DIRECTION_POINT_SHIFT_VARIABLES;
      case MV_DIRECTION_FORCE_TO_POINT:
         return MV_NO_OF_DIRECTION_POINT_FORCE_VARIABLES;
      case MV_GRAVITY_TO_POINT:
         return MV_NO_OF_GRAVITY_POINT_VARIABLES;
      case MV_FORCE_FIELD_ATTRACT:
      case MV_FORCE_FIELD_REPELL:
      case MV_FORCE_FIELD_FLUSH:
         return MV_NO_OF_FORCE_FIELD_VARIABLES;
      case MV_DRAG_ACCELERATION:
         return MV_NO_OF_DRAG_ACCELERATION_VARIABLES;
      case MV_NULL_ACCELERATION:
      case MV_NULL_ALL:
      case MV_NULL_DRAG:
      case MV_NULL_FIELD:
      case MV_NULL_FORCE:
      case MV_NULL_GRAVITY:
      case MV_NULL_SHIFT:
         return MV_NO_OF_NULL_FORCE_TYPE_VARIABLES;
      default:
         return MV_NO_OF_INVALID_FORCE_TYPE_VARIABLES;
   }
}

mvErrorEnum mvForce::initialiseForce(mvOptionEnum fType)
{
   mvFloat tempVariables[MV_MAX_NO_OF_FORCE_VARIABLES];
   mvIndex i;
   mvCount noOfVariables;

   if (variables != NULL)
   {
      // copies past variables over to new settings
      noOfVariables = getNoOfForceVariables();
      for (i = 0; i < noOfVariables; ++i)
      {
         tempVariables[i] = variables[i];
      }
      delete [] variables;
      variables = NULL;
   }

   switch(fType)
   {
      case MV_GRAVITY:
      case MV_UNIFORM_FORCE:
      case MV_DRAG_FORCE:
      case MV_FORCE_VECTOR:
      case MV_UNIFORM_SHIFT:
      case MV_DRAG_SHIFT:
      case MV_DIRECTION_SHIFT_TO_POINT:
      case MV_UNIFORM_ACCELERATION:
      case MV_DIRECTION_FORCE_TO_POINT:
      case MV_GRAVITY_TO_POINT:
      case MV_FORCE_FIELD_ATTRACT:
      case MV_FORCE_FIELD_REPELL:
      case MV_FORCE_FIELD_FLUSH:
      case MV_DRAG_ACCELERATION:
      case MV_NULL_ACCELERATION:
      case MV_NULL_ALL:
      case MV_NULL_DRAG:
      case MV_NULL_FIELD:
      case MV_NULL_FORCE:
      case MV_NULL_GRAVITY:
      case MV_NULL_SHIFT:
         forceType = fType;
         break;
      default:
         forceType = MV_NON_FORCE_TYPE;
         return MV_INVALID_FORCE_TYPE;
   }

   noOfVariables = getNoOfForceVariables();
   if (noOfVariables > 0)
   {
      variables = new mvFloat[noOfVariables];
   }
   for (i = 0; i < noOfVariables; ++i)
   {
      variables[i] = tempVariables[i];
   }
   return MV_NO_ERROR;
}

//mvEnum mvForce::initialiseForceVariables(mvEnum fType);

mvForce::mvForce(mvOptionEnum fType)
{
   variables = NULL;
   initialiseForce(fType);
   enableFlag = MV_TRUE;
   count = 0;
}

void mvForce::initLengthParameter(mvFloat length)
{
   switch(forceType)
   {
      case MV_UNIFORM_SHIFT:
      case MV_DRAG_SHIFT:
      case MV_DIRECTION_SHIFT_TO_POINT:
         variables[MV_FORCE_SPEED_VARIABLE_INDEX] = length;
         break;
      case MV_DRAG_ACCELERATION:
      case MV_UNIFORM_ACCELERATION:
      case MV_GRAVITY:
      case MV_GRAVITY_TO_POINT:
         variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX] = length;
         break;
      case MV_UNIFORM_FORCE:
      case MV_DRAG_FORCE:
      case MV_DIRECTION_FORCE_TO_POINT:
         variables[MV_FORCE_QUANTITY_VARIABLE_INDEX] = length;
         break;
      default:
         break;
   }
}

mvForce::mvForce(mvOptionEnum fType, mvFloat fx, mvFloat fy, mvFloat fz)
{
   mvFloat len = 0;

   variables = NULL;
   initialiseForce(fType);
   enableFlag = MV_TRUE;
   centralVector.set(fx,fy,fz);
   count = 0;
   /**/
   len = centralVector.length();
   if (len > 0.0)
      centralVector *= static_cast<mvFloat>(1.0)/len;
   initLengthParameter(len);
   /**/
}

mvOptionEnum mvForce::getEnableFlag() const
{
   return enableFlag;
}

mvOptionEnum mvForce::getType() const
{
   return forceType;
}

const mvVec3& mvForce::getVector() const
{
   return centralVector;
}

mvErrorEnum mvForce::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_INVALID_FORCE_PARAMETER;
}

mvForce::~mvForce()
{
   if (variables != NULL)
   {
      delete [] variables;
      variables = NULL;
   }
}

void mvForce::incrementCount()
{
   ++count;
}

void mvForce::decrementCount()
{
   if (count > 0)
      --count;
}

bool mvForce::isGlobalForce()
{
   static const mvCount MV_GLOBAL_FORCE_TOTAL = 0;

   return (count <= MV_GLOBAL_FORCE_TOTAL);
}

mvErrorEnum mvForce::getParameter(mvParamEnum paramFlag, mvOptionEnum* dest)
{
   if (dest != NULL)
   {
      switch(paramFlag)
      {
            //case MV_TYPE:
         case MV_IS_ENABLED:
            *dest = getEnableFlag();
            return MV_NO_ERROR;
         case MV_TYPE:
            *dest = getType();
            return MV_NO_ERROR;
         default:
            return MV_INVALID_FORCE_PARAMETER;
      }
   }
   else
      return MV_OPTION_ENUM_DEST_IS_NULL;

}

mvErrorEnum mvForce::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   //mvIndex  i;
   //mvCount noOfParameters;
   //mvFloat params[MV_MAX_NO_OF_PARAMETERS];
   mvFloat vectorLength;
   mvVec3 tempVector;
   bool isValid = false;

   if (numArray != NULL)
   {
      switch(paramFlag)
      {
         default:
            return setParameterf(paramFlag,numArray[0]);
            // check if parameter is valid for this force
            /*
            MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0,
            MV_FORCE_QUANTITY_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITY_CONSTAN_VARIABLE_INDEX = 1,
            MV_FORCE_SPEED_VARIABLE_INDEX = 0,
            */
         case MV_ACCELERATION_VECTOR:
            if (forceType == MV_UNIFORM_ACCELERATION || forceType == MV_GRAVITY)
            {
               tempVector.set(numArray[0],numArray[1],numArray[2]);
               vectorLength = tempVector.length();
               variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX] = vectorLength;
               centralVector = tempVector.normalize();
               isValid = true;
            }
            break;
         case MV_FORCE_VECTOR:
            if (forceType == MV_UNIFORM_FORCE || forceType == MV_DRAG_FORCE)
            {
               tempVector.set(numArray[0],numArray[1],numArray[2]);
               vectorLength = tempVector.length();
               variables[MV_FORCE_QUANTITY_VARIABLE_INDEX] = vectorLength;
               centralVector = tempVector.normalize();
               isValid = true;
            }
            break;
         case MV_POSITION:
            if (forceType == MV_GRAVITY_TO_POINT || forceType == MV_DIRECTION_FORCE_TO_POINT
                    || forceType == MV_DIRECTION_SHIFT_TO_POINT)
            {
               centralVector.set(numArray[0],numArray[1],numArray[2]);
               isValid = true;
            }
            break;
         case MV_VELOCITY:
            if (forceType == MV_UNIFORM_SHIFT || forceType == MV_DRAG_SHIFT)
            {
               tempVector.set(numArray[0],numArray[1],numArray[2]);
               vectorLength = tempVector.length();
               variables[MV_FORCE_SPEED_VARIABLE_INDEX] = vectorLength;
               centralVector = tempVector.normalize();
               isValid = true;
            }
            break;
         case MV_DIRECTION:
            if (forceType == MV_UNIFORM_FORCE ||  forceType == MV_UNIFORM_ACCELERATION
                    || forceType == MV_GRAVITY || forceType == MV_UNIFORM_SHIFT)
            {
               tempVector.set(numArray[0],numArray[1],numArray[2]);
               centralVector = tempVector.normalize();
               isValid = true;
            }
            break;
      }
      if (isValid)
      {
         return MV_NO_ERROR;
      }
      else
      {
         return MV_INVALID_FORCE_TYPE;
      }
   }
   else
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }
}

mvErrorEnum mvForce::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   //mvIndex i;
   //mvCount noOfParameters;
   //mvFloat params[MV_MAX_NO_OF_PARAMETERS];
   bool isValid = false;

   //noOfParameters = getNoOfParameters(paramFlag);
   switch(paramFlag)
   {
      default:
         return MV_INVALID_FORCE_PARAMETER;
         // check if parameter is valid for this force
         /*
         MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0,
         MV_FORCE_QUANTITY_VARIABLE_INDEX = 0,
         MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 0,
         MV_FORCE_GRAVITY_CONSTAN_VARIABLE_INDEX = 1,
         MV_FORCE_SPEED_VARIABLE_INDEX = 0,
         */
      case MV_ACCELERATION:
         if (forceType == MV_UNIFORM_ACCELERATION || forceType == MV_GRAVITY
                 || forceType == MV_DRAG_ACCELERATION || forceType == MV_GRAVITY_TO_POINT)
         {
            if (variables != NULL)
            {
               variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX] = num;
            }
            isValid = true;
         }
         break;
      case MV_FORCE_QUANTITY:
         if (forceType == MV_UNIFORM_FORCE || forceType == MV_DRAG_FORCE
                 || forceType == MV_DIRECTION_FORCE_TO_POINT)
         {
            if (variables != NULL)
            {
               variables[MV_FORCE_QUANTITY_VARIABLE_INDEX] = num;
            }
            isValid = true;
         }
         break;
      case MV_MASS:
         if (forceType == MV_GRAVITY_TO_POINT)
         {
            if (variables != NULL)
            {
               variables[MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX] = num;
            }
            isValid = true;
         }
         break;
      case MV_CONSTANT:
         if (forceType == MV_GRAVITY_TO_POINT)
         {
            if (variables != NULL)
            {
               variables[MV_FORCE_GRAVITY_CONSTANT_VARIABLE_INDEX] = num;
            }
            isValid = true;
         }
         break;
      case MV_SPEED:
         if (forceType == MV_DIRECTION_SHIFT_TO_POINT || forceType == MV_UNIFORM_SHIFT
                 || forceType == MV_DRAG_SHIFT)
         {
            if (variables != NULL)
            {
               variables[MV_FORCE_SPEED_VARIABLE_INDEX] = num;
            }
            isValid = true;
         }
         break;
   }
   if (isValid)
   {
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_FORCE_TYPE;
   }
}

mvErrorEnum mvForce::getParameterf(mvParamEnum paramFlag, mvFloat* dest)
{
   //mvIndex i;
   //mvCount noOfParameters;
   //mvFloat params[MV_MAX_NO_OF_PARAMETERS];
   bool isValid = false;

   //noOfParameters = getNoOfParameters(paramFlag);
   if (dest != NULL)
   {
      switch(paramFlag)
      {
         default:
            return MV_INVALID_FORCE_PARAMETER;
            // check if parameter is valid for this force
            /*
            MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0,
            MV_FORCE_QUANTITY_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITY_CONSTAN_VARIABLE_INDEX = 1,
            MV_FORCE_SPEED_VARIABLE_INDEX = 0,
            */
         case MV_ACCELERATION:
            if (forceType == MV_UNIFORM_ACCELERATION || forceType == MV_GRAVITY
                    || forceType == MV_DRAG_ACCELERATION || forceType == MV_GRAVITY_TO_POINT)
            {
               if (variables != NULL)
               {
                  dest[0] = variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX];
               }
               isValid = true;
            }
            break;
         case MV_FORCE_QUANTITY:
            if (forceType == MV_UNIFORM_FORCE || forceType == MV_DRAG_FORCE
                    || forceType == MV_DIRECTION_FORCE_TO_POINT)
            {
               if (variables != NULL)
               {
                  dest[0] = variables[MV_FORCE_QUANTITY_VARIABLE_INDEX];
               }
               isValid = true;
            }
            break;
         case MV_MASS:
            if (forceType == MV_GRAVITY_TO_POINT)
            {
               if (variables != NULL)
               {
                  dest[0] = variables[MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX];
               }
               isValid = true;
            }
            break;
         case MV_CONSTANT:
            if (forceType == MV_GRAVITY_TO_POINT)
            {
               if (variables != NULL)
               {
                  dest[0] = variables[MV_FORCE_GRAVITY_CONSTANT_VARIABLE_INDEX];
               }
               isValid = true;
            }
            break;
         case MV_SPEED:
            if (forceType == MV_DIRECTION_SHIFT_TO_POINT || forceType == MV_UNIFORM_SHIFT
                    || forceType == MV_DRAG_SHIFT)
            {
               if (variables != NULL)
               {
                  dest[0] = variables[MV_FORCE_SPEED_VARIABLE_INDEX];
               }
               isValid = true;
            }
            break;
      }
      /**/
      if (isValid)
      {
         return MV_NO_ERROR;
      }
      else
      {
         return MV_INVALID_FORCE_TYPE;
      }
   }
   else
   {
      return MV_FLOAT_DEST_IS_NULL;
   }
}

mvErrorEnum mvForce::getParameterv(mvParamEnum paramFlag, mvFloat* dest, mvCount* size)
{
   static const mvCount MV_MAX_NO_OF_FORCE_PARAMETERS = 3;
   static const mvCount MV_FAILED_GETPARAMETERF_NO_OF_PARAMETERS = 0;

   mvIndex i;
   mvCount noOfParameters;
   mvFloat vectorLength;
   mvFloat params[MV_MAX_NO_OF_FORCE_PARAMETERS];
   bool isValid = false;
   mvErrorEnum error = MV_NO_ERROR;

   if (size == NULL)
      return MV_COUNT_DEST_IS_NULL;

   if (dest != NULL)
   {
      switch(paramFlag)
      {
         default:
            error = getParameterf(paramFlag,dest);

            if (error == MV_NO_ERROR)
            {
               *size = 1;
               return MV_NO_ERROR;
            }
            else
            {
               *size = MV_FAILED_GETPARAMETERF_NO_OF_PARAMETERS;
               return error;
            }
            // check if parameter is valid for this force
            /*
            MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0,
            MV_FORCE_QUANTITY_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 0,
            MV_FORCE_GRAVITY_CONSTAN_VARIABLE_INDEX = 1,
            MV_FORCE_SPEED_VARIABLE_INDEX = 0,
            */
         case MV_ACCELERATION_VECTOR:
            if (forceType == MV_UNIFORM_ACCELERATION || forceType == MV_GRAVITY)
            {
               vectorLength = variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX];
               params[0] = vectorLength * centralVector.getX();
               params[1] = vectorLength * centralVector.getY();
               params[2] = vectorLength * centralVector.getZ();
               //puts("hello");
               isValid = true;
            }
            break;
         case MV_FORCE_VECTOR:
            if (forceType == MV_UNIFORM_FORCE || forceType == MV_DRAG_FORCE)
            {
               vectorLength = variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX];
               params[0] = vectorLength * centralVector.getX();
               params[1] = vectorLength * centralVector.getY();
               params[2] = vectorLength * centralVector.getZ();
               isValid = true;
            }
            break;
         case MV_POSITION:
            if (forceType == MV_GRAVITY_TO_POINT || forceType == MV_DIRECTION_FORCE_TO_POINT
                    || forceType == MV_DIRECTION_SHIFT_TO_POINT)
            {
               params[0] = centralVector.getX();
               params[1] = centralVector.getY();
               params[2] = centralVector.getZ();
               isValid = true;
            }
            break;
         case MV_VELOCITY:
            if (forceType == MV_UNIFORM_SHIFT || forceType == MV_DRAG_SHIFT)
            {
               vectorLength = variables[MV_FORCE_ACCELERATION_VARIABLE_INDEX];
               params[0] = vectorLength * centralVector.getX();
               params[1] = vectorLength * centralVector.getY();
               params[2] = vectorLength * centralVector.getZ();
               isValid = true;
            }
            break;
         case MV_DIRECTION:
            if (forceType == MV_UNIFORM_FORCE ||  forceType == MV_UNIFORM_ACCELERATION
                    || forceType == MV_GRAVITY || forceType == MV_UNIFORM_SHIFT)
            {
               params[0] = centralVector.getX();
               params[1] = centralVector.getY();
               params[2] = centralVector.getZ();
               isValid = true;
            }
            break;
      }
      // copies data from mvForce into destination array
      noOfParameters = getNoOfParameters(paramFlag);
      if (isValid)
      {
         *size = noOfParameters;
         for (i = 0; i < noOfParameters; ++i)
         {
            dest[i] = params[i];
         }
         return MV_NO_ERROR;
      }
      else
      {
         *size = MV_NO_OF_INVALID_OPTION_PARAMETERS;
         noOfParameters = MV_NO_OF_INVALID_OPTION_PARAMETERS;
         return MV_INVALID_FORCE_TYPE;
      }
   }
   else
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }
}

mvCount mvForce::getNoOfParameters(mvParamEnum paramFlag)
{
   static const mvCount MV_NO_OF_ACCELERATION_PARAMETERS = 1;
   static const mvCount MV_NO_OF_ACCELERATION_VECTOR_PARAMETERS = 3;
   static const mvCount MV_NO_OF_FORCE_QUANTITY_PARAMETERS = 1;
   static const mvCount MV_NO_OF_FORCE_VECTOR_PARAMETERS = 3;
   static const mvCount MV_NO_OF_GRAVITIONAL_MASS_PARAMETERS = 1;
   static const mvCount MV_NO_OF_GRAVITY_CONSTANT_PARAMETERS = 1;
   static const mvCount MV_NO_OF_POSITION_PARAMETERS = 3;
   static const mvCount MV_NO_OF_SPEED_PARAMETERS = 1;
   static const mvCount MV_NO_OF_VELOCITY_PARAMETERS = 3;
   //static const mvCount MV_NO_OF_MASS_PARAMETERS = 1;
   //static const mvCount MV_NO_OF_NULL_FORCE_TYPE_PARAMETERS = 0;

   switch(paramFlag)
   {
      default:
         return MV_NO_OF_INVALID_OPTION_PARAMETERS;
      case MV_ACCELERATION:
         return MV_NO_OF_ACCELERATION_PARAMETERS;
      case MV_ACCELERATION_VECTOR:
         return MV_NO_OF_ACCELERATION_VECTOR_PARAMETERS;
      case MV_FORCE_QUANTITY:
         return MV_NO_OF_FORCE_QUANTITY_PARAMETERS;
      case MV_FORCE_VECTOR:
         return MV_NO_OF_FORCE_VECTOR_PARAMETERS;
      case MV_MASS:
         return MV_NO_OF_GRAVITIONAL_MASS_PARAMETERS;
      case MV_CONSTANT:
         return MV_NO_OF_GRAVITY_CONSTANT_PARAMETERS;
      case MV_POSITION:
         return MV_NO_OF_POSITION_PARAMETERS;
      case MV_SPEED:
         return MV_NO_OF_SPEED_PARAMETERS;
      case MV_VELOCITY:
         return MV_NO_OF_VELOCITY_PARAMETERS;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvForce::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_FORCE_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvForce::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_FORCE_PARAMETER;
}


