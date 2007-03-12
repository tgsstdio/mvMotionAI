/**
 * \file mvMotionAI-Types.h
 *
 * \brief defines the basic data types used in mvMotionAI
 *
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
 *
 * Log
 *
 * version     date
 * 00-01-51    12/03/07
 * - declared header file here so change of header linking is easier.
 *
 * 00-01-35    31/01/07
 * - version number and class pointers
 *
 * 00-01-20    18/11/06  \li doxygen documentation added
 */
#ifndef MV_MOTIONAI_TYPES_H_
#define MV_MOTIONAI_TYPES_H_

#define MVMOTIONAI_TYPES_VERSION "00-01-40"

/*
 * FLOATING POINT - used in Vec3 and other places
 */

#ifndef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
/**
 * \brief  flag for higher precision mvFloat data type
 *
 * default : uses float (32 bits / 4 bytes)
 * higher precision : uses double (64 bits / 8 bytes)
 * comment out the line below
 * changes the float type to double
 *
 * i.e \#undef to //\#undef
 */
#define MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT 1

#undef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
#endif

#ifdef MV_MOTIONAI_HIGHER_PRECISION_FLOATING_POINT
typedef double mvFloat;
#else
typedef float mvFloat;
#endif

/*
 * INDEXES & COUNT - used in mvVec3 and other places
 */

/**
 * \brief mvIndex / mvCount data type flag to use integer (32 bits / 4 bytes)
 */
#define MV_MOTIONAI_INDEX_TYPE_INTEGER 0

/**
 * \brief mvIndex / mvCount data type flag to use short (16 bits / 2 bytes)
 */
#define MV_MOTIONAI_INDEX_TYPE_SHORT 1

/**
 * \brief mvIndex / mvCount data type flag to use long (64 bits / 8 bytes)
 */
#define MV_MOTIONAI_INDEX_TYPE_LONG 2

// alter this value MV_MOTIONAI_INDEX_TYPE to change the index type
#ifndef MV_MOTIONAI_INDEX_TYPE
/**
 * \brief default mvIndex data type flag to use integer (int)
 */
#define MV_MOTIONAI_INDEX_TYPE MV_MOTIONAI_INDEX_TYPE_INTEGER
#endif

#if MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_SHORT
typedef short mvIndex;
typedef short mvCount;
#elif MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_LONG
typedef long mvIndex;
typedef long mvCount;
#else
typedef int mvIndex;
typedef int mvCount;
#endif

/**
 * \brief offset value to index value in mvMotionAI
 *
 * first item in list is 1, last item is n
 * (unlike C, where first item is 0 and last item is n - 1 )
 */
static const mvIndex MV_OFFSET_TO_INDEX = -1;

/**
 * \brief index value returned if error as occured
 */
static const mvIndex MV_NO_CURRENT_INDEX = 0;

/**
 * \brief maximum array length required for set and retrieving parameters
 */
static const mvCount MV_MAX_NO_OF_PARAMETERS = 4;

/*
 * complicated behaviour structure
 * must pre declared pointer ahead of time
 *
 */

#define MV_BASE_BEHAVIOUR_HEADER_FILE_H_ "mvBaseBehaviour.h"
typedef class mvBaseBehaviour* mvBaseBehaviourPtr;
typedef class mvBaseBehaviourLoader* mvBaseBehaviourLoaderPtr;

#define MV_BEHAVIOUR_HEADER_FILE_H_ "mvBehaviour_V2.h"
typedef class mvBehaviour_V2* mvBehaviourPtr;

#define MV_BEHAVIOUR_RESULT_HEADER_FILE_H_ "mvBehaviourResult.h"
typedef class mvBehaviourResult* mvBehaviourResultPtr;

#define MV_BODY_HEADER_FILE_H_ "mvBody_V2.h"
typedef class mvBody_V2* mvBodyPtr;

#define MV_FORCE_HEADER_FILE_H_ "mvForce.h"
typedef class mvForce* mvForcePtr;

#define MV_FORCE_RESULT_HEADER_FILE_H_
typedef class mvForceResult* mvForceResultPtr;

#define MV_GROUP_HEADER_FILE_H_ "mvGroup.h"
typedef class mvGroup* mvGroupPtr;

#define MV_GROUP_BEHAVIOUR_HEADER_FILE_H_ "mvGroupBehaviour_V2.h"
typedef class mvGroupBehaviour_V2* mvGroupBehaviourPtr;
typedef class mvGroupBNode_V2* mvGroupBehaviourNodePtr;

#define MV_GROUP_BEHAVIOUR_RESULT_HEADER_FILE_H_ "mvGroupBehaviourResult.h"
typedef class mvGroupBehavResult* mvGroupBehaviourResultPtr;

#define MV_OBSTACLE_HEADER_FILE_H_ "mvObstacle.h"
typedef class mvObstacle* mvObstaclePtr;

#define MV_PATHWAY_HEADER_FILE_H_ "mvPathway.h"
typedef class mvPathway* mvPathwayPtr;

#define MV_WAYPOINT_HEADER_FILE_H_ "mvWaypoint.h"
typedef class mvWaypoint* mvWaypointPtr;

#define MV_WORLD_HEADER_FILE_H_ "mvWorld2.h"
typedef class mvWorld_V2* mvWorldPtr;

#define MV_TIMER_HEADER_FILE_H_ "mvTimer.h"
typedef class mvTimer* mvTimerPtr;

#define MV_VEC_3_HEADER_FILE_H_ "mvVec3.h"
#define MV_ENUMS_HEADER_FILE_H_ "mvEnums.h"
#define MV_MOTIONAI_HEADER_FILE "mvMotionAI-V2.h"

#endif
