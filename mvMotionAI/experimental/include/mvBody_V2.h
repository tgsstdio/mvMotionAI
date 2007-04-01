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

      // TODO : new functions for retriving values

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

      // parameter functions
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

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

};

#endif // MVBODY_V2_H_INCLUDED
