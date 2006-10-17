/**
 * \file mvLuaScript-Group.cpp
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

#include "mvLuaScript-Group.h"
#include "mvMotionAI-Types.h"
#include "mvMotionAI.h"
#include "mvEnums.h"
#include "mvGroup.h"

#define MV_LUA_SCRIPT_GROUP_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_GROUP_DEBUG_FLAG

int mvLua_AddGroup(lua_State* L);
int mvLua_GetGroup(lua_State* L);
int mvLua_RemoveCurrentGroup(lua_State* L);
int mvLua_RemoveGroup(lua_State* L);
int mvLua_SetCurrentGroup(lua_State* L);
int mvLua_RemoveAllGroups(lua_State* L);
int mvLua_SetGroupParameter(lua_State* L);
//int mvLua_SetGroupParameterf(lua_State* L);
//int mvLua_SetGroupParameterv(lua_State* L);
int mvLua_SetCurrentGroupParameter(lua_State* L);
//int mvLua_SetCurrentGroupParameterf(lua_State* L);
//int mvLua_SetCurrentGroupParameterv(lua_State* L);

int mvLua_AddBodyToGroup(lua_State* L);
int mvLua_AddCurrentBodyToGroup(lua_State* L);
int mvLua_AddBodyToCurrentGroup(lua_State* L);
int mvLua_AddCurrentBodyToCurrentGroup(lua_State* L);
int mvLua_RemoveBodyFromGroup(lua_State* L);
int mvLua_RemoveCurrentBodyFromGroup(lua_State* L);
int mvLua_RemoveBodyFromCurrentGroup(lua_State* L);
int mvLua_RemoveCurrentBodyFromCurrentGroup(lua_State* L);

const char* mvLua_GroupFunctionNames[] =
{
"mvAddGroup",
"mvGetGroup",
"mvRemoveCurrentGroup",
"mvRemoveGroup",
"mvSetCurrentGroup",
"mvRemoveAllGroups",
"mvAddBodyToGroup",
"mvAddCurrentBodyToGroup",
"mvAddBodyToCurrentGroup",
"mvAddCurrentBodyToCurrentGroup",
"mvRemoveBodyFromGroup",
"mvRemoveCurrentBodyFromGroup",
"mvRemoveBodyFromCurrentGroup",
"mvRemoveCurrentBodyFromCurrentGroup",
};

const char** mvGetLuaGroupFunctions()
{
   return &mvLua_GroupFunctionNames[0];
}

mvCount mvGetNoOfLuaGroupFunctions()
{
  return sizeof(mvLua_GroupFunctionNames)/sizeof(const char*);
}

void mvLoadLuaGroupFunctions(lua_State* L)
{
   lua_register(L,mvLua_GroupFunctionNames[0],mvLua_AddGroup);
   lua_register(L,mvLua_GroupFunctionNames[1],mvLua_GetGroup);

   lua_register(L,mvLua_GroupFunctionNames[2],mvLua_RemoveCurrentGroup);
   lua_register(L,mvLua_GroupFunctionNames[3],mvLua_RemoveGroup);
   lua_register(L,mvLua_GroupFunctionNames[4],mvLua_SetCurrentGroup);
   lua_register(L,mvLua_GroupFunctionNames[5],mvLua_RemoveAllGroups);

   lua_register(L,mvLua_GroupFunctionNames[6],mvLua_AddBodyToGroup);
   lua_register(L,mvLua_GroupFunctionNames[7],mvLua_AddCurrentBodyToGroup);
   lua_register(L,mvLua_GroupFunctionNames[8],mvLua_AddBodyToCurrentGroup);
   lua_register(L,mvLua_GroupFunctionNames[9],mvLua_AddCurrentBodyToCurrentGroup);
   lua_register(L,mvLua_GroupFunctionNames[10],mvLua_RemoveBodyFromGroup);
   lua_register(L,mvLua_GroupFunctionNames[11],mvLua_RemoveCurrentBodyFromGroup);
   lua_register(L,mvLua_GroupFunctionNames[12],mvLua_RemoveBodyFromCurrentGroup);
   lua_register(L,mvLua_GroupFunctionNames[13],mvLua_RemoveCurrentBodyFromCurrentGroup);
}

int mvLua_AddGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = static_cast<mvIndex>(lua_tonumber(L,1));
   char* groupName = const_cast<char*>(lua_tostring(L,2));
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      if (groupName != NULL)
      {
#ifdef MV_LUA_SCRIPT_GROUP_DEBUG_FLAG
         puts(groupName);
#endif
         result = tempWorld->mvAddGroup(groupName);
      }
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_GetGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   char* groupName = (char*)  lua_tostring(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvGetGroupIndexByID(groupName);
   }
   lua_pushnumber(L,result);
   return 1;

}

int mvLua_RemoveCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   tempWorld = mvGetWorldByIndex(worldID);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentGroup();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   tempWorld = mvGetWorldByIndex(worldID);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetCurrentGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveAllGroups(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);

   tempWorld = mvGetWorldByIndex(worldID);

   if (tempWorld != NULL)
   {
      tempWorld->mvRemoveAllGroups();
   }
   //lua_pushnumber(L,result);
   return 0;
}

int mvLua_AddBodyToGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_AddCurrentBodyToGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_AddBodyToCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
  // int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_AddCurrentBodyToCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
  // mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToCurrentGroup();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveBodyFromGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveCurrentBodyFromGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveBodyFromCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   //int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveCurrentBodyFromCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   //mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromCurrentGroup();
   }
   lua_pushnumber(L,result);
   return 1;
}

