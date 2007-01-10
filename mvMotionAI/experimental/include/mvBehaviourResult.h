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

#ifndef MVBEHAVIOURRESULT_H_INCLUDED
#define MVBEHAVIOURRESULT_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvWorld.h"

#define MV_QUATERNION_LENGTH 4

class mvBehaviourResult
{
   private:
      void resetResult();

   public:
      mvWorld* currentWorld;
      mvBody* currentBody;
      mvBaseBehaviour* currentGroupNode;

      bool isSteering;
      bool applyAccel;
      bool applyVecel;
      bool applyDirection;
      bool applyForce;
      bool applyTorque;
      // rotation change
      bool applyOmega;
      bool applyQuaternion;

      mvVec3 force;
      mvVec3 acceleration;
      mvVec3 velocity;
      mvVec3 direction;
      mvVec3 torque;
      mvVec3 omega;
      mvFloat quaternion[MV_QUATERNION_LENGTH];

      mvBehaviourResult();
      void setWorld(mvWorld* worldPtr);
      void setBody(mvBody* bodyPtr);
      void setGroupBehaviourNode(mvBaseBehaviour* groupBehPtr);

      void setGroup(mvGroup* groupPtr);

      void setForce(const mvVec3& value);
      void setAcceleration(const mvVec3& value);
      void setVelocity(const mvVec3& value);
      void setTorque(const mvVec3& value);
      void setDirection(const mvVec3& value);
      void setQuaternion(const mvFloat* quatArray);
      void resetAll();
      void setToDirectional();
      void setToSteering();

      mvWorld* getWorld();
      mvBaseBehaviour* getGroupBehaviourNode();
      mvBody*  getBody();
};

#endif // MVBEHAVIOURRESULT_H_INCLUDED
