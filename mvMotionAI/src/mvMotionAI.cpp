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

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(mvIndex saveFileIndex)
{
   return mvMotionAI_V2_CREATEWORLD(saveFileIndex);
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

//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultActions(mvActionLoaderListPtr loader)
//{
//   return mvMotionAI_V2_LOADDEFAULTBEHAVIOURS(loader);
//}
//
//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultForces(mvForceLoaderListPtr loader)
//{
//   return mvMotionAI_V2_LOADDEFAULTFORCES(loader);
//}

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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddForceFunction(mvOptionEnum bType,\
   mvBaseForceLoaderPtr loader)
{
   return mvMotionAI_V2_ADDFORCEFUNC(bType, loader);
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
      worldPtr->bodies.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->obstacles.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->waypoints.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->pathways.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->groups.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->behaviours.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->groupBehaviours.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->forces.applyToAllItems(someFunction, extraPtr);
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
      worldPtr->bodies.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->obstacles.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->waypoints.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->pathways.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->groups.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->behaviours.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
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
      worldPtr->groupBehaviours.applyToAllItemsByIndex(worldIndex, someFunction,\
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
      worldPtr->forces.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z,
   mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createBody(bType, bShape, x, y, z, saveFileIndex);
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
      return worldPtr->bodies.getClassPtr(bodyIndex);
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
      return worldPtr->bodies.getCurrentIndex();
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
      return worldPtr->bodies.getCurrentClassPtr();
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
      return worldPtr->bodies.setCurrentIndex(index);
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
      return worldPtr->bodies.deleteItem(index);
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
      worldPtr->bodies.deleteAllItems();
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
      return worldPtr->bodies.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->bodies.setItemParametero(index, paramFlag, option);
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
      return worldPtr->bodies.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->bodies.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->bodies.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->bodies.setItemParametero_str(index, param, option);
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
      return worldPtr->bodies.setItemParameterf_str(index, param, num);
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
      return worldPtr->bodies.setItemParameterv_str(index, param, array);
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
      return worldPtr->bodies.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->bodies.getItemParametero(index, paramFlag, option);
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
      return worldPtr->bodies.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->bodies.getItemParameterv(index, paramFlag, array,\
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
      return worldPtr->bodies.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->bodies.getItemParametero_str(index, param, option);
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
      return worldPtr->bodies.getItemParameterf_str(index, param, num);
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
      return worldPtr->bodies.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_INVALID_WORLD_INDEX;
      return worldPtr->addBehaviourToList(bodyIndex, bType, behaviourIndex,\
         groupIndex, saveFileIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList_str(mvIndex worldIndex,\
   mvIndex listIndex, const char* bType, mvIndex behaviourIndex,\
   mvIndex groupIndex, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->addBehaviourToList_str(listIndex, bType,
         behaviourIndex, groupIndex, saveFileIndex);
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
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z,
   mvIndex saveFileIndex)
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
      return worldPtr->createObstacle(oShape, oState, x, y, z, saveFileIndex);
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
      return worldPtr->obstacles.getClassPtr(index);
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
      return worldPtr->obstacles.getCurrentIndex();
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
      return worldPtr->obstacles.getCurrentClassPtr();
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
      return worldPtr->obstacles.setCurrentIndex(index);
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
      return worldPtr->obstacles.deleteItem(index);
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
      worldPtr->obstacles.deleteAllItems();
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
      return worldPtr->obstacles.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->obstacles.setItemParametero(index, paramFlag, option);
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
      return worldPtr->obstacles.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->obstacles.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->obstacles.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->obstacles.setItemParametero_str(index, param, option);
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
      return worldPtr->obstacles.setItemParameterf_str(index, param, num);
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
      return worldPtr->obstacles.setItemParameterv_str(index, param, array);
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
      return worldPtr->obstacles.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->obstacles.getItemParametero(index, paramFlag, option);
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
      return worldPtr->obstacles.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->obstacles.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->obstacles.getItemParametero_str(index, param, option);
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
      return worldPtr->obstacles.getItemParameterf_str(index, param, num);
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
      return worldPtr->obstacles.getItemParameterv_str(index, param, array,\
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
   const char* wShape, mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;

      return worldPtr->createWaypoint_str(wShape, x, y, z, saveFileIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
	mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createWaypoint(wShape, x, y, z, saveFileIndex);
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
      return worldPtr->waypoints.getClassPtr(index);
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
      return worldPtr->waypoints.getCurrentIndex();
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
      return worldPtr->waypoints.getCurrentClassPtr();
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
      return worldPtr->waypoints.setCurrentIndex(index);
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
      return worldPtr->waypoints.deleteItem(index);
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
      worldPtr->waypoints.deleteAllItems();
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
      return worldPtr->waypoints.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->waypoints.setItemParametero(index, paramFlag, option);
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
      return worldPtr->waypoints.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->waypoints.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->waypoints.setItemParametero_str(index, param, option);
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
      return worldPtr->waypoints.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->waypoints.setItemParameterf_str(index, param, num);
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
      return worldPtr->waypoints.setItemParameterv_str(index, param, array);
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
      return worldPtr->waypoints.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->waypoints.getItemParametero(index, paramFlag, option);
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
      return worldPtr->waypoints.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->waypoints.getItemParameterv(index, paramFlag, array,\
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
      return worldPtr->waypoints.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->waypoints.getItemParametero_str(index, param, option);
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
      return worldPtr->waypoints.getItemParameterf_str(index, param, num);
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
      return worldPtr->waypoints.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
	 mvOptionEnum bType, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createBehaviour(bType,saveFileIndex);
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
      return worldPtr->behaviours.getClassPtr(index);
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
      return worldPtr->behaviours.getCurrentIndex();
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
      return worldPtr->behaviours.getCurrentClassPtr();
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
      return worldPtr->behaviours.setCurrentIndex(index);
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
      return worldPtr->behaviours.deleteItem(index);
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
      worldPtr->behaviours.deleteAllItems();
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
      return worldPtr->behaviours.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->behaviours.setItemParametero(index, paramFlag, option);
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
      return worldPtr->behaviours.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->behaviours.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->behaviours.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->behaviours.setItemParametero_str(index, param, option);
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
      return worldPtr->behaviours.setItemParameterf_str(index, param, num);
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
      return worldPtr->behaviours.setItemParameterv_str(index, param, array);
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
      return worldPtr->behaviours.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->behaviours.getItemParametero(index, paramFlag, option);
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
      return worldPtr->behaviours.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->behaviours.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->behaviours.getItemParametero_str(index, param, option);
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
      return worldPtr->behaviours.getItemParameterf_str(index, param, num);
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
      return worldPtr->behaviours.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createForce(fType, saveFileIndex);
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
      return worldPtr->forces.getClassPtr(index);
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
      return worldPtr->forces.getCurrentIndex();
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
      return worldPtr->forces.getCurrentClassPtr();
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
      return worldPtr->forces.setCurrentIndex(index);
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
      return worldPtr->forces.deleteItem(index);
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
      worldPtr->forces.deleteAllItems();
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
      return worldPtr->forces.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->forces.setItemParametero(index, paramFlag, option);
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
      return worldPtr->forces.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->forces.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->forces.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->forces.setItemParametero_str(index, param, option);
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
      return worldPtr->forces.setItemParameterf_str(index, param, num);
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
      return worldPtr->forces.setItemParameterv_str(index, param, array);
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
      return worldPtr->forces.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->forces.getItemParametero(index, paramFlag, option);
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
      return worldPtr->forces.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->forces.getItemParameterv(index, paramFlag, array,\
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
      return worldPtr->forces.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->forces.getItemParametero_str(index, param, option);
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
      return worldPtr->forces.getItemParameterf_str(index, param, num);
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
      return worldPtr->forces.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex,\
   mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createPathway(saveFileIndex);
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
      return worldPtr->pathways.getClassPtr(index);
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
      return worldPtr->pathways.getCurrentIndex();
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
      return worldPtr->pathways.getCurrentClassPtr();
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
      return worldPtr->pathways.setCurrentIndex(index);
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
      return worldPtr->pathways.deleteItem(index);
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
      worldPtr->pathways.deleteAllItems();
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
      return worldPtr->pathways.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->pathways.setItemParametero(index, paramFlag, option);
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
      return worldPtr->pathways.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->pathways.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->pathways.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->pathways.setItemParametero_str(index, param, option);
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
      return worldPtr->pathways.setItemParameterf_str(index, param, num);
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
      return worldPtr->pathways.setItemParameterv_str(index, param, array);
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
      return worldPtr->pathways.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->pathways.getItemParametero(index, paramFlag, option);
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
      return worldPtr->pathways.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->pathways.getItemParameterv(index, paramFlag, array,\
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
      return worldPtr->pathways.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->pathways.getItemParametero_str(index, param, option);
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
      return worldPtr->pathways.getItemParameterf_str(index, param, num);
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
      return worldPtr->pathways.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex,\
   mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;

      return worldPtr->createGroup(saveFileIndex);
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
      return worldPtr->groups.getClassPtr(index);
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
      return worldPtr->groups.getCurrentIndex();
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
      return worldPtr->groups.getCurrentClassPtr();
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
      return worldPtr->groups.setCurrentIndex(index);
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
      return worldPtr->groups.deleteItem(index);
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
      worldPtr->groups.deleteAllItems();
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
      return worldPtr->groups.setItemParameteri(index, paramFlag, paramIndex);
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
      return worldPtr->groups.setItemParametero(index, paramFlag, option);
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
      return worldPtr->groups.setItemParameterf(index, paramFlag, num);
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
      return worldPtr->groups.setItemParameterv(index, paramFlag, array);
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
      return worldPtr->groups.setItemParameteri_str(index, param, paramIndex);
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
      return worldPtr->groups.setItemParametero_str(index, param, option);
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
      return worldPtr->groups.setItemParameterf_str(index, param, num);
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
      return worldPtr->groups.setItemParameterv_str(index, param, array);
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
      return worldPtr->groups.getItemParameteri(index, paramFlag, outIndex);
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
      return worldPtr->groups.getItemParametero(index, paramFlag, option);
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
      return worldPtr->groups.getItemParameterf(index, paramFlag, num);
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
      return worldPtr->groups.getItemParameterv(index, paramFlag, array,\
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
      return worldPtr->groups.getItemParameteri_str(index, param, outIndex);
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
      return worldPtr->groups.getItemParametero_str(index, param, option);
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
      return worldPtr->groups.getItemParameterf_str(index, param, num);
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
      return worldPtr->groups.getItemParameterv_str(index, param, array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour(mvIndex worldIndex,\
   mvOptionEnum gbType, mvIndex saveFileIndex)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorldPtr worldPtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      if (worldPtr == MV_NULL)
         return MV_NULL;
      return worldPtr->createGroupBehaviour(gbType, saveFileIndex);
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
      return worldPtr->groupBehaviours.getClassPtr(index);
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
      return worldPtr->groupBehaviours.getCurrentIndex();
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
      return worldPtr->groupBehaviours.getCurrentClassPtr();
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
      return worldPtr->groupBehaviours.setCurrentIndex(index);
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
      return worldPtr->groupBehaviours.deleteItem(index);
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
      worldPtr->groupBehaviours.deleteAllItems();
   }
   return error;
}

//MV_GLOBAL_FUNC_PREFIX const char* mvGetErrorEnumString(mvErrorEnum error)
//{
//   return mvGetErrorString(error);
//}
//
//MV_GLOBAL_FUNC_PREFIX const char* mvGetParamEnumString(mvParamEnum param)
//{
//   return mvGetParamString(param);
//}
//
//MV_GLOBAL_FUNC_PREFIX const char* mvGetOptionEnumString(mvOptionEnum option)
//{
//   return mvGetOptionString(option);
//}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameteri(\
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
      return worldPtr->setGroupBehaviourNodeParameteri(gbIndex, groupIndex,\
         paramFlag, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParametero(\
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
      return worldPtr->setGroupBehaviourNodeParametero(gbIndex, groupIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterf(\
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
      return worldPtr->setGroupBehaviourNodeParameterf(gbIndex, groupIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterv(\
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
      return worldPtr->setGroupBehaviourNodeParameterv(gbIndex, groupIndex,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameteri_str(\
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
      return worldPtr->setGroupBehaviourNodeParameteri_str(gbIndex, groupIndex,\
         param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParametero_str(\
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
      return worldPtr->setGroupBehaviourNodeParametero_str(gbIndex, groupIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterf_str(\
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
      return worldPtr->setGroupBehaviourNodeParameterf_str(gbIndex, groupIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourNodeParameterv_str(\
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
      return worldPtr->setGroupBehaviourNodeParameterv_str(gbIndex, groupIndex,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameteri(\
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
      return worldPtr->getGroupBehaviourNodeParameteri(gbIndex, groupIndex,\
         paramFlag, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParametero(\
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
      return worldPtr->getGroupBehaviourNodeParametero(gbIndex, groupIndex,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterf(\
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
      return worldPtr->getGroupBehaviourNodeParameterf(gbIndex, groupIndex,\
         paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterv(\
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
      return worldPtr->getGroupBehaviourNodeParameterv(gbIndex, groupIndex,\
         paramFlag, array, noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameteri_str(\
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
      return worldPtr->getGroupBehaviourNodeParameteri_str(gbIndex, groupIndex,\
         param, outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParametero_str(\
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
      return worldPtr->getGroupBehaviourNodeParametero_str(gbIndex, groupIndex,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterf_str(\
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
      return worldPtr->getGroupBehaviourNodeParameterf_str(gbIndex, groupIndex,\
         param, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourNodeParameterv_str(\
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
      return worldPtr->getGroupBehaviourNodeParameterv_str(gbIndex, groupIndex,\
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
      return worldPtr->entryLists.setItemParameteri(listIndex, paramFlag, index);
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
      return worldPtr->entryLists.setItemParametero(listIndex, paramFlag, option);
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
      return worldPtr->entryLists.setItemParameterf(listIndex, paramFlag, num);
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
      return worldPtr->entryLists.setItemParameterv(listIndex, paramFlag, array);
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
      return worldPtr->entryLists.setItemParameteri_str(listIndex, param, index);
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
      return worldPtr->entryLists.setItemParametero_str(listIndex, param, option);
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
      return worldPtr->entryLists.setItemParameterf_str(listIndex, param, num);
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
      return worldPtr->entryLists.setItemParameterv_str(listIndex, param, array);
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
      return worldPtr->entryLists.getItemParameteri(listIndex, paramFlag, outIndex);
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
      return worldPtr->entryLists.getItemParametero(listIndex, paramFlag, option);
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
      return worldPtr->entryLists.getItemParameterf(listIndex, paramFlag, num);
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
      return worldPtr->entryLists.getItemParameterv(listIndex, paramFlag, array,
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
      return worldPtr->entryLists.getItemParameteri_str(listIndex, param, outIndex);
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
      return worldPtr->entryLists.getItemParametero_str(listIndex, param, option);
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
      return worldPtr->entryLists.getItemParameterf_str(listIndex, param, num);
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
      return worldPtr->entryLists.getItemParameterv_str(listIndex, param, array,
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
      worldPtr->entryLists.applyToAllItems(someFunction, extraPtr);
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
   const char* bType, const char* bShape, mvFloat x, mvFloat y, mvFloat z,
   mvIndex saveFileIndex)
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

      return worldPtr->createBody_str(bType, bShape, x,y,z,saveFileIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle_str(mvIndex worldIndex,\
   const char* oShape, const char* oState, mvFloat x, mvFloat y, mvFloat z,
   mvIndex saveFileIndex)
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

      return worldPtr->createObstacle_str(oShape, oShape, x,y,z,saveFileIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour_str(mvIndex worldIndex,\
   const char* bType, mvIndex saveFileIndex)
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

      return worldPtr->createBehaviour_str(bType,saveFileIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce_str(mvIndex worldIndex,\
   const char* fType, mvIndex saveFileIndex)
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

      return worldPtr->createForce_str(fType, saveFileIndex);
   }
   else
   {
      return MV_NULL;
   }
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour_str(mvIndex worldIndex,\
	const char* gbType,mvIndex saveFileIndex)
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

      return worldPtr->createGroupBehaviour_str(gbType,saveFileIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri(\
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
      return worldPtr->groupBehaviours.setItemParameteri(index,\
         paramFlag, paramIndex);
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero(\
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
      return worldPtr->groupBehaviours.setItemParametero(index,\
         paramFlag, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf(\
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
      return worldPtr->groupBehaviours.setItemParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv(\
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
      return worldPtr->groupBehaviours.setItemParameterv(index,\
         paramFlag, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri_str(\
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
      return worldPtr->groupBehaviours.setItemParameteri_str(index,\
         param, paramIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametero_str(\
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
      return worldPtr->groupBehaviours.setItemParametero_str(index,\
         param, option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf_str(\
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
      return worldPtr->groupBehaviours.setItemParameterf_str(index,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv_str(\
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
      return worldPtr->groupBehaviours.setItemParameterv_str(index,\
         param, array);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri(\
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
      return worldPtr->groupBehaviours.getItemParameteri(index, paramFlag,\
         outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero(\
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
      return worldPtr->groupBehaviours.getItemParametero(index, paramFlag,\
         option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf(\
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
      return worldPtr->groupBehaviours.getItemParameterf(index, paramFlag, num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv(\
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
      return worldPtr->groupBehaviours.getItemParameterv(index, paramFlag,array,\
         noOfParameters);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri_str(\
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
      return worldPtr->groupBehaviours.getItemParameteri_str(index, param,\
         outIndex);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametero_str(\
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
      return worldPtr->groupBehaviours.getItemParametero_str(index, param,\
         option);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf_str(\
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
      return worldPtr->groupBehaviours.getItemParameterf_str(index, param,\
         num);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv_str(\
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
      return worldPtr->groupBehaviours.getItemParameterv_str(index, param,\
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

MV_GLOBAL_FUNC_PREFIX mvEntryListPtr mvGetEntryListPtr(mvIndex worldIndex,\
   mvIndex entryListIndex)
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
      return worldPtr->entryLists.getClassPtr(entryListIndex);
   }
   return MV_NULL;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvStepBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs)
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
      return worldPtr->stepBody(bodyIndex, timeInSecs);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRegisterAllGroupBehavioursToBodies(mvIndex\
	worldIndex)
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
      worldPtr->registerAllGroupBehavioursToBodies();
      return MV_NO_ERROR;
   }
   return error;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRegisterGroupBehaviourToBodies(mvIndex\
	worldIndex, mvIndex groupBehaviour)
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
      return worldPtr->registerGroupBehaviourToBodies(groupBehaviour);
   }
   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveBodyAndEntryList(mvIndex worldIndex,\
	mvIndex objIndex)
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
      return worldPtr->removeBodyAndEntryList(objIndex);
   }
   return error;
}

/**
 * \ingroup mvGlobal
 * \return MV_NO_ERROR or if error has occured, a non zero value is returned.
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyAndEntryList(mvIndex worldIndex,\
	mvIndex objIndex)
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
      return worldPtr->setCurrentBodyAndEntryList(objIndex);
   }
   return error;
}

