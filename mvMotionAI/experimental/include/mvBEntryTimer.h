#ifndef MVBENTRYTIMER_H_INCLUDED
#define MVBENTRYTIMER_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvEnums.h"

class mvBEntryTimer
{
   private:
      mvFloat elaspedTime;
      mvFloat period;
      bool isTimed;

   public:
      mvBEntryTimer(mvFloat periodInSecs);
      mvCount update(mvFloat timeInSecs);
      mvFloat getElaspedTime() const;
      mvFloat getPeriod() const;
      bool setPeriod(mvFloat timeInSecs);
      bool toAlways();
      bool toTimed();
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
};

#endif // MVBENTRYTIMER_H_INCLUDED
