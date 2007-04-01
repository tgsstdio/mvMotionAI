#include "mvObstacle_V2.h"

mvObstacle_V2::mvObstacle_V2(mvOptionEnum oShape, mvOptionEnum oType,\
   mvFloat x, mvFloat y, mvFloat z)
{
   setShape(oShape);
   setType(oType);
   setPosition(x,y,z);
}

void mvObstacle_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   obPosition.set(x,y,z);
}

mvFloat mvObstacle_V2::getX() const
{
   return obPosition.getX();
}

mvFloat mvObstacle_V2::getY() const
{
   return obPosition.getY();
}

mvFloat mvObstacle_V2::getZ() const
{
   return obPosition.getZ();
}

void mvObstacle_V2::setX(mvFloat x)
{
   obPosition.setX(x);
}

void mvObstacle_V2::setY(mvFloat y)
{
   obPosition.setY(y);
}

void mvObstacle_V2::setZ(mvFloat z)
{
   obPosition.setZ(z);
}

const mvVec3& mvObstacle_V2::getPosition() const
{
   return obPosition;
}

mvOptionEnum mvObstacle_V2::getType() const
{
   return obType;
}

mvErrorEnum mvObstacle_V2::setType(mvOptionEnum oType)
{
   switch(oType)
   {
      case MV_AIR_OBSTACLE:
      case MV_SOLID_OBSTACLE:
      case MV_LIQUID_OBSTACLE:
         obType = oType;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_OBSTACLE_TYPE;
   }
}

mvErrorEnum mvObstacle_V2::setShape(mvOptionEnum oShape)
{
   return obShape.setType(oShape);
}

mvConstShapePtr mvObstacle_V2::getShape() const
{
   return &obShape;
}

mvErrorEnum mvObstacle_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::getParameterv(mvParamEnum paramFlag,\
 mvFloat* numArray, mvCount* noOfParameters) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvObstacle_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvObstacle_V2::~mvObstacle_V2()
{
   // TODO : implement this function
}
