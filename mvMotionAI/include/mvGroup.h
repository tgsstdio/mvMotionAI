/**
 *\file mvGroup.h
 * Copyright (c) 2006,2007 David Young.
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

#ifndef MOTIONAI_MVGROUP_H_
#define MOTIONAI_MVGROUP_H_

#include <vector>
//#include <string>
#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvBody.h"

/**
 * \class mvGroup
 *
 * \brief to create a group of bodies
 *
 * Log
 *
 *version     date  comments
 *00-01-25  1/11/07  - changed to const char* in constructor
 *
 *00-01-17  18/10/06 - including get/set parameters
 *
 *00-01-16  15/10/06 - converted for new enums
 *
 *00-01-05  23/8/06  - types now declared by mvMotionAI-Types.h & mvVec3
 *
 *00-01-00  22/5/06  - initialised groups
 */
class mvGroup
{
   private:
     std::vector<mvBody*> members;
     //int noOfMembersSlots;
     mvCount noOfMembers;
     //char* groupID;
     char* groupID;

   public:
      mvGroup();
      mvGroup(const char* mBodyGroupID);
      mvCount getNoOfMembers();
      void clearAllMembers();
     // void removeAllMembers();
      char* getID() const;
      mvBody* getMemberByIndex(mvIndex index);
      mvErrorEnum addMember(mvBody* tempBody);
      mvErrorEnum removeMember(mvBody* tempBody);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
      ~mvGroup();
};

#endif

