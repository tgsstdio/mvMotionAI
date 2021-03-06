#include "mvWorld2_Functions.h"
#include <iostream>

#define MV_WORLD_V2_FUNCTIONS_DEBUG
#undef MV_WORLD_V2_FUNCTIONS_DEBUG

#include MV_BODY_HEADER_FILE_H_
#include MV_MOTIONAI_UTILITIES_HEADER_FILE_H_

// TODO : local conversions
void convertLocalLinearToGlobal(mvVec3& localVec,\
	mvConstBodyPtr currentBody)
{
	mvFloat factor = localVec.getX();
	mvVec3 forward = currentBody->getBodyDirection();

	localVec = forward * factor;
}

void convertLocalRotationalToGlobal(mvVec3& localVec,\
	mvConstBodyPtr currentBody)
{
	//return localVec;
}

#define MV_WORLD_IMPL_DEG_TO_RAD_CONVERSION 0.017453292519943295769236907684886
#define MV_WORLD_IMPL_RAD_TO_DEG_CONVERSION 57.295779513082320876798154817014

void convertRotationIntoRadians(mvVec3& localVec, bool isRotationInDegrees,\
	mvConstBodyPtr currentBody)
{
	mvFloat conversionValue = 1;

	if (isRotationInDegrees)
	{
		conversionValue = (mvFloat) MV_WORLD_IMPL_DEG_TO_RAD_CONVERSION;
	}

	localVec *= conversionValue;
}

void convertLocalTorqueToGlobal(mvVec3& localVec,\
	mvConstBodyPtr currentBody)
{
	//return localVec;
}

void convertLocalQuaternionToGlobal(mvVec3& localVec,\
	mvConstBodyPtr currentBody)
{
	//return localVec;
}

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
   while(!linkedWaypoints.isLoopFinished())
   {
		if (waypointList.containsIndex(\
			currentWorld->convertWaypointIndex(linkedWaypoints.getCurrentIndex())))
		{
			return currentForce->calcFullForces(currentResult);
		}
      linkedWaypoints.nextIndex();
   }

	return false;

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
      bool hasCalcForce = false;

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
      else if (!fCapsulePtr->isGlobalForce())
      {
         mvWorld_V2_InitialCurrentForceResult(finalResult, &currentResult);
         hasCalcForce = mvWorld_V2_CalculateLocalForceOnBody(fCapsulePtr,
            currentForce, &currentResult,helper->waypointList);
      }

      if (hasCalcForce)
      {
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

         puts(mvGetOptionEnumString(currentForce->getType()));
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

   mvVec3 zeroVector;
   zeroVector.toZeroVec();
   capsulePtr->deltaRotation.setEulerAngles(zeroVector);
   capsulePtr->fDeltaRotation.setEulerAngles(zeroVector);
}

void mvWorld_V2_PrepareForceCapsule(mvForceCapsulePtr capsulePtr,\
   void* extraPtr)
{
   //mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   // TODO : prefilter
   capsulePtr->isActive = true;
}

void mvWorld_V2_CalculateEachGroupInGroupBehaviour(\
   mvGroupBehaviourGroupNodePtr currentNode, void* extraPtr)
{
   // TODO : code untested
   mvWorld_V2_GroupBehaviourNodeHelper* container =
      (mvWorld_V2_GroupBehaviourNodeHelper*) extraPtr;

   mvWorldPtr currentWorld = container->currentWorld;
   mvBaseActionPtr groupAction = currentNode->getActionPtr();

   bool isEnabled = container->isEnabled;

	mvWorld_V2_RegisterEachGroupInGroupBehaviour(currentNode, extraPtr);

   if (groupAction != NULL && isEnabled && currentNode->isEnabled)
   {
      // TODO: perform groupOp
      mvGroupBehaviourResult groupDataModule(currentWorld,\
         &(currentNode->memberDataList));

      groupAction->groupOp(&groupDataModule);
   }
}

void mvWorld_V2_RegisterEachGroupInGroupBehaviour(\
	mvGroupBehaviourGroupNodePtr currentNode,	void* extraPtr)
{
   mvWorld_V2_GroupBehaviourNodeHelper* container =
      (mvWorld_V2_GroupBehaviourNodeHelper*) extraPtr;

   mvIndex currentGBehaviour = container->gbIndex;
   mvBaseActionPtr groupAction = currentNode->getActionPtr();
   mvOptionEnum defaultType = container->gbType;
	mvWorldPtr currentWorld = container->currentWorld;
   mvBaseActionPtr mainActionPtr = container->mainGroupActionPtr;

	mvWorldV2_registerGroup(currentWorld, defaultType, currentNode, mainActionPtr,
		groupAction,currentGBehaviour);
}

void mvWorldV2_addNewGroupNodeIntoMemberList(mvWorldPtr currentWorld,
	mvGroupNodeMemberList& nodeMemberList, mvIndex memberIndex,
	mvIndex gbGroupIndex, mvIndex grpBehavIndex, mvBaseActionPtr mainActionPtr,
	mvBaseActionPtr groupAction, mvOptionEnum defaultType, mvActionLoaderListPtr
	worldActionCreator)
{
	mvIndex existingMemberEntryIndex = MV_NULL;
	mvBaseActionPtr memberActionData = MV_NULL;
	mvBaseActionPtr lookupData = MV_NULL;
   mvEntryListPtr currentEntryList = MV_NULL;

	// A1: create new info struct for lookups
	mvNewBaseActionInfo typeLookupInfo(defaultType,
		mvNewBaseActionInfo::MV_GROUP_MEMBER_LOOKUP_OP,
		mainActionPtr, groupAction);
	// A2 : find out typical member node data type for entry list query
	// by 'psuedo' creating a new object

	// NOTE : type of the highest level flag group value
	// used for default group
	lookupData = worldActionCreator->createAClassPtr(\
		defaultType, typeLookupInfo);

	// A3 : retrieve entry list ptr of the new member
	currentEntryList = currentWorld->entryLists.getClassPtr(\
		memberIndex);

	// A4 : if entrylist therefore body doesn't exist
	if (!currentEntryList)
	{
		// exit and don't create.
		return;
	}

	// A4 : query entry list  by type, group id, group list
	existingMemberEntryIndex = currentEntryList->findExistingGroupEntry(
		grpBehavIndex, gbGroupIndex, lookupData->getType());

	// A5 : if not found then
	if (existingMemberEntryIndex == MV_NULL)
	{
		// A5a: create actual info for new member node
		mvNewBaseActionInfo memberInfo(defaultType,
			mvNewBaseActionInfo::MV_NEW_GB_GROUP_MEMBER_OP,
			mainActionPtr, groupAction);

		// A5b: create the action class for new class pointers
		memberActionData = worldActionCreator->createAClassPtr(\
			defaultType, memberInfo);

		// TODO  : check if action are being created.

		// A5c : create new node
		existingMemberEntryIndex =
			currentEntryList->addNewGroupBehaviourMemberNode(\
			grpBehavIndex, gbGroupIndex, memberActionData);
	}

	// A6 : add this node to the list.
	nodeMemberList.insertBeforeCurrentMember(\
		memberIndex,existingMemberEntryIndex);

#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
	std::cout << "Created new object : " << memberIndex << " " << existingMemberEntryIndex << std::endl;
#endif
}

void mvWorldV2_registerGroup(mvWorldPtr currentWorld, mvOptionEnum defaultType,
	mvGroupBehaviourGroupNodePtr currentNode, mvBaseActionPtr mainActionPtr,\
	mvBaseActionPtr groupAction, mvIndex grpBehavIndex)
{
   mvIndex gbGroupIndex = currentNode->getGroup();
   mvGroupPtr currentGroup = currentWorld->groups.getClassPtr(gbGroupIndex);
   if (currentGroup == MV_NULL)
   {
      return;
   }
   bool hasChanged =  currentWorld->hasGroupChanged(gbGroupIndex);
   mvGroupNodeMemberList& nodeMemberList = currentNode->memberDataList;
   mvActionLoaderListPtr worldActionCreator = MV_NULL;
   int count = 0;
   if (!hasChanged)
   {
		return;
   }

	// add/remove members in group beh node that be same as group
	worldActionCreator = currentWorld->getActionLoader();

	if (worldActionCreator == MV_NULL)
	{
		return;
	}

	// iterate over all member in list
	currentGroup->setToFirstMember();
	nodeMemberList.toFirstMember();
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
	std::cout << "Current Group Size : "  << currentGroup->getNoOfMembers() << std::endl;
	//theGBIndex = currentMemberList.getNoOfMembers();
#endif

	while (!currentGroup->areMembersFinished())
	//	!nodeMemberList.hasAllNodesBeenVisited() )
	{
		if (nodeMemberList.hasAllNodesBeenVisited())
		{
			// add extra group members then quit
			while (!currentGroup->areMembersFinished())
			{
				//std::cout << "add new member " << currentGroup->getCurrentMember() << std::endl;

				// A : find existing member data for code
				mvWorldV2_addNewGroupNodeIntoMemberList(currentWorld,
					nodeMemberList, currentGroup->getCurrentMember(),
					gbGroupIndex, grpBehavIndex, mainActionPtr,
					groupAction, defaultType, worldActionCreator);

				// A2 : move to next member of the group
				currentGroup->toNextMember();
			}
			break;
		}
		else
		{
			if (currentGroup->getCurrentMember() >
				nodeMemberList.getCurrentMember()->getMemberIndex())
			{
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
				// delete all preceding non-participating members.
				std::cout << "delete new member" << nodeMemberList.getCurrentMember()->getMemberIndex() << std::endl;
#endif
				nodeMemberList.deleteCurrentMember();

#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
				if (!currentGroup->areMembersFinished())
				{
					std::cout << "Next member" << nodeMemberList.getCurrentMember()->getMemberIndex() << std::endl;
				}
#endif
			}
			else
			{
				if (currentGroup->getCurrentMember() <
					nodeMemberList.getCurrentMember()->getMemberIndex())
				{
					// A : find existing member data for code
					mvWorldV2_addNewGroupNodeIntoMemberList(currentWorld,
						nodeMemberList, currentGroup->getCurrentMember(),
						gbGroupIndex, grpBehavIndex, mainActionPtr,
						groupAction, defaultType, worldActionCreator);
				}
				else
				{
					// if same just move ahead
					nodeMemberList.toNextMember();
				}
				count++;
				currentGroup->toNextMember();
			}
		}
   }

   // delete any trailing members which are not removed
   while (!nodeMemberList.hasAllNodesBeenVisited())
	{
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
		std::cout << "delete members " << nodeMemberList.getCurrentMember()->getMemberIndex() << std::endl;
#endif
		nodeMemberList.deleteCurrentMember();
		// delete member node from member list
	}
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
	std::cout << "GROUP COUNT : " << count << std::endl;
#endif
	count = 0;

	// iterate over update Memeber List
   nodeMemberList.toFirstMember();
   while (!nodeMemberList.hasAllNodesBeenVisited())
   {
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   	//memberNode = nodeMemberList.getCurrentMember();
#endif
		std::cout << "member : " << nodeMemberList.getCurrentMember()->getMemberIndex() << std::endl;
      nodeMemberList.toNextMember();
      count++;
   }
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "COUNT : " << count << std::endl;
#endif
}


void mvWorld_V2_CalculateForEachGroupBehaviour(\
   mvIndex groupBehaviourIndex, void* extraPtr)
{
   // foreach group in group behaviour
   mvWorldPtr currentWorld =  (mvWorldPtr) extraPtr;
   mvWorld_V2_GroupBehaviourNodeHelper container;

   mvGroupBehaviourPtr currentGroupBehav = currentWorld->groupBehaviours.getClassPtr(\
      groupBehaviourIndex);

   if (currentGroupBehav != MV_NULL)
   {
      mvBaseActionPtr defaultActionPtr =\
         currentGroupBehav->getDefaultActionPtr();

      if (defaultActionPtr != MV_NULL)
      {
         container.mainGroupActionPtr = defaultActionPtr;
         container.gbIndex = groupBehaviourIndex;
         container.currentWorld = currentWorld;
         container.isEnabled = currentGroupBehav->isEnabled;
         mvOptionEnum nodeType = defaultActionPtr->getType();
         container.gbType = nodeType;
         currentGroupBehav->groupNodeList.applyToAllItems(\
            mvWorld_V2_CalculateEachGroupInGroupBehaviour, &container);
      }
   }
}

mvBaseActionPtr mvWorld_V2_InitialiseResults(mvEntryPtr nodeInfo, mvIndex bodyIndex,
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

   mvOptionEnum nodeType = nodeInfo->getEntryType();
   mvIndex behaviourIndex = nodeInfo->getBehaviour();
   mvIndex groupIndex = nodeInfo->getGroup();

   mvConstGroupBehaviourPtr globalGrpBehav =\
      currentWorld->groupBehaviours.getConstClassPtr(behaviourIndex);
   mvConstBehaviourPtr globalBehav =\
      currentWorld->behaviours.getConstClassPtr(behaviourIndex);
   mvConstGroupPtr checkGroupPtr =\
      currentWorld->groups.getConstClassPtr(groupIndex);

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
         // todo : MV EXISTING GROUP BEHAVIOUR as using default behaviour

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

         currentAction = globalGrpBehav->getDefaultActionPtr();
         break;
      case MV_GROUP_BEHAVIOUR_MEMBER_ENTRY:
         // exit if behaviour does not exist
         // todo : check if group behaviour node works
         if (globalGrpBehav == MV_NULL || !globalGrpBehav->isEnabled)
         {
            return MV_NULL;
         }

         // exit if group does not exist
         if (checkGroupPtr == MV_NULL || !checkGroupPtr->isEnabled)
         {
            return MV_NULL;
         }

         currentAction = nodeInfo->getActionPtr();
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
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 1" << std::endl;
#endif
               motionVector.setY(0);
               motionVector.setZ(0);
               break;
            case MV_XY_PLANE:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 2 " << std::endl;
#endif
               motionVector.setZ(0);
               break;
            case MV_Y_AXIS_ONLY:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 3 " << std::endl;
#endif
               motionVector.setX(0);
               motionVector.setZ(0);
               break;
            case MV_YZ_PLANE:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 4 " << std::endl;
#endif
               motionVector.setX(0);
               break;
            case MV_Z_AXIS_ONLY:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 5 " << std::endl;
#endif
               motionVector.setX(0);
               motionVector.setY(0);
               break;
            case MV_XZ_PLANE:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 6 " << std::endl;
#endif
               motionVector.setY(0);
               break;
            default:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 7 " << std::endl;
#endif
               break;
            case MV_FULL_3D:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
               std::cout << "velocity confined 8 " << std::endl;
#endif
               break;
         }
         break;
      // rotation/sphere
      case MV_ROTATION:
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
      case MV_TORQUE:
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
         std::cout << "torque confined 8 " << std::endl;
#endif
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
			 convertLocalLinearToGlobal(actionVec,currentBody);
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
			convertLocalLinearToGlobal(actionVec,currentBody);
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
			convertLocalLinearToGlobal(actionVec,currentBody);
      }

      actionVec *= weight;
      if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
         actionVec -= currentBody->getVelocity();
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_VELOCITY, currentBody->getDomain(),
            actionVec);
      }


      totalVec += actionVec;
      summedResult->setVelocity(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }
}

// TODO : refactor into class
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
      actionVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
			convertLocalLinearToGlobal(actionVec,currentBody);
      }
      // TODO : check if before or after delocal

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_FORCE_VECTOR, currentBody->getDomain(),
            actionVec);
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

      actionVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
			convertLocalLinearToGlobal(actionVec,currentBody);
      }

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_ACCELERATION_VECTOR, currentBody->getDomain(),
            actionVec);
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
      actionVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
			convertLocalRotationalToGlobal(actionVec,currentBody);
      }

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_TORQUE, currentBody->getDomain(),
            actionVec);
      }

      totalVec += actionVec;
      summedResult->setTorque(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isDirectionSet())
   {
      //TODO : direction addition/subtraction
      currentMotion = actionResult.getDirectionMotionType();
      currentEffect = actionResult.getDirectionEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

		// TODO: localise - how?
		mvRotationUnit tempAngle(currentBody->getFaceDirection(),\
			actionResult.getDirection());

      mvRotationUnit totalAngle(summedResult->getRotationUnit());
		totalAngle.composeProduct(tempAngle);
      summedResult->setRotationUnit(totalAngle, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
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
		convertRotationIntoRadians(actionVec, actionResult.isOmegaInDegrees(),
			currentBody);

      actionVec *= weight;
      if (currentEffect == MV_LOCAL_EFFECT)
      {
			convertLocalRotationalToGlobal(actionVec,currentBody);
      }
      // TODO : check if before or after delocal or confining

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_OMEGA, currentBody->getDomain(),
            actionVec);
      }

      totalVec += actionVec;
      summedResult->setOmegaInRadians(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isRotationUnitSet())
   {
      currentMotion = actionResult.getRotationUnitMotionType();
      currentEffect = actionResult.getRotationUnitEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      mvRotationUnit actionAngle(actionResult.getRotationUnit());

      // for the moment - default is steering
      mvRotationUnit tempAngle(actionAngle);

      //TODO : localise - how?

      if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
			// TODO : not sure how
			tempAngle.setDelta(currentBody->getRotation(), actionAngle);
      }

      if (isConfined)
      {
			// TODO : not sure how do that -how?
      }

      mvRotationUnit totalAngle(summedResult->getRotationUnit());
		totalAngle.composeProduct(tempAngle);
      summedResult->setRotationUnit(totalAngle, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isRotationSet())
   {
      actionVec = actionResult.getRotation();
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

      actionVec *= weight;
      //TODO : localise - how?
      if (currentEffect == MV_LOCAL_EFFECT)
      {
			convertLocalRotationalToGlobal(actionVec,currentBody);
      }

      if (isConfined)
      {
         mvWorld_V2_ConfineMotionVector(MV_ROTATION, currentBody->getDomain(),
            actionVec);
      }

      mvRotationUnit actionAngle, tempAngle;
      if (actionResult.isRotationInDegrees())
      {
      	actionAngle.setEulerAnglesInDegrees(actionVec);
      }
      else
      {
      	actionAngle.setEulerAngles(actionVec);
      }

		if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
			// TODO : not sure how
			tempAngle.setDelta(currentBody->getRotation(), actionAngle);
      }

      mvRotationUnit totalAngle(summedResult->getRotationUnit());
		totalAngle.composeProduct(tempAngle);
      summedResult->setRotationUnit(totalAngle, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }
}

void mvWorld_V2_CalculateEntryByRandomSum(mvEntryListNodePtr eNodePtr,\
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

      mvEntryPtr nodeInfo = eNodePtr->getEntryPtr();
      bool isConfined = eNodePtr->entryFlags.confined;
      mvFloat minPercentage = eNodePtr->entryFlags.getWeight();

      // create temporary result object
      mvBehaviourResult currentResult(finalResult->getWorldPtr(),
         finalResult->getCurrentBodyPtr());
      mvBaseActionPtr currentAction = mvWorld_V2_InitialiseResults(nodeInfo,\
         bCapsule->bodyIndex, currentWorld, currentResult, finalResult);

      // apply mvBaseAction operator
      if (currentAction != MV_NULL)
      {
      	// negetive weights into positive percentage
      	if (minPercentage < 0)
      	{
				minPercentage *= -1;
      	}

         if (minPercentage > 1)
         {
            minPercentage = mvMax(minPercentage, 1);
         }

         //minPercentage = 1;
         mvFloat randomNumber = mvRandNormalised();

         if (randomNumber <= minPercentage)
         {
            // calc action
            bool addActionToResult = currentAction->bodyOp(&currentResult);
            if (addActionToResult)
            {
					// negetive weights = inverse of direction
            	mvFloat positiveWeight = (eNodePtr->entryFlags.getWeight() >= 0) ? 1 : -1;

               mvWorld_V2_SumBehaviourResults(finalResult, currentResult,positiveWeight,isConfined);
               bCapsule->performIntegration = true;
            }
         }
      }
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

      mvEntryPtr nodeInfo = eNodePtr->getEntryPtr();
      bool isConfined = eNodePtr->entryFlags.confined;
      mvFloat nodeWeight = eNodePtr->entryFlags.getWeight();

      // create temporary result object
      mvBehaviourResult currentResult(finalResult->getWorldPtr(),
         finalResult->getCurrentBodyPtr());
      mvBaseActionPtr currentAction = mvWorld_V2_InitialiseResults(nodeInfo,\
         bCapsule->bodyIndex, currentWorld, currentResult, finalResult);

      // apply mvBaseAction operator
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

void mvWorld_V2_CalculateEntryByRandomWeightSum(mvEntryListNodePtr eNodePtr,\
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

      mvEntryPtr nodeInfo = eNodePtr->getEntryPtr();
      bool isConfined = eNodePtr->entryFlags.confined;
      mvFloat nodeWeight = eNodePtr->entryFlags.getWeight();

      // create temporary result object
      mvBehaviourResult currentResult(finalResult->getWorldPtr(),
         finalResult->getCurrentBodyPtr());
      mvBaseActionPtr currentAction = mvWorld_V2_InitialiseResults(nodeInfo,\
         bCapsule->bodyIndex, currentWorld, currentResult, finalResult);

      // apply mvBaseAction operator
      if (currentAction != MV_NULL)
      {
         // calc action
         bool addActionToResult = currentAction->bodyOp(&currentResult);

         if (addActionToResult)
         {
            mvFloat randomNumber = mvRandNormalised();

            mvWorld_V2_SumBehaviourResults(finalResult, currentResult,\
               randomNumber * nodeWeight, isConfined);
            bCapsule->performIntegration = true;
         }
      }
   }
}


bool mvWorld_V2_FindFirstEntryForXOR(mvEntryListNodePtr eNodePtr,\
   void* extraPtr)
{
   return (eNodePtr->isEnabled());
}

void mvWorld_V2_CalculateEntryByXORSum(mvWorld_V2_CalcBehavOnListHelper*
   helper)
{
   mvEntryListPtr currentEntryList = helper->currentEntryList;
   mvEntryListNodePtr firstEnabledEntry = MV_NULL;

   if (currentEntryList != MV_NULL)
   {
      firstEnabledEntry = currentEntryList->findFirstEntryPtr(
         mvWorld_V2_FindFirstEntryForXOR, &helper);

      if (firstEnabledEntry != MV_NULL)
      {
         mvWorld_V2_CalculateEntryByWeightedSum(firstEnabledEntry, helper);
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

   mvVec3 euler_vel[2], euler_pos[2], euler_accel[2], c1, c2;
  // mvIndex i = 0;

   mvVec3 accelVec, deltaVelocity, bodyVelocity;
	mvRotationUnit totalRotationDelta;
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
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
      std::cout << "Future Speed : " << futureSpeed
         << " Min Speed : " << minSpeed
         << " Max Speed :" << maxSpeed
         << " Final Speed : " << currentBody->getFinalSpeed()
         << std::endl;
#endif

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


		// TODO : omega, rotation, quaternion sum - if bodys rotation test

		// add omega to delta rotation
		mvVec3 bodyOmega = capsulePtr->futureOmega;

		/*
       *  Set Torque
       */
      mvVec3 bodyTorque = capsulePtr->futureTorque;

		// todo : inverse mass matrix -> alpha (rot accel) -> omega (rot vel)

      // turn into delta rotations (euler angles)
		bodyOmega *= hTimeStep;

		// add deltas together
		totalRotationDelta.setEulerAngles(bodyOmega);
		totalRotationDelta.composeProduct(capsulePtr->deltaRotation);

		// TODO : apply roll & yaw limits by rotation then subtraction then inverse again

		bodyOmega = totalRotationDelta.getEulerAngles();
		bodyOmega *= inverse_h;
		//TODO : convert rotation unit format for body
		currentBody->setBodysOmega(bodyOmega);

		// is torque just unit axis vector plus angle


		// todo : omega (rot vel) -> alpha (rot accel) ->  inverse mass matrix

      currentBody->setBodysTorque(bodyTorque);
   }
   else
   {
      // reset force & torque values of body
      currentBody->setVelocity(zeroVector);
      currentBody->setBodysTorque(zeroVector);
      currentBody->setBodysForce(zeroVector);
      currentBody->setBodysOmega(zeroVector);
      totalRotationDelta.setEulerAngles(zeroVector);
   }

    /* 4. create a final velocity and final force which are
    *     - useful when used separately.
    *     - exactly the same thing in different forms
    */

   euler_vel[0] = currentBody->getFinalVelocity();
   euler_accel[0] = currentBody->getFinalForce();
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
   // sum steering velocities to final velocity
   bodyVelocity.toZeroVec();
#ifdef MV_WORLD_V2_FUNCTIONS_DEBUG
   std::cout << "Body Vecel 0: " << bodyVelocity.getX() << " " <<
      bodyVelocity.getY() << " " << bodyVelocity.getZ() << std::endl;
#endif

	// todo : filter force shifts
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
   bodyVelocity += euler_vel[0];
   //currentBody->setFinalVelocity(bodyVelocity);

   // calculating final force
   accelVec = bodyVelocity;
   accelVec -= euler_vel[0];
   accelVec *= inverse_h;
   accelVec *= bodyMass;
   currentBody->setFinalForce(accelVec);

   //* 1. calculate the final velocity of the body

   euler_pos[0] = currentBody->getPosition();

   mvFloat halfATimeStep = hTimeStep * 0.5;
   // TODO : rotation

   // euler_vel[1] += (c1) = euler_accel[0] = pastFinalForce;
   euler_vel[1] = euler_accel[0];
   // euler_vel[1] += c2 = h * euler_accel[1] = currentBody->getFinalForce()
   euler_vel[1] += currentBody->getFinalForce();
   euler_vel[1] /= bodyMass;
   euler_vel[1] *= halfATimeStep;
   euler_vel[1] += euler_vel[0];

   /*
   * 5.1.2.6.2 calculate the position
   */
   euler_pos[1] = euler_vel[0];  // c1 = hTimeStep * euler_vel[0];
   euler_pos[1] += euler_vel[1]; //c2 = hTimeStep * euler_vel[1];
   euler_pos[1] *= halfATimeStep;
   euler_pos[1] += euler_pos[0];

   /*
    * ROTATION :
    * set torque
    * TODO : omega, rotation, quaternion sum
    */

	// add omega to delta rotation
	mvVec3 finalOmega = capsulePtr->additionalOmega;

	/*
	 *  Set Torque
	 */
   mvVec3 totalTorque = currentBody->getBodysTorque();
   totalTorque += capsulePtr->additionalTorque;

	// todo : inverse mass matrix -> alpha (rot accel) -> omega (rot vel)

	// turn into delta rotations (euler angles)
	finalOmega *= hTimeStep;

	// add deltas together
	mvRotationUnit finalRotation;
	finalRotation.setEulerAngles(finalOmega);

	totalRotationDelta.composeProduct(finalRotation);
	totalRotationDelta.composeProduct(capsulePtr->fDeltaRotation);

	// TODO : apply roll & yaw limits by rotation then subtraction then inverse again

	finalOmega = totalRotationDelta.getEulerAngles();
	finalOmega *= inverse_h;

	//TODO : convert rotation unit format for body
	currentBody->setFinalOmega(finalOmega);

	// todo : omega (rot vel) -> alpha (rot accel) ->  mass matrix -> final torque

	finalRotation = currentBody->getRotation();
	finalRotation.composeProduct(totalRotationDelta);

	currentBody->setRotation(finalRotation);
   currentBody->setFinalTorque(totalTorque);
   currentBody->setFinalVelocity(euler_vel[1]);
   currentBody->setPosition(euler_pos[1]);
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
   const mvFloat* posArray = MV_NULL;
   mvFloat tempArray[MV_VEC3_NO_OF_COMPONENTS];
   mvWorld_V2_LocalForceCalculationHelper* sphereHelperPtr = MV_NULL;
   mvWorld_V2_LocalForceCalculationHelper* aaboxHelperPtr = MV_NULL;
   mvFloat radiusSq = 0;
   mvFloat totalDiff = 0;

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
   else if ((bodyHelper->bodyShape == MV_AABOX &&
      wpShapeData.bodyShape == MV_SPHERE) ||
      (bodyHelper->bodyShape == MV_SPHERE &&
         wpShapeData.bodyShape == MV_AABOX))
   {
      // sphere is on right
      if (bodyHelper->bodyShape == MV_AABOX)
      {
         sphereHelperPtr = &wpShapeData;
         aaboxHelperPtr = bodyHelper;
      }
      else
      {
         sphereHelperPtr = bodyHelper;
         aaboxHelperPtr = &wpShapeData;
      }

      posArray = sphereHelperPtr->shapePos.getPointer();
      if (posArray == MV_NULL)
		{
			sphereHelperPtr->shapePos.extractVecToArray(tempArray);
			posArray = &tempArray[0];
		}
      radiusSq = sphereHelperPtr->bodyRadiusSq;

      totalDiff = 0;

      for(int i = 0; i < MV_VEC3_NO_OF_COMPONENTS; i++)
      {
         totalDiff += mvWorldV2_SpheretoAABB_GetCollisionDistFromPoint(posArray[i],
            aaboxHelperPtr, i);
      }

      bodyInsideWaypoint = (totalDiff < radiusSq);
   }


   if (bodyInsideWaypoint)
   {
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
   mvFloat tempArray[MV_VEC3_NO_OF_COMPONENTS];
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
         if (arrayPtr)
         {
				currentPosition.extractVecToArray(tempArray);
				arrayPtr = &tempArray[0];
			}
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
		if (arrayPtr)
		{
			currentPosition.extractVecToArray(tempArray);
			arrayPtr = &tempArray[0];
		}
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

mvFloat mvWorldV2_SpheretoAABB_GetCollisionDistFromPoint(mvFloat firstBoxPosComponent,
   mvWorld_V2_LocalForceCalculationHelper* secondBox, mvIndex componentIndex)
{
   mvFloat delta = 0;

   mvFloat secondBoxMin = secondBox->aabbMinValues[componentIndex];
   mvFloat secondBoxMax = secondBox->aabbMaxValues[componentIndex];

   if (firstBoxPosComponent < secondBoxMin)
      //aabb_dims[MV_AABB_MIN_INDEX][i])
   {
      delta = firstBoxPosComponent;
      delta -= secondBoxMin;
      delta *= delta;
   }
   else if (firstBoxPosComponent > secondBoxMax)
   // (sphere_pos[i] > aabb_dims[MV_AABB_MAX_INDEX][i])
   {
      delta = firstBoxPosComponent;
      delta -= secondBoxMax;
      delta *= delta;
   }

   return delta;
}

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

void mvWorld_V2_RegisterEachGroupBehaviour(mvIndex itemIndex, void* extraPtr)
{
   mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   currentWorld->registerGroupBehaviourToBodies(itemIndex);
}
