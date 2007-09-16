/**
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
 * NOTE : Due to implementation, any new enum means this file must be updated
 * File version 00-01-23 11/12/06
 * Log
 *
 * version     date
 * 00-01-23    11/12/06
 * - incorrect function signature;
 *   was mvGetEnumString not mvGetErrorString
 */
#include <mv/mvEnums.h>
#include <cstring>

const char* mvOptionEnumStrings[] =
{
   "MV_FALSE",
   "MV_TRUE",
   "MV_SEEK",
   "MV_CLONE",
   "MV_FLEE",
   "MV_FOLLOW_PATH",
   "MV_PURSUIT",
   "MV_EVASION",
   "MV_SIMPLE_FLOCK",
   "MV_GROUP_ENTRY",
   "MV_EXISTING_GROUP_BEHAVIOUR",
   "MV_EXISTING_BEHAVIOUR",
   "MV_NON_GROUP_BEHAVIOUR_TYPE",
   "MV_NON_BEHAVIOUR_TYPE",
   "MV_PARTICLE",
   "MV_VEHICLE",
   "MV_DUAL_BODY",
   "MV_NON_BODY_TYPE",
   "MV_SOLID_OBSTACLE",
   "MV_LIQUID_OBSTACLE",
   "MV_AIR_OBSTACLE",
   "MV_NON_OBSTACLE_TYPE",
   "MV_AABOX",
   "MV_SPHERE",
   "MV_X_AXIS_AA_CYLINDER",
   "MV_Y_AXIS_AA_CYLINDER",
   "MV_Z_AXIS_AA_CYLINDER",
   "MV_NON_SHAPE",
   "MV_NURB_WAYPOINT",
   "MV_SINGLE_WAYPOINT",
   "MV_GROUP_WAYPOINT",
   "MV_NON_WAYPOINT_TYPE",
   "MV_DIRECTION_FORCE_TO_POINT",
   "MV_DIRECTION_SHIFT_TO_POINT",
   "MV_DRAG_ACCELERATION",
   "MV_DRAG_FORCE",
   "MV_DRAG_SHIFT",
   "MV_FORCE_FIELD_ATTRACT",
   "MV_FORCE_FIELD_FLUSH",
   "MV_FORCE_FIELD_REPELL",
   "MV_GRAVITY",
   "MV_UNIFORM_ACCELERATION",
   "MV_UNIFORM_FORCE",
   "MV_UNIFORM_SHIFT",
   "MV_NON_FORCE_TYPE",
   "MV_FULL_3D",
   "MV_XY_PLANE",
   "MV_XZ_PLANE",
   "MV_YZ_PLANE",
   "MV_X_AXIS_ONLY",
   "MV_Y_AXIS_ONLY",
   "MV_Z_AXIS_ONLY",
   "MV_ANY_PLANE",
   "MV_ANY_LINE",
   "MV_NO_DOMAIN_APPLIED",
   "MV_WEIGHTED",
   "MV_XOR",
   "MV_PRORITIZED_DITHERING",
   "MV_RANDOM",
   "MV_RANDOMIZED_WEIGHTED",
   "MV_LIST_TREE",
   "MV_NON_BEHAVIOUR_ENTRY_MODE",
   "MV_NON_OPTION_ENUM",
   "MV_NO_OF_OPTION_ENUMS",
};

const char* mvParamEnumStrings[] =
{
   "MV_NO_PARAMETER",
   "MV_SPEED",
   "MV_MAX_SPEED",
   "MV_ACCELERATION",
   "MV_DECELERATION",
   "MV_MASS",
   "MV_SHAPE",
   "MV_TYPE",
   "MV_DOMAIN",
   "MV_FORCE_VECTOR",
   "MV_VELOCITY",
   "MV_ACCELERATION_VECTOR",
   "MV_FORCE_QUANTITY",
   "MV_CONSTANT",
   "MV_POSITION",
   "MV_LENGTH",
   "MV_RADIUS",
   "MV_X_WIDTH",
   "MV_Y_HEIGHT",
   "MV_Z_DEPTH",
   "MV_DIRECTION",
   "MV_WAYPOINT",
   "MV_BODY",
   "MV_PATHWAY",
   "MV_PERCEIVED_COHESION",
   "MV_PERCEIVED_ALIGNMENT",
   "MV_COHESION_FACTOR",
   "MV_SEPARATION_FACTOR",
   "MV_ALIGNMENT_FACTOR",
   "MV_SHAPE_DIMENSIONS",
   "MV_NO_OF_SHAPE_DIMENSIONS",
   "MV_IS_ENABLED",
   "MV_DOMAIN_VARIABLES",
   "MV_NO_OF_DOMAIN_VARIABLES",
   "MV_NO_OF_BODIES",
   "MV_NO_OF_GROUPS",
   "MV_NO_OF_FORCES",
   "MV_NO_OF_WAYPOINTS",
   "MV_NO_OF_OBSTACLES",
   "MV_NO_OF_GROUP_BEHAVIOURS",
   "MV_NO_OF_BEHAVIOURS",
   "MV_NO_OF_PATHWAYS",
   "MV_WIDTH",
   "MV_DEPTH",
   "MV_MODE",
   "MV_CURRENT_INDEX",
   "MV_WEIGHT",
   "MV_FINAL_VELOCITY",
   "MV_FINAL_SPEED",
   "MV_FINAL_DIRECTION",
   "MV_PLANE_NORMAL",
   "MV_LINE_VECTOR",
   "MV_DOMAIN_NORMAL",
   "MV_ELAPSED_TIME",
   "MV_PERIOD",
   "MV_IS_TIMED",
   "MV_INDEX",
   "MV_NEW_NODE",
   "MV_NEW_LEVEL",
   "MV_NEXT_NODE",
   "MV_PREV_NODE",
   "MV_UP_LEVEL",
   "MV_DOWN_LEVEL",
   "MV_IS_CONFINED",
   "MV_GROUP",
   "MV_AUTO_CONVERT_INDEX",
   "MV_RIGHT_HANDED",
   "MV_APPLY_FORCES",
   "MV_APPLY_SHIFTS",
   "MV_APPLY_ACCELERATIONS",
   "MV_APPLY_GRAVITY",
   "MV_APPLY_COLLISIONS",
   "MV_APPLY_ALL_FORCES",
   "MV_APPLY_ALL_DRAG_FORCES",
   "MV_FACE_DIRECTION",
   "MV_OBSTACLE",
   "MV_GROUP_BEHAVIOUR",
   "MV_BEHAVIOUR",
   "MV_FORCE",
   "MV_ENTRY_TYPE",
   "MV_TORQUE",
   "MV_ROTATION",
   "MV_OMEGA",
   "MV_FINAL_FORCE",
   "MV_FINAL_TORQUE",
   "MV_FINAL_OMEGA",
   "MV_USER_PARAM_INDEX",
   "MV_USER_PARAM_0",
   "MV_USER_PARAM_1",
   "MV_USER_PARAM_2",
   "MV_USER_PARAM_3",
   "MV_NO_OF_PARAM_ENUMS",
};

const char* mvErrorEnumStrings[] =
{
   "MV_NO_ERROR",
   "MV_ITEM_POINTER_IS_NULL",
   "MV_ITEM_LIST_IS_EMPTY",
   "MV_UNIQUE_ITEM_ALREADY_IN_LIST",
   "MV_ITEM_NOT_FOUND_IN_LIST",
   "MV_ITEM_AT_INDEX_NO_LONGER_EXISTS",
   "MV_INVALID_FUNCTION_LOADER_INITIALIZATION",
   "MV_INVALID_BEHAVIOUR_PARAMETER",
   "MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION",
   "MV_INVALID_OPTION_ENUM_STRING",
   "MV_INVALID_PARAM_ENUM_STRING",
   "MV_INPUT_PARAM_STRING_IS_NULL",
   "MV_FLOAT_VALUE_IS_NOT_POSITIVE",
   "MV_INDEX_VALUE_IS_INVALID",
   "MV_INVALID_BODY_SHAPE",
   "MV_INVALID_BODY_PARAMETER",
   "MV_PARAMETER_ARRAY_IS_NULL",
   "MV_INVALID_BODY_TYPE",
   "MV_INVALID_OBSTACLE_TYPE",
   "MV_INVALID_OBSTACLE_SHAPE",
   "MV_INVALID_OBSTACLE_PARAMETER",
   "MV_INVALID_DOMAIN",
   "MV_INVALID_FORCE_TYPE",
   "MV_INVALID_FORCE_PARAMETER",
   "MV_OPTION_ENUM_DEST_IS_NULL",
   "MV_FLOAT_DEST_IS_NULL",
   "MV_COUNT_DEST_IS_NULL",
   "MV_INVALID_WAYPOINT_TYPE",
   "MV_INVALID_WAYPOINT_SHAPE",
   "MV_INVALID_WAYPOINT_PARAMETER",
   "MV_INVALID_SHAPE_PARAMETER",
   "MV_INCORRECT_SHAPE_TYPE",
   "MV_INVALID_GROUP_PARAMETER",
   "MV_INVALID_GROUP_BEHAVIOUR_PARAMETER",
   "MV_INVALID_PATHWAY_PARAMETER",
   "MV_ACTION_IS_NOT_INITIALISED",
   "MV_INVALID_BEHAVIOUR_TYPE",
   "MV_PATHWAY_CANNOT_ADDED",
   "MV_WAYPOINT_CANNOT_ADDED",
   "MV_BODY_CANNOT_ADDED",
   "MV_PATHWAY_INDEX_IS_INVALID",
   "MV_BODY_INDEX_IS_INVALID",
   "MV_WAYPOINT_INDEX_IS_INVALID",
   "MV_BEHAVIOUR_INDEX_IS_INVALID",
   "MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID",
   "MV_GROUP_INDEX_IS_INVALID",
   "MV_SRC_ARRAY_IS_NULL",
   "MV_DST_ARRAY_IS_NULL",
   "MV_INVALID_WORLD_INDEX",
   "MV_INDEX_DEST_IS_NULL",
   "MV_SCRIPT_MODULE_PTR_IS_NULL",
   "MV_SCRIPT_MODULE_PARSING_ERROR",
   "MV_C_BUFFER_ARRAY_IS_NULL",
   "MV_C_STRING_PTR_IS_NULL",
   "MV_FILENAME_POINTER_IS_NULL",
   "MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO",
   "MV_FUNCTION_NOT_IMPLEMENTED",
   "MV_OPTION_STRING_PARAM_IS_NULL",
   "MV_OPTION_STRING_DEST_IS_NULL",
   "MV_INVALID_BEHAVIOUR_LIST_PARAMETER",
   "MV_NOT_ENOUGH_FLOATS_IN_ARRAY",
   "MV_STRING_NOT_FOUND",
   "MV_INVALID_TIMER_PARAMETER",
   "MV_INVALID_BEHAVIOUR_ENTRY_TREE_PARAMETER",
   "MV_NEW_ENTRY_TREE_POSITION_IS_NOT_NULL",
   "MV_INVALID_NO_OF_MOVES_INSIDE_TREE",
   "MV_INVALID_MEMORY_ALLOCATION",
   "MV_MOTIONAI_IS_NOT_INITIALISED",
   "MV_FUNCTION_LOADER_IS_NULL",
   "MV_INVALID_WORLD_PARAMETER",
   "MV_INVALID_PATHWAY_NODE_PARAMETER",
   "MV_ACTION_LOADER_LIST_PTR_IS_NULL",
   "MV_OPTION_ENUM_KEY_IS_INVALID",
   "MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER",
   "MV_INVALID_INTEGRATION_MODE",
   "MV_INVALID_OBJECT_TYPE",
   "MV_FUNCTION_LOADER_LIST_PTR_IS_NULL",
   "MV_ITEM_IS_NOT_ENABLED",
   "MV_FORCE_INDEX_IS_INVALID",
   "MV_ERROR_ENUM_IS_NOT_FOUND",
   "MV_NO_OF_ERROR_ENUMS",
};

const char* mvGetErrorString(mvErrorEnum enumValue)
{
   if (enumValue >= 0 && enumValue <= MV_NO_OF_ERROR_ENUMS)
   {
      return mvErrorEnumStrings[enumValue];
   }
   else
   {
      return MV_NULL;
   }
}

const char* mvGetParamString(mvParamEnum param)
{
   if (param >= 0 && param <= MV_NO_OF_PARAM_ENUMS)
   {
      return mvParamEnumStrings[param];
   }
   else
   {
      return MV_NULL;
   }
}

const char* mvGetOptionString(mvOptionEnum option)
{
   if (option >= 0 && option <= MV_NO_OF_OPTION_ENUMS)
   {
      return mvOptionEnumStrings[option];
   }
   else
   {
      return MV_NULL;
   }
}

const mvOptionEnum orderedOptionEnums[] =
{
   MV_AABOX,
   MV_AIR_OBSTACLE,
   MV_ANY_LINE,
   MV_ANY_PLANE,
   MV_CLONE,
   MV_DIRECTION_FORCE_TO_POINT,
   MV_DIRECTION_SHIFT_TO_POINT,
   MV_DRAG_ACCELERATION,
   MV_DRAG_FORCE,
   MV_DRAG_SHIFT,
   MV_DUAL_BODY,
   MV_EVASION,
   MV_EXISTING_BEHAVIOUR,
   MV_EXISTING_GROUP_BEHAVIOUR,
   MV_FALSE,
   MV_FLEE,
   MV_FOLLOW_PATH,
   MV_FORCE_FIELD_ATTRACT,
   MV_FORCE_FIELD_FLUSH,
   MV_FORCE_FIELD_REPELL,
   MV_FULL_3D,
   MV_GRAVITY,
   MV_GROUP_ENTRY,
   MV_GROUP_WAYPOINT,
   MV_LIQUID_OBSTACLE,
   MV_LIST_TREE,
   MV_NO_DOMAIN_APPLIED,
   MV_NO_OF_OPTION_ENUMS,
   MV_NON_BEHAVIOUR_ENTRY_MODE,
   MV_NON_BEHAVIOUR_TYPE,
   MV_NON_BODY_TYPE,
   MV_NON_FORCE_TYPE,
   MV_NON_GROUP_BEHAVIOUR_TYPE,
   MV_NON_OBSTACLE_TYPE,
   MV_NON_OPTION_ENUM,
   MV_NON_SHAPE,
   MV_NON_WAYPOINT_TYPE,
   MV_NURB_WAYPOINT,
   MV_PARTICLE,
   MV_PRORITIZED_DITHERING,
   MV_PURSUIT,
   MV_RANDOM,
   MV_RANDOMIZED_WEIGHTED,
   MV_SEEK,
   MV_SIMPLE_FLOCK,
   MV_SINGLE_WAYPOINT,
   MV_SOLID_OBSTACLE,
   MV_SPHERE,
   MV_TRUE,
   MV_UNIFORM_ACCELERATION,
   MV_UNIFORM_FORCE,
   MV_UNIFORM_SHIFT,
   MV_VEHICLE,
   MV_WEIGHTED,
   MV_X_AXIS_AA_CYLINDER,
   MV_X_AXIS_ONLY,
   MV_XOR,
   MV_XY_PLANE,
   MV_XZ_PLANE,
   MV_Y_AXIS_AA_CYLINDER,
   MV_Y_AXIS_ONLY,
   MV_YZ_PLANE,
   MV_Z_AXIS_AA_CYLINDER,
   MV_Z_AXIS_ONLY,
};

const mvErrorEnum orderedErrorEnums[] =
{
   MV_ACTION_IS_NOT_INITIALISED,
   MV_ACTION_LOADER_LIST_PTR_IS_NULL,
   MV_BEHAVIOUR_INDEX_IS_INVALID,
   MV_BODY_CANNOT_ADDED,
   MV_BODY_INDEX_IS_INVALID,
   MV_C_BUFFER_ARRAY_IS_NULL,
   MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO,
   MV_C_STRING_PTR_IS_NULL,
   MV_COUNT_DEST_IS_NULL,
   MV_DST_ARRAY_IS_NULL,
   MV_ERROR_ENUM_IS_NOT_FOUND,
   MV_FILENAME_POINTER_IS_NULL,
   MV_FLOAT_DEST_IS_NULL,
   MV_FLOAT_VALUE_IS_NOT_POSITIVE,
   MV_FORCE_INDEX_IS_INVALID,
   MV_FUNCTION_LOADER_IS_NULL,
   MV_FUNCTION_LOADER_LIST_PTR_IS_NULL,
   MV_FUNCTION_NOT_IMPLEMENTED,
   MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID,
   MV_GROUP_INDEX_IS_INVALID,
   MV_INCORRECT_SHAPE_TYPE,
   MV_INDEX_DEST_IS_NULL,
   MV_INDEX_VALUE_IS_INVALID,
   MV_INPUT_PARAM_STRING_IS_NULL,
   MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION,
   MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER,
   MV_INVALID_BEHAVIOUR_ENTRY_TREE_PARAMETER,
   MV_INVALID_BEHAVIOUR_LIST_PARAMETER,
   MV_INVALID_BEHAVIOUR_PARAMETER,
   MV_INVALID_BEHAVIOUR_TYPE,
   MV_INVALID_BODY_PARAMETER,
   MV_INVALID_BODY_SHAPE,
   MV_INVALID_BODY_TYPE,
   MV_INVALID_DOMAIN,
   MV_INVALID_FORCE_PARAMETER,
   MV_INVALID_FORCE_TYPE,
   MV_INVALID_FUNCTION_LOADER_INITIALIZATION,
   MV_INVALID_GROUP_BEHAVIOUR_PARAMETER,
   MV_INVALID_GROUP_PARAMETER,
   MV_INVALID_INTEGRATION_MODE,
   MV_INVALID_MEMORY_ALLOCATION,
   MV_INVALID_NO_OF_MOVES_INSIDE_TREE,
   MV_INVALID_OBJECT_TYPE,
   MV_INVALID_OBSTACLE_PARAMETER,
   MV_INVALID_OBSTACLE_SHAPE,
   MV_INVALID_OBSTACLE_TYPE,
   MV_INVALID_OPTION_ENUM_STRING,
   MV_INVALID_PARAM_ENUM_STRING,
   MV_INVALID_PATHWAY_NODE_PARAMETER,
   MV_INVALID_PATHWAY_PARAMETER,
   MV_INVALID_SHAPE_PARAMETER,
   MV_INVALID_TIMER_PARAMETER,
   MV_INVALID_WAYPOINT_PARAMETER,
   MV_INVALID_WAYPOINT_SHAPE,
   MV_INVALID_WAYPOINT_TYPE,
   MV_INVALID_WORLD_INDEX,
   MV_INVALID_WORLD_PARAMETER,
   MV_ITEM_AT_INDEX_NO_LONGER_EXISTS,
   MV_ITEM_IS_NOT_ENABLED,
   MV_ITEM_LIST_IS_EMPTY,
   MV_ITEM_NOT_FOUND_IN_LIST,
   MV_ITEM_POINTER_IS_NULL,
   MV_MOTIONAI_IS_NOT_INITIALISED,
   MV_NEW_ENTRY_TREE_POSITION_IS_NOT_NULL,
   MV_NO_ERROR,
   MV_NO_OF_ERROR_ENUMS,
   MV_NOT_ENOUGH_FLOATS_IN_ARRAY,
   MV_OPTION_ENUM_DEST_IS_NULL,
   MV_OPTION_ENUM_KEY_IS_INVALID,
   MV_OPTION_STRING_DEST_IS_NULL,
   MV_OPTION_STRING_PARAM_IS_NULL,
   MV_PARAMETER_ARRAY_IS_NULL,
   MV_PATHWAY_CANNOT_ADDED,
   MV_PATHWAY_INDEX_IS_INVALID,
   MV_SCRIPT_MODULE_PARSING_ERROR,
   MV_SCRIPT_MODULE_PTR_IS_NULL,
   MV_SRC_ARRAY_IS_NULL,
   MV_STRING_NOT_FOUND,
   MV_UNIQUE_ITEM_ALREADY_IN_LIST,
   MV_WAYPOINT_CANNOT_ADDED,
   MV_WAYPOINT_INDEX_IS_INVALID,
};

const mvParamEnum orderedParamEnums[]=
{
   MV_ACCELERATION,
   MV_ACCELERATION_VECTOR,
   MV_ALIGNMENT_FACTOR,
   MV_APPLY_ACCELERATIONS,
   MV_APPLY_ALL_DRAG_FORCES,
   MV_APPLY_ALL_FORCES,
   MV_APPLY_COLLISIONS,
   MV_APPLY_FORCES,
   MV_APPLY_GRAVITY,
   MV_APPLY_SHIFTS,
   MV_AUTO_CONVERT_INDEX,
   MV_BEHAVIOUR,
   MV_BODY,
   MV_COHESION_FACTOR,
   MV_CONSTANT,
   MV_CURRENT_INDEX,
   MV_DECELERATION,
   MV_DEPTH,
   MV_DIRECTION,
   MV_DOMAIN,
   MV_DOMAIN_NORMAL,
   MV_DOMAIN_VARIABLES,
   MV_DOWN_LEVEL,
   MV_ELAPSED_TIME,
   MV_ENTRY_TYPE,
   MV_FACE_DIRECTION,
   MV_FINAL_DIRECTION,
   MV_FINAL_FORCE,
   MV_FINAL_OMEGA,
   MV_FINAL_SPEED,
   MV_FINAL_TORQUE,
   MV_FINAL_VELOCITY,
   MV_FORCE,
   MV_FORCE_QUANTITY,
   MV_FORCE_VECTOR,
   MV_GROUP,
   MV_GROUP_BEHAVIOUR,
   MV_INDEX,
   MV_IS_CONFINED,
   MV_IS_ENABLED,
   MV_IS_TIMED,
   MV_LENGTH,
   MV_LINE_VECTOR,
   MV_MASS,
   MV_MAX_SPEED,
   MV_MODE,
   MV_NEW_LEVEL,
   MV_NEW_NODE,
   MV_NEXT_NODE,
   MV_NO_OF_BEHAVIOURS,
   MV_NO_OF_BODIES,
   MV_NO_OF_DOMAIN_VARIABLES,
   MV_NO_OF_FORCES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_GROUPS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_PARAM_ENUMS,
   MV_NO_OF_PATHWAYS,
   MV_NO_OF_SHAPE_DIMENSIONS,
   MV_NO_OF_WAYPOINTS,
   MV_NO_PARAMETER,
   MV_OBSTACLE,
   MV_OMEGA,
   MV_PATHWAY,
   MV_PERCEIVED_ALIGNMENT,
   MV_PERCEIVED_COHESION,
   MV_PERIOD,
   MV_PLANE_NORMAL,
   MV_POSITION,
   MV_PREV_NODE,
   MV_RADIUS,
   MV_RIGHT_HANDED,
   MV_ROTATION,
   MV_SEPARATION_FACTOR,
   MV_SHAPE,
   MV_SHAPE_DIMENSIONS,
   MV_SPEED,
   MV_TORQUE,
   MV_TYPE,
   MV_UP_LEVEL,
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,
   MV_USER_PARAM_INDEX,
   MV_VELOCITY,
   MV_WAYPOINT,
   MV_WEIGHT,
   MV_WIDTH,
   MV_X_WIDTH,
   MV_Y_HEIGHT,
   MV_Z_DEPTH,
};

#define MV_ENUMS_DEBUG_BINARY_FLAG 1
#undef MV_ENUMS_DEBUG_BINARY_FLAG

template
<class mvClass> bool binarySearchOfEnumStrings(const char* key, mvClass* dest, const char** stringArray,
      const mvClass* enumArray, const mvClass sizeOfArrays, mvClass failedReturnItem)
{
   mvClass compareItem;

   mvIndex left = 0;
   mvIndex right = sizeOfArrays;
   //int result = -1;
   mvIndex compare;
   mvIndex index;
   mvCount ten = 0;

   if (dest == MV_NULL)
   {
      return false;
   }

#ifdef MV_ENUMS_DEBUG_BINARY_FLAG
   std::cout << "KEY : " << key << " Range : \n"<<
    stringArray[left] << " " << stringArray[right] <<std::endl;
#endif

   while (left <= right && ten < 10)
   {
      index = (right + left)/ 2;
      compareItem = enumArray[index];
#ifdef MV_ENUMS_DEBUG_BINARY_FLAG
      std::cout << index <<  " " << stringArray[compareItem] << std::endl;
#endif
      compare = strcmp(key,stringArray[compareItem]);
      ten++;
      if (compare == 0)
      {
#ifdef MV_ENUMS_DEBUG_BINARY_FLAG
         std::cout << "Found||||" << std::endl;
#endif
         *dest = compareItem;
         return true;
      }
      else if (compare < 0)
      {
#ifdef MV_ENUMS_DEBUG_BINARY_FLAG
         std::cout << "Go L" << std::endl;
#endif
         right = index - 1;
      }
      else
      {
#ifdef MV_ENUMS_DEBUG_BINARY_FLAG
         std::cout << "Go R" << std::endl;
#endif
         left = index + 1;
      }
   }
   *dest = failedReturnItem;
   return false;
}

bool mvCheckAllParamEnumsForString(const char* paramString, mvParamEnum* dest)
{
   return binarySearchOfEnumStrings<mvParamEnum>(paramString,dest,&mvParamEnumStrings[0],
      orderedParamEnums,MV_NO_OF_PARAM_ENUMS,MV_NO_PARAMETER);
}

bool mvCheckAllErrorEnumsForString(const char* errorString, mvErrorEnum* dest)
{
   return binarySearchOfEnumStrings<mvErrorEnum>(errorString,dest,&mvErrorEnumStrings[0],
      orderedErrorEnums,MV_NO_OF_ERROR_ENUMS,MV_ERROR_ENUM_IS_NOT_FOUND);
}

bool mvCheckAllOptionEnumsForString(const char* optionString, mvOptionEnum* dest)
{
   return binarySearchOfEnumStrings<mvOptionEnum>(optionString,dest,&mvOptionEnumStrings[0],
   orderedOptionEnums,MV_NO_OF_OPTION_ENUMS,MV_NON_OPTION_ENUM);
}

const char* mvMotionAI_MotionType_DescriptStrings[] =
{
   "MV_DEFAULT_MOTION",
   "MV_STEERING_MOTION",
   "MV_DIRECTIONAL_MOTION",
};

const char* mvMotionAI_EffectType_DescriptStrings[] =
{
   "MV_DEFAULT_EFFECT",
   "MV_GLOBAL_EFFECT",
   "MV_LOCAL_EFFECT",
};

const char* mvGetMotionTypeString(mvMotionTypeEnum mType)
{
   if (mType >= MV_DEFAULT_MOTION && mType <= MV_DIRECTIONAL_MOTION)
   {
      return mvMotionAI_MotionType_DescriptStrings[mType];
   }
   else
   {
      return MV_NULL;
   }
}

const char* mvGetEffectTypeString(mvEffectTypeEnum eType)
{
   if (eType >= MV_DEFAULT_EFFECT && eType <= MV_LOCAL_EFFECT)
   {
      return mvMotionAI_MotionType_DescriptStrings[eType];
   }
   else
   {
      return MV_NULL;
   }
}
