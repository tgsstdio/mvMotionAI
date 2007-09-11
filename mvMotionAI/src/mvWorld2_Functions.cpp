#include "mvWorld2_Functions.h"
#include <iostream>

#define MV_WORLD_V2_FUNCTIONS_DEBUG
#undef MV_WORLD_V2_FUNCTIONS_DEBUG

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_V2_InitialiseCurrentResultObject(mvFinalResultObject* finalResult,
   mvCurrentResultObject* currentResult);

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_V2_SumResultObjects(mvFinalResultObject* summedResult,
   const mvCurrentResultObject& actionResult, mvFloat weight, bool isConfined);

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_V2_InitialiseCurrentResultObject(mvFinalResultObject* finalResult,
   mvCurrentResultObject* currentResult)
{
   // transfer values across
   currentResult->setCurrentTimeStep(finalResult->getTimeStep());
   currentResult->setElaspedSystemTime(finalResult->getElapsedSystemTime());

   currentResult->setPositionPrediction(\
      finalResult->predictPositionOfCurrentBody());
   currentResult->setFinalPositionPrediction(\
      finalResult->predictFinalPositionOfCurrentBody());
   currentResult->setVelocityPrediction(\
      finalResult->predictVelocityOfCurrentBody());
   currentResult->setFinalVelocityPrediction(\
      finalResult->predictFinalVelocityOfCurrentBody());
}

void mvWorld_V2_IntegrateAllBodies(mvBodyCapsulePtr bodyPtr, void* extraPtr)
{
   mvWorld_V2_IntegrateLoopHelper* helpContainer =
      (mvWorld_V2_IntegrateLoopHelper*) extraPtr;
   mvWorldPtr currentWorld = helpContainer->currentWorld;
   mvFloat timeInSecs = helpContainer->timeInSecs;

   currentWorld->integrateBody(bodyPtr,timeInSecs);
}

void mvWorld_V2_InitialCurrentForceResult(mvForceResultPtr finalResult,
   mvForceResultPtr currentResult)
{
   mvWorld_V2_InitialiseCurrentResultObject<mvForceResult, mvForceResult>
      (finalResult, currentResult);
}

void mvWorld_V2_InitialiseCurrentBehavResult(mvBehaviourResultPtr finalResult,\
   mvBehaviourResultPtr currentResult)
{
   mvWorld_V2_InitialiseCurrentResultObject<mvBehaviourResult, mvBehaviourResult>
      (finalResult, currentResult);
}

bool mvWorld_V2_CalculateGlobalForceOnBody(mvBaseForcePtr currentForce,
   mvForceResultPtr currentResult)
{
  // calculate force
   if (currentForce)
   {
      return currentForce->calcFullForces(currentResult);
   }
   else
   {
      return false;
   }
}

bool mvWorld_V2_CalculateLocalForceOnBody(mvForceCapsulePtr fCapsulePtr,
   mvBaseForcePtr currentForce, mvForceResultPtr currentResult,\
   mvUniqueSet& waypointList)
{
   // current force parameters
   // check if any waypoints contain this body from this force's assigned wpoints
   mvConstWorldPtr currentWorld = currentResult->getWorldPtr();
   mvUniqueSet& linkedWaypoints = fCapsulePtr->linkedWaypoints;

   // start loop
   linkedWaypoints.beginLoop();
   while(!linkedWaypoints.isLoopFinished()
   && waypointList.findIndex(\
      currentWorld->convertWaypointIndex(linkedWaypoints.getCurrentIndex())
      )
      == MV_ITEM_NOT_FOUND_IN_LIST)
   {
      linkedWaypoints.nextIndex();
   }

   // hopefully ends correctly
   if (linkedWaypoints.isLoopFinished())
   {
      return false;
   }

   // if true for any waypoints
   return currentForce->calcFullForces(currentResult);
}

void mvWorld_V2_CalculateForceOnSingleBody(mvForceCapsulePtr fCapsulePtr,\
   void* extraPtr)
{
   mvBaseForcePtr currentForce = fCapsulePtr->getClassPtr();
   mvWorld_V2_CalcForceHelperStruct* helper =\
      (mvWorld_V2_CalcForceHelperStruct*) extraPtr;
   mvForceStatus forceStatus;

   mvForceResultPtr finalResult = helper->finalResult;
   mvConstWorldPtr currentWorld = helper->currentWorld;
   mvConstBodyPtr currentBody = finalResult->getCurrentBodyPtr();
   // check if enabled.

   if (currentForce->isEnabled() && currentBody->applyAllForces)
   {
      // store
      mvForceResult currentResult(currentWorld, currentBody);
      bool hasCalcForce = true;

      // check this world force filter
      forceStatus.applyingNone();
      currentForce->filter(forceStatus);

      // pre action filter
      // stop force if not to be apply to all bodies
      if (fCapsulePtr->isGlobalForce() && !forceStatus.onlyLocalForce)
      {
         mvWorld_V2_InitialCurrentForceResult(finalResult, &currentResult);
         hasCalcForce = mvWorld_V2_CalculateGlobalForceOnBody(currentForce,\
            &currentResult);
      }
      // continue with local action if not restricted to being global force
      else if (!forceStatus.onlyGlobalForce)
      {
         mvWorld_V2_InitialCurrentForceResult(finalResult, &currentResult);
         hasCalcForce = mvWorld_V2_CalculateLocalForceOnBody(fCapsulePtr,
            currentForce, &currentResult,helper->waypointList);
      }

      if (hasCalcForce)
      {
         // TODO : post calculation filter bool check
         if (!(currentWorld->applyForces && currentBody->applyForces))
         {
            currentResult.disableForce();
         }

         if (!(currentWorld->applyGravity && currentBody->applyGravity))
         {
            currentResult.disableGravity();
         }

         if (!(currentWorld->applyShifts && currentBody->applyShifts))
         {
            currentResult.disableShift();
         }

         if (!(currentWorld->applyAccelerations
               && currentBody->applyAccelerations))
         {
            currentResult.disableAccel();
         }

         // TODO : disable rotations

         if (!(currentWorld->applyAllDragForces
            && currentBody->applyAllDragForces))
         {
            currentResult.disableDragAccel();
            currentResult.disableDragForce();
            currentResult.disableDragShift();
         }

         // sum forces
         mvWorld_V2_SumForceResults(finalResult,currentResult);
      }
    }

}

void mvWorld_V2_ResetWaypointCapsule(mvWaypointCapsulePtr capsulePtr,\
   void* extraPtr)
{
   capsulePtr->containsBody = false;
}

void mvWorld_V2_PrepareBodyCapsule(mvBodyCapsulePtr capsulePtr, void* extraPtr)
{
   capsulePtr->performIntegration = false;
   capsulePtr->futureVelocity.toZeroVec();
   capsulePtr->additionalVelocity.toZeroVec();
   capsulePtr->futureForce.toZeroVec();
   capsulePtr->additionalForce.toZeroVec();
   capsulePtr->futureTorque.toZeroVec();
   capsulePtr->additionalTorque.toZeroVec();
   capsulePtr->futureOmega.toZeroVec();
   capsulePtr->additionalOmega.toZeroVec();
}

void mvWorld_V2_PrepareForceCapsule(mvForceCapsulePtr capsulePtr,\
   void* extraPtr)
{
   //mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   // TODO : prefilter
   capsulePtr->isActive = true;
}

void mvWorld_V2_CalculateEachGroupInGroupBehaviour(mvGroupBehaviourNodePtr currentNode,
   void* extraPtr)
{

   mvWorld_V2_GroupBehaviourNodeHelper* container =
      (mvWorld_V2_GroupBehaviourNodeHelper*) extraPtr;
   mvWorldPtr currentWorld = container->currentWorld;
   mvOptionEnum defaultType = container->gbType;
   mvIndex currentGBehaviour = container->gbIndex;
   bool isEnabled = container->isEnabled;

   mvIndex groupNo = currentNode->getGroup();
   mvGroupPtr currentGroup = currentWorld->getGroupPtr(groupNo);
   if (currentGroup == MV_NULL)
   {
      return;
   }

   bool hasChanged =  currentWorld->hasGroupChanged(groupNo);
   mvBaseActionPtr groupAction = currentNode->getActionPtr();
   mvGroupNodeMemberList& nodeMemberList = currentNode->memberDataList;
   mvGroupMemberNodePtr memberNode = NULL;

   if (hasChanged)
   {
      // add/remove members  in group beh node that be same as group
      currentGroup->setToFirstMember();
      mvIndex lhsSetIndex, rhsMemberIndex;

      mvBaseActionPtr tempMemberActionPtr = NULL;
      nodeMemberList.toFirstMember();
      while (!currentGroup->areMembersFinished() &&
         !nodeMemberList.hasAllNodesBeenVisited() )
      {
         if (nodeMemberList.hasAllNodesBeenVisited())
         {
            // keep adding new nodes to node member list
            lhsSetIndex = currentGroup->getCurrentMember();
            if (currentWorld->getActionLoader() != MV_NULL)
            {
               tempMemberActionPtr =
                  currentWorld->getActionLoader()->createAClassPtr(\
                     defaultType, groupAction);
               nodeMemberList.insertBeforeCurrentMember(lhsSetIndex,tempMemberActionPtr);
               // subscription sent to body
               currentWorld->addBehaviourToList(lhsSetIndex,\
                  MV_EXISTING_GROUP_BEHAVIOUR, currentGBehaviour, groupNo);
            }
            currentGroup->toNextMember();
         }
         else if (currentGroup->areMembersFinished())
         {
            // remove all trailing member nodes
            nodeMemberList.deleteCurrentMember();
         }
         else
         {
            // both sides have still contain items

            memberNode = nodeMemberList.getCurrentMember();
            rhsMemberIndex = memberNode->memberIndex;
            lhsSetIndex = currentGroup->getCurrentMember();

            if (lhsSetIndex > rhsMemberIndex)
            {
               // remove all rhs member nodes preceding node
               nodeMemberList.deleteCurrentMember();
            }
            else if (lhsSetIndex == rhsMemberIndex)
            {
               // skip by incrementing both lhs & rhs
               currentGroup->toNextMember();
               nodeMemberList.toNextMember();
            }
            else // (lhsSetIndex < rhsMemberIndex)
            {
               // insert ahead of position
               if (currentWorld->getActionLoader() != MV_NULL)
               {
                  tempMemberActionPtr =
                     currentWorld->getActionLoader()->createAClassPtr(\
                        defaultType, groupAction);
                  nodeMemberList.insertBeforeCurrentMember(lhsSetIndex,tempMemberActionPtr);
                  // subscription sent to body
                  currentWorld->addBehaviourToList(lhsSetIndex,\
                     MV_EXISTING_GROUP_BEHAVIOUR, currentGBehaviour, groupNo);
               }
               currentGroup->toNextMember();
            }
         }
      }
   }

   nodeMemberList.toFirstMember();
   while (!nodeMemberList.hasAllNodesBeenVisited())
   {
      memberNode = nodeMemberList.getCurrentMember();
   }

   if (groupAction != NULL && isEnabled && currentNode->isEnabled)
   {
      // TODO: perform groupOp
      mvGroupBehaviourResult groupDataModule(currentWorld,\
         &(currentNode->memberDataList));

      groupAction->groupOp(&groupDataModule);
   }
}

void mvWorld_V2_CalculateForEachGroupBehaviour(\
   mvIndex groupBehaviourIndex, void* extraPtr)
{
   // foreach group in group behaviour
   mvWorldPtr currentWorld =  (mvWorldPtr) extraPtr;
   mvWorld_V2_GroupBehaviourNodeHelper container;

   mvGroupBehaviourPtr currentGroupBehav = currentWorld->getGroupBehaviourPtr(\
      groupBehaviourIndex);

   if (currentGroupBehav != MV_NULL)
   {
      mvBaseActionPtr defaultActionPtr =\
         currentGroupBehav->getDefaultActionPtr();

      if (defaultActionPtr != MV_NULL)
      {
         container.gbIndex = groupBehaviourIndex;
         container.currentWorld = currentWorld;
         container.isEnabled = currentGroupBehav->isEnabled;
         const mvOptionEnum nodeType = defaultActionPtr->getType();
         container.gbType = nodeType;
         currentGroupBehav->groupNodeList.applyToAllItems(\
            mvWorld_V2_CalculateEachGroupInGroupBehaviour, &container);
      }
   }
}

mvBaseActionPtr mvWorld_V2_InitialiseResults(mvBEntryPtr nodeInfo, mvIndex bodyIndex,
   mvConstWorldPtr currentWorld,  mvBehaviourResult& currentResult,\
   mvBehaviourResultPtr finalResult)
{
   mvBaseActionPtr currentAction = MV_NULL;
   mvBaseActionPtr groupActionPtr = MV_NULL;
   // isolate result

   if (nodeInfo == MV_NULL)
   {
      return MV_NULL;
   }

   const mvOptionEnum nodeType = nodeInfo->getEntryType();
   mvIndex behaviourIndex = nodeInfo->getBehaviour();
   mvIndex groupIndex = nodeInfo->getGroup();

   mvConstGroupBehaviourPtr globalGrpBehav =\
      currentWorld->getConstGroupBehaviourPtr(behaviourIndex);
   mvConstBehaviourPtr globalBehav =\
      currentWorld->getConstBehaviourPtr(behaviourIndex);
   mvGroupMemberNodePtr memberNodePtr = NULL;
   mvGroupBehaviourNodePtr groupNodePtr = NULL;
   mvConstGroupPtr checkGroupPtr =\
      currentWorld->getConstGroupPtr(groupIndex);

   switch(nodeType)
   {
      case MV_EXISTING_BEHAVIOUR:
         // exit if behaviour does not exist
         if (globalBehav == MV_NULL || !globalBehav->isEnabled())
         {
            return MV_NULL;
         }

         // exit if action does not exist
         currentAction = globalBehav->getActionPtr();
         break;
      case MV_EXISTING_GROUP_BEHAVIOUR:
         // exit if behaviour does not exist
         if (globalGrpBehav == MV_NULL || !globalGrpBehav->isEnabled)
         {
            return MV_NULL;
         }

         // exit if group does not exist
         if (checkGroupPtr == MV_NULL || !checkGroupPtr->isEnabled)
         {
            return MV_NULL;
         }

         // check if group is linked to group behaviour
         groupNodePtr = globalGrpBehav->findGroupNode(groupIndex);

         if (groupNodePtr == MV_NULL || !groupNodePtr->isEnabled)
         {
            return MV_NULL;
         }

         groupActionPtr = groupNodePtr->getActionPtr();
         if (groupActionPtr == MV_NULL)
         {
            return MV_NULL;
         }

         // find member node and action
         memberNodePtr = groupNodePtr->findMemberInNode(\
            bodyIndex);

         if (memberNodePtr == MV_NULL)
         {
            return MV_NULL;
         }

         currentAction = memberNodePtr->getActionPtr();
         break;
      default:
         currentAction = nodeInfo->getActionPtr();
         break;
   }

    // set behaviour result to variables

   currentResult.setGroupBehaviourNode(groupActionPtr);
   currentResult.setBehaviourIndex(behaviourIndex);
   currentResult.setGroupIndex(groupIndex);
   mvWorld_V2_InitialiseCurrentBehavResult(finalResult, &currentResult);

   return currentAction;
}

void mvWorld_V2_ConfineMotionVector(mvParamEnum mType, mvOptionEnum domain,
   mvVec3& motionVector)
{
   switch(mType)
   {
      // straight line
      case MV_VELOCITY:
      case MV_FORCE_VECTOR:
      case MV_ACCELERATION_VECTOR:
      case MV_DIRECTION:
         switch(domain)
         {
            //todo : case MV_ANY_PLANE:
            //todo : case MV_ANY_LINE:
            case MV_X_AXIS_ONLY:
               motionVector.setY(0);
            case MV_XY_PLANE:
               motionVector.setZ(0);
               break;
            case MV_Y_AXIS_ONLY:
               motionVector.setZ(0);
            case MV_YZ_PLANE:
               motionVector.setX(0);
               break;
            case MV_Z_AXIS_ONLY:
               motionVector.setX(0);
            case MV_XZ_PLANE:
               motionVector.setY(0);
               break;
            default:
            case MV_FULL_3D:
               break;
         }
         break;
      // rotation/sphere
      case MV_ROTATION:
      case MV_TORQUE:
      case MV_OMEGA:
         switch(domain)
         {
            //todo :case MV_ANY_PLANE:
            //todo :case MV_ANY_LINE:
            //todo :case MV_X_AXIS_ONLY:
            //todo :case MV_Y_AXIS_ONLY:
            //todo :case MV_Z_AXIS_ONLY:
            case MV_XY_PLANE:
               motionVector.setX(0);
               motionVector.setY(0);
               break;
            case MV_XZ_PLANE:
               motionVector.setX(0);
               motionVector.setZ(0);
               break;
            case MV_YZ_PLANE:
               motionVector.setY(0);
               motionVector.setZ(0);
               break;
            default:
            case MV_FULL_3D:
               break;
         }
         break;
      default:
         break;
   }
}

void mvWorld_V2_SumForceResults(mvForceResultPtr summedResult,
   const mvForceResult& actionResult)
{
   mvWorld_V2_SumResultObjects<mvForceResult, mvForceResult>\
      (summedResult, actionResult, 1, false);

   mvVec3 actionVec, totalVec;
   mvMotionTypeEnum currentMotion;
   mvEffectTypeEnum currentEffect;

   const mvMotionTypeEnum defaultMotion =
      (actionResult.isSteeringMotionDefault()) ?
      MV_STEERING_MOTION : MV_DIRECTIONAL_MOTION;
   const mvEffectTypeEnum defaultEffect =
      (actionResult.isGlobalEffectDefault())  ?
      MV_GLOBAL_EFFECT : MV_LOCAL_EFFECT;

   mvConstBodyPtr currentBody = summedResult->getCurrentBodyPtr();

   if (actionResult.isShiftSet())
   {
      totalVec = summedResult->getShift();
      currentMotion = actionResult.getShiftMotionType();
      currentEffect = actionResult.getShiftEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getShift();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
         actionVec -= currentBody->getFinalVelocity();
      }

      totalVec += actionVec;
      summedResult->setShift(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isGravitySet())
   {
      totalVec = summedResult->getGravity();
      currentMotion = actionResult.getGravityMotionType();
      currentEffect = actionResult.getGravityEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getGravity();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      totalVec += actionVec;
      summedResult->setGravity(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }
}

void mvWorld_V2_SumBehaviourResults(mvBehaviourResultPtr summedResult,
   const mvBehaviourResult& actionResult, mvFloat weight, bool isConfined)
{
   mvWorld_V2_SumResultObjects<mvBehaviourResult, mvBehaviourResult>\
      (summedResult, actionResult, weight, isConfined);

   mvVec3 actionVec, totalVec;
   mvMotionTypeEnum currentMotion;
   mvEffectTypeEnum currentEffect;

   const mvMotionTypeEnum defaultMotion =
      (actionResult.isSteeringMotionDefault()) ?
      MV_STEERING_MOTION : MV_DIRECTIONAL_MOTION;
   const mvEffectTypeEnum defaultEffect =
      (actionResult.isGlobalEffectDefault())  ?
      MV_GLOBAL_EFFECT : MV_LOCAL_EFFECT;

   mvConstBodyPtr currentBody = summedResult->getCurrentBodyPtr();

   if (actionResult.isVelocitySet())
   {
      totalVec = summedResult->getVelocity();
      currentMotion = actionResult.getVelocityMotionType();
      currentEffect = actionResult.getVelocityEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getVelocity();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      totalVec *= weight;
      if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
         actionVec -= currentBody->getFinalVelocity();
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_VELOCITY, currentBody->getDomain(),
            totalVec);
      }


      totalVec += actionVec;
      summedResult->setVelocity(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }
}

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_V2_SumResultObjects(mvFinalResultObject* summedResult,
   const mvCurrentResultObject& actionResult, mvFloat weight, bool isConfined)
{
   mvVec3 actionVec, totalVec;
   mvMotionTypeEnum currentMotion;
   mvEffectTypeEnum currentEffect;

   const mvMotionTypeEnum defaultMotion =
      (actionResult.isSteeringMotionDefault()) ?
      MV_STEERING_MOTION : MV_DIRECTIONAL_MOTION;
   const mvEffectTypeEnum defaultEffect =
      (actionResult.isGlobalEffectDefault())  ?
      MV_GLOBAL_EFFECT : MV_LOCAL_EFFECT;

   mvConstBodyPtr currentBody = summedResult->getCurrentBodyPtr();

   if (currentBody == MV_NULL)
   {
      return;
   }

   // add forces
   if (actionResult.isForceSet())
   {
      totalVec = summedResult->getForce();
      currentMotion = actionResult.getForceMotionType();
      currentEffect = actionResult.getForceEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getForce();
      totalVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }
      // TODO : check if before or after delocal

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_FORCE_VECTOR, currentBody->getDomain(),
            totalVec);
      }

      totalVec += actionVec;
      summedResult->setForce(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isAccelerationSet())
   {
      totalVec = summedResult->getAcceleration();
      currentMotion = actionResult.getAccelerationMotionType();
      currentEffect = actionResult.getAccelerationEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getAcceleration();
      // TODO : check if before or after delocal or confining
      totalVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_ACCELERATION_VECTOR, currentBody->getDomain(),
            totalVec);
      }

      totalVec += actionVec;
      summedResult->setAcceleration(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isTorqueSet())
   {
      totalVec = summedResult->getTorque();
      currentMotion = actionResult.getTorqueMotionType();
      currentEffect = actionResult.getTorqueEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getTorque();
      totalVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_TORQUE, currentBody->getDomain(),
            totalVec);
      }

      totalVec += actionVec;
      summedResult->setTorque(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isDirectionSet())
   {
      //TODO : direction addition/subtraction
   }

   if (actionResult.isOmegaSet())
   {
      //TODO : quaternion addition/subtraction
      totalVec = summedResult->getOmega();
      currentMotion = actionResult.getOmegaMotionType();
      currentEffect = actionResult.getOmegaEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getOmega();
      if(actionResult.isOmegaInDegrees())
      {
         // TODO convert degrees in radains
      }

      totalVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_OMEGA, currentBody->getDomain(),
            totalVec);
      }

      totalVec += actionVec;
      summedResult->setOmegaInRadians(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isQuaternionSet())
   {
      //TODO : quaternion addition/subtraction
   }

   if (actionResult.isRotationSet())
   {
      totalVec = summedResult->getRotation();
      currentMotion = actionResult.getRotationMotionType();
      currentEffect = actionResult.getRotationEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getRotation();

      if(actionResult.isRotationInDegrees())
      {
         // TODO convert degrees in radains
      }

      totalVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
        // actionVec -= currentBody->getRotation();
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_ROTATION, currentBody->getDomain(),
            totalVec);
      }

      totalVec += actionVec;
      summedResult->setRotationInRadians(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }
}

void mvWorld_V2_CalculateEntryByWeightedSum(mvEntryListNodePtr eNodePtr,\
   void* extraPtr)
{
   if (eNodePtr->isEnabled())
   {
      // setting variables
      mvWorld_V2_CalcBehavOnListHelper* helper = (mvWorld_V2_CalcBehavOnListHelper*)\
         extraPtr;
      mvBodyCapsulePtr bCapsule = helper->bCapsule;
      mvBehaviourResultPtr finalResult = helper->finalResult;
      mvConstWorldPtr currentWorld = finalResult->getWorldPtr();

      mvBEntryPtr nodeInfo = eNodePtr->getEntryPtr();
      bool isConfined = eNodePtr->entryFlags.confined;
      mvFloat nodeWeight = eNodePtr->entryFlags.getWeight();

      mvBehaviourResult currentResult(finalResult->getWorldPtr(),
         finalResult->getCurrentBodyPtr());
      mvBaseActionPtr currentAction = mvWorld_V2_InitialiseResults(nodeInfo,\
         bCapsule->bodyIndex, currentWorld, currentResult, finalResult);

      if (currentAction != MV_NULL)
      {
         // calc action
         bool addActionToResult = currentAction->bodyOp(&currentResult);

         if (addActionToResult)
         {
            mvWorld_V2_SumBehaviourResults(finalResult, currentResult,nodeWeight, isConfined);
            bCapsule->performIntegration = true;
         }
      }
   }
}

void mvWorld_V2_CalculateIntegrationOfBody(mvBodyCapsulePtr capsulePtr,
   void *extraPtr)
{
   mvWorld_V2_IntegrateLoopHelper* helperModule =
      (mvWorld_V2_IntegrateLoopHelper*) extraPtr;

   /* Purpose of this is to
    * // MOTION
    * 13. convert all motion to velocity
    * 10. limit the motion by
    *    - body's max speed
    *    - body's max acceleration
    *    - body's max deceleration
    * 6. calc the body's 'own' propulsion velocity
    * 9. create the body's equivalent force
    * 2. sum the mvForces and mvBehaviours together
    * 4. create a final velocity and final force which are
    *     - useful when used separately.
    *     - exactly the same thing in different forms
    * 1. calculate the final position of the body
    * // ROTATION
    * 2. sum the mvForce's rotation and mvBehaviours rotation together
    * 15. calculate body shape's radius
    * 14. convert all circular (motion) to omega
    * 7. calc the body's 'own' prepulsion omega
    * 8. create the body's equivalent torque
    * 5. create the final omega (in degree) and torque of equivalent
    *    value
    * 10. limit the motion by
    *    - body's max turning/rolling/yawing angle
    *    - body's max turning/rolling/yawing omega
    * 3. calculate the final rotation of the body
    */

   // calculate change in velocity = delta_vel
   // accel = delta_vel / time_in_secs
   // force = accel * mass
   // torque = length * force

// TODO : calculate world functions
   mvBodyPtr currentBody = capsulePtr->getClassPtr();

   mvFloat vel[2][3], pos[2][3], c1, c2;
   mvIndex i = 0;

   mvVec3 accelVec, deltaVelocity, bodyVelocity;
   mvFloat hTimeStep = helperModule->timeInSecs;
   mvFloat bodyMass = currentBody->getMass();
   mvVec3 zeroVector;
   mvFloat inverse_h = 1;
   inverse_h /= hTimeStep;

   zeroVector.toZeroVec();

   if (capsulePtr->performIntegration)
   {
      // 13. convert all motion to velocity
      // currently all values are components

      // force => accel
      accelVec = capsulePtr->futureForce;
      accelVec /= bodyMass;

      // TODO : have h, h^2, 1/h, 1/h^2 timesteps
      // deltaVelocity += accel
      accelVec *= hTimeStep;
      deltaVelocity = capsulePtr->futureVelocity;
      deltaVelocity += accelVec;

      mvFloat bodySpeed = currentBody->getSpeed();
      bodyVelocity = currentBody->getVelocity();

      // end velocity
      bodyVelocity += deltaVelocity;
       /* 10. limit the motion by
       *    - body's max speed
       *    - body's max acceleration
       *    - body's max deceleration
       */

      mvFloat incrSpeedDelta = currentBody->getAcceleration();
      incrSpeedDelta *= hTimeStep;

      mvFloat decrSpeedDelta = currentBody->getDeceleration();
      decrSpeedDelta *= hTimeStep;

      mvFloat maxSpeed = currentBody->getMaxSpeed();

      mvFloat minSpeed = 0;

      mvFloat compareSpeed = bodySpeed + incrSpeedDelta;
      if (compareSpeed < maxSpeed)
      {
         maxSpeed = compareSpeed;
      }

      compareSpeed = bodySpeed - decrSpeedDelta;
      if (compareSpeed > minSpeed)
      {
         minSpeed = compareSpeed;
      }

      mvFloat futureSpeed = bodyVelocity.length();
      mvVec3 futureUnitVelocity = bodyVelocity.normalize();

      //compareSpeed = bodySpeed + decrSpeedDelta;
      if (futureSpeed > maxSpeed)
      {
         futureSpeed = maxSpeed;
      }
      else if (futureSpeed < minSpeed)
      {
         futureSpeed = minSpeed;
      }

      //* 6. calc the body's 'own' propulsion velocity
      bodyVelocity = futureUnitVelocity;
      bodyVelocity *= futureSpeed;
      // saving velocity
      deltaVelocity = currentBody->getVelocity();
      // set velocity
      currentBody->setVelocity(bodyVelocity);

      // 9. create the body's equivalent force
      // delta = old_vel - new vel
      // a = delta_vel * 1/h
      accelVec = bodyVelocity;
      accelVec -= deltaVelocity;
      accelVec *= inverse_h;
      accelVec *= bodyMass;
      currentBody->setBodysForce(accelVec);
   }
   else
   {
      // reset force & torque values of body
      //currentBody->setTorque(zeroVector);
      currentBody->setBodysForce(zeroVector);
   }

    /* 4. create a final velocity and final force which are
    *     - useful when used separately.
    *     - exactly the same thing in different forms
    */

   mvVec3 pastVelocity = currentBody->getFinalVelocity();
   /*

   */
   // repeat steps force -> accel -> delta_vel => accel => force
   accelVec = capsulePtr->additionalForce;

   // add bodys' force
   // accel = f / m
   accelVec += currentBody->getBodysForce();
   accelVec /= bodyMass;

   // delta_vel  = a * h
   accelVec *= hTimeStep;
   // accel -> delta_vel
   deltaVelocity = accelVec;
   //deltaVelocity *= hTimeStep;
   // sum velocities to final velocity
   bodyVelocity = currentBody->getVelocity();
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Body Vecel 0: " << bodyVelocity.getX() << " " <<
      bodyVelocity.getY() << " " << bodyVelocity.getZ() << std::endl;
#endif

   bodyVelocity += capsulePtr->additionalVelocity;
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Body Vecel 1: " << bodyVelocity.getX() << " " <<
      bodyVelocity.getY() << " " << bodyVelocity.getZ() << std::endl;
#endif

   bodyVelocity += deltaVelocity;
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Body Vecel 2: " << bodyVelocity.getX() << " " <<
      bodyVelocity.getY() << " " << bodyVelocity.getZ() << std::endl;
#endif
   // store final velocity
   bodyVelocity += pastVelocity;
   currentBody->setFinalVelocity(bodyVelocity);

   // calculating final force
   accelVec = bodyVelocity;
   accelVec -= pastVelocity;
   accelVec *= inverse_h;
   accelVec *= bodyMass;
   currentBody->setFinalForce(accelVec);
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Force Vec : " << accelVec.getX() << " " <<
      accelVec.getY() << " " << accelVec.getZ() << std::endl;
#endif

   bodyVelocity = currentBody->getFinalVelocity();
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Past Vecel : " << pastVelocity.getX() << " " <<
      pastVelocity.getY() << " " << pastVelocity.getZ() << std::endl;
   std::cout << "Body Vecel 3: " << bodyVelocity.getX() << " " <<
      bodyVelocity.getY() << " " << bodyVelocity.getZ() << std::endl;
#endif

   //* 1. calculate the final position of the body
   vel[0][0] = pastVelocity.getX();
   vel[0][1] = pastVelocity.getY();
   vel[0][2] = pastVelocity.getZ();
   vel[1][0] = bodyVelocity.getX();
   vel[1][1] = bodyVelocity.getY();
   vel[1][2] = bodyVelocity.getZ();

   pos[0][0] = currentBody->getPosition().getX();
   pos[0][1] = currentBody->getPosition().getY();
   pos[0][2] = currentBody->getPosition().getZ();

   // TODO : rotation

   for (i = 0; i < 3; i++)
   {
      //vel[0][i] += dir[i] * speed[0];
      //vel[1][i] += dir[i] * speed[1];
      //vel[0][j] *= speed[0];
      //vel[1][j] *= speed[1];

      /*
      * 5.1.2.6.2 calculate the position
      */
      c1 = hTimeStep * vel[0][i];
      c2 = hTimeStep * vel[1][i];
      pos[1][i] =  0.5 * (c1 + c2);
      pos[1][i] += pos[0][i];
   }

   //currentBody->setVelocity(vel[1][0],vel[1][1],vel[1][2]);
   currentBody->setPosition(pos[1][0],pos[1][1],pos[1][2]);
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Current Time : " << helperModule->currentWorld->getElapsedWorldTime()
      << " Time Step : " << hTimeStep << std::endl;
   std::cout << "New Position: " << pos[1][0] << " " <<
      pos[1][1] << " " << pos[1][2] << std::endl;
#endif
}

void mvWorld_V2_FinaliseGroups(mvGroupCapsulePtr capsulePtr, void* extraPtr)
{
   capsulePtr->hasChanged = false;
}

void mvWorldV2_CheckWaypointLocality(mvWaypointCapsulePtr wCapsulePtr,\
   void* extraPtr)
{
   mvWorld_V2_LocalForceCalculationHelper* bodyHelper =
      (mvWorld_V2_LocalForceCalculationHelper*) extraPtr;

   // skip associated waypoints
   if (bodyHelper == MV_NULL || wCapsulePtr == MV_NULL ||
      !wCapsulePtr->isLinkedWaypoint())
   {
      //std::cout << "Skip Local Waypoint Check " << std::endl;
      return;
   }

   // set waypoint variables
   mvConstWaypointPtr currentWaypoint = wCapsulePtr->getConstClassPtr();

   if (currentWaypoint == MV_NULL)
   {
      return;
   }

   mvConstShapePtr currentWpShape = currentWaypoint->getShape();
   mvVec3 wpPos = currentWaypoint->getPosition();
   mvWorld_V2_LocalForceCalculationHelper wpShapeData(bodyHelper->waypointList);

   // invalid type - abort
   if (!mvWorldV2_InitialiseInsideWaypointHelperStruct(wpShapeData,
      currentWpShape,wpPos))
   {
      return;
   }

   // TODO : complete this

   // check aabox - aabox
   bool bodyInsideWaypoint = false;
   if (bodyHelper->bodyShape == MV_AABOX && wpShapeData.bodyShape == MV_AABOX)
   {
      //std::cout << "Box check" << std::endl;
      bodyInsideWaypoint = true;
      for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; ++i)
      {
         if (!mvAABBtoAABB_Collision(bodyHelper,&wpShapeData, i))
         {
            // outside region
           // std::cout << "Outside Box" << std::endl;
            bodyInsideWaypoint = false;
            break;
         }
      }
   }
   // sphere - sphere collisions
   else if (bodyHelper->bodyShape == MV_SPHERE &&\
      wpShapeData.bodyShape == MV_SPHERE)
   {
      bodyInsideWaypoint = mvSpheretoSphere_Colision(bodyHelper->shapePos,
         wpShapeData.shapePos, bodyHelper->bodyRadiusSq,
         wpShapeData.bodyRadiusSq);
   }

   if (bodyInsideWaypoint)
   {
      /*
      std::cout << "Inside Waypoint : " <<
         wCapsulePtr->waypointIndex <<
         " NO : " << wCapsulePtr->noOfLinkedForces << std::endl;
      */
      // if inside, add to list
      bodyHelper->waypointList.addIndex(wCapsulePtr->waypointIndex);
   }
}

bool mvWorldV2_InitialiseInsideWaypointHelperStruct(\
   mvWorld_V2_LocalForceCalculationHelper& helper, mvConstShapePtr shapePtr,
   const mvVec3& currentPosition)
{
   mvFloat tempVariable;
   mvVec3 minValues, maxValues;
   mvFloat bodyRadius, bodyLength;
   mvFloat dimensions[MV_VEC3_NO_OF_COMPONENTS];
   mvCount noOfDimensions;
   mvErrorEnum error;
   const mvFloat* arrayPtr = NULL;


   if (shapePtr == MV_NULL)
   {
      return false;
   }

   // set type flag
   helper.bodyShape = shapePtr->getType();
   helper.shapePos = currentPosition;

   // set empty
   for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; ++i)
   {
      helper.calcDimensions[i] = false;
   }

   if (helper.bodyShape == MV_AABOX)
   {
      error = shapePtr->getParameterv(MV_SHAPE_DIMENSIONS,\
         &dimensions[0], &noOfDimensions);
      if (error == MV_NO_ERROR && noOfDimensions == MV_VEC3_NO_OF_COMPONENTS)
      {
         // copy and fill aabox info
         arrayPtr  = currentPosition.getPointer();
         for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; ++i)
         {
            helper.aabbMaxValues[i] = arrayPtr[i];
            helper.aabbMinValues[i] = arrayPtr[i];
            tempVariable = 0.5;
            tempVariable *= dimensions[i];
            helper.aabbMaxValues[i] += tempVariable;
            helper.aabbMinValues[i] -= tempVariable;
            helper.calcDimensions[i] = true;
         }
      }
      else
      {
         // exit
         return false;
      }
   }
   else if (helper.bodyShape == MV_SPHERE)
   {
      error = shapePtr->getParameterf(MV_RADIUS,&bodyRadius);
      if (error == MV_NO_ERROR)
      {
         helper.bodyRadius = bodyRadius;
         helper.bodyRadiusSq = bodyRadius;
         helper.bodyRadiusSq *= bodyRadius;

         // copy and fill aabox info
         for (int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; ++i)
         {
            helper.calcDimensions[i] = true;
         }
      }
      else
      {
         // exit
         return false;
      }
   }
   else if (helper.bodyShape == MV_X_AXIS_AA_CYLINDER ||
      helper.bodyShape == MV_Y_AXIS_AA_CYLINDER ||
      helper.bodyShape == MV_Z_AXIS_AA_CYLINDER)
   {
      // TODO : fill out cylinder data
      error = shapePtr->getParameterf(MV_RADIUS,&bodyRadius);
      if (error != MV_NO_ERROR)
      {
         return false;
      }

      error = shapePtr->getParameterf(MV_LENGTH,&bodyLength);
      if (error != MV_NO_ERROR)
      {
         return false;
      }

      if (helper.bodyShape == MV_X_AXIS_AA_CYLINDER)
      {
         helper.bodyOddAxisIndex = MV_VEC3_X_COMPONENT;
      }
      else if (helper.bodyShape == MV_Y_AXIS_AA_CYLINDER)
      {
         helper.bodyOddAxisIndex = MV_VEC3_Y_COMPONENT;
      }
      else
      {
         helper.bodyOddAxisIndex = MV_VEC3_Z_COMPONENT;
      }

      arrayPtr = currentPosition.getPointer();
      helper.aabbMaxValues[helper.bodyOddAxisIndex]
         = arrayPtr[helper.bodyOddAxisIndex];
      helper.aabbMinValues[helper.bodyOddAxisIndex]
         = arrayPtr[helper.bodyOddAxisIndex];

      tempVariable = 0.5;
      tempVariable *= bodyLength;
      helper.aabbMinValues[helper.bodyOddAxisIndex] -= tempVariable;
      helper.aabbMaxValues[helper.bodyOddAxisIndex] += tempVariable;

      helper.bodyRadius = bodyRadius;
      helper.bodyRadiusSq = bodyRadius;
      helper.bodyRadiusSq *= bodyRadius;
   }
   else
   {
      // default
      return false;
   }

   return true;
}

void mvWorldV2_RemoveAWaypointFromAllForceCapsules(\
   mvForceCapsulePtr fCapsulePtr, void* extraPtr)
{
   mvIndex* currentWaypoint = (mvIndex*) extraPtr;

   fCapsulePtr->removeWaypoint(*currentWaypoint);
}

bool mvAABBtoAABB_Collision(mvWorld_V2_LocalForceCalculationHelper* firstBox,
   mvWorld_V2_LocalForceCalculationHelper* secondBox, mvIndex componentIndex)
{
   // TODO : internal check removal
   if (firstBox == MV_NULL || secondBox == MV_NULL)
   {
      return false;
   }

   mvFloat firstBoxMin = firstBox->aabbMinValues[componentIndex];
   mvFloat firstBoxMax = firstBox->aabbMaxValues[componentIndex];
   mvFloat secondBoxMin = secondBox->aabbMinValues[componentIndex];
   mvFloat secondBoxMax = secondBox->aabbMaxValues[componentIndex];

   /*
   std::cout << "1stBMin : " << firstBoxMin
      << " 1stBMax : " << firstBoxMax
      << " 2ndBMin : " << secondBoxMin
      << " 2ndBMax  :  " << secondBoxMax << std::endl;
   */

   if (firstBoxMin > secondBoxMax || secondBoxMin > firstBoxMax)
   {
      return false;
   }
   else
   {
      return true;
   }
}

/*
bool SpheretoAABB_Collision(float** aabb_dims, float* sphere_pos, float sphere_radius)
{
  int i;
  float distSq = 0.0f;
  const int minIndex = 0;
  const int maxIndex = 1;
  float delta;

  float radiusSq = sphere_radius;
  radiusSq *= sphere_radius;

  for (i = 0; i < MAX_NO_OF_VECTORS_COMPONENTS; ++i)
  {
    if (sphere_pos[i] > aabb_dims[MV_AABB_MIN_INDEX][i])
    {
      delta = sphere_pos[i];
      delta -= aabb_dims[MV_AABB_MIN_INDEX][i];
      delta *= delta;
      distSq += delta;
    }
    else if (sphere_pos[i] > aabb_dims[MV_AABB_MAX_INDEX][i])
    {
      delta = sphere_pos[i];
      delta -= aabb_dims[MV_AABB_MAX_INDEX][i];
      delta *= delta;
      distSq += delta;
    }
  }
  return (distSq < radiusSq) ? true : false;
}
*/


bool mvSpheretoSphere_Colision(const mvVec3& firstShapePos,
   const mvVec3& secondShapePos, mvFloat firstRadiusSq, mvFloat secondRadiusSq)
{
  mvVec3 diff = secondShapePos;
  diff -= firstShapePos;

  mvFloat totalRadius = firstRadiusSq;
  totalRadius += secondRadiusSq;

  mvFloat distSq = diff.dot(diff);

  return (distSq < totalRadius);
}

mvWorld_V2_LocalForceCalculationHelper::mvWorld_V2_LocalForceCalculationHelper(\
   mvUniqueSet& wList) : waypointList(wList)
{

}

mvWorld_V2_CalcForceHelperStruct::mvWorld_V2_CalcForceHelperStruct(\
   mvUniqueSet& waypointList) : waypointList(waypointList)
{

}

