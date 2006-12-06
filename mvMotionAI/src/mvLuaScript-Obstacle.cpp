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
 *
 * Log
 * version     date     comments
 * 00-01-17    1/11/06  - lua mvSetCurrentObstacleParameter
 *                      - lua mvSetObstacleParameter
 *                      - conversion from lua pop magic index number to named constants
 */

#include "mvLuaScript-Obstacle.h"
#include "mvMotionAI-Types.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvObstacle.h"
#include "mvWorld.h"
#include "mvEnums.h"

#ifdef MV_MOTIONAI_LUA_DEBUG
#define MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG 1
#else
#define MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG
#endif

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


const char* mvLua_ObstacleFunctionNames[] =
{
"mvAddObstacle",
"mvRemoveCurrentObstacle",
"mvRemoveObstacle",
"mvSetCurrentObstacle",
"mvRemoveAllObstacles",
"mvSetObstacleParameter",
"mvSetCurrentObstacleParameter",
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
   const char** ptr = &mvLua_ObstacleFunctionNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddObstacle);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentObstacle);
   lua_register(L,ptr[counter++],mvLua_RemoveObstacle);
   lua_register(L,ptr[counter++],mvLua_SetCurrentObstacle);
   lua_register(L,ptr[counter++],mvLua_RemoveAllObstacles);

   /*
    * 00-01-17
    */
   lua_register(L,ptr[counter++],mvLua_SetObstacleParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentObstacleParameter);
}

int mvLua_AddObstacle(lua_State* L)
{
   static const mvIndex MV_ADDOBSTACLE_SHAPE_ENUM_INDEX = 2;
   static const mvIndex MV_ADDOBSTACLE_TYPE_ENUM_INDEX = 3;
   static const mvIndex MV_ADDOBSTACLE_X_INDEX = 4;
   static const mvIndex MV_ADDOBSTACLE_Y_INDEX = 5;
   static const mvIndex MV_ADDOBSTACLE_Z_INDEX = 6;

   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* shape = lua_tostring(L,MV_ADDOBSTACLE_SHAPE_ENUM_INDEX);
   const char* type = lua_tostring(L,MV_ADDOBSTACLE_TYPE_ENUM_INDEX);
   mvFloat x = (mvFloat) lua_tonumber(L,MV_ADDOBSTACLE_X_INDEX);
   mvFloat y = (mvFloat) lua_tonumber(L,MV_ADDOBSTACLE_Y_INDEX);
   mvFloat z = (mvFloat) lua_tonumber(L,MV_ADDOBSTACLE_Z_INDEX);
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
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
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
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
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
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
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
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllObstacles(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
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
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

int mvLua_SetObstacleParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Force.cpp + mvLuaScript_Body.cpp
    */

   int result = MV_INVALID_OBSTACLE_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_ITEM_INDEX);
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
      checkError = mvScript_checkObstacleParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkObstacleParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetObstacleParameter(bIndex,checkParams,checkOption);
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
      checkError = mvScript_checkObstacleParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetObstacleParameteri(bIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      /*
       * finally test vector (& single float value) parameter
       */
      checkError = mvScript_checkObstacleParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetObstacleParameterv(bIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentObstacleParameter(lua_State* L)
{
   int result = MV_INVALID_OBSTACLE_TYPE;
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
      checkError = mvScript_checkObstacleParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkObstacleParamsFlagOptions(option,checkOption);
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
      checkError = mvScript_checkObstacleParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentObstacleParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkObstacleParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentObstacleParameterv(checkParams,numArray);
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


// additional functions

