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

#ifndef MV_ENUMERATIONS_H_
#define MV_ENUMERATIONS_H_
#include <cstdlib>
// TODO : reimplement enum strings
enum mvOptionEnum
{
   MV_FALSE = 0,
   MV_TRUE,

   // BEHAVIOURS
   MV_SEEK,
   MV_CLONE,
   MV_FLEE,
   MV_FOLLOW_PATH,
   MV_PURSUIT,
   MV_EVASION,
   MV_SIMPLE_FLOCK,
   MV_GROUP_ENTRY, // unify all group behaviorus objects
   MV_EXISTING_GROUP_BEHAVIOUR,
   MV_EXISTING_BEHAVIOUR,
   MV_NON_GROUP_BEHAVIOUR_TYPE,
   MV_NON_BEHAVIOUR_TYPE,

   // BODY types
   MV_PARTICLE,
   MV_VEHICLE,
   MV_DUAL_TYPE,
   MV_NON_BODY_TYPE,

   // obstacle type
   MV_SOLID_OBSTACLE,
   MV_LIQUID_OBSTACLE,
   MV_AIR_OBSTACLE,
   MV_NON_OBSTACLE_TYPE,

   // shapes
   MV_AABOX,
   MV_SPHERE,
   MV_X_AXIS_AA_CYLINDER,
   MV_Y_AXIS_AA_CYLINDER,
   MV_Z_AXIS_AA_CYLINDER,
   // new enumerations
   MV_MINUS_AABOX,
   MV_MINUS_SPHERE,
   MV_MINUS_X_AXIS_AA_CYLINDER,
   MV_MINUS_Y_AXIS_AA_CYLINDER,
   MV_MINUS_Z_AXIS_AA_CYLINDER,
   MV_NON_SHAPE,

   // waypoints types
   MV_NURB_WAYPOINT,
   MV_SINGLE_WAYPOINT,
   MV_GROUP_WAYPOINT,
   MV_NON_WAYPOINT_TYPE,

   //STATE
   MV_APPLY_MOTIONAI_STATE,
   MV_NO_MOTION_STATE,
   MV_USER_MOTION_STATE,
   MV_APPLY_NO_FORCES_STATE,
   MV_NON_BODY_STATE,

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
   MV_NON_FORCE_TYPE,

   // DOMAINS
   MV_FULL_3D, //< default
   MV_XY_PLANE, // used in shapes
   MV_XZ_PLANE, // used in shapes
   MV_YZ_PLANE, // used in shapes
   MV_X_AXIS_ONLY,
   MV_Y_AXIS_ONLY,
   MV_Z_AXIS_ONLY,
   MV_ANY_PLANE, // used in shapes
   MV_ANY_LINE,
   MV_NO_DOMAIN_APPLIED,

   // integration mode
   MV_WEIGHTED,
   MV_XOR,
   MV_PROTIZED_DITHERED,
   MV_RANDOM,
   MV_RANDOMIZED_WEIGHTED,
   MV_LIST_TREE,

   MV_NON_OPTION_ENUM, // default failed enum value : do not use

   MV_NO_OF_OPTION_ENUMS
};
// TODO : reimplement param strings
enum mvParamEnum
{
   MV_NO_PARAMETER = 0,
   MV_SPEED,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_MASS,
   MV_STATE,
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,
   MV_FORCE_VECTOR,

   MV_VELOCITY,
   MV_ACCELERATION_VECTOR,
   MV_FORCE_QUANTITY,
   //MV_GRAVITIONAL_MASS,  duplicate
   MV_CONSTANT, // renamed
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH,
   MV_Y_LENGTH,
   MV_Z_DEPTH,
   MV_DIRECTION,
   MV_WAYPOINT,
   MV_BODY,
   MV_PATHWAY,
   MV_PERCEIVED_COHESION_FLAG,
   MV_PERCEIVED_ALIGNMENT_FLAG,
   MV_COHESION_FACTOR,
   MV_SEPARATION_FACTOR,
   MV_ALIGNMENT_FACTOR,
   // new enums
   MV_SHAPE_DIMENSIONS,
   MV_IS_ENABLED,
   MV_DOMAIN_VARIABLES,
   MV_NO_OF_BODIES,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   MV_WIDTH,
   MV_DEPTH,
   // new enums behaviour list
   MV_MODE,
   MV_CURRENT_INDEX,
   MV_WEIGHT,
   MV_FINAL_VELOCITY,
   MV_FINAL_SPEED,
   MV_FINAL_DIRECTION,
   MV_PLANE_NORMAL,
   MV_LINE_VECTOR,
   MV_ELAPSED_TIME,
   MV_PERIOD,
   MV_IS_TIMED,
   MV_INDEX,

   // tree movement functions
   MV_NEW_NODE,
   MV_NEW_LEVEL,
   MV_NEXT_NODE,
   MV_PREV_NODE,
   MV_UP_LEVEL,
   MV_DOWN_LEVEL,

   // user defined parameters
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,
   MV_USER_PARAM_5,

   MV_NO_OF_PARAM_ENUMS
};
// TODO  : duplicate invalid index range & index is invalid
// TODO : reimplement error strings
// TODO : unify all invalid ___ parameter together ??
enum mvErrorEnum
{
   MV_NO_ERROR = 0,
   MV_ITEM_POINTER_IS_NULL,
   MV_ITEM_LIST_IS_EMPTY,
   //MV_INVALID_INDEX_RANGE, // duplicate removed
   MV_UNIQUE_ITEM_ALREADY_IN_LIST,
   MV_ITEM_NOT_FOUND_IN_LIST,
   MV_ITEM_AT_INDEX_NO_LONGER_EXISTS,
   MV_INVALID_BEHAVIOUR_INITIALIZATION, // questions - need it
   MV_INVALID_BEHAVIOUR_PARAMETER,
   MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION,
   MV_INVALID_OPTION_ENUM_STRING,
   MV_INVALID_PARAM_ENUM_STRING,

   MV_INPUT_PARAM_STRING_IS_NULL, // duplicated

   MV_FLOAT_VALUE_IS_NOT_POSITIVE,
   MV_INDEX_VALUE_IS_INVALID,
   MV_INVALID_BODY_SHAPE,
   MV_INVALID_BODY_STATE,
   MV_INVALID_BODY_PARAMETER,
   MV_PARAMETER_ARRAY_IS_NULL,
   MV_INVALID_BODY_TYPE,
   MV_INVALID_OBSTACLE_TYPE,
   MV_INVALID_OBSTACLE_SHAPE,
   MV_INVALID_OBSTACLE_PARAMETER,
   MV_INVALID_DOMAIN,
   MV_INVALID_FORCE_TYPE,
   MV_INVALID_FORCE_PARAMETER,
   MV_OPTION_ENUM_DEST_IS_NULL,
   MV_FLOAT_DEST_IS_NULL,
   MV_COUNT_DEST_IS_NULL,
   MV_INVALID_WAYPOINT_TYPE,
   MV_INVALID_WAYPOINT_SHAPE,
   MV_INVALID_WAYPOINT_PARAMETER,

   MV_INVALID_GROUP_PARAMETER,
   MV_INVALID_GROUP_BEHAVIOUR_PARAMETER,
   MV_INVALID_PATHWAY_PARAMETER,
   MV_BEHAVIOUR_IS_NOT_INITIALISED,
   MV_INVALID_BEHAVIOUR_TYPE,
   MV_PATHWAY_CANNOT_ADDED,
   MV_WAYPOINT_CANNOT_ADDED,
   MV_BODY_CANNOT_ADDED,
   MV_PATHWAY_INDEX_IS_INVALID,
   MV_BODY_INDEX_IS_INVALID,
   MV_WAYPOINT_INDEX_IS_INVALID,
   MV_BEHAVIOUR_INDEX_IS_INVALID,
   MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID,
   MV_GROUP_INDEX_IS_INVALID,
   MV_SRC_ARRAY_IS_NULL,
   MV_DST_ARRAY_IS_NULL,
   MV_INVALID_WORLD_INDEX,
   MV_INDEX_DEST_IS_NULL, // changed from ...INVALID to NULL
   MV_SCRIPT_MODULE_PTR_IS_NULL,
   MV_SCRIPT_MODULE_PARSING_ERROR,
   MV_C_BUFFER_ARRAY_IS_NULL,
   MV_C_STRING_PTR_IS_NULL,
   MV_FILENAME_POINTER_IS_NULL,
   MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO, // qurestion need it
   // new error enums
   MV_FUNCTION_NOT_IMPLEMENTED,
   MV_OPTION_STRING_PARAM_IS_NULL,
   MV_OPTION_STRING_DEST_IS_NULL,
   MV_INVALID_BEHAVIOUR_LIST_PARAMETER,
   MV_NOT_ENOUGH_FLOATS_IN_ARRAY,
   MV_STRING_NOT_FOUND,
   MV_INVALID_TIMER_PARAMETER,
   MV_INVALID_BEHAVIOUR_ENTRY_TREE_PARAMETER,

   MV_ERROR_ENUM_IS_NOT_FOUND, // odd error
   MV_NO_OF_ERROR_ENUMS
};

const char* mvGetErrorString(mvErrorEnum error);
const char* mvGetParamString(mvParamEnum param);
const char* mvGetOptionString(mvOptionEnum option);

bool mvCheckAllParamEnumsForString(const char* paramString, mvParamEnum* dest);
bool mvCheckAllErrorEnumsForString(const char* errorString, mvErrorEnum* dest);
bool mvCheckAllOptionEnumsForString(const char* optionString, mvOptionEnum* dest);

#endif
