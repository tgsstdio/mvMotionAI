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
 */
#ifndef MV_MOTIONAI_WORLD_V2_H_
#define MV_MOTIONAI_WORLD_V2_H_
#include "mvList.h"

#include "mvForce.h"
#include "mvBody.h"
#include "mvObstacle.h"
#include "mvWaypoint.h"
#include "mvPathway.h"
#include "mvGroup.h"
#include "mvGroupBehaviour_V2.h"
#include "mvBehaviour_V2.h"

// TODO (White 2#1#): implement version two of world

typedef class mvWorld_V2
{
   private:
      char* worldID;
      mvItemList<mvForce> forces;
      mvItemList<mvObstacle> obstacles;
      mvItemList<mvBody> bodies;
      mvItemList<mvWaypoint> waypoints;
      mvItemList<mvPathway> pathways;
      mvItemList<mvGroupBehaviour_V2> groupBehaviours;
      mvItemList<mvBehaviour_V2> behaviours;
      mvItemList<mvGroup> groups;

   public:
      mvWorld_V2(const char* worldID);
      char* getID() const;
      ~mvWorld_V2();

      // TODO : world functions
      void worldStep(mvFloat timeInSecs);
      mvErrorEnum nudgeBody(mvIndex bodyIndex, mvFloat timeInSecs);
      mvErrorEnum nudgeCurrentBody(mvFloat timeInSecs);

      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements);

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);


      // body functions
      mvIndex createBody(mvOptionEnum bType, mvOptionEnum bShape,\
         mvFloat x, mvFloat y, mvFloat z);
      mvBody* getBodyPtr(mvIndex index);
      mvBody* getCurrentBodyPtr();
      mvIndex setCurrentBody(mvIndex index);
      mvErrorEnum deleteCurrentBody();
      mvErrorEnum deleteBody(mvIndex index);
      void deleteAllBodies();
      void applyToAllBodies(void (someFunction)(mvBody*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentBodyParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentBodyParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentBodyParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentBodyParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getBodyParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getBodyParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getBodyParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getBodyParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentBodyParametersi(const char* param, mvIndex* outIndex);
      mvErrorEnum getCurrentBodyParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentBodyParametersf(const char* param, mvFloat* num);
      mvErrorEnum getCurrentBodyParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // obstacle functions
      mvIndex createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
         mvFloat x, mvFloat y, mvFloat z);
      mvObstacle* getObstaclePtr(mvIndex index);
      mvObstacle* getCurrentObstaclePtr();
      mvIndex setCurrentObstacle(mvIndex index);
      mvErrorEnum deleteCurrentObstacle();
      mvErrorEnum deleteObstacle(mvIndex index);
      void deleteAllObstacles();
      void applyToAllObstacles(void (someFunction)(mvObstacle*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentObstacleParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentObstacleParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentObstacleParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentObstacleParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getObstacleParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getObstacleParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getObstacleParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getObstacleParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentObstacleParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentObstacleParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentObstacleParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentObstacleParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Waypoint functions
      mvIndex createWaypoint(mvOptionEnum wType, mvOptionEnum wShape,\
         mvFloat x, mvFloat y, mvFloat z);
      mvWaypoint* getWaypointPtr(mvIndex index);
      mvWaypoint* getCurrentWaypointPtr();
      mvIndex setCurrentWaypoint(mvIndex index);
      mvErrorEnum deleteCurrentWaypoint();
      mvErrorEnum deleteWaypoint(mvIndex index);
      void deleteAllWaypoints();
      void applyToAllWaypoints(void (someFunction)(mvWaypoint*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentWaypointParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentWaypointParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentWaypointParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentWaypointParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);


      mvErrorEnum getWaypointParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getWaypointParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getWaypointParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getWaypointParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentWaypointParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentWaypointParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentWaypointParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentWaypointParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Pathway functions
      mvIndex createPathway();
      mvPathway* getPathwayPtr(mvIndex index);
      mvPathway* getCurrentPathwayPtr();
      mvIndex setCurrentPathway(mvIndex index);
      mvErrorEnum deleteCurrentPathway();
      mvErrorEnum deletePathway(mvIndex index);
      void deleteAllPathways();
      void applyToAllPathways(void (someFunction)(mvPathway*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentPathwayParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentPathwayParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentPathwayParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentPathwayParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getPathwayParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getPathwayParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getPathwayParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getPathwayParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentPathwayParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentPathwayParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentPathwayParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentPathwayParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Behaviour functions
      mvIndex createBehaviour(mvOptionEnum bType);
      mvBehaviour_V2* getBehaviourPtr(mvIndex index);
      mvBehaviour_V2* getCurrentBehaviourPtr();
      mvIndex setCurrentBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentBehaviour();
      mvErrorEnum deleteBehaviour(mvIndex index);
      void deleteAllBehaviours();
      void applyToAllBehaviours(void (someFunction)(mvBehaviour_V2*, void*),\
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
         mvParamEnum paramFlag, mvIndex* outIndex);
      mvErrorEnum getBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentBehaviourParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getBehaviourParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getBehaviourParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getBehaviourParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getBehaviourParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentBehaviourParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentBehaviourParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentBehaviourParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentBehaviourParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Group functions
      mvIndex createGroup(const char* groupID);
      mvGroup* getGroupPtr(mvIndex index);
      mvGroup* getCurrentGroupPtr();
      mvIndex setCurrentGroup(mvIndex index);
      mvErrorEnum deleteCurrentGroup();
      mvErrorEnum deleteGroup(mvIndex index);
      void deleteAllGroups();
      void applyToAllGroups(void (someFunction)(mvGroup*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentGroupParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentGroupParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentGroupParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentGroupParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getGroupParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getGroupParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getGroupParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getGroupParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentGroupParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentGroupParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentGroupParametersf(const char* param, mvFloat* num);
      mvErrorEnum getCurrentGroupParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // GroupBehaviour functions
      mvIndex createGroupBehaviour(mvOptionEnum type);
      mvGroupBehaviour_V2* getGroupBehaviourPtr(mvIndex index);
      mvGroupBehaviour_V2* getCurrentGroupBehaviourPtr();
      mvIndex setCurrentGroupBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentGroupBehaviour();
      mvErrorEnum deleteGroupBehaviour(mvIndex index);
      void deleteAllGroupBehaviours();
      void applyToAllGroupBehaviours(\
         void (someFunction)(mvGroupBehaviour_V2*, void*), void* extraPtr);
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
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex);
      mvErrorEnum getGroupBehaviourParameter(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getGroupBehaviourParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getGroupBehaviourParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters);

      mvErrorEnum getCurrentGroupBehaviourParameteri(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvIndex* outIndex);
      mvErrorEnum getCurrentGroupBehaviourParameter(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getCurrentGroupBehaviourParameterf(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getCurrentGroupBehaviourParameterv(mvIndex groupIndex,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getGroupBehaviourParametersi(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex* outIndex);
      mvErrorEnum getGroupBehaviourParameters(mvIndex index,\
         mvIndex groupIndex, const char* param, const char** option);
      mvErrorEnum getGroupBehaviourParametersf(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* num);
      mvErrorEnum getGroupBehaviourParametersv(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters);

      mvErrorEnum getCurrentGroupBehaviourParametersi(mvIndex groupIndex,\
         const char* param, mvIndex* outIndex);
      mvErrorEnum getCurrentGroupBehaviourParameters(mvIndex groupIndex,\
         const char* param, const char** option);
      mvErrorEnum getCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
         const char* param, mvFloat* num);
      mvErrorEnum getCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
         const char* param, mvFloat* array, mvCount* noOfParameters);

      // Force functions
      mvIndex createForce(mvOptionEnum fType);
      mvForce* getForcePtr(mvIndex index);
      mvForce* getCurrentForcePtr();
      mvIndex setCurrentForce(mvIndex index);
      mvErrorEnum deleteCurrentForce();
      mvErrorEnum deleteForce(mvIndex index);
      void deleteAllForces();
      void applyToAllForces(void (someFunction)(mvForce*, void*),\
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
         mvIndex* outIndex);
      mvErrorEnum getForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentForceParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentForceParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentForceParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentForceParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getForceParametersi(mvIndex index, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getForceParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getForceParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getForceParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentForceParametersi(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentForceParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentForceParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentForceParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);
/*
//      mvErrorEnum setDefaultWaypointForBody(mvIndex waypointIndex,\
//         mvIndex bodyIndex);
//      mvErrorEnum setDefaultPathwayForBody(mvIndex pathwayIndex,\
//         mvIndex bodyIndex);
//      mvErrorEnum setDefaultBodyForBody(mvIndex targetIndex,\
//         mvIndex bodyIndex);
//      mvErrorEnum setDefaultWeightForBody(mvFloat factor,\
//         mvIndex bodyIndex);
//
//      mvErrorEnum setDefaultWaypointForCurrentBody(mvIndex wpIndex);
//      mvErrorEnum setDefaultPathwayForCurrentBody(mvIndex pwIndex);
//      mvErrorEnum setDefaultBodyForCurrentBody(mvIndex bodyIndex);
//      // weight for behaviour factor
//      mvErrorEnum setDefaultWeightForCurrentBody(mvFloat factor);
*/

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

      mvErrorEnum setCurrentMainGroupBehaviourParametersi(mvIndex index,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setCurrentMainGroupBehaviourParameters(mvIndex index,\
         const char* param, const char* option);
      mvErrorEnum setCurrentMainGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat num);
      mvErrorEnum setCurrentMainGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array);

      mvErrorEnum getMainGroupBehaviourParameters(mvIndex index,\
         const char* param, const char** option);
      mvErrorEnum getMainGroupBehaviourParametersi(mvIndex index,\
         const char* param, mvIndex* paramIndex);
      mvErrorEnum getMainGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat* num);
      mvErrorEnum getMainGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentMainGroupBehaviourParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentMainGroupBehaviourParametersi(const char* param,\
         mvIndex* paramIndex);
      mvErrorEnum getCurrentMainGroupBehaviourParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentMainGroupBehaviourParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getMainGroupBehaviourParameter(mvIndex index,\
         mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum getMainGroupBehaviourParameteri(mvIndex index,\
         mvParamEnum param, mvIndex* paramIndex);
      mvErrorEnum getMainGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum param, mvFloat* num);
      mvErrorEnum getMainGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentMainGroupBehaviourParameter(mvParamEnum param,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentMainGroupBehaviourParameteri(mvParamEnum param,\
         mvIndex* paramIndex);
      mvErrorEnum getCurrentMainGroupBehaviourParameterf(mvParamEnum param,\
         mvFloat* num);
      mvErrorEnum getCurrentMainGroupBehaviourParameterv(mvParamEnum param,\
         mvFloat* array, mvCount* noOfParameters);

      mvIndex getCurrentBody();
      mvIndex getCurrentObstacle();
      mvIndex getCurrentWaypoint();
      mvIndex getCurrentForce();
      mvIndex getCurrentGroup();
      mvIndex getCurrentBehaviour();
      mvIndex getCurrentGroupBehaviour();
      mvIndex getCurrentPathway();

      // TODO : patahway functions
} mvWorld;



#endif
