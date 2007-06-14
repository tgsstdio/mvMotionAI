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
#include "mvMotionAI-Types.h"
#include "mvEnums.h"
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
"MV_SIMPLE_FLOCK_GROUP_ENTRY",
"MV_EXISTING_GROUP_BEHAVIOUR",
"MV_EXISTING_BEHAVIOUR",
"MV_NON_GROUP_BEHAVIOUR_TYPE",
"MV_NON_BEHAVIOUR_TYPE",
"MV_PARTICLE",
"MV_VEHICLE",
"MV_DUAL_TYPE",
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
"MV_MINUS_AABOX",
"MV_MINUS_SPHERE",
"MV_MINUS_X_AXIS_AA_CYLINDER",
"MV_MINUS_Y_AXIS_AA_CYLINDER",
"MV_MINUS_Z_AXIS_AA_CYLINDER",
"MV_NON_SHAPE",
"MV_NURB_WAYPOINT",
"MV_SINGLE_WAYPOINT",
"MV_GROUP_WAYPOINT",
"MV_NON_WAYPOINT_TYPE",
"MV_APPLY_MOTIONAI_STATE",
"MV_NO_MOTION_STATE",
"MV_USER_MOTION_STATE",
"MV_APPLY_NO_FORCES_STATE",
"MV_NON_BODY_STATE",
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
"MV_STATE",
"MV_SHAPE",
"MV_TYPE",
"MV_DOMAIN",
"MV_FORCE_VECTOR",
"MV_VELOCITY",
"MV_ACCELERATION_VECTOR",
"MV_FORCE_QUANTITY",
"MV_GRAVITIONAL_MASS",
"MV_GRAVITY_CONSTANT",
"MV_POSITION",
"MV_LENGTH",
"MV_RADIUS",
"MV_X_WIDTH",
"MV_Y_LENGTH",
"MV_Z_DEPTH",
"MV_DIRECTION",
"MV_WAYPOINT_TARGET",
"MV_BODY_TARGET",
"MV_PATHWAY_TARGET",
"MV_PERCEIVED_COHESION_FLAG",
"MV_PERCEIVED_ALIGNMENT_FLAG",
"MV_COHESION_FACTOR",
"MV_SEPARATION_FACTOR",
"MV_ALIGNMENT_FACTOR",
"MV_SHAPE_DIMENSIONS",
"MV_IS_ENABLED",
"MV_DOMAIN_VARIABLES",
"MV_NO_OF_BODIES",
"MV_NO_OF_GROUPS",
"MV_NO_OF_FORCES",
"MV_NO_OF_WAYPOINTS",
"MV_NO_OF_OBSTACLES",
"MV_NO_OF_GROUP_BEHAVIOURS",
"MV_NO_OF_BEHAVIOURS",
"MV_WIDTH",
"MV_DEPTH",
"MV_NO_OF_PARAM_ENUMS",
};

const char* mvErrorEnumStrings[] =
{
"MV_NO_ERROR",
"MV_ITEM_POINTER_IS_NULL",
"MV_ITEM_LIST_IS_EMPTY",
"MV_INVALID_INDEX_RANGE",
"MV_UNIQUE_ITEM_ALREADY_IN_LIST",
"MV_ITEM_NOT_FOUND_IN_LIST",
"MV_ITEM_AT_INDEX_NO_LONGER_EXISTS",
"MV_INVALID_BEHAVIOUR_INITIALIZATION",
"MV_INVALID_BEHAVIOUR_PARAMETER",
"MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION",
"MV_INVALID_OPTION_ENUM_STRING",
"MV_INVALID_PARAM_ENUM_STRING",
"MV_INPUT_PARAM_STRING_IS_NULL",
"MV_FLOAT_VALUE_IS_NOT_POSITIVE",
"MV_INDEX_VALUE_IS_INVALID",
"MV_INVALID_BODY_SHAPE",
"MV_INVALID_BODY_STATE",
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
"MV_PARAM_POINTER_IS_NULL",
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
"MV_INDEX_DEST_IS_INVALID",
"MV_SCRIPT_MODULE_PTR_IS_NULL",
"MV_SCRIPT_MODULE_PARSING_ERROR",
"MV_C_BUFFER_ARRAY_IS_NULL",
"MV_C_STRING_PTR_IS_NULL",
"MV_FILENAME_POINTER_IS_NULL",
"MV_C_BUFFER_SIZE_IS_LESS_THAN_ZERO",
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
  // MV_APPLY_MOTIONAI_STATE,
  // MV_APPLY_NO_FORCES_STATE,
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
   MV_GRAVITY_TO_POINT,
   MV_GROUP_WAYPOINT,
   MV_LIQUID_OBSTACLE,
   //MV_MINUS_AABOX,
  // MV_MINUS_SPHERE,
   //MV_MINUS_X_AXIS_AA_CYLINDER,
  // MV_MINUS_Y_AXIS_AA_CYLINDER,
  // MV_MINUS_Z_AXIS_AA_CYLINDER,
   MV_NO_DOMAIN_APPLIED,
  // MV_NO_MOTION_STATE,
   MV_NO_OF_OPTION_ENUMS,
   MV_NON_BEHAVIOUR_TYPE,
//   MV_NON_BODY_STATE,
   MV_NON_BODY_TYPE,
   MV_NON_FORCE_TYPE,
   MV_NON_GROUP_BEHAVIOUR_TYPE,
   MV_NON_OBSTACLE_TYPE,
   MV_NON_OPTION_ENUM,
   MV_NON_SHAPE,
   MV_NON_WAYPOINT_TYPE,
   MV_NULL_ACCELERATION,
   MV_NULL_ALL,
   MV_NULL_DRAG,
   MV_NULL_FIELD,
   MV_NULL_FORCE,
   MV_NULL_GRAVITY,
   MV_NULL_SHIFT,
   MV_NURB_WAYPOINT,
   MV_PARTICLE,
   MV_PURSUIT,
   MV_SEEK,
   MV_SIMPLE_FLOCK,
   MV_GROUP_ENTRY,
   MV_SINGLE_WAYPOINT,
   MV_SOLID_OBSTACLE,
   MV_SPHERE,
   MV_TRUE,
   MV_UNIFORM_ACCELERATION,
   MV_UNIFORM_FORCE,
   MV_UNIFORM_SHIFT,
//   MV_USER_MOTION_STATE,
   MV_VEHICLE,
   MV_X_AXIS_AA_CYLINDER,
   MV_X_AXIS_ONLY,
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
   MV_BEHAVIOUR_INDEX_IS_INVALID,
   MV_ACTION_IS_NOT_INITIALISED,
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
   MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID,
   MV_GROUP_INDEX_IS_INVALID,
   //MV_INDEX_DEST_IS_INVALID,
   MV_INDEX_VALUE_IS_INVALID,
   MV_INPUT_PARAM_STRING_IS_NULL,
   MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION,
  // MV_INVALID_BEHAVIOUR_INITIALIZATION,
   MV_INVALID_BEHAVIOUR_PARAMETER,
   MV_INVALID_BEHAVIOUR_TYPE,
   MV_INVALID_BODY_PARAMETER,
   MV_INVALID_BODY_SHAPE,
   //MV_INVALID_BODY_STATE,
   MV_INVALID_BODY_TYPE,
   MV_INVALID_DOMAIN,
   MV_INVALID_FORCE_PARAMETER,
   MV_INVALID_FORCE_TYPE,
   MV_INVALID_GROUP_BEHAVIOUR_PARAMETER,
   MV_INVALID_GROUP_PARAMETER,
   //MV_INVALID_INDEX_RANGE,
   MV_INVALID_OBSTACLE_PARAMETER,
   MV_INVALID_OBSTACLE_SHAPE,
   MV_INVALID_OBSTACLE_TYPE,
   MV_INVALID_OPTION_ENUM_STRING,
   MV_INVALID_PARAM_ENUM_STRING,
   MV_INVALID_PATHWAY_PARAMETER,
   MV_INVALID_WAYPOINT_PARAMETER,
   MV_INVALID_WAYPOINT_SHAPE,
   MV_INVALID_WAYPOINT_TYPE,
   MV_INVALID_WORLD_INDEX,
   MV_ITEM_AT_INDEX_NO_LONGER_EXISTS,
   MV_ITEM_LIST_IS_EMPTY,
   MV_ITEM_NOT_FOUND_IN_LIST,
   MV_ITEM_POINTER_IS_NULL,
   MV_NO_ERROR,
   MV_NO_OF_ERROR_ENUMS,
   MV_OPTION_ENUM_DEST_IS_NULL,
  // MV_PARAM_POINTER_IS_NULL,
   MV_PARAMETER_ARRAY_IS_NULL,
   MV_PATHWAY_CANNOT_ADDED,
   MV_PATHWAY_INDEX_IS_INVALID,
   MV_SCRIPT_MODULE_PARSING_ERROR,
   MV_SCRIPT_MODULE_PTR_IS_NULL,
   MV_SRC_ARRAY_IS_NULL,
   MV_UNIQUE_ITEM_ALREADY_IN_LIST,
   MV_WAYPOINT_CANNOT_ADDED,
   MV_WAYPOINT_INDEX_IS_INVALID,
};

const mvParamEnum orderedParamEnums[]=
{
   MV_ACCELERATION,
   MV_ACCELERATION_VECTOR,
   MV_ALIGNMENT_FACTOR,
   MV_BODY,
   MV_COHESION_FACTOR,
   MV_DECELERATION,
   MV_DEPTH,
   MV_DIRECTION,
   MV_DOMAIN,
   MV_DOMAIN_VARIABLES,
   MV_FORCE_QUANTITY,
   MV_FORCE_VECTOR,
   //MV_GRAVITIONAL_MASS,
   //MV_GRAVITY_CONSTANT,
   MV_IS_ENABLED,
   MV_LENGTH,
   MV_MASS,
   MV_MAX_SPEED,
   MV_NO_OF_BEHAVIOURS,
   MV_NO_OF_BODIES,
   MV_NO_OF_FORCES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_GROUPS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_PARAM_ENUMS,
   MV_NO_OF_WAYPOINTS,
   MV_NO_PARAMETER,
   MV_PATHWAY,
   MV_PERCEIVED_ALIGNMENT,
   MV_PERCEIVED_COHESION,
   MV_POSITION,
   MV_RADIUS,
   MV_SEPARATION_FACTOR,
   MV_SHAPE,
   MV_SHAPE_DIMENSIONS,
   MV_SPEED,
//   MV_STATE,
   MV_TYPE,
   MV_VELOCITY,
   MV_WAYPOINT,
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
