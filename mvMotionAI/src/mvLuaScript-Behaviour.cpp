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
 *00-01-03    21/6/06   - added lua behaviour functions for get, remove, add waypoint, add to body
 *                      functions
 */

#define MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG

int mvLua_AddBehaviour(lua_State* L);
int mvLua_GetBehaviour(lua_State* L);
int mvLua_RemoveCurrentBehaviour(lua_State* L);
int mvLua_RemoveBehaviour(lua_State* L);
int mvLua_SetCurrentBehaviour(lua_State* L);
int mvLua_RemoveAllBehaviours(lua_State* L);

int mvLua_SetBehaviourParameter(lua_State* L);
int mvLua_SetCurrentBehaviourParameter(lua_State* L);

/*
Not longer valid
int mvLua_AddBehaviourToBody(lua_State* L);
int mvLua_AddCurrentBehaviourToBody(lua_State* L);
int mvLua_AddBehaviourToCurrentBody(lua_State* L);

int mvLua_AddBehaviourToBody(lua_State* L);
int mvLua_AddCurrentBehaviourToBody(lua_State* L);
int mvLua_AddBehaviourToCurrentBody(lua_State* L);
int mvLua_AddCurrentBehaviourToCurrentBody(lua_State* L);

int mvLua_AddWaypointToBehaviour(lua_State* L);
int mvLua_AddCurrentWaypointToBehaviour(lua_State* L);
int mvLua_AddWaypointToCurrentBehaviour(lua_State* L);
int mvLua_AddCurrentWaypointToCurrentBehaviour(lua_State* L);

int mvLua_AddBodyToBehaviour(lua_State* L);
int mvLua_AddCurrentBodyToBehaviour(lua_State* L);
int mvLua_AddBodyToCurrentBehaviour(lua_State* L);
int mvLua_AddCurrentBodyToCurrentBehaviour(lua_State* L);
*/

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
   lua_register(L,mvLua_BehaviourFunctionNames[0],mvLua_AddBehaviour);
   lua_register(L,mvLua_BehaviourFunctionNames[1],mvLua_RemoveCurrentBehaviour);
   lua_register(L,mvLua_BehaviourFunctionNames[2],mvLua_RemoveBehaviour);
   lua_register(L,mvLua_BehaviourFunctionNames[3],mvLua_SetCurrentBehaviour);
   lua_register(L,mvLua_BehaviourFunctionNames[4],mvLua_RemoveAllBehaviours);
   lua_register(L,mvLua_BehaviourFunctionNames[5],mvLua_AddBehaviourToBody);

   /**
    * 00-01-07
    */
   lua_register(L,mvLua_BehaviourFunctionNames[6],mvLua_SetBehaviourParameter);
   lua_register(L,mvLua_BehaviourFunctionNames[7],mvLua_SetCurrentBehaviourParameter);
/*
   lua_register(L,"mvAddBehaviourToBody",mvLua_AddBehaviourToBody);
   lua_register(L,"mvAddCurrentBehaviourToBody",mvLua_AddCurrentBehaviourToBody);
   lua_register(L,"mvAddBehaviourToCurrentBody",mvLua_AddBehaviourToCurrentBody);
   lua_register(L,"mvAddCurrentBehaviourToCurrentBody",mvLua_AddCurrentBehaviourToCurrentBody);

   lua_register(L,"mvAddWaypointToBehaviour",mvLua_AddWaypointToBehaviour);
   lua_register(L,"mvAddCurrentWaypointToBehaviour",mvLua_AddCurrentWaypointToBehaviour);
   lua_register(L,"mvAddWaypointToCurrentBehaviour",mvLua_AddWaypointToCurrentBehaviour);
   lua_register(L,"mvAddCurrentWaypointToCurrentBehaviour",mvLua_AddCurrentWaypointToCurrentBehaviour);

   lua_register(L,"mvAddBodyToBehaviour",mvLua_AddBodyToBehaviour);
   lua_register(L,"mvAddCurrentBodyToBehaviour",mvLua_AddCurrentBodyToBehaviour);
   lua_register(L,"mvAddBodyToCurrentBehaviour",mvLua_AddBodyToCurrentBehaviour);
   lua_register(L,"mvAddCurrentBodyToCurrentBehaviour",mvLua_AddCurrentBodyToCurrentBehaviour);
*/
}

int mvLua_AddBehaviour(lua_State* L)
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
     // puts(behaviourName);
      //puts(type);
      if (type != NULL)
      {
         mvScript_checkBehaviourType(type,bType);
#ifdef MV_LUA_SCRIPT_BEHAVIOUR_DEBUG_FLAG
         puts(mvGetEnumString(bType));
#endif
         result = tempWorld->mvAddBehaviour(bType);
      }
   };
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveCurrentBehaviour();
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_SetCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvSetCurrentBehaviour(bIndex);
   }
   lua_pushnumber(L,result);
   return 1;
}

int mvLua_RemoveAllBehaviours(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      tempWorld->mvRemoveAllBehaviours();
   }
   return 0;
}

//mvEnum mvAddBehaviourToBody(int bodyIndex, mvEnum bType, int behaviourIndex, int groupIndex);
int mvLua_AddBehaviourToBody(lua_State* L)
{
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   const char* bTypeString = (char*) lua_tostring(L,3);
   mvIndex behaviourIndex = (mvIndex) lua_tonumber(L,4);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,5);
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvWorld* tempWorld = NULL;
   mvOptionEnum bType;
   mvErrorEnum error;

   tempWorld = mvGetWorldByIndex(worldID);
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
   return 1;
}

int mvLua_SetBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex behaviourIndex = (mvIndex) lua_tonumber(L,2);
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
      checkError = mvScript_checkBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,4);
         if (option != NULL)
         {
            checkError = mvScript_checkBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               result = tempWorld->mvSetBehaviourParameter(behaviourIndex,checkParams,checkOption);
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return 1;
               }
            }
         }
      }

      checkError = mvScript_checkBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,4);
         result = tempWorld->mvSetBehaviourParameteri(behaviourIndex,checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return 1;
         }
      }


      checkError = mvScript_checkBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,4 + i);
         }
         result = tempWorld->mvSetBehaviourParameterv(behaviourIndex,checkParams,numArray);
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

int mvLua_SetCurrentBehaviourParameter(lua_State* L)
{
   int result = MV_INVALID_BEHAVIOUR_TYPE;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   const char* params = lua_tostring(L,2);
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
      checkError = mvScript_checkBehaviourParamsFlag(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         option = lua_tostring(L,3);
         if (option != NULL)
         {
            checkError = mvScript_checkBehaviourParamsFlagOptions(option,checkOption);
            if (checkError == MV_NO_ERROR)
            {
               if (result == MV_NO_ERROR)
               {
                  lua_pushnumber(L,result);
                  return 1;
               }
            }
         }
      }
      checkError = mvScript_checkBehaviourParamsIndex(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         indexValue = (mvIndex) lua_tonumber(L,4);
         result = tempWorld->mvSetCurrentBehaviourParameteri(checkParams,indexValue);
         if (result == MV_NO_ERROR)
         {
            lua_pushnumber(L,result);
            return 1;
         }
      }

      checkError = mvScript_checkBehaviourParamsv(params,checkParams);
      if (checkError == MV_NO_ERROR)
      {
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,3 + i);
         }
         result = tempWorld->mvSetCurrentBehaviourParameterv(checkParams,numArray);
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
/*
int mvLua_AddBehaviourToBody(lua_State* L)
{
   int worldID = (int) lua_tonumber(L,1);
   int behaviourID = (int) lua_tonumber(L,2);
   int bodyID = (int) lua_tonumber(L,3);
   int result = 0;
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBehaviourToBody(behaviourID,bodyID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentBehaviourToBody(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   int bodyID = (int) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBehaviourToBody(bodyID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddBehaviourToCurrentBody(lua_State* L)
{
   int worldID = (int) lua_tonumber(L,1);
   int behaviourID = (int) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBehaviourToCurrentBody(behaviourID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentBehaviourToCurrentBody(lua_State* L)
{
   int worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBehaviourToCurrentBody();
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddWaypointToBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   int wpID = (int) lua_tonumber(L,2);
   int behID = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddWaypointToBehaviour(wpID,behID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentWaypointToBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   //int wpID = (int) lua_tonumber(L,2);
   int behID = (int) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentWaypointToBehaviour(behID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddWaypointToCurrentBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   int wpID = (int) lua_tonumber(L,2);
   //int behID = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddWaypointToCurrentBehaviour(wpID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentWaypointToCurrentBehaviour(lua_State* L)
{
   int worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentWaypointToCurrentBehaviour();
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddBodyToBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   int bodyID = (int) lua_tonumber(L,2);
   int behID = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToBehaviour(bodyID,behID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentBodyToBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   //int wpID = (int) lua_tonumber(L,2);
   int behID = (int) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToBehaviour(behID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddBodyToCurrentBehaviour(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   int worldID = (int) lua_tonumber(L,1);
   //int wpID = (int) lua_tonumber(L,2);
   int bodyID = (int) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToCurrentBehaviour(bodyID);
   }
   lua_pushnumber(L,result);
   return 1;
};

int mvLua_AddCurrentBodyToCurrentBehaviour(lua_State* L)
{
   int worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToCurrentBehaviour();
   }
   lua_pushnumber(L,result);
   return 1;
};
*/

