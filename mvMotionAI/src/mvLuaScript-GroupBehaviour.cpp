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
 *
 * Log
 *
 * Version    Date     Comments
 * 00-01-17  1/11/06   - conversion from lua pop magic index number to named constants
 *                     - implemented setMainGroupBehaviour
 *                     - implemented setCurrentMainGroupGroupBehaviour
 */

#include "mvLuaScript-GroupBehaviour.h"
#include "mvMotionAI-Types.h"
#include "mvGroupBehaviour.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvEnums.h"

#ifdef MV_MOTIONAI_LUA_DEBUG
#define MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG 1
#else
#define MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG
#endif

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

/*
 * 00-01-17
 */
int mvLua_SetMainGroupBehaviourParameter(lua_State* L);
int mvLua_SetCurrentMainGroupBehaviourParameter(lua_State* L);

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
"mvSetMainGroupBehaviourParameter",
"mvSetCurrentMainGroupBehaviourParameter",
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
   const char** ptr = &mvLua_GroupBehaviourFunctionNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_SetCurrentGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_RemoveAllGroupBehaviours);
// insert group
   lua_register(L,ptr[counter++],mvLua_InsertGroupIntoGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_InsertCurrentGroupIntoGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_InsertGroupIntoCurrentGroupBehaviour);
   lua_register(L,ptr[counter++],mvLua_InsertCurrentGroupIntoCurrentBehaviour);
// set parameters
   lua_register(L,ptr[counter++],mvLua_SetGroupBehaviourParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentGroupBehaviourParameter);

   /*
    * 00-01-17
    */
   lua_register(L,ptr[counter++],mvLua_SetMainGroupBehaviourParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentMainGroupBehaviourParameter);

}

// unchceked
int mvLua_AddGroupBehaviour(lua_State* L)
{
   static const mvIndex MV_LUA_ADDGROUPBEHAVIOUR_TYPE_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //const char* behaviourName = lua_tostring(L,2);
   const char* type = lua_tostring(L,MV_LUA_ADDGROUPBEHAVIOUR_TYPE_INDEX);
   mvWorldPtr tempWorld = NULL;
   mvOptionEnum bType;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      //puts(behaviourName);
      //puts(type);
      if (type != NULL)
      {
         mvScript_checkGroupBehaviourType(type,bType);
#ifdef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG
         puts(mvGetOptionString(bType));
#endif
         result = tempWorld->mvAddGroupBehaviour(bType);
      }
   };
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

// unchecked
int mvLua_RemoveCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

// unchecked
int mvLua_RemoveGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

// unchecked
int mvLua_SetCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvSetCurrentGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

// unchecked
int mvLua_RemoveAllGroupBehaviours(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      tempWorld->mvRemoveAllGroupBehaviours();
   }
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

int mvLua_InsertGroupIntoGroupBehaviour(lua_State* L)
{
   static const mvIndex MV_LUA_INSERTGROUPINTOGROUPBEHAV_GROUP_INDEX = 2;
   static const mvIndex MV_LUA_INSERTGROUPINTOGROUPBEHAV_GROUP_BEHAV_INDEX = 3;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_INSERTGROUPINTOGROUPBEHAV_GROUP_INDEX);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,MV_LUA_INSERTGROUPINTOGROUPBEHAV_GROUP_BEHAV_INDEX);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoGroupBehaviour(groupIndex,groupBehIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_InsertCurrentGroupIntoGroupBehaviour(lua_State* L)
{
   static const mvIndex MV_LUA_INSERTCURRENTGROUPINTOGROUPBEHAV_GROUP_BEH_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,MV_LUA_INSERTCURRENTGROUPINTOGROUPBEHAV_GROUP_BEH_INDEX);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoGroupBehaviour(groupBehIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_InsertGroupIntoCurrentGroupBehaviour(lua_State* L)
{
   static const mvIndex MV_LUA_INSERTGROUPINTOCURRENTGROUPBEHAV_GROUP_INDEX = 2;

   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_INSERTGROUPINTOCURRENTGROUPBEHAV_GROUP_INDEX);
   //mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,3);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoCurrentGroupBehaviour(groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_InsertCurrentGroupIntoCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
  // mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorldPtr tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetGroupBehaviourParameter(lua_State* L)
{
   static const mvIndex MV_LUA_SETGROUPBEHAVPARAMETER_GROUP_BEHAV_INDEX = 2;
   static const mvIndex MV_LUA_SETGROUPBEHAVPARAMETER_GROUP_INDEX = 3;
   static const mvIndex MV_LUA_SETGROUPBEHAVPARAMETER_PARAM_ENUM_INDEX = 4;
   static const mvIndex MV_LUA_SETGROUPBEHAVPARAMETER_OPTION_ENUM_INDEX = 5;
   static const mvIndex MV_LUA_SETGROUPBEHEVPARAMETER_PARAM_INDEX_NO = 5;
   static const mvIndex MV_LUA_SETGROUPBEHEVPARAMETER_START_OF_VECTOR_INDEX = 5;

   int result = MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex gbIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETGROUPBEHAVPARAMETER_GROUP_BEHAV_INDEX);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETGROUPBEHAVPARAMETER_GROUP_INDEX);
   const char* params = lua_tostring(L,MV_LUA_SETGROUPBEHAVPARAMETER_PARAM_ENUM_INDEX);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorldPtr tempWorld = NULL;

   // check single parameter first
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SETGROUPBEHAVPARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupBehaviourParamsFlagOptions(option, checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetGroupBehaviourParameter(gbIndex,groupIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }

      checkError = mvScript_checkGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SETGROUPBEHEVPARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetGroupBehaviourParameteri(gbIndex,groupIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }


      checkError = mvScript_checkGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SETGROUPBEHEVPARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetGroupBehaviourParameterv(gbIndex,groupIndex,checkParams,numArray);
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

int mvLua_SetCurrentGroupBehaviourParameter(lua_State* L)
{
   static const mvIndex MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_GROUP_INDEX = 2;
   static const mvIndex MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_PARAM_ENUM_INDEX = 3;
   static const mvIndex MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_OPTION_ENUM_INDEX = 4;
   static const mvIndex MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_PARAM_INDEX = 4;
   static const mvIndex MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_START_OF_VECTOR = 4;

   int result = MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_GROUP_INDEX);
   const char* params = lua_tostring(L,MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_PARAM_ENUM_INDEX);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorldPtr tempWorld = NULL;

   // check single parameter first
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetCurrentGroupBehaviourParameter(groupIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return MV_LUA_RETURNED_ERROR_COUNT;
               }
            }
         }
      }
      checkError = mvScript_checkGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_PARAM_INDEX);
         result = tempWorld->mvSetCurrentGroupBehaviourParameteri(groupIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SETCURRENTGROUPBEHAVPARAMETER_START_OF_VECTOR + i);
         }
         result = tempWorld->mvSetCurrentGroupBehaviourParameterv(groupIndex,checkParams,numArray);
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
// TODO (White 2#1#): Need to do more checking for errors

int mvLua_SetMainGroupBehaviourParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Force.cpp + mvLuaScript_Behaviour.cpp
    */

   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex wpIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_ITEM_INDEX);
   const char* params = lua_tostring(L,MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX);
   const char* option;
   mvParamEnum checkParams;
   mvOptionEnum checkOption;
   mvErrorEnum checkError;
   mvIndex i, indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorldPtr tempWorld = NULL;

   // check single parameter first
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkMainGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkMainGroupBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetMainGroupBehaviourParameter(wpIndex,checkParams,checkOption);
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
      checkError = mvScript_checkMainGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetMainGroupBehaviourParameteri(wpIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      /*
       * finally test vector (& single float value) parameter
       */
      checkError = mvScript_checkMainGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetMainGroupBehaviourParameterv(wpIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentMainGroupBehaviourParameter(lua_State* L)
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
   mvWorldPtr tempWorld = NULL;

   // check single parameter first
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkMainGroupBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkMainGroupBehaviourParamsFlagOptions(option,checkOption);
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
      checkError = mvScript_checkMainGroupBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentMainGroupBehaviourParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkMainGroupBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentMainGroupBehaviourParameterv(checkParams,numArray);
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


