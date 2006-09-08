#ifndef MV_GROUP_BEHAVIOUR_H_
#define MV_GROUP_BEHAVIOUR_H_

#include "mvMotionAI-Types.h"
#include "mvBehaviour-Entry.h"
//#include "mvBehaviour.h"
//#include "mvGroup.h"
#include "mvEnum.h"
#include <vector>
#include <set>
/**
 * \class mvGroupBehaviourNode
 * Log
 *
 * Version     Date     Comments
 * 00-01-05   15/8/06   - now using index values instead.
 *
 *            26/7/06   - created mvGroupBehaviourNode for simplicity
 */

// MS VC++ compiler warnings are annoying
//#define mvGroupBehaviourNode gn

class mvGroupBehaviourNode
{
private:
     // mvGroup* groupPtr;
      mvIndex groupIndex;
      mvBehaviourEntry* behavData;

   public:
      mvGroupBehaviourNode();
      mvGroupBehaviourNode(mvEnum gbType, mvIndex bGroup);
      mvGroupBehaviourNode(const mvGroupBehaviourNode& rhs);
      const mvGroupBehaviourNode& operator=(const mvGroupBehaviourNode& rhs);
     // mvGroup* getGroup() const;
      mvIndex getGroup() const;
      mvBehaviourEntry* getBehavData() const;
      ~mvGroupBehaviourNode();
    mvEnum getParameteri(mvEnum paramFlag, mvIndex* index) const;
    mvEnum getParameter(mvEnum paramFlag, mvEnum* option) const;
    mvEnum getParameterf(mvEnum paramFlag, mvFloat* num) const;
    mvEnum getParameterv(mvEnum paramFlag, mvFloat* numArray) const;

    mvEnum setParameteri(mvEnum paramFlag, mvIndex index);
    mvEnum setParameter(mvEnum paramFlag, mvEnum option);
    mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
    mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
    bool operator<(const mvGroupBehaviourNode& rhs) const;
};

/**
 * \class mvGroupBehaviour
 * Log
 *
 * Version     Date     Comments
 *
 * 00-01-05   15/8/06   - considered using stl::sets - now back to vector.
 *
 *            26/7/06   - created mvGroupBehaviourNode vector for simplicity
 */

/**
struct CompareGroupNodes
{
   bool operator()(const mvGroupBehaviourNode* lhs, const mvGroupBehaviourNode* rhs) const
   {  **
      if (lhs != NULL && rhs != NULL)
      {
         return (lhs->getGroup() < rhs->getGroup());
      }
      else
      {
         return false;
      }
      **
      return true;
   };
};
**/

class mvGroupBehaviour
{
   private:
     //std::set<mvGroupBehaviourNode*,CompareGroupNodes> groupsList2;
     void initDefault();
     mvBehaviourEntry* defaultEntries;
     std::vector<mvGroupBehaviourNode*> groupsList;
     mvEnum groupBehaviourType;
     mvCount noOfGroups;

   public:
     //mvBehaviour* currentBehaviour;
     //std::vector<mvGroup*> groups;
     //std::vector<mvFloat*> groupVariables;
     //std::vector<mvIndex*> groupIndexes;
     //std::vector<mvEnum*> groupStates;

     mvGroupBehaviour();
     mvGroupBehaviour(mvEnum bType);
     mvEnum addGroup(mvIndex groupNo);
     mvEnum removeGroup(mvIndex groupNo);
     void removeAllGroups();
     mvGroupBehaviourNode* getGroupNodeByIndex(mvIndex index);
     mvGroupBehaviourNode* findGroupNodeByIndex(mvIndex groupIndex);
    // mvGroupBehaviourNode* findGroupNodeByPtr(mvGroup* groupPtr);
     //mvGroupBehaviourNode* findGroupNodeByPtr(mvIndex groupNo);
     mvCount getNoOfGroups() const;
     mvEnum getType() const;
     ~mvGroupBehaviour();
    // const mvGroupBehaviour& operator=(const mvGroupBehaviour& rhs);

    mvEnum getParameteri(mvIndex groupIndex, mvEnum paramFlag, mvIndex* index) const;
    mvEnum getParameter(mvIndex groupIndex, mvEnum paramFlag, mvEnum* option) const;
    mvEnum getParameterf(mvIndex groupIndex, mvEnum paramFlag, mvFloat* num) const;
    mvEnum getParameterv(mvIndex groupIndex, mvEnum paramFlag, mvFloat* numArray) const;

    mvEnum setParameteri(mvIndex groupIndex, mvEnum paramFlag, mvIndex index);
    mvEnum setParameter(mvIndex groupIndex, mvEnum paramFlag, mvEnum option);
    mvEnum setParameterf(mvIndex groupIndex, mvEnum paramFlag, mvFloat num);
    mvEnum setParameterv(mvIndex groupIndex, mvEnum paramFlag, mvFloat* numArray);
};


#endif
