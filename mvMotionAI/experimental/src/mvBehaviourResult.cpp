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
#include "mvBehaviourResult.h"

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstBodyPtr mvResult::getCurrentBodyPtr() const
{
   return currentBody;
}


// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvBaseBehaviour * mvResult::getGroupBehaviourNode()
//{
//   return currentGroupBehNode;
//}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvConstWorldPtr mvResult::getWorldPtr() const
{
   return currentWorld;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setToSteering()
{
   isSteering = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setToDirectional()
{
   isSteering = false;
}

/** @brief (one liner)
  *
  * default behaviour return type is directional
  */
void mvResult::resetAll()
{
   //currentWorld = MV_NULL;
   //currentBody = MV_NULL;
//   currentGroupBehNode = MV_NULL;
   behaviourIndex = MV_NULL;
   groupIndex = MV_NULL;

   isSteering = false;
   applyAccel = false;
   applyVelocity = false;
   applyDirection = false;
   applyForce = false;
   applyTorque = false;

   applyOmega = false;
   omegaInDegrees = true;
   applyQuaternion = false;

   force.resetXYZ();
   acceleration.resetXYZ();
   velocity.resetXYZ();
   direction.resetXYZ();
   torque.resetXYZ();
   omega.resetXYZ();

   // reset quaternion
   mvIndex i;
   for (i = 0; i < MV_QUATERNION_LENGTH; i++)
   {
      quaternion[MV_QUATERNION_LENGTH] = 0.0;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setQuaternion(const mvFloat* quatArray)
{
   mvIndex i;
   for (i = 0; i < MV_QUATERNION_LENGTH; i++)
   {
      quaternion[i] = quatArray[i];
   }
   applyQuaternion = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setDirection(const mvVec3& value)
{
   direction = value;
   applyDirection = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setTorque(const mvVec3& value)
{
   torque = value;
   applyTorque = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setVelocity(const mvVec3& value)
{
   velocity = value;
   applyVelocity = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setAcceleration(const mvVec3& value)
{
   acceleration = value;
   applyAccel = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setForce(const mvVec3& value)
{
   force = value;
   applyForce = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setGroupIndex(mvIndex gIndex)
{
   groupIndex = gIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setBehaviourIndex(mvIndex bIndex)
{
   behaviourIndex = bIndex;
}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//void mvResult::setGroupBehaviourNode(mvBaseBehaviour* groupBehPtr)
//{
//   currentGroupBehNode = groupBehPtr;
//}


/* @brief (one liner)
  *
  * (documentation goes here)
  *
  // invalid
void mvResult::setCurrentBodyPtr(mvBodyPtr bodyPtr)
{
   currentBody = bodyPtr;
}
*/

/* @brief (one liner)
  *
  * (documentation goes here)
  *
// invalid
void mvResult::setWorldPtr(mvWorldPtr worldPtr)
{
   currentWorld = worldPtr;
}
*/

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviourResult::mvBehaviourResult(mvConstWorldPtr worldPtr,\
   mvConstBodyPtr bodyPtr) : currentWorld(worldPtr), currentBody(bodyPtr)
{
   resetAll();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvResult::getBehaviourIndex() const
{
   return behaviourIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvResult::getGroupIndex() const
{
   return groupIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setOmega(const mvVec3& value)
{
   omega = value;
   applyOmega = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setOmegaInDegrees(const mvVec3& value)
{
   omega = value;
   applyOmega = true;
   omegaInDegrees = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvResult::setOmegaInRadians(const mvVec3& value)
{
   omega = value;
   applyOmega = true;
   omegaInDegrees = false;
}

// new utility functions
mvConstWaypointPtr mvResult::fetchWaypointPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstWaypointPtr(index);
}

mvConstBodyPtr mvResult::fetchBodyPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstBodyPtr(index);
}

mvConstGroupBehaviourPtr mvResult::fetchGroupBehaviourPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupBehaviourPtr(index);
}

mvConstPathwayPtr mvResult::fetchPathwayPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstPathwayPtr(index);
}

mvConstGroupPtr mvResult::fetchGroupPtr(mvIndex index) const
{
   if (currentWorld == MV_NULL)
   {
      return MV_NULL;
   }

   return currentWorld->getConstGroupPtr(index);
}


