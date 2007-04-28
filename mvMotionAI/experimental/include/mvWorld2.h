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

#include MV_BASE_BEHAVIOUR_HEADER_FILE_H_
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
//TODO : body capsule
//TODO : waypoint capsule

typedef class mvWorld_V2
{
   private:
      char* worldID;
      mvPointerList<mvForcePtr, mvConstForcePtr> forces;
      mvPointerList<mvObstaclePtr, mvConstObstaclePtr> obstacles;
      mvCapsuleList<mvBodyPtr, mvConstBodyPtr, mvBodyCapsulePtr,\
         mvConstBodyCapsulePtr> bodies;
      mvPointerList<mvWaypointCapsulePtr, mvConstWaypointCapsulePtr> waypoints;
      mvPointerList<mvPathwayPtr,mvConstPathwayPtr> pathways;
      mvPointerList<mvGroupBehaviourPtr, mvConstGroupBehaviourPtr>\
         groupBehaviours;
      mvPointerList<mvBehaviourPtr, mvConstBehaviourPtr> behaviours;
      mvPointerList<mvGroupPtr, mvConstGroupPtr> groups;
      mvBehavFuncListPtr behavLoader;

      /// world step functionality
      void prepareIntegrationStep();
      void calculateGroupBehaviours(); // 1
      void checkIfWaypointContainsBody(mvIndex waypointIndex,\
         mvIndex bodyIndex); // part of 2
      void calculateGlobalForceOnBody(mvIndex globalForce,mvIndex bodyIndex);
      void calculateLocalForceOnBody(mvIndex localForce, mvIndex bodyIndex);
      void calculateBehavioursOnBody(mvIndex bodyIndex);
      void finaliseIntegrationOfBody(mvIndex bodyIndex);

      mvConstBodyCapsulePtr getConstBodyCapsulePtr(int index) const;
      mvBodyCapsulePtr getBodyCapsulePtr(int index);

   public:
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

      mvErrorEnum setBodyParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBodyParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBodyParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentBodyParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBodyParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBodyParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBodyParametersv(const char* param,\
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

      mvErrorEnum getBodyParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBodyParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBodyParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBodyParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBodyParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentBodyParametersf(const char* param, mvFloat* num)\
         const;
      mvErrorEnum getCurrentBodyParametersv(const char* param,\
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

      mvErrorEnum setObstacleParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setObstacleParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setObstacleParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setObstacleParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentObstacleParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentObstacleParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentObstacleParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentObstacleParametersv(const char* param,\
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

      mvErrorEnum getObstacleParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getObstacleParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getObstacleParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getObstacleParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentObstacleParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentObstacleParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentObstacleParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentObstacleParametersv(const char* param,\
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

      mvErrorEnum setWaypointParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setWaypointParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setWaypointParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setWaypointParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentWaypointParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentWaypointParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentWaypointParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentWaypointParametersv(const char* param,\
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


      mvErrorEnum getWaypointParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getWaypointParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getWaypointParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getWaypointParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentWaypointParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentWaypointParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentWaypointParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentWaypointParametersv(const char* param,\
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

      mvErrorEnum setPathwayParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setPathwayParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setPathwayParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setPathwayParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentPathwayParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentPathwayParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentPathwayParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentPathwayParametersv(const char* param,\
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

      mvErrorEnum getPathwayParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getPathwayParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getPathwayParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getPathwayParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentPathwayParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentPathwayParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentPathwayParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentPathwayParametersv(const char* param,\
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

      mvErrorEnum setBehaviourParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBehaviourParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBehaviourParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBehaviourParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentBehaviourParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentBehaviourParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBehaviourParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBehaviourParametersv(const char* param,\
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

      mvErrorEnum getBehaviourParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBehaviourParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBehaviourParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBehaviourParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentBehaviourParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentBehaviourParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentBehaviourParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentBehaviourParametersv(const char* param,\
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

      mvErrorEnum setGroupParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setGroupParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setGroupParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentGroupParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentGroupParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentGroupParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentGroupParametersv(const char* param,\
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

      mvErrorEnum getGroupParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getGroupParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentGroupParametersf(const char* param, mvFloat* num)\
         const;
      mvErrorEnum getCurrentGroupParametersv(const char* param,\
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

      mvErrorEnum setGroupBehaviourParametersi(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourParameters(mvIndex index,\
         mvIndex groupIndex, const char* param, const char* option);
      mvErrorEnum setGroupBehaviourParametersf(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat num);
      mvErrorEnum setGroupBehaviourParametersv(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array);

      mvErrorEnum setCurrentGroupBehaviourParametersi(mvIndex groupIndex,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setCurrentGroupBehaviourParameters(mvIndex groupIndex,\
         const char* param, const char* option);
      mvErrorEnum setCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
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

      mvErrorEnum getGroupBehaviourParametersi(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourParameters(mvIndex index,\
         mvIndex groupIndex, const char* param, const char** option) const;
      mvErrorEnum getGroupBehaviourParametersf(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourParametersv(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getCurrentGroupBehaviourParametersi(mvIndex groupIndex,\
         const char* param, mvIndex* outIndex) const;
      mvErrorEnum getCurrentGroupBehaviourParameters(mvIndex groupIndex,\
         const char* param, const char** option) const;
      mvErrorEnum getCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
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

      mvErrorEnum setForceParametersi(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setForceParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setForceParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setForceParametersv(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum setCurrentForceParametersi(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentForceParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentForceParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentForceParametersv(const char* param,\
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

      mvErrorEnum getForceParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getForceParameters(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getForceParametersf(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getForceParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentForceParametersi(const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getCurrentForceParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentForceParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentForceParametersv(const char* param,\
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

      mvErrorEnum addBodyToGroup(mvIndex bodyIndex, mvIndex groupIndex);
      mvErrorEnum addCurrentBodyToGroup(mvIndex groupIndex);
      mvErrorEnum addBodyToCurrentGroup(mvIndex bodyIndex);
      mvErrorEnum addCurrentBodyToCurrentGroup();

      mvErrorEnum removeBodyFromGroup(mvIndex bodyIndex, mvIndex groupIndex);
      mvErrorEnum removeCurrentBodyFromGroup(mvIndex groupIndex);
      mvErrorEnum removeBodyFromCurrentGroup(mvIndex bodyIndex);
      mvErrorEnum removeCurrentBodyFromCurrentGroup();

      mvErrorEnum addWaypointToPathway(mvIndex wpIndex, mvIndex pIndex);
      mvErrorEnum addWaypointToCurrentPathway(mvIndex wpIndex);
      mvErrorEnum addCurrentWaypointToCurrentPathway();
      mvErrorEnum addCurrentWaypointToPathway(mvIndex pIndex);
      mvErrorEnum removeWaypointFromPathway(mvIndex wpIndex, mvIndex pIndex);
      mvErrorEnum removeWaypointFromCurrentPathway(mvIndex wpIndex);
      mvErrorEnum removeCurrentWaypointFromPathway(mvIndex pIndex);
      mvErrorEnum removeCurrentWaypointFromCurrentPathway();

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

      mvErrorEnum setMainGroupBehaviourParametersi(mvIndex index,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setMainGroupBehaviourParameters(mvIndex index,\
         const char* param, const char* option);
      mvErrorEnum setMainGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat num);
      mvErrorEnum setMainGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array);

      mvErrorEnum setCurrentMainGroupBehaviourParametersi(\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setCurrentMainGroupBehaviourParameters(\
         const char* param, const char* option);
      mvErrorEnum setCurrentMainGroupBehaviourParametersf(\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentMainGroupBehaviourParametersv(\
         const char* param, mvFloat* array);

      mvErrorEnum getMainGroupBehaviourParameters(mvIndex index,\
         const char* param, const char** option) const;
      mvErrorEnum getMainGroupBehaviourParametersi(mvIndex index,\
         const char* param, mvIndex* paramIndex) const;
      mvErrorEnum getMainGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getMainGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getCurrentMainGroupBehaviourParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentMainGroupBehaviourParametersi(const char* param,\
         mvIndex* paramIndex) const;
      mvErrorEnum getCurrentMainGroupBehaviourParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentMainGroupBehaviourParametersv(const char* param,\
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

      //TODO : new const object pointer loading
      mvConstBodyPtr getConstBodyPtr(mvIndex index) const;
      mvConstObstaclePtr getConstObstaclePtr(mvIndex index) const;
      mvConstWaypointPtr getConstWaypointPtr(mvIndex index) const;
      mvConstPathwayPtr getConstPathwayPtr(mvIndex index) const;
      mvConstGroupPtr getConstGroupPtr(mvIndex index) const;
      mvConstGroupBehaviourPtr getConstGroupBehaviourPtr(mvIndex index) const;
      mvConstBehaviourPtr getConstBehaviourPtr(mvIndex index) const;
      mvConstForcePtr getConstGroupForcePtr(mvIndex index) const;

      // TODO : patahway functions
} mvWorld;



#endif
