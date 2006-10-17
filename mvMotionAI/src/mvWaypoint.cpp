/**
 * \file mvWaypoint.cpp
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

#include "mvWaypoint.h"
/**
 * returns no of point for this waypoint
 */
static const mvCount MV_MAX_NO_OF_WAYPOINT_POINTS = 1;
static const mvIndex MV_WAYPOINT_MAIN_POSITION_INDEX = 0;

mvCount mvWaypoint::getNoOfPoints() const
{
  // static const mvCount MV_NO_OF_NURBS_POINTS = 3;
   static const mvCount MV_NO_OF_SINGLE_POINTS = 1;
   static const mvCount MV_NO_OF_GROUP_POINTS = 1;
   static const mvCount MV_NO_OF_INVALID_POINTS = 0;

   switch (wayPointType)
   {
   /**
    case MV_NURB_WAYPOINT:
        return MV_NO_OF_NURBS_POINTS;
    **/
    case MV_SINGLE_WAYPOINT:
      return MV_NO_OF_SINGLE_POINTS;
    case MV_GROUP_WAYPOINT:
      return MV_NO_OF_GROUP_POINTS;
    default:
      return MV_NO_OF_INVALID_POINTS;
   }
};

/**
 * initialises the points accordingly to the waypoint
 * type given.
 *
 * NOTE : completed for single, nurbs and group waypoints
 *
 */
mvErrorEnum mvWaypoint::initialisePoints(mvOptionEnum type)
{
   mvVec3 tempPoints[MV_MAX_NO_OF_WAYPOINT_POINTS];
   mvIndex i;
   mvCount noOfPoints;

   if (points != NULL)
   {
      noOfPoints = getNoOfPoints();
      for (i = 0; i < noOfPoints; ++i)
      {
        tempPoints[i] = points[i];
      }
      delete [] points;
      points = NULL;
   }

   /*
   if (type == MV_NURB_WAYPOINT)
   {
      points = new mvVec3[MV_NO_OF_NURBS_POINTS];
      wayPointType = MV_NURB_WAYPOINT;
   }
   */
   switch (type)
   {
      case MV_SINGLE_WAYPOINT:
      case MV_GROUP_WAYPOINT:
      //case MV_NURB_WAYPOINT:
         wayPointType = type;
         break;
      default:
         wayPointType = MV_NON_WAYPOINT_TYPE;
         return MV_INVALID_WAYPOINT_TYPE;
   }

   // copy back
   noOfPoints = getNoOfPoints();
   if (noOfPoints > 0)
   {
      points = new mvVec3[noOfPoints];
   }
   for (i = 0; i < noOfPoints; ++i)
   {
     points[i] = tempPoints[i];
   }
   return MV_NO_ERROR;
};

/**
 * returns no of dimensions required for current
 * waypoint shape
 */
mvCount mvWaypoint::getNoOfDimensions() const
{
   static const mvCount MV_NO_OF_AABOX_DIMENSIONS = 3;
   static const mvCount MV_NO_OF_AACYLINDER_DIMENSIONS = 2;
   static const mvCount MV_NO_OF_SPHERE_DIMENSIONS = 1;
   static const mvCount MV_INVALID_DIMENSIONS = 0;

   switch(wayPointShape)
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
 * initialises the shape dimensions accordingly to the waypoint
 * shape given.
 *
 * NOTE : inomplete - as it does not carry- over of parameters
 *
 * partial completion for aabox, aacylinder (x,y,z), sphere,
 *
 */
mvErrorEnum mvWaypoint::initialiseShapeDimensions(mvOptionEnum shape)
{
   mvCount noOfDims, i;
   mvFloat tempDims[MV_MAX_NO_OF_WAYPOINT_DIMENSIONS];

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
      case MV_AABOX:
      case MV_SPHERE:
      case MV_X_AXIS_AA_CYLINDER:
      case MV_Y_AXIS_AA_CYLINDER:
      case MV_Z_AXIS_AA_CYLINDER:
         wayPointShape = shape;
         break;
      default:
         wayPointShape = MV_NON_SHAPE;
         return MV_INVALID_WAYPOINT_SHAPE;
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

/*
 * \constructor default constructor
 *
 * NOTE :
 *

mvWaypoint::mvWaypoint()
{
  groupPtr = NULL;
  points = NULL;
  //noOfPoints = 0;
  wayPointType = MV_INVALID_WAYPOINT_TYPE;
  dimensions = NULL;
  wayPointShape = MV_NO_SHAPE;
};

*
 * \constructor second constructor defines type
 *
 * NOTE :
 *
mvWaypoint::mvWaypoint(mvEnum targetType)
{
  points = NULL;
  dimensions = NULL;
  groupPtr = NULL;
  initialisePoints(targetType);
  initialiseShapeDimensions(MV_NO_SHAPE);
};

*
 * \constructor third constructor defines type and shape
 *
 * NOTE :
 */

mvWaypoint::mvWaypoint(mvOptionEnum targetType, mvOptionEnum targetShape)
{
  points = NULL;
  dimensions = NULL;
  //groupPtr = NULL;
  noOfForces = 0;
  initialisePoints(targetType);
  initialiseShapeDimensions(targetShape);
};

mvWaypoint::mvWaypoint(mvOptionEnum targetType, mvOptionEnum targetShape, mvFloat x, mvFloat y, mvFloat z)
{
  points = NULL;
  dimensions = NULL;
  //groupPtr = NULL;
  initialisePoints(targetType);
  initialiseShapeDimensions(targetShape);
  noOfForces = 0;
  if (points != NULL)
  {
     points[MV_WAYPOINT_MAIN_POSITION_INDEX].set(x,y,z);
  }
};

mvErrorEnum mvWaypoint::addForce(mvForce* forcePtr)
{
   std::vector<mvForce*>::iterator i;
   mvForce* tempForce = NULL;

   if (forcePtr == NULL)
      return MV_PARAM_POINTER_IS_NULL;

   for (i = forceList.begin(); i != forceList.end(); ++i)
   {
      tempForce = *i;
      if (tempForce != NULL)
      {
         if(tempForce == forcePtr)
            return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
      }
   }
   forceList.push_back(forcePtr);
   forcePtr->incrementCount();
   ++noOfForces;
   return MV_NO_ERROR;
};

mvErrorEnum mvWaypoint::removeForce(mvForce* forcePtr)
{
   std::vector<mvForce*>::iterator i;
   mvForce* tempForce = NULL;

   if (forcePtr == NULL)
      return MV_PARAM_POINTER_IS_NULL;

   for (i = forceList.begin(); i != forceList.end(); ++i)
   {
      tempForce = *i;
      if (tempForce != NULL)
      {
         if (tempForce == forcePtr)
         {
           //delete tempForce;
           *i = NULL;
           --noOfForces;
           forcePtr->decrementCount();
           return MV_NO_ERROR;
         }
      }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
};

void mvWaypoint::removeAllForces()
{
   std::vector<mvForce*>::iterator i;
   mvForce* tempForce = NULL;

   for (i = forceList.begin(); i != forceList.end(); ++i)
   {
      tempForce = *i;
      if (tempForce != NULL)
      {
         //delete tempForce;
         tempForce->decrementCount();
         *i = NULL;
      }
   }
   noOfForces = 0;
};

mvCount mvWaypoint::getNoOfForces() const
{
   return noOfForces;
};

/**
 * returns current type of waypoint
 */
mvOptionEnum mvWaypoint::getType()
{
  return wayPointType;
};
/**
 * returns current shape of waypoint
 */
mvOptionEnum mvWaypoint::getShape()
{
  return wayPointShape;
};

/*
mvCount mvWaypoint::getNoOfDimensions() const
{
  switch(wayPointType)
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
*/

/**
 *  sets the current group to waypoint
 *
void mvWaypoint::setGroup(mvGroup* wpGroup)
{
   groupPtr = wpGroup;
};
**/

/**
 * set flag parameters of this waypoint
 *
 * NOTE : arguments accepted
 *
 *  MV_WAYPOINT_TYPE - single ,nurbs, group
 *
 *  MV_WAYPOINT_SHAPE - aabox, aacylinder, sphere
 *
 */
mvErrorEnum mvWaypoint::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   if (paramFlag == MV_TYPE)
   {
     return initialisePoints(option);
   }
   else if (paramFlag == MV_SHAPE)
   {
      return initialiseShapeDimensions(option);
   }
   else
   {
      return MV_INVALID_WAYPOINT_PARAMETER;
   }
};

/**
 * set a dimensional parameter of this waypoint
 *
 * NOTE : arguments accepted
 *
 *  MV_RADIUS - aacylinder, sphere
 *
 *  MV_LENGTH - aacylinder, sphere
 *
 */
mvErrorEnum mvWaypoint::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   //static const mvIndex MV_AABOX_X_LENGTH_INDEX_NO = 0;
   //static const mvIndex MV_AABOX_Y_LENGTH_INDEX_NO = 1;
   //static const mvIndex MV_AABOX_Z_LENGTH_INDEX_NO = 2;
   static const mvIndex MV_SPHERE_RADIUS_INDEX_NO = 0;
   static const mvIndex MV_AACYLINDER_RADIUS_INDEX_NO = 0;
   static const mvIndex MV_AACYLINDER_LENGTH_INDEX_NO = 1;

   mvIndex itemIndex;

   switch (paramFlag)
   {
      case MV_RADIUS:
         if (wayPointShape == MV_SPHERE)
         {
            itemIndex = MV_SPHERE_RADIUS_INDEX_NO;
         }
         else if (wayPointShape == MV_X_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_RADIUS_INDEX_NO;
          }
         else if (wayPointShape == MV_Y_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_RADIUS_INDEX_NO;
         }
         else if (wayPointShape == MV_Z_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_RADIUS_INDEX_NO;
         }
         else
         {
            return MV_INVALID_WAYPOINT_SHAPE;
         }
         dimensions[itemIndex] = num;
         return MV_NO_ERROR;
      case MV_LENGTH:
         if (wayPointShape == MV_X_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_LENGTH_INDEX_NO;
         }
         else if (wayPointShape == MV_Y_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_LENGTH_INDEX_NO;
         }
         else if (wayPointShape == MV_Z_AXIS_AA_CYLINDER)
         {
            itemIndex = MV_AACYLINDER_LENGTH_INDEX_NO;
         }
         else
         {
            return MV_INVALID_WAYPOINT_SHAPE;
         }
         dimensions[itemIndex] = num;
         return MV_NO_ERROR;
      default:
         return MV_INVALID_WAYPOINT_PARAMETER;
  }
};

mvErrorEnum mvWaypoint::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
  return MV_INVALID_WAYPOINT_PARAMETER;
};

/**
 * deconstructor
 */
mvWaypoint::~mvWaypoint()
{
  if (dimensions != NULL)
  {
    delete [] dimensions;
  }

  if (points != NULL)
  {
    delete [] points;
  }
};

mvFloat mvWaypoint::getX() const
{
   if (points != NULL)
      return points[0].getX();
   else
      return 0;
};

mvFloat mvWaypoint::getY() const
{
   if (points != NULL)
      return points[0].getY();
   else
      return 0;
}

mvFloat mvWaypoint::getZ() const
{
   if (points != NULL)
      return points[0].getZ();
   else
      return 0;
};
