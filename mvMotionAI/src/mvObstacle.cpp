/**
 * \file mvObstacle.cpp
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

#include "mvObstacle.h"

/**
 * initialises the shape dimensions accordingly to the obstacle
 * shape given.
 *
 * NOTE : inomplete - as it does not carry- over of parameters
 *
 * partial completion for aabox, aacylinder (x,y,z), sphere,
 *
 */

mvErrorEnum mvObstacle::initialiseShapeDimensions(mvOptionEnum shape)
{
   mvFloat tempDims[MV_MAX_NO_OF_OBSTACLE_DIMENSIONS];
   mvIndex i;
   mvCount noOfDims;

   // saving variables
   if (dimensions != NULL)
   {
      noOfDims = getNoOfDimensions();

      for (i = 0; i < noOfDims; ++i)
      {
         tempDims[i] = dimensions[i];
      }
      delete [] dimensions;
      dimensions = NULL;
   }

   switch(shape)
   {
      // valid shapes
      case MV_AABOX:
      case MV_SPHERE:
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         obstacleShape = shape;
         break;
      default:
         obstacleShape = MV_NON_SHAPE;
         dimensions = NULL;
         return MV_INVALID_OBSTACLE_SHAPE;
   }

   noOfDims = getNoOfDimensions();
   if (noOfDims > 0)
   {
      dimensions = new mvFloat[noOfDims];
   }
   for (i = 0; i < noOfDims; ++i)
   {
      dimensions[i] = tempDims[i];
   }
   return MV_NO_ERROR;
};

mvOptionEnum mvObstacle::getShape() const
{
  return obstacleShape;
};

mvErrorEnum mvObstacle::checkValidType(mvOptionEnum oType)
{
   switch(oType)
   {
     case MV_SOLID_OBSTACLE:
     case MV_LIQUID_OBSTACLE:
     case MV_AIR_OBSTACLE:
       obstacleType = oType;
       return MV_NO_ERROR;
     default:
       obstacleType = MV_NON_OBSTACLE_TYPE;
       return MV_INVALID_OBSTACLE_TYPE;
   }
};
/*
mvObstacle::mvObstacle()
{
  obstacleType = MV_NO_SHAPE;
  dimensions = NULL;
};

mvObstacle::mvObstacle(mvEnum oType)
{
  dimensions = NULL;
  obstacleType = MV_NO_SHAPE;
  initialiseShapeDimensions(oType);
};
*/
mvObstacle::mvObstacle(mvOptionEnum oShape, mvOptionEnum oType)
{
  dimensions = NULL;
  obstacleShape = MV_NON_SHAPE;
  obstacleType = MV_NON_OBSTACLE_TYPE;
  initialiseShapeDimensions(oShape);
  checkValidType(oType);
};

mvObstacle::mvObstacle(mvOptionEnum oShape, mvOptionEnum oType,mvFloat x, mvFloat y, mvFloat z)
{
  dimensions = NULL;
  position.set(x,y,z);
  obstacleShape = MV_NON_SHAPE;
  obstacleType = MV_NON_OBSTACLE_TYPE;
  initialiseShapeDimensions(oShape);
  checkValidType(oType);
};

mvObstacle::~mvObstacle()
{
  if (dimensions != NULL)
  {
     delete [] dimensions;
  }
};

/**
 * returns no of dimensions required for current
 * obstacle shape
 */
mvCount mvObstacle::getNoOfDimensions() const
{
   static const mvCount MV_NO_OF_AABOX_DIMENSIONS = 3;
   static const mvCount MV_NO_OF_AACYLINDER_DIMENSIONS = 2;
   static const mvCount MV_NO_OF_SPHERE_DIMENSIONS = 1;
   static const mvCount MV_INVALID_DIMENSIONS = 0;

   switch(obstacleType)
   {
      case MV_SPHERE:
         return MV_NO_OF_SPHERE_DIMENSIONS;
      case MV_AABOX:
         return MV_NO_OF_AABOX_DIMENSIONS;
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         return MV_NO_OF_AACYLINDER_DIMENSIONS;
      default:
         return MV_INVALID_DIMENSIONS;
  }
};

/**
 * set flag parameters of obstacle
 *
 * NOTE : implementations for c
 */
mvErrorEnum mvObstacle::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch (paramFlag)
   {
      case MV_SHAPE:
         return initialiseShapeDimensions(option);
      case MV_TYPE:
        return checkValidType(option);
      default:
         return MV_INVALID_OBSTACLE_PARAMETER;
   }
};

void mvObstacle::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
  position.set(x,y,z);
};

mvErrorEnum mvObstacle::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_OBSTACLE_PARAMETER;
};

mvErrorEnum mvObstacle::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   return MV_INVALID_OBSTACLE_PARAMETER;
};

mvFloat mvObstacle::getX() const
{
   return position.getX();
};

mvFloat mvObstacle::getY() const
{
   return position.getY();
}

mvFloat mvObstacle::getZ() const
{
   return position.getZ();
};

mvOptionEnum mvObstacle::getType() const
{
  return obstacleType;
};
