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

mvPathway::mvPathway()
{
  noOfWaypoints = 0;
};

mvPathway::~mvPathway()
{
  removeAllWaypoints();
};

/**
 * adds a waypoint to this pathway
 *
 * NOTE:  repetitions are allowed
 */
void mvPathway::addWaypoint(mvWaypoint* pWaypoint)
{
  if (pWaypoint != NULL)
     waypoints.push_back(pWaypoint);
};

/**
 * removes the latest instance
 */
mvEnum mvPathway::removeWaypoint(mvWaypoint* pWaypoint)
{
   std::vector<mvWaypoint*>::reverse_iterator i;
   mvWaypoint* currentWaypoint = NULL;

   if (pWaypoint == NULL)
     return MV_FALSE;

   for (i = waypoints.rbegin(); i != waypoints.rend(); ++i)
   {
     currentWaypoint = *i;
     if (currentWaypoint != NULL && currentWaypoint == pWaypoint)
     {
        *i = NULL;
        return MV_TRUE;
     }
   }
   return MV_FALSE;
};

mvEnum mvPathway::setParameter(mvEnum paramFlag, mvEnum option)
{
   return MV_FALSE;
};

mvEnum mvPathway::setParameterf(mvEnum paramFlag, float num)
{
   return MV_FALSE;
};

mvEnum mvPathway::setParameterv(mvEnum paramFlag, float* numArray)
{
   return MV_FALSE;
};

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
};
