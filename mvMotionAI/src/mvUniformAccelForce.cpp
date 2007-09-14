#include <mv/mvUniformAccelForce.h>

mvUniformAccelForce::mvUniformAccelForce()
   : mvBaseForce(MV_UNIFORM_FORCE),
   uAccel(0,0,8)
{

}

void mvUniformAccelForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingNone();
   worldStatus.applyingAcceleration();
}

mvUniformAccelForce::~mvUniformAccelForce()
{

}

bool mvUniformAccelForce::calcFullForces(mvForceResultPtr fResult)
{
   // todo : some type of mvMotionAI : ASSERT
   if (fResult == MV_NULL)
   {
      return false;
   }


   fResult->setAcceleration(uAccel,MV_STEERING_MOTION,MV_GLOBAL_EFFECT);
   return true;

}

mvUniformAccelForceLoader::mvUniformAccelForceLoader()
   : mvBaseForceLoader()
{

}

mvBaseForcePtr mvUniformAccelForceLoader::operator()(void* extraPtr)
{
   return new mvUniformAccelForce();
}
