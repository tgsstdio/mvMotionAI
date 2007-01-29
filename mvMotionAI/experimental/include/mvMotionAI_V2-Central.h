/**
 * Copyright (c) 2006, 2007 David Young.
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

#ifndef MVMOTIONAI_V2_CENTRAL_H_INCLUDED
#define MVMOTIONAI_V2_CENTRAL_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvBaseBehaviour.h"
#include "mvBehavFuncList.h"
#include "mvWorld2.h"
#include "mvList.h"

/* TODO : implement v2 motion ai functions */

void mvMotionAI_V2_INIT();
void mvMotionAI_V2_FREE();
mvErrorEnum mvMotionAI_V2_ALLWORLDSSTEPFORWARD(mvFloat timeInSecs);
mvIndex mvMotionAI_V2_CREATEWORLD(const char* id);
mvErrorEnum mvMotionAI_V2_DELETEALLWORLDS();
mvIndex mvMotionAI_V2_GETWORLDBYID(const char* id);
mvWorld_V2* mvMotionAI_V2_GETWORLDPTRBYID(const char* id);
mvWorld_V2* mvMotionAI_V2_GETWORLDPTR(mvIndex index);
mvErrorEnum mvMotionAI_V2_APPLYTOALLWORLDS(\
   void (someFunction)(mvWorld_V2* ,void*),void* extraPtr);
mvErrorEnum mvMotionAI_V2_APPLYTOALLWORLDSBYINDEX(\
   void(someFunction)(mvIndex, void* extraPtr), void* extraPtr);
mvErrorEnum mvMotionAI_V2_LOADDEFAULTBEHAVIOURS();
mvErrorEnum mvMotionAI_V2_ADDBEHAVIOURFUNC(mvOptionEnum bType,\
   mvBaseBehaviourLoader* loader);
mvSuperBehaviourPtr mvMotionAI_V2_CREATENEWBEHAVIOUR(mvOptionEnum type,\
   mvSuperBehaviourPtr  defaultBehaviour);
mvErrorEnum mvMotionAI_V2_CHECKIFINITIALISED();

// GLOBAL FUNCTIONS
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETER(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum option);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERI(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex index);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERF(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat num);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERV(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray);

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETER(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERI(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvIndex* index);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERF(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* num);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERV(mvIndex worldIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements);

mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERS(mvIndex worldIndex,\
   const char* param, const char* option);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSI(mvIndex worldIndex,\
   const char* param, mvIndex index);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSF(mvIndex worldIndex,\
   const char* param, mvFloat num);
mvErrorEnum mvMotionAI_V2_SETWORLDPARAMETERSV(mvIndex worldIndex,\
   const char* param, mvFloat* numArray);

mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERS(mvIndex worldIndex, const char* param,\
   const char** option);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSI(mvIndex worldIndex, const char* param,\
   mvIndex* index);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSF(mvIndex worldIndex, const char* param,\
   mvFloat* num);
mvErrorEnum mvMotionAI_V2_GETWORLDPARAMETERSV(mvIndex worldIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfElements);

class mvMotionAI_V2
{
   public:
      mvBehavFuncList bFunctions;
      mvItemList<mvWorld_V2> worlds;

      mvMotionAI_V2();
      mvIndex createWorld(const char* worldID);
      mvIndex getWorldByID(const char* worldID);
      mvCount getNoOfWorlds();
      mvWorld_V2* getWorldPtr(mvIndex index);
      mvWorld_V2* getWorldPtrByID(const char* worldID);
      void deleteAllWorlds();
      void allWorldsStepForward(mvFloat timeInSecs);
      void applyToAllWorlds(void (someFunction)(mvWorld_V2*,void*),void* extraPtr);
      void applyToAllWorldsByIndex(void (someFunction)(mvIndex,void*),\
         void* extraPtr);
      mvErrorEnum loadDefaultBehaviours();
      mvErrorEnum addBehaviourFunction(mvOptionEnum type,\
         mvBaseBehaviourLoader* loader);
      mvBaseBehaviour* createNewBehaviour(mvOptionEnum type,\
         mvBaseBehaviour* defaultBehaviour);

      // TODO : implement these functions
      mvErrorEnum getWorldParameter(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getWorldParameteri(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getWorldParameterf(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getWorldParameterv(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfElements);

      mvErrorEnum setWorldParameter(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setWorldParameteri(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setWorldParameterf(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setWorldParameterv(mvIndex worldIndex, mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getWorldParameters(mvIndex worldIndex, const char* param,\
         const char** option);
      mvErrorEnum getWorldParametersi(mvIndex worldIndex, const char* param,\
         mvIndex* index);
      mvErrorEnum getWorldParametersf(mvIndex worldIndex, const char* param,\
         mvFloat* num);
      mvErrorEnum getWorldParametersv(mvIndex worldIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfElements);

      mvErrorEnum setWorldParameters(mvIndex worldIndex, const char* param,\
         const char* option);
      mvErrorEnum setWorldParametersi(mvIndex worldIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setWorldParametersf(mvIndex worldIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setWorldParametersv(mvIndex worldIndex, const char* param,\
         mvFloat* numArray);

      ~mvMotionAI_V2();
};

class mvMotionAI_V2_SUPERCLASS
{
   private:
      mvMotionAI_V2* centralPtr;

   public:
      mvMotionAI_V2* getMotionAI_V2_Ptr();
      mvMotionAI_V2_SUPERCLASS();
      mvErrorEnum  initMotionAI();
      void freeMotionAI();
      ~mvMotionAI_V2_SUPERCLASS();
};

/**
 * \brief one item superclass
 */
extern mvMotionAI_V2_SUPERCLASS __mv__Motion__AI__Module;


#endif // MVMOTIONAI_V2-CENTRAL_H_INCLUDED
