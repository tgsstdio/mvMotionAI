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
 */

#ifndef MVBODY_V2_H_INCLUDED
#define MVBODY_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_SHAPE_HEADER_FILE_H_

//TODO : rotation
//TODO: behaviour list
//TODO: max force
//TODO: up vector
//TODO: confusion between direction/rotation/orientation

class mvBody_V2
{
   private:
      // position in 3D world
      mvVec3 bodyPosition;
      // mass
      mvFloat bodyMass;
      // body's own velocity after (incl.) mvForces
      mvVec3 finalVelocity;

      // TODO : torque/force/omega/rotation functions
      mvVec3 finalForceVector;
      mvVec3 bodysForceVector;
      mvVec3 finalTorque;
      mvVec3 bodysTorque;
      mvVec3 finalOmega;
      mvVec3 bodysOmega;
      mvVec3 bodysRotation;

      // direction of object local to motion
      mvVec3 faceDirection;

      // body's total potential acceleration
      mvFloat bodyAccel;
      // body's total potential deacceleration (braking)
      mvFloat bodyDeaccel;

      // body's maximum speed possible in system
      mvFloat bodyMaxSpeed;
      // body's own velocity excluding (before) mvForces
      //mvFloat bodyCurrentSpeed;
      // body's own unit velocity excluding (before) mvForces
      mvVec3 bodyVelocity;

      // mvBody rotation
      //mvVec3 eulerAngles;
      void* bodyUserDataPtr;

      // shape
      mvShape bodyShape;

      // type
      mvOptionEnum bodyType;

      //domain
      mvOptionEnum bodyDomain;
      mvFloat* bodyDomainVariables;

   public:
      mvOptionEnum getType() const;
      mvErrorEnum setType(mvOptionEnum bType);

      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      void setX(mvFloat x);
      void setY(mvFloat y);
      void setZ(mvFloat z);

      const mvVec3& getPosition() const;
      mvErrorEnum setPosition(mvFloat x, mvFloat y, mvFloat z);
      void setPosition(const mvVec3& pos);

      const mvVec3& getFaceDirection() const;
      mvErrorEnum setFaceDirection(mvFloat x, mvFloat y,mvFloat z);
      mvErrorEnum setFaceDirectionByVec3(const mvVec3& value);

      mvFloat getSpeed() const;
      mvErrorEnum setSpeed(mvFloat num);

      mvFloat getMaxSpeed() const;
      mvErrorEnum setMaxSpeed(mvFloat num);

      mvErrorEnum setMass(mvFloat num);
      mvFloat getMass() const;

      mvFloat getAcceleration() const;
      mvErrorEnum setAcceleration(mvFloat accel);

      mvFloat getDeceleration() const;
      mvErrorEnum setDeceleration(mvFloat dAccel);

      mvVec3 getBodyDirection() const;
      mvErrorEnum setBodyDirection(mvFloat fx, mvFloat fy, mvFloat fz);
      mvErrorEnum setBodyDirection(const mvVec3& value);

      mvVec3 getFinalDirection() const;
      mvErrorEnum setFinalDirection(mvFloat fx, mvFloat fy, mvFloat fz);
      mvErrorEnum setFinalDirection(const mvVec3& value);

      const mvVec3& getVelocity() const;
      mvErrorEnum setVelocity(mvFloat vx, mvFloat vy, mvFloat vz);
      mvErrorEnum setVelocity(const mvVec3& value);

      const mvVec3& getFinalVelocity() const;
      mvErrorEnum setFinalVelocity(mvFloat x, mvFloat y, mvFloat z);
      mvErrorEnum setFinalVelocity(const mvVec3& value);

      mvFloat getFinalSpeed() const;

      void* getUserData() const;
      void setUserData(void* usrData);

      mvConstShapePtr getShape() const;
      mvErrorEnum setShape(mvOptionEnum bShape);

      mvErrorEnum setDomain(mvOptionEnum bDomain);
      mvOptionEnum getDomain() const;
      mvCount getNoOfDomainVariables() const;
      const mvFloat* getDomainVariables() const;

      // parameter functions
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      bool enabled;
      bool applyForces;
      bool applyShifts;
      bool applyAccelerations;
      bool applyGravity;
      bool applyCollisions;
      bool applyAllForces;

      mvBody_V2(mvOptionEnum bType, mvOptionEnum shape, mvFloat x, mvFloat y,\
         mvFloat z);
      ~mvBody_V2();

      // TODO : functions here
      const mvVec3& getFinalForce() const;
      void setFinalForce(const mvVec3& vec);
      const mvVec3& getBodysForce() const;
      void setBodysForce(const mvVec3& vec);
      const mvVec3& getFinalTorque() const;
      void setFinalTorque(const mvVec3& vec);
      const mvVec3& getBodysTorque() const;
      void setBodyTorque(const mvVec3& vec);
      const mvVec3& getFinalOmega() const;
      void setFinalOmega(const mvVec3& vec);
      const mvVec3& getRotation() const;
      void setRotation(const mvVec3& vec);
      const mvVec3& getBodysOmega() const;
      void setBodysOmega(const mvVec3& vec);
};

#endif // MVBODY_V2_H_INCLUDED
