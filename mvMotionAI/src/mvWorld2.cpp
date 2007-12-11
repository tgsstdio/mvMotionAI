#include <mv/mvWorld2.h>

/**
 * \file mvWorld2.cpp
 *
 * \class mvWorld mv/mvWorld2.h
 * \brief The main class which controls all other objects within the mvMotionAI
 * library
 *
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

#include <cstring>
#include MV_BEHAVIOUR_RESULT_HEADER_FILE_H_
#include "mvWorld2_Functions.h"
#include <iostream>

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getItemParameterv_str(index,param,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return forces.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParametero_str(mvIndex index, const char* param,\
   const char** option) const
{
   return forces.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return forces.getItemParameterv(index, paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return forces.getItemParameterf(index,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParametero(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return forces.getItemParametero(index,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return forces.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return forces.setItemParameterf_str(index,param,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParametero_str(mvIndex index, const char* param,\
   const char* option)
{
   return forces.setItemParametero_str(index,param,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return forces.setItemParameterv(index, paramFlag,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return forces.setItemParameterf(index,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParametero(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return forces.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllForcesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   forces.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllForces(void (someFunction)(mvBaseForcePtr, void*),\
   void* extraPtr)
{
   forces.applyToAllItems(someFunction,extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllForces()
{
   forces.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteForce(mvIndex index)
{
   return forces.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentForce(mvIndex index)
{
   return forces.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseForcePtr mvWorld::getCurrentForcePtr()
{
   return forces.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseForcePtr mvWorld::getForcePtr(mvIndex index)
{
   return forces.getClassPtr(index);
}

mvIndex mvWorld::createForce_str(const char* fType, mvIndex saveFileIndex)
{
   mvOptionEnum optionType;

   if (!mvCheckAllOptionEnumsForString(fType, &optionType))
   {
      return MV_NULL;
   }

   return createForce(optionType);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createForce(mvOptionEnum fType, mvIndex saveFileIndex)
{
   mvBaseForcePtr temp = MV_NULL;
   mvForceCapsulePtr tempCapsule = MV_NULL;

   if (forceLoader == MV_NULL)
   {
      return MV_NULL;
   }

   std::cout << forceLoader->getNoOfFactoryFunctions() << std::endl;
   temp = forceLoader->createAClassPtr(fType,MV_NULL);
   if (temp == MV_NULL)
   {
      return MV_NULL;
   }

   tempCapsule = new mvForceCapsule(temp);
   if (tempCapsule == MV_NULL)
   {
      return MV_NULL;
   }

   return forces.addItem(tempCapsule);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupBehaviourParameterv_str(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupBehaviourParameterf_str(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupBehaviourParametero_str(mvIndex index,\
   mvIndex groupIndex, const char* param, const char** option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametero_str(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupBehaviourParameterv(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupBehaviourParameterf(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupBehaviourParametero(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->getGroupParametero(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupBehaviourParameterv_str(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParameterf_str(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParametero_str(mvIndex index,\
   mvIndex groupIndex, const char* param, const char* option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametero_str(groupIndex, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupBehaviourParameterv(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParameterf(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParametero(mvIndex index,\
   mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviourPtr temp = groupBehaviours.getClassPtr(index);

   if (temp == MV_NULL)
      return MV_ITEM_NOT_FOUND_IN_LIST;

   return temp->setGroupParametero(groupIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllGroupBehavioursByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   groupBehaviours.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllGroupBehaviours(\
   void (someFunction)(mvGroupBehaviourPtr, void*), void* extraPtr)
{
   groupBehaviours.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllGroupBehaviours()
{
   groupBehaviours.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteGroupBehaviour(mvIndex index)
{
   return groupBehaviours.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentGroupBehaviour(mvIndex index)
{
   return groupBehaviours.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourPtr mvWorld::getCurrentGroupBehaviourPtr()
{
   return groupBehaviours.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBehaviourPtr mvWorld::getGroupBehaviourPtr(mvIndex index)
{
   return groupBehaviours.getClassPtr(index);
}

mvIndex mvWorld::createGroupBehaviour_str(const char* type,\
   mvIndex saveFileIndex)
{
   mvOptionEnum optionType;

   if (!mvCheckAllOptionEnumsForString(type, &optionType))
   {
      return MV_NULL;
   }

   return createGroupBehaviour(optionType);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createGroupBehaviour(mvOptionEnum type, mvIndex saveFileIndex)
{

   mvBaseActionPtr temp = MV_NULL;
   mvNewBaseActionInfo actionInfo(type,
      mvNewBaseActionInfo::MV_NEW_GB_MAIN_NODE_OP,
      MV_NULL, MV_NULL);

   temp = behavLoader->createAClassPtr(type,actionInfo);

   if (temp == MV_NULL)
      return MV_NULL;

   mvGroupBehaviourPtr tempGBehav = new mvGroupBehaviour(temp);
   if (tempGBehav== MV_NULL)
      return MV_NULL;

   return groupBehaviours.addItem(tempGBehav);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return groups.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParametero_str(mvIndex index, const char* param,\
   const char** option) const
{
   return groups.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return groups.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return groups.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParametero(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return groups.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return groups.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return groups.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParametero_str(mvIndex index, const char* param,\
   const char* option)
{
   return groups.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return groups.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return groups.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return groups.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllGroupsByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   groups.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllGroups(void (someFunction)(mvGroupPtr, void*),\
   void* extraPtr)
{
   groups.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllGroups()
{
   groups.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteGroup(mvIndex index)
{
   return groups.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentGroup(mvIndex index)
{
   return groups.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupPtr mvWorld::getCurrentGroupPtr()
{
   return groups.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupPtr mvWorld::getGroupPtr(mvIndex index)
{
   return groups.getClassPtr(index);
}

/** @brief (one liner)
  *
  */
mvIndex mvWorld::createGroup(mvIndex saveFileIndex)
{
   mvGroupPtr temp = MV_NULL;
   mvGroupCapsulePtr tempCapsule = NULL;

   temp = new mvGroup();

   if (temp == MV_NULL)
   {
      return MV_NULL;
   }

   tempCapsule = new mvGroupCapsule(temp);
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
mvErrorEnum mvWorld::getBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return behaviours.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParameterf_str(mvIndex index,\
 const char* param, mvFloat* num) const
{
   return behaviours.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParametero_str(mvIndex index,\
   const char* param, const char** option) const
{
   return behaviours.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return behaviours.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return behaviours.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return behaviours.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return behaviours.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParametero_str(mvIndex index,\
   const char* param, const char* option)
{
   return behaviours.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return behaviours.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return behaviours.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return behaviours.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllBehavioursByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   behaviours.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllBehaviours(void (someFunction)(mvBehaviourPtr, void*),\
   void* extraPtr)
{
   behaviours.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllBehaviours()
{
   behaviours.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteBehaviour(mvIndex index)
{
   return behaviours.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentBehaviour(mvIndex index)
{
   return behaviours.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviour_V2 * mvWorld::getCurrentBehaviourPtr()
{
   return behaviours.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBehaviour_V2 * mvWorld::getBehaviourPtr(mvIndex index)
{
   return behaviours.getClassPtr(index);
}

mvIndex mvWorld::createBehaviour_str(const char* bType, mvIndex saveFileIndex)
{
   mvOptionEnum optionType;

   if (!mvCheckAllOptionEnumsForString(bType, &optionType))
   {
      return MV_NULL;
   }

   return createBehaviour(optionType);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createBehaviour(mvOptionEnum bType, mvIndex saveFileIndex)
{
   mvBaseActionPtr tempBehav = MV_NULL;
   mvNewBaseActionInfo actionInfo(bType,\
      mvNewBaseActionInfo::MV_NEW_GLOBAL_BEHAVIOUR_OP,
      MV_NULL,
      MV_NULL);


   if (behavLoader != MV_NULL)
   {
      tempBehav = behavLoader->createAClassPtr(bType,actionInfo);
   }

   if (tempBehav == MV_NULL)
   {
      return MV_NULL;
   }

   mvBehaviourPtr temp = new mvBehaviour_V2(tempBehav);
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
mvErrorEnum mvWorld::getPathwayParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return pathways.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParametero_str(mvIndex index, const char* param,\
   const char** option) const
{
   return pathways.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return pathways.getItemParameterv(index, paramFlag, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return pathways.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return pathways.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return pathways.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return pathways.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParametero_str(mvIndex index, const char* param,\
   const char* option)
{
   return pathways.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return pathways.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return pathways.setItemParameterf(index, paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return pathways.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllPathwaysByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   pathways.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllPathways(void (someFunction)(mvPathwayPtr, void*),\
   void* extraPtr)
{
   pathways.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllPathways()
{
   pathways.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deletePathway(mvIndex index)
{
   return pathways.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentPathway(mvIndex index)
{
   return pathways.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPathway * mvWorld::getCurrentPathwayPtr()
{
   return pathways.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvPathway * mvWorld::getPathwayPtr(mvIndex index)
{
   return pathways.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createPathway(mvIndex saveFileIndex)
{
   mvPathwayPtr temp = new mvPathway();

   return pathways.addItem(temp);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return waypoints.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParametero_str(mvIndex index,\
   const char* param, const char** option) const
{
   return waypoints.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return waypoints.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return waypoints.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return waypoints.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return waypoints.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return waypoints.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParametero_str(mvIndex index,\
   const char* param, const char* option)
{
   return waypoints.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return waypoints.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return waypoints.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return waypoints.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllWaypointsByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   waypoints.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllWaypoints(void (someFunction)(mvWaypointPtr, void*),\
   void* extraPtr)
{
   waypoints.applyToAllItems(someFunction,extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllWaypoints()
{
   waypoints.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteWaypoint(mvIndex index)
{
   return waypoints.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentWaypoint(mvIndex index)
{
   return waypoints.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypointPtr mvWorld::getCurrentWaypointPtr()
{
   return waypoints.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWaypointPtr mvWorld::getWaypointPtr(mvIndex index)
{
   return waypoints.getClassPtr(index);
}

mvIndex mvWorld::createWaypoint_str(const char* wShape,mvFloat x,\
   mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvOptionEnum optionShape;

   if (!mvCheckAllOptionEnumsForString(wShape, &optionShape))
   {
      return MV_NULL;
   }

   return createWaypoint(optionShape, x, y, z);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createWaypoint(mvOptionEnum wShape, mvFloat x,\
   mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvWaypointPtr tempWaypointPtr = new mvWaypoint(wShape, x, y, z);

   if (tempWaypointPtr == MV_NULL)
   {
      return MV_NULL;
   }

   mvWaypointCapsulePtr capsulePtr = new mvWaypointCapsule(tempWaypointPtr);

   if (capsulePtr == MV_NULL)
   {
      return MV_NULL;
   }

   mvIndex waypointIndex =  waypoints.addItem(capsulePtr);
   capsulePtr->waypointIndex = waypointIndex;
   return waypointIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return obstacles.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return obstacles.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParametero_str(mvIndex index,\
   const char* param, const char** option) const
{
   return obstacles.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return obstacles.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return obstacles.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return obstacles.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return obstacles.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return obstacles.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParametero_str(mvIndex index, const char* param,\
   const char* option)
{
   return obstacles.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameterv(mvIndex index,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return obstacles.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameterf(mvIndex index,\
   mvParamEnum paramFlag, mvFloat num)
{
   return obstacles.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParametero(mvIndex index,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return obstacles.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllObstaclesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   obstacles.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllObstacles(void (someFunction)(mvObstaclePtr, void*),\
   void* extraPtr)
{
   obstacles.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllObstacles()
{
   obstacles.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteObstacle(mvIndex index)
{
   return obstacles.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentObstacle(mvIndex index)
{
   return obstacles.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstaclePtr mvWorld::getCurrentObstaclePtr()
{
   return obstacles.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvObstaclePtr mvWorld::getObstaclePtr(mvIndex index)
{
   return obstacles.getClassPtr(index);
}

mvIndex mvWorld::createObstacle_str(const char* oType, const char* oState,\
   mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvOptionEnum optionType, optionState;

   if (!mvCheckAllOptionEnumsForString(oType, &optionType))
   {
      return MV_NULL;
   }

    if (!mvCheckAllOptionEnumsForString(oState, &optionState))
   {
      return MV_NULL;
   }

   return createObstacle(optionType, optionState, x, y, z);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createObstacle(mvOptionEnum oType, mvOptionEnum oState,\
   mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvObstaclePtr temp = new mvObstacle(oType, oState, x, y, z);

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
mvErrorEnum mvWorld::getBodyParameterv_str(mvIndex index, const char* param,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getItemParameterv_str(index, param, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParameterf_str(mvIndex index, const char* param,\
   mvFloat* num) const
{
   return bodies.getItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParametero_str(mvIndex index, const char* param,\
   const char** option) const
{
   return bodies.getItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters) const
{
   return bodies.getItemParameterv(index, paramFlag, array, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return bodies.getItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParametero(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return bodies.getItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameterv_str(mvIndex index, const char* param,\
   mvFloat* array)
{
   return bodies.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameterf_str(mvIndex index, const char* param,\
   mvFloat num)
{
   return bodies.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParametero_str(mvIndex index, const char* param,\
   const char* option)
{
   return bodies.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameterv(mvIndex index, mvParamEnum paramFlag,\
   mvFloat* array)
{
   return bodies.setItemParameterv(index, paramFlag, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameterf(mvIndex index, mvParamEnum paramFlag,\
   mvFloat num)
{
   return bodies.setItemParameterf(index, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParametero(mvIndex index, mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return bodies.setItemParametero(index, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllBodiesByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   bodies.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::applyToAllBodies(void (someFunction)(mvBodyPtr, void*),\
   void* extraPtr)
{
   bodies.applyToAllItems(someFunction, extraPtr);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::deleteAllBodies()
{
   bodies.deleteAllItems();
   entryLists.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::deleteBody(mvIndex index)
{
   entryLists.deleteItem(index);
   return bodies.deleteItem(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::setCurrentBody(mvIndex index)
{
   entryLists.setCurrentIndex(index);
   return bodies.setCurrentIndex(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBodyPtr mvWorld::getCurrentBodyPtr()
{
   return bodies.getCurrentClassPtr();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBodyPtr mvWorld::getBodyPtr(mvIndex index)
{
   return bodies.getClassPtr(index);
}

mvIndex mvWorld::createBody_str(const char* bType, const char* bShape,\
   mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvOptionEnum optionType, optionShape;

   if (!mvCheckAllOptionEnumsForString(bType, &optionType))
   {
      return MV_NULL;
   }

   if (!mvCheckAllOptionEnumsForString(bShape, &optionShape))
   {
      return MV_NULL;
   }

   return createBody(optionType, optionShape, x, y, z);

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::createBody(mvOptionEnum bType, mvOptionEnum bShape,\
   mvFloat x, mvFloat y, mvFloat z, mvIndex saveFileIndex)
{
   mvBodyPtr tempBody = new mvBody(bType, bShape,x,y,z);
   // TODO : new bodies created by body loader
   if (tempBody == MV_NULL)
   {
      return MV_NULL;
   }

   mvBodyCapsulePtr bCapsulePtr = new mvBodyCapsule(tempBody);
   if (bCapsulePtr == MV_NULL)
   {
      return MV_NULL;
   }

   mvEntryListPtr tempList = new mvEntryList();
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
 mvWorld::~mvWorld()
{
   //deleteAllBodies();
   //deleteAllObstacles();
   //deleteAllForces();
   //deleteAllGroupBehaviours();
   //deleteAllGroups();
   //deleteAllWaypoints();
}

void mvWorld::setWorldUserData(void* tempData)
{
   wUserData = tempData;
}

void* mvWorld::getWorldUserData() const
{
   return wUserData;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvWorld::mvWorld()
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

   wUserData = MV_NULL;
   behavLoader = MV_NULL;
   forceLoader = MV_NULL;
   elapsedWorldTime = 0;
}

void mvWorld::setForceLoader(mvForceLoaderListPtr fLoaderPtr)
{
   forceLoader = fLoaderPtr;
}

mvForceLoaderListPtr mvWorld::getForceLoaderPtr() const
{
   return forceLoader;
}

mvFloat mvWorld::getElapsedWorldTime() const
{
   return elapsedWorldTime;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::setActionLoader(mvActionLoaderListPtr bLoaderPtr)
{
   behavLoader = bLoaderPtr;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvActionLoaderListPtr mvWorld::getActionLoader() const
{
   return behavLoader;
}

void mvWorld::initialiseCommonVariables(mvBehaviourResultPtr behavResult,
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

   // C: predict velocity == old_vel + past_force * time
   mvVec3 predictVelocity(currentBody->getBodysForce());
   predictVelocity /= currentBody->getMass();
   predictVelocity *= hTimeStep;
   predictVelocity += currentBody->getVelocity();

   // D predict final velocity => predict_vel + past_vel_by_mvforces
   // past_vel_by_mvforces = final_vel + force
   mvVec3 predictFinalVelocity(currentBody->getFinalForce());
   predictFinalVelocity /= currentBody->getMass();
   predictFinalVelocity *= hTimeStep;
   predictFinalVelocity += currentBody->getFinalVelocity();

   behavResult->setPositionPrediction(predictPos);
   behavResult->setFinalPositionPrediction(predictFinalPos);
   behavResult->setVelocityPrediction(predictVelocity);
   behavResult->setFinalVelocityPrediction(predictFinalVelocity);

   forceResult->setPositionPrediction(predictPos);
   forceResult->setFinalPositionPrediction(predictFinalPos);
   forceResult->setVelocityPrediction(predictVelocity);
   forceResult->setFinalVelocityPrediction(predictFinalVelocity);
}

void mvWorld::integrateBody(mvBodyCapsulePtr bodyPtr, mvFloat timeInSecs)
{
   mvBehaviourResult finalBehavResult((mvConstWorldPtr) this,
      bodyPtr->getConstClassPtr());
   mvForceResult finalForceResult((mvConstWorldPtr) this,
      bodyPtr->getConstClassPtr());
   mvUniqueSet waypointsList;

   resetIntegrationLoop();
   checkIfWaypointContainsBody(bodyPtr,waypointsList);
   initialiseCommonVariables(&finalBehavResult,&finalForceResult,timeInSecs);
   calculateBehavioursOnBody(bodyPtr, &finalBehavResult);
   calculateAllForcesOnBody(bodyPtr, &finalForceResult, waypointsList);
   setFinalBodyCapsuleVariables(bodyPtr, &finalBehavResult, &finalForceResult);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::worldStep(mvFloat timeInSecs)
{
   mvWorld_V2_IntegrateLoopHelper helpContainer;

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
mvErrorEnum mvWorld::nudgeBody(mvIndex index, mvFloat timeInSecs)
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
      //elapsedWorldTime += timeInSecs;
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
mvErrorEnum mvWorld::stepBody(mvIndex bodyIndex, mvFloat timeInSecs)
{
   mvErrorEnum error = nudgeBody(bodyIndex, timeInSecs);

   if (error == MV_NO_ERROR)
   {
      // update time
      elapsedWorldTime += timeInSecs;
   }

   return error;
}

mvIndex mvWorld::convertWaypointIndex(mvIndex wPointIndex) const
{
   mvConstWaypointCapsulePtr tempCapsulePtr =\
      waypoints.getConstCapsulePtr(wPointIndex);

   if (tempCapsulePtr)
   {
      return tempCapsulePtr->waypointIndex;
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
void mvWorld::calculateAllForcesOnBody(mvBodyCapsulePtr bodyPtr,\
   mvForceResultPtr finalForceResult, mvUniqueSet& waypointList)
{
   mvWorld_V2_CalcForceHelperStruct helper(waypointList);
   helper.currentWorld = this;
   helper.currentBody = bodyPtr;
   helper.finalResult = finalForceResult;

   if (applyAllForces)
   {
      forces.applyToAllCapsules(mvWorld_V2_CalculateForceOnSingleBody, &helper);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvWorld::resetIntegrationLoop()
{
   // reset forces
   waypoints.applyToAllCapsules(mvWorld_V2_ResetWaypointCapsule, MV_NULL);
}

void mvWorld::prepareIntegrationStep()
{
   // reset bodies
   bodies.applyToAllCapsules(mvWorld_V2_PrepareBodyCapsule,MV_NULL);

   // reset forces
   forces.applyToAllCapsules(mvWorld_V2_PrepareForceCapsule, this);
}

bool mvWorld::hasGroupChanged(mvIndex groupNo)
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

void mvWorld::calculateGroupBehaviours() // 1
{
   // foreach group behaviour
   groupBehaviours.applyToAllItemsByItemIndex(mvWorld_V2_CalculateForEachGroupBehaviour,this);
}

void mvWorld::checkIfWaypointContainsBody(mvBodyCapsulePtr bodyPtr,
   mvUniqueSet& waypointList) // part of 2
{

   mvWorld_V2_LocalForceCalculationHelper helperModule(waypointList);
   helperModule.bCapsule = bodyPtr;

    // generate shape info body
   mvConstShapePtr bodyShapePtr = bodyPtr->getConstClassPtr()->getShape();
   mvVec3 bodyPos = bodyPtr->getConstClassPtr()->getPosition();

   if(!mvWorldV2_InitialiseInsideWaypointHelperStruct(helperModule,\
      bodyShapePtr,bodyPos))
   {
      return;
   }

   // loop over all forces - just local forces
   waypoints.applyToAllCapsules(mvWorldV2_CheckWaypointLocality, &helperModule);

   // check waypoints
   /*
   waypointList.beginLoop();
   while(!waypointList.isLoopFinished())
   {
      std::cout << "Index : " << waypointList.getCurrentIndex() << std::endl;
      waypointList.nextIndex();
   }
   */
}

void mvWorld::calculateBehavioursOnBody(mvBodyCapsulePtr bCapsulePtr,\
   mvBehaviourResultPtr finalResult)
{
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
   mvWorld_V2_CalcBehavOnListHelper helperModule;

   helperModule.finalResult = finalResult;
   helperModule.bCapsule = bCapsulePtr;
   helperModule.currentEntryList = currentEntryList;

   // integration mode
   mvOptionEnum integrationMode = currentEntryList->getMode();
   switch(integrationMode)
   {
      // TODO : case MV_TREE:
      case MV_XOR:
         mvWorld_V2_CalculateEntryByXORSum(&helperModule);
         break;
      // TODO : case MV_TREE:
      case MV_RANDOM:
         currentEntryList->applyToAllEntries(mvWorld_V2_CalculateEntryByRandomSum,
            &helperModule);
         break;
      // TODO : case MV_PRORTIZED_WEIGHTED:
      case MV_RANDOMIZED_WEIGHTED:
         currentEntryList->applyToAllEntries(mvWorld_V2_CalculateEntryByRandomWeightSum,
            &helperModule);
         break;
      case MV_WEIGHTED:
      default:
         currentEntryList->applyToAllEntries(mvWorld_V2_CalculateEntryByWeightedSum,
            &helperModule);
         break;
   }
}

void mvWorld::setFinalBodyCapsuleVariables(mvBodyCapsulePtr bodyPtr,\
   mvBehaviourResultPtr behavResModule, mvForceResultPtr forceResModule)
{
   mvVec3 tempVector;
   // ASSUME resultModule is "NORMALISED" - global steering motions

   // set
   mvFloat bodyMass = bodyPtr->getConstClassPtr()->getMass();

   if (bodyPtr->performIntegration)
   {
      if (behavResModule->isForceSet())
      {
         bodyPtr->futureForce += behavResModule->getForce();
      }

      if (behavResModule->isAccelerationSet())
      {
         tempVector = behavResModule->getAcceleration();
         tempVector *= bodyMass;
         bodyPtr->futureForce += tempVector;
      }

      if (behavResModule->isVelocitySet())
      {
         bodyPtr->futureVelocity += behavResModule->getVelocity();
      }

      if (behavResModule->isTorqueSet())
      {
         bodyPtr->futureTorque += behavResModule->getTorque();
      }

      if (behavResModule->isOmegaSet())
      {
         bodyPtr->futureOmega += behavResModule->getOmega();
      }
   }


   // TODO : add force variables to capsule
   if (forceResModule->isForceSet())
   {
      bodyPtr->additionalForce += forceResModule->getForce();
   }

   if (forceResModule->isGravitySet())
   {
      tempVector = forceResModule->getGravity();
      tempVector *= bodyMass;
      bodyPtr->additionalForce += tempVector;
   }

   if (forceResModule->isAccelerationSet())
   {
      tempVector = forceResModule->getAcceleration();
      tempVector *= bodyMass;
      bodyPtr->additionalForce += tempVector;
   }

   if (forceResModule->isShiftSet())
   {
      bodyPtr->additionalVelocity += forceResModule->getShift();
   }

   if (forceResModule->isTorqueSet())
   {
      bodyPtr->additionalTorque = forceResModule->getTorque();
   }

   if (forceResModule->isOmegaSet())
   {
      bodyPtr->additionalOmega = forceResModule->getOmega();
   }

   // translate
   // TODO : direction to omega

   // TODO : rotation to omega

   // TODO : quaternion to omega

}

void mvWorld::finaliseIntegrationStep(mvFloat timeInSecs)
{
   mvWorld_V2_IntegrateLoopHelper helperModule;
   helperModule.currentWorld = this;
   helperModule.timeInSecs = timeInSecs;

   groups.applyToAllCapsules(mvWorld_V2_FinaliseGroups,this);
   bodies.applyToAllCapsules(mvWorld_V2_CalculateIntegrationOfBody, &helperModule);
}

// WORLD STEP FUNCTIONS

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvWorld::addBehaviourToList(mvIndex listIndex, mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex, mvIndex saveFileIndex)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_NULL;
   }

   mvBaseActionPtr actionPtr = NULL;
   mvIndex convertedBehavIndex;
   mvIndex convertedGroupIndex;

   // in case
   mvNewBaseActionInfo privateActionInfo(bType,
      mvNewBaseActionInfo::MV_NEW_PRIVATE_BEHAVIOUR_OP, MV_NULL, MV_NULL);

   switch(bType)
   {
      default:
         if (behavLoader != MV_NULL)
         {
            actionPtr = behavLoader->createAClassPtr(bType, privateActionInfo);
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
      // TODO : how do we handle group entries objects?
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
mvIndex mvWorld::addBehaviourToList_str(mvIndex listIndex, const char* bType,\
   mvIndex behaviourIndex, mvIndex groupIndex, mvIndex saveFileIndex)
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
mvErrorEnum mvWorld::removeBehaviourFromList(mvIndex listIndex,\
   mvIndex entryIndex)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }

   return tempList->removeEntry(entryIndex);
}

mvIndex mvWorld::getCurrentEntryFromList(mvIndex listIndex) const
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
mvErrorEnum mvWorld::removeAllBehavioursFromList(mvIndex listIndex)
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
mvErrorEnum mvWorld::addGroupIntoGroupBehaviour(mvIndex gbIndex,
   mvIndex groupIndex)
{
   mvGroupBehaviourPtr tempGrpBehav = getGroupBehaviourPtr(gbIndex);

   if (tempGrpBehav == MV_NULL)
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }

   bool pastAutoConvertIndexFlag = groups.getAutoConvertFlag();
   groups.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex tempGrpIndex = groups.convertIndex(groupIndex);
   groups.setAutoConvertIndex(pastAutoConvertIndexFlag);

   if (tempGrpIndex == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
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

   mvNewBaseActionInfo groupActionInfo(defaultActionPtr->getType(),
      mvNewBaseActionInfo::MV_NEW_GB_GROUP_NODE_OP, defaultActionPtr, MV_NULL);

   mvBaseActionPtr nodeActionPtr = behavLoader->createAClassPtr(
      defaultActionPtr->getType(),groupActionInfo);

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
mvErrorEnum mvWorld::removeGroupFromGroupBehaviour(mvIndex gbIndex,\
   mvIndex groupIndex)
{
   mvGroupBehaviourPtr tempGrpBehav = getGroupBehaviourPtr(gbIndex);
   if (tempGrpBehav == MV_NULL)
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }

   // set auto convert indexes to world flag then back
   bool pastAutoConvertIndexFlag = groups.getAutoConvertFlag();
   groups.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex tempGrpIndex = groups.convertIndex(groupIndex);
   groups.setAutoConvertIndex(pastAutoConvertIndexFlag);

   if (tempGrpIndex == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   return tempGrpBehav->removeGroup(tempGrpIndex);
}

mvErrorEnum mvWorld::addMemberIntoGroup(mvIndex groupIndex, mvIndex mbrIndex)
{
   mvGroupCapsulePtr tempCapsule = groups.getCapsulePtr(groupIndex);
   if (tempCapsule == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }
   mvGroupPtr tempGroup = tempCapsule->getClassPtr();

   if (mbrIndex == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   mvErrorEnum error = tempGroup->addMember(mbrIndex);
   if (error == MV_NO_ERROR)
   {
      tempCapsule->hasChanged = true;
   }

   return error;
}

mvErrorEnum mvWorld::removeMemberFromGroup(mvIndex groupIndex,
   mvIndex mbrIndex)
{
   mvGroupCapsulePtr tempCapsule = groups.getCapsulePtr(groupIndex);

   if (tempCapsule == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   mvGroupPtr tempGroup = tempCapsule->getClassPtr();

   if (mbrIndex == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   mvErrorEnum error = tempGroup->removeMember(mbrIndex);
   if (error == MV_NO_ERROR)
   {
      tempCapsule->hasChanged = true;
   }
   return error;
}

mvIndex mvWorld::findMemberInGroup(mvIndex groupIndex,mvIndex mbrIndex)
{
   mvConstGroupPtr tempGroup = getConstGroupPtr(groupIndex);

   if (tempGroup == MV_NULL)
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }

   bool pastAutoConvertIndexFlag = bodies.getAutoConvertFlag();
   bodies.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex convertedIndex = bodies.convertIndex(mbrIndex);
   bodies.setAutoConvertIndex(pastAutoConvertIndexFlag);

   if (convertedIndex == MV_NULL)
   {
      return MV_NULL;
   }

   if (tempGroup->findMember(convertedIndex))
   {
		return convertedIndex;
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
mvErrorEnum mvWorld::setMainGroupBehaviourParametero(mvIndex index,\
   mvParamEnum param, mvOptionEnum option)
{
   return groupBehaviours.setItemParametero(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameteri(mvIndex index,\
   mvParamEnum param, mvIndex paramIndex)
{
   return groupBehaviours.setItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameterf(mvIndex index,\
   mvParamEnum param, mvFloat num)
{
   return groupBehaviours.setItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameterv(mvIndex index,\
   mvParamEnum param, mvFloat* array)
{
   return groupBehaviours.setItemParameterv(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return groupBehaviours.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParametero_str(mvIndex index,\
   const char* param, const char* option)
{
   return groupBehaviours.setItemParametero_str(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat num)
{
   return groupBehaviours.setItemParameterf_str(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setMainGroupBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array)
{
   return groupBehaviours.setItemParameterv_str(index, param, array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParametero_str(mvIndex index,\
   const char* param, const char** option) const
{
   return groupBehaviours.getItemParametero_str(index,param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex* paramIndex) const
{
   return groupBehaviours.getItemParameteri_str(index,param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameterf_str(mvIndex index,\
   const char* param, mvFloat* num) const
{
   return groupBehaviours.getItemParameterf_str(index,param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameterv_str(mvIndex index,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getItemParameterv_str(index,param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParametero(mvIndex index,\
   mvParamEnum param, mvOptionEnum* option) const
{
   return groupBehaviours.getItemParametero(index, param, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameteri(mvIndex index,\
   mvParamEnum param, mvIndex* paramIndex) const
{
   return groupBehaviours.getItemParameteri(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameterf(mvIndex index,\
   mvParamEnum param, mvFloat* num) const
{
   return groupBehaviours.getItemParameterf(index, param, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getMainGroupBehaviourParameterv(mvIndex index,\
   mvParamEnum param, mvFloat* array, mvCount* noOfParameters) const
{
   return groupBehaviours.getItemParameterv(index, param, array,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return forces.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getForceParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return forces.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return forces.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setForceParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return forces.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupBehaviourParameteri_str(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupBehaviourParameteri(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParameteri_str(mvIndex index,\
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
mvErrorEnum mvWorld::setGroupBehaviourParameteri(mvIndex index,\
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
mvErrorEnum mvWorld::getGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return groups.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getGroupParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return groups.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return groups.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setGroupParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return groups.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return behaviours.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBehaviourParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return behaviours.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return behaviours.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBehaviourParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return behaviours.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return pathways.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getPathwayParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return pathways.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return pathways.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setPathwayParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return pathways.setItemParameteri(index,paramFlag, paramIndex);
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return waypoints.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getWaypointParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return waypoints.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameteri_str(mvIndex index,\
   const char* param, mvIndex paramIndex)
{
   return waypoints.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setWaypointParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return waypoints.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParameteri_str(mvIndex index,\
   const char* param, mvIndex* outIndex) const
{
   return obstacles.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return obstacles.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setObstacleParameteri(mvIndex index,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return obstacles.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParameteri_str(mvIndex index, const char* param,\
   mvIndex* outIndex) const
{
   return bodies.getItemParameteri_str(index, param, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
   mvIndex* outIndex) const
{
   return bodies.getItemParameteri(index, paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameteri_str(mvIndex index, const char* param,\
   mvIndex paramIndex)
{
   return bodies.setItemParameteri_str(index, param, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setBodyParameteri(mvIndex index, mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return bodies.setItemParameteri(index, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::getParametero(mvParamEnum paramFlag,\
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
      case MV_APPLY_ALL_DRAG_FORCES:
         if (applyAllDragForces)
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
mvErrorEnum mvWorld::getParameteri(mvParamEnum paramFlag, mvIndex* outIndex)\
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
mvErrorEnum mvWorld::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
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
mvErrorEnum mvWorld::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
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
mvErrorEnum mvWorld::setParametero(mvParamEnum paramFlag, mvOptionEnum option)
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
      case MV_APPLY_ALL_DRAG_FORCES:
         if (option == MV_FALSE)
         {
            applyAllDragForces = false;
         }
         else
         {
            applyAllDragForces = true;
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
mvErrorEnum mvWorld::setParameteri(mvParamEnum paramFlag, mvIndex index)
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
mvErrorEnum mvWorld::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_WORLD_PARAMETER;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_WORLD_PARAMETER;
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentBody() const
{
   return bodies.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentObstacle() const
{
   return obstacles.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentWaypoint() const
{
   return waypoints.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentForce() const
{
   return forces.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentGroup() const
{
   return groups.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentBehaviour() const
{
   return behaviours.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentGroupBehaviour() const
{
   return groupBehaviours.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentPathway() const
{
   return pathways.getCurrentIndex();
}

/** \brief blah blah
 *
 */
mvConstBodyPtr mvWorld::getConstBodyPtr(mvIndex index) const
{
   return bodies.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstObstaclePtr mvWorld::getConstObstaclePtr(mvIndex index) const
{
   return obstacles.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstWaypointPtr mvWorld::getConstWaypointPtr(mvIndex index) const
{
   return waypoints.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstPathwayPtr mvWorld::getConstPathwayPtr(mvIndex index) const
{
   return pathways.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstGroupPtr mvWorld::getConstGroupPtr(mvIndex index) const
{
   return groups.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstGroupBehaviourPtr mvWorld::getConstGroupBehaviourPtr(mvIndex index)\
   const
{
   return groupBehaviours.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstBehaviourPtr mvWorld::getConstBehaviourPtr(mvIndex index) const
{
   return behaviours.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstBaseForcePtr mvWorld::getConstForcePtr(mvIndex index) const
{
   return forces.getConstClassPtr(index);
}

/** \brief blah blah
 *
 */
mvConstBodyCapsulePtr mvWorld::getConstBodyCapsulePtr(int index) const
{
   return bodies.getConstCapsulePtr(index);
}

/** \brief blah blah
 *
 */
mvBodyCapsulePtr mvWorld::getBodyCapsulePtr(int index)
{
   return bodies.getCapsulePtr(index);
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::addNodeToPathway(mvIndex pathwayIndex, mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->addNode(nodeIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeNodeFromPathway(mvIndex pathwayIndex,\
   mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->removeFirstNodeInstance(nodeIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeAllNodesFromPathway(mvIndex pwIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   tempPathway->removeAllNodes();
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameteri(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri(nodeIndex, paramFlag, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParametero(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParametero(nodeIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameterf(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf(nodeIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameterv(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv(nodeIndex, paramFlag, array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameteri_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvIndex index)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameteri_str(nodeIndex, param, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParametero_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, const char* option)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParametero_str(nodeIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameterf_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat num)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterf_str(nodeIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setPathwayNodeParameterv_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->setNodeParameterv_str(nodeIndex, param, array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameteri(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri(nodeIndex, paramFlag,  outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParametero(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParametero(nodeIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameterf(mvIndex pathwayIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf(nodeIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameterv(mvIndex pathwayIndex,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameteri_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvIndex* outIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameteri_str(nodeIndex, param, outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParametero_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, const char** option) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParametero_str(nodeIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameterf_str(mvIndex pathwayIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* num) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pathwayIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }

   return tempPathway->getNodeParameterf_str(nodeIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getPathwayNodeParameterv_str(mvIndex pathwayIndex,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removePathwayNodeAt(mvIndex pwIndex, mvIndex nodeIndex)
{
   mvPathwayPtr tempPathway = getPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_PATHWAY_INDEX_IS_INVALID;
   }
   return tempPathway->removeNodeAt(nodeIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameteri(mvIndex listIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return entryLists.setItemParameteri(listIndex, paramFlag, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParametero(mvIndex listIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return entryLists.setItemParametero(listIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameterf(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return entryLists.setItemParameterf(listIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameterv(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   return entryLists.setItemParameterv(listIndex, paramFlag, array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameteri_str(mvIndex listIndex,\
   const char* param, mvIndex index)
{
   return entryLists.setItemParameteri_str(listIndex, param, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParametero_str(mvIndex listIndex,\
   const char* param, const char* option)
{
   return entryLists.setItemParametero_str(listIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameterf_str(mvIndex listIndex,\
   const char* param, mvFloat num)
{
   return entryLists.setItemParameterf_str(listIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListParameterv_str(mvIndex listIndex,\
   const char* param, mvFloat* array)
{
   return entryLists.setItemParameterv_str(listIndex, param, array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameteri(mvIndex listIndex,\
   mvParamEnum paramFlag, mvIndex* outIndex) const
{
   return entryLists.getItemParameteri(listIndex, paramFlag, outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParametero(mvIndex listIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return entryLists.getItemParametero(listIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameterf(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return entryLists.getItemParameterf(listIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameterv(mvIndex listIndex,\
   mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   return entryLists.getItemParameterv(listIndex, paramFlag, array,
      noOfParameters);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameteri_str(mvIndex listIndex,\
   const char* param, mvIndex* outIndex) const
{
   return entryLists.getItemParameteri_str(listIndex, param, outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParametero_str(mvIndex listIndex,\
   const char* param, const char** option) const
{
   return entryLists.getItemParametero_str(listIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameterf_str(mvIndex listIndex,\
   const char* param, mvFloat* num) const
{
   return entryLists.getItemParameterf_str(listIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListParameterv_str(mvIndex listIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return entryLists.getItemParameterv_str(listIndex, param, array,\
      noOfParameters);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameteri(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameteri(nodeIndex, paramFlag, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParametero(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParametero(nodeIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameterf(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterf(nodeIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameterv(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

    return tempList->setEntryParameterv(nodeIndex, paramFlag, array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameteri_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvIndex index)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameteri_str(nodeIndex, param, index);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParametero_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, const char* option)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParametero_str(nodeIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameterf_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat num)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterf_str(nodeIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setEntryListNodeParameterv_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* array)
{
   mvEntryListPtr tempList = entryLists.getClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->setEntryParameterv_str(nodeIndex, param,  array);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameteri(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvIndex* outIndex) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameteri(nodeIndex, paramFlag, outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParametero(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParametero(nodeIndex, paramFlag, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameterf(mvIndex listIndex,\
   mvIndex nodeIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterf(nodeIndex, paramFlag, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameterv(mvIndex listIndex,\
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

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameteri_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvIndex* outIndex) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameteri_str(nodeIndex, param, outIndex);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParametero_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, const char** option) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParametero_str(nodeIndex, param, option);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameterf_str(mvIndex listIndex,\
   mvIndex nodeIndex, const char* param, mvFloat* num) const
{
   mvConstEntryListPtr tempList = entryLists.getConstClassPtr(listIndex);

   if (tempList == MV_NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

   return tempList->getEntryParameterf_str(nodeIndex, param, num);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::getEntryListNodeParameterv_str(mvIndex listIndex,\
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

/** \brief blah blah
 *
 */
void mvWorld::applyToAllEntryLists(void (someFunction)(mvEntryListPtr, void*),
   void* extraPtr)
{
   entryLists.applyToAllItems(someFunction, extraPtr);
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::setUserData(mvParamEnum objectType,\
   mvIndex objectIndex, void* userData)
{
   mvBaseForcePtr possibleForce = NULL;
   mvBodyPtr possibleBodyPtr = NULL;

   switch(objectType)
   {
      case MV_FORCE:
         possibleForce = getForcePtr(objectIndex);
         if (possibleForce == MV_NULL)
         {
            return MV_FORCE_INDEX_IS_INVALID;
         }
         possibleForce->setUserData(userData);
         return MV_NO_ERROR;
      case MV_BODY:
         possibleBodyPtr  = getBodyPtr(objectIndex);
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

/** \brief blah blah
 *
 */
void* mvWorld::getUserData(mvParamEnum objectType, mvIndex objectIndex) const
{
   mvConstBodyPtr possibleBodyPtr = getConstBodyPtr(objectIndex);
   mvConstBaseForcePtr possibleForcePtr = getConstForcePtr(objectIndex);

   switch(objectType)
   {
      case MV_BODY:
         if (possibleBodyPtr == MV_NULL)
         {
            return MV_NULL;
         }
         else
         {
            return possibleBodyPtr->getUserData();
         }
      case MV_FORCE:
         if (possibleForcePtr == MV_NULL)
         {
            return MV_NULL;
         }
         else
         {
            return possibleForcePtr->getUserData();
         }
      default:
         return MV_NULL;
   }
}

/** \brief blah blah
 *
 */
mvIndex mvWorld::getCurrentNodeOfPathway(mvIndex pwIndex) const
{
   mvConstPathwayPtr tempPathway = getConstPathwayPtr(pwIndex);

   if (tempPathway == MV_NULL)
   {
      return MV_NULL;
   }

   return tempPathway->getCurrentNode();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::addForceIntoWaypoint(mvIndex wIndex, mvIndex fIndex)
{
   mvWaypointCapsulePtr tempWaypointPtr = NULL;
   mvErrorEnum error;
   mvForceCapsulePtr tempCapsulePtr = forces.getCapsulePtr(fIndex);

   if (tempCapsulePtr == MV_NULL)
   {
      return MV_FORCE_INDEX_IS_INVALID;
   }

   // convert index
   bool pastAutoConvertIndex = waypoints.getAutoConvertFlag();
   waypoints.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex convertedWpIndex = waypoints.convertIndex(wIndex);
   waypoints.setAutoConvertIndex(pastAutoConvertIndex);

   if (convertedWpIndex == MV_NULL)
   {
      return MV_WAYPOINT_INDEX_IS_INVALID;
   }

   error = tempCapsulePtr->addWaypoint(convertedWpIndex);
   if (error == MV_NO_ERROR)
   {
      // increment count
      tempWaypointPtr = waypoints.getCapsulePtr(convertedWpIndex);
      tempWaypointPtr->incrementCount();
   }

   return error;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeForceFromWaypoint(mvIndex wIndex,\
   mvIndex fIndex)
{
   mvWaypointCapsulePtr tempWaypointPtr = NULL;
   mvErrorEnum error;
   mvForceCapsulePtr tempCapsulePtr = forces.getCapsulePtr(fIndex);

   if (tempCapsulePtr == MV_NULL)
   {
      return MV_FORCE_INDEX_IS_INVALID;
   }

   // convert index
   bool pastAutoConvertIndex = waypoints.getAutoConvertFlag();
   waypoints.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex convertedWpIndex = waypoints.convertIndex(wIndex);
   waypoints.setAutoConvertIndex(pastAutoConvertIndex);

   if (convertedWpIndex == MV_NULL)
   {
      return MV_WAYPOINT_INDEX_IS_INVALID;
   }

   error = tempCapsulePtr->removeWaypoint(convertedWpIndex);
   if (error == MV_NO_ERROR)
   {
      // increment count
      tempWaypointPtr = waypoints.getCapsulePtr(convertedWpIndex);
      tempWaypointPtr->decrementCount();
   }
   return error;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeAllWaypointsFromForce(mvIndex forceIndex)
{
   mvForceCapsulePtr tempCapsulePtr = forces.getCapsulePtr(forceIndex);

   if (tempCapsulePtr == MV_NULL)
   {
      return MV_FORCE_INDEX_IS_INVALID;
   }

   tempCapsulePtr->clearAllWaypoints();
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeAllForcesFromWaypoint(mvIndex wIndex)
{
   // convert index
   bool pastAutoConvertIndex = waypoints.getAutoConvertFlag();
   waypoints.setAutoConvertIndex(this->autoConvertIndex);
   mvIndex convertedWpIndex = waypoints.convertIndex(wIndex);
   waypoints.setAutoConvertIndex(pastAutoConvertIndex);

   if (convertedWpIndex == MV_NULL)
   {
      return MV_WAYPOINT_INDEX_IS_INVALID;
   }

   forces.applyToAllCapsules(mvWorldV2_RemoveAWaypointFromAllForceCapsules,
      &convertedWpIndex);

   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeAllGroupsFromGroupBehaviour(mvIndex gbIndex)
{
   mvGroupBehaviourPtr tempGBPtr = getGroupBehaviourPtr(gbIndex);

   if (tempGBPtr == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   tempGBPtr->removeAllGroups();
   return MV_NO_ERROR;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvWorld::removeAllMembersFromGroup(mvIndex groupIndex)
{
   mvGroupPtr tempGroup = getGroupPtr(groupIndex);

   if (tempGroup == MV_NULL)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   tempGroup->clearAll();
   return MV_NO_ERROR;
}

// TODO : register
bool addGroupBehaviourMemberToList(mvIndex bodyIndex,
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseActionPtr memberNodePtr)
{
   return false;
}

// TODO : register

void mvWorld::registerAllGroupBehavioursToBodies()
{
   groupBehaviours.applyToAllItemsByItemIndex(\
      mvWorld_V2_RegisterEachGroupBehaviour, this);
}

void mvWorld::registerGroupBehaviourToBodies(mvIndex groupBehaviourIndex)
{

}

/** \brief blah blah
 *
 */
mvEntryListPtr mvWorld::getEntryListPtr(mvIndex entryListIndex) const
{
   return entryLists.getClassPtr(entryListIndex);
}
