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

class mvWorld
{
   private:
      void resetAllVariables();

      char* idString;
      std::vector<mvWaypoint*> waypoints;
      mvCount noOfWaypoints;
      std::vector<mvBehaviour*> behaviours;
      mvCount noOfBehaviours;
      std::vector<mvBody*> bodies;
      mvCount noOfBodies;
      std::vector<mvPathway*> pathways;
      mvCount noOfPathways;
      std::vector<mvObstacle*> obstacles;
      mvCount noOfObstacles;
      std::vector<mvGroup*> groups;
      mvCount noOfGroups;
      std::vector<mvGroupBehaviour*> groupBehaviours;
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
      mvWorld(char* worldID); //< initialised
      char* getWorldID() const; //< initialised
      ~mvWorld(); //< initialised

      mvIndex mvAddWaypoint(mvEnum wType, mvEnum wShape); //< initialised
      mvIndex mvAddWaypointWithPos(mvEnum wType, mvEnum wShape, mvFloat x, mvFloat y, mvFloat z);//< initialised
      mvWaypoint* mvGetWaypoint(mvIndex index);//< initialised
      mvEnum mvRemoveWaypoint(mvIndex index);//< initialised
      mvEnum mvRemoveCurrentWaypoint();//< initialised
      mvIndex mvSetCurrentWaypoint(mvIndex index);//< initialised
      void mvRemoveAllWaypoints();//< initialised
      mvEnum mvSetWaypointParameter(mvIndex index, mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetWaypointParameterf(mvIndex index, mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetWaypointParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array);//< initialised
      mvEnum mvSetCurrentWaypointParameter(mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetCurrentWaypointParameterf(mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetCurrentWaypointParameterv(mvEnum paramFlag, mvFloat* array);//< initialised

      mvIndex mvBeginPathway();//< initialised
      mvPathway* mvGetPathway(mvIndex index);//< initialised
      mvEnum mvRemovePathway(mvIndex index);//< initialised
      //mvIndex mvEndPathway();
      mvEnum mvRemoveCurrentPathway();//< initialised
      mvIndex mvSetCurrentPathway(mvIndex index);//< initialised
      void mvRemoveAllPathways();//< initialised
      mvEnum mvSetPathwayParameter(mvIndex index, mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetPathwayParameterf(mvIndex index, mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetPathwayParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array);//< initialised
      mvEnum mvSetCurrentPathwayParameter(mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetCurrentPathwayParameterf(mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetCurrentPathwayParameterv(mvEnum paramFlag, mvFloat* array);//< initialised
      //
      mvEnum mvAddWaypointToPathway(mvIndex wpIndex, mvIndex pIndex); //< initialised
      mvEnum mvAddWaypointToCurrentPathway(mvIndex wpIndex);//< initialised
      mvEnum mvAddCurrentWaypointToCurrentPathway();//< initialised
      mvEnum mvAddCurrentWaypointToPathway(mvIndex pIndex);//< initialised
      mvEnum mvRemoveWaypointFromPathway(mvIndex wpIndex, mvIndex pIndex); //< initialised
      mvEnum mvRemoveWaypointFromCurrentPathway(mvIndex wpIndex);//< initialised
      mvEnum mvRemoveCurrentWaypointFromPathway(mvIndex pIndex);//< initialised
      mvEnum mvRemoveCurrentWaypointFromCurrentPathway();//< initialised
      //mvIndex mvAddNURBSWaypoint();


      mvIndex mvAddBody(mvEnum bType, mvEnum bShape); //< initialised
      mvIndex mvAddBodyWithPos(mvEnum bType, mvEnum bShape, mvFloat x, mvFloat y, mvFloat z); //< initialised
      mvBody* mvGetBody(mvIndex index); //< initialised
      mvIndex mvSetCurrentBody(mvIndex index); //< initialised
      mvEnum mvRemoveCurrentBody(); //< initialised
      mvEnum mvRemoveBody(mvIndex index); //< initialised
      void mvRemoveAllBodies();
      mvEnum mvSetBodyParameter(mvIndex index, mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetBodyParameterf(mvIndex index, mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetBodyParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array); //< initialised
      mvEnum mvSetCurrentBodyParameter(mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetCurrentBodyParameterf(mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetCurrentBodyParameterv(mvEnum paramFlag, mvFloat* array); //< initialised

      mvIndex mvAddObstacle(mvEnum oType, mvEnum oState); //< initialised
      mvIndex mvAddObstacleWithPos(mvEnum oType, mvEnum oState,mvFloat x, mvFloat y, mvFloat z); //< initialised
      mvObstacle* mvGetObstacle(mvIndex index); //< initialised
      mvEnum mvRemoveCurrentObstacle(); //< initialised
      mvEnum mvRemoveObstacle(mvIndex index); //< initialised
      mvIndex mvSetCurrentObstacle(mvIndex index); //< initialised
      void mvRemoveAllObstacles(); //< initialised
      mvEnum mvSetCurrentObstacleParameter(mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetCurrentObstacleParameterf(mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetCurrentObstacleParameterv(mvEnum paramFlag, mvFloat* array); //< initialised
      mvEnum mvSetObstacleParameter(mvIndex index,  mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetObstacleParameterf(mvIndex index, mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetObstacleParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array); //< initialised

      //mvIndex mvAddBehaviour(char* bName, mvEnum bType); //< initialised
      mvIndex mvAddBehaviour(mvEnum bType);
      mvBehaviour* mvGetBehaviour(mvIndex index); //< initialised
      //mvBehaviour* mvGetBehaviourByID(char* bID);//< initialised
      mvIndex mvGetBehaviourIndexByID(char* bID);//< initialised
      mvEnum mvRemoveCurrentBehaviour();//< initialised
      mvEnum mvRemoveBehaviour(mvIndex index);//< initialised
      mvIndex mvSetCurrentBehaviour(mvIndex index);//< initialised
      void mvRemoveAllBehaviours();//< initialised
      mvEnum mvSetBehaviourParameter(mvIndex index, mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetBehaviourParameterf(mvIndex index, mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetBehaviourParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array);//< initialised
      mvEnum mvSetCurrentBehaviourParameter(mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetCurrentBehaviourParameterf(mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetCurrentBehaviourParameterv(mvEnum paramFlag, mvFloat* array);//< initialised

      /**
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

      **/

      mvIndex mvAddGroup(char* mvGroupID); //< initialised
      mvGroup* mvGetGroup(mvIndex index); //< initialised
      mvGroup* mvGetGroupByID(char* groupID);
      mvIndex mvGetGroupIndexByID(char* groupID);
      mvEnum mvRemoveCurrentGroup(); //< initialised
      mvEnum mvRemoveGroup(mvIndex index); //< initialised
      mvIndex mvSetCurrentGroup(mvIndex index);//< initialised
      void mvRemoveAllGroups(); //< initialised
      mvEnum mvSetGroupParameter(mvIndex index, mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetGroupParameterf(mvIndex index, mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetGroupParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array); //< initialised
      mvEnum mvSetCurrentGroupParameter(mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetCurrentGroupParameterf(mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetCurrentGroupParameterv(mvEnum paramFlag, mvFloat* array); //< initialised

      //
      mvEnum mvAddBodyToGroup(mvIndex bodyIndex, mvIndex groupIndex);//< initialised
      mvEnum mvAddCurrentBodyToGroup(mvIndex groupIndex);//< initialised
      mvEnum mvAddBodyToCurrentGroup(mvIndex bodyIndex);//< initialised
      mvEnum mvAddCurrentBodyToCurrentGroup();//< initialised
      mvEnum mvRemoveBodyFromGroup(mvIndex bodyIndex, mvIndex groupIndex);//< initialised
      mvEnum mvRemoveCurrentBodyFromGroup(mvIndex groupIndex);//< initialised
      mvEnum mvRemoveBodyFromCurrentGroup(mvIndex bodyIndex);//< initialised
      mvEnum mvRemoveCurrentBodyFromCurrentGroup();//< initialised

      mvIndex mvAddForce(mvEnum fType); //< initialised
      mvForce* mvGetForce(mvIndex index);//< initialised
      mvIndex mvAddForceVector(mvEnum fType, mvFloat x, mvFloat y, mvFloat z);//< initialised
      mvEnum mvRemoveForce(mvIndex index);//< initialised
      mvEnum mvRemoveCurrentForce();//< initialised
      void mvRemoveAllForces();//< initialised
      mvIndex mvSetCurrentForce(mvIndex index);//< initialised
      mvEnum mvSetForceParameter(mvIndex index, mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetForceParameterf(mvIndex index, mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetForceParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array);//< initialised
      mvEnum mvSetCurrentForceParameter(mvEnum paramFlag, mvEnum option);//< initialised
      mvEnum mvSetCurrentForceParameterf(mvEnum paramFlag, mvFloat num);//< initialised
      mvEnum mvSetCurrentForceParameterv(mvEnum paramFlag, mvFloat* array); //< initialised

      // mv group behaviours
      mvIndex mvAddGroupBehaviour(mvEnum type); //< initialised
      mvGroupBehaviour* mvGetGroupBehaviour(mvIndex index); //< initialised
      mvEnum mvRemoveGroupBehaviour(mvIndex index); //< initialised
      mvEnum mvRemoveCurrentGroupBehaviour(); //< initialised
      void mvRemoveAllGroupBehaviours(); //< initialised
      mvIndex mvSetCurrentGroupBehaviour(mvIndex index); //< initialised
      /**
      mvEnum mvSetGroupBehaviourParameter(mvIndex index, mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetGroupBehaviourParameterf(mvIndex index, mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetGroupBehaviourParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameter(mvEnum paramFlag, mvEnum option); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameterf(mvEnum paramFlag, mvFloat num); //< initialised
      mvEnum mvSetCurrentGroupBehaviourParameterv(mvEnum paramFlag, mvFloat* array);  //< initialised
      **/

      mvEnum mvSetGroupBehaviourParameter(mvIndex gbIndex, mvIndex groupIndex, mvEnum paramFlag, mvEnum option);
      mvEnum mvSetGroupBehaviourParameteri(mvIndex gbIndex, mvIndex groupIndex, mvEnum paramFlag, mvIndex option);
      mvEnum mvSetGroupBehaviourParameterf(mvIndex gbIndex, mvIndex groupIndex, mvEnum paramFlag, mvFloat num);
      mvEnum mvSetGroupBehaviourParameterv(mvIndex gbIndex, mvIndex groupIndex, mvEnum paramFlag, mvFloat* array);

      mvEnum mvSetCurrentGroupBehaviourParameter(mvIndex groupIndex, mvEnum paramFlag, mvEnum option);
      mvEnum mvSetCurrentGroupBehaviourParameteri(mvIndex groupIndex, mvEnum paramFlag, mvIndex option);
      mvEnum mvSetCurrentGroupBehaviourParameterf(mvIndex groupIndex, mvEnum paramFlag, mvFloat num);
      mvEnum mvSetCurrentGroupBehaviourParameterv(mvIndex groupIndex, mvEnum paramFlag, mvFloat* array);

      mvEnum mvInsertGroupIntoGroupBehaviour(mvIndex groupIndex, mvIndex groupBehaviour);
      mvEnum mvInsertCurrentGroupIntoGroupBehaviour(mvIndex groupBehaviour);
      mvEnum mvInsertGroupIntoCurrentGroupBehaviour(mvIndex groupIndex);
      mvEnum mvInsertCurrentGroupIntoCurrentGroupBehaviour();


      void mvWorldStep(mvFloat timeInSecs); //< initialised
      mvIndex mvNudgeBody(mvIndex index, mvFloat timeInSecs);
      void mvApplyToAllBodies(void (someFunction)(mvBody*,void*),void* extraPtr);
      void mvApplyToAllObstacles(void (someFunction)(mvObstacle*,void*),void* extraPtr);
      void mvApplyToAllWaypoints(void (someFunction)(mvWaypoint*,void*),void* extraPtr);

      mvEnum mvSetDefaultWaypointForBody(mvIndex waypointIndex, mvIndex bodyIndex);  //< initialised
      mvEnum mvSetDefaultPathwayForBody(mvIndex pathwayIndex, mvIndex bodyIndex);  //< initialised
      mvEnum mvSetDefaultBodyForBody(mvIndex targetIndex,mvIndex bodyIndex); //< initialised
      mvEnum mvSetDefaultBehaviourFactorForBody(mvFloat factor, mvIndex bodyIndex); //< initialised

      mvEnum mvSetDefaultWaypointForCurrentBody(mvIndex wpIndex); //< initialised
      mvEnum mvSetDefaultPathwayForCurrentBody(mvIndex pwIndex);  //< initialised
      mvEnum mvSetDefaultBodyForCurrentBody(mvIndex bodyIndex); //< initialised
      mvEnum mvSetDefaultBehaviourFactorForCurrentBody(mvFloat factor); //< initialised

      mvEnum mvAddBehaviourToBody(mvIndex bodyIndex, mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);//< initialised
      mvEnum mvAddBehaviourToCurrentBody(mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);//< initialised

      mvEnum mvSetBehaviourParameteri(mvIndex behaviourIndex,mvEnum paramFlag, mvIndex index);  //< initialised
      mvEnum mvSetCurrentBehaviourParameteri(mvEnum paramFlag, mvIndex index);  //< initialised
};

#endif

