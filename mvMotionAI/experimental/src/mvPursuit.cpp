#include "mvPursuit.h"

mvCreatePursuits::mvCreatePursuits()
{

};

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseBehaviour* mvCreatePursuits::operator()(mvBaseBehaviour* defaultBehav)
{
   return new mvPursuit();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPursuit::getParameteri(mvParamEnum param, mvIndex* index)
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_INVALID;
   }

   if (param == MV_BODY_TARGET)
   {
      *index = targetObject;
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
mvErrorEnum mvPursuit::setParameteri(mvParamEnum param, mvIndex index)
{
   if (param == MV_BODY_TARGET)
   {
      targetObject = index;
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
mvBehaviourReturnType mvPursuit::bodyOperation(mvWorld* world, mvBody* body, mvBaseBehaviour* groupNodeBehaviour,
   mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
//mvVec3 mvBehaviour_Calculate_Pursuit(mvBody* currentBody, mvBody* targetBody)
//{
//   mvVec3 targetDir, finalVelocity, desiredVelocity, nextPos;
//   mvFloat dist = 0.0;
//   if (currentBody != NULL && targetBody != NULL)
//   {
//      dist = (targetBody->position - currentBody->position).length();
//
//      nextPos = targetBody->position + (targetBody->direction * targetBody->speed * (dist/currentBody->maxSpeed));
//
//      desiredVelocity = (nextPos - currentBody->position).normalize() * currentBody->maxSpeed;
//
//      //finalVelocity = (desiredVelocity - (currentBody->speed * currentBody->direction)) + (currentBody->speed * currentBody->direction);
//      finalVelocity = desiredVelocity;
//      finalVelocity *= 0.5;
//   }
//   return finalVelocity;
//}
   mvVec3 targetDir, desiredVelocity, nextPos;
   mvBody* target = NULL;
   mvFloat period = 0;

   if (world == NULL)
   {
      return MV_NO_OPERATION;
   }

   if (body == NULL)
   {
      return MV_NO_OPERATION;
   }

   target = world->mvGetBody(targetObject);

   if (target == NULL)
   {
      return MV_NO_OPERATION;
   }

   targetDir.setAll(target->position);
   targetDir.minusVec3(body->position);

   period = targetDir.length();
   period /= body->maxSpeed;

   // nextPos = targetBody->position +
   //(targetBody->direction * targetBody->speed *
   // (dist/currentBody->maxSpeed));

   nextPos.setAll(target->direction);
   nextPos *= target->speed;
   nextPos *= period;
   nextPos.addVec3(target->position);

   // desiredVelocity = (nextPos - currentBody->position).normalize()
   // * currentBody->maxSpeed;
   // finalVelocity = desiredVelocity;
   // finalVelocity *= 0.5;
   desiredVelocity.setAll(nextPos);
   desiredVelocity.minusVec3(body->position);
   velocity = desiredVelocity.normalize();
   velocity *= body->maxSpeed;
   velocity *= 0.5;

   return MV_VELOCITY_ONLY;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvPursuit::groupOperation(mvWorld* world, mvGroup* groupPtr)
{
   puts("PURSUIT - GROUP OPERATION");
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPursuit::mvPursuit() : mvBaseBehaviour(MV_PURSUIT)
{
   targetObject = MV_NO_CURRENT_INDEX;
}
