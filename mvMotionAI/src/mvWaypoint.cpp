#include "mvWaypoint.h"

/**
 * initialises the points accordingly to the waypoint
 * type given.
 *
 * NOTE : completed for single, nurbs and group waypoints
 *
 */
mvEnum mvWaypoint::initialisePoints(mvEnum type)
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
   /**
   if (type == MV_NURB_WAYPOINT)
   {
      points = new mvVec3[MV_NO_OF_NURBS_POINTS];
      wayPointType = MV_NURB_WAYPOINT;
   }
   **/
   if (type == MV_SINGLE_WAYPOINT)
   {
      points = new mvVec3[MV_NO_OF_SINGLE_POINTS];
      wayPointType = MV_SINGLE_WAYPOINT;
   }
   else if (type == MV_GROUP_WAYPOINT)
   {
      points = new mvVec3[MV_NO_OF_SINGLE_POINTS];
      wayPointType = MV_GROUP_WAYPOINT;
   }   
   else
   {
      points = NULL;
      wayPointType = MV_INVALID_WAYPOINT_TYPE;
   }

   noOfPoints = getNoOfPoints();
   for (i = 0; i < noOfPoints; ++i)
   {
     points[i] = tempPoints[i];
   }
   if (wayPointType == MV_INVALID_WAYPOINT_TYPE)
   {
     return MV_FALSE;
   }
   else
   {
     return MV_TRUE;
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
mvEnum mvWaypoint::initialiseShapeDimensions(mvEnum shape)
{
  if (dimensions != NULL)
  {
    delete [] dimensions;
    dimensions = NULL;
  }

  if (shape == MV_AABOX)
  {
     wayPointShape = MV_AABOX;
     dimensions = new mvFloat[MV_NO_OF_AABOX_DIMENSIONS];
  }
  else if (shape == MV_SPHERE)
  {
     wayPointShape = MV_SPHERE;
     dimensions = new mvFloat[MV_NO_OF_SPHERE_DIMENSIONS];
  }
  else if (shape == MV_X_AXIS_AA_CYLINDER)
  {
     wayPointShape = MV_X_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Y_AXIS_AA_CYLINDER)
  {
     wayPointShape = MV_Y_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Z_AXIS_AA_CYLINDER)
  {
     wayPointShape = MV_Z_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else
  {
    wayPointShape = MV_NO_SHAPE;
    dimensions = NULL;
  }

  if (wayPointShape == MV_NO_SHAPE)
  {
    return MV_FALSE;
  }
  else
  {
    return MV_TRUE;
  }
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

mvWaypoint::mvWaypoint(mvEnum targetType, mvEnum targetShape)
{
  points = NULL;
  dimensions = NULL;
  //groupPtr = NULL;
  noOfForces = 0;
  initialisePoints(targetType);
  initialiseShapeDimensions(targetShape);
};

mvWaypoint::mvWaypoint(mvEnum targetType, mvEnum targetShape, mvFloat x, mvFloat y, mvFloat z)
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

mvEnum mvWaypoint::addForce(mvForce* forcePtr)
{
   std::vector<mvForce*>::iterator i;
   mvForce* tempForce = NULL;

   if (forcePtr == NULL)
      return MV_FALSE;

   for (i = forceList.begin(); i != forceList.end(); ++i)
   {
      tempForce = *i;
      if (tempForce != NULL)
      {
         if(tempForce == forcePtr)
            return MV_FALSE;
      }
   }
   forceList.push_back(forcePtr);
   forcePtr->incrementCount();
   ++noOfForces;
   return MV_TRUE;
};

mvEnum mvWaypoint::removeForce(mvForce* forcePtr)
{
   std::vector<mvForce*>::iterator i;
   mvForce* tempForce = NULL;

   if (forcePtr == NULL)
      return MV_FALSE;

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
           return MV_TRUE;
         }
      }
   }
   return MV_FALSE;
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
mvEnum mvWaypoint::getType()
{
  return wayPointType;
};
/**
 * returns current shape of waypoint
 */
mvEnum mvWaypoint::getShape()
{
  return wayPointShape;
};

/**
 * returns no of point for this waypoint
 */
mvCount mvWaypoint::getNoOfPoints() const
{
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
 * returns no of dimensions required for current 
 * waypoint shape
 */
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
mvEnum mvWaypoint::setParameter(mvEnum paramFlag, mvEnum option)
{
  if (paramFlag == MV_WAYPOINT_TYPE)
  {
     if (initialisePoints(option) == MV_FALSE)
     {
        return MV_INVALID_WAYPOINT_TYPE;
     }
     else
     {
        return MV_TRUE;
     }
  }
  else if (paramFlag == MV_WAYPOINT_SHAPE)
  {
     if (initialiseShapeDimensions(option) == MV_FALSE)
     {
        return MV_INVALID_SHAPE_TYPE;
     }
     else
     {
        return MV_TRUE;
     }
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
mvEnum mvWaypoint::setParameterf(mvEnum paramFlag, mvFloat num)
{
  switch (paramFlag)
  {
    case MV_RADIUS:
      if (wayPointShape == MV_SPHERE)
      {
         dimensions[MV_SPHERE_RADIUS_INDEX_NO] = num;
         return MV_TRUE;
      }
      else if (wayPointShape == MV_X_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_RADIUS_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else if (wayPointShape == MV_Y_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_RADIUS_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else if (wayPointShape == MV_Z_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_RADIUS_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else
      {
         return MV_INVALID_SHAPE_TYPE;
      }
    case MV_LENGTH:
    {
      if (wayPointShape == MV_X_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_LENGTH_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else if (wayPointShape == MV_Y_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_LENGTH_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else if (wayPointShape == MV_Z_AXIS_AA_CYLINDER)
      {
         dimensions[MV_AACYLINDER_LENGTH_INDEX_NO] = num;
         return MV_TRUE;   
      }
      else
      {
         return MV_INVALID_SHAPE_TYPE;
      }
    }
    default:
      return MV_INVALID_WAYPOINT_PARAMETER;
  }
};

mvEnum mvWaypoint::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
  return MV_FALSE;
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
