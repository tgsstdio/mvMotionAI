#ifndef MVUNIFORMACCELFORCE_H_INCLUDED
#define MVUNIFORMACCELFORCE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

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
