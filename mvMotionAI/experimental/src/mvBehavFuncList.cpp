#include "mvBehavFuncList.h"

#ifdef MV_WORLD_DEBUG_OUTPUT_FLAG
#include <cstdlib>
#define MV_DEBUG_MVBEHAVFUNCLIST_OUTPUT 1
#endif


mvBehavFuncList::mvBehavFuncList()
{
   noOfValidFunctions = 0;
}

mvErrorEnum mvBehavFuncList::addBehaviourFunction(mvOptionEnum key, mvBaseBehaviourLoader* bFunc)
{
   // check if behaviour key exists
   std::map<mvOptionEnum,mvBaseBehaviourLoader*>::iterator checkKey;

   checkKey = bFunctions.find(key);

   // if found key exist in map, return false
   if (checkKey != bFunctions.end())
   {
//TODO : need new error for existing creation functions
      return MV_INVALID_BEHAVIOUR_INITIALIZATION;
   }

   bFunctions.insert(std::make_pair(key, bFunc));
   ++noOfValidFunctions;

   return MV_NO_ERROR;
}

void mvBehavFuncList::freeAllBehaviourFunctions()
{
   std::map<mvOptionEnum,mvBaseBehaviourLoader*>::iterator i;

#ifdef MV_DEBUG_MVBEHAVFUNCLIST_OUTPUT
   puts("Freeing All Behaviour Function Objects");
#endif

   for (i = bFunctions.begin(); i != bFunctions.end(); ++i)
   {
      delete i->second;
      i->second = NULL;
   }
   noOfValidFunctions = 0;
   bFunctions.clear();
}

mvBaseBehaviour* mvBehavFuncList::createBehaviour(mvOptionEnum key, mvBaseBehaviour* defaultBehav)
{
   // check if behaviour key exists
   std::map<mvOptionEnum,mvBaseBehaviourLoader*>::iterator checkKey;
   mvBaseBehaviourLoader* bFunc = NULL;

   checkKey = bFunctions.find(key);

   if (checkKey == bFunctions.end())
   {
      return NULL;
   }

   bFunc = checkKey->second;
   if (bFunc != NULL)
      return (*bFunc)(defaultBehav);
   else
      return NULL;
}

mvBehavFuncList::~mvBehavFuncList()
{
   freeAllBehaviourFunctions();
   noOfValidFunctions = 0;
}
