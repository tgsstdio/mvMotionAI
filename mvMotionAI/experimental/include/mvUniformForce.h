#ifndef MVUNIFORMFORCE_H_INCLUDED
#define MVUNIFORMFORCE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

class mvUniformForce: public mvBaseForce
{
   private:
      mvVec3 uniformForce;
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
