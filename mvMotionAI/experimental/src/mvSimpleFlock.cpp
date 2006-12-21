#include "mvSimpleFlock.h"

mvSimpleFlockDefaultGroup::mvSimpleFlockDefaultGroup() : mvBaseBehaviour(MV_SIMPLE_FLOCK)
{
   // DUMMY CLASSES FOR HOLDING VARIABLES
}

void mvSimpleFlockDefaultGroup::groupOperation(mvWorld* worldPtr, mvGroup* groupPtr)
{
   // DUMMY CLASSES FOR HOLDING VARIABLES
}

mvBehaviourReturnType mvSimpleFlockDefaultGroup::bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
   return MV_NO_OPERATION;
}

mvSimpleFlock::mvSimpleFlock() : mvBaseBehaviour(MV_SIMPLE_FLOCK)
{

}

void mvSimpleFlock::groupOperation(mvWorld* worldPtr, mvGroup* groupPtr)
{
   // DOES NOTHING
}

mvBehaviourReturnType mvSimpleFlock::bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
   // DOES SOMETHING
   return MV_NO_OPERATION;
}

mvSimpleFlockGroup::mvSimpleFlockGroup() : mvBaseBehaviour(MV_SIMPLE_FLOCK_GROUP_ENTRY)
{

}

void mvSimpleFlockGroup::groupOperation(mvWorld* worldPtr, mvGroup* groupPtr)
{
   // DOES SOMETHING
}

mvBehaviourReturnType mvSimpleFlockGroup::bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
   // DOES NOTHING
   return MV_NO_OPERATION;
}

mvBaseBehaviour* mvCreateSimpleFlock::operator()(mvBaseBehaviour* defaultBehaviour)
{
   mvOptionEnum type;

   if (defaultBehaviour == NULL)
   {
      return new mvSimpleFlockDefaultGroup();
   }

   type = defaultBehaviour->getType();
   // uses fast check instead of type checking
   // from default main group creation
   if (type == MV_SIMPLE_FLOCK)
   {
      return new mvSimpleFlockGroup();
   }
   else if (type == MV_SIMPLE_FLOCK_GROUP_ENTRY)
   {
      return new mvSimpleFlock();
   }
   else
   {
      // if something odd happess ??
      return NULL;
   }
}
