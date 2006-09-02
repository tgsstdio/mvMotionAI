#include "mvLuaScript-Force.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI-Types.h"
#include "mvEnum.h"
#include "mvWorld.h"
#include "mvMotionAI.h"

int mvLua_AddForce(lua_State* L);
int mvLua_GetForce(lua_State* L);
int mvLua_AddForceVector(lua_State* L);
int mvLua_RemoveForce(lua_State* L);
int mvLua_RemoveCurrentForce(lua_State* L);
int mvLua_RemoveAllForces(lua_State* L);
int mvLua_SetForceParameter(lua_State* L);
int mvLua_SetCurrentForceParameter(lua_State* L);

void mvLoadLuaForceFunctions(lua_State* L)
{
  lua_register(L,"mvAddForce",mvLua_AddForce);
  lua_register(L,"mvSetForceParameter",mvLua_SetForceParameter);
  lua_register(L,"mvSetCurrentForceParameter",mvLua_SetCurrentForceParameter);
};

int mvLua_AddForce(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   const char* type = lua_tostring(L,2);
   mvFloat x = (mvFloat) lua_tonumber(L,3);
   mvFloat y = (mvFloat) lua_tonumber(L,4);
   mvFloat z = (mvFloat) lua_tonumber(L,5);
   mvEnum fType;

   mvWorld* tempWorld = NULL;
   
   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(tempWorld->getWorldID());
      //puts(type);
      fType = mvScript_checkForceType(type);
      result = tempWorld->mvAddForceVector(fType,x,y,z);
   } 
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_SetForceParameter(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex forceIndex = (mvIndex) lua_tonumber(L,2);
   const char* params = lua_tostring(L,3);
   const char* option;
   mvEnum checkParams, checkOption;
   mvIndex i;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkParams = mvScript_checkForceParamsFlag(params);
      if (checkParams != MV_INVALID_FORCE_PARAMETER)
      {
         option = lua_tostring(L,4);         
         if (option != NULL)
         {
            checkOption = mvScript_checkForceParamsFlagOptions(option);
            if (checkOption != MV_INVALID_FORCE_OPTION)
            {
               result = tempWorld->mvSetForceParameter(forceIndex,checkParams,checkOption);
            }
         }
      }
      
      checkParams = mvScript_checkForceParamsv(params);
      if (checkParams != MV_INVALID_FORCE_PARAMETER)
      { 
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,4 + i);
         }
         result = tempWorld->mvSetForceParameterv(forceIndex,checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);         
   return 1;             
};

int mvLua_SetCurrentForceParameter(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   const char* params = lua_tostring(L,2);
   const char* option;
   mvEnum checkParams, checkOption;
   mvIndex i;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkParams = mvScript_checkForceParamsFlag(params);
      if (checkParams != MV_INVALID_FORCE_PARAMETER)
      {
         option = lua_tostring(L,3);         
         if (option != NULL)
         {
            checkOption = mvScript_checkForceParamsFlagOptions(option);
            if (checkOption != MV_INVALID_FORCE_OPTION)
            {
               result = tempWorld->mvSetCurrentForceParameter(checkParams,checkOption);
            }
         }
      }
      
      checkParams = mvScript_checkForceParamsv(params);
      if (checkParams != MV_INVALID_FORCE_PARAMETER)
      { 
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,3 + i);
         }
         result = tempWorld->mvSetCurrentForceParameterv(checkParams,numArray);
      }
   }
   lua_pushnumber(L,result);         
   return 1;             
};