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
 */

#ifndef MOTIONAI_MVOBSTACLE_H_
#define MOTIONAI_MVOBSTACLE_H_
#include "mvEnum.h"
//#include "Vec3.h"
#include "mvVec3.h"
#include "mvMotionAI-Types.h"

/**
 * \class mvObstacle
 * \brief immoveable objects that are avoided.
 *
 *Log
 *
 *version     date     comments
 *00-01-05   23/8/06    - replaces Vec3 with mvVec3, types declared as
 *                      either mvFloat, mvIndex, mvCount.
 *
 *00-01-00   22/5/06    - renamed Obstacles into mvObstacle
 *
 *00-00-05    4/3/06    - introducing shapes in obstacle
 *
 *00-00-02    8/2/06    - separated obstacle and vehicle into their own
 *                     header and source files
 */

class mvObstacle
{
   private:
      mvEnum initialiseShapeDimensions(mvEnum shape);
      mvEnum checkValidState(mvEnum oState);
      mvVec3 position; /**< Global position in world */
      mvFloat* dimensions;
      mvEnum state;
      mvEnum obstacleType;
   public:
      //mvObstacle();
      //mvObstacle(mvEnum oType);
      mvObstacle(mvEnum oType, mvEnum oState);
      mvObstacle(mvEnum oType, mvEnum oState,mvFloat x, mvFloat y, mvFloat z);
      mvEnum getType() const;
      mvCount getNoOfDimensions() const;
      void setPosition(mvFloat x, mvFloat y, mvFloat z);
      mvEnum getState() const;
      mvFloat getX() const;
      mvFloat getY() const;
      mvFloat getZ() const;
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      ~mvObstacle();
};

#endif

