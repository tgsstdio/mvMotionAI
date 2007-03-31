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
#ifndef MVBEHAVIOUR_V2_H_INCLUDED
#define MVBEHAVIOUR_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvBaseBehaviour.h"
#include MV_ENUMS_HEADER_FILE_H_

/**
 * \class mvBehaviour
 * \brief a global behaviour that all bodies can use.
 */

class mvBehaviour_V2
{
   private:
      bool behavEnabled;
      mvBaseBehaviourPtr behavPtr;

   public:
      mvBehaviour_V2(mvBaseBehaviourPtr bPtr);
      bool isEnabled();
      void setEnabled(bool value);
      mvBaseBehaviourPtr getBehaviourPtr();

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters);
      ~mvBehaviour_V2();
};

#endif // MVBEHAVIOUR_V2_H_INCLUDED
