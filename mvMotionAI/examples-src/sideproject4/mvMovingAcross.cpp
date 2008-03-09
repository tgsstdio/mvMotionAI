#include "mvMovingAcross.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvMovingAcross::mvMovingAcross()
 : mvBaseAction(MV_PARTICLE)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvMovingAcross::groupOp(mvGroupBehaviourResult* result)
{
	return false;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvMovingAcross::bodyOp(mvBehaviourResult* result)
{
	bool toIntegrate = false;
	if (result != MV_NULL)
	{
		result->setVelocity(mvVec3(1,0,0), MV_STEERING_MOTION, MV_GLOBAL_EFFECT);

		toIntegrate = true;
	}
	return toIntegrate;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvMovingAcross::~mvMovingAcross()
{

}

