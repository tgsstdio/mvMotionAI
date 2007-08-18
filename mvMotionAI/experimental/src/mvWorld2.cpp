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
#include MV_BEHAVIOUR_RESULT_HEADER_FILE_H_

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_InitialiseCurrentResultObject(mvFinalResultObject* finalResult,
   mvCurrentResultObject* currentResult);

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
void mvWorld_V2::applyToAllForces(void (someFunction)(mvBaseForcePtr, void*),\
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
mvBaseForcePtr mvWorld_V2::getCurrentForcePtr()
{
   return forces.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseForcePtr mvWorld_V2::getForcePtr(mvIndex index)
{
   return forces.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::createForce(mvOptionEnum fType)
{
   mvBaseForcePtr temp = MV_NULL;
   if (forceLoader == MV_NULL)
   {
      return MV_NULL;
   }

   temp = forceLoader->createAClassPtr(fType,MV_NULL);

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
   mvBaseActionPtr temp = behavLoader->createAClassPtr(type,MV_NULL);

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
   mvBaseActionPtr tempBehav = MV_NULL;

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
   entryLists.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteBody(mvIndex index)
{
   entryLists.deleteItem(index);
   return bodies.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::deleteCurrentBody()
{
   entryLists.deleteCurrentItem();
   return bodies.deleteCurrentItem();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::setCurrentBody(mvIndex index)
{
   entryLists.setCurrentIndex(index);
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

   mvEntryListPtr tempList = new (std::nothrow) mvEntryList();
   if (tempList == MV_NULL)
   {
      return MV_NULL;
   }

   // should have same index
   mvIndex correspondingBody = entryLists.addItem(tempList);
   if (correspondingBody != MV_NULL)
   {
      bCapsulePtr->bodyIndex = correspondingBody;
      return bodies.addItem(bCapsulePtr);
   }
   else
   {
      return MV_NULL;
   }
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
    * TODO : remove c strcopy - unsafe
    */
   if (id != MV_NULL)
   {
      strLen = strlen(id) + 1;
      worldID = new char[strLen];
      strncpy(worldID,id,strLen);
   }
   else
   {
      worldID = MV_NULL;
   }

   behavLoader = MV_NULL;
   forceLoader = MV_NULL;
   elapsedWorldTime = 0;
}

void mvWorld_V2::setForceLoader(mvForceLoaderListPtr fLoaderPtr)
{
   forceLoader = fLoaderPtr;
}

mvForceLoaderListPtr mvWorld_V2::getForceLoaderPtr() const
{
   return forceLoader;
}

mvFloat mvWorld_V2::getElapsedWorldTime() const
{
   return elapsedWorldTime;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::setActionLoader(mvActionLoaderListPtr bLoaderPtr)
{
   behavLoader = bLoaderPtr;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvActionLoaderListPtr mvWorld_V2::getActionLoader() const
{
   return behavLoader;
}

struct mvWorld_IntegrateLoopHelper
{
   public:
      mvWorldPtr currentWorld;
      mvFloat timeInSecs;
};

/*
 * private function
 */
void mvWorld_V2_IntegrateAllBodies(mvBodyCapsulePtr bodyPtr, void* extraPtr)
{
   mvWorld_IntegrateLoopHelper* helpContainer =
      (mvWorld_IntegrateLoopHelper*) extraPtr;
   mvWorldPtr currentWorld = helpContainer->currentWorld;
   mvFloat timeInSecs = helpContainer->timeInSecs;

   currentWorld->integrateBody(bodyPtr,timeInSecs);
}

void mvWorld_V2::initialiseCommonVariables(mvBehaviourResultPtr behavResult,
   mvForceResultPtr forceResult, mvFloat hTimeStep)
{
   mvConstBodyPtr currentBody = behavResult->getCurrentBodyPtr();
   behavResult->resetAll();
   forceResult->resetAll();

   behavResult->setCurrentTimeStep(hTimeStep);
   behavResult->setElaspedSystemTime(this->getElapsedWorldTime());

   forceResult->setCurrentTimeStep(hTimeStep);
   forceResult->setElaspedSystemTime(this->getElapsedWorldTime());

   // calculate predictions
   // A : predict position
   mvVec3 predictPos = currentBody->getVelocity();
   predictPos *= hTimeStep;
   predictPos += currentBody->getPosition();

   // B : predict final position
   mvVec3 predictFinalPos = currentBody->getFinalVelocity();
   predictFinalPos *= hTimeStep;
   predictFinalPos += currentBody->getPosition();

   // C: predict velocity == old_vel + max_accel * time
   // TODO : use current force
   mvVec3 predictVelocity = currentBody->getBodyDirection();
   predictVelocity *= currentBody->getSpeed() +
      (currentBody->getAcceleration() * hTimeStep);

   // D predict final velocity => predict_vel + past_vel_by_mvforces
   // past_vel_by_mvforces = (final_vel - vel)
   // TODO : use final force
   mvVec3 predictFinalVelocity;
   predictFinalVelocity.toZeroVec();
   predictFinalVelocity -= currentBody->getVelocity();
   predictFinalVelocity += currentBody->getFinalVelocity();
   predictFinalVelocity += predictVelocity;

   behavResult->setPositionPrediction(predictPos);
   behavResult->setFinalPositionPrediction(predictFinalPos);
   behavResult->setVelocityPrediction(predictVelocity);
   behavResult->setFinalVelocityPrediction(predictFinalVelocity);

   forceResult->setPositionPrediction(predictPos);
   forceResult->setFinalPositionPrediction(predictFinalPos);
   forceResult->setVelocityPrediction(predictVelocity);
   forceResult->setFinalVelocityPrediction(predictFinalVelocity);
}

void mvWorld_V2::integrateBody(mvBodyCapsulePtr bodyPtr, mvFloat timeInSecs)
{
   mvBehaviourResult finalBehavResult((mvConstWorldPtr) this,
      bodyPtr->getConstClassPtr());
   mvForceResult finalForceResult((mvConstWorldPtr) this,
      bodyPtr->getConstClassPtr());

   resetIntegrationLoop();
   checkIfWaypointContainsBody(bodyPtr);
   initialiseCommonVariables(&finalBehavResult,&finalForceResult,timeInSecs);
   calculateBehavioursOnBody(bodyPtr, &finalBehavResult);
   calculateAllForcesOnBody(bodyPtr, &finalForceResult);
   performIntegrationOfBody(bodyPtr, &finalBehavResult);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::worldStep(mvFloat timeInSecs)
{
   mvWorld_IntegrateLoopHelper helpContainer;

   if (isEnabled)
   {
      prepareIntegrationStep();
      calculateGroupBehaviours();

      helpContainer.currentWorld = this;
      helpContainer.timeInSecs = timeInSecs;
      bodies.applyToAllCapsules(mvWorld_V2_IntegrateAllBodies,&helpContainer);

      finaliseIntegrationStep(timeInSecs);
      elapsedWorldTime += timeInSecs;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_ITEM_IS_NOT_ENABLED;
   }
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

   if (isEnabled)
   {
      prepareIntegrationStep();
      calculateGroupBehaviours();
      integrateBody(tempCapsulePtr,timeInSecs);
      finaliseIntegrationStep(timeInSecs);
      elapsedWorldTime += timeInSecs;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_ITEM_IS_NOT_ENABLED;
   }
}

struct mvWorldV2_CalcForceHelperStruct
{
   public:
      mvWorldPtr currentWorld;
      mvBodyCapsulePtr currentBody;
      mvForceResultPtr finalResult;
};

template <class mvFinalResultObject, class mvCurrentResultObject>
void mvWorld_InitialiseCurrentResultObject(mvFinalResultObject* finalResult,
   mvCurrentResultObject* currentResult)
{
   // transfer values across
   currentResult->setCurrentTimeStep(finalResult->getTimeStep());
   currentResult->setElaspedSystemTime(finalResult->getElapsedSystemTime());

   currentResult->setPositionPrediction(\
      finalResult->predictPositionOfCurrentBody());
   currentResult->setFinalPositionPrediction(\
      finalResult->predictFinalPositionOfCurrentBody());
   currentResult->setVelocityPrediction(\
      finalResult->predictVelocityOfCurrentBody());
   currentResult->setFinalVelocityPrediction(\
      finalResult->predictFinalVelocityOfCurrentBody());
}

void mvWorld_InitialCurrentForceResult(mvForceResultPtr finalResult,
   mvForceResultPtr currentResult)
{
   mvWorld_InitialiseCurrentResultObject<mvForceResult, mvForceResult>
      (finalResult, currentResult);
}

bool mvWorld_CalculateGlobalForceOnBody(mvBaseForcePtr currentForce,
   mvForceResultPtr currentResult)
{
  // calculate force
   if (currentForce)
   {
      return currentForce->calcFullForces(currentResult);
   }
   else
   {
      return false;
   }
}

bool mvWorld_V2::doesWaypointContainBody(mvIndex wPointIndex) const
{
   mvConstWaypointCapsulePtr tempCapsulePtr =\
      waypoints.getConstCapsulePtr(wPointIndex);

   if (tempCapsulePtr)
   {
      return tempCapsulePtr->containsBody;
   }
   else
   {
      return false;
   }
}

bool mvWorld_CalculateLocalForceOnBody(mvForceCapsulePtr fCapsulePtr,
   mvBaseForcePtr currentForce, mvForceResultPtr currentResult)
{
   // current force parameters
   // check if any waypoints contain this body from this force's assigned wpoints
   mvConstWorldPtr currentWorld = currentResult->getWorldPtr();
   mvUniqueSet& linkedWaypoints = fCapsulePtr->linkedWaypoints;

   // start loop
   linkedWaypoints.beginLoop();
   while(!linkedWaypoints.isLoopFinished()
   && !currentWorld->doesWaypointContainBody(linkedWaypoints.getCurrentIndex()))
   {
      linkedWaypoints.nextIndex();
   }

   // hopefully ends correctly
   if (linkedWaypoints.isLoopFinished())
   {
      return false;
   }

   // if true for any waypoints
   return currentForce->calcFullForces(currentResult);
}

void mvWorld_CalculateForceOnSingleBody(mvForceCapsulePtr fCapsulePtr,\
   void* extraPtr)
{
   mvBaseForcePtr currentForce = fCapsulePtr->getClassPtr();
   mvWorldV2_CalcForceHelperStruct* helper =\
      (mvWorldV2_CalcForceHelperStruct*) extraPtr;
   mvForceStatus forceStatus;

   mvForceResultPtr finalResult = helper->finalResult;
   // check if enabled.
   if (currentForce->isEnabled())
   {
      // store
      mvForceResult currentResult(helper->currentWorld,
         finalResult->getCurrentBodyPtr());
      bool hasCalcForce = true;

      // check this world force filter
      forceStatus.applyingNone();
      currentForce->filter(forceStatus);

      // pre action filter
      // stop force if not to be apply to all bodies
      if (fCapsulePtr->isGlobalForce() && !forceStatus.onlyLocalForce)
      {
         mvWorld_InitialCurrentForceResult(finalResult, &currentResult);
         hasCalcForce = mvWorld_CalculateGlobalForceOnBody(currentForce,\
            &currentResult);
      }
      // continue with local action if not restricted to being global force
      else if (!forceStatus.onlyGlobalForce)
      {
         mvWorld_InitialCurrentForceResult(finalResult, &currentResult);
         hasCalcForce = mvWorld_CalculateLocalForceOnBody(fCapsulePtr,
            currentForce, &currentResult);
      }

      if (hasCalcForce)
      {
         // post calculation filter

         // sum forces
      }
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld_V2::calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr,\
   mvForceResultPtr finalForceResult)
{
   mvWorldV2_CalcForceHelperStruct helper;
   helper.currentWorld = this;
   helper.currentBody = bodyPtr;
   helper.finalResult = finalForceResult;

   if (applyAllForces)
   {
      forces.applyToAllCapsules(mvWorld_CalculateForceOnSingleBody, &helper);
   }
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
   capsulePtr->containsBody = false;
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
   capsulePtr->performIntegration = false;
   capsulePtr->futureVelocity.toZeroVec();
   capsulePtr->additionalVelocity.toZeroVec();
   capsulePtr->futureForce.toZeroVec();
   capsulePtr->additionalForce.toZeroVec();
   capsulePtr->futureTorque.toZeroVec();
   capsulePtr->additionalTorque.toZeroVec();
   capsulePtr->futureOmega.toZeroVec();
   capsulePtr->additionalOmega.toZeroVec();
}

void mvWorld_Prepare_Force_Capsule(mvForceCapsulePtr capsulePtr,\
   void* extraPtr)
{
   //mvWorldPtr currentWorld = (mvWorldPtr) extraPtr;

   // TODO : prefilter
   capsulePtr->isActive = true;
}

void mvWorld_V2::prepareIntegrationStep()
{
   // TODO : reset bodies
   bodies.applyToAllCapsules(mvWorld_Prepare_Body_Capsule,MV_NULL);

   // reset forces
   forces.applyToAllCapsules(mvWorld_Prepare_Force_Capsule, this);
}

bool mvWorld_V2::hasGroupChanged(mvIndex groupNo)
{
   mvGroupCapsulePtr tempCapsule = groups.getCapsulePtr(groupNo);

   if (tempCapsule == MV_NULL)
   {
      return false;
   }
   else
   {
      return tempCapsule->hasChanged;
   }
}

struct mvWorld_GroupBehaviourNodeHelper
{
   public:
      mvWorldPtr currentWorld;
      mvOptionEnum gbType;
      mvIndex gbIndex;
      bool isEnabled;
};

void mvWorld_CalculateEachGroupInGroupBehaviour(mvGroupBehaviourNodePtr currentNode,
   void* extraPtr)
{

   mvWorld_GroupBehaviourNodeHelper* container =
      (mvWorld_GroupBehaviourNodeHelper*) extraPtr;
   mvWorldPtr currentWorld = container->currentWorld;
   mvOptionEnum defaultType = container->gbType;
   mvIndex currentGBehaviour = container->gbIndex;
   bool isEnabled = container->isEnabled;

   mvIndex groupNo = currentNode->getGroup();
   mvGroupPtr currentGroup = currentWorld->getGroupPtr(groupNo);
   if (currentGroup == MV_NULL)
   {
      return;
   }

   bool hasChanged =  currentWorld->hasGroupChanged(groupNo);
   mvBaseActionPtr groupAction = currentNode->getActionPtr();
   mvGroupNodeMemberList& nodeMemberList = currentNode->memberDataList;
   mvGroupMemberNodePtr memberNode = NULL;

   if (hasChanged)
   {
      // add/remove members  in group beh node that be same as group
      currentGroup->setToFirstMember();
      mvIndex lhsSetIndex, rhsMemberIndex;

      mvBaseActionPtr tempMemberActionPtr = NULL;
      nodeMemberList.toFirstMember();
      while (!currentGroup->areMembersFinished() &&
         !nodeMemberList.hasAllNodesBeenVisited() )
      {
         if (nodeMemberList.hasAllNodesBeenVisited())
         {
            // keep adding new nodes to node member list
            lhsSetIndex = currentGroup->getCurrentMember();
            if (currentWorld->getActionLoader() != MV_NULL)
            {
               tempMemberActionPtr =
                  currentWorld->getActionLoader()->createAClassPtr(\
                     defaultType, groupAction);
               nodeMemberList.insertBeforeCurrentMember(lhsSetIndex,tempMemberActionPtr);
               // subscription sent to body
               currentWorld->addBehaviourToList(lhsSetIndex,\
                  MV_EXISTING_GROUP_BEHAVIOUR, currentGBehaviour, groupNo);
            }
            currentGroup->toNextMember();
         }
         else if (currentGroup->areMembersFinished())
         {
            // remove all trailing member nodes
            nodeMemberList.deleteCurrentMember();
         }
         else
         {
            // both sides have still contain items

            memberNode = nodeMemberList.getCurrentMember();
            rhsMemberIndex = memberNode->memberIndex;
            lhsSetIndex = currentGroup->getCurrentMember();

            if (lhsSetIndex > rhsMemberIndex)
            {
               // remove all rhs member nodes preceding node
               nodeMemberList.deleteCurrentMember();
            }
            else if (lhsSetIndex == rhsMemberIndex)
            {
               // skip by incrementing both lhs & rhs
               currentGroup->toNextMember();
               nodeMemberList.toNextMember();
            }
            else // (lhsSetIndex < rhsMemberIndex)
            {
               // insert ahead of position
               if (currentWorld->getActionLoader() != MV_NULL)
               {
                  tempMemberActionPtr =
                     currentWorld->getActionLoader()->createAClassPtr(\
                        defaultType, groupAction);
                  nodeMemberList.insertBeforeCurrentMember(lhsSetIndex,tempMemberActionPtr);
                  // subscription sent to body
                  currentWorld->addBehaviourToList(lhsSetIndex,\
                     MV_EXISTING_GROUP_BEHAVIOUR, currentGBehaviour, groupNo);
               }
               currentGroup->toNextMember();
            }
         }
      }
   }

   nodeMemberList.toFirstMember();
   while (!nodeMemberList.hasAllNodesBeenVisited())
   {
      memberNode = nodeMemberList.getCurrentMember();
   }

   if (groupAction != NULL && isEnabled && currentNode->isEnabled)
   {
      // TODO: perform groupOp
      mvGroupBehaviourResult groupDataModule(currentWorld,\
         &(currentNode->memberDataList));

      groupAction->groupOp(&groupDataModule);
   }
}

void mvWorld_CalculateForEachGroupBehaviour(\
   mvIndex groupBehaviourIndex, void* extraPtr)
{
   // foreach group in group behaviour
   mvWorldPtr currentWorld =  (mvWorldPtr) extraPtr;
   mvWorld_GroupBehaviourNodeHelper container;

   mvGroupBehaviourPtr currentGroupBehav = currentWorld->getGroupBehaviourPtr(\
      groupBehaviourIndex);
   if (currentGroupBehav != NULL && currentGroupBehav->getDefaultActionPtr() != MV_NULL)
   {
      container.gbIndex = groupBehaviourIndex;
      container.currentWorld = currentWorld;
      container.isEnabled = currentGroupBehav->isEnabled;
      container.gbType = currentGroupBehav->getDefaultActionPtr()->getType();
      currentGroupBehav->groupNodeList.applyToAllItems(\
         mvWorld_CalculateEachGroupInGroupBehaviour, &container);
   }
}

void mvWorld_V2::calculateGroupBehaviours() // 1
{
   // foreach group behaviour
   groupBehaviours.applyToAllItemsByItemIndex(mvWorld_CalculateForEachGroupBehaviour,this);
}

void mvWorld_V2::checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr) // part of 2
{
// TODO : calculate world functions
}

struct mvWorld_CalcBehavOnListHelper
{
   public:
      mvBehaviourResultPtr finalResult;
      mvBodyCapsulePtr bCapsule;
};

mvBaseActionPtr initialiseResults(mvBEntryPtr nodeInfo, mvIndex bodyIndex,
   mvConstWorldPtr currentWorld,  mvBehaviourResult& currentResult,\
   mvBehaviourResultPtr finalResult)
{
   mvBaseActionPtr currentAction = MV_NULL;
   mvBaseActionPtr groupActionPtr = MV_NULL;
   // isolate result

   if (nodeInfo == MV_NULL)
   {
      return MV_NULL;
   }

   mvOptionEnum nodeType = nodeInfo->getEntryType();
   mvIndex behaviourIndex = nodeInfo->getBehaviour();
   mvIndex groupIndex = nodeInfo->getGroup();

   switch(nodeType)
   {
      case MV_EXISTING_BEHAVIOUR:
         mvConstBehaviourPtr globalBehav =\
            currentWorld->getConstBehaviourPtr(behaviourIndex);

         // exit if behaviour does not exist
         if (globalBehav == MV_NULL || !globalBehav->isEnabled())
         {
            return MV_NULL;
         }

         // exit if action does not exist
         currentAction = globalBehav->getActionPtr();
         break;
      case MV_EXISTING_GROUP_BEHAVIOUR:
         mvConstGroupBehaviourPtr globalGrpBehav =\
            currentWorld->getConstGroupBehaviourPtr(behaviourIndex);

         // exit if behaviour does not exist
         if (globalGrpBehav == MV_NULL || !globalGrpBehav->isEnabled)
         {
            return MV_NULL;
         }

         mvConstGroupPtr checkGroupPtr =\
            currentWorld->getConstGroupPtr(groupIndex);

         // exit if group does not exist
         if (checkGroupPtr == MV_NULL || !checkGroupPtr->isEnabled)
         {
            return MV_NULL;
         }

         // check if group is linked to group behaviour
         mvGroupBehaviourNodePtr groupNodePtr =\
            globalGrpBehav->findGroupNode(groupIndex);

         if (groupNodePtr == MV_NULL || !groupNodePtr->isEnabled)
         {
            return MV_NULL;
         }

         groupActionPtr = groupNodePtr->getActionPtr();
         if (groupActionPtr == MV_NULL)
         {
            return MV_NULL;
         }

         // find member node and action
         mvGroupMemberNodePtr memberNodePtr = groupNodePtr->findMemberInNode(\
            bodyIndex);

         if (memberNodePtr == MV_NULL)
         {
            return MV_NULL;
         }

         currentAction = memberNodePtr->getActionPtr();
         break;
      default:
         currentAction = nodeInfo->getActionPtr();
         break;
   }

    // set behaviour result to variables

   currentResult.setGroupBehaviourNode(groupActionPtr);
   currentResult.setBehaviourIndex(behaviourIndex);
   currentResult.setGroupIndex(groupIndex);
   /*
   currentResult.setCurrentTimeStep(finalResult->getTimeStep());
   currentResult.setElaspedSystemTime(finalResult->getElapsedSystemTime());
   // TODO : prediction action
   currentResult.setPositionPrediction(\
      finalResult->predictPositionOfCurrentBody());
   currentResult.setFinalPositionPrediction(\
      finalResult->predictFinalPositionOfCurrentBody());
   currentResult.setVelocityPrediction(\
      finalResult->predictVelocityOfCurrentBody());
   currentResult.setFinalVelocityPrediction(\
      finalResult->predictFinalVelocityOfCurrentBody());
   */
   mvWorld_InitialiseCurrentResultObject<mvBehaviourResult, mvBehaviourResult>
      (finalResult, &currentResult);

   return currentAction;
}

void mvWorld_ConfineMotionVector(mvParamEnum mType, mvOptionEnum domain,
   mvVec3& motionVector)
{
   switch(mType)
   {
      // straight line
      case MV_VELOCITY:
      case MV_FORCE_VECTOR:
      case MV_ACCELERATION_VECTOR:
      case MV_DIRECTION:
         switch(domain)
         {
            //todo : case MV_ANY_PLANE:
            //todo : case MV_ANY_LINE:
            case MV_X_AXIS_ONLY:
               motionVector.setY(0);
            case MV_XY_PLANE:
               motionVector.setZ(0);
               break;
            case MV_Y_AXIS_ONLY:
               motionVector.setZ(0);
            case MV_YZ_PLANE:
               motionVector.setX(0);
               break;
            case MV_Z_AXIS_ONLY:
               motionVector.setX(0);
            case MV_XZ_PLANE:
               motionVector.setY(0);
               break;
            default:
            case MV_FULL_3D:
               break;
         }
         break;
      // rotation/sphere
      case MV_ROTATION:
      case MV_TORQUE:
      case MV_OMEGA:
         switch(domain)
         {
            //todo :case MV_ANY_PLANE:
            //todo :case MV_ANY_LINE:
            //todo :case MV_X_AXIS_ONLY:
            //todo :case MV_Y_AXIS_ONLY:
            //todo :case MV_Z_AXIS_ONLY:
            case MV_XY_PLANE:
               motionVector.setX(0);
               motionVector.setY(0);
               break;
            case MV_XZ_PLANE:
               motionVector.setX(0);
               motionVector.setZ(0);
               break;
            case MV_YZ_PLANE:
               motionVector.setY(0);
               motionVector.setZ(0);
               break;
            default:
            case MV_FULL_3D:
               break;
         }
         break;
      default:
         break;
   }
}

void mvWorld_SumBehaviourResults(mvBehaviourResultPtr summedResult,
   const mvBehaviourResult& actionResult, bool isConfined)
{
   mvVec3 actionVec, totalVec;
   mvMotionTypeEnum currentMotion;
   mvEffectTypeEnum currentEffect;

   const mvMotionTypeEnum defaultMotion =
      (actionResult.isSteeringMotionDefault()) ?
      MV_STEERING_MOTION : MV_DIRECTIONAL_MOTION;
   const mvEffectTypeEnum defaultEffect =
      (actionResult.isGlobalEffectDefault())  ?
      MV_GLOBAL_EFFECT : MV_LOCAL_EFFECT;

   mvConstBodyPtr currentBody = summedResult->getCurrentBodyPtr();

   if (currentBody == MV_NULL)
   {
      return;
   }

   // add forces
   if (actionResult.isForceSet())
   {
      totalVec = summedResult->getForce();
      currentMotion = actionResult.getForceMotionType();
      currentEffect = actionResult.getForceEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getForce();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      if (isConfined)
      {
         mvWorld_ConfineMotionVector(MV_FORCE_VECTOR, currentBody->getDomain(),
            actionVec);
      }

      totalVec += actionVec;
      summedResult->setForce(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isAccelerationSet())
   {
      totalVec = summedResult->getAcceleration();
      currentMotion = actionResult.getAccelerationMotionType();
      currentEffect = actionResult.getAccelerationEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getAcceleration();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      if (isConfined)
      {
         mvWorld_ConfineMotionVector(MV_ACCELERATION_VECTOR, currentBody->getDomain(),
            actionVec);
      }

      totalVec += actionVec;
      summedResult->setAcceleration(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isVelocitySet())
   {
      totalVec = summedResult->getVelocity();
      currentMotion = actionResult.getVelocityMotionType();
      currentEffect = actionResult.getVelocityEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getVelocity();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function

      }

      if (currentMotion == MV_DIRECTIONAL_MOTION)
      {
         actionVec -= currentBody->getFinalVelocity();
      }

      if (isConfined)
      {
         mvWorld_ConfineMotionVector(MV_VELOCITY, currentBody->getDomain(),
            actionVec);
      }


      totalVec += actionVec;
      summedResult->setVelocity(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isTorqueSet())
   {
      totalVec = summedResult->getTorque();
      currentMotion = actionResult.getTorqueMotionType();
      currentEffect = actionResult.getTorqueEffectType();

      if (currentMotion == MV_DEFAULT_MOTION)
      {
         currentMotion = defaultMotion;
      }

      if (currentEffect == MV_DEFAULT_EFFECT)
      {
         currentEffect = defaultEffect;
      }

      actionVec = actionResult.getTorque();
      if (currentEffect == MV_LOCAL_EFFECT)
      {
         // TODO : delocalise function
      }

      if (isConfined)
      {
         mvWorld_ConfineMotionVector(MV_TORQUE, currentBody->getDomain(),
            actionVec);
      }

      totalVec += actionVec;
      summedResult->setTorque(totalVec, MV_STEERING_MOTION,
         MV_GLOBAL_EFFECT);
   }

   if (actionResult.isDirectionSet())
   {
      //TODO : direction addition/subtraction
   }

   if (actionResult.isOmegaSet())
   {
      //TODO : quaternion addition/subtraction
   }

   if (actionResult.isQuaternionSet())
   {
      //TODO : quaternion addition/subtraction
   }

   if (actionResult.isRotationSet())
   {
      //TODO : rotation addition/subtraction
   }
}

void mvWorld_CalculateEntryByWeightedSum(mvEntryListNodePtr eNodePtr,\
   void* extraPtr)
{
   if (eNodePtr->isEnabled)
   {
      // setting variables
      mvWorld_CalcBehavOnListHelper* helper = (mvWorld_CalcBehavOnListHelper*)\
         extraPtr;
      mvBodyCapsulePtr bCapsule = helper->bCapsule;
      mvBehaviourResultPtr finalResult = helper->finalResult;
      mvConstWorldPtr currentWorld = finalResult->getWorldPtr();

      mvBEntryPtr nodeInfo = eNodePtr->getEntryPtr();
      bool isConfined = eNodePtr->entryFlags.confined;

      mvBehaviourResult currentResult(finalResult->getWorldPtr(),
         finalResult->getCurrentBodyPtr());
      mvBaseActionPtr currentAction = initialiseResults(nodeInfo,\
         bCapsule->bodyIndex, currentWorld, currentResult, finalResult);

      if (currentAction != MV_NULL)
      {
         // calc action
         bool addActionToResult = currentAction->bodyOp(&currentResult);

         if (addActionToResult)
         {
            mvWorld_SumBehaviourResults(finalResult, currentResult,isConfined);
            bCapsule->performIntegration = true;
         }
      }
   }
}

void mvWorld_V2::calculateBehavioursOnBody(mvBodyCapsulePtr bCapsulePtr,\
   mvBehaviourResultPtr finalResult)
{
   // TODO : code here

   // Step 1 - fetch body
   mvConstBodyPtr currentBody = bCapsulePtr->getConstClassPtr();

   // Step 1b : check enable flags
   if (!currentBody->enabled)
   {
      return;
   }

   // Step 2 - fetch entry list
   mvIndex entryListIndex = bCapsulePtr->bodyIndex;
   if (entryListIndex == MV_NULL)
   {
      // error
      return;
   }

   mvEntryListPtr currentEntryList = entryLists.getClassPtr(entryListIndex);

   if (currentEntryList == MV_NULL || !currentEntryList->isEnabled)
   {
      return;
   }

   // initialise mvbehaviour result values
   mvWorld_CalcBehavOnListHelper helperModule;

   helperModule.finalResult = finalResult;
   helperModule.bCapsule = bCapsulePtr;

   // integration mode
   mvOptionEnum integrationMode = currentEntryList->getMode();
   switch(integrationMode)
   {
      case MV_WEIGHTED:
      // TODO : case MV_XOR:
      // TODO : case MV_TREE:
      // TODO : case MV_RANDOM:
      // TODO : case MV_RANDOMISED_WEIGHTED:
      default:
         currentEntryList->applyToAllEntries(mvWorld_CalculateEntryByWeightedSum,
            &helperModule);
   }
}

void mvWorld_V2::performIntegrationOfBody(mvBodyCapsulePtr bodyPtr,
   mvBehaviourResultPtr resultModule)
{
   mvVec3 tempVector;
   // ASSUME resultModule is "NORMALISED" - global steering motions
   // TODO : normalize bool

   if (!bodyPtr->performIntegration)
   {
      return;
   }
   // set
   bodyPtr->futureForce = resultModule->getForce();
   bodyPtr->futureVelocity = resultModule->getVelocity();
   bodyPtr->futureTorque = resultModule->getTorque();
   bodyPtr->futureOmega = resultModule->getOmega();

   // translate
   // TODO : accel to force
   // F = ma
   tempVector = resultModule->getAcceleration();
   tempVector *= bodyPtr->getConstClassPtr()->getMass();

   bodyPtr->futureForce += tempVector;
   // TODO : direction to omega

   // TODO : rotation to omega

   // TODO : quaternion to omega

}

void mvWorld_calculateIntegrationOfBody(mvBodyCapsulePtr capsulePtr,
   void *extraPtr)
{
   mvWorld_IntegrateLoopHelper* helperModule =
      (mvWorld_IntegrateLoopHelper*) extraPtr;

   if (!capsulePtr->performIntegration)
   {
      return;
   }

   /* Purpose of this is to
    * // MOTION
    * 13. convert all motion to velocity
    * 10. limit the motion by
    *    - body's max speed
    *    - body's max acceleration
    *    - body's max deceleration
    * 6. calc the body's 'own' propulsion velocity
    * 9. create the body's equivalent force
    * 2. sum the mvForces and mvBehaviours together
    * 4. create a final velocity and final force which are
    *     - useful when used separately.
    *     - exactly the same thing in different forms
    * 1. calculate the final position of the body
    * // ROTATION
    * 2. sum the mvForce's rotation and mvBehaviours rotation together
    * 15. calculate body shape's radius
    * 14. convert all circular (motion) to omega
    * 7. calc the body's 'own' prepulsion omega
    * 8. create the body's equivalent torque
    * 5. create the final omega (in degree) and torque of equivalent
    *    value
    * 10. limit the motion by
    *    - body's max turning/rolling/yawing angle
    *    - body's max turning/rolling/yawing omega
    * 3. calculate the final rotation of the body
    */

   // calculate change in velocity = delta_vel
   // accel = delta_vel / time_in_secs
   // force = accel * mass
   // torque = length * force

// TODO : calculate world functions
   mvBodyPtr currentBody = capsulePtr->getClassPtr();

   mvFloat vel[2][3], pos[2][3], c1, c2;
   mvIndex i = 0;

   mvFloat hTimeStep = helperModule->timeInSecs;
   mvFloat inverse_h = 1;
   inverse_h /= hTimeStep;

   // 13. convert all motion to velocity
   // currently all values are components

   // force => accel
   mvVec3 accelVec = capsulePtr->futureForce;
   accelVec /= currentBody->getMass();

   // TODO : have h, h^2, 1/h, 1/h^2 timesteps
   // deltaVelocity += accel
   accelVec *= hTimeStep;
   mvVec3 deltaVelocity = capsulePtr->futureVelocity;
   deltaVelocity += accelVec;

   mvFloat bodySpeed = currentBody->getSpeed();
   mvVec3 bodyVelocity = currentBody->getVelocity();

   // end velocity
   bodyVelocity += deltaVelocity;
    /* 10. limit the motion by
    *    - body's max speed
    *    - body's max acceleration
    *    - body's max deceleration
    */

   mvFloat incrSpeedDelta = currentBody->getAcceleration();
   incrSpeedDelta *= hTimeStep;

   mvFloat decrSpeedDelta = currentBody->getDeceleration();
   decrSpeedDelta *= hTimeStep;

   mvFloat maxSpeed = currentBody->getMaxSpeed();
   // TODO : separate reverse speed
   mvFloat minSpeed = 0;

   mvFloat compareSpeed = bodySpeed + incrSpeedDelta;
   if (compareSpeed < maxSpeed)
   {
      maxSpeed = compareSpeed;
   }

   compareSpeed = bodySpeed + decrSpeedDelta;
   if (compareSpeed > minSpeed)
   {
      minSpeed = compareSpeed;
   }

   mvFloat futureSpeed = bodyVelocity.length();
   mvVec3 futureUnitVelocity = bodyVelocity.normalize();

   //compareSpeed = bodySpeed + decrSpeedDelta;
   if (futureSpeed > maxSpeed)
   {
      futureSpeed = maxSpeed;
   }
   else if (futureSpeed < minSpeed)
   {
      futureSpeed = minSpeed;
   }

   //* 6. calc the body's 'own' propulsion velocity
   bodyVelocity = futureUnitVelocity;
   bodyVelocity *= futureSpeed;
   // saving velocity
   deltaVelocity = currentBody->getVelocity();
   // set velocity
   currentBody->setVelocity(bodyVelocity);

   // TODO * 9. create the body's equivalent force
   // delta = old_vel - new vel
   // a = delta_vel * 1/h
   accelVec = bodyVelocity;
   accelVec -= deltaVelocity;
   accelVec *= inverse_h;
   accelVec *= currentBody->getMass();
   currentBody->setBodysForce(accelVec);

    /* 4. create a final velocity and final force which are
    *     - useful when used separately.
    *     - exactly the same thing in different forms
    */

   // repeat steps force -> accel -> delta_vel => accel => force
   accelVec = capsulePtr->additionalForce;
   // add bodys' force
   accelVec += currentBody->getBodysForce();
   accelVec /= currentBody->getMass();
   accelVec *= hTimeStep;
   // accel -> delta_vel
   deltaVelocity = accelVec;
   deltaVelocity *= hTimeStep;
   // sum velocities to final velocity
   bodyVelocity = capsulePtr->additionalVelocity;
   bodyVelocity += currentBody->getVelocity();
   bodyVelocity += deltaVelocity;
   // store final velocity
   deltaVelocity = currentBody->getFinalVelocity();
   currentBody->setFinalVelocity(bodyVelocity);

   // calculating final force
   accelVec = bodyVelocity;
   accelVec -= deltaVelocity;
   accelVec *= inverse_h;
   accelVec *= currentBody->getMass();
   currentBody->setFinalForce(accelVec);

   bodyVelocity = currentBody->getFinalVelocity();

   //* 1. calculate the final position of the body
   vel[0][0] = deltaVelocity.getX();
   vel[0][1] = deltaVelocity.getY();
   vel[0][2] = deltaVelocity.getZ();
   vel[1][0] = bodyVelocity.getX();
   vel[1][1] = bodyVelocity.getY();
   vel[1][2] = bodyVelocity.getZ();

   pos[0][0] = currentBody->getPosition().getX();
   pos[0][1] = currentBody->getPosition().getY();
   pos[0][2] = currentBody->getPosition().getZ();

   // TODO : rotation

   for (i = 0; i < 3; i++)
   {
      //vel[0][i] += dir[i] * speed[0];
      //vel[1][i] += dir[i] * speed[1];
      //vel[0][j] *= speed[0];
      //vel[1][j] *= speed[1];

      /*
      * 5.1.2.6.2 calculate the position
      */
      c1 = hTimeStep * vel[0][i];
      c2 = hTimeStep * vel[1][i];
      pos[1][i] = pos[0][i] + 0.5 * (c1 + c2);
   }

   //currentBody->setVelocity(vel[1][0],vel[1][1],vel[1][2]);
   currentBody->setPosition(pos[1][0],pos[1][1],pos[1][2]);
}

void mvWorld_Finalise_Groups(mvGroupCapsulePtr capsulePtr, void* extraPtr)
{
   capsulePtr->hasChanged = false;
}

void mvWorld_V2::finaliseIntegrationStep(mvFloat timeInSecs)
{
   mvWorld_IntegrateLoopHelper helperModule;
   helperModule.currentWorld = this;
   helperModule.timeInSecs = timeInSecs;

   groups.applyToAllCapsules(mvWorld_Finalise_Groups,this);
   bodies.applyToAllCapsules(mvWorld_calculateIntegrationOfBody, &helperModule);
}

// WORLD STEP FUNCTIONS

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::addBehaviourToList(mvIndex listIndex, mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_NULL;
   }

   mvBaseActionPtr actionPtr = NULL;
   mvIndex convertedBehavIndex;
   mvIndex convertedGroupIndex;

   switch(bType)
   {
      default:
         if (behavLoader != MV_NULL)
         {
            actionPtr = behavLoader->createAClassPtr(bType, MV_NULL);
         }
         else
         {
            return MV_NULL;
         }

         // behaviour not found or reserved
         if (actionPtr == MV_NULL)
         {
            return MV_NULL;
         }
         return tempList->addNewBehaviourEntry(bType, actionPtr);
      case MV_EXISTING_BEHAVIOUR:
         convertedBehavIndex = behaviours.convertIndex(behaviourIndex);
         return tempList->addExistingBehaviourEntry(convertedBehavIndex);
      case MV_EXISTING_GROUP_BEHAVIOUR:
         convertedBehavIndex = groupBehaviours.convertIndex(behaviourIndex);
         convertedGroupIndex = groups.convertIndex(groupIndex);
         return tempList->addExistingGroupBehaviourEntry(convertedBehavIndex,\
            convertedGroupIndex);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld_V2::addBehaviourToList_str(mvIndex listIndex, const char* bType,\
   mvIndex behaviourIndex, mvIndex groupIndex)
{
   mvOptionEnum option;

   if (mvCheckAllOptionEnumsForString(bType, &option))
   {
      return addBehaviourToList(listIndex, option, behaviourIndex, groupIndex);
   }
   else
   {
      return MV_NULL;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeBehaviourFromList(mvIndex listIndex,\
   mvIndex entryIndex)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return tempList->removeEntry(entryIndex);
}

mvIndex mvWorld_V2::getCurrentEntryFromList(mvIndex listIndex) const
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_NULL;
   }

   return tempList->getCurrentEntry();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeAllBehavioursFromList(mvIndex listIndex)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   tempList->clearAll();
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::addGroupIntoGroupBehaviour(mvIndex groupIndex,\
   mvIndex groupBehaviour)
{
   mvIndex tempGrpIndex = groups.convertIndex(groupIndex);

   mvGroupBehaviourPtr tempGrpBehav = getGroupBehaviourPtr(groupBehaviour);

   if (groupBehaviour == MV_NULL)
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }

   mvBaseActionPtr defaultActionPtr = tempGrpBehav->getDefaultActionPtr();
   if (defaultActionPtr == MV_NULL)
   {
      return MV_ACTION_IS_NOT_INITIALISED;
   }

   if (behavLoader == MV_NULL)
   {
      return MV_ACTION_LOADER_LIST_PTR_IS_NULL;
   }

   mvBaseActionPtr nodeActionPtr = behavLoader->createAClassPtr(
      defaultActionPtr->getType(),defaultActionPtr);

   if (nodeActionPtr == MV_NULL)
   {
      return MV_OPTION_ENUM_KEY_IS_INVALID;
   }

   return tempGrpBehav->addGroup(tempGrpIndex, nodeActionPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld_V2::removeGroupFromGroupBehaviour(mvIndex groupIndex,\
   mvIndex groupBehaviour)
{
   mvIndex tempGrpIndex = groups.convertIndex(groupIndex);

   mvGroupBehaviourPtr tempGrpBehav = getGroupBehaviourPtr(groupBehaviour);

   if (groupBehaviour == MV_NULL)
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }

   return tempGrpBehav->removeGroup(tempGrpIndex);
}

mvErrorEnum mvWorld_V2::addMemberIntoGroup(mvIndex memberIndex,\
   mvIndex groupIndex)
{
   mvGroupCapsulePtr tempCapsule = groups.getCapsulePtr(groupIndex);

   if (tempCapsule == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   mvGroupPtr tempGroup = tempCapsule->getClassPtr();

   mvErrorEnum error = tempGroup->addMember(memberIndex);
   if (error == MV_NO_ERROR)
   {
      tempCapsule->hasChanged = true;
   }
   return error;
}

mvErrorEnum mvWorld_V2::removeMemberFromGroup(mvIndex memberIndex,\
   mvIndex groupIndex)
{
   mvGroupCapsulePtr tempCapsule = groups.getCapsulePtr(groupIndex);

   if (tempCapsule == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   mvGroupPtr tempGroup = tempCapsule->getClassPtr();

   mvErrorEnum error = tempGroup->removeMember(memberIndex);
   if (error == MV_NO_ERROR)
   {
      tempCapsule->hasChanged = true;
   }
   return error;
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
mvErrorEnum mvWorld_V2::getForceParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return forces.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setForceParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return forces.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return groups.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return groups.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return behaviours.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return behaviours.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return pathways.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return pathways.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return waypoints.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return waypoints.setItemParameteri_str(index, param, paramIndex);
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
mvErrorEnum mvWorld_V2::getObstacleParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return obstacles.getItemParameteri_str(index, param, outIndex);
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
mvErrorEnum mvWorld_V2::setObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return obstacles.setItemParameteri(index, paramFlag, paramIndex);
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
mvErrorEnum mvWorld_V2::setBodyParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return bodies.setItemParameteri_str(index, param, paramIndex);
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

mvConstBaseForcePtr mvWorld_V2::getConstForcePtr(mvIndex index) const
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
   mvPathwayPtr tempPathway = getPathwayPtr(pIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(nIndex);
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

mvIndex mvWorld_V2::removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->removeNodeAt(nodeIndex);
}

mvErrorEnum mvWorld_V2::setEntryListParameteri(mvIndex listIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return entryLists.setItemParameteri(listIndex, paramFlag, index);
}

mvErrorEnum mvWorld_V2::setEntryListParameter(mvIndex listIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return entryLists.setItemParameter(listIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::setEntryListParameterf(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return entryLists.setItemParameterf(listIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::setEntryListParameterv(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return entryLists.setItemParameterv(listIndex, paramFlag, array);
}

mvErrorEnum mvWorld_V2::setEntryListParameteri_str(mvIndex listIndex,\
   const char* param, mvIndex index)
{
   return entryLists.setItemParameteri_str(listIndex, param, index);
}

mvErrorEnum mvWorld_V2::setEntryListParameter_str(mvIndex listIndex,\
   const char* param, const char* option)
{
   return entryLists.setItemParameter_str(listIndex, param, option);
}

mvErrorEnum mvWorld_V2::setEntryListParameterf_str(mvIndex listIndex,\
   const char* param, mvFloat num)
{
   return entryLists.setItemParameterf_str(listIndex, param, num);
}

mvErrorEnum mvWorld_V2::setEntryListParameterv_str(mvIndex listIndex,\
   const char* param, mvFloat* array)
{
   return entryLists.setItemParameterv_str(listIndex, param, array);
}

mvErrorEnum mvWorld_V2::getEntryListParameteri(mvIndex listIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return entryLists.getItemParameteri(listIndex, paramFlag, outIndex);
}

mvErrorEnum mvWorld_V2::getEntryListParameter(mvIndex listIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return entryLists.getItemParameter(listIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::getEntryListParameterf(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return entryLists.getItemParameterf(listIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::getEntryListParameterv(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   return entryLists.getItemParameterv(listIndex, paramFlag, array,
      noOfParameters);
}

mvErrorEnum mvWorld_V2::getEntryListParameteri_str(mvIndex listIndex,\
   const char* param, mvIndex* outIndex) const
{
   return entryLists.getItemParameteri_str(listIndex, param, outIndex);
}

mvErrorEnum mvWorld_V2::getEntryListParameter_str(mvIndex listIndex,\
   const char* param, const char** option) const
{
   return entryLists.getItemParameter_str(listIndex, param, option);
}

mvErrorEnum mvWorld_V2::getEntryListParameterf_str(mvIndex listIndex,\
   const char* param, mvFloat* num) const
{
   return entryLists.getItemParameterf_str(listIndex, param, num);
}

mvErrorEnum mvWorld_V2::getEntryListParameterv_str(mvIndex listIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return entryLists.getItemParameterv_str(listIndex, param, array,\
      noOfParameters);
}

mvErrorEnum mvWorld_V2::setEntryListNodeParameteri(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameteri(nodeIndex, paramFlag, index);
}

mvErrorEnum mvWorld_V2::setEntryListNodeParameter(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::setEntryListNodeParameterf(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterf(nodeIndex, paramFlag, num);
}
mvErrorEnum mvWorld_V2::setEntryListNodeParameterv(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

    return tempList->setEntryParameterv(nodeIndex, paramFlag, array);
}

mvErrorEnum mvWorld_V2::setEntryListNodeParameteri_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvIndex index)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameteri_str(nodeIndex, param, index);
}
mvErrorEnum mvWorld_V2::setEntryListNodeParameter_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, const char* option)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameter_str(nodeIndex, param, option);
}
mvErrorEnum mvWorld_V2::setEntryListNodeParameterf_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat num)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterf_str(nodeIndex, param, num);
}
mvErrorEnum mvWorld_V2::setEntryListNodeParameterv_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterv_str(nodeIndex, param,  array);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameteri(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameteri(nodeIndex, paramFlag, outIndex);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameter(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameter(nodeIndex, paramFlag, option);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameterf(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterf(nodeIndex, paramFlag, num);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameterv(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterv(nodeIndex, paramFlag, array,\
      noOfParameters);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameteri_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvIndex* outIndex) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameteri_str(nodeIndex, param, outIndex);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameter_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, const char** option) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameter_str(nodeIndex, param, option);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameterf_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* num) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterf_str(nodeIndex, param, num);
}

mvErrorEnum mvWorld_V2::getEntryListNodeParameterv_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterv_str(nodeIndex, param, array,\
      noOfParameters);
}

void mvWorld_V2::applyToAllEntryLists(void (someFunction)(mvEntryListPtr, void*),
   void* extraPtr)
{
   entryLists.applyToAllItems(someFunction, extraPtr);
}

mvErrorEnum mvWorld_V2::setUserData(mvParamEnum objectType,\
   mvIndex objectIndex, void* userData)
{
   switch(objectType)
   {
      case MV_BODY:
         mvBodyPtr possibleBodyPtr  = getBodyPtr(objectIndex);
         if (possibleBodyPtr == MV_NULL)
         {
            return MV_BODY_INDEX_IS_INVALID;
         }
         possibleBodyPtr->setUserData(userData);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_OBJECT_TYPE;
   }

}

void* mvWorld_V2::getUserData(mvParamEnum objectType, mvIndex objectIndex) const
{
   switch(objectType)
   {
      case MV_BODY:
         mvConstBodyPtr possibleBodyPtr = getConstBodyPtr(objectIndex);
         if (possibleBodyPtr == MV_NULL)
         {
            return MV_NULL;
         }
         return possibleBodyPtr->getUserData();
      default:
         return MV_NULL;
   }
}
