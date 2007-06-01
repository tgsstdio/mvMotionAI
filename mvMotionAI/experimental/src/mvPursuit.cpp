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
#include "mvPursuit.h"
#include <new>

mvCreatePursuits::mvCreatePursuits()
{

};

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseAction* mvCreatePursuits::operator()(mvBaseAction* defaultBehav)
{
   return new (std::nothrow) mvPursuit();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPursuit::getParameteri(mvParamEnum param, mvIndex* index)
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   if (param == MV_BODY)
   {
      *index = targetObject;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPursuit::setParameteri(mvParamEnum param, mvIndex index)
{
   if (param == MV_BODY)
   {
      targetObject = index;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvPursuit::bodyOp(mvBehaviourResultPtr resultModule)
{
/*
mvVec3 mvBehaviour_Calculate_Pursuit(mvBody* currentBody, mvBody* targetBody)
{
   mvVec3 targetDir, finalVelocity, desiredVelocity, nextPos;
   mvFloat dist = 0.0;
   if (currentBody != NULL && targetBody != NULL)
   {
      dist = (targetBody->position - currentBody->position).length();

      nextPos = targetBody->position + (targetBody->direction * targetBody->speed * (dist/currentBody->maxSpeed));

      desiredVelocity = (nextPos - currentBody->position).normalize() * currentBody->maxSpeed;

      //finalVelocity = (desiredVelocity - (currentBody->speed * currentBody->direction)) + (currentBody->speed * currentBody->direction);
      finalVelocity = desiredVelocity;
      finalVelocity *= 0.5;
   }
   return finalVelocity;
}
*/
   mvVec3 targetDir, desiredVelocity, nextPos, velocity;
   mvBodyPtr body = NULL;
   mvBodyPtr target = NULL;
   mvWorldPtr world = NULL;
   mvFloat period = 0;

   if (resultModule == NULL)
   {
      return false;
   }

   world = resultModule->getWorld();
   if (world == NULL)
   {
      return false;
   }

   body = resultModule->getBody();
   if (body == NULL)
   {
      return false;
   }

   target = world->getBodyPtr(targetObject);
   if (target == NULL)
   {
      return false;
   }

   targetDir.setAll(target->position);
   targetDir.minusVec3(body->position);

   period = targetDir.length();
   period /= body->maxSpeed;

   // nextPos = targetBody->position +
   //(targetBody->direction * targetBody->speed *
   // (dist/currentBody->maxSpeed));

   nextPos.setAll(target->direction);
   nextPos *= target->speed;
   nextPos *= period;
   nextPos.addVec3(target->position);

   // desiredVelocity = (nextPos - currentBody->position).normalize()
   // * currentBody->maxSpeed;
   // finalVelocity = desiredVelocity;
   // finalVelocity *= 0.5;
   desiredVelocity.setAll(nextPos);
   desiredVelocity.minusVec3(body->position);
   velocity = desiredVelocity.normalize();
   velocity *= body->maxSpeed;
   velocity *= 0.5;

   resultModule->setVelocity(velocity);
   resultModule->setToDirectional();

   return true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvPursuit::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   puts("PURSUIT - GROUP OPERATION");
   return false;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPursuit::mvPursuit() : mvBaseAction(MV_PURSUIT)
{
   targetObject = MV_NO_CURRENT_INDEX;
}
