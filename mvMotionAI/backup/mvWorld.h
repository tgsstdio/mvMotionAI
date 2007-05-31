/**
 * \file mvWorld.h
 *
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
 */

#ifndef MOTIONAI_MVWORLD_H_
#define MOTIONAI_MVWORLD_H_
#include "mvMotionAI-Types.h"
#include "mvBody.h"
#include "mvWaypoint.h"
#include "mvBehaviour.h"
#include "mvPathway.h"
#include "mvGroup.h"
#include "mvObstacle.h"
#include "mvForce.h"
#include "mvGroupBehaviour.h"

/**
 * \class mvWorld
 * \brief an global instance of the AI module, storing all instances
 *         of vehicles, obstacles and global variables.
 *
 *Log
 *version     date     comments
 *00-01-17  11/11/06   - implemented nudge body functions
 *
 *           2/11/06   - added lot of set and get parameter functions
 *
 *
 *00-01-05   23/8/06   - using mvMotionAI types headers
 *
 *00-01-03   21/6/06   - iterator has now working behaviours
 *
 *00-01-01   25/6/06   - completing mvBehaviour functions
 *
 *00-01-00   22/5/06   - rename mWorld into mvWorld, allowed forces and
 *                     groups
 *
 *00-00-06    6/3/06   - adding (hopefully) a temporary Particle array and
 * to mWorld so I can prototype behaviour early.
 *
 *00-00-05    3/3/06    - adding basic intergrater (Improved Euler)
 * to m world.
 *
 *00-00-04     26/2/06   - added world ID variable
 *
 *00-00-04    22/2/06   Separated MotionAI to allow multiple instances
 *
 *00-00-01    7/2/06   created file
 *                      -added scripting language to MotionAI
 *
 *00-00-01    8/2/06   loads lua script files and adds vehicles
 *                     and obstacles
 *
 */
//TODO: declare new template vector class to encapsulate ...
class mvWorld
{
   private:
      void resetAllVariables();

      char* idString;
      std::vector<mvWaypoint*> waypoints;
      mvCount noOfWaypoints;
      std::vector<mvBehaviour*> behaviours;
      mvCount noOfBehaviours;
      std::vector<mvBodyPtr> bodies;
      mvCount noOfBodies;
      std::vector<mvPathway*> pathways;
      mvCount noOfPathways;
      std::vector<mvObstacle*> obstacles;
      mvCount noOfObstacles;
      std::vector<mvGroup*> groups;
      mvCount noOfGroups;
      std::vector<mvGroupBehaviourPtr> groupBehaviours;
      mvCount noOfGroupBehaviours;
      mvIndex currentGroupBehaviour;

      mvIndex currentPathway;
      mvIndex currentBody;
      mvIndex currentGroup;
      mvIndex currentBehaviour;
      mvIndex currentWaypoint;
      mvIndex currentObstacle;

      std::vector<mvForce*> forces;
      mvCount noOfForces;
      mvIndex currentForce;
      //Vec3 gravityDirection;
      //mvFloat gravityFactor;

   public:
      mvWorld(); //< initialised
      mvWorld(const char* worldID); //< initialised
      char* getWorldID() const; //< initialised
      ~mvWorld(); //< initialised

      mvIndex mvAddWaypoint(mvOptionEnum wType, mvOptionEnum wShape); //< initialised
      mvIndex mvAddWaypointWithPos(mvOptionEnum wType, mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z);//< initialised
      mvWaypointPtr mvGetWaypoint(mvIndex index);//< initialised
      mvErrorEnum mvRemoveWaypoint(mvIndex index);//< initialised
      mvErrorEnum mvRemoveCurrentWaypoint();//< initialised
      mvIndex mvSetCurrentWaypoint(mvIndex index);//< initialised
      void mvRemoveAllWaypoints();//< initialised
      mvErrorEnum mvSetWaypointParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetWaypointParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetWaypointParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array);//< initialised

      mvErrorEnum mvSetCurrentWaypointParameter(mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetCurrentWaypointParameterf(mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetCurrentWaypointParameterv(mvParamEnum paramFlag, mvFloat* array);//< initialised

      mvIndex mvBeginPathway();//< initialised
      mvPathway* mvGetPathway(mvIndex index);//< initialised
      mvErrorEnum mvRemovePathway(mvIndex index);//< initialised
      //mvIndex mvEndPathway();
      mvErrorEnum mvRemoveCurrentPathway();//< initialised
      mvIndex mvSetCurrentPathway(mvIndex index);//< initialised
      void mvRemoveAllPathways();//< initialised

      mvErrorEnum mvSetPathwayParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetPathwayParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetPathwayParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array);//< initialised
      mvErrorEnum mvSetCurrentPathwayParameter(mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetCurrentPathwayParameterf(mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetCurrentPathwayParameterv(mvParamEnum paramFlag, mvFloat* array);//< initialised
      //
      mvErrorEnum mvAddWaypointToPathway(mvIndex wpIndex, mvIndex pIndex); //< initialised
      mvErrorEnum mvAddWaypointToCurrentPathway(mvIndex wpIndex);//< initialised
      mvErrorEnum mvAddCurrentWaypointToCurrentPathway();//< initialised
      mvErrorEnum mvAddCurrentWaypointToPathway(mvIndex pIndex);//< initialised
      mvErrorEnum mvRemoveWaypointFromPathway(mvIndex wpIndex, mvIndex pIndex); //< initialised
      mvErrorEnum mvRemoveWaypointFromCurrentPathway(mvIndex wpIndex);//< initialised
      mvErrorEnum mvRemoveCurrentWaypointFromPathway(mvIndex pIndex);//< initialised
      mvErrorEnum mvRemoveCurrentWaypointFromCurrentPathway();//< initialised
      //mvIndex mvAddNURBSWaypoint();


      mvIndex mvAddBody(mvOptionEnum bType, mvOptionEnum bShape); //< initialised
      mvIndex mvAddBodyWithPos(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z); //< initialised
      mvBodyPtr mvGetBody(mvIndex index); //< initialised
      mvIndex mvSetCurrentBody(mvIndex index); //< initialised
      mvErrorEnum mvRemoveCurrentBody(); //< initialised
      mvErrorEnum mvRemoveBody(mvIndex index); //< initialised
      void mvRemoveAllBodies();
      mvErrorEnum mvSetBodyParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetBodyParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetBodyParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array); //< initialised
      mvErrorEnum mvSetCurrentBodyParameter(mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetCurrentBodyParameterf(mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetCurrentBodyParameterv(mvParamEnum paramFlag, mvFloat* array); //< initialised

      mvIndex mvAddObstacle(mvOptionEnum oType, mvOptionEnum oState); //< initialised
      mvIndex mvAddObstacleWithPos(mvOptionEnum oType, mvOptionEnum oState,mvFloat x, mvFloat y, mvFloat z); //< initialised
      mvObstacle* mvGetObstacle(mvIndex index); //< initialised
      mvErrorEnum mvRemoveCurrentObstacle(); //< initialised
      mvErrorEnum mvRemoveObstacle(mvIndex index); //< initialised
      mvIndex mvSetCurrentObstacle(mvIndex index); //< initialised
      void mvRemoveAllObstacles(); //< initialised
      mvErrorEnum mvSetCurrentObstacleParameter(mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetCurrentObstacleParameterf(mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetCurrentObstacleParameterv(mvParamEnum paramFlag, mvFloat* array); //< initialised
      mvErrorEnum mvSetObstacleParameter(mvIndex index,  mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetObstacleParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetObstacleParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array); //< initialised

      //mvIndex mvAddBehaviour(char* bName, mvOptionEnum bType); //< initialised
      mvIndex mvAddBehaviour(mvOptionEnum bType);
      mvBehaviourPtr mvGetBehaviour(mvIndex index); //< initialised
      //mvBehaviourPtr mvGetBehaviourByID(char* bID);//< initialised
      mvIndex mvGetBehaviourIndexByID(char* bID);//< initialised
      mvErrorEnum mvRemoveCurrentBehaviour();//< initialised
      mvErrorEnum mvRemoveBehaviour(mvIndex index);//< initialised
      mvIndex mvSetCurrentBehaviour(mvIndex index);//< initialised
      void mvRemoveAllBehaviours();//< initialised
      mvErrorEnum mvSetBehaviourParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetBehaviourParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetBehaviourParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array);//< initialised
      mvErrorEnum mvSetCurrentBehaviourParameter(mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetCurrentBehaviourParameterf(mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetCurrentBehaviourParameterv(mvParamEnum paramFlag, mvFloat* array);//< initialised

      /*
      mvEnum mvAddBehaviourToBody(mvIndex behaviourIndex,mvIndex bodyIndex);//< initialised
      mvEnum mvAddCurrentBehaviourToBody(mvIndex bodyIndex);//< initialised
      mvEnum mvAddBehaviourToCurrentBody(mvIndex behaviourIndex);//< initialised
      mvEnum mvAddCurrentBehaviourToCurrentBody();//< initialised

      mvEnum mvAddWaypointToBehaviour(mvIndex wpIndex,mvIndex behIndex); //< initialised
      mvEnum mvAddCurrentWaypointToBehaviour(mvIndex behIndex);//< initialised
      mvEnum mvAddWaypointToCurrentBehaviour(mvIndex wpIndex);//< initialised
      mvEnum mvAddCurrentWaypointToCurrentBehaviour();//< initialised

      mvEnum mvAddBodyToBehaviour(mvIndex bodyIndex, mvIndex behaviourIndex);//< initialised
      mvEnum mvAddCurrentBodyToBehaviour(mvIndex behaviourIndex);//< initialised
      mvEnum mvAddBodyToCurrentBehaviour(mvIndex bodyIndex);//< initialised
      mvEnum mvAddCurrentBodyToCurrentBehaviour();//< initialised

      */

      mvIndex mvAddGroup(char* mvGroupID); //< initialised
      mvGroupPtr mvGetGroup(mvIndex index); //< initialised
      mvGroupPtr mvGetGroupByID(char* groupID);
      mvIndex mvGetGroupIndexByID(char* groupID);
      mvErrorEnum mvRemoveCurrentGroup(); //< initialised
      mvErrorEnum mvRemoveGroup(mvIndex index); //< initialised
      mvIndex mvSetCurrentGroup(mvIndex index);//< initialised
      void mvRemoveAllGroups(); //< initialised
      mvErrorEnum mvSetGroupParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetGroupParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetGroupParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array); //< initialised
      mvErrorEnum mvSetCurrentGroupParameter(mvParamEnum paramFlag, mvOptionEnum option); //< initialised
      mvErrorEnum mvSetCurrentGroupParameterf(mvParamEnum paramFlag, mvFloat num); //< initialised
      mvErrorEnum mvSetCurrentGroupParameterv(mvParamEnum paramFlag, mvFloat* array); //< initialised

      //
      mvErrorEnum mvAddBodyToGroup(mvIndex bodyIndex, mvIndex groupIndex);//< initialised
      mvErrorEnum mvAddCurrentBodyToGroup(mvIndex groupIndex);//< initialised
      mvErrorEnum mvAddBodyToCurrentGroup(mvIndex bodyIndex);//< initialised
      mvErrorEnum mvAddCurrentBodyToCurrentGroup();//< initialised
      mvErrorEnum mvRemoveBodyFromGroup(mvIndex bodyIndex, mvIndex groupIndex);//< initialised
      mvErrorEnum mvRemoveCurrentBodyFromGroup(mvIndex groupIndex);//< initialised
      mvErrorEnum mvRemoveBodyFromCurrentGroup(mvIndex bodyIndex);//< initialised
      mvErrorEnum mvRemoveCurrentBodyFromCurrentGroup();//< initialised

      mvIndex mvAddForce(mvOptionEnum fType); //< initialised
      mvForcePtr mvGetForce(mvIndex index);//< initialised
      mvIndex mvAddForceVector(mvOptionEnum fType, mvFloat x, mvFloat y, mvFloat z);//< initialised
      mvErrorEnum mvRemoveForce(mvIndex index);//< initialised
      mvErrorEnum mvRemoveCurrentForce();//< initialised
      void mvRemoveAllForces();//< initialised
      mvIndex mvSetCurrentForce(mvIndex index);//< initialised
      mvErrorEnum mvSetForceParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetForceParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetForceParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array);//< initialised
      mvErrorEnum mvSetCurrentForceParameter(mvParamEnum paramFlag, mvOptionEnum option);//< initialised
      mvErrorEnum mvSetCurrentForceParameterf(mvParamEnum paramFlag, mvFloat num);//< initialised
      mvErrorEnum mvSetCurrentForceParameterv(mvParamEnum paramFlag, mvFloat* array); //< initialised

      // mv group behaviours
      mvIndex mvAddGroupBehaviour(mvOptionEnum type); //< initialised
      mvGroupBehaviourPtr mvGetGroupBehaviour(mvIndex index); //< initialised
      mvErrorEnum mvRemoveGroupBehaviour(mvIndex index); //< initialised
      mvErrorEnum mvRemoveCurrentGroupBehaviour(); //< initialised
      void mvRemoveAllGroupBehaviours(); //< initialised
      mvIndex mvSetCurrentGroupBehaviour(mvIndex index); //< initialised
      /*
      mvEnum mvSetGroupBehaviourParameter(mvIndex index, mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetGroupBehaviourParameterf(mvIndex index, mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetGroupBehaviourParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameter(mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameterf(mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameterv(mvEnum paramFlag, mvFloat* array);  //< initialised
      */

      mvErrorEnum mvSetGroupBehaviourParameter(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum mvSetGroupBehaviourParameteri(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvIndex option);
      mvErrorEnum mvSetGroupBehaviourParameterf(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum mvSetGroupBehaviourParameterv(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum mvSetCurrentGroupBehaviourParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum mvSetCurrentGroupBehaviourParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex option);
      mvErrorEnum mvSetCurrentGroupBehaviourParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum mvSetCurrentGroupBehaviourParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array);

      mvErrorEnum mvInsertGroupIntoGroupBehaviour(mvIndex groupIndex, mvIndex groupBehaviour);
      mvErrorEnum mvInsertCurrentGroupIntoGroupBehaviour(mvIndex groupBehaviour);
      mvErrorEnum mvInsertGroupIntoCurrentGroupBehaviour(mvIndex groupIndex);
      mvErrorEnum mvInsertCurrentGroupIntoCurrentGroupBehaviour();

      void mvWorldStep(mvFloat timeInSecs); //< initialised
      void mvApplyToAllBodies(void (someFunction)(mvBodyPtr,void*),void* extraPtr);
      void mvApplyToAllObstacles(void (someFunction)(mvObstacle*,void*),void* extraPtr);
      void mvApplyToAllWaypoints(void (someFunction)(mvWaypoint*,void*),void* extraPtr);

      mvErrorEnum mvSetDefaultWaypointForBody(mvIndex waypointIndex, mvIndex bodyIndex);  //< initialised
      mvErrorEnum mvSetDefaultPathwayForBody(mvIndex pathwayIndex, mvIndex bodyIndex);  //< initialised
      mvErrorEnum mvSetDefaultBodyForBody(mvIndex targetIndex,mvIndex bodyIndex); //< initialised
      mvErrorEnum mvSetDefaultBehaviourFactorForBody(mvFloat factor, mvIndex bodyIndex); //< initialised

      mvErrorEnum mvSetDefaultWaypointForCurrentBody(mvIndex wpIndex); //< initialised
      mvErrorEnum mvSetDefaultPathwayForCurrentBody(mvIndex pwIndex);  //< initialised
      mvErrorEnum mvSetDefaultBodyForCurrentBody(mvIndex bodyIndex); //< initialised
      mvErrorEnum mvSetDefaultBehaviourFactorForCurrentBody(mvFloat factor); //< initialised

      mvErrorEnum mvAddBehaviourToBody(mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);//< initialised
      mvErrorEnum mvAddBehaviourToCurrentBody(mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);//< initialised

      mvErrorEnum mvSetBehaviourParameteri(mvIndex behaviourIndex,mvParamEnum paramFlag, mvIndex index);  //< initialised
      mvErrorEnum mvSetCurrentBehaviourParameteri(mvParamEnum paramFlag, mvIndex index);  //< initialised

      mvErrorEnum mvSetBodyParameteri(mvIndex bIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetPathwayParameteri(mvIndex pIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetWaypointParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetObstacleParameteri(mvIndex oIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetGroupParameteri(mvIndex gIndex, mvParamEnum paramFlag, mvIndex index);

      mvErrorEnum mvSetCurrentBodyParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetCurrentPathwayParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetCurrentWaypointParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetCurrentObstacleParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum mvSetCurrentGroupParameteri(mvParamEnum paramFlag, mvIndex index);

      mvErrorEnum mvGetBodyParameteri(mvIndex bIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetPathwayParameteri(mvIndex pIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetWaypointParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetObstacleParameteri(mvIndex oIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetGroupParameteri(mvIndex gIndex, mvParamEnum paramFlag, mvIndex* index);

      mvErrorEnum mvGetCurrentBodyParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetCurrentPathwayParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetCurrentWaypointParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetCurrentObstacleParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum mvGetCurrentGroupParameteri(mvParamEnum paramFlag, mvIndex* index);

      mvErrorEnum mvGetBodyParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetBodyParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetBodyParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentBodyParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentBodyParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentBodyParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetObstacleParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetObstacleParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetObstacleParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentObstacleParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentObstacleParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentObstacleParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetWaypointParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetWaypointParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetWaypointParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentWaypointParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentWaypointParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentWaypointParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetPathwayParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetPathwayParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetPathwayParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentPathwayParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentPathwayParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentPathwayParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetGroupParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetGroupParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetGroupParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentGroupParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentGroupParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentGroupParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetBehaviourParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetBehaviourParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetBehaviourParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentBehaviourParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentBehaviourParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentBehaviourParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetGroupBehaviourParameter(mvIndex gbIndex, mvIndex groupIndex,  mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetGroupBehaviourParameterf(mvIndex gbIndex, mvIndex groupIndex,  mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetGroupBehaviourParameterv(mvIndex gbIndex, mvIndex groupIndex,  mvParamEnum param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum mvGetCurrentGroupBehaviourParameter(mvIndex groupIndex, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentGroupBehaviourParameterf(mvIndex groupIndex, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentGroupBehaviourParameterv(mvIndex groupIndex, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvSetMainGroupBehaviourParameter(mvIndex index, mvParamEnum param, mvOptionEnum option);
      mvErrorEnum mvSetMainGroupBehaviourParameteri(mvIndex index, mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum mvSetMainGroupBehaviourParameterf(mvIndex index, mvParamEnum param, mvFloat num);
      mvErrorEnum mvSetMainGroupBehaviourParameterv(mvIndex index, mvParamEnum param, mvFloat* array);

      mvErrorEnum mvSetCurrentMainGroupBehaviourParameter(mvParamEnum param, mvOptionEnum option);
      mvErrorEnum mvSetCurrentMainGroupBehaviourParameteri(mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum mvSetCurrentMainGroupBehaviourParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum mvSetCurrentMainGroupBehaviourParameterv(mvParamEnum param, mvFloat* array);

      mvErrorEnum mvGetMainGroupBehaviourParameter(mvIndex index, mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetMainGroupBehaviourParameteri(mvIndex index, mvParamEnum param, mvIndex* paramIndex);
      mvErrorEnum mvGetMainGroupBehaviourParameterf(mvIndex index, mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetMainGroupBehaviourParameterv(mvIndex index, mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvGetCurrentMainGroupBehaviourParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetCurrentMainGroupBehaviourParameteri(mvParamEnum param, mvIndex* paramIndex);
      mvErrorEnum mvGetCurrentMainGroupBehaviourParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetCurrentMainGroupBehaviourParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvSetWorldParameter(mvParamEnum param, mvOptionEnum option);
      mvErrorEnum mvSetWorldParameteri(mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum mvSetWorldParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum mvSetWorldParameterv(mvParamEnum param, mvFloat* array);

      mvErrorEnum mvGetWorldParameter(mvParamEnum param, mvOptionEnum* option);
      mvErrorEnum mvGetWorldParameteri(mvParamEnum param, mvIndex* paramIndex);
      mvErrorEnum mvGetWorldParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum mvGetWorldParameterv(mvParamEnum param, mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum mvSetForceParameteri(mvIndex index, mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum mvGetForceParameteri(mvIndex index, mvParamEnum param, mvIndex* paramIndex);
      mvErrorEnum mvSetCurrentForceParameteri(mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum mvGetCurrentForceParameteri(mvParamEnum param, mvIndex* paramIndex);

      mvErrorEnum mvNudgeBody(mvIndex index, mvFloat timeInSecs);
      mvErrorEnum mvNudgeCurrentBody(mvFloat timeInSecs);

// TODO (White 2#1#): implement these functions below
      void mvApplyToAllGroupsByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllBodiesByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllObstaclesByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllBehavioursByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);

      void mvApplyToAllWaypointsByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllPathwaysByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllForcesByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);
      void mvApplyToAllGroupBehavioursByIndex(void (someFunction)(mvIndex,void*), void* extraPtr);

      void mvApplyToAllBehaviours(void (someFunction)(mvBehaviour*, void*), void* extraPtr);
      void mvApplyToAllWaypoints(void (someFunction)(mvBehaviour*, void*), void* extraPtr);
      void mvApplyToAllPathways(void (someFunction)(mvBehaviour*, void*), void* extraPtr);
      void mvApplyToAllForces(void (someFunction)(mvBehaviour*, void*), void* extraPtr);
      void mvApplyToAllGroups(void (someFunction)(mvBehaviour*, void*), void* extraPtr);
};

#endif

