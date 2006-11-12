/**
 * \file mvBehaviour-List.cpp
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

#include "mvBehaviour-List.h"
#include "mvMotionAI-Utilities.h"

#define MV_BEHAVIOUR_LIST_DEBUG_FLAG 1
#undef MV_BEHAVIOUR_LIST_DEBUG_FLAG

enum mvBehaviour_ListCPPEnums
{
   MV_BEHAVIOUR_LIST_DEFAULT_BODY_INDEX = 0,
   MV_BEHAVIOUR_LIST_DEFAULT_PATHWAY_INDEX = 0,
   MV_BEHAVIOUR_LIST_DEFAULT_WAYPOINT_INDEX = 0,
   MV_BEHAVIOUR_LIST_INVALID_GROUP_INDEX = 0,
   MV_BEHAVIOUR_LIST_INVALID_BEHAVIOUR_INDEX = 0
};

void mvBehaviourList::setDefaultBody(mvIndex bodyIndex)
{
   defaultBody = bodyIndex;
}

void mvBehaviourList::setDefaultWaypoint(mvIndex wpIndex)
{
   defaultWaypoint = wpIndex;
}

void mvBehaviourList::setDefaultPathway(mvIndex pwIndex)
{
   defaultPathway = pwIndex;
}

mvBehaviourList::mvBehaviourList()
{
   noOfEntries = 0;
   defaultBody = MV_BEHAVIOUR_LIST_DEFAULT_BODY_INDEX;
   defaultPathway = MV_BEHAVIOUR_LIST_DEFAULT_PATHWAY_INDEX;
   defaultWaypoint = MV_BEHAVIOUR_LIST_DEFAULT_WAYPOINT_INDEX;
   nodeFactorTotal = 0.0;
   defaultFactor = 1.0;
}

void mvBehaviourList::removeAll()
{
   std::vector<mvBehaviourListNode*>::iterator i;
   mvBehaviourListNode* tempEntry = NULL;

   for (i =  entries.begin(); i != entries.end(); ++i)
   {
      tempEntry = *i;
      if (tempEntry)
      {
         // need to add counter to allow
         // one call to shared entry
         delete tempEntry;
         *i = NULL;
      }
   }
   noOfEntries = 0;
}

mvBehaviourList::~mvBehaviourList()
{
  removeAll();
  noOfEntries = 0;
}

mvBehaviourListNode* mvBehaviourList::findExistingGroupEntry(mvIndex bIndex, mvIndex gIndex)
{
   std::vector<mvBehaviourListNode*>::iterator i;
   mvBehaviourListNode* tempEntry = NULL;

   for (i = entries.begin(); i != entries.end(); ++i)
   {
      tempEntry = *i;
      if (tempEntry != NULL && tempEntry->getType() == MV_EXISTING_GROUP_BEHAVIOUR
          && tempEntry->getBehaviourIndex() == bIndex && tempEntry->getGroupIndex() == gIndex)
      {
         return tempEntry;
      }
   }
   return NULL;
}

mvBehaviourListNode* mvBehaviourList::getEntryByIndex(mvIndex index)
{
   /*
   if (index > 0 && index <= noOfEntries)
   {
      return entries[index + MV_OFFSET_TO_INDEX];
   }
   else
   {
      return NULL;
   }
   */
   return mvGetClassPtr<mvBehaviourListNode>(entries, index, noOfEntries);
}

mvCount mvBehaviourList::getNoOfEntries() const
{
   return noOfEntries;
}

mvBehaviourList::mvBehaviourList(const mvBehaviourList& rhs)
{
  mvBehaviourListNode* currentNode = NULL;
  mvBehaviourListNode* copyNode = NULL;
  mvIndex i;

  if (noOfEntries > 0)
  {
     removeAll();
  }

  noOfEntries = rhs.getNoOfEntries();

  for (i = 1; i <= noOfEntries; ++i)
  {
     currentNode = rhs.entries.at(i);
     if (currentNode != NULL)
     {
        copyNode = new mvBehaviourListNode(*currentNode);
        entries.push_back(copyNode);
     }
  }
}

const mvBehaviourList& mvBehaviourList::operator=(const mvBehaviourList& rhs)
{
  mvBehaviourListNode* currentNode = NULL;
  mvBehaviourListNode* copyNode = NULL;
  mvIndex i;

  if (noOfEntries > 0)
  {
     removeAll();
  }

  noOfEntries = rhs.getNoOfEntries();

  for (i = 1; i <= noOfEntries; ++i)
  {
     currentNode = rhs.entries.at(i);
     if (currentNode != NULL)
     {
        copyNode = new mvBehaviourListNode(*currentNode);
        entries.push_back(copyNode);
     }
  }

  return *this;
}

mvErrorEnum mvBehaviourList::addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex)
{
  return addEntry(MV_EXISTING_GROUP_BEHAVIOUR,behaviourIndex,groupIndex);
}

mvErrorEnum mvBehaviourList::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
  return addEntry(MV_EXISTING_GROUP_BEHAVIOUR,behaviourIndex,MV_BEHAVIOUR_LIST_INVALID_GROUP_INDEX);
}

mvErrorEnum mvBehaviourList::addNewBehaviourEntry(mvOptionEnum behaviourType)
{
  return addEntry(behaviourType,MV_BEHAVIOUR_LIST_INVALID_BEHAVIOUR_INDEX,MV_BEHAVIOUR_LIST_INVALID_GROUP_INDEX);
}

mvFloat mvBehaviourList::getListFactorTotal() const
{
   return nodeFactorTotal;
}

mvErrorEnum mvBehaviourList::addEntry(mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
{
   mvBehaviourListNode* tempNode = NULL;

   tempNode = new mvBehaviourListNode(bType,behaviourIndex,groupIndex);
#ifdef MV_BEHAVIOUR_LIST_DEBUG_FLAG
   puts(mvGetEnumString(tempNode->getType()));
   std::cout << "B I : "<<tempNode->getBehaviourIndex() << std::endl;
   std::cout << "G I : "<<tempNode->getGroupIndex() << std::endl;
#endif
   // if (bType != MV_EXISTING_BEHAVIOUR || MV_EXISTING_GROUP_BEHAVIOUR)
   if (tempNode->getBehavData() != NULL)
   {
#ifdef MV_BEHAVIOUR_LIST_DEBUG_FLAG
      std::cout << "PW : "<<defaultPathway << std::endl;
      std::cout << "BD : "<<defaultBody << std::endl;
      std::cout << "WP : "<<defaultWaypoint << std::endl;
      std::cout << "F : "<<tempNode->getFactor() << std::endl;
#endif
      tempNode->getBehavData()->addBody(defaultBody);
      tempNode->getBehavData()->addWaypoint(defaultWaypoint);
      tempNode->getBehavData()->addPathway(defaultPathway);
      tempNode->setFactor(defaultFactor);
#ifdef MV_BEHAVIOUR_LIST_DEBUG_FLAG
      std::cout << "PW : "<<tempNode->getBehavData()->getPathway() << std::endl;
      std::cout << "BD : "<<tempNode->getBehavData()->getBody() << std::endl;
      std::cout << "WP : "<<tempNode->getBehavData()->getWaypoint() << std::endl;
      std::cout << "F : "<<tempNode->getFactor() << std::endl;
#endif
   }
   entries.push_back(tempNode);
   ++noOfEntries;
   if (tempNode->getType() != MV_NON_BEHAVIOUR_TYPE)
   {
      nodeFactorTotal += tempNode->getFactor();
   }
   return MV_NO_ERROR;
}

//mvBehaviourListNode

mvBehaviourListNode::mvBehaviourListNode(const mvBehaviourListNode& rhs)
{
   initDefault();

   bNodeType = rhs.getType();
   switch(bNodeType)
   {
      /**
       * Existing behaviour use a shared entry
       */
      case MV_EXISTING_BEHAVIOUR:
         setBehaviourIndex(rhs.getBehaviourIndex());
         behaveData = rhs.behaveData;
         break;
      /**
       * Existing group behaviour & new behaviour (default)
       * use a shared entry
       */
      case MV_EXISTING_GROUP_BEHAVIOUR:
         setGroupIndex(rhs.getGroupIndex());
         setBehaviourIndex(rhs.getBehaviourIndex());
      default:
         // copies default entries
         if (rhs.behaveData != NULL)
         {
            behaveData = new mvBehaviourEntry(*rhs.behaveData);
         }
         break;
   }

}

void mvBehaviourListNode::initialiseEntry(mvOptionEnum type)
{
  if (behaveData != NULL)
  {
     delete [] behaveData;
     behaveData = NULL;
  }
  behaveData = new mvBehaviourEntry(type);
}

mvFloat mvBehaviourListNode::getFactor() const
{
   return bNodeFactor;
}

mvErrorEnum mvBehaviourListNode::setFactor(mvFloat factor)
{
  if (factor >= 0.0)
  {
     bNodeFactor = factor;
     return MV_NO_ERROR;
  }
  else
  {
     return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
  }
}

const mvBehaviourListNode& mvBehaviourListNode::operator=(const mvBehaviourListNode& rhs)
{
   initDefault();

   bNodeType = rhs.getType();
   switch(bNodeType)
   {
      /**
       * Existing behaviour use a shared entry
       */
      case MV_EXISTING_BEHAVIOUR:
         setBehaviourIndex(rhs.getBehaviourIndex());
         behaveData = rhs.behaveData;
         break;
      /**
       * Existing group behaviour & new behaviour
       * use a shared entry
       */
      case MV_EXISTING_GROUP_BEHAVIOUR:
         setGroupIndex(rhs.getGroupIndex());
         setBehaviourIndex(rhs.getBehaviourIndex());
      default:
         // copies default entries
         if (rhs.behaveData != NULL)
         {
            behaveData = new mvBehaviourEntry(*rhs.behaveData);
         }
         break;
   }

   return *this;
}

void mvBehaviourListNode::initDefault()
{
   behaveData = NULL;
   groupIndex = MV_BEHAVIOUR_LIST_INVALID_GROUP_INDEX;
   behaviourIndex = MV_BEHAVIOUR_LIST_INVALID_BEHAVIOUR_INDEX;
   bNodeFactor = 1.0f;
}

mvBehaviourListNode::mvBehaviourListNode(mvOptionEnum nodeType, mvIndex behaviour, mvIndex group)
{
   initDefault();

   switch(nodeType)
   {
      case MV_EXISTING_GROUP_BEHAVIOUR:
         setGroupIndex(group);
      case MV_EXISTING_BEHAVIOUR:
         setBehaviourIndex(behaviour);
         bNodeType = nodeType;
         break;
      default:
         behaveData = new mvBehaviourEntry(nodeType);
         bNodeType = nodeType;
         break;
   }

}

mvBehaviourListNode::mvBehaviourListNode(mvOptionEnum nodeType, mvIndex behaviour, mvIndex group,
      mvBehaviourEntry* defaultEntry)
{
   initDefault();

   switch(nodeType)
   {
      case MV_EXISTING_GROUP_BEHAVIOUR:
         setGroupIndex(group);
      case MV_EXISTING_BEHAVIOUR:
         setBehaviourIndex(behaviour);
         bNodeType = nodeType;
         break;
      default:
         // copies default entries
         if (defaultEntry != NULL && defaultEntry->getType() == nodeType)
         {
            behaveData = new mvBehaviourEntry(*defaultEntry);
         }
         break;
   }


}

mvBehaviourListNode::mvBehaviourListNode()
{
   initDefault();
}

mvBehaviourListNode::~mvBehaviourListNode()
{
   if (behaveData != NULL && bNodeType != MV_EXISTING_BEHAVIOUR)
   {
      delete behaveData;
      behaveData = NULL;
   }
}

mvOptionEnum mvBehaviourListNode::getType() const
{
   return bNodeType;
}

mvIndex mvBehaviourListNode::getBehaviourIndex() const
{
   return behaviourIndex;
}

mvIndex mvBehaviourListNode::getGroupIndex() const
{
   return groupIndex;
}

mvBehaviourEntry* mvBehaviourListNode::getBehavData() const
{
   return behaveData;
}

mvErrorEnum mvBehaviourListNode::setBehaviourIndex(mvIndex bIndex)
{
   if (bIndex > 0)
   {
      behaviourIndex = bIndex;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

mvErrorEnum mvBehaviourListNode::setGroupIndex(mvIndex gIndex)
{
   if (gIndex > 0)
   {
      groupIndex = gIndex;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

mvErrorEnum mvBehaviourList::setDefaultBehaviourFactor(mvFloat factor)
{
   if (factor < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
   else
   {
      defaultFactor = factor;
      return MV_NO_ERROR;
   }
}

/** \brief returns default index value of the body target.
  *
  * returns default index value of the body target, either positive index or 0.
  * This index value represents the initial body target of any new behaviour
  * added to the behaviour list.
  */
mvIndex mvBehaviourList::getDefaultBody() const
{
   return defaultBody;
}

/** \brief returns default index value of the waypoint target.
  *
  * returns default index value of the waypoint target, either positive index or 0.
  * This index value represents the initial waypoint target of any new behaviour
  * added to the mvBehaviourList.
  */
mvIndex mvBehaviourList::getDefaultWaypoint() const
{
   return defaultWaypoint;
}

/** \brief returns default index value of the pathway target.
  *
  * returns default index value of the pathway target, either positive index or 0.
  * This index value represents the initial pathway target of any new behaviour
  * added to the mvBehaviourList.
  */
mvIndex mvBehaviourList::getDefaultPathway() const
{
   return defaultPathway;
}

/** \brief returns default float value for any new behaviour.
  *
  * returns default float value of the waypoint target, either positive index or 0.
  *
  * This floating point represents the initial factor of any new behaviour
  * added to the mvBehaviourList. Each behaviour's effect on composite motion is
  * proportional or 'limited' by factor compared to overall total of all motions in the
  * list
  */
mvFloat mvBehaviourList::getDefaultBehaviourFactor() const
{
   return defaultFactor;
}



/*
mvBehaviourEntry* mvBehaviour_List::findEntryByKey(mvBehaviour* bEntry)
{
   std::vector<mvBehaviourEntry*>::iterator i;
   mvBehaviourEntry* tempEntry = NULL;

   if (bEntry == NULL)
      return NULL;

   for (i =  entries.begin(); i != entries.end(); ++i)
   {
      tempEntry = *i;
      if (tempEntry != NULL && tempEntry->currentBehaviour == bEntry)
      {
         return tempEntry;
      }
   }
   return NULL;
};

mvBehaviourEntry* mvBehaviour_List::findEntryByName(char* bName)
{
   std::vector<mvBehaviourEntry*>::iterator i;
   mvBehaviourEntry* tempEntry = NULL;

   if (bName == NULL)
      return NULL;

   for (i =  entries.begin(); i != entries.end(); ++i)
   {
      tempEntry = *i;
      if (tempEntry != NULL
         && strcmp(tempEntry->currentBehaviour->getName(),bName) == 0)
      {
         return tempEntry;
      }
   }
   return NULL;
};
*/

/*
mvEnum mvBehaviourList::addNewEntry(mvBehaviour* behaviourKey)
{
   mvBehaviourEntry* tempEntry = NULL;

   if (behaviourKey == NULL)
      return MV_FALSE;

   // only unique behaivour keys are allowed
   tempEntry = findEntryByKey(behaviourKey);
   if (tempEntry == NULL)
   {
      tempEntry = new mvBehaviourEntry();
      tempEntry->currentBehaviour = behaviourKey;
      entries.push_back(tempEntry);
      ++noOfEntries;
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvBehaviourList::addNewEntryPtr(mvBehaviourEntry* bEntryPtr)
{
   mvBehaviourListNode* tempEntry = NULL;
   std::vector<mvBehaviourListNode*>::iterator i;

   if (bEntryPtr == NULL)
      return MV_FALSE;

   // check if new entry is unique
   for (i = entries.begin(); i != entries.end(); ++i)
   {
      tempEntry = *i;
      if (tempEntry == bEntryPtr)
      {
         return MV_FALSE;
      }
   }

   // add entry
   entries.push_back(bEntryPtr);
   ++noOfEntries;
   return MV_TRUE;
};
*/
