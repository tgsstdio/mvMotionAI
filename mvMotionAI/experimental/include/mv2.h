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

/* TODO (White 2#1#): implement functions later */

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeCurrentBody(mvIndex worldIndex,\
   mvFloat timeInSecs);

//GET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameter(mvIndex worldIndex,\
	mvParamEnum param, mvOptionEnum* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri(mvIndex worldIndex,\
	mvParamEnum param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv(mvIndex worldIndex,\
	mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameters(mvIndex worldIndex,\
	const char* param, const char* option);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersi(mvIndex worldIndex,\
	const char* param, mvIndex* index);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersf(mvIndex worldIndex,\
	const char* param, mvFloat* num);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersv(mvIndex worldIndex,\
	const char* param, mvFloat* array, mvCount* noOfParameters);

//SET
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

// C pointer
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
// mvIndex

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodiesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstaclesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypointsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathwaysByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,void*),void* extraPtr);

// TODO (White 2#1#): Global functions for mvMotionAI doing world and lua script functions

//// body functions 44 functions = 6 + 16 + 16 + 16//
mvIndex mvAddBody(mvIndex worldIndex, mvOptionEnum bodyType, mvOptionEnum bodyShape);
mvIndex mvAddBodyWithPos(mvIndex worldIndex, mvOptionEnum bodyType, mvOptionEnum bodyShape,\
        mvFloat x, mvFloat y, mvFloat z);
void mvRemoveCurrentBody(mvIndex worldIndex);mvErrorEnum mvRemoveBody(mvIndex worldIndex, mvIndex index);
void mvRemoveAllBodies(mvIndex worldIndex);mvIndex mvSetCurrentBody(mvIndex worldIndex, mvIndex index);

//change default body setting later...

mvErrorEnum mvGetDefaultWaypointForBody(mvIndex worldIndex, mvIndex* wayPoint, mvIndex* bodyIndex);
mvErrorEnum mvGetDefaultPathwayForBody(mvIndex worldIndex, mvIndex* pathway, mvIndex* bodyIndex);
mvErrorEnum mvGetDefaultBodyForBody(mvIndex worldIndex, mvIndex* target, mvIndex* bodyIndex);
mvErrorEnum mvGetDefaultBehaviourFactorForBody(mvIndex worldIndex, mvFloat* bFactor, mvIndex bodyIndex);
mvErrorEnum mvGetDefaultWaypointOfCurrentBody(mvIndex worldIndex, mvIndex* wayPoint);
mvErrorEnum mvGetDefaultPathwayOfCurrentBody(mvIndex worldIndex, mvIndex* pathway);
mvErrorEnum mvGetDefaultBodyOfCurrentBody(mvIndex worldIndex, mvIndex* target);
mvErrorEnum mvGetDefaultBehaviourFactorOfCurrentBody(mvIndex worldIndex, mvFloat* bFactor);
mvErrorEnum mvSetDefaultWaypointForBody(mvIndex worldIndex, mvIndex wayPoint, mvIndex bodyIndex);
mvErrorEnum mvSetDefaultPathwayForBody(mvIndex worldIndex, mvIndex pathway, mvIndex bodyIndex);
mvErrorEnum mvSetDefaultBodyForBody(mvIndex worldIndex, mvIndex target, mvIndex bodyIndex);
mvErrorEnum mvSetDefaultBehaviourFactorForBody(mvIndex worldIndex, mvFloat bFactor, mvIndex bodyIndex);
mvErrorEnum mvSetDefaultWaypointForCurrentBody(mvIndex worldIndex, mvIndex wayPoint);
mvErrorEnum mvSetDefaultPathwayForCurrentBody(mvIndex worldIndex, mvIndex pathway);
mvErrorEnum mvSetDefaultBodyForCurrentBody(mvIndex worldIndex, mvIndex target);
mvErrorEnum mvSetDefaultBehaviourFactorForCurrentBody(mvIndex worldIndex, mvFloat bFactor);

// get methods
mvErrorEnum mvGetBodyParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentBodyParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetBodyParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentBodyParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetBodyParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentBodyParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetBodyParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBodyParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetBodyParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvGetCurrentBodyParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvGetBodyParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentBodyParametersi(mvIndex worldIndex,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetBodyParametersf(mvIndex worldIndex, mvIndex index, \
            const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentBodyParametersf(mvIndex worldIndex,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetBodyParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBodyParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array, mvCount* noOfParameters);

// set methods

mvErrorEnum mvSetBodyParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentBodyParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetBodyParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentBodyParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetBodyParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentBodyParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetBodyParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentBodyParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetBodyParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvSetCurrentBodyParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvSetBodyParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex index);
mvErrorEnum mvSetCurrentBodyParametersi(mvIndex worldIndex,\
            const char* param, mvIndex index);
mvErrorEnum mvSetBodyParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat num);
mvErrorEnum mvSetCurrentBodyParametersf(mvIndex worldIndex,\
            const char* param, mvFloat num);
mvErrorEnum mvSetBodyParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentBodyParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array);

////mvObstacle 41 functions =  9 + 16 + 16
mvIndex mvAddObstacle(mvIndex worldIndex, mvOptionEnum oShape, mvOptionEnum oState);
mvIndex mvAddObstacleWithPos(mvIndex worldIndex, mvOptionEnum oShape,\
        mvOptionEnum oState, mvFloat x, mvFloat y, mvFloat z);
mvErrorEnum mvRemoveCurrentObstacle(mvIndex worldIndex);
mvErrorEnum mvRemoveObstacle(mvIndex worldIndex, mvIndex index);
mvErrorEnum mvSetCurrentObstacle(mvIndex worldIndex, mvIndex index);
void mvRemoveAllObstacles(mvIndex worldIndex);
mvErrorEnum mvSetObstacleAsWorldBoundary(mvIndex worldIndex, mvIndex obstacleIndex);
mvErrorEnum mvSetCurrentObstacleAsWorldBoundary(mvIndex worldIndex);
mvErrorEnum mvGetCurrentObstacleAsWorldBoundary(mvIndex worldIndex);

// GET

mvErrorEnum mvGetObstacleParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentObstacleParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetObstacleParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentObstacleParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetObstacleParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentObstacleParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetObstacleParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentObstacleParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetObstacleParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvGetCurrentObstacleParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvGetObstacleParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentObstacleParametersi(mvIndex worldIndex,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetObstacleParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentObstacleParametersf(mvIndex worldIndex,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetObstacleParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentObstacleParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array, mvCount* noOfParameters);

// SET
mvErrorEnum mvSetObstacleParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentObstacleParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetObstacleParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentObstacleParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetObstacleParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentObstacleParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetObstacleParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentObstacleParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetObstacleParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvSetCurrentObstacleParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvSetObstacleParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex index);
mvErrorEnum mvSetCurrentObstacleParametersi(mvIndex worldIndex,\
            const char* param, mvIndex index);
mvErrorEnum mvSetObstacleParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat num);
mvErrorEnum mvSetCurrentObstacleParametersf(mvIndex worldIndex,\
            const char* param, mvFloat num);
mvErrorEnum mvSetObstacleParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentObstacleParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array);

/*
 * mvWaypoint
 * No Of Functions : 46 = 6 + 16 + 16 + 8
 */

mvIndex mvAddWaypoint(mvIndex worldIndex, mvOptionEnum wType,\
        mvOptionEnum wShape);
mvIndex mvAddWaypointWithPos(mvIndex worldIndex, mvOptionEnum wType,\
        mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z);
mvErrorEnum mvRemoveWaypoint(mvIndex worldIndex, mvIndex index);
mvErrorEnum mvRemoveCurrentWaypoint(mvIndex worldIndex);
mvIndex mvSetCurrentWaypoint(mvIndex worldIndex, mvIndex index);
void mvRemoveAllWaypoints(mvIndex worldIndex);

// Force => Waypoints

mvErrorEnum mvIncludeForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex, mvIndex waypointIndex);
mvErrorEnum mvIncludeCurrentForceIntoWaypoint(mvIndex worldIndex, mvIndex waypointIndex);
mvErrorEnum mvIncludeForceIntoCurrentWaypoint(mvIndex worldIndex, mvIndex forceIndex);
mvErrorEnum mvIncludeCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);
mvErrorEnum mvReleaseForceIntoWaypoint(mvIndex worldIndex, mvIndex forceIndex, mvIndex waypointIndex);
mvErrorEnum mvReleaseCurrentForceIntoWaypoint(mvIndex worldIndex, mvIndex waypointIndex);
mvErrorEnum mvReleaseForceIntoCurrentWaypoint(mvIndex worldIndex, mvIndex forceIndex);
mvErrorEnum mvReleaseCurrentForceIntoCurrentWaypoint(mvIndex worldIndex);

// GET

mvErrorEnum mvGetWaypointParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentWaypointParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetWaypointParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvGetCurrentWaypointParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetWaypointParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvGetCurrentWaypointParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetWaypointParameterv(mvIndex worldIndex, mvIndex index,\
mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentWaypointParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetWaypointParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvGetCurrentWaypointParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvGetWaypointParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentWaypointParametersi(mvIndex worldIndex,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetWaypointParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentWaypointParametersf(mvIndex worldIndex,\
            const char* param, mvFloat* num, mvCount* noOfParameters);
mvErrorEnum mvGetWaypointParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentWaypointParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array, mvCount* noOfParameters);

// SET

mvErrorEnum mvSetWaypointParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentWaypointParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetWaypointParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentWaypointParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetWaypointParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentWaypointParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetWaypointParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentWaypointParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvSetWaypointParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvSetCurrentWaypointParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvSetWaypointParametersi(mvIndex worldIndex, mvIndex index,
            const char* param, mvIndex index);
mvErrorEnum mvSetCurrentWaypointParametersi(mvIndex worldIndex,\
            const char* param, mvIndex index);
mvErrorEnum mvSetWaypointParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat num);
mvErrorEnum mvSetCurrentWaypointParametersf(mvIndex worldIndex,\
            const char* param, mvFloat num);
mvErrorEnum mvSetWaypointParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentWaypointParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array);

/*
 *mvBehaviour
 *No Of Functions : 39 = 5 + 2 + 16 + 16
 */

mvIndex mvAddBehaviour(mvIndex worldIndex, mvOptionEnum bType);
mvErrorEnum mvRemoveCurrentBehaviour(mvIndex worldIndex);
mvErrorEnum mvRemoveBehaviour(mvIndex worldIndex, mvIndex index);
mvIndex mvSetCurrentBehaviour(mvIndex worldIndex, mvIndex index);
void mvRemoveAllBehaviours(mvIndex worldIndex);

// change format later.

mvErrorEnum mvAddBehaviourToBody(mvIndex worldIndex, mvIndex bodyIndex,\
   mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);
mvErrorEnum mvAddBehaviourToCurrentBody(mvIndex worldIndex, mvOptionEnum bType,\
            mvIndex behaviourIndex, mvIndex groupIndex);

// GET
mvErrorEnum mvGetBehaviourParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvGetCurrentBehaviourParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetBehaviourParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvGetCurrentBehaviourParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetBehaviourParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvGetCurrentBehaviourParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetBehaviourParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBehaviourParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetBehaviourParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvGetCurrentBehaviourParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvGetBehaviourParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex index);
mvErrorEnum mvGetCurrentBehaviourParametersi(mvIndex worldIndex,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetBehaviourParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentBehaviourParametersf(mvIndex worldIndex,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetBehaviourParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBehaviourParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array, mvCount* noOfParameters);

// SET
mvErrorEnum mvSetBehaviourParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentBehaviourParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetBehaviourParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentBehaviourParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex index);
mvErrorEnum mvSetBehaviourParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentBehaviourParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat num);
mvErrorEnum mvSetBehaviourParameterv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentBehaviourParameterv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetBehaviourParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvSetCurrentBehaviourParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvSetBehaviourParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex index);
mvErrorEnum mvSetCurrentBehaviourParametersi(mvIndex worldIndex,\
            const char* param, mvIndex index);
mvErrorEnum mvSetBehaviourParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat num);
mvErrorEnum mvSetCurrentBehaviourParametersf(mvIndex worldIndex,\
            const char* param, mvFloat num);
mvErrorEnum mvSetBehaviourParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentBehaviourParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array);

//=============
//mvForce
//No Of Functions : 37 = 5 + 16 + 16
//=============

mvIndex mvAddForce(mvIndex worldIndex, mvOptionEnum fType);
mvErrorEnum mvRemoveCurrentForce(mvIndex worldIndex);
mvErrorEnum mvRemoveForce(mvIndex worldIndex, mvIndex index);
mvIndex mvSetCurrentForce(mvIndex worldIndex, mvIndex index);
void mvRemoveAllForces(mvIndex worldIndex);

//GET
mvErrorEnum mvGetForceParameter(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentForceParameter(mvIndex worldIndex,\
            mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetForceParameteri(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentForceParameteri(mvIndex worldIndex,\
            mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetForceParameterf(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentForceParameterf(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetForceParametersv(mvIndex worldIndex, mvIndex index,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentForceParametersv(mvIndex worldIndex,\
            mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetForceParameters(mvIndex worldIndex, mvIndex index,\
            const char* param, const char* option);
mvErrorEnum mvGetCurrentForceParameters(mvIndex worldIndex,\
            const char* param, const char* option);
mvErrorEnum mvGetForceParametersi(mvIndex worldIndex, mvIndex index,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentForceParametersi(mvIndex worldIndex,\
            const char* param, mvIndex* index);
mvErrorEnum mvGetForceParametersf(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentForceParametersf(mvIndex worldIndex,\
            const char* param, mvFloat* num, mvCount* noOfParameters);
mvErrorEnum mvGetForceParametersv(mvIndex worldIndex, mvIndex index,\
            const char* param, mvFloat* array);
mvErrorEnum mvGetCurrentForceParametersv(mvIndex worldIndex,\
            const char* param, mvFloat* array, mvCount* noOfParameters);

// SET
mvErrorEnum mvSetForceParameter(mvIndex worldIndex, mvIndex index,                                mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentForceParameter(mvIndex worldIndex,                                       mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetForceParameteri(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentForceParameteri(mvIndex worldIndex,                                        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetForceParameterf(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentForceParameterf(mvIndex worldIndex,                                        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetForceParametersv(mvIndex worldIndex, mvIndex index,                                  mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentForceParametersv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetForceParameters(mvIndex worldIndex, mvIndex index,                                 const char* param, const char* option);
mvErrorEnum mvSetCurrentForceParameters(mvIndex worldIndex,                                        const char* param, const char* option);
mvErrorEnum mvSetForceParametersi(mvIndex worldIndex, mvIndex index,                                  const char* param, mvIndex index);
mvErrorEnum mvSetCurrentForceParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetForceParametersf(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat num);
mvErrorEnum mvSetCurrentForceParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetForceParametersv(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentForceParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

//=============
//mvPathway
//No Of Functions : 115 = 5 + 16 + 16 (37) + 12 + 32 + 32 + 2
//=============

mvIndex mvAddPathway(mvIndex worldIndex, mvOptionEnum fType);
mvErrorEnum mvRemoveCurrentPathway(mvIndex worldIndex);
mvErrorEnum mvRemovePathway(mvIndex worldIndex, mvIndex index);
mvIndex mvSetCurrentPathway(mvIndex worldIndex, mvIndex index);
void mvRemoveAllPathways(mvIndex worldIndex);
mvIndex mvSetCurrentNodeForPathway(mvIndex worldIndex, mvIndex currentNode, mvIndex pathway);
mvIndex mvSetCurrentNodeForCurrentPathway(mvIndex worldIndex, mvIndex currentNode);

//GET
mvErrorEnum mvGetPathwayParameter(mvIndex worldIndex, mvIndex index,                                  mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetPathwayParameteri(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetPathwayParameterf(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetPathwayParameterv(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetPathwayParameters(mvIndex worldIndex, mvIndex index,                                   const char* param, const char* option);
mvErrorEnum mvGetCurrentPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvGetPathwayParametersi(mvIndex worldIndex, mvIndex* index,                                    const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetPathwayParametersf(mvIndex worldIndex, mvIndex index,                                    const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetPathwayParametersv(mvIndex worldIndex, mvIndex index,                                    const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);

//SET
mvErrorEnum mvSetPathwayParameter(mvIndex worldIndex, mvIndex index,                                  mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetPathwayParameteri(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetPathwayParameterf(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetPathwayParameterv(mvIndex worldIndex, mvIndex index,                                   mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetPathwayParameters(mvIndex worldIndex, mvIndex index,                                   const char* param, const char* option);
mvErrorEnum mvSetCurrentPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvSetPathwayParametersi(mvIndex worldIndex, mvIndex index,                                    const char* param, mvIndex index);
mvErrorEnum mvSetCurrentPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetPathwayParametersf(mvIndex worldIndex, mvIndex index,                                    const char* param, mvFloat num);
mvErrorEnum mvSetCurrentPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetPathwayParametersv(mvIndex worldIndex, mvIndex index,                                    const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

// add waypoints to paths

mvErrorEnum mvAssociateWaypointWithPathway(mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex);
mvErrorEnum mvAssociateCurrentWaypointWithPathway(mvIndex worldIndex,mvIndex pathwayIndex);
mvErrorEnum mvAssociateWaypointWithCurrentPathway(mvIndex worldIndex, mvIndex nodeIndex);
mvErrorEnum mvAssociateCurrentWaypointWithCurrentPathway(mvIndex worldIndex);

// last-in-first-out for duplicates

mvErrorEnum mvReleaseWaypointWithPathway(mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex);
mvErrorEnum mvReleaseCurrentWaypointWithPathway(mvIndex worldIndex,mvIndex pathwayIndex);
mvErrorEnum mvReleaseWaypointWithCurrentPathway(mvIndex worldIndex, mvIndex nodeIndex);
mvErrorEnum mvReleaseCurrentWaypointWithCurrentPathway(mvIndex worldIndex);

// removes waypoints to paths

mvErrorEnum mvReleaseNodeWithPathway(mvIndex worldIndex, mvIndex nodeIndex, mvIndex pathwayIndex);
mvErrorEnum mvReleaseCurrentNodeWithPathway(mvIndex worldIndex,mvIndex pathwayIndex);
mvErrorEnum mvReleaseNodeWithCurrentPathway(mvIndex worldIndex, mvIndex nodeIndex);
mvErrorEnum mvReleaseCurrentNodeWithCurrentPathway(mvIndex worldIndex);

// GET
mvErrorEnum mvGetNodeInPathwayParameter(mvIndex worldIndex, mvIndex index,                                        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentNodeInPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetNodeInPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentNodeInPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetNodeInPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentNodeInPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetNodeInPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentNodeInPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetNodeInPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvGetCurrentNodeInPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvGetNodeInPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentNodeInPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetNodeInPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentNodeInPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetNodeInPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentNodeInPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetNodeInCurrentPathwayParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetNodeInCurrentPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetNodeInCurrentPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetNodeInCurrentPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetNodeInCurrentPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvGetNodeInCurrentPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetNodeInCurrentPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetNodeInCurrentPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentNodeInCurrentPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);

// SET

mvErrorEnum mvSetNodeInPathwayParameter(mvIndex worldIndex, mvIndex index,                                        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentNodeInPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetNodeInPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentNodeInPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetNodeInPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentNodeInPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetNodeInPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentNodeInPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetNodeInPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvSetCurrentNodeInPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvSetNodeInPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
mvErrorEnum mvSetCurrentNodeInPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetNodeInPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
mvErrorEnum mvSetCurrentNodeInPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetNodeInPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentNodeInPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);
mvErrorEnum mvSetNodeInCurrentPathwayParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetNodeInCurrentPathwayParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetNodeInCurrentPathwayParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetNodeInCurrentPathwayParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetNodeInCurrentPathwayParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvSetNodeInCurrentPathwayParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetNodeInCurrentPathwayParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetNodeInCurrentPathwayParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentNodeInCurrentPathwayParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

//=============
//mvGroup
//No Of Functions : 51 = 8 + 5 + 16 + 16 + 2 + 4
//=============

/**mvAddGroup(mvIndex worldIndex);mvGetGroup(mvIndex worldIndex);
mvRemoveCurrentGroup(mvIndex worldIndex);mvRemoveGroup(mvIndex worldIndex);
mvSetCurrentGroup(mvIndex worldIndex);mvRemoveAllGroups(mvIndex worldIndex);
**/

// rearrange later
mvErrorEnum mvAddBodyToGroup(mvIndex worldIndex, mvIndex bodyIndex, mvIndex groupIndex);
mvErrorEnum mvAddCurrentBodyToGroup(mvIndex worldIndex, mvIndex groupIndex);
mvErrorEnum mvAddBodyToCurrentGroup(mvIndex worldIndex, mvIndex bodyIndex);
mvErrorEnum mvAddCurrentBodyToCurrentGroup(mvIndex worldIndex);
mvErrorEnum mvRemoveBodyFromGroup(mvIndex worldIndex, mvIndex bodyIndex, mvIndex groupIndex);
mvErrorEnum mvRemoveCurrentBodyFromGroup(mvIndex worldIndex, mvIndex groupIndex);
mvErrorEnum mvRemoveBodyFromCurrentGroup(mvIndex worldIndex, mvIndex bodyIndex);
mvErrorEnum mvRemoveCurrentBodyFromCurrentGroup(mvIndex worldIndex);
mvErrorEnum mvRemoveAllMembersFromGroup(mvIndex worldIndex, mvIndex groupIndex);
mvErrorEnum mvRemoveAllMembersFromCurrentGroup(mvIndex worldIndex);
mvIndex mvAddGroup(mvIndex worldIndex, mvOptionEnum fType);
mvErrorEnum mvRemoveCurrentGroup(mvIndex worldIndex);
mvErrorEnum mvRemoveGroup(mvIndex worldIndex, mvIndex index);mvIndex mvSetCurrentGroup(mvIndex worldIndex, mvIndex index);
void mvRemoveAllGroups(mvIndex worldIndex);

//GET
mvErrorEnum mvGetGroupParameter(mvIndex worldIndex, mvIndex index,                                mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentGroupParameter(mvIndex worldIndex,                                       mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetGroupParameteri(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentGroupParameteri(mvIndex worldIndex,                                        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetGroupParameterf(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentGroupParameterf(mvIndex worldIndex,                                        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetGroupParameterv(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentGroupParameterv(mvIndex worldIndex,                                        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetGroupParameters(mvIndex worldIndex, mvIndex index,                                 const char* param, const char* option);
mvErrorEnum mvGetCurrentGroupParameters(mvIndex worldIndex,                                        const char* param, const char* option);
mvErrorEnum mvGetGroupParametersi(mvIndex worldIndex, mvIndex index,                                  const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentGroupParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetGroupParametersf(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentGroupParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetGroupParametersv(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentGroupParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);

//SET
mvErrorEnum mvSetGroupParameter(mvIndex worldIndex, mvIndex index,                                mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentGroupParameter(mvIndex worldIndex,                                       mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetGroupParameteri(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentGroupParameteri(mvIndex worldIndex,                                        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetGroupParameterf(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentGroupParameterf(mvIndex worldIndex,                                        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetGroupParameterv(mvIndex worldIndex, mvIndex index,                                 mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentGroupParameterv(mvIndex worldIndex,                                        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetGroupParameters(mvIndex worldIndex, mvIndex index,                                 const char* param, const char* option);
mvErrorEnum mvSetCurrentGroupParameters(mvIndex worldIndex,                                        const char* param, const char* option);
mvErrorEnum mvSetGroupParametersi(mvIndex worldIndex, mvIndex index,                                  const char* param, mvIndex index);
mvErrorEnum mvSetCurrentGroupParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetGroupParametersf(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat num);
mvErrorEnum mvSetCurrentGroupParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetGroupParametersv(mvIndex worldIndex, mvIndex index,                                  const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentGroupParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

// GROUP SET OPERATIONS LATER
mvErrorEnum mvCombineGroups(mvIndex worldIndex, mvIndex groupA, mvIndex groupB, mvOptionEnum operation);
mvErrorEnum mvCombineGroupWithCurrentGroup(mvIndex worldIndex, mvIndex groupB, mvOptionEnum operation);
mvErrorEnum mvSetOperationOnGroup(mvIndex worldIndex, mvIndex groupIndex, mvOptionEnum operation);
mvErrorEnum mvSetOperationOnCurrentGroup(mvIndex worldIndex, mvOptionEnum operation);
//=============
//mvGroupBehaviour
//No Of Functions : 75 = 5 + 4 + 4 + 32 + 32
//=============

/*
mvAddGroupBehaviour(mvIndex worldIndex);mvRemoveGroupCurrentBehaviour(mvIndex worldIndex);
mvRemoveGroupBehaviour(mvIndex worldIndex);mvSetCurrentGroupBehaviour(mvIndex worldIndex);
mvRemoveAllGroupBehaviours(mvIndex worldIndex);mvInsertGroupIntoGroupBehaviour(mvIndex worldIndex);
mvInsertCurrentGroupIntoGroupBehaviour(mvIndex worldIndex);
mvInsertGroupIntoCurrentGroupBehaviour(mvIndex worldIndex);
mvInsertCurrentGroupIntoCurrentGroupBehaviour(mvIndex worldIndex);
mvSetGroupBehaviourParameter(mvIndex worldIndex);mvSetCurrentGroupBehaviourParameter(mvIndex worldIndex);
*/

mvIndex mvAddGroupBehaviour(mvIndex worldIndex, mvOptionEnum fType);
mvErrorEnum mvRemoveCurrentGroupBehaviour(mvIndex worldIndex);
mvErrorEnum mvRemoveGroupBehaviour(mvIndex worldIndex, mvIndex index);
mvIndex mvSetCurrentGroupBehaviour(mvIndex worldIndex, mvIndex index);
void mvRemoveAllGroupBehaviours(mvIndex worldIndex);
mvErrorEnum mvInsertGroupIntoGroupBehaviour(mvIndex worldIndex,mvIndex groupIndex);
mvErrorEnum mvInsertCurrentGroupIntoGroupBehaviour(mvIndex worldIndex,mvIndex groupBehaviour);
mvErrorEnum mvInsertGroupIntoCurrentGroupBehaviour(mvIndex worldIndex,mvIndex groupIndex);
mvErrorEnum mvInsertCurrentGroupIntoCurrentGroupBehaviour(mvIndex worldIndex);
mvErrorEnum mvRemoveGroupIntoGroupBehaviour(mvIndex worldIndex,mvIndex groupIndex);
mvErrorEnum mvRemoveCurrentGroupIntoGroupBehaviour(mvIndex worldIndex,mvIndex groupBehaviour);
mvErrorEnum mvRemoveGroupIntoCurrentGroupBehaviour(mvIndex worldIndex,mvIndex groupIndex);
mvErrorEnum mvRemoveCurrentGroupIntoCurrentGroupBehaviour(mvIndex worldIndex);

// GET

mvErrorEnum mvGetGroupBehaviourParameter(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentGroupBehaviourParameter(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetGroupBehaviourParameteri(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentGroupBehaviourParameteri(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetGroupBehaviourParameterf(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentGroupBehaviourParameterf(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetGroupBehaviourParameterv(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentGroupBehaviourParameterv(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetGroupBehaviourParameters(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, const char* option);
mvErrorEnum mvGetCurrentGroupBehaviourParameters(mvIndex worldIndex,mvIndex groupIndex,        const char* param, const char* option);
mvErrorEnum mvGetGroupBehaviourParametersi(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentGroupBehaviourParametersi(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetGroupBehaviourParametersf(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentGroupBehaviourParametersf(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetGroupBehaviourParametersv(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentGroupBehaviourParametersv(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetMainGroupBehaviourParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentMainGroupBehaviourParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetMainGroupBehaviourParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentMainGroupBehaviourParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetGroupMainBehaviourParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentMainGroupBehaviourParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetMainGroupBehaviourParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentMainGroupBehaviourParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetMainGroupBehaviourParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvGetCurrentMainGroupBehaviourParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvGetMainGroupBehaviourParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentMainGroupBehaviourParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetMainGroupBehaviourParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentMainGroupBehaviourParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetMainGroupBehaviourParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentMainGroupBehaviourParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);

// SET
mvErrorEnum mvSetGroupBehaviourParameter(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentGroupBehaviourParameter(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetGroupBehaviourParameteri(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentGroupBehaviourParameteri(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetGroupBehaviourParameterf(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentGroupBehaviourParameterf(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetGroupBehaviourParameterv(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentGroupBehaviourParameterv(mvIndex worldIndex,mvIndex groupIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetGroupBehaviourParameters(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, const char* option);
mvErrorEnum mvSetCurrentGroupBehaviourParameters(mvIndex worldIndex,mvIndex groupIndex,        const char* param, const char* option);
mvErrorEnum mvSetGroupBehaviourParametersi(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetCurrentGroupBehaviourParametersi(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetGroupBehaviourParametersf(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetCurrentGroupBehaviourParametersf(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetGroupBehaviourParametersv(mvIndex worldIndex, mvIndex gbIndex, mvIndex groupIndex,        const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentGroupBehaviourParametersv(mvIndex worldIndex,mvIndex groupIndex,        const char* param, mvFloat* array);
mvErrorEnum mvSetMainGroupBehaviourParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentMainGroupBehaviourParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetMainGroupBehaviourParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentMainGroupBehaviourParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetGroupMainBehaviourParametercf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentMainGroupBehaviourParametercf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetMainGroupBehaviourParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentMainGroupBehaviourParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetMainGroupBehaviourParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvSetCurrentMainGroupBehaviourParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvSetMainGroupBehaviourParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
mvErrorEnum mvSetCurrentMainGroupBehaviourParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetMainGroupBehaviourParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
mvErrorEnum mvSetCurrentMainGroupBehaviourParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetMainGroupBehaviourParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentMainGroupBehaviourParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

////  behaviour state functions
//  using current body
//  32 functions = 16 + 16
//
//GET

mvErrorEnum mvGetBehaviourEntryParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetCurrentBehaviourEntryParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum* option);
mvErrorEnum mvGetBehaviourEntryParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetCurrentBehaviourEntryParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex* index);
mvErrorEnum mvGetBehaviourEntryParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetCurrentBehaviourEntryParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat* num);
mvErrorEnum mvGetBehaviourEntryParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBehaviourEntryParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetBehaviourEntryParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvGetCurrentBehaviourEntryParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvGetBehaviourEntryParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex* index);
mvErrorEnum mvGetCurrentBehaviourEntryParametersi(mvIndex worldIndex,        const char* param, mvIndex* index);
mvErrorEnum mvGetBehaviourEntryParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* num);
mvErrorEnum mvGetCurrentBehaviourEntryParametersf(mvIndex worldIndex,        const char* param, mvFloat* num);
mvErrorEnum mvGetBehaviourEntryParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array, mvCount* noOfParameters);
mvErrorEnum mvGetCurrentBehaviourEntryParametersv(mvIndex worldIndex,        const char* param, mvFloat* array, mvCount* noOfParameters);

//SET
mvErrorEnum mvSetBehaviourEntryParameter(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetCurrentBehaviourEntryParameter(mvIndex worldIndex,        mvParamEnum param, mvOptionEnum option);
mvErrorEnum mvSetBehaviourEntryParameteri(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetCurrentBehaviourEntryParameteri(mvIndex worldIndex,        mvParamEnum param, mvIndex index);
mvErrorEnum mvSetBehaviourEntryParameterf(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetCurrentBehaviourEntryParameterf(mvIndex worldIndex,        mvParamEnum param, mvFloat num);
mvErrorEnum mvSetBehaviourEntryParameterv(mvIndex worldIndex, mvIndex index,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetCurrentBehaviourEntryParameterv(mvIndex worldIndex,        mvParamEnum param, mvFloat* array);
mvErrorEnum mvSetBehaviourEntryParameters(mvIndex worldIndex, mvIndex index,        const char* param, const char* option);
mvErrorEnum mvSetCurrentBehaviourEntryParameters(mvIndex worldIndex,        const char* param, const char* option);
mvErrorEnum mvSetBehaviourEntryParametersi(mvIndex worldIndex, mvIndex index,        const char* param, mvIndex index);
mvErrorEnum mvSetCurrentBehaviourEntryParametersi(mvIndex worldIndex,        const char* param, mvIndex index);
mvErrorEnum mvSetBehaviourEntryParametersf(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat num);
mvErrorEnum mvSetCurrentBehaviourEntryParametersf(mvIndex worldIndex,        const char* param, mvFloat num);
mvErrorEnum mvSetBehaviourEntryParametersv(mvIndex worldIndex, mvIndex index,        const char* param, mvFloat* array);
mvErrorEnum mvSetCurrentBehaviourEntryParametersv(mvIndex worldIndex,        const char* param, mvFloat* array);

#endif

