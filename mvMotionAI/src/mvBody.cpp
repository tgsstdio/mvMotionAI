/**
 * \file mvBody.cpp
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

#include "mvBody.h"

static const mvCount MV_MAX_NO_OF_BODY_DOMAIN_VARIABLES = 3;
static const mvCount MV_BODY_NO_DIMENSIONS = 1;
static const mvIndex MV_CIRCULAR_RADIUS_INDEX = 0;
static const mvIndex MV_AACYLINDER_LENGTH_INDEX = 1;
static const mvIndex MV_AABOX_X_INDEX = 0;
static const mvIndex MV_AABOX_Y_INDEX = 1;
static const mvIndex MV_AABOX_Z_INDEX = 2;

void mvBody::initialiseFloats()
{
   direction.set(0,0,1);
   mass = 1.0f;
   maxSpeed = 6.0f;
   // maxForce = 1.0f;
   speed = 3.0f;
   acceleration = 2.0f;
   deceleration = 0.3f;
   //maxAcceleration = 1.0f;
}

mvBody::mvBody(mvOptionEnum bType, mvOptionEnum shape)
{
   dimensions = NULL;
   domainVariables = NULL;
   initialiseFloats();
   initialiseDimensions(shape);
   initialiseType(bType);
   domain = MV_FULL_3D_DOMAIN;
}

mvBody::mvBody(mvOptionEnum bType, mvOptionEnum shape, mvFloat x, mvFloat y, mvFloat z)
{
   dimensions = NULL;
   domainVariables = NULL;
   position.set(x,y,z);
   initialiseFloats();
   initialiseDimensions(shape);
   initialiseType(bType);
   domain = MV_FULL_3D_DOMAIN;
}

void mvBody::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   position.set(x,y,z);
}

void mvBody::setDirection(mvFloat x, mvFloat y, mvFloat z)
{
   direction.set(x,y,z);
}

void mvBody::setSpeed(mvFloat num)
{
   speed = num;
}

void mvBody::setMaxSpeed(mvFloat num)
{
   maxSpeed = num;
}

void mvBody::setMass(mvFloat num)
{
   mass = num;
}

//void mvBody::setMaxAcceleration(mvFloat num){};
void mvBody::setAcceleration(mvFloat accel)
{
   acceleration = accel;
}

mvOptionEnum mvBody::getType() const
{
   return type;
}

mvOptionEnum mvBody::getState() const
{
   return state;
}

mvOptionEnum mvBody::getDomain() const
{
   return domain;
}

mvBody::~mvBody()
{
   if (dimensions != NULL)
   {
      delete [] dimensions;
   }

   if (domainVariables != NULL)
   {
      delete [] domainVariables;
   }
}

mvErrorEnum mvBody::initialiseDimensions(mvOptionEnum shape)
{
   mvFloat tempDims[MV_MAX_NO_OF_BODY_DIMENSIONS];
   mvIndex i;
   mvCount noOfDimensions;

   if (dimensions != NULL)
   {
      noOfDimensions = getNoOfDimensions();
      for (i = 0; i < noOfDimensions; i++)
      {
         tempDims[i] = dimensions[i];
      }
      delete [] dimensions;
      dimensions = NULL;
   }

   switch(shape)
   {
      case MV_AABOX:
      case MV_SPHERE:
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         bodyShape = shape;
         break;
      default:
         bodyShape = MV_NON_SHAPE;
         return MV_INVALID_BODY_SHAPE;
   }

   noOfDimensions = getNoOfDimensions();
   if (noOfDimensions > 0)
   {
      dimensions = new mvFloat[noOfDimensions];
   }
   for (i = 0; i < noOfDimensions; i++)
   {
      dimensions[i] = tempDims[i];
   }
   return MV_NO_ERROR;
}

mvFloat mvBody::getListFactorTotal() const
{
   return bList.getListFactorTotal();
}

mvCount mvBody::getNoOfDimensions() const
{
   static const mvCount MV_NO_OF_AABOX_DIMENSIONS = 3;
   static const mvCount MV_NO_OF_AACYLINDER_DIMENSIONS = 2;
   static const mvCount MV_NO_OF_SPHERE_DIMENSIONS = 1;

   switch(bodyShape)
   {
      case MV_SPHERE:
         return MV_NO_OF_SPHERE_DIMENSIONS;
      case MV_AABOX:
         return MV_NO_OF_AABOX_DIMENSIONS;
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         return MV_NO_OF_AACYLINDER_DIMENSIONS;
      default:
         return MV_BODY_NO_DIMENSIONS;
   }
}

mvErrorEnum mvBody::initialiseType(mvOptionEnum option)
{
   switch(option)
   {
      case MV_PARTICLE:
      case MV_DUAL_TYPE:
      case MV_VEHICLE:
         type = option;
         return MV_NO_ERROR;
      default:
         type = MV_NON_BODY_TYPE;
         return MV_INVALID_BODY_TYPE;
   }
}

mvErrorEnum mvBody::initialiseState(mvOptionEnum option)
{
   switch(option)
   {
      case MV_APPLY_NO_FORCES_STATE:
      case MV_USER_MOTION_STATE:
      case MV_NO_MOTION_STATE:
      case MV_APPLY_MOTIONAI_STATE:
         state = option;
         return MV_NO_ERROR;
      default:
         state = MV_NON_BODY_STATE;
         return MV_INVALID_BODY_STATE;
   }
}

mvErrorEnum mvBody::initialiseDomain(mvOptionEnum option)
{
   mvFloat tempDomVars[MV_MAX_NO_OF_BODY_DOMAIN_VARIABLES];
   mvIndex i;
   mvCount noOfVariables;

   if (domainVariables != NULL)
   {
      noOfVariables = getNoOfDomainVariables();
      for (i = 0; i < noOfVariables; ++i)
      {
         tempDomVars[i] = domainVariables[i];
      }
      delete [] domainVariables;
      domainVariables = NULL;
   }

   switch(option)
   {
      case MV_ANY_PLANE_DOMAIN:
      case MV_ANY_LINE_DOMAIN:
      case MV_FULL_3D_DOMAIN:
      case MV_XY_PLANE_DOMAIN:
      case MV_XZ_PLANE_DOMAIN:
      case MV_YZ_PLANE_DOMAIN:
      case MV_X_AXIS_ONLY_DOMAIN:
      case MV_Y_AXIS_ONLY_DOMAIN:
      case MV_Z_AXIS_ONLY_DOMAIN:
         domain = option;
         break;
      default:
         domain = MV_NO_DOMAIN_APPLIED;
         return MV_INVALID_DOMAIN;
   }

   noOfVariables = getNoOfDomainVariables();
   if (noOfVariables > 0)
   {
      domainVariables = new mvFloat[noOfVariables];
   }
   for (i = 0; i < noOfVariables; ++i)
   {
      domainVariables[i] = tempDomVars[i];
   }

   return MV_NO_ERROR;
}

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

   switch (domain)
   {
      case MV_FULL_3D_DOMAIN:
         return MV_NO_OF_FULL_3D_VARIABLES;
      case MV_XY_PLANE_DOMAIN:
         return MV_NO_OF_XY_PLANE_VARIABLES;
      case MV_XZ_PLANE_DOMAIN:
         return MV_NO_OF_XZ_PLANE_VARIABLES;
      case MV_YZ_PLANE_DOMAIN:
         return MV_NO_OF_YZ_PLANE_VARIABLES;
      case MV_X_AXIS_ONLY_DOMAIN:
         return MV_NO_OF_X_AXIS_ONLY_VARIABLES;
      case MV_Y_AXIS_ONLY_DOMAIN:
         return MV_NO_OF_Y_AXIS_ONLY_VARIABLES;
      case MV_Z_AXIS_ONLY_DOMAIN:
         return MV_NO_OF_Z_AXIS_ONLY_VARIABLES;
      case MV_ANY_PLANE_DOMAIN:
         return MV_NO_OF_ANY_PLANE_VARIABLES;
      case MV_ANY_LINE_DOMAIN:
         return MV_NO_OF_ANY_LINE_VARIABLES;
      default:
         return MV_INVALID_DOMAIN_NO_OF_VARIABLES;
   }
}

mvFloat mvBody::getX() const
{
   return position.getX();
}

mvFloat mvBody::getY() const
{
   return position.getY();
}

mvFloat mvBody::getZ() const
{
   return position.getZ();
}

mvOptionEnum mvBody::getShape() const
{
   return bodyShape;
}
/*
16th June 2006
Behaviour functions in mvBody
**
mvEnum mvBody::addBehaviour(mvBehaviour* bItem, mvEnum* flagArray, mvFloat* varArray)
{
   **
   mvBehaviourEntry* tempEntry = getEntryByPtr(bItem);
   if (tempEntry != NULL)
      return MV_FALSE;

   tempEntry = new mvBehaviourEntry();
   bList.addNewEntryPtr(tempEntry);
   tempEntry->currentBehaviour = bItem;
   tempEntry->extraStates = flagArray;
   tempEntry->extraVariables = varArray;
   **
   return MV_TRUE;
};
**
mvBehaviourEntry* mvBody::getEntryByPtr(mvBehaviour* bEntry)
{
   return bList.findEntryByKey(bEntry);
};

mvBehaviourEntry* mvBody::getEntryByName(char* bName)
{
   return bList.findEntryByName(bName);
};

*/
void mvBody::removeAllBehaviours()
{
   bList.removeAll();
}

mvCount mvBody::getNoOfBehaviours()
{
   return bList.getNoOfEntries();
}

mvErrorEnum mvBody::addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex)
{
   return bList.addExistingGroupBehaviourEntry(behaviourIndex, groupIndex);
}

mvErrorEnum mvBody::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
   return bList.addExistingBehaviourEntry(behaviourIndex);
}

mvErrorEnum mvBody::addNewBehaviourEntry(mvOptionEnum behaviourType)
{
   return bList.addNewBehaviourEntry(behaviourType);
}

mvErrorEnum mvBody::addEntry(mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
{
   return bList.addEntry(bType,behaviourIndex,groupIndex);
}

mvBehaviourListNode* mvBody::getEntryByIndex(mvIndex index)
{
   return bList.getEntryByIndex(index);
}

void mvBody::setDefaultBody(mvIndex bodyIndex)
{
   bList.setDefaultBody(bodyIndex);
}

void mvBody::setDefaultWaypoint(mvIndex wpIndex)
{
   bList.setDefaultWaypoint(wpIndex);
}

void mvBody::setDefaultPathway(mvIndex pwIndex)
{
   bList.setDefaultPathway(pwIndex);
}

bool mvBody::checkGroupBehaviourExists(mvIndex behaviourIndex, mvIndex groupIndex)
{
   return (bList.findExistingGroupEntry(behaviourIndex,groupIndex) != NULL);
}

mvErrorEnum mvBody::setDefaultBehaviourFactor(mvFloat factor)
{
   return bList.setDefaultBehaviourFactor(factor);
}

/** @brief get body's index parameters
  *
  * (documentation goes here)
  */
mvErrorEnum mvBody::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (index == NULL)
      return MV_INDEX_VALUE_IS_INVALID;

   switch (paramFlag)
   {
      case MV_WAYPOINT_TARGET:
         *index = getDefaultWaypoint();
         return MV_NO_ERROR;
      case MV_BODY_TARGET:
         *index = getDefaultBody();
         return MV_NO_ERROR;
      case MV_PATHWAY_TARGET:
         *index = getDefaultPathway();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

mvErrorEnum mvBody::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_TYPE:
         return initialiseType(option);
      case MV_DOMAIN:
         return initialiseDomain(option);
      case MV_SHAPE:
         return initialiseDimensions(option);
      case MV_STATE:
         return initialiseState(option);
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

/** \brief get body's state parameter
  *
  * (documentation goes here)
  */
mvErrorEnum mvBody::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   if (option == NULL)
      return MV_OPTION_ENUM_DEST_IS_NULL;

   switch (paramFlag)
   {
      case MV_SHAPE:
         *option = getShape();
         return MV_NO_ERROR;
      case MV_STATE:
         *option = getState();
         return MV_NO_ERROR;
      case MV_TYPE:
         *option = getType();
         return MV_NO_ERROR;
      case MV_DOMAIN:
         *option = getDomain();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

/**
  *\brief get body's parameters single float values
  *
  */
mvErrorEnum mvBody::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   mvIndex tempIndex;

   if (num == NULL)
      return MV_FLOAT_DEST_IS_NULL;

   switch (paramFlag)
   {
      case MV_LENGTH:
         switch(bodyShape)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_AACYLINDER_LENGTH_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_RADIUS:
         switch(bodyShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_CIRCULAR_RADIUS_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_X_WIDTH:
         switch(bodyShape)
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
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_Y_LENGTH:
         switch(bodyShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Y_INDEX;
               return MV_NO_ERROR;
            case MV_Y_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_Z_DEPTH:
         switch(bodyShape)
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
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_SPEED:
         *num = speed;
         return MV_NO_ERROR;
      case MV_MAX_SPEED:
         *num = maxSpeed;
         return MV_NO_ERROR;
      case MV_ACCELERATION:
         *num = acceleration;
         return MV_NO_ERROR;
      case MV_DECELERATION:
         *num = deceleration;
         return MV_NO_ERROR;
      case MV_MASS:
         *num = mass;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

/**
 * \brief get body's parameters single float values
 *
 * NOTE : declarations for acceleration, deceleration,
 * max speed, speed, mass
 */
mvErrorEnum mvBody::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvIndex tempIndex;

   switch (paramFlag)
   {
      case MV_LENGTH:
         switch(bodyShape)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_AACYLINDER_LENGTH_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_RADIUS:
         switch(bodyShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_CIRCULAR_RADIUS_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_X_WIDTH:
         switch(bodyShape)
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
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_Y_LENGTH:
         switch(bodyShape)
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
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_Z_DEPTH:
         switch(bodyShape)
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
               return MV_INVALID_BODY_SHAPE;
         }
      case MV_SPEED:
         speed = num;
         return MV_NO_ERROR;
      case MV_MAX_SPEED:
         maxSpeed = num;
         return MV_NO_ERROR;
      case MV_ACCELERATION:
         acceleration = num;
         return MV_NO_ERROR;
      case MV_DECELERATION:
         deceleration = num;
         return MV_NO_ERROR;
      case MV_MASS:
         mass = num;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_PARAMETER;
   }
}

/**
  * \brief set body's floating point vector parameters
  *
  * NOTE : setParameterv also calls setParameterf
  */
mvErrorEnum mvBody::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   mvVec3 tempVector;
   mvFloat vectorLength;

   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_DIRECTION:
         tempVector.setXYZ(numArray[0],numArray[1],numArray[2]);
         direction = tempVector.normalize();
         return MV_NO_ERROR;
      case MV_POSITION:
         position.setXYZ(numArray[0],numArray[1],numArray[2]);
         return MV_NO_ERROR;
      case MV_VELOCITY:
         tempVector.setXYZ(numArray[0],numArray[1],numArray[2]);
         vectorLength = tempVector.length();
         speed = vectorLength;
         direction = tempVector.normalize();
         return MV_NO_ERROR;
      default:
         return setParameterf(paramFlag,numArray[0]);
   }
}

/** \brief get body's vector parameters
  *
  * NOTE : getParameterv also calls getParameterf
  */
mvErrorEnum mvBody::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   mvErrorEnum error;
   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }


   if (numArray == NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_DIRECTION:
         numArray[0] = direction.getX();
         numArray[1] = direction.getY();
         numArray[2] = direction.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_POSITION:
         numArray[0] = position.getX();
         numArray[1] = position.getY();
         numArray[2] = position.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      case MV_VELOCITY:
         numArray[0] = speed * direction.getX();
         numArray[1] = speed * direction.getY();
         numArray[2] = speed * direction.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
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

/** @brief set body's index parameters
  *
  */
mvErrorEnum mvBody::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch (paramFlag)
   {
      case MV_WAYPOINT_TARGET:
         setDefaultWaypoint(index);
         return MV_NO_ERROR;
      case MV_BODY_TARGET:
         setDefaultBody(index);
         return MV_NO_ERROR;
      case MV_PATHWAY_TARGET:
         setDefaultPathway(index);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BODY_PARAMETER;
   }

}

/** @brief returns body's initial (default) body target of all
  * new behaviours added to the body.
  */
mvIndex mvBody::getDefaultBody() const
{
   return bList.getDefaultBody();
}

/** @brief returns body's initial (default) waypoint target of all
  * new behaviours added to the body.
  */
mvIndex mvBody::getDefaultWaypoint() const
{
   return bList.getDefaultWaypoint();
}

/** @brief returns body's initial (default) pathway target of all
  * new behaviours added to the body.
  */
mvIndex mvBody::getDefaultPathway() const
{
   return bList.getDefaultPathway();
}

/** @brief returns body's initial (default) behaviour factor of all
  * new behaviours added to the body.
  */
mvFloat mvBody::getDefaultBehaviourFactor() const
{
   return bList.getDefaultBehaviourFactor();
}




