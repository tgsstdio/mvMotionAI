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
 *
 * Log
 * Version     Date
 * 00-01-31    20/1/07
 *
 * - changed function signatures & removed commented code
 *
 * 00-01-29    11/1/07
 *
 * - changing bodyOperation signature to 5+ parameters & return type to only one
 *   super class for result and input
 */
#ifndef MV_BASE_BEHAVIOUR_H_
#define MV_BASE_BEHAVIOUR_H_

#include "mvMotionAI-Types.h"
#include "mvWorld.h"
#include "mvVec3.h"
#include "mvBody.h"
#include "mvEnums.h"
#include "mvGroup.h"

#include "mvBehaviourResult.h"

class mvBaseBehaviour
{
   private:
      mvOptionEnum bType;

   public:
      mvBaseBehaviour(mvOptionEnum type);
      mvOptionEnum getType();

      virtual mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      virtual mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* index);
      virtual mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      virtual mvErrorEnum getParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfElements);

      virtual mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      virtual mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      virtual mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      virtual mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

	   virtual void groupOp(mvWorld* world, mvGroup* groupPtr) = 0;
      virtual void bodyOp(mvBehaviourResult* resultModule) = 0;

      virtual ~mvBaseBehaviour();
};

class mvBaseBehaviourLoader
{
   public:
      virtual mvBaseBehaviour* operator()(\
         mvBaseBehaviour* defaultBehaviour) = 0;
      mvBaseBehaviourLoader();
      virtual ~mvBaseBehaviourLoader();
};

#endif
