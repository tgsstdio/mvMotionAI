#ifndef MVWAYPOINTCAPSULE_H_INCLUDED
#define MVWAYPOINTCAPSULE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_WAYPOINT_HEADER_FILE_H_

class mvWaypointCapsule
{
   protected:
      mvWaypointPtr waypointPtr;
   public:
      bool containBody;
      mvCount noOfLinkedCapsules;

      mvWaypointCapsule(mvWaypointPtr wPoint);
      mvConstWaypointPtr getConstWaypointPtr() const;
      mvWaypointPtr getWaypointPtr() const;

      bool isLinkedWaypoint() const;
      void resetCapsule();

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      ~mvWaypointCapsule();
};

typedef class mvWaypointCapsule* mvWaypointCapsulePtr;

#endif // MVWAYPOINTCAPSULE_H_INCLUDED
