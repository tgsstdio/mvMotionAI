#ifndef MV_SEEK_BHEAVIOUR_OBJECT_H_
#define MV_SEEK_BHEAVIOUR_OBJECT_H_
#include "mvBaseBehaviour.h"

class mvSeek : public mvBaseBehaviour
{
   private:
      mvIndex waypointIndex;
      mvFloat length;

   public:
      mvSeek();
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);

      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum setParameteri(mvParamEnum param, mvIndex index);
      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index);
};

class mvCreateSeeks : public mvBaseBehaviourLoader
{
   public:
      mvCreateSeeks();
      mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehav);
      ~mvCreateSeeks(){};
};

#endif
