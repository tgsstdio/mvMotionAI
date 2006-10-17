/**
 * \file mvLuaScript-Body.cpp
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

#include "mvLuaScript-Body.h"
#include "mvScript-Utilities.h"
#include "mvBody.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvEnums.h"

#define MV_LUA_SCRIPT_BODY_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_BODY_DEBUG_FLAG

int mvLua_AddBody(lua_State* L);
int mvLua_GetBody(lua_State* L);
int mvLua_SetCurrentBody(lua_State* L);
int mvLua_RemoveCurrentBody(lua_State* L);
int mvLua_RemoveBody(lua_State* L);
int mvLua_RemoveAllBodies(lua_State* L);
int mvLua_SetBodyParameter(lua_State* L);
int mvLua_SetCurrentBodyParameter(lua_State* L);

/**
 * mvEnum mvSetDefaultWaypointForBody(int waypointIndex, int bodyIndex);
 * mvEnum mvSetDefaultPathwayForBody(int pathwayIndex, int bodyIndex);
 * mvEnum mvSetDefaultBodyForBody(int targetIndex,int bodyIndex);
 */
int mvLua_SetDefaultWaypointForBody(lua_State* L);
int mvLua_SetDefaultPathwayForBody(lua_State* L);
int mvLua_SetDefaultBodyForBody(lua_State* L);

int mvLua_SetDefaultBehaviourFactorForBody(lua_State* L);
int mvLua_SetDefaultWaypointForCurrentBody(lua_State* L);
int mvLua_SetDefaultPathwayForCurrentBody(lua_State* L);
int mvLua_SetDefaultBodyForCurrentBody(lua_State* L);
int mvLua_SetDefaultBehaviourFactorForCurrentBody(lua_State* L);

const char* mvLua_BodyFunctionNames[] =
{
"mvAddBody",
"mvRemoveCurrentBody",
"mvRemoveBody",
"mvRemoveAllBodies",
"mvSetCurrentBody",
"mvSetDefaultWaypointForBody",
"mvSetDefaultPathwayForBody",
"mvSetDefaultBodyForBody",
"mvSetDefaultBehaviourFactorForBody",
"mvSetDefaultWaypointForCurrentBody",
"mvSetDefaultPathwayForCurrentBody",
"mvSetDefaultBodyForCurrentBody",
"mvSetDefaultBehaviourFactorForCurrentBody",
};

const char** mvGetLuaBodyFunctions()
{
   return &mvLua_BodyFunctionNames[0];
}

mvCount mvGetNoOfLuaBodyFunctions()
{
   return sizeof(mvLua_BodyFunctionNames)/sizeof(const char*);
}

void mvLoadLuaBodyFunctions(lua_State* L)
{
  lua_register(L,mvLua_BodyFunctionNames[0],mvLua_AddBody);
  lua_register(L,mvLua_BodyFunctionNames[1],mvLua_RemoveCurrentBody);
  lua_register(L,mvLua_BodyFunctionNames[2],mvLua_RemoveBody);
  lua_register(L,mvLua_BodyFunctionNames[3],mvLua_RemoveAllBodies);
  lua_register(L,mvLua_BodyFunctionNames[4],mvLua_SetCurrentBody);

  /*
   * New default behaviours
   */
  lua_register(L,mvLua_BodyFunctionNames[5],mvLua_SetDefaultWaypointForBody);
  lua_register(L,mvLua_BodyFunctionNames[6],mvLua_SetDefaultPathwayForBody);
  lua_register(L,mvLua_BodyFunctionNames[7],mvLua_SetDefaultBodyForBody);

  /*
   * 00-01-07
   */
  lua_register(L,mvLua_BodyFunctionNames[8],mvLua_SetDefaultBehaviourFactorForBody);
  lua_register(L,mvLua_BodyFunctionNames[9],mvLua_SetDefaultWaypointForCurrentBody);
  lua_register(L,mvLua_BodyFunctionNames[10],mvLua_SetDefaultPathwayForCurrentBody);
  lua_register(L,mvLua_BodyFunctionNames[11],mvLua_SetDefaultBodyForCurrentBody);
  lua_register(L,mvLua_BodyFunctionNames[12],mvLua_SetDefaultBehaviourFactorForCurrentBody);
}

int mvLua_AddBody(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   const char* type = lua_tostring(L,2);
   const char* shape = lua_tostring(L,3);
   mvFloat x = (mvFloat) lua_tonumber(L,4);
   mvFloat y = (mvFloat) lua_tonumber(L,5);
   mvFloat z = (mvFloat) lua_tonumber(L,6);
   mvOptionEnum bType, bShape;

   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      //puts(type);
      mvScript_checkBodyType(type,bType);
      mvScript_checkBodyShape(shape,bShape);
      result = tempWorld->mvAddBodyWithPos(bType,bShape,x,y,z);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentBody();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveBody(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentBody(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveAllBodies(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      tempWorld->mvRemoveAllBodies();
   }
   return 0;
}

int mvLua_SetDefaultWaypointForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex waypointIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,3);

   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultWaypointForBody(waypointIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultPathwayForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex pathwayIndex =  (mvIndex) lua_tonumber(L,2);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultPathwayForBody(pathwayIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultBodyForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex targetIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultBodyForBody(targetIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultBehaviourFactorForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvFloat bFactor = (mvFloat) lua_tonumber(L,2);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBehaviourFactorForBody(bFactor,bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultWaypointForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex wpIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultWaypointForCurrentBody(wpIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultPathwayForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex pwIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultPathwayForCurrentBody(pwIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultBodyForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBodyForCurrentBody(bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetDefaultBehaviourFactorForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvFloat bFactor = (mvFloat) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBehaviourFactorForCurrentBody(bFactor);
   }
   lua_pushnumber(L,result);
   return 1;
}
//additional code


