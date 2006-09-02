#include "mvBehaviour-Seek.h"
/**
 * \brief mvBehaviour Seek behaviour
 * 2006
 * using (psuedo-)code from SIGGRAPH 2000 article - Steering Behaviours
 * by Robin Green (2000)
 */
mvVec3 mvBehaviour_Calculate_Seek(mvBody* body, mvWaypoint* point)
{
   mvVec3 final_velocity;
   mvVec3 direction;
   mvVec3 target;
   mvVec3 pos;   
  
   if (body != NULL && point != NULL)
   {
      pos = body->position;
      target.set(point->getX(),point->getY(),point->getZ());
      direction = target - pos;
      final_velocity = body->maxSpeed * direction.normalize();
      final_velocity -= body->finalVelocity;
   }   
   return final_velocity; 
};
