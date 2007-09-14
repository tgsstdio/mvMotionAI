#include <mv/mvGroupBehaviourResult.h>

mvGroupBehaviourResult::mvGroupBehaviourResult(mvWorldPtr currentWorld,\
   mvGroupNodeMemberListPtr currentMList)
{
   world = currentWorld;
   groupMemberList = currentMList;
}

mvWorldPtr mvGroupBehaviourResult::getWorldPtr()
{
   return world;
}

mvGroupNodeMemberListPtr mvGroupBehaviourResult::getMemberList()
{
   return groupMemberList;
}

mvGroupBehaviourResult::~mvGroupBehaviourResult()
{

}
