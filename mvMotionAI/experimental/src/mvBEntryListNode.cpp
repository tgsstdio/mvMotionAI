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
#include "mvBEntryListNode.h"

mvBEntryListNode::mvBEntryListNode(mvFloat bNodeWeight = 0,\
   mvBEntry* behEntry = NULL,\
   mvFloat period = 1.0,
   mvFloat elaspedTime = 0)
{
   timer.setPeriod(period);
   timer.setElapsedTime(elaspedTime);
   bEntryPtr = behEntry;
   weight = bNodeWeight;
}

mvBEntry* mvBEntryListNode::getEntryPtr()
{
   return bEntryPtr;
}

mvBEntryTimer* mvBEntryListNode::getTimer()
{
   return &timer;
}

mvFloat mvBEntryListNode::getWeight() const
{
   return weight;
}

mvErrorEnum mvBEntryListNode::setEntryPtr(mvBEntry* behEntry)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::setWeight(mvFloat bNodeWeight)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::setParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntryListNode::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
      // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvBEntryListNode::~mvBEntryListNode()
{

}

