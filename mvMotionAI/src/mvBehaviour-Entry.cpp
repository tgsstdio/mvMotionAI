/**
 * \file mvBehaviour-Entry.cpp
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

#include "mvBehaviour-Entry.h"
#include "mvBehaviour-Type.h"

/**/

static const mvIndex MV_BEHAVIOUR_CLONE_BODY_TARGET_INDEX = 0;
static const mvIndex MV_BEHAVIOUR_PURSUIT_BODY_TARGET_INDEX = 0;
static const mvIndex MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX = 0;
static const mvIndex MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX = 1;
static const mvIndex MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX = 2;
static const mvIndex MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX = 0;
static const mvIndex MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX = 1;
static const mvIndex MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX = 0;

void mvBehaviourEntry::initDefault()
{
   extraVariables = NULL;
   extraStates = NULL;
   extraPoints = NULL;
   indexes = NULL;
   bType = MV_NON_BEHAVIOUR_TYPE;
   //groupIndex = MV_INVALID_GROUP_INDEX;
   //behaviourIndex = MV_INVALID_BEHAVIOUR_INDEX;
}

mvBehaviourEntry::mvBehaviourEntry()
{
   initDefault();
}

mvBehaviourEntry::mvBehaviourEntry(mvOptionEnum type)
{
   initDefault();
   //mvBehaviour_InitialiseType(type,bType,indexes,extraVariables,extraStates,extraPoints);
   mvBehaviour_InitialiseType2(type);
}

/*
mvBehaviourEntry::mvBehaviourEntry(mvEnum type, mvIndex bIndex, mvIndex gIndex)
{
   initDefault();
   mvBehaviour_InitialiseType(type,bType,indexes,extraVariables,extraStates,extraPoints);
   **
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
*/

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
}
/*
mvIndex mvBehaviourEntry::getBehaviourIndex()
{
   return behaviourIndex;
};
*/
mvOptionEnum mvBehaviourEntry::getType() const
{
   return bType;
}
/*
mvIndex mvBehaviourEntry::getGroupIndex()
{
   return groupIndex;
};
*/

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBehaviourEntry::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   if (index == NULL)
      return MV_INDEX_VALUE_IS_INVALID;

   switch(paramFlag)
   {
      case MV_WAYPOINT:
         *index = getWaypoint();
         return MV_NO_ERROR;
      case MV_BODY:
         *index = getBody();
         return MV_NO_ERROR;
      case MV_PATHWAY:
         *index = getPathway();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

mvErrorEnum mvBehaviourEntry::setParameteri(mvParamEnum paramFlag, mvIndex option)
{
   switch(paramFlag)
   {
      case MV_WAYPOINT:
         return addWaypoint(option);
      case MV_BODY:
         return addBody(option);
      case MV_PATHWAY:
         return addPathway(option);
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

mvErrorEnum mvBehaviourEntry::getParameter(mvParamEnum paramFlag, mvOptionEnum* dest)
{
   bool isValid = false;

   if (dest == NULL)
      return MV_OPTION_ENUM_DEST_IS_NULL;

   switch(paramFlag)
   {
      case MV_TYPE:
         *dest = getType();
         return MV_NO_ERROR;
      case MV_PERCEIVED_COHESION_FLAG:
         if (bType == MV_GROUP_ENTRY)
         {
            *dest = extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX];
            isValid = true;
         }
         break;
      case MV_PERCEIVED_ALIGNMENT_FLAG:
         if (bType == MV_GROUP_ENTRY)
         {
            *dest = extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX];
            isValid = true;
         }
         break;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   return (isValid) ? MV_NO_ERROR : MV_INVALID_BEHAVIOUR_TYPE;
}

mvErrorEnum mvBehaviourEntry::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   bool isValid = false;

   switch(paramFlag)
   {
      case MV_PERCEIVED_COHESION_FLAG:
         if (bType == MV_GROUP_ENTRY)
         {
            extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX] = option;
            isValid = true;
         }
         break;
      case MV_PERCEIVED_ALIGNMENT_FLAG:
         if (bType == MV_GROUP_ENTRY)
         {
            extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = option;
            isValid = true;
         }
         break;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   return (isValid) ? MV_NO_ERROR : MV_INVALID_BEHAVIOUR_TYPE;
}

mvErrorEnum mvBehaviourEntry::getParameterf(mvParamEnum paramFlag, mvFloat* dest)
{
   bool isValid = false;

   if (dest == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_COHESION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            *dest = extraVariables[MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX];
            isValid = true;
         }
         break;
      case MV_SEPARATION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            *dest = extraVariables[MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX];
            isValid = true;
         }
         break;
      case MV_ALIGNMENT_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            *dest = extraVariables[MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX];
            isValid = true;
         }
         break;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   return (isValid) ? MV_NO_ERROR : MV_INVALID_BEHAVIOUR_TYPE;
}

mvErrorEnum mvBehaviourEntry::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   bool isValid = false;
   switch(paramFlag)
   {
      case MV_COHESION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX] = num;
            isValid = true;
         }
         break;
      case MV_SEPARATION_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX] = num;
            isValid = true;
         }
         break;
      case MV_ALIGNMENT_FACTOR:
         if (bType == MV_SIMPLE_FLOCK)
         {
            extraVariables[MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX] = num;
            isValid = true;
         }
         break;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
   return (isValid) ? MV_NO_ERROR : MV_INVALID_BEHAVIOUR_TYPE;
}

mvErrorEnum mvBehaviourEntry::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return setParameterf(paramFlag,numArray[0]);
}

mvErrorEnum mvBehaviourEntry::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* size)
{
   mvErrorEnum error;

   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (size == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   error = getParameterf(paramFlag,numArray);
   if (error == MV_NO_ERROR)
   {
      *size = 1;
   }
   else
   {
      *size = 0;
   }
   return error;
}

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
      mvBehaviour_CopyArrayContents<mvOptionEnum>(extraStates,rhs.extraStates,noOfElements);
   }

   return *this;
}

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
      mvBehaviour_CopyArrayContents<mvOptionEnum>(extraStates,rhs.extraStates,noOfElements);
   }
}


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
            return MV_NO_CURRENT_INDEX;
      }
   }
   else
   {
      return MV_NO_CURRENT_INDEX;
   }
}

mvErrorEnum mvBehaviourEntry::addBody(mvIndex bBody)
{

  if (indexes != NULL)
  {
     switch(bType)
     {
        case MV_CLONE:
           indexes[MV_BEHAVIOUR_CLONE_BODY_TARGET_INDEX] = bBody;
           return MV_NO_ERROR;
        case MV_PURSUIT:
        case MV_EVASION:
           indexes[MV_BEHAVIOUR_PURSUIT_BODY_TARGET_INDEX] = bBody;
           return MV_NO_ERROR;
        default:
           return MV_BODY_CANNOT_ADDED;
     }
  }
  else
     return MV_INVALID_BEHAVIOUR_TYPE;
}

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
        return MV_NO_CURRENT_INDEX;
   }
}

mvErrorEnum mvBehaviourEntry::addPathway(mvIndex bPathway)
{
   //bPaths = bPathway;
   return MV_PATHWAY_CANNOT_ADDED;
}

mvIndex mvBehaviourEntry::getPathway() const
{
   //bPaths = bPathway;
   return MV_NO_CURRENT_INDEX;
}

mvErrorEnum mvBehaviourEntry::addWaypoint(mvIndex bWaypoint)
{
   static const mvIndex MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX = 0;
   //bWaypoints = bWaypoint;
   switch(bType)
   {
      case MV_SEEK:
      case MV_FLEE:
         //  puts("Hello Add WP");
         if (indexes != NULL)
         {
            indexes[MV_BEHAVIOUR_SEEK_WAYPOINT_INDEX] = bWaypoint;
            return MV_NO_ERROR;
         }
         else
         {
            return MV_WAYPOINT_CANNOT_ADDED;
         }
      default:
         return MV_INVALID_BEHAVIOUR_TYPE;
  }
}
/**/

mvErrorEnum mvBehaviourEntry::mvBehaviour_InitialiseType2(mvOptionEnum type)
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
      case MV_GROUP_ENTRY:
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
            extraStates = new mvOptionEnum[statesSize];
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
         bType = MV_NON_BEHAVIOUR_TYPE;
         return MV_INVALID_BEHAVIOUR_TYPE;
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
