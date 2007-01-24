/**
 * \file mv2.h
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

#ifndef MV_GLOBAL_FUNCTIONS_H_
#define MV_GLOBAL_FUNCTIONS_H_
#include "mvMotionAI-Types.h"
#include "mvWorld2.h"
#include "mvBaseBehaviour.h"
#include "mvEnums.h"

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
MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtrByID(const char* id);
MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtr(mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorld_V2*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultBehaviours();
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseBehaviourLoader* loader);
MV_GLOBAL_FUNC_PREFIX mvBaseBehaviour* mvCreateNewBehaviour(mvOptionEnum type,\
   mvBaseBehaviour* defaultBehaviour);

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
	mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameters(mvIndex worldIndex,\
	const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersi(mvIndex worldIndex,\
	const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersf(mvIndex worldIndex,\
	const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersv(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameters(mvIndex worldIndex,\
   const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersi(mvIndex worldIndex,\
   const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* array);

/*
 * C pointer foreach functions = 8
 * for C++ class methods
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBody*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstacle*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypoint*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathway*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroup*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviour*,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviour*,void*),\
   void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvForce*,void*),void* extraPtr);

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

// TODO : function laters
// TODO (White 2#1#): Global functions for mvMotionAI doing world and lua script functions

/* body functions ?? functions = 7 + 8 + 8 + 8 + 8*/

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBody(mvIndex worldIndex,\
   mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvBody* mvGetBodyPtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBody(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvBody* mvGetCurrentBodyPtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBodyParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameteri(\
   mvIndex worldIndex,  mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBodyParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGgetCurrentBodyParameters(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBodyParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

/* TODO: implement the functions below */
//change default body setting later... do we need these functions = 16

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultWaypointOfBody(\
   mvIndex worldIndex, mvIndex* wayPoint, mvIndex* bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultPathwayOfBody(\
   mvIndex worldIndex, mvIndex* pathway, mvIndex* bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultBodyOfBody(\
   mvIndex worldIndex, mvIndex* target, mvIndex* bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultWeightOfBody(\
   mvIndex worldIndex, mvFloat* weight, mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultWaypointOfCurrentBody(\
   mvIndex worldIndex, mvIndex* wayPoint);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultPathwayOfCurrentBody(\
   mvIndex worldIndex, mvIndex* pathway);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultBodyOfCurrentBody(\
   mvIndex worldIndex, mvIndex* target);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetDefaultWeightOfCurrentBody(\
   mvIndex worldIndex, mvFloat* weight);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultWaypointOfBody(\
   mvIndex worldIndex, mvIndex wayPoint, mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultPathwayOfBody(\
   mvIndex worldIndex, mvIndex pathway, mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultBodyOfBody(\
   mvIndex worldIndex, mvIndex target, mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultWeightOfBody(\
   mvIndex worldIndex, mvFloat weight, mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultWaypointOfCurrentBody(\
   mvIndex worldIndex, mvIndex wayPoint);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultPathwayOfCurrentBody(\
   mvIndex worldIndex, mvIndex pathway);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultBodyOfCurrentBody(\
   mvIndex worldIndex, mvIndex target);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetDefaultWeightOfCurrentBody(\
   mvIndex worldIndex, mvFloat weight);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourToCurrentBody(\
   mvIndex worldIndex, mvOptionEnum bType, mvIndex behaviourIndex,\
   mvIndex groupIndex);

////mvObstacle 41 functions =  9 + 16 + 16
MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateObstacle(mvIndex worldIndex,\
   mvOptionEnum oShape, mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvObstacle* mvGetObstaclePtr(mvIndex worldIndex,\
   mvIndex bodyIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentObstacle(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvObstacle* mvGetCurrentObstaclePtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameteri(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameter(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterf(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameterv(\
   mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetObstacleParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParameters(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentObstacleParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetObstacleAsWorldBoundary(\
   mvIndex worldIndex, mvIndex obstacleIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentObstacleAsWorldBoundary(\
   mvIndex worldIndex);

/*
 * TODO : mvWaypoint No Of Functions : 46 = 6 + 16 + 16 + 8
 */

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWaypoint(mvIndex worldIndex,\
	 mvOptionEnum wType, mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z);
MV_GLOBAL_FUNC_PREFIX mvWaypoint* mvGetWaypointPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentWaypoint(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvWaypoint* mvGetCurrentWaypointPtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWaypointParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentWaypointParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWaypointParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentWaypointParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);


// TODO : Force => Waypoints

mvErrorEnum mvAddForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex, mvIndex waypointIndex);
mvErrorEnum mvAddCurrentForceIntoWaypoint(mvIndex worldIndex, mvIndex waypointIndex);
mvErrorEnum mvAddForceIntoCurrentWaypoint(mvIndex worldIndex, mvIndex forceIndex);
mvErrorEnum mvAddCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);
mvErrorEnum mvRemoveForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex, mvIndex waypointIndex);
mvErrorEnum mvRemoveCurrentForceIntoWaypoint(mvIndex worldIndex, mvIndex waypointIndex);
mvErrorEnum mvRemoveForceIntoCurrentWaypoint(mvIndex worldIndex, mvIndex forceIndex);
mvErrorEnum mvRemoveCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);

/*
 *mvBehaviour
 *No Of Functions : 39 = 5 + 2 + 16 + 16
 */

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateBehaviour(mvIndex worldIndex,\
	 mvOptionEnum bType);
MV_GLOBAL_FUNC_PREFIX mvBehaviour* mvGetBehaviourPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvBehaviour* mvGetCurrentBehaviourPtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);



//=============
// TODO : mvForce
//No Of Functions : 37 = 5 + 16 + 16
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateForce(mvIndex worldIndex,\
   mvOptionEnum fType);
MV_GLOBAL_FUNC_PREFIX mvForce* mvGetForcePtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentForce(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvForce* mvGetCurrentForcePtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetForceParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentForceParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetForceParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentForceParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);


//=============
//TODO : mvPathway
//No Of Functions : 115 = 5 + 16 + 16 (37) + 12 + 32 + 32 + 2
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreatePathway(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvPathway* mvGetPathwayPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentPathway(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvPathway* mvGetCurrentPathwayPtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetPathwayParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentPathwayParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetPathwayParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentPathwayParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);

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
   mvIndex worldIndex, mvIndex nodeIndex, mvParamEnum param, mvIndex* index);
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
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParameters(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParameters(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameters(\
   mvIndex worldIndex, const char* param, const char* option);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParametersi(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParametersi(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParametersf(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParametersf(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInPathwayParametersv(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetNodeInCurrentPathwayParametersv(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInPathwayParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

// SET

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameter(mvIndex worldIndex, mvIndex index,                                        mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetNodeInCurrentPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

//=============
//TODO : mvGroup
//No Of Functions : 51 = 8 + 5 + 16 + 16 + 2 + 4
//=============

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateGroup(mvIndex worldIndex,\
   const char* groupName);
MV_GLOBAL_FUNC_PREFIX mvGroup* mvGetGroupPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroup(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvGroup* mvGetCurrentGroupPtr(mvIndex worldIndex);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);

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
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviour* mvGetGroupBehaviourPtr(mvIndex worldIndex,\
	 mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvIndex mvGetCurrentGroupBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvGroupBehaviour* mvGetCurrentGroupBehaviourPtr(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteCurrentGroupBehaviour(mvIndex worldIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteGroupBehaviour(mvIndex worldIndex,\
   mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllGroupBehaviours(mvIndex worldIndex);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameteri(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterf(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameterv(\
   mvIndex worldIndex,mvParamEnum paramFlag, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParametersi(mvIndex worldIndex,\
   mvIndex index, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParameters(mvIndex worldIndex,\
   mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetMainGroupBehaviourParametersf(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBodyParametersv(mvIndex worldIndex,\
   mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParametersi(\
   mvIndex worldIndex, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentMainGroupBehaviourParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameteri(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameter(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterf(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameterv(mvIndex worldIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameteri(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameter(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterf(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameterv(\
	mvIndex worldIndex, mvParamEnum paramFlag, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParametersi(\
	mvIndex worldIndex, mvIndex index, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParameters(\
	mvIndex worldIndex, mvIndex index, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParametersf(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetMainGroupBehaviourParametersv(\
	mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
	mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParametersi(\
	mvIndex worldIndex, const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParameters(\
	mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParametersf(\
	mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentMainGroupBehaviourParametersv(\
	mvIndex worldIndex, const char* param, mvFloat* array,\
	mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameteri(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameter(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameterv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   mvIndex index, mvParamEnum paramFlag, mvFloat* array);
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametersi(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParameters(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametersf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetGroupBehaviourParametersv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParametersi(\
   mvIndex worldIndex, mvIndex gbType, const char* param, mvIndex paramIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParameters(\
   mvIndex worldIndex, mvIndex gbType, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParametersf(\
   mvIndex worldIndex, mvIndex gbType, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentGroupBehaviourParametersv(\
   mvIndex worldIndex, mvIndex gbType, const char* param, mvFloat* array);

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
	mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);
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
	mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametersi(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParameters(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametersf(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetGroupBehaviourParametersv(\
	mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParametersi(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvIndex* outIndex);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParameters(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParametersf(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentGroupBehaviourParametersv(\
	mvIndex worldIndex, mvIndex groupIndex, const char* param,\
	mvFloat* array, mvCount* noOfParameters);

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
   mvIndex worldIndex, mvIndex index, mvParamEnum param, mvOptionEnum* option);
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
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameterv(\
   mvIndex worldIndex,mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParameters(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParametersi(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParametersf(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourEntryParametersv(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array,\
   mvCount* noOfParameters);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetCurrentBehaviourEntryParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);

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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParameters(\
   mvIndex worldIndex, mvIndex index, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParametersi(\
   mvIndex worldIndex, mvIndex index, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParametersi(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParametersf(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParametersf(
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourEntryParametersv(\
   mvIndex worldIndex, mvIndex index, const char* param, mvFloat* array);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetCurrentBehaviourEntryParametersv(\
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

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParameters(\
   mvIndex worldIndex, const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParametersi(\
   mvIndex worldIndex, const char* param, mvIndex index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParametersf(\
   mvIndex worldIndex, const char* param, mvFloat num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetBehaviourTreeParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameter(\
   mvIndex worldIndex, mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameteri(\
   mvIndex worldIndex, mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterf(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameterv(\
   mvIndex worldIndex, mvParamEnum param, mvFloat* array,\
   mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParameters(\
   mvIndex worldIndex, const char* param, const char** option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParametersi(\
   mvIndex worldIndex, const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParametersf(\
   mvIndex worldIndex, const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetBehaviourTreeParametersv(\
   mvIndex worldIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters);
#endif

