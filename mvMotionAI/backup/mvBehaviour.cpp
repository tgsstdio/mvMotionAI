/**
 * \file mvBehaviour.cpp
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

#include "mvBehaviour.h"
//#include "mvBehaviour-Type.h"

void mvBehaviour::initDefault()
{
   behavData = NULL;
}

mvBehaviour::mvBehaviour(mvOptionEnum type)
{
   initDefault();
   behavData = new mvBehaviourEntry(type);
}

mvBehaviour::mvBehaviour(const mvBehaviour& rhs)
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   behavData = new mvBehaviourEntry();
   *behavData = *rhs.behavData;
}

const mvBehaviour& mvBehaviour::operator=(const mvBehaviour& rhs)
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   behavData = new mvBehaviourEntry();
   *behavData = *rhs.behavData;
   return *this;
}

mvBehaviourEntry* mvBehaviour::getData() const
{
   return behavData;
}

mvOptionEnum mvBehaviour::getType() const
{
   if (behavData == NULL)
   {
      return MV_NON_BEHAVIOUR_TYPE;
   }
   else
   {
      return behavData->getType();
   }
}

mvBehaviour::~mvBehaviour()
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }
}

mvErrorEnum mvBehaviour::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (behavData != NULL)
   {
      return behavData->getParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   if (behavData != NULL)
   {
      return behavData->getParameter(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   if (behavData != NULL)
   {
      return behavData->getParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   if (behavData != NULL)
   {
      return behavData->getParameterv(paramFlag,numArray,noOfElements);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (behavData != NULL)
   {
      return behavData->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   if (behavData != NULL)
   {
      return behavData->setParameter(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (behavData != NULL)
   {
      return behavData->setParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (behavData != NULL)
   {
      return behavData->setParameterv(paramFlag,numArray);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}
