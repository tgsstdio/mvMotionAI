#include "mvGravityForce.h"
#include <new>

mvGravityForce::mvGravityForce()
  : mvBaseForce(MV_GRAVITY),
  gravityForce(0,-9.8,0)
 {

 }

void mvGravityForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingNone();
   worldStatus.applyingGravity();
}

bool mvGravityForce::calcFullForces(mvForceResultPtr fResult)
{
   fResult->setGravity(gravityForce,MV_STEERING_MOTION, MV_GLOBAL_EFFECT);
   return true;
}

mvGravityForce::~mvGravityForce()
{

}

mvGravityForceLoader::mvGravityForceLoader()
{

}

mvBaseForcePtr mvGravityForceLoader::operator()(\
   void* extraPtr)
{
   return new mvGravityForce();
}

mvGravityForceLoader::~mvGravityForceLoader()
{

}
