/**
 * \file mvLuaScript-GroupBehaviour.cpp
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

#include "mvLuaScript-GroupBehaviour.h"
#include "mvMotionAI-Types.h"
#include "mvGroupBehaviour.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvEnums.h"

#define MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG

int mvLua_AddGroupBehaviour(lua_State* L);
int mvLua_GetGroupBehaviour(lua_State* L);
int mvLua_RemoveGroupBehaviour(lua_State* L);
int mvLua_RemoveCurrentGroupBehaviour(lua_State* L);
int mvLua_RemoveAllGroupBehaviours(lua_State* L);
int mvLua_SetCurrentGroupBehaviour(lua_State* L);
int mvLua_SetGroupBehaviourParameter(lua_State* L);
int mvLua_SetCurrentGroupBehaviourParameter(lua_State* L);
//int mvLua_SetCurrentGroupBehaviourParameterf(lua_State* L);
//int mvLua_SetCurrentGroupBehaviourParameterv(lua_State* L);

int mvLua_InsertGroupIntoGroupBehaviour(lua_State* L);
int mvLua_InsertCurrentGroupIntoGroupBehaviour(lua_State* L);
int mvLua_InsertGroupIntoCurrentGroupBehaviour(lua_State* L);
int mvLua_InsertCurrentGroupIntoCurrentBehaviour(lua_State* L);

const char* mvLua_GroupBehaviourFunctionNames[] =
{
"mvAddGroupBehaviour",
"mvRemoveGroupCurrentBehaviour",
"mvRemoveGroupBehaviour",
"mvSetCurrentGroupBehaviour",
"mvRemoveAllGroupBehaviours",
"mvInsertGroupIntoGroupBehaviour",
"mvInsertCurrentGroupIntoGroupBehaviour",
"mvInsertGroupIntoCurrentGroupBehaviour",
"mvInsertCurrentGroupIntoCurrentGroupBehaviour",
"mvSetGroupBehaviourParameter",
"mvSetCurrentGroupBehaviourParameter",
};

const char** mvGetLuaGroupBehaviourFunctions()
{
   return &mvLua_GroupBehaviourFunctionNames[0];
}

mvCount mvGetNoOfLuaGroupBehaviourFunctions()
{
   return sizeof(mvLua_GroupBehaviourFunctionNames)/sizeof(const char*);
}

void mvLoadLuaGroupBehaviourFunctions(lua_State* L)
{
   lua_register(L,mvLua_GroupBehaviourFunctionNames[0],mvLua_AddGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[1],mvLua_RemoveCurrentGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[2],mvLua_RemoveGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[3],mvLua_SetCurrentGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[4],mvLua_RemoveAllGroupBehaviours);
// insert group
   lua_register(L,mvLua_GroupBehaviourFunctionNames[5],mvLua_InsertGroupIntoGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[6],mvLua_InsertCurrentGroupIntoGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[7],mvLua_InsertGroupIntoCurrentGroupBehaviour);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[8],mvLua_InsertCurrentGroupIntoCurrentBehaviour);
// set parameters
   lua_register(L,mvLua_GroupBehaviourFunctionNames[9],mvLua_SetGroupBehaviourParameter);
   lua_register(L,mvLua_GroupBehaviourFunctionNames[10],mvLua_SetCurrentGroupBehaviourParameter);
}

// unchceked
int mvLua_AddGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //const char* behaviourName = lua_tostring(L,2);
   const char* type = lua_tostring(L,2);
   mvWorld* tempWorld = NULL;
   mvOptionEnum bType;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(behaviourName);
      //puts(type);
      if (type != NULL)
      {
         mvScript_checkGroupBehaviourType(type,bType);
#ifdef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG
         puts(mvGetEnumString(bType));
#endif
         result = tempWorld->mvAddGroupBehaviour(bType);
      }
   };
   lua_pushnumber(L,result);
   return 1;
}

// unchecked
int mvLua_RemoveCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);
   return 1;
}

// unchecked
int mvLua_RemoveGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

// unchecked
int mvLua_SetCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvSetCurrentGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

// unchecked
int mvLua_RemoveAllGroupBehaviours(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      tempWorld->mvRemoveAllGroupBehaviours();
   }
   return 0;
}

int mvLua_InsertGroupIntoGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoGroupBehaviour(groupIndex,groupBehIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_InsertCurrentGroupIntoGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoGroupBehaviour(groupBehIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_InsertGroupIntoCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   //mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoCurrentGroupBehaviour(groupIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_InsertCurrentGroupIntoCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
  // mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetGroupBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex gbIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   const char* params = lua_tostring(L,4);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,5);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupBehaviourParamsFlagOptions(option, checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetGroupBehaviourParameter(gbIndex,groupIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return 1;
               }
            }
         }
      }

      checkError = mvScript_checkGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,5);
         result = tempWorld->mvSetGroupBehaviourParameteri(gbIndex,groupIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return 1;
         }
      }


      checkError = mvScript_checkGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,5 + i);
         }
         result = tempWorld->mvSetGroupBehaviourParameterv(gbIndex,groupIndex,checkParams,numArray);
      }

      lua_pushnumber(L,result);
      return 1;
   }
   else
   {
      lua_pushnumber(L,result);
      return 1;
   }
}

int mvLua_SetCurrentGroupBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   const char* params = lua_tostring(L,3);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,4);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetCurrentGroupBehaviourParameter(groupIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return 1;
               }
            }
         }
      }
      checkError = mvScript_checkGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,4);
         result = tempWorld->mvSetCurrentGroupBehaviourParameteri(groupIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return 1;
         }
      }

      checkError = mvScript_checkGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,4 + i);
         }
         result = tempWorld->mvSetCurrentGroupBehaviourParameterv(groupIndex,checkParams,numArray);
      }

      lua_pushnumber(L,result);
      return 1;
   }
   else
   {
      lua_pushnumber(L,result);
      return 1;
   }
}
