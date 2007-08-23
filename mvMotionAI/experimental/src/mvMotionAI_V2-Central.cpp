#include "mvMotionAI_V2-Central.h"
#include <cstring>
#include <new>

/**
 * default behaviours/actions
 */
#include "mvNullLoader.h"
#include "mvSeek.h"

/**
 * default forces
 */
#include "mvGravityForce.h"
#include "mvUniformForce.h"
#include "mvUniformAccelForce.h"
#include "mvUniformShiftForce.h"

mvMotionAI_V2_SUPERCLASS __mv__Motion__AI__Module;

// function signatures
bool findExistingWorld(mvWorld_V2* worldPtr, void* extraPtr);
void updatingWorlds(mvWorld_V2* worldPtr, void* extraPtr);

mvMotionAI_V2_SUPERCLASS::mvMotionAI_V2_SUPERCLASS()
{
   centralPtr = MV_NULL;
}

mvErrorEnum  mvMotionAI_V2_SUPERCLASS::initMotionAI()
{
   if (centralPtr == MV_NULL)
   {
      centralPtr = new mvMotionAI_V2();
      if (centralPtr == MV_NULL)
         return MV_INVALID_MEMORY_ALLOCATION;
   }
   return MV_NO_ERROR;
}

void mvMotionAI_V2_SUPERCLASS::freeMotionAI()
{
   if (centralPtr != MV_NULL)
   {
      delete centralPtr;
      centralPtr = MV_NULL;
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
   const char* worldID = MV_NULL;
   const char* existingID = MV_NULL;

   if (worldPtr == MV_NULL)
   {
      return false;
   }

   if (extraPtr == MV_NULL)
   {
      return false;
   }

   worldID = (const char*) extraPtr;
   existingID = worldPtr->getID();

   if (existingID == MV_NULL)
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
   mvWorldPtr temp = MV_NULL;

   // check for existing world using same id
   temp = worlds.findItemPtrInList(findExistingWorld, (void*) worldID);

   // if found, reject it
   if (temp != MV_NULL)
   {
      return MV_NULL;
   }

   temp = new (std::nothrow) mvWorld(worldID);
   puts(temp->getID());

   if (temp == MV_NULL)
   {
      return MV_NULL;
   }
   temp->setActionLoader(&bFunctions);
   temp->setForceLoader(&fFunctions);

   return worlds.addItem(temp);
}

mvIndex mvMotionAI_V2::getCurrentWorld() const
{
   return worlds.getCurrentIndex();
}

mvIndex mvMotionAI_V2::setCurrentWorld(mvIndex index)
{
   return worlds.setCurrentIndex(index);
}

mvWorldPtr mvMotionAI_V2::getCurrentWorldPtr()
{
   return worlds.getCurrentClassPtr();
}

mvIndex mvMotionAI_V2::getWorldByID(const char* worldID)
{
   return worlds.findItemInList(findExistingWorld, (void*) worldID);
}

mvCount mvMotionAI_V2::getNoOfWorlds() const
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

   if (worldPtr != MV_NULL && extraPtr != MV_NULL)
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
   worlds.applyToAllItemsByItemIndex(someFunction, extraPtr);
}

mvErrorEnum mvMotionAI_V2_LOADDEFAULTBEHAVIOURS(mvActionLoaderListPtr
   loader)
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
   tempLoader = new (std::nothrow) mvNullLoader();
   // check for memory errors
   if (tempLoader == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }
   error = loader->addFactoryFunction(MV_GROUP_ENTRY, tempLoader);
   // if error occurs
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   // enum 2
   tempLoader = MV_NULL;
   tempLoader = new (std::nothrow) mvNullLoader();
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
   tempLoader = new (std::nothrow) mvNullLoader();
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
   tempLoader = new (std::nothrow) mvCreateSeeks();
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

   // now adding defined functions
   //TODO : add more behaviours
   return MV_NO_ERROR;
}

mvErrorEnum mvMotionAI_V2_LOADDEFAULTFORCES(mvForceLoaderListPtr
   loader)
{
   mvErrorEnum error;
   mvBaseForceLoaderPtr tempLoader;

   if (loader == MV_NULL)
   {
      return MV_FUNCTION_LOADER_LIST_PTR_IS_NULL;
   }

   tempLoader = MV_NULL;
   tempLoader = new (std::nothrow) mvGravityForceLoader();
   error = loader->addFactoryFunction(MV_GRAVITY,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new (std::nothrow) mvUniformForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_FORCE,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new (std::nothrow) mvUniformAccelForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_ACCELERATION,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }

   tempLoader = MV_NULL;
   tempLoader = new (std::nothrow) mvUniformShiftForceLoader();
   error = loader->addFactoryFunction(MV_UNIFORM_SHIFT,\
      tempLoader);
   if (error != MV_NO_ERROR)
   {
      delete tempLoader;
      return error;
   }
   // todo : add more forces

   return MV_NO_ERROR;
}

mvErrorEnum mvMotionAI_V2::loadDefaultActions()
{
   return mvMotionAI_V2_LOADDEFAULTBEHAVIOURS(&bFunctions);
}

mvBaseAction* mvMotionAI_V2::createNewBehaviour(mvOptionEnum type,\
   mvBaseActionPtr defaultBehaviour)
{
   return bFunctions.createAClassPtr(type, defaultBehaviour);
}

void mvMotionAI_V2::freeDefaultActions()
{
   bFunctions.freeAllFactoryFunctions();
}

mvErrorEnum mvMotionAI_V2::loadDefaultForces()
{
   return mvMotionAI_V2_LOADDEFAULTFORCES(&fFunctions);
}

void mvMotionAI_V2::freeDefaultForces()
{
   fFunctions.freeAllFactoryFunctions();
}

mvErrorEnum mvMotionAI_V2::addForceFunction(mvOptionEnum type,\
   mvBaseForceLoaderPtr loader)
{
   return fFunctions.addFactoryFunction(type, loader);
}

mvBaseForcePtr mvMotionAI_V2::createNewForce(mvOptionEnum type)
{
   return fFunctions.createAClassPtr(type,MV_NULL);
}

mvMotionAI_V2::~mvMotionAI_V2()
{
   deleteAllWorlds();
   freeDefaultActions();
   freeDefaultForces();
}

mvErrorEnum mvMotionAI_V2::addBehaviourFunction(mvOptionEnum type,\
   mvBaseActionLoader* loader)
{
   return bFunctions.addFactoryFunction(type, loader);
}

mvErrorEnum mvMotionAI_V2::getWorldParameter(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return worlds.getItemParameter(worldIndex, paramFlag, option);
}

mvErrorEnum mvMotionAI_V2::getWorldParameteri(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return worlds.getItemParameteri(worldIndex, paramFlag, index);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterf(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return worlds.getItemParameterf(worldIndex, paramFlag, num);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterv(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements) const
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

mvErrorEnum mvMotionAI_V2::getWorldParameter_str(mvIndex worldIndex,\
   const char* param, const char** option) const
{
   return worlds.getItemParameter_str(worldIndex, param, option);
}

mvErrorEnum mvMotionAI_V2::getWorldParameteri_str(mvIndex worldIndex,\
   const char* param,  mvIndex* index) const
{
   return worlds.getItemParameteri_str(worldIndex, param, index);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterf_str(mvIndex worldIndex,\
   const char* param, mvFloat* num) const
{
   return worlds.getItemParameterf_str(worldIndex, param, num);
}

mvErrorEnum mvMotionAI_V2::getWorldParameterv_str(mvIndex worldIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfElements) const
{
   return worlds.getItemParameterv_str(worldIndex, param, numArray, noOfElements);
}

mvErrorEnum mvMotionAI_V2::setWorldParameter_str(mvIndex worldIndex,\
   const char* param, const char* option)
{
   return worlds.setItemParameter_str(worldIndex, param, option);
}

mvErrorEnum mvMotionAI_V2::setWorldParameteri_str(mvIndex worldIndex,\
   const char* param, mvIndex index)
{
   return worlds.setItemParameteri_str(worldIndex, param, index);
}

mvErrorEnum mvMotionAI_V2::setWorldParameterf_str(mvIndex worldIndex,\
   const char* param, mvFloat num)
{
   return worlds.setItemParameterf_str(worldIndex, param, num);
}

mvErrorEnum mvMotionAI_V2::setWorldParameterv_str(mvIndex worldIndex,\
   const char* param, mvFloat* numArray)
{
   return worlds.setItemParameterv_str(worldIndex, param, numArray);
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
   mvMotionAI_V2* modulePtr = MV_NULL;

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
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->createWorld(id);
   }
   else
   {
      return MV_NULL;
   }
}

mvErrorEnum mvMotionAI_V2_DELETEALLWORLDS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

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
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldByID(id);
   }
   else
   {
      return MV_NULL;
   }
}

mvWorld_V2* mvMotionAI_V2_GETWORLDPTRBYID(const char* id)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldPtrByID(id);
   }
   else
   {
      return MV_NULL;
   }
}

mvWorld_V2* mvMotionAI_V2_GETWORLDPTR(mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldPtr(index);
   }
   else
   {
      return MV_NULL;
   }
}

mvErrorEnum mvMotionAI_V2_APPLYTOALLWORLDS(\
   void (someFunction)(mvWorld_V2*,void*),void* extraPtr)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

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
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->applyToAllWorldsByIndex(someFunction,extraPtr);
   }

   return error;
}

/*
mvErrorEnum mvMotionAI_V2_INITDEFAULTBODIES()
{
   // todo : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}
*/

mvErrorEnum mvMotionAI_V2_INITDEFAULTFORCES()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->loadDefaultForces();
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_INITALLDEFAULTS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();

   if (error == MV_NO_ERROR)
   {
      mvMotionAI_V2_INITDEFAULTFORCES();
     // mvMotionAI_V2_INITDEFAULTBODIES();
      mvMotionAI_V2_INITDEFAULTACTIONS();
   }
   return error;
}

mvErrorEnum mvMotionAI_V2_FREEDEFAULTACTIONS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->freeDefaultActions();
   }

   return error;
}
/*
mvErrorEnum mvMotionAI_V2_FREEDEFAULTBODIES()
{
   // todo : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}
*/

mvErrorEnum mvMotionAI_V2_FREEDEFAULTFORCES()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->freeDefaultForces();
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_FREEALLDEFAULTS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();

   if (error == MV_NO_ERROR)
   {
    //  mvMotionAI_V2_FREEDEFAULTBODIES();
      mvMotionAI_V2_FREEDEFAULTFORCES();
      mvMotionAI_V2_INITDEFAULTACTIONS();
   }
   return error;
}

mvErrorEnum mvMotionAI_V2_INITDEFAULTACTIONS()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      modulePtr->loadDefaultActions();
   }

   return error;
}

mvErrorEnum mvMotionAI_V2_ADDBEHAVIOURFUNC(mvOptionEnum bType,\
   mvBaseActionLoaderPtr loader)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

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

mvBaseActionPtr mvMotionAI_V2_CREATENEWBEHAVIOUR(mvOptionEnum type,\
   mvBaseActionPtr defaultBehaviour)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->createNewBehaviour(type, defaultBehaviour);
   }
   else
   {
      return MV_NULL;
   }
}

mvErrorEnum mvMotionAI_V2_ADDFORCEFUNC(mvOptionEnum fType,\
   mvBaseForceLoaderPtr loader)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->addForceFunction(fType, loader);
   }
   else
   {
      return error;
   }
}

mvBaseForcePtr mvMotionAI_V2_CREATENEWFORCE(mvOptionEnum type)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->createNewForce(type);
   }
   else
   {
      return MV_NULL;
   }
}

mvErrorEnum mvMotionAI_V2_CHECKIFINITIALISED()
{
   if (__mv__Motion__AI__Module.getMotionAI_V2_Ptr() != MV_NULL)
   {
      return MV_NO_ERROR;
   }
   else
   {
      return MV_MOTIONAI_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETER(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameter(worldIndex, paramFlag, option);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERI(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameteri(worldIndex, paramFlag, index);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERF(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameterf(worldIndex, paramFlag, num);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERV(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameterv(worldIndex, paramFlag, numArray);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETER(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameter(worldIndex, paramFlag, option);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERI(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex* index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameteri(worldIndex, paramFlag, index);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERF(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameterf(worldIndex, paramFlag, num);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERV(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameterv(worldIndex, paramFlag, numArray,\
         noOfElements);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERS(mvIndex worldIndex,\
   const char* param, const char* option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameter_str(worldIndex, param, option);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSI(mvIndex worldIndex,\
   const char* param, mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameteri_str(worldIndex, param, index);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSF(mvIndex worldIndex,\
   const char* param, mvFloat num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameterf_str(worldIndex, param, num);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSV(mvIndex worldIndex,\
   const char* param, mvFloat* numArray)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setWorldParameterv_str(worldIndex, param, numArray);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERS(mvIndex worldIndex,\
   const char* param, const char** option)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameter_str(worldIndex, param, option);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSI(mvIndex worldIndex,\
   const char* param, mvIndex* index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameteri_str(worldIndex, param, index);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSF(mvIndex worldIndex,\
   const char* param, mvFloat* num)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameterf_str(worldIndex, param, num);
   }
   else
   {
      return error;
   }
}

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSV(mvIndex worldIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfElements)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getWorldParameterv_str(worldIndex, param, numArray,\
         noOfElements);
   }
   else
   {
      return error;
   }
}

mvIndex mvMotionAI_V2_GETCURRENTWORLD()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getCurrentWorld();
   }
   else
   {
      return MV_NULL;
   }
}

mvWorldPtr mvMotionAI_V2_GETCURRENTWORLDPTR()
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->getCurrentWorldPtr();
   }
   else
   {
      return MV_NULL;
   }
}

mvIndex mvMotionAI_V2_SETCURRENTWORLD(mvIndex index)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvMotionAI_V2* modulePtr = MV_NULL;

   if (error == MV_NO_ERROR)
   {
      modulePtr = __mv__Motion__AI__Module.getMotionAI_V2_Ptr();
      return modulePtr->setCurrentWorld(index);
   }
   else
   {
      return MV_NULL;
   }
}

