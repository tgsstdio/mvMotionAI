#include "mvBehaviour-Entry.h"
#include "mvBehaviour-Type.h"

/**/

void mvBehaviourEntry::initDefault()
{
   extraVariables = NULL;
   extraStates = NULL;
   extraPoints = NULL;
   indexes = NULL;
   bType = MV_INVALID_BEHAVIOUR_ENTRY_TYPE;
   //groupIndex = MV_INVALID_GROUP_INDEX;
   //behaviourIndex = MV_INVALID_BEHAVIOUR_INDEX;
};
/**/

mvBehaviourEntry::mvBehaviourEntry()
{
   initDefault();   
};

mvBehaviourEntry::mvBehaviourEntry(mvEnum type)
{
   initDefault();
   //mvBehaviour_InitialiseType(type,bType,indexes,extraVariables,extraStates,extraPoints);
   mvBehaviour_InitialiseType2(type);
};

/**
mvBehaviourEntry::mvBehaviourEntry(mvEnum type, mvIndex bIndex, mvIndex gIndex)
{
   initDefault();
   mvBehaviour_InitialiseType(type,bType,indexes,extraVariables,extraStates,extraPoints);
   /**
   if (mvBehaviour_InitialiseType(type,bType,indexes) == MV_FALSE)
   {
      switch(type)
      {
        case MV_EXISTING_GROUP_BEHAVIOUR:
           groupIndex = gIndex;
        case MV_EXISTING_BEHAVIOUR:
           behaviourIndex = bIndex;        
           bType = type;
        default:
           bType = MV_INVALID_BEHAVIOUR_ENTRY_TYPE;
           break;
      }
   }
   **
};
**/

mvBehaviourEntry::~mvBehaviourEntry()
{
  if (extraPoints != NULL)
  {
     delete [] extraPoints;
     extraPoints = NULL;
  }

  if (extraVariables != NULL)
  {
     delete [] extraVariables;
     extraVariables = NULL;
  }

  if (extraStates != NULL)
  {
     delete [] extraStates;
     extraStates = NULL;
  }

  if (indexes != NULL)
  {
     delete [] indexes;
     indexes = NULL;
  }
};
/**

mvIndex mvBehaviourEntry::getBehaviourIndex()
{
   return behaviourIndex;
};

**/
mvEnum mvBehaviourEntry::getType() const
{
   return bType;
};
/**
mvIndex mvBehaviourEntry::getGroupIndex()
{
   return groupIndex;
};
**/

mvEnum mvBehaviourEntry::getParameter(mvEnum paramFlag, mvEnum* dest) const
{
  return MV_FALSE;
};

mvEnum mvBehaviourEntry::getParameterf(mvEnum paramFlag, mvFloat* dest) const 
{
  return MV_FALSE;
};

mvEnum mvBehaviourEntry::getParameterv(mvEnum paramFlag, mvFloat* dest, mvCount* size) const
{
  return MV_FALSE;
};

mvEnum mvBehaviourEntry::setParameteri(mvEnum paramFlag, mvIndex option)
{
   switch(paramFlag)
   {
      case MV_BEHAVIOUR_WAYPOINT_TARGET:
         return addWaypoint(option);
      case MV_BEHAVIOUR_BODY_TARGET:
         return addBody(option);
      case MV_BEHAVIOUR_PATHWAY_TARGET:
         return addPathway(option);
      default:
         return MV_FALSE;
   }
};

mvEnum mvBehaviourEntry::setParameter(mvEnum paramFlag, mvEnum option)
{
   bool isValid = false;

   switch(paramFlag)
   {
      case MV_PERCEIVED_COHESION_FLAG:
         if (bType == MV_SIMPLE_FLOCK_GROUP_ENTRY)
         {
            extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX] = option;
            isValid = true;
         }
         break;
      case MV_PERCEIVED_ALIGNMENT_FLAG:
         if (bType == MV_SIMPLE_FLOCK_GROUP_ENTRY)
         {
            extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = option,
            isValid = true;
         }
         break;
      default:
         isValid = false;
   }
   return (isValid) ? MV_TRUE : MV_FALSE;
};

mvEnum mvBehaviourEntry::setParameterf(mvEnum paramFlag, mvFloat num)
{
   bool isValid = false;
   switch(paramFlag)
   {
      case MV_COHESION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX] = num;
            isValid = true;
         }
         break;
      case MV_SEPARATION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = num,
            isValid = true;
         }
         break;
      case MV_ALIGNMENT_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = num,
            isValid = true;
         }
         break;
      default:
         isValid = false;
   }
   return (isValid) ? MV_TRUE : MV_FALSE;
};

mvEnum mvBehaviourEntry::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
   if (numArray != NULL)
   {
      return setParameterf(paramFlag,numArray[0]);
   }
   else
   {
      return MV_FALSE;
   }
};

const mvBehaviourEntry& mvBehaviourEntry::operator=(const mvBehaviourEntry& rhs)
{
   mvCount noOfElements;
   
   mvBehaviour_InitialiseType(rhs.getType(),bType,this->indexes,
      this->extraVariables,this->extraStates,this->extraPoints);
   //mvBehaviour_InitialiseType(rhs.bType,bType,indexes);
   
   if (indexes != NULL)
   {
      noOfElements = mvBehaviour_GetIndexesArraySize(bType);
      mvBehaviour_CopyArrayContents<mvIndex>(indexes,rhs.indexes,noOfElements);
   }

   if (extraPoints != NULL)
   {
      noOfElements = mvBehaviour_GetPointsArraySize(bType);
      mvBehaviour_CopyArrayContents<mvVec3>(extraPoints,rhs.extraPoints,noOfElements);
   } 

   if (extraVariables != NULL)
   {
      noOfElements = mvBehaviour_GetVariablesArraySize(bType);
      mvBehaviour_CopyArrayContents<mvFloat>(extraVariables,rhs.extraVariables,noOfElements);
   }
   
   if (extraStates != NULL)
   {   
      noOfElements = mvBehaviour_GetStateArraySize(bType);
      mvBehaviour_CopyArrayContents<mvEnum>(extraStates,rhs.extraStates,noOfElements);
   }

   return *this;
};

mvBehaviourEntry::mvBehaviourEntry(const mvBehaviourEntry& rhs)
{
   mvCount noOfElements;
   
   mvBehaviour_InitialiseType(rhs.getType(),bType,this->indexes,
      this->extraVariables,this->extraStates,this->extraPoints);
   //mvBehaviour_InitialiseType(rhs.bType,bType,indexes);
   
   if (indexes != NULL)
   {
      noOfElements = mvBehaviour_GetIndexesArraySize(bType);
      mvBehaviour_CopyArrayContents<mvIndex>(indexes,rhs.indexes,noOfElements);
   }

   if (extraPoints != NULL)
   {
      noOfElements = mvBehaviour_GetPointsArraySize(bType);
      mvBehaviour_CopyArrayContents<mvVec3>(extraPoints,rhs.extraPoints,noOfElements);
   } 

   if (extraVariables != NULL)
   {
      noOfElements = mvBehaviour_GetVariablesArraySize(bType);
      mvBehaviour_CopyArrayContents<mvFloat>(extraVariables,rhs.extraVariables,noOfElements);
   }
   
   if (extraStates != NULL)
   {   
      noOfElements = mvBehaviour_GetStateArraySize(bType);
      mvBehaviour_CopyArrayContents<mvEnum>(extraStates,rhs.extraStates,noOfElements);
   }  
};

mvIndex mvBehaviourEntry::getBody() const
{
  if (indexes != NULL)
  {
     switch(bType)
     {
        case MV_CLONE:
           return indexes[MV_BEHAVIOUR_CLONE_BODY_TARGET_INDEX];        
        case MV_PURSUIT:
        case MV_EVASION:
           return indexes[MV_BEHAVIOUR_PURSUIT_BODY_TARGET_INDEX];  
        default:
           return MV_INVALID_BEHAVIOUR_INDEX_VALUE;
     }
  }
  else
  { 
     return MV_INVALID_BEHAVIOUR_INDEX_VALUE;
  }
};

mvEnum mvBehaviourEntry::addBody(mvIndex bBody)
{
  if (indexes != NULL)
  {
     switch(bType)
     {
        case MV_CLONE:
           indexes[MV_BEHAVIOUR_CLONE_BODY_TARGET_INDEX] = bBody;
           return MV_TRUE;
        case MV_PURSUIT:
        case MV_EVASION:
           indexes[MV_BEHAVIOUR_PURSUIT_BODY_TARGET_INDEX] = bBody;
           return MV_TRUE;
        default:
           return MV_FALSE;
     }
  }
  else
     return MV_FALSE; 
};

mvIndex mvBehaviourEntry::getWaypoint() const
{
   //return bWaypoints;
  switch(bType)
  {
     case MV_SEEK:
     case MV_FLEE:
        if (indexes != NULL)
        {
          // puts("Hello Get WP");
           return indexes[MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX];
        }
     default:
        return MV_INVALID_BEHAVIOUR_INDEX_VALUE;
  }
};

mvEnum mvBehaviourEntry::addPathway(mvIndex bPathway)
{
   //bPaths = bPathway;
   return MV_FALSE;
};

mvIndex mvBehaviourEntry::getPathway() const
{
   //bPaths = bPathway;
   return 0;
};

mvEnum mvBehaviourEntry::addWaypoint(mvIndex bWaypoint)
{
  //bWaypoints = bWaypoint;
  switch(bType)
  {
     case MV_SEEK:
     case MV_FLEE:
      //  puts("Hello Add WP");
     if (indexes != NULL)
     {
        indexes[MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX] = bWaypoint;
        return MV_TRUE;
     }
     default:
        return MV_FALSE;
  }
};
/**/

mvEnum mvBehaviourEntry::mvBehaviour_InitialiseType2(mvEnum type)
{
   mvCount indexSize = 0;
   mvCount statesSize = 0;
   mvCount pointsSize = 0;
   mvCount variablesSize = 0;
  // mvIndex i;

   /**/
   /**/

   switch(type)
   {
      case MV_SEEK:
      case MV_CLONE:
      case MV_FLEE:
      case MV_FOLLOW_PATH:
      case MV_PURSUIT:
      case MV_EVASION:
      case MV_SIMPLE_FLOCK:
      case MV_SIMPLE_FLOCK_GROUP_ENTRY:
         if (indexes != NULL)
         {
          delete [] indexes;
          indexes = NULL;
         }

         if (extraStates != NULL)
         {
           delete [] extraStates;
           extraStates = NULL;       
         }

         if (extraPoints != NULL)
         {
           delete [] extraPoints;
           extraPoints = NULL;
         }

         if (extraVariables != NULL)
         {
           delete [] extraVariables;
           extraVariables = NULL;
         }
         bType = type;
         indexSize = mvBehaviour_GetIndexesArraySize(bType);
         statesSize = mvBehaviour_GetStateArraySize(bType);
         pointsSize = mvBehaviour_GetPointsArraySize(bType);
         variablesSize = mvBehaviour_GetVariablesArraySize(bType);

         //std::cout << "Index Size = " << indexSize << std::endl;

         if (indexSize > 0)
         {
            indexes = new mvIndex[indexSize];
            //std::cout << "Index Size = " << sizeof(indexes)/sizeof(mvIndex) << std::endl;
         }

         if (statesSize > 0)
         {
            extraStates = new mvEnum[statesSize];
         }

         if (pointsSize > 0)
         {
            extraPoints = new mvVec3[pointsSize];
         }

         if (variablesSize > 0)
         {
            extraVariables = new mvFloat[variablesSize];
         }
         break;
      default:
         bType = MV_INVALID_BEHAVIOUR_TYPE;
         return MV_FALSE;
   }

   /**
   if (indexes != NULL)
   {
      indexSize = mvBehaviour_GetIndexesArraySize(bType);

      for (i = 0; i < indexSize; i++)
      {
         indexes[i] = tempIndexArray[i];
      }
   }
   **/
   return MV_TRUE;
};