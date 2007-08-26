#include "mvUniformShiftForce.h"

mvUniformShiftForce::mvUniformShiftForce()
  : mvBaseForce(MV_UNIFORM_SHIFT),
  uShift(-3,0,0)
 {

 }

void mvUniformShiftForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingNone();
   worldStatus.applyingShifts();
}

bool mvUniformShiftForce::calcFullForces(mvForceResultPtr fResult)
{
   // todo : some type of mvMotionAI : ASSERT
   if (fResult == MV_NULL)
   {
      return false;
   }

   fResult->setShift(uShift,MV_STEERING_MOTION, MV_GLOBAL_EFFECT);
   return true;
}

mvUniformShiftForce::~mvUniformShiftForce()
{

}

mvUniformShiftForceLoader::mvUniformShiftForceLoader() : mvBaseForceLoader()
{

}

mvBaseForcePtr mvUniformShiftForceLoader::operator()(\
   void* extraPtr)
{
   return new mvUniformShiftForce();
}
