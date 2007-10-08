/**
 * \brief tutorial1 : adding mvMotionAI library to an console application
 *  via the C function interface
 *
 */

 // step 1 : include the main library header file
 #include <mv/mvMotionAI.h>

// for outputting info
 #include <iostream>

// step 2: create various function for loop based functions

// mvIndex - c interface index type
void displayAllBodyByIndexes(mvIndex worldIndex, mvIndex index, void *extraPtr);

// c pointer type
void displayAllObstaclesByPtr(mvObstaclePtr currentObstacle, void* extraPtr);

int main(void)
{
   // step 3 : initialise library
   mvInitMotionAI();

   // step 4 : create world instance
   mvIndex ourWorld = mvCreateWorld();

   // step 5 : create multiple bodies
   for (int i = 0; i < 5; i++)
   {
      mvCreateBody(ourWorld, MV_PARTICLE, MV_AABOX, i, i * 2, i * 3);
      mvCreateObstacle(ourWorld, MV_AABOX, MV_LIQUID_OBSTACLE, i * 5, i, i * -2);
   }

   const char* obstacleHeader = "OBSTACLE : ";
   const char* bodyHeader = "BODY ";

   // loop over bodies in the ourWorld instance
   mvApplyToAllBodiesByIndex(ourWorld, displayAllBodyByIndexes,
      (void*) bodyHeader);

   // loop over all obstacles in the ourWorld instance
   mvApplyToAllObstacles(ourWorld, displayAllObstaclesByPtr,\
      (void*) obstacleHeader);

   // step 6 : free motion library - automatically at close.
   mvFreeMotionAI();

   return 0;
}

// this function is for iterating over all bodies using the C function interface
void displayAllBodyByIndexes(mvIndex worldIndex, mvIndex index, void *extraPtr)
{
   mvCount noOfParameters;
   mvFloat positionArray[MV_MAX_NO_OF_PARAMETERS];

   if (mvGetBodyParameterv(worldIndex, index, MV_POSITION, &positionArray[0],
      &noOfParameters) == MV_NO_ERROR)
   {
      std::cout << (const char*) extraPtr << " world index : " << worldIndex
         << " body index : " <<  index << std::endl;

      std::cout << "Pos ";
      for (int j = 0; j < noOfParameters; j++)
      {
         std::cout << positionArray[j] << ", ";
      }

      std::cout << std::endl;
   }
}

// this functions is used to interact with the actual object pointer
void displayAllObstaclesByPtr(mvObstaclePtr currentObstacle, void* extraPtr)
{
   mvVec3 position = currentObstacle->getPosition();

   std::cout << (const char*) extraPtr
      << " Pos : " << position.getX()
      << ", " << position.getY()
      << ", " << position.getZ() << std::endl;
}
