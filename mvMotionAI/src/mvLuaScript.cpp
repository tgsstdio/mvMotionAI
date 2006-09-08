#include "mvMotionAI.h"
//#include "mvVec3.h"
#include "mvMotionAI-Types.h"
#include "mvLuaScript.h"
#include "mvLuaScript-World.h"
#include "mvLuaScript-Body.h"
#include "mvLuaScript-Behaviour.h"
#include "mvLuaScript-Group.h"
#include "mvLuaScript-Obstacle.h"
#include "mvLuaScript-Pathway.h"
#include "mvLuaScript-Waypoint.h"
#include "mvLuaScript-Force.h"
#include "mvLuaScript-GroupBehaviour.h"

int mvLua_LoadLuaScriptFile(lua_State* luaVM);
int mvLua_RemoveAllWorlds(lua_State* luaVM);
int mvLua_AddWorld(lua_State* luaVM);
int mvLua_GetWorldByID(lua_State* luaVM);
int mvLua_AllWorldsStepForward(lua_State* luaVM);

/**
void mvLoadLuaScriptFile(char* fileName);
void mvAllWorldsStepForward(mvFloat timeInSecs);
mvWorld* mvGetWorldByID(char* id);
mvWorld* mvAddWorld(char* id);
void mvRemoveAllWorlds();
**/

void mvLoadLuaScriptFunctions(lua_State* L)
{
  // mvMotionAI main functions
  lua_register(L,"mvLoadLuaScriptFile",mvLua_LoadLuaScriptFile);
  lua_register(L,"mvRemoveAllWorlds",mvLua_RemoveAllWorlds);
  lua_register(L,"mvAddWorld",mvLua_AddWorld);
  lua_register(L,"mvGetWorldByID",mvLua_GetWorldByID);
  lua_register(L,"mvAllWorldsStepForward",mvLua_AllWorldsStepForward);
  mvLoadLuadBehaviourFunctions(L);
  mvLoadLuaBodyFunctions(L);
  mvLoadLuaGroupFunctions(L);
  mvLoadLuaObstacleFunctions(L);
  mvLoadLuaPathwayFunctions(L);
  mvLoadLuaWaypointFunctions(L);
  mvLoadLuaWorldFunctions(L);
  mvLoadLuaForceFunctions(L);
  mvLoadLuaGroupBehaviourFunctions(L);
};

int mvLua_AllWorldsStepForward(lua_State* L)
{
  mvFloat timeInSecs = (mvFloat) lua_tonumber(L, 1);
  mvAllWorldsStepForward(timeInSecs);
  lua_pushnumber(L,0);
  return 1;
};

int mvLua_GetWorldByID(lua_State* luaVM)
{
  char* worldID = (char*) lua_tostring(luaVM, 1);

  #ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
    if (__motionAI_Central_Module != NULL)
    {
      return __motionAI_Central_Module->getWorldIndex(worldID);
    }
    else
    {
      return NULL;
    }
  #else
    return __motionAI_Central_Module.getWorldIndex(worldID);
  #endif
};

int mvLua_LoadLuaScriptFile(lua_State* luaVM)
{
  char* fileName = (char*) lua_tostring(luaVM, 1);

  mvLoadLuaScriptFile(fileName);
  lua_pushnumber(luaVM,0);
  return 1;
};

int mvLua_RemoveAllWorlds(lua_State* luaVM)
{
  mvRemoveAllWorlds();
  lua_pushnumber(luaVM,0);
  return 1;
};


int mvLua_AddWorld(lua_State* luaVM)
{
   int result = 0;
   char* worldID = (char*) lua_tostring(luaVM, 1);

 #ifdef MV_MOTIONAI_LUA_DEBUG
   if (worldID != NULL)
      std::cout << worldID << std::endl;
   else
      std::cout << "NULL" << std::endl;
 #endif

   #ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
     if (__motionAI_Central_Module != NULL)
     {
       result = __motionAI_Central_Module->addWorld(worldID);
     }
     #ifdef MV_MOTIONAI_LUA_DEBUG
     else
     {
       std::cout << "AI Module not declared" << std::endl;
     }
     #endif
   #else
     result = __motionAI_Central_Module.addWorld(worldID);
   #endif

   #ifdef MV_MOTIONAI_LUA_DEBUG
     if (result == 0)
     {
        std::cout << "Add mvWorld Error " << std::endl;
     }
     else
     {
       std::cout << "No of Motion AI worlds : " << result << std::endl;
     }
   #endif

   lua_pushnumber(luaVM,result);
   return 1;
};



