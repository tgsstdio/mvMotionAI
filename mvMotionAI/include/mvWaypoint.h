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
 */

#ifndef MOTIONAI_MVWAYPOINT_H_
#define MOTIONAI_MVWAYPOINT_H_
#include <vector>
//#include "Vec3.h"
#include "mvMotionAI-Types.h"
#include "mvVec3.h"
#include "mvEnum.h"
//#include "mvGroup.h"
#include "mvForce.h"

/**
 * \class mvWaypoint
 * \brief Immediate class between Motion AI objects and gloabl world points
 *
 * Log
 *
 * Version		Date		Comments
 *
 * 00-01-02  31/5/06  - removing groups from system until better solution
 *                     arrives.
 *
 * 00-01-00   16/5/06      - renamed target to mvWaypoint.
 *
 * 00-00-07		9/3/06		- initialised Target Object,
 */

class mvWaypoint
{
   private:
      mvEnum initialisePoints(mvEnum type);
      mvEnum initialiseShapeDimensions(mvEnum shape);
      //mvGroup* groupPtr;
      mvVec3* points;
      //mvCount noOfPoints;
      mvEnum wayPointType;
      mvEnum wayPointShape;
      mvFloat* dimensions;
      std::vector<mvForce*> forceList;
      mvCount noOfForces;

   public:
      //mvWaypoint();
      //mvWaypoint(mvEnum targetType);
      mvWaypoint(mvEnum targetType, mvEnum targetShape);
      mvWaypoint(mvEnum targetType, mvEnum targetShape, mvFloat x, mvFloat y, mvFloat z);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      mvEnum addForce(mvForce* forcePtr);
      mvEnum removeForce(mvForce* forcePtr);
      void removeAllForces();
      mvCount getNoOfForces() const;
      mvCount getNoOfPoints() const;
      mvCount getNoOfDimensions() const;
      //void setGroup(mvGroup* wpGroup);
      mvEnum getType();
      mvEnum getShape();
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      ~mvWaypoint();
};

#endif

