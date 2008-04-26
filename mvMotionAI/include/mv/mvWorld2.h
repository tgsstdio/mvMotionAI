#ifndef MV_MOTIONAI_WORLD_V2_H_
#define MV_MOTIONAI_WORLD_V2_H_

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

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

#include MV_ACTION_LOADER_LIST_HEADER_FILE_H_
#include MV_FORCE_LOADER_LIST_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_BODY_HEADER_FILE_H_
#include MV_OBSTACLE_HEADER_FILE_H_
#include MV_WAYPOINT_HEADER_FILE_H_
#include MV_PATHWAY_HEADER_FILE_H_
#include MV_GROUP_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_HEADER_FILE_H_
#include MV_BEHAVIOUR_HEADER_FILE_H_


#include MV_POINTER_LIST_HEADER_FILE_H_
#include MV_CAPSULE_LIST_HEADER_FILE_H_

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

// TODO : reorganize index order

class MV_GLOBAL_FUNC_PREFIX mvWorld
{
   private:
      mvActionLoaderListPtr behavLoader;

      /// world step functionality
      void prepareIntegrationStep();
      void setFinalBodyCapsuleVariables(mvBodyCapsulePtr bodyPtr,
         mvBehaviourResultPtr behavResModule,
         mvForceResultPtr forceResModule);
      void calculateGroupBehaviours(); // 1
      void checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr, mvUniqueSet&
         waypointList);
      void resetIntegrationLoop();
      void calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr,\
         mvForceResultPtr finalForceResult, mvUniqueSet& waypointList);
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
      mvPointerList<mvEntryListPtr, mvConstEntryListPtr> entryLists;
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

      void registerAllGroupBehavioursToBodies();
      mvErrorEnum registerGroupBehaviourToBodies(mvIndex groupBehaviourIndex);

      mvFloat getElapsedWorldTime() const;
      void integrateBody(mvBodyCapsulePtr bodyPtr, mvFloat timeInSecs);
      bool hasGroupChanged(mvIndex groupNo);

      /** \brief
       * internal function - info is useless out of integration loop
       */
      mvIndex convertWaypointIndex(mvIndex wPointIndex) const;

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

      mvWorld();
      ~mvWorld();
      void setWorldUserData(void* tempData);
      void* getWorldUserData() const;

      void setActionLoader(mvActionLoaderListPtr bLoaderPtr);
      mvActionLoaderListPtr getActionLoader() const;

      void setForceLoader(mvForceLoaderListPtr fLoaderPtr);
      mvForceLoaderListPtr getForceLoaderPtr() const;

      mvErrorEnum worldStep(mvFloat timeInSecs);
      mvErrorEnum nudgeBody(mvIndex bodyIndex, mvFloat timeInSecs);

      mvErrorEnum getParametero(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfElements) const;

      mvErrorEnum setParametero(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      // body functions
      mvIndex createBody(mvOptionEnum bType, mvOptionEnum bShape,\
         mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);
      mvIndex createBody_str(const char* bType, const char* bShape,\
         mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);

		mvErrorEnum removeBodyAndEntryList(mvIndex objIndex);
		mvErrorEnum setCurrentBodyAndEntryList(mvIndex objIndex);

      // obstacle functions
      mvIndex createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
         mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);
      mvIndex createObstacle_str(const char* oType, const char* oState,\
         mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);

      // Waypoint functions
      mvIndex createWaypoint(mvOptionEnum wShape,mvFloat x,\
         mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);
      mvIndex createWaypoint_str(const char* wShape,mvFloat x,\
         mvFloat y, mvFloat z, mvIndex saveFileIndex = MV_NULL);

      // Pathway functions
      mvIndex createPathway(mvIndex saveFileIndex = MV_NULL);

      // Behaviour functions
      mvIndex createBehaviour(mvOptionEnum bType,\
         mvIndex saveFileIndex = MV_NULL);
      mvIndex createBehaviour_str(const char* bType,\
         mvIndex saveFileIndex = MV_NULL);

      // Group functions
      mvIndex createGroup(mvIndex saveFileIndex = MV_NULL);

      // GroupBehaviour functions
      mvIndex createGroupBehaviour(mvOptionEnum type,\
         mvIndex saveFileIndex = MV_NULL);
      mvIndex createGroupBehaviour_str(const char* type,\
         mvIndex saveFileIndex = MV_NULL);

      mvErrorEnum setGroupBehaviourNodeParameteri(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourNodeParametero(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setGroupBehaviourNodeParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setGroupBehaviourNodeParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setGroupBehaviourNodeParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex paramIndex);
      mvErrorEnum setGroupBehaviourNodeParametero_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char* option);
      mvErrorEnum setGroupBehaviourNodeParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat num);
      mvErrorEnum setGroupBehaviourNodeParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array);

      mvErrorEnum getGroupBehaviourNodeParameteri(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourNodeParametero(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getGroupBehaviourNodeParameterf(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourNodeParameterv(mvIndex index,\
         mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getGroupBehaviourNodeParameteri_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getGroupBehaviourNodeParametero_str(mvIndex index,\
         mvIndex groupIndex, const char* param, const char** option) const;
      mvErrorEnum getGroupBehaviourNodeParameterf_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getGroupBehaviourNodeParameterv_str(mvIndex index,\
         mvIndex groupIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      // Force functions
      mvIndex createForce(mvOptionEnum fType,\
         mvIndex saveFileIndex = MV_NULL);
      mvIndex createForce_str(const char* fType,\
         mvIndex saveFileIndex = MV_NULL);

      mvErrorEnum setPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setPathwayNodeParametero(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex index);
      mvErrorEnum setPathwayNodeParametero_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char* option);
      mvErrorEnum setPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat num);
      mvErrorEnum setPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array);

      mvErrorEnum getPathwayNodeParameteri(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParametero(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getPathwayNodeParameterf(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv(mvIndex pathwayIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getPathwayNodeParameteri_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getPathwayNodeParametero_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, const char** option) const;
      mvErrorEnum getPathwayNodeParameterf_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getPathwayNodeParameterv_str(mvIndex pathwayIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum setEntryListNodeParameteri(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setEntryListNodeParametero(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setEntryListNodeParameterf(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setEntryListNodeParameterv(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum setEntryListNodeParameteri_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvIndex index);
      mvErrorEnum setEntryListNodeParametero_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, const char* option);
      mvErrorEnum setEntryListNodeParameterf_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat num);
      mvErrorEnum setEntryListNodeParameterv_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array);

      mvErrorEnum getEntryListNodeParameteri(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const;
      mvErrorEnum getEntryListNodeParametero(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const;
      mvErrorEnum getEntryListNodeParameterf(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getEntryListNodeParameterv(mvIndex listIndex,\
         mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum getEntryListNodeParameteri_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvIndex* outIndex) const;
      mvErrorEnum getEntryListNodeParametero_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, const char** option) const;
      mvErrorEnum getEntryListNodeParameterf_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* num) const;
      mvErrorEnum getEntryListNodeParameterv_str(mvIndex listIndex,\
         mvIndex nodeIndex, const char* param, mvFloat* array,\
         mvCount* noOfParameters) const;

      mvErrorEnum setUserData(mvParamEnum objectType, mvIndex objectIndex,\
         void* userData);
      void* getUserData(mvParamEnum objectType, mvIndex objectIndex) const;

      mvIndex addBehaviourToList(mvIndex listIndex, mvOptionEnum bType,\
         mvIndex behaviourIndex, mvIndex groupIndex,\
         mvIndex saveFileIndex = MV_NULL);
      mvIndex addBehaviourToList_str(mvIndex listIndex, const char* bType,\
         mvIndex behaviourIndex, mvIndex groupIndex,\
         mvIndex saveFileIndex = MV_NULL);
      mvErrorEnum removeBehaviourFromList(mvIndex listIndex, mvIndex entryIndex);
      mvErrorEnum removeAllBehavioursFromList(mvIndex listIndex);
      mvIndex getCurrentEntryFromList(mvIndex listIndex) const;

      mvErrorEnum addGroupIntoGroupBehaviour(mvIndex groupBehaviour,\
         mvIndex groupIndex);
      mvErrorEnum removeGroupFromGroupBehaviour(mvIndex groupBehaviour,\
         mvIndex groupIndex);
      mvErrorEnum addMemberIntoGroup(mvIndex groupIndex, mvIndex memberIndex);
      mvErrorEnum removeMemberFromGroup(mvIndex groupIndex, mvIndex memberIndex);
      mvIndex findMemberInGroup(mvIndex groupIndex, mvIndex memberIndex);

      mvErrorEnum removeAllNodesFromPathway(mvIndex pwIndex);
      mvIndex getCurrentNodeOfPathway(mvIndex pwIndex) const;
      mvErrorEnum removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex);

      mvErrorEnum removeAllWaypointsFromForce(mvIndex forceIndex);
      mvErrorEnum removeAllForcesFromWaypoint(mvIndex waypointIndex);
      mvErrorEnum removeAllGroupsFromGroupBehaviour(mvIndex gbIndex);
      mvErrorEnum removeAllMembersFromGroup(mvIndex groupIndex);

      mvIndex addNodeToPathway(mvIndex pathwayIndex, mvIndex nodeIndex);
      mvErrorEnum removeNodeFromPathway(mvIndex pathwayIndex, mvIndex nodeIndex);

      mvErrorEnum addForceIntoWaypoint(mvIndex waypointIndex,
         mvIndex forceIndex);
      mvErrorEnum removeForceFromWaypoint(mvIndex waypointIndex,\
         mvIndex forceIndex);
      mvErrorEnum stepBody(mvIndex bodyIndex, mvFloat timeInSecs);
};



#endif
