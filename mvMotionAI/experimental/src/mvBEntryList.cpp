#include "mvBEntryList.h"
/* TODO (White 2#1#): Implement all functions below */

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBEntryList::~mvBEntryList()
{

}

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
   return entryList.set
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
   return entryList.setCurrentItemParameteri(paramFlag, outIndex);
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
   return entryList.setItemParameterv(entryList,paramFlag, numArray,\
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

   return
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameter(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getEntryParameteri(mvIndex entryIndex,\
   mvParamEnum paramFlag, mvIndex* index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameterf(mvParamEnum paramFlag, mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setParameteri(mvParamEnum paramFlag, mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{

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

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addNewBehaviourEntry(mvOptionEnum behaviourType)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addExistingBehaviourEntry(mvIndex behaviourIndex)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::addExistingGroupBehaviourEntry(\
   mvIndex behaviourIndex, mvIndex groupIndex, mvBaseBehaviour* dBehaviour)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryList::setDefaultWeight(mvFloat factor)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultPathway(mvIndex pwIndex)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultWaypoint(mvIndex wpIndex)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryList::setDefaultBody(mvIndex bodyIndex)
{

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

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryListNode * mvBEntryList::getEntry(mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryListNode * mvBEntryList::findExistingGroupEntry(mvIndex bIndex,\
   mvIndex gIndex)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBEntryList::mvBEntryList(mvFloat dWeight, mvIndex dBody, mvIndex dWaypoint,\
   mvIndex dPathway)
{

}

mvErrorEnum mvBEntryList::getEntryParametersi(mvIndex entryIndex,\
   const char* param, mvIndex* outIndex)
{

}

mvErrorEnum mvBEntryList::getEntryParameters(mvIndex entryIndex, const char* param,\
   const char** option)
{

}

mvErrorEnum mvBEntryList::getEntryParametersf(mvIndex entryIndex, const char* param,\
   mvFloat* num)
{

}

mvErrorEnum mvBEntryList::getEntryParametersv(mvIndex entryIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}


mvErrorEnum mvBEntryList::setEntryParametersi(mvIndex entryIndex,const char* param,\
   mvIndex paramIndex)
{

}

mvErrorEnum mvBEntryList::setEntryParameters(mvIndex entryIndex,const char* param,\
   mvOptionEnum option)
{

}

mvErrorEnum mvBEntryList::setEntryParametersf(mvIndex entryIndex,const char* param,\
   mvFloat num)
{

}

mvErrorEnum mvBEntryList::setEntryParametersv(mvIndex entryIndex,const char* param,\
   mvFloat* numArray)
{

}


mvErrorEnum mvBEntryList::getCurrentEntryParametersi(const char* param,\
   mvIndex* outIndex)
{

}

mvErrorEnum mvBEntryList::getCurrentEntryParameters(const char* param,\
   const char** option)
{

}

mvErrorEnum mvBEntryList::getCurrentEntryParametersf(const char* param,\
   mvFloat* num)
{

}

mvErrorEnum mvBEntryList::getCurrentEntryParametersv(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}


mvErrorEnum mvBEntryList::setCurrentEntryParametersi(const char* param,\
   mvIndex paramIndex)
{

}

mvErrorEnum mvBEntryList::setCurrentEntryParameters(const char* param,\
   mvOptionEnum option)
{

}

mvErrorEnum mvBEntryList::setCurrentEntryParametersf(const char* param,\
   mvFloat num)
{

}

mvErrorEnum mvBEntryList::setCurrentEntryParametersv(const char* param,\
   mvFloat* numArray)
{

}

