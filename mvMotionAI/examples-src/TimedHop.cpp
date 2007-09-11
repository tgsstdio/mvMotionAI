#include "TimedHop.h"
#include <iostream>

TimedHop::TimedHop()
   /* NOTE : you should use a different mvOptionEnum enum than
   *  existing mvBaseAction classes
   */
   : mvBaseAction(MV_NON_BODY_TYPE)
{

}

bool TimedHop::bodyOp(mvBehaviourResultPtr resultMod)
{
   if (!resultMod)
   {
      return false;
   }

   mvIndex currentTime = (mvIndex) (
      resultMod->getElapsedSystemTime() +resultMod->getTimeStep());

   if (currentTime % 2 == 0)
   {
      resultMod->setVelocity(mvVec3(0,4,0),MV_DIRECTIONAL_MOTION);
   }
   else
   {
      resultMod->setVelocity(mvVec3(0,-4,0),MV_DIRECTIONAL_MOTION);
   }
   return true;
}

bool TimedHop::groupOp(mvGroupBehaviourResultPtr groupBehMod)
{
   return false;
}

TimedHop::~TimedHop()
{

}

TimedHopLoader::TimedHopLoader()
{

}

mvBaseActionPtr TimedHopLoader::operator()(mvBaseActionPtr higherNode)
{
   return new TimedHop();
}

TimedHopLoader::~TimedHopLoader()
{

}
