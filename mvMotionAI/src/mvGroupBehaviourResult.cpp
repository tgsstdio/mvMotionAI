/**
 * \file mvGroupBehaviourResult.cpp
 *
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
#include <mv/mvGroupBehaviourResult.h>

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourResult::mvGroupBehaviourResult(mvWorldPtr currentWorld,\
   mvGroupNodeMemberListPtr currentMList)
{
   world = currentWorld;
   groupMemberList = currentMList;
	toFirstMember();
}

bool mvGroupBehaviourResult::areWorldAndMemberListValid() const
{
	return (world != MV_NULL && groupMemberList != NULL);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWorldPtr mvGroupBehaviourResult::getWorldPtr()
{
   return world;
}

bool mvGroupBehaviourResult::isAtEndOfMemberList() const
{
	if (groupMemberList == MV_NULL)
	{
		return true;
	}

	return groupMemberList->hasAllNodesBeenVisited();
}

void mvGroupBehaviourResult::toFirstMember()
{
	if (groupMemberList)
	{
		groupMemberList->toFirstMember();
	}
}

void mvGroupBehaviourResult::toNextMember()
{
	if (groupMemberList != MV_NULL)
	{
		groupMemberList->toNextMember();
	}
}

mvBodyPtr mvGroupBehaviourResult::getCurrentMemberAsBodyPtr() const
{
	mvGroupMemberNodePtr current = MV_NULL;

	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	current = groupMemberList->getCurrentMember();
	if (current == MV_NULL)
	{
		return MV_NULL;
	}

	mvIndex requiredBody = current->getMemberIndex();
	return world->bodies.getClassPtr(requiredBody);
}

mvEntryListNodePtr mvGroupBehaviourResult::getCurrentMemberNodePtr() const
{
	mvGroupMemberNodePtr current = MV_NULL;
	mvEntryListPtr actionList = NULL;
	mvIndex requiredList = MV_NULL;
	mvIndex requiredNode = MV_NULL;

	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	current = groupMemberList->getCurrentMember();

	if (current == MV_NULL)
	{
		return MV_NULL;
	}

	requiredList = current->getMemberIndex();
	requiredNode = current->getEntryNodeIndex();

	actionList = world->entryLists.getClassPtr(requiredList);

	if (actionList == MV_NULL)
	{
		return MV_NULL;
	}

	return actionList->getEntry(requiredNode);
}

mvBaseActionPtr mvGroupBehaviourResult::getCurrentMemberActionDataPtr() const
{
	mvEntryListNodePtr currentNode = getCurrentMemberNodePtr();
	mvEntryPtr memberEntryPtr = MV_NULL;

	if (currentNode == MV_NULL)
	{
		return MV_NULL;
	}

	memberEntryPtr =  currentNode->getEntryPtr();

	if (memberEntryPtr == MV_NULL)
	{
		return MV_NULL;
	}

	return memberEntryPtr->getActionPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupNodeMemberListPtr mvGroupBehaviourResult::getMemberList() const
{
   return groupMemberList;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourResult::~mvGroupBehaviourResult()
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBodyPtr mvGroupBehaviourResult::fetchBodyPtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->bodies.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstaclePtr mvGroupBehaviourResult::fetchObstaclePtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->obstacles.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseForcePtr mvGroupBehaviourResult::fetchForcePtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->forces.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypointPtr mvGroupBehaviourResult::fetchWaypointPtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->waypoints.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupPtr mvGroupBehaviourResult::fetchGroupPtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->groups.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviourPtr mvGroupBehaviourResult::fetchBehaviourPtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->behaviours.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourPtr mvGroupBehaviourResult::fetchGroupBehaviourPtr(mvIndex\
	objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->groupBehaviours.getClassPtr(objIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPathwayPtr mvGroupBehaviourResult::fetchPathwayPtr(mvIndex objIndex) const
{
	if (world == MV_NULL)
	{
		return MV_NULL;
	}

	return world->pathways.getClassPtr(objIndex);
}
