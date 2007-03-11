/**
 * \file mvBehaviour-Type.cpp
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

#include "mvBehaviour-Type.h"
//#include <iostream>

mvCount mvBehaviour_GetIndexesArraySize(mvOptionEnum type)
{
   static const mvCount MV_BEHAVIOUR_SEEK_INDEX_SIZE = 1;
   static const mvCount MV_INVALID_BEHAVIOUR_INDEX_SIZE = 0;
   static const mvCount MV_BEHAVIOUR_CLONE_INDEX_SIZE = 1;
   static const mvCount MV_BEHAVIOUR_PURSUIT_INDEX_SIZE = 1;

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
}

mvErrorEnum mvBehaviour_InitialiseType(mvOptionEnum type, mvOptionEnum& bType, mvIndex* indexes,
                                  mvFloat* variables, mvOptionEnum* states, mvVec3* points)
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
      case MV_GROUP_ENTRY:
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
            states = new mvOptionEnum[statesSize];
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
         bType = MV_NON_BEHAVIOUR_TYPE;
         return MV_INVALID_BEHAVIOUR_INITIALIZATION;
   }

   /*
   if (indexes != NULL)
   {
      indexSize = mvBehaviour_GetIndexesArraySize(bType);

      for (i = 0; i < indexSize; i++)
      {
         indexes[i] = tempIndexArray[i];
      }
   }
   */
   return MV_NO_ERROR;
}

mvCount mvBehaviour_GetPointsArraySize(mvOptionEnum type)
{
   static const int MV_NO_OF_SIMPLE_FLOCK_POINTS = 0;
   static const int MV_NO_OF_SIMPLE_FLOCK_GROUP_POINTS = 2;

   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_POINTS;
      case MV_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_POINTS;
      default:
         return 0;
   }
}

mvCount mvBehaviour_GetVariablesArraySize(mvOptionEnum type)
{
   static const int MV_NO_OF_SIMPLE_FLOCK_GROUP_VARIABLES = 1;
   static const int MV_NO_OF_SIMPLE_FLOCK_VARIABLES = 3;

   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_VARIABLES;
      case MV_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_VARIABLES;
      default:
         return 0;
   }
}

mvCount mvBehaviour_GetStateArraySize(mvOptionEnum type)
{
   static const int MV_NO_OF_SIMPLE_FLOCK_GROUP_STATES = 2;
   static const int MV_NO_OF_SIMPLE_FLOCK_STATES = 0;

   switch(type)
   {
      case MV_SIMPLE_FLOCK:
         return MV_NO_OF_SIMPLE_FLOCK_STATES;
      case MV_GROUP_ENTRY:
         return MV_NO_OF_SIMPLE_FLOCK_GROUP_STATES;
      default:
         return 0;
   }
}

mvOptionEnum singleNodeArray[] =
{
  MV_SIMPLE_FLOCK,
};

mvOptionEnum groupNodeArray[] =
{
  MV_GROUP_ENTRY,
};

mvOptionEnum selectBodyToGroupEntryType(mvOptionEnum type)
{
   mvIndex i;
   static const mvCount size = sizeof(groupNodeArray)/sizeof(mvOptionEnum);

   for (i = 0; i < size; i++)
   {
      if (singleNodeArray[i] == type)
      {
         return groupNodeArray[i];
      }
   }
   return MV_NON_BEHAVIOUR_TYPE;
}

mvOptionEnum selectGroupToBodyEntryType(mvOptionEnum type)
{
   mvIndex i;
   static const mvCount size = sizeof(singleNodeArray)/sizeof(mvOptionEnum);

   for (i = 0; i < size; i++)
   {
      if (groupNodeArray[i] == type)
      {
         return singleNodeArray[i];
      }
   }
   return MV_NON_BEHAVIOUR_TYPE;
}

