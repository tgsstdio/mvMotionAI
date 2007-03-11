/**
 * \file mvBehaviour-Pursuit.h
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
 * Pursuit code below from Robin's Green HTML document 'Steering Behaviours' 2001
 *
 * Vector2d Pursuit::calculate(const Pilot &target)
 * {
 *   float dist = (target.pos - pos).length();
 *   Vector2d target_pos = target.predict(dist/max_speed);
 *   desired_velocity = normalise(target_pos - pos) * max_speed;
 *   return desired_velocity - vel;
 * }
 */

#ifndef MV_BEHAVIOUR_PURSUIT_H_
#define MV_BEHAVIOUR_PURSUIT_H_
#include "mvVec3.h"
#include "mvBody.h"
#include "mvMotionAI-Types.h"

mvVec3 mvBehaviour_Calculate_Pursuit(mvBodyPtr currentBody, mvBodyPtr targetBody);

#endif
