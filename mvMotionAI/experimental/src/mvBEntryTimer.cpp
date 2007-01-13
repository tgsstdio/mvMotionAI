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
#include "mvMotionAI-Utilities.h"
#include "mvBEntryTimer.h"

/** @brief (one liner)
  *
  * Automatically calls setParameterf as well
  */
mvErrorEnum mvBEntryTimer::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   // nothing to do
   return setParameterf(paramFlag, numArray[0]);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryTimer::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   switch (paramFlag)
   {
      case MV_PERIOD:
         return setPeriod(num);
      case MV_ELAPSED_TIME:
         return setElapsedTime(num);
      default:
         return MV_INVALID_TIMER_PARAMETER;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryTimer::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch (paramFlag)
   {
      case MV_IS_TIMED:
         if (option == MV_TRUE)
            toTimed();
         else
            toAlways();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_TIMER_PARAMETER;
   }
}

/* TODO (White 2#1#): Doxgen Documentation */

/** @brief (one liner)
  * \param[in] paramFlag mvParamEnum query option
  * \param[in] index
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvBEntryTimer::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_TIMER_PARAMETER;
}

/** @brief (one liner)
  * \param[in] paramFlag mvParamEnum query option
  * \param[out] numArray mvFloat pointer to memory location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvBEntryTimer::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   mvCount noOfValuesReturned = 0;
   mvErrorEnum error;

   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      *noOfParameters = noOfValuesReturned;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   error = getParameterf(paramFlag, numArray);
   if(error == MV_NO_ERROR)
   {
      noOfValuesReturned = 1;
   }

   *noOfParameters = noOfValuesReturned;

   return error;
}

/** @brief retrieves a float variable from this timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[out] num mvFloat pointer to memory location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvBEntryTimer::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_PERIOD:
         *num =  period;
         return MV_NO_ERROR;
      case MV_ELAPSED_TIME:
         *num =  elapsedTime;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_TIMER_PARAMETER;
   }
}

/** @brief retrieves the state variables of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[out] option mvOptionEnum pointer to memory location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvBEntryTimer::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   switch (paramFlag)
   {
      case MV_IS_TIMED:
         if (isTimed)
            *option = MV_TRUE;
         else
            *option = MV_FALSE;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_TIMER_PARAMETER;
   }
}

/** @brief retrieves index parameter of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[out] index mvIndex pointer to memery location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvBEntryTimer::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_TIMER_PARAMETER;
}

/** @brief set timer to timed
  *
  */
void mvBEntryTimer::toTimed()
{
   isTimed = true;
}

/**
  * @brief set timer to always perform
  */
void mvBEntryTimer::toAlways()
{
   isTimed = false;
}

/** @brief Set the timer's elapsed time.
  * \return either MV_NO_ERROR or MV_FLOAT_VALUE_IS_NOT_POSITIVE
  * \param[in] timeInSecs Only positive mvFloats are allowed.
  *
  * If timeInSecs given is greater than the period of the timer
  * the remainder of timeInSecs/period is set as the elapsedTime
  */
mvErrorEnum mvBEntryTimer::setElapsedTime(mvFloat timeInSecs)
{
   if (timeInSecs < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }

   if (timeInSecs > period)
   {
      elapsedTime = mvFMod(timeInSecs,period);
      return MV_NO_ERROR;
   }
   else
   {
      elapsedTime = timeInSecs;
      return MV_NO_ERROR;
   }
}

/** @brief Sets the period (or the time in seconds when the
  * next action is required).
  *
  * Only positive numbers are allowed as the period.
  * If the past elapsed time is greater than the new period,
  * the remainder is the new elasped time. Also in reverse,
  * if the period is greater, then the old elapsed time is kept
  */
mvErrorEnum mvBEntryTimer::setPeriod(mvFloat timeInSecs)
{
   if (timeInSecs < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }

   period = timeInSecs;
   if (elaspedTime > timeInSecs)
   {
      elapsedTime = mvFMod(timeInSecs,period);
   }

   return MV_NO_ERROR;
}

/** @brief retrieves period (in seconds) of timer
  * \return positive mvFloat value
  */
mvFloat mvBEntryTimer::getPeriod() const
{
   return period;
}

/** @brief retrieves elapsed time (in seconds) of timer
  * \return positive mvFloat value
  */
mvFloat mvBEntryTimer::getElaspedTime() const
{
   return elapsedTime;
}

/** @brief update and check if action should be performed
  * \param[in] timeInSecs mvFloat should be positive.
  * \return either 0 or more times the action was required.
  *
  * The value, when timed,  returned is the number of times this action
  * should be performed in this duration, including the previous remaining
  * time on the timer.
  *
  * If set to always (or not timed) then the returned value is
  * time given divided the period of the timer.
  *
  * TODO : negetive regression
  */
mvCount mvBEntryTimer::update(mvFloat timeInSecs)
{
   //TODO : implement these functions
   mvFloat intPart;
   mvFloat total;

   // if positive
   if (timeInSecs > 0.0)
   {
      if (!isTimed)
      {
         result = timeInSecs;
         result /= period;
         result = mvModf(result, &intPart);
      }
      else
      {
         elapsedTime += timeInSecs;
         if (elapsedTime > period)
         {
            elapsedTime /= period;
            elapsedTime = mvModf(elapsedTime, &intPart);
         }
      }
   }
   else
   {
      // TODO : negetive regression
      intPart = 1;
   }

   return (mvCount) intPart;
}

/** @brief timer constructor
  *
  * default timer mode is set to always
  */
mvBEntryTimer::mvBEntryTimer(mvFloat periodInSecs, mvFloat eTime)
{
   period = periodInSecs;
   elapsedTime = eTime;
   isTimed = false;
}

