#include "mvBehaviour-Flee.h"

mvVec3 mvBehaviour_Calculate_Flee(mvBody* body, mvWaypoint* point)
{
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
};
