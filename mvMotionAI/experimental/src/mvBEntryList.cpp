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
#include "mvBEntryList.h"
/* TODO (White 2#1#): Implement all functions below */

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setCurrentEntryParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   return entryList.setCurrentItemParameterv(paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setCurrentEntryParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return entryList.setCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setCurrentEntryParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return entryList.setCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setCurrentEntryParameteri(mvParamEnum paramFlag,\
   mvIndex paramIndex)
{
   return entryList.setCurrentItemParameteri(paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getCurrentEntryParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getCurrentItemParameterv(paramFlag, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getCurrentEntryParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return entryList.getCurrentItemParameterf(paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getCurrentEntryParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return entryList.getCurrentItemParameter(paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getCurrentEntryParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   return entryList.getCurrentItemParameteri(paramFlag, outIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return entryList.setItemParameterv(entryIndex, paramFlag, numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return entryList.setItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameter(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return entryList.setItemParameter(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex paramIndex)
{
   return entryList.setItemParameteri(entryIndex, paramFlag, paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameterv(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getItemParameterv(entryIndex,paramFlag, numArray,\
      noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameterf(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
/* TODO (White 2#1#): implement function
 */
   return entryList.getItemParameterf(entryIndex, paramFlag, num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameter(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   return entryList.getItemParameter(entryIndex, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex* index)
{
   return entryList.getItemParameteri(entryIndex, paramFlag, index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFloat mvBEntryList::getDefaultWeight() const
{
   return defaultWeight;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultPathway() const
{
   return defaultPathway;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultWaypoint() const
{
   return defaultWaypoint;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvIndex mvBEntryList::getDefaultBody() const
{
   return defaultBody;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addNewEntry(mvOptionEnum bType,\
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseBehaviour* dBehaviour)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addNewBehaviourEntry(mvOptionEnum behaviourType)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addExistingBehaviourEntry(mvIndex behaviourIndex)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addExistingGroupBehaviourEntry(\
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseBehaviour* dBehaviour)
{
   // TODO : implement this function
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setDefaultWeight(mvFloat factor)
{
   return (factor < 0.0) ? MV_FLOAT_VALUE_IS_NOT_POSITIVE : MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultPathway(mvIndex pwIndex)
{
   defaultPathway = pwIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultWaypoint(mvIndex wpIndex)
{
   defaultWaypoint = wpIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultBody(mvIndex bodyIndex)
{
   defaultBody = bodyIndex;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvOptionEnum mvBEntryList::getMode() const
{
   return integrationMode;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setMode(mvOptionEnum option)
{
   // TODO : further implementation
   integrationMode = option;
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryListNode * mvBEntryList::getEntry(mvIndex index)
{
   return entryList.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryListNode * mvBEntryList::findExistingGroupEntry(mvIndex bIndex,\
   mvIndex gIndex)
{
   return NULL;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBEntryList::mvBEntryList(mvFloat dWeight,\
   mvIndex dBody = MV_NO_CURRENT_INDEX,\
   mvIndex dWaypoint = MV_NO_CURRENT_INDEX,\
   mvIndex dPathway = MV_NO_CURRENT_INDEX)
{
   defaultWeight = dWeight;
   defaultBody = dBody;
   defaultWaypoint = dWaypoint;
   defaultPathway = dPathway;
   /* TODO : created new integration mode enums */
   integrationMode = MV_WEIGHTED;
}

mvErrorEnum mvBEntryList::getEntryParameteri_str(mvIndex entryIndex,\
   const char* param, mvIndex* outIndex)
{
   return entryList.getItemParameteri_str(entryIndex, param, outIndex);
}

mvErrorEnum mvBEntryList::getEntryParameter_str(mvIndex entryIndex, const char* param,\
   const char** option)
{
   return entryList.getItemParameter_str(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::getEntryParameterf_str(mvIndex entryIndex, const char* param,\
   mvFloat* num)
{
   return entryList.getItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::getEntryParameterv_str(mvIndex entryIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getItemParameterv_str(entryIndex, param, numArray,\
      noOfParameters);
}


mvErrorEnum mvBEntryList::setEntryParameteri_str(mvIndex entryIndex,const char* param,\
   mvIndex paramIndex)
{
   return entryList.setItemParameteri_str(entryIndex, param, paramIndex);
}

mvErrorEnum mvBEntryList::setEntryParameter_str(mvIndex entryIndex,const char* param,\
   const char* option)
{
   return entryList.setItemParameter_str(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::setEntryParameterf_str(mvIndex entryIndex,const char* param,\
   mvFloat num)
{
   return entryList.setItemParameterf_str(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::setEntryParameterv_str(mvIndex entryIndex,const char* param,\
   mvFloat* numArray)
{
   return entryList.setItemParameterv_str(entryIndex, param, numArray);
}

mvErrorEnum mvBEntryList::getCurrentEntryParameteri_str(const char* param,\
   mvIndex* outIndex)
{
   return entryList.getCurrentItemParameteri_str(param, outIndex);
}

mvErrorEnum mvBEntryList::getCurrentEntryParameter_str(const char* param,\
   const char** option)
{
   return entryList.getCurrentItemParameter_str(param, option);
}

mvErrorEnum mvBEntryList::getCurrentEntryParameterf_str(const char* param,\
   mvFloat* num)
{
   return entryList.getCurrentItemParameterf_str(param, num);
}

mvErrorEnum mvBEntryList::getCurrentEntryParameterv_str(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getCurrentItemParameterv_str(param, numArray, noOfParameters);
}

mvErrorEnum mvBEntryList::setCurrentEntryParameteri_str(const char* param,\
   mvIndex paramIndex)
{
   return entryList.setCurrentItemParameteri_str(param, paramIndex);
}

mvErrorEnum mvBEntryList::setCurrentEntryParameter_str(const char* param,\
   const char* option)
{
   return entryList.setCurrentItemParameter_str(param, option);
}

mvErrorEnum mvBEntryList::setCurrentEntryParameterf_str(const char* param,\
   mvFloat num)
{
   return entryList.setCurrentItemParameterf_str(param, num);
}

mvErrorEnum mvBEntryList::setCurrentEntryParameterv_str(const char* param,\
   mvFloat* numArray)
{
   return entryList.setCurrentItemParameterv_str(param, numArray);
}

