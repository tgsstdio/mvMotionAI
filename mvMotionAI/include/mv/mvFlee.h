#ifndef MVFLEE_H_INCLUDED
#define MVFLEE_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

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
      virtual mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num) const;
      virtual mvErrorEnum getParameteri(mvParamEnum param, mvIndex* index) const;
};

class mvCreateFlees : public mvBaseActionLoader
{
   public:
      mvCreateFlees();
      virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& actionInfo);
      virtual ~mvCreateFlees(){};
};

#endif // MVFLEE_H_INCLUDED
