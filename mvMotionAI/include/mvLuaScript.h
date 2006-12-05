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
 * Log
 *
 * version     date
 *
 * 00-01-21   25/11/06
 * - added new functions
 *    -# mvLua_LoadScriptFileWithLuaState,
 *    -# mvLua_LoadScriptFromCString,
 *    -# mvLua_LoadCStringWithLuaState,
*
 * 00-01-17   --/11/06
 * - number indexes (magic numbers) for lua are pain to debug so using named constants
 *
 */

#ifndef MV_MOTIONAI_LUA_SCRIPT_H_
#define MV_MOTIONAI_LUA_SCRIPT_H_

#include "mvMotionAI-Types.h"
#include "mvEnums.h"

#ifndef MV_MOTIONAI_LUA_FLAG
#define MV_MOTIONAI_LUA_FLAG
/*
 * Using Lua version 5.0
 */
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif

#ifndef MV_MOTIONAI_LUA_DEBUG
/**
 * \brief debug flag for lua functions in mvMotionAI
 *
 * default is not defined.
 * - To debug either:
 *
 *    -# comment the line (\#undef MV_MOTIONAI_LUA_DEBUG) like so (//\#undef MV_MOTIONAI_LUA_DEBUG)
 *    -# or define it at compile time as compiler flag i.e -DMV_MOTIONAI_LUA_DEBUG
 */
#define MV_MOTIONAI_LUA_DEBUG 1
#undef MV_MOTIONAI_LUA_DEBUG
#endif

/**
 * \brief internal constant - ignore
 */
static const mvCount MV_LUA_RETURNED_ERROR_COUNT = 1;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_CURRENT_ITEM_INDEX_NO = 2;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_REMOVE_ITEM_INDEX_NO = 2;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_WORLD_INDEX_VALUE = 1;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_PARAMETER_ITEM_INDEX = 2;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_ENUM_INDEX = 3;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_PARAMETER_OPTION_ENUM_INDEX = 4;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_PARAMETER_PARAM_INDEX_NO = 4;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_PARAMETER_START_OF_VECTOR_INDEX = 4;

/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_PARAM_ENUM_INDEX = 2;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_OPTION_ENUM_INDEX = 3;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_PARAM_INDEX_NO = 3;
/**
 * \brief internal constant - ignore
 */
static const mvIndex MV_LUA_SET_CURRENT_PARAMETER_START_OF_VECTOR_INDEX = 3;
/**
 * \brief internal constant - ignore
 */
static const mvCount MV_LUA_REMOVE_ALL_ITEMS_COUNT = 0;

void mvLoadLuaScriptFunctions(lua_State* L);

// 00-01-21 new lua functions
mvErrorEnum mvLua_LoadScriptFromCString(const char* statement);
mvErrorEnum mvLua_LoadCStringWithLuaState(lua_State* cState, const char* luaString);
mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* cState, const char* fileName);

// TODO: implement these functions below if possible
//mvErrorEnum mvLoadLuaScriptFromCBuffer(const char* buffer, const mvCount bufferSize);
//mvErrorEnum mvLoadLuaCBufferWithLuaState(lua_State* cState, const char* buffer, const mvCount bufferSize);

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
