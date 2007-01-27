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
 */
#include "mvWorld2.h"
#include <cstring>
#include <new>

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return forces.getCurrentItemParametersv(param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersf(const char* param,\
   mvFloat* num)
{
   return forces.getCurrentItemParametersf(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameters(const char* param,\
   const char** option)
{
   return forces.getCurrentItemParameters(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return forces.getItemParametersv(index,param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersf(mvIndex index, const char* param,\
   mvFloat* num)
{
   return forces.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameters(mvIndex index, const char* param,\
   const char** option)
{
   return forces.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return forces.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return forces.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return forces.getCurrentItemParameter(paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return forces.getItemParameterv(index, paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return forces.getItemParameterf(index,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option)
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
void mvWorld_V2::applyToAllForces(void (someFunction)(mvForce*, void*),\
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
mvForce* mvWorld_V2::getCurrentForcePtr()
{
   return forces.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvForce* mvWorld_V2::getForcePtr(mvIndex index)
{
   return forces.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createForce(mvOptionEnum fType)
{
   mvForce* temp = new (std::nothrow) mvForce(fType);

   if (temp == NULL)
      return MV_NO_CURRENT_INDEX;

   return forces.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersv(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
   const char* param, mvFloat* num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersf(groupIndex, param, array, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameters(mvIndex groupIndex,\
   const char* param, const char** option)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameters(groupIndex, param, array, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParametersv(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersv(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParametersf(mvIndex index,\
   mvIndex groupIndex, const char* param, mvFloat* num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersf(groupIndex, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameters(mvIndex index,\
   mvIndex groupIndex, const char* param, const char** option)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvCount* noOfParameters)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersv(groupIndex, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameterf(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameter(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

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
   mvCount* noOfParameters)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterf(groupIndex, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameter(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameterv(groupIndex, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParametersv(mvIndex groupIndex,\
   const char* param, mvFloat* array)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv(groupIndex, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParametersf(mvIndex groupIndex,\
   const char* param, mvFloat num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterv(groupIndex, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentGroupBehaviourParameters(mvIndex groupIndex,\
   const char* param, const char* option)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp == NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameterf(groupIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameterf(mvIndex index,\
   mvIndex groupIndex,mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
mvGroupBehaviour_V2* mvWorld_V2::getCurrentGroupBehaviourPtr()
{
   return groupBehaviours.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviour_V2* mvWorld_V2::getGroupBehaviourPtr(mvIndex index)
{
   return groupBehaviours.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createGroupBehaviour(mvOptionEnum type)
{
   mvGroupBehaviour_V2* temp = new (std::nothrow) mvGroupBehaviour_V2(type);

   if (temp == NULL)
      return MV_NO_CURRENT_INDEX;

   return groupBehaviours.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return groups.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersf(const char* param,\
   mvFloat* num)
{
   return groups.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameters(const char* param,\
   const char** option)
{
   return groups.getCurrentItemParameters(param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return groups.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersf(mvIndex index, const char* param,\
   mvFloat* num)
{
   return groups.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameters(mvIndex index, const char* param,\
   const char** option)
{
   return groups.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return groups.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return groups.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return groups.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return groups.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return groups.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option)
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

bool checkGroupsForIDMatch(mvGroup* currentGroup, void* extraPtr)
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
   mvGroup* temp = NULL;

   if (groupID == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   temp = groups.findItemPtrInList(checkGroupsForIDMatch,(void*) groupID);

   if (temp != NULL)
   {
      return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
   }

   temp = new (std::nothrow) mvGroup(groupID)

   return groups.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return behaviours.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParametersf(const char* param,\
   mvFloat* num)
{
   return behaviours.getCurrentItemParametersf(param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameters(const char* param,\
   const char** option)
{
   return behaviours.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return behaviours.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersf(mvIndex index,\
 const char* param, mvFloat* num)
{
   return behaviours.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameters(mvIndex index,\
   const char* param, const char** option)
{
   return behaviours.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return behaviours.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return behaviours.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return behaviours.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return behaviours.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return behaviours.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option)
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
   return behaviours.addItem(new mvBehaviour_V2(bType));
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return pathways.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParametersf(const char* param,\
   mvFloat* num)
{
   return pathways.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameters(const char* param,\
   const char** option)
{
   return pathways.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return pathways.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersf(mvIndex index, const char* param,\
   mvFloat* num)
{
   return pathways.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameters(mvIndex index, const char* param,\
   const char** option)
{
   return pathways.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return pathways.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return pathways.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return pathways.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return pathways.getItemParameterv(index, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return pathways.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option)
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
   return pathways.addItem(new mvPathway());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return waypoints.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParametersf(const char* param,\
   mvFloat* num)
{
   return waypoints.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameters(const char* param,\
   const char** option)
{
   return waypoints.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return waypoints.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersf(mvIndex index,\
   const char* param, mvFloat* num)
{
   return waypoints.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameters(mvIndex index,\
   const char* param, const char** option)
{
   return waypoints.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return waypoints.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return waypoints.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return waypoints.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return waypoints.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return waypoints.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option)
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
   waypoints.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::applyToAllWaypoints(void (someFunction)(mvWaypoint*, void*),\
   void* extraPtr)
{
   waypoints.applyToAllItems(someFunction, extraPtr);
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
mvWaypoint * mvWorld_V2::getCurrentWaypointPtr()
{
   return waypoints.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypoint * mvWorld_V2::getWaypointPtr(mvIndex index)
{
   return waypoints.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createWaypoint(mvOptionEnum wType,\
   mvOptionEnum wShape, mvFloat x = 0, mvFloat y = 0, mvFloat z = 0)
{
   return waypoints.addItem(new mvWaypoint(wType,wShape, x, y, z));
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return obstacles.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParametersf(const char* param,\
   mvFloat* num)
{
   return obstacles.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameters(const char* param,\
   const char** option)
{
   return obstacles.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return obstacles.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersf(mvIndex index,\
   const char* param, mvFloat* num)
{
   return obstacles.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameters(mvIndex index,\
   const char* param, const char** option)
{
   return obstacles.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return obstacles.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return obstacles.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return obstacles.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return obstacles.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num)
{
   return obstacles.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameter(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option)
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
mvErrorEnum mvWorld_V2::setObstacleParameters(mvIndex index, const char* param,\
   const char* option)
{
   return obstacles.setItemParameters(index, param, option);
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
void mvWorld_V2::applyToAllObstacles(void (someFunction)(mvObstacle*, void*),\
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
mvObstacle * mvWorld_V2::getCurrentObstaclePtr()
{
   return obstacles.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstacle * mvWorld_V2::getObstaclePtr(mvIndex index)
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
   return obstacles.addItem(new mvObstacle(oType, oState, x, y, z));
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return bodies.getCurrentItemParametersv(param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParametersf(const char* param,\
   mvFloat* num)
{
   return bodies.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameters(const char* param,\
   const char** option)
{
   return bodies.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersv(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return bodies.getItemParametersv(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersf(mvIndex index, const char* param,\
   mvFloat* num)
{
   return bodies.getItemParametersf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameters(mvIndex index, const char* param,\
   const char** option)
{
   return bodies.getItemParameters(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return bodies.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return bodies.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return bodies.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return bodies.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* num)
{
   return bodies.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameter(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option)
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
void mvWorld_V2::applyToAllBodies(void (someFunction)(mvBody*, void*),\
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
mvBody * mvWorld_V2::getCurrentBodyPtr()
{
   return bodies.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBody * mvWorld_V2::getBodyPtr(mvIndex index)
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
   return bodies.addItem(new mvBody(bType, bShape,x,y,z));
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


}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::worldStep(mvFloat timeInSecs)
{
   //TODO : implement theis function
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeBody(mvIndex index, mvFloat timeInSecs)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::nudgeCurrentBody(mvFloat timeInSecs)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultWaypointForBody(mvIndex waypointIndex,\
//   mvIndex bodyIndex)
//{
//   mvBody* tempBody = bodies.getClassPtr(bodyIndex);
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = waypoints.convertIndex(waypointIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_WAYPOINT_INDEX_IS_INVALID;
//   }
//   tempBody->setDefaultWaypoint(convertedIndex);
//   return MV_NO_ERROR;
//}
//
// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultPathwayForBody(mvIndex pathwayIndex,\
//   mvIndex bodyIndex)
//{
//   mvBody* tempBody = bodies.getClassPtr(bodyIndex);
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = pathways.convertIndex(pathwayIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_PATHWAY_INDEX_IS_INVALID;
//   }
//   tempBody->setDefaultPathway(convertedIndex);
//   return MV_NO_ERROR;
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultBodyForBody(mvIndex targetIndex,\
//   mvIndex bodyIndex)
//{
//   mvBody* tempBody = bodies.getClassPtr(bodyIndex);
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = bodies.convertIndex(targetIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//   tempBody->setDefaultBody(convertedIndex);
//   return MV_NO_ERROR;
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultWeightForBody(mvFloat factor,\
//   mvIndex bodyIndex)
//{
//   mvBody* tempBody = bodies.getClassPtr(bodyIndex);
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   return tempBody->setDefaultBehaviourFactor(factor);
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultWaypointForCurrentBody(mvIndex wpIndex)
//{
//   mvBody* tempBody = bodies.getCurrentClassPtr();
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = waypoints.convertIndex(wpIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_WAYPOINT_INDEX_IS_INVALID;
//   }
//   tempBody->setDefaultWaypoint(convertedIndex);
//   return MV_NO_ERROR;
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultPathwayForCurrentBody(mvIndex pwIndex)
//{
//   mvBody* tempBody = bodies.getCurrentClassPtr();
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = pathways.convertIndex(pwIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_PATHWAY_INDEX_IS_INVALID;
//   }
//
//   tempBody->setDefaultWaypoint(convertedIndex);
//   return MV_NO_ERROR;
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultBodyForCurrentBody(mvIndex bodyIndex)
//{
//   mvBody* tempBody = bodies.getCurrentClassPtr();
//   mvIndex convertedIndex;
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   convertedIndex = bodies.convertIndex(bodyIndex);
//   if (convertedIndex == MV_NO_CURRENT_INDEX)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   tempBody->setDefaultBody(convertedIndex);
//   return MV_NO_ERROR;
//}

// /** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvErrorEnum mvWorld_V2::setDefaultWeightForCurrentBody(mvFloat factor)
//{
//   mvBody* tempBody = bodies.getCurrentClassPtr();
//
//   if (tempBody == NULL)
//   {
//      return MV_BODY_INDEX_IS_INVALID;
//   }
//
//   return tempBody->setDefaultBehaviourFactor(factor);
//}

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
   return groupBehaviours.setCurrentItemParameter(param, paramIndex);
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
   return groupBehaviours.setItemParametersv(index, param, option);
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
   return groupBehaviours.setCurrentItemParametersf(param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setCurrentMainGroupBehaviourParametersv(\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setCurrentItemParametersf(param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameters(mvIndex index,\
   const char* param, const char** option)
{
   return groupBehaviours.getItemParameters(index,param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex* paramIndex)
{
   return groupBehaviours.getItemParametersi(index,param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersf(mvIndex index,\
   const char* param, mvFloat* num)
{
   return groupBehaviours.getItemParametersf(index,param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParametersv(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return groupBehaviours.getItemParametersf(index,param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameters(\
   const char* param,const char** option)
{
   return groupBehaviours.getCurrentItemParameters(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersi(\
   const char* param, mvIndex* paramIndex)
{
   return groupBehaviours.getCurrentItemParametersi(param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersf(\
   const char* param, mvFloat* num)
{
   return groupBehaviours.getCurrentItemParametersf(param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParametersv(\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   return groupBehaviours.getCurrentItemParametersv(param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameter(mvIndex index,\
   mvParamEnum param, mvOptionEnum* option)
{
   return groupBehaviours.getItemParameter(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameteri(mvIndex index,\
   mvParamEnum param, mvIndex* paramIndex)
{
   return groupBehaviours.getItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterf(mvIndex index,\
   mvParamEnum param, mvFloat* num)
{
   return groupBehaviours.getItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getMainGroupBehaviourParameterv(mvIndex index,\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters)
{
   return groupBehaviours.getItemParameterv(index, param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameteri(\
   mvParamEnum param, mvIndex* paramIndex)
{
   return groupBehaviours.getItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterf(\
   mvParamEnum param, mvFloat* num)
{
   return groupBehaviours.getCurrentItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentMainGroupBehaviourParameterv(\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters)
{
   return groupBehaviours.getCurrentItemParameterv(index, param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParametersi(const char* param,\
   mvIndex* outIndex)
{
   return forces.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex)
{
   return forces.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentForceParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return forces.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getForceParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex groupIndex, const char* param, mvIndex* outIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersi(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParameteri(\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupBehaviourParameteri(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* outIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParameteri(groupIndex, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupBehaviourParametersi(mvIndex groupIndex,\
   const char* param, mvIndex* outIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametersi(groupIndex, param, outIndex);
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParametersi(mvIndex index,\
   mvIndex groupIndex, const char* param, mvIndex paramIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

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
   mvGroupBehaviour_V2* temp = groupBehaviours.getCurrentClassPtr();

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri(groupIndex, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setGroupBehaviourParameteri(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBehaviour_V2* temp = groupBehaviours.getClassPtr(index);

   if (temp != NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParameteri(groupIndex, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParametersi(const char* param,\
   mvIndex* outIndex)
{
   return groups.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex)
{
   return groups.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentGroupParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return groups.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getGroupParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex* outIndex)
{
   return behaviours.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex)
{
   return behaviours.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBehaviourParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return behaviours.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBehaviourParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex* outIndex)
{
   return pathways.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex)
{
   return pathways.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentPathwayParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return pathways.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getPathwayParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex* outIndex)
{
   return waypoints.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex)
{
   return waypoints.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentWaypointParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return waypoints.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getWaypointParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex* outIndex)
{
   return obstacles.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParametersi(mvIndex index,\
   const char* param, mvIndex* outIndex)
{
   return obstacles.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentObstacleParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return obstacles.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex)
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
   mvIndex* outIndex)
{
   return bodies.getCurrentItemParametersi(param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getCurrentBodyParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return bodies.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParametersi(mvIndex index, const char* param,\
   mvIndex* outIndex)
{
   return bodies.getItemParametersi(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
   mvIndex* outIndex)
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
   mvOptionEnum* option)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameteri(mvParamEnum paramFlag, mvIndex* outIndex)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfElements)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
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
   //TODO : implement the function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

mvIndex mvWorld_V2::getCurrentBody()
{
   return bodies.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentObstacle()
{
   return obstacles.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentWaypoint()
{
   return waypoints.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentForce()
{
   return forces.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentGroup()
{
   return groups.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentBehaviour()
{
   return behaviours.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentGroupBehaviour()
{
   return groupBehaviours.getCurrentIndex();
}

mvIndex mvWorld_V2::getCurrentPathway()
{
   return pathways.getCurrentIndex();
}
