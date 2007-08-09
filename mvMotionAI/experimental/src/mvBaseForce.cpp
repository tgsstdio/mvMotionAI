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
   rotationOn = true;
   quaternionOn = true;
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
   rotationOn = false;
   quaternionOn = false;
}

void mvForceStatus::applyingLinearMotionOnly()
{
   forcesOn = true;
   gravityOn = true;
   accelerationOn = true;
   shiftsOn = true;
}

void mvForceStatus::applyingAngularMotionOnly()
{
   torqueOn = true;
   omegaOn = true;
   rotationOn = true;
   quaternionOn = true;
}

void mvForceStatus::forLocalForceOnly()
{
   onlyLocalForce = true;
}

void mvForceStatus::forGlobalForceOnly()
{
   onlyGlobalForce = true;
}

void mvForceStatus::applyingGravity()
{
   gravityOn = false;
}
void mvForceStatus::applyingAcceleration()
{
   accelerationOn = true;
}

void mvForceStatus::applyingShifts()
{
   shiftsOn = false;
}

void mvForceStatus::applyingFullDrag()
{
   dragForceOn = true;
   dragAccelerationOn = true;
   dragShiftOn = true;
}

void mvForceStatus::applyingDragForce()
{
   dragForceOn = true;
}

void mvForceStatus::applyingDragAcceleration()
{
   dragAccelerationOn = true;
}

void mvForceStatus::applyingDragShift()
{
   dragShiftOn = true;
}

void mvForceStatus::applyingForce()
{
   forcesOn = true;
}

void mvForceStatus::applyingTorque()
{
   torqueOn = true;
}

void mvForceStatus::applyingOmega()
{
   omegaOn = true;
}

void mvForceStatus::applyingRotation()
{
   rotationOn = true;
}

void mvForceStatus::applyingQuaternion()
{
   quaternionOn = true;
}

