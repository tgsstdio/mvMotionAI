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

/**
 *  NOTE : declarations for acceleration, deceleration,
 * max speed, speed, mass
 */
mvErrorEnum mvBody::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
  switch (paramFlag)
  {
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

mvErrorEnum mvBody::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray != NULL)
   {
      return setParameterf(paramFlag,numArray[0]);
   }
   else
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }
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
