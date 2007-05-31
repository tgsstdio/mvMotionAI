#ifndef MOTIONAI_MVTARGET_H
#define MOTIONAI_MVTARGET_H
#include "Vec3.h"

class mvTarget
{
   public:
      Vec3 bodyPoint;
      int targetType;
      float dimensions[4];
};

#endif

