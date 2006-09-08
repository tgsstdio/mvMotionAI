#include "mvGroupBehaviour.h"
#include "mvMotionAI-Utilities.h"
#include "mvBehaviour-Type.h"
/**/
void mvGroupBehaviour::initDefault()
{
   defaultEntries = NULL;
   noOfGroups = 0;
   groupBehaviourType = MV_INVALID_BEHAVIOUR_TYPE;
};

mvGroupBehaviour::mvGroupBehaviour()
{
   initDefault();
};

mvGroupBehaviour::mvGroupBehaviour(mvEnum gbType)
{
   //mvCount noOfDefaultBehaviours;

   initDefault();
   // set type
   groupBehaviourType = gbType;
   // get no of default beh entry

};

// no repetition
/**/
//mvEnum mvGroupBehaviour::addGroup(mvGroup* groupPtr)
mvEnum mvGroupBehaviour::addGroup(mvIndex  groupNo)
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
            return MV_FALSE;
         }
      }
   }
   tempNode = new mvGroupBehaviourNode(groupBehaviourType,groupNo);
   groupsList.push_back(tempNode);
   ++noOfGroups;
   return MV_TRUE;
};


// no repetition
//mvEnum mvGroupBehaviour::removeGroup(mvGroup* groupPtr)
mvEnum mvGroupBehaviour::removeGroup(mvIndex groupNo)
{
  /**
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
   **/
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
            return MV_TRUE;
         }
      }
   }
   return MV_FALSE;
};

mvGroupBehaviourNode* mvGroupBehaviour::getGroupNodeByIndex(mvIndex index)
{
   return mvGetClassPtr<mvGroupBehaviourNode>(groupsList, index, noOfGroups);
   //return NULL;
};
/**/
mvCount mvGroupBehaviour::getNoOfGroups() const
{
   return noOfGroups;
};

mvGroupBehaviour::~mvGroupBehaviour()
{
   removeAllGroups();

   if (defaultEntries != NULL)
   {
      delete [] defaultEntries;
      defaultEntries = NULL;
   }
};
/**/
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
};
/**/
mvEnum mvGroupBehaviour::getParameteri(mvIndex groupIndex, mvEnum paramFlag, mvIndex* index) const
{
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::getParameter(mvIndex groupIndex, mvEnum paramFlag, mvEnum* option) const
{
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::getParameterf(mvIndex groupIndex, mvEnum paramFlag, mvFloat* num) const
{
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::getParameterv(mvIndex groupIndex, mvEnum paramFlag, mvFloat* numArray) const
{
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::setParameteri(mvIndex groupIndex, mvEnum paramFlag, mvIndex index)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameteri(paramFlag,index);
   }
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::setParameter(mvIndex groupIndex, mvEnum paramFlag, mvEnum option)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameter(paramFlag,option);
   }
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::setParameterf(mvIndex groupIndex, mvEnum paramFlag, mvFloat num)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameterf(paramFlag,num);
   }
   return MV_FALSE;
};

mvEnum mvGroupBehaviour::setParameterv(mvIndex groupIndex, mvEnum paramFlag, mvFloat* numArray)
{
   mvGroupBehaviourNode* tempNode = findGroupNodeByIndex(groupIndex);
   mvBehaviourEntry* tempEntry = NULL;

   if (tempNode != NULL)
   {
      tempEntry = tempNode->getBehavData();
      if (tempEntry != NULL)
         return tempEntry->setParameterv(paramFlag,numArray);
   }
   return MV_FALSE;
};

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
};

/**
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
**/
mvEnum mvGroupBehaviour::getType() const
{
   //std::map<mvIndex,char>::iterator i;

   return groupBehaviourType;
};


// group beh list node

//mvGroupBehaviourNode::mvGroupBehaviourNode(mvEnum gbType, mvGroup* bGroup)
mvGroupBehaviourNode::mvGroupBehaviourNode(mvEnum gbType, mvIndex bGroup)
{
   mvEnum groupNodeType;

   //groupPtr = bGroup;
   groupIndex = MV_INVALID_GROUP_INDEX;
   groupNodeType = selectBodyToGroupEntryType(gbType);
   behavData = new mvBehaviourEntry(groupNodeType);
   groupIndex = bGroup;
};

mvGroupBehaviourNode::mvGroupBehaviourNode()
{
   //groupPtr = NULL;
   groupIndex = MV_INVALID_GROUP_INDEX;
   behavData = NULL;
};

// deep copy for behav entry , shallow copy for group ptr
mvGroupBehaviourNode::mvGroupBehaviourNode(const mvGroupBehaviourNode& rhs)
{
   /**
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   **/

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   //groupPtr = rhs.getGroup();
   groupIndex = rhs.getGroup();
   behavData = new mvBehaviourEntry(*rhs.getBehavData());
};
// deep copy for behav entry , shallow copy for group ptr
const mvGroupBehaviourNode& mvGroupBehaviourNode::operator=(const mvGroupBehaviourNode& rhs)
{
   /**
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   **/

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   //groupPtr = rhs.getGroup();
   groupIndex = rhs.getGroup();
   behavData = new mvBehaviourEntry(*rhs.getBehavData());
   return *this;
};

//mvGroup* mvGroupBehaviourNode::getGroup() const
mvIndex mvGroupBehaviourNode::getGroup() const
{
   //return groupPtr;
   return groupIndex;
};

mvBehaviourEntry* mvGroupBehaviourNode::getBehavData() const
{
   return behavData;
};

bool mvGroupBehaviourNode::operator<(const mvGroupBehaviourNode& rhs) const
{
   return (getGroup() < rhs.getGroup());
};

mvGroupBehaviourNode::~mvGroupBehaviourNode()
{
   /**
   if (groupPtr != NULL)
   {
      groupPtr = NULL;
   }
   **/

   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }
};

/**
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
**/
