/**
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
#ifndef MV_BASE_BEHAVIOUR_H_
#define MV_BASE_BEHAVIOUR_H_
#include "mvWorld.h"
#include "mvVec3.h"
#include "mvBody.h"
#include "mvEnums.h"
#include "mvGroup.h"
#include "mvMotionAI-Types.h"

/**
 * for optimization purposes
 * less operations performed...
 */
enum mvBehaviourReturnType
{
   MV_NO_OPERATION,
   MV_VELOCITY_ONLY,
   MV_ACCELERATION_ONLY,
   MV_FORCE_ONLY,
   MV_FORCE_AND_VELOCITY,
   MV_FORCE_AND_ACCELERATION,
   MV_ACCELERATION_AND_VELOCITY,
   MV_ALL_OPERATIONS,
};

class mvBaseBehaviour
{
   private:
      mvOptionEnum bType;

   public:
      mvBaseBehaviour(mvOptionEnum type);
      mvOptionEnum getType();

      /*
      virtual const char* getAllPossibleParameters(mvCount* noOfElements) const;
      virtual mvEnum getParameterType(const char* params);
      virtual mvEnum getParametersForAllTypes(const char* paramFlag, mvFloat* variablesArray,
         mvEnum* statesArray, mvCount* noOfElements, mvEnum* returnTypes);
      virtual mvEnum setParametersForAllTypes(const char* paramFlag, mvFloat* variablesArray,
         mvEnum* statesArray, mvCount* noOfElements, mvEnum* paramsTypes);
      */

      //virtual mvErrorEnum getParameters(const char* paramFlag, mvOptionEnum* option);
      //virtual mvErrorEnum getParametersi(const char* paramFlag, mvIndex* index);
      //virtual mvErrorEnum getParametersf(const char* paramFlag, mvFloat* num);
      //virtual mvErrorEnum getParametersv(const char* paramFlag, mvFloat* numArray, mvCount* noOfElements);

      virtual mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      virtual mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex index);
      virtual mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      virtual mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements);

      //virtual mvErrorEnum setParameters(const char* paramFlag, mvEnum* option);
      //virtual mvErrorEnum setParameters(const char* paramFlag, mvIndex* option);
      //virtual mvErrorEnum setParametersf(const char* paramFlag, mvFloat num);
      //virtual mvErrorEnum setParametersv(const char* paramFlag, mvFloat* numArray);

      virtual mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      virtual mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      virtual mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      virtual mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      //virtual mvBaseBehaviour* createGroupEntry(mvBaseBehaviour* options);
	   //virtual mvBaseBehaviour* createBodyEntry(mvBaseBehaviour* options);

	   virtual void groupOperation(mvWorld* world, mvGroup* groupPtr) = 0;

	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity) = 0;

      virtual ~mvBaseBehaviour();
};

//function class


class mvBaseBehaviourLoader
{
   public:
      //mvBaseBehaviourLoader(mvOptionEnum bType);
      virtual mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehaviour) = 0;
};

//typedef mvBaseBehaviour* (loadBehaviour)(mvBaseBehaviour* defaultBehaviour);
#endif
