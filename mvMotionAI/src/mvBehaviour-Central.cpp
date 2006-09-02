#include "mvBehaviour-Central.h"
#include "mvBehaviour-Seek.h"
#include "mvBehaviour-Flee.h"
#include "mvBehaviour-Clone.h"
#include "mvBehaviour-Pursuit.h"
#include "mvBehaviour-SimpleFlock.h"

#define MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG 1
#undef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG

//update global behaviours data
void mvProcessGroupBehaviours(mvWorld* worldPtr, mvGroupBehaviour* groupBehPtr, mvIndex behaviourIndex, mvFloat timeStep)
{
   mvIndex i,j;
   mvCount noOfGroups, noOfMembers;
   mvGroupBehaviourNode* currentGroupNode = NULL;
   mvBody* currentBody = NULL;
   mvGroup* currentGroup = NULL;
   mvIndex currentGroupIndex;
   mvBehaviourEntry* groupEntry = NULL;
   mvEnum behaviourType;

   if (worldPtr == NULL || groupBehPtr == NULL)
      return;   

   //puts("Default");
   noOfGroups = groupBehPtr->getNoOfGroups();

#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
   std::cout << "No of Groups : " << noOfGroups << std::endl;
#endif

   for (i = 1; i <= noOfGroups; i++)
   {
      /**
        * Step 1.0 registering bodies for each group
        */
      currentGroupNode = groupBehPtr->getGroupNodeByIndex(i);
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
      std::cout << "CGN Index : " << i << std::endl;
#endif
      if (currentGroupNode != NULL)
      {
         /**
          * Step 2.0 for each group in behaviour ...
          */
         currentGroupIndex = currentGroupNode->getGroup();
         currentGroup = worldPtr->mvGetGroup(currentGroupIndex);
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
        std::cout << "CG Index : " << currentGroupIndex << std::endl;
#endif
         if (currentGroup != NULL)
         {
            /**
             * Step 2.1 for each body in group ...
             */            
             noOfMembers = currentGroup->getNoOfMembers();
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
             std::cout << "No of Members : " << noOfMembers << std::endl;
#endif
             for (j = 1; j <= noOfMembers; j++)
             {
                /**
                 * Step 2.1a) for each body in group ...
                 */
                currentBody = currentGroup->getMemberByIndex(j);
                if (currentBody != NULL)
                {
                   if(currentBody->checkGroupBehaviourExists(behaviourIndex,currentGroupIndex) == MV_FALSE)
                   {
                   /**
                     * Step 2.1a) if empty, register body.
                     */
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                      puts("Created new behaviour");
#endif
                      currentBody->addExistingGroupBehaviourEntry(behaviourIndex,currentGroupIndex);                   
                   }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                   else
                   {
                   /**
                    * Step 2.1a) if full do nothing.
                    **/

                      puts("Not create stuff");
                      std::cout << " BI : " << behaviourIndex << std::endl
                             << " GI : " << currentGroupIndex << std::endl;
                   }
#endif
                }
                   /**
                else
                {
                   puts("HELLO 2");
                }
                **/
                //if (currentBody != NULL && 
                   
               /**/
             }

            /**
             * Step 3.0  apply group functions
             */
             groupEntry = currentGroupNode->getBehavData();
             if (groupEntry != NULL)
             {
                behaviourType = groupEntry->getType();
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                puts(mvGetEnumString(behaviourType));
#endif
                switch (behaviourType)
                {
                   case MV_SIMPLE_FLOCK_GROUP_ENTRY:
                      mvBehaviour_SimpleFlock_GroupOperations(worldPtr, currentGroup, groupEntry);
                      break;
                   default:
                      break;
                }
            }         
         }

      }
   }
};

void mvProcessBodyBehaviours(mvWorld* worldPtr, mvBody* currentBody, mvFloat timeStep,
                             mvVec3& mvDirVector, mvVec3& mvVelocityVector,
                             mvVec3& mvAccelVector,mvVec3& mvForceVector)
{
   mvBehaviourListNode* currentBNode = NULL;
   mvBehaviourEntry* groupEntry = NULL;
   mvBehaviourEntry* bodyEntry = NULL;
   mvEnum nodeType, behaviourType;
   mvBehaviour* globalBehaviour = NULL;
   mvGroupBehaviour* groupBehav = NULL;
   mvGroupBehaviourNode* groupBehavNode = NULL;
   mvGroup* currentGroup = NULL;
   mvIndex i;
   mvCount noOfBehaviours;
   mvIndex behaviourIndex, groupIndex, bodyIndex, waypointIndex;
   mvBody* bodyPtr = NULL;
   mvWaypoint* wayPointPtr = NULL;
   mvPathway* pathWayPtr = NULL;
   mvFloat nodeFactor; // multiplier with each behaviour
   mvFloat listFactorTotal;

   /**
    * Step 1.0 Continue only if != NULL
    */
   if (worldPtr != NULL && currentBody != NULL)
   {
      /**
       * Step 2.0 loop for all behaviours in body's list
       */
      listFactorTotal = currentBody->getListFactorTotal();
      noOfBehaviours = currentBody->getNoOfBehaviours();
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
      std::cout << "noOfBehaviours : " << noOfBehaviours << std::endl;
#endif
      for (i = 1; i <= noOfBehaviours; i++)
      {
         /**
          * Step 3.0 detrimine node type
          * - 4 types
          * MV_EXISTING_BEHAVIOUR
          * MV_EXISTING_GROUP_BEHAVIOUR
          * default
          *   - actual behaviour
          *   - non behaviour
          */
         currentBNode = currentBody->getEntryByIndex(i);
         if (currentBNode != NULL)
         {
            /**
             * Step 3.0a) get node type 
             */
            nodeType = currentBNode->getType();
            /**
             * Step 3.0b) select node type
             */
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
            puts(mvGetEnumString(nodeType));
#endif
            switch(nodeType)
            {
               case MV_EXISTING_GROUP_BEHAVIOUR:
                  groupIndex = currentBNode->getGroupIndex();
                  behaviourIndex = currentBNode->getBehaviourIndex();
                  
                  /**
                   * Step 3.1a) check if group exists
                   */   
                  /**
                  currentGroup = worldPtr->mvGetGroup(groupIndex);              
                  if (currentGroup == NULL)
                  {
                     behaviourType = MV_INVALID_BEHAVIOUR_TYPE;
                     break;
                  }
                  **/

                  /**
                   * Step 3.1b) check if group behaviour exists
                   */   

                  groupBehav = worldPtr->mvGetGroupBehaviour(behaviourIndex);
                  if (groupBehav == NULL)
                  {
                     behaviourType = MV_INVALID_BEHAVIOUR_TYPE;
                     break;
                  }

                  /**
                   * Step 3.1c) check if group exists 
                   * in group behaviour
                   */ 
                  //groupBehavNode = groupBehav->findGroupNodeByPtr(currentGroup);
                  groupBehavNode = groupBehav->findGroupNodeByIndex(groupIndex);
                  if (groupBehavNode == NULL)
                  {
                     behaviourType = MV_INVALID_BEHAVIOUR_TYPE;
                     break;
                  }

                  /**
                   * Step 3.1d) retrieve group entry 
                   */
                  //
                  groupEntry = groupBehavNode->getBehavData();
                  if (groupEntry == NULL)
                  {
                     behaviourType = MV_INVALID_BEHAVIOUR_TYPE;
                     break;
                  }

                  /**
                   * Step 3.1e) check if node has entry initialised
                   */
    
                  bodyEntry = currentBNode->getBehavData();
                  if (bodyEntry != NULL)
                  {
                     behaviourType = bodyEntry->getType(); 
                    // puts("hello2");
                  }
                  else
                  {              
                     behaviourType = groupBehav->getType();
                     currentBNode->initialiseEntry(behaviourType);
                     //puts("hello");
                  }            
                  
                  nodeFactor = (currentBNode->getFactor()/listFactorTotal);
                  break;
               case MV_EXISTING_BEHAVIOUR:
                  behaviourIndex = currentBNode->getBehaviourIndex();
                  /**
                   * Step 3.2a) check if global behaviour exists
                   */

                  globalBehaviour = worldPtr->mvGetBehaviour(behaviourIndex);
                  if (globalBehaviour == NULL)
                  {
                     behaviourType = MV_INVALID_BEHAVIOUR_TYPE;
                     break;
                  }
                  behaviourType = globalBehaviour->getType();
                  bodyEntry = globalBehaviour->getData();
                  //waypointIndex = bodyEntry->addWaypoint(1);
                  //puts("Empty ");
                  nodeFactor = (currentBNode->getFactor()/listFactorTotal);
                  break;
               default:
                  behaviourType = nodeType;
                  bodyEntry = currentBNode->getBehavData();
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(bodyEntry->getType()));
#endif
                  nodeFactor = (currentBNode->getFactor()/listFactorTotal);
                  break;
            }

            switch(behaviourType)
            {
               case MV_SEEK:
                  waypointIndex = bodyEntry->getWaypoint();
                  wayPointPtr = worldPtr->mvGetWaypoint(waypointIndex);
                  if (wayPointPtr != NULL)
                  {
                     mvAccelVector += nodeFactor * mvBehaviour_Calculate_Seek(currentBody, wayPointPtr);
                     //puts("SSEELL");
                  }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;
               case MV_FLEE:
                  waypointIndex = bodyEntry->getWaypoint();
                  wayPointPtr = worldPtr->mvGetWaypoint(waypointIndex);
                  if (wayPointPtr != NULL)
                  {
                     mvAccelVector += nodeFactor * mvBehaviour_Calculate_Flee(currentBody, wayPointPtr);                  
                  }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;
               case MV_CLONE:
                  bodyIndex = bodyEntry->getBody();
                  bodyPtr = worldPtr->mvGetBody(bodyIndex);
                  if (bodyPtr != NULL)
                  {
                     mvVelocityVector = nodeFactor * mvBehaviour_Calculate_Clone(NULL,bodyPtr,0);
                  }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;
               case MV_PURSUIT:
                  bodyIndex = bodyEntry->getBody();
                  bodyPtr = worldPtr->mvGetBody(bodyIndex);
                  if (bodyPtr != NULL)
                  {
                     mvVelocityVector += nodeFactor * mvBehaviour_Calculate_Pursuit(currentBody,bodyPtr);
                  }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;
               case MV_SIMPLE_FLOCK:
                  //puts("Hello");
                  if (groupEntry != NULL && bodyEntry != NULL)
                  {
                     mvVelocityVector += nodeFactor * mvBehaviour_SimpleFlock_SingularOperation(groupEntry, currentBody,
                                               bodyEntry);
                  }
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;
               default:
#ifdef MV_BEHAVIOUR_CENTRAL_DEBUG_OUTPUT_FLAG
                  puts(mvGetEnumString(behaviourType));
#endif
                  break;

            }

         }
      }
   } 
};

   /**
   new behaviours
   **
   mvBehaviourEntry* tempEntry = NULL;
   mvIndex index;
   mvEnum bType;
   mvPathway* currentPathway = NULL;
   mvWaypoint* tempWaypoint = NULL;            
   mvBody* tempBody1 = NULL;
   mvBody* tempBody2 = NULL;
   **/

         /**          
   //std::cout << "No of Behaviours : " << noOfBehaviours << std::endl;
         if (bType == MV_SEEK)
         {
            index = tempEntry->currentBehaviour->getWaypoint();
            tempWaypoint = worldPtr->mvGetWaypoint(index);
            if (tempWaypoint != NULL)
            {
               mvAccelVector += mvBehaviour_Calculate_Seek(tempBody, tempWaypoint);
            }
         }
         else if (bType == MV_FLEE)
         {
            index = tempEntry->currentBehaviour->getWaypoint();
            tempWaypoint = worldPtr->mvGetWaypoint(index);
            if (tempWaypoint != NULL)
            {
               mvAccelVector += mvBehaviour_Calculate_Flee(tempBody, tempWaypoint);                  
            }
         }
         else if (bType == MV_CLONE)
         {
            index = tempEntry->currentBehaviour->getBody();
            tempBody1 = worldPtr->mvGetBody(index);
            if (tempBody1 != NULL)
            {
               mvVelocityVector = mvBehaviour_Calculate_Clone(NULL,tempBody1,0);
            }
         }
         else if (bType == MV_PURSUIT)
         {
            index = tempEntry->currentBehaviour->getBody();
            tempBody1 = worldPtr->mvGetBody(index);
            if (tempBody1 != NULL)
            {
               mvVelocityVector += mvBehaviour_Calculate_Pursuit(tempBody,tempBody1);
            }
         }
         **/
            /**
            case MV_SIMPLE_FLOCK:
               index = tempEntry
            }

         //puts(mvGetEnumString(bType));
         /**
         switch(bType)
         {
            case MV_SEEK:
               index = tempEntry->currentBehaviour->getWaypoint();
               tempWaypoint = worldPtr->mvGetWaypoint(index);
               if (tempWaypoint != NULL)
               {
                  mvAccelVector += mvBehaviour_Calculate_Seek(tempBody, tempWaypoint);
               }
               break;
            case MV_FLEE:
               index = tempEntry->currentBehaviour->getWaypoint();
               tempWaypoint = worldPtr->mvGetWaypoint(index);
               if (tempWaypoint != NULL)
               {
                  mvAccelVector += mvBehaviour_Calculate_Flee(tempBody, tempWaypoint);                  
               }
               break;
            case MV_CLONE:
               index = tempEntry->currentBehaviour->getBody();
               tempBody1 = worldPtr->mvGetBody(index);
               if (tempBody1 != NULL)
               {
                  mvVelocityVector = mvBehaviour_Calculate_Clone(NULL,tempBody1,0);
               }
               break;
            case MV_PURSUIT:
               index = tempEntry->currentBehaviour->getBody();
               tempBody1 = worldPtr->mvGetBody(index);
               if (tempBody1 != NULL)
               {
                  mvVelocityVector += mvBehaviour_Calculate_Pursuit(tempBody,tempBody1);
               }
               break;
            /**
            case MV_SIMPLE_FLOCK:
               index = tempEntry
            **/