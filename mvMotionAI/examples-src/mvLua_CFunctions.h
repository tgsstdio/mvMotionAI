#ifndef MVLUA_CFUNCTIONS_H_INCLUDED
#define MVLUA_CFUNCTIONS_H_INCLUDED
#include <mv/mvMotionAI.h>
#include <Lua.hpp>

lua_CFunction* mvLua_GetLuaFunctionPointers();
const char** mvLua_GetLuaFunctionNames();
mvCount mvLua_GetNoOfImplementedFunctions();

//1
int mvLua_InitMotionAI(lua_State* luaVM);
int mvLua_FreeMotionAI(lua_State* luaVM);
int mvLua_AllWorldsStepForward(lua_State* luaVM);
int mvLua_CreateWorld(lua_State* luaVM);
int mvLua_DeleteAllWorlds(lua_State* luaVM);
int mvLua_SetCurrentWorld(lua_State* luaVM);
int mvLua_GetCurrentWorld(lua_State* luaVM);
int mvLua_InitDefaultActions(lua_State* luaVM);
int mvLua_InitDefaultForces(lua_State* luaVM);
int mvLua_InitAllDefaults(lua_State* luaVM);

//2
int mvLua_FreeDefaultActions(lua_State* luaVM);
int mvLua_FreeDefaultForces(lua_State* luaVM);
int mvLua_FreeAllDefaults(lua_State* luaVM);
int mvLua_GetErrorEnumString(lua_State* luaVM);
int mvLua_GetParamEnumString(lua_State* luaVM);
int mvLua_GetOptionEnumString(lua_State* luaVM);
int mvLua_WorldStep(lua_State* luaVM);
int mvLua_NudgeBody(lua_State* luaVM);
int mvLua_GetWorldParameter(lua_State* luaVM);
int mvLua_SetWorldParameter(lua_State* luaVM);

//3
int mvLua_CreateBody(lua_State* luaVM);
int mvLua_GetCurrentBody(lua_State* luaVM);
int mvLua_SetCurrentBody(lua_State* luaVM);
int mvLua_DeleteBody(lua_State* luaVM);
int mvLua_DeleteAllBodies(lua_State* luaVM);
int mvLua_SetBodyParameter(lua_State* luaVM);
int mvLua_GetBodyParameter(lua_State* luaVM);
int mvLua_AddBehaviourToList(lua_State* luaVM);
int mvLua_RemoveBehaviourFromList(lua_State* luaVM);
int mvLua_RemoveAllBehavioursFromList(lua_State* luaVM);

//4
int mvLua_GetCurrentEntryFromList(lua_State* luaVM);
int mvLua_CreateObstacle(lua_State* luaVM);
int mvLua_GetCurrentObstacle(lua_State* luaVM);
int mvLua_SetCurrentObstacle(lua_State* luaVM);
int mvLua_DeleteObstacle(lua_State* luaVM);
int mvLua_DeleteAllObstacles(lua_State* luaVM);
int mvLua_SetObstacleParameter(lua_State* luaVM);
int mvLua_GetObstacleParameter(lua_State* luaVM);
int mvLua_CreateWaypoint(lua_State* luaVM);
int mvLua_GetCurrentWaypoint(lua_State* luaVM);

// 5
int mvLua_SetCurrentWaypoint(lua_State* luaVM);
int mvLua_DeleteWaypoint(lua_State* luaVM);
int mvLua_DeleteAllWaypoints(lua_State* luaVM);
int mvLua_SetWaypointParameter(lua_State* luaVM);
int mvLua_GetWaypointParameter(lua_State* luaVM);
int mvLua_AddForceIntoWaypoint(lua_State* luaVM);
int mvLua_RemoveForceFromWaypoint(lua_State* luaVM);
int mvLua_RemoveAllWaypointsFromForce(lua_State* luaVM);
int mvLua_RemoveAllForcesFromWaypoint(lua_State* luaVM);
int mvLua_CreateBehaviour(lua_State* luaVM);

// 6
int mvLua_GetCurrentBehaviour(lua_State* luaVM);
int mvLua_SetCurrentBehaviour(lua_State* luaVM);
int mvLua_DeleteBehaviour(lua_State* luaVM);
int mvLua_DeleteAllBehaviours(lua_State* luaVM);
int mvLua_SetBehaviourParameter(lua_State* luaVM);
int mvLua_GetBehaviourParameter(lua_State* luaVM);
int mvLua_CreateForce(lua_State* luaVM);
int mvLua_GetCurrentForce(lua_State* luaVM);
int mvLua_SetCurrentForce(lua_State* luaVM);
int mvLua_DeleteForce(lua_State* luaVM);

// 7
int mvLua_DeleteAllForces(lua_State* luaVM);
int mvLua_SetForceParameter(lua_State* luaVM);
int mvLua_GetForceParameter(lua_State* luaVM);
int mvLua_CreatePathway(lua_State* luaVM);
int mvLua_GetCurrentPathway(lua_State* luaVM);
int mvLua_SetCurrentPathway(lua_State* luaVM);
int mvLua_DeletePathway(lua_State* luaVM);
int mvLua_DeleteAllPathways(lua_State* luaVM);
int mvLua_SetPathwayParameter(lua_State* luaVM);
int mvLua_GetPathwayParameter(lua_State* luaVM);
int mvLua_AddNodeToPathway(lua_State* luaVM);

//8
int mvLua_RemoveNodeFromPathway(lua_State* luaVM);
int mvLua_RemoveAllNodesFromPathway(lua_State* luaVM);
int mvLua_GetCurrentNodeOfPathway(lua_State* luaVM);
int mvLua_RemovePathwayNodeAt(lua_State* luaVM);
int mvLua_SetPathwayNodeParameter(lua_State* luaVM);
int mvLua_GetPathwayNodeParameter(lua_State* luaVM);
int mvLua_CreateGroup(lua_State* luaVM);
int mvLua_GetCurrentGroup(lua_State* luaVM);
int mvLua_SetCurrentGroup(lua_State* luaVM);
int mvLua_DeleteGroup(lua_State* luaVM);

// 9
int mvLua_DeleteAllGroups(lua_State* luaVM);
int mvLua_SetGroupParameter(lua_State* luaVM);
int mvLua_GetGroupParameter(lua_State* luaVM);
int mvLua_AddMemberIntoGroup(lua_State* luaVM);
int mvLua_RemoveMemberFromGroup(lua_State* luaVM);
int mvLua_RemoveAllMembersFromGroup(lua_State* luaVM);
int mvLua_CreateGroupBehaviour(lua_State* luaVM);
int mvLua_GetCurrentGroupBehaviour(lua_State* luaVM);
int mvLua_SetCurrentGroupBehaviour(lua_State* luaVM);
int mvLua_DeleteGroupBehaviour(lua_State* luaVM);

//10
int mvLua_DeleteAllGroupBehaviours(lua_State* luaVM);
int mvLua_SetMainGroupBehaviourParameter(lua_State* luaVM);
int mvLua_GetMainGroupBehaviourParameter(lua_State* luaVM);
int mvLua_SetGroupBehaviourParameter(lua_State* luaVM);
int mvLua_GetGroupBehaviourParameter(lua_State* luaVM);
int mvLua_AddGroupIntoGroupBehaviour(lua_State* luaVM);
int mvLua_RemoveGroupFromGroupBehaviour(lua_State* luaVM);
int mvLua_SetEntryListNodeParameter(lua_State* luaVM);
int mvLua_GetEntryListNodeParameter(lua_State* luaVM);
int mvLua_SetEntryListParameter(lua_State* luaVM);

//11
int mvLua_GetEntryListParameter(lua_State* luaVM);
int mvLua_RemoveAllGroupsFromGroupBehaviour(lua_State* luaVM);
int mvLua_FindMemberInGroup(lua_State* luaVM);

#endif // MVLUA_CFUNCTIONS_H_INCLUDED
