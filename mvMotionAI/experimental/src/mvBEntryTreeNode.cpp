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
#include "mvBEntryTreeNode.h"

/** @brief (one liner)
  *
  * Automatically calls timer setParameteri
  */
mvErrorEnum mvBEntryTreeNode::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   switch(paramFlag)
   {
      case MV_INDEX:
         bEntryNode = index;
         return MV_NO_ERROR;
      default:
         return timer.setParameteri(paramFlag, index);
   }
}

/** @brief (one liner)
  *
  * Automatically calls timer's getParameterv, then its own getParameterf
  */
mvErrorEnum mvBEntryTreeNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{
   mvErrorEnum error;

   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   error = timer.getParameterv(paramFlag, numArray, noOfParameters);
   if (error == MV_INVALID_TIMER_PARAMETER)
   {
      error = getParameterf(paramFlag, numArray);
      if (error == MV_NO_ERROR)
      {
         *noOfParameters = 1;
      }
      else
      {
         *noOfParameters = 0;
      }
   }


   return error;
}

/** @brief (one liner)
  *
  * Automatically calls the timer's getParameterf
  */
mvErrorEnum mvBEntryTreeNode::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   switch(paramFlag)
   {
      case MV_WEIGHT:
         *num = weight;
         return MV_NO_ERROR;
      default:
         return timer.getParameterf(paramFlag, num);
   }
}

/** @brief (one liner)
  *
  * Automatically calls the timer's getParameter
  */
mvErrorEnum mvBEntryTreeNode::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   switch(paramFlag)
   {
      case MV_MODE:
         *option = mode;
         return MV_NO_ERROR;
      default:
         return timer.getParameter(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * Automatically calls the timer's getParameteri
  */
mvErrorEnum mvBEntryTreeNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* paramIndex)
{
   switch(paramFlag)
   {
      case MV_INDEX:
         *paramIndex = bEntryNode;
         return MV_NO_ERROR;
      default:
         return timer.getParameteri(paramFlag, paramIndex);
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryTreeNode::setNextLevel(mvBEntryTreeNode* node)
{
   nextLevel = node;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryTreeNode::setNextNode(mvBEntryTreeNode* node)
{
   nextNode = node;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryTreeNode::setPrevLevel(mvBEntryTreeNode* node)
{
   prevLevel = node;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBEntryTreeNode::setPrevNode(mvBEntryTreeNode* node)
{
   prevNode = node;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryTreeNode * mvBEntryTreeNode::getNextLevel()
{
   return nextLevel;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryTreeNode * mvBEntryTreeNode::getNextNode()
{
   return nextNode;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryTreeNode * mvBEntryTreeNode::getPrevLevel()
{
   return prevLevel;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryTreeNode * mvBEntryTreeNode::getPrevNode()
{
   return prevNode;
}

/** @brief set the node's weight value
  * \param[in] bWeight positive mvFloat value
  *
  * if given weight value is positive value, then old value is kept
  */
mvErrorEnum mvBEntryTreeNode::setWeight(mvFloat bWeight)
{
   if (bWeight > 0)
   {
      weight = bWeight;
      return MV_NO_ERROR;
   }
   else
   {
      return MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBEntryTimer * mvBEntryTreeNode::getTimer()
{
   return &timer;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvFloat mvBEntryTreeNode::getWeight() const
{
   return weight;
}

/* TODO (White 2#1#): implement functions below */
/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBEntryTreeNode::mvBEntryTreeNode(mvIndex bEntryIndex,\
         mvOptionEnum bNodeMode,\
         mvFloat bEWeight,\
         mvFloat period,\
         mvFloat elapsedTime,
         mvBEntryTreeNode* beNextNode,\
         mvBEntryTreeNode* beNextLevel,
         mvBEntryTreeNode* bePrevNode,\
         mvBEntryTreeNode* bePrevLevel
         )
{
   bEntryNode = bEntryIndex;
   weight = 0.0;

   setWeight(bEWeight);
   setMode(bNodeMode);
   setNextNode(beNextNode);
   setNextLevel(beNextLevel);
   setPrevLevel(bePrevLevel);
   setPrevNode(bePrevNode);
   timer.setPeriod(period);
   timer.setElapsedTime(elapsedTime);
}

mvIndex mvBEntryTreeNode::getEntryIndex()
{
   return bEntryNode;
}

/** @brief (one liner)
  *
  * Automatically calls timer's setParameter
  */
mvErrorEnum mvBEntryTreeNode::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   switch (paramFlag)
   {
      case MV_MODE:
         return setMode(option);
      default:
         return timer.setParameter(paramFlag, option);
   }
}

/** @brief (one liner)
  *
  * Automatically calls timer's setParameterf
  */
mvErrorEnum mvBEntryTreeNode::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   switch (paramFlag)
   {
      case MV_WEIGHT:
         return setWeight(num);
      default:
         return timer.setParameterf(paramFlag, num);
   }
}

/** @brief (one liner)
  *
  * Automatically calls timer's setParameterv, then calls its setParameterf
  */
mvErrorEnum mvBEntryTreeNode::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   mvErrorEnum error;

   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   // check timer parameter first
   error = timer.setParameterv(paramFlag, numArray);
   if (error == MV_INVALID_TIMER_PARAMETER)
   {
      // then call setParameterf
      error = setParameterf(paramFlag,numArray[0]);
   }

   return error;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBEntryTreeNode::setMode(mvOptionEnum option)
{
   switch(option)
   {
      case MV_WEIGHTED:
      case MV_XOR:
      case MV_PRORITIZED_DITHERING:
      case MV_RANDOM:
      case MV_RANDOMIZED_WEIGHTED:
         mode = option;
         return MV_NO_ERROR;
      default:
         mode = MV_NON_BEHAVIOUR_ENTRY_MODE;
         return MV_INVALID_BEHAVIOUR_ENTRY_INITIALIZATION;
   }
}

void mvBEntryTreeNode::addNewNode(mvBEntryTreeNode* childNode)
{
   if (nextNode != NULL && childNode != NULL)
   {
      setNextNode(childNode);
      childNode->setPrevNode(this);
   }
}

void mvBEntryTreeNode::addNewLevel(mvBEntryTreeNode* childNode)
{
   if (nextLevel != NULL && childNode != NULL)
   {
      setNextLevel(childNode);
      childNode->setPrevLevel(this);
   }
}

