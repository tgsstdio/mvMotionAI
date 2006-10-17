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
   MV_BODY_TYPE,
   MV_BODY_STATE,
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
   MV_NO_SHAPE,
   MV_WAYPOINT_TYPE,
   MV_WAYPOINT_SHAPE,
   MV_AABOX_DIMENSIONS,
   MV_AACYLINDER_DIMENSIONS,
   MV_INVALID_WAYPOINT_PARAMETER,
   MV_INVALID_WAYPOINT_TYPE,

   // MV FORCE

//MV_POSITION,
//MV_SPEED,

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

   MV_AABOX_X_LENGTH_INDEX_NO = 0,
   MV_AABOX_Y_LENGTH_INDEX_NO = 1,
   MV_AABOX_Z_LENGTH_INDEX_NO = 2,

   MV_SPHERE_RADIUS_INDEX_NO = 0,
   MV_AACYLINDER_RADIUS_INDEX_NO = 0,
   MV_AACYLINDER_LENGTH_INDEX_NO = 1,

   MV_VEC3_X_INDEX_NO = 0,
   MV_VEC3_Y_INDEX_NO = 1,
   MV_VEC3_Z_INDEX_NO = 2,


   MV_MAX_NO_OF_PARAMETERS = 3,
   //MV_OFFSET_TO_INDEX = -1,


   MV_MAX_BEHAVIOUR_INDEX_ARRAY_SIZE = 1,
   MV_INVALID_BEHAVIOUR_INDEX_VALUE = 0,
   MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX = 0,



   MV_MAX_BEHAVIOUR_VECTORS = 3,

  // MV ERROR ENUMS
   MV_NO_ERROR = 0,
};

const char* mvGetEnumString(mvEnum enumValue);

#endif

