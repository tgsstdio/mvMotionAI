/**
 *\file mvMotionAI.h
 * Copyright (c) 2006 David Young.
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
 *
 *Log:
 *
 *version    date      changes
 *00-01-21   24/11/06  - changed  void mvLoadLuaScriptFile to mvErrorEnum mvLua_LoadScriptFile
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
 */

#ifndef MV_MOTION_AI_H_
#define MV_MOTION_AI_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include "mvWorld.h"
#include "mvMotionAI-Types.h"

/*
#ifndef MV_MOTIONAI_LUA_FLAG
#define MV_MOTIONAI_LUA_FLAG
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif
*/

//static const mvCount MAX_NO_OF_WORLDS = 10;

void mvInitMotionAI();
mvErrorEnum mvLua_LoadScriptFile(char* fileName);
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
 */
// TODO: dynamic behaviour loading by array of derived function objects.
// TODO: add single class to handle shapes.
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
