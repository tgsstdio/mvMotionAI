/**
 * \brief mvBaseForce.cpp
 * Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include <mv/mvBaseForce.h>

/** \brief blah blah
 *
 */
mvBaseForce::mvBaseForce(mvOptionEnum type)
{
   fType = type;
   isForceEnabled = true;
   userData = MV_NULL;
}

/** \brief blah blah
 *
 */
mvOptionEnum mvBaseForce::getType() const
{
   return fType;
}

/** \brief blah blah
 *
 */
bool mvBaseForce::isEnabled() const
{
   return isForceEnabled;
}

/** \brief blah blah
 *
 */
void mvBaseForce::setEnabled(bool value)
{
   isForceEnabled = value;
}

/** \brief blah blah
 *
 */
void mvBaseForce::filter(mvForceStatus& worldStatus)
{
   worldStatus.applyingAll();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::getParametero(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::getParameterf(mvParamEnum paramFlag, mvFloat* dest)\
   const
{
   if (dest == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

/** \brief blah blah
 *
 */
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::setParametero(mvParamEnum paramFlag,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_FORCE_PARAMETER;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_FORCE_PARAMETER;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseForce::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_FORCE_PARAMETER;
}

/** \brief blah blah
 *
 */
mvBaseForce::~mvBaseForce()
{

}

/** \brief blah blah
 *
 */
void* mvBaseForce::getUserData() const
{
   return userData;
}

/** \brief blah blah
 *
 */
void mvBaseForce::setUserData(void* tempData)
{
   userData = tempData;
}

// force loader
/** \brief blah blah
 *
 */
mvBaseForceLoader::mvBaseForceLoader()
{

}

/** \brief blah blah
 *
 */
mvBaseForceLoader::~mvBaseForceLoader()
{

}

// force status
/** \brief blah blah
 *
 */
mvForceStatus::mvForceStatus()
{
   onlyLocalForce = false;
   onlyGlobalForce = false;
   applyingNone();
}

/** \brief blah blah
 *
 */
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

/** \brief blah blah
 *
 */
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

/** \brief blah blah
 *
 */
void mvForceStatus::applyingLinearMotionOnly()
{
   forcesOn = true;
   gravityOn = true;
   accelerationOn = true;
   shiftsOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingAngularMotionOnly()
{
   torqueOn = true;
   omegaOn = true;
   rotationOn = true;
   quaternionOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::forLocalForceOnly()
{
   onlyLocalForce = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::forGlobalForceOnly()
{
   onlyGlobalForce = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingGravity()
{
   gravityOn = false;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingAcceleration()
{
   accelerationOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingShifts()
{
   shiftsOn = false;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingFullDrag()
{
   dragForceOn = true;
   dragAccelerationOn = true;
   dragShiftOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingDragForce()
{
   dragForceOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingDragAcceleration()
{
   dragAccelerationOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingDragShift()
{
   dragShiftOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingForce()
{
   forcesOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingTorque()
{
   torqueOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingOmega()
{
   omegaOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingRotation()
{
   rotationOn = true;
}

/** \brief blah blah
 *
 */
void mvForceStatus::applyingQuaternion()
{
   quaternionOn = true;
}

