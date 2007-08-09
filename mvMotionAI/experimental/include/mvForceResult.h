#ifndef MVFORCERESULT_H_INCLUDED
#define MVFORCERESULT_H_INCLUDED

#include "mvMotionAI-Types.h"

#define MV_FORCE_QUATERNION_LENGTH (4)
#include MV_VEC_3_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_

class mvForceResult
{
   private:
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;

      bool applyForce;
      bool applyAccel;
      bool applyShift;
      bool applyGravity;
      bool applyDragForce;
      bool applyDragAccel;
      bool applyDragShift;
      // rotation change
      bool applyTorque;
      bool applyOmega;
      bool applyQuaternion;
      bool omegaInDegrees;
      bool rotationInDegrees;
      bool applyRotation;

      mvVec3 force;
      mvVec3 acceleration;
      mvVec3 shiftVec;
      mvVec3 dragForce;
      mvVec3 dragAcceleration;
      mvVec3 dragShift;
      mvVec3 torque;
      mvVec3 omega;
      mvVec3 rotation;
      mvFloat quaternion[MV_FORCE_QUATERNION_LENGTH];

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;

      // TODO : current time step
      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;

   public:

      mvForceResult(mvConstWorldPtr world,
         mvConstBodyPtr body);
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

      bool           isRotationSet() const;
      const mvVec3&  getRotation() const;
      bool           isRotationInDegrees() const;

      bool           isQuaternionSet() const;
      const mvFloat* getQuaternion() const;

      // user utility functions
      mvFloat           getTimeStep() const;
      mvFloat           getElapsedSystemTime() const;
      void     setElaspedSystemTime(mvFloat timeInSecs);
      void     setCurrentTimeStep(mvFloat timeInSecs);

      // TODO: conversion functions
      /*
      mvVec3     convertForceToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToForce(const mvVec3& v) const;
      mvVec3     convertVelocityToAccel(const mvVec3& v) const;
      mvVec3     convertAccelToVelocity(const mvVec3& v) const;
      mvVec3     convertLocalToGlobal(const mvVec3& v) const;
      mvVec3     convertGlobalToLocal(const mvVec3& v) const;
      */

      void setForce(const mvVec3& value);
      void setAcceleration(const mvVec3& value);
      void setGravity(const mvVec3& value);
      void setShift(const mvVec3& value);
      void setDragForce(const mvVec3& value);
      void setDragAcceleration(const mvVec3& value);
      void setDragShift(const mvVec3& value);

      void setTorque(const mvVec3& value);
      void setQuaternion(const mvFloat* quatArray);
      void setOmega(const mvVec3& value);
      void setOmegaInDegrees(const mvVec3& value);
      void setOmegaInRadians(const mvVec3& value);

      void setRotationInDegrees(const mvVec3& value);
      void setRotationInRadians(const mvVec3& value);

      void resetAll();
      mvConstWorldPtr getWorldPtr() const;
      mvConstBodyPtr getCurrentBodyPtr() const;

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
};

#endif // MVFORCERESULT_H_INCLUDED
