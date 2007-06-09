#ifndef MV_MOTIONAI_WORLD_V2_H_
#define MV_MOTIONAI_WORLD_V2_H_

#include "mvMotionAI-Types.h"

#ifdef MV_FILE_HEADER_TAG_
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
 *
 *  implementation of version two of mvMotionAI world
 */
#endif

#include "mvPointerList.h"
#include "mvCapsuleList.h"

#include "mvBodyCapsule.h"
#include "mvWaypointCapsule.h"
#include "mvForceCapsule.h"
#include "mvGroupCapsule.h"

#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_FORCE_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_OBSTACLE_HEADER_FILE_H_
#include MV_WAYPOINT_HEADER_FILE_H_
#include MV_PATHWAY_HEADER_FILE_H_
#include MV_GROUP_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_HEADER_FILE_H_
#include MV_BEHAVIOUR_HEADER_FILE_H_
#include MV_BEHAV_FUNC_LIST_HEADER_FILE_H_

//TODO : new group behaviour functions

class mvWorld_V2
{
   private:
      char* worldID;
      mvCapsuleList<mvForcePtr, mvConstForcePtr,\
         mvForceCapsulePtr, mvConstForceCapsulePtr> forces;
      mvPointerList<mvObstaclePtr, mvConstObstaclePtr> obstacles;
      mvCapsuleList<mvBodyPtr, mvConstBodyPtr, mvBodyCapsulePtr,\
         mvConstBodyCapsulePtr> bodies;
      mvCapsuleList<mvWaypointPtr, mvConstWaypointPtr, mvWaypointCapsulePtr,\
         mvConstWaypointCapsulePtr> waypoints;
      mvPointerList<mvPathwayPtr,mvConstPathwayPtr> pathways;
      mvPointerList<mvGroupBehaviourPtr, mvConstGroupBehaviourPtr>\
         groupBehaviours;
      mvPointerList<mvBehaviourPtr, mvConstBehaviourPtr> behaviours;
      mvCapsuleList<mvGroupPtr, mvConstGroupPtr, mvGroupCapsulePtr,\
         mvConstGroupCapsulePtr> groups;
      mvBehavFuncListPtr behavLoader;

      /// world step functionality
      void prepareIntegrationStep();
      void performIntegrationOfBody(mvBodyCapsulePtr bodyPtr,mvFloat timeInSecs);
      void calculateGroupBehaviours(); // 1
      void checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr);
      void resetIntegrationLoop();
      void calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr);
      void calculateGlobalForceOnBody(mvIndex globalForce,
         mvBodyCapsulePtr bodyPtr);
      void calculateLocalForceOnBody(mvIndex localForce,
         mvBodyCapsulePtr bodyPtr);
      void calculateBehavioursOnBody(mvBodyCapsulePtr bodyPtr);
      void finaliseIntegrationStep();

      mvConstBodyCapsulePtr getConstBodyCapsulePtr(int index) const;
      mvBodyCapsulePtr getBodyCapsulePtr(int index);

   public:
      void integrateBody(mvBodyCapsulePtr bodyPtr, mvFloat timeInSecs);

      bool isEnabled;
      bool applyForces;
      bool applyGravity;
      bool applyShifts;
      bool applyAccelerations;
      bool applyCollisions;
      bool applyAllForces;
      bool autoConvertIndex;
      bool isRightHanded;

      mvWorld_V2(const char* worldID);
      char* getID() const;
      ~mvWorld_V2();


      void setBehaviourLoader(mvBehavFuncListPtr bLoaderPtr);
      mvBehavFuncListPtr getBehaviourLoader() const;

      // TODO : world functions
      void worldStep(mvFloat timeInSecs);
      mvErrorEnum nudgeBody(mvIndex bodyIndex, mvFloat timeInSecs);
      mvErrorEnum nudgeCurrentBody(mvFloat timeInSecs);

      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfElements) const;

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      // body functions
      mvIndex createBody(mvOptionEnum bType, mvOptionEnum bShape,\
         mvFloat x, mvFloat y, mvFloat z);
      mvBodyPtr getBodyPtr(mvIndex index);
      mvBodyPtr getCurrentBodyPtr();
      mvIndex setCurrentBody(mvIndex index);
      mvErrorEnum deleteCurrentBody();
      mvErrorEnum deleteBody(mvIndex index);
      void deleteAllBodies();
      void applyToAllBodies(void (someFunction)(mvBodyPtr, void*),\
         void* extraPtr);
      void applyToAllBodiesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentBodyParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBodyParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentBodyParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentBodyParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentBodyParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBodyParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBodyParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBodyParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBodyParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBodyParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentBodyParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentBodyParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBodyParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBodyParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentBodyParameterf_str(const char* param, mvFloat* num)\
         const;
      mvErrorEnum getCurrentBodyParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // obstacle functions
      mvIndex createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
         mvFloat x, mvFloat y, mvFloat z);
      mvObstaclePtr getObstaclePtr(mvIndex index);
      mvObstaclePtr getCurrentObstaclePtr();
      mvIndex setCurrentObstacle(mvIndex index);
      mvErrorEnum deleteCurrentObstacle();
      mvErrorEnum deleteObstacle(mvIndex index);
      void deleteAllObstacles();
      void applyToAllObstacles(void (someFunction)(mvObstaclePtr, void*),\
         void* extraPtr);
      void applyToAllObstaclesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);


      mvErrorEnum setObstacleParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentObstacleParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentObstacleParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentObstacleParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentObstacleParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setObstacleParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setObstacleParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setObstacleParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setObstacleParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentObstacleParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentObstacleParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentObstacleParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentObstacleParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getObstacleParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentObstacleParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentObstacleParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentObstacleParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentObstacleParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getObstacleParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getObstacleParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getObstacleParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getObstacleParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentObstacleParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentObstacleParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentObstacleParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentObstacleParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Waypoint functions
      mvIndex createWaypoint(mvOptionEnum wShape,mvFloat x,\
         mvFloat y, mvFloat z);
      mvWaypointPtr getWaypointPtr(mvIndex index);
      mvWaypointPtr getCurrentWaypointPtr();
      mvIndex setCurrentWaypoint(mvIndex index);
      mvErrorEnum deleteCurrentWaypoint();
      mvErrorEnum deleteWaypoint(mvIndex index);
      void deleteAllWaypoints();
      void applyToAllWaypoints(void (someFunction)(mvWaypointPtr, void*),\
         void* extraPtr);
      void applyToAllWaypointsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setWaypointParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentWaypointParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentWaypointParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentWaypointParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentWaypointParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setWaypointParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setWaypointParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setWaypointParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setWaypointParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentWaypointParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentWaypointParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentWaypointParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentWaypointParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getWaypointParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentWaypointParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentWaypointParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentWaypointParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentWaypointParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;


      mvErrorEnum getWaypointParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getWaypointParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getWaypointParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getWaypointParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentWaypointParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentWaypointParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentWaypointParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentWaypointParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Pathway functions
      mvIndex createPathway();
      mvPathwayPtr getPathwayPtr(mvIndex index);
      mvPathwayPtr getCurrentPathwayPtr();
      mvIndex setCurrentPathway(mvIndex index);
      mvErrorEnum deleteCurrentPathway();
      mvErrorEnum deletePathway(mvIndex index);
      void deleteAllPathways();
      void applyToAllPathways(void (someFunction)(mvPathwayPtr, void*),\
         void* extraPtr);
      void applyToAllPathwaysByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setPathwayParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentPathwayParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentPathwayParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentPathwayParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentPathwayParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setPathwayParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setPathwayParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setPathwayParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setPathwayParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentPathwayParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentPathwayParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentPathwayParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentPathwayParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getPathwayParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentPathwayParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentPathwayParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentPathwayParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentPathwayParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getPathwayParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getPathwayParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getPathwayParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getPathwayParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentPathwayParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentPathwayParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentPathwayParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentPathwayParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Behaviour functions
      mvIndex createBehaviour(mvOptionEnum bType);
      mvBehaviourPtr getBehaviourPtr(mvIndex index);
      mvBehaviourPtr getCurrentBehaviourPtr();
      mvIndex setCurrentBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentBehaviour();
      mvErrorEnum deleteBehaviour(mvIndex index);
      void deleteAllBehaviours();
      void applyToAllBehaviours(void (someFunction)(mvBehaviourPtr, void*),\
         void* extraPtr);
      void applyToAllBehavioursByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setBehaviourParameteri(mvIndex index,\
         mvParamEnum paramFlag, mvIndex paramIndex);
      mvErrorEnum setBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setCurrentBehaviourParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setBehaviourParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBehaviourParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBehaviourParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBehaviourParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentBehaviourParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBehaviourParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBehaviourParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBehaviourParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getBehaviourParameteri(mvIndex index,\
         mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBehaviourParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getBehaviourParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBehaviourParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBehaviourParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBehaviourParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBehaviourParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBehaviourParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentBehaviourParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentBehaviourParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Group functions
      mvIndex createGroup(const char* groupID);
      mvGroupPtr getGroupPtr(mvIndex index);
      mvGroupPtr getCurrentGroupPtr();
      mvIndex setCurrentGroup(mvIndex index);
      mvErrorEnum deleteCurrentGroup();
      mvErrorEnum deleteGroup(mvIndex index);
      void deleteAllGroups();
      void applyToAllGroups(void (someFunction)(mvGroupPtr, void*),\
         void* extraPtr);
      void applyToAllGroupsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setGroupParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentGroupParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentGroupParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentGroupParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentGroupParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setGroupParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setGroupParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setGroupParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentGroupParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentGroupParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentGroupParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentGroupParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getGroupParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentGroupParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentGroupParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getGroupParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getGroupParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentGroupParameterf_str(const char* param, mvFloat* num)\
         const;
      mvErrorEnum getCurrentGroupParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // GroupBehaviour functions
      mvIndex createGroupBehaviour(mvOptionEnum type);
      mvGroupBehaviourPtr getGroupBehaviourPtr(mvIndex index);
      mvGroupBehaviourPtr getCurrentGroupBehaviourPtr();
      mvIndex setCurrentGroupBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentGroupBehaviour();
      mvErrorEnum deleteGroupBehaviour(mvIndex index);
      void deleteAllGroupBehaviours();
      void applyToAllGroupBehaviours(\
         void (someFunction)(mvGroupBehaviourPtr, void*), void* extraPtr);
      void applyToAllGroupBehavioursByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setGroupBehaviourParameteri(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourParameter(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setGroupBehaviourParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setGroupBehaviourParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setCurrentGroupBehaviourParameteri(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvIndex paramIndex);
      mvErrorEnum setCurrentGroupBehaviourParameter(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentGroupBehaviourParameterf(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setCurrentGroupBehaviourParameterv(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setGroupBehaviourParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourParameter_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char* option);
      mvErrorEnum setGroupBehaviourParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat num);
      mvErrorEnum setGroupBehaviourParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array);

      mvErrorEnum setCurrentGroupBehaviourParameteri_str(mvIndex groupIndex,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setCurrentGroupBehaviourParameter_str(mvIndex groupIndex,\
         const char* param, const char* option);
      mvErrorEnum setCurrentGroupBehaviourParameterf_str(mvIndex groupIndex,\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentGroupBehaviourParameterv_str(mvIndex groupIndex,\
         const char* param, mvFloat* array);

      mvErrorEnum getGroupBehaviourParameteri(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourParameter(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getGroupBehaviourParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupBehaviourParameteri(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupBehaviourParameter(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getCurrentGroupBehaviourParameterf(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getCurrentGroupBehaviourParameterv(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getGroupBehaviourParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourParameter_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char** option) const;
      mvErrorEnum getGroupBehaviourParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupBehaviourParameteri_str(mvIndex groupIndex,\
         const char* param, mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupBehaviourParameter_str(mvIndex groupIndex,\
         const char* param, const char** option) const;
      mvErrorEnum getCurrentGroupBehaviourParameterf_str(mvIndex groupIndex,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getCurrentGroupBehaviourParameterv_str(mvIndex groupIndex,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;

      // Force functions
      mvIndex createForce(mvOptionEnum fType);
      mvForcePtr getForcePtr(mvIndex index);
      mvForcePtr getCurrentForcePtr();
      mvIndex setCurrentForce(mvIndex index);
      mvErrorEnum deleteCurrentForce();
      mvErrorEnum deleteForce(mvIndex index);
      void deleteAllForces();
      void applyToAllForces(void (someFunction)(mvForcePtr, void*),\
         void* extraPtr);
      void applyToAllForcesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setForceParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setCurrentForceParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentForceParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentForceParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentForceParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setForceParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setForceParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setForceParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setForceParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentForceParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentForceParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentForceParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentForceParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getForceParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentForceParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentForceParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentForceParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentForceParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getForceParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getForceParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getForceParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getForceParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentForceParameteri_str(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentForceParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentForceParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentForceParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum addBehaviourToBody(mvIndex bodyIndex, mvOptionEnum bType,\
         mvIndex behaviourIndex, mvIndex groupIndex);
      mvErrorEnum addBehaviourToCurrentBody(mvOptionEnum bType,\
         mvIndex behaviourIndex, mvIndex groupIndex);

      mvErrorEnum addGroupIntoGroupBehaviour(mvIndex groupIndex,\
         mvIndex groupBehaviour);
      mvErrorEnum addCurrentGroupIntoGroupBehaviour(mvIndex groupBehaviour);
      mvErrorEnum addGroupIntoCurrentGroupBehaviour(mvIndex groupIndex);
      mvErrorEnum addCurrentGroupIntoCurrentGroupBehaviour();

      mvErrorEnum removeGroupFromGroupBehaviour(mvIndex groupIndex,\
         mvIndex groupBehaviour);
      mvErrorEnum removeCurrentGroupFromGroupBehaviour(mvIndex groupBehaviour);
      mvErrorEnum removeGroupFromCurrentGroupBehaviour(mvIndex groupIndex);
      mvErrorEnum removeCurrentGroupFromCurrentGroupBehaviour();

      mvErrorEnum addMemberToGroup(mvIndex memberIndex, mvIndex groupIndex);
      mvErrorEnum addMemberToCurrentGroup(mvIndex memberIndex);

      mvErrorEnum removeMemberFromGroup(mvIndex memberIndex, mvIndex groupIndex);
      mvErrorEnum removeMemberFromCurrentGroup(mvIndex bodyIndex);

      mvErrorEnum findMemberFromGroup(mvIndex memberIndex, mvIndex groupIndex)
         const;
      mvErrorEnum findMemberFromCurrentGroup(mvIndex memberIndex) const;

      mvErrorEnum setMainGroupBehaviourParameter(mvIndex index,\
         mvParamEnum param, mvOptionEnum option);
      mvErrorEnum setMainGroupBehaviourParameteri(mvIndex index,\
         mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum setMainGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum param, mvFloat num);
      mvErrorEnum setMainGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum param, mvFloat* array);

      mvErrorEnum setCurrentMainGroupBehaviourParameter(mvParamEnum param,\
         mvOptionEnum option);
      mvErrorEnum setCurrentMainGroupBehaviourParameteri(mvParamEnum param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentMainGroupBehaviourParameterf(mvParamEnum param,\
         mvFloat num);
      mvErrorEnum setCurrentMainGroupBehaviourParameterv(mvParamEnum param,\
         mvFloat* array);

      mvErrorEnum setMainGroupBehaviourParameteri_str(mvIndex index,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setMainGroupBehaviourParameter_str(mvIndex index,\
         const char* param, const char* option);
      mvErrorEnum setMainGroupBehaviourParameterf_str(mvIndex index,\
         const char* param, mvFloat num);
      mvErrorEnum setMainGroupBehaviourParameterv_str(mvIndex index,\
         const char* param, mvFloat* array);

      mvErrorEnum setCurrentMainGroupBehaviourParameteri_str(\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setCurrentMainGroupBehaviourParameter_str(\
         const char* param, const char* option);
      mvErrorEnum setCurrentMainGroupBehaviourParameterf_str(\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentMainGroupBehaviourParameterv_str(\
         const char* param, mvFloat* array);

      mvErrorEnum getMainGroupBehaviourParameter_str(mvIndex index,\
         const char* param, const char** option) const;
      mvErrorEnum getMainGroupBehaviourParameteri_str(mvIndex index,\
         const char* param, mvIndex* paramIndex) const;
      mvErrorEnum getMainGroupBehaviourParameterf_str(mvIndex index,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getMainGroupBehaviourParameterv_str(mvIndex index,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentMainGroupBehaviourParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameteri_str(const char* param,\
         mvIndex* paramIndex) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getMainGroupBehaviourParameter(mvIndex index,\
         mvParamEnum param, mvOptionEnum* option) const;
      mvErrorEnum getMainGroupBehaviourParameteri(mvIndex index,\
         mvParamEnum param, mvIndex* paramIndex) const;
      mvErrorEnum getMainGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum param, mvFloat* num) const;
      mvErrorEnum getMainGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum param, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentMainGroupBehaviourParameter(mvParamEnum param,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameteri(mvParamEnum param,\
         mvIndex* paramIndex) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameterf(mvParamEnum param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentMainGroupBehaviourParameterv(mvParamEnum param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvIndex getCurrentBody() const;
      mvIndex getCurrentObstacle() const;
      mvIndex getCurrentWaypoint() const;
      mvIndex getCurrentForce() const;
      mvIndex getCurrentGroup() const;
      mvIndex getCurrentBehaviour() const;
      mvIndex getCurrentGroupBehaviour() const;
      mvIndex getCurrentPathway() const;

      mvConstBodyPtr getConstBodyPtr(mvIndex index) const;
      mvConstObstaclePtr getConstObstaclePtr(mvIndex index) const;
      mvConstWaypointPtr getConstWaypointPtr(mvIndex index) const;
      mvConstPathwayPtr getConstPathwayPtr(mvIndex index) const;
      mvConstGroupPtr getConstGroupPtr(mvIndex index) const;
      mvConstGroupBehaviourPtr getConstGroupBehaviourPtr(mvIndex index) const;
      mvConstBehaviourPtr getConstBehaviourPtr(mvIndex index) const;
      mvConstForcePtr getConstGroupForcePtr(mvIndex index) const;

      mvIndex addNodeToPathway(mvIndex nIndex, mvIndex pIndex);
      mvIndex addNodeToCurrentPathway(mvIndex wpIndex);
      mvErrorEnum removeNodeFromPathway(mvIndex wpIndex, mvIndex pIndex);
      mvErrorEnum removeNodeFromCurrentPathway(mvIndex wpIndex);

      mvIndex addCurrentWaypointToCurrentPathway();
      mvIndex addCurrentWaypointToPathway(mvIndex pIndex);
      mvErrorEnum removeCurrentWaypointFromPathway(mvIndex pIndex);
      mvErrorEnum removeCurrentWaypointFromCurrentPathway();

      mvErrorEnum removeAllNodesFromPathway(mvIndex pwIndex);
      mvErrorEnum removeAllNodesFromCurrentPathway();

      mvIndex getCurrentNodeOfPathway(mvIndex pwIndex);
      mvIndex getCurrentNodeOfCurrentPathway();

      mvIndex removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex);
      mvIndex removeCurrentPathwayNodeAt(mvIndex nodeIndex);

      // TODO implement to pathway node functions
      mvErrorEnum setPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setPathwayNodeParameter(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setCurrentPathwayNodeParameteri(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setCurrentPathwayNodeParameter(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentPathwayNodeParameterf(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setCurrentPathwayNodeParameterv(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex index);
      mvErrorEnum setPathwayNodeParameter_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char* option);
      mvErrorEnum setPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array);

      mvErrorEnum setCurrentPathwayNodeParameteri_str(mvIndex nodeIndex,\
         const char* param, mvIndex index);
      mvErrorEnum setCurrentPathwayNodeParameter_str(mvIndex nodeIndex,\
         const char* param, const char* option);
      mvErrorEnum setCurrentPathwayNodeParameterf_str(mvIndex nodeIndex,\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentPathwayNodeParameterv_str(mvIndex nodeIndex,\
         const char* param, mvFloat* array);

      mvErrorEnum getPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParameter(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getCurrentPathwayNodeParameteri(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getCurrentPathwayNodeParameter(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getCurrentPathwayNodeParameterf(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getCurrentPathwayNodeParameterv(mvIndex nodeIndex,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParameter_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char** option) const;
      mvErrorEnum getPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getCurrentPathwayNodeParameteri_str(mvIndex nodeIndex,\
         const char* param, mvIndex* outIndex) const;
      mvErrorEnum getCurrentPathwayNodeParameter_str(mvIndex nodeIndex,\
         const char* param, const char** option) const;
      mvErrorEnum getCurrentPathwayNodeParameterf_str(mvIndex nodeIndex,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getCurrentPathwayNodeParameterv_str(mvIndex nodeIndex,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;
};



#endif
