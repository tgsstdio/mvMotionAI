#ifndef MV_MOTIONAI_LUA_SCRIPT_H_
#define MV_MOTIONAI_LUA_SCRIPT_H_

#ifndef MV_MOTIONAI_LUA_FLAG
#define MV_MOTIONAI_LUA_FLAG
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif

#define MV_MOTIONAI_LUA_DEBUG 1
#undef MV_MOTIONAI_LUA_DEBUG

void mvLoadLuaScriptFunctions(lua_State* L);

#endif
