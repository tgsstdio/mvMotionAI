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

   luaError = lua_dofile(lState, fileName);

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
