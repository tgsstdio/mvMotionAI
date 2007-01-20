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

// TODO : world function implementation

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
      worldPtr->applyToAllPathhwaysByIndex(worldIndex, someFunction, extraPtr);
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
