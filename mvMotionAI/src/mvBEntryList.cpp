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
#include "mvBEntryList.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return entryList.setItemParameterv(entryIndex, paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return entryList.setItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameter(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return entryList.setItemParameter(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return entryList.setItemParameteri(entryIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters) const
{
   return entryList.getItemParameterv(entryIndex,paramFlag, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return entryList.getItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameter(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return entryList.getItemParameter(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return entryList.getItemParameteri(entryIndex, paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return defaultNodeTimerFlags.setParameterv(paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return defaultNodeTimerFlags.setParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_MODE:
         return setMode(option);
      default:
         return defaultNodeTimerFlags.setParameter(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      case MV_PATHWAY:
         defaultPathway = index;
         return MV_NO_ERROR;
      case MV_BODY:
         defaultBody = index;
         return MV_NO_ERROR;
      case MV_WAYPOINT:
         defaultWaypoint = index;
         return MV_NO_ERROR;
      default:
         return defaultNodeTimerFlags.setParameteri(paramFlag, index);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterv(mvParamEnum paramFlag,\
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

   return defaultNodeTimerFlags.getParameterv(paramFlag,\
      numArray, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return defaultNodeTimerFlags.getParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_MODE:
         *option = getMode();
         return MV_NO_ERROR;
      default:
         return defaultNodeTimerFlags.getParameter(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_PATHWAY:
         *index = getDefaultPathway();
         return MV_NO_ERROR;
      case MV_BODY:
         *index = getDefaultBody();
         return MV_NO_ERROR;
      case MV_WAYPOINT:
         *index = getDefaultWaypoint();
         return MV_NO_ERROR;
      default:
         return defaultNodeTimerFlags.getParameteri(paramFlag, index);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFloat mvBEntryList::getDefaultWeight() const
{
   return defaultNodeTimerFlags.getWeight();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultPathway() const
{
   return defaultPathway;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultWaypoint() const
{
   return defaultWaypoint;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultBody() const
{
   return defaultBody;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::addNewEntry(mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseActionPtr dBehaviour,
   mvFloat bNodeWeight, mvFloat period, mvFloat elaspedTime)
{
   // TODO : unit test this code
   mvEntryListNodePtr tempNode = MV_NULL;
   mvBaseActionPtr actionPtr = MV_NULL;

   if (bType == MV_EXISTING_BEHAVIOUR || bType == MV_EXISTING_GROUP_BEHAVIOUR)
   {
      actionPtr = MV_NULL;
   }
   else if (dBehaviour == MV_NULL)
   {
      return MV_NULL;
   }
   else if (bType != dBehaviour->getType())
   {
      return MV_NULL;
   }
   else
   {
      actionPtr = dBehaviour;
   }

   tempNode = new mvBEntryListNode(bType, behaviourIndex,
      groupIndex, actionPtr, bNodeWeight, period, elaspedTime);

   if (tempNode == MV_NULL)
      return MV_NULL;

   return entryList.addItem(tempNode);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::addNewBehaviourEntry(mvOptionEnum behaviourType,
   mvBaseActionPtr behaviourData)
{
   return addNewEntry(behaviourType,MV_NULL,MV_NULL, behaviourData,\
      defaultNodeTimerFlags.getWeight(),\
      defaultNodeTimerFlags.getTimerPtr()->getPeriod(),\
      defaultNodeTimerFlags.getTimerPtr()->getElapsedTime());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
   return addNewEntry(MV_EXISTING_BEHAVIOUR,behaviourIndex,MV_NULL, MV_NULL,\
      defaultNodeTimerFlags.getWeight(),\
      defaultNodeTimerFlags.getTimerPtr()->getPeriod(),\
      defaultNodeTimerFlags.getTimerPtr()->getElapsedTime());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::addExistingGroupBehaviourEntry(\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   return addNewEntry(MV_EXISTING_GROUP_BEHAVIOUR,\
      behaviourIndex,groupIndex, MV_NULL,\
      defaultNodeTimerFlags.getWeight(),\
      defaultNodeTimerFlags.getTimerPtr()->getPeriod(),\
      defaultNodeTimerFlags.getTimerPtr()->getElapsedTime());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setDefaultWeight(mvFloat factor)
{
   return defaultNodeTimerFlags.setWeight(factor);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultPathway(mvIndex pwIndex)
{
   defaultPathway = pwIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultWaypoint(mvIndex wpIndex)
{
   defaultWaypoint = wpIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultBody(mvIndex bodyIndex)
{
   defaultBody = bodyIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvOptionEnum mvBEntryList::getMode() const
{
   return integrationMode;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setMode(mvOptionEnum option)
{
   switch(option)
   {
      case MV_WEIGHTED:
      case MV_XOR:
      case MV_RANDOMIZED_WEIGHTED:
      case MV_RANDOM:
         integrationMode = option;
         return MV_NO_ERROR;
      default:
         // TODO : further implementation
         integrationMode = MV_WEIGHTED;
         return MV_INVALID_INTEGRATION_MODE;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvEntryListNodePtr mvBEntryList::getEntry(mvIndex index)
{
   return entryList.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvEntryListNodePtr mvBEntryList::findExistingGroupEntry(mvIndex bIndex,\
   mvIndex gIndex)
{
   return NULL;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBEntryList::mvBEntryList()
{
   isEnabled = true;
   defaultBody = MV_NULL;
   defaultWaypoint = MV_NULL;
   defaultPathway = MV_NULL;
   setMode(MV_WEIGHTED);
}

mvBEntryList::~mvBEntryList()
{

}

mvErrorEnum mvBEntryList::getEntryParameteri_str(mvIndex entryIndex,\
   const char* param, mvIndex* outIndex) const
{
   return entryList.getItemParameteri_str(entryIndex, param, outIndex);
}

mvErrorEnum mvBEntryList::getEntryParameter_str(mvIndex entryIndex, const char* param,\
   const char** option) const
{
   return entryList.getItemParameter_str(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::getEntryParameterf_str(mvIndex entryIndex, const char* param,\
   mvFloat* num) const
{
   return entryList.getItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::getEntryParameterv_str(mvIndex entryIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   return entryList.getItemParameterv_str(entryIndex, param, numArray,\
      noOfParameters);
}

mvErrorEnum mvBEntryList::setEntryParameteri_str(mvIndex entryIndex,const char* param,\
   mvIndex paramIndex)
{
   return entryList.setItemParameteri_str(entryIndex, param, paramIndex);
}

mvErrorEnum mvBEntryList::setEntryParameter_str(mvIndex entryIndex,const char* param,\
   const char* option)
{
   return entryList.setItemParameter_str(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::setEntryParameterf_str(mvIndex entryIndex,const char* param,\
   mvFloat num)
{
   return entryList.setItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::setEntryParameterv_str(mvIndex entryIndex,const char* param,\
   mvFloat* numArray)
{
   return entryList.setItemParameterv_str(entryIndex, param, numArray);
}

void mvBEntryList::clearAll()
{
   entryList.deleteAllItems();
}

mvErrorEnum mvBEntryList::removeEntry(mvIndex entryIndex)
{
   return entryList.deleteItem(entryIndex);
}

mvIndex mvBEntryList::getCurrentEntry() const
{
   return entryList.getCurrentIndex();
}

void mvBEntryList::applyToAllEntries(\
   void (someFunction)(mvEntryListNodePtr, void*), void* extraPtr)
{
   entryList.applyToAllItems(someFunction,extraPtr);
}