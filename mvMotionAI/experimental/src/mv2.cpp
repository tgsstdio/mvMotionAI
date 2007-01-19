#include "mv2.h"

#include "mvMotionAI_V2-Central.h"
/**
 * \brief initialises the mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX void mvInitMotionAI()
{
   mvMotionAI_V2_INIT();
}

/**
 * \brief frees the mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX void mvFreeMotionAI()
{
   mvMotionAI_V2_FREE();
}

/**
 * \brief iterates all worlds in mvMotionAI library module
 */
MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAllWorldsStepForward(mvFloat timeInSecs)
{
   return mvMotionAI_V2_ALLWORLDSSTEPFORWARD(timeInSecs);
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvCreateWorld(const char* id)
{
   return mvMotionAI_V2_CREATEWORLD(id);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvDeleteAllWorlds()
{
   return mvMotionAI_V2_DELETEALLWORLDS();
}

MV_GLOBAL_FUNC_PREFIX mvIndex mvGetWorldByID(const char* id)
{
   return mvMotionAI_V2_GETWORLDBYID(id);
}

MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtrByID(const char* id)
{
   return mvMotionAI_V2_GETWORLDPTRBYID(id);
}

MV_GLOBAL_FUNC_PREFIX mvWorld_V2* mvGetWorldPtr(mvIndex index)
{
   return mvMotionAI_V2_GETWORLDPTR(index);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorlds(\
   void (someFunction)(mvWorld_V2*,void*),void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDS(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvApplyToAllWorldsByIndex(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr)
{
   return mvMotionAI_V2_APPLYTOALLWORLDSBYINDEX(someFunction, extraPtr);
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvLoadDefaultBehaviours()
{
   return mvMotionAI_V2_LOADDEFAULTBEHAVIOURS();
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvAddBehaviourFunction(mvOptionEnum bType,\
   mvBaseBehaviourLoader* loader)
{
   return mvMotionAI_V2_ADDBEHAVIOURFUNC(bType, loader);
}

MV_GLOBAL_FUNC_PREFIX mvBaseBehaviour* mvCreateNewBehaviour(mvOptionEnum type,\
   mvBaseBehaviour* defaultBehaviour)
{
   return mvMotionAI_V2_CREATENEWBEHAVIOUR(type, defaultBehaviour);
}

// TODO : world function implementation

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvWorldStep(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      worldPtr->worldStep(timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeBody(mvIndex worldIndex,\
   mvIndex bodyIndex, mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      return worldPtr->nudgeBody(bodyIndex,timeInSecs);
   }

   return error;
}

MV_GLOBAL_FUNC_PREFIX mvErrorEnum mvNudgeCurrentBody(mvIndex worldIndex,\
   mvFloat timeInSecs)
{
   mvErrorEnum error = mvMotionAI_V2_CHECKIFINITIALISED();
   mvWorld_V2* worldPtr = NULL;

   if (error == MV_NO_ERROR)
   {
      worldPtr = mvMotionAI_V2_GETWORLDPTR(worldIndex);
      return worldPtr->nudgeCurrentBody(timeInSecs);
   }

   return error;
}
