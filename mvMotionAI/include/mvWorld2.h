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

#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_OBSTACLE_HEADER_FILE_H_
#include MV_WAYPOINT_HEADER_FILE_H_
#include MV_PATHWAY_HEADER_FILE_H_
#include MV_GROUP_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_HEADER_FILE_H_
#include MV_BEHAVIOUR_HEADER_FILE_H_
#include MV_ACTION_LOADER_LIST_HEADER_FILE_H_
#include MV_FORCE_LOADER_LIST_HEADER_FILE_H_

#include "mvPointerList.h"
#include "mvCapsuleList.h"

#include "mvBodyCapsule.h"
#include "mvWaypointCapsule.h"
#include "mvGroupCapsule.h"
#include MV_FORCE_CAPSULE_HEADER_FILE
#include MV_BEHAVIOUR_LIST_HEADER_FILE_H_

// DLL library function
#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

class MV_GLOBAL_FUNC_PREFIX mvWorld_V2
{
   private:
      mvPointerList<mvEntryListPtr, mvConstEntryListPtr> entryLists;
      //char* worldID;
      mvCapsuleList<mvBaseForcePtr, mvConstBaseForcePtr,\
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
      mvActionLoaderListPtr behavLoader;

      /// world step functionality
      void prepareIntegrationStep();
      void setFinalBodyCapsuleVariables(mvBodyCapsulePtr bodyPtr,
         mvBehaviourResultPtr behavResModule,
         mvForceResultPtr forceResModule);
      void calculateGroupBehaviours(); // 1
      void checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr);
      void resetIntegrationLoop();
      void calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr,\
         mvForceResultPtr finalForceResult);
      void calculateBehavioursOnBody(mvBodyCapsulePtr bodyPtr,
         mvBehaviourResultPtr finalResult);
      void finaliseIntegrationStep(mvFloat timeInSecs);
      void initialiseCommonVariables(mvBehaviourResultPtr behavResult,
         mvForceResultPtr forceResult, mvFloat hTimeStep);

      mvConstBodyCapsulePtr getConstBodyCapsulePtr(int index) const;
      mvBodyCapsulePtr getBodyCapsulePtr(int index);

      mvFloat elapsedWorldTime;
      mvForceLoaderListPtr forceLoader;
      void* wUserData;

   public:
      mvFloat getElapsedWorldTime() const;
      void integrateBody(mvBodyCapsulePtr bodyPtr, mvFloat timeInSecs);
      bool hasGroupChanged(mvIndex groupNo);
      /** \brief
       * internal function - info is useless out of integration loop
       */
      bool doesWaypointContainBody(mvIndex wPointIndex) const;

      bool isEnabled;
      bool applyForces;
      bool applyGravity;
      bool applyShifts;
      bool applyAccelerations;
      bool applyCollisions;
      bool applyAllForces;
      bool applyAllDragForces;
      bool autoConvertIndex;
      bool isRightHanded;

      mvWorld_V2();
      ~mvWorld_V2();
      void setWorldUserData(void* tempData);
      void* getWorldUserData() const;

      void setActionLoader(mvActionLoaderListPtr bLoaderPtr);
      mvActionLoaderListPtr getActionLoader() const;

      void setForceLoader(mvForceLoaderListPtr fLoaderPtr);
      mvForceLoaderListPtr getForceLoaderPtr() const;

      // TODO : world functions
      mvErrorEnum worldStep(mvFloat timeInSecs);
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

      mvErrorEnum setBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBodyParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getBodyParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBodyParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBodyParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBodyParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // obstacle functions
      mvIndex createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
         mvFloat x, mvFloat y, mvFloat z);
      mvObstaclePtr getObstaclePtr(mvIndex index);
      mvObstaclePtr getCurrentObstaclePtr();
      mvIndex setCurrentObstacle(mvIndex index);
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

      mvErrorEnum setObstacleParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setObstacleParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setObstacleParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setObstacleParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getObstacleParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getObstacleParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getObstacleParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getObstacleParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getObstacleParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Waypoint functions
      mvIndex createWaypoint(mvOptionEnum wShape,mvFloat x,\
         mvFloat y, mvFloat z);
      mvWaypointPtr getWaypointPtr(mvIndex index);
      mvWaypointPtr getCurrentWaypointPtr();
      mvIndex setCurrentWaypoint(mvIndex index);
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

      mvErrorEnum setWaypointParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setWaypointParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setWaypointParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setWaypointParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getWaypointParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getWaypointParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getWaypointParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getWaypointParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getWaypointParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Pathway functions
      mvIndex createPathway();
      mvPathwayPtr getPathwayPtr(mvIndex index);
      mvPathwayPtr getCurrentPathwayPtr();
      mvIndex setCurrentPathway(mvIndex index);
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

      mvErrorEnum setPathwayParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setPathwayParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setPathwayParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setPathwayParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getPathwayParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getPathwayParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getPathwayParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getPathwayParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getPathwayParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Behaviour functions
      mvIndex createBehaviour(mvOptionEnum bType);
      mvBehaviourPtr getBehaviourPtr(mvIndex index);
      mvBehaviourPtr getCurrentBehaviourPtr();
      mvIndex setCurrentBehaviour(mvIndex index);
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

      mvErrorEnum setBehaviourParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setBehaviourParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBehaviourParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBehaviourParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getBehaviourParameteri(mvIndex index,\
         mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getBehaviourParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getBehaviourParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getBehaviourParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getBehaviourParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // Group functions
      mvIndex createGroup(const char* groupID);
      mvGroupPtr getGroupPtr(mvIndex index);
      mvGroupPtr getCurrentGroupPtr();
      mvIndex setCurrentGroup(mvIndex index);
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

      mvErrorEnum setGroupParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setGroupParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setGroupParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getGroupParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getGroupParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getGroupParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      // GroupBehaviour functions
      mvIndex createGroupBehaviour(mvOptionEnum type);
      mvGroupBehaviourPtr getGroupBehaviourPtr(mvIndex index);
      mvGroupBehaviourPtr getCurrentGroupBehaviourPtr();
      mvIndex setCurrentGroupBehaviour(mvIndex index);
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

      mvErrorEnum setGroupBehaviourParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourParameter_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char* option);
      mvErrorEnum setGroupBehaviourParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat num);
      mvErrorEnum setGroupBehaviourParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array);

      mvErrorEnum getGroupBehaviourParameteri(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourParameter(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getGroupBehaviourParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getGroupBehaviourParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourParameter_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char** option) const;
      mvErrorEnum getGroupBehaviourParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      // Force functions
      mvIndex createForce(mvOptionEnum fType);
      mvBaseForcePtr getForcePtr(mvIndex index);
      mvBaseForcePtr getCurrentForcePtr();
      mvIndex setCurrentForce(mvIndex index);
      mvErrorEnum deleteForce(mvIndex index);
      void deleteAllForces();
      void applyToAllForces(void (someFunction)(mvBaseForcePtr, void*),\
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

      mvErrorEnum setForceParameteri_str(mvIndex index, const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setForceParameter_str(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setForceParameterf_str(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setForceParameterv_str(mvIndex index, const char* param,\
         mvFloat* array);

      mvErrorEnum getForceParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getForceParameteri_str(mvIndex index, const char* param,\
         mvIndex* outIndex) const;
      mvErrorEnum getForceParameter_str(mvIndex index, const char* param,\
         const char** option) const;
      mvErrorEnum getForceParameterf_str(mvIndex index, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getForceParameterv_str(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvIndex addBehaviourToList(mvIndex listIndex, mvOptionEnum bType,\
         mvIndex behaviourIndex, mvIndex groupIndex);
      mvIndex addBehaviourToList_str(mvIndex listIndex, const char* bType,\
         mvIndex behaviourIndex, mvIndex groupIndex);
      mvErrorEnum removeBehaviourFromList(mvIndex listIndex, mvIndex entryIndex);
      mvErrorEnum removeAllBehavioursFromList(mvIndex listIndex);
      mvIndex getCurrentEntryFromList(mvIndex listIndex) const;

      mvErrorEnum addGroupIntoGroupBehaviour(mvIndex groupIndex,\
         mvIndex groupBehaviour);

      mvErrorEnum removeGroupFromGroupBehaviour(mvIndex groupIndex,\
         mvIndex groupBehaviour);

      mvErrorEnum addMemberIntoGroup(mvIndex memberIndex, mvIndex groupIndex);

      mvErrorEnum removeMemberFromGroup(mvIndex memberIndex, mvIndex groupIndex);

      mvErrorEnum findMemberFromGroup(mvIndex memberIndex, mvIndex groupIndex)
         const;

      mvErrorEnum setMainGroupBehaviourParameter(mvIndex index,\
         mvParamEnum param, mvOptionEnum option);
      mvErrorEnum setMainGroupBehaviourParameteri(mvIndex index,\
         mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum setMainGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum param, mvFloat num);
      mvErrorEnum setMainGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum param, mvFloat* array);

      mvErrorEnum setMainGroupBehaviourParameteri_str(mvIndex index,\
         const char* param, mvIndex paramIndex);
      mvErrorEnum setMainGroupBehaviourParameter_str(mvIndex index,\
         const char* param, const char* option);
      mvErrorEnum setMainGroupBehaviourParameterf_str(mvIndex index,\
         const char* param, mvFloat num);
      mvErrorEnum setMainGroupBehaviourParameterv_str(mvIndex index,\
         const char* param, mvFloat* array);

      mvErrorEnum getMainGroupBehaviourParameter_str(mvIndex index,\
         const char* param, const char** option) const;
      mvErrorEnum getMainGroupBehaviourParameteri_str(mvIndex index,\
         const char* param, mvIndex* paramIndex) const;
      mvErrorEnum getMainGroupBehaviourParameterf_str(mvIndex index,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getMainGroupBehaviourParameterv_str(mvIndex index,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum getMainGroupBehaviourParameter(mvIndex index,\
         mvParamEnum param, mvOptionEnum* option) const;
      mvErrorEnum getMainGroupBehaviourParameteri(mvIndex index,\
         mvParamEnum param, mvIndex* paramIndex) const;
      mvErrorEnum getMainGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum param, mvFloat* num) const;
      mvErrorEnum getMainGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum param, mvFloat* array, mvCount* noOfParameters) const;

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
      mvConstBaseForcePtr getConstForcePtr(mvIndex index) const;

      mvIndex addNodeToPathway(mvIndex nIndex, mvIndex pIndex);
      mvErrorEnum removeNodeFromPathway(mvIndex wpIndex, mvIndex pIndex);

      mvErrorEnum removeAllNodesFromPathway(mvIndex pwIndex);

      mvIndex getCurrentNodeOfPathway(mvIndex pwIndex) const;

      mvErrorEnum removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex);

      mvErrorEnum setPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setPathwayNodeParameter(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex index);
      mvErrorEnum setPathwayNodeParameter_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char* option);
      mvErrorEnum setPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array);

      mvErrorEnum getPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParameter(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParameter_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char** option) const;
      mvErrorEnum getPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum setEntryListNodeParameteri(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setEntryListNodeParameter(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setEntryListNodeParameterf(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setEntryListNodeParameterv(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setEntryListNodeParameteri_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvIndex index);
      mvErrorEnum setEntryListNodeParameter_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, const char* option);
      mvErrorEnum setEntryListNodeParameterf_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat num);
      mvErrorEnum setEntryListNodeParameterv_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array);

      mvErrorEnum getEntryListNodeParameteri(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getEntryListNodeParameter(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getEntryListNodeParameterf(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getEntryListNodeParameterv(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getEntryListNodeParameteri_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getEntryListNodeParameter_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, const char** option) const;
      mvErrorEnum getEntryListNodeParameterf_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getEntryListNodeParameterv_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum setEntryListParameteri(mvIndex listIndex,\
         mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setEntryListParameter(mvIndex listIndex,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setEntryListParameterf(mvIndex listIndex,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setEntryListParameterv(mvIndex listIndex,\
         mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setEntryListParameteri_str(mvIndex listIndex,\
         const char* param, mvIndex index);
      mvErrorEnum setEntryListParameter_str(mvIndex listIndex,\
         const char* param, const char* option);
      mvErrorEnum setEntryListParameterf_str(mvIndex listIndex,\
         const char* param, mvFloat num);
      mvErrorEnum setEntryListParameterv_str(mvIndex listIndex,\
         const char* param, mvFloat* array);

      mvErrorEnum getEntryListParameteri(mvIndex listIndex,\
         mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getEntryListParameter(mvIndex listIndex,\
         mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getEntryListParameterf(mvIndex listIndex,\
         mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getEntryListParameterv(mvIndex listIndex,\
         mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getEntryListParameteri_str(mvIndex listIndex,\
         const char* param, mvIndex* outIndex) const;
      mvErrorEnum getEntryListParameter_str(mvIndex listIndex,\
         const char* param, const char** option) const;
      mvErrorEnum getEntryListParameterf_str(mvIndex listIndex,\
         const char* param, mvFloat* num) const;
      mvErrorEnum getEntryListParameterv_str(mvIndex listIndex,\
         const char* param, mvFloat* array, mvCount* noOfParameters) const;

      void applyToAllEntryLists(void (someFunction)(mvEntryListPtr, void*),
         void* extraPtr);
      mvErrorEnum setUserData(mvParamEnum objectType, mvIndex objectIndex,\
         void* userData);
      void* getUserData(mvParamEnum objectType, mvIndex objectIndex) const;
};



#endif
