#ifndef MV_MOTION_AI_H_
#define MV_MOTION_AI_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include "mvWorld.h"
#include "mvMotionAI-Types.h"

#ifndef MV_MOTIONAI_LUA_FLAG
#define MV_MOTIONAI_LUA_FLAG
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif

//static const mvCount MAX_NO_OF_WORLDS = 10;

void mvInitMotionAI();
void mvLoadLuaScriptFile(char* fileName);
void mvFreeMotionAI();
void mvAllWorldsStepForward(mvFloat timeInSecs);
mvWorld* mvGetWorldByID(char* id);
mvWorld* mvAddWorld(char* id);
void mvRemoveAllWorlds();
mvWorld* mvGetWorldPtrByID(char* id);
mvWorld* mvGetWorldByIndex(mvIndex index);
void mvApplyToAllWorlds(void (someFunction)(mvWorld*,void*),void* extraPtr);

/**
 * \class mvMotionAI
 * \brief movement or direction steering for 3D objects based, copied and 
 * translated from source code of OpenSteer AI steering 2006.
 *
 *
 *Log:
 *
 *version    date      changes
 *
 *00-01-00   10/04/06   - new naming conventions - mv(blah)
 *
 *00-00-04   22/02/06   - Hopefully created a overall central module 
 *                      and many world objects
 *
 *00-00-01   7/2/06    created header file based on Opensteer
 *                     - created a overall AI module called 
 *                       MotionAI
 *
 *                     - stubs of vehicles and obstacles
 *
 *                     - To use library, declare global instance of 
 *                     aiModule.
 *
 *                     - introduced Vec3 and Utilities from OpenSteer
 *                     into project
 *
 */

class mvMotionAI
{
   private:
     //mvIndex searchWorldByName(char* worldID);
     //mvIndex currentWorld;
     mvCount noOfWorlds;     

   public:
     std::vector<mvWorld*> mvWorlds;

     mvMotionAI();
     mvIndex addWorld(char* worldID);
     mvIndex getWorldIndex(char* worldID);
     mvCount getNoOfWorlds();
     mvWorld* getWorldByIndex(mvIndex index);
     mvWorld* getWorldByID(char* worldID);
     void removeAllWorlds();
     void allWorldsStepForward(mvFloat timeInSecs);
     ~mvMotionAI();
     void applyToAllWorlds(void (someFunction)(mvWorld*,void*),void* extraPtr);
};


#define __MV_MOTIONAI_CENTRAL_MODULE_PTR 0
#undef __MV_MOTIONAI_CENTRAL_MODULE_PTR
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
extern mvMotionAI* __motionAI_Central_Module;
#else
extern mvMotionAI __motionAI_Central_Module;
#endif


#endif
