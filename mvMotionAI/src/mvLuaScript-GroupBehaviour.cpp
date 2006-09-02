#include "mvLuaScript-GroupBehaviour.h"
#include "mvMotionAI-Types.h"
#include "mvGroupBehaviour.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvEnum.h"

#define MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG

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

void mvLoadLuaGroupBehaviourFunctions(lua_State* L)
{
   lua_register(L,"mvAddGroupBehaviour",mvLua_AddGroupBehaviour);
   lua_register(L,"mvRemoveGroupCurrentBehaviour",mvLua_RemoveCurrentGroupBehaviour);
   lua_register(L,"mvRemoveGroupBehaviour",mvLua_RemoveGroupBehaviour);
   lua_register(L,"mvSetCurrentGroupBehaviour",mvLua_SetCurrentGroupBehaviour);
   lua_register(L,"mvRemoveAllGroupBehaviours",mvLua_RemoveAllGroupBehaviours);
// insert group
   lua_register(L,"mvInsertGroupIntoGroupBehaviour",mvLua_InsertGroupIntoGroupBehaviour);
   lua_register(L,"mvInsertCurrentGroupIntoGroupBehaviour",mvLua_InsertCurrentGroupIntoGroupBehaviour);
   lua_register(L,"mvInsertGroupIntoCurrentGroupBehaviour",mvLua_InsertGroupIntoCurrentGroupBehaviour);
   lua_register(L,"mvInsertCurrentGroupIntoCurrentGroupBehaviour",mvLua_InsertCurrentGroupIntoCurrentBehaviour);
// set parameters 
   lua_register(L,"mvSetGroupBehaviourParameter",mvLua_SetGroupBehaviourParameter);
   lua_register(L,"mvSetCurrentGroupBehaviourParameter",mvLua_SetCurrentGroupBehaviourParameter);
};

// unchceked
int mvLua_AddGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //const char* behaviourName = lua_tostring(L,2);
   const char* type = lua_tostring(L,2);
   mvWorld* tempWorld = NULL;
   mvEnum bType;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //puts(behaviourName);
      //puts(type);
      if (type != NULL)
      {
         bType = mvScript_checkGroupBehaviourType(type);
#ifdef MV_LUA_SCRIPT_GROUP_BEHAVIOUR_DEBUG_FLAG
         puts(mvGetEnumString(bType));
#endif
         result = tempWorld->mvAddGroupBehaviour(bType);
      }
   };
   lua_pushnumber(L,result);         
   return 1;
};

// unchecked
int mvLua_RemoveCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);         
   return 1;   
};

// unchecked
int mvLua_RemoveGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      result = tempWorld->mvRemoveGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);         
   return 1;   
};

// unchecked
int mvLua_SetCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvSetCurrentGroupBehaviour(bIndex);
   }
   lua_pushnumber(L,result);         
   return 1;  
};

// unchecked
int mvLua_RemoveAllGroupBehaviours(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
     // puts(tempWorld->getWorldID());
      tempWorld->mvRemoveAllGroupBehaviours();
   }        
   return 0;  
};

int mvLua_InsertGroupIntoGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoGroupBehaviour(groupIndex,groupBehIndex);
   }
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_InsertCurrentGroupIntoGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoGroupBehaviour(groupBehIndex);
   }
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_InsertGroupIntoCurrentGroupBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   //mvIndex groupBehIndex = (mvIndex) lua_tonumber(L,3);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertGroupIntoCurrentGroupBehaviour(groupIndex);
   }
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_InsertCurrentGroupIntoCurrentBehaviour(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bIndex = (mvIndex) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
   //  puts(tempWorld->getWorldID());
      result = tempWorld->mvInsertCurrentGroupIntoCurrentGroupBehaviour();
   }
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_SetGroupBehaviourParameter(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex gbIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   const char* params = lua_tostring(L,4);
   const char* option;
   mvEnum checkParams, checkOption;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkParams = mvScript_checkGroupBehaviourParamsFlag(params);      
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      {
         option = lua_tostring(L,5);         
         if (option != NULL)
         {
            checkOption = mvScript_checkGroupBehaviourParamsFlagOptions(option);
            if (checkOption != MV_INVALID_BEHAVIOUR_PARAM_OPTION)
            {
               result = tempWorld->mvSetGroupBehaviourParameter(gbIndex,groupIndex,checkParams,checkOption);
               lua_pushnumber(L,result);         
               return 1;
            }
         }
      }
      
      checkParams = mvScript_checkGroupBehaviourParamsIndex(params);
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      { 
          indexValue = (mvIndex) lua_tonumber(L,5);
          result = tempWorld->mvSetGroupBehaviourParameteri(gbIndex,groupIndex,checkParams,indexValue);
          lua_pushnumber(L,result);         
          return 1;
      }

      
      checkParams = mvScript_checkGroupBehaviourParamsv(params);
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      { 
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,5 + i);
         }
         result = tempWorld->mvSetGroupBehaviourParameterv(gbIndex,groupIndex,checkParams,numArray);
      }

      lua_pushnumber(L,result);         
      return 1;
   }
   else
   {
      lua_pushnumber(L,result);         
      return 1;
   }
};

int mvLua_SetCurrentGroupBehaviourParameter(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   const char* params = lua_tostring(L,3);
   const char* option;
   mvEnum checkParams, checkOption;
   mvIndex i;
   mvIndex indexValue;
   mvFloat numArray[MV_MAX_NO_OF_PARAMETERS];
   mvWorld* tempWorld = NULL;

   // check single parameter first
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL && params != NULL)
   {
      checkParams = mvScript_checkGroupBehaviourParamsFlag(params);
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      {
         option = lua_tostring(L,4);         
         if (option != NULL)
         {
            checkOption = mvScript_checkGroupBehaviourParamsFlagOptions(option);
            if (checkOption !=   MV_INVALID_BEHAVIOUR_PARAM_OPTION)
            {
               result = tempWorld->mvSetCurrentGroupBehaviourParameter(groupIndex,checkParams,checkOption);
               lua_pushnumber(L,result);         
               return 1;
            }
         }
      }
      checkParams = mvScript_checkGroupBehaviourParamsIndex(params);
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      { 
          indexValue = (mvIndex) lua_tonumber(L,4);
          result = tempWorld->mvSetCurrentGroupBehaviourParameteri(groupIndex,checkParams,indexValue);
          lua_pushnumber(L,result);         
          return 1;
      }
      
      checkParams = mvScript_checkGroupBehaviourParamsv(params);
      if (checkParams != MV_INVALID_BEHAVIOUR_PARAMETER)
      { 
         for (i = 0; i < MV_MAX_NO_OF_PARAMETERS; i++)
         {
            numArray[i] = (mvFloat) lua_tonumber(L,4 + i);
         }
         result = tempWorld->mvSetCurrentGroupBehaviourParameterv(groupIndex,checkParams,numArray);
      }

      lua_pushnumber(L,result);         
      return 1;
   }
   else
   {
      lua_pushnumber(L,result);         
      return 1;
   }
};
