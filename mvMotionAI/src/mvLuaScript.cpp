/**
 * \file mvLuaScript.cpp
 *
 * Copyright (c) 2006 David Young.
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
 *
 * version     date        comments
 * 00-01-17    2/11/06     - conversion to named constants for lua index values
 */

#include "mvMotionAI.h"
//#include "mvVec3.h"
#include "mvMotionAI-Types.h"
#include "mvLuaScript.h"
#include "mvLuaScript-World.h"
#include "mvLuaScript-Body.h"
#include "mvLuaScript-Behaviour.h"
#include "mvLuaScript-Group.h"
#include "mvLuaScript-Obstacle.h"
#include "mvLuaScript-Pathway.h"
#include "mvLuaScript-Waypoint.h"
#include "mvLuaScript-Force.h"
#include "mvLuaScript-GroupBehaviour.h"

int mvLua_LoadLuaScriptFile(lua_State* luaVM);
int mvLua_RemoveAllWorlds(lua_State* luaVM);
int mvLua_AddWorld(lua_State* luaVM);
int mvLua_GetWorldByID(lua_State* luaVM);
int mvLua_AllWorldsStepForward(lua_State* luaVM);

/*
void mvLoadLuaScriptFile(char* fileName);
void mvAllWorldsStepForward(mvFloat timeInSecs);
mvWorld* mvGetWorldByID(char* id);
mvWorld* mvAddWorld(char* id);
void mvRemoveAllWorlds();
*/

const char* mvLua_MotionAIFunctionNames[] =
   {
      "mvLuaLoadScriptFile",
      "mvRemoveAllWorlds",
      "mvAddWorld",
      "mvGetWorldByID",
      "mvAllWorldsStepForward",
   };

const char** mvGetLuaMotionAIFunctions()
{
   return &mvLua_MotionAIFunctionNames[0];
}

mvCount mvGetNoOfLuaMotionAIFunctions()
{
   return sizeof(mvLua_MotionAIFunctionNames)/sizeof(const char*);
}

/**
 * \brief load or  implemented mvMotionAI Lua functions to Lua state object pointer
 * \param[in] L Persistent Lua State object pointer which is already initialised
 *
 * Registers all lua functions through the various with sub functions.
 *
 * NOTE: if NULL pointer passed to function, functional behaviour is unknown
 */
void mvLoadLuaScriptFunctions(lua_State* L)
{
   // mvMotionAI main functions
   lua_register(L,mvLua_MotionAIFunctionNames[0],mvLua_LoadLuaScriptFile);
   lua_register(L,mvLua_MotionAIFunctionNames[1],mvLua_RemoveAllWorlds);
   lua_register(L,mvLua_MotionAIFunctionNames[2],mvLua_AddWorld);
   lua_register(L,mvLua_MotionAIFunctionNames[3],mvLua_GetWorldByID);
   lua_register(L,mvLua_MotionAIFunctionNames[4],mvLua_AllWorldsStepForward);

   mvLoadLuadBehaviourFunctions(L);
   mvLoadLuaBodyFunctions(L);
   mvLoadLuaGroupFunctions(L);
   mvLoadLuaObstacleFunctions(L);
   mvLoadLuaPathwayFunctions(L);
   mvLoadLuaWaypointFunctions(L);
   mvLoadLuaWorldFunctions(L);
   mvLoadLuaForceFunctions(L);
   mvLoadLuaGroupBehaviourFunctions(L);
}

int mvLua_AllWorldsStepForward(lua_State* L)
{
   static const mvIndex MV_LUA_ALLWORLDSSTEPFORWARD_TIME_IN_SECS_INDEX = 1;

   mvFloat timeInSecs = (mvFloat) lua_tonumber(L, MV_LUA_ALLWORLDSSTEPFORWARD_TIME_IN_SECS_INDEX);
   mvAllWorldsStepForward(timeInSecs);
   lua_pushnumber(L,0);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_GetWorldByID(lua_State* luaVM)
{
   static const mvIndex MV_LUA_GETWORLDBYID_WORLD_ID_INDEX = 1;

   char* worldID = (char*) lua_tostring(luaVM, MV_LUA_GETWORLDBYID_WORLD_ID_INDEX);

#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      return __motionAI_Central_Module->getWorldIndex(worldID);
   }
   else
   {
      return NULL;
   }
#else
   return __motionAI_Central_Module.getWorldIndex(worldID);
#endif
}

int mvLua_LoadLuaScriptFile(lua_State* luaVM)
{
   int result;
   static const mvIndex MV_LUA_LOADLUASCRIPTFILE_FILENAME_INDEX = 1;

   char* fileName = (char*) lua_tostring(luaVM, MV_LUA_LOADLUASCRIPTFILE_FILENAME_INDEX);

   result = mvLua_LoadScriptFile(fileName);
   lua_pushnumber(luaVM,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllWorlds(lua_State* luaVM)
{
   mvRemoveAllWorlds();
   lua_pushnumber(luaVM,0);
   return MV_LUA_RETURNED_ERROR_COUNT;
}


int mvLua_AddWorld(lua_State* luaVM)
{
   static const mvIndex MV_LUA_ADDWORLD_WORLD_ID_INDEX = 1;

   int result = 0;
   char* worldID = (char*) lua_tostring(luaVM, MV_LUA_ADDWORLD_WORLD_ID_INDEX);

#ifdef MV_MOTIONAI_LUA_DEBUG
   if (worldID != NULL)
      std::cout << worldID << std::endl;
   else
      std::cout << "NULL" << std::endl;
#endif

#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      result = __motionAI_Central_Module->addWorld(worldID);
   }
#ifdef MV_MOTIONAI_LUA_DEBUG
   else
   {
      std::cout << "AI Module not declared" << std::endl;
   }
#endif
   #else
   result = __motionAI_Central_Module.addWorld(worldID);
#endif

#ifdef MV_MOTIONAI_LUA_DEBUG
   if (result == 0)
   {
      std::cout << "Add mvWorld Error " << std::endl;
   }
   else
   {
      std::cout << "No of Motion AI worlds : " << result << std::endl;
   }
#endif

   lua_pushnumber(luaVM,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

// code adapted from mvLuaLoadScriptFromFile


/**
 * \brief loads lua script inside C type string
 * \param[in] statement Constant C String containing lua script (terminated with NULL or '\\0')
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses the script string pointed by statement
 *
 */
mvErrorEnum mvLua_LoadScriptFromCString(const char* statement)
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
 * \param[in] luaString Constant C String containing lua script (terminated with NULL or '\\0')
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * It assumes that the Lua state, cState, has been already initialised (such as Lua's base libraries,
 * AND mvMotionAI functions), and parses and runs the C type string
 *
 */
mvErrorEnum mvLua_LoadCStringWithLuaState(lua_State* cState, const char* luaString)
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
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses & runs the file 'fileName'
 *
 */
mvErrorEnum mvLua_LoadScriptFile(char* fileName)
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
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * It assumes that the Lua state, cState, has been already initialised (such as Lua's base libraries,
 * AND mvMotionAI functions), and parses and runs the file 'fileName'
 *
 */
mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* cState, const char* fileName)
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

/*
 * ignore comment
 NOTE : MV_NO_ERROR is still returned if invalid lua code is located inside the statement
 * variable
 */

/*
 // NO C BUFFER ARRAY LOADING

 * \brief loads lua script inside C char buffer of length n, using initialised Lua state
 * \param[in] cState Persistent Pointer to Lua State
 * \param[in] buffer Constant C String containing lua script (terminated with '\\0')
 * \param[in] bufferSize Buffer Length in mvCount
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * It assumes that the Lua state, cState, has been already initialised (such as Lua's base libraries,
 * AND mvMotionAI functions), and parses and runs the C char buffer of length
 *
 * NOTE : MV_NO_ERROR is still returned if invalid lua code is located inside the statement
 * variable
 *
mvErrorEnum mvLua_LoadCBufferWithLuaState(lua_State* cState, const char* buffer, const mvCount bufferSize)
{
   if (cState == NULL)
   {
      return MV_SCRIPT_MODULE_PTR_IS_NULL;
   }

   if (buffer == NULL)
   {
      return MV_C_BUFFER_ARRAY_IS_NULL;
   }

   if (bufferSize > 0)
   {
      return MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO;
   }

   lua_dostring(cState,luaString);
   return MV_NO_ERROR;
}

**
 * \brief loads lua script inside C char buffer array of length n
 * \param[in] buffer Constant C String containing lua script
 * \param[in] bufferSize Buffer Length in mvCount
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses the script string pointed by statement
 *
 * NOTE : MV_NO_ERROR is still returned if invalid lua code is located inside the buffer
 * variable
 *
mvErrorEnum mvLua_LoadScriptFromCBuffer(const char* buffer, const mvCount bufferSize)
{
   lua_State *L = NULL;

   if (buffer == NULL)
      return MV_C_BUFFER_ARRAY_IS_NULL;

   if (bufferSize > 0)
      return MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO;

   L = lua_open();
   luaopen_base(L);
   luaopen_table(L);
   luaopen_string(L);
   luaopen_math(L);
   luaopen_io(L);
   mvLoadLuaScriptFunctions(L);
   lua_dobuffer(L,buffer,bufferSize);
   lua_close(L);
   return MV_NO_ERROR;
}
*/
