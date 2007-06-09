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
#include MV_ENUMS_HEADER_FILE_H_

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

// TODO :
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultActions();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultForces();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitDefaultBodies();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvInitAllDefaults();

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultActions();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultForces();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeDefaultBodies();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvFreeAllDefaults();

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseActionLoader* loader);
MV_GLOBAL_FUNC_PREFIX mvBaseActionPtr mvCreateNewBehaviour(mvOptionEnum type,\
   mvBaseActionPtr defaultBehaviour);

// enums & error functions
MV_GLOBAL_FUNC_PREFIX const char* mvGetErrorEnumString(mvErrorEnum error);
MV_GLOBAL_FUNC_PREFIX const char* mvGetParamEnumString(mvParamEnum param);
MV_GLOBAL_FUNC_PREFIX const char* mvGetOptionEnumString(mvOptionEnum option);


// 506 functions + 2 + 2 + 4 + 8(13/10/06)
// // Lua fucntions
/*
removing lua functions to own file
#ifndef MV_ENABLE_LUA_SCRIPTING_FLAG
#define MV_ENABLE_LUA_SCRIPTING_FLAG 1
#include "mvLuaScript.h"
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFile(\
   char* fileName);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFromCString(\
   const char* statement);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadCStringWithLuaState(\
   lua_State* cState, const char* luaString);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFileWithLuaState(\
   lua_State* cState,const char* fileName);
#endif
*/

/* WORLD FUNCTIONS  = 18 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeCurrentBody(mvIndex worldIndex,\
   mvFloat timeInSecs);

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
   void (someFunction)(mvForcePtr,void*),void* extraPtr);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameteri(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGgetCurrentBodyParameter_str(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToCurrentBody(\
   mvIndex worldIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

/*
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
*/
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameter_str(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleAsWorldBoundary(\
   mvIndex worldIndex);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterf_str(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);


// TODO : Force => Waypoints

mvErrorEnum mvAddForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex,\
   mvIndex waypointIndex);
mvErrorEnum mvAddCurrentForceIntoWaypoint(mvIndex worldIndex,\
   mvIndex waypointIndex);
mvErrorEnum mvAddForceIntoCurrentWaypoint(mvIndex worldIndex,\
   mvIndex forceIndex);
mvErrorEnum mvAddCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);
mvErrorEnum mvRemoveForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex,\
   mvIndex waypointIndex);
mvErrorEnum mvRemoveCurrentForceIntoWaypoint(mvIndex worldIndex,\
   mvIndex waypointIndex);
mvErrorEnum mvRemoveForceIntoCurrentWaypoint(mvIndex worldIndex,\
   mvIndex forceIndex);
mvErrorEnum mvRemoveCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterf_str(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);



//=============
// TODO : mvForce
//No Of Functions : 37 = 5 + 16 + 16
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType);
MV_GLOBAL_FUNC_PREFIX mvForcePtr mvGetForcePtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvForcePtr mvGetCurrentForcePtr(mvIndex worldIndex);
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterf_str(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);


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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterf_str(mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);

// TODO : add waypoints to paths or Pathway Node

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddWaypointIntoPathway(mvIndex worldIndex,\
   mvIndex nodeIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentWaypointIntoPathway(\
   mvIndex worldIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddWaypointIntoCurrentPathway(\
   mvIndex worldIndex, mvIndex nodeIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentWaypointIntoCurrentPathway(\
   mvIndex worldIndex);

// TODO : last-in-first-out for duplicates

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveWaypointFromPathway(\
   mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentWaypointFromPathway(\
   mvIndex worldIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveWaypointFromCurrentPathway(\
   mvIndex worldIndex, mvIndex nodeIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentWaypointFromCurrentPathway(\
   mvIndex worldIndex);

// TODO : removes waypoints to paths

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveNodeFromPathway(mvIndex worldIndex,\
   mvIndex nodeIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentNodeFromPathway(\
   mvIndex worldIndex, mvIndex pathwayIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveNodeFromCurrentPathway(\
   mvIndex worldIndex, mvIndex nodeIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentNodeFromCurrentPathway(\
   mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameter(\
   mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex,\
   mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameter(\
   mvIndex worldIndex, mvIndex nodeIndex, mvParamEnum param,\
   mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameter(\
   mvIndex worldIndex, mvParamEnum param, mvIndex pathwayIndex,\
   mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum* option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameteri(\
   mvIndex worldIndex, mvIndex nodeIndex, mvParamEnum param, mvIndex* index)\
   ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex* index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);

// SET

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameteri_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameter_str(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterf_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameterv_str(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterf_str(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameter_str);

// TODO : GROUP ADD/REMOVE MEMBERS
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddMemberIntoGroup(mvIndex worldIndex,\
   mvIndex mIndex, mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentMemberIntoGroup(\
   mvIndex worldIndex, mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddMemberIntoCurrentGroup(\
   mvIndex worldIndex, mvIndex mIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentMemberIntoCurrentGroup(\
   mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveMemberFromGroup(mvIndex worldIndex,\
   mvIndex mIndex, mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentMemberFromGroup(\
   mvIndex worldIndex, mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveMemberFromCurrentGroup(\
   mvIndex worldIndex, mvIndex mIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentMemberFromCurrentGroup(\
   mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllMembersFromGroup(\
   mvIndex worldIndex, mvIndex mIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveAllMembersFromCurrentGroup(\
   mvIndex worldIndex);

// TODO : GROUP SET OPERATIONS LATER
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvCombineGroups(mvIndex worldIndex, mvIndex groupA, mvIndex groupB, mvOptionEnum operation);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvCombineGroupWithCurrentGroup(mvIndex worldIndex, mvIndex groupB, mvOptionEnum operation);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetOperationOnGroup(mvIndex worldIndex, mvIndex groupIndex, mvOptionEnum operation);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetOperationOnCurrentGroup(mvIndex worldIndex, mvOptionEnum operation);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameteri_str(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameter_str(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterf_str(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterv_str(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameter(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvFloat* array);

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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameteri_str(\
   mvIndex worldIndex, mvIndex groupIndex, const char* param,\
   mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameter_str(\
   mvIndex worldIndex, mvIndex groupIndex, const char* param,\
   const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameterf_str(\
   mvIndex worldIndex, mvIndex groupIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameterv_str(\
   mvIndex worldIndex, mvIndex groupIndex, const char* param, mvFloat* array);


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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameter(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex groupIndex, mvParamEnum paramFlag,\
	mvFloat* array, mvCount* noOfParameter_str);

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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameteri_str(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameter_str(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameterf_str(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameterv_str(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array, mvCount* noOfParameter_str);

// TODO : convert to global functions for group behaviours

// TODO : add group to group behaviours
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddGroupIntoGroupBehaviour(\
   mvIndex worldIndex,mvIndex groupIndex, mvIndex groupBehaviour);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentGroupIntoGroupBehaviour(\
   mvIndex worldIndex, mvIndex groupBehaviour);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddGroupIntoCurrentGroupBehaviour(\
   mvIndex worldIndex, mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddCurrentGroupIntoCurrentGroupBehaviour(\
   mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveGroupFromGroupBehaviour(\
   mvIndex worldIndex, mvIndex groupIndex, mvIndex groupBehaviour);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentGroupFromGroupBehaviour(\
   mvIndex worldIndex,mvIndex groupBehaviour);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveGroupFromCurrentGroupBehaviour(\
   mvIndex worldIndex,mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvRemoveCurrentGroupFromCurrentGroupBehaviour(\
   mvIndex worldIndex);

//  TODO : behaviour state functions using current body
//  32 functions = 16 + 16
//GET

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum* option)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameterv(\
   mvIndex worldIndex,mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option)\
  ;
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);

//SET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameter(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameteri(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameterf(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameter_str(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameteri_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameterf_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameterf_str(
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameterv_str(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

// TODO : tree functions  = 16
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameter_str(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameter_str);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameter_str(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameteri_str(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterf_str(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterv_str(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameter_str);
#endif

