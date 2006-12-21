#ifndef MVPURSUIT_H_INCLUDED
#define MVPURSUIT_H_INCLUDED
#include "mvBaseBehaviour.h"

class mvPursuit : public mvBaseBehaviour
{
   private:
      mvIndex targetObject;

   public:
      mvPursuit();
      void groupOperation(mvWorld* world, mvGroup* groupPtr);
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
      mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index);
};

class mvCreatePursuits : public mvBaseBehaviourLoader
{
   public:
      mvCreatePursuits();
      mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehav);
};

#endif // MVPURSUIT_H_INCLUDED
