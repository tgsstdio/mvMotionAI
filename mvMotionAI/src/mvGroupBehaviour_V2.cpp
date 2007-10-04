/**
 * \file mvGroupBehaviour_V2.cpp
 *
 * \brief Copyright (c) 2006, 2007 David Young.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \class mvGroupBehaviour mv/mvGroupBehaviour_V2.h MV_GROUP_BEHAVIOUR_HEADER_FILE_H_
 *
 * \brief A cooperative behaviour between groups of objects
 */
#include <mv/mvGroupBehaviour_V2.h>

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

/** @fn mvGroupBehaviour::mvGroupBehaviour(mvBaseActionPtr groupBehPtr)
  * @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviour_V2::mvGroupBehaviour_V2(mvBaseActionPtr groupBehPtr)
{
   defaultGBehaviour = groupBehPtr;
   isEnabled = true;
}

/**
  * @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviour_V2::~mvGroupBehaviour_V2()
{
   removeAllGroups();
   if (defaultGBehaviour != MV_NULL)
   {
      delete defaultGBehaviour;
      defaultGBehaviour = MV_NULL;
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
   mvGroupBehaviourGroupNodePtr groupNodePtr = MV_NULL;

   // first check if index exists
   if (groupNodeList.findItemPtrInList(findGroupNodeByIndex,\
      (void*) &groupIndex) != MV_NULL)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }

   groupNodePtr = new mvGroupBehaviourGroupNode(behavPtr,groupIndex);

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
mvErrorEnum mvGroupBehaviour_V2::getParametero(mvParamEnum paramFlag,\
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
            return defaultGBehaviour->getParametero(paramFlag, option);
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
mvErrorEnum mvGroupBehaviour_V2::setParametero(mvParamEnum paramFlag,\
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
            return defaultGBehaviour->setParametero(paramFlag, option);
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
mvErrorEnum mvGroupBehaviour_V2::getGroupParametero(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvGroupBNode_V2* temp = findGroupNode(groupIndex);

   if (temp == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return temp->getParametero(paramFlag, option);
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
mvErrorEnum mvGroupBehaviour_V2::setGroupParametero(mvIndex groupIndex,\
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
mvErrorEnum mvGroupBehaviour_V2::getGroupParametero_str(mvIndex groupIndex,\
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

   error = temp->getParametero(paramFlag, &optionFlag);

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
mvErrorEnum mvGroupBehaviour_V2::setGroupParametero_str(mvIndex groupIndex,\
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

   return temp->setParametero(paramFlag, optionFlag);
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


