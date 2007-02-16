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
 * Log
 * Version     Date
 * 00-01-31    16/01/06
 *
 * - completed timer and doxygen documentation
 */
#include "mvMotionAI-Utilities.h"
#include "mvBEntryTimer.h"

/** @brief set vector variable of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[in] numArray mvFloat array pointer to memory location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  *
  * Automatically calls setParameterf as well
  */
mvErrorEnum mvTimer::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   // nothing to do
   return setParameterf(paramFlag, numArray[0]);
}

/** @brief set floating point variable of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[in] num mvFloat value
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvTimer::setParameterf(mvParamEnum paramFlag, mvFloat num)
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

/** @brief set the state parameter of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[in] option mvOptionEnum state value
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvTimer::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
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


/** @brief set an index parameter of the timer
  * \param[in] paramFlag mvParamEnum query option
  * \param[in] index
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvTimer::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_TIMER_PARAMETER;
}

/** @brief (one liner)
  * \param[in] paramFlag mvParamEnum query option
  * \param[out] numArray mvFloat pointer to memory location
  * \return either MV_NO_ERROR (0) or any non zero (ie.
  * MV_INVALID_TIMER_PARAMETER)
  */
mvErrorEnum mvTimer::getParameterv(mvParamEnum paramFlag,\
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
mvErrorEnum mvTimer::getParameterf(mvParamEnum paramFlag, mvFloat* num)
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
mvErrorEnum mvTimer::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

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
mvErrorEnum mvTimer::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (index == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   return MV_INVALID_TIMER_PARAMETER;
}

/** @brief set timer to timed
 */
void mvTimer::toTimed()
{
   isTimed = true;
}

/** @brief set timer to always perform
 */
void mvTimer::toAlways()
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
mvErrorEnum mvTimer::setElapsedTime(mvFloat timeInSecs)
{
   if (timeInSecs < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }

   if (timeInSecs > period)
   {
      if (period > 0.0)
      {
         elapsedTime = mvFMod(timeInSecs,period);
      }
      else
      {
         elapsedTime = period;
      }
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
mvErrorEnum mvTimer::setPeriod(mvFloat timeInSecs)
{
   if (timeInSecs < 0.0)
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }

   period = timeInSecs;
   if (elapsedTime > timeInSecs)
   {
      elapsedTime = mvFMod(timeInSecs,period);
   }

   return MV_NO_ERROR;
}

/** @brief retrieves period (in seconds) of timer
  * \return positive mvFloat value
  */
mvFloat mvTimer::getPeriod() const
{
   return period;
}

/** @brief retrieves elapsed time (in seconds) of timer
  * \return positive mvFloat value
  */
mvFloat mvTimer::getElapsedTime() const
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
mvFloat mvTimer::update(mvFloat timeInSecs)
{
   mvFloat noOfCount = 0;
   mvFloat result;

   // if positive
   if (timeInSecs >= 0.0)
   {
      if (!isTimed) // set to always
      {
         // once per call, no change to values
         noOfCount = 1;
      }
      else
      {
         elapsedTime += timeInSecs;
         if (elapsedTime > period)
         {
            elapsedTime /= period;
            elapsedTime = mvModf(elapsedTime, &noOfCount);
            elapsedTime *= period;
         }
      }
   }
   else
   {
      // TODO : negetive regression
      noOfCount = -1;
   }

   return noOfCount;
}

/** @brief timer constructor
  * \param[in] periodInSecs time when the action is performed
  * \param[in] eTime elaspedTime
  *
  * If period or elapsed time is invalid, the period will be 1.0 second
  * and elapsed time will be 0.0
  *
  * Default timer mode is set to always.
  */
mvTimer::mvTimer(mvFloat periodInSecs, mvFloat eTime)
{
   if (setPeriod(periodInSecs) != MV_NO_ERROR)
   {
      period = 1.0;
   }

   if (setElapsedTime(eTime) != MV_NO_ERROR)
   {
      elapsedTime = 0.0;
   }

   isTimed = false;
}

