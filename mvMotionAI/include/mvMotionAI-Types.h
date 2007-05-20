#ifndef MV_MOTIONAI_TYPES_H_
#define MV_MOTIONAI_TYPES_H_

#define MVMOTIONAI_TYPES_VERSION "00-01-61"

#define MV_FILE_HEADER_TAG_ 1
#undef MV_FILE_HEADER_TAG_

#ifdef MV_FILE_HEADER_TAG_
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
 #endif


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
 * \brief index value returned if error as occured
 */
#define MV_NULL 0

/**
 * \brief maximum array length required for set and retrieving parameters
 */
static const mvCount MV_MAX_NO_OF_PARAMETERS = 5;

/*
 * complicated behaviour structure
 * must pre declared pointer ahead of time
 *
 */

#define MV_BASE_BEHAVIOUR_HEADER_FILE_H_ "mvBaseBehaviour.h"
typedef class mvBaseBehaviour* mvBaseBehaviourPtr;
typedef class mvBaseBehaviourLoader* mvBaseBehaviourLoaderPtr;

#define MV_BEHAVIOUR_HEADER_FILE_H_ "mvBehaviour_V2.h"
typedef class mvBehaviour_V2 mvBehaviour;
typedef class mvBehaviour_V2* mvBehaviourPtr;
typedef class mvBehaviour_V2 const * const mvConstBehaviourPtr;

#define MV_BEHAVIOUR_RESULT_HEADER_FILE_H_ "mvBehaviourResult.h"
typedef class mvBehaviourResult* mvBehaviourResultPtr;

#define MV_BODY_HEADER_FILE_H_ "mvBody_V2.h"
typedef class mvBody_V2 mvBody;
typedef class mvBody_V2* mvBodyPtr;
typedef class mvBody_V2 const * const mvConstBodyPtr;
//#define mvBodyPtr mvBody_V2*

#define MV_FORCE_HEADER_FILE_H_ "mvForce.h"
typedef class mvForce* mvForcePtr;
typedef class mvForce const * const mvConstForcePtr;

#define MV_FORCE_RESULT_HEADER_FILE_H_
typedef class mvForceResult* mvForceResultPtr;

#define MV_GROUP_HEADER_FILE_H_ "mvGroup_V2.h"
typedef class mvGroup_V2 mvGroup;
typedef class mvGroup_V2* mvGroupPtr;
typedef class mvGroup_V2 const * const mvConstGroupPtr;

#define MV_GROUP_BEHAVIOUR_HEADER_FILE_H_ "mvGroupBehaviour_V2.h"
#define MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_ "mvGroupBNode_V2.h"
typedef class mvGroupBehaviour_V2 mvGroupBehaviour;
typedef class mvGroupBehaviour_V2* mvGroupBehaviourPtr;
typedef class mvGroupBNode_V2* mvGroupBehaviourNodePtr;
typedef class mvGroupBehaviour_V2 const * const mvConstGroupBehaviourPtr;

#define MV_GROUP_BEHAVIOUR_RESULT_HEADER_FILE_H_ "mvGroupBehaviourResult.h"
typedef class mvGroupBehavResult* mvGroupBehaviourResultPtr;

#define MV_OBSTACLE_HEADER_FILE_H_ "mvObstacle_V2.h"
typedef class mvObstacle_V2 mvObstacle;
typedef class mvObstacle_V2* mvObstaclePtr;
typedef class mvObstacle_V2 const * const mvConstObstaclePtr;

#define MV_PATHWAY_HEADER_FILE_H_ "mvPathway_V2.h"
typedef class mvPathway_V2 mvPathway;
typedef class mvPathway_V2* mvPathwayPtr;
typedef class mvPathway_V2 const * const mvConstPathwayPtr;

#define MV_WAYPOINT_HEADER_FILE_H_ "mvWaypoint_V2.h"
typedef class mvWaypoint_V2 mvWaypoint;
typedef class mvWaypoint_V2* mvWaypointPtr;
typedef class mvWaypoint_V2 const * const mvConstWaypointPtr;

#define MV_WORLD_HEADER_FILE_H_ "mvWorld2.h"
typedef class mvWorld_V2* mvWorldPtr;
typedef class mvWorld_V2 const * const mvConstWorldPtr;

#define MV_TIMER_HEADER_FILE_H_ "mvBEntryTimer.h"
typedef class mvTimer* mvTimerPtr;

#define MV_BENTRY_HEADER_FILE_H_ "mvBEntry.h"
typedef class mvBEntry* mvBEntryPtr;

#define MV_BEHAV_FUNC_LIST_HEADER_FILE_H_ "mvBehavFuncList.h"
//typedef class mvBehavFuncList*  mvBehavFuncListPtr;
#define mvBehavFuncListPtr mvBehavFuncList*

#define MV_VEC_3_HEADER_FILE_H_ "mvVec3.h"
#define MV_ENUMS_HEADER_FILE_H_ "mvEnums.h"
#define MV_MOTIONAI_HEADER_FILE "mvMotionAI-V2.h"

#define MV_SHAPE_HEADER_FILE_H_ "mvShape.h"
typedef class mvShape* mvShapePtr;
typedef class mvShape const * const mvConstShapePtr;

#define MV_INDEX_SET_HEADER_FILE_H_ "mvIndexSet.h"

#endif
