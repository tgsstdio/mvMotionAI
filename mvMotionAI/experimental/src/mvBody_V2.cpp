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
   bodyAccel = 1;
   // deaccleation = 1
   bodyDeaccel = 1;
   // mass = 1.0
   bodyMass = 1.0;
   // current speed = 0
   bodyCurrentSpeed = 0;
   // max speed = 5
   bodyMaxSpeed = 5;
   // user data = NULL
   bodyUserDataPtr = NULL;
   // default direction 1.0
   bodyDirection.set(0,0,1);
   // face direction
   faceDirection.set(0,0,1);
   // shape
   setShape(shape);

   // domain
   bodyDomain = MV_FULL_3D;
   bodyDomainVariables = NULL;
   setDomain(bodyDomain);
   //TODO : initialises variables

}

mvBody_V2::~mvBody_V2()
{
   if (bodyDomainVariables != NULL)
   {
      delete [] bodyDomainVariables;
   }
}

mvErrorEnum mvBody_V2::setDomain(mvOptionEnum bDomain)
{
   mvFloat tempDomVars[MV_MAX_NO_OF_PARAMETERS];
   mvIndex i;
   mvCount noOfVariables;

   if (bodyDomainVariables != NULL)
   {
      noOfVariables = getNoOfDomainVariables();
      for (i = 0; i < noOfVariables; ++i)
      {
         tempDomVars[i] = bodyDomainVariables[i];
      }
      delete [] bodyDomainVariables;
      bodyDomainVariables = NULL;
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

void mvBody_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   bodyPosition.set(x,y,z);
}

const mvVec3& mvBody_V2::getFaceDirection() const
{
   return faceDirection;
}

void mvBody_V2::setFaceDirection(mvFloat x, mvFloat y,mvFloat z)
{
   faceDirection.set(x,y,z);
}

mvFloat mvBody_V2::getSpeed() const
{
   return bodyCurrentSpeed;
}

void mvBody_V2::setSpeed(mvFloat num)
{
   bodyCurrentSpeed = num;
}

mvFloat mvBody_V2::getMaxSpeed() const
{
   return bodyMaxSpeed;
}

void mvBody_V2::setMaxSpeed(mvFloat num)
{
   bodyMaxSpeed = num;
}

void mvBody_V2::setMass(mvFloat num)
{
   bodyMass = num;
}

mvFloat mvBody_V2::getMass() const
{
   return bodyMass;
}


mvFloat mvBody_V2::getDeacceleration() const
{
   return bodyDeaccel;
}

void mvBody_V2::setDeacceleration(mvFloat dAccel)
{
   bodyDeaccel = dAccel;
}

mvFloat mvBody_V2::getAcceleration() const
{
   return bodyAccel;
}

void mvBody_V2::setAcceleration(mvFloat accel)
{
   bodyAccel = accel;
}

// TODO : new functions for retriving values
const mvVec3& mvBody_V2::getFinalDirection() const
{
   return faceDirection;
}

void mvBody_V2::setFinalDirection(mvVec3& value)
{
   faceDirection = value;
}

const mvVec3& mvBody_V2::getFinalVelocity() const
{
   return finalVelocity;
}

void mvBody_V2::setFinalVelocity(mvVec3& value)
{
   finalVelocity = value;
}

mvVec3 mvBody_V2::getVelocity() const
{
   mvVec3 temp(bodyDirection);
   temp *= getSpeed();

   return temp;
}

mvFloat mvBody_V2::getFinalSpeed() const
{
   return finalVelocity.length();
}

// parameter functions
mvErrorEnum mvBody_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   /*
   MV_NO_OF_SHAPE_DIMENSIONS,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   */
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   mvErrorEnum error;

   //TODO : implememt this function
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_SHAPE:
         *option = bodyShape.getType();
         return MV_NO_ERROR;
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
      default:
         // TODO : pass behaviour list

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

   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      // TODO : MV_FORCE_QUANTITY
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
         *num = getDeacceleration();
         return MV_NO_ERROR;
      case MV_MASS:
         *num = getMass();
         return MV_NO_ERROR;
      case MV_FINAL_SPEED:
         *num = getFinalSpeed();
         return MV_NO_ERROR;
      default:
         // TODO : pass behaviour list

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

   if (notOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   //TODO : implememt this function
   switch(paramFlag)
   {
      // TODO : case MV_FORCE_VECTOR:
      //TODO : case MV_ACCELERATION_VECTOR:
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
         *noOfParameters = dimensionCount;
         return MV_NO_ERROR;
      case MV_FINAL_VELOCITY:
         resultVector = getFinalVelocity();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_FINAL_DIRECTION:
         resultVector = getFinalDirection();
         numArray[0] = resultVector.getX();
         numArray[1] = resultVector.getY();
         numArray[2] = resultVector.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_PLANE_NORMAL:
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
   //TODO : implememt this function
   mvErrorEnum error;

   // TODO : behaviour list

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
   /*
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,

   MV_IS_ENABLED,
   // body boolean flags
   MV_APPLY_FORCES,
   MV_APPLY_SHIFTS,
   MV_APPLY_ACCELERATIONS,
   MV_APPLY_GRAVITY,
   MV_APPLY_COLLISIONS,
   MV_APPLY_ALL_FORCES,
   */
   mvErrorEnum error;

   switch(paramFlag)
   {
      default:
         // TODO : behaviour list

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
      case MV_TYPE:
         return setType(option);
      case MV_DOMAIN:
         return setDomain(option);
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_FORCES:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_SHIFTS:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ACCELERATIONS:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_GRAVITY:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_COLLISIONS:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_FORCES:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
   }
}

mvErrorEnum mvBody_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   /*
   MV_NO_PARAMETER = 0,
   MV_SPEED,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_MASS,
   //MV_STATE,
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,
   MV_FORCE_VECTOR,

   MV_VELOCITY,
   MV_ACCELERATION_VECTOR,
   MV_FORCE_QUANTITY,
   MV_CONSTANT, // renamed
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH, // shorten
   MV_Y_HEIGHT, // shorten
   MV_Z_DEPTH, // shorten
   MV_DIRECTION,
   MV_WAYPOINT,
   MV_BODY,
   MV_PATHWAY,
   MV_PERCEIVED_COHESION,
   MV_PERCEIVED_ALIGNMENT,
   MV_COHESION_FACTOR,
   MV_SEPARATION_FACTOR,
   MV_ALIGNMENT_FACTOR,
   // new enums
   MV_SHAPE_DIMENSIONS,
   MV_NO_OF_SHAPE_DIMENSIONS,
   MV_IS_ENABLED,
   MV_DOMAIN_VARIABLES,
   MV_NO_OF_BODIES,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   MV_WIDTH,
   MV_DEPTH,
   // new enums behaviour list
   MV_MODE,
   MV_CURRENT_INDEX,
   MV_WEIGHT,
   MV_FINAL_VELOCITY,
   MV_FINAL_SPEED,
   MV_FINAL_DIRECTION,
   MV_PLANE_NORMAL,
   MV_LINE_VECTOR,
   MV_ELAPSED_TIME,
   MV_PERIOD,
   MV_IS_TIMED,
   MV_INDEX,

   // tree movement functions
   MV_NEW_NODE,
   MV_NEW_LEVEL,
   MV_NEXT_NODE,
   MV_PREV_NODE,
   MV_UP_LEVEL,
   MV_DOWN_LEVEL,
   MV_IS_CONFINED,
   MV_GROUP,
   MV_AUTO_CONVERT_INDEX,
   MV_RIGHT_HANDED,

   // body boolean flags
   MV_APPLY_FORCES,
   MV_APPLY_SHIFTS,
   MV_APPLY_ACCELERATIONS,
   MV_APPLY_GRAVITY,
   MV_APPLY_COLLISIONS,
   MV_APPLY_ALL_FORCES,

   // user defined parameters
   MV_USER_PARAM_INDEX,
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,

   // user string statements
   MV_USER_STRING_INDEX,
   MV_USER_STRING_0,
   MV_USER_STRING_1,
   MV_USER_STRING_2,
   MV_USER_STRING_3,

   MV_NO_OF_PARAM_ENUMS
   */
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   /*
   MV_NO_PARAMETER = 0,
   MV_SPEED,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_MASS,
   //MV_STATE,
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,
   MV_FORCE_VECTOR,

   MV_VELOCITY,
   MV_ACCELERATION_VECTOR,
   MV_FORCE_QUANTITY,
   MV_CONSTANT, // renamed
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH, // shorten
   MV_Y_HEIGHT, // shorten
   MV_Z_DEPTH, // shorten
   MV_DIRECTION,
   MV_WAYPOINT,
   MV_BODY,
   MV_PATHWAY,
   MV_PERCEIVED_COHESION,
   MV_PERCEIVED_ALIGNMENT,
   MV_COHESION_FACTOR,
   MV_SEPARATION_FACTOR,
   MV_ALIGNMENT_FACTOR,
   // new enums
   MV_SHAPE_DIMENSIONS,
   MV_NO_OF_SHAPE_DIMENSIONS,
   MV_IS_ENABLED,
   MV_DOMAIN_VARIABLES,
   MV_NO_OF_BODIES,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   MV_WIDTH,
   MV_DEPTH,
   // new enums behaviour list
   MV_MODE,
   MV_CURRENT_INDEX,
   MV_WEIGHT,
   MV_FINAL_VELOCITY,
   MV_FINAL_SPEED,
   MV_FINAL_DIRECTION,
   MV_PLANE_NORMAL,
   MV_LINE_VECTOR,
   MV_ELAPSED_TIME,
   MV_PERIOD,
   MV_IS_TIMED,
   MV_INDEX,

   // tree movement functions
   MV_NEW_NODE,
   MV_NEW_LEVEL,
   MV_NEXT_NODE,
   MV_PREV_NODE,
   MV_UP_LEVEL,
   MV_DOWN_LEVEL,
   MV_IS_CONFINED,
   MV_GROUP,
   MV_AUTO_CONVERT_INDEX,
   MV_RIGHT_HANDED,

   // body boolean flags
   MV_APPLY_FORCES,
   MV_APPLY_SHIFTS,
   MV_APPLY_ACCELERATIONS,
   MV_APPLY_GRAVITY,
   MV_APPLY_COLLISIONS,
   MV_APPLY_ALL_FORCES,

   // user defined parameters
   MV_USER_PARAM_INDEX,
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,

   // user string statements
   MV_USER_STRING_INDEX,
   MV_USER_STRING_0,
   MV_USER_STRING_1,
   MV_USER_STRING_2,
   MV_USER_STRING_3,

   MV_NO_OF_PARAM_ENUMS
   */
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

