/**
 * \file mvWaypoint.h
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
 * Log
 *
 * Version		Date		Comments
 *
 * 00-01-21 27/11/06
 * - implementing MV_SHAPE
 *
 * 00-01-17  26/10/06
 * - add get/set parameter functions
 *
 * 00-01-02  31/5/06
 * - removing groups from system until better solution
 *                     arrives.
 *
 * 00-01-00   16/5/06
 * - renamed target to mvWaypoint.
 *
 * 00-00-07		9/3/06
 * - initialised Target Object,
 */

#ifndef MOTIONAI_MVWAYPOINT_H_
#define MOTIONAI_MVWAYPOINT_H_
#include <vector>
//#include "Vec3.h"
#include "mvMotionAI-Types.h"
#include MV_VEC_3_HEADER_FILE_H_
#include MV_ENUMS_HEADER_FILE_H_
//#include "mvGroup.h"
#include MV_FORCE_HEADER_FILE_H_

/**
 * \class mvWaypoint
 * \brief Immediate class between Motion AI objects and gloabl world points
 */
// TODO (White 2#1#): doygen documentation

static const mvCount MV_MAX_NO_OF_WAYPOINT_DIMENSIONS = 3;

class mvWaypoint
{
   private:
      mvErrorEnum initialisePoints(mvOptionEnum type);
      mvErrorEnum initialiseShapeDimensions(mvOptionEnum shape);
      //mvGroupPtr groupPtr;
      mvVec3* points;
      //mvCount noOfPoints;
      mvOptionEnum wayPointType;
      mvOptionEnum wayPointShape;
      mvFloat* dimensions;
      std::vector<mvForce*> forceList;
      mvCount noOfForces;

   public:
      //mvWaypoint();
      //mvWaypoint(mvEnum targetType);
      mvWaypoint(mvOptionEnum targetType, mvOptionEnum targetShape);
      mvWaypoint(mvOptionEnum targetType, mvOptionEnum targetShape, mvFloat x, mvFloat y, mvFloat z);
      mvErrorEnum addForce(mvForcePtr forcePtr);
      mvErrorEnum removeForce(mvForcePtr forcePtr);
      void removeAllForces();
      mvCount getNoOfForces() const;
      mvCount getNoOfPoints() const;
      mvCount getNoOfDimensions() const;
      //void setGroup(mvGroupPtr wpGroup);
      mvOptionEnum getType();
      mvOptionEnum getShape();
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      void setX(mvFloat x);
      void setY(mvFloat y);
      void setZ(mvFloat z);
      ~mvWaypoint();

      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
};

#endif

