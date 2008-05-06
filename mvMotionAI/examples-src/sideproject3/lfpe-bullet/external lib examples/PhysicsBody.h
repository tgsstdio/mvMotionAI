#ifndef PHYSICSBODY_H_INCLUDED
#define PHYSICSBODY_H_INCLUDED

#include <cstdlib>
#include <Newton.h>
#include <mv/mvMotionAI.h>
#include <lf/Lightfeather.h>
#include "PhysicsModule.h"

class PhysicsBody
{
   public:
      static void setCubeParameters(lf::core::CProperties* settings);
      static void setCylinderParameters(lf::core::CProperties* settings);
      static void setSphereParameters(lf::core::CProperties* settings);

      static void getCubeParameters(lf::core::CProperties* settings);
      static void getCylinderParameters(lf::core::CProperties* settings);
      static void getSphereParameters(lf::core::CProperties* settings);

      static void setPositionParameters(lf::core::CProperties* settings);
      static void getPositionParameters(lf::core::CProperties* settings);

      static void setShapeParameters(lf::core::CProperties* settings);
      static void getShapeParameters(lf::core::CProperties* settings);

      static void setBodyParameters(lf::core::CProperties* settings);
      static void getBodyParameters(lf::core::CProperties* settings);

      enum PhysicsBodyParams
      {
         // pos
         POS_X,
         POS_Y,
         POS_Z,
         // mass
         MASS,
         IXX,
         IYY,
         IZZ,
         // vel
         VELX,
         VELY,
         VELZ,
         FINAL_VELX,
         FINAL_VELY,
         FINAL_VELZ,
         // omega
         OMEGA_X,
         OMEGA_Y,
         OMEGA_Z,
         FINAL_OMEGA_X,
         FINAL_OMEGA_Y,
         FINAL_OMEGA_Z,
         // torque
         TORQUE_X,
         TORQUE_Y,
         TORQUE_Z,
         FINAL_TORQUE_X,
         FINAL_TORQUE_Y,
         FINAL_TORQUE_Z,
         // rotation
         ROTATION_X,
         ROTATION_Y,
         ROTATION_Z,
         // body specific
         ACCEL,
         DECEL,
         MAX_SPEED,
         // obstacle specific
         STATE,
      };

      NewtonBody* bodyObject;
      NewtonCollision* collisionItem;
      mvIndex bodyIndex;

      PhysicsBody(PhysicsModule* pModule);
      void setBox(lf::core::CProperties* settings);
      void setSphere(lf::core::CProperties* settings);
      void setCylinder(lf::core::CProperties* settings);
      void loadParameters(lf::core::CProperties* output);
      void setParameters(lf::core::CProperties* output);
      ~PhysicsBody();
};

#endif // PHYSICSBODY_H_INCLUDED
