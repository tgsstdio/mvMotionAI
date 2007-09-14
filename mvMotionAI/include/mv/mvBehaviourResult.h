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
 *
 * Log
 *
 * version     comments
 * 00-01-39
 * - renamed mv behaviour result to mv result for future use
 */

#ifndef MVBEHAVIOURRESULT_H_INCLUDED
#define MVBEHAVIOURRESULT_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_
#define MV_QUATERNION_LENGTH 4

//typedef void* mvWorldPtr;

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvBehaviourResult
{
   public:

      mvBehaviourResult(mvConstWorldPtr worldPtr, mvConstBodyPtr bodyPtr);

      void     setBehaviourIndex(mvIndex bIndex);
      void     setGroupIndex(mvIndex gIndex);
      void     setElaspedSystemTime(mvFloat timeInSecs);
      void     setCurrentTimeStep(mvFloat timeInSecs);
      void     setPositionPrediction(const mvVec3& pos);
      void     setFinalPositionPrediction(const mvVec3& pos);
      void     setVelocityPrediction(const mvVec3& pos);
      void     setFinalVelocityPrediction(const mvVec3& pos);
      void     setGroupBehaviourNode(mvBaseActionPtr groupBehPtr);

      bool           isForceSet() const;
      const mvVec3&  getForce() const;
      mvMotionTypeEnum   getForceMotionType() const;
      mvEffectTypeEnum   getForceEffectType() const;
      bool           isAccelerationSet() const;
      const mvVec3&  getAcceleration() const;
      mvMotionTypeEnum   getAccelerationMotionType() const;
      mvEffectTypeEnum   getAccelerationEffectType() const;
      bool           isDirectionSet() const;
      const mvVec3&  getDirection() const;
      mvMotionTypeEnum   getDirectionMotionType() const;
      mvEffectTypeEnum   getDirectionEffectType() const;
      bool           isTorqueSet() const;
      const mvVec3&  getTorque() const;
      mvMotionTypeEnum   getTorqueMotionType() const;
      mvEffectTypeEnum   getTorqueEffectType() const;
      bool           isOmegaSet() const;
      const mvVec3&  getOmega() const;
      mvMotionTypeEnum   getOmegaMotionType() const;
      mvEffectTypeEnum   getOmegaEffectType() const;
      bool           isOmegaInDegrees() const;
      bool           isVelocitySet() const;
      const mvVec3&  getVelocity() const;
      mvMotionTypeEnum   getVelocityMotionType() const;
      mvEffectTypeEnum   getVelocityEffectType() const;
      bool           isQuaternionSet() const;
      const mvFloat* getQuaternion() const;
      mvMotionTypeEnum   getQuaternionMotionType() const;
      mvEffectTypeEnum   getQuaternionEffectType() const;

      bool           isRotationSet() const;
      const mvVec3&  getRotation() const;
      mvMotionTypeEnum   getRotationMotionType() const;
      mvEffectTypeEnum   getRotationEffectType() const;
      bool           isRotationInDegrees() const;

      // user utility functions
      mvBaseActionPtr   getGroupBehaviourNode() const;
      mvFloat           getTimeStep() const;
      mvFloat           getElapsedSystemTime() const;
      void              setToLocalEffect();
      void              setToGlobalEffect();
      bool              isGlobalEffectDefault() const;
      bool              isSteeringMotionDefault() const;

      // TODO: conversion functions
      /*
      mvVec3     convertForceToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToForce(const mvVec3& v) const;
      mvVec3     convertVelocityToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToVelocity(const mvVec3& v) const;
      mvVec3     convertLocalToGlobal(const mvVec3& v) const;
      mvVec3     convertGlobalToLocal(const mvVec3& v) const;
      */

      void setForce(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setAcceleration(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setVelocity(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setTorque(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setDirection(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setQuaternion(const mvFloat* quatArray,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setOmega(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setOmegaInDegrees(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setOmegaInRadians(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);

      void setRotationInDegrees(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);
      void setRotationInRadians(const mvVec3& value,\
         mvMotionTypeEnum mType = MV_DEFAULT_MOTION,\
         mvEffectTypeEnum eType = MV_DEFAULT_EFFECT);

      void setToDirectional();
      void setToSteering();
      void resetAll();
      mvConstWorldPtr getWorldPtr() const;
      mvConstBodyPtr getCurrentBodyPtr() const;
      mvIndex getBehaviourIndex() const;
      mvIndex getGroupIndex() const;
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

   private:
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;
      mvBaseActionPtr currentGroupBehNode;
      mvIndex behaviourIndex;
      mvIndex groupIndex;

      bool isDefaultMotionSteering;
      bool isDefaultEffectGlobal;

      mvMotionTypeEnum accelMotionType;
      mvMotionTypeEnum velocityMotionType;
      mvMotionTypeEnum directionMotionType;
      mvMotionTypeEnum forceMotionType;
      mvMotionTypeEnum torqueMotionType;
      mvMotionTypeEnum omegaMotionType;
      mvMotionTypeEnum rotationMotionType;
      mvMotionTypeEnum quaternionMotionType;

      mvEffectTypeEnum accelEffectType;
      mvEffectTypeEnum velocityEffectType;
      mvEffectTypeEnum directionEffectType;
      mvEffectTypeEnum forceEffectType;
      mvEffectTypeEnum torqueEffectType;
      mvEffectTypeEnum omegaEffectType;
      mvEffectTypeEnum rotationEffectType;
      mvEffectTypeEnum quaternionEffectType;

      bool applyAccel;
      bool applyVelocity;
      bool applyDirection;
      bool applyForce;
      bool applyTorque;
      // rotation change
      bool applyOmega;
      bool applyQuaternion;
      bool omegaInDegrees;
      bool rotationInDegrees;
      bool applyRotation;

      mvVec3 force;
      mvVec3 acceleration;
      mvVec3 velocity;
      mvVec3 direction;
      mvVec3 torque;
      mvVec3 omega;
      mvVec3 rotation;
      mvFloat quaternion[MV_QUATERNION_LENGTH];

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;

      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;
};


#endif // MVBEHAVIOURRESULT_H_INCLUDED
