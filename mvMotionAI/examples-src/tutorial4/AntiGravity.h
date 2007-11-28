#ifndef ANTIGRAVITY_H_INCLUDED
#define ANTIGRAVITY_H_INCLUDED

#include <mv/mvMotionAI.h>

class AntiGravcty : public mvBaseForce
{
   public:
      AntiGravity(mvOptionEnum forceKey);
      virtual void filter(mvForceStatus& worldStatus);
      virtual bool calcFullForces(mvForceResultPtr fResult);
      ~AntiGravity();
};

class AntiGravityLoader : public mvBaseForceLoader
{
   public:
      mvOptionEnum typeKey;

      mvAntiGravityLoader(mvOptionEnum forceKey);
      mvBaseForcePtr operator()(void* extraPtr);
      ~mvAntiGravityLoader();
};

#endif // ANTIGRAVITY_H_INCLUDED
