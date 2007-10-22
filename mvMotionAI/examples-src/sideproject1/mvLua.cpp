/**
 * Copyright (c) 2004 - 2006 David Young.
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
#include "mvLua.h"
#include "mvLua_CFunctions.h"

// moved from mvMotionAI / decleared in mvMotionAI.h
void mvLua_LoadLuaMotionAIFunctions(lua_State* luaVM)
{
   const char** nameArray = mvLua_GetLuaFunctionNames();
   lua_CFunction* funcArray = mvLua_GetLuaFunctionPointers();
   mvCount noOfFunctions = mvLua_GetNoOfImplementedFunctions();

   for (mvIndex i = 0; i < noOfFunctions; i++)
   {
      lua_register(luaVM,nameArray[i],funcArray[i]);
   }
}


mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* lState,\
   const char* fileName)
{
   int luaError;

   if (fileName == NULL)
   {
      return MV_FILENAME_POINTER_IS_NULL;
   }

   // load all functions
   luaopen_base(lState);
   luaopen_table(lState);
   luaopen_string(lState);
   luaopen_math(lState);
   luaopen_io(lState);
   /*
   mvCount noOfFunctions =
   for (int i = 0; i < mvCount mvLua_CFUNCNOOFFUNCTIONNAMES; ++i)
   {
      lua_register(L,ptr[counter++],mvLua_WorldStep);
   }
   */
   mvLua_LoadLuaMotionAIFunctions(lState);

   luaError = luaL_dofile(lState, fileName);

   if (luaError) // 1 is error found
   {
      return MV_SCRIPT_MODULE_PARSING_ERROR;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

/**
 * \brief loads lua and runs script file
 * \param[in] fileName File Name of Lua script file
 * \return If correct MV_NO_ERROR (or 0) is returned. Any else (non zero) and an error has occured.
 *
 * During operation, it opens & closes a temporary instance of lua state,
 * automatically loads all implemented lua function in this function,
 * then parses & runs the file 'fileName'
 *
 */
mvErrorEnum mvLua_LoadScriptFile(char* fileName)
{
   lua_State *L = NULL;
   L = lua_open();
   mvErrorEnum error = mvLua_LoadScriptFileWithLuaState(L, fileName);
   lua_close(L);
   return error;
}
