/**
 * \file mvWorld.cpp
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

#include "mvWorld.h"
#include <cstdlib>
#include <iostream>
#include "mvMotionAI-Utilities.h"
#include "mvBehaviour-Central.h"
//#include "Utilities.h"

#ifndef MV_WORLD_DEBUG_OUTPUT_FLAG
#define MV_WORLD_DEBUG_OUTPUT_FLAG 1
#undef MV_WORLD_DEBUG_OUTPUT_FLAG
#endif

void applyImprovEuler(mvFloat h,mvVec3* position, mvVec3* direction, mvFloat* currentSpeed,
                      mvFloat maxSpeed, mvFloat currentAcceleration);

void mvWorld::resetAllVariables()
{
   noOfWaypoints = 0;
   noOfBehaviours = 0;
   noOfBodies = 0;
   noOfPathways = 0;
   noOfObstacles = 0;
   noOfGroups = 0;
   noOfForces = 0;
   noOfGroupBehaviours = 0;
   currentGroupBehaviour = MV_NO_CURRENT_INDEX;
   currentForce = MV_NO_CURRENT_INDEX;
   currentPathway = MV_NO_CURRENT_INDEX;
   currentBody = MV_NO_CURRENT_INDEX;
   currentGroup = MV_NO_CURRENT_INDEX;
   currentBehaviour = MV_NO_CURRENT_INDEX;
   currentWaypoint = MV_NO_CURRENT_INDEX;
   currentObstacle = MV_NO_CURRENT_INDEX;

}


/**
 * \brief constructor
 */
mvWorld::mvWorld()
{
   idString = NULL;
   resetAllVariables();
}

/**
 * \brief constructor
 */
mvWorld::mvWorld(const char* worldID)
{
   mvCount strLen;
   //idString = NULL;

   /*
    c string copy
   */
   if (worldID != NULL)
   {
      strLen = strlen(worldID) + 1;
      idString = new char[strLen];
      strcpy(idString,worldID);
   }
   else
   {
      idString = NULL;
   }

   resetAllVariables();
}

/**
 *
 * \brief destructor
 */
mvWorld::~mvWorld()
{
  mvRemoveAllWaypoints();
  mvRemoveAllPathways();
  mvRemoveAllObstacles();
  mvRemoveAllBehaviours();
  mvRemoveAllGroups();
  mvRemoveAllBodies();
  mvRemoveAllGroupBehaviours();

  if (idString != NULL)
  {
     delete [] idString;
     idString = NULL;
  }
}

char* mvWorld::getWorldID() const
{
   return idString;
}

// really old integrator - obsolete
void applyImprovEuler(mvFloat h,mvVec3* position, mvVec3* direction, mvFloat* currentSpeed,
                      mvFloat maxSpeed, mvFloat currentAcceleration)
{
   mvFloat c1,c2;
   mvFloat pos[2][3];
   mvFloat vel[2][3];
   mvFloat speed[2];
   mvIndex j;

   /*
    * Step 3: initialise initial position
    */
   pos[0][0] = position->getX();
   pos[0][1] = position->getY();
   pos[0][2] = position->getZ();

   /*
    * Step 3 : set velocity direction (as in unit vector direction)
    */
   for (j = 0; j < 2; j++)
   {
      vel[j][0] = direction->getX();
      vel[j][1] = direction->getY();
      vel[j][2] = direction->getZ();
   }

   /*
    * Step 3: calculate the new speed using constant
    * acceleration
    */
   speed[0] = *currentSpeed;
   speed[1] = speed[0] + h * currentAcceleration;

   /*
    * 3a : clipping speed to max speed
    */
   speed[0] = (speed[0] < maxSpeed) ? speed[0] : maxSpeed;
   speed[1] = (speed[1] < maxSpeed) ? speed[1] : maxSpeed;

   /*
    * Step 4 : for each calculate new position
    * with improved euler.
    */
   for (j = 0; j < 3; j++)
   {
      /*
       * Step 4a: calculate the velocity
       * for all
       */
      vel[0][j] *= speed[0];
      vel[1][j] *= speed[1];

      /*
       * Step 4b: calculate the position
       */
      c1 = h * vel[0][j];
      c2 = h * vel[1][j];
      pos[1][j] = pos[0][j] + 0.5 * (c1 + c2);

   }

   /*
    * Step 5: set the final speed and
    * position
    */
   position->set(pos[1][0],pos[1][1],pos[1][2]);
   *currentSpeed = speed[1];
}

void mvWorld::mvWorldStep(mvFloat timeInSecs)
{
   /**/
   mvFloat c1,c2;
   mvFloat pos[2][3];
   mvFloat vel[2][3];
   /**/
   std::vector<mvBody*>::iterator i;
   std::vector<mvForce*>::iterator forceIterator;
   mvBody* tempBody = NULL;
   mvForce* currentForce = NULL;
   // linear motion variables
   mvFloat h,currentAcceleration, maxSpeed, extraVelocity;
   // force variables
   mvFloat globalDragForceQuantity, globalDragAccel, globalDragShift;
   mvVec3 globalUniformForce, globalUniformAccel, globalUniformShift,
      totalForce, totalAccel, totalVelocity, bodyDirection,
      bodyAccel, bodyVelocity, bodyForce;
   mvOptionEnum forceType, bodyState;
   mvVec3 tempVector;
   mvFloat parameters[MV_MAX_NO_OF_FORCE_VARIABLES];
   mvCount noOfParameters;
   //mvFloat totalMass;
   mvFloat speed[2], dir[3];
   mvIndex j, groupNo;


   /*
    * Step 1 : initialise all global force, gravity
    and shift and drag.
    */
    globalDragForceQuantity = 0.0f;
    globalDragAccel = 0.0f;
    globalDragShift = 0.0f;
    globalUniformForce.set(0.0f,0.0f,0.0f);
    globalUniformAccel.set(0.0f,0.0f,0.0f);
    globalUniformShift.set(0.0f,0.0f,0.0f);

   /*
    * Step 2 : iterates over all forces in
    * force array to build global force values
    */
    for (forceIterator = forces.begin(); forceIterator != forces.end(); ++forceIterator)
    {
       currentForce = *forceIterator;
       // 2.1 check if not null
       if (currentForce != NULL)
       {
           /*
            * 2.2 check if current force is global and
            *     enabled
            */
            if (currentForce->isGlobalForce() &&
                currentForce->getEnableFlag() == MV_TRUE)
            {
                forceType = currentForce->getType();

                switch (forceType)
                {

                   case MV_UNIFORM_FORCE:
                   ///
                   // 2.3a) add force to global force
                   ///
                      if (currentForce->getParameterv(MV_FORCE_VECTOR,parameters,&noOfParameters) == MV_NO_ERROR)
                      {
                         tempVector.set(parameters[0],parameters[1],parameters[2]);
                         globalUniformForce += tempVector;
                         //puts("hello 2");
                      }
                      break;
                   /**/
                   case MV_GRAVITY:
                   case MV_UNIFORM_ACCELERATION:
                   ///
                   // 2.3b) add acceleration to global accel
                   ///
                      //std::cout << "hello 2" << std::endl;

                      if (currentForce->getParameterv(MV_ACCELERATION_VECTOR,parameters,&noOfParameters) == MV_NO_ERROR)
                      {
                         tempVector.set(parameters[0],parameters[1],parameters[2]);
                         globalUniformAccel += tempVector;
                      }
                      break;
                   /**/
                   case MV_UNIFORM_SHIFT:
                   ///
                   // 2.3c) add acceleration to global velocity
                   ///
                      if (currentForce->getParameterv(MV_VELOCITY,parameters,&noOfParameters) == MV_NO_ERROR)
                      {
                         tempVector.set(parameters[0],parameters[1],parameters[2]);
                         globalUniformShift += tempVector;
                      }
                      break;
                   case MV_DRAG_FORCE:
                   ///
                   // 2.3d) adds drag force to global drag force quantity
                   ///
                      if (currentForce->getParameterf(MV_FORCE_QUANTITY,parameters) == MV_NO_ERROR)
                      {
                         globalDragForceQuantity += parameters[0];
                      }
                      break;
                   case MV_DRAG_ACCELERATION:
                   ///
                   // 2.3d) adds drag acceleration to global drag accel
                   ///
                      if (currentForce->getParameterf(MV_ACCELERATION,parameters) == MV_NO_ERROR)
                      {
                         globalDragForceQuantity += parameters[0];
                      }
                      break;
                   case MV_DRAG_SHIFT:
                   ///
                   // 2.3e) adds drag shift to total drag shift
                   ///
                      if (currentForce->getParameterf(MV_SPEED,parameters) == MV_NO_ERROR)
                      {
                         globalDragForceQuantity += parameters[0];
                      }
                      break;
                   case MV_NULL_ALL:
                   ///
                   // 2.3f) resets all (uniform + drag) force, shift and
                   // acceleration
                   ///
                       globalDragForceQuantity = 0.0f;
                       globalDragAccel = 0.0f;
                       globalDragShift = 0.0f;
                       globalUniformForce.set(0.0f,0.0f,0.0f);
                       globalUniformAccel.set(0.0f,0.0f,0.0f);
                       globalUniformShift.set(0.0f,0.0f,0.0f);
                       break;
                   case MV_NULL_FIELD:
                   ///
                   // 2.3g) resets all uniform (other than drag) force, shift and
                   // acceleration
                   ///
                       globalUniformForce.set(0.0f,0.0f,0.0f);
                       globalUniformAccel.set(0.0f,0.0f,0.0f);
                       globalUniformShift.set(0.0f,0.0f,0.0f);
                       break;
                   case MV_NULL_FORCE:
                   ///
                   // 2.3h) resets (global + drag) force to global drag force quantity
                   ///
                      globalDragForceQuantity = 0.0f;
                      globalUniformForce.set(0.0f,0.0f,0.0f);
                      break;
                   case MV_NULL_ACCELERATION:
                   ///
                   // 2.3i) resets (global + drag) acceleration to zero
                   ///
                      globalDragAccel = 0.0f;
                      globalUniformAccel.set(0.0f,0.0f,0.0f);
                      break;
                   case MV_NULL_SHIFT:
                   ///
                   // 2.3j) reset all shifts (global and drag) to zero
                   ///
                      globalDragShift = 0.0f;
                      globalUniformShift.set(0.0f,0.0f,0.0f);
                      break;
                   case MV_NULL_DRAG:
                   //
                   // 2.3k) reset all shifts (global and drag) to zero
                   //
                      globalDragForceQuantity = 0.0f;
                      globalDragAccel = 0.0f;
                      globalDragShift = 0.0f;
                      break;
                   case MV_NULL_GRAVITY:
                   //
                   // 2.3k) reset uniform acceleration (global uniform) to zero
                   //  point gravity  as well ???
                   //
                      globalUniformAccel.set(0.0f,0.0f,0.0f);
                   /**/
                   default:
                      //puts("hello 2");
                      break;
                   /**/
                }
                /**/

            }
       }
    }

   /*
    * Step 3 : initialises the time step (h)
    *
    */
   h = timeInSecs;

   /*
    * Step 4 : iterate & perform group functions
    */
   mvGroupBehaviour* currentGroupBeh = NULL;
   for (groupNo = 1; groupNo <= noOfGroupBehaviours; groupNo++)
   {
      currentGroupBeh = mvGetGroupBehaviour(groupNo);
      if (currentGroupBeh != NULL)
      {
         mvProcessGroupBehaviours(this, currentGroupBeh,
                              groupNo, h);
      }
   }



   /*
    * Step 5 : iterate over all vehicles
    */
   //puts("Step 5");
   for (i = bodies.begin(); i != bodies.end(); ++i)
   {
      tempBody = *i;
      if (tempBody != NULL)
      {

         bodyState = tempBody->getState();
         /*
          * 5.1.1 (a) straight line integration if unaffected by forces
          */
         if (bodyState == MV_APPLY_NO_FORCES_STATE)
         {
            maxSpeed = tempBody->maxSpeed;
            currentAcceleration = tempBody->acceleration;
// TODO : motion integration of MV_APPLY_NO_FORCES_STATE not correct
            applyImprovEuler(h,&(tempBody->position),&(tempBody->direction), &(tempBody->speed),
                      maxSpeed,currentAcceleration);
         }
         /*
          * 5.1.2 (b) apply forces to body straight line integration
          * eular
          */
         else if (bodyState != MV_NO_MOTION_STATE && bodyState != MV_NON_BODY_STATE)
         {
            maxSpeed = tempBody->maxSpeed;
            //tempVector = tempBody->direction;
            //tempVector *= tempBody->acceleration;
            totalForce = globalUniformForce;
            totalAccel = globalUniformAccel;
            totalVelocity = globalUniformShift;
            // body directions, forces, velocity, accel
            bodyForce.resetXYZ();
            bodyAccel.resetXYZ();
            bodyVelocity.resetXYZ();


            mvProcessBodyBehaviours(this, tempBody, h,
               bodyDirection, bodyVelocity,bodyAccel,bodyForce);

            /*
             * final integration
             */
            /*
             * force(mvForce) => accel (a = f/m)
             */
            totalAccel += ((1.0f/tempBody->mass) * totalForce);
            bodyAccel += ((1.0f/tempBody->mass) * bodyForce);
            /*
             * accel to velocity <> change in v =  a * h
             */
            totalVelocity += (h * totalAccel);
            bodyVelocity += (h * bodyAccel);


            /*
             * 5.1.2.1: initialise initial position
             */
            pos[0][0] = tempBody->getX();
            pos[0][1] = tempBody->getY();
            pos[0][2] = tempBody->getZ();

            /*
             * 5.1.2.2: set velocity direction to total velocity (as in unit vector direction)
             */
            //tempBody->finalVelocity.x;

            vel[0][0] = tempBody->finalVelocity.getX();
            vel[0][1] = tempBody->finalVelocity.getY();
            vel[0][2] = tempBody->finalVelocity.getZ();

            vel[1][0] = totalVelocity.getX() + tempBody->finalVelocity.getX();
            vel[1][1] = totalVelocity.getY() + tempBody->finalVelocity.getY();
            vel[1][2] = totalVelocity.getZ() + tempBody->finalVelocity.getZ();

            /*
             * 5.1.2.3 realign direction
             */
            tempBody->direction = bodyVelocity.normalize();

            dir[0] = tempBody->direction.getX();
            dir[1] = tempBody->direction.getY();
            dir[2] = tempBody->direction.getZ();

            /*
             * 5.1.2.3: calculate the new speed using constant
             * acceleration
             */
            speed[0] = tempBody->speed;
            speed[1] = bodyVelocity.length();

            /*
             * limits change in velocity by max velocity
             *change per frame
             */
            /**/
            if (speed[0] < speed[1])
            {
               extraVelocity = tempBody->acceleration * h;
#ifdef MV_WORLD_DEBUG_OUTPUT_FLAG
               std::cout << "Acceleration : " << tempBody->acceleration << std::endl
                         << "Extra velocity : " << extraVelocity << std::endl
                         << "Speed[0] : " << speed[0] << std::endl
                         << "Speed[1] : " << speed[1] << std::endl;
#endif
               if ((speed[1] - speed[0]) > extraVelocity)
               {
                  //puts("LIMIT");
                  speed[1] = speed[0] + extraVelocity;
               }
            }
            else
            {
               extraVelocity = tempBody->deceleration * h;
               if ((speed[0] - speed[1]) > extraVelocity)
               {
                 // puts("LIMIT 2");
                  speed[1] = speed[1] + extraVelocity;
               }
            }
            /**/

            //speed[1] *= (speed[1] < 0) ? -1.0f : 1.0f;

            /*
             * 5.1.2.4: clipping speed to max speed
             */
            speed[0] = (speed[0] < maxSpeed) ? speed[0] : maxSpeed;
            speed[1] = (speed[1] < maxSpeed) ? speed[1] : maxSpeed;

            /*
             * 5.1.2.6: for each calculate new position
             * with improved euler.
             */
            for (j = 0; j < 3; j++)
            {
               /*
                * 5.1.2.6.1 calculate the velocity
                * for all
                */
               vel[0][j] += dir[j] * speed[0];
               vel[1][j] += dir[j] * speed[1];
               //vel[0][j] *= speed[0];
               //vel[1][j] *= speed[1];

               /*
                * 5.1.2.6.2 calculate the position
                */
               c1 = h * vel[0][j];
               c2 = h * vel[1][j];
               pos[1][j] = pos[0][j] + 0.5 * (c1 + c2);

            }
            /*
             * 5.1.2.7: set new position
             * and new speed
             */
            tempBody->finalVelocity.set(vel[1][0],vel[1][1],vel[1][2]);
            tempBody->position.set(pos[1][0],pos[1][1],pos[1][2]);
            tempBody->speed = speed[1];
#ifdef MV_WORLD_DEBUG_OUTPUT_FLAG
            std::cout << "Final Velocity : " << tempBody->finalVelocity << std::endl
               << "Position : "  << tempBody->position << std::endl
               << "Speed : " << tempBody->speed << std::endl;
#endif
         }
      }
   }
}

/**
 * \brief moves a single body in the system forward by timeInSecs seconds
 *
 * NOTE : does not include forces in calculation
 */
mvErrorEnum mvWorld::mvNudgeBody(mvIndex bodyIndex, mvFloat timeInSecs)
{
   /**/
   mvFloat c1,c2;
   mvFloat pos[2][3];
   mvFloat vel[2][3];
   /**/
   mvFloat h, maxSpeed, extraVelocity;
   // force variables
//   mvFloat globalDragForceQuantity, globalDragAccel, globalDragShift;
   mvVec3 globalUniformForce, globalUniformAccel, globalUniformShift,
      totalForce, totalAccel, totalVelocity, bodyDirection,
      bodyAccel, bodyVelocity, bodyForce;
   mvOptionEnum bodyState;
   mvVec3 tempVector;
   //mvFloat totalMass;
   mvFloat speed[2], dir[3];
   mvIndex j;

   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody != NULL)
   {
      h = timeInSecs;
      bodyState = tempBody->getState();
      /*
       * 5.1.2 (b) apply forces to body straight line integration
       * eular
       */
      if (bodyState != MV_NO_MOTION_STATE && bodyState != MV_NON_BODY_STATE)
      {
         maxSpeed = tempBody->maxSpeed;
         // body directions, forces, velocity, accel
         bodyForce.resetXYZ();
         bodyAccel.resetXYZ();
         bodyVelocity.resetXYZ();


         mvProcessBodyBehaviours(this, tempBody, h,
            bodyDirection, bodyVelocity,bodyAccel,bodyForce);

         /*
          * final integration
          */
         /*
          * force(mvForce) => accel (a = f/m)
          */
         totalAccel += ((1.0f/tempBody->mass) * totalForce);
         bodyAccel += ((1.0f/tempBody->mass) * bodyForce);
         /*
          * accel to velocity <> change in v =  a * h
          */
         totalVelocity += (h * totalAccel);
         bodyVelocity += (h * bodyAccel);


         /*
          * 5.1.2.1: initialise initial position
          */
         pos[0][0] = tempBody->getX();
         pos[0][1] = tempBody->getY();
         pos[0][2] = tempBody->getZ();

         /*
          * 5.1.2.2: set velocity direction to total velocity (as in unit vector direction)
          */

         vel[0][0] = tempBody->finalVelocity.getX();
         vel[0][1] = tempBody->finalVelocity.getY();
         vel[0][2] = tempBody->finalVelocity.getZ();

         vel[1][0] = totalVelocity.getX() + tempBody->finalVelocity.getX();
         vel[1][1] = totalVelocity.getY() + tempBody->finalVelocity.getY();
         vel[1][2] = totalVelocity.getZ() + tempBody->finalVelocity.getZ();

         /*
          * 5.1.2.3 realign direction
          */
         tempBody->direction = bodyVelocity.normalize();

         dir[0] = tempBody->direction.getX();
         dir[1] = tempBody->direction.getY();
         dir[2] = tempBody->direction.getZ();

         /*
          * 5.1.2.3: calculate the new speed using constant
          * acceleration
          */
         speed[0] = tempBody->speed;
         speed[1] = bodyVelocity.length();

         /*
          * limits change in velocity by max velocity
          *change per frame
          */
         /**/
         if (speed[0] < speed[1])
         {
            extraVelocity = tempBody->acceleration * h;

            if ((speed[1] - speed[0]) > extraVelocity)
            {
               //puts("LIMIT");
               speed[1] = speed[0] + extraVelocity;
            }
         }
         else
         {
            extraVelocity = tempBody->deceleration * h;
            if ((speed[0] - speed[1]) > extraVelocity)
            {
              // puts("LIMIT 2");
               speed[1] = speed[1] + extraVelocity;
            }
         }


         /*
          * 5.1.2.4: clipping speed to max speed
          */
         speed[0] = (speed[0] < maxSpeed) ? speed[0] : maxSpeed;
         speed[1] = (speed[1] < maxSpeed) ? speed[1] : maxSpeed;

         /*
          * 5.1.2.6: for each calculate new position
          * with improved euler.
          */
         for (j = 0; j < 3; j++)
         {
            /*
             * 5.1.2.6.1 calculate the velocity
             * for all
             */
            vel[0][j] += dir[j] * speed[0];
            vel[1][j] += dir[j] * speed[1];
            //vel[0][j] *= speed[0];
            //vel[1][j] *= speed[1];

            /*
             * 5.1.2.6.2 calculate the position
             */
            c1 = h * vel[0][j];
            c2 = h * vel[1][j];
            pos[1][j] = pos[0][j] + 0.5 * (c1 + c2);

         }
         /*
          * 5.1.2.7: set new position
          * and new speed
          */
         tempBody->finalVelocity.set(vel[1][0],vel[1][1],vel[1][2]);
         tempBody->position.set(pos[1][0],pos[1][1],pos[1][2]);
         tempBody->speed = speed[1];
      }
      return MV_NO_ERROR;
   }
   else
   {
      return MV_BODY_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvNudgeCurrentBody(mvFloat timeInSecs)
{
   return mvNudgeBody(currentBody,timeInSecs);
}

void mvWorld::mvApplyToAllBodies(void (someFunction)(mvBody*,void*),void* extraPtr)
{
   /*
   std::vector<mvBody*>::iterator i;
   mvBody* tempBody = NULL;

   for (i = bodies.begin(); i != bodies.end(); ++i)
   {
      tempBody = *i;
      if (tempBody != NULL)
      {
         someFunction(tempBody);
      }
   }
   */
   mvApplyFunctionToAllItemsInListVector<mvBody>(bodies,someFunction,extraPtr);
}

void mvWorld::mvApplyToAllObstacles(void (someFunction)(mvObstacle*,void*),void* extraPtr)
{
   mvApplyFunctionToAllItemsInListVector<mvObstacle>(obstacles,someFunction,extraPtr);
}

void mvWorld::mvApplyToAllWaypoints(void (someFunction)(mvWaypoint*,void*),void* extraPtr)
{
   mvApplyFunctionToAllItemsInListVector<mvWaypoint>(waypoints,someFunction,extraPtr);
}

// start mv Body declearations

/**
 * adds bodies to
 */
mvIndex mvWorld::mvAddBody(mvOptionEnum bType, mvOptionEnum bShape)
{
   return mvAddBodyWithPos(bType, bShape, 0, 0, 0);
}

mvIndex mvWorld::mvAddBodyWithPos(mvOptionEnum bType, mvOptionEnum bShape, mvFloat x, mvFloat y, mvFloat z)
{
   mvBody* tempBody = NULL;

   // initialise body
   tempBody = new mvBody(bType,bShape,x,y,z);
   bodies.push_back(tempBody);
   ++noOfBodies;
   currentBody = noOfBodies;

   // add to main group
   //groups[0]->addMember(tempBody);

   return currentBody;
}

mvBody* mvWorld::mvGetBody(mvIndex index)
{
   return mvGetClassPtr<mvBody>(bodies,index, noOfBodies);
}

mvIndex mvWorld::mvSetCurrentBody(mvIndex index)
{
  return mvSetCurrentIndexOfClassList<mvBody>(bodies, index, currentBody, noOfBodies);
}

mvErrorEnum mvWorld::mvRemoveCurrentBody()
{
   //return removeCurrentItemFromList<mvBody>(bodies,currentBody,noOfBodies);
   return removeItemFromVectorByIndex<mvBody>(bodies, currentBody, currentBody, noOfBodies);
}

mvErrorEnum mvWorld::mvRemoveBody(mvIndex index)
{
  return removeItemFromVectorByIndex<mvBody>(bodies,index,currentBody,noOfBodies);
}

void mvWorld::mvRemoveAllBodies()
{
   mvRemoveAllClassObjectsFromList<mvBody>(bodies, currentBody, noOfBodies);
}

mvErrorEnum mvWorld::mvSetBodyParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvBody>(bodies,index, noOfBodies, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetBodyParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
  return mvSetClassParameterf<mvBody>(bodies, noOfBodies, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetBodyParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvBody>(bodies, noOfBodies,index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentBodyParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvBody>(bodies, currentBody, noOfBodies, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentBodyParameterf(mvParamEnum paramFlag, mvFloat num)
{
  return mvSetClassParameterf<mvBody>(bodies,noOfBodies, currentBody, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentBodyParameterv(mvParamEnum paramFlag, mvFloat* array)
{
  return mvSetClassParameterv<mvBody>(bodies, noOfBodies, currentBody, paramFlag, array);
}
// end body functions - start mv group functions

/**
 * takes mvGroupID as parameter but
 *
 * returns index number of new group created
 */
mvIndex mvWorld::mvAddGroup(char* mvGroupID)
{
   std::vector<mvGroup*>::iterator i;
   mvGroup* tempGroup = NULL;

   if (mvGroupID == NULL)
      return MV_FALSE;

   // iterate over all
   for (i = groups.begin(); i != groups.end(); ++i)
   {
      tempGroup = *i;
      if (tempGroup != NULL)
      {
         // check if name is not the same
         if (strcmp(tempGroup->getID(),mvGroupID) == 0)
         {
            return MV_FALSE;
         }
      }
   }

   // initialise group
   tempGroup = new mvGroup(mvGroupID);
   groups.push_back(tempGroup);
   ++noOfGroups;
   currentGroup = noOfGroups;
   return currentGroup;
}

mvGroup* mvWorld::mvGetGroup(mvIndex index)
{
   //std::cout << "Index : " << index << std::endl;
   return mvGetClassPtr<mvGroup>(groups, index, noOfGroups);
}

mvErrorEnum mvWorld::mvRemoveCurrentGroup()
{
   // return removeCurrentItemFromList<mvGroup>(groups, currentGroup, noOfGroups);
    return removeItemFromVectorByIndex<mvGroup>(groups, currentGroup, currentGroup, noOfGroups);
}

mvErrorEnum mvWorld::mvRemoveGroup(mvIndex index)
{
  /*
  mvGroup* tempGroup = NULL;
  mvIndex groupIndex = index + MV_OFFSET_TO_INDEX;

  if (groupIndex >= 0 && groupIndex < noOfGroups)
  {
    tempGroup = groups[groupIndex];
    if (tempGroup != NULL)
    {
       delete tempGroup;
       groups[groupIndex] = NULL;
    }
    if (groupIndex == currentGroup)
    {
       currentGroup = MV_NO_CURRENT_INDEX;
    }
    return MV_TRUE;
  }
  else
  {
     return MV_FALSE;
  }
  */
  return removeItemFromVectorByIndex<mvGroup>(groups, index, currentGroup, noOfGroups);
}

mvIndex mvWorld::mvSetCurrentGroup(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvGroup>(groups, index, currentGroup, noOfGroups);
}

/**
 *  \brief remove all additional groups in mvWorld
 */
void mvWorld::mvRemoveAllGroups()
{
   /*
   std::vector<mvGroup*>::iterator i = groups.begin();
   mvGroup* temp = NULL;

   ** ignores first group <=> ALL **
   for (++i ; i != groups.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         delete temp;
         *i= NULL;
      }
   }
   noOfGroups = 1;
   */
   //noOfGroupsSlots = 0;
   mvRemoveAllClassObjectsFromList<mvGroup>(groups, currentGroup, noOfGroups);
}

mvErrorEnum mvWorld::mvSetGroupParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvGroup>(groups, index, noOfGroups, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetGroupParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvGroup>(groups, noOfGroups, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetGroupParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvGroup>(groups, noOfGroups,index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentGroupParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvGroup>(groups, currentGroup,noOfObstacles, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentGroupParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvGroup>(groups,noOfGroups, currentGroup, paramFlag,num);
}

mvErrorEnum mvWorld::mvSetCurrentGroupParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvGroup>(groups, noOfGroups, currentGroup, paramFlag, array);
}

mvErrorEnum mvWorld::mvAddBodyToGroup(mvIndex bodyIndex, mvIndex groupIndex)
{
   mvGroup* currentGroup = NULL;
   mvBody* tempBody = NULL;

   tempBody = mvGetBody(bodyIndex);
   if (tempBody != NULL)
   {
      currentGroup = mvGetGroup(groupIndex);
     // puts("HELLO");
      if (currentGroup != NULL)
      {
#ifdef MV_WORLD_DEBUG_OUTPUT_FLAG
         std::cout << "No of Members : " << currentGroup->getNoOfMembers() << std::endl;
#endif
         return currentGroup->addMember(tempBody);
      }
      else
      {
         return MV_GROUP_INDEX_IS_INVALID;
      }
   }
   else
   {
      return MV_BODY_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvAddCurrentBodyToGroup(mvIndex groupIndex)
{
   return mvAddBodyToGroup(currentBody, groupIndex);
}

mvErrorEnum mvWorld::mvAddBodyToCurrentGroup(mvIndex bodyIndex)
{
   return mvAddBodyToGroup(bodyIndex, currentGroup);
}

mvErrorEnum mvWorld::mvAddCurrentBodyToCurrentGroup()
{
   return mvAddBodyToGroup(currentBody, currentGroup);
}

mvErrorEnum mvWorld::mvRemoveBodyFromGroup(mvIndex bodyIndex, mvIndex groupIndex)
{
   mvGroup* currentGroup = NULL;
   mvBody* tempBody = NULL;

   tempBody = mvGetBody(bodyIndex);
   if (tempBody != NULL)
   {
      currentGroup = mvGetGroup(groupIndex);
      if (currentGroup != NULL)
      {
         return currentGroup->removeMember(tempBody);
      }
      else
      {
         return MV_GROUP_INDEX_IS_INVALID;
      }
   }
   else
   {
      return MV_BODY_INDEX_IS_INVALID;
   }

}

mvErrorEnum mvWorld::mvRemoveCurrentBodyFromGroup(mvIndex groupIndex)
{
   return mvRemoveBodyFromGroup(currentBody, groupIndex);
}

mvErrorEnum mvWorld::mvRemoveBodyFromCurrentGroup(mvIndex bodyIndex)
{
   return mvRemoveBodyFromGroup(bodyIndex, currentGroup);
}

mvErrorEnum mvWorld::mvRemoveCurrentBodyFromCurrentGroup()
{
   return mvRemoveBodyFromGroup(currentBody, currentGroup);
}

mvGroup* mvWorld::mvGetGroupByID(char* groupID)
{
   std::vector<mvGroup*>::iterator i;
   mvGroup* tempGroup = NULL;

   if (groupID == NULL)
      return NULL;

   for (i = groups.begin(); i != groups.end(); ++i)
   {
      tempGroup = *i;
      if (tempGroup != NULL)
      {
         // check if name is the same
         if (strcmp(tempGroup->getID(),groupID) == 0)
         {
            return tempGroup;
         }
      }
   }
   return NULL;
}

mvIndex mvWorld::mvGetGroupIndexByID(char* groupID)
{
   std::vector<mvGroup*>::iterator i;
   mvCount count = 1;
   mvGroup* temp = NULL;
   char* tempID = NULL;

   if (groupID == NULL)
      return 0;

   for ( i = groups.begin(); i != groups.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         tempID = temp->getID();
         if (tempID != NULL && strcmp(tempID, groupID) == 0)
         {
            return count;
         }
      }
      ++count;
   }
   return 0;
}

// end group functions - start Obstacle functions

/**
 * takes mvGroupID as parameter but
 *
 * returns index number of new group created
 */

mvIndex mvWorld::mvAddObstacle(mvOptionEnum oType, mvOptionEnum oState)
{
   return mvAddObstacleWithPos(oType, oState, 0, 0, 0);
}

mvIndex mvWorld::mvAddObstacleWithPos(mvOptionEnum oType, mvOptionEnum oState,mvFloat x, mvFloat y, mvFloat z)
{
   // initialise obstacle
   mvObstacle* tempObstacle = new mvObstacle(oType,oState,x,y,z);
   obstacles.push_back(tempObstacle);
   ++noOfObstacles;
   currentObstacle = noOfObstacles;
   return currentObstacle;
}

mvObstacle* mvWorld::mvGetObstacle(mvIndex index)
{
   return  mvGetClassPtr<mvObstacle>(obstacles, index, noOfObstacles);
}

void mvWorld::mvRemoveAllObstacles()
{
   mvRemoveAllClassObjectsFromList<mvObstacle>(obstacles,currentObstacle,noOfObstacles);
}

mvErrorEnum mvWorld::mvRemoveCurrentObstacle()
{
   //return removeCurrentItemFromList<mvObstacle>(obstacles, currentObstacle, noOfObstacles);
   return removeItemFromVectorByIndex<mvObstacle>(obstacles, currentObstacle, currentObstacle, noOfObstacles);
}

mvErrorEnum mvWorld::mvRemoveObstacle(mvIndex index)
{
   return removeItemFromVectorByIndex<mvObstacle>(obstacles, index, currentObstacle, noOfObstacles);
}

mvIndex mvWorld::mvSetCurrentObstacle(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvObstacle>(obstacles, index, currentObstacle, noOfObstacles);
}

mvErrorEnum mvWorld::mvSetObstacleParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvObstacle>(obstacles, index, noOfObstacles, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetObstacleParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvObstacle>(obstacles, noOfObstacles, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetObstacleParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvObstacle>(obstacles, noOfObstacles,index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentObstacleParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvObstacle>(obstacles, currentObstacle, noOfObstacles, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentObstacleParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvObstacle>(obstacles, noOfObstacles, currentObstacle, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentObstacleParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvObstacle>(obstacles,noOfObstacles,currentObstacle,paramFlag,array);
}

// end obstacle functions -  start waypoint functions
mvIndex mvWorld::mvAddWaypoint(mvOptionEnum wType, mvOptionEnum wShape)
{
   return mvAddWaypointWithPos(wType,wShape, 0, 0, 0);
}

mvIndex mvWorld::mvAddWaypointWithPos(mvOptionEnum wType, mvOptionEnum wShape, mvFloat x, mvFloat y, mvFloat z)
{
  mvWaypoint* temp = new mvWaypoint(wType, wShape, x,y,z);
  waypoints.push_back(temp);
  ++noOfWaypoints;
  currentWaypoint = noOfWaypoints;
  return currentWaypoint;
}

mvWaypoint* mvWorld::mvGetWaypoint(mvIndex index)
{
   return mvGetClassPtr<mvWaypoint>(waypoints, index, noOfWaypoints);
}

mvErrorEnum mvWorld::mvRemoveWaypoint(mvIndex index)
{
  return removeItemFromVectorByIndex<mvWaypoint>(waypoints, index, currentWaypoint, noOfWaypoints);
}

mvErrorEnum mvWorld::mvRemoveCurrentWaypoint()
{
   return removeItemFromVectorByIndex<mvWaypoint>(waypoints, currentWaypoint, currentWaypoint, noOfWaypoints);
}

mvIndex mvWorld::mvSetCurrentWaypoint(mvIndex index)
{
  return mvSetCurrentIndexOfClassList<mvWaypoint>(waypoints, index, currentWaypoint, noOfWaypoints);
}

void mvWorld::mvRemoveAllWaypoints()
{
   mvRemoveAllClassObjectsFromList<mvWaypoint>(waypoints, currentWaypoint, noOfWaypoints);
}

mvErrorEnum mvWorld::mvSetWaypointParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvWaypoint>(waypoints, index, noOfWaypoints, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetWaypointParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvWaypoint>(waypoints, noOfWaypoints, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetWaypointParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvWaypoint>(waypoints, noOfWaypoints, index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentWaypointParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvWaypoint>(waypoints, currentWaypoint, noOfWaypoints, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentWaypointParameterf(mvParamEnum paramFlag, mvFloat num)
{
  return mvSetClassParameterf<mvWaypoint>(waypoints, noOfWaypoints, currentWaypoint, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentWaypointParameterv(mvParamEnum paramFlag, mvFloat* array)
{
  return mvSetClassParameterv<mvWaypoint>(waypoints, noOfWaypoints, currentWaypoint, paramFlag, array);
}

// end waypoint functions - start pathway functions
mvIndex mvWorld::mvBeginPathway()
{
   mvPathway* temp = new mvPathway();
   pathways.push_back(temp);
   ++noOfPathways;
   currentPathway = noOfPathways;
   return currentPathway;
}

mvPathway* mvWorld::mvGetPathway(mvIndex index)
{
   return mvGetClassPtr<mvPathway>(pathways,index, noOfPathways);
}

mvErrorEnum mvWorld::mvRemovePathway(mvIndex index)
{
   return removeItemFromVectorByIndex<mvPathway>(pathways, index, currentPathway, noOfPathways);
}

//mvIndex mvEndPathway();
mvErrorEnum mvWorld::mvRemoveCurrentPathway()
{
   //return removeCurrentItemFromList<mvPathway>(pathways, currentPathway, noOfPathways);
   return removeItemFromVectorByIndex<mvPathway>(pathways, currentPathway, currentPathway, noOfPathways);
}

mvIndex mvWorld::mvSetCurrentPathway(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvPathway>(pathways, index, currentPathway, noOfPathways);
}

void mvWorld::mvRemoveAllPathways()
{
   mvRemoveAllClassObjectsFromList<mvPathway>(pathways,currentPathway,noOfPathways);
}

mvErrorEnum mvWorld::mvSetPathwayParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvPathway>(pathways, index, noOfPathways, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetPathwayParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvPathway>(pathways, noOfPathways, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetPathwayParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
  return mvSetClassParameterv<mvPathway>(pathways, noOfPathways, index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentPathwayParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvPathway>(pathways, currentPathway, noOfPathways, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentPathwayParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvPathway>(pathways, noOfPathways, currentPathway, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentPathwayParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvPathway>(pathways, noOfPathways, currentPathway, paramFlag, array);
}

mvErrorEnum mvWorld::mvAddWaypointToPathway(mvIndex wpIndex, mvIndex pIndex)
{
   mvPathway* tempPathway = NULL;
   mvWaypoint* wPoint = NULL;

   wPoint = mvGetWaypoint(wpIndex);
   if (wPoint == NULL)
      return MV_WAYPOINT_INDEX_IS_INVALID;

   tempPathway = mvGetPathway(pIndex);
   if (tempPathway == NULL)
      return MV_PATHWAY_INDEX_IS_INVALID;

   tempPathway->addWaypoint(wPoint);
   return MV_NO_ERROR;
}

mvErrorEnum mvWorld::mvAddWaypointToCurrentPathway(mvIndex wpIndex)
{
   return mvAddWaypointToPathway(wpIndex,currentPathway);
}

mvErrorEnum mvWorld::mvAddCurrentWaypointToCurrentPathway()
{
   return mvAddWaypointToPathway(currentWaypoint,currentPathway);
}

mvErrorEnum mvWorld::mvAddCurrentWaypointToPathway(mvIndex pIndex)
{
   return mvAddWaypointToPathway(currentWaypoint,pIndex);
}

mvErrorEnum mvWorld::mvRemoveWaypointFromPathway(mvIndex wpIndex, mvIndex pIndex)
{
   mvPathway* tempPathway = NULL;
   mvWaypoint* wPoint = NULL;

   wPoint = mvGetWaypoint(wpIndex);
   if (wPoint == NULL)
      return MV_WAYPOINT_INDEX_IS_INVALID;

   tempPathway = mvGetPathway(pIndex);
   if (tempPathway == NULL)
      return MV_PATHWAY_INDEX_IS_INVALID;

   return tempPathway->removeWaypoint(wPoint);
}

mvErrorEnum mvWorld::mvRemoveWaypointFromCurrentPathway(mvIndex wpIndex)
{
   return mvRemoveWaypointFromPathway(wpIndex, currentPathway);
}

mvErrorEnum mvWorld::mvRemoveCurrentWaypointFromPathway(mvIndex pIndex)
{
   return mvRemoveWaypointFromPathway(currentWaypoint, pIndex);
}

mvErrorEnum mvWorld::mvRemoveCurrentWaypointFromCurrentPathway()
{
   return mvRemoveWaypointFromPathway(currentWaypoint, currentPathway);
}
// end waypoint / start force function

mvIndex mvWorld::mvAddForce(mvOptionEnum fType)
{
   return mvAddForceVector(fType, 0, 0, 0);
}

mvForce* mvWorld::mvGetForce(mvIndex index)
{
   return mvGetClassPtr<mvForce>(forces, index, noOfForces);
}

mvIndex mvWorld::mvAddForceVector(mvOptionEnum fType, mvFloat x, mvFloat y, mvFloat z)
{
   mvForce* tempForce = new mvForce(fType,x,y,z);

   forces.push_back(tempForce);
   ++noOfForces;
   currentForce = noOfForces;
   return currentForce;
}

mvErrorEnum mvWorld::mvRemoveForce(mvIndex index)
{
   return removeItemFromVectorByIndex<mvForce>(forces, index, currentForce, noOfForces);
}

mvErrorEnum mvWorld::mvRemoveCurrentForce()
{
   return removeItemFromVectorByIndex<mvForce>(forces, currentForce, currentForce, noOfForces);
}

void mvWorld::mvRemoveAllForces()
{
   mvRemoveAllClassObjectsFromList<mvForce>(forces, currentForce, noOfForces);
}

mvErrorEnum mvWorld::mvSetForceParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvForce>(forces, index, noOfForces, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetForceParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvForce>(forces, noOfForces, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetForceParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvForce>(forces, noOfForces,index, paramFlag, array);
}

mvErrorEnum mvWorld::mvSetCurrentForceParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvForce>(forces, currentForce, noOfForces, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentForceParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvForce>(forces, noOfForces, currentForce, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentForceParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvForce>(forces, noOfForces,currentForce, paramFlag, array);
}

mvIndex mvWorld::mvSetCurrentForce(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvForce>(forces, index, currentForce, noOfForces);
}

//mvIndex mvWorld::mvAddBehaviour(char* bName, mvEnum bType)
mvIndex mvWorld::mvAddBehaviour(mvOptionEnum bType)
{
   //std::vector<mvBehaviour*>::iterator i;
   mvBehaviour* tempBehaviour = NULL;
   /*
   if (bName == NULL)
      return 0;

   for (i = behaviours.begin(); i != behaviours.end(); ++i)
   {
      tempBehaviour = *i;
      if (tempBehaviour != NULL)
      {
         // if same name abort
         if (strcmp(tempBehaviour->getName(),bName) == 0)
         {
            return 0;
         }
      }
   }
   */
   // now name is unique
  // tempBehaviour = new mvBehaviour(bName,bType);
   tempBehaviour = new mvBehaviour(bType);
   behaviours.push_back(tempBehaviour);
   ++noOfBehaviours;
   currentBehaviour = noOfBehaviours;
   return currentBehaviour;
}

mvBehaviour* mvWorld::mvGetBehaviour(mvIndex index)
{
   return mvGetClassPtr<mvBehaviour>(behaviours, index, noOfBehaviours);
}
/*
mvBehaviour* mvWorld::mvGetBehaviourByID(char* bID)
{
   std::vector<mvBehaviour*>::iterator i;
   mvBehaviour* tempBehaviour = NULL;

   if (bID == NULL)
      return NULL;

   for (i = behaviours.begin(); i != behaviours.end(); ++i)
   {
      tempBehaviour = *i;
      if (tempBehaviour != NULL)
      {
         // check if name is the same
         if (strcmp(tempBehaviour->getName(),bID) == 0)
         {
            return tempBehaviour;
         }
      }
   }
   return NULL;
};
**
mvIndex mvWorld::mvGetBehaviourIndexByID(char* bID)
{
   std::vector<mvBehaviour*>::iterator i;
   mvCount count = 1;
   mvBehaviour* temp = NULL;
   char* tempID = NULL;

   if (bID == NULL)
      return 0;

   for ( i = behaviours.begin(); i != behaviours.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         tempID = temp->getName();
         if (tempID != NULL && strcmp(tempID, bID) == 0)
         {
            return count;
         }
      }
      ++count;
   }
   return 0;
};
*/

mvErrorEnum mvWorld::mvRemoveCurrentBehaviour()
{
   return removeItemFromVectorByIndex<mvBehaviour>(behaviours, currentBehaviour, currentBehaviour, noOfBehaviours);
}

mvErrorEnum mvWorld::mvRemoveBehaviour(mvIndex index)
{
   return removeItemFromVectorByIndex<mvBehaviour>(behaviours, index, currentBehaviour, noOfBehaviours);
}

mvIndex mvWorld::mvSetCurrentBehaviour(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvBehaviour>(behaviours, index, currentBehaviour, noOfBehaviours);
}

void mvWorld::mvRemoveAllBehaviours()
{
   mvRemoveAllClassObjectsFromList<mvBehaviour>(behaviours,currentBehaviour,noOfBehaviours);
}

mvErrorEnum mvWorld::mvSetBehaviourParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvBehaviour>(behaviours, index, noOfBehaviours, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetBehaviourParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvBehaviour>(behaviours, noOfBehaviours, index, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetBehaviourParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvBehaviour>(behaviours,noOfBehaviours,index,paramFlag,array);
}

mvErrorEnum mvWorld::mvSetCurrentBehaviourParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetClassParameter<mvBehaviour>(behaviours, currentBehaviour, noOfBehaviours, paramFlag, option);
}

mvErrorEnum mvWorld::mvSetCurrentBehaviourParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvBehaviour>(behaviours, noOfBehaviours, currentBehaviour, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentBehaviourParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvBehaviour>(behaviours, noOfBehaviours, currentBehaviour, paramFlag, array);
}

/*
mvEnum mvWorld::mvAddBehaviourToBody(mvIndex behaviourIndex, mvIndex bodyIndex)
{
   mvBody* tempBody = NULL;
   mvBehaviour* tempBehaviour = NULL;

   tempBehaviour = mvGetBehaviour(behaviourIndex);
   tempBody = mvGetBody(bodyIndex);

   if (tempBody != NULL && tempBehaviour != NULL)
   {
      return tempBody->addBehaviour(tempBehaviour,NULL,NULL);
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvWorld::mvAddCurrentBehaviourToBody(mvIndex bodyIndex)
{
   return mvAddBehaviourToBody(currentBehaviour,bodyIndex);
};

mvEnum mvWorld::mvAddBehaviourToCurrentBody(mvIndex behaviourIndex)
{
   return mvAddBehaviourToBody(behaviourIndex,currentBody);
};

mvEnum mvWorld::mvAddCurrentBehaviourToCurrentBody()
{
   return mvAddBehaviourToBody(currentBehaviour,currentBody);
};

mvEnum mvWorld::mvAddWaypointToBehaviour(mvIndex wpIndex,mvIndex behIndex)
{
   mvWaypoint* tempWaypoint = NULL;
   mvBehaviour* tempBehaviour = NULL;

   tempWaypoint = mvGetWaypoint(wpIndex);
   tempBehaviour = mvGetBehaviour(behIndex);

   if (tempWaypoint != NULL && tempBehaviour != NULL)
   {
      return tempBehaviour->addWaypoint(wpIndex);
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvWorld::mvAddCurrentWaypointToBehaviour(mvIndex behIndex)
{
   return mvAddWaypointToBehaviour(currentWaypoint,behIndex);
};

mvEnum mvWorld::mvAddWaypointToCurrentBehaviour(mvIndex wpIndex)
{
   return mvAddWaypointToBehaviour(wpIndex,currentBehaviour);
};

mvEnum mvWorld::mvAddCurrentWaypointToCurrentBehaviour()
{
   return mvAddWaypointToBehaviour(currentWaypoint,currentBehaviour);
};

mvEnum mvWorld::mvAddBodyToBehaviour(mvIndex bodyIndex, mvIndex behaviourIndex)
{
   mvBody* tempBody = NULL;
   mvBehaviour* tempBehaviour = NULL;

   tempBody = mvGetBody(bodyIndex);
   tempBehaviour = mvGetBehaviour(behaviourIndex);

   if (tempBody != NULL && tempBehaviour != NULL)
   {
      return tempBehaviour->addBody(bodyIndex);
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvWorld::mvAddCurrentBodyToBehaviour(mvIndex behaviourIndex)
{
   return mvAddBodyToBehaviour(currentBody,behaviourIndex);
};

mvEnum mvWorld::mvAddBodyToCurrentBehaviour(mvIndex bodyIndex)
{
  return mvAddBodyToBehaviour(bodyIndex,currentBehaviour);
};

mvEnum mvWorld::mvAddCurrentBodyToCurrentBehaviour()
{
   return mvAddBodyToBehaviour(currentBody,currentBehaviour);
};

*/

mvErrorEnum mvWorld::mvSetDefaultWaypointForBody(mvIndex waypointIndex, mvIndex bodyIndex)
{
   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   };

   tempBody->setDefaultWaypoint(waypointIndex);
   return MV_NO_ERROR;
}

mvErrorEnum mvWorld::mvSetDefaultPathwayForBody(mvIndex pathwayIndex, mvIndex bodyIndex)
{
   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   };

   tempBody->setDefaultPathway(pathwayIndex);
   return MV_NO_ERROR;
}

mvErrorEnum mvWorld::mvSetDefaultBodyForBody(mvIndex targetIndex,mvIndex bodyIndex)
{
   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   };

   tempBody->setDefaultBody(targetIndex);
   return MV_NO_ERROR;
}

mvIndex mvWorld::mvAddGroupBehaviour(mvOptionEnum type)
{
   mvGroupBehaviour* tempGroupBehav = NULL;

   tempGroupBehav = new mvGroupBehaviour(type);
   groupBehaviours.push_back(tempGroupBehav);
   ++noOfGroupBehaviours;
   currentGroupBehaviour = noOfBehaviours;
   return currentBehaviour;
}

mvGroupBehaviour* mvWorld::mvGetGroupBehaviour(mvIndex index)
{
   return mvGetClassPtr<mvGroupBehaviour>(groupBehaviours,index, noOfGroupBehaviours);
}

mvErrorEnum mvWorld::mvRemoveGroupBehaviour(mvIndex index)
{
   return removeItemFromVectorByIndex<mvGroupBehaviour>(groupBehaviours, index,
      currentGroupBehaviour, noOfGroupBehaviours);
}

mvErrorEnum mvWorld::mvRemoveCurrentGroupBehaviour()
{
   return removeItemFromVectorByIndex<mvGroupBehaviour>(groupBehaviours, currentGroupBehaviour,
      currentGroupBehaviour, noOfGroupBehaviours);
}

void mvWorld::mvRemoveAllGroupBehaviours()
{
   mvRemoveAllClassObjectsFromList<mvGroupBehaviour>(groupBehaviours, currentGroupBehaviour, noOfGroupBehaviours);
}

mvIndex mvWorld::mvSetCurrentGroupBehaviour(mvIndex index)
{
   return mvSetCurrentIndexOfClassList<mvGroupBehaviour>(groupBehaviours, index, currentGroupBehaviour, noOfGroupBehaviours);
}
/*
mvEnum mvWorld::mvSetGroupBehaviourParameter(mvIndex index, mvEnum paramFlag, mvEnum option)
{
   return mvSetClassParameterByIndex<mvGroupBehaviour>(groupBehaviours, index, noOfGroupBehaviours,
                       paramFlag, option);
};

mvEnum mvWorld::mvSetGroupBehaviourParameterf(mvIndex index, mvEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvGroupBehaviour>(groupBehaviours, noOfGroupBehaviours, index,
                   paramFlag, num);
};

mvEnum mvWorld::mvSetGroupBehaviourParameterv(mvIndex index, mvEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvGroupBehaviour>(groupBehaviours, noOfGroupBehaviours,index, paramFlag, array);
};

mvEnum mvWorld::mvSetCurrentGroupBehaviourParameter(mvEnum paramFlag, mvEnum option)
{
   return mvSetClassParameterByIndex<mvGroupBehaviour>(groupBehaviours,currentGroupBehaviour, noOfGroupBehaviours,
                       paramFlag, option);
};

mvEnum mvWorld::mvSetCurrentGroupBehaviourParameterf(mvEnum paramFlag, mvFloat num)
{
   return mvSetClassParameterf<mvGroupBehaviour>(groupBehaviours, noOfGroupBehaviours, currentGroupBehaviour,
                   paramFlag, num);
};

mvEnum mvWorld::mvSetCurrentGroupBehaviourParameterv(mvEnum paramFlag, mvFloat* array)
{
   return mvSetClassParameterv<mvGroupBehaviour>(groupBehaviours, noOfGroupBehaviours, currentGroupBehaviour, paramFlag, array);
};
*/
// 00-01-09
mvErrorEnum mvWorld::mvSetGroupBehaviourParameter(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setParameter(groupIndex,paramFlag,option);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvSetGroupBehaviourParameteri(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvIndex option)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setParameteri(groupIndex,paramFlag,option);
   }
   else
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvSetGroupBehaviourParameterf(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setParameterf(groupIndex,paramFlag,num);
   }
   else
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvSetGroupBehaviourParameterv(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setParameterv(groupIndex,paramFlag,array);
   }
   else
   {
      return MV_GROUP_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvSetCurrentGroupBehaviourParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetGroupBehaviourParameter(currentGroupBehaviour,groupIndex,paramFlag,option);
}

mvErrorEnum mvWorld::mvSetCurrentGroupBehaviourParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex option)
{
   return mvSetGroupBehaviourParameteri(currentGroupBehaviour,groupIndex,paramFlag,option);
}

mvErrorEnum mvWorld::mvSetCurrentGroupBehaviourParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num)
{
   return mvSetGroupBehaviourParameterf(currentGroupBehaviour, groupIndex, paramFlag, num);
}

mvErrorEnum mvWorld::mvSetCurrentGroupBehaviourParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetGroupBehaviourParameterv(currentGroupBehaviour,groupIndex,paramFlag,array);
}

mvErrorEnum mvWorld::mvAddBehaviourToBody(mvIndex bodyIndex, mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
{
   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody == NULL)
      return MV_BODY_INDEX_IS_INVALID;

   return tempBody->addEntry(bType,behaviourIndex,groupIndex);
}

mvErrorEnum mvWorld::mvInsertGroupIntoGroupBehaviour(mvIndex groupIndex, mvIndex groupBehaviour)
{
  mvGroup* checkGroup = mvGetGroup(groupIndex);
  mvGroupBehaviour* tempGBehaviour = mvGetGroupBehaviour(groupBehaviour);

  if (checkGroup != NULL && tempGBehaviour != NULL)
  {
     return tempGBehaviour->addGroup(groupIndex);
  }
  else
  {
     return MV_GROUP_INDEX_IS_INVALID;
  }
}

mvErrorEnum mvWorld::mvInsertCurrentGroupIntoGroupBehaviour(mvIndex groupBehaviour)
{
   return mvInsertGroupIntoGroupBehaviour(currentGroup,groupBehaviour);
}

mvErrorEnum mvWorld::mvInsertGroupIntoCurrentGroupBehaviour(mvIndex groupIndex)
{
   return mvInsertGroupIntoGroupBehaviour(groupIndex,currentGroupBehaviour);
}

mvErrorEnum mvWorld::mvInsertCurrentGroupIntoCurrentGroupBehaviour()
{
   return mvInsertGroupIntoGroupBehaviour(currentGroup,currentGroupBehaviour);
}

mvErrorEnum mvWorld::mvSetDefaultBehaviourFactorForBody(mvFloat factor, mvIndex bodyIndex)
{
   mvBody* tempBody = mvGetBody(bodyIndex);

   if (tempBody == NULL)
   {
      return MV_BODY_INDEX_IS_INVALID;
   }
   else
   {
      return tempBody->setDefaultBehaviourFactor(factor);
   }
}

mvErrorEnum mvWorld::mvSetDefaultWaypointForCurrentBody(mvIndex wpIndex)
{
   return mvSetDefaultWaypointForBody(wpIndex,currentBody);
}

mvErrorEnum mvWorld::mvSetDefaultPathwayForCurrentBody(mvIndex pwIndex)
{
   return mvSetDefaultPathwayForBody(pwIndex,currentBody);
}

mvErrorEnum mvWorld::mvSetDefaultBodyForCurrentBody(mvIndex bodyIndex)
{
   return mvSetDefaultBodyForBody(bodyIndex,currentBody);
}

mvErrorEnum mvWorld::mvSetDefaultBehaviourFactorForCurrentBody(mvFloat factor)
{
   return mvSetDefaultBehaviourFactorForBody(factor,currentBody);
}

mvErrorEnum mvWorld::mvAddBehaviourToCurrentBody(mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex)
{
   return mvAddBehaviourToBody(currentBody,bType,behaviourIndex,groupIndex);
}

mvErrorEnum mvWorld::mvSetBehaviourParameteri(mvIndex behaviourIndex,mvParamEnum paramFlag, mvIndex index)
{
   mvBehaviour* tempBehaviour = mvGetBehaviour(behaviourIndex);

   if (tempBehaviour != NULL)
   {
      return tempBehaviour->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

mvErrorEnum mvWorld::mvSetCurrentBehaviourParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetBehaviourParameteri(currentBehaviour,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetBodyParameteri(mvIndex bIndex, mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvBody>(bodies,bIndex,noOfBodies,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetPathwayParameteri(mvIndex pIndex, mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvPathway>(pathways,pIndex,noOfPathways,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetWaypointParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetObstacleParameteri(mvIndex oIndex, mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvObstacle>(obstacles,oIndex,noOfObstacles,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetGroupParameteri(mvIndex gIndex, mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvGroup>(groups,gIndex,noOfGroups,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentBodyParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvBody>(bodies,currentBody,noOfBodies,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentPathwayParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvPathway>(pathways,currentPathway,noOfPathways,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentWaypointParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvWaypoint>(waypoints,currentWaypoint,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentObstacleParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvObstacle>(obstacles,currentObstacle,noOfObstacles,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentGroupParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetClassParameteri<mvGroup>(groups,currentGroup,noOfGroups,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBodyParameteri(mvIndex bIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvBody>(bodies,bIndex,noOfBodies,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetPathwayParameteri(mvIndex pIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvPathway>(pathways,pIndex,noOfPathways,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWaypointParameteri(mvIndex wpIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvWaypoint>(waypoints,wpIndex,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetObstacleParameteri(mvIndex oIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvObstacle>(obstacles,oIndex,noOfObstacles,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupParameteri(mvIndex gIndex, mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvGroup>(groups,gIndex,noOfGroups,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBodyParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvBody>(bodies,currentBody,noOfBodies,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentPathwayParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvPathway>(pathways,currentPathway,noOfPathways,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentWaypointParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvWaypoint>(waypoints,currentWaypoint,noOfWaypoints,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentObstacleParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvObstacle>(obstacles,currentObstacle,noOfObstacles,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetClassParameteri<mvGroup>(groups,currentGroup,noOfGroups,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBodyParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvBody>(bodies,index,noOfBodies,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBodyParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvBody>(bodies,index,noOfBodies,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBodyParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvBody>(bodies,index,noOfBodies,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBodyParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvBody>(bodies,currentBody,noOfBodies,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBodyParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvBody>(bodies,currentBody,noOfBodies,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBodyParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvBody>(bodies,currentBody,noOfBodies,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetObstacleParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvObstacle>(obstacles,index,noOfObstacles,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetObstacleParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvObstacle>(obstacles,index,noOfObstacles,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetObstacleParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvObstacle>(obstacles,index,noOfObstacles,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentObstacleParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvObstacle>(obstacles,currentObstacle,noOfObstacles,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentObstacleParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvObstacle>(obstacles,currentObstacle,noOfObstacles,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentObstacleParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvObstacle>(obstacles,currentObstacle,noOfObstacles,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWaypointParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvWaypoint>(waypoints,index,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWaypointParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvWaypoint>(waypoints,index,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWaypointParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvWaypoint>(waypoints,index,noOfWaypoints,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentWaypointParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvWaypoint>(waypoints,currentWaypoint,noOfWaypoints,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentWaypointParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvWaypoint>(waypoints,currentWaypoint,noOfWaypoints,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentWaypointParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvWaypoint>(waypoints,currentWaypoint,noOfWaypoints,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetPathwayParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvPathway>(pathways,index,noOfPathways,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetPathwayParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvPathway>(pathways,index,noOfPathways,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetPathwayParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvPathway>(pathways,index,noOfPathways,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentPathwayParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvPathway>(pathways,currentPathway,noOfPathways,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentPathwayParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvPathway>(pathways,currentPathway,noOfPathways,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentPathwayParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvPathway>(pathways,currentPathway,noOfPathways,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvGroup>(groups,index,noOfGroups,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvGroup>(groups,index,noOfGroups,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvGroup>(groups,index,noOfGroups,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvGroup>(groups,currentGroup,noOfGroups,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvGroup>(groups,currentGroup,noOfGroups,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvGroup>(groups,currentGroup,noOfGroups,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBehaviourParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvBehaviour>(behaviours,index,noOfBehaviours,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBehaviourParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvBehaviour>(behaviours,index,noOfBehaviours,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetBehaviourParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetClassParameterv<mvBehaviour>(behaviours,index,noOfBehaviours,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBehaviourParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetClassParameter<mvBehaviour>(behaviours,currentBehaviour,noOfBehaviours,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBehaviourParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetClassParameterf<mvBehaviour>(behaviours,currentBehaviour,noOfBehaviours,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentBehaviourParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
return mvGetClassParameterv<mvBehaviour>(behaviours,currentBehaviour,noOfBehaviours,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupBehaviourParameter(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getParameter(groupIndex,paramFlag,option);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  *
  */
mvErrorEnum mvWorld::mvGetGroupBehaviourParameterf(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num)
{
//   return mvGetClassParameterf<mvGroupBehaviour>(groupBehaviours,index,noOfGroupBehaviours,paramFlag,num);
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getParameterf(groupIndex,paramFlag,num);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetGroupBehaviourParameterv(mvIndex gbIndex, mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(gbIndex);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getParameterv(groupIndex,paramFlag,array,noOfParameters);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupBehaviourParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetGroupBehaviourParameter(currentGroupBehaviour,groupIndex,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupBehaviourParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetGroupBehaviourParameterf(currentGroupBehaviour,groupIndex,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentGroupBehaviourParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetGroupBehaviourParameterv(currentGroupBehaviour,groupIndex,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetMainGroupBehaviourParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setMainParameter(paramFlag,option);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetMainGroupBehaviourParameteri(mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setMainParameteri(paramFlag,paramIndex);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetMainGroupBehaviourParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setMainParameterf(paramFlag,num);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetMainGroupBehaviourParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->setMainParameterv(paramFlag,array);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentMainGroupBehaviourParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return mvSetMainGroupBehaviourParameter(currentGroupBehaviour,paramFlag,option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentMainGroupBehaviourParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return mvSetMainGroupBehaviourParameteri(currentGroupBehaviour,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentMainGroupBehaviourParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return mvSetMainGroupBehaviourParameterf(currentGroupBehaviour,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentMainGroupBehaviourParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return mvSetMainGroupBehaviourParameterv(currentGroupBehaviour,paramFlag,array);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetMainGroupBehaviourParameter(mvIndex index, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getMainParameter(paramFlag,option);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetMainGroupBehaviourParameteri(mvIndex index, mvParamEnum paramFlag, mvIndex* paramIndex)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getMainParameteri(paramFlag,paramIndex);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetMainGroupBehaviourParameterf(mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getMainParameterf(paramFlag,num);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetMainGroupBehaviourParameterv(mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvGroupBehaviour* tempGroupBehav = mvGetGroupBehaviour(index);

   if (tempGroupBehav != NULL)
   {
      return tempGroupBehav->getMainParameterv(paramFlag,array,noOfParameters);
   }
   else
   {
      return MV_GROUP_BEHAVIOUR_INDEX_IS_INVALID;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentMainGroupBehaviourParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return mvGetMainGroupBehaviourParameter(currentGroupBehaviour, paramFlag, option);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentMainGroupBehaviourParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return mvGetMainGroupBehaviourParameteri(currentGroupBehaviour,paramFlag,index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentMainGroupBehaviourParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return mvGetMainGroupBehaviourParameterf(currentGroupBehaviour,paramFlag,num);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentMainGroupBehaviourParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return mvGetMainGroupBehaviourParameterv(currentGroupBehaviour,paramFlag,array,noOfParameters);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetWorldParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetWorldParameteri(mvParamEnum paramFlag, mvIndex paramIndex)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetWorldParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetWorldParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWorldParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWorldParameteri(mvParamEnum paramFlag, mvIndex* paramIndex)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWorldParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetWorldParameterv(mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   return MV_NO_ERROR;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetForceParameteri(mvIndex index, mvParamEnum paramFlag, mvIndex paramIndex)
{
   return mvSetClassParameteri<mvForce>(forces,index,noOfForces,paramFlag,paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetForceParameteri(mvIndex index, mvParamEnum paramFlag, mvIndex* paramIndex)
{
   return mvGetClassParameteri<mvForce>(forces,index,noOfForces,paramFlag,paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvSetCurrentForceParameteri(mvParamEnum paramFlag, mvIndex paramIndex)
{
   return mvSetClassParameteri<mvForce>(forces,currentForce,noOfForces,paramFlag,paramIndex);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvWorld::mvGetCurrentForceParameteri(mvParamEnum paramFlag, mvIndex* paramIndex)
{
   return mvGetClassParameteri<mvForce>(forces,currentForce,noOfForces,paramFlag,paramIndex);
}



