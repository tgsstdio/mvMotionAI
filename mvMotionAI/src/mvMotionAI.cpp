#include <mv/mvMotionAI.h>
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

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWorld(mvIndex index)
{
   return mvMotionAI_V2_SETCURRENTWORLD(index);
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWorld()
{
   return mvMotionAI_V2_GETCURRENTWORLD();
}

MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetCurrentWorldPtr()
{
   return mvMotionAI_V2_GETCURRENTWORLDPTR();
}

/**
 * \brief iterates all worlds in mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAllWorldsStepForward(mvFloat timeInSecs)
{
   return mvMotionAI_V2_ALLWORLDSSTEPFORWARD(timeInSecs);
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld()
{
   return mvMotionAI_V2_CREATEWORLD();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWorlds()
{
   return mvMotionAI_V2_DELETEALLWORLDS();
}

MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetWorldPtr(mvIndex index)
{
   return mvMotionAI_V2_GETWORLDPTR(index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorldPtr,void*),void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDS(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDSBYINDEX(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultBehaviours(mvActionLoaderListPtr loader)
{
   return mvMotionAI_V2_LOADDEFAULTBEHAVIOURS(loader);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultForces(mvForceLoaderListPtr loader)
{
   return mvMotionAI_V2_LOADDEFAULTFORCES(loader);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultActions()
{
   return mvMotionAI_V2_INITDEFAULTACTIONS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultForces()
{
   return mvMotionAI_V2_INITDEFAULTFORCES();
}

/* TODO : implementation later*/
/*
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultBodies()
{
   return mvMotionAI_V2_INITDEFAULTBODIES();
}
*/

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitAllDefaults()
{
   return mvMotionAI_V2_INITALLDEFAULTS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultActions()
{
   return mvMotionAI_V2_FREEDEFAULTACTIONS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultForces()
{
   return mvMotionAI_V2_FREEDEFAULTFORCES();
}

/*TODO : implementation later*/
/*
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultBodies()
{
   return mvMotionAI_V2_FREEDEFAULTBODIES();
}
*/

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeAllDefaults()
{
   return mvMotionAI_V2_FREEALLDEFAULTS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseActionLoaderPtr loader)
{
   return mvMotionAI_V2_ADDBEHAVIOURFUNC(bType, loader);
}

MV_GLOBAL_FUNC_PREFIX mvBaseActionPtr mvCreateNewBehaviourFromLoader(mvOptionEnum type,\
   mvBaseActionPtr defaultBehaviour)
{
   return mvMotionAI_V2_CREATENEWBEHAVIOUR(type);
}

MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvCreateNewForceFromLoader(mvOptionEnum type)
{
   return mvMotionAI_V2_CREATENEWFORCE(type);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->worldStep(timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->nudgeBody(bodyIndex,timeInSecs);
   }

   return error;
}
/*
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeCurrentBody(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->nudgeCurrentBody(timeInSecs);
   }

   return error;
}
*/

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametero(mvIndex worldIndex,\
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametero_str(mvIndex worldIndex,\
	const char* param, const char** option)
{
   return mvMotionAI_V2_GETWORLDPARAMETERS(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri_str(mvIndex worldIndex,\
	const char* param, mvIndex* index)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf_str(mvIndex worldIndex,\
	const char* param, mvFloat* num)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSF(worldIndex, param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv_str(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return mvMotionAI_V2_GETWORLDPARAMETERSV(worldIndex, param, array,\
      noOfParameters);
}

//SET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametero(mvIndex worldIndex,\
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametero_str(mvIndex worldIndex,\
   const char* param, const char* option)
{
   return mvMotionAI_V2_SETWORLDPARAMETERS(worldIndex, param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri_str(mvIndex worldIndex,\
   const char* param, mvIndex index)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSI(worldIndex, param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf_str(mvIndex worldIndex,\
   const char* param, mvFloat num)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSF(worldIndex, param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv_str(mvIndex worldIndex,\
   const char* param, mvFloat* array)
{
   return mvMotionAI_V2_SETWORLDPARAMETERSV(worldIndex, param, array);
}

// C pointer foreach functions

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBody*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBodies(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstacle*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllObstacles(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypoint*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllWaypoints(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathway*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllPathways(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroup*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroups(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviour_V2*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllBehaviours(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviourPtr,void*),\
   void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllGroupBehaviours(someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvBaseForcePtr,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllForcesByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createBody(bType, bShape, x, y, z);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetBodyPtr(mvIndex worldIndex,\
   mvIndex bodyIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getBodyPtr(bodyIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBody(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentBody();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetCurrentBodyPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentBodyPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBody(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentBody(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBody(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteBody(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBodies(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllBodies();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBodyParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBodyParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->addBehaviourToList(bodyIndex, bType, behaviourIndex,\
         groupIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList_str(mvIndex worldIndex,\
   mvIndex listIndex, const char* bType, mvIndex behaviourIndex,\
   mvIndex groupIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->addBehaviourToList_str(listIndex, bType,
         behaviourIndex, groupIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveBehaviourFromList(mvIndex worldIndex,\
   mvIndex listIndex, mvIndex entryIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->removeBehaviourFromList(listIndex, entryIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllBehavioursFromList(\
   mvIndex worldIndex, mvIndex listIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->removeAllBehavioursFromList(listIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentEntryFromList(mvIndex worldIndex,\
   mvIndex listIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getCurrentEntryFromList(listIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle(mvIndex worldIndex,\
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);

      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }
      return worldPtr->createObstacle(oShape, oState, x, y, z);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetObstaclePtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getObstaclePtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentObstacle(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentObstacle();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetCurrentObstaclePtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentObstaclePtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentObstacle(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentObstacle(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteObstacle(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteObstacle(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllObstacles(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllObstacles();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setObstacleParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getObstacleParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex)
{
   // TODO : function later implementation
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
  // mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
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
  // mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      return MV_FUNCTION_NOT_IMPLEMENTED;
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint_str(mvIndex worldIndex,\
   const char* wShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;

      return worldPtr->createWaypoint_str(wShape, x, y, z);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
	mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createWaypoint(wShape, x, y, z);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetWaypointPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getWaypointPtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWaypoint(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentWaypoint();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetCurrentWaypointPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentWaypointPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWaypoint(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentWaypoint(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteWaypoint(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteWaypoint(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWaypoints(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllWaypoints();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setWaypointParameterv_str(index, param, array);
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getWaypointParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
	 mvOptionEnum bType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createBehaviour(bType);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetBehaviourPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getBehaviourPtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentBehaviour();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetCurrentBehaviourPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentBehaviourPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentBehaviour(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteBehaviour(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBehaviours(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllBehaviours();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setBehaviourParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getBehaviourParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createForce(fType);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetForcePtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getForcePtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentForce();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetCurrentForcePtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentForcePtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentForce(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentForce(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteForce(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteForce(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllForces(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllForces();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setForceParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getForceParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createPathway();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetPathwayPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getPathwayPtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentPathway(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentPathway();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetCurrentPathwayPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentPathwayPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentPathway(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentPathway(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeletePathway(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deletePathway(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllPathways(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllPathways();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setPathwayParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getPathwayParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;

      return worldPtr->createGroup();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetGroupPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getGroupPtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroup(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentGroup();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetCurrentGroupPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentGroupPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroup(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentGroup(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroup(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteGroup(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroups(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllGroups();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameteri(index, paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterv(index, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameteri_str(index, param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupParameterv_str(index, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameteri(index, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametero(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParametero(index, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
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
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameterv(index, paramFlag, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameteri_str(index, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametero_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParametero_str(index, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameterf_str(index, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour(mvIndex worldIndex,\
   mvOptionEnum gbType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createGroupBehaviour(gbType);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetGroupBehaviourPtr(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getGroupBehaviourPtr(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroupBehaviour(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentGroupBehaviour();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetCurrentGroupBehaviourPtr(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->getCurrentGroupBehaviourPtr();
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->setCurrentGroupBehaviour(index);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroupBehaviour(mvIndex worldIndex,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->deleteGroupBehaviour(index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroupBehaviours(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->deleteAllGroupBehaviours();
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX const char* mvGetErrorEnumString(mvErrorEnum error)
{
   return mvGetErrorString(error);
}

MV_GLOBAL_FUNC_PREFIX const char* mvGetParamEnumString(mvParamEnum param)
{
   return mvGetParamString(param);
}

MV_GLOBAL_FUNC_PREFIX const char* mvGetOptionEnumString(mvOptionEnum option)
{
   return mvGetOptionString(option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameteri(gbIndex, groupIndex,\
         paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParametero(gbIndex, groupIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameterf(gbIndex, groupIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameterv(gbIndex, groupIndex,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameteri_str(gbIndex, groupIndex,\
         param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParametero_str(gbIndex, groupIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameterf_str(gbIndex, groupIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setGroupBehaviourParameterv_str(gbIndex, groupIndex,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameteri(gbIndex, groupIndex,\
         paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParametero(gbIndex, groupIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameterf(gbIndex, groupIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameterv(gbIndex, groupIndex,\
         paramFlag, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameteri_str(gbIndex, groupIndex,\
         param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParametero_str(gbIndex, groupIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameterf_str(gbIndex, groupIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getGroupBehaviourParameterv_str(gbIndex, groupIndex,\
         param, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddMemberIntoGroup(mvIndex worldIndex,\
   mvIndex groupIndex, mvIndex memberIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->addMemberIntoGroup(groupIndex,memberIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddGroupIntoGroupBehaviour(\
   mvIndex worldIndex,mvIndex gbIndex, mvIndex groupIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->addGroupIntoGroupBehaviour(gbIndex,groupIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveGroupFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->removeGroupFromGroupBehaviour(gbIndex, groupIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameteri(listIndex, nodeIndex,\
         paramFlag, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParametero(
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParametero(listIndex, nodeIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameterf(listIndex, nodeIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameterv(listIndex, nodeIndex,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameteri_str(listIndex, nodeIndex,\
         param, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParametero_str(listIndex, nodeIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameterf_str(listIndex, nodeIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListNodeParameterv_str(listIndex, nodeIndex,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameteri(listIndex, nodeIndex,\
         paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParametero(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParametero(listIndex, nodeIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameterf(listIndex, nodeIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameterv(listIndex, nodeIndex,\
         paramFlag, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameteri_str(listIndex, nodeIndex,\
         param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParametero_str(\
   mvIndex worldIndex, mvIndex listIndex,mvIndex nodeIndex, const char* param,
   const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParametero_str(listIndex, nodeIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameterf_str(listIndex, nodeIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListNodeParameterv_str(listIndex, nodeIndex,\
         param, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameteri(listIndex, paramFlag, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParametero(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParametero(listIndex, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameterf(listIndex, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameterv(listIndex, paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameteri_str(listIndex, param, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParametero_str(listIndex, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameterf_str(listIndex, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setEntryListParameterv_str(listIndex, param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameteri(listIndex, paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParametero(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParametero(listIndex, paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameterf(listIndex, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameterv(listIndex, paramFlag, array,
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameteri_str(listIndex, param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParametero_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param,\
   const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParametero_str(listIndex, param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameterf_str(listIndex, param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->getEntryListParameterv_str(listIndex, param, array,
         noOfParameters);
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllEntryLists(mvIndex worldIndex,\
   void (someFunction)(mvEntryListPtr, void*), void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      worldPtr->applyToAllEntryLists(someFunction, extraPtr);
      return MV_NO_ERROR;
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex, void* userData)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->setUserData(objectType,objectIndex,userData);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX void* mvGetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }
      return worldPtr->getUserData(objectType,objectIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddNodeToPathway(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->addNodeToPathway(pathwayIndex,nodeIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveNodeFromPathway(mvIndex worldIndex,\
   mvIndex pIndex, mvIndex nIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeNodeFromPathway(pIndex,nIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllNodesFromPathway(\
   mvIndex worldIndex, mvIndex pathwayIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeAllNodesFromPathway(pathwayIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentNodeOfPathway(mvIndex worldIndex,\
   mvIndex pwIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }
      return worldPtr->getCurrentNodeOfPathway(pwIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemovePathwayNodeAt(mvIndex worldIndex,\
   mvIndex pwIndex, mvIndex nodeIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removePathwayNodeAt(pwIndex,nodeIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameteri(\
   mvIndex worldIndex,mvIndex pathwayIndex,  mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameteri(pathwayIndex, nodeIndex,\
         paramFlag, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParametero(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParametero(pathwayIndex, nodeIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterf(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameterf(pathwayIndex, nodeIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterv(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameterv(pathwayIndex, nodeIndex,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameteri_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameteri_str(pathwayIndex, nodeIndex,\
         param, index);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParametero_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParametero_str(pathwayIndex, nodeIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterf_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameterf_str(pathwayIndex, nodeIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayNodeParameterv_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setPathwayNodeParameterv_str(pathwayIndex, nodeIndex,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameteri(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameteri(pathwayIndex, nodeIndex,\
         paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParametero(mvIndex worldIndex,\
   mvIndex pathwayIndex, mvIndex nodeIndex, mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParametero(pathwayIndex, nodeIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterf(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameterf(pathwayIndex, nodeIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterv(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameterv(pathwayIndex, nodeIndex,\
         paramFlag, array, noOfParameters);
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameteri_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameteri_str(pathwayIndex, nodeIndex,\
         param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParametero_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParametero_str(pathwayIndex, nodeIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterf_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameterf_str(pathwayIndex, nodeIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayNodeParameterv_str(\
   mvIndex worldIndex,mvIndex pathwayIndex, mvIndex nodeIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getPathwayNodeParameterv_str(pathwayIndex, nodeIndex,\
         param, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldUserData(mvIndex worldIndex,
   void* tempData)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      worldPtr->setWorldUserData(tempData);
      return MV_NO_ERROR;
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX void* mvGetWorldUserData(mvIndex worldIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }
      return worldPtr->getWorldUserData();
   }
   return MV_NULL;
}

// TODO : add waypoints to forces
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddForceIntoWaypoint(mvIndex worldIndex,\
   mvIndex wIndex, mvIndex fIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->addForceIntoWaypoint(wIndex, fIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveForceFromWaypoint(mvIndex worldIndex,\
   mvIndex wIndex, mvIndex fIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeForceFromWaypoint(wIndex, fIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllWaypointsFromForce(\
   mvIndex worldIndex, mvIndex forceIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeAllWaypointsFromForce(forceIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllForcesFromWaypoint(\
   mvIndex worldIndex, mvIndex waypointIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeAllForcesFromWaypoint(waypointIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody_str(mvIndex worldIndex,\
   const char* bType, const char* bShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }

      return worldPtr->createBody_str(bType, bShape, x,y,z);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle_str(mvIndex worldIndex,\
   const char* oShape, const char* oState, mvFloat x, mvFloat y, mvFloat z)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }

      return worldPtr->createObstacle_str(oShape, oShape, x,y,z);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour_str(mvIndex worldIndex,\
   const char* bType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }

      return worldPtr->createBehaviour_str(bType);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce_str(mvIndex worldIndex,\
   const char* fType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }

      return worldPtr->createForce_str(fType);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour_str(mvIndex worldIndex,\
	const char* gbType)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }

      return worldPtr->createGroupBehaviour_str(gbType);
   }
   else
   {
      return MV_NULL;
   }
}

// TODO : main group functiosn
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllGroupsFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex gbIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeAllGroupsFromGroupBehaviour(gbIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameteri(index,\
         paramFlag, paramIndex);
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParametero(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParametero(index,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameterv(index,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex paramIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameteri_str(index,\
         param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParametero_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParametero_str(index,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameterf_str(index,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->setMainGroupBehaviourParameterv_str(index,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameteri(index, paramFlag,\
         outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParametero(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParametero(index, paramFlag,\
         option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameterv(index, paramFlag,array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameteri_str(index, param,\
         outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParametero_str(\
	mvIndex worldIndex, mvIndex index, const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParametero_str(index, param,\
         option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameterf_str(index, param,\
         num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
	mvCount* noOfParameters)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->getMainGroupBehaviourParameterv_str(index, param,\
         array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveMemberFromGroup(mvIndex worldIndex,\
   mvIndex groupIndex, mvIndex memberIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeMemberFromGroup(groupIndex, memberIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllMembersFromGroup(\
   mvIndex worldIndex, mvIndex groupIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_INVALID_WORLD_INDEX;
      }
      return worldPtr->removeAllMembersFromGroup(groupIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvFindMemberInGroup(mvIndex worldIndex,
   mvIndex groupIndex, mvIndex memberIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
      {
         return MV_NULL;
      }
      return worldPtr->findMemberInGroup(groupIndex, memberIndex);
   }
   return MV_NULL;
}
