#ifndef MOTIONAI_MVWAYPOINT_H_
#define MOTIONAI_MVWAYPOINT_H_
#include <vector>
//#include "Vec3.h"
#include "mvMotionAI-Types.h"
#include "mvVec3.h"
#include "mvEnum.h"
//#include "mvGroup.h"
#include "mvForce.h"

/**
 * \file mvWaypoint.h
 * \class mvWaypoint
 * \brief Immediate class between Motion AI objects and gloabl world points
 * 
 * Log
 *
 * Version		Date		Comments
 *
 * 00-01-02  31/5/06  - removing groups from system until better solution
 *                     arrives.
 *
 * 00-01-00   16/5/06      - renamed target to mvWaypoint.
 *
 * 00-00-07		9/3/06		- initialised Target Object,
 */

class mvWaypoint
{
   private:      
      mvEnum initialisePoints(mvEnum type);
      mvEnum initialiseShapeDimensions(mvEnum shape);
      //mvGroup* groupPtr;
      mvVec3* points;
      //mvCount noOfPoints;
      mvEnum wayPointType;
      mvEnum wayPointShape;
      mvFloat* dimensions;
      std::vector<mvForce*> forceList;
      mvCount noOfForces;

   public:
      //mvWaypoint();
      //mvWaypoint(mvEnum targetType);
      mvWaypoint(mvEnum targetType, mvEnum targetShape);
      mvWaypoint(mvEnum targetType, mvEnum targetShape, mvFloat x, mvFloat y, mvFloat z);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      mvEnum addForce(mvForce* forcePtr);
      mvEnum removeForce(mvForce* forcePtr);
      void removeAllForces();
      mvCount getNoOfForces() const;
      mvCount getNoOfPoints() const;
      mvCount getNoOfDimensions() const;
      //void setGroup(mvGroup* wpGroup);      
      mvEnum getType();
      mvEnum getShape();
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;      
      ~mvWaypoint();
};

#endif

