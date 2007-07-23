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

#include "mvMotionAI-Types.h"
#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_
#define MV_QUATERNION_LENGTH 4

//typedef void* mvWorldPtr;

typedef class mvBehaviourResult
{
   public:
      enum mvMotionType
      {
         MV_DEFAULT_MOTION,
         MV_STEERING_MOTION,
         MV_DIRECTIONAL_MOTION
      };

      enum mvEffectType
      {
         MV_DEFAULT_EFFECT,
         MV_GLOBAL_EFFECT,
         MV_LOCAL_EFFECT
      };

      mvBehaviourResult(mvConstWorldPtr worldPtr, mvConstBodyPtr bodyPtr);

      // TODO: new internal setting
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
      mvMotionType   getForceMotionType() const;
      mvEffectType   getForceEffectType() const;
      bool           isAccelSet() const;
      const mvVec3&  getAccel() const;
      mvMotionType   getAccelMotionType() const;
      mvEffectType   getAccelEffectType() const;
      bool           isDirectionSet() const;
      const mvVec3&  getDirection() const;
      mvMotionType   getDirectionMotionType() const;
      mvEffectType   getDirectionEffectType() const;
      bool           isTorqueSet() const;
      const mvVec3&  getTorque() const;
      mvMotionType   getTorqueMotionType() const;
      mvEffectType   getTorqueEffectType() const;
      bool           isOmegaSet() const;
      const mvVec3&  getOmega() const;
      mvMotionType   getOmegaMotionType() const;
      mvEffectType   getOmegaEffectType() const;
      bool           isOmegaInDegrees() const;
      bool           isVelocitySet() const;
      const mvVec3&  getVelocity() const;
      mvMotionType   getVelocityMotionType() const;
      mvEffectType   getVelocityEffectType() const;
      bool           isQuaternionSet() const;
      const mvFloat* getQuaternion() const;
      mvMotionType   getQuaternionMotionType() const;
      mvEffectType   getQuaternionEffectType() const;

      bool           isRotationSet() const;
      const mvVec3&  getRotation() const;
      mvMotionType   getRotationMotionType() const;
      mvEffectType   getRotationEffectType() const;
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
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setAcceleration(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setVelocity(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setTorque(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setDirection(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setQuaternion(const mvFloat* quatArray,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setOmega(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setOmegaInDegrees(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setOmegaInRadians(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);

      void setRotationInDegrees(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);
      void setRotationInRadians(const mvVec3& value,\
         mvMotionType mType = MV_DEFAULT_MOTION,\
         mvEffectType eType = MV_DEFAULT_EFFECT);

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
      mvConstForcePtr fetchForcePtr(mvIndex index) const;
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

      mvMotionType accelMotionType;
      mvMotionType velocityMotionType;
      mvMotionType directionMotionType;
      mvMotionType forceMotionType;
      mvMotionType torqueMotionType;
      mvMotionType omegaMotionType;
      mvMotionType rotationMotionType;
      mvMotionType quaternionMotionType;

      mvEffectType accelEffectType;
      mvEffectType velocityEffectType;
      mvEffectType directionEffectType;
      mvEffectType forceEffectType;
      mvEffectType torqueEffectType;
      mvEffectType omegaEffectType;
      mvEffectType rotationEffectType;
      mvEffectType quaternionEffectType;

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

      // TODO : current time step
      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;
} mvResult;


#endif // MVBEHAVIOURRESULT_H_INCLUDED
