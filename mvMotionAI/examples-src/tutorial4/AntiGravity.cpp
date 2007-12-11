#include "AntiGravity.h"

AntiGravity::AntiGravity(mvOptionEnum forceKey)
 : mvBaseForce(forceKey)
{

}

void AntiGravity::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingNone();
   worldStatus.applyingAcceleration();
   worldStatus.forLocalForceOnly();
}

bool AntiGravity::calcFullForces(mvForceResultPtr fResult)
{
   mvVec3 updraft(0,10,0);

   if(fResult)
   {
      fResult->setAcceleration(updraft);
      fResult->setToSteering();
      return true;
   }
   else
   {
      return false;
   }
}

AntiGravity::~AntiGravity()
{

}

AntiGravityLoader::AntiGravityLoader(mvOptionEnum forceKey)
 : typeKey(forceKey)
{

}

mvBaseForcePtr AntiGravityLoader::operator()(void* extraPtr)
{
   return new AntiGravity(typeKey);
}

AntiGravityLoader::~AntiGravityLoader()
{

}

