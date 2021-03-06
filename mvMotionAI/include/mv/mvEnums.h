/**
 * \file mvEnums.h
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

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/*! \enum mvOptionEnum
 * \brief Option or state values within mvMotionAI library
 */
// TODO : alignment , cohension & separation behaviours
enum mvOptionEnum
{
   MV_FALSE = 0, /*!< false or zero */
   MV_TRUE, /*!< true or non zero : NOTE in boolean situation,  any error code other than MV_FALSE is true */
   MV_SEEK,
   MV_CLONE,
   MV_FLEE,
   MV_FOLLOW_PATH,
   MV_PURSUIT,
   MV_EVASION,
   MV_SIMPLE_FLOCK,
   MV_GROUP_BEHAVIOUR_MEMBER_ENTRY, /*!< RESERVED for internal use*/
   MV_EXISTING_GROUP_BEHAVIOUR, /*!< RESERVED for internal use*/
   MV_EXISTING_BEHAVIOUR, /*!< RESERVED for internal use*/
   MV_NON_GROUP_BEHAVIOUR_TYPE,
   MV_NON_BEHAVIOUR_TYPE,
   MV_PARTICLE,
   MV_VEHICLE,
   MV_DUAL_BODY,
   MV_NON_BODY_TYPE,
   MV_SOLID_OBSTACLE,
   MV_LIQUID_OBSTACLE,
   MV_AIR_OBSTACLE,
   MV_NON_OBSTACLE_TYPE,
   MV_AABOX,
   MV_SPHERE,
   MV_X_AXIS_AA_CYLINDER,
   MV_Y_AXIS_AA_CYLINDER,
   MV_Z_AXIS_AA_CYLINDER,
   MV_NON_SHAPE,
   MV_NURB_WAYPOINT,
   MV_SINGLE_WAYPOINT,
   MV_GROUP_WAYPOINT,
   MV_NON_WAYPOINT_TYPE,
   MV_DIRECTION_FORCE_TO_POINT,
   MV_DIRECTION_SHIFT_TO_POINT,
   MV_DRAG_ACCELERATION,
   MV_DRAG_FORCE,
   MV_DRAG_SHIFT,
   MV_FORCE_FIELD_ATTRACT,
   MV_FORCE_FIELD_FLUSH,
   MV_FORCE_FIELD_REPELL,
   MV_GRAVITY,
   MV_UNIFORM_ACCELERATION,
   MV_UNIFORM_FORCE,
   MV_UNIFORM_SHIFT,
   MV_NON_FORCE_TYPE,
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
   MV_WEIGHTED,
   MV_XOR,
   MV_PRORITIZED_DITHERING,
   MV_RANDOM,
   MV_RANDOMIZED_WEIGHTED,
   MV_LIST_TREE,
   MV_NON_BEHAVIOUR_ENTRY_MODE,
   MV_NON_OPTION_ENUM, // default failed enum value : do not use
   MV_NO_OF_OPTION_ENUMS
};
// TODO : reimplement param strings
/** \enum mvParamEnum
 * \brief Enums for querying and setting variables in mvMotionAI library
 */
enum mvParamEnum
{
   MV_NO_PARAMETER = 0,
   MV_SPEED,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_MASS,
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,
   MV_FORCE_VECTOR,
   MV_VELOCITY,
   MV_ACCELERATION_VECTOR,
   MV_FORCE_QUANTITY,
   MV_CONSTANT, // renamed
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH, // shorten
   MV_Y_HEIGHT, // shorten
   MV_Z_DEPTH, // shorten
   MV_DIRECTION,
   MV_WAYPOINT,
   MV_BODY,
   MV_PATHWAY,
   MV_PERCEIVED_COHESION,
   MV_PERCEIVED_ALIGNMENT,
   MV_COHESION_FACTOR,
   MV_SEPARATION_FACTOR,
   MV_ALIGNMENT_FACTOR,
   MV_SHAPE_DIMENSIONS,
   MV_NO_OF_SHAPE_DIMENSIONS,
   MV_IS_ENABLED,
   MV_DOMAIN_VARIABLES,
   MV_NO_OF_DOMAIN_VARIABLES,
   MV_NO_OF_BODIES,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   MV_NO_OF_PATHWAYS,
   MV_WIDTH,
   MV_DEPTH,
   MV_MODE,
   MV_CURRENT_INDEX,
   MV_WEIGHT,
   MV_FINAL_VELOCITY,
   MV_FINAL_SPEED,
   MV_FINAL_DIRECTION,
   MV_PLANE_NORMAL,
   MV_LINE_VECTOR,
   MV_DOMAIN_NORMAL,
   MV_ELAPSED_TIME,
   MV_PERIOD,
   MV_IS_TIMED,
   MV_INDEX,
   MV_NEW_NODE,
   MV_NEW_LEVEL,
   MV_NEXT_NODE,
   MV_PREV_NODE,
   MV_UP_LEVEL,
   MV_DOWN_LEVEL,
   MV_IS_CONFINED,
   MV_GROUP,
   MV_AUTO_CONVERT_INDEX,
   MV_RIGHT_HANDED,
   MV_APPLY_FORCES,
   MV_APPLY_SHIFTS,
   MV_APPLY_ACCELERATIONS,
   MV_APPLY_GRAVITY,
   MV_APPLY_COLLISIONS,
   MV_APPLY_ALL_FORCES,
   MV_APPLY_ALL_DRAG_FORCES,
   MV_FACE_DIRECTION,
   MV_OBSTACLE,
   MV_GROUP_BEHAVIOUR,
   MV_BEHAVIOUR,
   MV_FORCE,
   MV_ENTRY_TYPE,
   MV_TORQUE,
   MV_ROTATION,
   MV_OMEGA,
   MV_FINAL_FORCE,
   MV_FINAL_TORQUE,
   MV_FINAL_OMEGA,
   MV_USER_PARAM_INDEX,
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,
   MV_NO_OF_PARAM_ENUMS
};

// TODO : reimplement error strings
/** \enum mvErrorEnum
 * \brief Error codes in mvMotionAI library
 *
 * If no problems MV_NO_ERROR (0) is returned, else any nonzero value means
 * an error has occured. If programming with the mvMotionAI, avoid using
 * MV_ERROR_ENUM_IS_NOT_FOUND as it has no real meaning.
 */
enum mvErrorEnum
{
   MV_NO_ERROR = 0, /*!< no error has occured, normal operation */
   MV_ITEM_POINTER_IS_NULL,
   MV_ITEM_LIST_IS_EMPTY,
   MV_UNIQUE_ITEM_ALREADY_IN_LIST,
   MV_ITEM_NOT_FOUND_IN_LIST,
   MV_ITEM_AT_INDEX_NO_LONGER_EXISTS,
   MV_INVALID_FUNCTION_LOADER_INITIALIZATION, // questions - need it
   MV_INVALID_BEHAVIOUR_PARAMETER,
   MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION,
   MV_INVALID_OPTION_ENUM_STRING,
   MV_INVALID_PARAM_ENUM_STRING,

   MV_INPUT_PARAM_STRING_IS_NULL, // duplicated

   MV_FLOAT_VALUE_IS_NOT_POSITIVE,
   MV_INDEX_VALUE_IS_INVALID,
   MV_INVALID_BODY_SHAPE,
   //MV_INVALID_BODY_STATE,
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

   MV_INVALID_SHAPE_PARAMETER,
   MV_INCORRECT_SHAPE_TYPE,
   MV_INVALID_GROUP_PARAMETER,
   MV_INVALID_GROUP_BEHAVIOUR_PARAMETER,
   MV_INVALID_PATHWAY_PARAMETER,
   MV_ACTION_IS_NOT_INITIALISED,
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
   MV_INDEX_DEST_IS_NULL, // changed from ...INVALID to MV_NULL
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
   MV_NEW_ENTRY_TREE_POSITION_IS_NOT_NULL,
   MV_INVALID_NO_OF_MOVES_INSIDE_TREE,
   MV_INVALID_MEMORY_ALLOCATION, // new / delete problems
   MV_MOTIONAI_IS_NOT_INITIALISED,
   MV_FUNCTION_LOADER_IS_NULL,
   MV_INVALID_WORLD_PARAMETER,
   MV_INVALID_PATHWAY_NODE_PARAMETER,
   MV_ACTION_LOADER_LIST_PTR_IS_NULL,
   MV_OPTION_ENUM_KEY_IS_INVALID,
   MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER,
   MV_INVALID_INTEGRATION_MODE,
   MV_INVALID_OBJECT_TYPE,
   MV_FUNCTION_LOADER_LIST_PTR_IS_NULL,
   MV_ITEM_IS_NOT_ENABLED,
   MV_FORCE_INDEX_IS_INVALID,

   MV_ERROR_ENUM_IS_NOT_FOUND, // odd error
   MV_NO_OF_ERROR_ENUMS
};

// internal use only
/** \enum mvMotionTypeEnum
 * \brief Determines the type of force recorded in mvBehaviourResult
 * & mvForceResult
 */
enum mvMotionTypeEnum
{
   MV_DEFAULT_MOTION = 0, /*!< default motion applied */
   MV_STEERING_MOTION, /*!< steering motion applied i.e.
      change in motion needed*/
   MV_DIRECTIONAL_MOTION /*!< direction motion applied i.e.
      the desired final motion */
};

/** \enum mvEffectTypeEnum
 * \brief Determines the effect of the forces recorded in mvBehaviourResult
 * & mvForceResult
 */
enum mvEffectTypeEnum
{
   MV_DEFAULT_EFFECT = 0, /*!< default effect applied */
   MV_GLOBAL_EFFECT, /*!< force effect applied w.r.t.
      world/global coordinates */
   MV_LOCAL_EFFECT /*!< force effect applied w.r.t. the direction that
      the body is facing */
};

const char* mvGetMotionTypeString(mvMotionTypeEnum mType);
const char* mvGetEffectTypeString(mvEffectTypeEnum eType);

/**
 * \ingroup mvGlobal
 * \brief Retrieves C string description of the error value
 * \param[in] error An error value returned from a function
 * \return A C string description of the enum value
 *  or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX const char* mvGetErrorEnumString(mvErrorEnum error);


/**
 * \ingroup mvGlobal
 * \brief Retrieves C string description of the parameter value
 * \param[in] param An parameter/variable to retrieve data from mvMotionAI types
 * \return A C string description of the enum value
 *  or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX const char* mvGetParamEnumString(mvParamEnum param);

/**
 * \ingroup mvGlobal
 * \brief Retrieves C string description of the option value
 * \param[in] option An value/data for some of the variables in mvMotionAI
 * \return A C string description of the enum value
 *  or if error has occured, MV_NULL is returned.
 */
MV_GLOBAL_FUNC_PREFIX const char* mvGetOptionEnumString(mvOptionEnum option);


MV_GLOBAL_FUNC_PREFIX bool mvCheckAllParamEnumsForString(const char* paramString, mvParamEnum* dest);
MV_GLOBAL_FUNC_PREFIX bool mvCheckAllErrorEnumsForString(const char* errorString, mvErrorEnum* dest);
MV_GLOBAL_FUNC_PREFIX bool mvCheckAllOptionEnumsForString(const char* optionString, mvOptionEnum* dest);

#endif
