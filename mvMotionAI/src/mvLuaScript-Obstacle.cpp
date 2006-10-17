/**
 * \file mvLuaScript-Obstacle.cpp
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

#include "mvLuaScript-Obstacle.h"
#include "mvMotionAI-Types.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvObstacle.h"
#include "mvWorld.h"
#include "mvEnums.h"

#define MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG

int mvLua_AddObstacle(lua_State* L);
int mvLua_GetObstacle(lua_State* L);
//int mvLua_SetCurrentObstacleParameterf(lua_State* L);
//int mvLua_SetCurrentObstacleParameterv(lua_State* L);
int mvLua_RemoveCurrentObstacle(lua_State* L);
int mvLua_RemoveObstacle(lua_State* L);
int mvLua_SetCurrentObstacle(lua_State* L);
int mvLua_RemoveAllObstacles(lua_State* L);
int mvLua_SetCurrentObstacleParameter(lua_State* L);
int mvLua_SetObstacleParameter(lua_State* L);
//int mvLua_SetObstacleParameterf(lua_State* L);
//int mvLua_SetObstacleParameterv(lua_State* L);

/*
int compareString(const void* left, const void* right)
{
   const char* leftStr = *((char**)  left);
   const char* rightStr = *((char**) left);

   puts(leftStr);
   puts(rightStr);
   return 0;
}
*/

const char* mvLua_ObstacleFunctionNames[] =
{
"mvAddObstacle",
"mvRemoveCurrentObstacle",
"mvRemoveObstacle",
"mvSetCurrentObstacle",
"mvRemoveAllObstacles",
};

const char** mvGetLuaObstacleFunctions()
{
   return &mvLua_ObstacleFunctionNames[0];
}

mvCount mvGetNoOfLuaObstacleFunctions()
{
   return sizeof(mvLua_ObstacleFunctionNames)/sizeof(const char*);
}

void mvLoadLuaObstacleFunctions(lua_State* L)
{
  lua_register(L,mvLua_ObstacleFunctionNames[0],mvLua_AddObstacle);
  lua_register(L,mvLua_ObstacleFunctionNames[1],mvLua_RemoveCurrentObstacle);
  lua_register(L,mvLua_ObstacleFunctionNames[2],mvLua_RemoveObstacle);
  lua_register(L,mvLua_ObstacleFunctionNames[3],mvLua_SetCurrentObstacle);
  lua_register(L,mvLua_ObstacleFunctionNames[4],mvLua_RemoveAllObstacles);
}

int mvLua_AddObstacle(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   const char* shape = lua_tostring(L,2);
   const char* type = lua_tostring(L,3);
   mvFloat x = (mvFloat) lua_tonumber(L,4);
   mvFloat y = (mvFloat) lua_tonumber(L,5);
   mvFloat z = (mvFloat) lua_tonumber(L,6);
   mvOptionEnum oShape, oType;

   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //std::cout << worldID << std::endl;
      //puts(tempWorld->getWorldID());
      //puts(type);
      mvScript_checkObstacleShape(shape,oShape);
      mvScript_checkObstacleType(type,oType);
      result = tempWorld->mvAddObstacleWithPos(oShape,oType,x,y,z);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentObstacle();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveObstacle(oIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentObstacle(oIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveAllObstacles(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      tempWorld->mvRemoveAllObstacles();
   }
   //lua_pushnumber(L,result);
   return 0;
}

int mvLua_SetCurrentObstacleParameter(lua_State* L);

int mvLua_SetObstacleParameter(lua_State* L);


// additional functions

