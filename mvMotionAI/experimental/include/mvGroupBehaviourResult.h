#ifndef MVGROUPBEHAVIOURRESULT_H_INCLUDED
#define MVGROUPBEHAVIOURRESULT_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvGroup.h"
#include "mvWorld2.h"

class mvGroupBehaviourResult
{
   public:
      mvWorldPtr world;
      mvGroupPtr group;

   mvGroupBehaviourResult();
   ~mvGroupBehaviourResult();
};

#endif // MVGROUPBEHAVIOURRESULT_H_INCLUDED
