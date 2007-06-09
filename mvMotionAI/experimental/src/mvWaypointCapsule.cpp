#include "mvWaypointCapsule.h"

mvWaypointCapsule::mvWaypointCapsule(mvWaypointPtr wPoint)
{
   encappedWaypoint = wPoint;
   noOfLinkedForces = 0;
   containsBody = false;
}

mvConstWaypointPtr mvWaypointCapsule::getConstClassPtr() const
{
   return (mvConstWaypointPtr) encappedWaypoint;
}

mvWaypointPtr mvWaypointCapsule::getClassPtr() const
{
   return encappedWaypoint;
}

bool mvWaypointCapsule::isLinkedWaypoint() const
{
   return (noOfLinkedForces <= 0);
}

void mvWaypointCapsule::resetCapsule()
{
   containsBody = false;
}

void mvWaypointCapsule::incrementCount()
{
   ++noOfLinkedForces;
}

void mvWaypointCapsule::decrementCount()
{
   if (noOfLinkedForces > 0)
   {
      --noOfLinkedForces;
   }
}

mvErrorEnum mvWaypointCapsule::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->getParameteri(paramFlag, index);
}

mvErrorEnum mvWaypointCapsule::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->getParameter(paramFlag, option);
}

mvErrorEnum mvWaypointCapsule::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->getParameterf(paramFlag, num);
}

mvErrorEnum mvWaypointCapsule::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->getParameterv(paramFlag,\
      numArray, noOfParameters);
}

mvErrorEnum mvWaypointCapsule::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->setParameteri(paramFlag, index);
}
mvErrorEnum mvWaypointCapsule::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->setParameter(paramFlag,option);
}

mvErrorEnum mvWaypointCapsule::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->setParameterf(paramFlag, num);
}

mvErrorEnum mvWaypointCapsule::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (encappedWaypoint == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedWaypoint->setParameterv(paramFlag,numArray);
}

mvWaypointCapsule::~mvWaypointCapsule()
{
   if (encappedWaypoint != MV_NULL)
   {
      delete encappedWaypoint;
      encappedWaypoint = MV_NULL;
   }
}
