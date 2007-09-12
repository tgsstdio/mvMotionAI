#ifndef MVWORLD2_FUNCTIONS_H_INCLUDED
#define MVWORLD2_FUNCTIONS_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_INDEX_SET_HEADER_FILE_H_
#include MV_WORLD_HEADER_FILE_H_
#include MV_FORCE_RESULT_HEADER_FILE_H_
#include MV_BEHAVIOUR_RESULT_HEADER_FILE_H_
#include MV_BODY_CAPSULE_HEADER_FILE_H_
#include MV_WAYPOINT_CAPSULE_HEADER_FILE_H_
#include MV_GROUP_CAPSULE_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

struct mvWorld_V2_IntegrateLoopHelper
{
   public:
      mvWorldPtr currentWorld;
      mvFloat timeInSecs;
};

void mvWorld_V2_IntegrateAllBodies(mvBodyCapsulePtr bodyPtr, void* extraPtr);

class mvWorld_V2_CalcForceHelperStruct
{
   public:
      mvWorld_V2_CalcForceHelperStruct(mvUniqueSet& insideWPList);
      mvUniqueSet& waypointList;
      mvWorldPtr currentWorld;
      mvBodyCapsulePtr currentBody;
      mvForceResultPtr finalResult;
};

void mvWorld_V2_InitialCurrentForceResult(mvForceResultPtr finalResult,
   mvForceResultPtr currentResult);

bool mvWorld_V2_CalculateGlobalForceOnBody(mvBaseForcePtr currentForce,
   mvForceResultPtr currentResult);

bool mvWorld_V2_CalculateLocalForceOnBody(mvForceCapsulePtr fCapsulePtr,
   mvBaseForcePtr currentForce, mvForceResultPtr currentResult,\
   mvUniqueSet& waypointList);

void mvWorld_V2_CalculateForceOnSingleBody(mvForceCapsulePtr fCapsulePtr,\
   void* extraPtr);

void mvWorld_V2_ResetWaypointCapsule(mvWaypointCapsulePtr capsulePtr,\
   void* extraPtr);

void mvWorld_V2_PrepareBodyCapsule(mvBodyCapsulePtr capsulePtr, void* extraPtr);

void mvWorld_V2_PrepareForceCapsule(mvForceCapsulePtr capsulePtr,\
   void* extraPtr);

struct mvWorld_V2_GroupBehaviourNodeHelper
{
   public:
      mvWorldPtr currentWorld;
      mvOptionEnum gbType;
      mvIndex gbIndex;
      bool isEnabled;
};

void mvWorld_V2_CalculateEachGroupInGroupBehaviour(mvGroupBehaviourNodePtr currentNode,
   void* extraPtr);

void mvWorld_V2_CalculateForEachGroupBehaviour(\
   mvIndex groupBehaviourIndex, void* extraPtr);

struct mvWorld_V2_CalcBehavOnListHelper
{
   public:
      mvBehaviourResultPtr finalResult;
      mvBodyCapsulePtr bCapsule;
};

mvBaseActionPtr mvWorld_V2_InitialiseResults(mvBEntryPtr nodeInfo, mvIndex bodyIndex,
   mvConstWorldPtr currentWorld,  mvBehaviourResult& currentResult,\
   mvBehaviourResultPtr finalResult);

void mvWorld_V2_ConfineMotionVector(mvParamEnum mType, mvOptionEnum domain,
   mvVec3& motionVector);

void mvWorld_V2_SumBehaviourResults(mvBehaviourResultPtr summedResult,
   const mvBehaviourResult& actionResult, mvFloat weight, bool isConfined);

void mvWorld_V2_SumForceResults(mvForceResultPtr summedResult,
   const mvForceResult& actionResult);

void mvWorld_V2_CalculateEntryByWeightedSum(mvEntryListNodePtr eNodePtr,\
   void* extraPtr);

void mvWorld_V2_CalculateIntegrationOfBody(mvBodyCapsulePtr capsulePtr,
   void *extraPtr);

void mvWorld_V2_FinaliseGroups(mvGroupCapsulePtr capsulePtr, void* extraPtr);

void mvWorld_V2_InitialiseCurrentBehavResult(mvBehaviourResultPtr finalResult,\
   mvBehaviourResultPtr currentResult);

class mvWorld_V2_LocalForceCalculationHelper
{
   public:
      mvWorld_V2_LocalForceCalculationHelper(mvUniqueSet& wList);

      mvBodyCapsulePtr bCapsule;
      mvUniqueSet& waypointList;
      mvVec3 shapePos;
      mvOptionEnum bodyShape;
      bool calcDimensions[MV_VEC3_NO_OF_COMPONENTS];
      mvFloat aabbMinValues[MV_VEC3_NO_OF_COMPONENTS];
      mvFloat aabbMaxValues[MV_VEC3_NO_OF_COMPONENTS];
      mvFloat bodyRadiusSq;
      mvFloat bodyRadius;
      mvIndex bodyOddAxisIndex;
};

void mvWorldV2_CheckWaypointLocality(mvWaypointCapsulePtr fCapsulePtr,\
   void* extraPtr);

void mvWorldV2_RemoveAWaypointFromAllForceCapsules(\
   mvForceCapsulePtr fCapsulePtr, void* extraPtr);

bool mvWorldV2_InitialiseInsideWaypointHelperStruct(\
   mvWorld_V2_LocalForceCalculationHelper& helper, mvConstShapePtr shapePtr,
   const mvVec3& currentPosition);

bool mvAABBtoAABB_Collision(mvWorld_V2_LocalForceCalculationHelper* firstBox,
   mvWorld_V2_LocalForceCalculationHelper* secondBox, mvIndex componentIndex);

bool mvSpheretoSphere_Colision(const mvVec3& firstShapePos,
   const mvVec3& secondShapePos, mvFloat firstRadiusSq, mvFloat secondRadiusSq);

mvFloat mvWorldV2_SpheretoAABB_GetCollisionDistFromPoint(mvFloat firstBoxPosComponent,
   mvWorld_V2_LocalForceCalculationHelper* secondBox, mvIndex componentIndex);

#endif // MVWORLD2_FUNCTIONS_H_INCLUDED
