#ifndef MVGRAVITYFORCE_H_INCLUDED
#define MVGRAVITYFORCE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

class mvGravityForce : public mvBaseForce
{
   private:
      mvVec3 gravityForce;
   public:
      mvGravityForce();
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      virtual ~mvGravityForce();
};

class mvGravityForceLoader : public mvBaseForceLoader
{
   public:
      mvGravityForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      virtual ~mvGravityForceLoader()
      {

      }
};

#endif // MVGRAVITYFORCE_H_INCLUDED
