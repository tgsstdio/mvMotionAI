#ifndef MOTIONAI_MVBEHAVIOUR_H_
#define MOTIONAI_MVBEHAVIOUR_H_
//#include "mvGroup.h"
//#include "mvPathway.h"
//#include "mvWaypoint.h"
#include "mvBehaviour-Entry.h"
#include "mvEnum.h"
#include "mvMotionAI-Types.h"
//#include "Vec3.h"
//#include <vector>
/**
 * \class mvBehaviour
 *
 * \brief behaviour states
 *
 * Log
 *
 *version     date  comments
 *
 *00-01-05  26/7/06  - removed variables, added code reuse in mvBehaviourEntry
 *
 *00-01-03  21/6/06  - now using index values instead of pointers, finally
 *                     implemented two beahviours SEEK and FLEE,
 *
 *00-01-02  31/5/06  - removing groups from system until better solution
 *                     arrives.
 *
 *00-01-01  24/5/06  - start work on behvaiour functions i.e
 *                     SEEK, FLEE, CLONE, FOLLOW PATH
 *
 *                   - add behaviour entry as temp solution
 *
 *00-01-00  22/5/06  - initialised behaviours
 */

class mvBehaviour
{
  private:
    //char* behaviourName;
    //std::vector<mvGroup*> groups;
    //int noOfGroups;
    //mvEnum bType;
    mvBehaviourEntry* behavData;
    void initDefault();
    //mvEnum initialiseType(mvEnum type);
    //mvEnum initialiseVectors(mvEnum type);
    //mvEnum addEntry(mvGroup* bGroup, mvBody* bBody);
    //mvEnum removeEntry(mvGroup* bGroup, mvBody* bBody);
    //mvEnum removeGroupEntries(mvGroup* bGroup);
    //mvFloat* defaultVariables;
    //Vec3* defaultVectors;
    //mvPathway* bPaths;
    //mvWaypoint* bWaypoints;
    //mvIndex* indexes;

  public:
     // undecleared
    mvBehaviour(mvEnum type);
    mvBehaviour(const mvBehaviour& rhs);
    const mvBehaviour& operator=(const mvBehaviour& rhs);
    mvBehaviourEntry* getData() const;
    mvEnum getType() const;

    ~mvBehaviour();
    mvEnum getParameteri(mvEnum paramFlag, mvIndex* index) const;
    mvEnum getParameter(mvEnum paramFlag, mvEnum* option) const;
    mvEnum getParameterf(mvEnum paramFlag, mvFloat* num) const;
    mvEnum getParameterv(mvEnum paramFlag, mvFloat* numArray) const;

    mvEnum setParameteri(mvEnum paramFlag, mvIndex index);
    mvEnum setParameter(mvEnum paramFlag, mvEnum option);
    mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
    mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);

    //mvBehaviour(char* bName, mvEnum type);
    //char* getName();
    //int getNoOfGroups();
    //void removeAllGroups();
    //mvEnum addGroup(mvGroup* bGroup);
    //mvEnum removeGroup(mvGroup* bGroup);
};
#endif
