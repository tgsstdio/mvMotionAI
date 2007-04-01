#ifndef MVOBSTACLE_V2_H_INCLUDED
#define MVOBSTACLE_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_SHAPE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

// TODO : shape
// TODO : parameters
// TODO : type
// TODO : constructor

class mvObstacle_V2
{
   private:
      mvShape obShape;
      mvOptionEnum obType;
      mvVec3 obPosition;

   public:
      mvObstacle_V2(mvOptionEnum oShape, mvOptionEnum oType,\
         mvFloat x, mvFloat y, mvFloat z);
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;

      void setX(mvFloat x);
      void setY(mvFloat y);
      void setZ(mvFloat z);
      const mvVec3& getPosition() const;

      void setPosition(mvFloat x, mvFloat y, mvFloat z);


      mvOptionEnum getType() const;
      mvErrorEnum setType(mvOptionEnum oType);

      mvErrorEnum setShape(mvOptionEnum oShape);
      mvConstShapePtr getShape() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index) const;
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option)\
         const;
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num) const;
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray) const;
      ~mvObstacle_V2();
};

#endif // MVOBSTACLE_V2_H_INCLUDED
