/**
 * \file mvBehaviour-SimpleFlock.h
 * Copyright (c) 2006 David Young.
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
 *
 */

#ifndef MV_GROUP_BEHAVIOUR_SIMPLE_FLOCK
#define MV_GROUP_BEHAVIOUR_SIMPLE_FLOCK
#include "mvVec3.h"
#include "mvWorld.h"
#include "mvBody.h"
#include "mvGroup.h"
#include "mvMotionAI-Types.h"
#include "mvBehaviour-Entry.h"

void mvBehaviour_SimpleFlock_GroupOperations(mvWorldPtr worldPtr, mvGroupPtr flockGroup, mvBehaviourEntry* groupData);

mvVec3 mvBehaviour_SimpleFlock_SingularOperation(mvBehaviourEntry* groupData, mvBodyPtr currentBody,
                                               mvBehaviourEntry* bodyData);
/*
class mvSimpleFlock
{
   public:
      void mvGroupFunc(mvWorldPtr worldPtr, mvGroupPtr flockGroup, mvBehaviourEntry* groupData);
      mvVec3 mvBodyFunc(mvBehaviourEntry* groupData, mvBodyPtr currentBody,
                                               mvBehaviourEntry* bodyData);
      mvBehaviourEntry* createBodyEntry(mvBehaviourEntry* defaultEntry);
      mvBehaviourEntry* createGroupEntry(mvBehaviourEntry* defaultEntry);
};
*/
#endif
