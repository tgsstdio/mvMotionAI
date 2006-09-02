#include "mvScript-Utilities.h"
#include "mvEnum.h"
#include "mvWorld.h"
#include "mvMotionAI.h"
#include "mvMotionAI-Types.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MV_SCRIPT_DEBUG_STDOUT 1
#undef MV_SCRIPT_DEBUG_STDOUT

//mvIndex iterativeSearch(const char* key, const char** array, mvCount noOfItems);
//mvIndex binarySearch(const char* key, char** array, mvCount noOfItems);

mvEnum checkIterativeArray(const char* key, const char** strArray, mvCount noOfStrings, mvEnum invalidOption,
                           const mvEnum* enumArray);

mvIndex iterativeEnumSearch(const char* key, const mvEnum* array, mvCount noOfItems)
{
   mvIndex i;
   const char* tempString = NULL;

   for (i = 0; i < noOfItems; i++)
   {
      tempString = mvGetEnumString(array[i]);

      if (tempString != NULL)
      {
#ifdef MV_SCRIPT_DEBUG_STDOUT
      std::cout << key << " <-> " << tempString << std::endl;
#endif
         if (strcmp(key,tempString) == 0)
         {
            return i;
         }
      }
   }
   return -1;
};

mvIndex binaryEnumSearch(const char* key, const mvEnum* array, mvCount noOfItems)
{
   mvIndex mid;
   mvIndex left = 0;
   mvIndex right = noOfItems - 1;
   mvIndex result = -1;
   int compare;
   mvIndex index;
   const char* tempString = NULL;

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << key << " <-> " << mvEnumString[array[0]] << std::endl;
#endif

   while (left <= right)
   {  
      mid = (right + left) / 2;
      index = mid;
      tempString = mvGetEnumString(array[index]);
#ifdef MV_SCRIPT_DEBUG_STDOUT
      std::cout << "INDEX : " << index << " LEFT : " << left << " RIGHT : " << right <<std::endl;
      std::cout << key << " <-> " << tempString << std::endl;
#endif
      if (tempString != NULL)
      {
         compare = strcmp(key,tempString);
         if (compare == 0)
            return index;
          else if (compare < 0)
          {         
             right = mid - 1;         
          }
          else
          {
             left = mid + 1; 
          }
      }
      else
      {  
         // drop out
         return -1;
      }
   }
   return -1;
};

mvEnum mvScript_checkEnumArrayIteratively(const char* key, const mvEnum* array, mvCount noOfEnums, mvEnum invalidOption) 
{
   mvCount index = iterativeEnumSearch(key,array,noOfEnums);

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << noOfEnums << std::endl;
#endif

   return (index == -1) ? invalidOption : array[index];
};

mvEnum mvScript_checkEnumArrayBinarySearch(const char* key, const mvEnum* array, mvCount noOfEnums, mvEnum invalidOption) 
{
   mvIndex index = binaryEnumSearch(key,array,noOfEnums);

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << noOfEnums << std::endl;
#endif
   return (index == -1) ? invalidOption : array[index];
};
/**
mvIndex binarySearch(const char* key, char** array, mvCount noOfItems)
{
   mvIndex mid = noOfItems / 2;
   mvIndex left = 0;
   mvIndex right = noOfItems - 1;
   mvIndex result = -1;
   int compare;
   mvIndex index;

   while (left < right)
   {
      index = mid;
      compare = strcmp(key,array[index]);
      if (compare == 0)
         return index;
      else if (compare < 0)
      {
         right = mid - 1;         
      }
      else
      {
         left = mid + 1; 
      }
   }
   return -1;
};
**/

/**
mvIndex iterativeSearch(const char* key, const char** array, mvCount noOfItems)
{
   mvIndex i;

   for (i = 0; i < noOfItems; i++)
   {
      if (strcmp(key,array[i]) == 0)
      {
         return i;
      }
   }
   return -1;
};
**/
/**
mvEnum checkIterativeArray(const char* key, const char** strArray, mvCount noOfStrings, mvEnum invalidOption, const mvEnum* enumArray)
{
   mvIndex index = iterativeSearch(key,strArray,noOfStrings);

   return (index == -1) ? invalidOption : enumArray[index];
};
**/
/**
static const char* mvScript_ObstacleTypeStringEnums[] = {
   mvEnumString[MV_AABOX],
   mvEnumString[MV_SPHERE],
   mvEnumString[MV_X_AXIS_AA_CYLINDER],
   mvEnumString[MV_Y_AXIS_AA_CYLINDER],
   mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
**/

static const mvEnum mvScript_ObstacleTypeEnums[] =
{
  MV_AABOX,
  MV_SPHERE,
  MV_X_AXIS_AA_CYLINDER,
  MV_Y_AXIS_AA_CYLINDER,
  MV_Z_AXIS_AA_CYLINDER,
};
static const mvCount MVSCRIPT_NO_OF_OBSTACLE_TYPES = sizeof(mvScript_ObstacleTypeEnums)/sizeof(mvEnum);

/**
static const char* mvScript_ObstacleStateStringEnums[] = {
   mvEnumString[MV_AIR_OBSTACLE],
   mvEnumString[MV_LIQUID_OBSTACLE],
   mvEnumString[MV_SOLID_OBSTACLE],
};
**/

static const mvEnum mvScript_ObstacleStateEnums[] =
{
   MV_AIR_OBSTACLE,
   MV_LIQUID_OBSTACLE,
   MV_SOLID_OBSTACLE,  
};

static const mvCount MVSCRIPT_NO_OF_OBSTACLE_STATES = sizeof(mvScript_ObstacleStateEnums)/sizeof(mvEnum);


mvEnum mvScript_checkObstacleType(const char* shape)
{
  /**
  return checkIterativeArray(shape, mvScript_ObstacleTypeStringEnums, MVSCRIPT_NO_OF_OBSTACLE_TYPES,
     MV_NO_SHAPE,  mvScript_ObstacleTypeEnums);
  **/
  return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_ObstacleTypeEnums[0], MVSCRIPT_NO_OF_OBSTACLE_TYPES, MV_NO_SHAPE);
};

mvEnum mvScript_checkObstacleState(const char* state)
{
  /**
  int index = iterativeSearch(state,mvScript_ObstacleStateStringEnums,MVSCRIPT_NO_OF_OBSTACLE_STATES);

#ifdef MV_SCRIPT_DEBUG_STDOUT
  std::cout << "mv script size s= " << MVSCRIPT_NO_OF_OBSTACLE_STATES << std::endl;  
#endif

  if (index == -1)
  {
     return MV_NO_SHAPE;
  }
  else
  {

#ifdef MV_SCRIPT_DEBUG_STDOUT
     puts(mvScript_ObstacleStateStringEnums[index]);
#endif

     return mvScript_ObstacleStateEnums[index];
  }
  **/
  return mvScript_checkEnumArrayBinarySearch(state, &mvScript_ObstacleStateEnums[0],
     MVSCRIPT_NO_OF_OBSTACLE_STATES, MV_INVALID_OBSTACLE_STATE);
};

mvEnum mvScript_checkObstacleParamsFlag(const char* params);
mvEnum mvScript_checkObstacleParamsv(const char* params);
mvEnum mvScript_checkObstacleParamsFlagOptions(const char* option);

// waypoints 
/**
static const char* mvScript_WaypointTypeEnumStrings[] = 
{
   mvEnumString[MV_GROUP_WAYPOINT],
   mvEnumString[MV_SINGLE_WAYPOINT],
};
**/

static const mvEnum mvScript_WaypointTypeEnums[] =
{
MV_GROUP_WAYPOINT,
MV_SINGLE_WAYPOINT,
};

static const mvCount MVSCRIPT_NO_OF_WAYPOINT_TYPES = sizeof(mvScript_WaypointTypeEnums)/sizeof(mvEnum);

/**
static const char* mvScript_WaypointShapeEnumStrings[] = 
{
   mvEnumString[MV_AABOX],
   mvEnumString[MV_SPHERE],
   mvEnumString[MV_X_AXIS_AA_CYLINDER],
   mvEnumString[MV_Y_AXIS_AA_CYLINDER],
   mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
**/

static const mvEnum mvScript_WaypointShapeEnums[] =
{
MV_AABOX,
MV_SPHERE,
MV_X_AXIS_AA_CYLINDER,
MV_Y_AXIS_AA_CYLINDER,
MV_Z_AXIS_AA_CYLINDER,
};

static const mvCount MVSCRIPT_NO_OF_WAYPOINT_SHAPES = sizeof(mvScript_WaypointShapeEnums)/sizeof(mvEnum);

mvEnum mvScript_checkWaypointType(const char* type)
{
   /**
   int index = iterativeSearch(type, mvScript_WaypointTypeEnumStrings, MVSCRIPT_NO_OF_WAYPOINT_TYPES);   

#ifdef MV_SCRIPT_DEBUG_STDOUT
   std::cout << "mv script size = " << MVSCRIPT_NO_OF_WAYPOINT_TYPES << std::endl;
#endif

   if (index == -1)
   {
      return MV_INVALID_WAYPOINT_TYPE;
   }
   else
   {
      return mvScript_WaypointTypeEnums[index];
   }
   **/
   return  mvScript_checkEnumArrayBinarySearch(type, &mvScript_WaypointTypeEnums[0],
      MVSCRIPT_NO_OF_WAYPOINT_TYPES, MV_INVALID_WAYPOINT_TYPE);
};

mvEnum mvScript_checkWaypointShape(const char* shape)
{
   /**
   int index = iterativeSearch(shape, mvScript_WaypointShapeEnumStrings, MVSCRIPT_NO_OF_WAYPOINT_SHAPES);   
   //std::cout << "mv script size = " << MVSCRIPT_NO_OF_WAYPOINT_SHAPES << std::endl;
   if (index == -1)
   {
      return MV_INVALID_SHAPE_TYPE;
   }
   else
   {
      return mvScript_WaypointShapeEnums[index];
   }
   **/
   return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_WaypointShapeEnums[0],
      MVSCRIPT_NO_OF_WAYPOINT_SHAPES, MV_INVALID_SHAPE_TYPE); 

};

// body script functions

static const mvEnum mvScript_BodyTypeEnums[] =
{
MV_DUAL_TYPE,
MV_PARTICLE,
MV_VEHICLE,
};
/**
static const char* mvScript_BodyTypeEnumStrings[] =
{
mvEnumString[MV_DUAL_TYPE],
mvEnumString[MV_PARTICLE],
mvEnumString[MV_VEHICLE],
};
**/

static const mvCount MVSCRIPT_NO_OF_BODY_TYPES = sizeof(mvScript_BodyTypeEnums)/sizeof(mvEnum); //3;

mvEnum mvScript_checkBodyType(const char* type)
{
   /**
   int index = iterativeSearch(type,mvScript_BodyTypeEnumStrings,MVSCRIPT_NO_OF_BODY_TYPES);

   if (index == -1)
   {
      return MV_INVALID_BODY_TYPE;
   }
   else
   {
      return mvScript_BodyTypeEnums[index];
   }
   **
   return checkIterativeArray(type,mvScript_BodyTypeEnumStrings,MVSCRIPT_NO_OF_BODY_TYPES,
      MV_INVALID_BODY_TYPE,mvScript_BodyTypeEnums);
   **/

   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_BodyTypeEnums[0],
      MVSCRIPT_NO_OF_BODY_TYPES, MV_INVALID_BODY_TYPE); 
};

static const mvEnum mvScript_BodyShapeEnums[] =
{
MV_AABOX,
MV_SPHERE,
MV_X_AXIS_AA_CYLINDER,
MV_Y_AXIS_AA_CYLINDER,
MV_Z_AXIS_AA_CYLINDER,
};

/**
static const char* mvScript_BodyShapeEnumStrings[] =
{
mvEnumString[MV_AABOX],
mvEnumString[MV_SPHERE],
mvEnumString[MV_X_AXIS_AA_CYLINDER],
mvEnumString[MV_Y_AXIS_AA_CYLINDER],
mvEnumString[MV_Z_AXIS_AA_CYLINDER],
};
**/

static const mvCount MVSCRIPT_NO_OF_BODY_SHAPES = sizeof(mvScript_BodyShapeEnums)/sizeof(mvEnum);

mvEnum mvScript_checkBodyShape(const char* shape)
{
   /**
   int index = iterativeSearch(shape,mvScript_BodyShapeEnumStrings,MVSCRIPT_NO_OF_BODY_SHAPES);

   if (index == -1)
   {
      return MV_NO_SHAPE;
   }
   else
   {
      return mvScript_BodyShapeEnums[index];
   }
   **
   return checkIterativeArray(shape,mvScript_BodyShapeEnumStrings,
      MVSCRIPT_NO_OF_BODY_SHAPES,MV_NO_SHAPE,mvScript_BodyShapeEnums);
   **/
   return mvScript_checkEnumArrayBinarySearch(shape, &mvScript_BodyShapeEnums[0], MVSCRIPT_NO_OF_BODY_SHAPES, MV_NO_SHAPE);
};

static const mvEnum mvScript_ForceTypeEnums[] =
{
MV_DIRECTION_FORCE_TO_POINT,
MV_DIRECTION_SHIFT_TO_POINT,
MV_DRAG_ACCELERATION,
MV_DRAG_FORCE,
MV_DRAG_SHIFT,
MV_FORCE_FIELD_ATTRACT,
MV_FORCE_FIELD_FLUSH,
MV_FORCE_FIELD_REPELL,
MV_GRAVITY,
MV_GRAVITY_TO_POINT,
MV_NULL_ACCELERATION,
MV_NULL_ALL,
MV_NULL_DRAG,
MV_NULL_FIELD,
MV_NULL_FORCE,
MV_NULL_GRAVITY,
MV_NULL_SHIFT,
MV_UNIFORM_ACCELERATION,
MV_UNIFORM_FORCE,
MV_UNIFORM_SHIFT,
};
/**
static const char* mvScript_ForceTypeEnumStrings[] =
{
mvEnumString[MV_DIRECTION_FORCE_TO_POINT],
mvEnumString[MV_DIRECTION_SHIFT_TO_POINT],
mvEnumString[MV_DRAG_ACCELERATION],
mvEnumString[MV_DRAG_FORCE],
mvEnumString[MV_DRAG_SHIFT],
mvEnumString[MV_FORCE_FIELD_ATTRACT],
mvEnumString[MV_FORCE_FIELD_FLUSH],
mvEnumString[MV_FORCE_FIELD_REPELL],
mvEnumString[MV_GRAVITY],
mvEnumString[MV_GRAVITY_TO_POINT],
mvEnumString[MV_NULL_ACCELERATION],
mvEnumString[MV_NULL_ALL],
mvEnumString[MV_NULL_DRAG],
mvEnumString[MV_NULL_FIELD],
mvEnumString[MV_NULL_FORCE],
mvEnumString[MV_NULL_GRAVITY],
mvEnumString[MV_NULL_SHIFT],
mvEnumString[MV_UNIFORM_ACCELERATION],
mvEnumString[MV_UNIFORM_FORCE],
mvEnumString[MV_UNIFORM_SHIFT],
};
**/
static const mvCount MVSCRIPT_NO_OF_FORCE_TYPES = sizeof(mvScript_ForceTypeEnums)/sizeof(mvEnum);

mvEnum mvScript_checkForceType(const char* type)
{
   /**
   int index = iterativeSearch(type,mvScript_ForceTypeEnumStrings,MVSCRIPT_NO_OF_FORCE_TYPES);

   if (index == -1)
   {
      return MV_INVALID_FORCE_TYPE;
   }
   else
   {
      return mvScript_ForceTypeEnums[index];
   }
   **
   return checkIterativeArray(type,mvScript_ForceTypeEnumStrings,MVSCRIPT_NO_OF_FORCE_TYPES,
      MV_INVALID_FORCE_TYPE,mvScript_ForceTypeEnums);
   **/
   return mvScript_checkEnumArrayBinarySearch(type,&mvScript_ForceTypeEnums[0], MVSCRIPT_NO_OF_FORCE_TYPES, MV_INVALID_FORCE_TYPE);
};

static const mvEnum mvScript_ForceParamsvEnums[] =
{
MV_ACCELERATION,
MV_ACCELERATION_VECTOR,
MV_DIRECTION,
MV_FORCE_QUANTITY,
MV_FORCE_VECTOR,
MV_GRAVITIONAL_MASS,
MV_GRAVITY_CONSTANT,
MV_POSITION,
MV_SPEED,
MV_VELOCITY,
};
/**
static const char* mvScript_ForceParamsvEnumStrings[] =
{
mvEnumString[MV_ACCELERATION],
mvEnumString[MV_ACCELERATION_VECTOR],
mvEnumString[MV_DIRECTION],
mvEnumString[MV_FORCE_QUANTITY],
mvEnumString[MV_FORCE_VECTOR],
mvEnumString[MV_GRAVITIONAL_MASS],
mvEnumString[MV_GRAVITY_CONSTANT],
mvEnumString[MV_POSITION],
mvEnumString[MV_SPEED],
mvEnumString[MV_VELOCITY],
};
**/

static const mvCount MVSCRIPT_NO_OF_FORCE_PARAMSV = sizeof(mvScript_ForceParamsvEnums)/sizeof(mvEnum);

mvEnum mvScript_checkForceParamsv(const char* params)
{
   /**
   int index = iterativeSearch(type,mvScript_ForceParamsvEnumStrings,MVSCRIPT_NO_OF_FORCE_PARAMSV);

   if (index == -1)
   {
      return MV_INVALID_FORCE_TYPE;
   }
   else
   {
      return mvScript_ForceParamsvEnums[index];
   }
   **
   return checkIterativeArray(params,mvScript_ForceParamsvEnumStrings,MVSCRIPT_NO_OF_FORCE_PARAMSV,
       MV_INVALID_FORCE_PARAMETER,mvScript_ForceParamsvEnums);
   **/
   return mvScript_checkEnumArrayBinarySearch(params, &mvScript_ForceParamsvEnums[0],
      MVSCRIPT_NO_OF_FORCE_PARAMSV, MV_INVALID_FORCE_PARAMETER);
};

static const mvEnum mvScript_ForceParamsFlagEnums[] =
{
MV_ENABLE_FORCE,
MV_FORCE_TYPE,
};

/**
static const char* mvScript_ForceParamsFlagEnumStrings[] =
{
mvEnumString[MV_ENABLE_FORCE],
mvEnumString[MV_FORCE_TYPE],
};
**/

static const mvCount MVSCRIPT_NO_OF_FORCE_FLAGPARAMS = sizeof(mvScript_ForceParamsFlagEnums)/sizeof(mvEnum);

mvEnum mvScript_checkForceParamsFlag(const char* params)
{
   /**
  return checkIterativeArray(params, mvScript_ForceParamsFlagEnumStrings, MVSCRIPT_NO_OF_FORCE_FLAGPARAMS,
            MV_INVALID_FORCE_PARAMETER, mvScript_ForceParamsFlagEnums);
   **/
   return mvScript_checkEnumArrayBinarySearch(params, &mvScript_ForceParamsFlagEnums[0],
      MVSCRIPT_NO_OF_FORCE_FLAGPARAMS, MV_INVALID_FORCE_PARAMETER);
};


static const mvEnum mvScript_ForceFlagParamsOptionsEnums[] =
{
MV_DIRECTION_FORCE_TO_POINT,
MV_DIRECTION_SHIFT_TO_POINT,
MV_DRAG_ACCELERATION,
MV_DRAG_FORCE,
MV_DRAG_SHIFT,
MV_FORCE_FIELD_ATTRACT,
MV_FORCE_FIELD_FLUSH,
MV_FORCE_FIELD_REPELL,
MV_FORCE_OFF,
MV_FORCE_ON,
MV_GRAVITY,
MV_GRAVITY_TO_POINT,
MV_NULL_ACCELERATION,
MV_NULL_ALL,
MV_NULL_DRAG,
MV_NULL_FIELD,
MV_NULL_FORCE,
MV_NULL_GRAVITY,
MV_NULL_SHIFT,
MV_UNIFORM_ACCELERATION,
MV_UNIFORM_FORCE,
MV_UNIFORM_SHIFT,
};
/**
static const char* mvScript_ForceFlagParamsOptionsStrings[] =
{
mvEnumString[MV_DIRECTION_FORCE_TO_POINT],
mvEnumString[MV_DIRECTION_SHIFT_TO_POINT],
mvEnumString[MV_DRAG_ACCELERATION],
mvEnumString[MV_DRAG_FORCE],
mvEnumString[MV_DRAG_SHIFT],
mvEnumString[MV_FORCE_FIELD_ATTRACT],
mvEnumString[MV_FORCE_FIELD_FLUSH],
mvEnumString[MV_FORCE_FIELD_REPELL],
mvEnumString[MV_FORCE_OFF],
mvEnumString[MV_FORCE_ON],
mvEnumString[MV_GRAVITY],
mvEnumString[MV_GRAVITY_TO_POINT],
mvEnumString[MV_NULL_ACCELERATION],
mvEnumString[MV_NULL_ALL],
mvEnumString[MV_NULL_DRAG],
mvEnumString[MV_NULL_FIELD],
mvEnumString[MV_NULL_FORCE],
mvEnumString[MV_NULL_GRAVITY],
mvEnumString[MV_NULL_SHIFT],
mvEnumString[MV_UNIFORM_ACCELERATION],
mvEnumString[MV_UNIFORM_FORCE],
mvEnumString[MV_UNIFORM_SHIFT],
};
**/

static const mvCount MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS = sizeof(mvScript_ForceFlagParamsOptionsEnums)/sizeof(mvEnum);

mvEnum mvScript_checkForceParamsFlagOptions(const char* option)
{
/**
  return checkIterativeArray(option,mvScript_ForceFlagParamsOptionsStrings,MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS,
         MV_INVALID_FORCE_OPTION,mvScript_ForceFlagParamsOptionsEnums);
  **/
  return mvScript_checkEnumArrayBinarySearch(option,mvScript_ForceFlagParamsOptionsEnums,
     MVSCRIPT_NO_OF_FORCE_FLAGPARAMOPTIONS,MV_INVALID_FORCE_OPTION);
};

static const mvEnum mvScript_BehaviourTypes[] =
{
MV_CLONE,
MV_EVASION,
MV_FLEE,
MV_FOLLOW_PATH,
MV_PURSUIT,
MV_SEEK,
MV_SPIN,
MV_WANDER,
};

static const mvCount MVSCRIPT_NO_OF_BEHAVIOUR_TYPES = sizeof(mvScript_BehaviourTypes)/sizeof(mvEnum);

mvEnum mvScript_checkBehaviourType(const char* type)
{
   //return mvScript_checkEnumArrayIteratively(type, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);

   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
};

static const mvEnum mvScript_AddBehaviourParams[] =
{
MV_EXISTING_BEHAVIOUR,
MV_EXISTING_GROUP_BEHAVIOUR,
};

static const mvCount MVSCRIPT_NO_OF_ADD_BEHAVIOUR_PARAMS = sizeof(mvScript_AddBehaviourParams)/sizeof(mvEnum);

mvEnum mvScript_checkAddBehaviourParams(const char* params)
{
   mvEnum paramsCheck = mvScript_checkEnumArrayBinarySearch(params, &mvScript_AddBehaviourParams[0],MVSCRIPT_NO_OF_ADD_BEHAVIOUR_PARAMS,MV_FALSE);
   if (paramsCheck == MV_FALSE)
   {
      paramsCheck = mvScript_checkEnumArrayBinarySearch(params, &mvScript_BehaviourTypes[0],MVSCRIPT_NO_OF_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
   }
   return paramsCheck;
};

const mvEnum mvScript_GroupBehaviourTypes[] =
{
MV_SIMPLE_FLOCK,
};

const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_TYPES = sizeof(mvScript_GroupBehaviourTypes)/sizeof(mvEnum);

mvEnum mvScript_checkGroupBehaviourType(const char* type)
{
   return mvScript_checkEnumArrayBinarySearch(type, &mvScript_GroupBehaviourTypes[0],
                                     MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_TYPES,MV_INVALID_BEHAVIOUR_TYPE);
};

const mvEnum mvScript_BehaviourParamsIndex[] =
{
MV_BEHAVIOUR_BODY_TARGET,
MV_BEHAVIOUR_PATHWAY_TARGET,
MV_BEHAVIOUR_WAYPOINT_TARGET,
};

const mvCount MVSCRIPT_NO_OF_BEHAVIOUR_PARAMS_INDEXES = sizeof(mvScript_BehaviourParamsIndex)/sizeof(mvEnum);


mvEnum mvScript_checkBehaviourParamsIndex(const char* params)
{
    return mvScript_checkEnumArrayBinarySearch(params,&mvScript_BehaviourParamsIndex[0],
       MVSCRIPT_NO_OF_BEHAVIOUR_PARAMS_INDEXES,MV_INVALID_BEHAVIOUR_PARAMETER);
};

mvEnum mvScript_checkBehaviourParamsFlag(const char* params)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
};

mvEnum mvScript_checkBehaviourParamsv(const char* params)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
};

mvEnum mvScript_checkBehaviourParamsFlagOptions(const char* option)
{
   return MV_INVALID_BEHAVIOUR_PARAM_OPTION;
};


const mvEnum mvScript_GroupBehaviourParamsFlagsEnums[] =
{
MV_PERCEIVED_ALIGNMENT_FLAG,
MV_PERCEIVED_COHESION_FLAG,
};

const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAGS = sizeof(mvScript_GroupBehaviourParamsFlagsEnums)/sizeof(mvEnum);

mvEnum mvScript_checkGroupBehaviourParamsFlag(const char* params)
{
   return mvScript_checkEnumArrayBinarySearch(params,&mvScript_GroupBehaviourParamsFlagsEnums[0],
      MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAGS,MV_INVALID_BEHAVIOUR_PARAMETER);
};

const mvEnum mvScript_GroupBehaviourParamsvEnums[] =
{
MV_ALIGNMENT_FACTOR,
MV_COHESION_FACTOR,
MV_SEPARATION_FACTOR,
};

const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMSV = sizeof(mvScript_GroupBehaviourParamsvEnums)/sizeof(mvEnum);

mvEnum mvScript_checkGroupBehaviourParamsv(const char* params)
{
    return mvScript_checkEnumArrayBinarySearch(params,&mvScript_GroupBehaviourParamsvEnums[0],
          MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMSV,MV_INVALID_BEHAVIOUR_PARAMETER);
};

const mvEnum mvScript_GroupBehaviourParamsFlagOptions[] =
{
MV_TRUE,
MV_FALSE,
};

const mvCount MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAG_OPTIONS = sizeof(mvScript_GroupBehaviourParamsFlagOptions)/sizeof(mvEnum);

mvEnum mvScript_checkGroupBehaviourParamsFlagOptions(const char* option)
{
   return mvScript_checkEnumArrayBinarySearch(option,&mvScript_GroupBehaviourParamsFlagOptions[0],
      MVSCRIPT_NO_OF_GROUP_BEHAVIOUR_PARAMS_FLAG_OPTIONS,MV_INVALID_BEHAVIOUR_PARAM_OPTION);
};

mvEnum mvScript_checkGroupBehaviourParamsIndex(const char* params)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
};
