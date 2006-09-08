#ifndef MV_BEHAVIOUR_CENTRAL_H_
#define MV_BEHAVIOUR_CENTRAL_H_
#include "mvVec3.h"
#include "mvBody.h"
#include "mvWorld.h"
#include "mvEnum.h"
#include "mvGroupBehaviour.h"
#include "mvMotionAI-Types.h"

/**
 * \file mvBehaviour-Central.h
 *
 * version     date     comments
 *00-01-03    21/6/06   - added processing to behaviours with central function : mvProcessBodyBehaviours
 *
 */

void mvProcessBodyBehaviours(mvWorld* worldPtr, mvBody* currentBody, mvFloat timeStep,
                             mvVec3& mvDirVector, mvVec3& mvVelocityVector,
                             mvVec3& mvAccelVector,mvVec3& mvForceVector);

void mvProcessGroupBehaviours(mvWorld* worldPtr, mvGroupBehaviour* groupBehPtr,
                              mvIndex groupIndex, mvFloat timeStep);


#endif
