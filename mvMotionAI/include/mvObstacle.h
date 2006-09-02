#ifndef MOTIONAI_MVOBSTACLE_H_
#define MOTIONAI_MVOBSTACLE_H_
#include "mvEnum.h"
//#include "Vec3.h"
#include "mvVec3.h"
#include "mvMotionAI-Types.h"

/**
 * \file mvObstacle.h,mvObstacle.cpp
 * \class mvObstacle
 * \brief immoveable objects that are avoided.
 *
 *Log
 *
 *version     date     comments
 *00-01-05   23/8/06    - replaces Vec3 with mvVec3, types declared as
 *                      either mvFloat, mvIndex, mvCount.
 *
 *00-01-00   22/5/06    - renamed Obstacles into mvObstacle
 *
 *00-00-05    4/3/06    - introducing shapes in obstacle
 *
 *00-00-02    8/2/06    - separated obstacle and vehicle into their own
 *                     header and source files
 */

class mvObstacle
{
   private:
      mvEnum initialiseShapeDimensions(mvEnum shape);
      mvEnum checkValidState(mvEnum oState);
      mvVec3 position; /**< Global position in world */
      mvFloat* dimensions;
      mvEnum state;
      mvEnum obstacleType;
   public:
      //mvObstacle();
      //mvObstacle(mvEnum oType);
      mvObstacle(mvEnum oType, mvEnum oState);
      mvObstacle(mvEnum oType, mvEnum oState,mvFloat x, mvFloat y, mvFloat z);
      mvEnum getType() const;
      mvCount getNoOfDimensions() const;
      void setPosition(mvFloat x, mvFloat y, mvFloat z);
      mvEnum getState() const;
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      ~mvObstacle();
};

#endif

