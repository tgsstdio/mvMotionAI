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


