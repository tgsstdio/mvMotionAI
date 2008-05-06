#include "PhysicsModule.h"
#include "PhysicsController.h"

PhysicsModule::PhysicsModule()
   : isFirstTime(true),
   updateInterval(0),
   lastAnimatedTime(0),
   g_newtonmap(NULL),
   g_newtonmapbody(NULL),
   aiWorldIndex(MV_NULL),
   m_physicsPointer(NULL),
   m_physicsTerrainMesh(NULL)
{

   pWorldPtr = NewtonCreate(NULL, NULL);
	int i = NewtonMaterialGetDefaultGroupID(pWorldPtr);
	NewtonMaterialSetDefaultFriction   (pWorldPtr, i, i, 0.8f, 0.4f);
	NewtonMaterialSetDefaultElasticity (pWorldPtr, i, i, 0.2f);
	NewtonMaterialSetDefaultSoftness   (pWorldPtr, i, i, 0.05f);
	NewtonMaterialSetCollisionCallback (pWorldPtr, i, i, NULL, NULL, NULL, NULL);

   aiWorldIndex = mvCreateWorld();
   if (mvCreateForce(aiWorldIndex, MV_GRAVITY) == MV_NULL)
   {
      std::cout << "FORCE ERROR" << std::endl;
   }

   m_physicsPointer = PF->CreatePhysics();
   m_physicsPointer->Init(0,0,0);
}

PhysicsModule::~PhysicsModule()
{
   if (g_newtonmapbody)
   {
      NewtonDestroyBody(pWorldPtr,g_newtonmapbody);
   }

   if (pWorldPtr)
   {
      NewtonDestroy(pWorldPtr);
   }

   PF->Cleanup();
}

void PhysicsModule::setUpdateInterval(u32 uInterval)
{
   updateInterval = uInterval;
}

void PhysicsModule::move(u32 frameTime, u32 frameTimeDiff)
{
   if (isFirstTime)
   {
      lastAnimatedTime = frameTime;
      isFirstTime = false;
   }

   u32 timeDiff = frameTime - lastAnimatedTime;
	f32 timeInSecs = ((f32) timeDiff)/1000.0f;

	if (timeDiff > 0 && timeDiff > updateInterval)
	{
      mvWorldStep(aiWorldIndex, timeInSecs);
      //NewtonUpdate(pWorldPtr, timeInSecs);

      m_physicsPointer->Update(timeInSecs);
      lastAnimatedTime = frameTime;
	}

}

NewtonWorld* PhysicsModule::getNewtonWorld()
{
   return pWorldPtr;
}

mvIndex PhysicsModule::getWorldIndex() const
{
   return aiWorldIndex;
}


/**
 *  \brief build Newton World Mesh Collision from Lightfeather CModel file.
 *
 *  //////////////////////////////////////////////////////////////////////////
 *  //
 *  // Create the newton collision tree from the map mesh
 *  //
 *  // Remember to use (video::S3DVertex) if you are loading a mesh without lightmaps
 *  // for your level. (Like a .x or .3ds level)
 *  //
 *  //////////////////////////////////////////////////////////////////////////
 */
bool PhysicsModule::buildCollisionMapFromMesh(lf::res::CModel* currentModel,
   bool optimizeTree)
{

   int v1i, v2i, v3i;
   //IMeshBuffer *mb;
   res::CMesh *currentMesh = NULL;
   res::CVertexBuffer* vertices;
   res::CIndexBuffer* indexes;
   const lf::core::vector3df *first, *second, *third;
   float vArray[9]; // vertex array (3*3 floats)
   int indexCount = 0;

   if (currentModel == NULL)
   {
      return false;
   }

   int meshCount = (int) currentModel->getMeshCount();
   std::cout << "Mesh count : " << meshCount << std::endl;

   g_newtonmap = NewtonCreateTreeCollision(pWorldPtr, NULL);
   NewtonTreeCollisionBeginBuild(g_newtonmap);

   for (int meshIndex =0; meshIndex < meshCount; meshIndex++)
   {
      currentMesh = currentModel->getMesh(meshIndex);
      vertices = currentMesh->getVertexBuffer();
      indexes = currentMesh->getIndexBuffer();

      // add each triangle from the mesh
      indexCount = (int) indexes->getIndexCount();
      std::cout << "Index count : " << indexCount << std::endl;

      for (int j = 0; j< indexCount; j+=3)
      {
         v1i = indexes->getIndex32Safe(j);
         v2i = indexes->getIndex32Safe(j+1);
         v3i = indexes->getIndex32Safe(j+2);

         first = vertices->getPositionPointer(v1i);
         vArray[0] = first->X;
         vArray[1] = first->Y;
         vArray[2] = first->Z;

         second = vertices->getPositionPointer(v2i);
         vArray[3] = second->X;
         vArray[4] = second->Y;
         vArray[5] = second->Z;

         third = vertices->getPositionPointer(v3i);
         vArray[6] = third->X;
         vArray[7] = third->Y;
         vArray[8] = third->Z;

         // TODO : find out material types
         NewtonTreeCollisionAddFace(g_newtonmap, 3,
            &vArray[0], sizeof(float) * 3, 0);
      }

   }

   NewtonTreeCollisionEndBuild(g_newtonmap, (optimizeTree) ? 1 : 0);
   g_newtonmapbody = NewtonCreateBody(pWorldPtr, g_newtonmap);

   // set the newton world size based on the bsp size
   float boxP0[3];
   float boxP1[3];
   float matrix[4][4];
   NewtonBodyGetMatrix (g_newtonmapbody, &matrix[0][0]);
   NewtonCollisionCalculateAABB (g_newtonmap, &matrix[0][0],  &boxP0[0], &boxP1[0]);
   NewtonSetWorldSize (pWorldPtr, (float*)boxP0, (float*)boxP1);

   /*
    * newton collision objects are referenced pointed
    * i.e the newtonworld instance will handle the deletion of the collision
    * map
    */
   NewtonReleaseCollision(pWorldPtr, g_newtonmap);

   return true;
}

palPhysics* PhysicsModule::getPhysicsModule()
{
   return m_physicsPointer;
}

bool PhysicsModule::buildTerrainMeshFromMesh(lf::res::CModel* currentModel)
{
   if (currentModel == NULL || m_physicsPointer == NULL)
   {
      return false;
   }

   return true;
}

palSphere* PhysicsModule::createSphere(Float x,	Float	y,	Float	z,	Float	radius,\
   Float mass)
{
   palSphere* temp = NULL;

   if (m_physicsPointer == NULL)
   {
      return NULL;
   }

   temp = PF->CreateSphere();

   if (temp != NULL)
   {
      temp->Init(x,y,z,radius,mass);
   }

   //TODO : mvmotionai linking

   return temp;
}

palCylinder* PhysicsModule::createCappedCylinder(Float x, Float y, Float z, Float radius,
   Float	length, Float mass)
{
   palCylinder* temp = NULL;

   if (m_physicsPointer == NULL)
   {
      return NULL;
   }

   temp = PF->CreateCylinder();

   if (temp != NULL)
   {
      temp->Init(x,y,z,radius,length,mass);
   }

   //TODO : mvmotionai linking

   return temp;
}

palBox* PhysicsModule::createBox(Float x, Float y, Float z, Float width, Float height,\
   Float depth, Float mass)
{
   palBox* temp = NULL;

   if (m_physicsPointer == NULL)
   {
      return NULL;
   }

   temp = PF->CreateBox();

   if (temp != NULL)
   {
      temp->Init(x,y,z,width,height,depth,mass);
   }

   //TODO : mvmotionai linking

   return temp;
}
