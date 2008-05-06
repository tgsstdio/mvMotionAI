#ifndef PHYSICSCONTROLLER_H_INCLUDED
#define PHYSICSCONTROLLER_H_INCLUDED

#include "PhysicsModule.h"
#include "DebugPhysicsModel.h"
#include <mv/mvMotionAI.h>
#include <lf/Lightfeather.h>
#include <Newton.h>

using namespace lf;

class PhysicsController : public scene::CSceneNodeController
{
   public:
      PhysicsController(scene::CSceneNode* node, PhysicsModule* phyModule,
         mvOptionEnum shapeEnum, bool isDebugging = true);

      // TODO : Generate physics Data from mvMotionAI instance
      PhysicsController(scene::CSceneNode* node, PhysicsModule* phyModule,
         mvIndex worldIndex, mvIndex bodyIndex);
      virtual void move(u32 frameTime, u32 frameTimeDiff);

      void setMass(float mass, float xx = 1, float yy = 1, float zz = 1);
      void setAABBDimensions(float aabbX, float aabbY, float aabbZ);
      void setRotation(float rX, float rY, float rZ);
      void setRadius(float length);
      ~PhysicsController();

      PhysicsModule* getPhysicsModule();
      mvIndex  getBodyIndex() const;

   private:
      enum PC_ShapeEnum{
         PC_BOX,
         PC_SPHERE,
         PC_CYLINDER
      };

      PC_ShapeEnum shapeFlag;
      void init(PhysicsModule* phyModule, PC_ShapeEnum shapeFlag,\
         lf::core::vector3df& initialPos, float dims1, float dims2,\
         float dims3, scene::CSceneNode* node, bool isDebugging);
      void updateNode();
      void updatePhysicsLayer();

      PhysicsModule* physicsUpdater;
      mvIndex bodyIndex;
      //NewtonWorld* pWorldPtr;
      NewtonBody* bodyObj;
      NewtonCollision* collisionObj;
      DebugPhysicsModel* debugModel;

      palBody* m_currentBody;

};

#endif // PHYSICSCONTROLLER_H_INCLUDED
