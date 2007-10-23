#ifndef MVLUA_H_INCLUDED
#define MVLUA_H_INCLUDED

#include <mv/mvMotionAI.h>
#include <lua.hpp>

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

MV_GLOBAL_FUNC_PREFIX void mvLua_LoadLuaMotionAIFunctions(lua_State* luaVM);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* cState,\
   const char* fileName);
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFile(const char* fileName);

#endif // MVLUA_H_INCLUDED
