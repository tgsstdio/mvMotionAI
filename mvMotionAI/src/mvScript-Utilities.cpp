/**
 * \file mvScript-Utilities.cpp
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

#include "mvScript-Utilities.h"
//#include "mvWorld.h"
//#include "mvMotionAI.h"
#include "mvMotionAI-Types.h"
#include <cstdlib>
#include <cstring>
//#include <iostream>

#define MV_SCRIPT_DEBUG_STDOUT 1
#undef MV_SCRIPT_DEBUG_STDOUT

//mvIndex iterativeSearch(const char* key, const char** array, mvCount noOfItems);
//mvIndex binarySearch(const char* key, char** array, mvCount noOfItems);
/*
mvEnum checkIterativeArray(const char* key, const char** strArray, mvCount noOfStrings, mvEnum invalidOption,
                           const mvEnum* enumArray);

mvIndex iterativeEnumSearch(const char* key, const mvEnum* array, mvCount noOfItems)
{
   mvIndex i;
   const char* tempString = NULL;

   for (i = 0; i < noOfItems; i++)
   {
      tempString = mvGetEnumString(array[i]);

      if (tempString != NULL)
      {
#ifdef MV_SCRIPT_DEBUG_STDOUT
      std::cout << key << " <-> " << tempString << std::endl;
#endif
         if (strcmp(key,tempString) == 0)
         {
            return i;
         }
      }
   }
   return -1;
};

mvIndex binaryEnumSearch(const char* key, const mvEnum* array, mvCount noOfItems)
{
   mvIndex mid;
   mvIndex left = 0;
   mvIndex right = noOfItems - 1;
   mvIndex result = -1;
   int compare;
   mvIndex index;
   const char* tempString = NULL;

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << key << " <-> " << mvEnumString[array[0]] << std::endl;
#endif

   while (left <= right)
   {
      mid = (right + left) / 2;
      index = mid;
      tempString = mvGetEnumString(array[index]);
#ifdef MV_SCRIPT_DEBUG_STDOUT
      std::cout << "INDEX : " << index << " LEFT : " << left << " RIGHT : " << right <<std::endl;
      std::cout << key << " <-> " << tempString << std::endl;
#endif
      if (tempString != NULL)
      {
         compare = strcmp(key,tempString);
         if (compare == 0)
            return index;
          else if (compare < 0)
          {
             right = mid - 1;
          }
          else
          {
             left = mid + 1;
          }
      }
      else
      {
         // drop out
         return -1;
      }
   }
   return -1;
};

mvEnum mvScript_checkEnumArrayIteratively(const char* key, const mvEnum* array, mvCount noOfEnums, mvEnum invalidOption)
{
   mvCount index = iterativeEnumSearch(key,array,noOfEnums);

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << noOfEnums << std::endl;
#endif

   return (index == -1) ? invalidOption : array[index];
};

mvEnum mvScript_checkEnumArrayBinarySearch(const char* key, const mvEnum* array, mvCount noOfEnums, mvEnum invalidOption)
{
   mvIndex index = binaryEnumSearch(key,array,noOfEnums);

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << noOfEnums << std::endl;
#endif
   return (index == -1) ? invalidOption : array[index];
};
*/
/*
mvIndex binarySearch(const char* key, char** array, mvCount noOfItems)
{
   mvIndex mid = noOfItems / 2;
   mvIndex left = 0;
   mvIndex right = noOfItems - 1;
   mvIndex result = -1;
   int compare;
   mvIndex index;

   while (left < right)
   {
      index = mid;
      compare = strcmp(key,array[index]);
      if (compare == 0)
         return index;
      else if (compare < 0)
      {
         right = mid - 1;
      }
      else
      {
         left = mid + 1;
      }
   }
   return -1;
};
*/

/*
mvIndex iterativeSearch(const char* key, const char** array, mvCount noOfItems)
{
   mvIndex i;

   for (i = 0; i < noOfItems; i++)
   {
      if (strcmp(key,array[i]) == 0)
      {
         return i;
      }
   }
   return -1;
};
*/
/*
mvEnum checkIterativeArray(const char* key, const char** strArray, mvCount noOfStrings, mvEnum invalidOption, const mvEnum* enumArray)
{
   mvIndex index = iterativeSearch(key,strArray,noOfStrings);

   return (index == -1) ? invalidOption : enumArray[index];
};
*/
/*
static const char* mvScript_ObstacleTypeStringEnums[] = {
   mvEnumString[MV_AABOX],
   mvEnumString[MV_SPHERE],
   mvEnumString[MV_X_AXIS_AA_CYLINDER],
   mvEnumString[MV_Y_AXIS_AA_CYLINDER],
   mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
*/
/*
static const mvEnum mvScript_ObstacleShapeEnums[] =
{
  MV_AABOX,
  MV_SPHERE,
  MV_X_AXIS_AA_CYLINDER,
  MV_Y_AXIS_AA_CYLINDER,
  MV_Z_AXIS_AA_CYLINDER,
};
static const mvCount MVSCRIPT_NO_OF_OBSTACLE_SHAPES = sizeof(mvScript_ObstacleShapeEnums)/sizeof(mvEnum);
*/
/*
static const char* mvScript_ObstacleStateStringEnums[] = {
   mvEnumString[MV_AIR_OBSTACLE],
   mvEnumString[MV_LIQUID_OBSTACLE],
   mvEnumString[MV_SOLID_OBSTACLE],
};
*/
/*
static const mvEnum mvScript_ObstacleTypeEnums[] =
{
   MV_AIR_OBSTACLE,
   MV_LIQUID_OBSTACLE,
   MV_SOLID_OBSTACLE,
};

static const mvCount MVSCRIPT_NO_OF_OBSTACLE_TYPES = sizeof(mvScript_ObstacleTypeEnums)/sizeof(mvEnum);
*/

/**
 * obstacle functions
 */

mvErrorEnum CheckAllOptionEnumsForString(const char* item, mvOptionEnum& dest, mvOptionEnum failedOption, mvErrorEnum failedError)
{
   mvOptionEnum option;

   if (mvCheckAllOptionEnumsForString(item, &option))
   {
      dest = option;
      return MV_NO_ERROR;
   }
   else
   {
      dest = failedOption;
      return failedError;
   }
}

mvErrorEnum CheckAllParamEnumsForString(const char* item, mvParamEnum& dest,mvParamEnum failedParam, mvErrorEnum failedError)
{
   mvParamEnum paramFlag;

   if (mvCheckAllParamEnumsForString(item, &paramFlag))
   {
      dest = paramFlag;
      return MV_NO_ERROR;
   }
   else
   {
      dest = failedParam;
      return failedError;
   }
}

mvErrorEnum mvScript_checkObstacleShape(const char* shape, mvOptionEnum& dest)
{
  /*
  return checkIterativeArray(shape, mvScript_ObstacleTypeStringEnums, MVSCRIPT_NO_OF_OBSTACLE_TYPES,
     MV_NO_SHAPE,  mvScript_ObstacleTypeEnums);
  *
  //return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_ObstacleShapeEnums[0], MVSCRIPT_NO_OF_OBSTACLE_TYPES, MV_NO_SHAPE);
   *
   mvOptionEnum option;

   if (mvCheckAllOptionEnumsForString(shape, &option))
   {
      dest = option;
      return MV_NO_ERROR;
   }
   else
   {
      dest = MV_NON_SHAPE;
      return MV_INVALID_OBSTACLE_SHAPE;
   }
   */
   return CheckAllOptionEnumsForString(shape, dest, MV_NON_SHAPE, MV_INVALID_OBSTACLE_SHAPE);
}

mvErrorEnum mvScript_checkObstacleType(const char* type, mvOptionEnum& dest)
{
  /*
  int index = iterativeSearch(state,mvScript_ObstacleStateStringEnums,MVSCRIPT_NO_OF_OBSTACLE_STATES);

#ifdef MV_SCRIPT_DEBUG_STDOUT
  std::cout << "mv script size s= " << MVSCRIPT_NO_OF_OBSTACLE_STATES << std::endl;
#endif

  if (index == -1)
  {
     return MV_NO_SHAPE;
  }
  else
  {

#ifdef MV_SCRIPT_DEBUG_STDOUT
     puts(mvScript_ObstacleStateStringEnums[index]);
#endif

     return mvScript_ObstacleStateEnums[index];
  }
  */
  /*
  return mvScript_checkEnumArrayBinarySearch(state, &mvScript_ObstacleStateEnums[0],
     MVSCRIPT_NO_OF_OBSTACLE_STATES, MV_INVALID_OBSTACLE_STATE);
  */
  /*
   mvOptionEnum option;

   if (mvCheckAllOptionEnumsForString(shape, &option))
   {
      dest = option;
      return MV_NO_ERROR;
   }
   else
   {
      dest = MV_NON_OBSTACLE_TYPE;
      return MV_INVALID_OBSTACLE_TYPE;
   }
   */
   return CheckAllOptionEnumsForString(type, dest, MV_NON_OBSTACLE_TYPE, MV_INVALID_OBSTACLE_TYPE);
}

mvErrorEnum mvScript_checkObstacleParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_OBSTACLE_PARAMETER);
}

mvErrorEnum mvScript_checkObstacleParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_OBSTACLE_PARAMETER);
}

mvErrorEnum mvScript_checkObstacleParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_OBSTACLE_PARAMETER);
}

mvErrorEnum mvScript_checkObstacleParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option,dest,MV_NON_OPTION_ENUM,MV_INVALID_OBSTACLE_TYPE);
}

/**
 * waypoints functions
 */

/*
static const char* mvScript_WaypointTypeEnumStrings[] =
{
   mvEnumString[MV_GROUP_WAYPOINT],
   mvEnumString[MV_SINGLE_WAYPOINT],
};
*/
/*
static const mvEnum mvScript_WaypointTypeEnums[] =
{
MV_GROUP_WAYPOINT,
MV_SINGLE_WAYPOINT,
};

static const mvCount MVSCRIPT_NO_OF_WAYPOINT_TYPES = sizeof(mvScript_WaypointTypeEnums)/sizeof(mvEnum);
*/
/*
static const char* mvScript_WaypointShapeEnumStrings[] =
{
   mvEnumString[MV_AABOX],
   mvEnumString[MV_SPHERE],
   mvEnumString[MV_X_AXIS_AA_CYLINDER],
   mvEnumString[MV_Y_AXIS_AA_CYLINDER],
   mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
*/
/*
static const mvEnum mvScript_WaypointShapeEnums[] =
{
MV_AABOX,
MV_SPHERE,
MV_X_AXIS_AA_CYLINDER,
MV_Y_AXIS_AA_CYLINDER,
MV_Z_AXIS_AA_CYLINDER,
};

static const mvCount MVSCRIPT_NO_OF_WAYPOINT_SHAPES = sizeof(mvScript_WaypointShapeEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkWaypointType(const char* type, mvOptionEnum& dest)
{
   /*
   int index = iterativeSearch(type, mvScript_WaypointTypeEnumStrings, MVSCRIPT_NO_OF_WAYPOINT_TYPES);

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << "mv script size = " << MVSCRIPT_NO_OF_WAYPOINT_TYPES << std::endl;
#endif

   if (index == -1)
   {
      return MV_INVALID_WAYPOINT_TYPE;
   }
   else
   {
      return mvScript_WaypointTypeEnums[index];
   }
   */
   /*
   return  mvScript_checkEnumArrayBinarySearch(type, &mvScript_WaypointTypeEnums[0],
      MVSCRIPT_NO_OF_WAYPOINT_TYPES, MV_INVALID_WAYPOINT_TYPE);
   */

   return CheckAllOptionEnumsForString(type, dest, MV_NON_WAYPOINT_TYPE, MV_INVALID_WAYPOINT_TYPE);
}

mvErrorEnum mvScript_checkWaypointShape(const char* shape, mvOptionEnum& dest)
{
   /*
   int index = iterativeSearch(shape, mvScript_WaypointShapeEnumStrings, MVSCRIPT_NO_OF_WAYPOINT_SHAPES);
   //std::cout << "mv script size = " << MVSCRIPT_NO_OF_WAYPOINT_SHAPES << std::endl;
   if (index == -1)
   {
      return MV_INVALID_SHAPE_TYPE;
   }
   else
   {
      return mvScript_WaypointShapeEnums[index];
   }
   */
   /*
   return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_WaypointShapeEnums[0],
      MVSCRIPT_NO_OF_WAYPOINT_SHAPES, );
   */

   return CheckAllOptionEnumsForString(shape, dest, MV_NON_SHAPE, MV_INVALID_WAYPOINT_SHAPE);
}

mvErrorEnum mvScript_checkWaypointParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_WAYPOINT_PARAMETER);
}

mvErrorEnum mvScript_checkWaypointParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_WAYPOINT_PARAMETER);
}

mvErrorEnum mvScript_checkWaypointParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_WAYPOINT_PARAMETER);
}

mvErrorEnum mvScript_checkWaypointParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option,dest,MV_NON_OPTION_ENUM,MV_INVALID_WAYPOINT_TYPE);
}

/**
 * body functions
 */

/*
static const mvEnum mvScript_BodyTypeEnums[] =
{
MV_DUAL_TYPE,
MV_PARTICLE,
MV_VEHICLE,
};
*
static const char* mvScript_BodyTypeEnumStrings[] =
{
mvEnumString[MV_DUAL_TYPE],
mvEnumString[MV_PARTICLE],
mvEnumString[MV_VEHICLE],
};
*
static const mvCount MVSCRIPT_NO_OF_BODY_TYPES = sizeof(mvScript_BodyTypeEnums)/sizeof(mvEnum); //3;
*/
mvErrorEnum mvScript_checkBodyType(const char* type, mvOptionEnum& dest)
{
   /*
   int index = iterativeSearch(type,mvScript_BodyTypeEnumStrings,MVSCRIPT_NO_OF_BODY_TYPES);

   if (index == -1)
   {
      return MV_INVALID_BODY_TYPE;
   }
   else
   {
      return mvScript_BodyTypeEnums[index];
   }
   **
   return checkIterativeArray(type,mvScript_BodyTypeEnumStrings,MVSCRIPT_NO_OF_BODY_TYPES,
      MV_INVALID_BODY_TYPE,mvScript_BodyTypeEnums);
   */
/*
   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_BodyTypeEnums[0],
      MVSCRIPT_NO_OF_BODY_TYPES, MV_INVALID_BODY_TYPE);
*/
   return CheckAllOptionEnumsForString(type, dest, MV_NON_BODY_TYPE, MV_INVALID_BODY_TYPE);
}
/*
static const mvEnum mvScript_BodyShapeEnums[] =
{
MV_AABOX,
MV_SPHERE,
MV_X_AXIS_AA_CYLINDER,
MV_Y_AXIS_AA_CYLINDER,
MV_Z_AXIS_AA_CYLINDER,
};

*
static const char* mvScript_BodyShapeEnumStrings[] =
{
mvEnumString[MV_AABOX],
mvEnumString[MV_SPHERE],
mvEnumString[MV_X_AXIS_AA_CYLINDER],
mvEnumString[MV_Y_AXIS_AA_CYLINDER],
mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
static const mvCount MVSCRIPT_NO_OF_BODY_SHAPES = sizeof(mvScript_BodyShapeEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkBodyShape(const char* shape, mvOptionEnum& dest)
{
   /*
   int index = iterativeSearch(shape,mvScript_BodyShapeEnumStrings,MVSCRIPT_NO_OF_BODY_SHAPES);

   if (index == -1)
   {
      return MV_NO_SHAPE;
   }
   else
   {
      return mvScript_BodyShapeEnums[index];
   }
   **
   return checkIterativeArray(shape,mvScript_BodyShapeEnumStrings,
      MVSCRIPT_NO_OF_BODY_SHAPES,MV_NO_SHAPE,mvScript_BodyShapeEnums);
      //return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_BodyShapeEnums[0], MVSCRIPT_NO_OF_BODY_SHAPES, MV_NO_SHAPE);
   */
   return CheckAllOptionEnumsForString(shape, dest, MV_NON_SHAPE, MV_INVALID_BODY_SHAPE);
}
/*
static const mvEnum mvScript_ForceTypeEnums[] =
{
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
};
*
static const char* mvScript_ForceTypeEnumStrings[] =
{
mvEnumString[MV_DIRECTION_FORCE_TO_POINT],
mvEnumString[MV_DIRECTION_SHIFT_TO_POINT],
mvEnumString[MV_DRAG_ACCELERATION],
mvEnumString[MV_DRAG_FORCE],
mvEnumString[MV_DRAG_SHIFT],
mvEnumString[MV_FORCE_FIELD_ATTRACT],
mvEnumString[MV_FORCE_FIELD_FLUSH],
mvEnumString[MV_FORCE_FIELD_REPELL],
mvEnumString[MV_GRAVITY],
mvEnumString[MV_GRAVITY_TO_POINT],
mvEnumString[MV_NULL_ACCELERATION],
mvEnumString[MV_NULL_ALL],
mvEnumString[MV_NULL_DRAG],
mvEnumString[MV_NULL_FIELD],
mvEnumString[MV_NULL_FORCE],
mvEnumString[MV_NULL_GRAVITY],
mvEnumString[MV_NULL_SHIFT],
mvEnumString[MV_UNIFORM_ACCELERATION],
mvEnumString[MV_UNIFORM_FORCE],
mvEnumString[MV_UNIFORM_SHIFT],
};
*
static const mvCount MVSCRIPT_NO_OF_FORCE_TYPES = sizeof(mvScript_ForceTypeEnums)/sizeof(mvEnum);
*/

mvErrorEnum mvScript_checkBodyParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_BODY_PARAMETER);
}

mvErrorEnum mvScript_checkBodyParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_BODY_PARAMETER);
}

mvErrorEnum mvScript_checkBodyParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_BODY_PARAMETER);
}

mvErrorEnum mvScript_checkBodyParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option,dest,MV_NON_OPTION_ENUM,MV_INVALID_BODY_TYPE);
}

/*
 * force functions
 */
mvErrorEnum mvScript_checkForceType(const char* type, mvOptionEnum& dest)
{
   /*
   int index = iterativeSearch(type,mvScript_ForceTypeEnumStrings,MVSCRIPT_NO_OF_FORCE_TYPES);

   if (index == -1)
   {
      return MV_INVALID_FORCE_TYPE;
   }
   else
   {
      return mvScript_ForceTypeEnums[index];
   }
   **
   return checkIterativeArray(type,mvScript_ForceTypeEnumStrings,MVSCRIPT_NO_OF_FORCE_TYPES,
      MV_INVALID_FORCE_TYPE,mvScript_ForceTypeEnums);
   //return mvScript_checkEnumArrayBinarySearch(type,&mvScript_ForceTypeEnums[0], MVSCRIPT_NO_OF_FORCE_TYPES, MV_INVALID_FORCE_TYPE);
   */
   return CheckAllOptionEnumsForString(type,dest,MV_NON_OPTION_ENUM,MV_INVALID_FORCE_TYPE);
}

mvErrorEnum mvScript_checkForceParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_FORCE_PARAMETER);
}

/*
static const mvEnum mvScript_ForceParamsvEnums[] =
{
MV_ACCELERATION,
MV_ACCELERATION_VECTOR,
MV_DIRECTION,
MV_FORCE_QUANTITY,
MV_FORCE_VECTOR,
MV_GRAVITIONAL_MASS,
MV_GRAVITY_CONSTANT,
MV_POSITION,
MV_SPEED,
MV_VELOCITY,
};
*
static const char* mvScript_ForceParamsvEnumStrings[] =
{
mvEnumString[MV_ACCELERATION],
mvEnumString[MV_ACCELERATION_VECTOR],
mvEnumString[MV_DIRECTION],
mvEnumString[MV_FORCE_QUANTITY],
mvEnumString[MV_FORCE_VECTOR],
mvEnumString[MV_GRAVITIONAL_MASS],
mvEnumString[MV_GRAVITY_CONSTANT],
mvEnumString[MV_POSITION],
mvEnumString[MV_SPEED],
mvEnumString[MV_VELOCITY],
};
*
static const mvCount MVSCRIPT_NO_OF_FORCE_PARAMSV = sizeof(mvScript_ForceParamsvEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkForceParamsv(const char* params, mvParamEnum& dest)
{
   /*
   int index = iterativeSearch(type,mvScript_ForceParamsvEnumStrings,MVSCRIPT_NO_OF_FORCE_PARAMSV);

   if (index == -1)
   {
      return MV_INVALID_FORCE_TYPE;
   }
   else
   {
      return mvScript_ForceParamsvEnums[index];
   }
   **
   return checkIterativeArray(params,mvScript_ForceParamsvEnumStrings,MVSCRIPT_NO_OF_FORCE_PARAMSV,
       MV_INVALID_FORCE_PARAMETER,mvScript_ForceParamsvEnums);
   */
/*
   return mvScript_checkEnumArrayBinarySearch(params, &mvScript_ForceParamsvEnums[0],
      MVSCRIPT_NO_OF_FORCE_PARAMSV, MV_INVALID_FORCE_PARAMETER);
*/
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER,MV_INVALID_FORCE_PARAMETER);
}
/*
static const mvEnum mvScript_ForceParamsFlagEnums[] =
{
MV_ENABLE_FORCE,
MV_FORCE_TYPE,
};
*
static const char* mvScript_ForceParamsFlagEnumStrings[] =
{
mvEnumString[MV_ENABLE_FORCE],
mvEnumString[MV_FORCE_TYPE],
};
*
static const mvCount MVSCRIPT_NO_OF_FORCE_FLAGPARAMS = sizeof(mvScript_ForceParamsFlagEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkForceParamsFlag(const char* params, mvParamEnum& dest)
{
   /*
  return checkIterativeArray(params, mvScript_ForceParamsFlagEnumStrings, MVSCRIPT_NO_OF_FORCE_FLAGPARAMS,
            MV_INVALID_FORCE_PARAMETER, mvScript_ForceParamsFlagEnums);
   */
/*
   return mvScript_checkEnumArrayBinarySearch(params, &mvScript_ForceParamsFlagEnums[0],
      MVSCRIPT_NO_OF_FORCE_FLAGPARAMS, MV_INVALID_FORCE_PARAMETER);
*/
   return CheckAllParamEnumsForString(params,dest,MV_NO_PARAMETER, MV_INVALID_FORCE_PARAMETER);
}

/*
static const mvEnum mvScript_ForceFlagParamsOptionsEnums[] =
{
MV_DIRECTION_FORCE_TO_POINT,
MV_DIRECTION_SHIFT_TO_POINT,
MV_DRAG_ACCELERATION,
MV_DRAG_FORCE,
MV_DRAG_SHIFT,
MV_FORCE_FIELD_ATTRACT,
MV_FORCE_FIELD_FLUSH,
MV_FORCE_FIELD_REPELL,
MV_FORCE_OFF,
MV_FORCE_ON,
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
};
*
static const char* mvScript_ForceFlagParamsOptionsStrings[] =
{
mvEnumString[MV_DIRECTION_FORCE_TO_POINT],
mvEnumString[MV_DIRECTION_SHIFT_TO_POINT],
mvEnumString[MV_DRAG_ACCELERATION],
mvEnumString[MV_DRAG_FORCE],
mvEnumString[MV_DRAG_SHIFT],
mvEnumString[MV_FORCE_FIELD_ATTRACT],
mvEnumString[MV_FORCE_FIELD_FLUSH],
mvEnumString[MV_FORCE_FIELD_REPELL],
mvEnumString[MV_FORCE_OFF],
mvEnumString[MV_FORCE_ON],
mvEnumString[MV_GRAVITY],
mvEnumString[MV_GRAVITY_TO_POINT],
mvEnumString[MV_NULL_ACCELERATION],
mvEnumString[MV_NULL_ALL],
mvEnumString[MV_NULL_DRAG],
mvEnumString[MV_NULL_FIELD],
mvEnumString[MV_NULL_FORCE],
mvEnumString[MV_NULL_GRAVITY],
mvEnumString[MV_NULL_SHIFT],
mvEnumString[MV_UNIFORM_ACCELERATION],
mvEnumString[MV_UNIFORM_FORCE],
mvEnumString[MV_UNIFORM_SHIFT],
};
*
static const mvCount MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS = sizeof(mvScript_ForceFlagParamsOptionsEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkForceParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
/*
  return checkIterativeArray(option,mvScript_ForceFlagParamsOptionsStrings,MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS,
         MV_INVALID_FORCE_OPTION,mvScript_ForceFlagParamsOptionsEnums);
  */
  /*
  return mvScript_checkEnumArrayBinarySearch(option,mvScript_ForceFlagParamsOptionsEnums,
     MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS,MV_INVALID_FORCE_OPTION);\
*/
   return CheckAllOptionEnumsForString(option,dest,MV_NON_OPTION_ENUM,MV_INVALID_FORCE_PARAMETER);
}
/*
static const mvEnum mvScript_BehaviourTypes[] =
{
MV_CLONE,
MV_EVASION,
MV_FLEE,
MV_FOLLOW_PATH,
MV_PURSUIT,
MV_SEEK,
MV_SPIN,
MV_WANDER,
};
static const mvCount MVSCRIPT_NO_OF_BEHAVIOUR_TYPES = sizeof(mvScript_BehaviourTypes)/sizeof(mvEnum);
*/

/**
 * behaviour functions
 */

mvErrorEnum mvScript_checkBehaviourType(const char* type, mvOptionEnum& dest)
{
   /*
   return mvScript_checkEnumArrayIteratively(type, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
   */
   return CheckAllOptionEnumsForString(type, dest, MV_NON_BEHAVIOUR_TYPE,MV_INVALID_BEHAVIOUR_TYPE);
}
/*
static const mvEnum mvScript_AddBehaviourParams[] =
{
MV_EXISTING_BEHAVIOUR,
MV_EXISTING_GROUP_BEHAVIOUR,
};

static const mvCount MVSCRIPT_NO_OF_ADD_BEHAVIOUR_PARAMS = sizeof(mvScript_AddBehaviourParams)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkAddBehaviourOption(const char* params, mvOptionEnum& dest)
{
   /*
   mvEnum paramsCheck = mvScript_checkEnumArrayBinarySearch(params, &mvScript_AddBehaviourParams[0],MVSCRIPT_NO_OF_ADD_BEHAVIOUR_PARAMS,MV_FALSE);
   if (paramsCheck == MV_FALSE)
   {
      paramsCheck = mvScript_checkEnumArrayBinarySearch(params, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
   }
   return paramsCheck;
   */
   return CheckAllOptionEnumsForString(params, dest, MV_NON_BEHAVIOUR_TYPE,MV_INVALID_BEHAVIOUR_TYPE);
}

/*
const mvEnum mvScript_BehaviourParamsIndex[] =
{
MV_BEHAVIOUR_BODY_TARGET,
MV_BEHAVIOUR_PATHWAY_TARGET,
MV_BEHAVIOUR_WAYPOINT_TARGET,
};
const mvCount MVSCRIPT_NO_OF_BEHAVIOUR_PARAMS_INDEXES = sizeof(mvScript_BehaviourParamsIndex)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkBehaviourParamsIndex(const char* params, mvParamEnum& dest)
{
/*
    return mvScript_checkEnumArrayBinarySearch(params,&mvScript_BehaviourParamsIndex[0],
       MVSCRIPT_NO_OF_BEHAVIOUR_PARAMS_INDEXES,MV_INVALID_BEHAVIOUR_PARAMETER);
*/
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkBehaviourParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkBehaviourParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkBehaviourParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM,MV_INVALID_BEHAVIOUR_TYPE);
}

/**
 * group behaviour functions
 */

/*
const mvEnum mvScript_GroupBehaviourTypes[] =
{
MV_SIMPLE_FLOCK,
};
const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_TYPES = sizeof(mvScript_GroupBehaviourTypes)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkGroupBehaviourType(const char* type, mvOptionEnum& dest)
{
/*
   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_GroupBehaviourTypes[0],
                                     MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
*/
   return CheckAllOptionEnumsForString(type, dest, MV_NON_BEHAVIOUR_TYPE,MV_INVALID_BEHAVIOUR_TYPE);
}

/*
const mvEnum mvScript_GroupBehaviourParamsFlagsEnums[] =
{
MV_PERCEIVED_ALIGNMENT_FLAG,
MV_PERCEIVED_COHESION_FLAG,
};
const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAGS = sizeof(mvScript_GroupBehaviourParamsFlagsEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkGroupBehaviourParamsFlag(const char* params, mvParamEnum& dest)
{
   /*
   return mvScript_checkEnumArrayBinarySearch(params,&mvScript_GroupBehaviourParamsFlagsEnums[0],
      MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAGS,MV_INVALID_BEHAVIOUR_PARAMETER);
   */
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}
/*
const mvEnum mvScript_GroupBehaviourParamsvEnums[] =
{
MV_ALIGNMENT_FACTOR,
MV_COHESION_FACTOR,
MV_SEPARATION_FACTOR,
};
const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMSV = sizeof(mvScript_GroupBehaviourParamsvEnums)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkGroupBehaviourParamsv(const char* params, mvParamEnum& dest)
{
   /*
    return mvScript_checkEnumArrayBinarySearch(params,&mvScript_GroupBehaviourParamsvEnums[0],
          MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMSV,MV_INVALID_BEHAVIOUR_PARAMETER);
   */
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}
/*
const mvEnum mvScript_GroupBehaviourParamsFlagOptions[] =
{
MV_TRUE,
MV_FALSE,
};
const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAG_OPTIONS = sizeof(mvScript_GroupBehaviourParamsFlagOptions)/sizeof(mvEnum);
*/
mvErrorEnum mvScript_checkGroupBehaviourParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   /*
   return mvScript_checkEnumArrayBinarySearch(option,&mvScript_GroupBehaviourParamsFlagOptions[0],
      MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAG_OPTIONS,MV_INVALID_BEHAVIOUR_PARAM_OPTION);
   */
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM,MV_INVALID_BEHAVIOUR_TYPE);
}

mvErrorEnum mvScript_checkGroupBehaviourParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkMainGroupBehaviourParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_GROUP_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkMainGroupBehaviourParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_GROUP_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkMainGroupBehaviourParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_GROUP_BEHAVIOUR_PARAMETER);
}

mvErrorEnum mvScript_checkMainGroupBehaviourParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM,MV_INVALID_BEHAVIOUR_TYPE);
}

/**
 * pathway parameter
 */

mvErrorEnum mvScript_checkPathwayParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkPathwayParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkPathwayParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkPathwayParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM, MV_INVALID_OPTION_ENUM_STRING);
}

mvErrorEnum mvScript_checkWorldParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkWorldParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkWorldParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkWorldParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM, MV_INVALID_OPTION_ENUM_STRING);
}

mvErrorEnum mvScript_checkGroupParamsIndex(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkGroupParamsFlag(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkGroupParamsv(const char* params, mvParamEnum& dest)
{
   return CheckAllParamEnumsForString(params, dest, MV_NO_PARAMETER,MV_INVALID_PATHWAY_PARAMETER);
}

mvErrorEnum mvScript_checkGroupParamsFlagOptions(const char* option, mvOptionEnum& dest)
{
   return CheckAllOptionEnumsForString(option, dest, MV_NON_OPTION_ENUM, MV_INVALID_OPTION_ENUM_STRING);
}

