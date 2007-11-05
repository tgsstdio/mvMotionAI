#ifndef MVFOLLOWPATH_H_INCLUDED
#define MVFOLLOWPATH_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_

class mvFollowPath : public mvBaseAction
{
   private:
      mvIndex m_insideNode;
      mvIndex m_pathwayIndex;
      mvFloat m_lengthSquared;

   public:
      mvFollowPath();
      mvErrorEnum setParameterf(mvParamEnum param, mvFloat num);
      mvErrorEnum getParameterf(mvParamEnum param, mvFloat* num) const;

      mvErrorEnum setParameteri(mvParamEnum param, mvIndex paramIndex);
      mvErrorEnum getParameteri(mvParamEnum param, mvIndex* paramIndex) const;
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
      ~mvFollowPath();
};

class mvCreatePathFollower : public mvBaseActionLoader
{
   public:
      mvCreatePathFollower();
      virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& actionInfo);
      virtual ~mvCreatePathFollower();
};

#endif // MVFOLLOWPATH_H_INCLUDED
