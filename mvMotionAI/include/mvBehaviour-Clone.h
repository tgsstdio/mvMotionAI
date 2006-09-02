#ifndef MV_BEHAVIOUR_CLONE_H_
#define MV_BEHAVIOUR_CLONE_H_
#include "mvMotionAI-Types.h"
#include "mvVec3.h"
#include "mvBody.h"

mvVec3 mvBehaviour_Calculate_Clone(mvBody* currentBody, mvBody* targetBody,
                                mvFloat syncRatio);

#endif