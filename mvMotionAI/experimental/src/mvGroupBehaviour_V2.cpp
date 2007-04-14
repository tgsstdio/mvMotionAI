#include "mvGroupBehaviour_V2.h"
#include "mvMotionAI_V2-Central.h"
#include <new>

bool findGroupNodeByIndex(mvGroupBNode_V2* groupNodePtr, void* extraPtr)
{
   mvIndex groupIndex;

   if (groupNodePtr == NULL)
   {
      return false;
   }

   if (extraPtr == NULL)
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
 mvGroupBehaviour_V2::mvGroupBehaviour_V2(mvBaseBehaviourPtr groupBehPtr)
{
      // TODO : group behavioior functions with behaviour loading

   defaultGBehaviour = groupBehPtr;
   behavEnabled = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBehaviour_V2::~mvGroupBehaviour_V2()
{
   removeAllGroups();
   if (defaultGBehaviour == NULL)
   {
      delete defaultGBehaviour;
   }
}

/** @brief (one liner)
  *
  */
mvErrorEnum mvGroupBehaviour_V2::addGroup(mvIndex groupNo)
{
   // first check if index exists
   mvIndex groupIndex = groupNo;
   mvGroupBehaviourNodePtr groupNodePtr = NULL;

   // first check if index exists
   if (groupNodeList.findItemPtrInList(findGroupNodeByIndex,\
      (void*) &groupIndex) != NULL)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }

   // create new behaviour node if valid
   if (defaultGBehaviour == NULL)
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }

   groupNodePtr = new (std::nothrow) mvGroupBNode_V2(\
      defaultGBehaviour->getType(), defaultGBehaviour,groupIndex);

   if (groupNodePtr == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }

   return groupNodeList.addItem(groupNodePtr);
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

   // assuming MV_NO_CURRENT_INDEX (0) returned means no values was returned
   if (nodeIndex == MV_NO_CURRENT_INDEX)
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

// ** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvOptionEnum mvGroupBehaviour_V2::getType()
//{
//
//}

/** @brief (one liner)
  *
  */
bool mvGroupBehaviour_V2::isEnabled() const
{
   return behavEnabled;
}

/** @brief (one liner)
  *
  */
void mvGroupBehaviour_V2::setEnabled(bool value)
{
   behavEnabled = value;
}

/** @brief (one liner)
  *
  * automatically calls the behaviour's default template version of
  * getParameteri
  */
mvErrorEnum mvGroupBehaviour_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   if (outIndex == NULL)
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
         if (defaultGBehaviour == NULL)
         {
            return defaultGBehaviour->getParameteri(paramFlag, outIndex);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
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
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (behavEnabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         if (defaultGBehaviour != NULL)
         {
            return defaultGBehaviour->getParameter(paramFlag, option);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
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
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (defaultGBehaviour != NULL)
   {
      return defaultGBehaviour->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template getParameterv
  */
mvErrorEnum mvGroupBehaviour_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (defaultGBehaviour != NULL)
   {
      return defaultGBehaviour->getParameterv(paramFlag, numArray,\
         noOfParameters);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
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
         if (defaultGBehaviour == NULL)
         {
            return defaultGBehaviour->setParameteri(paramFlag, index);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
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
            behavEnabled = false;
         }
         else
         {
            behavEnabled = true;
         }
         return MV_NO_ERROR;
      default:
         if (defaultGBehaviour != NULL)
         {
            return defaultGBehaviour->setParameter(paramFlag, option);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
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
   if (defaultGBehaviour != NULL)
   {
      return defaultGBehaviour->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * Automatically call default group node template setParameterv
  */
mvErrorEnum mvGroupBehaviour_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (defaultGBehaviour != NULL)
   {
      return defaultGBehaviour->setParameterv(paramFlag, numArray);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */

mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameteri(\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return groupNodeList.getCurrentItemParameteri(paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameter(\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return groupNodeList.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameterf(\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return groupNodeList.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameterv(\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters) const
{
   return groupNodeList.getCurrentItemParameterv(paramFlag, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameteri(\
   mvParamEnum paramFlag, mvIndex index)
{
   return groupNodeList.setCurrentItemParameteri(paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return groupNodeList.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameterf(\
   mvParamEnum paramFlag, mvFloat num)
{
   return groupNodeList.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameterv(\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return groupNodeList.setCurrentItemParameterv(paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersi(const char* param,\
   mvIndex* index) const
{
   return groupNodeList.getCurrentItemParametersi(param, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameters(const char* param,\
   const char** option) const
{
   return groupNodeList.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersf(const char* param,\
   mvFloat* num) const
{
   return groupNodeList.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersv(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   return groupNodeList.getCurrentItemParametersv(param, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersi(const char* param,\
   mvIndex index)
{
   return groupNodeList.setCurrentItemParametersi(param, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameters(const char* param,\
   const char* option)
{
   return groupNodeList.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersf(const char* param,\
   mvFloat num)
{
   return groupNodeList.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersv(const char* param,\
   mvFloat* numArray)
{
   return groupNodeList.setCurrentItemParametersv(param, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParameteri(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == NULL)
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

   if (temp == NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParameter(paramFlag, option);
}

mvErrorEnum mvGroupBehaviour_V2::getGroupParameterf(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == NULL)
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

   if (temp == NULL)
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

   if (temp == NULL)
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

   if (temp == NULL)
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

   if (temp == NULL)
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

   if (temp == NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->setParameterv(paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getGroupParametersi(mvIndex groupIndex,\
   const char* param, mvIndex* index) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::getGroupParameters(mvIndex groupIndex,\
   const char* param, const char** option) const

{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;
   mvErrorEnum error;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::getGroupParametersf(mvIndex groupIndex,\
   const char* param, mvFloat* num) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::getGroupParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfParameters) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::setGroupParametersi(mvIndex groupIndex,\
   const char* param, mvIndex paramIndex)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::setGroupParameters(mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;
   mvOptionEnum optionFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::setGroupParametersf(mvIndex groupIndex,\
   const char* param, mvFloat num)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
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
mvErrorEnum mvGroupBehaviour_V2::setGroupParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* numArray)
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);
   mvParamEnum paramFlag;

   if (temp == NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   if (!mvCheckAllParamEnumsForString(param, &paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   return temp->setParameterv(paramFlag, numArray);
}
