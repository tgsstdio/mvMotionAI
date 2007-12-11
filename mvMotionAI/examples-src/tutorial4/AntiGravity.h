#ifndef ANTIGRAVITY_H_INCLUDED
#define ANTIGRAVITY_H_INCLUDED

#include <mv/mvMotionAI.h>

class AntiGravity : public mvBaseForce
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

      AntiGravityLoader(mvOptionEnum forceKey);
      mvBaseForcePtr operator()(void* extraPtr);
      ~AntiGravityLoader();
};

#endif // ANTIGRAVITY_H_INCLUDED
