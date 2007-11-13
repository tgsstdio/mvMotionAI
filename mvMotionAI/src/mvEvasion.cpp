#include <mv/mvEvasion.h>

mvEvasion::mvEvasion() :  mvBaseAction(MV_EVASION), m_wanderRadius(1),\
   m_wanderLength(1), m_pursuingBody(MV_NULL)
{

}

mvEvasion::~mvEvasion()
{

}

mvErrorEnum mvEvasion::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   mvErrorEnum error = mvBaseAction::getParameteri(paramFlag, index);

   if (error == MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      if (paramFlag == MV_BODY)
      {
         *index = m_pursuingBody;
         error = MV_NO_ERROR;
      }
   }
   return error;
}

mvErrorEnum mvEvasion::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   mvErrorEnum error = mvBaseAction::getParameterf(paramFlag, num);

   if (error == MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      if (paramFlag == MV_LENGTH)
      {
         *num = m_wanderLength;
         error = MV_NO_ERROR;
      }
      else if (paramFlag == MV_RADIUS)
      {
         *num = m_wanderRadius;
         error = MV_NO_ERROR;
      }
   }
   return error;
}

mvErrorEnum mvEvasion::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   mvErrorEnum error = MV_INVALID_BEHAVIOUR_PARAMETER;

   if (paramFlag == MV_BODY)
   {
      m_pursuingBody = index;
      error = MV_NO_ERROR;
   }

   return error;
}

mvErrorEnum mvEvasion::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error = MV_INVALID_BEHAVIOUR_PARAMETER;

   if (paramFlag == MV_LENGTH)
   {
      if (num >= 0)
      {
         m_wanderLength = num;
         error = MV_NO_ERROR;
      }
      else
      {
         error = MV_FLOAT_VALUE_IS_NOT_POSITIVE;
      }
   }
   else if (paramFlag == MV_RADIUS)
   {
      if (num >= 0)
      {
         m_wanderRadius = num;
         error = MV_NO_ERROR;
      }
      else
      {
         error = MV_FLOAT_VALUE_IS_NOT_POSITIVE;
      }
   }

   return error;
}

bool mvEvasion::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   return false;
}

bool mvEvasion::bodyOp(mvBehaviourResultPtr resultModule)
{
   /**
    * based off mvPursuit.cpp 2007 & the wander behaviour from
    * SIGGRAPH 2000 article - Steering Behaviours by Robin Green (2000)
    */
   mvVec3 targetDir, randomVelocity, nextPos, velocity, wanderCentre;
   mvFloat period = 0;

   if (resultModule == NULL)
   {
      return false;
   }

   mvConstBodyPtr body = resultModule->getCurrentBodyPtr();
   if (body == MV_NULL)
   {
      return false;
   }

   mvConstBodyPtr target = resultModule->fetchBodyPtr(m_pursuingBody);
   if (target == MV_NULL)
   {
      return false;
   }

   targetDir = body->getPosition();
   targetDir -= target->getPosition();

   //period = targetDir.length();
   //period /= body->getMaxSpeed();

   //nextPos = target->getFinalVelocity();
   //nextPos *= period;
   //nextPos += target->getPosition();

   //targetDir = body->getPosition();
   //targetDir -= nextPos;

   // calculate center of the wander circle
   wanderCentre = targetDir.normalize();
   wanderCentre *= m_wanderLength;

   // random unit vector from wander center
   randomVelocity.randomiseNormal();
   randomVelocity *= m_wanderRadius;

   // resulting vector is direction for evasion
   wanderCentre += randomVelocity;

   velocity = wanderCentre.normalize();
   velocity *= body->getMaxSpeed();

   resultModule->setVelocity(velocity);
   resultModule->setToDirectional();

   return true;
}

mvBaseActionPtr mvCreateEvasions::operator()(mvNewBaseActionInfo& actionInfo)
{
   return new mvEvasion();
}

mvCreateEvasions::mvCreateEvasions()
{

}

mvCreateEvasions::~mvCreateEvasions()
{

}

