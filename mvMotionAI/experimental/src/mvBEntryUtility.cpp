#include "mvBEntryUtility.h"


/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvTimerPtr mvBEntryUtility::getTimerPtr()
{
   return &bTimer;
}

/** @brief (one liner)
  *
  * Default values for members in class
  * - Confined = true;
  * - Enabled = true;
  * - Timer = default values from class
  * - Weight = 1.0
  */
 mvBEntryUtility::mvBEntryUtility()
{
   confined = true;
   enabled = true;
   bWeight = 1.0;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryUtility::setWeight(mvFloat entryWeight)
{
   return MV_FUNCTION_NOT_IMPLEMENTED;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFloat mvBEntryUtility::getWeight() const
{
   return 0;
}
