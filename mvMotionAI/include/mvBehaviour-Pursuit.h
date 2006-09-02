#ifndef MV_BEHAVIOUR_PURSUIT_H_
#define MV_BEHAVIOUR_PURSUIT_H_
#include "mvVec3.h"
#include "mvBody.h"
#include "mvMotionAI-Types.h"
/**

Vector2d Pursuit::calculate(const Pilot &target)
{
   float dist = (target.pos - pos).length();
   Vector2d target_pos = target.predict(dist/max_speed);
   desired_velocity = normalise(target_pos - pos) * max_speed;
   return desired_velocity - vel;
}
**/
mvVec3 mvBehaviour_Calculate_Pursuit(mvBody* currentBody, mvBody* targetBody);                               

#endif