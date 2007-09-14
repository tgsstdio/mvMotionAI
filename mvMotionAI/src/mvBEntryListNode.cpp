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
#include <mv/mvBEntryListNode.h>

mvBEntryListNode::mvBEntryListNode(mvOptionEnum type, mvIndex behaviourIndex,\
   mvIndex groupIndex, mvBaseActionPtr actionPtr, mvFloat bNodeWeight,\
   mvFloat period, mvFloat elaspedTime)
 {
   behaviourEntry = new mvBEntry(type, behaviourIndex,\
      groupIndex, actionPtr);

   entryFlags.getTimerPtr()->setPeriod(period);
   entryFlags.getTimerPtr()->setElapsedTime(elaspedTime);
   entryFlags.setWeight(bNodeWeight);
}

mvBEntryPtr mvBEntryListNode::getEntryPtr()
{
   return behaviourEntry;
}

mvTimerPtr mvBEntryListNode::getTimer()
{
   return entryFlags.getTimerPtr();
}

mvFloat mvBEntryListNode::getWeight() const
{
   return entryFlags.getWeight();
}

bool mvBEntryListNode::isEnabled() const
{
   return entryFlags.enabled;
}

mvErrorEnum mvBEntryListNode::setWeight(mvFloat bNodeWeight)
{
   return entryFlags.setWeight(bNodeWeight);
}

mvErrorEnum mvBEntryListNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.getParameteri(paramFlag, index);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->getParameteri(paramFlag, index);
}

mvErrorEnum mvBEntryListNode::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.getParameter(paramFlag, option);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->getParameter(paramFlag, option);
}

mvErrorEnum mvBEntryListNode::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.getParameterf(paramFlag, num);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->getParameterf(paramFlag, num);
}

mvErrorEnum mvBEntryListNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (behaviourEntry == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.getParameterv(paramFlag, numArray,\
      noOfParameters);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      *noOfParameters = 0;
      return error;
   }

   return behaviourEntry->getParameterv(paramFlag, numArray,\
      noOfParameters);

   // TODO : float redirection
}

mvErrorEnum mvBEntryListNode::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.setParameteri(paramFlag, index);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->setParameteri(paramFlag, index);
}

mvErrorEnum mvBEntryListNode::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.setParameter(paramFlag, option);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->setParameter(paramFlag, option);
}

mvErrorEnum mvBEntryListNode::setParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.setParameterf(paramFlag, num);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->setParameterf(paramFlag, num);
}

mvErrorEnum mvBEntryListNode::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (behaviourEntry == MV_NULL)
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }

   mvErrorEnum error = entryFlags.setParameterv(paramFlag, numArray);

   // utility then entry
   if (error != MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER)
   {
      return error;
   }

   return behaviourEntry->setParameterv(paramFlag, numArray);
}

mvBEntryListNode::~mvBEntryListNode()
{
   if (behaviourEntry)
   {
      delete behaviourEntry;
      behaviourEntry = MV_NULL;
   }
}

