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
#ifndef MVGROUPBNODE_V2_H_INCLUDED
#define MVGROUPBNODE_V2_H_INCLUDED

#include "mvEnums.h"
#include "mvMotionAI-Types.h"
#include "mvBaseBehaviour.h"

class mvGroupBNode_V2
{
   private:
      mvIndex groupIndex;
      mvSuperBehaviourPtr grpBehaviour;
      bool behavEnabled;

   public:
      mvGroupBNode_V2(mvOptionEnum gbType, mvSuperBehaviourPtr mainBehaviour,\
         mvIndex grpIndex);
      bool isEnabled();
      void setEnabled(bool value);
      mvSuperBehaviourPtr getBehaviourPtr();
      mvIndex getGroup();
      mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      ~mvGroupBNode_V2();
};

#endif // MVGROUPBNODE_V2_H_INCLUDED
