#include "mvClone.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvClone::mvClone() : mvBaseBehaviour(MV_CLONE)
{
   targetIndex = MV_NO_CURRENT_INDEX;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvClone::getParameteri(mvParamEnum param, mvIndex* index)
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_INVALID;
   }

   if (param == MV_BODY_TARGET)
   {
      *index = targetIndex;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvClone::setParameteri(mvParamEnum param, mvIndex index)
{
   if (param == MV_BODY_TARGET)
   {
      targetIndex = index;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvClone::groupOperation(mvWorld* world, mvGroup* groupPtr)
{
   puts("MV CLONE group operation");
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviourReturnType mvClone::bodyOperation(mvWorld* world, mvBody* body, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
//{
//mvVec3 mvBehaviour_Calculate_Clone(mvBody* currentBody, mvBody* targetBody,
//                                mvFloat syncRatio)
//{
//   mvVec3 finalVelocity;
//
//   if (targetBody != NULL)
//   {
//      finalVelocity = targetBody->speed * targetBody->direction;
//   }
//   return finalVelocity;
//}

   mvBody* target = NULL;

   if (world == NULL)
   {
      return MV_NO_OPERATION;
   }

   if (body == NULL)
   {
      return MV_NO_OPERATION;
   }

   target = world->mvGetBody(targetIndex);
   if (target == NULL)
   {
      return MV_NO_OPERATION;
   }

   velocity = target->getVelocity();
   // should add turning angles later

   return MV_VELOCITY_ONLY;
}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseBehaviour * mvCreateClones::operator()(mvBaseBehaviour* defaultBehav)
{
   return new mvClone();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvCreateClones::mvCreateClones()
{

}





