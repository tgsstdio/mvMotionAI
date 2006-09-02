#ifndef MOTIONAI_MVPATHWAY_H_
#define MOTIONAI_MVPATHWAY_H_
#include <vector>
#include "mvEnum.h"
#include "mvWaypoint.h"
#include "mvMotionAI-Types.h"
//#include "Vec3.h"

/**
 * \file mvPathway.h
 * \class mvPathway
 * \brief a series of points (or waypoints) that which represents a path
 *
 * Log
 *
 *version		date		comments
 *
 *00-01-00     22/5/06     - renamed pathways to mvPathway
 *
 *00-00-03		14/2/06		- declared Pathway class
 *
 *                         - created simple array of waypoints which can be loaded via scripts
 *
 */

class mvPathway
{
   private:
      std::vector<mvWaypoint*> waypoints;
      mvCount noOfWaypoints;

   public:
      mvPathway();
      void addWaypoint(mvWaypoint* pWaypoint);
      mvEnum removeWaypoint(mvWaypoint* pWaypoint);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, float num);
      mvEnum setParameterv(mvEnum paramFlag, float* numArray);
      void removeAllWaypoints();
      ~mvPathway();
};

#endif

