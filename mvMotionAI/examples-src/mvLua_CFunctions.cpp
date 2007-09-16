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
#define MV_LUA_GET_PARAM_MINIMUM_VALUS_RETURNED (2)

int mvLua_SetParameterFunction_2i(lua_State* luaVM,
   mvErrorEnum (setParameter_str)(mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*));

int mvLua_GetParameterFunction_2i(lua_State* luaVM, mvErrorEnum finalErrorCode,
   mvErrorEnum (getParameter_str)(mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, const char*, mvIndex*),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, const char*, mvFloat*),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*, mvCount*));

// TODO : complete template functions
int mvLua_SetParameterFunction_3i(lua_State* luaVM,
   mvErrorEnum (setParameter_str)(mvIndex, mvIndex, const char*, const char*),
   mvErrorEnum (setParameteri_str)(mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (setParameterf_str)(mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (setParameterv_str)(mvIndex, mvIndex, const char*, mvFloat*));

int mvLua_GetParameterFunction_3i(lua_State* luaVM, mvErrorEnum finalErrorCode,
   mvErrorEnum (getParameter_str)(mvIndex, mvIndex, mvIndex, const char*, const char**),
   mvErrorEnum (getParameteri_str)(mvIndex, mvIndex, mvIndex, const char*, mvIndex),
   mvErrorEnum (getParameterf_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat),
   mvErrorEnum (getParameterv_str)(mvIndex, mvIndex, mvIndex, const char*, mvFloat*, mvCount));

int mvLua_GetCurrentIndex(lua_State* luaVM,
   mvIndex (getCurrentIndex)(mvIndex));
int mvLua_SetCurrentIndex(lua_State* luaVM,
   mvIndex (setCurrentIndex)(mvIndex, mvIndex));
int mvLua_DeleteAllItems(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex));
int mvLua_DeleteAllNodesInItem(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex, mvIndex));
int mvLua_DeleteItem(lua_State* luaVM,
   mvErrorEnum (deleteItem)(mvIndex, mvIndex));

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
   /*
   mvLua_GetCurrentBody,
   mvLua_SetCurrentBody,
   mvLua_DeleteBody,
   mvLua_DeleteAllBodies,
   mvLua_SetBodyParameter,
   mvLua_GetBodyParameter,
   mvLua_AddBehaviourToList,
   mvLua_RemoveBehaviourFromList,
   mvLua_RemoveAllBehavioursFromList,
   */
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

// TODO : use template
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
   paramError = mvGetWorldParameter_str(worldIndex, paramString, &optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING)
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

   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   paramString = lua_tostring(luaVM, luaIndex);

   // SET PARAMETER
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   optionString = lua_tostring(luaVM, luaIndex);

   paramError = mvSetWorldParameter_str(worldIndex, paramString, optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING)
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
   mvErrorEnum (setParameter_str)(mvIndex, mvIndex, const char*, const char*),
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
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   paramString = lua_tostring(luaVM, luaIndex);

   // SET PARAMETER
   firstParamIndex = MV_LUA_WORLD_INDEX_VALUE + 3;
   luaIndex = firstParamIndex;
   optionString = lua_tostring(luaVM, luaIndex);

   paramError = setParameter_str(worldIndex, objectIndex, paramString,
      optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING)
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
   mvErrorEnum (getParameter_str)(mvIndex, mvIndex, const char*, const char**),
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
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   objectIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   // PARAM STRING
   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   paramString = lua_tostring(luaVM, luaIndex);

   // GET PARAMETER
   paramError = getParameter_str(worldIndex, objectIndex,
      paramString, &optionString);

   // early exit for invalid param
   if (paramError == MV_INVALID_PARAM_ENUM_STRING)
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

   objectIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   returnedIndex = setCurrentIndex(worldIndex,objectIndex);
   lua_pushnumber(luaVM, returnedIndex);
   return MV_LUA_DEFAULT_NO_OF_ITEMS_RETURNED;
}

int mvLua_DeleteAllItems(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex));
int mvLua_DeleteAllNodesInItem(lua_State* luaVM,
   mvErrorEnum (deleteAllItems)(mvIndex, mvIndex));
int mvLua_DeleteItem(lua_State* luaVM,
   mvErrorEnum (deleteItem)(mvIndex, mvIndex));

// TODO : block 3
int mvLua_CreateBody(lua_State* luaVM)
{
   mvIndex worldIndex, luaIndex, objectIndex;
   const char* typeString = NULL;
   const char* shapeString = NULL;
   mvFloat floatArray[MV_MAX_NO_OF_PARAMETERS];

   // WORLD INDEX
   luaIndex = MV_LUA_WORLD_INDEX_VALUE;
   worldIndex = (mvIndex) lua_tonumber(luaVM,luaIndex);

   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 1;
   typeString = lua_tostring(luaVM, luaIndex);

   luaIndex = MV_LUA_WORLD_INDEX_VALUE + 2;
   shapeString = lua_tostring(luaVM, luaIndex);

   for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; i++)
   {
      luaIndex = MV_LUA_WORLD_INDEX_VALUE + 3 + i;
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

int mvLua_DeleteBody(lua_State* luaVM);
int mvLua_DeleteAllBodies(lua_State* luaVM);
int mvLua_SetBodyParameter(lua_State* luaVM);
int mvLua_GetBodyParameter(lua_State* luaVM);
int mvLua_AddBehaviourToList(lua_State* luaVM);
int mvLua_RemoveBehaviourFromList(lua_State* luaVM);
int mvLua_RemoveAllBehavioursFromList(lua_State* luaVM);
