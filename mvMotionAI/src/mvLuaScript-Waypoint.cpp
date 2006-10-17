/**
 * \file mvLuaScript-Waypoint.cpp
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

#include "mvLuaScript-Waypoint.h"
#include "mvEnums.h"
#include "mvMotionAI.h"
#include "mvWorld.h"
#include "mvScript-Utilities.h"

/**
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

const char* mvLua_WaypointFunctions[] =
{
"mvAddWaypoint",
"mvRemoveWaypoint",
"mvRemoveCurrentWaypoint",
"mvSetCurrentWaypoint",
"mvRemoveAllWaypoints",
};

const char** mvGetLuaWaypointFunctions()
{
   return &mvLua_WaypointFunctions[0];
}

mvCount mvGetNoOfLuaWaypointFunctions()
{
   return sizeof(mvLua_WaypointFunctions)/sizeof(const char*);
}

void mvLoadLuaWaypointFunctions(lua_State* L)
{
   lua_register(L,mvLua_WaypointFunctions[0],mvLua_AddWaypoint);
   lua_register(L,mvLua_WaypointFunctions[1],mvLua_RemoveWaypoint);
   lua_register(L,mvLua_WaypointFunctions[2],mvLua_RemoveCurrentWaypoint);
   lua_register(L,mvLua_WaypointFunctions[3],mvLua_SetCurrentWaypoint);
   lua_register(L,mvLua_WaypointFunctions[4],mvLua_RemoveAllWaypoints);
   //lua_register(L,"mvAddWaypoint",mvLua_AddWaypoint);
}

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
   mvOptionEnum wType, wShape;

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
      mvScript_checkWaypointType(type,wType);
      mvScript_checkWaypointShape(shape,wShape);
      result = tempWorld->mvAddWaypointWithPos(wType,wShape,x,y,z);
   }
   lua_pushnumber(L,result);
   return 1;
}

/*
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
*/

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
}

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
}

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
}

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
}

