/**
 * \file mvBehaviour-Central.h
 *
 * version     date     comments
 *00-01-03    21/6/06   - added processing to behaviours with central function : mvProcessBodyBehaviours
 *
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
 */

#ifndef MV_BEHAVIOUR_CENTRAL_H_
#define MV_BEHAVIOUR_CENTRAL_H_
#include "mvVec3.h"
#include "mvBody.h"
#include "mvWorld.h"
#include "mvEnums.h"
#include "mvGroupBehaviour.h"
#include "mvMotionAI-Types.h"


void mvProcessBodyBehaviours(mvWorld* worldPtr, mvBody* currentBody, mvFloat timeStep,
                             mvVec3& mvDirVector, mvVec3& mvVelocityVector,
                             mvVec3& mvAccelVector,mvVec3& mvForceVector);

void mvProcessGroupBehaviours(mvWorld* worldPtr, mvGroupBehaviour* groupBehPtr,
                              mvIndex groupIndex, mvFloat timeStep);


#endif
