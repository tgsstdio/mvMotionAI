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
#include <mv/mvSeek.h>

mvSeek::mvSeek() : mvBaseAction(MV_SEEK),
   length(0),  waypointIndex(MV_NULL)
{

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

   // 1. check if input/output class pointer is valid
   if (resultModule == MV_NULL)
   {
      // 1.a exit here & apply no operation
      return false;
   }

   // 2. check body pointer is valid
   mvConstBodyPtr bodyPtr = resultModule->getCurrentBodyPtr();
   if (bodyPtr == MV_NULL)
   {
      return false;
   }

   // 3. fetch waypoint module from list
   mvConstWaypointPtr point = resultModule->fetchWaypointPtr(waypointIndex);
   if (point == MV_NULL)
   {
      return false;
   }

   pos = bodyPtr->getPosition();
   direction = point->getPosition();
   direction -= pos;
   velocity = direction.normalize();
   velocity *= bodyPtr->getMaxSpeed();
   resultModule->setVelocity(velocity);

   // behaviour result is direction (not steering force)
   resultModule->setToDirectional();

   // integration include this operation
   return true;
}

mvSeek::~mvSeek()
{

}

mvErrorEnum mvSeek::setParameterf(mvParamEnum param, mvFloat num)
{
   mvErrorEnum error = mvBaseAction::setParameterf(param, num);

   if (error != MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      return error;
   }

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
   mvErrorEnum error = mvBaseAction::setParameteri(param, index);

   if (error != MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      return error;
   }

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

mvErrorEnum mvSeek::getParameterf(mvParamEnum param, mvFloat* num) const
{
   mvErrorEnum error = mvBaseAction::getParameterf(param, num);

   if (error != MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      return error;
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

mvErrorEnum mvSeek::getParameteri(mvParamEnum param, mvIndex* index) const
{
   mvErrorEnum error = mvBaseAction::getParameteri(param, index);

   if (error != MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      return error;
   }

   switch(param)
   {
      case MV_WAYPOINT:
         *index = waypointIndex;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;

   }
}

bool mvSeek::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   return false;
}
