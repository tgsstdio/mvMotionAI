#include "mvGroupBehaviour_V2.h"

bool findGroupNodeByIndex(mvGroupBNode_V2* groupNodePtr, void* extraPtr)
{
   mvIndex groupIndex;

   if (groupNodePtr == MV_NULL)
   {
      return false;
   }

   if (extraPtr == MV_NULL)
   {
      return false;
   }

   groupIndex = *((mvIndex*) extraPtr);

   if (groupNodePtr->getGroup() == groupIndex)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBehaviour_V2::mvGroupBehaviour_V2(mvBaseActionPtr groupBehPtr)
{
   defaultGBehaviour = groupBehPtr;
   isEnabled = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBehaviour_V2::~mvGroupBehaviour_V2()
{
   removeAllGroups();
   if (defaultGBehaviour == MV_NULL)
   {
      delete defaultGBehaviour;
   }
}

/** @brief (one liner)
  *
  */
mvErrorEnum mvGroupBehaviour_V2::addGroup(mvIndex groupNo, mvBaseActionPtr
   behavPtr)
{
   // first check if index exists
   mvIndex groupIndex = groupNo;
   mvGroupBehaviourNodePtr groupNodePtr = MV_NULL;

   // first check if index exists
   if (groupNodeList.findItemPtrInList(findGroupNodeByIndex,\
      (void*) &groupIndex) != MV_NULL)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }

   groupNodePtr = new mvGroupBNode_V2(behavPtr,groupIndex);

   if (groupNodePtr == MV_NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }

   if (groupNodeList.addItem(groupNodePtr) == MV_NULL)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }
   else
   {
      return MV_NO_ERROR;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::removeGroup(mvIndex groupNo)
{
   mvIndex nodeIndex;
   mvIndex groupIndex = groupNo;

   // first check if index exists
   nodeIndex = groupNodeList.findItemInList(findGroupNodeByIndex,\
      (void*) &groupIndex);

   // assuming MV_NULL (0) returned means no values was returned
   if (nodeIndex == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return groupNodeList.deleteItem(nodeIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvGroupBehaviour_V2::removeAllGroups()
{
   groupNodeList.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBNode_V2 * mvGroupBehaviour_V2::getGroupNodeByIndex(mvIndex index) const
{
   return groupNodeList.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBNode_V2* mvGroupBehaviour_V2::findGroupNode(mvIndex group) const
{
   mvIndex groupIndex = group;

   return groupNodeList.findItemPtrInList(findGroupNodeByIndex,\
      (void*) &groupIndex);
}

/** @brief (one liner)
  *
  */
mvCount mvGroupBehaviour_V2::getNoOfGroups() const
{
   return groupNodeList.getNoOfItems();
}

/** @brief (one liner)
  *
  * automatically calls the behaviour's default template version of
  * getParameteri
  */
mvErrorEnum mvGroupBehaviour_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   if (outIndex == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_CURRENT_INDEX:
         *outIndex = groupNodeList.getCurrentIndex();
         return MV_NO_ERROR;
      case MV_NO_OF_GROUPS:
         *outIndex = getNoOfGroups();
         return MV_NO_ERROR;
      default:
         if (defaultGBehaviour == MV_NULL)
         {
            return defaultGBehaviour->getParameteri(paramFlag, outIndex);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * automatically calls the behaviour's default template version of
  * getParameter
  */
mvErrorEnum mvGroupBehaviour_V2::getParameter(mvParamEnum paramFlag,\
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
         if (defaultGBehaviour != MV_NULL)
         {
            return defaultGBehaviour->getParameter(paramFlag, option);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template getParameterf
  */
mvErrorEnum mvGroupBehaviour_V2::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (defaultGBehaviour != MV_NULL)
   {
      return defaultGBehaviour->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template getParameterv
  */
mvErrorEnum mvGroupBehaviour_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (defaultGBehaviour != MV_NULL)
   {
      return defaultGBehaviour->getParameterv(paramFlag, numArray,\
         noOfParameters);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template setParameteri
  */
mvErrorEnum mvGroupBehaviour_V2::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   switch(paramFlag)
   {
      case MV_CURRENT_INDEX:
         groupNodeList.setCurrentIndex(index);
         return MV_NO_ERROR;
      default:
         if (defaultGBehaviour == MV_NULL)
         {
            return defaultGBehaviour->setParameteri(paramFlag, index);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template setParameter
  */
mvErrorEnum mvGroupBehaviour_V2::setParameter(mvParamEnum paramFlag,\
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
         if (defaultGBehaviour != MV_NULL)
         {
            return defaultGBehaviour->setParameter(paramFlag, option);
         }
         else
         {
            return MV_ACTION_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template setParameterf
  */
mvErrorEnum mvGroupBehaviour_V2::setParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   if (defaultGBehaviour != MV_NULL)
   {
      return defaultGBehaviour->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template setParameterv
  */
mvErrorEnum mvGroupBehaviour_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (defaultGBehaviour != MV_NULL)
   {
      return defaultGBehaviour->setParameterv(paramFlag, numArray);
   }
   else
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameteri(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParameteri(paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameter(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParameter(paramFlag, option);
}

mvErrorEnum mvGroupBehaviour_V2::getGroupParameterf(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameterv(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParameterv(paramFlag, numArray, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameteri(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->setParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameter(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->setParameteri(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameterf(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->setParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameterv(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->setParameterv(paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameteri_str(mvIndex groupIndex,\
   const char* param, mvIndex* index) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->getParameteri(paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameter_str(mvIndex groupIndex,\
   const char* param, const char** option) const

{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum error;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   error = temp->getParameter(paramFlag, &optionFlag);

   if (error == MV_NO_ERROR)
   {
      *option = mvGetOptionString(optionFlag);
   }

   return error;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameterf_str(mvIndex groupIndex,\
   const char* param, mvFloat* num) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->getParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameterv_str(mvIndex groupIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfParameters) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->getParameterv(paramFlag, numArray, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameteri_str(mvIndex groupIndex,\
   const char* param, mvIndex paramIndex)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->setParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameter_str(mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   if (!mvCheckAllOptionEnumsForString(option, &optionFlag))
   {
      return MV_INVALID_OPTION_ENUM_STRING;
   }

   return temp->setParameter(paramFlag, optionFlag);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameterf_str(mvIndex groupIndex,\
   const char* param, mvFloat num)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->setParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setGroupParameterv_str(mvIndex groupIndex,\
   const char* param, mvFloat* numArray)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->setParameterv(paramFlag, numArray);
}

mvIndex mvGroupBehaviour_V2::getCurrentGroupBehaviourNode() const
{
   return groupNodeList.getCurrentIndex();
}

mvBaseActionPtr mvGroupBehaviour_V2::getDefaultActionPtr() const
{
   return defaultGBehaviour;
}


