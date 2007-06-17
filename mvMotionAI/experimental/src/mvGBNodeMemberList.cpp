#include "mvGBNodeMemberList.h"

mvGroupMemberNode::mvGroupMemberNode(mvIndex mbIndex,  mvBaseActionPtr mbAction)
 {
   memberIndex = mbIndex;
   memberAction = mbAction;
 }

mvErrorEnum mvGroupMemberNode::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (memberAction != MV_NULL)
   {
      return memberAction->setParameter(paramFlag, option);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

bool mvGroupMemberNode::operator<(const mvGroupMemberNode& rhs) const
{
   return (this->memberIndex < rhs.memberIndex);
}

bool mvGroupMemberNode:: operator== (const mvGroupMemberNode& rhs) const
{
   return (this->memberIndex == rhs.memberIndex);
}

mvErrorEnum mvGroupMemberNode::setParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   if (memberAction != MV_NULL)
   {
      return memberAction->setParameteri(paramFlag, paramIndex);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::setParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   if (memberAction != MV_NULL)
   {
      return memberAction->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::setParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   if (memberAction != MV_NULL)
   {
      return memberAction->setParameterv(paramFlag, array);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (memberAction != MV_NULL)
   {
      return memberAction->getParameter(paramFlag, option);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   if (memberAction != MV_NULL)
   {
      return memberAction->getParameteri(paramFlag, outIndex);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (memberAction != MV_NULL)
   {
      return memberAction->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvGroupMemberNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   if (memberAction != MV_NULL)
   {
      return memberAction->getParameterv(paramFlag, array, noOfParameters);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

mvGroupMemberNode::~mvGroupMemberNode()
{
   if (memberAction != MV_NULL)
   {
      delete memberAction;
   }
}

mvGroupNodeMemberList::mvGroupNodeMemberList()
{

}

void mvGroupNodeMemberList::clearAll()
{

}

bool mvGroupNodeMemberList::hasAllNodesBeenVisited()
{
   return false;
}

void mvGroupNodeMemberList::toNextMember()
{

}

void mvGroupNodeMemberList::toFirstMember()
{

}

mvGroupMemberNodePtr mvGroupNodeMemberList::getCurrentMember()
{

}

bool mvGroupNodeMemberList::insertBeforeCurrentMember(mvIndex memberIndex,\
   mvBaseActionPtr actionPtr)
{
   return false;
}

void mvGroupNodeMemberList::deleteCurrentMember()
{

}

mvGroupNodeMemberList::~mvGroupNodeMemberList()
{

}
