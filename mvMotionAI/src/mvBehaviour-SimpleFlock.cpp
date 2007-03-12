/**
 * \file mvBehaviour-SimpleFlock.cpp
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

#include "mvBehaviour-SimpleFlock.h"
#include "mvEnums.h"

enum mvBehaviour_SimpleFlock{
   MV_SIMPLE_FLOCK_TOTAL_POSITION = 0,
   MV_SIMPLE_FLOCK_TOTAL_VELOCITY = 1,
   //MV_NO_OF_SIMPLE_FLOCK_POINTS,
   MV_NO_OF_SIMPLE_FLOCK_BODY_VARIABLES,
   MV_SIMPLE_FLOCK_NO_OF_MEMBERS = 0,
   MV_SIMPLE_FLOCK_NO_OF_GROUP_VARIABLES
};

static const mvIndex MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX = 0;
static const mvIndex MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX = 1;
static const mvIndex MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX = 2;
static const mvIndex MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX = 0;
static const mvIndex MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX = 1;

void mvBehaviour_SimpleFlock_GroupOperations(mvWorldPtr worldPtr,
                                             mvGroupPtr flockGroup,
                                             mvBehaviourEntry* groupData)
{
   mvCount groupSize;
   mvIndex i;
   mvVec3 totalVelocity, totalPosition;
   mvBodyPtr tempBody = NULL;

   if (worldPtr != NULL && flockGroup != NULL && groupData != NULL)
   {
      /**
       * Step 1 - sum total velocity and total position
       */
      groupSize = flockGroup->getNoOfMembers();
      for (i = 1; i <= groupSize; i++)
      {
         tempBody = flockGroup->getMemberByIndex(i);
         if (tempBody != NULL)
         {
            totalVelocity += tempBody->direction * tempBody->speed;
            totalPosition += tempBody->position;
         }
      }
      /**
       * Step 2 - set totals to flock groupData
       */
      if (groupData->getType() == MV_GROUP_ENTRY)
      {
         groupData->extraPoints[MV_SIMPLE_FLOCK_TOTAL_POSITION] = totalPosition;
         groupData->extraPoints[MV_SIMPLE_FLOCK_TOTAL_VELOCITY] = totalVelocity;
         groupData->extraVariables[MV_SIMPLE_FLOCK_NO_OF_MEMBERS] = (mvFloat) groupSize;
         /**
         std::cout << "GROUP" << std::endl
                   << totalPosition << std::endl
                   << totalVelocity << std::endl
                   << groupSize << std::endl;
          **/
      }
   }
}


mvVec3 mvBehaviour_SimpleFlock_SingularOperation(mvBehaviourEntry* groupData, mvBodyPtr currentBody,
                                               mvBehaviourEntry* bodyData)
{
   mvVec3 finalVelocity, cohesion, alignment, separation,
        totalVelocity, totalPosition, flockCentre, averageVelocity;
   mvFloat cohesionFactor, alignmentFactor, separationFactor,
         noOfBodies, flockNumber;
   mvOptionEnum perceivedAttractionFlag, perceivedCohensionFlag;

   if (groupData != NULL && bodyData != NULL)
   {
      /*
       * Step Alpha init values
       *
      //puts("hello");
      bodyData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX] = MV_TRUE;
      bodyData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = MV_FALSE;
      */
      //bodyData->extraVariables[MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX] = 0.22f;
      //bodyData->extraVariables[MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX] = 0.05f;
      //bodyData->extraVariables[MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX] = 0.0f;
      /**/

      /*
       * Step 1 -  retrieve values from entries
       */
      noOfBodies = groupData->extraVariables[MV_SIMPLE_FLOCK_NO_OF_MEMBERS];
      totalVelocity = groupData->extraPoints[MV_SIMPLE_FLOCK_TOTAL_VELOCITY];
      totalPosition = groupData->extraPoints[MV_SIMPLE_FLOCK_TOTAL_POSITION];
      perceivedAttractionFlag = groupData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX];
      perceivedCohensionFlag = groupData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX];

      cohesionFactor = bodyData->extraVariables[MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX];
      separationFactor = bodyData->extraVariables[MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX];
      alignmentFactor = bodyData->extraVariables[MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX];

      /*
       * Step 2 - calculate separation
       * [Away from other bodies]
       */
      if (noOfBodies > 1)
      {
         separation = (noOfBodies * currentBody->position) - totalPosition;
         separation *= separationFactor/(separation.lengthSquared());
      }


      /*
       * Step 3 - calculate cohesion (attraction)
       * [Towards the centre of the flock]
       * on if perceived flock (MV_TRUE) or actual flock (MV_FALSE) i.e included
       * itself
       */
      flockNumber = noOfBodies;
      flockCentre = totalPosition;
      if (perceivedAttractionFlag == MV_TRUE)
      {
         flockCentre -= currentBody->position;
         flockNumber -= 1.0f;
      }
      /**/
      flockCentre *= 1.0f/flockNumber;
      /**/
      if (flockNumber > 0.0f)
      {
         cohesion = flockCentre - currentBody->position;
         cohesion *= cohesionFactor;
      }
      /*
      std::cout << "ATTRACTION :" << attraction << std::endl;
      */

      /*
       * Step 3 - calculate alignment (cohesion)
       * [How close is body's velocity to flock velocity]
       * on if perceived flock (MV_TRUE) or actual flock (MV_FALSE) i.e included
       * itself
       */
      /**/
      flockNumber = noOfBodies;
      averageVelocity = totalVelocity;
      /**/
      if (perceivedCohensionFlag == MV_TRUE)
      {
         averageVelocity -= currentBody->direction * currentBody->speed;
         flockNumber -= 1.0f;
      }
      /**/
      if (flockNumber > 0.0f)
      {
         alignment = averageVelocity / flockNumber;
         alignment *= alignmentFactor;
      }
      /**/

      /*
       * Step 4 - sum all values for final velocity accord to
       * behaviour
       */
      finalVelocity = cohesion + alignment + separation;
      //finalVelocity = separation;
      /*
      std::cout  << "SINGLE " << std::endl
                  << totalPosition << std::endl
                   << totalVelocity << std::endl
                   << noOfBodies << std::endl;
      */
   }
   return finalVelocity;
}
