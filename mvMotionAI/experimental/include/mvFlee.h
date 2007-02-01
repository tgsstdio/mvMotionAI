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
	   bool groupOp(mvGroupBehaviourResultPtr resultModule);
      bool bodyOp(mvBehaviourResultPtr resultModule);
      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index);
};

class mvCreateFlees : public mvBaseBehaviourLoader
{
   public:
      mvCreateFlees();
      virtual mvBaseBehaviourPtr operator()(mvBaseBehaviourPtr defaultBehav);
      virtual ~mvCreateFlees(){};
};

#endif // MVFLEE_H_INCLUDED
