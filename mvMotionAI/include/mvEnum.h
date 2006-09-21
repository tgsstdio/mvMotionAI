/**
 *\file mvEnum.h
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

#ifndef MOTIONAI_MVENUM_H_
#define MOTIONAI_MVENUM_H_
#include <cstdlib>
/**
 *\enum mvEnum
 *
 *Log
 *
 *version      date     comments
 *00-01-03    21/6/06   - split enums and their string into header and source file.
 *
 *00-01-00    22/5/06   - initialised enums
 */
enum mvEnum{
   // MV_BOOLEAN

   MV_FALSE = 0,
   MV_TRUE,

   // MV BODY ENUMS
   MV_SPEED,
   MV_MASS,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_PARTICLE,
   MV_VEHICLE,
   MV_DUAL_TYPE,
   MV_BODY_TYPE,
   MV_POSITION,
   MV_FULL_3D_DOMAIN, //< default
   MV_XY_PLANE_DOMAIN,
   MV_XZ_PLANE_DOMAIN,
   MV_YZ_PLANE_DOMAIN,
   MV_X_AXIS_ONLY_DOMAIN,
   MV_Y_AXIS_ONLY_DOMAIN,
   MV_Z_AXIS_ONLY_DOMAIN,
   MV_ANY_PLANE_DOMAIN,
   MV_ANY_LINE_DOMAIN,
   MV_NO_DOMAIN_APPLIED,
   MV_BODY_STATE,
   MV_APPLY_MOTIONAI_STATE,
   MV_NO_MOTION_STATE,
   MV_USER_MOTION_STATE,
   MV_APPLY_NO_FORCES_STATE,
   MV_INVALID_BODY_STATE,
   MV_BODY_DOMAIN,
   MV_INVALID_BODY_TYPE,
   MV_BODY_SHAPE,
   MV_INVALID_BODY_PARAMETER,
   MV_INVALID_SHAPE_TYPE,

   // MV_OBSTACLE TYPES
   MV_MINUS_AABOX,
   MV_MINUS_AACYLINDER,
   MV_MINUS_SPHERE,
   MV_X_AXIS_AA_CYLINDER,
   MV_Y_AXIS_AA_CYLINDER,
   MV_Z_AXIS_AA_CYLINDER,
   MV_LENGTH,
   MV_OBSTACLE_TYPE,
   MV_OBSTACLE_STATE,
   MV_SOLID_OBSTACLE,
   MV_LIQUID_OBSTACLE,
   MV_AIR_OBSTACLE,
   MV_INVALID_OBSTACLE_STATE,
   MV_INVALID_OBSTACLE_TYPE,
   MV_INVALID_OBSTACLE_PARAMETER,

   // MV_WAYPOINT_TYPES
   MV_SPHERE,
   MV_AABOX,
   MV_RADIUS,
   MV_X_WIDTH,
   MV_Y_LENGTH,
   MV_Z_DEPTH,
   MV_NO_SHAPE,
   MV_NURB_WAYPOINT,
   MV_SINGLE_WAYPOINT,
   MV_GROUP_WAYPOINT,
   MV_WAYPOINT_TYPE,
   MV_WAYPOINT_SHAPE,
   MV_AABOX_DIMENSIONS,
   MV_AACYLINDER_DIMENSIONS,
   MV_INVALID_WAYPOINT_PARAMETER,
   MV_INVALID_WAYPOINT_TYPE,

   // MV FORCE
   MV_FORCE_VECTOR,
   MV_FORCE_ON,
   MV_FORCE_OFF,
   MV_ENABLE_FORCE,
   MV_VELOCITY,
   MV_FORCE_TYPE,
   MV_INVALID_FORCE_TYPE,
   // force types
MV_DIRECTION_FORCE_TO_POINT,
MV_DIRECTION_SHIFT_TO_POINT,
MV_DRAG_ACCELERATION,
MV_DRAG_FORCE,
MV_DRAG_SHIFT,
MV_FORCE_FIELD_ATTRACT,
MV_FORCE_FIELD_FLUSH,
MV_FORCE_FIELD_REPELL,
MV_GRAVITY,
MV_GRAVITY_TO_POINT,
MV_NULL_ACCELERATION,
MV_NULL_ALL,
MV_NULL_DRAG,
MV_NULL_FIELD,
MV_NULL_FORCE,
MV_NULL_GRAVITY,
MV_NULL_SHIFT,
MV_UNIFORM_ACCELERATION,
MV_UNIFORM_FORCE,
MV_UNIFORM_SHIFT,
// force parameters
//MV_ACCELERATION,
MV_ACCELERATION_VECTOR,
MV_FORCE_QUANTITY,
//MV_FORCE_VECTOR,
MV_GRAVITIONAL_MASS,
MV_GRAVITY_CONSTANT,
//MV_POSITION,
//MV_SPEED,
//MV_VELOCITY,
MV_DIRECTION,
MV_INVALID_FORCE_PARAMETER,
MV_INVALID_FORCE_OPTION,

// mv behaviour type enums
  MV_SEEK,
  MV_CLONE,
  MV_FLEE,
  MV_FOLLOW_PATH,
  MV_INVALID_BEHAVIOUR_TYPE,
  MV_PURSUIT,
  MV_EVASION,
  MV_WANDER,
  MV_SPIN,
  MV_GROUP_BOIDS,
  MV_EXISTING_BEHAVIOUR,
  MV_EXISTING_GROUP_BEHAVIOUR,
  MV_INVALID_BEHAVIOUR_ENTRY_TYPE,
  MV_INVALID_BEHAVIOUR_PARAMETER,
  MV_BEHAVIOUR_WAYPOINT_TARGET,
  MV_BEHAVIOUR_BODY_TARGET,
  MV_BEHAVIOUR_PATHWAY_TARGET,
  MV_INVALID_BEHAVIOUR_PARAM_OPTION,

  // mv behaviour entry
  MV_SIMPLE_FLOCK,
  MV_SIMPLE_FLOCK_GROUP_ENTRY,
  MV_PERCEIVED_COHESION_FLAG,
  MV_PERCEIVED_ALIGNMENT_FLAG,
//   MV_NO_OF_SIMPLE_FLOCK_STATES,
  MV_COHESION_FACTOR,
  MV_SEPARATION_FACTOR,
  MV_ALIGNMENT_FACTOR,

   // mv end enums
   MV_NO_OF_ENUMS,

   MV_NO_OF_NURBS_POINTS = 3,
   MV_NO_OF_SINGLE_POINTS = 1,
   MV_NO_OF_GROUP_POINTS = 1,
   MV_NO_OF_INVALID_POINTS = 0,
   MV_NO_OF_AABOX_DIMENSIONS = 3,
   MV_AABOX_X_LENGTH_INDEX_NO = 0,
   MV_AABOX_Y_LENGTH_INDEX_NO = 1,
   MV_AABOX_Z_LENGTH_INDEX_NO = 2,
   MV_NO_OF_SPHERE_DIMENSIONS = 1,
   MV_SPHERE_RADIUS_INDEX_NO = 0,
   MV_NO_OF_AACYLINDER_DIMENSIONS = 2,
   MV_AACYLINDER_RADIUS_INDEX_NO = 0,
   MV_AACYLINDER_LENGTH_INDEX_NO = 1,
   MV_MAX_NO_OF_OBSTACLE_DIMENSIONS = 4,
   MV_MAX_NO_OF_WAYPOINT_DIMENSIONS = 3,
   MV_MAX_NO_OF_BODY_DIMENSIONS = 3,
   MV_MAX_NO_OF_WAYPOINT_POINTS = 3,
   MV_INVALID_DIMENSIONS = 0,
   MV_NO_CURRENT_INDEX = -1,
   MV_MAX_NO_OF_BODY_DOMAIN_VARIABLES = 3,
   MV_NO_OF_FULL_3D_VARIABLES = 0,
   MV_NO_OF_XY_PLANE_VARIABLES = 0,
   MV_NO_OF_XZ_PLANE_VARIABLES = 0,
   MV_NO_OF_YZ_PLANE_VARIABLES = 0,
   MV_NO_OF_X_AXIS_ONLY_VARIABLES = 0,
   MV_NO_OF_Y_AXIS_ONLY_VARIABLES = 0,
   MV_NO_OF_Z_AXIS_ONLY_VARIABLES = 0,
   MV_NO_OF_ANY_PLANE_VARIABLES = 3,
   MV_NO_OF_ANY_LINE_VARIABLES = 3,
   MV_INVALID_DOMAIN_NO_OF_VARIABLES = 0,
   MV_WAYPOINT_MAIN_POSITION_INDEX = 0,
   MV_VEC3_X_INDEX_NO = 0,
   MV_VEC3_Y_INDEX_NO = 1,
   MV_VEC3_Z_INDEX_NO = 2,
   MV_NO_OF_GRAVITY_VARIABLES = 1,
   MV_NO_OF_UNIFORM_FORCE_VARIABLES = 1,
   MV_NO_OF_DIRECTION_POINT_FORCE_VARIABLES = 1,
   MV_NO_OF_GRAVITY_POINT_VARIABLES = 3,
   MV_NO_OF_FORCE_FIELD_VARIABLES = 0,
   MV_NO_OF_UNIFORM_SHIFT_VARIABLES = 1,
   MV_NO_OF_DIRECTION_POINT_SHIFT_VARIABLES = 1,
   MV_NO_OF_DRAG_SHIFT_VARIABLES = 1,
   MV_NO_OF_DRAG_ACCELERATION_VARIABLES = 1,
   MV_NO_OF_INVALID_FORCE_TYPE_VARIABLES = 0,
   MV_MAX_NO_OF_FORCE_VARIABLES = 3,
   MV_GLOBAL_FORCE_TOTAL = 0,
   MV_NO_OF_ACCELERATION_PARAMETERS = 1,
   MV_NO_OF_ACCELERATION_VECTOR_PARAMETERS = 3,
   MV_NO_OF_FORCE_QUANTITY_PARAMETERS = 1,
   MV_NO_OF_FORCE_VECTOR_PARAMETERS = 3,
   MV_NO_OF_GRAVITIONAL_MASS_PARAMETERS = 1,
   MV_NO_OF_GRAVITY_CONSTANT_PARAMETERS = 1,
   MV_NO_OF_POSITION_PARAMETERS = 3,
   MV_NO_OF_SPEED_PARAMETERS = 1,
   MV_NO_OF_VELOCITY_PARAMETERS = 3,
   MV_NO_OF_MASS_PARAMETERS = 1,
   MV_NO_OF_INVALID_OPTION_PARAMETERS = 0,
   MV_NO_OF_NULL_FORCE_TYPE_PARAMETERS = 0,
   MV_MAX_NO_OF_PARAMETERS = 3,
   MV_FORCE_ACCELERATION_VARIABLE_INDEX = 0,
   MV_FORCE_QUANTITY_VARIABLE_INDEX = 0,
   MV_FORCE_GRAVITIONAL_MASS_VARIABLE_INDEX = 1,
   MV_FORCE_GRAVITY_CONSTANT_VARIABLE_INDEX = 2,
   MV_FORCE_SPEED_VARIABLE_INDEX = 0,
   MV_OFFSET_TO_INDEX = -1,
   MV_BEHAVIOUR_SEEK_INDEX_SIZE = 1,
   MV_INVALID_BEHAVIOUR_INDEX_SIZE = 0,
   MV_MAX_BEHAVIOUR_INDEX_ARRAY_SIZE = 1,
   MV_INVALID_BEHAVIOUR_INDEX_VALUE = 0,
   MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX = 0,
   MV_BEHAVIOUR_CLONE_BODY_TARGET_INDEX = 0,
   MV_BEHAVIOUR_CLONE_INDEX_SIZE = 1,
   MV_BEHAVIOUR_PURSUIT_INDEX_SIZE = 1,
   MV_BEHAVIOUR_PURSUIT_BODY_TARGET_INDEX = 0,
   MV_MAX_BEHAVIOUR_VECTORS = 3,
   MV_INVALID_GROUP_INDEX = 0,
   MV_INVALID_BEHAVIOUR_INDEX = 0,
   MV_NO_OF_SIMPLE_FLOCK_GROUP_POINTS = 2,
   MV_NO_OF_SIMPLE_FLOCK_GROUP_VARIABLES = 1,
   MV_NO_OF_SIMPLE_FLOCK_GROUP_STATES = 2,
   MV_NO_OF_SIMPLE_FLOCK_POINTS = 0,
  MV_NO_OF_SIMPLE_FLOCK_VARIABLES = 3,
  MV_NO_OF_SIMPLE_FLOCK_STATES = 0,
  MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX = 0,
  MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX = 1,
//   MV_NO_OF_SIMPLE_FLOCK_STATES,
  MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX = 0,
  MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX,
  MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX,
  // MV ERROR ENUMS
   MV_NO_ERROR = 0,
};

const char* mvGetEnumString(mvEnum enumValue);

#endif

