#include "mvLuaScript-Obstacle.h"
#include "mvMotionAI-Types.h"
#include "mvScript-Utilities.h"
#include "mvMotionAI.h"
#include "mvObstacle.h"
#include "mvWorld.h"
#include "mvEnum.h"

#define MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_OBSTACLE_DEBUG_FLAG

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

/**
int compareString(const void* left, const void* right)
{
   const char* leftStr = *((char**)  left);
   const char* rightStr = *((char**) left);

   puts(leftStr);
   puts(rightStr);
   return 0; 
}
**/

void mvLoadLuaObstacleFunctions(lua_State* L)
{
  lua_register(L,"mvAddObstacle",mvLua_AddObstacle);
  lua_register(L,"mvRemoveCurrentObstacle",mvLua_RemoveCurrentObstacle);
  lua_register(L,"mvRemoveObstacle",mvLua_RemoveObstacle);
  lua_register(L,"mvSetCurrentObstacle",mvLua_SetCurrentObstacle);
  lua_register(L,"mvRemoveAllObstacles",mvLua_RemoveAllObstacles);
};

int mvLua_AddObstacle(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   const char* type = lua_tostring(L,2);
   const char* state = lua_tostring(L,3);
   mvFloat x = (mvFloat) lua_tonumber(L,4);
   mvFloat y = (mvFloat) lua_tonumber(L,5);
   mvFloat z = (mvFloat) lua_tonumber(L,6);
   mvEnum oType, oState;

   mvWorld* tempWorld = NULL;
   
   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //std::cout << worldID << std::endl;
      //puts(tempWorld->getWorldID());
      //puts(type);
      oType = mvScript_checkObstacleType(type);
      oState = mvScript_checkObstacleState(state);
      result = tempWorld->mvAddObstacleWithPos(oType,oState,x,y,z);
   } 
   lua_pushnumber(L,result);         
   return 1;
};

int mvLua_RemoveCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
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
   return 1;   
};

int mvLua_RemoveObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,2);
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
   return 1;   
};

int mvLua_SetCurrentObstacle(lua_State* L)
{
   int result = 0;
   mvIndex worldID = (mvIndex) lua_tonumber(L,1);
   mvIndex oIndex = (mvIndex) lua_tonumber(L,2);
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
   return 1;  
};

int mvLua_RemoveAllObstacles(lua_State* L)
{
   //int result = 0;
   mvIndex worldID = (int) lua_tonumber(L,1);
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
   return 0;  
};
   
int mvLua_SetCurrentObstacleParameter(lua_State* L);

int mvLua_SetObstacleParameter(lua_State* L);


// additional functions

