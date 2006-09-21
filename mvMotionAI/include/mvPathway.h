/**
 *\file mvPathway.h
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
 *
 */

#ifndef MOTIONAI_MVPATHWAY_H_
#define MOTIONAI_MVPATHWAY_H_
#include <vector>
#include "mvEnum.h"
#include "mvWaypoint.h"
#include "mvMotionAI-Types.h"
//#include "Vec3.h"

/**
 * \class mvPathway
 * \brief a series of points (or waypoints) that which represents a path
 *
 * Log
 *
 *version		date		comments
 *
 *00-01-00     22/5/06     - renamed pathways to mvPathway
 *
 *00-00-03		14/2/06		- declared Pathway class
 *
 *                         - created simple array of waypoints which can be loaded via scripts
 *
 */

class mvPathway
{
   private:
      std::vector<mvWaypoint*> waypoints;
      mvCount noOfWaypoints;

   public:
      mvPathway();
      void addWaypoint(mvWaypoint* pWaypoint);
      mvEnum removeWaypoint(mvWaypoint* pWaypoint);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, float num);
      mvEnum setParameterv(mvEnum paramFlag, float* numArray);
      void removeAllWaypoints();
      ~mvPathway();
};

#endif

