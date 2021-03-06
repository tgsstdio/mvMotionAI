/**
 * \file mvForceresult.h
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

#ifndef MVFORCERESULT_H_INCLUDED
#define MVFORCERESULT_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ROTATION_UNIT_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/** \class mvForceResult
 * \brief Class for storing results of operations of derived mvBaseForce classes
 */
class MV_GLOBAL_FUNC_PREFIX mvForceResult
{
   public:
      mvForceResult(mvConstWorldPtr world,
         mvConstBodyPtr body);
      bool           isDragForceSet() const;
      mvFloat        getDragForce() const;
      bool           isDragAccelerationSet() const;
      mvFloat        getDragAcceleration() const;
      bool           isGravitySet() const;
      const mvVec3&  getGravity() const;
      bool           isDragShiftSet() const;
      mvFloat        getDragShift() const;
      bool           isForceSet() const;
      const mvVec3&  getForce() const;
      bool           isAccelerationSet() const;
      const mvVec3&  getAcceleration() const;
      bool           isShiftSet() const;
      const mvVec3&  getShift() const;
      bool           isTorqueSet() const;
      const mvVec3&  getTorque() const;
      bool           isOmegaSet() const;
      const mvVec3&  getOmega() const;
      bool           isOmegaInDegrees() const;
      bool           isRotationSet() const;
      const mvVec3&  getRotation() const;
      bool           isRotationInDegrees() const;
      bool           isRotationUnitSet() const;
      const mvRotationUnit& getRotationUnit() const;
      bool           isDirectionSet() const;
      const mvVec3&  getDirection() const;

      void     setElaspedSystemTime(mvFloat timeInSecs);
      void     setCurrentTimeStep(mvFloat timeInSecs);
      void     setPositionPrediction(const mvVec3& pos);
      void     setFinalPositionPrediction(const mvVec3& pos);
      void     setVelocityPrediction(const mvVec3& pos);
      void     setFinalVelocityPrediction(const mvVec3& pos);

      mvMotionTypeEnum   getForceMotionType() const;
      mvEffectTypeEnum   getForceEffectType() const;
      mvMotionTypeEnum   getAccelerationMotionType() const;
      mvEffectTypeEnum   getAccelerationEffectType() const;
      mvMotionTypeEnum   getDirectionMotionType() const;
      mvEffectTypeEnum   getDirectionEffectType() const;
      mvMotionTypeEnum   getTorqueMotionType() const;
      mvEffectTypeEnum   getTorqueEffectType() const;
      mvMotionTypeEnum   getOmegaMotionType() const;
      mvEffectTypeEnum   getOmegaEffectType() const;
      mvMotionTypeEnum   getShiftMotionType() const;
      mvEffectTypeEnum   getShiftEffectType() const;
      mvMotionTypeEnum   getRotationUnitMotionType() const;
      mvEffectTypeEnum   getRotationUnitEffectType() const;
      mvMotionTypeEnum   getGravityMotionType() const;
      mvEffectTypeEnum   getGravityEffectType() const;
      mvMotionTypeEnum   getRotationMotionType() const;
      mvEffectTypeEnum   getRotationEffectType() const;


      // TODO: conversion functions
      /*
      mvVec3     convertForceToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToForce(const mvVec3& v) const;
      mvVec3     convertVelocityToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToVelocity(const mvVec3& v) const;
      mvVec3     convertLocalToGlobal(const mvVec3& v) const;
      mvVec3     convertGlobalToLocal(const mvVec3& v) const;
      */

      void setForce(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setAcceleration(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setGravity(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setShift(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setTorque(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setRotationUnit(const mvRotationUnit& quatArray,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setDirection(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setOmegaInDegrees(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setOmegaInRadians(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setRotationInDegrees(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setRotationInRadians(const mvVec3& value,
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);

      void setDragForce(mvFloat value);
      void setDragAcceleration(mvFloat value);
      void setDragShift(mvFloat value);

      void resetAll();
      mvConstWorldPtr getWorldPtr() const;
      mvConstBodyPtr getCurrentBodyPtr() const;

      // user utility functions
      mvFloat           getTimeStep() const;
      mvFloat           getElapsedSystemTime() const;
      mvConstWaypointPtr fetchWaypointPtr(mvIndex index) const;
      mvConstBodyPtr fetchBodyPtr(mvIndex index) const;
      mvConstGroupBehaviourPtr fetchGroupBehaviourPtr(mvIndex gbIndex) const;
      mvConstPathwayPtr fetchPathwayPtr(mvIndex index) const;
      mvConstGroupPtr fetchGroupPtr(mvIndex index) const;
      mvConstBaseForcePtr fetchForcePtr(mvIndex index) const;

      const mvVec3& predictPositionOfCurrentBody() const;
      const mvVec3& predictFinalPositionOfCurrentBody() const;
      const mvVec3& predictVelocityOfCurrentBody() const;
      const mvVec3& predictFinalVelocityOfCurrentBody() const;

      void  setToLocalEffect();
      void  setToGlobalEffect();
      void  setToDirectional();
      void  setToSteering();
      bool  isGlobalEffectDefault() const;
      bool  isSteeringMotionDefault() const;

      // integration loop
      void disableForce();
      void disableAccel();
      void disableShift();
      void disableGravity();
      void disableTorque();
      void disableOmega();
      void disableDirection();
      void disableRotationUnit();
      void disableRotation();
      void disableDragForce();
      void disableDragAccel();
      void disableDragShift();
   private:
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;

      bool applyForce;
      bool applyAccel;
      bool applyShift;
      bool applyGravity;
      bool applyTorque;
      bool applyOmega;
      bool applyDirection;
      bool applyRotationUnit;
      bool applyRotation;
      bool applyDragForce;
      bool applyDragAccel;
      bool applyDragShift;

      mvMotionTypeEnum forceMotion;
      mvMotionTypeEnum accelMotion;
      mvMotionTypeEnum shiftMotion;
      mvMotionTypeEnum gravityMotion;
      mvMotionTypeEnum torqueMotion;
      mvMotionTypeEnum omegaMotion;
      mvMotionTypeEnum directionMotion;
      mvMotionTypeEnum quaternionMotion;
      mvMotionTypeEnum rotationMotion;

      mvEffectTypeEnum forceEffect;
      mvEffectTypeEnum accelEffect;
      mvEffectTypeEnum shiftEffect;
      mvEffectTypeEnum gravityEffect;
      mvEffectTypeEnum torqueEffect;
      mvEffectTypeEnum omegaEffect;
      mvEffectTypeEnum directionEffect;
      mvEffectTypeEnum quaternionEffect;
      mvEffectTypeEnum rotationEffect;

      bool omegaInDegrees;
      bool rotationInDegrees;

      bool isDefaultMotionSteering;
      bool isDefaultEffectGlobal;

      mvVec3 force;
      mvVec3 gravity;
      mvVec3 acceleration;
      mvVec3 shiftVec;
      mvFloat dragForce;
      mvFloat dragAcceleration;
      mvFloat dragShift;
      mvVec3 torque;
      mvVec3 omega;
      mvVec3 rotation;
      mvVec3 direction;
      mvRotationUnit quaternion;

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;

      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;
};

#endif // MVFORCERESULT_H_INCLUDED
