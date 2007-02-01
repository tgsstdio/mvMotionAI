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
#include "mvFlee.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvFlee::getParameteri(mvParamEnum param, mvIndex* index)
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   if (param == MV_WAYPOINT)
   {
      *index = waypointIndex;
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
mvErrorEnum mvFlee::getParameterf(mvParamEnum param, mvFloat* num)
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (param == MV_LENGTH)
   {
      *num = length;
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
mvErrorEnum mvFlee::setParameteri(mvParamEnum param, mvIndex index)
{
   if (param == MV_WAYPOINT)
   {
      waypointIndex = index;
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
mvErrorEnum mvFlee::setParameterf(mvParamEnum param, mvFloat num)
{
   if (param == MV_LENGTH)
   {
      length = num;
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
bool mvFlee::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   puts("FLEE GROUP OPERATION");
   return false;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvFlee::bodyOp(mvBehaviourResultPtr resultModule)
{
   /*
   from file mvBehaviour-Flee.h/.cpp (2006)

   mvVec3 final_velocity;
   mvVec3 direction;
   mvVec3 target;
   mvVec3 pos;

   if (body != NULL && point != NULL)
   {
      pos = body->position;
      target.set(point->getX(),point->getY(),point->getZ());
      direction = pos - target;
      final_velocity = body->maxSpeed * direction.normalize();
      final_velocity -= body->finalVelocity;
   }
   return final_velocity;

   0.5 is averaged with steering + direction
   */
// TODO: incorporate length into equation
   mvVec3 targetPos, direction, velocity;
   mvWaypointPtr point = NULL;
   mvBodyPtr b = NULL;
   mvWorldPtr world = NULL;

   if (resultModule == NULL)
   {
      return false;
   }

   world = resultModule->getWorld();
   if (world == NULL)
   {
      return false;
   }

   b = resultModule->getBody();
   if (b == NULL)
   {
      return false;
   }

   point = world->getWaypointPtr(waypointIndex);
   if (point == NULL)
   {
      return false;
   }

   direction.setAll(b->position);
   targetPos.set(point->getX(), point->getY(), point->getZ());
   direction.minusVec3(targetPos);
   velocity = direction.normalize();
   velocity *= b->maxSpeed;
   velocity *= 0.5;

   resultModule->setVelocity(velocity);
   resultModule->setToDirectional();

   return true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvFlee::mvFlee() : mvBaseBehaviour(MV_FLEE)
{
   waypointIndex = MV_NO_CURRENT_INDEX;
   length = 0;
}

mvCreateFlees::mvCreateFlees()
{

}

mvBaseBehaviourPtr mvCreateFlees::operator()(mvBaseBehaviourPtr defaultBehav)
{
   return new mvFlee();
};




