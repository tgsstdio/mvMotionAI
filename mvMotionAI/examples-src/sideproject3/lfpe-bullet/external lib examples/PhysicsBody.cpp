#include "PhysicsBody.h"

      const char* PhysicsBodyParamsStrings[] =
      {
         // pos
         "POS_X",
         "POS_Y",
         "POS_Z",
         "MASS",
         // mass
         "IXX",
         "IYY",
         "IZZ",
         // vel
         "VELX",
         "VELY",
         "VELZ",
         "FINAL_VELX",
         "FINAL_VELY",
         "FINAL_VELZ",
         // omega
         "OMEGA_X",
         "OMEGA_Y",
         "OMEGA_Z",
         "FINAL_OMEGA_X",
         "FINAL_OMEGA_Y",
         "FINAL_OMEGA_Z",
         // torque
         "TORQUE_X",
         "TORQUE_Y",
         "TORQUE_Z",
         "FINAL_TORQUE_X",
         "FINAL_TORQUE_Y",
         "FINAL_TORQUE_Z",
         // rotation
         "ROTATION_X",
         "ROTATION_Y",
         "ROTATION_Z",
         // body specific
         "ACCEL",
         "DECEL",
         "MAX_SPEED",
         // obstacle specific
         "STATE",
      };

PhysicsBody::PhysicsBody(PhysicsModule* pModule)
{

}
/*
void PhysicsBody::setCubeParameters(lf::core::CProperties* settings);
void PhysicsBody::setCylinderParameters(lf::core::CProperties* settings);
void PhysicsBody::setSphereParameters(lf::core::CProperties* settings);

void PhysicsBody::getCubeParameters(lf::core::CProperties* settings);
void PhysicsBody::getCylinderParameters(lf::core::CProperties* settings);
void PhysicsBody::getSphereParameters(lf::core::CProperties* settings);

void PhysicsBody::setBodyParameters(lf::core::CProperties* settings)
{

}

void PhysicsBody::getBodyParameters(lf::core::CProperties* settings)
{

}

void PhysicsBody::setBox(lf::core::CProperties* settings)
{

   f32 posX = 0;
   f32 posY = 0;
   f32 posZ = 0;
   f32 mass = 1;
   f32 mass_ixx = 1;
   f32 mass_ixx = 1;
   f32 mass_ixx = 1;

   if (settings)
   {
      posX = settings->getProperty("POSX",posX);
      posY = settings->getProperty("POSY",posY);
      posZ = settings->getProperty("POSZ",posZ);

      mass = settings->getProperty("MASS",posZ);
   }

}

void PhysicsBody::setSphere(lf::core::CProperties* settings)
{

}

void PhysicsBody::setCylinder(lf::core::CProperties* settings)
{

}

void PhysicsBody::loadParameters(lf::core::CProperties* output)
{

}

void PhysicsBody::setParameters(lf::core::CProperties* output)
{

}
*/
PhysicsBody::~PhysicsBody()
{

}
