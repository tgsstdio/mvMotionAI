#include "mvBaseForce.h"

mvBaseForce::mvBaseForce(mvOptionEnum type)
{
   fType = type;
   isForceEnabled = true;
   userData = MV_NULL;
}

mvOptionEnum mvBaseForce::getType() const
{
   return fType;
}

bool mvBaseForce::isEnabled() const
{
   return isForceEnabled;
}

void mvBaseForce::setEnabled(bool value)
{
   isForceEnabled = value;
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

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (isForceEnabled)
         {
            *dest = MV_TRUE;
         }
         else
         {
            *dest = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_FORCE_PARAMETER;
   }
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
   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            isForceEnabled = false;
         }
         else
         {
            isForceEnabled = true;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_FORCE_PARAMETER;
   }
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

void* mvBaseForce::getUserData() const
{
   return userData;
}

void mvBaseForce::setUserData(void* tempData)
{
   userData = tempData;
}

// force loader
mvBaseForceLoader::mvBaseForceLoader()
{

}

mvBaseForceLoader::~mvBaseForceLoader()
{

}

// force status

mvForceStatus::mvForceStatus()
{
   onlyLocalForce = false;
   onlyGlobalForce = false;
   applyingNone();
}

void mvForceStatus::applyingAll()
{
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

