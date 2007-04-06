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


//TODO : Implement these functions
//TODO : rotation
//TODO: behaviour list
//TODO: max force
//TODO: up vector
//TODO: shape in parameters
//TODO: confusion between direction/rotation/orientation
//TODO: domain

class mvBody_V2
{
   private:
      // position in 3D world
      mvVec3 bodyPosition;
      // mass
      mvFloat bodyMass;
      // body's own velocity after (incl.) mvForces
      mvVec3 finalVelocity;

      // direction of object local to motion
      mvVec3 faceDirection;

      // body's total potential acceleration
      mvFloat bodyAccel;
      // body's total potential deacceleration (braking)
      mvFloat bodyDeaccel;

      // body's maximum speed possible in system
      mvFloat bodyMaxSpeed;
      // body's own velocity excluding (before) mvForces
      mvFloat bodyCurrentSpeed;
      // body's own unit velocity excluding (before) mvForces
      mvVec3 bodyDirection;
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
      const mvVec3& getPosition() const;
      void setPosition(mvFloat x, mvFloat y, mvFloat z);

      const mvVec3& getFaceDirection() const;
      void setFaceDirection(mvFloat x, mvFloat y,mvFloat z);

      mvFloat getSpeed() const;
      void setSpeed(mvFloat num);

      mvFloat getMaxSpeed() const;
      void setMaxSpeed(mvFloat num);

      void setMass(mvFloat num);
      mvFloat getMass() const;

      mvFloat getAcceleration() const;
      void setAcceleration(mvFloat accel);

      mvFloat getDeacceleration() const;
      void setDeacceleration(mvFloat dAccel);

      const mvVec3& getFinalDirection() const;
      void setFinalDirection(mvVec3& value);

      const mvVec3& getFinalVelocity() const;
      void setFinalVelocity(mvVec3& value);

      mvVec3 getVelocity() const;
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
      //TODO : implement destructor
      ~mvBody_V2();

};

#endif // MVBODY_V2_H_INCLUDED
