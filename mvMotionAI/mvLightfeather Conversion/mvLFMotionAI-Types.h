/**
 * \file mvMotionAI-Types.h - lightfeather conversion file
 *
 * \brief defines the basic data types used in mvMotionAI
 *
 * Copyright (c) 2006, 2008 David Young.
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
 * 00-02-51    12/03/07
 * - convert all mvMotionAI types into lightfeather library values
 *
 * 00-01-51    12/03/07
 * - declared header file here so change of header linking is easier.
 *
 * 00-01-35    31/01/07
 * - version number and class pointers
 *
 * 00-01-20    18/11/06  \li doxygen documentation added
 */

#ifndef MV_LF_MOTIONAI_TYPES_HEADER_FILE_H_
#define MV_LF_MOTIONAI_TYPES_HEADER_FILE_H_

//#define MV_MOTIONAI_TYPES_HEADER_FILE_H_ <mvLFMotionAI-Types.h>

#ifndef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#define MV_MOTIONAI_TYPES_HEADER_FILE_H_ <mv/mvMotionAI-Types.h>
#endif

#include <lf/lightfeather.h>
#define MVMOTIONAI_TYPES_VERSION "00-02-01-LF"

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
/**
 * \brief floating point numbers
 */
typedef f64 mvFloat;
#else
/**
 * \brief floating point numbers
 */
typedef lf::f32 mvFloat;
#endif

/**
 * \brief mvChar - char & string variables
 */
typedef lf::s8 mvChar;

/**
 * \brief string pointer
 */
typedef const mvChar* mvConstStringPtr;

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
/**
 * \brief array index type
 */
typedef lf::s16 mvIndex;
/**
 * \brief counter / no of items type
 */
typedef lf::s16 mvCount;
#elif MV_MOTIONAI_INDEX_TYPE == MV_MOTIONAI_INDEX_TYPE_LONG
/**
 * \brief array index type
 */
typedef lf::s64 mvIndex;
/**
 * \brief counter / no of items type
 */
typedef lf::s64 mvCount;
#else
/**
 * \brief array index type
 */
typedef lf::s32 mvIndex;
/**
 * \brief counter / no of items type
 */
typedef lf::s32 mvCount;
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

#define MV_BASE_ACTION_HEADER_FILE_H_ <mv/mvBaseAction.h>
/**
 * \brief mvBaseAction pointer type
 */
typedef class mvBaseAction* mvBaseActionPtr;
/**
 * \brief mvBaseActionLoader pointer type
 */
typedef class mvBaseActionLoader* mvBaseActionLoaderPtr;

#define MV_BEHAVIOUR_HEADER_FILE_H_ <mv/mvBehaviour_V2.h>
/**
 * \brief mvBehaviour object type
 */
typedef class mvBehaviour_V2 mvBehaviour;
/**
 * \brief mvBehaviour pointer type
 */
typedef class mvBehaviour_V2* mvBehaviourPtr;
/**
 * \brief mvBehaviour const pointer type
 */
typedef class mvBehaviour_V2 const * const mvConstBehaviourPtr;

#define MV_BEHAVIOUR_RESULT_HEADER_FILE_H_ <mv/mvBehaviourResult.h>
/**
 * \brief mvBehaviourResult pointer type
 */
typedef class mvBehaviourResult* mvBehaviourResultPtr;

#define MV_BODY_HEADER_FILE_H_ <mv/mvBody_V2.h>
//typedef class mvBody_V2 mvBody; // rename
/**
 * \brief mvBody pointer type
 */
typedef class mvBody* mvBodyPtr;
/**
 * \brief mvBody const pointer type
 */
typedef class mvBody const * const mvConstBodyPtr;

#define MV_BASE_FORCE_HEADER_FILE_H_ <mv/mvBaseForce.h>
/**
 * \brief mvBaseForce pointer type
 */
typedef class mvBaseForce* mvBaseForcePtr;
/**
 * \brief mvBaseForce const pointer type
 */
typedef class mvBaseForce const * const mvConstBaseForcePtr;
/**
 * \brief mvBaseForceLoader pointer type
 */
typedef class mvBaseForceLoader* mvBaseForceLoaderPtr;

#define MV_FORCE_RESULT_HEADER_FILE_H_ <mv/mvForceResult.h>
/**
 * \brief mvForceResult pointer type
 */
typedef class mvForceResult* mvForceResultPtr;

#define MV_FORCE_CAPSULE_HEADER_FILE <mv/mvForceCapsule.h>
/**
 * \brief mvForceCapsule pointer type
 */
typedef class mvForceCapsule* mvForceCapsulePtr;
/**
 * \brief mvForceCapsule const pointer type
 */
typedef class mvForceCapsule const * const mvConstForceCapsulePtr;

#define MV_GROUP_HEADER_FILE_H_ <mv/mvGroup_V2.h>
//typedef class mvGroup_V2 mvGroup;
/**
 * \brief mvGroupIterator object type
 */
typedef class mvUniqueSetIterator mvGroupIterator;
/**
 * \brief mvGroup pointer type
 */
typedef class mvGroup* mvGroupPtr;
/**
 * \brief mvGroup const pointer type
 */
typedef class mvGroup const * const mvConstGroupPtr;

#define MV_GROUP_BEHAVIOUR_HEADER_FILE_H_ <mv/mvGroupBehaviour_V2.h>
#define MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_ <mv/mvGroupBNode_V2.h>
//typedef class mvGroupBehaviour_V2 mvGroupBehaviour;
/**
 * \brief mvGroupBehaviour pointer type
 */
typedef class mvGroupBehaviour* mvGroupBehaviourPtr;
/**
 * \brief mvGroupBehaviourGroupNode pointer type
 */
typedef class mvGroupBNode_V2* mvGroupBehaviourGroupNodePtr;
/**
 * \brief mvGroupBehaviourGroupNode object type
 */
typedef class mvGroupBNode_V2 mvGroupBehaviourGroupNode;
/**
 * \brief mvGroupBehaviourGroupNode const pointer type
 */
typedef class mvGroupBNode_V2 const * const mvConstGroupBehaviourGroupNodePtr;
/**
 * \brief mvGroupNodeMemberList object type
 */
typedef class mvGroupNodeMemberList* mvGroupNodeMemberListPtr;
/**
 * \brief mvGroupBehaviour const pointer type
 */
typedef class mvGroupBehaviour const * const mvConstGroupBehaviourPtr;
/**
 * \brief mvGroupMemberNode pointer type
 */
typedef class mvGroupMemberNode* mvGroupMemberNodePtr;
/**
 * \brief mvGroupMemberNode const pointer type
 */
typedef class mvGroupMemberNode const * const mvConstGroupMemberNodePtr;

#define MV_GROUP_BEHAVIOUR_RESULT_HEADER_FILE_H_ <mv/mvGroupBehaviourResult.h>
/**
 * \brief mvGroupBehaviourResult pointer type
 */
typedef class mvGroupBehaviourResult* mvGroupBehaviourResultPtr;

#define MV_OBSTACLE_HEADER_FILE_H_ <mv/mvObstacle_V2.h>
//typedef class mvObstacle_V2 mvObstacle;
/**
 * \brief mvObstacle pointer type
 */
typedef class mvObstacle* mvObstaclePtr;
/**
 * \brief mvObstacle const pointer type
 */
typedef class mvObstacle const * const mvConstObstaclePtr;

#define MV_PATHWAY_HEADER_FILE_H_ <mv/mvPathway_V2.h>
//typedef class mvPathway_V2 mvPathway;
/**
 * \brief mvPathway pointer type
 */
typedef class mvPathway* mvPathwayPtr;
/**
 * \brief mvPathway const pointer type
 */
typedef class mvPathway const * const mvConstPathwayPtr;

#define MV_WAYPOINT_HEADER_FILE_H_ <mv/mvWaypoint_V2.h>
//typedef class mvWaypoint mvWaypoint;
/**
 * \brief mvWaypoint pointer type
 */
typedef class mvWaypoint* mvWaypointPtr;
/**
 * \brief mvWaypoint const pointer type
 */
typedef class mvWaypoint const * const mvConstWaypointPtr;

#define MV_WORLD_HEADER_FILE_H_ <mv/mvWorld2.h>
//typedef class mvWorld mvWorld;
/**
 * \brief mvWorld pointer type
 */
typedef class mvWorld* mvWorldPtr;
/**
 * \brief mvWorld const pointer type
 */
typedef class mvWorld const * const mvConstWorldPtr;

#define MV_TIMER_HEADER_FILE_H_ <mv/mvBEntryTimer.h>
/**
 * \brief mvTiner pointer type
 */
typedef class mvTimer* mvTimerPtr;

#define MV_ENTRY_HEADER_FILE_H_ <mv/mvBEntry.h>
/**
 * \brief mvEntry object type
 */
typedef class mvBEntry mvEntry;
/**
 * \brief mvEntry pointer type
 */
typedef class mvBEntry* mvEntryPtr;

#define MV_ACTION_LOADER_LIST_HEADER_FILE_H_ <mv/mvActionLoaderList.h>
//typedef class mvActionLoaderList*  mvActionLoaderListPtr;
/**
 * \brief mvActionLoaderList pointer type
 */
#define mvActionLoaderListPtr mvActionLoaderList*

#define MV_FORCE_LOADER_LIST_HEADER_FILE_H_ <mv/mvForceLoaderList.h>
//typedef class mvActionLoaderList*  mvActionLoaderListPtr;
/**
 * \brief mvForceLoaderList pointer type
 */
#define mvForceLoaderListPtr mvForceLoaderList*

#define MV_VEC_3_HEADER_FILE_H_ <mvLFVec3.h>
#define MV_ENUMS_HEADER_FILE_H_ <mv/mvEnums.h>
#define MV_MOTIONAI_HEADER_FILE <mv/mvMotionAI.h>

#define MV_SHAPE_HEADER_FILE_H_ <mv/mvShape.h>
/**
 * \brief mvShape pointer type
 */
typedef class mvShape* mvShapePtr;
/**
 * \brief mvShape const pointer type
 */
typedef class mvShape const * const mvConstShapePtr;

#define MV_INDEX_SET_HEADER_FILE_H_ <mv/mvIndexSet.h>

#define MV_BEHAVIOUR_LIST_HEADER_FILE_H_ <mv/mvBEntryList.h>
//typedef class mvEntryList mvEntryList;
/**
 * \brief mvEntryList pointer type
 */
typedef class mvEntryList* mvEntryListPtr;
/**
 * \brief mvEntryList const pointer type
 */
typedef class mvEntryList const * const mvConstEntryListPtr;
#define MV_BEHAVIOUR_LIST_NODE_HEADER_FILE_H_ <mv/mvBEntryListNode.h>
/**
 * \brief mvEntryListNode object type
 */
typedef class mvBEntryListNode mvEntryListNode;
/**
 * \brief mvEntryListNode pointer type
 */
typedef class mvBEntryListNode* mvEntryListNodePtr;
/**
 * \brief mvEntryListNode const pointer type
 */
typedef class mvBEntryListNode const * const mvConstEntryListNodePtr;

#define MV_ROTATION_UNIT_HEADER_FILE_H_ <mvLFQuaternion.h>
typedef class mvLFQuaternion mvRotationUnit;

#define MV_POINTER_LIST_HEADER_FILE_H_ <mv/mvPointerList.h>
#define MV_CAPSULE_LIST_HEADER_FILE_H_ <mv/mvCapsuleList.h>
#define MV_BODY_CAPSULE_HEADER_FILE_H_ <mv/mvBodyCapsule.h>
#define MV_WAYPOINT_CAPSULE_HEADER_FILE_H_ <mv/mvWaypointCapsule.h>
#define MV_GROUP_CAPSULE_HEADER_FILE_H_ <mv/mvGroupCapsule.h>

#define MV_MOTIONAI_UTILITIES_HEADER_FILE_H_ <mv/mvMotionAI-Utilities.h>
#define MV_READY_MADE_ACTION_LOADER_HEADER_FILE_H_ <mv/mvReadyMadeLoader.h>
#define MV_STDLIB_HEADER_FILE_H_ <mv/mvStdLib.h>

typedef lf::core::quaternion mvQuaternion;
typedef lf::core::matrix4 mvMatrix4x4;

#endif
