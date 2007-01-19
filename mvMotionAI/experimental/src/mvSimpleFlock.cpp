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
