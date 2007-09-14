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
#include <mv/mvBehaviourResult.h>

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstBodyPtr mvBehaviourResult::getCurrentBodyPtr() const
{
   return currentBody;
}

/** @brief (one liner)
 *
 * (documentation goes here)
 */
mvBaseActionPtr mvBehaviourResult::getGroupBehaviourNode() const
{
   return currentGroupBehNode;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstWorldPtr mvBehaviourResult::getWorldPtr() const
{
   return currentWorld;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setToSteering()
{
   isDefaultMotionSteering = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setToDirectional()
{
   isDefaultMotionSteering = false;
}

/** @brief (one liner)
  *
  * default behaviour return type is directional
  */
void mvBehaviourResult::resetAll()
{
   currentGroupBehNode = MV_NULL;
   behaviourIndex = MV_NULL;
   groupIndex = MV_NULL;

   isDefaultMotionSteering = false;
   isDefaultEffectGlobal = true;
   applyAccel = false;
   applyVelocity = false;
   applyDirection = false;
   applyForce = false;
   applyTorque = false;
   applyOmega = false;
   omegaInDegrees = true;
   rotationInDegrees = true;
   applyQuaternion = false;
   applyRotation = false;

   accelMotionType = MV_DEFAULT_MOTION;
   velocityMotionType = MV_DEFAULT_MOTION;
   directionMotionType = MV_DEFAULT_MOTION;
   forceMotionType = MV_DEFAULT_MOTION;
   torqueMotionType = MV_DEFAULT_MOTION;
   omegaMotionType = MV_DEFAULT_MOTION;
   quaternionMotionType = MV_DEFAULT_MOTION;
   rotationMotionType = MV_DEFAULT_MOTION;

   accelEffectType = MV_DEFAULT_EFFECT;
   velocityEffectType = MV_DEFAULT_EFFECT;
   directionEffectType = MV_DEFAULT_EFFECT;
   forceEffectType = MV_DEFAULT_EFFECT;
   torqueEffectType = MV_DEFAULT_EFFECT;
   omegaEffectType = MV_DEFAULT_EFFECT;
   quaternionEffectType = MV_DEFAULT_EFFECT;
   rotationEffectType = MV_DEFAULT_EFFECT;

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setQuaternion(const mvFloat* quatArray,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   mvIndex i;
   for (i = 0; i < MV_QUATERNION_LENGTH; i++)
   {
      quaternion[i] = quatArray[i];
   }
   applyQuaternion = true;
   quaternionEffectType = eType;
   quaternionMotionType = mType;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setDirection(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   direction = value;
   directionMotionType = mType;
   directionEffectType = eType;
   applyDirection = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setTorque(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   torque = value;
   torqueMotionType = mType;
   torqueEffectType = eType;
   applyTorque = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setVelocity(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   velocity = value;
   velocityMotionType = mType;
   velocityEffectType = eType;
   applyVelocity = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setAcceleration(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   acceleration = value;
   accelMotionType = mType;
   accelEffectType = eType;
   applyAccel = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setForce(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   force = value;
   forceMotionType = mType;
   forceEffectType = eType;
   applyForce = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setGroupIndex(mvIndex gIndex)
{
   groupIndex = gIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setBehaviourIndex(mvIndex bIndex)
{
   behaviourIndex = bIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviourResult::mvBehaviourResult(mvConstWorldPtr worldPtr,\
   mvConstBodyPtr bodyPtr) : currentWorld(worldPtr), currentBody(bodyPtr)
{
   elapsedSystemTime = 0;
   currentTimeStep = 0;
   currentGroupBehNode = MV_NULL;
   behaviourIndex = MV_NULL;
   groupIndex = MV_NULL;
   resetAll();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBehaviourResult::getBehaviourIndex() const
{
   return behaviourIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBehaviourResult::getGroupIndex() const
{
   return groupIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setOmega(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotionType = mType;
   omegaEffectType = eType;
   applyOmega = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setOmegaInDegrees(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotionType = mType;
   omegaEffectType = eType;
   applyOmega = true;
   omegaInDegrees = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviourResult::setOmegaInRadians(const mvVec3& value,\
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotionType = mType;
   omegaEffectType = eType;
   applyOmega = true;
   omegaInDegrees = false;
}

// new utility functions
mvConstWaypointPtr mvBehaviourResult::fetchWaypointPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstWaypointPtr(index);
}

mvConstBodyPtr mvBehaviourResult::fetchBodyPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstBodyPtr(index);
}

mvConstGroupBehaviourPtr mvBehaviourResult::fetchGroupBehaviourPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupBehaviourPtr(index);
}

mvConstPathwayPtr mvBehaviourResult::fetchPathwayPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstPathwayPtr(index);
}

mvConstGroupPtr mvBehaviourResult::fetchGroupPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupPtr(index);
}

void mvBehaviourResult::setElaspedSystemTime(mvFloat timeInSecs)
{
   elapsedSystemTime = timeInSecs;
}

void mvBehaviourResult::setCurrentTimeStep(mvFloat timeInSecs)
{
   currentTimeStep = timeInSecs;
}

void mvBehaviourResult::setPositionPrediction(const mvVec3& pos)
{
   brFuturePosition = pos;
}

void mvBehaviourResult::setFinalPositionPrediction(const mvVec3& pos)
{
   brFutureFinalPosition = pos;
}

void mvBehaviourResult::setVelocityPrediction(const mvVec3& vel)
{
   brFutureVelocity = vel;
}

void mvBehaviourResult::setFinalVelocityPrediction(const mvVec3& vel)
{
   brFutureFinalVelocity = vel;
}

void mvBehaviourResult::setGroupBehaviourNode(mvBaseActionPtr groupBehPtr)
{
   currentGroupBehNode = groupBehPtr;
}

mvFloat mvBehaviourResult::getTimeStep() const
{
   return currentTimeStep;
}

mvFloat mvBehaviourResult::getElapsedSystemTime() const
{
   return elapsedSystemTime;
}

void  mvBehaviourResult::setToLocalEffect()
{
   isDefaultEffectGlobal = false;
}

void  mvBehaviourResult::setToGlobalEffect()
{
   isDefaultEffectGlobal = true;
}

bool  mvBehaviourResult::isGlobalEffectDefault() const
{
   return isDefaultEffectGlobal;
}

bool  mvBehaviourResult::isSteeringMotionDefault() const
{
   return isDefaultMotionSteering;
}

mvConstBaseForcePtr mvBehaviourResult::fetchForcePtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstForcePtr(index);
}

const mvVec3& mvBehaviourResult::predictPositionOfCurrentBody() const
{
   return brFuturePosition;
}

const mvVec3& mvBehaviourResult::predictFinalPositionOfCurrentBody() const
{
   return brFutureFinalPosition;
}

const mvVec3& mvBehaviourResult::predictVelocityOfCurrentBody() const
{
   return brFutureVelocity;
}

const mvVec3& mvBehaviourResult::predictFinalVelocityOfCurrentBody() const
{
   return brFutureFinalVelocity;
}

bool mvBehaviourResult::isForceSet() const
{
   return applyForce;
}

const mvVec3& mvBehaviourResult::getForce() const
{
   return force;
}

mvMotionTypeEnum mvBehaviourResult::getForceMotionType() const
{
   return forceMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getForceEffectType() const
{
   return forceEffectType;
}

bool mvBehaviourResult::isAccelerationSet() const
{
   return applyAccel;
}

const mvVec3& mvBehaviourResult::getAcceleration() const
{
   return acceleration;
}

mvMotionTypeEnum mvBehaviourResult::getAccelerationMotionType() const
{
   return accelMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getAccelerationEffectType() const
{
   return accelEffectType;
}

bool mvBehaviourResult::isDirectionSet() const
{
   return applyDirection;
}

const mvVec3& mvBehaviourResult::getDirection() const
{
   return direction;
}

mvMotionTypeEnum mvBehaviourResult::getDirectionMotionType() const
{
   return directionMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getDirectionEffectType() const
{
   return directionEffectType;
}

bool mvBehaviourResult::isTorqueSet() const
{
   return applyTorque;
}

const mvVec3& mvBehaviourResult::getTorque() const
{
   return torque;
}

mvMotionTypeEnum mvBehaviourResult::getTorqueMotionType() const
{
   return torqueMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getTorqueEffectType() const
{
   return torqueEffectType;
}

bool mvBehaviourResult::isOmegaSet() const
{
   return applyOmega;
}

const mvVec3& mvBehaviourResult::getOmega() const
{
   return omega;
}

mvMotionTypeEnum mvBehaviourResult::getOmegaMotionType() const
{
   return omegaMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getOmegaEffectType() const
{
   return omegaEffectType;
}

bool mvBehaviourResult::isOmegaInDegrees() const
{
   return omegaInDegrees;
}

bool mvBehaviourResult::isVelocitySet() const
{
   return applyVelocity;
}

const mvVec3& mvBehaviourResult::getVelocity() const
{
   return velocity;
}

mvMotionTypeEnum mvBehaviourResult::getVelocityMotionType() const
{
   return velocityMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getVelocityEffectType() const
{
   return velocityEffectType;
}

bool mvBehaviourResult::isQuaternionSet() const
{
   return applyQuaternion;
}

const mvFloat* mvBehaviourResult::getQuaternion() const
{
   return quaternion;
}

mvMotionTypeEnum mvBehaviourResult::getQuaternionMotionType() const
{
   return quaternionMotionType;
}

mvEffectTypeEnum mvBehaviourResult::getQuaternionEffectType() const
{
   return quaternionEffectType;
}

bool  mvBehaviourResult::isRotationSet() const
{
   return applyRotation;
}

const mvVec3&  mvBehaviourResult::getRotation() const
{
   return rotation;
}

mvMotionTypeEnum  mvBehaviourResult::getRotationMotionType()\
   const
{
   return rotationMotionType;
}

mvEffectTypeEnum  mvBehaviourResult::getRotationEffectType()\
   const
{
      return rotationEffectType;
}

bool mvBehaviourResult::isRotationInDegrees() const
{
   return rotationInDegrees;
}

void mvBehaviourResult::setRotationInDegrees(const mvVec3& value,\
   mvMotionTypeEnum mType,\
   mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotionType = mType;
   rotationEffectType = eType;
   applyRotation = true;
   rotationInDegrees = true;
}

void mvBehaviourResult::setRotationInRadians(const mvVec3& value,\
   mvMotionTypeEnum mType,\
   mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotionType = mType;
   rotationEffectType = eType;
   applyRotation = true;
   rotationInDegrees = false;
}

