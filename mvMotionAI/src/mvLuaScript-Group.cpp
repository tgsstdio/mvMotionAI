#include "mvLuaScript-Group.h"
#include "mvMotionAI-Types.h"
#include "mvMotionAI.h"
#include "mvEnum.h"
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


void mvLoadLuaGroupFunctions(lua_State* L)
{
   lua_register(L,"mvAddGroup",mvLua_AddGroup);
   lua_register(L,"mvGetGroup",mvLua_GetGroup);

   lua_register(L,"mvRemoveCurrentGroup",mvLua_RemoveCurrentGroup);
   lua_register(L,"mvRemoveGroup",mvLua_RemoveGroup);
   lua_register(L,"mvSetCurrentGroup",mvLua_SetCurrentGroup);
   lua_register(L,"mvRemoveAllGroups",mvLua_RemoveAllGroups);

   lua_register(L,"mvAddBodyToGroup",mvLua_AddBodyToGroup);
   lua_register(L,"mvAddCurrentBodyToGroup",mvLua_AddCurrentBodyToGroup);
   lua_register(L,"mvAddBodyToCurrentGroup",mvLua_AddBodyToCurrentGroup);
   lua_register(L,"mvAddCurrentBodyToCurrentGroup",mvLua_AddCurrentBodyToCurrentGroup);
   lua_register(L,"mvRemoveBodyFromGroup",mvLua_RemoveBodyFromGroup);
   lua_register(L,"mvRemoveCurrentBodyFromGroup",mvLua_RemoveCurrentBodyFromGroup);
   lua_register(L,"mvRemoveBodyFromCurrentGroup",mvLua_RemoveBodyFromCurrentGroup);
   lua_register(L,"mvRemoveCurrentBodyFromCurrentGroup",mvLua_RemoveCurrentBodyFromCurrentGroup);
};

int mvLua_AddGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = static_cast<mvIndex>(lua_tonumber(L,1));
   char* groupName = const_cast<char*>(lua_tostring(L,2));
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
   return 1;
};

int mvLua_GetGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   char* groupName = (char*)  lua_tostring(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvGetGroupIndexByID(groupName);
   }
   lua_pushnumber(L,result);    
   return 1;

};

int mvLua_RemoveCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   tempWorld = mvGetWorldByIndex(worldID);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentGroup();
   }
   lua_pushnumber(L,result);    
   return 1;
};

int mvLua_RemoveGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   tempWorld = mvGetWorldByIndex(worldID);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveGroup(groupIndex);
   }
   lua_pushnumber(L,result);    
   return 1;
};

int mvLua_SetCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvSetCurrentGroup(groupIndex);
   }
   lua_pushnumber(L,result);    
   return 1;
};

int mvLua_RemoveAllGroups(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);

   tempWorld = mvGetWorldByIndex(worldID);

   if (tempWorld != NULL)
   {
      tempWorld->mvRemoveAllGroups();
   }
   //lua_pushnumber(L,result);    
   return 0;
};

int mvLua_AddBodyToGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_AddCurrentBodyToGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToGroup(groupIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_AddBodyToCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
  // int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddBodyToCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_AddCurrentBodyToCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
  // mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvAddCurrentBodyToCurrentGroup();
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_RemoveBodyFromGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromGroup(bodyIndex,groupIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_RemoveCurrentBodyFromGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   //mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,2);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromGroup(groupIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_RemoveBodyFromCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   //int groupIndex = (int) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveBodyFromCurrentGroup(bodyIndex);
   }
   lua_pushnumber(L,result);  
   return 1;
};

int mvLua_RemoveCurrentBodyFromCurrentGroup(lua_State* L)
{
   mvWorld* tempWorld = NULL;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex bodyIndex = (mvIndex) lua_tonumber(L,2);
   mvIndex groupIndex = (mvIndex) lua_tonumber(L,3);
   int result = 0;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      result = tempWorld->mvRemoveCurrentBodyFromCurrentGroup();
   }
   lua_pushnumber(L,result);  
   return 1;
};

