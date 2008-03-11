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
		virtual mvErrorEnum setParameterv(mvParamEnum param, mvFloat* array);
		virtual mvErrorEnum getParameterv(mvParamEnum param, mvFloat* array,\
			mvCount* noOfParameters) const;
		virtual mvErrorEnum setParameteri(mvParamEnum param, mvIndex inputIndex);
		virtual mvErrorEnum getParameteri(mvParamEnum param, mvIndex* outIndex) const;
		virtual ~mvFlyingV();
};

#endif // MVFLYINGV_H_INCLUDED
