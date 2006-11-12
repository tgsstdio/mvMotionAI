/**
 * \file mvPathway.cpp
 *
 * Copyright (c) 2006 David Young.
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

#include "mvPathway.h"
#include "mvMotionAI-Utilities.h"

mvPathway::mvPathway()
{
  noOfWaypoints = 0;
  currentWPIndex = MV_NO_CURRENT_INDEX;
}

mvPathway::~mvPathway()
{
  removeAllWaypoints();
}

/**
 * adds a waypoint to this pathway
 *
 * NOTE:  repetitions are allowed
 */
void mvPathway::addWaypoint(mvWaypoint* pWaypoint)
{
  if (pWaypoint != NULL)
  {
     waypoints.push_back(pWaypoint);
     ++noOfWaypoints;
  }
}

/**
 * removes the latest instance
 */
mvErrorEnum mvPathway::removeWaypoint(mvWaypoint* pWaypoint)
{
   std::vector<mvWaypoint*>::reverse_iterator i;
   mvWaypoint* currentWaypoint = NULL;
   mvIndex wpIndex;

   if (pWaypoint == NULL)
     return MV_ITEM_POINTER_IS_NULL;

   wpIndex = noOfWaypoints;
   for (i = waypoints.rbegin(); i != waypoints.rend(); ++i)
   {
     currentWaypoint = *i;
     if (currentWaypoint != NULL && currentWaypoint == pWaypoint)
     {
        *i = NULL;
        --noOfWaypoints;
        if (wpIndex == currentWPIndex)
        {
            currentWPIndex = MV_NO_CURRENT_INDEX;
        }
        return MV_NO_ERROR;
     }
     --wpIndex;
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

void mvPathway::removeAllWaypoints()
{
   std::vector<mvWaypoint*>::iterator i;
   mvWaypoint* tempPoint = NULL;

   for (i = waypoints.begin(); i != waypoints.end(); ++i)
   {
      tempPoint = *i;
      if (tempPoint != NULL)
      {
         delete tempPoint;
         *i = NULL;
      }
   }
   noOfWaypoints = 0;
}

mvErrorEnum mvPathway::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* numArray)
{
   return mvSetClassParameterv<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,numArray, noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setCurrentNodeParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setCurrentNodeParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setCurrentNodeParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::setCurrentNodeParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   return mvSetClassParameterv<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,numArray);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getCurrentNodeParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getCurrentNodeParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getCurrentNodeParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvPathway::getCurrentNodeParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvWaypoint>(waypoints,currentWPIndex,noOfWaypoints,paramFlag,numArray, noOfParameters);
}


