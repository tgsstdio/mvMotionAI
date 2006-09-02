#include "mvBehaviour-Type.h"
#include <iostream>

mvCount mvBehaviour_GetIndexesArraySize(mvEnum type)
{
   switch(type)
   {
      case MV_SEEK:
      case MV_FLEE:
         return MV_BEHAVIOUR_SEEK_INDEX_SIZE;
      case MV_CLONE:
         return MV_BEHAVIOUR_CLONE_INDEX_SIZE;
      case MV_PURSUIT:
      case MV_EVASION:
         return MV_BEHAVIOUR_PURSUIT_INDEX_SIZE;
      default:
         return MV_INVALID_BEHAVIOUR_INDEX_SIZE;
   }
};

mvEnum mvBehaviour_InitialiseType(mvEnum type, mvEnum& bType, mvIndex* indexes,
                                  mvFloat* variables, mvEnum* states, mvVec3* points)
{
   mvCount indexSize = 0;
   mvCount statesSize = 0;
   mvCount pointsSize = 0;
   mvCount variablesSize = 0;
  // mvIndex i;

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

         if (states != NULL)
         {
           delete [] states;
           states = NULL;       
         }

         if (points != NULL)
         {
           delete [] points;
           points = NULL;
         }

         if (variables != NULL)
         {
           delete [] variables;
           variables = NULL;
         }
         bType = type;
         indexSize = mvBehaviour_GetIndexesArraySize(bType);
         statesSize = mvBehaviour_GetStateArraySize(bType);
         pointsSize = mvBehaviour_GetPointsArraySize(bType);
         variablesSize = mvBehaviour_GetVariablesArraySize(bType);

        // std::cout << "Index Size = " << indexSize << std::endl;

         if (indexSize > 0)
         {
            indexes = new mvIndex[indexSize];
            //std::cout << "Index Size = " << sizeof(indexes)/sizeof(mvIndex) << std::endl;
         }

         if (statesSize > 0)
         {
            states = new mvEnum[statesSize];
         }

         if (pointsSize > 0)
         {
            points = new mvVec3[pointsSize];
         }

         if (variablesSize > 0)
         {
            variables = new mvFloat[variablesSize];
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

mvCount mvBehaviour_GetPointsArraySize(mvEnum type)
{
   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_POINTS;
      case MV_SIMPLE_FLOCK_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_POINTS;
      default:
         return 0;
   }
};

mvCount mvBehaviour_GetVariablesArraySize(mvEnum type)
{
   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_VARIABLES;
      case MV_SIMPLE_FLOCK_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_VARIABLES;
      default:
         return 0;
   }
};

mvCount mvBehaviour_GetStateArraySize(mvEnum type)
{
   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_STATES;
      case MV_SIMPLE_FLOCK_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_STATES;
      default:
         return 0;
   }
};

mvEnum singleNodeArray[] =
{
  MV_SIMPLE_FLOCK,
};

mvEnum groupNodeArray[] = 
{
  MV_SIMPLE_FLOCK_GROUP_ENTRY,
};

const mvCount MV_NO_OF_GROUP_BEHAVIOUR_TYPES = sizeof(groupNodeArray)/sizeof(mvEnum);

mvEnum selectBodyToGroupEntryType(mvEnum type)
{
   mvIndex i;

   for (i = 0; i < MV_NO_OF_GROUP_BEHAVIOUR_TYPES; i++)
   {
      if (singleNodeArray[i] == type)
      {
         return groupNodeArray[i];
      }
   }
   return MV_INVALID_BEHAVIOUR_ENTRY_TYPE;
};

mvEnum selectGroupToBodyEntryType(mvEnum type)
{
   mvIndex i;

   for (i = 0; i < MV_NO_OF_GROUP_BEHAVIOUR_TYPES; i++)
   {
      if (groupNodeArray[i] == type)
      {
         return singleNodeArray[i];
      }
   }
   return MV_INVALID_BEHAVIOUR_ENTRY_TYPE;
};