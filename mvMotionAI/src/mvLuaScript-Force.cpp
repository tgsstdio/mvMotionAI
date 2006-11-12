/**
 * \file mvLuaScript-Force.cpp
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
 * Version     Date     Comments
 * 00-01-17   31/10/06  - conversion from lua pop magic index number to named constants
 *                      - LUA remove force
 *                      - LUA remove all forces
 *                      - LUA remove current force
 *                      - LUA set current force
 */

#include "mvLuaScript-Force.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvWorld.h"
#include "mvMotionAI.h"

int mvLua_AddForce(lua_State* L);

//int mvLua_AddForceVector(lua_State* L);
int mvLua_RemoveForce(lua_State* L);
int mvLua_RemoveCurrentForce(lua_State* L);
int mvLua_RemoveAllForces(lua_State* L);
int mvLua_SetForceParameter(lua_State* L);
int mvLua_SetCurrentForce(lua_State* L);
int mvLua_SetCurrentForceParameter(lua_State* L);

const char* mvLua_LuaForceFunctionNames[] =
{
"mvAddForce",
"mvSetForceParameter",
"mvSetCurrentForceParameter",
"mvRemoveCurrentForce",
"mvRemoveForce",
"mvSetCurrentForce",
"mvRemoveAllForces",
};

const char** mvGetLuaForceFunctions()
{
   return &mvLua_LuaForceFunctionNames[0];
}

mvCount mvGetNoOfLuaForceFunctions()
{
   return sizeof(mvLua_LuaForceFunctionNames)/sizeof(const char*);
}

void mvLoadLuaForceFunctions(lua_State* L)
{
   const char** ptr = &mvLua_LuaForceFunctionNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddForce);
   lua_register(L,ptr[counter++],mvLua_SetForceParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentForceParameter);

/*
 * 00-01-17
"mvRemoveCurrentForce",
"mvRemoveForce",
"mvSetCurrentForce",
"mvRemoveAllForces",
*/
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentForce);
   lua_register(L,ptr[counter++],mvLua_RemoveForce);
   lua_register(L,ptr[counter++],mvLua_SetCurrentForce);
   lua_register(L,ptr[counter++],mvLua_RemoveAllForces);
}

int mvLua_AddForce(lua_State* L)
{
   static const mvIndex MV_LUA_ADDFORCE_TYPE_INDEX = 2;
   static const mvIndex MV_LUA_ADDFORCE_X_INDEX = 3;
   static const mvIndex MV_LUA_ADDFORCE_Y_INDEX = 4;
   static const mvIndex MV_LUA_ADDFORCE_Z_INDEX = 5;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* type = lua_tostring(L,MV_LUA_ADDFORCE_TYPE_INDEX);
   mvFloat x = (mvFloat) lua_tonumber(L,MV_LUA_ADDFORCE_X_INDEX);
   mvFloat y = (mvFloat) lua_tonumber(L,MV_LUA_ADDFORCE_Y_INDEX);
   mvFloat z = (mvFloat) lua_tonumber(L,MV_LUA_ADDFORCE_Z_INDEX);
   mvOptionEnum fType;

   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      //puts(type);
      mvScript_checkForceType(type,fType);
      result = tempWorld->mvAddForceVector(fType,x,y,z);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetForceParameter(lua_State* L)
{
   int result = MV_INVALID_FORCE_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex forceIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_ITEM_INDEX);
   const char* params = lua_tostring(L,MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX);
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
      checkError = mvScript_checkForceParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkForceParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetForceParameter(forceIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      checkError = mvScript_checkForceParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetForceParameteri(forceIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkForceParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetForceParameterv(forceIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentForceParameter(lua_State* L)
{
   int result = MV_INVALID_FORCE_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* params = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_ENUM_INDEX);
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
      checkError = mvScript_checkForceParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkForceParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetCurrentForceParameter(checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      checkError = mvScript_checkForceParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentForceParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkForceParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentForceParameterv(checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentForce(lua_State* L)
{
   int result = MV_NO_ERROR;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentForce();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveForce(lua_State* L)
{
   int result = MV_NO_ERROR;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   int fIndex = (int) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveForce(fIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentForce(lua_State* L)
{
   int result = MV_NO_ERROR;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   int fIndex = (int) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentForce(fIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllForces(lua_State* L)
{
   //int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      tempWorld->mvRemoveAllForces();
   }
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

