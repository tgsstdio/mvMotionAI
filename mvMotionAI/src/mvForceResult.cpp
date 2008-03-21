/**
 * \file mvForceResult.cpp
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
#include <mv/mvForceResult.h>

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
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
 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstWaypointPtr mvForceResult::fetchWaypointPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->waypoints.getConstClassPtr(index);
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstBodyPtr mvForceResult::fetchBodyPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->bodies.getConstClassPtr(index);
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstGroupBehaviourPtr mvForceResult::fetchGroupBehaviourPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->groupBehaviours.getConstClassPtr(index);
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstPathwayPtr mvForceResult::fetchPathwayPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->pathways.getConstClassPtr(index);
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstGroupPtr mvForceResult::fetchGroupPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->groups.getConstClassPtr(index);
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setElaspedSystemTime(mvFloat timeInSecs)
{
   elapsedSystemTime = timeInSecs;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setCurrentTimeStep(mvFloat timeInSecs)
{
   currentTimeStep = timeInSecs;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setPositionPrediction(const mvVec3& pos)
{
   brFuturePosition = pos;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setFinalPositionPrediction(const mvVec3& pos)
{
   brFutureFinalPosition = pos;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setVelocityPrediction(const mvVec3& vel)
{
   brFutureVelocity = vel;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvForceResult::setFinalVelocityPrediction(const mvVec3& vel)
{
   brFutureFinalVelocity = vel;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvFloat mvForceResult::getTimeStep() const
{
   return currentTimeStep;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvFloat mvForceResult::getElapsedSystemTime() const
{
   return elapsedSystemTime;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvConstBaseForcePtr mvForceResult::fetchForcePtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->forces.getConstClassPtr(index);
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::predictPositionOfCurrentBody() const
{
   return brFuturePosition;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::predictFinalPositionOfCurrentBody() const
{
   return brFutureFinalPosition;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::predictVelocityOfCurrentBody() const
{
   return brFutureVelocity;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::predictFinalVelocityOfCurrentBody() const
{
   return brFutureFinalVelocity;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isForceSet() const
{
   return applyForce;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getForce() const
{
   return force;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isAccelerationSet() const
{
   return applyAccel;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getAcceleration() const
{
   return acceleration;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isDirectionSet() const
{
   return applyDirection;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getDirection() const
{
   return direction;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isTorqueSet() const
{
   return applyTorque;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getTorque() const
{
   return torque;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isOmegaSet() const
{
   return applyOmega;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getOmega() const
{
   return omega;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isOmegaInDegrees() const
{
   return omegaInDegrees;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isShiftSet() const
{
   return applyShift;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getShift() const
{
   return shiftVec;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isQuaternionSet() const
{
   return applyQuaternion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvFloat* mvForceResult::getQuaternion() const
{
   return quaternion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool  mvForceResult::isRotationSet() const
{
   return applyRotation;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3&  mvForceResult::getRotation() const
{
   return rotation;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isRotationInDegrees() const
{
   return rotationInDegrees;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isDragForceSet() const
{
   return applyDragForce;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvFloat mvForceResult::getDragForce() const
{
   return dragForce;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isDragAccelerationSet() const
{
   return applyDragAccel;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvFloat mvForceResult::getDragAcceleration() const
{
   return dragAcceleration;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isGravitySet() const
{
   return applyGravity;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
const mvVec3& mvForceResult::getGravity() const
{
   return gravity;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool mvForceResult::isDragShiftSet() const
{
   return applyDragShift;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvFloat mvForceResult::getDragShift() const
{
   return dragShift;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setForce(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   force = value;
   forceMotion = mType;
   forceEffect = eType;
   applyForce = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setAcceleration(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   acceleration = value;
   accelMotion = mType;
   accelEffect = eType;
   applyAccel = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setGravity(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   gravity = value;
   gravityEffect = eType;
   gravityMotion = mType;
   applyGravity = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setShift(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   shiftVec = value;
   shiftMotion = mType;
   shiftEffect = eType;
   applyShift = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setTorque(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   torque = value;
   torqueMotion = mType;
   torqueEffect = eType;
   applyTorque = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
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

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setDirection(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   direction = value;
   directionMotion = mType;
   directionEffect = eType;
   applyDirection = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setOmegaInDegrees(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotion = mType;
   omegaEffect = eType;
   applyOmega = true;
   omegaInDegrees = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setOmegaInRadians(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   omega = value;
   omegaMotion = mType;
   omegaEffect = eType;
   applyOmega = true;
   omegaInDegrees = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setRotationInDegrees(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotion = mType;
   rotationEffect = eType;
   applyRotation = true;
   rotationInDegrees = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setRotationInRadians(const mvVec3& value,
   mvMotionTypeEnum mType, mvEffectTypeEnum eType)
{
   rotation = value;
   rotationMotion = mType;
   rotationEffect = eType;
   applyRotation = true;
   rotationInDegrees = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum   mvForceResult::getForceMotionType() const
{
   return forceMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum   mvForceResult::getForceEffectType() const
{
   return forceEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum   mvForceResult::getAccelerationMotionType() const
{
   return accelMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum   mvForceResult::getAccelerationEffectType() const
{
   return accelEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum   mvForceResult::getDirectionMotionType() const
{
   return directionMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum mvForceResult::getDirectionEffectType() const
{
   return directionEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum mvForceResult::getTorqueMotionType() const
{
   return torqueMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum mvForceResult::getTorqueEffectType() const
{
   return torqueEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum   mvForceResult::getOmegaMotionType() const
{
   return omegaMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum mvForceResult::getOmegaEffectType() const
{
   return omegaEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum mvForceResult::getShiftMotionType() const
{
   return shiftMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum mvForceResult::getShiftEffectType() const
{
   return shiftEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum mvForceResult::getQuaternionMotionType() const
{
   return quaternionMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum   mvForceResult::getQuaternionEffectType() const
{
   return quaternionEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum mvForceResult::getGravityMotionType() const
{
   return gravityMotion;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvEffectTypeEnum mvForceResult::getGravityEffectType() const
{
   return gravityEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
mvMotionTypeEnum mvForceResult::getRotationMotionType() const
{
   return rotationMotion;
}

mvEffectTypeEnum   mvForceResult::getRotationEffectType() const
{
   return rotationEffect;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
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

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableForce()
{
   applyForce = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableAccel()
{
   applyAccel = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableShift()
{
   applyShift = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableGravity()
{
   applyGravity = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableTorque()
{
   applyTorque = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableOmega()
{
   applyOmega = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableDirection()
{
   applyDirection = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableQuaternion()
{
   applyQuaternion = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableRotation()
{
   applyRotation = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableDragForce()
{
   applyDragForce = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableDragAccel()
{
   applyDragAccel = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::disableDragShift()
{
   applyDragShift = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool  mvForceResult::isGlobalEffectDefault() const
{
   return isDefaultEffectGlobal;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
bool  mvForceResult::isSteeringMotionDefault() const
{
   return isDefaultMotionSteering;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void  mvForceResult::setToLocalEffect()
{
   isDefaultEffectGlobal = false;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void  mvForceResult::setToGlobalEffect()
{
   isDefaultEffectGlobal = true;
}

/** @brief (one liner)
*
* (documentation goes here)
*/
void mvForceResult::setToSteering()
{
   isDefaultMotionSteering = true;
}

void mvForceResult::setToDirectional()
{
   isDefaultMotionSteering = false;
}
