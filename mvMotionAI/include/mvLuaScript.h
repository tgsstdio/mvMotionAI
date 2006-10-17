/**
 *\file mvLuaScript.h
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
 *
 */

#ifndef MV_MOTIONAI_LUA_SCRIPT_H_
#define MV_MOTIONAI_LUA_SCRIPT_H_

#include "mvMotionAI-Types.h"

#ifndef MV_MOTIONAI_LUA_FLAG
#define MV_MOTIONAI_LUA_FLAG
/**
 * Using Lua version 5.0
 */
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif

#define MV_MOTIONAI_LUA_DEBUG 1
#undef MV_MOTIONAI_LUA_DEBUG


void mvLoadLuaScriptFunctions(lua_State* L);

const char** mvGetLuaMotionAIFunctions();
mvCount mvGetNoOfLuaMotionAIFunctions();

const char** mvGetLuaBodyFunctions();
mvCount mvGetNoOfLuaBodyFunctions();

const char** mvGetLuaWorldFunctions();
mvCount mvGetNoOfLuaWorldFunctions();

const char** mvGetLuaObstacleFunctions();
mvCount mvGetNoOfLuaObstacleFunctions();

const char** mvGetLuaForceFunctions();
mvCount mvGetNoOfLuaForceFunctions();

const char** mvGetLuaGroupFunctions();
mvCount mvGetNoOfLuaGroupFunctions();

const char** mvGetLuaPathwayFunctions();
mvCount mvGetNoOfLuaPathwayFunctions();

const char** mvGetLuaWaypointFunctions();
mvCount mvGetNoOfLuaWaypointFunctions();

const char** mvGetLuaBehaviourFunctions();
mvCount mvGetNoOfLuaBehaviourFunctions();

const char** mvGetLuaGroupBehaviourFunctions();
mvCount mvGetNoOfLuaGroupBehaviourFunctions();
#endif
