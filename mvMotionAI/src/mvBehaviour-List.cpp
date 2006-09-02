#include "mvBehaviour-List.h"

#define MV_BEHAVIOUR_LIST_DEBUG_FLAG 1
#undef MV_BEHAVIOUR_LIST_DEBUG_FLAG

enum mvBehaviour_ListCPPEnums
{
   MV_BEHAVIOUR_LIST_DEFAULT_BODY_INDEX = 0,
   MV_BEHAVIOUR_LIST_DEFAULT_PATHWAY_INDEX = 0,
   MV_BEHAVIOUR_LIST_DEFAULT_WAYPOINT_INDEX = 0,
};

void mvBehaviourList::setDefaultBody(mvIndex bodyIndex)
{
   defaultBody = bodyIndex;
};

void mvBehaviourList::setDefaultWaypoint(mvIndex wpIndex)
{
   defaultWaypoint = wpIndex;
};

void mvBehaviourList::setDefaultPathway(mvIndex pwIndex)
{
   defaultPathway = pwIndex;
};

mvBehaviourList::mvBehaviourList()
{
   noOfEntries = 0;
   defaultBody = MV_BEHAVIOUR_LIST_DEFAULT_BODY_INDEX;
   defaultPathway = MV_BEHAVIOUR_LIST_DEFAULT_PATHWAY_INDEX;
   defaultWaypoint = MV_BEHAVIOUR_LIST_DEFAULT_WAYPOINT_INDEX;
   nodeFactorTotal = 0.0;
   defaultFactor = 1.0;
};

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
};

mvBehaviourList::~mvBehaviourList()
{
  removeAll();
  noOfEntries = 0;
};

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
};

mvBehaviourListNode* mvBehaviourList::getEntryByIndex(mvIndex index) const
{ 
   if (index > 0 && index <= noOfEntries)
   {       
      return entries[index + MV_OFFSET_TO_INDEX];
   }
   else
   {
      return NULL;
   } 
};

mvCount mvBehaviourList::getNoOfEntries() const
{
   return noOfEntries;
};

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
     currentNode = rhs.getEntryByIndex(i);
     if (currentNode != NULL)
     {
        copyNode = new mvBehaviourListNode(*currentNode);
        entries.push_back(copyNode);
     }
  }  
};

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
     currentNode = rhs.getEntryByIndex(i);
     if (currentNode != NULL)
     {
        copyNode = new mvBehaviourListNode(*currentNode);
        entries.push_back(copyNode);
     }
  }  
  
  return *this;
};

mvEnum mvBehaviourList::addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex)
{
  return addEntry(MV_EXISTING_GROUP_BEHAVIOUR,behaviourIndex,groupIndex);
};

mvEnum mvBehaviourList::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
  return addEntry(MV_EXISTING_GROUP_BEHAVIOUR,behaviourIndex,MV_INVALID_GROUP_INDEX);
};

mvEnum mvBehaviourList::addNewBehaviourEntry(mvEnum behaviourType)
{
  return addEntry(behaviourType,MV_INVALID_BEHAVIOUR_INDEX,MV_INVALID_GROUP_INDEX);
};

mvFloat mvBehaviourList::getListFactorTotal() const
{
   return nodeFactorTotal;
};

mvEnum mvBehaviourList::addEntry(mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
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
   if (tempNode->getType() != MV_INVALID_BEHAVIOUR_ENTRY_TYPE)
   {
      nodeFactorTotal += tempNode->getFactor();
   }
   return MV_TRUE;
};

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
  
};

void mvBehaviourListNode::initialiseEntry(mvEnum type)
{
  if (behaveData != NULL)
  {
     delete [] behaveData;
     behaveData = NULL;
  }
  behaveData = new mvBehaviourEntry(type);
};

mvFloat mvBehaviourListNode::getFactor() const
{
   return bNodeFactor;
};
mvEnum mvBehaviourListNode::setFactor(mvFloat factor)
{
  if (factor >= 0.0) 
  {
     bNodeFactor = factor;
     return MV_TRUE;
  }
  else
  {
     return MV_FALSE;
  }  
};

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
};

void mvBehaviourListNode::initDefault()
{
   behaveData = NULL;
   groupIndex = MV_INVALID_GROUP_INDEX;
   behaviourIndex = MV_INVALID_BEHAVIOUR_INDEX;
   bNodeFactor = 1.0f;
};

mvBehaviourListNode::mvBehaviourListNode(mvEnum nodeType, mvIndex behaviour, mvIndex group)
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
   
};

mvBehaviourListNode::mvBehaviourListNode(mvEnum nodeType, mvIndex behaviour, mvIndex group,
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

   
};

mvBehaviourListNode::mvBehaviourListNode()
{
   initDefault();   
};

mvBehaviourListNode::~mvBehaviourListNode()
{
   if (behaveData != NULL && bNodeType != MV_EXISTING_BEHAVIOUR)
   {
      delete behaveData;
      behaveData = NULL;
   }
};

mvEnum mvBehaviourListNode::getType() const
{
   return bNodeType;
};

mvIndex mvBehaviourListNode::getBehaviourIndex() const
{
   return behaviourIndex;
};

mvIndex mvBehaviourListNode::getGroupIndex() const
{
   return groupIndex;
};

mvBehaviourEntry* mvBehaviourListNode::getBehavData() const
{
   return behaveData;
};

mvEnum mvBehaviourListNode::setBehaviourIndex(mvIndex bIndex)
{
   if (bIndex > 0)
   {
      behaviourIndex = bIndex;
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvBehaviourListNode::setGroupIndex(mvIndex gIndex)
{
   if (gIndex > 0)
   {
      groupIndex = gIndex;
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvBehaviourList::setDefaultBehaviourFactor(mvFloat factor)
{
   if (factor < 0.0)
   {
      return MV_FALSE;
   }
   else
   {
      defaultFactor = factor;
      return MV_TRUE;
   }
};

/**
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
**/

/**
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
**/