#include "mvBaseForce.h"

mvBaseForce::mvBaseForce(mvOptionEnum type)
{
   fType = type;
}

mvOptionEnum mvBaseForce::getType() const
{
   return fType;
}

void mvBaseForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingAll();
}

mvErrorEnum mvBaseForce::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* dest) const
{
   if (dest == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::getParameterf(mvParamEnum paramFlag, mvFloat* dest)\
   const
{
   if (dest == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::getParameterv(mvParamEnum paramFlag, mvFloat* dest,\
   mvCount* size) const
{
   if (size == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (dest == MV_NULL)
   {
      *size = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_FORCE_PARAMETER;
}

mvErrorEnum mvBaseForce::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

mvBaseForce::~mvBaseForce()
{

}

// force status

mvForceStatus::mvForceStatus()
{
   applyingNone();
}

void mvForceStatus::applyingAll()
{
   onlyLocalForce = false;
   onlyGlobalForce = false;
   forcesOn = true;
   gravityOn = true;
   accelerationOn = true;
   shiftsOn = true;
   dragForceOn = true;
   dragAccelerationOn = true;
   dragShiftOn = true;
   torqueOn = true;
   omegaOn = true;
}

void mvForceStatus::applyingNone()
{
   onlyLocalForce = true;
   onlyGlobalForce = true;
   forcesOn = false;
   gravityOn = false;
   accelerationOn = false;
   shiftsOn = false;
   dragForceOn = false;
   dragAccelerationOn = false;
   dragShiftOn = false;
   torqueOn = false;
   omegaOn = false;
}

// TODO : force status flags
void mvForceStatus::applyingLinearMotionOnly()
{

}

void mvForceStatus::applyingAngularMotionOnly()
{

}

void mvForceStatus::forLocalForceOnly()
{

}

void mvForceStatus::forGlobalForceOnly()
{

}

void mvForceStatus::applyingGravity()
{

}
void mvForceStatus::applyingAcceleration()
{

}

void mvForceStatus::applyingShifts()
{

}

void mvForceStatus::applyingFullDrag()
{

}

void mvForceStatus::applyingDragForce()
{

}

void mvForceStatus::applyingDragAcceleration()
{

}

void mvForceStatus::applyingDragShift()
{

}

void mvForceStatus::applyingForces()
{

}

void mvForceStatus::applyingTorque()
{

}

void mvForceStatus::applyingOmega()
{

}

