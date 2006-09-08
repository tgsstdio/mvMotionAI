#ifndef MV_BEHAVIOUR_LIST_H_
#define MV_BEHAVIOUR_LIST_H_
//#include "Vec3.h"
#include <vector>
//#include "mvBody.h"
#include "mvEnum.h"
//#include "mvPathway.h"
#include "mvMotionAI-Types.h"
//#include "mvBehaviour.h"
#include "mvBehaviour-Entry.h"

/**
 * \class mvBehaviourListNode
 * Log
 *
 * Version     Date     Comments
 *
 * 00-01-05   26/7/06   - created behaviour list node instead of entry
 */

class mvBehaviourListNode
{
  private:
   mvEnum bNodeType; // key 1
   mvIndex behaviourIndex; // key 2
   mvIndex groupIndex; // key 3
   mvFloat bNodeFactor;
   mvBehaviourEntry* behaveData;
   void initDefault();

  public:
   // undeclared
   mvBehaviourListNode();
   mvBehaviourListNode(mvEnum nodeType, mvIndex behaviour, mvIndex group);
   mvBehaviourListNode(mvEnum nodeType, mvIndex behaviour, mvIndex group,
      mvBehaviourEntry* defaultEntry);
   mvBehaviourListNode(const mvBehaviourListNode& rhs);
   const mvBehaviourListNode& operator=(const mvBehaviourListNode& rhs);
   ~mvBehaviourListNode();
   mvFloat getFactor() const;
   mvEnum setFactor(mvFloat factor);
   void initialiseEntry(mvEnum type);

   mvEnum setBehaviourIndex(mvIndex bIndex);
   mvEnum setGroupIndex(mvIndex gIndex);

   mvEnum getType() const;
   mvIndex getBehaviourIndex() const;
   mvIndex getGroupIndex() const;
   mvBehaviourEntry* getBehavData() const;
};

/**
 * \class mvBehaviourList
 * Log
 *
 * Version     Date     Comments
 *
 * 00-01-05   26/7/06   - use node instead of entry for consistency and code reuse
 *
 * 00-01-03   21/6/06   - created behaviour list
 */
class mvBehaviourList
{
   private:
      mvCount noOfEntries;
      std::vector<mvBehaviourListNode*> entries;
      mvIndex defaultBody;
      mvIndex defaultWaypoint;
      mvIndex defaultPathway;
      mvFloat nodeFactorTotal;
      mvFloat defaultFactor;

   public:
      mvBehaviourList();
      mvCount getNoOfEntries() const;
      void removeAll();
      ~mvBehaviourList();
      mvBehaviourListNode* findExistingGroupEntry(mvIndex behaviourIndex, mvIndex groupIndex);
      mvBehaviourListNode* getEntryByIndex(mvIndex index) const;

      // undeclared
      mvBehaviourList(const mvBehaviourList& rhs);
      const mvBehaviourList& operator=(const mvBehaviourList& rhs);
      mvEnum addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex);
      mvEnum addExistingBehaviourEntry(mvIndex behaviourIndex);
      mvEnum addNewBehaviourEntry(mvEnum behaviourType);
      mvEnum addEntry(mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);
      mvFloat getListFactorTotal() const;

      //mvBehaviourEntry* entries;

      //mvBehaviourEntry* findNodeByKeyPtr(mvBehaviour* bEntry);
      //mvBehaviourEntry* findEntryByName(char* bName);
      void setDefaultBody(mvIndex bodyIndex);
      void setDefaultWaypoint(mvIndex wpIndex);
      void setDefaultPathway(mvIndex pwIndex);
      mvEnum setDefaultBehaviourFactor(mvFloat factor);
};

#endif
