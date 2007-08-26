#include "mvUniformForce.h"

mvUniformForce::mvUniformForce()
   : mvBaseForce(MV_UNIFORM_FORCE),
   uForce(5,0,0)
{

}

void mvUniformForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingNone();
   worldStatus.applyingForce();
}

mvUniformForce::~mvUniformForce()
{

}

bool mvUniformForce::calcFullForces(mvForceResultPtr fResult)
{
   // todo : some type of mvMotionAI : ASSERT
   if (fResult == MV_NULL)
   {
      return false;
   }

   fResult->setForce(uForce,MV_STEERING_MOTION,MV_GLOBAL_EFFECT);
   return true;
}

mvUniformForceLoader::mvUniformForceLoader()
   : mvBaseForceLoader()
{

}

mvBaseForcePtr mvUniformForceLoader::operator()(void* extraPtr)
{
   return new mvUniformForce();
}
