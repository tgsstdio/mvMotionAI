#include "mvMotionAI_V2-Central.h"
#include "mvNullLoader.h"
#include <cstring>
#include <new>

mvMotionAI_V2_SUPERCLASS __mv__Motion__AI__Module;

// function signatures
bool findExistingWorld(mvWorld_V2* worldPtr, void* extraPtr);
void updatingWorlds(mvWorld_V2* worldPtr, void* extraPtr);

mvMotionAI_V2_SUPERCLASS::mvMotionAI_V2_SUPERCLASS()
{
   centralPtr = NULL;
}

mvErrorEnum  mvMotionAI_V2_SUPERCLASS::initMotionAI()
{
   if (centralPtr == NULL)
   {
      centralPtr = new mvMotionAI_V2();
      if (centralPtr == NULL)
         return MV_INVALID_MEMORY_ALLOCATION;
   }
   return MV_NO_ERROR;
}

void mvMotionAI_V2_SUPERCLASS::freeMotionAI()
{
   if (centralPtr != NULL)
   {
      delete centralPtr;
      centralPtr = NULL;
   }
}

mvMotionAI_V2_SUPERCLASS::~mvMotionAI_V2_SUPERCLASS()
{
   freeMotionAI();
}

mvMotionAI_V2* mvMotionAI_V2_SUPERCLASS::getMotionAI_V2_Ptr()
{
   return centralPtr;
}

mvMotionAI_V2::mvMotionAI_V2()
{
   // EMPTY
}

bool findExistingWorld(mvWorld_V2* worldPtr, void* extraPtr)
{
   const char* worldID = NULL;
   const char* existingID = NULL;

   if (worldPtr == NULL)
   {
      return false;
   }

   if (extraPtr == NULL)
   {
      return false;
   }

   worldID = (const char*) extraPtr;
   existingID = worldPtr->getID();

   if (existingID == NULL)
   {
      return false;
   }

   if (strcmp(worldID, existingID) == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

mvIndex mvMotionAI_V2::createWorld(const char* worldID)
{
   mvWorld_V2* temp = NULL;

   // check for existing world using same id
   temp = worlds.findItemPtrInList(findExistingWorld, (void*) worldID);

   // if found, reject it
   if (temp != NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   temp = new (std::nothrow) mvWorld_V2(worldID);

   if (temp == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return worlds.addItem(temp);
}

mvIndex mvMotionAI_V2::getWorldByID(const char* worldID)
{
   return worlds.findItemInList(findExistingWorld, (void*) worldID);
}

mvCount mvMotionAI_V2::getNoOfWorlds()
{
   return worlds.getNoOfItems();
}

mvWorld_V2* mvMotionAI_V2::getWorldPtr(mvIndex index)
{
   return worlds.getClassPtr(index);
}

mvWorld_V2* mvMotionAI_V2::getWorldPtrByID(const char* worldID)
{
   return worlds.findItemPtrInList(findExistingWorld, (void*) worldID);
}

void mvMotionAI_V2::deleteAllWorlds()
{
   worlds.deleteAllItems();
}

void updatingWorlds(mvWorld_V2* worldPtr, void* extraPtr)
{
   mvFloat timeInSecs = 0;

   if (worldPtr != NULL && extraPtr != NULL)
   {
      timeInSecs = *((mvFloat*) extraPtr);
      worldPtr->worldStep(timeInSecs);
   }
}

void mvMotionAI_V2::allWorldsStepForward(mvFloat timeInSecs)
{
   mvFloat deltaTime = timeInSecs;

   worlds.applyToAllItems(updatingWorlds, (void*) &deltaTime);
}

void mvMotionAI_V2::applyToAllWorlds(void (someFunction)(mvWorld_V2*,void*),\
   void* extraPtr)
{
   worlds.applyToAllItems(someFunction,extraPtr);
}

void mvMotionAI_V2::applyToAllWorldsByIndex(void (someFunction)(mvIndex,void*),\
   void* extraPtr)
{
   //TODO : implement function
   worlds.applyToAllItemsByItemIndex(someFunction, extraPtr);
}

mvErrorEnum mvMotionAI_V2::loadDefaultBehaviours()
{
   mvErrorEnum error;
   mvBaseBehaviourLoader* tempLoader;

   // adding nullLoaders to protected enums such as
   // enum 1
   tempLoader = NULL;
   tempLoader = new (std::nothrow) mvNullLoader();
   // check for memory errors
   if (tempLoader == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = bFunctions.addBehaviourFunction(MV_GROUP_ENTRY, tempLoader);
   // if error occurs
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 2
   tempLoader = NULL;
   tempLoader = new (std::nothrow) mvNullLoader();
   // check for memory errors
   if (tempLoader == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = bFunctions.addBehaviourFunction(MV_EXISTING_BEHAVIOUR,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 3
   tempLoader = NULL;
   tempLoader = new (std::nothrow) mvNullLoader();
   // check for memory errors
   if (tempLoader == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = bFunctions.addBehaviourFunction(MV_EXISTING_GROUP_BEHAVIOUR,\
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

mvBaseBehaviour* mvMotionAI_V2::createNewBehaviour(mvOptionEnum type,\
   mvBaseBehaviour* defaultBehaviour)
{
   return bFunctions.createBehaviour(type, defaultBehaviour);
}

mvMotionAI_V2::~mvMotionAI_V2()
{
   deleteAllWorlds();
   bFunctions.freeAllBehaviourFunctions();
}

mvErrorEnum mvMotionAI_V2::addBehaviourFunction(mvOptionEnum type,\
   mvBaseBehaviourLoader* loader)
{
   return bFunctions.addBehaviourFunction(type, loader);
}

// TODO : implement these functions
mvErrorEnum mvMotionAI_V2::getWorldParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   return worlds.getItemParameter(worldIndex, paramFlag, option);
}

mvErrorEnum mvMotionAI_V2::getWorldParameteri(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex* index)
{
   return worlds.getItemParameteri(worldIndex, paramFlag, index);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterf(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return worlds.getItemParameterf(worldIndex, paramFlag, num);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterv(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   return worlds.getItemParameterv(worldIndex, paramFlag, numArray,\
      noOfElements);
}

mvErrorEnum mvMotionAI_V2::setWorldParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return worlds.setItemParameter(worldIndex, paramFlag, option);
}

mvErrorEnum mvMotionAI_V2::setWorldParameteri(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return worlds.setItemParameteri(worldIndex, paramFlag, index);
}

mvErrorEnum mvMotionAI_V2::setWorldParameterf(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return worlds.setItemParameterf(worldIndex, paramFlag, num);
}

mvErrorEnum mvMotionAI_V2::setWorldParameterv(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return worlds.setItemParameterv(worldIndex, paramFlag, numArray);
}

mvErrorEnum mvMotionAI_V2::getWorldParameters(mvIndex worldIndex,\
   const char* param, const char** option)
{
   return worlds.getItemParameters(worldIndex, param, option);
}

mvErrorEnum mvMotionAI_V2::getWorldParametersi(mvIndex worldIndex,\
   const char* param,  mvIndex* index)
{
   return worlds.getItemParametersi(worldIndex, param, index);
}

mvErrorEnum mvMotionAI_V2::getWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat* num)
{
   return worlds.getItemParametersf(worldIndex, param, num);
}

mvErrorEnum mvMotionAI_V2::getWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfElements)
{
   return worlds.getItemParametersv(worldIndex, param, numArray, noOfElements);
}

mvErrorEnum mvMotionAI_V2::setWorldParameters(mvIndex worldIndex,\
   const char* param, const char* option)
{
   return worlds.setItemParameters(worldIndex, param, option);
}

mvErrorEnum mvMotionAI_V2::setWorldParametersi(mvIndex worldIndex,\
   const char* param, mvIndex index)
{
   return worlds.setItemParametersi(worldIndex, param, index);
}

mvErrorEnum mvMotionAI_V2::setWorldParametersf(mvIndex worldIndex,\
   const char* param, mvFloat num)
{
   return worlds.setItemParametersf(worldIndex, param, num);
}

mvErrorEnum mvMotionAI_V2::setWorldParametersv(mvIndex worldIndex,\
   const char* param, mvFloat* numArray)
{
   return worlds.setItemParametersv(worldIndex, param, numArray);
}
/*
 * GLOBAL FUNCTIONS
 */

void mvMotionAI_V2_INIT()
{
   __mv__Motion__AI__Module.initMotionAI();
}

void mvMotionAI_V2_FREE()
{
   __mv__Motion__AI__Module.freeMotionAI();
}

mvErrorEnum mvMotionAI_V2_ALLWORLDSSTEPFORWARD(mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->allWorldsStepForward(timeInSecs);
   }
   return error;
}

mvIndex mvMotionAI_V2_CREATEWORLD(const char* id)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->createWorld(id);
   }
   else
   {
      return MV_NO_CURRENT_INDEX;
   }
}

mvErrorEnum mvMotionAI_V2_DELETEALLWORLDS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->deleteAllWorlds();
   }

   return error;
}

mvIndex mvMotionAI_V2_GETWORLDBYID(const char* id)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldByID(id);
   }
   else
   {
      return MV_NO_CURRENT_INDEX;
   }
}

mvWorld_V2* mvMotionAI_V2_GETWORLDPTRBYID(const char* id)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldPtrByID(id);
   }
   else
   {
      return NULL;
   }
}

mvWorld_V2* mvMotionAI_V2_GETWORLDPTR(mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldPtr(index);
   }
   else
   {
      return NULL;
   }
}

mvErrorEnum mvMotionAI_V2_APPLYTOALLWORLDS(\
   void (someFunction)(mvWorld_V2*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->applyToAllWorlds(someFunction,extraPtr);
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_APPLYTOALLWORLDSBYINDEX(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->applyToAllWorldsByIndex(someFunction,extraPtr);
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_LOADDEFAULTBEHAVIOURS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->loadDefaultBehaviours();
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_ADDBEHAVIOURFUNC(mvOptionEnum bType,\
   mvBaseBehaviourLoader* loader)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->addBehaviourFunction(bType, loader);
   }
   else
   {
      return error;
   }
}

mvBaseBehaviour* mvMotionAI_V2_CREATENEWBEHAVIOUR(mvOptionEnum type,\
   mvBaseBehaviour* defaultBehaviour)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->createNewBehaviour(type, defaultBehaviour);
   }
   else
   {
      return NULL;
   }
}

mvErrorEnum mvMotionAI_V2_CHECKIFINITIALISED()
{
   if (__mv__Motion__AI__Module.getMotionAI_V2_Ptr() != NULL)
   {
      return MV_NO_ERROR;
   }
   else
   {
      return MV_MOTIONAI_IS_NOT_INITIALISED;
   }
}



