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
#include "mvMotionAI-Types.h"
#include <vector>
#include MV_ENUMS_HEADER_FILE_H_
#include MV_WAYPOINT_HEADER_FILE_H_
//#include "Vec3.h"

/**
 * \class mvPathway
 * \brief a series of points (or waypoints) that which represents a path
 *
 * Log
 *
 *version		date		comments
 *00-01-17     26/10/06    -  add get/set parameter functions
 *
 *                         -  add node get/set node parameters functions
 *
 *00-01-16     15/10/06    - converted mvenums to 3 enums
 *
 *00-01-00     22/5/06     - renamed pathways to mvPathway
 *
 *00-00-03		14/2/06		- declared Pathway class
 *
 *                         - created simple array of waypoints which can be loaded via scripts
 *
 */

 // TODO : removing waypoint pointer to indexes

class mvPathway
{
   private:
      std::vector<mvWaypointPtr> waypoints;
      mvIndex currentWPIndex;
      mvCount noOfWaypoints;

   public:
      mvPathway();
      void addWaypoint(mvWaypointPtr pWaypoint);
      mvErrorEnum removeWaypoint(mvWaypointPtr pWaypoint);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setCurrentNodeParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setCurrentNodeParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentNodeParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setCurrentNodeParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getCurrentNodeParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getCurrentNodeParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getCurrentNodeParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getCurrentNodeParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      void removeAllWaypoints();
      ~mvPathway();
};

#endif

