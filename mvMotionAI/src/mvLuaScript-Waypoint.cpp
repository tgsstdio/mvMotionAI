/**
 * \file mvLuaScript-Waypoint.cpp
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
 * version     date     comments
 *00-01-17    31/10/06  - added set parameter functions
 *
 *                      - lua 'pop' index magic numbers are replaced
 * with named constant values
 *
 *
 *00-01-03    21/6/06   - added lua functions for get, remove
 *                      waypoint functions
 */

#include "mvLuaScript-Waypoint.h"
#include "mvEnums.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvScript-Utilities.h"



#define MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG


int mvLua_AddWaypoint(lua_State* L);
//int mvLua_GetWaypoint(lua_State* L);
int mvLua_RemoveWaypoint(lua_State* L);
int mvLua_RemoveCurrentWaypoint(lua_State* L);
int mvLua_SetCurrentWaypoint(lua_State* L);
int mvLua_RemoveAllWaypoints(lua_State* L);
int mvLua_SetWaypointParameter(lua_State* L);
//int mvLua_SetWaypointParameterf(lua_State* L);
//int mvLua_SetWaypointParameterv(lua_State* L);
int mvLua_SetCurrentWaypointParameter(lua_State* L);
//int mvLua_SetCurrentWaypointParameterf(lua_State* L);
//int mvLua_SetCurrentWaypointParameterv(lua_State* L);


const char* mvLua_WaypointFunctions[] =
{
      "mvAddWaypoint",
      "mvRemoveWaypoint",
      "mvRemoveCurrentWaypoint",
      "mvSetCurrentWaypoint",
      "mvRemoveAllWaypoints",
      "mvSetWaypointParameter",
      "mvSetCurrentWaypointParameter",
};

const char** mvGetLuaWaypointFunctions()
{
   return &mvLua_WaypointFunctions[0];
}

mvCount mvGetNoOfLuaWaypointFunctions()
{
   return sizeof(mvLua_WaypointFunctions)/sizeof(const char*);
}

void mvLoadLuaWaypointFunctions(lua_State* L)
{
   // check error later
   const char** ptr = &mvLua_WaypointFunctions[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddWaypoint);
   lua_register(L,ptr[counter++],mvLua_RemoveWaypoint);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentWaypoint);
   lua_register(L,ptr[counter++],mvLua_SetCurrentWaypoint);
   lua_register(L,ptr[counter++],mvLua_RemoveAllWaypoints);
   lua_register(L,ptr[counter++],mvLua_SetWaypointParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentWaypointParameter);
   //lua_register(L,"mvAddWaypoint",mvLua_AddWaypoint);
}

int mvLua_AddWaypoint(lua_State* L)
{
   //   int mvAddWaypointWithPos(mvEnum wType, mvEnum wShape, mvFloat x, mvFloat y, mvFloat z);
   static const mvIndex MV_LUA_WAYPOINT_TYPE_INDEX_NO = 2;
   static const mvIndex MV_LUA_WAYPOINT_SHAPE_INDEX_NO = 3;
   static const mvIndex MV_LUA_WAYPOINT_X_INDEX_NO = 4;
   static const mvIndex MV_LUA_WAYPOINT_Y_INDEX_NO = 5;
   static const mvIndex MV_LUA_WAYPOINT_Z_INDEX_NO = 6;

   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* type = lua_tostring(L,MV_LUA_WAYPOINT_TYPE_INDEX_NO);
   const char* shape = lua_tostring(L,MV_LUA_WAYPOINT_SHAPE_INDEX_NO);
   mvFloat x = (mvFloat) lua_tonumber(L,MV_LUA_WAYPOINT_X_INDEX_NO);
   mvFloat y = (mvFloat) lua_tonumber(L,MV_LUA_WAYPOINT_Y_INDEX_NO);
   mvFloat z = (mvFloat) lua_tonumber(L,MV_LUA_WAYPOINT_Z_INDEX_NO);
   mvOptionEnum wType, wShape;

   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //std::cout << worldID << std::endl;
      //puts(tempWorld->getWorldID());
      //puts(type);
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(shape);
#endif
      mvScript_checkWaypointType(type,wType);
      mvScript_checkWaypointShape(shape,wShape);
      result = tempWorld->mvAddWaypointWithPos(wType,wShape,x,y,z);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentWaypoint();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   int wIndex = (int) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveWaypoint(wIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   int wIndex = (int) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentWaypoint(wIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllWaypoints(lua_State* L)
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
      tempWorld->mvRemoveAllWaypoints();
   }
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

int mvLua_SetWaypointParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Force.cpp + mvLuaScript_Behaviour.cpp
    */

   int result = MV_INVALID_WAYPOINT_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex wpIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_ITEM_INDEX);
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
      checkError = mvScript_checkWaypointParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkWaypointParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetWaypointParameter(wpIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      /*
       * check index parameters next
       */
      checkError = mvScript_checkWaypointParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetWaypointParameteri(wpIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      /*
       * finally test vector (& single float value) parameter
       */
      checkError = mvScript_checkWaypointParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetWaypointParameterv(wpIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentWaypointParameter(lua_State* L)
{
   int result = MV_INVALID_WAYPOINT_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* params = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_ENUM_INDEX);
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
      checkError = mvScript_checkWaypointParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkWaypointParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }
      checkError = mvScript_checkWaypointParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentWaypointParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkWaypointParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentWaypointParameterv(checkParams,numArray);
      }

      lua_pushnumber(L,result);
      return MV_LUA_RETURNED_ERROR_COUNT;
   }
   else
   {
      lua_pushnumber(L,result);
      return MV_LUA_RETURNED_ERROR_COUNT;
   }

}

