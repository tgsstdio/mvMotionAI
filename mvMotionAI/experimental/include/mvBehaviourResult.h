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
 *
 * Log
 *
 * version     comments
 * 00-01-39
 * - renamed mv behaviour result to mv result for future use
 */

#ifndef MVBEHAVIOURRESULT_H_INCLUDED
#define MVBEHAVIOURRESULT_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_

#define MV_QUATERNION_LENGTH 4

//typedef void* mvWorldPtr;

typedef class mvBehaviourResult
{
   private:
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;
//      mvBaseAction* currentGroupBehNode;
      mvIndex behaviourIndex;
      mvIndex groupIndex;

      bool isSteering;
      bool applyAccel;
      bool applyVelocity;
      bool applyDirection;
      bool applyForce;
      bool applyTorque;
      // rotation change
      bool applyOmega;
      bool applyQuaternion;
      bool omegaInDegrees;

      mvVec3 force;
      mvVec3 acceleration;
      mvVec3 velocity;
      mvVec3 direction;
      mvVec3 torque;
      mvVec3 omega;
      mvFloat quaternion[MV_QUATERNION_LENGTH];

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;


   public:
      mvBehaviourResult(mvConstWorldPtr worldPtr, mvConstBodyPtr bodyPtr);
//      void setGroupBehaviourNode(mvBaseAction* groupBehPtr);

      void setBehaviourIndex(mvIndex bIndex);
      void setGroupIndex(mvIndex gIndex);

      void setForce(const mvVec3& value);
      void setAcceleration(const mvVec3& value);
      void setVelocity(const mvVec3& value);
      void setTorque(const mvVec3& value);
      void setDirection(const mvVec3& value);
      void setQuaternion(const mvFloat* quatArray);
      void setOmega(const mvVec3& value);
      void setOmegaInDegrees(const mvVec3& value);
      void setOmegaInRadians(const mvVec3& value);
      void resetAll();
      void setToDirectional();
      void setToSteering();

      mvConstWorldPtr getWorldPtr() const;
//      mvBaseAction* getGroupBehaviourNode();
      mvConstBodyPtr getCurrentBodyPtr() const;
      mvIndex getBehaviourIndex() const;
      mvIndex getGroupIndex() const;

      // utility functions
      // TODO: new predicter functions
      const mvVec3& predictPositionOfCurrentBody(mvFloat timeInSecs) const;
      const mvVec3& predictFinalPositionOfCurrentBody(mvFloat timeInSecs) const;

      const mvVec3& predictVelocityOfCurrentBody(mvFloat timeInSecs) const;
      const mvVec3& predictFinalVelocityOfCurrentBody(mvFloat timeInSecs) const;
      // maybe
      const mvVec3& confineVector(const mvVec3& v) const;

      // utility functions
      mvConstWaypointPtr fetchWaypointPtr(mvIndex index) const;
      mvConstBodyPtr fetchBodyPtr(mvIndex index) const;
      mvConstGroupBehaviourPtr fetchGroupBehaviourPtr(mvIndex gbIndex) const;
      mvConstPathwayPtr fetchPathwayPtr(mvIndex index) const;
      mvConstGroupPtr fetchGroupPtr(mvIndex index) const;
} mvResult;


#endif // MVBEHAVIOURRESULT_H_INCLUDED
