#include "mvForceResult.h"

mvForceResult::mvForceResult(mvConstWorldPtr worldPtr,\
   mvConstBodyPtr bodyPtr) :
   currentWorld(worldPtr),
   currentBody(bodyPtr)
{
   elapsedSystemTime = 0;
   currentTimeStep = 0;
   dragAcceleration = 0;
   dragShift = 0;
   dragForce = 0;
   resetAll();
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstBodyPtr mvForceResult::getCurrentBodyPtr() const
{
   return currentBody;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstWorldPtr mvForceResult::getWorldPtr() const
{
   return currentWorld;
}

// new utility functions
mvConstWaypointPtr mvForceResult::fetchWaypointPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstWaypointPtr(index);
}

mvConstBodyPtr mvForceResult::fetchBodyPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstBodyPtr(index);
}

mvConstGroupBehaviourPtr mvForceResult::fetchGroupBehaviourPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupBehaviourPtr(index);
}

mvConstPathwayPtr mvForceResult::fetchPathwayPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstPathwayPtr(index);
}

mvConstGroupPtr mvForceResult::fetchGroupPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupPtr(index);
}

void mvForceResult::setElaspedSystemTime(mvFloat timeInSecs)
{
   elapsedSystemTime = timeInSecs;
}

void mvForceResult::setCurrentTimeStep(mvFloat timeInSecs)
{
   currentTimeStep = timeInSecs;
}

void mvForceResult::setPositionPrediction(const mvVec3& pos)
{
   brFuturePosition = pos;
}

void mvForceResult::setFinalPositionPrediction(const mvVec3& pos)
{
   brFutureFinalPosition = pos;
}

void mvForceResult::setVelocityPrediction(const mvVec3& vel)
{
   brFutureVelocity = vel;
}

void mvForceResult::setFinalVelocityPrediction(const mvVec3& vel)
{
   brFutureFinalVelocity = vel;
}

mvFloat mvForceResult::getTimeStep() const
{
   return currentTimeStep;
}

mvFloat mvForceResult::getElapsedSystemTime() const
{
   return elapsedSystemTime;
}

mvConstBaseForcePtr mvForceResult::fetchForcePtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstForcePtr(index);
}

const mvVec3& mvForceResult::predictPositionOfCurrentBody() const
{
   return brFuturePosition;
}

const mvVec3& mvForceResult::predictFinalPositionOfCurrentBody() const
{
   return brFutureFinalPosition;
}

const mvVec3& mvForceResult::predictVelocityOfCurrentBody() const
{
   return brFutureVelocity;
}

const mvVec3& mvForceResult::predictFinalVelocityOfCurrentBody() const
{
   return brFutureFinalVelocity;
}

bool mvForceResult::isForceSet() const
{
   return applyForce;
}

const mvVec3& mvForceResult::getForce() const
{
   return force;
}

bool mvForceResult::isAccelerationSet() const
{
   return applyAccel;
}

const mvVec3& mvForceResult::getAcceleration() const
{
   return acceleration;
}

bool mvForceResult::isDirectionSet() const
{
   return applyDirection;
}

const mvVec3& mvForceResult::getDirection() const
{
   return direction;
}

bool mvForceResult::isTorqueSet() const
{
   return applyTorque;
}

const mvVec3& mvForceResult::getTorque() const
{
   return torque;
}

bool mvForceResult::isOmegaSet() const
{
   return applyOmega;
}

const mvVec3& mvForceResult::getOmega() const
{
   return omega;
}

bool mvForceResult::isOmegaInDegrees() const
{
   return omegaInDegrees;
}

bool mvForceResult::isShiftSet() const
{
   return applyShift;
}

const mvVec3& mvForceResult::getShift() const
{
   return shiftVec;
}

bool mvForceResult::isQuaternionSet() const
{
   return applyQuaternion;
}

const mvFloat* mvForceResult::getQuaternion() const
{
   return quaternion;
}

bool  mvForceResult::isRotationSet() const
{
   return applyRotation;
}

const mvVec3&  mvForceResult::getRotation() const
{
   return rotation;
}

bool mvForceResult::isRotationInDegrees() const
{
   return rotationInDegrees;
}

bool mvForceResult::isDragForceSet() const
{
   return applyDragForce;
}

mvFloat mvForceResult::getDragForce() const
{
   return dragForce;
}

bool mvForceResult::isDragAccelerationSet() const
{
   return applyDragAccel;
}

mvFloat mvForceResult::getDragAcceleration() const
{
   return dragAcceleration;
}

bool mvForceResult::isGravitySet() const
{
   return applyGravity;
}

const mvVec3& mvForceResult::getGravity() const
{
   return gravity;
}

bool mvForceResult::isDragShiftSet() const
{
   return applyDragShift;
}

mvFloat mvForceResult::getDragShift() const
{
   return dragShift;
}

void mvForceResult::setForce(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   force = value;
   forceMotion = mType;
   forceEffect = eType;
   applyForce = true;
}

void mvForceResult::setAcceleration(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   acceleration = value;
   accelMotion = mType;
   accelEffect = eType;
   applyAccel = true;
}

void mvForceResult::setGravity(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   gravity = value;
   gravityEffect = eType;
   gravityMotion = mType;
   applyGravity = true;
}

void mvForceResult::setShift(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   shiftVec = value;
   shiftMotion = mType;
   shiftEffect = eType;
   applyShift = true;
}

void mvForceResult::setTorque(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   torque = value;
   torqueMotion = mType;
   torqueEffect = eType;
   applyTorque = true;
}

void mvForceResult::setQuaternion(const mvFloat* quatArray,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   for ( mvIndex i = 0; i < MV_QUATERNION_LENGTH; i++)
   {
      quaternion[i] = quatArray[i];
   }
   applyQuaternion = true;
   quaternionEffect = eType;
   quaternionMotion = mType;
}

void mvForceResult::setDirection(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   direction = value;
   directionMotion = mType;
   directionEffect = eType;
   applyDirection = true;
}

void mvForceResult::setOmegaInDegrees(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotion = mType;
   omegaEffect = eType;
   applyOmega = true;
   omegaInDegrees = true;
}

void mvForceResult::setOmegaInRadians(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotion = mType;
   omegaEffect = eType;
   applyOmega = true;
   omegaInDegrees = false;
}

void mvForceResult::setRotationInDegrees(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotion = mType;
   rotationEffect = eType;
   applyRotation = true;
   rotationInDegrees = true;
}

void mvForceResult::setRotationInRadians(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotion = mType;
   rotationEffect = eType;
   applyRotation = true;
   rotationInDegrees = false;
}

mvMotionTypeEnum   mvForceResult::getForceMotionType() const
{
   return forceMotion;
}

mvEffectTypeEnum   mvForceResult::getForceEffectType() const
{
   return forceEffect;
}

mvMotionTypeEnum   mvForceResult::getAccelerationMotionType() const
{
   return accelMotion;
}

mvEffectTypeEnum   mvForceResult::getAccelerationEffectType() const
{
   return accelEffect;
}

mvMotionTypeEnum   mvForceResult::getDirectionMotionType() const
{
   return directionMotion;
}

mvEffectTypeEnum   mvForceResult::getDirectionEffectType() const
{
   return directionEffect;
}

mvMotionTypeEnum   mvForceResult::getTorqueMotionType() const
{
   return torqueMotion;
}

mvEffectTypeEnum   mvForceResult::getTorqueEffectType() const
{
   return torqueEffect;
}

mvMotionTypeEnum   mvForceResult::getOmegaMotionType() const
{
   return omegaMotion;
}

mvEffectTypeEnum   mvForceResult::getOmegaEffectType() const
{
   return omegaEffect;
}

mvMotionTypeEnum   mvForceResult::getShiftMotionType() const
{
   return shiftMotion;
}

mvEffectTypeEnum   mvForceResult::getShiftEffectType() const
{
   return shiftEffect;
}

mvMotionTypeEnum   mvForceResult::getQuaternionMotionType() const
{
   return quaternionMotion;
}

mvEffectTypeEnum   mvForceResult::getQuaternionEffectType() const
{
   return quaternionEffect;
}

mvMotionTypeEnum   mvForceResult::getGravityMotionType() const
{
   return gravityMotion;
}

mvEffectTypeEnum   mvForceResult::getGravityEffectType() const
{
   return gravityEffect;
}

mvMotionTypeEnum   mvForceResult::getRotationMotionType() const
{
   return rotationMotion;
}

mvEffectTypeEnum   mvForceResult::getRotationEffectType() const
{
   return rotationEffect;
}

void mvForceResult::resetAll()
{
   applyForce = false;
   applyAccel = false;
   applyShift = false;
   applyGravity = false;
   applyTorque = false;
   applyOmega = false;
   applyDirection = false;
   applyQuaternion = false;
   applyRotation = false;

   forceMotion = MV_DEFAULT_MOTION;
   accelMotion = MV_DEFAULT_MOTION;
   shiftMotion = MV_DEFAULT_MOTION;
   gravityMotion = MV_DEFAULT_MOTION;
   torqueMotion = MV_DEFAULT_MOTION;
   omegaMotion = MV_DEFAULT_MOTION;
   directionMotion = MV_DEFAULT_MOTION;
   quaternionMotion = MV_DEFAULT_MOTION;
   rotationMotion = MV_DEFAULT_MOTION;

   forceEffect = MV_DEFAULT_EFFECT;
   accelEffect = MV_DEFAULT_EFFECT;
   shiftEffect = MV_DEFAULT_EFFECT;
   gravityEffect = MV_DEFAULT_EFFECT;
   torqueEffect = MV_DEFAULT_EFFECT;
   omegaEffect = MV_DEFAULT_EFFECT;
   directionEffect = MV_DEFAULT_EFFECT;
   quaternionEffect = MV_DEFAULT_EFFECT;
   rotationEffect = MV_DEFAULT_EFFECT;

   omegaInDegrees = true;
   rotationInDegrees = true;
   applyDragForce = false;
   applyDragAccel = false;
   applyDragShift = false;

   isDefaultMotionSteering = true;
   isDefaultEffectGlobal = true;

}

void mvForceResult::disableForce()
{
   applyForce = false;
}

void mvForceResult::disableAccel()
{
   applyAccel = false;
}

void mvForceResult::disableShift()
{
   applyShift = false;
}

void mvForceResult::disableGravity()
{
   applyGravity = false;
}

void mvForceResult::disableTorque()
{
   applyTorque = false;
}

void mvForceResult::disableOmega()
{
   applyOmega = false;
}

void mvForceResult::disableDirection()
{
   applyDirection = false;
}

void mvForceResult::disableQuaternion()
{
   applyQuaternion = false;
}

void mvForceResult::disableRotation()
{
   applyRotation = false;
}

void mvForceResult::disableDragForce()
{
   applyDragForce = false;
}

void mvForceResult::disableDragAccel()
{
   applyDragAccel = false;
}

void mvForceResult::disableDragShift()
{
   applyDragShift = false;
}

bool  mvForceResult::isGlobalEffectDefault() const
{
   return isDefaultEffectGlobal;
}

bool  mvForceResult::isSteeringMotionDefault() const
{
   return isDefaultMotionSteering;
}

void  mvForceResult::setToLocalEffect()
{
   isDefaultEffectGlobal = false;
}

void  mvForceResult::setToGlobalEffect()
{
   isDefaultEffectGlobal = true;
}
