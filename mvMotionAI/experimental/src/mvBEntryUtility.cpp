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
   mvErrorEnum error;

   switch(paramFlag)
   {
      case MV_IS_CONFINED:
         // i.e non zero is true
         if(option == MV_FALSE)
         {
            confined = false;
         }
         else
         {
            confined = true;
         }
         return MV_NO_ERROR;
      case MV_IS_ENABLED:
         // i.e non zero is true
         if(option == MV_FALSE)
         {
            enabled = false;
         }
         else
         {
            enabled = true;
         }
         return MV_NO_ERROR;
      default:
         error = bTimer.setParameter(paramFlag, option);
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

/** @brief set this utility's index/count parameters
  * \param[in] paramFlag Behaviour parameter to be set
  * \param[in] index A mvIndex index value
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

/** @brief retrieves utility's vector/array parameters
  * \param[in] paramFlag Behaviour parameter to be retrieved
  * \param[out] numArray mvFloat array pointer
  * \param[out] noOfParameters no of parameteters returned by function
  *
  * NOTE: also calls getParameterf
  */
mvErrorEnum mvBEntryUtility::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   // TODO: implement later
   /*
   mvErrorEnum error = bTimer.getParameterv(paramArray, numArray,\
      noOfParameters);

   if (error == MV_INVALID_TIMER_PARAMETER)
   {
      //  NOT_FOUND then not 'behaviour' parameter error
      return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   else
   {
      return error;
   }
   */

   return MV_FUNCTION_NOT_IMPLEMENTED;

}

/** @brief retrieves single floating point variable of entry
  * \param[in] paramFlag Behaviour parameter to be retrieved
  * \param[out] numArray mvFloat pointer to memory location
  *
  * NOTE : also calls its timer's getParameterf
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
  * \param[in] paramFlag Behaviour parameter to be retrieved
  * \param[out] option mvFloat array pointer
  *
  * NOTE : also calls its timer's getParameter
  */
mvErrorEnum mvBEntryUtility::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   mvErrorEnum error;

   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_CONFINED:
         if(confined)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      case MV_IS_ENABLED:
         if(enabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         error = bTimer.getParameter(paramFlag, option);
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
   // TODO: implement later
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
