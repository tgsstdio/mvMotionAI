/**
 *\file mvBody.h
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
 *
 */
#ifndef MOTIONAI_MVBODY_H_
#define MOTIONAI_MVBODY_H_

#include <vector>

#include "mvMotionAI-Types.h"
#include "mvEnum.h"
#include "mvVec3.h"
#include "mvBehaviour-List.h"

/**
 *\class mvBody
 *
 * \brief
 *
 * Particle : An unidirectional moving object that does not require
 * rotation,
 *
 * Vehicle : a single directional moving object as either an obstacle or not.
 *
 * This class should be defined as a subclass of overall movement
 * class. This class differs from Vehicle because Particles can
 * travel along any direction instead of travelling along a single unit
 * vector.
 *
 * Log
 * Version		date		comments
 * 00-01-05   22/8/06   - using types headers and mvVec3.
 *
 * 00-01-03   21/6/06   - added behaviour list to mvBody class
 *
 * 00-01-02   31/5/06   - added behaviour / removing groups from body & system
 *
 * 00-01-00   19/5/06   - renamed particles and vehicles, grouped them into a group
 *                     under the name of mvBody.
 *
 * 00-00-06		6/3/06	- initialised particle
 *
 * 00-00-05    3/3/06   - intergration for motion.
 *
 * 00-00-02    8/2/06   - separated from MotionAI.h, created new
 *                     header and source file.
 *
 */

class mvBody
{
  private:
     void initialiseFloats();
     mvEnum initialiseDomain(mvEnum option);
     mvEnum initialiseDimensions(mvEnum option);
     mvEnum initialiseType(mvEnum option);
     mvEnum initialiseState(mvEnum option);
     mvCount getNoOfDomainVariables() const;

  public:
    mvBehaviourList bList;
    mvVec3 position;
    mvVec3 direction;
    mvVec3 finalVelocity;
    mvFloat maxSpeed;
    mvFloat speed;
    //mvFloat maxForce;
    mvFloat acceleration;
    mvFloat deceleration;
    //mvFloat maxDeceleration;
    //mvFloat maxAcceleration;
    mvFloat mass;
    mvFloat* dimensions;
    mvEnum bodyShape;
    //std::vector<int> behaviours;
    mvEnum domain; //< freedom of motion allowed
    mvFloat* domainVariables;
    //int noOfBehaviours;
    //int behaviourIndex;
    mvEnum type; //< body type i.e vehicle/particle/dual type
    mvEnum state; //< motion to apply iteration

    mvBody(mvEnum bType, mvEnum shape);
    mvBody(mvEnum bType, mvEnum shape, mvFloat x, mvFloat y, mvFloat z);
    //mvBody(mvFloat x, mvFloat y, mvFloat z);
    void setPosition(mvFloat x, mvFloat y, mvFloat z);
    void setDirection(mvFloat x, mvFloat y,mvFloat z);
    void setSpeed(mvFloat num);
    void setMaxSpeed(mvFloat num);
    void setMass(mvFloat num);
    void setState(mvEnum bState);
    mvCount getNoOfDimensions() const;

    mvEnum getType() const;
    mvEnum getState() const;
    mvEnum getDomain() const;
    mvEnum getShape() const;
    mvFloat getX() const;
    mvFloat getY() const;
    mvFloat getZ() const;
    //void setMaxAcceleration(mvFloat num);
    void setAcceleration(mvFloat accel);
    mvEnum setParameter(mvEnum paramFlag, mvEnum option);
    mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
    mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
    //
    mvEnum addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex);
    mvEnum addExistingBehaviourEntry(mvIndex behaviourIndex);
    mvEnum addNewBehaviourEntry(mvEnum behaviourType);
    mvEnum addEntry(mvEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);

    //mvEnum addBehaviour(mvBehaviour* bItem, mvEnum* flagArray, mvFloat* varArray);
    mvCount getNoOfBehaviours();
    mvBehaviourListNode* getEntryByIndex(mvIndex index);
    mvFloat getListFactorTotal() const;
    //mvBehaviourEntry* getEntryByPtr(mvBehaviour* bEntry);
    //mvBehaviourEntry* getEntryByName(char* bName);
    void removeAllBehaviours();
    ~mvBody();
    void setDefaultBody(mvIndex bodyIndex);
    void setDefaultWaypoint(mvIndex wpIndex);
    void setDefaultPathway(mvIndex pwIndex);
    mvEnum setDefaultBehaviourFactor(mvFloat factor);
    mvEnum checkGroupBehaviourExists(mvIndex behaviourIndex, mvIndex groupIndex);
};

#endif
