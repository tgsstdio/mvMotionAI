#ifndef MVUNIFORMSHIFTFORCE_H_INCLUDED
#define MVUNIFORMSHIFTFORCE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_BASE_FORCE_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_

class mvUniformShiftForce : public mvBaseForce
{
   private:
      mvVec3 uShift;
   public:
      mvUniformShiftForce();
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      virtual ~mvUniformShiftForce();
};

class mvUniformShiftForceLoader : public mvBaseForceLoader
{
   public:
      mvUniformShiftForceLoader();
      virtual mvBaseForcePtr operator()(\
         void* extraPtr);
      virtual ~mvUniformShiftForceLoader()
      {

      }
};

#endif // MVUNIFORMSHIFTFORCE_H_INCLUDED
