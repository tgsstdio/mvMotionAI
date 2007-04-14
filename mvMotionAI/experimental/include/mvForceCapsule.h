#ifndef MVFORCECAPSULE_H_INCLUDED
#define MVFORCECAPSULE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_INDEX_SET_HEADER_FILE_H_

class mvForceCapsule
{
   private:
      mvCount noOfWaypointsConnected;

   public:
      mvUniqueSet linkedWaypoints;
      mvForcePtr encappedForce;

      mvForceCapsule(mvForcePtr forcePtr);
      mvErrorEnum addWaypoint(mvIndex index);
      mvErrorEnum removeWaypoint(mvIndex index);
      void clearAll();

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

      ~mvForceCapsule();
};

#endif // MVFORCECAPSULE_H_INCLUDED
