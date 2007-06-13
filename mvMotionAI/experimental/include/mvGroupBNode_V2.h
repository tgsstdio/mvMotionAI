#ifndef MVGROUPBNODE_V2_H_INCLUDED
#define MVGROUPBNODE_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#ifdef MV_FILE_HEADER_TAG_
/**
 * Copyright (c) 2006, 2007 David Young.
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
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include MV_BASE_ACTION_HEADER_FILE_H_
#include <list>

class mvGroupMemberNode
{
   public:
      mvIndex memberIndex;
      mvBaseActionPtr memberAction;

      mvGroupMemberNode(mvIndex mbIndex,  mvBaseActionPtr mbAction);
      bool operator<(const mvGroupMemberNode& rhs) const;
      bool operator== (const mvGroupMemberNode& rhs) const;
      mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;
      ~mvGroupMemberNode();
};

typedef class mvGroupMemberNode* mvGroupMemberNodePtr;
typedef class mvGroupMemberNode const * const mvConstGroupMemberNodePtr;

class mvGroupNodeMemberList
{
   public:
         // TODO : use something else like a set
      std::list<mvGroupMemberNodePtr>::iterator currentIter;
      std::list<mvGroupMemberNodePtr> mbActionDataSet;

      mvGroupNodeMemberList();
      void clearAll();
      bool hasAllNodesBeenVisited();
      void toNextMember();
      void toFirstMember();
      mvGroupMemberNodePtr getCurrentMember();
      void insertBeforeCurrentMember(mvIndex memberIndex,\
         mvBaseActionPtr actionPtr);
      void deleteCurrentMember();
      ~mvGroupNodeMemberList();
};

class mvGroupBNode_V2
{
   private:
      mvIndex groupIndex;
      mvBaseActionPtr grpBehaviour;

   public:
      mvGroupNodeMemberList memberDataList;

      bool isEnabled;
      mvGroupBNode_V2(mvBaseActionPtr mainBehaviour,\
         mvIndex grpIndex);
      mvBaseActionPtr getActionPtr();
      mvIndex getGroup();
      mvErrorEnum setParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex) const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;
      ~mvGroupBNode_V2();
};

#endif // MVGROUPBNODE_V2_H_INCLUDED
