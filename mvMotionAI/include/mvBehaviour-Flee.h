#ifndef MV_BEHAVIOUR_FLEE_H_
#define MV_BEHAVIOUR_FLEE_H_

#include "mvVec3.h"
#include "mvBody.h"
#include "mvWaypoint.h"

mvVec3 mvBehaviour_Calculate_Flee(mvBody* body, mvWaypoint* point);

#endif
