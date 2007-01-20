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
#include "mvBaseBehaviour.h"

mvBaseBehaviour::mvBaseBehaviour(mvOptionEnum type)
{
   bType = type;
}

mvOptionEnum mvBaseBehaviour::getType()
{
   return bType;
}

mvErrorEnum mvBaseBehaviour::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfElements)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvBaseBehaviour::~mvBaseBehaviour()
{
   // empty code
}

/**
 * \brief mvBaseBehaviourLoader constructor
 */
mvBaseBehaviourLoader::mvBaseBehaviourLoader()
{
   // empty code
};
