#ifndef MV_GROUP_BEHAVIOUR_SIMPLE_FLOCK
#define MV_GROUP_BEHAVIOUR_SIMPLE_FLOCK
#include "mvVec3.h"
#include "mvWorld.h"
#include "mvBody.h"
#include "mvGroup.h"
#include "mvMotionAI-Types.h"
#include "mvBehaviour-Entry.h"

void mvBehaviour_SimpleFlock_GroupOperations(mvWorld* worldPtr, mvGroup* flockGroup, mvBehaviourEntry* groupData);

mvVec3 mvBehaviour_SimpleFlock_SingularOperation(mvBehaviourEntry* groupData, mvBody* currentBody,
                                               mvBehaviourEntry* bodyData);

class mvSimpleFlock
{
   public:
      void mvGroupFunc(mvWorld* worldPtr, mvGroup* flockGroup, mvBehaviourEntry* groupData);
      mvVec3 mvBodyFunc(mvBehaviourEntry* groupData, mvBody* currentBody,
                                               mvBehaviourEntry* bodyData);
      mvBehaviourEntry* createBodyEntry(mvBehaviourEntry* defaultEntry);
      mvBehaviourEntry* createGroupEntry(mvBehaviourEntry* defaultEntry);
};
#endif
