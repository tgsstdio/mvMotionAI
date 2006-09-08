#ifndef MV_BEHAVIOUR_ENTRY_H_
#define MV_BEHAVIOUR_ENTRY_H_
//#include "Vec3.h"
#include "mvMotionAI-Types.h"
#include "mvVec3.h"
//#include "mvBody.h"
#include "mvEnum.h"
//#include "mvPathway.h"
//#include "mvBehaviour.h"

/**
 * \class mvBehaviourEntry
 * Log
 *
 * Version     Date     Comments
 * 00-01-05   23/7/06   - re implememting file
 *
 * 00-01-03   21/6/06   - created behaviour entry
 */

class mvBehaviourEntry
{
   private:
      void initDefault();
      mvEnum mvBehaviour_InitialiseType2(mvEnum type);

   public:
      //mvIndex behaviourIndex; // key 2
      mvEnum bType; // key 1
      //mvIndex groupIndex; // key 3

      mvFloat* extraVariables;
      mvVec3* extraPoints;
      mvEnum* extraStates;
      mvIndex* indexes;

   //mvIndex currentGroup;
   //mvPathway* currentPathway;
   //mvIndex currentWaypoint;
//   mvBody* currentBody;
   mvBehaviourEntry();
   mvBehaviourEntry(mvEnum type);
  //vBehaviourEntry(mvEnum type, mvIndex behaviourIndex, mvIndex groupIndex);
   ~mvBehaviourEntry();
   mvBehaviourEntry(const mvBehaviourEntry& rhs);
   const mvBehaviourEntry& operator=(const mvBehaviourEntry& rhs);
   //mvIndex getBehaviourIndex();
   mvEnum getType() const;
   //mvIndex getGroupIndex();
   mvEnum getParameter(mvEnum paramFlag, mvEnum* dest) const;
   mvEnum getParameterf(mvEnum paramFlag, mvFloat* dest) const;
   mvEnum getParameterv(mvEnum paramFlag, mvFloat* dest, mvCount* size) const;
   mvEnum setParameter(mvEnum paramFlag, mvEnum option);
   mvEnum setParameteri(mvEnum paramFlag, mvIndex option);
   mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
   mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);

   mvEnum addPathway(mvIndex bPathway);
   mvEnum addWaypoint(mvIndex bWaypoint);
   mvIndex getWaypoint() const;
   mvIndex getPathway() const ;

   mvIndex getWaypointIndexAt(mvIndex num) const;
   mvIndex getPathwayIndexAt(mvIndex num) const;

   mvIndex getBodyIndexAt(mvIndex num) const;
   mvIndex getBody() const;
   mvEnum addBody(mvIndex bBody);
};

#endif
