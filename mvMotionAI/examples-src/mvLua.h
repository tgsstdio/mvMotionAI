#ifndef MVLUA_H_INCLUDED
#define MVLUA_H_INCLUDED

#include <mv/mvMotionAI.h>
#include <Lua.hpp>

void mvLua_LoadLuaMotionAIFunctions(lua_State* luaVM);
mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* cState,\
   const char* fileName);
mvErrorEnum mvLua_LoadScriptFile(const char* fileName);

#endif // MVLUA_H_INCLUDED
