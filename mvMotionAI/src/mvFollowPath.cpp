#include <mv/mvFollowPath.h>
#include MV_MOTIONAI_UTILITIES_HEADER_FILE_H_

mvFollowPath::mvFollowPath()
 : mvBaseAction(MV_FOLLOW_PATH), m_pathwayIndex(MV_NULL),\
   m_insideNode(MV_NULL), m_lengthSquared(0.1)
{

}

mvErrorEnum mvFollowPath::setParameterf(mvParamEnum param, mvFloat num)
{
   if (param == MV_LENGTH)
   {
      m_lengthSquared = num;
      m_lengthSquared *= num;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

mvErrorEnum mvFollowPath::getParameterf(mvParamEnum param, mvFloat* num) const
{
   mvFloat temp;
   mvErrorEnum error = mvBaseAction::getParameterf(param, num);

   // proceed
   if (error == MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      if (param == MV_LENGTH)
      {
         *num = mvSqrt(m_lengthSquared);
         error = MV_NO_ERROR;
      }
   }
   return error;
}

mvErrorEnum mvFollowPath::setParameteri(mvParamEnum param, mvIndex paramIndex)
{
   if (param == MV_PATHWAY)
   {
      m_pathwayIndex = paramIndex;
      return MV_NO_ERROR;
   }
   else if (param == MV_WAYPOINT)
   {
      m_insideNode = paramIndex;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

mvErrorEnum mvFollowPath::getParameteri(mvParamEnum param, mvIndex* paramIndex)\
   const
{
   mvErrorEnum error = mvBaseAction::getParameteri(param, paramIndex);

   // proceed
   if (error == MV_INVALID_BEHAVIOUR_PARAMETER)
   {
      if (param == MV_PATHWAY)
      {
         *paramIndex = m_pathwayIndex;
         error = MV_NO_ERROR;
      }
      else if (param == MV_WAYPOINT)
      {
         *paramIndex = m_insideNode;
         error = MV_NO_ERROR;
      }
   }
   return error;
}

bool mvFollowPath::groupOp(mvGroupBehaviourResultPtr resultModule)
{
   return false;
}

bool mvFollowPath::bodyOp(mvBehaviourResultPtr resultModule)
{
   // taken from mvSeek.cpp 2007.
   mvVec3 pos, direction, velocity;

   // 1. check if input/output class pointer is valid
   if (resultModule == MV_NULL)
   {
      // 1.a exit here & apply no operation
      return false;
   }

   // 2. check body pointer is valid
   mvConstBodyPtr bodyPtr = resultModule->getCurrentBodyPtr();
   if (bodyPtr == MV_NULL)
   {
      return false;
   }

   mvConstPathwayPtr pathwayPtr = resultModule->fetchPathwayPtr(m_pathwayIndex);
   if (pathwayPtr == MV_NULL)
   {
      return false;
   }

   // find new node
   if (m_insideNode == MV_NULL)
   {
      m_insideNode = pathwayPtr->getNextNode(m_insideNode);
   }

   // 3. fetch waypoint module from list
   mvConstWaypointPtr point = resultModule->fetchWaypointPtr(m_insideNode);
   if (point == MV_NULL)
   {
      return false;
   }

   pos = bodyPtr->getPosition();
   direction = point->getPosition();
   direction -= pos;

   if (direction.lengthSquared() < m_lengthSquared)
   {
      // preceed to next node next time
      m_insideNode = pathwayPtr->getNextNode(m_insideNode);
   }

   velocity = direction.normalize();
   velocity *= bodyPtr->getMaxSpeed();
   resultModule->setVelocity(velocity);

   // behaviour result is direction (not steering force)
   resultModule->setToDirectional();

   // integration include this operation
   return true;
}

mvFollowPath::~mvFollowPath()
{

}

mvCreatePathFollower::mvCreatePathFollower()
{

}

mvBaseActionPtr mvCreatePathFollower::operator()(mvNewBaseActionInfo& actionInfo)
{
   return new mvFollowPath();
}

mvCreatePathFollower::~mvCreatePathFollower()
{

}
