#include "mvGroup_V2.h"

mvGroup_V2::mvGroup_V2()
{
   isActive = true;
}

mvGroup_V2::~mvGroup_V2()
{
   clearAll();
}

mvErrorEnum mvGroup_V2::addMember(mvIndex memberIndex)
{
   return members.addIndex(memberIndex);
}

mvErrorEnum mvGroup_V2::findMember(mvIndex memberIndex) const
{
   return members.findIndex(memberIndex);
}

mvErrorEnum mvGroup_V2::removeMember(mvIndex memberIndex)
{
   return members.removeIndex(memberIndex);
}

mvCount mvGroup_V2::getNoOfMembers() const
{
   return members.getNoOfIndexes();
}

void mvGroup_V2::clearAll()
{
   members.clearAll();
}

void mvGroup_V2::setToFirstMember()
{
   members.beginLoop();
}

bool mvGroup_V2::areMembersFinished() const
{
   return members.isLoopFinished();
}

mvIndex mvGroup_V2::getCurrentMember() const
{
   return members.getCurrentIndex();
}

mvErrorEnum mvGroup_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvErrorEnum mvGroup_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   //TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

