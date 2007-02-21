#include "mvBEntryUtility.h"


/** @brief sets a floating point variable
  * \param[in] paramFlag Behaviour parameter to be set
  * \param[in] num mvFloat float value
  * \return if ok MV_NO_ERROR (0), else any non-zero error value
  *
  * NOTE : timer getParameter is also called
  */
mvErrorEnum mvBEntryUtility::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvErrorEnum error;

   switch(paramFlag)
   {
      case MV_WEIGHT:
         return setWeight(num);
      default:
         error = bTimer.setParameterf(paramFlag, num);
         if (error == MV_INVALID_TIMER_PARAMETER)
         {
            //  NOT_FOUND then not 'behaviour' parameter error
            return MV_INVALID_BEHAVIOUR_PARAMETER;
         }
         else
         {
            return error;
         }
   }
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

/** @brief set this utility's index/count parameters
  * \param[in] paramFlag Behaviour parameter to be set
  * \param[in] index A mvIndex value
  * \return if ok MV_NO_ERROR (0), else any non-zero error value
  */
mvErrorEnum mvBEntryUtility::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   mvErrorEnum error = bTimer.setParameteri(paramFlag, index);
   if (error == MV_INVALID_TIMER_PARAMETER)
   {
      //  NOT_FOUND then not 'behaviour' parameter error
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   else
   {
      return error;
   }
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
   mvErrorEnum error;

   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_WEIGHT:
         *num = getWeight();
         return MV_NO_ERROR;
      default:
         error = bTimer.getParameterf(paramFlag, num);
         if (error == MV_INVALID_TIMER_PARAMETER)
         {
            //  NOT_FOUND then not 'behaviour' parameter error
            return MV_INVALID_BEHAVIOUR_PARAMETER;
         }
         else
         {
            return error;
         }
   }
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

/** @brief get this utility's index/count parameters
  * \param[in] paramFlag Parameter to be retrieved
  * \param[out] index Pointer to mvIndex memory location
  * \return if ok MV_NO_ERROR (0) else any non-zero error value
  *
  * NOTE if index pointer is NULL, then MV_INDEX_DEST_IS_NULL is returned.
  */
mvErrorEnum mvBEntryUtility::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   mvErrorEnum error;

   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   error = bTimer.getParameteri(paramFlag, index);
   if (error == MV_INVALID_TIMER_PARAMETER)
   {
      //  NOT_FOUND then not 'behaviour' parameter error
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   else
   {
      return error;
   }
}

/** @brief return pointer to the timer
  */
mvTimerPtr mvBEntryUtility::getTimerPtr()
{
   return &bTimer;
}

/** @brief Constructor
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

/** @brief set weight of behaviour
 * \param[in] entryWeight Positive mvFloat value
  * \return if ok MV_NO_ERROR (0) else any non-zero error value
 */
mvErrorEnum mvBEntryUtility::setWeight(mvFloat entryWeight)
{
   if (entryWeight < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }

   bWeight = entryWeight;
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFloat mvBEntryUtility::getWeight() const
{
   return bWeight;
}
