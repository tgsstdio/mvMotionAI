#include <mv/mvStdLib.h>

/**
 * default behaviours/actions
 */
#include <mv/mvNullLoader.h>
#include <mv/mvSeek.h>
#include <mv/mvPursuit.h>
#include <mv/mvFlee.h>
#include <mv/mvFollowPath.h>
#include <mv/mvEvasion.h>
#include MV_READY_MADE_ACTION_LOADER_HEADER_FILE_H_

/**
 * default forces
 */
#include <mv/mvGravityForce.h>
#include <mv/mvUniformForce.h>
#include <mv/mvUniformAccelForce.h>
#include <mv/mvUniformShiftForce.h>

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultForces(\
   mvForceLoaderListPtr loader)
{
   mvErrorEnum error;
   mvBaseForceLoaderPtr tempLoader;

   if (loader == MV_NULL)
   {
      return MV_FUNCTION_LOADER_LIST_PTR_IS_NULL;
   }

   tempLoader = MV_NULL;
   tempLoader = new mvGravityForceLoader();
   error = loader->addFactoryFunction(MV_GRAVITY,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new mvUniformForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_FORCE,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new mvUniformAccelForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_ACCELERATION,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new mvUniformShiftForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_SHIFT,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }
#ifdef MV_MOTIONAI_V2_SINGLETON_DEBUG_OUTPUT
   // todo : add more forces
   std::cout<< "No Of FF " << loader->getNoOfFactoryFunctions() << std::endl;
#endif

   return MV_NO_ERROR;
}


MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultActions(\
   mvActionLoaderListPtr loader)
{
   mvErrorEnum error;
   mvBaseActionLoaderPtr tempLoader;

   if (loader == MV_NULL)
   {
      return MV_FUNCTION_LOADER_LIST_PTR_IS_NULL;
   }

   // adding nullLoaders to protected enums such as
   // enum 1
   tempLoader = MV_NULL;
   tempLoader = new mvNullLoader();
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_GROUP_BEHAVIOUR_MEMBER_ENTRY,\
      tempLoader);
   // if error occurs
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 2
   tempLoader = MV_NULL;
   tempLoader = new mvNullLoader();
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_EXISTING_BEHAVIOUR,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 3
   tempLoader = MV_NULL;
   tempLoader = new mvNullLoader();
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_EXISTING_GROUP_BEHAVIOUR,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 4 seek
   tempLoader = MV_NULL;
   tempLoader = new mvReadyMadeActionLoader<mvSeek>(MV_SEEK);
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_SEEK,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 5 pursuit
   tempLoader = MV_NULL;
   tempLoader = new mvReadyMadeActionLoader<mvPursuit>(MV_PURSUIT);
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_PURSUIT,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 6 flee
   tempLoader = MV_NULL;
   tempLoader = new mvReadyMadeActionLoader<mvFlee>(MV_FLEE);
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_FLEE,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 6 path follow
   tempLoader = MV_NULL;
   tempLoader = new mvReadyMadeActionLoader<mvFollowPath>(MV_FOLLOW_PATH);
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_FOLLOW_PATH,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 7 evade body
   tempLoader = MV_NULL;
   tempLoader = new mvReadyMadeActionLoader<mvEvasion>(MV_EVASION);
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_EVASION,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // now adding defined functions
   //TODO : add more behaviours
   return MV_NO_ERROR;
}
