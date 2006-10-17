#include "mvBaseBehaviour.h"

mvBaseBehaviour::mvBaseBehaviour(mvOptionEnum type)
{
   bType = type;
}

mvOptionEnum mvBaseBehaviour::getType()
{
   return bType;
}
/*
mvErrorEnum mvBaseBehaviour::getParameters(const char* paramFlag, mvOptionEnum* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParametersi(const char* paramFlag, mvIndex* index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParametersf(const char* paramFlag, mvFloat* num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParametersv(const char* paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}
*/

mvErrorEnum mvBaseBehaviour::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}
/*
mvErrorEnum mvBaseBehaviour::setParameters(const char* paramFlag, mvEnum* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameters(const char* paramFlag, mvIndex* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParametersf(const char* paramFlag, mvFloat num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParametersv(const char* paramFlag, mvFloat* numArray)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}
*/
mvErrorEnum mvBaseBehaviour::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseBehaviour::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}


mvBaseBehaviour* mvBaseBehaviour::createGroupEntry(mvBaseBehaviour* options)
{
   return NULL;
}

mvBaseBehaviour* mvBaseBehaviour::createBodyEntry(mvBaseBehaviour* options)
{
   return NULL;
}

void mvBaseBehaviour::groupOperation(mvWorld* world, mvGroup* groupPtr)
{
   // empty code
}

void mvBaseBehaviour::bodyOperation(mvWorld* world, mvBody* b,
                             mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity)
{
   // empty code
}

mvBaseBehaviour::~mvBaseBehaviour()
{
   // empty code
}
