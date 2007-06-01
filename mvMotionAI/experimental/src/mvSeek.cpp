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
#include "mvSeek.h"
#include <new>

mvSeek::mvSeek() : mvBaseAction(MV_SEEK)
{
   length = 0;
   waypointIndex = MV_NO_CURRENT_INDEX;
}

bool mvSeek::bodyOp(mvBehaviourResultPtr resultModule)
{
   // TODO: incorporate length into equation
   /*
      ********************************
      * mvBehaviour Seek behaviour  2006 using (psuedo-)code from
      * SIGGRAPH 2000 article - Steering Behaviours by Robin Green (2000)
      * later copied out of mvBehaviour-Seek.h/.cpp Dec 2006
      ********************************
      mvVec3 mvBehaviour_Calculate_Seek(mvBody* body, mvWaypoint* point)
      {
         mvVec3 final_velocity;
         mvVec3 direction;
         mvVec3 target;
         mvVec3 pos;
         if (body != NULL && point != NULL)
         {
            pos = body->position;
            target = point;
            direction = target - pos;
            final_velocity = body->maxSpeed * direction.normalize();
            final_velocity -= body->finalVelocity;
         }
         return final_velocity;
      }
      restult = 0.5  times [i.e averaged with] (new velocity + old velocity)
   */
   mvVec3 pos, direction, velocity;
   const mvBodyPtr bodyPtr = NULL;
   mvWaypointPtr point = NULL;

   // 1. check if input/output class pointer is valid
   if (resultModule == NULL)
   {
      // 1.a exit here & apply no operation
      return false;
   }

   // 2. check body pointer is valid
   bodyPtr = resultModule->getCurrentBodyPtr();
   if (bodyPtr == NULL)
   {
      return false;
   }

   // 3. fetch waypoint module from list
   point = resultModule->fetchWaypointPtr(waypointIndex);
   if (point == NULL)
   {
      return false;
   }

   // pos = body->position;
   pos = bodyPtr->getPosition();
   // direction = target - pos;
   direction.set(point->getX(), point->getY(), point->getZ());
   direction.minusVec3(pos);
   /*
    * final velocity == velocity
    * final_velocity = body->maxSpeed * direction.normalize();
    * final_velocity -= body->finalVelocity;
   */
   velocity.setAll(direction.normalize());
   velocity *= bodyPtr->getMaxSpeed();
   velocity *= 0.5;
   /*
    * velocity.minusVec3(body->finalVelocity);
    */
   resultModule->setVelocity(velocity);

   // behaviour result is direction (not steering force)
   resultModule->setToDirectional();

   // integration include this operation
   return true;
}

mvErrorEnum mvSeek::setParameterf(mvParamEnum param, mvFloat num)
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

mvErrorEnum mvSeek::setParameteri(mvParamEnum param, mvIndex index)
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

mvErrorEnum mvSeek::getParameterf(mvParamEnum param, mvFloat* num)
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

mvErrorEnum mvSeek::getParameteri(mvParamEnum param, mvIndex* index)
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

bool mvSeek::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   return false;
}

mvCreateSeeks::mvCreateSeeks()
{
   // empty body
}

mvBaseAction* mvCreateSeeks::operator()(mvBaseAction* defaultBehav)
{
   return new (std::nothrow) mvSeek();
}
