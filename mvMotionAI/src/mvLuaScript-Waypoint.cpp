#include "mvLuaScript-Waypoint.h"
#include "mvEnum.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvScript-Utilities.h"

/**
 * \file mvLuaScript-Waypoint.cpp
 * 
 * Log
 *
 * version     date     comments 
 *00-01-03    21/6/06   - added lua functions for get, remove
 *                      waypoint functions
 */

#define MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG 1
#undef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG

int mvLua_AddWaypoint(lua_State* L);
//int mvLua_GetWaypoint(lua_State* L);
int mvLua_RemoveWaypoint(lua_State* L);
int mvLua_RemoveCurrentWaypoint(lua_State* L);
int mvLua_SetCurrentWaypoint(lua_State* L);
int mvLua_RemoveAllWaypoints(lua_State* L);
int mvLua_SetWaypointParameter(lua_State* L);
//int mvLua_SetWaypointParameterf(lua_State* L);
//int mvLua_SetWaypointParameterv(lua_State* L);
int mvLua_SetCurrentWaypointParameter(lua_State* L);
//int mvLua_SetCurrentWaypointParameterf(lua_State* L);
//int mvLua_SetCurrentWaypointParameterv(lua_State* L);

void mvLoadLuaWaypointFunctions(lua_State* L)
{
   lua_register(L,"mvAddWaypoint",mvLua_AddWaypoint);
   lua_register(L,"mvRemoveWaypointt",mvLua_RemoveWaypoint);
   lua_register(L,"mvRemoveCurrentWaypoint",mvLua_RemoveCurrentWaypoint);
   lua_register(L,"mvSetCurrentWaypoint",mvLua_SetCurrentWaypoint);
   lua_register(L,"mvRemoveAllWaypoints",mvLua_RemoveAllWaypoints);
   //lua_register(L,"mvAddWaypoint",mvLua_AddWaypoint);
};

int mvLua_AddWaypoint(lua_State* L)
{
   //   int mvAddWaypointWithPos(mvEnum wType, mvEnum wShape, mvFloat x, mvFloat y, mvFloat z);

   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   const char* type = lua_tostring(L,2);
   const char* shape = lua_tostring(L,3);
   mvFloat x = (mvFloat) lua_tonumber(L,4);
   mvFloat y = (mvFloat) lua_tonumber(L,5);
   mvFloat z = (mvFloat) lua_tonumber(L,6);
   mvEnum wType, wShape;

   mvWorld* tempWorld = NULL;
   
   // check if world exist
   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
      //std::cout << worldID << std::endl;
      //puts(tempWorld->getWorldID());
      //puts(type);
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(shape);
#endif
      wType = mvScript_checkWaypointType(type);
      wShape = mvScript_checkWaypointShape(shape);
      result = tempWorld->mvAddWaypointWithPos(wType,wShape,x,y,z);
   }
   lua_pushnumber(L,result);         
   return 1;
};

/**
int mvWaypoint::getNoOfPoints() const
{
  switch (wayPointType)
  {
    case MV_NURB_WAYPOINT:
        return MV_NO_OF_NURBS_POINTS;
    case MV_SINGLE_WAYPOINT:
      return MV_NO_OF_SINGLE_POINTS;
    case MV_GROUP_WAYPOINT:
      return MV_NO_OF_GROUP_POINTS;
    default:
      return MV_NO_OF_INVALID_POINTS;
  }
};

int mvWaypoint::getNoOfDimensions() const
{
  switch(wayPointType)
  {
    case MV_SPHERE:
      return MV_NO_OF_SPHERE_DIMENSIONS;
    case MV_AABOX:
      return MV_NO_OF_AABOX_DIMENSIONS;
    case MV_X_AXIS_AA_CYLINDER:
    case MV_Y_AXIS_AA_CYLINDER:
    case MV_Z_AXIS_AA_CYLINDER:
       return MV_NO_OF_AACYLINDER_DIMENSIONS;
    default:
       return MV_INVALID_DIMENSIONS;
  }    
};
**/

int mvLua_RemoveCurrentWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveCurrentWaypoint();
   }
   lua_pushnumber(L,result);         
   return 1;   
};

int mvLua_RemoveWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   int wIndex = (int) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvRemoveWaypoint(wIndex);
   }
   lua_pushnumber(L,result);         
   return 1;   
};

int mvLua_SetCurrentWaypoint(lua_State* L)
{
   int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   int wIndex = (int) lua_tonumber(L,2);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      result = tempWorld->mvSetCurrentWaypoint(wIndex);
   }
   lua_pushnumber(L,result);         
   return 1;  
};

int mvLua_RemoveAllWaypoints(lua_State* L)
{
   //int result = 0;
   int worldID = (int) lua_tonumber(L,1);
   mvWorld* tempWorld = NULL;

   tempWorld = mvGetWorldByIndex(worldID);
   if (tempWorld != NULL)
   {
#ifdef MV_LUA_SCRIPT_WAYPOINT_DEBUG_FLAG
      puts(tempWorld->getWorldID());
#endif
      tempWorld->mvRemoveAllWaypoints();
   }        
   return 0;  
};