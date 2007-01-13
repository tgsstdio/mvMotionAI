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
 mvBEntryList::mvBEntryList(mvFloat dWeight = 1.0,\
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

mvErrorEnum mvBEntryList::getEntryParametersi(mvIndex entryIndex,\
   const char* param, mvIndex* outIndex)
{
   return entryList.getItemParametersi(entryIndex, param, outIndex);
}

mvErrorEnum mvBEntryList::getEntryParameters(mvIndex entryIndex, const char* param,\
   const char** option)
{
   return entryList.getItemParameters(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::getEntryParametersf(mvIndex entryIndex, const char* param,\
   mvFloat* num)
{
   return entryList.getItemParametersf(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::getEntryParametersv(mvIndex entryIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getItemParametersv(entryIndex, param, numArray,\
      noOfParameters);
}


mvErrorEnum mvBEntryList::setEntryParametersi(mvIndex entryIndex,const char* param,\
   mvIndex paramIndex)
{
   return entryList.setItemParametersi(entryIndex, param, paramIndex);
}

mvErrorEnum mvBEntryList::setEntryParameters(mvIndex entryIndex,const char* param,\
   const char* option)
{
   return entryList.setItemParameters(entryIndex, param, option);
}

mvErrorEnum mvBEntryList::setEntryParametersf(mvIndex entryIndex,const char* param,\
   mvFloat num)
{
   return entryList.setItemParametersf(entryIndex, param, num);
}

mvErrorEnum mvBEntryList::setEntryParametersv(mvIndex entryIndex,const char* param,\
   mvFloat* numArray)
{
   return entryList.setItemParametersv(entryIndex, param, numArray);
}

mvErrorEnum mvBEntryList::getCurrentEntryParametersi(const char* param,\
   mvIndex* outIndex)
{
   return entryList.getCurrentItemParametersi(param, outIndex);
}

mvErrorEnum mvBEntryList::getCurrentEntryParameters(const char* param,\
   const char** option)
{
   return entryList.getCurrentItemParameters(param, option);
}

mvErrorEnum mvBEntryList::getCurrentEntryParametersf(const char* param,\
   mvFloat* num)
{
   return entryList.getCurrentItemParametersf(param, num);
}

mvErrorEnum mvBEntryList::getCurrentEntryParametersv(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return entryList.getCurrentItemParametersv(param, numArray, noOfParameters);
}

mvErrorEnum mvBEntryList::setCurrentEntryParametersi(const char* param,\
   mvIndex paramIndex)
{
   return entryList.setCurrentItemParametersi(param, paramIndex);
}

mvErrorEnum mvBEntryList::setCurrentEntryParameters(const char* param,\
   const char* option)
{
   return entryList.setCurrentItemParameters(param, option);
}

mvErrorEnum mvBEntryList::setCurrentEntryParametersf(const char* param,\
   mvFloat num)
{
   return entryList.setCurrentItemParametersf(param, num);
}

mvErrorEnum mvBEntryList::setCurrentEntryParametersv(const char* param,\
   mvFloat* numArray)
{
   return entryList.setCurrentItemParametersv(param, numArray);
}

