#include "mvLua_CFunctions.h"

/**
 * \brief internal constant - ignore
 */
/*
static const mvCount MV_LUA_RETURNED_ERROR_COUNT = 1;
static const mvIndex MV_LUA_SET_CURRENT_ITEM_INDEX_NO = 2;
static const mvIndex MV_LUA_REMOVE_ITEM_INDEX_NO = 2;
static const mvIndex MV_LUA_SET_PARAMETER_ITEM_INDEX = 2;
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX = 3;
static const mvIndex MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX = 4;
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_INDEX_NO = 4;
#define MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX
*/
#define MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED (1)
#define MV_LUA_WORLD_INDEX_VALUE (1)
#define MV_LUA_REMOVE_ALL_ITEMS_NO_OF_ITEMS_RETURNED (1)
#define MV_LUA_VOID_NO_OF_ITEMS_RETURNED (0)
#define MV_LUA_MV_NULL_STRING "MV_NULL"
#define MV_LUA_DEFAULT_ERROR_ENUM MV_SCRIPT_MODULE_PARSING_ERROR

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
   mvFloat timeInSecs;

   // TIME IN SECS
   luaIndex = 1;
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   timeInSecs = (mvFloat) lua_tonumber(luaVM,\
      luaIndex);

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
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
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

// TODO : block 2
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
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
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
   mvErrorEnum error;

   // ERROR CODE
   luaIndex = 1;
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
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
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   option = (mvOptionEnum) lua_isnumber(luaVM, luaIndex);

   const char* optionString = mvGetOptionEnumString(option);
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
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   worldIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // TIME IN SECS
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
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
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   worldIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // BODY INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   bodyIndex = (mvIndex) lua_tonumber(luaVM,\
      luaIndex);

   // TIME IN SECS
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   if (!luaL_isnumber(luaVM, luaIndex))
   {
      // error exit
      lua_pushnumber(luaVM, MV_LUA_DEFAULT_ERROR_ENUM);
      return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
   }
   timeInSecs = (mvFloat) lua_tonumber(luaVM,\
      luaIndex);

   mvErrorEnum error = mvNudgeBody(worldIndex, bodyIndex, timeInSecs);
   lua_pushnumber(luaVM, error);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_GetWorldParameter(lua_State* luaVM);
int mvLua_SetWorldParameter(lua_State* luaVM);

// TODO : block 3

