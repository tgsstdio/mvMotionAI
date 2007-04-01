#include "mvWaypoint_V2.h"
mvWaypoint_V2::mvWaypoint_V2(mvOptionEnum wshape, mvFloat x, mvFloat y,\
   mvFloat z)
{
   setPosition(x,y,z);
   setShape(wshape);
}

mvFloat mvWaypoint_V2::getX() const
{
   return wpPosition.getX();
}

mvFloat mvWaypoint_V2::getY() const
{
   return wpPosition.getY();
}

mvFloat mvWaypoint_V2::getZ() const
{
   return wpPosition.getZ();
}

void mvWaypoint_V2::setX(mvFloat x)
{
   wpPosition.setX(x);
}

void mvWaypoint_V2::setY(mvFloat y)
{
   wpPosition.setY(y);
}

void mvWaypoint_V2::setZ(mvFloat z)
{
   wpPosition.setZ(z);
}

const mvVec3& mvWaypoint_V2::getPosition() const
{
   return wpPosition;
}

void mvWaypoint_V2::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
   wpPosition.set(x,y,z);
}

mvErrorEnum mvWaypoint_V2::setShape(mvOptionEnum shape)
{
   return wpShape.setType(shape);
}

mvConstShapePtr mvWaypoint_V2::getShape() const
{
   return &wpShape;
}

mvErrorEnum mvWaypoint_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)\
   const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvWaypoint_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray) const
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvWaypoint_V2::~mvWaypoint_V2()
{
   // TODO : implement this function
}

