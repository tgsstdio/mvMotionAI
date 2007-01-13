#ifndef MVBENTRYLISTNODE_H_INCLUDED
#define MVBENTRYLISTNODE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvBEntry.h"
#include "mvBEntryTimer.h"

class mvBEntryListNode
{
   public:
      mvBEntry* bEntryPtr;
      mvFloat weight;
      mvBEntryTimer timer;

      mvBEntryListNode(mvFloat bNodeWeight, mvBEntry* behEntry, mvFloat period,\
         mvFloat elaspedTime);
      mvBEntry* getEntryPtr();
      mvBEntryTimer* getTimer();
      mvFloat getWeight() const;

      mvErrorEnum setEntryPtr(mvBEntry* behEntry);
      mvErrorEnum setWeight(mvFloat bNodeWeight);

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvBEntryListNode();
};

#endif // MVBENTRYLISTNODE_H_INCLUDED
