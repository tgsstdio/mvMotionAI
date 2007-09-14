#ifndef MVUNIFORMFORCE_H_INCLUDED
#define MVUNIFORMFORCE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

class mvUniformForce: public mvBaseForce
{
   private:
      mvVec3 uForce;
   public:
      mvUniformForce();
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      virtual ~mvUniformForce();
};

class mvUniformForceLoader : public mvBaseForceLoader
{
   public:
      mvUniformForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      virtual ~mvUniformForceLoader()
      {

      }
};

#endif // MVUNIFORMFORCE_H_INCLUDED
