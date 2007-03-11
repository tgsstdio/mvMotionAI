/**
 * \file mvBehaviour.h
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

#ifndef MOTIONAI_MVBEHAVIOUR_H_
#define MOTIONAI_MVBEHAVIOUR_H_
//#include "mvGroup.h"
//#include "mvPathway.h"
//#include "mvWaypoint.h"
#include "mvBehaviour-Entry.h"
#include "mvEnums.h"
#include "mvMotionAI-Types.h"
//#include "Vec3.h"
//#include <vector>
/**
 * \class mvBehaviour
 *
 * \brief behaviour states
 *
 *
 * Log
 *
 *version     date  comments
 *
 *00-01-17  25/10/06 - added get/set parameter functions
 *
 *00-01-05  26/7/06  - removed variables, added code reuse in mvBehaviourEntry
 *
 *00-01-03  21/6/06  - now using index values instead of pointers, finally
 *                     implemented two beahviours SEEK and FLEE,
 *
 *00-01-02  31/5/06  - removing groups from system until better solution
 *                     arrives.
 *
 *00-01-01  24/5/06  - start work on behvaiour functions i.e
 *                     SEEK, FLEE, CLONE, FOLLOW PATH
 *
 *                   - add behaviour entry as temp solution
 *
 *00-01-00  22/5/06  - initialised behaviours
 */


class mvBehaviour
{
  private:
    //char* behaviourName;
    //std::vector<mvGroup*> groups;
    //int noOfGroups;
    //mvEnum bType;
    mvBehaviourEntry* behavData;
    void initDefault();
    //mvEnum initialiseType(mvEnum type);
    //mvEnum initialiseVectors(mvEnum type);
    //mvEnum addEntry(mvGroupPtr bGroup, mvBodyPtr bBody);
    //mvEnum removeEntry(mvGroupPtr bGroup, mvBodyPtr bBody);
    //mvEnum removeGroupEntries(mvGroupPtr bGroup);
    //mvFloat* defaultVariables;
    //Vec3* defaultVectors;
    //mvPathway* bPaths;
    //mvWaypoint* bWaypoints;
    //mvIndex* indexes;

  public:
     // undecleared
    mvBehaviour(mvOptionEnum type);
    mvBehaviour(const mvBehaviour& rhs);
    const mvBehaviour& operator=(const mvBehaviour& rhs);
    mvBehaviourEntry* getData() const;
    mvOptionEnum getType() const;

    ~mvBehaviour();
    mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
    mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
    mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
    mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements);

    mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
    mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
    mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
    mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

    //mvBehaviour(char* bName, mvEnum type);
    //char* getName();
    //int getNoOfGroups();
    //void removeAllGroups();
    //mvEnum addGroup(mvGroupPtr bGroup);
    //mvEnum removeGroup(mvGroupPtr bGroup);
};
#endif
