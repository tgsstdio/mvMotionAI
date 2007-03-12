/**
 *\file mvObstacle.h
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
 *Log
 *
 *version     date     comments
 *00-01-21     25/11/06
 * - implemented MV_SHAPE_DIMENSIONS
 *
 *00-01-17     21/10/06
 * - adding and implementions get/set parameter functions
 *
 *00-01-16   14/10/06
 *  - redefined single type of mvEnums to 3 enums,
 *  - changed type to shape, state to type.
 *
 *00-01-05   23/8/06
 * - replaces Vec3 with mvVec3, types declared as
 * either mvFloat, mvIndex, mvCount.
 *
 *00-01-00   22/5/06
 * - renamed Obstacles into mvObstacle
 *
 *00-00-05    4/3/06
 * - introducing shapes in obstacle
 *
 *00-00-02    8/2/06
 *- separated obstacle and vehicle into their own header and source files
 */

#ifndef MOTIONAI_MVOBSTACLE_H_
#define MOTIONAI_MVOBSTACLE_H_

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include MV_VEC_3_HEADER_FILE_H_


/**
 * \class mvObstacle
 * \brief immoveable objects that are avoided.
 */

static const mvCount MV_MAX_NO_OF_OBSTACLE_DIMENSIONS = 4;

class mvObstacle
{
   private:
      mvErrorEnum initialiseShapeDimensions(mvOptionEnum shape);
      mvErrorEnum checkValidType(mvOptionEnum oType);
      mvVec3 position; /**< Global position in world */
      mvFloat* dimensions;
      mvOptionEnum obstacleType;
      mvOptionEnum obstacleShape;
   public:
      //mvObstacle();
      //mvObstacle(mvEnum oType);
      mvObstacle(mvOptionEnum oShape, mvOptionEnum oType);
      mvObstacle(mvOptionEnum oShape, mvOptionEnum oType,mvFloat x, mvFloat y, mvFloat z);
      mvOptionEnum getType() const;
      mvCount getNoOfDimensions() const;
      void setPosition(mvFloat x, mvFloat y, mvFloat z);
      mvOptionEnum getShape() const;
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvObstacle();
};

#endif

