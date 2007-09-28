#include "mvLua_CFunctions.h"

#define MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED (1)
#define MV_LUA_WORLD_INDEX_VALUE (1)
#define MV_LUA_REMOVE_ALL_ITEMS_NO_OF_ITEMS_RETURNED (1)
#define MV_LUA_VOID_NO_OF_ITEMS_RETURNED (0)
#define MV_LUA_MV_NULL_STRING "MV_NULL"
#define MV_LUA_DEFAULT_ERROR_ENUM MV_SCRIPT_MODULE_PARSING_ERROR
#define MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED (2)

int mvLua_SetParameterFunction_2i(lua_State* luaVM,
   mvErrorEnum (setParametero_str)(mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*));

int mvLua_GetParameterFunction_2i(lua_State* luaVM,
   mvErrorEnum (getParametero_str)(mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, const char*, mvIndex*),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, const char*, mvFloat*),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*, mvCount*));

int mvLua_GetCurrentIndex(lua_State* luaVM,
   mvIndex (getCurrentIndex)(mvIndex));
int mvLua_SetCurrentIndex(lua_State* luaVM,
   mvIndex (setCurrentIndex)(mvIndex, mvIndex));
int mvLua_DeleteAllItems(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex));
int mvLua_DeleteItem(lua_State* luaVM,
   mvErrorEnum (deleteItem)(mvIndex, mvIndex));
int mvLua_DeleteAllNodesInItem(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex, mvIndex));
int mvLua_DeleteNodeIndexInItem(lua_State* luaVM,
   mvErrorEnum (deleteAllNodesInItem)(mvIndex, mvIndex,mvIndex));
int mvLua_AddNodeIndexIntoItem(lua_State* luaVM,
   mvIndex (addNodeIndexIntoItem)(mvIndex, mvIndex, mvIndex));
int mvLua_GetCurrentNodeInItem(lua_State* luaVM,
   mvIndex (getCurrentNodeInItem)(mvIndex, mvIndex));

int mvLua_SetParameterFunction_3i(lua_State* luaVM,
   mvErrorEnum (setParametero_str)(mvIndex, mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*));

int mvLua_GetParameterFunction_3i(lua_State* luaVM,
   mvErrorEnum (getParametero_str)(mvIndex, mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, mvIndex, const char*, mvIndex*),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*, mvCount*));

int mvLua_AddAndCheckNodeIndexIntoItem(lua_State* luaVM,
   mvErrorEnum (addNodeIndexIntoItem)(mvIndex, mvIndex, mvIndex));

lua_CFunction mvLua_LuaFunctionPointers[] =
{
   //1
   mvLua_InitMotionAI,
   mvLua_FreeMotionAI,
   mvLua_AllWorldsStepForward,
   mvLua_CreateWorld,
   mvLua_DeleteAllWorlds,
   mvLua_SetCurrentWorld,
   mvLua_GetCurrentWorld,
   mvLua_InitDefaultActions,
   mvLua_InitDefaultForces,
   mvLua_InitAllDefaults,
   // 2
   mvLua_FreeDefaultActions,
   mvLua_FreeDefaultForces,
   mvLua_FreeAllDefaults,
   mvLua_GetErrorEnumString,
   mvLua_GetParamEnumString,
   mvLua_GetOptionEnumString,
   mvLua_WorldStep,
   mvLua_NudgeBody,
   mvLua_GetWorldParameter,
   mvLua_SetWorldParameter,
   //3
   mvLua_CreateBody,
   mvLua_GetCurrentBody,
   mvLua_SetCurrentBody,
   mvLua_DeleteBody,
   mvLua_DeleteAllBodies,
   mvLua_SetBodyParameter,
   mvLua_GetBodyParameter,
   mvLua_AddBehaviourToList,
   mvLua_RemoveBehaviourFromList,
   mvLua_RemoveAllBehavioursFromList,
   //4
   mvLua_GetCurrentEntryFromList,
   mvLua_CreateObstacle,
   mvLua_GetCurrentObstacle,
   mvLua_SetCurrentObstacle,
   mvLua_DeleteObstacle,
   mvLua_DeleteAllObstacles,
   mvLua_SetObstacleParameter,
   mvLua_GetObstacleParameter,
   mvLua_CreateWaypoint,
   mvLua_GetCurrentWaypoint,
// 5
   mvLua_SetCurrentWaypoint,
   mvLua_DeleteWaypoint,
   mvLua_DeleteAllWaypoints,
   mvLua_SetWaypointParameter,
   mvLua_GetWaypointParameter,
   mvLua_AddForceIntoWaypoint,
   mvLua_RemoveForceFromWaypoint,
   mvLua_RemoveAllWaypointsFromForce,
   mvLua_RemoveAllForcesFromWaypoint,
   mvLua_CreateBehaviour,
// 6
   mvLua_GetCurrentBehaviour,
   mvLua_SetCurrentBehaviour,
   mvLua_DeleteBehaviour,
   mvLua_DeleteAllBehaviours,
   mvLua_SetBehaviourParameter,
   mvLua_GetBehaviourParameter,
   mvLua_CreateForce,
   mvLua_GetCurrentForce,
   mvLua_SetCurrentForce,
   mvLua_DeleteForce,
// 7
   mvLua_DeleteAllForces,
   mvLua_SetForceParameter,
   mvLua_GetForceParameter,
   mvLua_CreatePathway,
   mvLua_GetCurrentPathway,
   mvLua_SetCurrentPathway,
   mvLua_DeletePathway,
   mvLua_DeleteAllPathways,
   mvLua_SetPathwayParameter,
   mvLua_GetPathwayParameter,
   mvLua_AddNodeToPathway,
//8
   mvLua_RemoveNodeFromPathway,
   mvLua_RemoveAllNodesFromPathway,
   mvLua_GetCurrentNodeOfPathway,
   mvLua_RemovePathwayNodeAt,
   mvLua_SetPathwayNodeParameter,
   mvLua_GetPathwayNodeParameter,
   mvLua_CreateGroup,
   mvLua_GetCurrentGroup,
   mvLua_SetCurrentGroup,
   mvLua_DeleteGroup,
// 9
   mvLua_DeleteAllGroups,
   mvLua_SetGroupParameter,
   mvLua_GetGroupParameter,
   mvLua_AddMemberIntoGroup,
   mvLua_RemoveMemberFromGroup,
   mvLua_RemoveAllMembersFromGroup,
   mvLua_CreateGroupBehaviour,
   mvLua_GetCurrentGroupBehaviour,
   mvLua_SetCurrentGroupBehaviour,
   mvLua_DeleteGroupBehaviour,
//10
   mvLua_DeleteAllGroupBehaviours,
   mvLua_SetMainGroupBehaviourParameter,
   mvLua_GetMainGroupBehaviourParameter,
   mvLua_SetGroupBehaviourParameter,
   mvLua_GetGroupBehaviourParameter,
   mvLua_AddGroupIntoGroupBehaviour,
   mvLua_RemoveGroupFromGroupBehaviour,
   mvLua_SetEntryListNodeParameter,
   mvLua_GetEntryListNodeParameter,
   mvLua_SetEntryListParameter,
   // 11
   mvLua_GetEntryListParameter,
   mvLua_RemoveAllGroupsFromGroupBehaviour,
   mvLua_FindMemberInGroup,
};

const char* mvLua_CFuncFunctionNames[] =
{
   //1
   "mvInitMotionAI",
   "mvFreeMotionAI",
   "mvAllWorldsStepForward",
   "mvCreateWorld",
   "mvDeleteAllWorlds",
   "mvSetCurrentWorld",
   "mvGetCurrentWorld",
   "mvInitDefaultActions",
   "mvInitDefaultForces",
   "mvInitAllDefaults",
   //2
   "mvFreeDefaultActions",
   "mvFreeDefaultForces",
   "mvFreeAllDefaults",
   "mvGetErrorEnumString",
   "mvGetParamEnumString",
   "mvGetOptionEnumString",
   "mvWorldStep",
   "mvNudgeBody",
   "mvGetWorldParameter",
   "mvSetWorldParameter",
   // 3
   "mvCreateBody",
   "mvGetCurrentBody",
   "mvSetCurrentBody",
   "mvDeleteBody",
   "mvDeleteAllBodies",
   "mvSetBodyParameter",
   "mvGetBodyParameter",
   "mvAddBehaviourToList",
   "mvRemoveBehaviourFromList",
   "mvRemoveAllBehavioursFromList",
   // 4
   "mvGetCurrentEntryFromList",
   "mvCreateObstacle",
   "mvGetCurrentObstacle",
   "mvSetCurrentObstacle",
   "mvDeleteObstacle",
   "mvDeleteAllObstacles",
   "mvSetObstacleParameter",
   "mvGetObstacleParameter",
   "mvCreateWaypoint",
   "mvGetCurrentWaypoint",
   // 5
   "mvSetCurrentWaypoint",
   "mvDeleteWaypoint",
   "mvDeleteAllWaypoints",
   "mvSetWaypointParameter",
   "mvGetWaypointParameter",
   "mvAddForceIntoWaypoint",
   "mvRemoveForceFromWaypoint",
   "mvRemoveAllWaypointsFromForce",
   "mvRemoveAllForcesFromWaypoint",
   "mvCreateBehaviour",
// 6
   "mvGetCurrentBehaviour",
   "mvSetCurrentBehaviour",
   "mvDeleteBehaviour",
   "mvDeleteAllBehaviours",
   "mvSetBehaviourParameter",
   "mvGetBehaviourParameter",
   "mvCreateForce",
   "mvGetCurrentForce",
   "mvSetCurrentForce",
   "mvDeleteForce",
// 7
   "mvSetForceParameter",
   "mvGetForceParameter",
   "mvCreatePathway",
   "mvGetCurrentPathway",
   "mvSetCurrentPathway",
   "mvDeletePathway",
   "mvDeleteAllPathways",
   "mvSetPathwayParameter",
   "mvGetPathwayParameter",
   "mvAddNodeToPathway",
//8
   "mvRemoveNodeFromPathway",
   "mvRemoveAllNodesFromPathway",
   "mvGetCurrentNodeOfPathway",
   "mvRemovePathwayNodeAt",
   "mvSetPathwayNodeParameter",
   "mvGetPathwayNodeParameter",
   "mvCreateGroup",
   "mvGetCurrentGroup",
   "mvSetCurrentGroup",
   "mvDeleteGroup",
// 9
   "mvDeleteAllGroups",
   "mvSetGroupParameter",
   "mvGetGroupParameter",
   "mvAddMemberIntoGroup",
   "mvRemoveMemberFromGroup",
   "mvRemoveAllMembersFromGroup",
   "mvCreateGroupBehaviour",
   "mvGetCurrentGroupBehaviour",
   "mvSetCurrentGroupBehaviour",
   "mvDeleteGroupBehaviour",
//10
   "mvDeleteAllGroupBehaviours",
   "mvSetMainGroupBehaviourParameter",
   "mvGetMainGroupBehaviourParameter",
   "mvSetGroupBehaviourParameter",
   "mvGetGroupBehaviourParameter",
   "mvAddGroupIntoGroupBehaviour",
   "mvRemoveGroupFromGroupBehaviour",
   "mvSetEntryListNodeParameter",
   "mvGetEntryListNodeParameter",
   "mvSetEntryListParameter",
// 11
   "mvGetEntryListParameter",
   "mvRemoveAllGroupsFromGroupBehaviour",
   "mvLua_FindMemberInGroup",
};

const char** mvLua_GetLuaFunctionNames()
{
   return &mvLua_CFuncFunctionNames[0];
}

lua_CFunction* mvLua_GetLuaFunctionPointers()
{
   return &mvLua_LuaFunctionPointers[0];
}

mvCount mvLua_GetNoOfImplementedFunctions()
{
   return sizeof(mvLua_LuaFunctionPointers)/sizeof(lua_CFunction);
}

int mvLua_InitMotionAI(lua_State* luaVM)
{
   mvInitMotionAI();
   return MV_LUA_VOID_NO_OF_ITEMS_RETURNED;
}

int mvLua_FreeMotionAI(lua_State* luaVM)
{
   mvFreeMotionAI();
   return MV_LUA_VOID_NO_OF_ITEMS_RETURNED;
}

/** @brief mvLua_GetEntryListParameter
  *
  * @todo: document this function
  */
int mvLua_AllWorldsStepForward(lua_State* luaVM)
{
   mvFloat timeInSecs = (mvFloat) lua_tonumber(luaVM,\
      1);

   mvErrorEnum error = mvAllWorldsStepForward(timeInSecs);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_CreateWorld(lua_State* luaVM)
{
   mvIndex worldIndex = mvCreateWorld();
   lua_pushnumber(luaVM, worldIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteAllWorlds(lua_State* luaVM)
{
   mvErrorEnum error = mvDeleteAllWorlds();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_SetCurrentWorld(lua_State* luaVM)
{
   mvIndex luaIndex;
   mvIndex worldIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   mvIndex correctIndex = mvSetCurrentWorld(worldIndex);
   lua_pushnumber(luaVM, correctIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentWorld(lua_State* luaVM)
{
   mvIndex worldIndex = mvGetCurrentWorld();
   lua_pushnumber(luaVM, worldIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_InitDefaultActions(lua_State* luaVM)
{
   mvErrorEnum error = mvInitDefaultActions();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_InitDefaultForces(lua_State* luaVM)
{
   mvErrorEnum error = mvInitDefaultForces();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_InitAllDefaults(lua_State* luaVM)
{
   mvErrorEnum error = mvInitAllDefaults();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_FreeDefaultActions(lua_State* luaVM)
{
   mvErrorEnum error = mvFreeDefaultActions();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_FreeDefaultForces(lua_State* luaVM)
{
   mvErrorEnum error = mvFreeDefaultForces();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_FreeAllDefaults(lua_State* luaVM)
{
   mvErrorEnum error = mvFreeAllDefaults();
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetErrorEnumString(lua_State* luaVM)
{
   mvIndex luaIndex;
   mvErrorEnum error;

   // ERROR CODE
   luaIndex = 1;
   error = (mvErrorEnum) lua_isnumber(luaVM, luaIndex);

   const char* errorString = mvGetErrorEnumString(error);
   if (errorString == MV_NULL)
   {
      errorString = MV_LUA_MV_NULL_STRING;
   }
   lua_pushstring(luaVM, errorString);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetParamEnumString(lua_State* luaVM)
{
   mvParamEnum param;

   // ERROR CODE
   mvIndex luaIndex = 1;
   param = (mvParamEnum) lua_isnumber(luaVM, luaIndex);

   const char* paramString = mvGetParamEnumString(param);
   if (paramString == MV_NULL)
   {
      paramString = MV_LUA_MV_NULL_STRING;
   }
   lua_pushstring(luaVM, paramString);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetOptionEnumString(lua_State* luaVM)
{
   const char* optionString = MV_NULL;
   mvOptionEnum option;
   mvIndex luaIndex;

   luaIndex = 1;
   option = (mvOptionEnum) lua_isnumber(luaVM, luaIndex);

   optionString = mvGetOptionEnumString(option);
   if (optionString == MV_NULL)
   {
      optionString = MV_LUA_MV_NULL_STRING;
   }
   lua_pushstring(luaVM, optionString);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_WorldStep(lua_State* luaVM)
{
   mvFloat timeInSecs;
   mvIndex luaIndex;
   mvIndex worldIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // TIME IN SECS
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   timeInSecs = (mvFloat) lua_tonumber(luaVM,\
      luaIndex);

   mvErrorEnum error = mvWorldStep(worldIndex, timeInSecs);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_NudgeBody(lua_State* luaVM)
{
   mvFloat timeInSecs;
   mvIndex luaIndex;
   mvIndex worldIndex, bodyIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // BODY INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   bodyIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // TIME IN SECS
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   timeInSecs = (mvFloat) lua_tonumber(luaVM,\
      luaIndex);

   mvErrorEnum error = mvNudgeBody(worldIndex, bodyIndex, timeInSecs);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetWorldParameter(lua_State* luaVM)
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatOutput;
   mvCount noOfVariables;
   mvIndex indexOutput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   paramString = lua_tostring(luaVM, luaIndex);

   // GET PARAMETER
   paramError = mvGetWorldParametero_str(worldIndex, paramString, &optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return 2;
   }

   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushstring(luaVM, optionString);
      return 3;
   }

   // GET PARAMETER I
   paramError = mvGetWorldParameteri_str(worldIndex, paramString, &indexOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return 3;
   }

   // GET PARAMETER F

   paramError = mvGetWorldParameterf_str(worldIndex, paramString, &floatOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return 3;
   }

   // GET PARAMETER V

   paramError = mvGetWorldParameterv_str(worldIndex, paramString,\
      &floatArray[0],&noOfVariables);

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      for (mvCount i = 0; i < noOfVariables; ++i)
      {
         lua_pushnumber(luaVM, floatArray[i]);
      }

      return 2 + noOfVariables;
   }
   else
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return 2;
   }
}

int mvLua_SetWorldParameter(lua_State* luaVM)
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatInput;
   mvIndex indexInput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   paramString = lua_tostring(luaVM, luaIndex);

   // SET PARAMETER
   ++luaIndex;
   optionString = lua_tostring(luaVM, luaIndex);

   paramError = mvSetWorldParametero_str(worldIndex, paramString, optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER I
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   indexInput = (mvIndex) lua_tonumber(luaVM,luaIndex);

   paramError = mvSetWorldParameteri_str(worldIndex, paramString, indexInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER F
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   floatInput = (mvFloat) lua_tonumber(luaVM,luaIndex);

   paramError = mvSetWorldParameterf_str(worldIndex, paramString, floatInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER V
   for (mvIndex i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
   {
      luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2 + i;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM,luaIndex);
   }

   paramError = mvSetWorldParameterv_str(worldIndex, paramString,\
      &floatArray[0]);

   lua_pushnumber(luaVM, paramError);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_SetParameterFunction_2i(lua_State* luaVM,
   mvErrorEnum (setParametero_str)(mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*))
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex, objectIndex, firstParamIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatInput;
   mvIndex indexInput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // OBJECT INDEX
   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   paramString = lua_tostring(luaVM, luaIndex);

   // SET PARAMETER
   firstParamIndex = ++luaIndex;
   luaIndex = firstParamIndex;
   optionString = lua_tostring(luaVM, luaIndex);

   paramError = setParametero_str(worldIndex, objectIndex, paramString,
      optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER I
   luaIndex = firstParamIndex;
   indexInput = (mvIndex) lua_tonumber(luaVM,luaIndex);

   paramError = setParameteri_str(worldIndex, objectIndex,
      paramString, indexInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER F
   luaIndex = firstParamIndex;
   floatInput = (mvFloat) lua_tonumber(luaVM,luaIndex);

   paramError = setParameterf_str(worldIndex, objectIndex,
      paramString, floatInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER V
   for (mvIndex i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
   {
      luaIndex = firstParamIndex + i;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM,luaIndex);
   }

   paramError = setParameterv_str(worldIndex, objectIndex, paramString,\
      &floatArray[0]);

   lua_pushnumber(luaVM, paramError);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetParameterFunction_2i(lua_State* luaVM,
   mvErrorEnum (getParametero_str)(mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, const char*, mvIndex*),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, const char*, mvFloat*),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*, mvCount*))
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatOutput;
   mvCount noOfVariables;
   mvIndex indexOutput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // OBJECT INDEX
   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // PARAM STRING
   ++luaIndex;
   paramString = lua_tostring(luaVM, luaIndex);

   // GET PARAMETER
   paramError = getParametero_str(worldIndex, objectIndex,
      paramString, &optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushstring(luaVM, optionString);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER I
   paramError = getParameteri_str(worldIndex, objectIndex, paramString,\
      &indexOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER F

   paramError = getParameterf_str(worldIndex, objectIndex, paramString,\
      &floatOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER V

   paramError = getParameterv_str(worldIndex, objectIndex, paramString,\
      &floatArray[0],&noOfVariables);

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      for (mvCount i = 0; i < noOfVariables; ++i)
      {
         lua_pushnumber(luaVM, floatArray[i]);
      }

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }
   else
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }
}

int mvLua_SetParameterFunction_3i(lua_State* luaVM,
   mvErrorEnum (setParametero_str)(mvIndex, mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*))
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex, objectIndex, nodeIndex, firstParamIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatInput;
   mvIndex indexInput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // OBJECT INDEX
   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   nodeIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   paramString = lua_tostring(luaVM, luaIndex);

   // SET PARAMETER
   firstParamIndex = ++luaIndex;
   luaIndex = firstParamIndex;
   optionString = lua_tostring(luaVM, luaIndex);

   paramError = setParametero_str(worldIndex, objectIndex, nodeIndex,\
      paramString,  optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER I
   luaIndex = firstParamIndex;
   indexInput = (mvIndex) lua_tonumber(luaVM,luaIndex);

   paramError = setParameteri_str(worldIndex, objectIndex, nodeIndex,\
      paramString, indexInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER F
   luaIndex = firstParamIndex;
   floatInput = (mvFloat) lua_tonumber(luaVM,luaIndex);

   paramError = setParameterf_str(worldIndex, objectIndex, nodeIndex,
      paramString, floatInput);
   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }

   // SET PARAMETER V
   for (mvIndex i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
   {
      luaIndex = firstParamIndex + i;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM,luaIndex);
   }

   paramError = setParameterv_str(worldIndex, objectIndex, nodeIndex,\
      paramString, &floatArray[0]);

   lua_pushnumber(luaVM, paramError);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetParameterFunction_3i(lua_State* luaVM,
   mvErrorEnum (getParametero_str)(mvIndex, mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, mvIndex, const char*, mvIndex*),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*, mvCount*))
{
   mvErrorEnum paramError;
   mvIndex worldIndex, luaIndex, objectIndex, nodeIndex;
   const char* paramString = NULL;
   const char* optionString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS], floatOutput;
   mvCount noOfVariables;
   mvIndex indexOutput;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // OBJECT INDEX
   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // NODE INDEX
   ++luaIndex;
   nodeIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // PARAM STRING
   ++luaIndex;
   paramString = lua_tostring(luaVM, luaIndex);

   // GET PARAMETER
   paramError = getParametero_str(worldIndex, objectIndex,nodeIndex,\
      paramString, &optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING || paramError ==
      MV_MOTIONAI_IS_NOT_INITIALISED)
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushstring(luaVM, optionString);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER I
   paramError = getParameteri_str(worldIndex, objectIndex,nodeIndex,\
      paramString, &indexOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER F

   paramError = getParameterf_str(worldIndex, objectIndex,nodeIndex,\
      paramString, &floatOutput);
   if (paramError == MV_NO_ERROR)
   {
      noOfVariables = 1;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      lua_pushnumber(luaVM, indexOutput);
      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }

   // GET PARAMETER V

   paramError = getParameterv_str(worldIndex, objectIndex,nodeIndex,\
      paramString, &floatArray[0],&noOfVariables);

   if (paramError == MV_NO_ERROR)
   {
      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      // push option enum string to window
      for (mvCount i = 0; i < noOfVariables; ++i)
      {
         lua_pushnumber(luaVM, floatArray[i]);
      }

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }
   else
   {
      noOfVariables = 0;

      lua_pushnumber(luaVM, paramError);
      lua_pushnumber(luaVM, noOfVariables);

      return MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED + noOfVariables;
   }
}

int mvLua_GetCurrentIndex(lua_State* luaVM,
   mvIndex (getCurrentIndex)(mvIndex))
{
   mvIndex worldIndex, luaIndex, objectIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   objectIndex = getCurrentIndex(worldIndex);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_SetCurrentIndex(lua_State* luaVM,
   mvIndex (setCurrentIndex)(mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, objectIndex, returnedIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   returnedIndex = setCurrentIndex(worldIndex,objectIndex);
   lua_pushnumber(luaVM, returnedIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteItem(lua_State* luaVM,
   mvErrorEnum (deleteItem)(mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, objectIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   error = deleteItem(worldIndex,objectIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteAllItems(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex))
{
   mvIndex worldIndex, luaIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   error = deleteAllItems(worldIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteAllNodesInItem(lua_State* luaVM,
   mvErrorEnum (deleteAllNodesInItem)(mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, objectIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   error = deleteAllNodesInItem(worldIndex,objectIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteNodeIndexInItem(lua_State* luaVM,
   mvErrorEnum (deleteNodeFromSubject)(mvIndex, mvIndex,mvIndex))
{
   mvIndex worldIndex, luaIndex, subjectIndex, objectIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   subjectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   error = deleteNodeFromSubject(worldIndex, objectIndex, subjectIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentNodeInItem(lua_State* luaVM,
   mvIndex (getCurrentNodeInItem)(mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, objectIndex, nodeIndex;

   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   nodeIndex = getCurrentNodeInItem(worldIndex, objectIndex);
   lua_pushnumber(luaVM, nodeIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_AddAndCheckNodeIndexIntoItem(lua_State* luaVM,
   mvErrorEnum (addNodeIndexIntoItem)(mvIndex, mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, nodeIndex, itemIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   nodeIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   itemIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   error = addNodeIndexIntoItem(worldIndex,nodeIndex,itemIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_AddNodeIndexIntoItem(lua_State* luaVM,
   mvIndex (addNodeIndexIntoItem)(mvIndex, mvIndex, mvIndex))
{
   mvIndex worldIndex, luaIndex, nodeIndex, itemIndex, returnedIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   nodeIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   itemIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   returnedIndex = addNodeIndexIntoItem(worldIndex,nodeIndex,itemIndex);
   lua_pushnumber(luaVM, returnedIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_CreateBody(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* typeString = NULL;
   const char* shapeString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS];

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   typeString = lua_tostring(luaVM, luaIndex);

   ++luaIndex;
   shapeString = lua_tostring(luaVM, luaIndex);

   for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; i++)
   {
      ++luaIndex;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM, luaIndex);
   }

   objectIndex = mvCreateBody_str(worldIndex,typeString, shapeString,\
      floatArray[0], floatArray[1], floatArray[2]);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentBody(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM,mvGetCurrentBody);
}

int mvLua_SetCurrentBody(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM,mvSetCurrentBody);
}

int mvLua_DeleteBody(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteBody);
}

int mvLua_DeleteAllBodies(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllBodies);
}

int mvLua_SetBodyParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,
      mvSetBodyParametero_str, mvSetBodyParameteri_str, mvSetBodyParameterf_str,
      mvSetBodyParameterv_str);
}

int mvLua_GetBodyParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM, mvGetBodyParametero_str,
      mvGetBodyParameteri_str, mvGetBodyParameterf_str,\
      mvGetBodyParameterv_str);
}

int mvLua_AddBehaviourToList(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, listIndex, behaviourIndex, groupIndex,\
      entryIndex;
   const char* bTypeString = MV_NULL;

   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   listIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   bTypeString = lua_tostring(luaVM, luaIndex);

   ++luaIndex;
   behaviourIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   groupIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   entryIndex = mvAddBehaviourToList_str(worldIndex,listIndex,bTypeString,
      behaviourIndex, groupIndex);
   lua_pushnumber(luaVM, entryIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_RemoveBehaviourFromList(lua_State* luaVM)
{
   return mvLua_DeleteNodeIndexInItem(luaVM, mvRemoveBehaviourFromList);
}

int mvLua_RemoveAllBehavioursFromList(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllBehavioursFromList);
}

int mvLua_GetCurrentEntryFromList(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, listIndex, entryIndex;

   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   listIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   entryIndex = mvGetCurrentEntryFromList(worldIndex, listIndex);
   lua_pushnumber(luaVM, entryIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_CreateObstacle(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* typeString = NULL;
   const char* stateString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS];

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   typeString = lua_tostring(luaVM, luaIndex);

   ++luaIndex;
   stateString = lua_tostring(luaVM, luaIndex);

   for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; i++)
   {
      ++luaIndex;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM, luaIndex);
   }

   objectIndex = mvCreateObstacle_str(worldIndex,typeString, stateString,\
      floatArray[0], floatArray[1], floatArray[2]);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentObstacle(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentObstacle);
}

int mvLua_SetCurrentObstacle(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentObstacle);
}

int mvLua_DeleteObstacle(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteObstacle);
}

int mvLua_DeleteAllObstacles(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllObstacles);
}

int mvLua_SetObstacleParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,
      mvSetObstacleParametero_str,  mvSetObstacleParameteri_str,\
      mvSetObstacleParameterf_str,  mvSetObstacleParameterv_str);
}

int mvLua_GetObstacleParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,
      mvGetObstacleParametero_str,  mvGetObstacleParameteri_str,\
      mvGetObstacleParameterf_str,  mvGetObstacleParameterv_str);
}

int mvLua_CreateWaypoint(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* shapeString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS];

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   shapeString = lua_tostring(luaVM, luaIndex);

   for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; i++)
   {
      ++luaIndex;
      floatArray[i] = (mvFloat) lua_tonumber(luaVM, luaIndex);
   }

   objectIndex = mvCreateWaypoint_str(worldIndex,shapeString,\
      floatArray[0], floatArray[1], floatArray[2]);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentWaypoint(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentWaypoint);
}

int mvLua_SetCurrentWaypoint(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentWaypoint);
}

int mvLua_DeleteWaypoint(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteWaypoint);
}

int mvLua_DeleteAllWaypoints(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllWaypoints);
}

int mvLua_SetWaypointParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,\
      mvSetWaypointParametero_str, mvSetWaypointParameteri_str,\
      mvSetWaypointParameterf_str,mvSetWaypointParameterv_str);
}

int mvLua_GetWaypointParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,\
      mvGetWaypointParametero_str, mvGetWaypointParameteri_str,\
      mvGetWaypointParameterf_str,mvGetWaypointParameterv_str);
}

int mvLua_AddForceIntoWaypoint(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, forceIndex, waypointIndex;
   mvErrorEnum error;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   forceIndex = (mvIndex) lua_tonumber(luaVM, luaIndex);

   ++luaIndex;
   waypointIndex = (mvIndex) lua_tonumber(luaVM, luaIndex);

   error = mvAddForceIntoWaypoint(worldIndex, forceIndex, waypointIndex);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_RemoveForceFromWaypoint(lua_State* luaVM)
{
   return mvLua_DeleteNodeIndexInItem(luaVM, mvRemoveForceFromWaypoint);
}

int mvLua_RemoveAllWaypointsFromForce(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllWaypointsFromForce);
}

int mvLua_RemoveAllForcesFromWaypoint(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllForcesFromWaypoint);
}

int mvLua_CreateBehaviour(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* bTypeString = NULL;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   bTypeString = lua_tostring(luaVM, luaIndex);

   objectIndex = mvCreateBehaviour_str(worldIndex,bTypeString);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentBehaviour(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentBehaviour);
}

int mvLua_SetCurrentBehaviour(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentBehaviour);
}

int mvLua_DeleteBehaviour(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteBehaviour);
}

int mvLua_DeleteAllBehaviours(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllBehaviours);
}

int mvLua_SetBehaviourParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,\
      mvSetBehaviourParametero_str,  mvSetBehaviourParameteri_str,\
      mvSetBehaviourParameterf_str,  mvSetBehaviourParameterv_str);
}

int mvLua_GetBehaviourParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,\
      mvGetBehaviourParametero_str,  mvGetBehaviourParameteri_str,\
      mvGetBehaviourParameterf_str,  mvGetBehaviourParameterv_str);
}

int mvLua_CreateForce(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* fTypeString = NULL;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   fTypeString = lua_tostring(luaVM, luaIndex);

   objectIndex = mvCreateForce_str(worldIndex, fTypeString);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentForce(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentForce);
}

int mvLua_SetCurrentForce(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentForce);
}

int mvLua_DeleteForce(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteForce);
}

// 7
int mvLua_DeleteAllForces(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllForces);
}

int mvLua_SetForceParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,\
      mvSetForceParametero_str,  mvSetForceParameteri_str,\
      mvSetForceParameterf_str,  mvSetForceParameterv_str);
}

int mvLua_GetForceParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,\
      mvGetForceParametero_str,  mvGetForceParameteri_str,\
      mvGetForceParameterf_str,  mvGetForceParameterv_str);
}

int mvLua_CreatePathway(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   objectIndex =  mvCreatePathway(worldIndex);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentPathway(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentPathway);
}

int mvLua_SetCurrentPathway(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentPathway);
}

int mvLua_DeletePathway(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeletePathway);
}

int mvLua_DeleteAllPathways(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllPathways);
}

int mvLua_SetPathwayParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,\
      mvSetPathwayParametero_str,  mvSetPathwayParameteri_str,\
      mvSetPathwayParameterf_str,  mvSetPathwayParameterv_str);
}

int mvLua_GetPathwayParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,\
      mvGetPathwayParametero_str, mvGetPathwayParameteri_str,\
      mvGetPathwayParameterf_str, mvGetPathwayParameterv_str);
}

int mvLua_AddNodeToPathway(lua_State* luaVM)
{
   return mvLua_AddNodeIndexIntoItem(luaVM, mvAddNodeToPathway);
}

int mvLua_RemoveNodeFromPathway(lua_State* luaVM)
{
   return mvLua_DeleteNodeIndexInItem(luaVM, mvRemoveNodeFromPathway);
}

int mvLua_RemoveAllNodesFromPathway(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllNodesFromPathway);
}

int mvLua_GetCurrentNodeOfPathway(lua_State* luaVM)
{
   return mvLua_GetCurrentNodeInItem(luaVM, mvGetCurrentNodeOfPathway);
}

int mvLua_RemovePathwayNodeAt(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, nodeIndex, pathwayIndex, returnedIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   pathwayIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   nodeIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   returnedIndex = mvRemovePathwayNodeAt(worldIndex,pathwayIndex, nodeIndex);
   lua_pushnumber(luaVM, returnedIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_SetPathwayNodeParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_3i(luaVM,
      mvSetPathwayNodeParametero_str,mvSetPathwayNodeParameteri_str,
      mvSetPathwayNodeParameterf_str,mvSetPathwayNodeParameterv_str);
}

int mvLua_GetPathwayNodeParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_3i(luaVM,
      mvGetPathwayNodeParametero_str,mvGetPathwayNodeParameteri_str,
      mvGetPathwayNodeParameterf_str,mvGetPathwayNodeParameterv_str);
}

int mvLua_CreateGroup(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   objectIndex = mvCreateGroup(worldIndex);
   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentGroup(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentGroup);
}

int mvLua_SetCurrentGroup(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentGroup);
}

int mvLua_DeleteGroup(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteGroup);
}

int mvLua_DeleteAllGroups(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllGroups);
}

int mvLua_SetGroupParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM, mvSetGroupParametero_str,
      mvSetGroupParameteri_str, mvSetGroupParameterf_str,
      mvSetGroupParameterv_str);
}

int mvLua_GetGroupParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM, mvGetGroupParametero_str,
      mvGetGroupParameteri_str, mvGetGroupParameterf_str,
      mvGetGroupParameterv_str);
}

int mvLua_AddMemberIntoGroup(lua_State* luaVM)
{
   return mvLua_AddAndCheckNodeIndexIntoItem(luaVM, mvAddMemberIntoGroup);
}

int mvLua_RemoveMemberFromGroup(lua_State* luaVM)
{
   return mvLua_DeleteNodeIndexInItem(luaVM, mvRemoveMemberFromGroup);
}

int mvLua_RemoveAllMembersFromGroup(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllMembersFromGroup);
}

int mvLua_CreateGroupBehaviour(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   const char* bTypeString = lua_tostring(luaVM, luaIndex);
   objectIndex = mvCreateGroupBehaviour_str(worldIndex, bTypeString);

   lua_pushnumber(luaVM, objectIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetCurrentGroupBehaviour(lua_State* luaVM)
{
   return mvLua_GetCurrentIndex(luaVM, mvGetCurrentGroupBehaviour);
}

int mvLua_SetCurrentGroupBehaviour(lua_State* luaVM)
{
   return mvLua_SetCurrentIndex(luaVM, mvSetCurrentGroupBehaviour);
}

int mvLua_DeleteGroupBehaviour(lua_State* luaVM)
{
   return mvLua_DeleteItem(luaVM, mvDeleteGroupBehaviour);
}

//10
int mvLua_DeleteAllGroupBehaviours(lua_State* luaVM)
{
   return mvLua_DeleteAllItems(luaVM, mvDeleteAllGroupBehaviours);
}

int mvLua_SetMainGroupBehaviourParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,
      mvSetMainGroupBehaviourParametero_str,
      mvSetMainGroupBehaviourParameteri_str,
      mvSetMainGroupBehaviourParameterf_str,
      mvSetMainGroupBehaviourParameterv_str);
}

int mvLua_GetMainGroupBehaviourParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,
      mvGetMainGroupBehaviourParametero_str,
      mvGetMainGroupBehaviourParameteri_str,
      mvGetMainGroupBehaviourParameterf_str,
      mvGetMainGroupBehaviourParameterv_str);
}

int mvLua_SetGroupBehaviourParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_3i(luaVM,
      mvSetGroupBehaviourParametero_str,
      mvSetGroupBehaviourParameteri_str,
      mvSetGroupBehaviourParameterf_str,
      mvSetGroupBehaviourParameterv_str);
}

int mvLua_GetGroupBehaviourParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_3i(luaVM,
      mvGetGroupBehaviourParametero_str,
      mvGetGroupBehaviourParameteri_str,
      mvGetGroupBehaviourParameterf_str,
      mvGetGroupBehaviourParameterv_str);
}

int mvLua_AddGroupIntoGroupBehaviour(lua_State* luaVM)
{
   return mvLua_AddAndCheckNodeIndexIntoItem(luaVM,\
      mvAddGroupIntoGroupBehaviour);
}

int mvLua_RemoveGroupFromGroupBehaviour(lua_State* luaVM)
{
   return mvLua_DeleteNodeIndexInItem(luaVM, mvRemoveGroupFromGroupBehaviour);
}

int mvLua_SetEntryListNodeParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_3i(luaVM,
      mvSetEntryListNodeParametero_str,
      mvSetEntryListNodeParameteri_str,
      mvSetEntryListNodeParameterf_str,
      mvSetEntryListNodeParameterv_str);
}

int mvLua_GetEntryListNodeParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_3i(luaVM,
      mvGetEntryListNodeParametero_str,
      mvGetEntryListNodeParameteri_str,
      mvGetEntryListNodeParameterf_str,
      mvGetEntryListNodeParameterv_str);
}

int mvLua_SetEntryListParameter(lua_State* luaVM)
{
   return mvLua_SetParameterFunction_2i(luaVM,
      mvSetEntryListParametero_str,
      mvSetEntryListParameteri_str,
      mvSetEntryListParameterf_str,
      mvSetEntryListParameterv_str);
}

int mvLua_GetEntryListParameter(lua_State* luaVM)
{
   return mvLua_GetParameterFunction_2i(luaVM,
      mvGetEntryListParametero_str,
      mvGetEntryListParameteri_str,
      mvGetEntryListParameterf_str,
      mvGetEntryListParameterv_str);
}

int mvLua_RemoveAllGroupsFromGroupBehaviour(lua_State* luaVM)
{
   return mvLua_DeleteAllNodesInItem(luaVM, mvRemoveAllGroupsFromGroupBehaviour);
}

int mvLua_FindMemberInGroup(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, groupIndex, memberIndex, returnValue;

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   groupIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   ++luaIndex;
   memberIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   returnValue = mvFindMemberInGroup(worldIndex, groupIndex, memberIndex);

   lua_pushnumber(luaVM, returnValue);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}
