#ifndef MVCLONE_H_INCLUDED
#define MVCLONE_H_INCLUDED
#include "mvBaseBehaviour.h"

class mvClone : public mvBaseBehaviour
{
   private:
      mvIndex targetIndex;

   public:
      mvClone();
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
      void groupOperation(mvWorld* world, mvGroup* groupPtr);
//      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
//      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index);

};

class mvCreateClones : public mvBaseBehaviourLoader
{
   public:
      mvCreateClones();
      mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehav);
};

#endif // MVCLONE_H_INCLUDED
