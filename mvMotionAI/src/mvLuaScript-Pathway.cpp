#include "mvLuaScript-Pathway.h"

int mvLua_BeginPathway(lua_State* L);
int mvLua_GetPathway(lua_State* L);
int mvLua_RemovePathway(lua_State* L);
int mvLua_EndPathway(lua_State* L);
int mvLua_RemoveCurrentPathway(lua_State* L);
int mvLua_SetCurrentPathway(lua_State* L);
int mvLua_RemoveAllPathways(lua_State* L);
int mvLua_SetPathwayParameter(lua_State* L);
int mvLua_SetPathwayParameterf(lua_State* L);
int mvLua_SetPathwayParameterv(lua_State* L);
int mvLua_SetCurrentPathwayParameter(lua_State* L);
int mvLua_SetCurrentPathwayParameterf(lua_State* L);
int mvLua_SetCurrentPathwayParameterv(lua_State* L);
      //
int mvLua_AddCurrentWaypointToCurrentPathway(lua_State* L);
int mvLua_AddCurrentWaypointToPathway(lua_State* L);
int mvLua_AddWaypointToPathway(lua_State* L);
int mvLua_AddNURBSWaypoint(lua_State* L);

void mvLoadLuaPathwayFunctions(lua_State* L)
{

};

