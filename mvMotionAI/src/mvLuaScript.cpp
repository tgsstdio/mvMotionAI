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

/**
void mvLoadLuaScriptFile(char* fileName);
void mvAllWorldsStepForward(mvFloat timeInSecs);
mvWorld* mvGetWorldByID(char* id);
mvWorld* mvAddWorld(char* id);
void mvRemoveAllWorlds();
**/

// moved from mvMotionAI / decleared in mvMotionAI.h
void mvLoadLuaScriptFile(char* fileName)
{
   if (fileName != NULL)
   {
      lua_State *L = lua_open();
      luaopen_base(L);
      luaopen_table(L);
      luaopen_string(L);
      luaopen_math(L);
      luaopen_io(L);
      mvLoadLuaScriptFunctions(L);
      lua_dofile(L, fileName);
      lua_close(L);
   }
}

const char* mvLua_MotionAIFunctionNames[] =
{
"mvLoadLuaScriptFile",
"mvRemoveAllWorlds",
"mvAddWorld",
"mvGetWorldByID",
"mvAllWorldsStepForward",
};

const char** mvGetLuaMotionAIFunctions()
{
   return &mvLua_MotionAIFunctionNames[0];
};

mvCount mvGetNoOfLuaMotionAIFunctions()
{
   return sizeof(mvLua_MotionAIFunctionNames)/sizeof(const char*);
};

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
};

int mvLua_AllWorldsStepForward(lua_State* L)
{
  mvFloat timeInSecs = (mvFloat) lua_tonumber(L, 1);
  mvAllWorldsStepForward(timeInSecs);
  lua_pushnumber(L,0);
  return 1;
};

int mvLua_GetWorldByID(lua_State* luaVM)
{
  char* worldID = (char*) lua_tostring(luaVM, 1);

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
};

int mvLua_LoadLuaScriptFile(lua_State* luaVM)
{
  char* fileName = (char*) lua_tostring(luaVM, 1);

  mvLoadLuaScriptFile(fileName);
  lua_pushnumber(luaVM,0);
  return 1;
};

int mvLua_RemoveAllWorlds(lua_State* luaVM)
{
  mvRemoveAllWorlds();
  lua_pushnumber(luaVM,0);
  return 1;
};


int mvLua_AddWorld(lua_State* luaVM)
{
   int result = 0;
   char* worldID = (char*) lua_tostring(luaVM, 1);

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
   return 1;
};



