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
#include <mvLua/mvLua.h>
#include "mvLua_CFunctions.h"

// moved from mvMotionAI / decleared in mvMotionAI.h
MV_GLOBAL_FUNC_PREFIX void mvLua_LoadLuaMotionAIFunctions(lua_State* luaVM)
{
   const char** nameArray = mvLua_GetLuaFunctionNames();
   lua_CFunction* funcArray = mvLua_GetLuaFunctionPointers();
   mvCount noOfFunctions = mvLua_GetNoOfImplementedFunctions();

   for (mvIndex i = 0; i < noOfFunctions; i++)
   {
      //printf("i : %i = %s\n", i,nameArray[i]);
      lua_register(luaVM,nameArray[i],funcArray[i]);
   }
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFileWithLuaState(lua_State* lState,\
   const char* fileName)
{
   int luaError = 0;

   if (fileName == NULL)
   {
      return MV_FILENAME_POINTER_IS_NULL;
   }

   // load all functions
   luaL_openlibs( lState );
   mvLua_LoadLuaMotionAIFunctions(lState);
   luaError = luaL_dofile(lState, fileName);

   if (luaError) // 1 is error found
   {
      // print top error from stack
      puts(lua_tostring(lState,-1));
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
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLua_LoadScriptFile(const char* fileName)
{
   mvErrorEnum error;
   lua_State *L = NULL;
   L = lua_open();
   if (L != NULL)
   {
      error = mvLua_LoadScriptFileWithLuaState(L,fileName);
      lua_close(L);
   }
   else
   {
      error = MV_SCRIPT_MODULE_PTR_IS_NULL;
   }
   return error;
}
