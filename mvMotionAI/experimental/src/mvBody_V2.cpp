/**
 * \file mvBody_V2.cpp
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

#include "mvBody_V2.h"
#include <new>

/** \brief mvBodyV2 constructor
 * This is a rewrite of mvBody
 */
mvBody_V2::mvBody_V2(mvOptionEnum bType, mvOptionEnum shape, mvFloat x,\
   mvFloat y, mvFloat z) :  bodyPosition(x,y,z)
{
   // boolean flags are true
   enabled = true;
   applyForces = true;
   applyShifts = true;
   applyAccelerations = true;
   applyGravity = true;
   applyCollisions = true;
   applyAllForces = true;

   //acceleration = 1.0
   setAcceleration(1);
   // deaccleation = 1
   setDeceleration(1);
   // mass = 1.0
   setMass(1);
   // current speed = 0
   setSpeed(0);
   // max speed = 5
   setMaxSpeed(5);
   // user data = MV_NULL
   bodyUserDataPtr = MV_NULL;

   // default direction 1.0
   //bodyDirection.set(0,0,1);

   // face direction
   faceDirection.set(0,0,1);
   // shape
   setShape(shape);

   // domain
   bodyDomain = MV_FULL_3D;
   bodyDomainVariables = MV_NULL;
   setDomain(bodyDomain);
   //TODO : initialises variables ... add more later

}

mvVec3 mvBody_V2::getBodyDirection() const
{
   return bodyVelocity.normalize();
}

mvErrorEnum mvBody_V2::setBodyDirection(mvFloat x, mvFloat y, mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setBodyDirection(temp);
}

mvErrorEnum mvBody_V2::setBodyDirection(const mvVec3& value)
{
   mvVec3 newNormalized = value.normalize();
   mvFloat bodySpeed = getSpeed();
   bodyVelocity = value;
   bodyVelocity *= bodySpeed;
   return MV_NO_ERROR;
}

mvBody_V2::~mvBody_V2()
{
   if (bodyDomainVariables != MV_NULL)
   {
      delete [] bodyDomainVariables;
      bodyDomainVariables = MV_NULL;
   }
}

mvErrorEnum mvBody_V2::setDomain(mvOptionEnum bDomain)
{
   mvFloat tempDomVars[MV_MAX_NO_OF_PARAMETERS];
   mvIndex i;
   mvCount noOfVariables;

   if (bodyDomainVariables != MV_NULL)
   {
      noOfVariables = getNoOfDomainVariables();
      for (i = 0; i < noOfVariables; ++i)
      {
         tempDomVars[i] = bodyDomainVariables[i];
      }
      delete [] bodyDomainVariables;
      bodyDomainVariables = MV_NULL;
   }

   switch(bDomain)
   {
      case MV_ANY_PLANE:
      case MV_ANY_LINE:
      case MV_FULL_3D:
      case MV_XY_PLANE:
      case MV_XZ_PLANE:
      case MV_YZ_PLANE:
      case MV_X_AXIS_ONLY:
      case MV_Y_AXIS_ONLY:
      case MV_Z_AXIS_ONLY:
         bodyDomain = bDomain;
         break;
      default:
         bodyDomain = MV_NO_DOMAIN_APPLIED;
         return MV_INVALID_DOMAIN;
   }

   noOfVariables = getNoOfDomainVariables();
   if (noOfVariables > 0)
   {
      bodyDomainVariables = new (std::nothrow) mvFloat[noOfVariables];
      if (bodyDomainVariables == MV_NULL)
      {
         return MV_INVALID_MEMORY_ALLOCATION;
      }
   }

   for (i = 0; i < noOfVariables; ++i)
   {
      bodyDomainVariables[i] = tempDomVars[i];
   }

   return MV_NO_ERROR;
}

const mvFloat* mvBody_V2::getDomainVariables() const
{
   return bodyDomainVariables;
}

mvCount mvBody_V2::getNoOfDomainVariables() const
{
   static const mvCount MV_NO_OF_FULL_3D_VARIABLES = 0;
   static const mvCount MV_NO_OF_XY_PLANE_VARIABLES = 0;
   static const mvCount MV_NO_OF_XZ_PLANE_VARIABLES = 0;
   static const mvCount MV_NO_OF_YZ_PLANE_VARIABLES = 0;
   static const mvCount MV_NO_OF_X_AXIS_ONLY_VARIABLES = 0;
   static const mvCount MV_NO_OF_Y_AXIS_ONLY_VARIABLES = 0;
   static const mvCount MV_NO_OF_Z_AXIS_ONLY_VARIABLES = 0;
   static const mvCount MV_NO_OF_ANY_PLANE_VARIABLES = 3;
   static const mvCount MV_NO_OF_ANY_LINE_VARIABLES = 3;
   static const mvCount MV_INVALID_DOMAIN_NO_OF_VARIABLES = 0;

   switch (bodyDomain)
   {
      case MV_FULL_3D:
         return MV_NO_OF_FULL_3D_VARIABLES;
      case MV_XY_PLANE:
         return MV_NO_OF_XY_PLANE_VARIABLES;
      case MV_XZ_PLANE:
         return MV_NO_OF_XZ_PLANE_VARIABLES;
      case MV_YZ_PLANE:
         return MV_NO_OF_YZ_PLANE_VARIABLES;
      case MV_X_AXIS_ONLY:
         return MV_NO_OF_X_AXIS_ONLY_VARIABLES;
      case MV_Y_AXIS_ONLY:
         return MV_NO_OF_Y_AXIS_ONLY_VARIABLES;
      case MV_Z_AXIS_ONLY:
         return MV_NO_OF_Z_AXIS_ONLY_VARIABLES;
      case MV_ANY_PLANE:
         return MV_NO_OF_ANY_PLANE_VARIABLES;
      case MV_ANY_LINE:
         return MV_NO_OF_ANY_LINE_VARIABLES;
      default:
         return MV_INVALID_DOMAIN_NO_OF_VARIABLES;
   }
}

mvOptionEnum mvBody_V2::getDomain() const
{
   return bodyDomain;
}

mvOptionEnum mvBody_V2::getType() const
{
   return bodyType;
}

mvErrorEnum mvBody_V2::setType(mvOptionEnum bType)
{
   switch(bType)
   {
      case MV_VEHICLE:
      case MV_PARTICLE:
      case MV_DUAL_BODY:
         bodyType = bType;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_TYPE;
   }
}

mvConstShapePtr mvBody_V2::getShape() const
{
   return &bodyShape;
}

mvErrorEnum mvBody_V2::setShape(mvOptionEnum bShape)
{
   return bodyShape.setType(bShape);
}

void* mvBody_V2::getUserData() const
{
   return bodyUserDataPtr;
}

void mvBody_V2::setUserData(void* usrData)
{
   bodyUserDataPtr = usrData;
}

mvFloat mvBody_V2::getX() const
{
   return bodyPosition.getX();
}

mvFloat mvBody_V2::getY() const
{
   return bodyPosition.getY();
}

mvFloat mvBody_V2::getZ() const
{
   return bodyPosition.getZ();
}

const mvVec3& mvBody_V2::getPosition() const
{
   return bodyPosition;
}

mvErrorEnum mvBody_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   setX(x);
   setY(y);
   setZ(z);
   return MV_NO_ERROR;
}

const mvVec3& mvBody_V2::getFaceDirection() const
{
   return faceDirection;
}

mvErrorEnum mvBody_V2::setFaceDirection(mvFloat x, mvFloat y,mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setFaceDirectionByVec3(temp);
}

mvErrorEnum mvBody_V2::setFaceDirectionByVec3(const mvVec3& value)
{
   faceDirection = value;
   return MV_NO_ERROR;
}

mvFloat mvBody_V2::getSpeed() const
{
   return bodyVelocity.length();
}

mvErrorEnum mvBody_V2::setSpeed(mvFloat num)
{
   if (num > 0)
   {
      mvVec3 unitVelocity = bodyVelocity.normalize();
      bodyVelocity = unitVelocity;
      bodyVelocity *= num;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
}

mvFloat mvBody_V2::getMaxSpeed() const
{
   return bodyMaxSpeed;
}

mvErrorEnum mvBody_V2::setMaxSpeed(mvFloat num)
{
   bodyMaxSpeed = num;
   return MV_NO_ERROR;
}

mvErrorEnum mvBody_V2::setMass(mvFloat num)
{
   if (num >= 0)
   {
      bodyMass = num;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
}

mvFloat mvBody_V2::getMass() const
{
   return bodyMass;
}

mvFloat mvBody_V2::getDeceleration() const
{
   return bodyDeaccel;
}

mvErrorEnum mvBody_V2::setDeceleration(mvFloat dAccel)
{
   bodyDeaccel = dAccel;
   return MV_NO_ERROR;
}

mvFloat mvBody_V2::getAcceleration() const
{
   return bodyAccel;
}

mvErrorEnum mvBody_V2::setAcceleration(mvFloat accel)
{
   bodyAccel = accel;
   return MV_NO_ERROR;
}


mvVec3 mvBody_V2::getFinalDirection() const
{
   mvVec3 temp = finalVelocity.normalize();
   return temp;
}

/*
mvErrorEnum mvBody_V2::setFinalDirection(mvFloat fx, mvFloat fy, mvFloat fz)
{
   mvVec3 temp(fx,fy,fz);
   return setFinalDirectionByVec3(temp);
}
*/

mvErrorEnum mvBody_V2::setFinalDirection(const mvVec3& value)
{
   faceDirection = value;
   return MV_NO_ERROR;
}

const mvVec3& mvBody_V2::getFinalVelocity() const
{
   return finalVelocity;
}

mvErrorEnum mvBody_V2::setFinalVelocity(mvFloat x, mvFloat y, mvFloat z)
{
   finalVelocity.set(x,y,z);
   return MV_NO_ERROR;
}

mvErrorEnum mvBody_V2::setVelocity(mvFloat vx, mvFloat vy, mvFloat vz)
{
   bodyVelocity.set(vx,vy,vz);
   return MV_NO_ERROR;
}

mvErrorEnum mvBody_V2::setVelocity(const mvVec3& value)
{
   bodyVelocity = value;
   return MV_NO_ERROR;
}

mvErrorEnum mvBody_V2::setFinalVelocity(const mvVec3& value)
{
   finalVelocity = value;
   return MV_NO_ERROR;
}

void mvBody_V2::setPosition(const mvVec3& value)
{
   bodyPosition = value;
}

const mvVec3& mvBody_V2::getVelocity() const
{
   return bodyVelocity;
}

mvFloat mvBody_V2::getFinalSpeed() const
{
   return finalVelocity.length();
}

// parameter functions
mvErrorEnum mvBody_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   mvErrorEnum error;

   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_NO_OF_DOMAIN_VARIABLES:
         *index = getNoOfDomainVariables();
         return MV_NO_ERROR;
      default:
         // shape parameter
         error = bodyShape.getParameteri(paramFlag,index);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }
         else
         {
            return MV_INVALID_BODY_PARAMETER;
         }
   }
}

mvErrorEnum mvBody_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   mvErrorEnum error;

   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_TYPE:
         *option = getType();
         return MV_NO_ERROR;
      case MV_DOMAIN:
         *option = getDomain();
         return MV_NO_ERROR;
      case MV_IS_ENABLED:
         if (enabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_FORCES:
         if (applyForces)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_SHIFTS:
         if (applyShifts)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ACCELERATIONS:
         if (applyAccelerations)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_GRAVITY:
         if (applyGravity)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_COLLISIONS:
         if (applyCollisions)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_FORCES:
         if (applyAllForces)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_DRAG_FORCES:
         if (applyAllDragForces)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:

         // check shape then return error
         error = bodyShape.getParameter(paramFlag,option);

         if (error == MV_INVALID_SHAPE_PARAMETER)
         {
            return MV_INVALID_BODY_PARAMETER;
         }
         else
         {
            return error;
         }
   }

}

mvErrorEnum mvBody_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   mvErrorEnum error;

   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_SPEED:
         *num = getSpeed();
         return MV_NO_ERROR;
      case MV_MAX_SPEED:
         *num = getMaxSpeed();
         return MV_NO_ERROR;
      case MV_ACCELERATION:
         *num = getAcceleration();
         return MV_NO_ERROR;
      case MV_DECELERATION:
         *num = getDeceleration();
         return MV_NO_ERROR;
      case MV_MASS:
         *num = getMass();
         return MV_NO_ERROR;
      case MV_FINAL_SPEED:
         *num = getFinalSpeed();
         return MV_NO_ERROR;
      default:
         // check shape then return error
         error = bodyShape.getParameterf(paramFlag, num);

         if (error == MV_INVALID_SHAPE_PARAMETER)
         {
            return MV_INVALID_BODY_PARAMETER;
         }
         else
         {
            return error;
         }
   }
}

mvErrorEnum mvBody_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   mvErrorEnum error;
   mvOptionEnum option;
   mvVec3 resultVector;
   mvCount arrayCount, i;

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
      case MV_TORQUE:
         resultVector = getBodysTorque();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_ROTATION:
         resultVector = getRotation();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_OMEGA:
         resultVector = getBodysOmega();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FINAL_FORCE:
         resultVector = getFinalForce();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FINAL_TORQUE:
         resultVector = getFinalTorque();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FINAL_OMEGA:
         resultVector = getFinalOmega();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FORCE_VECTOR:
         resultVector = getBodysForce();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_VELOCITY:
         resultVector = getVelocity();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_POSITION:
         resultVector = getPosition();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_DIRECTION:
         resultVector = bodyVelocity.normalize();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FACE_DIRECTION:
         resultVector = getFaceDirection();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_DOMAIN_VARIABLES:
         arrayCount = getNoOfDomainVariables();
         for (i = 0; i < arrayCount; i++)
         {
            numArray[i] = bodyDomainVariables[i];
         }
         *noOfParameters = arrayCount;
         return MV_NO_ERROR;
      case MV_FINAL_VELOCITY:
         resultVector = getFinalVelocity();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FINAL_DIRECTION:
         resultVector = finalVelocity.normalize();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_DOMAIN_NORMAL:
         option = getDomain();
         switch(option)
         {
            default:
               *noOfParameters = 0;
               return MV_INVALID_DOMAIN;
            // is right handed
            // TODO: left hand conversion
            case MV_XZ_PLANE:
               numArray[0] = 0;
               numArray[1] = 1;
               numArray[2] = 0;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_XY_PLANE:
               numArray[0] = 0;
               numArray[1] = 0;
               numArray[2] = 1;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_YZ_PLANE:
               numArray[0] = 1;
               numArray[1] = 0;
               numArray[2] = 0;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_ANY_PLANE:
               arrayCount = 3;
               for (i = 0; i < arrayCount; i++)
               {
                  numArray[i] = bodyDomainVariables[i];
               }
               *noOfParameters = arrayCount;
               return MV_NO_ERROR;
         }
      case MV_LINE_VECTOR:
         option = getDomain();
         switch(option)
         {
            default:
               *noOfParameters = 0;
               return MV_INVALID_DOMAIN;
            // is right handed
            // TODO: left hand conversion
            case MV_X_AXIS_ONLY:
               numArray[0] = 1;
               numArray[1] = 0;
               numArray[2] = 0;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_Y_AXIS_ONLY:
               numArray[0] = 0;
               numArray[1] = 1;
               numArray[2] = 0;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_Z_AXIS_ONLY:
               numArray[0] = 0;
               numArray[1] = 0;
               numArray[2] = 1;
               *noOfParameters = 3;
               return MV_NO_ERROR;
            case MV_ANY_LINE:
               arrayCount = 3;
               for (i = 0; i < arrayCount; i++)
               {
                  numArray[i] = bodyDomainVariables[i];
               }
               *noOfParameters = arrayCount;
               return MV_NO_ERROR;
         }
      default:
         // shape's getParameterv
         error = bodyShape.getParameterv(paramFlag, numArray, noOfParameters);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }

         // body getParameterv
         error = getParameterf(paramFlag, &numArray[0]);
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

mvErrorEnum mvBody_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error;

   // shape set parameter
   error = bodyShape.setParameteri(paramFlag, index);

   if (error == MV_INVALID_SHAPE_PARAMETER)
   {
      return MV_INVALID_BODY_PARAMETER;
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvBody_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      default:

         // shape
         error = bodyShape.setParameter(paramFlag, option);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }
         else
         {
            return MV_INVALID_BODY_PARAMETER;
         }
      case MV_SHAPE:
         return setShape(option);
      case MV_DOMAIN:
         return setDomain(option);
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            enabled = false;
         }
         else
         {
            enabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_FORCES:
         if (option == MV_FALSE)
         {
            applyForces = false;
         }
         else
         {
            applyForces = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_SHIFTS:
         if (option == MV_FALSE)
         {
            applyShifts = false;
         }
         else
         {
            applyShifts = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ACCELERATIONS:
         if (option == MV_FALSE)
         {
            applyAccelerations = false;
         }
         else
         {
            applyAccelerations = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_GRAVITY:
         if (option == MV_FALSE)
         {
            applyGravity = false;
         }
         else
         {
            applyGravity = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_COLLISIONS:
         if (option == MV_FALSE)
         {
            applyCollisions = false;
         }
         else
         {
            applyCollisions = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_FORCES:
         if (option == MV_FALSE)
         {
            applyAllForces = false;
         }
         else
         {
            applyAllForces = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_DRAG_FORCES:
         if (option == MV_FALSE)
         {
            applyAllDragForces = false;
         }
         else
         {
            applyAllDragForces = true;
         }
         return MV_NO_ERROR;
   }
}

mvErrorEnum mvBody_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error;
   mvVec3 tempVector;

   switch (paramFlag)
   {
      case MV_SPEED:
         return setSpeed(num);
      case MV_MAX_SPEED:
         return setMaxSpeed(num);
      case MV_ACCELERATION:
         return setAcceleration(num);
      case MV_DECELERATION:
         return setDeceleration(num);
      case MV_MASS:
         return setMass(num);
      case MV_FINAL_SPEED:
         tempVector = getFinalDirection();
         tempVector *= num;
         setFinalVelocity(tempVector);
         return MV_NO_ERROR;
      default:
         // shape set parameterf
         error = bodyShape.setParameterf(paramFlag, num);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }
         else
         {
            return MV_INVALID_BODY_PARAMETER;
         }
   }
}

mvErrorEnum mvBody_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   mvErrorEnum error;
   mvOptionEnum option;
   mvIndex i;
   mvCount arrayCount;
   mvVec3 tempVector;

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_FORCE_VECTOR:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setBodysForce(tempVector);
         return MV_NO_ERROR;
      case MV_TORQUE:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setBodysTorque(tempVector);
         return MV_NO_ERROR;
      case MV_FINAL_VELOCITY:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setFinalVelocity(tempVector);
         return MV_NO_ERROR;
      case MV_FINAL_TORQUE:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setFinalTorque(tempVector);
         return MV_NO_ERROR;
      case MV_ROTATION:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setRotation(tempVector);
         return MV_NO_ERROR;
      case MV_OMEGA:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setBodysOmega(tempVector);
         return MV_NO_ERROR;
      case MV_FINAL_OMEGA:
         tempVector.set(numArray[0],numArray[1],numArray[2]);
         setFinalOmega(tempVector);
         return MV_NO_ERROR;
      case MV_VELOCITY:
         return setVelocity(numArray[0],numArray[1],numArray[2]);
      case MV_POSITION:
         return setPosition(numArray[0],numArray[1],numArray[2]);
      case MV_DIRECTION:
         return setBodyDirection(numArray[0],numArray[1],numArray[2]);
      case MV_FACE_DIRECTION:
         return setFaceDirection(numArray[0],numArray[1],numArray[2]);
      case MV_DOMAIN_NORMAL:
      case MV_LINE_VECTOR:
      case MV_DOMAIN_VARIABLES:
         option = getDomain();
         switch(option)
         {
            case MV_ANY_LINE:
            case MV_ANY_PLANE:
               arrayCount = getNoOfDomainVariables();
               for (i = 0; i < arrayCount; i++)
               {
                  bodyDomainVariables[i] = numArray[i];
               }
               return MV_NO_ERROR;
            default:
               return MV_INVALID_DOMAIN;
         }
      default:

         // shape setParamterv
         error = bodyShape.setParameterv(paramFlag, numArray);
         if (error != MV_INVALID_SHAPE_PARAMETER)
         {
            return error;
         }

         return setParameterf(paramFlag,numArray[0]);
   }
}

void mvBody_V2::setX(mvFloat x)
{
   bodyPosition.setX(x);
}

void mvBody_V2::setY(mvFloat y)
{
   bodyPosition.setY(y);
}

void mvBody_V2::setZ(mvFloat z)
{
   bodyPosition.setZ(z);
}

const mvVec3& mvBody_V2::getFinalForce() const
{
   return finalForceVector;
}

void mvBody_V2::setFinalForce(const mvVec3& vec)
{
   finalForceVector = vec;
}

const mvVec3& mvBody_V2::getBodysForce() const
{
   return bodysForceVector;
}

void mvBody_V2::setBodysForce(const mvVec3& vec)
{
   bodysForceVector = vec;
}

const mvVec3& mvBody_V2::getFinalTorque() const
{
   return finalTorque;
}

void mvBody_V2::setFinalTorque(const mvVec3& vec)
{
   finalTorque = vec;
}

const mvVec3& mvBody_V2::getBodysTorque() const
{
   return bodysTorque;
}

void mvBody_V2::setBodysTorque(const mvVec3& vec)
{
   bodysTorque = vec;
}

const mvVec3& mvBody_V2::getFinalOmega() const
{
   return finalOmega;
}

void mvBody_V2::setFinalOmega(const mvVec3& vec)
{
   finalOmega = vec;
}

const mvVec3& mvBody_V2::getRotation() const
{
   return bodysRotation;
}

void mvBody_V2::setRotation(const mvVec3& vec)
{
   bodysRotation = vec;
}

const mvVec3& mvBody_V2::getBodysOmega() const
{
   return bodysOmega;
}

void mvBody_V2::setBodysOmega(const mvVec3& vec)
{
   bodysOmega = vec;
}
