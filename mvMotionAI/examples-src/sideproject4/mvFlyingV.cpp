#include "mvFlyingV.h"
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
bool mvFlyingV::groupOp(mvGroupBehaviourResultPtr result)
{
	if (result == MV_NULL)
		return false;



	return false;
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

	return true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFlyingV::~mvFlyingV()
{

}

