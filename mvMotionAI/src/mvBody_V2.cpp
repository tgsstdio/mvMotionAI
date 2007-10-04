/**
 * \file mvBody_V2.cpp
 *
 * MV_PARTICLE : An unidirectional moving object that does not require rotation
 *
 * MV_VEHICLE : A single directional moving object as either an obstacle or not.
 *
 * MV_DUAL_TYPE:
 *
 * This class should be defined as a subclass of overall movement
 * class. This class differs from Vehicle because Particles can
 * travel along any direction instead of travelling along a single unit
 * vector.
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
 *
 * Log
 * Version		date		comments
 *
 * 00-02-15+   4/10/07
 * - rewrote entire class and typedef as mvBody.
 *
 * 00-01-21    25/11/06
 * - add parameter option MV_SHAPE_DIMENSIONS, MV_DOMAIN_VARIABLES
 *
 * 00-01-17   22/8/06
 * - add get/set parameters
 *
 * 00-01-05   22/8/06
 * - using types headers and mvVec3.
 *
 * 00-01-03   21/6/06
 * - added behaviour list to mvBody class
 *
 * 00-01-02   31/5/06
 * - added behaviour / removing groups from body & system
 *
 * 00-01-00   19/5/06
 * - renamed particles and vehicles, grouped them into a group
 * under the name of mvBody.
 *
 * 00-00-06		6/3/06
 * - initialised particle
 *
 * 00-00-05    3/3/06
 * - intergration for motion.
 *
 * 00-00-02    8/2/06
 *  - separated from MotionAI.h, created new header and source file.
 *
 */
#include <mv/mvBody_V2.h>

/**
 * \class mvBody
 *
 * \brief This class represents the moving objects within the system
 */

/**
 *  \brief mvBody constructor
 *  \param[in] bType Body type [MV_VEHICLE, MV_PARTICLE, MV_DUAL_TYPE]
 *  \param[in] shape Shape of body [MV_AABOX, MV_SPHERE, ...]
 *  \param[in] x X component of the body's initial position
 *  \param[in] y Y component of the body's initial position
 *  \param[in] z Z component of the body's initial position
 */
mvBody::mvBody(mvOptionEnum bType, mvOptionEnum shape, mvFloat x,\
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

/** \brief blah blah
 *
 */
mvVec3 mvBody::getBodyDirection() const
{
   return bodyVelocity.normalize();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setBodyDirection(mvFloat x, mvFloat y, mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setBodyDirection(temp);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setBodyDirection(const mvVec3& value)
{
   mvVec3 newNormalized = value.normalize();
   mvFloat bodySpeed = getSpeed();
   bodyVelocity = value;
   bodyVelocity *= bodySpeed;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvBody::~mvBody()
{
   if (bodyDomainVariables != MV_NULL)
   {
      delete [] bodyDomainVariables;
      bodyDomainVariables = MV_NULL;
   }
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setDomain(mvOptionEnum bDomain)
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
      bodyDomainVariables = new mvFloat[noOfVariables];
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

/** \brief blah blah
 *
 */
const mvFloat* mvBody::getDomainVariables() const
{
   return bodyDomainVariables;
}

/** \brief blah blah
 *
 */
mvCount mvBody::getNoOfDomainVariables() const
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

/** \brief blah blah
 *
 */
mvOptionEnum mvBody::getDomain() const
{
   return bodyDomain;
}

/** \brief blah blah
 *
 */
mvOptionEnum mvBody::getType() const
{
   return bodyType;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setType(mvOptionEnum bType)
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

/** \brief blah blah
 *
 */
mvConstShapePtr mvBody::getShape() const
{
   return &bodyShape;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setShape(mvOptionEnum bShape)
{
   return bodyShape.setType(bShape);
}

/** \brief blah blah
 *
 */
void* mvBody::getUserData() const
{
   return bodyUserDataPtr;
}

/** \brief blah blah
 *
 */
void mvBody::setUserData(void* usrData)
{
   bodyUserDataPtr = usrData;
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getX() const
{
   return bodyPosition.getX();
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getY() const
{
   return bodyPosition.getY();
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getZ() const
{
   return bodyPosition.getZ();
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getPosition() const
{
   return bodyPosition;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   setX(x);
   setY(y);
   setZ(z);
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getFaceDirection() const
{
   return faceDirection;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setFaceDirection(mvFloat x, mvFloat y,mvFloat z)
{
   mvVec3 temp(x,y,z);
   return setFaceDirectionByVec3(temp);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setFaceDirectionByVec3(const mvVec3& value)
{
   faceDirection = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getSpeed() const
{
   return bodyVelocity.length();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setSpeed(mvFloat num)
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

/** \brief blah blah
 *
 */
mvFloat mvBody::getMaxSpeed() const
{
   return bodyMaxSpeed;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setMaxSpeed(mvFloat num)
{
   bodyMaxSpeed = num;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setMass(mvFloat num)
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

/** \brief blah blah
 *
 */
mvFloat mvBody::getMass() const
{
   return bodyMass;
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getDeceleration() const
{
   return bodyDeaccel;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setDeceleration(mvFloat dAccel)
{
   if (dAccel >= 0)
   {
      bodyDeaccel = dAccel;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getAcceleration() const
{
   return bodyAccel;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setAcceleration(mvFloat accel)
{
   if (accel >= 0)
   {
      bodyAccel = accel;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
}

/** \brief blah blah
 *
 */
mvVec3 mvBody::getFinalDirection() const
{
   mvVec3 temp = finalVelocity.normalize();
   return temp;
}

/*
mvErrorEnum mvBody::setFinalDirection(mvFloat fx, mvFloat fy, mvFloat fz)
{
   mvVec3 temp(fx,fy,fz);
   return setFinalDirectionByVec3(temp);
}
*/

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setFinalDirection(const mvVec3& value)
{
   faceDirection = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getFinalVelocity() const
{
   return finalVelocity;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setFinalVelocity(mvFloat x, mvFloat y, mvFloat z)
{
   finalVelocity.set(x,y,z);
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setVelocity(mvFloat vx, mvFloat vy, mvFloat vz)
{
   bodyVelocity.set(vx,vy,vz);
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setVelocity(const mvVec3& value)
{
   bodyVelocity = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setFinalVelocity(const mvVec3& value)
{
   finalVelocity = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setPosition(const mvVec3& value)
{
   bodyPosition = value;
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getVelocity() const
{
   return bodyVelocity;
}

/** \brief blah blah
 *
 */
mvFloat mvBody::getFinalSpeed() const
{
   return finalVelocity.length();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::getParametero(mvParamEnum paramFlag,\
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
         error = bodyShape.getParametero(paramFlag,option);

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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setParameteri(mvParamEnum paramFlag, mvIndex index)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setParametero(mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      default:

         // shape
         error = bodyShape.setParametero(paramFlag, option);
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setParameterf(mvParamEnum paramFlag, mvFloat num)
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBody::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
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

/** \brief blah blah
 *
 */
void mvBody::setX(mvFloat x)
{
   bodyPosition.setX(x);
}

/** \brief blah blah
 *
 */
void mvBody::setY(mvFloat y)
{
   bodyPosition.setY(y);
}

/** \brief blah blah
 *
 */
void mvBody::setZ(mvFloat z)
{
   bodyPosition.setZ(z);
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getFinalForce() const
{
   return finalForceVector;
}

/** \brief blah blah
 *
 */
void mvBody::setFinalForce(const mvVec3& vec)
{
   finalForceVector = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getBodysForce() const
{
   return bodysForceVector;
}

/** \brief blah blah
 *
 */
void mvBody::setBodysForce(const mvVec3& vec)
{
   bodysForceVector = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getFinalTorque() const
{
   return finalTorque;
}

/** \brief blah blah
 *
 */
void mvBody::setFinalTorque(const mvVec3& vec)
{
   finalTorque = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getBodysTorque() const
{
   return bodysTorque;
}

/** \brief blah blah
 *
 */
void mvBody::setBodysTorque(const mvVec3& vec)
{
   bodysTorque = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getFinalOmega() const
{
   return finalOmega;
}

/** \brief blah blah
 *
 */
void mvBody::setFinalOmega(const mvVec3& vec)
{
   finalOmega = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getRotation() const
{
   return bodysRotation;
}

/** \brief blah blah
 *
 */
void mvBody::setRotation(const mvVec3& vec)
{
   bodysRotation = vec;
}

/** \brief blah blah
 *
 */
const mvVec3& mvBody::getBodysOmega() const
{
   return bodysOmega;
}

/** \brief blah blah
 *
 */
void mvBody::setBodysOmega(const mvVec3& vec)
{
   bodysOmega = vec;
}
