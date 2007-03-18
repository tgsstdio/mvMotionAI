#include "mvBEntry.h"
// TODO: implement later
mvBEntry::mvBEntry(mvOptionEnum type, mvIndex bIndex, mvIndex gIndex,\
   mvBaseBehaviour* dBehaviour)
{
   entryType = type;
   behaviourIndex = bIndex;
   groupIndex = gIndex;
   behaviourPtr = dBehaviour;
}

void mvBEntry::setBehaviourPtr(mvBaseBehaviourPtr behavPtr)
{
   behaviourPtr = behavPtr;
}

mvBaseBehaviourPtr mvBEntry::getBehaviourPtr() const
{
   return NULL;
}

mvOptionEnum mvBEntry::getType() const
{
   return entryType;
}

mvIndex mvBEntry::getGroup() const
{
   return groupIndex;
}

mvIndex mvBEntry::getBehaviour() const
{
   return behaviourIndex;
}

void mvBEntry::setBehaviourIndex(mvIndex index)
{
   behaviourIndex = index;
}

void mvBEntry::setGroupIndex(mvIndex index)
{
   groupIndex = index;
}

mvErrorEnum mvBEntry::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}


mvErrorEnum mvBEntry::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvBEntry::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvBEntry::~mvBEntry()
{
   if (behaviourPtr != NULL)
   {
      delete behaviourPtr;
   }
}
