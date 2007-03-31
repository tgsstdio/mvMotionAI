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
   //  default direction

   // face direction
   faceDirection.set(0,0,1);
   //TODO : initialises variables

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
mvErrorEnum mvBody_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBody_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   //TODO : implememt this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

