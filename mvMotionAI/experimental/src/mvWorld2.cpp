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
mvErrorEnum mvWorld_V2::getCurrentForceParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getCurrentItemParameterv_str(param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameterf_str(const char* param,\
   mvFloat* num) const
{
   return forces.getCurrentItemParameterf_str(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameter_str(const char* param,\
   const char** option) const
{
   return forces.getCurrentItemParameter_str(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getItemParameterv_str(index,param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return forces.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameter_str(mvIndex index, const char* param,\
   const char** option) const
{
   return forces.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentForceParameterv_str(const char* param,\
   mvFloat* array)
{
   return forces.setCurrentItemParameterv_str(param,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameterf_str(const char* param,\
   mvFloat num)
{
   return forces.setCurrentItemParameterf_str(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentForceParameter_str(const char* param,\
   const char* option)
{
   return forces.setCurrentItemParameter_str(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return forces.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return forces.setItemParameterf_str(index,param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameter_str(mvIndex index, const char* param,\
   const char* option)
{
   return forces.setItemParameter_str(index,param,option);
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

   if (temp == MV_NULL)
      return MV_NULL;

   mvForceCapsulePtr tempCapsule = new (std::nothrow) mvForceCapsule(temp);

   if (tempCapsule == MV_NULL)
      return MV_NULL;

   return forces.addItem(tempCapsule);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameterv_str(mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterv_str(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameterf_str(mvIndex groupIndex,\
   const char* param, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf_str(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameter_str(mvIndex groupIndex,\
   const char* param, const char** option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameter_str(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameterv_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterv_str(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameterf_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* num) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf_str(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameter_str(mvIndex index,\
   mvIndex groupIndex, const char* param, const char** option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameter_str(groupIndex, param, option);
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameter(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameterv_str(mvIndex groupIndex,\
   const char* param, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv_str(groupIndex, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameterf_str(mvIndex groupIndex,\
   const char* param, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterf_str(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameter_str(mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameter_str(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameterv_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv_str(groupIndex, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameterf_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat num)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterf_str(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameter_str(mvIndex index,\
   mvIndex groupIndex, const char* param, const char* option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameter_str(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameterv(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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

   if (temp == MV_NULL)
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
   mvBaseBehaviourPtr temp = behavLoader->createAClassPtr(type,MV_NULL);

   if (temp == MV_NULL)
      return MV_NULL;

   mvGroupBehaviourPtr tempGBehav = new (std::nothrow) mvGroupBehaviour(temp);
   if (tempGBehav== MV_NULL)
      return MV_NULL;

   return groupBehaviours.addItem(tempGBehav);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterf_str(const char* param,\
   mvFloat* num) const
{
   return groups.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameter_str(const char* param,\
   const char** option) const
{
   return groups.getCurrentItemParameter_str(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return groups.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameter_str(mvIndex index, const char* param,\
   const char** option) const
{
   return groups.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentGroupParameterv_str(const char* param,\
   mvFloat* array)
{
   return groups.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameterf_str(const char* param,\
   mvFloat num)
{
   return groups.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupParameter_str(const char* param,\
   const char* option)
{
   return groups.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return groups.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return groups.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameter_str(mvIndex index, const char* param,\
   const char* option)
{
   return groups.setItemParameter_str(index, param, option);
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
mvGroupPtr mvWorld_V2::getCurrentGroupPtr()
{
   return groups.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupPtr mvWorld_V2::getGroupPtr(mvIndex index)
{
   return groups.getClassPtr(index);
}

/** @brief (one liner)
  *
  * Should clean up this code
  */
mvIndex mvWorld_V2::createGroup(const char* groupID)
{
   mvGroupPtr temp = MV_NULL;
   mvGroupCapsulePtr tempCapsule = NULL;

   temp = new (std::nothrow) mvGroup();

   if (temp == MV_NULL)
   {
      return MV_NULL;
   }

   tempCapsule = new (std::nothrow) mvGroupCapsule(temp);
   if (tempCapsule == MV_NULL)
   {
      return MV_NULL;
   }

   return groups.addItem(tempCapsule);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterf_str(const char* param,\
   mvFloat* num) const
{
   return behaviours.getCurrentItemParameterf_str(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameter_str(const char* param,\
   const char** option) const
{
   return behaviours.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterf_str(mvIndex index,\
 const char* param, mvFloat* num) const
{
   return behaviours.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameter_str(mvIndex index,\
   const char* param, const char** option) const
{
   return behaviours.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameterv_str(const char* param,\
   mvFloat* array)
{
   return behaviours.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameterf_str(const char* param,\
   mvFloat num)
{
   return behaviours.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameter_str(const char* param,\
   const char* option)
{
   return behaviours.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return behaviours.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return behaviours.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameter_str(mvIndex index,\
   const char* param, const char* option)
{
   return behaviours.setItemParameter_str(index, param, option);
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
   mvBaseBehaviourPtr tempBehav = MV_NULL;

   if (behavLoader != MV_NULL)
   {
      tempBehav = behavLoader->createAClassPtr(bType,MV_NULL);
   }

   if (tempBehav == MV_NULL)
   {
      return MV_NULL;
   }

   mvBehaviourPtr temp = new (std::nothrow) mvBehaviour_V2(tempBehav);
   if (temp == MV_NULL)
   {
      return MV_NULL;
   }

   return behaviours.addItem(temp);

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterf_str(const char* param,\
   mvFloat* num) const
{
   return pathways.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameter_str(const char* param,\
   const char** option) const
{
   return pathways.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return pathways.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameter_str(mvIndex index, const char* param,\
   const char** option) const
{
   return pathways.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentPathwayParameterv_str(const char* param,\
   mvFloat* array)
{
   return pathways.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameterf_str(const char* param,\
   mvFloat num)
{
   return pathways.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentPathwayParameter_str(const char* param,\
   const char* option)
{
   return pathways.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return pathways.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return pathways.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameter_str(mvIndex index, const char* param,\
   const char* option)
{
   return pathways.setItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterf_str(const char* param,\
   mvFloat* num) const
{
   return waypoints.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameter_str(const char* param,\
   const char** option) const
{
   return waypoints.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return waypoints.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameter_str(mvIndex index,\
   const char* param, const char** option) const
{
   return waypoints.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentWaypointParameterv_str(const char* param,\
   mvFloat* array)
{
   return waypoints.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameterf_str(const char* param,\
   mvFloat num)
{
   return waypoints.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentWaypointParameter_str(const char* param,\
   const char* option)
{
   return waypoints.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return waypoints.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return waypoints.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameter_str(mvIndex index,\
   const char* param, const char* option)
{
   return waypoints.setItemParameter_str(index, param, option);
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

   if (tempWaypointPtr == MV_NULL)
   {
      return MV_NULL;
   }

   mvWaypointCapsulePtr capsulePtr = new (std::nothrow)\
      mvWaypointCapsule(tempWaypointPtr);

   if (capsulePtr == MV_NULL)
   {
      return MV_NULL;
   }

   return waypoints.addItem(capsulePtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterf_str(const char* param,\
   mvFloat* num) const
{
   return obstacles.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameter_str(const char* param,\
   const char** option) const
{
   return obstacles.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return obstacles.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameter_str(mvIndex index,\
   const char* param, const char** option) const
{
   return obstacles.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentObstacleParameterv_str(const char* param,\
   mvFloat* array)
{
   return obstacles.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameterf_str(const char* param,\
   mvFloat num)
{
   return obstacles.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentObstacleParameter_str(const char* param,\
   const char* option)
{
   return obstacles.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return obstacles.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return obstacles.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return obstacles.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setObstacleParameter_str(mvIndex index, const char* param,\
   const char* option)
{
   return obstacles.setItemParameter_str(index, param, option);
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

   if (temp == MV_NULL)
   {
      return MV_NULL;
   }

   return obstacles.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getCurrentItemParameterv_str(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterf_str(const char* param,\
   mvFloat* num) const
{
   return bodies.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameter_str(const char* param,\
   const char** option) const
{
   return bodies.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return bodies.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameter_str(mvIndex index, const char* param,\
   const char** option) const
{
   return bodies.getItemParameter_str(index, param, option);
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
mvErrorEnum mvWorld_V2::setCurrentBodyParameterv_str(const char* param,\
   mvFloat* array)
{
   return bodies.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameterf_str(const char* param,\
   mvFloat num)
{
   return bodies.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentBodyParameter_str(const char* param,\
   const char* option)
{
   return bodies.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return bodies.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return bodies.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameter_str(mvIndex index, const char* param,\
   const char* option)
{
   return bodies.setItemParameter_str(index, param, option);
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
   if (tempBody == MV_NULL)
   {
      return MV_NULL;
   }

   mvBodyCapsulePtr bCapsulePtr = new (std::nothrow) mvBodyCapsule(tempBody);
   if (bCapsulePtr == MV_NULL)
   {
      return MV_NULL;
   }

   return bodies.addItem(bCapsulePtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvWorld_V2::~mvWorld_V2()
{
   if (worldID != MV_NULL)
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
mvWorld_V2::mvWorld_V2(const char* id = MV_NULL)
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
   //idString = MV_NULL;

   /*
    *c string copy
    */
   if (id != MV_NULL)
   {
      strLen = strlen(id) + 1;
      worldID = new char[strLen];
      strcpy(worldID,id);
   }
   else
   {
      worldID = MV_NULL;
   }

   behavLoader = MV_NULL;
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

/*
 * private function
 */
void mvWorld_V2_IntegrateAllBodies(mvBodyCapsulePtr bodyPtr, void* extraPtr)
{
   mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   if (currentWorld != NULL)
   {
      currentWorld->integrateBody(bodyPtr);
   }
}

void mvWorld_V2::integrateBody(mvBodyCapsulePtr bodyPtr)
{
   resetIntegrationLoop();
   checkIfWaypointContainsBody(bodyPtr);
   calculateAllForcesOnBody(bodyPtr);
   calculateBehavioursOnBody(bodyPtr);
   performIntegrationOfBody(bodyPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::worldStep(mvFloat timeInSecs)
{
   prepareIntegrationStep();
   calculateGroupBehaviours();

   bodies.applyToAllCapsules(mvWorld_V2_IntegrateAllBodies,this);

   finaliseIntegrationStep();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeBody(mvIndex index, mvFloat timeInSecs)
{
   mvBodyCapsulePtr tempCapsulePtr = getBodyCapsulePtr(index);

   if (tempCapsulePtr == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   prepareIntegrationStep();
   calculateGroupBehaviours();
   integrateBody(tempCapsulePtr);
   finaliseIntegrationStep();

   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeCurrentBody(mvFloat timeInSecs)
{
   return nudgeBody(getCurrentBody(), timeInSecs);
}

void mvWorld_Reset_Waypoint_Capsule(mvWaypointCapsulePtr capsulePtr,\
   void* extraPtr)
{
   if (capsulePtr != MV_NULL)
   {
      capsulePtr->containsBody = false;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::resetIntegrationLoop()
{
   // TODO : reset waypoints
   waypoints.applyToAllCapsules(mvWorld_Reset_Waypoint_Capsule, MV_NULL);
}

void mvWorld_Prepare_Body_Capsule(mvBodyCapsulePtr capsulePtr, void* extraPtr)
{
   if (capsulePtr != MV_NULL)
   {
      // TODO : reset bodies
      capsulePtr->performIntegration = false;
      capsulePtr->futurePosition.resetXYZ();
      capsulePtr->futureFinalVelocity.resetXYZ();
      capsulePtr->futureRotation.resetXYZ();
   }
}

void mvWorld_Prepare_Force_Capsule(mvForceCapsulePtr capsulePtr,\
   void* extraPtr)
{
   mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   if (capsulePtr != MV_NULL && currentWorld != MV_NULL)
   {
      // TODO : prefilter
      capsulePtr->isActive = true;
   }
}

void mvWorld_V2::prepareIntegrationStep()
{
   // TODO : reset bodies
   bodies.applyToAllCapsules(mvWorld_Prepare_Body_Capsule,MV_NULL);

   // reset forces
   forces.applyToAllCapsules(mvWorld_Prepare_Force_Capsule, this);
}

void mvWorld_V2::calculateGroupBehaviours() // 1
{
// TODO : calculate world functions
}

void mvWorld_V2::checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr) // part of 2
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateGlobalForceOnBody(mvIndex globalForce,\
   mvBodyCapsulePtr bodyPtr)
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateLocalForceOnBody(mvIndex localForce,\
   mvBodyCapsulePtr bodyPtr)
{
// TODO : calculate world functions
}

void mvWorld_V2::calculateBehavioursOnBody(mvBodyCapsulePtr bodyPtr)
{
// TODO : calculate world functions
}

void mvWorld_V2::performIntegrationOfBody(mvBodyCapsulePtr bodyPtr)
{
// TODO : calculate world functions
}

void mvWorld_Finalise_Groups(mvGroupCapsulePtr capsulePtr, void* extraPtr)
{
   if (capsulePtr != MV_NULL && extraPtr != MV_NULL)
   {
      capsulePtr->hasChanged = false;
   }
}

void mvWorld_V2::finaliseIntegrationStep()
{
   groups.applyToAllCapsules(mvWorld_Finalise_Groups,this);
}

// WORLD STEP FUNCTIONS

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


mvErrorEnum mvWorld_V2::addMemberToGroup(mvIndex memberIndex,\
   mvIndex groupIndex)
{
   mvGroupPtr tempGroup = getGroupPtr(groupIndex);

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->addMember(memberIndex);
}

mvErrorEnum mvWorld_V2::addMemberToCurrentGroup(mvIndex memberIndex)
{
   mvGroupPtr tempGroup = getCurrentGroupPtr();

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->addMember(memberIndex);
}

mvErrorEnum mvWorld_V2::removeMemberFromGroup(mvIndex memberIndex,\
   mvIndex groupIndex)
{
   mvGroupPtr tempGroup = getGroupPtr(groupIndex);

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->removeMember(memberIndex);
}

mvErrorEnum mvWorld_V2::removeMemberFromCurrentGroup(mvIndex memberIndex)
{
   mvGroupPtr tempGroup = getCurrentGroupPtr();

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->removeMember(memberIndex);
}

mvErrorEnum mvWorld_V2::findMemberFromGroup(mvIndex memberIndex,\
   mvIndex groupIndex) const
{
   mvConstGroupPtr tempGroup = getConstGroupPtr(groupIndex);

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->findMember(memberIndex);
}

mvErrorEnum mvWorld_V2::findMemberFromCurrentGroup(mvIndex memberIndex) const
{
   mvConstGroupPtr tempGroup = getConstGroupPtr(getCurrentGroup());

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGroup->findMember(memberIndex);
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
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return groupBehaviours.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameter_str(mvIndex index,\
   const char* param, const char* option)
{
   return groupBehaviours.setItemParameter_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return groupBehaviours.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setMainGroupBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameteri_str(\
   const char* param, mvIndex paramIndex)
{
   return groupBehaviours.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameter_str(\
   const char* param, const char* option)
{
   return groupBehaviours.setCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameterf_str(\
   const char* param, mvFloat num)
{
   return groupBehaviours.setCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParameterv_str(\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setCurrentItemParameterv_str(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameter_str(mvIndex index,\
   const char* param, const char** option) const
{
   return groupBehaviours.getItemParameter_str(index,param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex* paramIndex) const
{
   return groupBehaviours.getItemParameteri_str(index,param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return groupBehaviours.getItemParameterf_str(index,param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getItemParameterv_str(index,param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameter_str(\
   const char* param,const char** option) const
{
   return groupBehaviours.getCurrentItemParameter_str(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameteri_str(\
   const char* param, mvIndex* paramIndex) const
{
   return groupBehaviours.getCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterf_str(\
   const char* param, mvFloat* num) const
{
   return groupBehaviours.getCurrentItemParameterf_str(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterv_str(\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getCurrentItemParameterv_str(param, array,\
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
mvErrorEnum mvWorld_V2::getCurrentForceParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return forces.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return forces.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentForceParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return forces.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setForceParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return forces.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getGroupBehaviourParameteri_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri_str(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameteri(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != MV_NULL)
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

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri(groupIndex, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameteri_str(mvIndex groupIndex,\
   const char* param, mvIndex* outIndex) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri_str(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameteri_str(\
   mvIndex groupIndex, const char* param, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri_str(groupIndex, param, paramIndex);
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameteri_str(mvIndex index,\
   mvIndex groupIndex, const char* param, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri_str(groupIndex, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameteri(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getCurrentClassPtr();

   if (temp != MV_NULL)
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

   if (temp != MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri(groupIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return groups.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return groups.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentGroupParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return groups.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return groups.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return behaviours.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return behaviours.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentBehaviourParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return behaviours.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return behaviours.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getCurrentPathwayParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return pathways.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return pathways.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentPathwayParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return pathways.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return pathways.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getCurrentWaypointParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return waypoints.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return waypoints.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentWaypointParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return waypoints.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return waypoints.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getCurrentObstacleParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return obstacles.getCurrentItemParameteri_str(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return obstacles.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentObstacleParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return obstacles.setCurrentItemParameteri_str(param, paramIndex);
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
mvErrorEnum mvWorld_V2::getCurrentBodyParameteri_str(const char* param,\
   mvIndex* outIndex) const
{
   return bodies.getCurrentItemParameteri_str(param, outIndex);
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
mvErrorEnum mvWorld_V2::getBodyParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return bodies.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setCurrentBodyParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return bodies.setCurrentItemParameteri_str(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setBodyParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return bodies.setItemParameteri_str(index, param, paramIndex);
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
   if (option == MV_NULL)
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

   if (outIndex == MV_NULL)
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
   if (num == MV_NULL)
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
   if (noOfElements == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
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
   return MV_INVALID_WORLD_PARAMETER;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == MV_NULL)
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

mvConstBodyCapsulePtr mvWorld_V2::getConstBodyCapsulePtr(int index) const
{
   return bodies.getConstCapsulePtr(index);
}

mvBodyCapsulePtr mvWorld_V2::getBodyCapsulePtr(int index)
{
   return bodies.getCapsulePtr(index);
}

mvIndex mvWorld_V2::addNodeToPathway(mvIndex nIndex, mvIndex pIndex)
{
   // TODO : convert nodes
   mvPathwayPtr tempPathway = getPathwayPtr(pIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(nIndex);
}

mvIndex mvWorld_V2::addNodeToCurrentPathway(mvIndex wpIndex)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(wpIndex);
}

mvErrorEnum mvWorld_V2::removeNodeFromPathway(mvIndex wpIndex, mvIndex pIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->removeFirstNodeInstance(wpIndex);
}

mvErrorEnum mvWorld_V2::removeNodeFromCurrentPathway(mvIndex wpIndex)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->removeFirstNodeInstance(wpIndex);
}

mvIndex mvWorld_V2::addCurrentWaypointToCurrentPathway()
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(getCurrentWaypoint());
}

mvIndex mvWorld_V2::addCurrentWaypointToPathway(mvIndex pIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(getCurrentWaypoint());
}

mvErrorEnum mvWorld_V2::removeCurrentWaypointFromPathway(mvIndex pIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->removeFirstNodeInstance(getCurrentWaypoint());
}

mvErrorEnum mvWorld_V2::removeCurrentWaypointFromCurrentPathway()
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->removeFirstNodeInstance(getCurrentWaypoint());
}

mvErrorEnum mvWorld_V2::removeAllNodesFromPathway(mvIndex pwIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   tempPathway->removeAllNodes();
   return MV_NO_ERROR;
}

mvErrorEnum mvWorld_V2::removeAllNodesFromCurrentPathway()
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   tempPathway->removeAllNodes();
   return MV_NO_ERROR;
}

mvIndex mvWorld_V2::getCurrentNodeOfPathway(mvIndex pwIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->getCurrentNode();
}

mvIndex mvWorld_V2::getCurrentNodeOfCurrentPathway()
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->getCurrentNode();
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameteri(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri(nodeIndex, paramFlag, index);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameter(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameterf(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf(nodeIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameterv(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv(nodeIndex, paramFlag, array);
}


mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameteri(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri(nodeIndex, paramFlag, index);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameter(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameterf(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf(nodeIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameterv(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv(nodeIndex, paramFlag, array);
}


mvErrorEnum mvWorld_V2::setPathwayNodeParameteri_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvIndex index)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri_str(nodeIndex, param, index);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameter_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, const char* option)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameter_str(nodeIndex, param, option);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameterf_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat num)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf_str(nodeIndex, param, num);
}

mvErrorEnum mvWorld_V2::setPathwayNodeParameterv_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv_str(nodeIndex, param, array);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameteri_str(mvIndex nodeIndex,\
   const char* param, mvIndex index)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri_str(nodeIndex, param, index);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameter_str(mvIndex nodeIndex,\
   const char* param, const char* option)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameter_str(nodeIndex, param, option);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameterf_str(mvIndex nodeIndex,\
   const char* param, mvFloat num)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf_str(nodeIndex, param, num);
}

mvErrorEnum mvWorld_V2::setCurrentPathwayNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* array)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv_str(nodeIndex, param, array);
}


mvErrorEnum mvWorld_V2::getPathwayNodeParameteri(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri(nodeIndex, paramFlag,  outIndex);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameter(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameterf(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf(nodeIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameterv(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterv(nodeIndex, paramFlag, array,
      noOfParameters);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameteri(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri(nodeIndex, paramFlag, outIndex);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameter(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameterf(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf(nodeIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameterv(mvIndex nodeIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterv(nodeIndex, paramFlag, array,
      noOfParameters);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameteri_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri_str(nodeIndex, param, outIndex);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameter_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, const char** option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameter_str(nodeIndex, param, option);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameterf_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf_str(nodeIndex, param, num);
}

mvErrorEnum mvWorld_V2::getPathwayNodeParameterv_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterv_str(nodeIndex, param, array,\
      noOfParameters);
}


mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameteri_str(mvIndex nodeIndex,\
   const char* param, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri_str(nodeIndex, param,outIndex);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameter_str(mvIndex nodeIndex,\
   const char* param, const char** option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameter_str(nodeIndex, param,option);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameterf_str(mvIndex nodeIndex,\
   const char* param, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf_str(nodeIndex, param,num);
}

mvErrorEnum mvWorld_V2::getCurrentPathwayNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(\
      pathways.getCurrentIndex());

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterv_str(nodeIndex, param,array,\
      noOfParameters);
}

mvIndex mvWorld_V2::removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->removeNodeAt(nodeIndex);
}

mvIndex mvWorld_V2::removeCurrentPathwayNodeAt(mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getCurrentPathwayPtr();

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->removeNodeAt(nodeIndex);
}
