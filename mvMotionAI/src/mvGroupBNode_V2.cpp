#include <mv/mvGroupBNode_V2.h>

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBNode_V2::~mvGroupBNode_V2()
{
   if (grpBehaviour != MV_NULL)
   {
      delete grpBehaviour;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's getParameterv
  */
mvErrorEnum mvGroupBNode_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (array == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (grpBehaviour  != MV_NULL)
   {
      return grpBehaviour ->getParameterv(paramFlag, array, noOfParameters);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's getParameterf
  */
mvErrorEnum mvGroupBNode_V2::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (grpBehaviour  != MV_NULL)
   {
      return grpBehaviour ->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's getParameteri
  */
mvErrorEnum mvGroupBNode_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   if (outIndex == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_GROUP:
         *outIndex = groupIndex;
         return MV_NO_ERROR;
      default:
         if (grpBehaviour != MV_NULL)
         {
            return grpBehaviour ->getParameteri(paramFlag, outIndex);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's getParameter
  */
mvErrorEnum mvGroupBNode_V2::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (isEnabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         if (grpBehaviour  != MV_NULL)
         {
            return grpBehaviour ->getParametero(paramFlag, option);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's setParameterv
  */
mvErrorEnum mvGroupBNode_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   if (array == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (grpBehaviour  != MV_NULL)
   {
      return grpBehaviour ->setParameterv(paramFlag, array);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's setParameterf
  */
mvErrorEnum mvGroupBNode_V2::setParameterf( mvParamEnum paramFlag, mvFloat num)
{
   if (grpBehaviour != MV_NULL)
   {
      return grpBehaviour->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's setParameteri
  */
mvErrorEnum mvGroupBNode_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (grpBehaviour  != MV_NULL)
   {
      return grpBehaviour ->setParameteri(paramFlag, index);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically calls group behaviour node's setParameter
  */
mvErrorEnum mvGroupBNode_V2::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      default:
         if (grpBehaviour  != MV_NULL)
         {
            return grpBehaviour->setParametero(paramFlag, option);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupMemberNodePtr mvGroupBNode_V2::findMemberInNode(mvIndex memberIndex)
{
   return memberDataList.findMember(memberIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseActionPtr mvGroupBNode_V2::getActionPtr()
{
   return grpBehaviour;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBNode_V2::mvGroupBNode_V2(\
   mvBaseActionPtr mainBehaviour, mvIndex grpIndex)
{
   grpBehaviour = mainBehaviour;
   groupIndex = grpIndex;
   isEnabled = true;
}

mvIndex  mvGroupBNode_V2::getGroup()
{
   return groupIndex;
}

mvGroupMemberNode::mvGroupMemberNode(mvIndex mbIndex,  mvBaseActionPtr mbAction)
 {
   memberIndex = mbIndex;
   memberAction = mbAction;
 }

mvErrorEnum mvGroupMemberNode::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (memberAction != MV_NULL)
   {
      return memberAction->setParametero(paramFlag, option);
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

mvBaseActionPtr mvGroupMemberNode::getActionPtr()
{
   return memberAction;
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

mvErrorEnum mvGroupMemberNode::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (memberAction != MV_NULL)
   {
      return memberAction->getParametero(paramFlag, option);
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
   toFirstMember();
}

void mvGroupNodeMemberList::clearAll()
{
   std::list<mvGroupMemberNodePtr>::iterator i;
   std::list<mvGroupMemberNodePtr>::iterator listEnd = mbActionDataSet.end();
   mvGroupMemberNodePtr tempNode;

   for (i = mbActionDataSet.begin(); i != listEnd; ++i)
   {
      tempNode = *i;
      if (tempNode != NULL)
      {
         delete tempNode;
         *i = NULL;
      }
   }
   mbActionDataSet.clear();
}

mvGroupMemberNodePtr mvGroupNodeMemberList::findMember(mvIndex memberIndex)
{
   std::list<mvGroupMemberNodePtr>::iterator i;
   std::list<mvGroupMemberNodePtr>::iterator listEnd = mbActionDataSet.end();
   mvGroupMemberNodePtr tempNode;

   for (i = mbActionDataSet.begin(); i != listEnd; ++i)
   {
      tempNode = *i;
      if (tempNode != NULL && tempNode->memberIndex == memberIndex)
      {
         return tempNode;
      }
   }

   // not found;
   return MV_NULL;
}

bool mvGroupNodeMemberList::hasAllNodesBeenVisited()
{
   return (currentIter == mbActionDataSet.end());
}

void mvGroupNodeMemberList::toNextMember()
{
   ++currentIter;
}

void mvGroupNodeMemberList::toFirstMember()
{
   currentIter =  mbActionDataSet.begin();
}

mvGroupMemberNodePtr mvGroupNodeMemberList::getCurrentMember()
{
   return MV_NULL;
}

void mvGroupNodeMemberList::insertBeforeCurrentMember(mvIndex memberIndex,\
   mvBaseActionPtr actionPtr)
{
   if (memberIndex == MV_NULL || actionPtr == MV_NULL)
   {
      return;
   }

   mvGroupMemberNodePtr tempNode =
      new mvGroupMemberNode(memberIndex, actionPtr);

   mbActionDataSet.insert(currentIter,tempNode);
}

void mvGroupNodeMemberList::deleteCurrentMember()
{
   std::list<mvGroupMemberNodePtr>::iterator pastNode = currentIter;
   mvGroupMemberNodePtr tempNode = *currentIter;
   delete tempNode;
   ++currentIter;
   mbActionDataSet.erase(pastNode);
}

mvGroupNodeMemberList::~mvGroupNodeMemberList()
{
   clearAll();
}

