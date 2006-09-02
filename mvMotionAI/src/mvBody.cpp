#include "mvBody.h"

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
};

mvBody::mvBody(mvEnum bType, mvEnum shape)
{
   dimensions = NULL;
   domainVariables = NULL;
   initialiseFloats();
   initialiseDimensions(shape);
   initialiseType(bType);
   domain = MV_FULL_3D_DOMAIN; 
};

mvBody::mvBody(mvEnum bType, mvEnum shape, mvFloat x, mvFloat y, mvFloat z)
{
   dimensions = NULL;
   domainVariables = NULL;
   position.set(x,y,z);
   initialiseFloats();
   initialiseDimensions(shape);
   initialiseType(bType);
   domain = MV_FULL_3D_DOMAIN; 
};

void mvBody::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   position.set(x,y,z);
};

void mvBody::setDirection(mvFloat x, mvFloat y, mvFloat z)
{
   direction.set(x,y,z);
};

void mvBody::setSpeed(mvFloat num)
{
   speed = num;
};

void mvBody::setMaxSpeed(mvFloat num)
{
   maxSpeed = num;
};

void mvBody::setMass(mvFloat num)
{
   mass = num;
};

//void mvBody::setMaxAcceleration(mvFloat num){};    
void mvBody::setAcceleration(mvFloat accel)
{
   acceleration = accel;
};

mvEnum mvBody::setParameter(mvEnum paramFlag, mvEnum option)
{
   switch(paramFlag)
   {
     case MV_BODY_TYPE:
        return (initialiseType(option) == MV_FALSE) ? MV_INVALID_BODY_TYPE : MV_TRUE;               
     case MV_BODY_DOMAIN:
        return (initialiseDomain(option) == MV_FALSE) ? MV_NO_DOMAIN_APPLIED : MV_TRUE;
     case MV_BODY_SHAPE:
        return (initialiseDimensions(option)  == MV_FALSE) ? MV_INVALID_SHAPE_TYPE : MV_TRUE;
     case MV_BODY_STATE:
        return (initialiseState(option) == MV_FALSE) ? MV_INVALID_BODY_STATE : MV_TRUE;
     default:
        return MV_FALSE;
   }
};

/**
 *  NOTE : declarations for acceleration, deceleration,
 * max speed, speed, mass
 */
mvEnum mvBody::setParameterf(mvEnum paramFlag, mvFloat num)
{
  switch (paramFlag)
  {
    case MV_SPEED:
       speed = num;        
       return MV_TRUE;
    case MV_MAX_SPEED:
       maxSpeed = num;
       return MV_TRUE;
    case MV_ACCELERATION:
       acceleration = num;
       return MV_TRUE;
    case MV_DECELERATION:
       deceleration = num;
       return MV_TRUE;
    case MV_MASS:
       mass = num;
       return MV_TRUE;
    default:
      return MV_INVALID_BODY_PARAMETER;
  }
};

mvEnum mvBody::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
   return MV_FALSE;
};

mvEnum mvBody::getType() const
{
  return type;
};

mvEnum mvBody::getState() const
{
  return state;
};

mvEnum mvBody::getDomain() const
{
  return domain;
};

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
};

mvEnum mvBody::initialiseDimensions(mvEnum shape)
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

  if (shape == MV_AABOX)
  {
     bodyShape = shape;
     dimensions = new mvFloat[MV_NO_OF_AABOX_DIMENSIONS];
  }
  else if (shape == MV_SPHERE)
  {
     bodyShape = shape;
     dimensions = new mvFloat[MV_NO_OF_SPHERE_DIMENSIONS];
  }
  else if (shape == MV_X_AXIS_AA_CYLINDER)
  {
     bodyShape = shape;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Y_AXIS_AA_CYLINDER)
  {
     bodyShape = shape;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Z_AXIS_AA_CYLINDER)
  {
     bodyShape = shape;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else
  {
    bodyShape = MV_NO_SHAPE;
    dimensions = NULL;
  }

  if (bodyShape == MV_NO_SHAPE)
  {
    return MV_FALSE;
  }
  else
  {
    noOfDimensions = getNoOfDimensions();
    for (i = 0; i < noOfDimensions; i++)
    {
       dimensions[i] = tempDims[i];
    }
    return MV_TRUE;
  }
};

mvFloat mvBody::getListFactorTotal() const
{
   return bList.getListFactorTotal();
};

mvCount mvBody::getNoOfDimensions() const
{
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
       return MV_INVALID_DIMENSIONS;
  }    
};

mvEnum mvBody::initialiseType(mvEnum option)
{
  switch(option)
  {
    case MV_PARTICLE:
    case MV_DUAL_TYPE:
    case MV_VEHICLE:
      type = option;
      return MV_TRUE;
    default:
      type = MV_INVALID_BODY_TYPE;
      return MV_FALSE;
  }
};

mvEnum mvBody::initialiseState(mvEnum option)
{
  switch(option)
  {
    case MV_APPLY_NO_FORCES_STATE:
    case MV_USER_MOTION_STATE:
    case MV_NO_MOTION_STATE:
    case MV_APPLY_MOTIONAI_STATE:
      state = option;
      return MV_TRUE;
    default:
      state = MV_INVALID_BODY_STATE;
      return MV_FALSE;
  }
};

mvEnum mvBody::initialiseDomain(mvEnum option)
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
    //< default
    case MV_ANY_PLANE_DOMAIN:
    case MV_ANY_LINE_DOMAIN:
      domain = option;
      noOfVariables = getNoOfDomainVariables();
      domainVariables = new mvFloat[noOfVariables];
      for (i = 0; i < noOfVariables; ++i)
      {
        domainVariables[i] = tempDomVars[i];
      }
      return MV_TRUE;
    // use no varibles
    case MV_FULL_3D_DOMAIN:
    case MV_XY_PLANE_DOMAIN:
    case MV_XZ_PLANE_DOMAIN:
    case MV_YZ_PLANE_DOMAIN:
    case MV_X_AXIS_ONLY_DOMAIN:
    case MV_Y_AXIS_ONLY_DOMAIN:
    case MV_Z_AXIS_ONLY_DOMAIN:
      domain = option;
      return MV_TRUE;
    default:
      domain = MV_NO_DOMAIN_APPLIED;
      return MV_FALSE;
  }
};

mvCount mvBody::getNoOfDomainVariables() const
{
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
};

mvFloat mvBody::getX() const
{
   return position.getX();
};

mvFloat mvBody::getY() const
{
   return position.getY();
}

mvFloat mvBody::getZ() const
{
   return position.getZ();
};

mvEnum mvBody::getShape() const
{
   return bodyShape;
};
/**
16th June 2006 
Behaviour functions in mvBody
**
mvEnum mvBody::addBehaviour(mvBehaviour* bItem, mvEnum* flagArray, mvFloat* varArray)
{
   /**
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

**/
void mvBody::removeAllBehaviours()
{
   bList.removeAll();
};

mvCount mvBody::getNoOfBehaviours()
{
   return bList.getNoOfEntries();
};

mvEnum mvBody::addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex)
{
   return bList.addExistingGroupBehaviourEntry(behaviourIndex, groupIndex);
};

mvEnum mvBody::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
   return bList.addExistingBehaviourEntry(behaviourIndex);
};

mvEnum mvBody::addNewBehaviourEntry(mvEnum behaviourType)
{
   return bList.addNewBehaviourEntry(behaviourType);
};

mvEnum mvBody::addEntry(mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
{
   return bList.addEntry(bType,behaviourIndex,groupIndex);
};

mvBehaviourListNode* mvBody::getEntryByIndex(mvIndex index)
{
   return bList.getEntryByIndex(index);
};

void mvBody::setDefaultBody(mvIndex bodyIndex)
{
   bList.setDefaultBody(bodyIndex);
};

void mvBody::setDefaultWaypoint(mvIndex wpIndex)
{
   bList.setDefaultWaypoint(wpIndex);
};

void mvBody::setDefaultPathway(mvIndex pwIndex)
{
   bList.setDefaultPathway(pwIndex);
};

mvEnum mvBody::checkGroupBehaviourExists(mvIndex behaviourIndex, mvIndex groupIndex)
{
   if (bList.findExistingGroupEntry(behaviourIndex,groupIndex) != NULL)
   {
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvBody::setDefaultBehaviourFactor(mvFloat factor)
{
   return bList.setDefaultBehaviourFactor(factor);
};
