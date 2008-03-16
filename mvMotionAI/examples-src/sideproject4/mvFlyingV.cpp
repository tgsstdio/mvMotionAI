#include "mvFlyingV.h"
#include <iostream>
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFlyingV::mvFlyingV()
	: mvBaseAction(MV_VEHICLE)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvFlyingV::groupOp(mvGroupBehaviourResult* result)
{
	mvWorldPtr currentWorld = MV_NULL;
	mvBaseActionPtr actionDataPtr = MV_NULL;
	mvFlyingV* flyData = MV_NULL;
	mvIndex leaderNode = MV_NULL;
	mvBodyPtr currentBody = MV_NULL;
	mvBodyPtr targetBody = MV_NULL;
	mvVec3 totalVelocity;

	if (result == MV_NULL)
	{
		return false;
	}

	if (!result->areWorldAndMemberListValid())
	{
		// quick exit
		return false;
	}

	currentWorld = result->getWorldPtr();

	result->toFirstMember();
	while (!result->isAtEndOfMemberList())
	{
		currentBody = result->getCurrentMemberAsBodyPtr();
		if (currentBody != MV_NULL)
		{
			actionDataPtr = result->getCurrentMemberActionDataPtr();

			// checking it has the same type
			if (actionDataPtr != MV_NULL)
			{
				if (actionDataPtr->getType() == getType())
				{

					flyData = (mvFlyingV*) actionDataPtr;

					leaderNode = flyData->parentNode;

					// only bodies that following a parent are calculated
					if (leaderNode != MV_NULL)
					{
						targetBody = currentWorld->getBodyPtr(leaderNode);

						totalVelocity = targetBody->getPosition();
						totalVelocity += flyData->offsetPosition;

						flyData->finalVelocity = currentBody->getPosition();
						flyData->finalVelocity -= totalVelocity;
					}
				}
			}
		}
		result->toNextMember();
	}

	return true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvFlyingV::bodyOp(mvBehaviourResultPtr result)
{
	if (result == MV_NULL)
	{
		return false;
	}

	result->setVelocity(finalVelocity, MV_DIRECTIONAL_MOTION, MV_GLOBAL_EFFECT);
	std::cout << "Flying after : "  << parentNode<< std::endl;
	return true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFlyingV::~mvFlyingV()
{

}

/** @brief setParameterv
  *
  * @todo: document this function
  */
mvErrorEnum mvFlyingV::setParameterv(mvParamEnum param, mvFloat* array)
{
	mvErrorEnum error = mvBaseAction::setParameterv(param, array);

	if (error != getNotFoundEnum())
	{
		return error;
	}

	if (param == MV_POSITION)
	{
		offsetPosition.set(array[0], array[1], array[2]);
		return MV_NO_ERROR;
	}
	else
	{
		return getNotFoundEnum();
	}
}

/** @brief getParameterv
  *
  * @todo: document this function
  */
mvErrorEnum mvFlyingV::getParameterv(mvParamEnum param, mvFloat* array,\
	mvCount* noOfParameters) const
{
	mvErrorEnum error = mvBaseAction::getParameterv(param, array,\
		noOfParameters);

	if (error != getNotFoundEnum())
	{
		return error;
	}

	if (param == MV_POSITION)
	{
		offsetPosition.extractVecToArray(array);
		return MV_NO_ERROR;
	}
	else if (param == MV_FINAL_VELOCITY)
	{
		finalVelocity.extractVecToArray(array);
		return MV_NO_ERROR;
	}
	else
	{
		return getNotFoundEnum();
	}


}

/** @brief setParameteri
  *
  * @todo: document this function
  */
mvErrorEnum mvFlyingV::setParameteri(mvParamEnum param, mvIndex inputIndex)
{
	mvErrorEnum error = mvBaseAction::setParameteri(param, inputIndex);

	if (error != getNotFoundEnum())
	{
		return error;
	}

	if (param == MV_INDEX)
	{
		parentNode = inputIndex;
		return MV_NO_ERROR;
	}
	else
	{
		return getNotFoundEnum();
	}

}

/** @brief getParameteri
  *
  * @todo: document this function
  */
mvErrorEnum mvFlyingV::getParameteri(mvParamEnum param, mvIndex* outIndex) const
{
	mvErrorEnum error = mvBaseAction::getParameteri(param, outIndex);

	if (error != getNotFoundEnum())
	{
		return error;
	}

	if (param == MV_INDEX)
	{
		*outIndex = parentNode;
		return MV_NO_ERROR;
	}
	else
	{
		return getNotFoundEnum();
	}
}

