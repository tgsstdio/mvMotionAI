#include "mv2.h"

// mvMotionAI functions
MV_GLOBAL_FUNC_PREFIX void mvInitMotionAI()
{
   mvMotionAI_INIT();
}

MV_GLOBAL_FUNC_PREFIX void mvFreeMotionAI()
{
   mvMotionAI_FREE();
}

MV_GLOBAL_FUNC_PREFIX void mvRemoveAllWorlds()
{
   mvMotionAI_DELETEALLWORLDS();
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(const char* id)
{
   return mvMotionAI_CREATEWORLD(id);
}

MV_GLOBAL_FUNC_PREFIX mvWorld* mvGetWorldPtrByID(const char* worldID)
{
   return mvMotionAI_GETWORLDPTRBYID(worldID);
}

MV_GLOBAL_FUNC_PREFIX mvWorld* mvGetWorldPtr(mvIndex index)
{
   return mvMotionAI_GETWORLDPTR(index);
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetWorldByID(const char* worldID)
{
   return mvMotionAI_GETWORLDBYID(worldID);
}

MV_GLOBAL_FUNC_PREFIX void mvAllWorldsStepForward(mvFloat timeInSecs)
{
   mvMotionAI_ALLWORLDSSTEPFORWARD(timeInSecs);
}

MV_GLOBAL_FUNC_PREFIX void mvApplyToAllWorlds(\
   void (someFunction)(mvWorld*,void*),void* extraPtr)
{
   mvMotionAI_APPLYTOALLWORLDS(someFunction,extraPtr);
}

#ifdef MV_ENABLE_LUA_SCRIPTING_FLAG

/**
 * \brief loads lua script inside C type string
 * \param[in] statement Constant C String containing lua script
 * (terminated with NULL or '\\0')
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero)
 * and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses the script string pointed by statement
 *
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFromCString(\
   const char* statement)
{
   lua_State *L = NULL;
   int luaError;

   if (statement == NULL)
   {
      return MV_C_STRING_PTR_IS_NULL;
   }

   L = lua_open();
   luaopen_base(L);
   luaopen_table(L);
   luaopen_string(L);
   luaopen_math(L);
   luaopen_io(L);
   mvLoadLuaScriptFunctions(L);
   luaError = lua_dostring(L,statement);
   lua_close(L);
   if (luaError) // 1 is error found
   {
      return MV_SCRIPT_MODULE_PARSING_ERROR;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

/**
 * \brief loads lua script inside C type string, using initialised Lua state
 * \param[in] cState Persistent Pointer to Lua State
 * \param[in] luaString Constant C String containing lua script
 * (terminated with NULL or '\\0')
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero)
 *  and an error has occured.
 *
 * It assumes that the Lua state, cState, has been already initialised
 * (such as Lua's base libraries, AND mvMotionAI functions), and parses
 * and runs the C type string
 *
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadCStringWithLuaState(lua_State* cState, const char* luaString)
{
   int luaError;

   if (cState == NULL)
   {
      return MV_SCRIPT_MODULE_PTR_IS_NULL;
   }

   if (luaString == NULL)
   {
      return MV_C_STRING_PTR_IS_NULL;
   }

   luaError = lua_dostring(cState,luaString);
   if (luaError) // 1 is error found
   {
      return MV_SCRIPT_MODULE_PARSING_ERROR;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

// moved from mvMotionAI / decleared in mvMotionAI.h
/**
 * \brief loads lua and runs script file
 * \param[in] fileName File Name of Lua script file
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero)
 * and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses & runs the file 'fileName'
 *
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFile(char* fileName)
{
   lua_State *L = NULL;
   int luaError;

   if (fileName == NULL)
   {
      return MV_FILENAME_POINTER_IS_NULL;
   }

   L = lua_open();
   // load all functions
   luaopen_base(L);
   luaopen_table(L);
   luaopen_string(L);
   luaopen_math(L);
   luaopen_io(L);
   mvLoadLuaScriptFunctions(L);
   luaError = lua_dofile(L, fileName);
   lua_close(L);

   if (luaError) // 1 is error found
   {
      return MV_SCRIPT_MODULE_PARSING_ERROR;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

/**
 * \brief loads lua and runs script file using initialised Lua state
 * \param[in] cState Persistent Pointer to Lua State
 * \param[in] fileName File Name of Lua script file
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero)
 *  and an error has occured.
 *
 * It assumes that the Lua state, cState, has been already initialised
 * (such as Lua's base libraries,
 * AND mvMotionAI functions), and parses and runs the file 'fileName'
 *
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFileWithLuaState(\
   lua_State* cState, const char* fileName)
{
   int luaError;

   if (cState == NULL)
   {
      return MV_SCRIPT_MODULE_PTR_IS_NULL;
   }

   if (fileName == NULL)
   {
      return MV_FILENAME_POINTER_IS_NULL;
   }

   luaError = lua_dofile(cState, fileName);

   if (luaError) // 1 is error found
   {
      return MV_SCRIPT_MODULE_PARSING_ERROR;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

#endif
// TODO (White 2#1#): world functions

//
// world functions 30 functions  = 5 + 8 + 8 + 8 + 1
//

MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   worldPtr->mvWorldStep(timeInSecs);

   return MV_NO_ERROR;
}

// C pointer
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllBodies(mvIndex worldIndex,\
   void (someFunction)(mvBody*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   worldPtr->mvApplyToAllBodies(someFunction,extraPtr);

   return MV_NO_ERROR;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstacles(mvIndex worldIndex,\
   void (someFunction)(mvObstacle*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   worldPtr->mvApplyToAllObstacles(someFunction,extraPtr);

   return MV_NO_ERROR;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypoints(mvIndex worldIndex,\
   void (someFunction)(mvWaypoint*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   worldPtr->mvApplyToAllWaypoints(someFunction,extraPtr);

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathways(mvIndex worldIndex,\
   void (someFunction)(mvPathway*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroups(mvIndex worldIndex,\
   void (someFunction)(mvGroup*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehaviours(mvIndex worldIndex,\
   void (someFunction)(mvBehaviour*,void*), void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehaviours(\
   mvIndex worldIndex, void (someFunction)(mvGroupBehaviour*,void*),\
   void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum  mvApplyToAllForces(mvIndex worldIndex,\
   void (someFunction)(mvForce*,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

// mvIndex
/**
 * not fully implemented
 */
//TODO : need mvMotionAI functionality for index loop functions
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void (someFunction)(mvIndex,void*),void* extraPtr)
{
   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex,void*), void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllObstaclesByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*), void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWaypointsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllPathwaysByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

/**
 * not fully implemented
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllGroupBehavioursByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex,void*),void* extraPtr)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return MV_NO_ERROR;
}

//GET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameter(mvIndex worldIndex,\
   mvParamEnum param, mvOptionEnum* option)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvGetWorldParameter(param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameteri(mvIndex worldIndex,\
   mvParamEnum param, mvIndex* index)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvGetWorldParameteri(param,index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterf(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* num)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvGetWorldParameterf(param,num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvGetWorldParameterv(param,array,noOfParameters);
}

/**
 * not fully implemented
 * have to check if functions correctly i.e parameter returns
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParameters(mvIndex worldIndex,\
   const char* param, const char* option)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum errorFlag;

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   if (param == NULL)
   {
      return MV_PARAM_POINTER_IS_NULL;
   }

   if (!mvCheckAllParamEnumsForString(param,&paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   errorFlag = worldPtr->mvGetWorldParameter(paramFlag,&optionFlag);

   if (errorFlag == MV_NO_ERROR)
   {
      option = mvGetOptionString(optionFlag);
   }
   else
   {
      option = NULL;
   }

   return errorFlag;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersi(mvIndex worldIndex,\
   const char* param, mvIndex* index)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum errorFlag;

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   if (param == NULL)
   {
      return MV_PARAM_POINTER_IS_NULL;
   }

   if (!mvCheckAllParamEnumsForString(param,&paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return worldPtr->mvGetWorldParameteri(paramFlag,index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat* num)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum errorFlag;

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   if (param == NULL)
   {
      return MV_PARAM_POINTER_IS_NULL;
   }

   if (!mvCheckAllParamEnumsForString(param,&paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return worldPtr->mvGetWorldParameterf(paramFlag,num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvGetWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum errorFlag;

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   if (param == NULL)
   {
      return MV_PARAM_POINTER_IS_NULL;
   }

   if (!mvCheckAllParamEnumsForString(param,&paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return worldPtr->mvGetWorldParameterv(paramFlag, array, noOfParameters);
}

//SET
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameter(mvIndex worldIndex,\
   mvParamEnum param, mvOptionEnum option)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvSetWorldParameter(param, option);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameteri(mvIndex worldIndex,\
   mvParamEnum param, mvIndex index)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvSetWorldParameteri(param, index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterf(mvIndex worldIndex,\
   mvParamEnum param, mvFloat num)
   {
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvSetWorldParameterf(param, num);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameterv(mvIndex worldIndex,\
   mvParamEnum param, mvFloat* array)
{
   mvWorld* worldPtr = mvGetWorldPtr(worldIndex);

   if (worldPtr == NULL)
   {
      return MV_INVALID_WORLD_INDEX;
   }

   return worldPtr->mvSetWorldParameterv(param, array);
}

// TODO (White 2#1#): more code here
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParameters(mvIndex worldIndex,\
   const char* param, const char* option)
{

}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersi(mvIndex worldIndex,\
   const char* param, mvIndex index);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat num);

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvSetWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* array);
