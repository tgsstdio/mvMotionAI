#ifndef MVBENTRYTREENODE_H_INCLUDED
#define MVBENTRYTREENODE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvBEntryTimer.h"

class mvBEntryTreeNode
{
   public:
      mvIndex bEntryNode;
      mvBEntryTimer timer;
      mvBEntryTreeNode* nextNode;
      mvBEntryTreeNode* nextLevel;
      mvFloat weight;

      mvBEntryTreeNode(mvIndex bEntryIndex, mvFloat bEWeight);
      mvFloat getWeight() const;
      mvBEntryTimer* getTimer();
      void setWeight(mvFloat bWeight);
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      ~mvBEntryTreeNode();
};

#endif // MVBENTRYTREENODE_H_INCLUDED
