/**
 * \file mvMotionAI.cpp
 *
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
 */

#include "mvMotionAI.h"
#include "mvLuaScript.h"
#include "mvMotionAI-Utilities.h"

#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
mvMotionAI* __motionAI_Central_Module = NULL;
#else
mvMotionAI __motionAI_Central_Module;
#endif

void mvInitMotionAI()
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module == NULL)
   {
     __motionAI_Central_Module = new mvMotionAI();
      if (__motionAI_Central_Module == NULL)
        // std::cout << "hello" << std::endl;

   }
#endif
}

void mvFreeMotionAI()
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      delete __motionAI_Central_Module;
      __motionAI_Central_Module = NULL;
   }
#endif
}

void mvAllWorldsStepForward(mvFloat timeInSecs)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      __motionAI_Central_Module->allWorldsStepForward(timeInSecs);
   }
#else
   __motionAI_Central_Module.allWorldsStepForward(timeInSecs);
#endif
}

mvWorld* mvGetWorldPtrByID(char* id)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      return __motionAI_Central_Module->getWorldByID(id);
   }
   else
   {
      return NULL;
   }
#else
   return __motionAI_Central_Module.getWorldByID(id);
#endif
}

mvWorld* mvAddWorld(char* id)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      return __motionAI_Central_Module->getWorldByIndex(__motionAI_Central_Module->addWorld(id));
   }
   else
   {
      return NULL;
   }
#else
   return __motionAI_Central_Module.getWorldByIndex(__motionAI_Central_Module.addWorld(id));
#endif
}

void mvRemoveAllWorlds()
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      __motionAI_Central_Module->removeAllWorlds();
   }
#else
   __motionAI_Central_Module.removeAllWorlds();
#endif
}

mvWorld* mvGetWorldByIndex(mvIndex index)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      return __motionAI_Central_Module->getWorldByIndex(index);
   }
   else
   {
      return NULL;
   }
#else
   return __motionAI_Central_Module.getWorldByIndex(index);
#endif
}

mvWorld* mvGetWorldByID(char* worldID)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      return __motionAI_Central_Module->getWorldByID(worldID);
   }
   else
   {
      return NULL;
   }
#else
   return __motionAI_Central_Module.getWorldByID(worldID);
#endif
}

void mvApplyToAllWorlds(void (someFunction)(mvWorld*,void*),void* extraPtr)
{
#ifdef __MV_MOTIONAI_CENTRAL_MODULE_PTR
   if (__motionAI_Central_Module != NULL)
   {
      __motionAI_Central_Module->applyToAllWorlds(someFunction,extraPtr);
   }
#else
      __motionAI_Central_Module.applyToAllWorlds(someFunction,extraPtr);
#endif
}

mvMotionAI::mvMotionAI()
{
  noOfWorlds = 0;
}

mvIndex mvMotionAI::addWorld(char* worldID)
{
   mvWorld* temp = NULL;

   temp = new mvWorld(worldID);
   mvWorlds.push_back(temp);
   ++noOfWorlds;

   return noOfWorlds;
}

mvIndex mvMotionAI::getWorldIndex(char* worldID)
{
   std::vector<mvWorld*>::iterator i;
   mvCount count = 1;
   mvWorld* temp = NULL;
   char* tempID = NULL;

   for ( i = mvWorlds.begin(); i != mvWorlds.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         tempID = temp->getWorldID();
         if (tempID != NULL && strcmp(tempID, worldID) == 0)
         {
            return count;
         }
      }
      ++count;
   }
   return 0;
}

mvCount mvMotionAI::getNoOfWorlds()
{
   return noOfWorlds;
}mvWorld* mvMotionAI::getWorldByIndex(mvIndex index)
{
   /*
   if (index < 1 || index > noOfWorlds)
   {
      return NULL;
   }
   else
   {
      return mvWorlds[index-1];
   }
   */
   /**
    * 00-01-10 Now using mv utilities declarations
    */
   return mvGetClassPtr<mvWorld>(mvWorlds,index, noOfWorlds);
}

mvWorld* mvMotionAI::getWorldByID(char* worldID)
{
   std::vector<mvWorld*>::iterator i;
   mvWorld* temp = NULL;
   char* tempID = NULL;

   for ( i = mvWorlds.begin(); i != mvWorlds.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         tempID = temp->getWorldID();
         if (tempID != NULL && strcmp(tempID, worldID) == 0)
         {
            return temp;
         }
      }
   }
   return NULL;
}

void mvMotionAI::removeAllWorlds()
{
   /*
   std::vector<mvWorld*>::iterator i;
   mvWorld* temp = NULL;

   for ( i = mvWorlds.begin(); i != mvWorlds.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         delete temp;
         *i = NULL;
      }
   }
   noOfWorlds = 0;
   */

   /*
    * 00-01-10 Now using mv utilities declarations
    */
   mvIndex dummyNum = 0;
   mvRemoveAllClassObjectsFromList<mvWorld>(mvWorlds, dummyNum, noOfWorlds);
}

mvMotionAI::~mvMotionAI()
{
  removeAllWorlds();
}

void mvMotionAI::allWorldsStepForward(mvFloat timeInSecs)
{
   std::vector<mvWorld*>::iterator i;
   mvWorld* temp = NULL;

   for ( i = mvWorlds.begin(); i != mvWorlds.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         temp->mvWorldStep(timeInSecs);
      }
   }
}

void mvMotionAI::applyToAllWorlds(void (someFunction)(mvWorld*,void*),void* extraPtr)
{
   mvApplyFunctionToAllItemsInListVector<mvWorld>(mvWorlds,someFunction, extraPtr);
}
