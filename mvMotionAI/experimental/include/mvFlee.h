#ifndef MVFLEE_H_INCLUDED
#define MVFLEE_H_INCLUDED
#include "mvBaseAction.h"

class mvFlee : public mvBaseAction
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

class mvCreateFlees : public mvBaseActionLoader
{
   public:
      mvCreateFlees();
      virtual mvBaseActionPtr operator()(mvBaseActionPtr defaultBehav);
      virtual ~mvCreateFlees(){};
};

#endif // MVFLEE_H_INCLUDED
