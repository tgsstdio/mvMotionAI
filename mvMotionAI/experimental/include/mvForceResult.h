#ifndef MVFORCERESULT_H_INCLUDED
#define MVFORCERESULT_H_INCLUDED

#include "mvMotionAI-Types.h"

class mvForceResult
{
   private:
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;

   public:

      mvForceResult();
      bool           isDragForceSet() const;
      const mvVec3&  getDragForce() const;

      bool           isForceSet() const;
      const mvVec3&  getForce() const;

      bool           isGravitySet() const;
      const mvVec3&  getGravity() const;

      bool           isDragAccelerationSet() const;
      const mvVec3&  getDragAcceleration() const;

      bool           isAccelerationSet() const;
      const mvVec3&  getAcceleration() const;

      bool           isShiftSet() const;
      const mvVec3&  getShift() const;

      bool           isDragShiftSet() const;
      const mvVec3&  getDragShift() const;

      bool           isTorqueSet() const;
      const mvVec3&  getTorque() const;

      bool           isOmegaSet() const;
      const mvVec3&  getOmega() const;
      bool           isOmegaInDegrees() const;

      bool           isQuaternionSet() const;
      const mvFloat* getQuaternion() const;

      // user utility functions
      mvFloat           getTimeStep() const;
      mvFloat           getElapsedSystemTime() const;

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

      void resetAll();
      mvConstWorldPtr getWorldPtr() const;
      mvConstBodyPtr getCurrentBodyPtr() const;

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
};

#endif // MVFORCERESULT_H_INCLUDED
