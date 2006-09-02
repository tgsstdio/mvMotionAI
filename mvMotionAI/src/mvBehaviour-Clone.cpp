#include "mvBehaviour-Clone.h"

mvVec3 mvBehaviour_Calculate_Clone(mvBody* currentBody, mvBody* targetBody,
                                mvFloat syncRatio)
{
   mvVec3 finalVelocity;

   if (targetBody != NULL)
   {      
      finalVelocity = targetBody->speed * targetBody->direction;
   }
   return finalVelocity;
};

