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
 * Log
 *
 * version     date     comments
 * 00-01-17    1/11/06  - lua mvSetCurrentBodyParameter
 *                      - lua mvSetBodyParameter
 *                      - conversion from lua pop magic index number to named constants
 *
 */

#include "mvLuaScript-Body.h"
#include "mvScript-Utilities.h"
#include "mvBody.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvEnums.h"

#ifdef MV_MOTIONAI_LUA_DEBUG
#define MV_LUA_SCRIPT_BODY_DEBUG_FLAG 1
#else
#define MV_LUA_SCRIPT_BODY_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
#endif

int mvLua_AddBody(lua_State* L);
int mvLua_GetBody(lua_State* L);
int mvLua_SetCurrentBody(lua_State* L);
int mvLua_RemoveCurrentBody(lua_State* L);
int mvLua_RemoveBody(lua_State* L);
int mvLua_RemoveAllBodies(lua_State* L);
int mvLua_SetBodyParameter(lua_State* L);
int mvLua_SetCurrentBodyParameter(lua_State* L);
int mvLua_SetDefaultWaypointForBody(lua_State* L);
int mvLua_SetDefaultPathwayForBody(lua_State* L);
int mvLua_SetDefaultBodyForBody(lua_State* L);

int mvLua_SetDefaultBehaviourFactorForBody(lua_State* L);
int mvLua_SetDefaultWaypointForCurrentBody(lua_State* L);
int mvLua_SetDefaultPathwayForCurrentBody(lua_State* L);
int mvLua_SetDefaultBodyForCurrentBody(lua_State* L);
int mvLua_SetDefaultBehaviourFactorForCurrentBody(lua_State* L);

static const mvIndex MV_LUA_SET_DEFAULT_ITEM_BODY_INDEX = 3;
static const mvIndex MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO = 2;

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
"mvSetBodyParameter",
"mvSetCurrentBodyParameter",
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
   const char** ptr = &mvLua_BodyFunctionNames[0];
   mvIndex counter = 0;

//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_AddBody);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_RemoveCurrentBody);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_RemoveBody);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_RemoveAllBodies);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_SetCurrentBody);

   /*
    * New default behaviours
    */
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_SetDefaultWaypointForBody);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_SetDefaultPathwayForBody);
//   puts(ptr[counter]);
   lua_register(L,ptr[counter++],mvLua_SetDefaultBodyForBody);

   /*
    * 00-01-07
    */
   lua_register(L,ptr[counter++],mvLua_SetDefaultBehaviourFactorForBody);
   lua_register(L,ptr[counter++],mvLua_SetDefaultWaypointForCurrentBody);
   lua_register(L,ptr[counter++],mvLua_SetDefaultPathwayForCurrentBody);
   lua_register(L,ptr[counter++],mvLua_SetDefaultBodyForCurrentBody);
   lua_register(L,ptr[counter++],mvLua_SetDefaultBehaviourFactorForCurrentBody);

   /*
    * 00-01-17
    */
   lua_register(L,ptr[counter++],mvLua_SetBodyParameter);
   lua_register(L,ptr[counter++],mvLua_SetCurrentBodyParameter);
}

int mvLua_AddBody(lua_State* L)
{
   static const mvIndex MV_LUA_ADDBODY_TYPE_INDEX = 2;
   static const mvIndex MV_LUA_ADDBODY_SHAPE_INDEX = 3;
   static const mvIndex MV_LUA_ADDBODY_X_INDEX = 4;
   static const mvIndex MV_LUA_ADDBODY_Y_INDEX = 5;
   static const mvIndex MV_LUA_ADDBODY_Z_INDEX = 6;

   int result = 0;
   int worldID = (int) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   const char* type = lua_tostring(L,MV_LUA_ADDBODY_TYPE_INDEX);
   const char* shape = lua_tostring(L,MV_LUA_ADDBODY_SHAPE_INDEX);
   mvFloat x = (mvFloat) lua_tonumber(L,MV_LUA_ADDBODY_X_INDEX);
   mvFloat y = (mvFloat) lua_tonumber(L,MV_LUA_ADDBODY_Y_INDEX);
   mvFloat z = (mvFloat) lua_tonumber(L,MV_LUA_ADDBODY_Z_INDEX);
   mvOptionEnum bType, bShape;

   mvWorld* tempWorld = NULL;

   // check if world exist
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      //puts(type);
      mvScript_checkBodyType(type,bType);
      mvScript_checkBodyShape(shape,bShape);
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
   puts(mvGetOptionString(bType));
   puts(mvGetOptionString(bShape));
#endif
      result = tempWorld->mvAddBodyWithPos(bType,bShape,x,y,z);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentBody();
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_REMOVE_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveBody(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_ITEM_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_BODY_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentBody(bIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_RemoveAllBodies(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
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
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex waypointIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_DEFAULT_ITEM_BODY_INDEX);

   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultWaypointForBody(waypointIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultPathwayForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex pathwayIndex =  (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_DEFAULT_ITEM_BODY_INDEX);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      // puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultPathwayForBody(pathwayIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultBodyForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex targetIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_DEFAULT_ITEM_BODY_INDEX);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      // puts(tempWorld->getWorldID());
      result = tempWorld->mvSetDefaultBodyForBody(targetIndex,bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultBehaviourFactorForBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvFloat bFactor = (mvFloat) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_SET_DEFAULT_ITEM_BODY_INDEX);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBehaviourFactorForBody(bFactor,bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultWaypointForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex wpIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultWaypointForCurrentBody(wpIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultPathwayForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex pwIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultPathwayForCurrentBody(pwIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultBodyForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBodyForCurrentBody(bodyIndex);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetDefaultBehaviourFactorForCurrentBody(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,MV_LUA_WORLD_INDEX_VALUE);
   mvFloat bFactor = (mvFloat) lua_tonumber(L,MV_LUA_SETDEFAULTITEMFORBODY_INDEX_NO);
   mvWorld* tempWorld = NULL;

   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetDefaultBehaviourFactorForCurrentBody(bFactor);
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}
//additional code

int mvLua_SetBodyParameter(lua_State* L)
{
   /*
    * cut + paste from mvLuaScript_Force.cpp + mvLuaScript_Behaviour.cpp
    */

   int result = MV_INVALID_BODY_TYPE;
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
   tempWorld = mvMotionAI_GETWORLDPTR(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkError = mvScript_checkBodyParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkBodyParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetBodyParameter(bIndex,checkParams,checkOption);
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
      checkError = mvScript_checkBodyParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetBodyParameteri(bIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      /*
       * finally test vector (& single float value) parameter
       */
      checkError = mvScript_checkBodyParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetBodyParameterv(bIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);
   return MV_LUA_RETURNED_ERROR_COUNT;
}

int mvLua_SetCurrentBodyParameter(lua_State* L)
{
   int result = MV_INVALID_BODY_TYPE;
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
      checkError = mvScript_checkBodyParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX);
         if (option != NULL)
         {
            checkError = mvScript_checkBodyParamsFlagOptions(option,checkOption);
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
      checkError = mvScript_checkBodyParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO);
         result = tempWorld->mvSetCurrentBodyParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return MV_LUA_RETURNED_ERROR_COUNT;
         }
      }

      checkError = mvScript_checkBodyParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX + i);
         }
         result = tempWorld->mvSetCurrentBodyParameterv(checkParams,numArray);
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


