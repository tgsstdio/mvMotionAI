/**
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
 */
#ifndef MVBASEFORCE_H_INCLUDED
#define MVBASEFORCE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_FORCE_RESULT_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvForceStatus
{
   public:
      bool onlyLocalForce;
      bool onlyGlobalForce;
      bool forcesOn;
      bool gravityOn;
      bool accelerationOn;
      bool shiftsOn;
      bool dragForceOn;
      bool dragAccelerationOn;
      bool dragShiftOn;
      bool torqueOn;
      bool omegaOn;
      bool rotationOn;
      bool quaternionOn;

      mvForceStatus();
      void applyingAll();
      void applyingNone();
      void applyingLinearMotionOnly();
      void applyingAngularMotionOnly();

      void forLocalForceOnly();
      void forGlobalForceOnly();
      void applyingGravity();
      void applyingAcceleration();
      void applyingShifts();
      void applyingFullDrag();
      void applyingDragForce();
      void applyingDragAcceleration();
      void applyingDragShift();
      void applyingForce();
      void applyingTorque();
      void applyingOmega();
      void applyingRotation();
      void applyingQuaternion();
};

class MV_GLOBAL_FUNC_PREFIX mvBaseForce
{
   private:
      mvOptionEnum fType;
      bool isForceEnabled;
      void* userData;
   public:
      mvBaseForce(mvOptionEnum type);
      mvOptionEnum getType() const;
      bool isEnabled() const;
      void setEnabled(bool value);
      void* getUserData() const;
      void setUserData(void* tempData);

      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult) = 0;
      virtual mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* index) const;
      virtual mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* dest) const;
      virtual mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* dest)\
         const;
      virtual mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* dest,\
         mvCount* size) const;

      virtual mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      virtual mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      virtual mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      virtual mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);
      virtual ~mvBaseForce();
};

class MV_GLOBAL_FUNC_PREFIX mvBaseForceLoader
{
   public:
      mvBaseForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr) = 0;
      virtual ~mvBaseForceLoader();
};

#endif // MVBASEFORCE_H_INCLUDED
