#ifndef RAGDOLLCONTROLLER_H_INCLUDED
#define RAGDOLLCONTROLLER_H_INCLUDED

#include "PhysicsModule.h"
#include "DebugPhysicsModel.h"
#include <mv/mvMotionAI.h>
#include <lf/Lightfeather.h>
#include <Newton.h>

class RagdollBoneController : public scene::CSceneNodeController
{
   public:
      int bonephysicsID;
      mvIndex aiBodyID;
      NewtonRagDollBone* bonePtr;
      NewtonCollision* bonePhysicsCollision;
      DebugPhysicsModel* debugModel;
      PhysicsModule* pModule;

      RagdollBoneController(scene::CSceneNode* node);
      ~RagdollBoneController();

      virtual void move(u32 frameTime, u32 frameTimeDiff);
};

#define RAGDOLL_ROOT_NODE_ID (-1)

class RagdollController
{
   public:
      NewtonRagDoll* dollPhysics;
      PhysicsModule* pModule;
      int noOfBones;
      int aiGroupID;

      RagdollController(PhysicsModule* currentPhysics);
      void beginConstruction();
      RagdollBoneController* addBone(scene::CSceneNode* node,
         int parentNodeIndex, mvOptionEnum collisionType,
            const core::vector3df& relativePos, float mass, float length);
      void endConstruction();
      ~RagdollController();
};

#endif // RAGDOLLCONTROLLER_H_INCLUDED
