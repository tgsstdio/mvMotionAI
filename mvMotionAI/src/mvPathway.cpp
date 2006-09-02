#include "mvPathway.h"

mvPathway::mvPathway()
{
  noOfWaypoints = 0;
};

mvPathway::~mvPathway()
{
  removeAllWaypoints();
};

/**
 * adds a waypoint to this pathway
 *
 * NOTE:  repetitions are allowed
 */ 
void mvPathway::addWaypoint(mvWaypoint* pWaypoint)
{
  if (pWaypoint != NULL)
     waypoints.push_back(pWaypoint);
};

/**
 * removes the latest instance
 */
mvEnum mvPathway::removeWaypoint(mvWaypoint* pWaypoint)
{
   std::vector<mvWaypoint*>::reverse_iterator i;
   mvWaypoint* currentWaypoint = NULL;

   if (pWaypoint == NULL)
     return MV_FALSE; 

   for (i = waypoints.rbegin(); i != waypoints.rend(); ++i)
   {
     currentWaypoint = *i;
     if (currentWaypoint != NULL && currentWaypoint == pWaypoint)
     {
        *i = NULL;
        return MV_TRUE;
     }
   }
   return MV_FALSE;
};

mvEnum mvPathway::setParameter(mvEnum paramFlag, mvEnum option)
{
   return MV_FALSE;
};

mvEnum mvPathway::setParameterf(mvEnum paramFlag, float num)
{
   return MV_FALSE;
};

mvEnum mvPathway::setParameterv(mvEnum paramFlag, float* numArray)
{
   return MV_FALSE;
};

void mvPathway::removeAllWaypoints()
{
   std::vector<mvWaypoint*>::iterator i;
   mvWaypoint* tempPoint = NULL;

   for (i = waypoints.begin(); i != waypoints.end(); ++i)
   {
      tempPoint = *i;
      if (tempPoint != NULL)
      {
         delete tempPoint;
         *i = NULL;
      }
   }
};
