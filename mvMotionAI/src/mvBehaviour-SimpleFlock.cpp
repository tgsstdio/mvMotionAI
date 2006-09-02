#include "mvBehaviour-SimpleFlock.h"
#include "mvEnum.h"

enum mvBehaviour_SimpleFlock{
   MV_SIMPLE_FLOCK_TOTAL_POSITION = 0,
   MV_SIMPLE_FLOCK_TOTAL_VELOCITY = 1,
   //MV_NO_OF_SIMPLE_FLOCK_POINTS,
   MV_NO_OF_SIMPLE_FLOCK_BODY_VARIABLES,
   MV_SIMPLE_FLOCK_NO_OF_MEMBERS = 0,
   MV_SIMPLE_FLOCK_NO_OF_GROUP_VARIABLES,
};

void mvBehaviour_SimpleFlock_GroupOperations(mvWorld* worldPtr,
                                             mvGroup* flockGroup,
                                             mvBehaviourEntry* groupData)
{
   mvCount groupSize;
   mvIndex i;
   mvVec3 totalVelocity, totalPosition;
   mvBody* tempBody = NULL;

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
      if (groupData->getType() == MV_SIMPLE_FLOCK_GROUP_ENTRY)
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
};


mvVec3 mvBehaviour_SimpleFlock_SingularOperation(mvBehaviourEntry* groupData, mvBody* currentBody,
                                               mvBehaviourEntry* bodyData)
{
   mvVec3 finalVelocity, cohesion, alignment, separation,
        totalVelocity, totalPosition, flockCentre, averageVelocity;
   mvFloat cohesionFactor, alignmentFactor, separationFactor,
         noOfBodies, flockNumber;
   mvEnum perceivedAttractionFlag, perceivedCohensionFlag;

   if (groupData != NULL && bodyData != NULL)
   {
      /**
       * Step Alpha init values
       *
      //puts("hello");
      bodyData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_COHESION_FLAG_INDEX] = MV_TRUE;
      bodyData->extraStates[MV_SIMPLE_FLOCK_PERCEIVED_ALIGNMENT_FLAG_INDEX] = MV_FALSE;
      **/
      bodyData->extraVariables[MV_SIMPLE_FLOCK_COHESION_FACTOR_INDEX] = 0.22f;
      bodyData->extraVariables[MV_SIMPLE_FLOCK_SEPARATION_FACTOR_INDEX] = 0.05f;
      bodyData->extraVariables[MV_SIMPLE_FLOCK_ALIGNMENT_FACTOR_INDEX] = 0.0f;
      /**/

      /**
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
      
      /**
       * Step 2 - calculate separation
       * [Away from other bodies]
       */
      if (noOfBodies > 1)
      {
         separation = (noOfBodies * currentBody->position) - totalPosition; 
         separation *= separationFactor/(separation.lengthSquared());
      }
      

      /**
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
      /**
      std::cout << "ATTRACTION :" << attraction << std::endl;
      **/

      /**
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
        
      /**
       * Step 4 - sum all values for final velocity accord to
       * behaviour
       */
      finalVelocity = cohesion + alignment + separation;
      //finalVelocity = separation;
      /**
      std::cout  << "SINGLE " << std::endl
                  << totalPosition << std::endl
                   << totalVelocity << std::endl
                   << noOfBodies << std::endl;
      **/
   }
   return finalVelocity;
};
