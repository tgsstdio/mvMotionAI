#ifndef MVGROUPBNODE_V2_H_INCLUDED
#define MVGROUPBNODE_V2_H_INCLUDED

#include "mvEnums.h"
#include "mvMotionAI-Types.h"
#include "mvBaseBehaviour.h"

class mvGroupBNode_V2
{
   private:
      mvIndex groupIndex;
      mvBaseBehaviour* grpBehaviour;

   public:
      mvGroupBNode_V2(mvOptionEnum gbType, mvIndex groupIndex);
      mvOptionEnum getType();
      mvBaseBehaviour* getBehaviourPtr();
      mvErrorEnum setParameter(mvIndex index, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setParameteri(mvIndex index, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setParameterf(mvIndex index, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setParameterv(mvIndex index, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getParameter(mvIndex index,mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getParameteri(mvIndex index,mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getParameterf(mvIndex index,mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getParameterv(mvIndex index,mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
      ~mvGroupBNode_V2();
};

#endif // MVGROUPBNODE_V2_H_INCLUDED
