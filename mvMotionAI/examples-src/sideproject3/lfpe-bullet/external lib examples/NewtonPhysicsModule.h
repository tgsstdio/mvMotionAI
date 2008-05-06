#ifndef PHYSICSMODULE_H_INCLUDED
#define PHYSICSMODULE_H_INCLUDED

#include <cstdlib>
#include <Newton.h>
#include <mv/mvMotionAI.h>
#include <lf/Lightfeather.h>

#include <palFactory.h>

using namespace lf;

class PhysicsModule
{
   public:
      PhysicsModule();
      ~PhysicsModule();
      bool buildCollisionMapFromMesh(lf::res::CModel* currentModel,
         bool optimizeTree = false);

      NewtonWorld* getNewtonWorld();
      mvIndex  getWorldIndex() const;

      // lf scene graph - variables
      void setUpdateInterval(u32 updateInterval);
      void move(u32 frameTime, u32 frameTimeDiff);

      palPhysics* getPhysicsModule();
      bool buildTerrainMeshFromMesh(lf::res::CModel* currentModel);
      palSphere* createSphere(Float x,	Float	y,	Float	z,	Float	radius,\
         Float mass);
      palCylinder* createCappedCylinder(Float x, Float y, Float z, Float radius,
         Float	length, Float mass);
      palBox* createBox(Float x, Float y, Float z, Float width, Float height,\
         Float depth, Float mass);

   private:
      NewtonWorld* pWorldPtr;
      bool isFirstTime;
		u32 updateInterval;
		u32 lastAnimatedTime;//last time this controller was updated
      mvIndex aiWorldIndex;

      NewtonCollision* g_newtonmap;
      NewtonBody* g_newtonmapbody;

      palPhysics *m_physicsPointer;
      palTerrainMesh* m_physicsTerrainMesh;
};

#endif // PHYSICSMODULE_H_INCLUDED
