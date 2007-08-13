#ifndef MVGRAVITYFORCE_H_INCLUDED
#define MVGRAVITYFORCE_H_INCLUDED

#include "mvMotionAI-Types.h"
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
      ~mvGravityForce();
};

class mvGravityForceLoader : public mvBaseForceLoader
{
   public:
      mvGravityForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      ~mvGravityForceLoader();
};

#endif // MVGRAVITYFORCE_H_INCLUDED
