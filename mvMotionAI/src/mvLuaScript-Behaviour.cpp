/**
 * \file mvLuaScript-Behaviour.cpp
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

#include "mvLuaScript-Behaviour.h"
#include "mvMotionAI-Types.h"
#include "mvScript-Utilities.h"
#include "mvEnums.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
/**
 *
 * Log
 *
 * version     date     comments
 *00-01-17    31/10/06  - conversion from lua pop magic index number to named constants
 *
 *                      - implemented addBehaviourToCurrentBody
 *
 *00-01-03    21/6/06   - added lua behaviour functions for get, remove, add waypoint, add to body
 *                      functions
 */
#ifdef MV_MOTIONAI_LUA_DEBUG
#define MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG 1
#else
#define MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG
#endif

int mvLua_AddBehaviour(lua_State* L);
int mvLua_GetBehaviour(lua_State* L);
int mvLua_RemoveCurrentBehaviour(lua_State* L);
int mvLua_RemoveBehaviour(lua_State* L);
int mvLua_SetCurrentBehaviour(lua_State* L);
int mvLua_RemoveAllBehaviours(lua_State* L);

int mvLua_SetBehaviourParameter(lua_State* L);
int mvLua_SetCurrentBehaviourParameter(lua_State* L);
//mvEnum mvAddBehaviourToBody(int bodyIndex, mvEnum bType, int behaviourIndex, int groupIndex);
int mvLua_AddBehaviourToBody(lua_State* L);
int mvLua_AddBehaviourToCurrentBody(lua_State* L);

const char* mvLua_BehaviourFunctionNames[] =
{
"mvAddBehaviour",
"mvRemoveCurrentBehaviour",
"mvRemoveBehaviour",
"mvSetCurrentBehaviour",
"mvRemoveAllBehaviours",
"mvAddBehaviourToBody",
"mvSetBehaviourParameter",
"mvSetCurrentBehaviourParameter",
"mvAddBehaviourToCurrentBody",
};

const char** mvGetLuaBehaviourFunctions()
{
  return &mvLua_BehaviourFunctionNames[0];
}

mvCount mvGetNoOfLuaBehaviourFunctions()
{
   return sizeof(mvLua_BehaviourFunctionNames)/sizeof(const char*);
}

void mvLoadLuadBehaviourFunctions(lua_State* L)
{
   const char** ptr = &mvLua_BehaviourFunctionNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveBehaviour);
   lua_register(L,ptr[counter++],mvLua_SetCurrentBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveAllBehaviours);
   lua_register(L,ptr[counter++],mvLua_AddBehaviourToBody);

   /*
    * 00-01-07
    */
   lua_register(L,ptr[counter++],mvLua_SetBehaviourParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentBehaviourParameter);

   /*
    * 00-01-17
    */
   lua_register(L,ptr[counter++],mvLua_AddBehaviourToCurrentBody);
}

int mvLua_AddBehaviour(lua_State* L)
{
   static const mvIndex MV_LUA_ADD_BEhAVIOUR_TYPE_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //const char* behaviourName = lua_tostring(L,2);
   const char* type = lua_tostring(L,MV_LUA_ADD_BEhAVIOUR_TYPE_INDEX);
   mvWorld* tempWorld = NULL;
   mvOptionEnum bType;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(behaviourName);
      //puts(type);
      if (type != NULL)
      {
         mvScript_checkBehaviourType(type,bType);
#ifdef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG
         puts(mvGetOptionString(bType));
#endif
         result = tempWorld->mvAddBehaviour(bType);
      }
   };
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveCurrentBehaviour();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvSetCurrentBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllBehaviours(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      tempWorld->mvRemoveAllBehaviours();
   }
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

//mvEnum mvAddBehaviourToBody(int bodyIndex, mvEnum bType, int behaviourIndex, int groupIndex);
int mvLua_AddBehaviourToBody(lua_State* L)
{
   static const mvIndex MV_LUA_ADDBEHAVIOURTOBODY_BODY_ITEM_INDEX_NO = 2;
   static const mvIndex MV_LUA_ADDBEHAVIOURTOBODY_BEHAVIOUR_ENTRY_TYPE_INDEX = 3;
   static const mvIndex MV_LUA_ADDBEHAVIOURTOBODY_BEHAVIOUR_INDEX_NO = 4;
   static const mvIndex MV_LUA_ADDBEHAVIOURTOBODY_GROUP_INDEX_NO = 5;

   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBEHAVIOURTOBODY_BODY_ITEM_INDEX_NO);
   const char* bTypeString = (char*) lua_tostring(L,MV_LUA_ADDBEHAVIOURTOBODY_BEHAVIOUR_ENTRY_TYPE_INDEX);
   mvIndex behaviourIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBEHAVIOURTOBODY_BEHAVIOUR_INDEX_NO);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBEHAVIOURTOBODY_GROUP_INDEX_NO);
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvWorld* tempWorld = NULL;
   mvOptionEnum bType;
   mvErrorEnum error;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG
      std::cout << bodyIndex << "/"
                << behaviourIndex  << "/"
                << groupIndex << "/" << bTypeString << std::endl;
#endif
      error = mvScript_checkAddBehaviourOption(bTypeString,bType);
      if (error == MV_NO_ERROR)
      {
         result = tempWorld->mvAddBehaviourToBody(bodyIndex,bType,behaviourIndex,groupIndex);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_AddBehaviourToCurrentBody(lua_State* L)
{
   /*
    * derive from addBehaviourToCurrentBody
    */
   static const mvIndex MV_LUA_ADDBEHAVIOURTOCURRENTBODY_BEHAVIOUR_ENTRY_TYPE_INDEX = 2;
   static const mvIndex MV_LUA_ADDBEHAVIOURTOCURRENTBODY_BEHAVIOUR_INDEX_NO = 3;
   static const mvIndex MV_LUA_ADDBEHAVIOURTOCURRENTBODY_GROUP_INDEX_NO = 4;

   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* bTypeString = (char*) lua_tostring(L,MV_LUA_ADDBEHAVIOURTOCURRENTBODY_BEHAVIOUR_ENTRY_TYPE_INDEX);
   mvIndex behaviourIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBEHAVIOURTOCURRENTBODY_BEHAVIOUR_INDEX_NO);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBEHAVIOURTOCURRENTBODY_GROUP_INDEX_NO);
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvWorld* tempWorld = NULL;
   mvOptionEnum bType;
   mvErrorEnum error;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG
      std::cout << behaviourIndex  << "/"
                << groupIndex << "/" << bTypeString << std::endl;
#endif
      error = mvScript_checkAddBehaviourOption(bTypeString,bType);
      if (error == MV_NO_ERROR)
      {
         result = tempWorld->mvAddBehaviourToCurrentBody(bType,behaviourIndex,groupIndex);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex behaviourIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_ITEM_INDEX);
   const char* params = lua_tostring(L,MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetBehaviourParameter(behaviourIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      checkError = mvScript_checkBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetBehaviourParameteri(behaviourIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }


      checkError = mvScript_checkBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetBehaviourParameterv(behaviourIndex,checkParams,numArray);
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

int mvLua_SetCurrentBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_BEHAVIOUR_TYPE;
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
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkBehaviourParamsFlagOptions(option,checkOption);
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
      checkError = mvScript_checkBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentBehaviourParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentBehaviourParameterv(checkParams,numArray);
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
