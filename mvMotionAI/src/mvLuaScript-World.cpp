/**
 * \file mvLuaScript-World.cpp
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
 * version     date     comments
 * 00-01-17    2/11/06     - conversion from lua pop magic index number to named constants
 *                         - lua set world parameter
 *                         - lua world step
 *                         - lua nudge body
 */

#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvScript-Utilities.h"
#include "mvLuaScript-World.h"


//

int mvLua_WorldStep(lua_State* L);
int mvLua_SetWorldParameter(lua_State* L);
int mvLua_NudgeBody(lua_State* L);
int mvLua_NudgeCurrentBody(lua_State* L);

const char* mvLua_WorldFunctionsNames[] =
{
"mvWorldStep",
"mvSetWorldParameter",
"mvNudgeBody",
"mvNudgeCurrentBody",
};

const char** mvGetLuaWorldFunctions()
{
   return &mvLua_WorldFunctionsNames[0];
}

mvCount mvGetNoOfLuaWorldFunctions()
{
   return sizeof(mvLua_WorldFunctionsNames)/sizeof(const char*);;
}

void mvLoadLuaWorldFunctions(lua_State* L)
{
   const char** ptr = &mvLua_WorldFunctionsNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_WorldStep);
   lua_register(L,ptr[counter++],mvLua_SetWorldParameter);

   lua_register(L,ptr[counter++],mvLua_NudgeBody);
   lua_register(L,ptr[counter++],mvLua_NudgeCurrentBody);
}

int mvLua_WorldStep(lua_State* L)
{
   static const mvIndex MV_LUA_WORLDSTEP_TIMEINSECS_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvFloat timeInSecs = (mvFloat) lua_tonumber(L,MV_LUA_WORLDSTEP_TIMEINSECS_INDEX);
   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      tempWorld->mvWorldStep(timeInSecs);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_NudgeBody(lua_State* L)
{
   static const mvIndex MV_LUA_NUDGEBODY_BODY_INDEX_VALUE = 2;
   static const mvIndex MV_LUA_NUDGEBODY_TIMEINSECS_INDEX = 3;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_NUDGEBODY_BODY_INDEX_VALUE);
   mvFloat timeInSecs = (mvFloat) lua_tonumber(L,MV_LUA_NUDGEBODY_TIMEINSECS_INDEX);
   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvNudgeBody(bodyIndex,timeInSecs);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_NudgeCurrentBody(lua_State* L)
{
   static const mvIndex MV_LUA_NUDGECURRENTBODY_TIMEINSECS_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvFloat timeInSecs = (mvFloat) lua_tonumber(L,MV_LUA_NUDGECURRENTBODY_TIMEINSECS_INDEX);
   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvNudgeCurrentBody(timeInSecs);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetWorldParameter(lua_State* L)
{
   static const mvIndex MV_LUA_SETWORLDPARAMETER_PARAM_ENUM_INDEX = 2;
   static const mvIndex MV_LUA_SETWORLDPARAMETER_OPTION_ENUM_INDEX = 3;
   static const mvIndex MV_LUA_SETWORLDPARAMETER_PARAM_INDEX_NO = 3;
   static const mvIndex MV_LUA_SETWORLDPARAMETER_START_OF_VECTOR = 3;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* params = lua_tostring(L,MV_LUA_SETWORLDPARAMETER_PARAM_ENUM_INDEX);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i, indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkWorldParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SETWORLDPARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkWorldParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetWorldParameter(checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      checkError = mvScript_checkWorldParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SETWORLDPARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetWorldParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkWorldParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SETWORLDPARAMETER_START_OF_VECTOR + i);
         }
         result = tempWorld->mvSetWorldParameterv(checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

