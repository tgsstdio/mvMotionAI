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
//mvEnum mvGroupBehaviour::addGroup(mvGroup* groupPtr)
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
//mvEnum mvGroupBehaviour::removeGroup(mvGroup* groupPtr)
mvErrorEnum mvGroupBehaviour::removeGroup(mvIndex groupNo)
{
  /*
   mvGroup* currentGroup = NULL;
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

mvErrorEnum mvGroupBehaviour::getParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* index) const
{
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::getParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::getParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::getParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray) const
{
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::setParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameteri(paramFlag,index);
   }
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::setParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameter(paramFlag,option);
   }
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::setParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameterf(paramFlag,num);
   }
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvGroupBehaviour::setParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameterv(paramFlag,numArray);
   }
   return MV_INVALID_GROUP_BEHAVIOUR_PARAMETER;
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
mvGroupBehaviourNode* mvGroupBehaviour::findGroupNodeByPtr(mvGroup* groupPtr)
{
   mvGroup* currentGroup = NULL;
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


// group beh list node

//mvGroupBehaviourNode::mvGroupBehaviourNode(mvEnum gbType, mvGroup* bGroup)
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

//mvGroup* mvGroupBehaviourNode::getGroup() const
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

/*
mvGroupBehaviour::mvGroupBehaviour(mvBehaviour* groupBeh)
{
   currentBehaviour = groupBeh;
   noOfGroups = 0;
};

mvEnum mvGroupBehaviour::addGroup(mvGroup* groupPtr)
{
  return mvAddUniqueItemInVector<mvGroup>(groups,groupPtr,noOfGroups);
};

mvEnum mvGroupBehaviour::removeGroup(mvGroup* groupPtr)
{
  return mvRemoveUniqueItemInVector<mvGroup>(groups,groupPtr,noOfGroups);
};

mvGroup* mvGroupBehaviour::getGroupByIndex(mvIndex index)
{
   return mvGetClassPtr<mvGroup>(groups, index, noOfGroups);
};

mvCount mvGroupBehaviour::getNoOfGroups()
{
   return noOfGroups;
};

mvBehaviour* mvGroupBehaviour::getBehaviour()
{
   return currentBehaviour;
};
*/
