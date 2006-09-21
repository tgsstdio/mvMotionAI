/**
 * \file mvBehaviour-Pursuit.cpp
 *
 * Copyright (c) 2006 David Young.
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

#include "mvBehaviour-Pursuit.h"

/**
 *Based on Robin Green's Steering Behaviours html page,2001
 *
 * Pursuit - chasing bodies
 *
 * Vector2d Pursuit::calculate(const Pilot &target)
 *{
 * mvFloat dist = (target.pos - pos).length();
 * Vector2d target_pos = target.predict(dist/max_speed);
 * desired_velocity = normalise(target_pos - pos) * max_speed;
 * return desired_velocity - vel;
 * // set the final velocity to include the current velocity to average out
 * // calculation to stop jittering
 *}
**/

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
};


