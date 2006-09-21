/**
 * \file mvEnum.cpp
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

#include "mvEnum.h"

const char* mvEnumString[] = {
   // MV BOOLEAN ENUMS
   "MV_FALSE",
   "MV_TRUE",
   // MV BODY ENUMS
   "MV_SPEED",
   "MV_MASS",
   "MV_MAX_SPEED",
   "MV_ACCELERATION",
   "MV_DECELERATION",
   "MV_PARTICLE",
   "MV_VEHICLE",
   "MV_DUAL_TYPE",
   "MV_BODY_TYPE",
   "MV_POSITION",
   "MV_FULL_3D_DOMAIN", //< default
   "MV_XY_PLANE_DOMAIN",
   "MV_XZ_PLANE_DOMAIN",
   "MV_YZ_PLANE_DOMAIN",
   "MV_X_AXIS_ONLY_DOMAIN",
   "MV_Y_AXIS_ONLY_DOMAIN",
   "MV_Z_AXIS_ONLY_DOMAIN",
   "MV_ANY_PLANE_DOMAIN",
   "MV_ANY_LINE_DOMAIN",
   "MV_NO_DOMAIN_APPLIED",
   "MV_BODY_STATE",
   "MV_APPLY_MOTIONAI_STATE",
   "MV_NO_MOTION_STATE",
   "MV_USER_MOTION_STATE",
   "MV_APPLY_NO_FORCES_STATE",
   "MV_INVALID_BODY_STATE",
   "MV_BODY_DOMAIN",
   "MV_INVALID_BODY_TYPE",
   "MV_BODY_SHAPE",
   "MV_INVALID_BODY_PARAMETER",
   "MV_INVALID_SHAPE_TYPE",
   // MV_OBSTACLE TYPES
   "MV_MINUS_AABOX",
   "MV_MINUS_AACYLINDER",
   "MV_MINUS_SPHERE",
   "MV_X_AXIS_AA_CYLINDER",
   "MV_Y_AXIS_AA_CYLINDER",
   "MV_Z_AXIS_AA_CYLINDER",
   "MV_LENGTH",
   "MV_OBSTACLE_TYPE",
   "MV_OBSTACLE_STATE",
   "MV_SOLID_OBSTACLE",
   "MV_LIQUID_OBSTACLE",
   "MV_AIR_OBSTACLE",
   "MV_INVALID_OBSTACLE_STATE",
   "MV_INVALID_OBSTACLE_TYPE",
   "MV_INVALID_OBSTACLE_PARAMETER",
   // MV_WAYPOINT_TYPES
   "MV_SPHERE",
   "MV_AABOX",
   "MV_RADIUS",
   "MV_X_WIDTH",
   "MV_Y_LENGTH",
   "MV_Z_DEPTH",
   "MV_NO_SHAPE",
   "MV_NURB_WAYPOINT",
   "MV_SINGLE_WAYPOINT",
   "MV_GROUP_WAYPOINT",
   "MV_WAYPOINT_TYPE",
   "MV_WAYPOINT_SHAPE",
   "MV_AABOX_DIMENSIONS",
   "MV_AACYLINDER_DIMENSIONS",
   "MV_INVALID_WAYPOINT_PARAMETER",
   "MV_INVALID_WAYPOINT_TYPE",
   // MV FORCE ENUMS
   "MV_FORCE_VECTOR",
   "MV_FORCE_ON",
   "MV_FORCE_OFF",
   "MV_ENABLE_FORCE",
   "MV_VELOCITY",
   "MV_FORCE_TYPE",
   "MV_INVALID_FORCE_TYPE",
   // mv force types
   "MV_DIRECTION_FORCE_TO_POINT",
   "MV_DIRECTION_SHIFT_TO_POINT",
   "MV_DRAG_ACCELERATION",
   "MV_DRAG_FORCE",
   "MV_DRAG_SHIFT",
   "MV_FORCE_FIELD_ATTRACT",
   "MV_FORCE_FIELD_FLUSH",
   "MV_FORCE_FIELD_REPELL",
   "MV_GRAVITY",
   "MV_GRAVITY_TO_POINT",
   "MV_NULL_ACCELERATION",
   "MV_NULL_ALL",
   "MV_NULL_DRAG",
   "MV_NULL_FIELD",
   "MV_NULL_FORCE",
   "MV_NULL_GRAVITY",
   "MV_NULL_SHIFT",
   "MV_UNIFORM_ACCELERATION",
   "MV_UNIFORM_FORCE",
   "MV_UNIFORM_SHIFT",
// force parameters
//MV_ACCELERATION,
   "MV_ACCELERATION_VECTOR",
   "MV_FORCE_QUANTITY",
//MV_FORCE_VECTOR,
   "MV_GRAVITIONAL_MASS",
   "MV_GRAVITY_CONSTANT",
//MV_POSITION,
//MV_SPEED,
//MV_VELOCITY,
"MV_DIRECTION",
"MV_INVALID_FORCE_PARAMETER",
"MV_INVALID_FORCE_OPTION",
 // mv behaviour types
  "MV_SEEK",
  "MV_CLONE",
  "MV_FLEE",
  "MV_FOLLOW_PATH",
  "MV_INVALID_BEHAVIOUR_TYPE",
  "MV_PURSUIT",
  "MV_EVASION",
  "MV_WANDER",
  "MV_SPIN",
  "MV_GROUP_BOIDS",
  "MV_EXISTING_BEHAVIOUR",
  "MV_EXISTING_GROUP_BEHAVIOUR",
  "MV_INVALID_BEHAVIOUR_ENTRY_TYPE",
  "MV_INVALID_BEHAVIOUR_PARAMETER",
  "MV_BEHAVIOUR_WAYPOINT_TARGET",
  "MV_BEHAVIOUR_BODY_TARGET",
  "MV_BEHAVIOUR_PATHWAY_TARGET",
  "MV_INVALID_BEHAVIOUR_PARAM_OPTION",

  "MV_SIMPLE_FLOCK",
  "MV_SIMPLE_FLOCK_GROUP_ENTRY",
  "MV_PERCEIVED_COHESION_FLAG",
  "MV_PERCEIVED_ALIGNMENT_FLAG",
//   MV_NO_OF_SIMPLE_FLOCK_STATES,
  "MV_COHESION_FACTOR",
  "MV_SEPARATION_FACTOR",
  "MV_ALIGNMENT_FACTOR",

   // MV ENUM END
   "MV_NO_OF_ENUMS",
};

const char* mvGetEnumString(mvEnum enumValue)
{
   if (enumValue >= 0 && enumValue < MV_NO_OF_ENUMS)
   {
      return mvEnumString[enumValue];
   }
   else
   {
      return NULL;
   }
};

