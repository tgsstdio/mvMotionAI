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
mvEnum mvObstacle::initialiseShapeDimensions(mvEnum shape)
{
  mvFloat tempDims[MV_MAX_NO_OF_OBSTACLE_DIMENSIONS];
  mvIndex i;
  mvCount noOfDims;

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

  if (shape == MV_AABOX)
  {
     obstacleType = MV_AABOX;
     dimensions = new mvFloat[MV_NO_OF_AABOX_DIMENSIONS];
  }
  else if (shape == MV_SPHERE)
  {
     obstacleType = MV_SPHERE;
     dimensions = new mvFloat[MV_NO_OF_SPHERE_DIMENSIONS];
  }
  else if (shape == MV_X_AXIS_AA_CYLINDER)
  {
     obstacleType = MV_X_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Y_AXIS_AA_CYLINDER)
  {
     obstacleType = MV_Y_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else if (shape == MV_Z_AXIS_AA_CYLINDER)
  {
     obstacleType = MV_Z_AXIS_AA_CYLINDER;
     dimensions = new mvFloat[MV_NO_OF_AACYLINDER_DIMENSIONS];
  }
  else
  {
    obstacleType = MV_NO_SHAPE;
    dimensions = NULL;
  }

  if (obstacleType == MV_NO_SHAPE)
  {
    return MV_FALSE;
  }
  else
  {
    noOfDims = getNoOfDimensions();
    for (i = 0; i < noOfDims; ++i)
    {
      dimensions[i] = tempDims[i];
    }
    return MV_TRUE;
  }
};

mvEnum mvObstacle::getState() const
{
  return state;
};

mvEnum mvObstacle::checkValidState(mvEnum oState)
{
   switch(oState)
   {
     case MV_SOLID_OBSTACLE:
     case MV_LIQUID_OBSTACLE:
     case MV_AIR_OBSTACLE:
       state = oState;
       break;
     default:
       state = MV_INVALID_OBSTACLE_STATE;
   }
   return (state != MV_INVALID_OBSTACLE_STATE) ? MV_TRUE : MV_FALSE;
};
/**
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
**/
mvObstacle::mvObstacle(mvEnum oType, mvEnum oState)
{
  dimensions = NULL;
  obstacleType = MV_NO_SHAPE;
  initialiseShapeDimensions(oType);
  checkValidState(oState);
};

mvObstacle::mvObstacle(mvEnum oType, mvEnum oState,mvFloat x, mvFloat y, mvFloat z)
{
  dimensions = NULL;
  position.set(x,y,z);
  obstacleType = MV_NO_SHAPE;
  initialiseShapeDimensions(oType);
  checkValidState(oState);
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
mvEnum mvObstacle::setParameter(mvEnum paramFlag, mvEnum option)
{
   switch (paramFlag)
   {
     case MV_OBSTACLE_TYPE:
        if (initialiseShapeDimensions(option) == MV_FALSE)
        {
          return MV_INVALID_OBSTACLE_TYPE;
        }
        else
        {
          return MV_TRUE;
        }
     case MV_OBSTACLE_STATE:
        if (checkValidState(option) == MV_FALSE)
        {
          return MV_INVALID_OBSTACLE_STATE;
        }
        else
        {
          return MV_TRUE;
        }
     default:
       return MV_INVALID_OBSTACLE_PARAMETER;
   }
};

void mvObstacle::setPosition(mvFloat x, mvFloat y, mvFloat z)
{
  position.set(x,y,z);
};

mvEnum mvObstacle::setParameterf(mvEnum paramFlag, mvFloat num)
{
  return MV_FALSE;
};

mvEnum mvObstacle::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
  return MV_FALSE;
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

mvEnum mvObstacle::getType() const
{
  return obstacleType;
};
