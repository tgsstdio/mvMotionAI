#include "mvLua_CFunctions.h"

/**
 * \brief internal constant - ignore
 */
static const mvCount MV_LUA_RETURNED_ERROR_COUNT = 1;
static const mvIndex MV_LUA_SET_CURRENT_ITEM_INDEX_NO = 2;
static const mvIndex MV_LUA_REMOVE_ITEM_INDEX_NO = 2;
static const mvIndex MV_LUA_WORLD_INDEX_VALUE = 1;
static const mvIndex MV_LUA_SET_PARAMETER_ITEM_INDEX = 2;
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX = 3;
static const mvIndex MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX = 4;
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_INDEX_NO = 4;
static const mvIndex MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX = 4;
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_PARAM_ENUM_INDEX = 2;
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX = 3;
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO = 3;
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX = 3;
static const mvCount MV_LUA_REMOVE_ALL_ITEMS_COUNT = 0;

lua_CFunction mvLua_LuaFunctionPointers[] =
{
   mvLua_InitMotionAI,
   mvLua_FreeMotionAI,
};

const char* mvLua_CFuncFunctionNames[] =
{
   //1
   "mvInitMotionAI",
   "mvFreeMotionAI",
   "mvAllWorldsStepForward",
   "mvIndex mvCreateWorld",
   "mvErrorEnum mvDeleteAllWorlds",
   "mvIndex mvSetCurrentWorld",
   "mvIndex mvGetCurrentWorld",
   "mvErrorEnum mvInitDefaultActions",
   "mvErrorEnum mvInitDefaultForces",
   "mvErrorEnum mvInitAllDefaults",
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
   return 0;
}

int mvLua_FreeMotionAI(lua_State* luaVM)
{
   mvFreeMotionAI();
   return 0;
}

/** @brief mvLua_GetEntryListParameter
  *
  * @todo: document this function
  */
int mvLua_GetEntryListParameter(lua_State* luaVM)
{
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvFloat timeInSecs = (mvFloat) lua_tonumber(L,MV_LUA_WORLDSTEP_TIMEINSECS_INDEX);
}


