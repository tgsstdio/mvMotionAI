#ifndef MV_GLOBAL_FUNCTIONS_H_
#define MV_GLOBAL_FUNCTIONS_H_

#include "mvMotionAI-Types.h"
#ifdef MV_FILE_HEADER_TAG_
/**
 * \file mvMotionAI.h
 *
 * Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Log
 * version
 * 00-01-31    19/01/07
 *
 * - now mvMotionAI C interface using mvWorld_V2
 *
 * 00-01-25    23/12/06
 *
 * -changed function signature
 *  - Permanent removing item from world  = Remove to Delete
 * - mvRemoveAllWorlds to mvDeleteAllWorlds
 *  - Create instead of Add
 * - mvAddWorld to mvCreateAllWorlds
 */
#endif

#include MV_WORLD_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
#include MV_ACTION_LOADER_LIST_HEADER_FILE_H_
#include MV_FORCE_LOADER_LIST_HEADER_FILE_H_

#ifdef BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

// mvMotionAI functions - 13 functions
MV_GLOBAL_FUNC_PREFIX void mvInitMotionAI();
MV_GLOBAL_FUNC_PREFIX void mvFreeMotionAI();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAllWorldsStepForward(mvFloat timeInSecs);
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(const char* id);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWorlds();
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetWorldByID(const char* id);
MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetWorldPtrByID(const char* id);
MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetWorldPtr(mvIndex index);

MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWorld(mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWorld();
MV_GLOBAL_FUNC_PREFIX mvWorldPtr mvGetCurrentWorldPtr();

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorldPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultActions();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultForces();
//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultBodies();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitAllDefaults();

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultActions();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultForces();
//MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultBodies();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeAllDefaults();

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddForceFunction(mvOptionEnum bType,\
   mvBaseForceLoaderPtr loader);
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvCreateNewForce(mvOptionEnum type);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseActionLoaderPtr loader);
MV_GLOBAL_FUNC_PREFIX mvBaseActionPtr mvCreateNewBehaviour(mvOptionEnum type,\
   mvBaseActionPtr defaultBehaviour);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultBehaviours(\
   mvActionLoaderListPtr loader);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultForces(\
   mvForceLoaderListPtr loader);


// enums & error functions
MV_GLOBAL_FUNC_PREFIX const char* mvGetErrorEnumString(mvErrorEnum error);
MV_GLOBAL_FUNC_PREFIX const char* mvGetParamEnumString(mvParamEnum param);
MV_GLOBAL_FUNC_PREFIX const char* mvGetOptionEnumString(mvOptionEnum option);

// world instance functions
/**
 * TODO : remove world index from C interface
 */

/* WORLD FUNCTIONS  = 18 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* array, mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameter_str(mvIndex worldIndex,\
	const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri_str(mvIndex worldIndex,\
	const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf_str(mvIndex worldIndex,\
	const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv_str(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameter_str(mvIndex worldIndex,\
   const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri_str(mvIndex worldIndex,\
   const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf_str(mvIndex worldIndex,\
   const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv_str(mvIndex worldIndex,\
   const char* param, mvFloat* array);

/*
 * C pointer foreach functions = 8
 * for C++ class methods
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBodyPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstaclePtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypointPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathwayPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroupPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviourPtr,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviourPtr,void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvBaseForcePtr,void*),void* extraPtr);

/*
 * mvIndex foreach functions = 8
 * for using C interface functions
 */

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstaclesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypointsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex,void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathwaysByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,mvIndex, void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,mvIndex, void*), void* extraPtr);

/* body functions ?? functions = 7 + 8 + 8 + 8 + 8*/

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetBodyPtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBody(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvBodyPtr mvGetCurrentBodyPtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBody(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentBody(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBody(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBodies(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str)\
   ;

MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex = MV_NULL,\
   mvIndex groupIndex = MV_NULL);
MV_GLOBAL_FUNC_PREFIX mvIndex mvAddBehaviourToList_str(mvIndex worldIndex,\
   mvIndex listIndex, const char* bType, mvIndex behaviourIndex,\
   mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveBehaviourFromList(mvIndex worldIndex,\
   mvIndex listIndex,\
   mvIndex entryIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllBehavioursFromList(\
   mvIndex worldIndex, mvIndex listIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentEntryFromList(mvIndex worldIndex,\
   mvIndex listIndex);

////mvObstacle 41 functions =  9 + 16 + 16
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle(mvIndex worldIndex,\
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetObstaclePtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentObstacle(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvObstaclePtr mvGetCurrentObstaclePtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentObstacle(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentObstacle(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteObstacle(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllObstacles(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex);

/*
 * TODO : mvWaypoint No Of Functions : 46 = 6 + 16 + 16 + 8
 */

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
   mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetWaypointPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWaypoint(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvWaypointPtr mvGetCurrentWaypointPtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentWaypoint(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentWaypoint(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteWaypoint(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWaypoints(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str)\
   ;
// TODO : Force => Waypoints

mvErrorEnum mvAddForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex,\
   mvIndex waypointIndex);
mvErrorEnum mvRemoveForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex,\
   mvIndex waypointIndex);

/*
 *mvBehaviour
 *No Of Functions : 39 = 5 + 2 + 16 + 16
 */

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
	 mvOptionEnum bType);
MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetBehaviourPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvBehaviourPtr mvGetCurrentBehaviourPtr(\
   mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllBehaviours(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str)\
   ;

//=============
// TODO : mvForce
//No Of Functions : 37 = 5 + 16 + 16
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType);
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetForcePtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvBaseForcePtr mvGetCurrentForcePtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentForce(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentForce(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteForce(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllForces(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str)\
   ;

//=============
//TODO : mvPathway
//No Of Functions : 115 = 5 + 16 + 16 (37) + 12 + 32 + 32 + 2
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetPathwayPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentPathway(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvPathwayPtr mvGetCurrentPathwayPtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentPathway(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentPathway(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeletePathway(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllPathways(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str);

// TODO : add waypoints to paths or Pathway Node

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddWaypointIntoPathway(mvIndex worldIndex,\
   mvIndex nodeIndex, mvIndex pathwayIndex);

// TODO : last-in-first-out for duplicates

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveWaypointFromPathway(\
   mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex);

// TODO : removes waypoints to paths

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveNodeFromPathway(mvIndex worldIndex,\
   mvIndex nodeIndex, mvIndex pathwayIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameter(\
   mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex,\
   mvParamEnum param, mvOptionEnum* option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameteri(\
   mvIndex worldIndex, mvIndex nodeIndex, mvParamEnum param, mvIndex* index)\
   ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)\
  ;

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);

// SET

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum option);


//=============
//TODO : mvGroup
//No Of Functions : 51 = 8 + 5 + 16 + 16 + 2 + 4
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex,\
   const char* groupName);
MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetGroupPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroup(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvGroupPtr mvGetCurrentGroupPtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroup(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentGroup(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroup(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroups(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str)\
  ;

// TODO : GROUP ADD/REMOVE MEMBERS
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddMemberIntoGroup(mvIndex worldIndex,\
   mvIndex mIndex, mvIndex groupIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveMemberFromGroup(mvIndex worldIndex,\
   mvIndex mIndex, mvIndex groupIndex);


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllMembersFromGroup(\
   mvIndex worldIndex, mvIndex mIndex);


// TODO : GROUP SET OPERATIONS LATER
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvCombineGroups(mvIndex worldIndex, mvIndex groupA, mvIndex groupB, mvOptionEnum operation);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetOperationOnGroup(mvIndex worldIndex, mvIndex groupIndex, mvOptionEnum operation);


//=============
// TODO : GROUP BEHAVIOURS
//No Of Functions : 75 = 5 + 4 + 4 + 32 + 32
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroupBehaviour(mvIndex worldIndex,\
	 mvOptionEnum gbType);
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetGroupBehaviourPtr(\
   mvIndex worldIndex, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroupBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviourPtr mvGetCurrentGroupBehaviourPtr(\
mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentGroupBehaviour(\
   mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroupBehaviours(\
   mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat num)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array)\
  ;

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex paramIndex)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex)\
	;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameter_str(\
	mvIndex worldIndex, mvIndex index, const char* param, const char** option)\
	;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num) ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameter(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* array);


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameter_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array);


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameter(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
	mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameter_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameter_str);

// TODO : add group to group behaviours
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddGroupIntoGroupBehaviour(\
   mvIndex worldIndex,mvIndex groupIndex, mvIndex groupBehaviour);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveGroupFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex groupIndex, mvIndex groupBehaviour);

//TODO : behaviour state functions using current body
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameter(
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameter_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameter(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameter_str(\
   mvIndex worldIndex, mvIndex listIndex,mvIndex nodeIndex, const char* param,
   const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListNodeParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, mvIndex nodeIndex, const char* param,\
   mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameter(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameter_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameter(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv(mvIndex worldIndex,\
   mvIndex listIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameteri_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameter_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param,\
   const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterf_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetEntryListParameterv_str(\
   mvIndex worldIndex, mvIndex listIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllEntryLists(mvIndex worldIndex,\
   void (someFunction)(mvEntryListPtr, void*), void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex, void* userData);
MV_GLOBAL_FUNC_PREFIX void* mvGetUserData(mvIndex worldIndex,\
   mvParamEnum objectType, mvIndex objectIndex);
#endif

