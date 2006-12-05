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


static const mvIndex MV_CIRCULAR_RADIUS_INDEX = 0;
static const mvIndex MV_AACYLINDER_LENGTH_INDEX = 1;
static const mvIndex MV_AABOX_X_INDEX = 0;
static const mvIndex MV_AABOX_Y_INDEX = 1;
static const mvIndex MV_AABOX_Z_INDEX = 2;

/**
 * \brief initialises the shape dimensions accordingly to the obstacle
 * shape given.
 *
 * NOTE : inomplete - as it does not carry- over of parameters.
 * Partial completion for aabox, aacylinder (x,y,z), sphere.
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
}

mvOptionEnum mvObstacle::getShape() const
{
  return obstacleShape;
}

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
}
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
}

mvObstacle::mvObstacle(mvOptionEnum oShape, mvOptionEnum oType,mvFloat x, mvFloat y, mvFloat z)
{
  dimensions = NULL;
  position.set(x,y,z);
  obstacleShape = MV_NON_SHAPE;
  obstacleType = MV_NON_OBSTACLE_TYPE;
  initialiseShapeDimensions(oShape);
  checkValidType(oType);
}

mvObstacle::~mvObstacle()
{
  if (dimensions != NULL)
  {
     delete [] dimensions;
  }
}

/**
 * \brief returns no of dimensions required for current
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
}
/**
 * \brief get x component of the obstacle's position
 */
mvFloat mvObstacle::getX() const
{
   return position.getX();
}

/**
 * \brief get y component of the obstacle's position
 */
mvFloat mvObstacle::getY() const
{
   return position.getY();
}

/**
 * \brief get z component of the obstacle's position
 */
mvFloat mvObstacle::getZ() const
{
   return position.getZ();
}

void mvObstacle::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
  position.set(x,y,z);
}

mvOptionEnum mvObstacle::getType() const
{
  return obstacleType;
}

/**
 * \brief set state of obstacle by parameter
 * \param[in] paramFlag parameter to be set
 * \param[in] option Option value to be used
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
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
}

/**
 * \brief get state of obstacle by parameter
 * \param[in] paramFlag parameter to be retrieved
 * \param[out] option mvOptionEnum pointer to memory location
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 */
mvErrorEnum mvObstacle::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   if (option == NULL)
      return MV_OPTION_ENUM_DEST_IS_NULL;

   switch (paramFlag)
   {
      case MV_SHAPE:
         *option = obstacleShape;
         return MV_NO_ERROR;
      case MV_TYPE:
         *option = obstacleType;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_OBSTACLE_PARAMETER;
   }
}
/*
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH,
   MV_Y_LENGTH,
   MV_Z_DEPTH,
*/

/** @brief get single floating point value from this obstacle
 * \param[in] paramFlag Parameter option to retrieve
 * \param[in] num mvFloat pointer to memory location
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 */
mvErrorEnum mvObstacle::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   mvIndex tempIndex;

   if (num == NULL)
      return  MV_FLOAT_DEST_IS_NULL;

   switch(paramFlag)
   {
      case MV_LENGTH:
         switch(obstacleShape)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_AACYLINDER_LENGTH_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_RADIUS:
         switch(obstacleShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               *num = dimensions[MV_CIRCULAR_RADIUS_INDEX];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_X_WIDTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_X_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            case MV_X_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_Y_LENGTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Y_INDEX;
               return MV_NO_ERROR;
            case MV_Y_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_Z_DEPTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Z_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            case MV_Z_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               *num = dimensions[tempIndex];
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      default:
         return MV_INVALID_OBSTACLE_PARAMETER;
   }
}

/** @brief set single floating point value of this obstacle
 * \param[in] paramFlag parameter option to be set
 * \param[in] num mvFloat value to be used
 *
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 */
mvErrorEnum mvObstacle::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   mvIndex tempIndex;

   switch(paramFlag)
   {
      case MV_LENGTH:
         switch(obstacleShape)
         {
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_AACYLINDER_LENGTH_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_RADIUS:
         switch(obstacleShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
               dimensions[MV_CIRCULAR_RADIUS_INDEX] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_X_WIDTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_X_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_X_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_Y_LENGTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Y_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_Y_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_Z_DEPTH:
         switch(obstacleShape)
         {
            case MV_AABOX:
               tempIndex = MV_AABOX_Z_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            case MV_Z_AXIS_AA_CYLINDER:
               tempIndex = MV_AACYLINDER_LENGTH_INDEX;
               dimensions[tempIndex] = num;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      default:
         return MV_INVALID_OBSTACLE_PARAMETER;
   }
}
/**
 * \brief set obstacle's vector paramters
 * \param[in] paramFlag parameter option
 * \param[in] numArray mvFloat array pointer
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 *
 * Also call getParameterf using the numArray as one of the parameters
 */
mvErrorEnum mvObstacle::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   mvVec3 tempVector;
   mvIndex i;
   mvCount noOfDimensions;

   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_SHAPE_DIMENSIONS:
         switch(obstacleShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
            case MV_AABOX:
               noOfDimensions = getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  dimensions[i] = numArray[i];
               }
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_POSITION:
         position.setXYZ(numArray[0],numArray[1],numArray[2]);
         return MV_NO_ERROR;
      default:
         return setParameterf(paramFlag,numArray[0]);
   }
}

/** @brief get obstacle's vector parameter
 * \param[in] paramFlag parameter option
 * \param[out] numArray mvFloat array pointer to memory location
 * \param[out] noOfParameters mvCount array to memery location
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 *
 * Also call getParameterf using the numArray as one of the parameters
 */
mvErrorEnum mvObstacle::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   mvErrorEnum error;
   mvIndex i;
   mvCount noOfDimensions;

   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_SHAPE_DIMENSIONS:
         switch(obstacleShape)
         {
            case MV_SPHERE:
            case MV_X_AXIS_AA_CYLINDER:
            case MV_Z_AXIS_AA_CYLINDER:
            case MV_Y_AXIS_AA_CYLINDER:
            case MV_AABOX:
               noOfDimensions = getNoOfDimensions();
               for (i = 0; i < noOfDimensions; i++)
               {
                  numArray[i] = dimensions[i];
               }
               *noOfParameters = noOfDimensions;
               return MV_NO_ERROR;
            default:
               return MV_INVALID_OBSTACLE_SHAPE;
         }
      case MV_POSITION:
         numArray[0] = position.getX();
         numArray[1] = position.getY();
         numArray[2] = position.getZ();
         *noOfParameters = 3;
         return MV_NO_ERROR;
      default:
         error = getParameterf(paramFlag,&numArray[0]);
         if (error == MV_NO_ERROR)
         {
            *noOfParameters = 1;
         }
         else
         {
            *noOfParameters = 0;
         }
         return error;
   }
}

/** @brief set obstacle's index parameter
 * \param[in] paramFlag parameter option
 * \param[in] index Index value
 *
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 */
mvErrorEnum mvObstacle::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_OBSTACLE_PARAMETER;
}

/** @brief get obstacle's index parameter
 * \param[in] paramFlag parameter option
 * \param[out] index mvIndex pointer address to memory location
 *
 * \return mvErrorEnum enum. If successful, MV_NO_ERROR is returned else
 * other error value (! 0) is returned.
 */
mvErrorEnum mvObstacle::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (index == NULL)
      return MV_INDEX_VALUE_IS_INVALID;

   return MV_INVALID_OBSTACLE_PARAMETER;
}




