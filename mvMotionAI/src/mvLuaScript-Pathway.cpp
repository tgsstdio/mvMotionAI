/**
 * \file mvLuaScript-Pathway.cpp
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

const char** mvGetLuaPathwayFunctions()
{
   return NULL;
}

mvCount mvGetNoOfLuaPathwayFunctions()
{
   return 0;
}

void mvLoadLuaPathwayFunctions(lua_State* L)
{

}

