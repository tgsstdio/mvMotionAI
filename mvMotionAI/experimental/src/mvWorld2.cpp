#include "mvWorld2.h"

#ifdef MV_FILE_HEADER_TAG_
/**
 * Copyright (c) 2006, 2007 David Young.
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
 */
#endif

#include <cstring>
#include <new>

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getCurrentItemParametersv(param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersf(const char* param,\
   mvFloat* num) const
{
   return forces.getCurrentItemParametersf(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameters(const char* param,\
   const char** option) const
{
   return forces.getCurrentItemParameters(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getItemParametersv(index,param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersf(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return forces.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameters(mvIndex index, const char* param,\
   const char** option) const
{
   return forces.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return forces.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return forces.getCurrentItemParameter(paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getItemParameterv(index, paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return forces.getItemParameterf(index,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return forces.getItemParameter(index,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParametersv(const char* param,\
   mvFloat* array)
{
   return forces.setCurrentItemParametersv(param,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParametersf(const char* param,\
   mvFloat num)
{
   return forces.setCurrentItemParametersf(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameters(const char* param,\
   const char* option)
{
   return forces.setCurrentItemParameters(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParametersv(mvIndex index, const char* param,\
   mvFloat* array)
{
   return forces.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParametersf(mvIndex index, const char* param,\
   mvFloat num)
{
   return forces.setItemParametersf(index,param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameters(mvIndex index, const char* param,\
   const char* option)
{
   return forces.setItemParameters(index,param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return forces.setCurrentItemParameterv(paramFlag,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return forces.setCurrentItemParameterf(paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return forces.setCurrentItemParameter(paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return forces.setItemParameterv(index, paramFlag,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return forces.setItemParameterf(index,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return forces.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   forces.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllForces(void (someFunction)(mvForcePtr, void*),\
   void* extraPtr)
{
   forces.applyToAllItems(someFunction,extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllForces()
{
   forces.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteForce(mvIndex index)
{
   return forces.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentForce()
{
   return forces.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentForce(mvIndex index)
{
   return forces.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvForcePtr mvWorld_V2::getCurrentForcePtr()
{
   return forces.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvForcePtr mvWorld_V2::getForcePtr(mvIndex index)
{
   return forces.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createForce(mvOptionEnum fType)
{
   mvForcePtr temp = new (std::nothrow) mvForce(fType);

   if (temp == NULL)
      return MV_NO_CURRENT_INDEX;

   mvForceCapsulePtr tempCapsule = new (std::nothrow) mvForceCapsule(temp);

   if (tempCapsule == NULL)
      return MV_NO_CURRENT_INDEX;

   return forces.addItem(tempCapsule);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersv(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
   const char* param, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersf(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameters(mvIndex groupIndex,\
   const char* param, const char** option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameters(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParametersv(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersv(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParametersf(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersf(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameters(mvIndex index,\
   mvIndex groupIndex, const char* param, const char** option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameters(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameterv(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterv(groupIndex, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameterf(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameter(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameter(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameterv(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterv(groupIndex, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameterf(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameter(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameter(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersv(groupIndex, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
   const char* param, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersf(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameters(mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameters(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParametersv(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersv(groupIndex, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParametersf(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersf(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameters(mvIndex index,\
   mvIndex groupIndex, const char* param, const char* option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameters(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameterv(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv(groupIndex, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameterf(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameter(mvIndex groupIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameter(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameterv(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv(groupIndex, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameterf(mvIndex index,\
   mvIndex groupIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameter(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameter(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllGroupBehavioursByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   groupBehaviours.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllGroupBehaviours(\
   void (someFunction)(mvGroupBehaviour_V2*, void*), void* extraPtr)
{
   groupBehaviours.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllGroupBehaviours()
{
   groupBehaviours.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteGroupBehaviour(mvIndex index)
{
   return groupBehaviours.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentGroupBehaviour()
{
   return groupBehaviours.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentGroupBehaviour(mvIndex index)
{
   return groupBehaviours.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourPtr mvWorld_V2::getCurrentGroupBehaviourPtr()
{
   return groupBehaviours.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourPtr mvWorld_V2::getGroupBehaviourPtr(mvIndex index)
{
   return groupBehaviours.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createGroupBehaviour(mvOptionEnum type)
{
   mvBaseBehaviourPtr temp = behavLoader->createAClassPtr(type,NULL);

   if (temp == NULL)
      return MV_NO_CURRENT_INDEX;

   mvGroupBehaviourPtr tempGBehav = new (std::nothrow) mvGroupBehaviour(temp);
   if (tempGBehav== NULL)
      return MV_NO_CURRENT_INDEX;

   return groupBehaviours.addItem(tempGBehav);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersf(const char* param,\
   mvFloat* num) const
{
   return groups.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameters(const char* param,\
   const char** option) const
{
   return groups.getCurrentItemParameters(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersf(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return groups.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameters(mvIndex index, const char* param,\
   const char** option) const
{
   return groups.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return groups.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return groups.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return groups.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return groups.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParametersv(const char* param,\
   mvFloat* array)
{
   return groups.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParametersf(const char* param,\
   mvFloat num)
{
   return groups.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameters(const char* param,\
   const char* option)
{
   return groups.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParametersv(mvIndex index, const char* param,\
   mvFloat* array)
{
   return groups.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParametersf(mvIndex index, const char* param,\
   mvFloat num)
{
   return groups.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameters(mvIndex index, const char* param,\
   const char* option)
{
   return groups.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return groups.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return groups.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return groups.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return groups.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return groups.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return groups.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllGroupsByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   return groups.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllGroups(void (someFunction)(mvGroup*, void*),\
   void* extraPtr)
{
   return groups.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllGroups()
{
   groups.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteGroup(mvIndex index)
{
   return groups.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentGroup()
{
   return groups.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentGroup(mvIndex index)
{
   return groups.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroup * mvWorld_V2::getCurrentGroupPtr()
{
   return groups.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroup * mvWorld_V2::getGroupPtr(mvIndex index)
{
   return groups.getClassPtr(index);
}

bool checkGroupsForIDMatch(mvGroupPtr currentGroup, void* extraPtr)
{
   const char* groupID = NULL;

   if (extraPtr == NULL)
   {
      return false;
   }

   groupID = (const char*) extraPtr;

   if (currentGroup == NULL)
   {
      return false;
   }

   if (strcmp(currentGroup->getID(), groupID) == 0)
      return true;
   else
      return false;
}

/** @brief (one liner)
  *
  * Should clean up this code
  */
mvIndex mvWorld_V2::createGroup(const char* groupID)
{
   mvGroupPtr temp = NULL;

   if (groupID == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   temp = groups.findItemPtrInList(checkGroupsForIDMatch,(void*) groupID);

   if (temp != NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   temp = new (std::nothrow) mvGroup(groupID);

   if (temp == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return groups.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParametersf(const char* param,\
   mvFloat* num) const
{
   return behaviours.getCurrentItemParametersf(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameters(const char* param,\
   const char** option) const
{
   return behaviours.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersf(mvIndex index,\
 const char* param, mvFloat* num) const
{
   return behaviours.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameters(mvIndex index,\
   const char* param, const char** option) const
{
   return behaviours.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return behaviours.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return behaviours.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return behaviours.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return behaviours.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParametersv(const char* param,\
   mvFloat* array)
{
   return behaviours.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParametersf(const char* param,\
   mvFloat num)
{
   return behaviours.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameters(const char* param,\
   const char* option)
{
   return behaviours.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array)
{
   return behaviours.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParametersf(mvIndex index,\
   const char* param, mvFloat num)
{
   return behaviours.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameters(mvIndex index,\
   const char* param, const char* option)
{
   return behaviours.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return behaviours.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return behaviours.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return behaviours.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return behaviours.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return behaviours.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return behaviours.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllBehavioursByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   return behaviours.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllBehaviours(void (someFunction)(mvBehaviour_V2*, void*),\
   void* extraPtr)
{
   return behaviours.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllBehaviours()
{
   behaviours.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteBehaviour(mvIndex index)
{
   return behaviours.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentBehaviour()
{
   return behaviours.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentBehaviour(mvIndex index)
{
   return behaviours.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviour_V2 * mvWorld_V2::getCurrentBehaviourPtr()
{
   return behaviours.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviour_V2 * mvWorld_V2::getBehaviourPtr(mvIndex index)
{
   return behaviours.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createBehaviour(mvOptionEnum bType)
{
   mvBaseBehaviourPtr tempBehav = NULL;

   if (behavLoader != NULL)
   {
      tempBehav = behavLoader->createAClassPtr(bType,NULL);
   }

   if (tempBehav == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   mvBehaviourPtr temp = new (std::nothrow) mvBehaviour_V2(tempBehav);
   if (temp == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return behaviours.addItem(temp);

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParametersf(const char* param,\
   mvFloat* num) const
{
   return pathways.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameters(const char* param,\
   const char** option) const
{
   return pathways.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersf(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return pathways.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameters(mvIndex index, const char* param,\
   const char** option) const
{
   return pathways.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return pathways.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return pathways.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getItemParameterv(index, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return pathways.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return pathways.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParametersv(const char* param,\
   mvFloat* array)
{
   return pathways.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParametersf(const char* param,\
   mvFloat num)
{
   return pathways.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameters(const char* param,\
   const char* option)
{
   return pathways.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParametersv(mvIndex index, const char* param,\
   mvFloat* array)
{
   return pathways.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParametersf(mvIndex index, const char* param,\
   mvFloat num)
{
   return pathways.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameters(mvIndex index, const char* param,\
   const char* option)
{
   return pathways.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return pathways.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return pathways.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return pathways.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return pathways.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return pathways.setItemParameterf(index, paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return pathways.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllPathwaysByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   pathways.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllPathways(void (someFunction)(mvPathway*, void*),\
   void* extraPtr)
{
   pathways.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllPathways()
{
   pathways.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deletePathway(mvIndex index)
{
   return pathways.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentPathway()
{
   return pathways.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentPathway(mvIndex index)
{
   return pathways.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPathway * mvWorld_V2::getCurrentPathwayPtr()
{
   return pathways.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPathway * mvWorld_V2::getPathwayPtr(mvIndex index)
{
   return pathways.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createPathway()
{
   mvPathwayPtr temp = new (std::nothrow) mvPathway();

   return pathways.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParametersf(const char* param,\
   mvFloat* num) const
{
   return waypoints.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameters(const char* param,\
   const char** option) const
{
   return waypoints.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersf(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return waypoints.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameters(mvIndex index,\
   const char* param, const char** option) const
{
   return waypoints.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return waypoints.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return waypoints.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return waypoints.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return waypoints.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParametersv(const char* param,\
   mvFloat* array)
{
   return waypoints.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParametersf(const char* param,\
   mvFloat num)
{
   return waypoints.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameters(const char* param,\
   const char* option)
{
   return waypoints.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParametersv(mvIndex index,\
   const char* param, mvFloat* array)
{
   return waypoints.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParametersf(mvIndex index,\
   const char* param, mvFloat num)
{
   return waypoints.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameters(mvIndex index,\
   const char* param, const char* option)
{
   return waypoints.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return waypoints.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return waypoints.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return waypoints.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return waypoints.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return waypoints.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return waypoints.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllWaypointsByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   // TODO : check laer for possible changes
   waypoints.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllWaypoints(void (someFunction)(mvWaypoint*, void*),\
   void* extraPtr)
{
   waypoints.applyToAllItems(someFunction,extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllWaypoints()
{
   waypoints.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteWaypoint(mvIndex index)
{
   return waypoints.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentWaypoint()
{
   return waypoints.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentWaypoint(mvIndex index)
{
   return waypoints.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypointPtr mvWorld_V2::getCurrentWaypointPtr()
{
   return waypoints.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypointPtr mvWorld_V2::getWaypointPtr(mvIndex index)
{
   return waypoints.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createWaypoint(mvOptionEnum wShape, mvFloat x = 0,\
   mvFloat y = 0, mvFloat z = 0)
{
   mvWaypointPtr tempWaypointPtr = new (std::nothrow)\
      mvWaypoint(wShape, x, y, z);

   if (tempWaypointPtr == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   mvWaypointCapsulePtr capsulePtr = new (std::nothrow)\
      mvWaypointCapsule(tempWaypointPtr);

   if (capsulePtr == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return waypoints.addItem(capsulePtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParametersf(const char* param,\
   mvFloat* num) const
{
   return obstacles.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameters(const char* param,\
   const char** option) const
{
   return obstacles.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersf(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return obstacles.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameters(mvIndex index,\
   const char* param, const char** option) const
{
   return obstacles.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return obstacles.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return obstacles.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return obstacles.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return obstacles.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParametersv(const char* param,\
   mvFloat* array)
{
   return obstacles.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParametersf(const char* param,\
   mvFloat num)
{
   return obstacles.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameters(const char* param,\
   const char* option)
{
   return obstacles.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParametersv(mvIndex index,\
   const char* param, mvFloat* array)
{
   return obstacles.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParametersf(mvIndex index,\
   const char* param, mvFloat num)
{
   return obstacles.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParametersi(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return obstacles.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameters(mvIndex index, const char* param,\
   const char* option)
{
   return obstacles.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameteri(\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return obstacles.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return obstacles.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return obstacles.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return obstacles.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return obstacles.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return obstacles.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return obstacles.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllObstaclesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   obstacles.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllObstacles(void (someFunction)(mvObstaclePtr, void*),\
   void* extraPtr)
{
   obstacles.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllObstacles()
{
   obstacles.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteObstacle(mvIndex index)
{
   return obstacles.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentObstacle()
{
   return obstacles.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentObstacle(mvIndex index)
{
   return obstacles.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstaclePtr mvWorld_V2::getCurrentObstaclePtr()
{
   return obstacles.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstaclePtr mvWorld_V2::getObstaclePtr(mvIndex index)
{
   return obstacles.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
   mvFloat x = 0, mvFloat y = 0, mvFloat z = 0)
{
   mvObstaclePtr temp = new (std::nothrow) mvObstacle(oType, oState, x, y, z);

   if (temp == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return obstacles.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParametersf(const char* param,\
   mvFloat* num) const
{
   return bodies.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameters(const char* param,\
   const char** option) const
{
   return bodies.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersf(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return bodies.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameters(mvIndex index, const char* param,\
   const char** option) const
{
   return bodies.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return bodies.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return bodies.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return bodies.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return bodies.getItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParametersv(const char* param,\
   mvFloat* array)
{
   return bodies.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParametersf(const char* param,\
   mvFloat num)
{
   return bodies.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameters(const char* param,\
   const char* option)
{
   return bodies.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParametersv(mvIndex index, const char* param,\
   mvFloat* array)
{
   return bodies.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParametersf(mvIndex index, const char* param,\
   mvFloat num)
{
   return bodies.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameters(mvIndex index, const char* param,\
   const char* option)
{
   return bodies.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return bodies.setCurrentItemParameterv(paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return bodies.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return bodies.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* array)
{
   return bodies.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
   mvFloat num)
{
   return bodies.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return bodies.setItemParameter(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   bodies.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllBodies(void (someFunction)(mvBodyPtr, void*),\
   void* extraPtr)
{
   bodies.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::deleteAllBodies()
{
   bodies.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteBody(mvIndex index)
{
   return bodies.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentBody()
{
   return bodies.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentBody(mvIndex index)
{
   return bodies.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBodyPtr mvWorld_V2::getCurrentBodyPtr()
{
   return bodies.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBodyPtr mvWorld_V2::getBodyPtr(mvIndex index)
{
   return bodies.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createBody(mvOptionEnum bType, mvOptionEnum bShape,\
   mvFloat x = 0, mvFloat y  = 0, mvFloat z = 0)
{
   mvBodyPtr tempBody = new (std::nothrow) mvBody(bType, bShape,x,y,z);
   // TODO : new bodies created by body loader
   if (tempBody == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   mvBodyCapsulePtr bCapsulePtr = new (std::nothrow) mvBodyCapsule(tempBody);
   if (bCapsulePtr == NULL)
   {
      return MV_NO_CURRENT_INDEX;
   }

   return bodies.addItem(bCapsulePtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvWorld_V2::~mvWorld_V2()
{
   if (worldID != NULL)
   {
      delete worldID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
char* mvWorld_V2::getID() const
{
   return worldID;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWorld_V2::mvWorld_V2(const char* id = NULL)
{
   isEnabled  = true;
   applyForces = true;
   applyGravity = true;
   applyShifts = true;
   applyAccelerations = true;
   applyCollisions = true;
   applyAllForces = true;
   autoConvertIndex = false;
   isRightHanded = true;

   mvCount strLen;
   //idString = NULL;

   /*
    *c string copy
    */
   if (id != NULL)
   {
      strLen = strlen(id) + 1;
      worldID = new char[strLen];
      strcpy(worldID,id);
   }
   else
   {
      worldID = NULL;
   }

   behavLoader = NULL;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::setBehaviourLoader(mvBehavFuncListPtr bLoaderPtr)
{
   behavLoader = bLoaderPtr;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehavFuncListPtr mvWorld_V2::getBehaviourLoader() const
{
   return behavLoader;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::worldStep(mvFloat timeInSecs)
{
   //TODO : implement theis function
   calculateGroupBehaviours();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeBody(mvIndex index, mvFloat timeInSecs)
{
   mvBodyPtr tempBodyPtr = getBodyPtr(index);

   if (tempBodyPtr == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   calculateGroupBehaviours();

   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeCurrentBody(mvFloat timeInSecs)
{
   mvBodyPtr tempBodyPtr = getCurrentBodyPtr();

   if (tempBodyPtr == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   calculateGroupBehaviours();

   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addBehaviourToBody(mvIndex bodyIndex, mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addBehaviourToCurrentBody(mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addGroupIntoGroupBehaviour(mvIndex groupIndex,\
   mvIndex groupBehaviour)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentGroupIntoGroupBehaviour(\
   mvIndex groupBehaviour)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addGroupIntoCurrentGroupBehaviour(mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentGroupIntoCurrentGroupBehaviour()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeGroupFromGroupBehaviour(mvIndex groupIndex,\
   mvIndex groupBehaviour)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentGroupFromGroupBehaviour(\
   mvIndex groupBehaviour)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeGroupFromCurrentGroupBehaviour(\
   mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentGroupFromCurrentGroupBehaviour()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addBodyToGroup(mvIndex bodyIndex, mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentBodyToGroup(mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addBodyToCurrentGroup(mvIndex bodyIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentBodyToCurrentGroup()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeBodyFromGroup(mvIndex bodyIndex,\
   mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentBodyFromGroup(mvIndex groupIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeBodyFromCurrentGroup(mvIndex bodyIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentBodyFromCurrentGroup()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addWaypointToPathway(mvIndex wpIndex, mvIndex pIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addWaypointToCurrentPathway(mvIndex wpIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentWaypointToCurrentPathway()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addCurrentWaypointToPathway(mvIndex pIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeWaypointFromPathway(mvIndex wpIndex,\
   mvIndex pIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeWaypointFromCurrentPathway(mvIndex wpIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentWaypointFromPathway(mvIndex pIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeCurrentWaypointFromCurrentPathway()
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameter(mvIndex index,\
   mvParamEnum param, mvOptionEnum option)
{
   return groupBehaviours.setItemParameter(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameteri(mvIndex index,\
   mvParamEnum param, mvIndex paramIndex)
{
   return groupBehaviours.setItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameterf(mvIndex index,\
   mvParamEnum param, mvFloat num)
{
   return groupBehaviours.setItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameterv(mvIndex index,\
   mvParamEnum param, mvFloat* array)
{
   return groupBehaviours.setItemParameterv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameter(\
   mvParamEnum param, mvOptionEnum option)
{
   return groupBehaviours.setCurrentItemParameter(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameteri(\
   mvParamEnum param, mvIndex paramIndex)
{
   return groupBehaviours.setCurrentItemParameteri(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameterf(\
   mvParamEnum param, mvFloat num)
{
   return groupBehaviours.setCurrentItemParameterf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameterv(\
   mvParamEnum param, mvFloat* array)
{
   return groupBehaviours.setCurrentItemParameterv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return groupBehaviours.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameters(mvIndex index,\
   const char* param, const char* option)
{
   return groupBehaviours.setItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParametersf(mvIndex index,\
   const char* param, mvFloat num)
{
   return groupBehaviours.setItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setItemParametersv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParametersi(\
   const char* param, mvIndex paramIndex)
{
   return groupBehaviours.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameters(\
   const char* param, const char* option)
{
   return groupBehaviours.setCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParametersf(\
   const char* param, mvFloat num)
{
   return groupBehaviours.setCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParametersv(\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setCurrentItemParametersv(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameters(mvIndex index,\
   const char* param, const char** option) const
{
   return groupBehaviours.getItemParameters(index,param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex* paramIndex) const
{
   return groupBehaviours.getItemParametersi(index,param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersf(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return groupBehaviours.getItemParametersf(index,param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getItemParametersv(index,param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameters(\
   const char* param,const char** option) const
{
   return groupBehaviours.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersi(\
   const char* param, mvIndex* paramIndex) const
{
   return groupBehaviours.getCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersf(\
   const char* param, mvFloat* num) const
{
   return groupBehaviours.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersv(\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getCurrentItemParametersv(param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameter(mvIndex index,\
   mvParamEnum param, mvOptionEnum* option) const
{
   return groupBehaviours.getItemParameter(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameteri(mvIndex index,\
   mvParamEnum param, mvIndex* paramIndex) const
{
   return groupBehaviours.getItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterf(mvIndex index,\
   mvParamEnum param, mvFloat* num) const
{
   return groupBehaviours.getItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterv(mvIndex index,\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getItemParameterv(index, param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameteri(\
   mvParamEnum param, mvIndex* paramIndex) const
{
   return groupBehaviours.getCurrentItemParameteri(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterf(\
   mvParamEnum param, mvFloat* num) const
{
   return groupBehaviours.getCurrentItemParameterf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterv(\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getCurrentItemParameterv(param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return forces.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return forces.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return forces.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return forces.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParametersi(const char* param,\
   mvIndex paramIndex)
{
   return forces.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParametersi(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return forces.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return forces.setCurrentItemParameteri(paramFlag,paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return forces.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParametersi(mvIndex index,\
   mvIndex groupIndex, const char* param, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersi(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameteri(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri(groupIndex, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameteri(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri(groupIndex, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersi(mvIndex groupIndex,\
   const char* param, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersi(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParametersi(\
   mvIndex groupIndex, const char* param, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersi(groupIndex, param, paramIndex);
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParametersi(mvIndex index,\
   mvIndex groupIndex, const char* param, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametersi(groupIndex, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameteri(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri(groupIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameteri(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri(groupIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return groups.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return groups.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return groups.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return groups.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParametersi(const char* param,\
   mvIndex paramIndex)
{
   return groups.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParametersi(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return groups.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return groups.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return groups.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return behaviours.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return behaviours.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return behaviours.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return behaviours.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParametersi(const char* param,\
   mvIndex paramIndex)
{
   return behaviours.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return behaviours.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return behaviours.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return behaviours.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return pathways.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return pathways.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return pathways.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return pathways.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParametersi(const char* param,\
   mvIndex paramIndex)
{
   return pathways.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParametersi(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return pathways.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return pathways.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return pathways.setItemParameteri(index,paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return waypoints.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return waypoints.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return waypoints.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return waypoints.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParametersi(const char* param,\
   mvIndex paramIndex)
{
   return waypoints.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParametersi(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return waypoints.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return waypoints.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return waypoints.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return obstacles.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return obstacles.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return obstacles.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return obstacles.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParametersi(const char* param,\
   mvIndex paramIndex)
{
   return obstacles.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return obstacles.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParametersi(const char* param,\
   mvIndex* outIndex) const
{
   return bodies.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return bodies.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return bodies.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return bodies.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParametersi(const char* param,\
   mvIndex paramIndex)
{
   return bodies.setCurrentItemParametersi(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParametersi(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return bodies.setItemParametersi(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return bodies.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return bodies.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      //TODO : MV_TYPE,
      case MV_IS_ENABLED:
         if (isEnabled)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_AUTO_CONVERT_INDEX:
         if (autoConvertIndex)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_RIGHT_HANDED:
         if (isRightHanded)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_FORCES:
         if (applyForces)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_SHIFTS:
         if (applyShifts)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ACCELERATIONS:
         if (applyAccelerations)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_GRAVITY:
         if (applyGravity)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_COLLISIONS:
         if (applyCollisions)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_FORCES:
         if (applyAllForces)
         {
            *option =MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_WORLD_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameteri(mvParamEnum paramFlag, mvIndex* outIndex)\
   const
{

   if (outIndex == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_WAYPOINT:
         *outIndex = getCurrentWaypoint();
         return MV_NO_ERROR;
      case MV_BODY:
         *outIndex = getCurrentBody();
         return MV_NO_ERROR;
      case MV_PATHWAY:
         *outIndex = getCurrentPathway();
         return MV_NO_ERROR;
      case MV_NO_OF_BODIES:
         *outIndex = bodies.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_GROUPS:
         *outIndex = groups.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_FORCES:
         *outIndex = forces.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_WAYPOINTS:
         *outIndex = waypoints.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_OBSTACLES:
         *outIndex = obstacles.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_GROUP_BEHAVIOURS:
         *outIndex = groupBehaviours.getNoOfItems();
         return MV_NO_ERROR;
      case MV_NO_OF_BEHAVIOURS:
         *outIndex = behaviours.getNoOfItems();
         return MV_NO_ERROR;
      case MV_GROUP:
         *outIndex = getCurrentGroup();
         return MV_NO_ERROR;
      case MV_OBSTACLE:
         *outIndex = getCurrentObstacle();
         return MV_NO_ERROR;
      case MV_GROUP_BEHAVIOUR:
         *outIndex = getCurrentGroupBehaviour();
         return MV_NO_ERROR;
      case MV_BEHAVIOUR:
         *outIndex = getCurrentBehaviour();
         return MV_NO_ERROR;
      case MV_FORCE:
         *outIndex = getCurrentForce();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_WORLD_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   // no parameter
   return MV_INVALID_WORLD_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfElements) const
{
   /*
   */
   if (noOfElements == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      *noOfElements = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   // no parameter
   return MV_INVALID_WORLD_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch (paramFlag)
   {
      //TODO : case MV_TYPE,
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
      case MV_AUTO_CONVERT_INDEX:
         if (option == MV_FALSE)
         {
            autoConvertIndex = false;
         }
         else
         {
            autoConvertIndex = true;
         }
         return MV_NO_ERROR;
      case MV_RIGHT_HANDED:
         if (option == MV_FALSE)
         {
            isRightHanded= false;
         }
         else
         {
            isRightHanded = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_FORCES:
         if (option == MV_FALSE)
         {
            applyForces = false;
         }
         else
         {
            applyForces = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_SHIFTS:
         if (option == MV_FALSE)
         {
            applyShifts = false;
         }
         else
         {
            applyShifts = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ACCELERATIONS:
         if (option == MV_FALSE)
         {
            applyAccelerations = false;
         }
         else
         {
            applyAccelerations = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_GRAVITY:
         if (option == MV_FALSE)
         {
            applyGravity = false;
         }
         else
         {
            applyGravity = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_COLLISIONS:
         if (option == MV_FALSE)
         {
            applyCollisions = false;
         }
         else
         {
            applyCollisions = true;
         }
         return MV_NO_ERROR;
      case MV_APPLY_ALL_FORCES:
         if (option == MV_FALSE)
         {
            applyAllForces = false;
         }
         else
         {
            applyAllForces = true;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_WORLD_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      case MV_WAYPOINT:
         setCurrentWaypoint(index);
         return MV_NO_ERROR;
      case MV_BODY:
         setCurrentBody(index);
         return MV_NO_ERROR;
      case MV_PATHWAY:
         setCurrentPathway(index);
         return MV_NO_ERROR;
      case MV_GROUP:
         setCurrentGroup(index);
         return MV_NO_ERROR;
      case MV_OBSTACLE:
         setCurrentObstacle(index);
         return MV_NO_ERROR;
      case MV_GROUP_BEHAVIOUR:
         setCurrentGroupBehaviour(index);
         return MV_NO_ERROR;
      case MV_BEHAVIOUR:
         setCurrentBehaviour(index);
         return MV_NO_ERROR;
      case MV_FORCE:
         setCurrentForce(index);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_WORLD_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_WORLD_PARAMETER;
}

mvIndex mvWorld_V2::getCurrentBody() const
{
   return bodies.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentObstacle() const
{
   return obstacles.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentWaypoint() const
{
   return waypoints.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentForce() const
{
   return forces.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentGroup() const
{
   return groups.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentBehaviour() const
{
   return behaviours.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentGroupBehaviour() const
{
   return groupBehaviours.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentPathway() const
{
   return pathways.getCurrentIndex();
}

mvConstBodyPtr mvWorld_V2::getConstBodyPtr(mvIndex index) const
{
   return bodies.getConstClassPtr(index);
}

mvConstObstaclePtr mvWorld_V2::getConstObstaclePtr(mvIndex index) const
{
   return obstacles.getConstClassPtr(index);
}

mvConstWaypointPtr mvWorld_V2::getConstWaypointPtr(mvIndex index) const
{
   return waypoints.getConstClassPtr(index);
}

mvConstPathwayPtr mvWorld_V2::getConstPathwayPtr(mvIndex index) const
{
   return pathways.getConstClassPtr(index);
}

mvConstGroupPtr mvWorld_V2::getConstGroupPtr(mvIndex index) const
{
   return groups.getConstClassPtr(index);
}

mvConstGroupBehaviourPtr mvWorld_V2::getConstGroupBehaviourPtr(mvIndex index)\
   const
{
   return groupBehaviours.getConstClassPtr(index);
}

mvConstBehaviourPtr mvWorld_V2::getConstBehaviourPtr(mvIndex index) const
{
   return behaviours.getConstClassPtr(index);
}

mvConstForcePtr mvWorld_V2::getConstGroupForcePtr(mvIndex index) const
{
   return forces.getConstClassPtr(index);
}

void mvWorld_Prepare_Body_Capsule(mvBodyCapsulePtr capsulePtr, void* extraPtr)
{
   if (capsulePtr != NULL)
   {
      // TODO : reset bodies
   }
}

void mvWorld_Prepare_Waypoint_Capsule(mvWaypointCapsulePtr capsulePtr,\
   void* extraPtr)
{

}

void mvWorld_V2::prepareIntegrationStep()
{
   // TODO : reset bodies
   bodies.applyToAllCapsules(mvWorld_Prepare_Body_Capsule,NULL);

   // TODO : reset waypoints
   waypoints.applyToAllCapsules(mvWorld_Prepare_Waypoint_Capsule, NULL);
   // reset forces
}

void mvWorld_V2::calculateGroupBehaviours() // 1
{
// TODO : calculate world functions
}

void mvWorld_V2::checkIfWaypointContainsBody(mvIndex waypointIndex,\
      mvIndex bodyIndex) // part of 2
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateGlobalForceOnBody(mvIndex globalForce,\
   mvIndex bodyIndex)
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateLocalForceOnBody(mvIndex localForce,\
   mvIndex bodyIndex)
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateBehavioursOnBody(mvIndex bodyIndex)
{
// TODO : calculate world functions
}

void mvWorld_V2::finaliseIntegrationOfBody(mvIndex bodyIndex)
{
// TODO : calculate world functions
}

mvConstBodyCapsulePtr mvWorld_V2::getConstBodyCapsulePtr(int index) const
{
   return bodies.getConstCapsulePtr(index);
}

mvBodyCapsulePtr mvWorld_V2::getBodyCapsulePtr(int index)
{
   return bodies.getCapsulePtr(index);
}
