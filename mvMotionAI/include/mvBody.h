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
#include "mvEnums.h"
#include "mvVec3.h"
#include "mvBehaviour-List.h"

/**
 *\class mvBody
 *
 *\brief moving objects in the system
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
// TODO : add speed functions/methods to get current engine speed, \
// actual speed. direction speed
// TODO : implementation of VEHICLE
// TODO : implementation of DUAL_TYPE
// TODO : domains limiting
// TODO : shapes and dimensions
 *
 * Log
 * Version		date		comments
 * 00-01-17   22/8/06   - add get/set parameters
 *
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

static const mvCount MV_MAX_NO_OF_BODY_DIMENSIONS = 3;

class mvBody
{
  private:
     void initialiseFloats();
     mvErrorEnum initialiseDomain(mvOptionEnum option);
     mvErrorEnum initialiseDimensions(mvOptionEnum option);
     mvErrorEnum initialiseType(mvOptionEnum option);
     mvErrorEnum initialiseState(mvOptionEnum option);
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
    mvOptionEnum bodyShape;
    //std::vector<int> behaviours;
    mvOptionEnum domain; //< freedom of motion allowed
    mvFloat* domainVariables;
    //int noOfBehaviours;
    //int behaviourIndex;
    mvOptionEnum type; //< body type i.e vehicle/particle/dual type
    mvOptionEnum state; //< motion to apply iteration

    mvBody(mvOptionEnum bType, mvOptionEnum shape);
    mvBody(mvOptionEnum bType, mvOptionEnum shape, mvFloat x, mvFloat y, mvFloat z);
    //mvBody(mvFloat x, mvFloat y, mvFloat z);
    void setPosition(mvFloat x, mvFloat y, mvFloat z);
    void setDirection(mvFloat x, mvFloat y,mvFloat z);
    void setSpeed(mvFloat num);
    void setMaxSpeed(mvFloat num);
    void setMass(mvFloat num);
    void setState(mvOptionEnum bState);
    mvCount getNoOfDimensions() const;

    mvOptionEnum getType() const;
    mvOptionEnum getState() const;
    mvOptionEnum getDomain() const;
    mvOptionEnum getShape() const;
    mvFloat getX() const;
    mvFloat getY() const;
    mvFloat getZ() const;
    //void setMaxAcceleration(mvFloat num);
    void setAcceleration(mvFloat accel);
    mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
    mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
    mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
    mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

    mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
    mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
    mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
    mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
    //
    mvErrorEnum addExistingGroupBehaviourEntry(mvIndex behaviourIndex, mvIndex groupIndex);
    mvErrorEnum addExistingBehaviourEntry(mvIndex behaviourIndex);
    mvErrorEnum addNewBehaviourEntry(mvOptionEnum behaviourType);
    mvErrorEnum addEntry(mvOptionEnum bType, mvIndex behaviourIndex, mvIndex groupIndex);

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
    mvIndex getDefaultBody() const;
    mvIndex getDefaultWaypoint() const;
    mvIndex getDefaultPathway() const;
    mvFloat getDefaultBehaviourFactor() const;
    mvErrorEnum setDefaultBehaviourFactor(mvFloat factor);
    bool checkGroupBehaviourExists(mvIndex behaviourIndex, mvIndex groupIndex);
};

#endif
