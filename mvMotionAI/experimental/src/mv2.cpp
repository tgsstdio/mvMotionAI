#include "mv2.h"

#include "mvMotionAI_V2-Central.h"
/**
 * \brief initialises the mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX void mvInitMotionAI()
{
   mvMotionAI_V2_INIT();
}

/**
 * \brief frees the mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX void mvFreeMotionAI()
{
   mvMotionAI_V2_FREE();
}

/**
 * \brief iterates all worlds in mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAllWorldsStepForward(mvFloat timeInSecs)
{
   return mvMotionAI_V2_ALLWORLDSSTEPFORWARD(timeInSecs);
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(const char* id)
{
   return mvMotionAI_V2_CREATEWORLD(id);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWorlds()
{
   return mvMotionAI_V2_DELETEALLWORLDS();
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetWorldByID(const char* id)
{
   return mvMotionAI_V2_GETWORLDBYID(id);
}

MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtrByID(const char* id)
{
   return mvMotionAI_V2_GETWORLDPTRBYID(id);
}

MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtr(mvIndex index)
{
   return mvMotionAI_V2_GETWORLDPTR(index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorld_V2*,void*),void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDS(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDSBYINDEX(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultBehaviours()
{
   return mvMotionAI_V2_LOADDEFAULTBEHAVIOURS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseBehaviourLoader* loader)
{
   return mvMotionAI_V2_ADDBEHAVIOURFUNC(bType, loader);
}

MV_GLOBAL_FUNC_PREFIX mvBaseBehaviour* mvCreateNewBehaviour(mvOptionEnum type,\
   mvBaseBehaviour* defaultBehaviour)
{
   return mvMotionAI_V2_CREATENEWBEHAVIOUR(type, defaultBehaviour);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->worldStep(timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->nudgeBody(bodyIndex,timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeCurrentBody(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->nudgeCurrentBody(timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum* option)
{
   return mvMotionAI_V2_GETWORLDPARAMETER(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex* index)
{
   return mvMotionAI_V2_GETWORLDPARAMETERI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* num)
{
   return mvMotionAI_V2_GETWORLDPARAMETERF(worldIndex, param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* array, mvCount* noOfParameters)
{
   return mvMotionAI_V2_GETWORLDPARAMETERV(worldIndex, param, array,\
      noOfParameters);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameters(mvIndex worldIndex,\
	const char* param, const char** option)
{
   return mvMotionAI_V2_GETWORLDPARAMETERS(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersi(mvIndex worldIndex,\
	const char* param, mvIndex* index)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersf(mvIndex worldIndex,\
	const char* param, mvFloat* num)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSF(worldIndex, param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersv(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSV(worldIndex, param, array,\
      noOfParameters);
}

//SET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum option)
{
   return mvMotionAI_V2_SETWORLDPARAMETER(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex index)
{
   return mvMotionAI_V2_SETWORLDPARAMETERI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat num)
{
   return mvMotionAI_V2_SETWORLDPARAMETERF(worldIndex,param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array)
{
   return mvMotionAI_V2_SETWORLDPARAMETERV(worldIndex, param, array);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameters(mvIndex worldIndex,\
   const char* param, const char* option)
{
   return mvMotionAI_V2_SETWORLDPARAMETERS(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersi(mvIndex worldIndex,\
   const char* param, mvIndex index)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat num)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSF(worldIndex, param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* array)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSV(worldIndex, param, array);
}

// C pointer foreach functions

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBody*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBodies(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstacle*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllObstacles(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypoint*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllWaypoints(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathway*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllPathways(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroup*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroups(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviour*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBehaviours(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviour*,void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroupBehaviours(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvForce*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllForces(someFunction, extraPtr);
   }

   return error;
}

// mvIndex C interface foreach

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBodiesByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstaclesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllObstaclesByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypointsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllWaypointsByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathwaysByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllPathwaysByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroupsByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBehavioursByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroupBehavioursByIndex(worldIndex, someFunction,\
         extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex, void*), void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllForcesByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}
// TODO : implement theses functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createBody(bType, bShape, x, y, z);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvBody* mvGetBodyPtr(mvIndex worldIndex,\
   mvIndex bodyIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getBodyPtr(bodyIndex);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBody(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentBody();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvBody* mvGetCurrentBodyPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentBodyPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBody(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentBody(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentBody(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentBody();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBody(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteBody(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBodies(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllBodies();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBodyParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBodyParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex)
{
   // TODO : function later implementation
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   //mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return MV_FUNCTION_NOT_IMPLEMENTED;
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToCurrentBody(\
   mvIndex worldIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex)
{
   // TODO : function later implementation
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
  // mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return MV_FUNCTION_NOT_IMPLEMENTED;
   }
   return error;
}

// TODO : obstacle functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle(mvIndex worldIndex,\
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createObstacle(oShape, oState, x, y, z);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvObstacle* mvGetObstaclePtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getObstaclePtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentObstacle(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentObstacle();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvObstacle* mvGetCurrentObstaclePtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentObstaclePtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentObstacle(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentObstacle(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentObstacle(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentObstacle();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteObstacle(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteObstacle(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllObstacles(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllObstacles();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentObstacleParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentObstacleParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex)
{
   // TODO : function later implementation
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
  // mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return MV_FUNCTION_NOT_IMPLEMENTED;
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleAsWorldBoundary(\
   mvIndex worldIndex)
{
   // TODO : function later implementation
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
  // mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return MV_FUNCTION_NOT_IMPLEMENTED;
   }
   return error;
}

// TODO : waypoint functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
	 mvOptionEnum wType, mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createWaypoint(wType, wShape, x, y, z);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvWaypoint* mvGetWaypointPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getWaypointPtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWaypoint(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentWaypoint();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvWaypoint* mvGetCurrentWaypointPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentWaypointPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWaypoint(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentWaypoint(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentWaypoint(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentWaypoint();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteWaypoint(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteWaypoint(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWaypoints(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllWaypoints();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentWaypointParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentWaypointParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

// TODO : mvBehaviour function
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
	 mvOptionEnum bType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createBehaviour(bType);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvBehaviour* mvGetBehaviourPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getBehaviourPtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentBehaviour();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvBehaviour* mvGetCurrentBehaviourPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentBehaviourPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentBehaviour(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentBehaviour();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteBehaviour(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBehaviours(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllBehaviours();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentBehaviourParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentBehaviourParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

// TODO : mvForce functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createForce(fType);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvForce* mvGetForcePtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getForcePtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentForce();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvForce* mvGetCurrentForcePtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentForcePtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentForce(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentForce(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentForce(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentForce();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteForce(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteForce(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllForces(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllForces();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentForceParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentForceParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

// TODO : pathway functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createPathway();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvPathway* mvGetPathwayPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getPathwayPtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentPathway(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentPathway();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvPathway* mvGetCurrentPathwayPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentPathwayPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentPathway(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentPathway(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentPathway(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentPathway();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeletePathway(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deletePathway(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllPathways(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllPathways();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentPathwayParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentPathwayParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

//TODO : group functions
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex,\
   const char* groupName)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createGroup(groupName);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvGroup* mvGetGroupPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getGroupPtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroup(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentGroup();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvGroup* mvGetCurrentGroupPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentGroupPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroup(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentGroup(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentGroup(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentGroup();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroup(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteGroup(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroups(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllGroups();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParameteri(paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParameterv(paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParametersi(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParametersv(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParametersi(param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameters(\
   mvIndex worldIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setCurrentGroupParametersv(param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameter(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParameteri(paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameter(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParameter(paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParameterf(paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParameterv(paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParametersi(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameters(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParametersf(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParametersv(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParametersi(param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameters(\
   mvIndex worldIndex,const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParameters(param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParametersf(param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentGroupParametersv(param, array,\
         noOfParameters);
   }
   return error;
}

// TODO : GROUP BEHAVIOUR FUNCTIONS
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour(mvIndex worldIndex,\
	 mvOptionEnum gbType);
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->createGroupBehaviour(gbType);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvGroupBehaviour* mvGetGroupBehaviourPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getGroupBehaviourPtr(index);
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroupBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->getCurrentGroupBehaviour();
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvGroupBehaviour* mvGetCurrentGroupBehaviourPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return NULL;
      return worldPtr->getCurrentGroupBehaviourPtr();
   }
   return NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_NO_CURRENT_INDEX;
      return worldPtr->setCurrentGroupBehaviour(index);
   }
   return MV_NO_CURRENT_INDEX;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentGroupBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteCurrentGroupBehaviour();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroupBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteGroupBehaviour(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroupBehaviours(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllGroupBehaviours();
   }
   return error;
}

// TODO : more functions

