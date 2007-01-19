/**
 * Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
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





