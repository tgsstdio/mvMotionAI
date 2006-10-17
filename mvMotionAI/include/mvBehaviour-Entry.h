/**
 * \file mvBehaviour-Entry.h
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

#ifndef MV_BEHAVIOUR_ENTRY_H_
#define MV_BEHAVIOUR_ENTRY_H_
//#include "Vec3.h"
#include "mvMotionAI-Types.h"
#include "mvVec3.h"
//#include "mvBody.h"
#include "mvEnums.h"
//#include "mvPathway.h"
//#include "mvBehaviour.h"

/**
 * \class mvBehaviourEntry
 * Log
 *
 * Version     Date     Comments
 * 00-01-16   23/7/06   - enumerations now split into 3 categories
 *
 * 00-01-05   23/7/06   - re implememting file
 *
 * 00-01-03   21/6/06   - created behaviour entry
 *
 */
class mvBehaviourEntry
{
   private:
      void initDefault();
      mvErrorEnum mvBehaviour_InitialiseType2(mvOptionEnum type);

   public:
      //mvIndex behaviourIndex; // key 2
      mvOptionEnum bType; // key 1
      //mvIndex groupIndex; // key 3

      mvFloat* extraVariables;
      mvVec3* extraPoints;
      mvOptionEnum * extraStates;
      mvIndex* indexes;

   //mvIndex currentGroup;
   //mvPathway* currentPathway;
   //mvIndex currentWaypoint;
//   mvBody* currentBody;
      mvBehaviourEntry();
      mvBehaviourEntry(mvOptionEnum type);
  //vBehaviourEntry(mvEnum type, mvIndex behaviourIndex, mvIndex groupIndex);
      ~mvBehaviourEntry();
      mvBehaviourEntry(const mvBehaviourEntry& rhs);
      const mvBehaviourEntry& operator=(const mvBehaviourEntry& rhs);
   //mvIndex getBehaviourIndex();
      mvOptionEnum getType() const;
   //mvIndex getGroupIndex();

      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum * dest) const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvFloat* dest) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* dest) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* dest, mvCount* size) const;

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getParameters(const char* paramFlag, const char* dest) const;
      mvErrorEnum getParametersi(const char* paramFlag, mvFloat* dest) const;
      mvErrorEnum getParametersf(const char* paramFlag, mvFloat* dest) const;
      mvErrorEnum getParametersv(const char* paramFlag, mvFloat* dest, mvCount* size) const;

      mvErrorEnum setParameters(const char* paramFlag, const char* option);
      mvErrorEnum setParametersi(const char* paramFlag, mvIndex option);
      mvErrorEnum setParametersf(const char* paramFlag, mvFloat num);
      mvErrorEnum setParametersv(const char* paramFlag, mvFloat* numArray);

      mvErrorEnum addPathway(mvIndex bPathway);
      mvErrorEnum addWaypoint(mvIndex bWaypoint);
      mvIndex getWaypoint() const;
      mvIndex getPathway() const;

      mvIndex getWaypointIndexAt(mvIndex num) const;
      mvIndex getPathwayIndexAt(mvIndex num) const;

      mvIndex getBodyIndexAt(mvIndex num) const;
      mvIndex getBody() const;
      mvErrorEnum addBody(mvIndex bBody);
};

#endif
