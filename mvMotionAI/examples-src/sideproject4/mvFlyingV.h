#ifndef MVFLYINGV_H_INCLUDED
#define MVFLYINGV_H_INCLUDED

#include <mv/mvMotionAI.h>

class mvFlyingV : public mvBaseAction
{
	public:
		mvIndex parentNode;
		mvVec3 offsetPosition;
		mvVec3 finalVelocity;
		bool isLocalised;

		mvFlyingV();
		virtual bool bodyOp(mvBehaviourResult* result);
		virtual bool groupOp(mvGroupBehaviourResult* result);
		virtual ~mvFlyingV();
};

#endif // MVFLYINGV_H_INCLUDED
