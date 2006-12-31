#ifndef MV_MOTIONAI_WORLD_H_
#define MV_MOTIONAI_WORLD_H_
#include "mvList.h"

#include "mvForce.h"
#include "mvBody.h"
#include "mvObstacle.h"
#include "mvWaypoint.h"
#include "mvPathway.h"
#include "mvGroup.h"
#include "mvGroupBehaviour.h"
#include "mvBehaviour.h"

// TODO (White 2#1#): implement version two of world

class mvWorld_V2
{
   private:
      char* worldID;
      mvItemList<mvForce> forces;
      mvItemList<mvObstacle> obstacles;
      mvItemList<mvBody> bodies;
      mvItemList<mvWaypoint> waypoints;
      mvItemList<mvPathway> pathways;
      mvItemList<mvGroupBehaviour> groupBehaviours;
      mvItemList<mvBehaviour> behaviours;

   public:
      mvWorld_V2(const char* worldID);
      char* getID() const;
      ~mvWorld_V2();

      // body functions
      mvIndex createBody(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvBody* getBody(mvIndex index);
      mvBody* getCurrentBody();
      mvIndex setCurrentBody(mvIndex index);
      mvErrorEnum deleteCurrentBody();
      mvErrorEnum deleteBody(mvIndex index);
      void deleteAllBodies();
      void applyToAllBodies(void (someFunction)(mvBody*, void*),\
         void* extraPtr);
      void applyToAllBodiesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentBodyParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentBodyParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentBodyParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setBodyParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBodyParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBodyParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentBodyParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBodyParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBodyParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentBodyParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentBodyParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentBodyParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getBodyParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getBodyParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getBodyParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentBodyParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentBodyParametersf(const char* param, mvFloat* num);
      mvErrorEnum getCurrentBodyParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // obstacle functions
      mvIndex createObstacle(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvObstacle* getObstacle(mvIndex index);
      mvObstacle* getCurrentObstacle();
      mvIndex setCurrentObstacle(mvIndex index);
      mvErrorEnum deleteCurrentObstacle();
      mvErrorEnum deleteObstacle(mvIndex index);
      void deleteAllObstacles();
      void applyToAllObstacles(void (someFunction)(mvObstacle*, void*),\
         void* extraPtr);
      void applyToAllObstaclesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentObstacleParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentObstacleParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentObstacleParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setObstacleParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setObstacleParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setObstacleParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentObstacleParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentObstacleParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentObstacleParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getObstacleParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getObstacleParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getObstacleParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentObstacleParameter(mvParamEnum paramFlag,\
       mvOptionEnum* option);
      mvErrorEnum getCurrentObstacleParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentObstacleParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getObstacleParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getObstacleParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getObstacleParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentObstacleParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentObstacleParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentObstacleParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Waypoint functions
      mvIndex createWaypoint(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvWaypoint* getWaypoint(mvIndex index);
      mvWaypoint* getCurrentWaypoint();
      mvIndex setCurrentWaypoint(mvIndex index);
      mvErrorEnum deleteCurrentWaypoint();
      mvErrorEnum deleteWaypoint(mvIndex index);
      void deleteAllWaypoints();
      void applyToAllWaypoints(void (someFunction)(mvWaypoint*, void*),\
         void* extraPtr);
      void applyToAllWaypointsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentWaypointParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentWaypointParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentWaypointParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setWaypointParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setWaypointParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setWaypointParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentWaypointParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentWaypointParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentWaypointParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getWaypointParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getWaypointParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getWaypointParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentWaypointParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentWaypointParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentWaypointParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getWaypointParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getWaypointParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getWaypointParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentWaypointParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentWaypointParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentWaypointParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Pathway functions
      mvIndex createPathway(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvPathway* getPathway(mvIndex index);
      mvPathway* getCurrentPathway();
      mvIndex setCurrentPathway(mvIndex index);
      mvErrorEnum deleteCurrentPathway();
      mvErrorEnum deletePathway(mvIndex index);
      void deleteAllPathways();
      void applyToAllPathways(void (someFunction)(mvPathway*, void*),\
         void* extraPtr);
      void applyToAllPathwaysByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentPathwayParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentPathwayParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentPathwayParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setPathwayParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setPathwayParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setPathwayParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentPathwayParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentPathwayParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentPathwayParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getPathwayParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getPathwayParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getPathwayParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentPathwayParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentPathwayParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentPathwayParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getPathwayParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getPathwayParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getPathwayParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentPathwayParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentPathwayParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentPathwayParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Behaviour functions
      mvIndex createBehaviour(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvBehaviour* getBehaviour(mvIndex index);
      mvBehaviour* getCurrentBehaviour();
      mvIndex setCurrentBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentBehaviour();
      mvErrorEnum deleteBehaviour(mvIndex index);
      void deleteAllBehaviours();
      void applyToAllBehaviours(void (someFunction)(mvBehaviour*, void*),\
         void* extraPtr);
      void applyToAllBehavioursByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array);
      mvErrorEnum setCurrentBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setBehaviourParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setBehaviourParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setBehaviourParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentBehaviourParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentBehaviourParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentBehaviourParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getBehaviourParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getBehaviourParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getBehaviourParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentBehaviourParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentBehaviourParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentBehaviourParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Group functions
      mvIndex createGroup(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z);
      mvGroup* getGroup(mvIndex index);
      mvGroup* getCurrentGroup();
      mvIndex setCurrentGroup(mvIndex index);
      mvErrorEnum deleteCurrentGroup();
      mvErrorEnum deleteGroup(mvIndex index);
      void deleteAllGroups();
      void applyToAllGroups(void (someFunction)(mvGroup*, void*),\
         void* extraPtr);
      void applyToAllGroupsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentGroupParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentGroupParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentGroupParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setGroupParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setGroupParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentGroupParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentGroupParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentGroupParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getGroupParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getGroupParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentGroupParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentGroupParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentGroupParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getGroupParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getGroupParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getGroupParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentGroupParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentGroupParametersf(const char* param, mvFloat* num);
      mvErrorEnum getCurrentGroupParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // GroupBehaviour functions
      mvIndex createGroupBehaviour(mvOptionEnum type);
      mvGroupBehaviour* getGroupBehaviour(mvIndex index);
      mvGroupBehaviour* getCurrentGroupBehaviour();
      mvIndex setCurrentGroupBehaviour(mvIndex index);
      mvErrorEnum deleteCurrentGroupBehaviour();
      mvErrorEnum deleteGroupBehaviour(mvIndex index);
      void deleteAllGroupBehaviours();
      void applyToAllGroupBehaviours(\
         void (someFunction)(mvGroupBehaviour*, void*), void* extraPtr);
      void applyToAllGroupBehavioursByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setGroupBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array);
      mvErrorEnum setCurrentGroupBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentGroupBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentGroupBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setGroupBehaviourParameters(mvIndex index,\
         const char* param, const char* option);
      mvErrorEnum setGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat num);
      mvErrorEnum setGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array);
      mvErrorEnum setCurrentGroupBehaviourParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentGroupBehaviourParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentGroupBehaviourParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getGroupBehaviourParameter(mvIndex index,\
         mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getGroupBehaviourParameterf(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getGroupBehaviourParameterv(mvIndex index,\
         mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentGroupBehaviourParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentGroupBehaviourParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentGroupBehaviourParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getGroupBehaviourParameters(mvIndex index,\
         const char* param, const char** option);
      mvErrorEnum getGroupBehaviourParametersf(mvIndex index,\
         const char* param, mvFloat* num);
      mvErrorEnum getGroupBehaviourParametersv(mvIndex index,\
         const char* param, mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentGroupBehaviourParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentGroupBehaviourParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentGroupBehaviourParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      // Force functions
      mvIndex createForce(mvOptionEnum fType);
      mvForce* getForce(mvIndex index);
      mvForce* getCurrentForce();
      mvIndex setCurrentForce(mvIndex index);
      mvErrorEnum deleteCurrentForce();
      mvErrorEnum deleteForce(mvIndex index);
      void deleteAllForces();
      void applyToAllForces(void (someFunction)(mvForce*, void*),\
         void* extraPtr);
      void applyToAllForcesByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);
      mvErrorEnum setCurrentForceParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentForceParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentForceParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setForceParameters(mvIndex index, const char* param,\
         const char* option);
      mvErrorEnum setForceParametersf(mvIndex index, const char* param,\
         mvFloat num);
      mvErrorEnum setForceParametersv(mvIndex index, const char* param,\
         mvFloat* array);
      mvErrorEnum setCurrentForceParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentForceParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentForceParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getForceParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getForceParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getForceParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentForceParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentForceParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentForceParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getForceParameters(mvIndex index, const char* param,\
         const char** option);
      mvErrorEnum getForceParametersf(mvIndex index, const char* param,\
         mvFloat* num);
      mvErrorEnum getForceParametersv(mvIndex index, const char* param,\
         mvFloat* array, mvCount* noOfParameters);
      mvErrorEnum getCurrentForceParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentForceParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentForceParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);
};

#endif
