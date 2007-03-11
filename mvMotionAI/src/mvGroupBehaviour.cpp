/**
 * \file mvGroupBehaviour.cpp
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

#include "mvGroupBehaviour.h"
#include "mvMotionAI-Utilities.h"
#include "mvBehaviour-Type.h"
/**/

static const mvIndex MV_INVALID_GROUP_INDEX = 0;
void mvGroupBehaviour::initDefault()
{
   defaultEntries = NULL;
   noOfGroups = 0;
   groupBehaviourType = MV_NON_GROUP_BEHAVIOUR_TYPE;
}

mvGroupBehaviour::mvGroupBehaviour()
{
   initDefault();
}

mvGroupBehaviour::mvGroupBehaviour(mvOptionEnum gbType)
{
   //mvCount noOfDefaultBehaviours;

   initDefault();
   // set type
   groupBehaviourType = gbType;
   // get no of default beh entry

}

// no repetition
/**/
//mvEnum mvGroupBehaviour::addGroup(mvGroupPtr groupPtr)
mvErrorEnum mvGroupBehaviour::addGroup(mvIndex  groupNo)
{
   mvIndex currentGroupIndex;
   mvGroupBehaviourNode* tempNode = NULL;
   std::vector<mvGroupBehaviourNode*>::iterator i;

   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         // if new group already exists in group list
         // return false
         currentGroupIndex = tempNode->getGroup();
         if (currentGroupIndex == groupNo)
         {
            return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
         }
      }
   }
   tempNode = new mvGroupBehaviourNode(groupBehaviourType,groupNo);
   groupsList.push_back(tempNode);
   ++noOfGroups;
   return MV_NO_ERROR;
}


// no repetition
//mvEnum mvGroupBehaviour::removeGroup(mvGroupPtr groupPtr)
mvErrorEnum mvGroupBehaviour::removeGroup(mvIndex groupNo)
{
  /*
   mvGroupPtr currentGroup = NULL;
   mvGroupBehaviourNode* tempNode = NULL;
   std::set<mvGroupBehaviourNode*>::iterator i;

   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         currentGroup = tempNode->getGroup();
         if (currentGroup == groupPtr)
         {
            delete tempNode;
            tempNode = NULL;
            *i = NULL;
            groupsList.erase(i);
            --noOfGroups;
            return MV_TRUE;
         }
      }
   }
   return MV_FALSE;
   */
   mvIndex currentGroupIndex;
   mvGroupBehaviourNode* tempNode = NULL;
   std::vector<mvGroupBehaviourNode*>::iterator i;

   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         // if new group already exists in group list
         // return false
         currentGroupIndex = tempNode->getGroup();
         if (currentGroupIndex == groupNo)
         {
            delete tempNode;
            tempNode = NULL;
            *i = NULL;
            groupsList.erase(i);
            --noOfGroups;
            return MV_NO_ERROR;
         }
      }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

mvGroupBehaviourNode* mvGroupBehaviour::getGroupNodeByIndex(mvIndex index)
{
   return mvGetClassPtr<mvGroupBehaviourNode>(groupsList, index, noOfGroups);
   //return NULL;
}
/**/
mvCount mvGroupBehaviour::getNoOfGroups() const
{
   return noOfGroups;
}

mvGroupBehaviour::~mvGroupBehaviour()
{
   removeAllGroups();

   if (defaultEntries != NULL)
   {
      delete [] defaultEntries;
      defaultEntries = NULL;
   }
}

void mvGroupBehaviour::removeAllGroups()
{
   mvGroupBehaviourNode* tempNode = NULL;
   std::vector<mvGroupBehaviourNode*>::iterator i;

   noOfGroups = 0;
   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         delete tempNode;
         *i = NULL;
      }
   }
   groupsList.clear();
}

mvErrorEnum mvGroupBehaviour::getParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* index)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->getParameteri(paramFlag,index);
   }
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::getParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
      return tempEntry->getParameter(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::getParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
      return tempEntry->getParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::getParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
         return tempEntry->getParameterv(paramFlag,numArray,noOfParameters);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::setParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
         return tempEntry->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::setParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
         return tempEntry->setParameter(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::setParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
         return tempEntry->setParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupBehaviour::setParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   tempEntry = tempNode->getBehavData();
   if (tempEntry != NULL)
   {
      return tempEntry->setParameterv(paramFlag,numArray);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvGroupBehaviourNode* mvGroupBehaviour::findGroupNodeByIndex(mvIndex groupIndex)
{
   mvIndex currentGroupIndex;
   mvGroupBehaviourNode* tempNode = NULL;
   std::vector<mvGroupBehaviourNode*>::iterator i;

   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         // if new group  exists in group list
         // return node ptr
         currentGroupIndex = tempNode->getGroup();
         if (currentGroupIndex == groupIndex)
         {
            return tempNode;
         }
      }
   }
   return NULL;
}

/*
mvGroupBehaviourNode* mvGroupBehaviour::findGroupNodeByPtr(mvGroupPtr groupPtr)
{
   mvGroupPtr currentGroup = NULL;
   mvGroupBehaviourNode* tempNode = NULL;
   std::vector<mvGroupBehaviourNode*>::iterator i;

   for (i = groupsList.begin(); i != groupsList.end(); ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         // if new group  exists in group list
         // return node ptr
         currentGroup = tempNode->getGroup();
         if (currentGroup == groupPtr)
         {
            return tempNode;
         }
      }
   }
   return NULL;
};
*/
mvOptionEnum mvGroupBehaviour::getType() const
{
   //std::map<mvIndex,char>::iterator i;

   return groupBehaviourType;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::getMainParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->getParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::getMainParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->getParameter(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::getMainParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->getParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::getMainParameterv(mvParamEnum paramFlag, mvFloat* numArray,mvCount* noOfParameters)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->getParameterv(paramFlag,numArray,noOfParameters);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::setMainParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::setMainParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->setParameteri(paramFlag,option);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::setMainParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->setParameterf(paramFlag,num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour::setMainParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (defaultEntries != NULL)
   {
      return defaultEntries->setParameterv(paramFlag,numArray);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

// group beh list node

//mvGroupBehaviourNode::mvGroupBehaviourNode(mvEnum gbType, mvGroupPtr bGroup)
mvGroupBehaviourNode::mvGroupBehaviourNode(mvOptionEnum gbType, mvIndex bGroup)
{
   mvOptionEnum groupNodeType;

   //groupPtr = bGroup;
   groupIndex = MV_INVALID_GROUP_INDEX;
   groupNodeType = selectBodyToGroupEntryType(gbType);
   behavData = new mvBehaviourEntry(groupNodeType);
   groupIndex = bGroup;
}

mvGroupBehaviourNode::mvGroupBehaviourNode()
{
   //groupPtr = NULL;
   groupIndex = MV_INVALID_GROUP_INDEX;
   behavData = NULL;
}

// deep copy for behav entry , shallow copy for group ptr
mvGroupBehaviourNode::mvGroupBehaviourNode(const mvGroupBehaviourNode& rhs)
{
   /*
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   */

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   //groupPtr = rhs.getGroup();
   groupIndex = rhs.getGroup();
   behavData = new mvBehaviourEntry(*rhs.getBehavData());
}
// deep copy for behav entry , shallow copy for group ptr
const mvGroupBehaviourNode& mvGroupBehaviourNode::operator=(const mvGroupBehaviourNode& rhs)
{
   /*
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   */

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   //groupPtr = rhs.getGroup();
   groupIndex = rhs.getGroup();
   behavData = new mvBehaviourEntry(*rhs.getBehavData());
   return *this;
}

//mvGroupPtr mvGroupBehaviourNode::getGroup() const
mvIndex mvGroupBehaviourNode::getGroup() const
{
   //return groupPtr;
   return groupIndex;
}

mvBehaviourEntry* mvGroupBehaviourNode::getBehavData() const
{
   return behavData;
}

bool mvGroupBehaviourNode::operator<(const mvGroupBehaviourNode& rhs) const
{
   return (getGroup() < rhs.getGroup());
}

mvGroupBehaviourNode::~mvGroupBehaviourNode()
{
   /*
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   */

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }
}





