/**
 * \file mvBEntryList.cpp
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
#include <mv/mvBEntryList.h>

struct mvEntryList_FindGBMNodeStruct
{
   mvIndex behaviourIndex;
   mvIndex groupIndex;
   mvOptionEnum actionKey;
};

bool mvEntryList_FindExistingGroupBehavMemberNode(mvEntryListNodePtr node,\
   void* extraPtr);

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return entryList.setItemParameterv(entryIndex, paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return entryList.setItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setEntryParametero(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return entryList.setItemParametero(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return entryList.setItemParameteri(entryIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::getEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters) const
{
   return entryList.getItemParameterv(entryIndex,paramFlag, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::getEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return entryList.getItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::getEntryParametero(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return entryList.getItemParametero(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::getEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return entryList.getItemParameteri(entryIndex, paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setParameterv(mvParamEnum paramFlag,\
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
mvErrorEnum mvEntryList::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return defaultNodeTimerFlags.setParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_MODE:
         return setMode(option);
      default:
         return defaultNodeTimerFlags.setParametero(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setParameteri(mvParamEnum paramFlag, mvIndex index)
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
mvErrorEnum mvEntryList::getParameterv(mvParamEnum paramFlag,\
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
mvErrorEnum mvEntryList::getParameterf(mvParamEnum paramFlag,\
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
mvErrorEnum mvEntryList::getParametero(mvParamEnum paramFlag,\
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
         return defaultNodeTimerFlags.getParametero(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::getParameteri(mvParamEnum paramFlag,\
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
mvFloat mvEntryList::getDefaultWeight() const
{
   return defaultNodeTimerFlags.getWeight();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::getDefaultPathway() const
{
   return defaultPathway;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::getDefaultWaypoint() const
{
   return defaultWaypoint;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::getDefaultBody() const
{
   return defaultBody;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::addNewEntry(mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseActionPtr dBehaviour,
   mvFloat bNodeWeight, mvFloat period, mvFloat elaspedTime)
{
   // TODO : unit test this code
   mvEntryListNodePtr tempNode = MV_NULL;
   mvBaseActionPtr actionPtr = MV_NULL;

   // special type - no action pointer needed
   if (bType == MV_EXISTING_BEHAVIOUR || bType == MV_EXISTING_GROUP_BEHAVIOUR)
   {
      actionPtr = MV_NULL;
   }
   // group member type - skip rest
   else if (bType == MV_GROUP_BEHAVIOUR_MEMBER_ENTRY)
   {
      actionPtr = dBehaviour;
   }

   // abort if it has no action
   else if (dBehaviour == MV_NULL)
   {
      return MV_NULL;
   }
   // if not same as pointer
   else if (bType != dBehaviour->getType())
   {
      return MV_NULL;
   }
   else
   {
      actionPtr = dBehaviour;
   }

   tempNode = new mvEntryListNode(bType, behaviourIndex,
      groupIndex, actionPtr, bNodeWeight, period, elaspedTime);

   if (tempNode == MV_NULL)
      return MV_NULL;

   tempNode->setParameteri(MV_BODY, defaultBody);
   tempNode->setParameteri(MV_PATHWAY, defaultPathway);
   tempNode->setParameteri(MV_WAYPOINT, defaultWaypoint);

   return entryList.addItem(tempNode);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::addNewBehaviourEntry(mvOptionEnum behaviourType,
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
mvIndex mvEntryList::addExistingBehaviourEntry(mvIndex behaviourIndex)
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
mvIndex mvEntryList::addExistingGroupBehaviourEntry(\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   return addNewEntry(MV_GROUP_BEHAVIOUR_MEMBER_ENTRY,\
      behaviourIndex,groupIndex, MV_NULL,\
      defaultNodeTimerFlags.getWeight(),\
      defaultNodeTimerFlags.getTimerPtr()->getPeriod(),\
      defaultNodeTimerFlags.getTimerPtr()->getElapsedTime());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setDefaultWeight(mvFloat factor)
{
   return defaultNodeTimerFlags.setWeight(factor);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvEntryList::setDefaultPathway(mvIndex pwIndex)
{
   defaultPathway = pwIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvEntryList::setDefaultWaypoint(mvIndex wpIndex)
{
   defaultWaypoint = wpIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvEntryList::setDefaultBody(mvIndex bodyIndex)
{
   defaultBody = bodyIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvOptionEnum mvEntryList::getMode() const
{
   return integrationMode;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvEntryList::setMode(mvOptionEnum option)
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
mvEntryListNodePtr mvEntryList::getEntry(mvIndex index) const
{
   return entryList.getClassPtr(index);
}

bool mvEntryList_FindExistingGroupBehavMemberNode(mvEntryListNodePtr node,\
   void* extraPtr)
{
   mvEntryList_FindGBMNodeStruct* helper = (mvEntryList_FindGBMNodeStruct*)
      extraPtr;

   mvEntryPtr currentEntry = node->getEntryPtr();
   if (helper == MV_NULL || currentEntry == MV_NULL)
   {
      return false;
   }

   return (currentEntry->getEntryType() == MV_GROUP_BEHAVIOUR_MEMBER_ENTRY
      && currentEntry->getBehaviour() == helper->behaviourIndex
      && currentEntry->getGroup() == helper->groupIndex
      && currentEntry->getActionPtr() != MV_NULL
      && currentEntry->getActionPtr()->getType() == helper->actionKey);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvEntryList::findExistingGroupEntry(mvIndex bIndex,\
   mvIndex gIndex, mvOptionEnum actionKey)
{
   mvEntryList_FindGBMNodeStruct helper;
   helper.actionKey = actionKey;
   helper.behaviourIndex = bIndex;
   helper.groupIndex = gIndex;

   return entryList.findItemInList(mvEntryList_FindExistingGroupBehavMemberNode,
      &helper);
}

#define MV_ENTRY_LIST_DEFAULT_WEIGHT (1)
#define MV_ENTRY_LIST_DEFAULT_PERIOD (1)
#define MV_ENTRY_LIST_DEFAULT_ELAPSED_TIME (0)

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvEntryList::mvEntryList()
  : defaultNodeTimerFlags(MV_ENTRY_LIST_DEFAULT_WEIGHT,\
      MV_ENTRY_LIST_DEFAULT_PERIOD, MV_ENTRY_LIST_DEFAULT_ELAPSED_TIME)
{
   isEnabled = true;
   defaultBody = MV_NULL;
   defaultWaypoint = MV_NULL;
   defaultPathway = MV_NULL;
   setMode(MV_WEIGHTED);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvEntryList::~mvEntryList()
{

}

mvErrorEnum mvEntryList::getEntryParameteri_str(mvIndex entryIndex,\
   const char* param, mvIndex* outIndex) const
{
   return entryList.getItemParameteri_str(entryIndex, param, outIndex);
}

mvErrorEnum mvEntryList::getEntryParametero_str(mvIndex entryIndex, const char* param,\
   const char** option) const
{
   return entryList.getItemParametero_str(entryIndex, param, option);
}

mvErrorEnum mvEntryList::getEntryParameterf_str(mvIndex entryIndex, const char* param,\
   mvFloat* num) const
{
   return entryList.getItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvEntryList::getEntryParameterv_str(mvIndex entryIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   return entryList.getItemParameterv_str(entryIndex, param, numArray,\
      noOfParameters);
}

mvErrorEnum mvEntryList::setEntryParameteri_str(mvIndex entryIndex,const char* param,\
   mvIndex paramIndex)
{
   return entryList.setItemParameteri_str(entryIndex, param, paramIndex);
}

mvErrorEnum mvEntryList::setEntryParametero_str(mvIndex entryIndex,const char* param,\
   const char* option)
{
   return entryList.setItemParametero_str(entryIndex, param, option);
}

mvErrorEnum mvEntryList::setEntryParameterf_str(mvIndex entryIndex,const char* param,\
   mvFloat num)
{
   return entryList.setItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvEntryList::setEntryParameterv_str(mvIndex entryIndex,const char* param,\
   mvFloat* numArray)
{
   return entryList.setItemParameterv_str(entryIndex, param, numArray);
}

void mvEntryList::clearAll()
{
   entryList.deleteAllItems();
}

mvErrorEnum mvEntryList::removeEntry(mvIndex entryIndex)
{
   return entryList.deleteItem(entryIndex);
}

mvIndex mvEntryList::getCurrentEntry() const
{
   return entryList.getCurrentIndex();
}

void mvEntryList::applyToAllEntries(\
   void (someFunction)(mvEntryListNodePtr, void*), void* extraPtr)
{
   entryList.applyToAllItems(someFunction,extraPtr);
}

bool mvEntryList::getEnabled() const
{
   return isEnabled;
}

void mvEntryList::setEnabled(bool enabled)
{
   isEnabled = enabled;
}

mvIndex mvEntryList::addNewGroupBehaviourMemberNode(mvIndex behaviourIndex,
   mvIndex groupIndex, mvBaseActionPtr memberAction)
{
   mvIndex foundEntry, entryIndex;

   if (behaviourIndex == MV_NULL || groupIndex == MV_NULL
      || memberAction == MV_NULL)
   {
      return MV_NULL;
   }

   // if member action already exist, pass back index to user.
   foundEntry = findExistingGroupEntry(behaviourIndex, groupIndex,
      memberAction->getType());

   // unique object only
   if (foundEntry == MV_NULL)
   {
      // add new entry
      entryIndex = addNewEntry(MV_GROUP_BEHAVIOUR_MEMBER_ENTRY,\
         behaviourIndex,groupIndex, MV_NULL,\
         defaultNodeTimerFlags.getWeight(),\
         defaultNodeTimerFlags.getTimerPtr()->getPeriod(),\
         defaultNodeTimerFlags.getTimerPtr()->getElapsedTime());
   }
   else
   {
      // if existing, no creation
      entryIndex = MV_NULL;
   }

    return entryIndex;
}
