/**
 *\file mvGroupBehaviour.h
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

#ifndef MV_GROUP_BEHAVIOUR_H_
#define MV_GROUP_BEHAVIOUR_H_

#include "mvMotionAI-Types.h"
#include "mvBehaviour-Entry.h"
//#include "mvBehaviour.h"
//#include "mvGroup.h"
#include "mvEnums.h"
#include <vector>
//#include <set>
/**
 * \class mvGroupBehaviourNode
 * Log
 *
 * Version     Date     Comments
 * 00-01-05   15/8/06   - now using index values instead.
 *
 *            26/7/06   - created mvGroupBehaviourNode for simplicity
 */
// MS VC++ compiler warnings are annoying
//#define mvGroupBehaviourNode gn
class mvGroupBehaviourNode
{
   private:
     // mvGroupPtr groupPtr;
      mvIndex groupIndex;
      mvBehaviourEntry* behavData;

   public:
      mvGroupBehaviourNode();
      mvGroupBehaviourNode(mvOptionEnum gbType, mvIndex bGroup);
      mvGroupBehaviourNode(const mvGroupBehaviourNode& rhs);
      const mvGroupBehaviourNode& operator=(const mvGroupBehaviourNode& rhs);
     // mvGroupPtr getGroup() const;
      mvIndex getGroup() const;
      mvBehaviourEntry* getBehavData() const;
      ~mvGroupBehaviourNode();

      bool operator<(const mvGroupBehaviourNode& rhs) const;
};

/**
 * \class mvGroupBehaviour
 * Log
 *
 * Version     Date     Comments
 *
 * 00-01-17   24/10/06  - added get/set parameters + main functions
 *
 * 00-01-05   15/8/06   - considered using stl::sets - now back to vector.
 *
 *            26/7/06   - created mvGroupBehaviourNode vector for simplicity
 */

class mvGroupBehaviour
{
   private:
      void initDefault();
      mvBehaviourEntry* defaultEntries;
      std::vector<mvGroupBehaviourNode*> groupsList;
      mvOptionEnum groupBehaviourType;
      mvCount noOfGroups;

   public:

      mvGroupBehaviour();
      mvGroupBehaviour(mvOptionEnum bType);
      mvErrorEnum addGroup(mvIndex groupNo);
      mvErrorEnum removeGroup(mvIndex groupNo);
      void removeAllGroups();
      mvGroupBehaviourNode* getGroupNodeByIndex(mvIndex index);
      mvGroupBehaviourNode* findGroupNodeByIndex(mvIndex groupIndex);
      mvCount getNoOfGroups() const;
      mvOptionEnum getType() const;
      ~mvGroupBehaviour();

      mvErrorEnum getMainParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getMainParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getMainParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getMainParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setMainParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setMainParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setMainParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setMainParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvIndex groupIndex, mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvIndex groupIndex, mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvIndex groupIndex, mvParamEnum paramFlag, mvFloat* numArray);
};


#endif
