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
 *
 * Log
 * version     date        comments
 * 00-01-17   4/11/06      - lua set current group parameters
 *                         - lua set group parameters
 *                         - conversion from lua pop magic index number to named constants
 */

#include "mvLuaScript-Group.h"
#include "mvScript-Utilities.h"
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
"mvSetGroupParameter",
"mvSetCurrentParameter",
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
   const char** ptr = &mvLua_GroupFunctionNames[0];
   mvIndex counter = 0;

   lua_register(L,ptr[counter++],mvLua_AddGroup);
   lua_register(L,ptr[counter++],mvLua_GetGroup);

   lua_register(L,ptr[counter++],mvLua_RemoveCurrentGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveGroup);
   lua_register(L,ptr[counter++],mvLua_SetCurrentGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveAllGroups);

   lua_register(L,ptr[counter++],mvLua_AddBodyToGroup);
   lua_register(L,ptr[counter++],mvLua_AddCurrentBodyToGroup);
   lua_register(L,ptr[counter++],mvLua_AddBodyToCurrentGroup);
   lua_register(L,ptr[counter++],mvLua_AddCurrentBodyToCurrentGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveBodyFromGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentBodyFromGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveBodyFromCurrentGroup);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentBodyFromCurrentGroup);

   /*
    * 00-01-17
    */
   lua_register(L,ptr[counter++],mvLua_SetGroupParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentGroupParameter);
}

int mvLua_AddGroup(lua_State* L)
{
   static const mvIndex MV_LUA_ADDGROUP_GROUP_NAME_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = static_cast<mvIndex>(lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE));
   char* groupName = const_cast<char*>(lua_tostring(L,MV_LUA_ADDGROUP_GROUP_NAME_INDEX));
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
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_GetGroup(lua_State* L)
{
   static const mvIndex MV_LUA_GETGROUP_GROUP_NAME_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   char* groupName = (char*)  lua_tostring(L,MV_LUA_GETGROUP_GROUP_NAME_INDEX);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvGetGroupIndexByID(groupName);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;

}

int mvLua_RemoveCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   tempWorld = mvGetWorldByIndex(worldID);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentGroup();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   tempWorld = mvGetWorldByIndex(worldID);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetCurrentGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllGroups(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);

   tempWorld = mvGetWorldByIndex(worldID);

   if (tempWorld != NULL)
   {
      tempWorld->mvRemoveAllGroups();
   }
   //lua_pushnumber(L,result);
   return MV_LUA_REMOVE_ALL_ITEMS_COUNT;
}

int mvLua_AddBodyToGroup(lua_State* L)
{
   static const mvIndex MV_LUA_ADDBODYTOGROUP_BODY_INDEX = 2;
   static const mvIndex MV_LUA_ADDBODYTOGROUP_GROUP_INDEX = 3;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBODYTOGROUP_BODY_INDEX);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBODYTOGROUP_GROUP_INDEX);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_AddCurrentBodyToGroup(lua_State* L)
{
   static const mvIndex MV_LUA_ADDCURRENTBODYTOGROUP_GROUP_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDCURRENTBODYTOGROUP_GROUP_INDEX);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_AddBodyToCurrentGroup(lua_State* L)
{
   static const mvIndex MV_LUA_ADDBODYTOCURRENTGROUP_GROUP_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_ADDBODYTOCURRENTGROUP_GROUP_INDEX);
  // int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_AddCurrentBodyToCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
  // mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToCurrentGroup();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveBodyFromGroup(lua_State* L)
{
   static const mvIndex MV_LUA_REMOVEBODYFROMGROUP_BODY_INDEX = 2;
   static const mvIndex MV_LUA_REMOVEBODYFROMGROUP_GROUP_INDEX = 3;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVEBODYFROMGROUP_BODY_INDEX);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVEBODYFROMGROUP_GROUP_INDEX);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentBodyFromGroup(lua_State* L)
{
   static const mvIndex MV_LUA_REMOVECURRENTBODYFROMGROUP_GROUP_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVECURRENTBODYFROMGROUP_GROUP_INDEX);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromGroup(groupIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveBodyFromCurrentGroup(lua_State* L)
{
   static const mvIndex MV_LUA_REMOVEFROMCURRENTGROUP_BODY_INDEX = 2;

   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVEFROMCURRENTGROUP_BODY_INDEX);
   //int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentBodyFromCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   //mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromCurrentGroup();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetGroupParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Waypoint.cpp
    */

   int result = MV_INVALID_GROUP_PARAMETER;
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
      checkError = mvScript_checkGroupParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetGroupParameter(wpIndex,checkParams,checkOption);
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
      checkError = mvScript_checkGroupParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetGroupParameteri(wpIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      /*
       * finally test vector (& single float value) parameter
       */
      checkError = mvScript_checkGroupParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetGroupParameterv(wpIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentGroupParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Waypoint.cpp
    */
   int result = MV_INVALID_GROUP_PARAMETER;
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
      checkError = mvScript_checkGroupParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkGroupParamsFlagOptions(option,checkOption);
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
      checkError = mvScript_checkGroupParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentGroupParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkGroupParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentGroupParameterv(checkParams,numArray);
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

