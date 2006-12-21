#ifndef MVFLEE_H_INCLUDED
#define MVFLEE_H_INCLUDED
#include "mvBaseBehaviour.h"

class mvFlee : public mvBaseBehaviour
{
   private:
      mvFloat length;
      mvIndex waypointIndex;

   public:
      mvFlee();
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
      void groupOperation(mvWorld* world, mvGroup* groupPtr);
      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index);
};

class mvCreateFlees : public mvBaseBehaviourLoader
{
   public:
      mvCreateFlees();
      mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehav);
};

#endif // MVFLEE_H_INCLUDED
