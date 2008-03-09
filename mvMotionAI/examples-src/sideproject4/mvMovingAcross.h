#ifndef MVMOVINGACROSS_H_INCLUDED
#define MVMOVINGACROSS_H_INCLUDED

#include <mv/mvMotionAI.h>

class mvMovingAcross : public mvBaseAction
{
	public:
		mvMovingAcross();
		virtual bool groupOp(mvGroupBehaviourResult* result);
		virtual bool bodyOp(mvBehaviourResult* result);
		virtual ~mvMovingAcross();
};

#endif // MVMOVINGACROSS_H_INCLUDED
