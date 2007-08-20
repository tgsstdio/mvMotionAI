#ifndef MVUNIFORMACCELFORCE_H_INCLUDED
#define MVUNIFORMACCELFORCE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

class mvUniformAccelForce: public mvBaseForce
{
   private:
      mvVec3 uAccel;
   public:
      mvUniformAccelForce();
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      virtual ~mvUniformAccelForce();
};

class mvUniformAccelForceLoader : public mvBaseForceLoader
{
   public:
      mvUniformAccelForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      virtual ~mvUniformAccelForceLoader()
      {

      }
};

#endif // MVUNIFORMACCELFORCE_H_INCLUDED
