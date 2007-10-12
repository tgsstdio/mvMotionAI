#ifndef MVGROUPBNODE_V2_H_INCLUDED
#define MVGROUPBNODE_V2_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

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
#include MV_BEHAVIOUR_LIST_NODE_HEADER_FILE_H_
#include <list>

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

// todo : incorporate entry list node ptr

/** \class mvGroupMemberNode
 * \brief A class of member and its mvEntryListNode index related to
 * the mvGroupBehaviour.
 */
class MV_GLOBAL_FUNC_PREFIX mvGroupMemberNode
{
   public:
      mvIndex memberIndex;
      mvIndex memberNodeIndex;

      mvIndex getEntryNodeIndex() const;
      mvGroupMemberNode(mvIndex mbIndex,  mvIndex mbNodeIndex);
      bool operator<(const mvGroupMemberNode& rhs) const;
      bool operator== (const mvGroupMemberNode& rhs) const;
      ~mvGroupMemberNode();
};

/** \class mvGroupNodeMemberList
 * \brief A list of current members inside a group and the mvEntryListNode related
 * to the mvGroupBehaviour
 */
class MV_GLOBAL_FUNC_PREFIX mvGroupNodeMemberList
{
   public:
      std::list<mvGroupMemberNodePtr>::iterator currentIter;
      std::list<mvGroupMemberNodePtr> mbActionDataSet;

      mvGroupMemberNodePtr findMember(mvIndex memberIndex);
      mvGroupNodeMemberList();
      void clearAll();
      bool hasAllNodesBeenVisited();
      void toNextMember();
      void toFirstMember();
      mvGroupMemberNodePtr getCurrentMember();
      void insertBeforeCurrentMember(mvIndex memberIndex,\
         mvIndex entryNodeIndex);
      void deleteCurrentMember();
      ~mvGroupNodeMemberList();
};

class MV_GLOBAL_FUNC_PREFIX mvGroupBNode_V2
{
   private:
      mvIndex groupIndex;
      mvBaseActionPtr grpBehaviour;

   public:
      mvGroupNodeMemberList memberDataList;

      mvGroupMemberNodePtr findMemberInNode(mvIndex memberIndex);
      bool isEnabled;
      mvGroupBNode_V2(mvBaseActionPtr mainBehaviour,\
         mvIndex grpIndex);
      mvBaseActionPtr getActionPtr();
      mvIndex getGroup();
      mvErrorEnum setParametero(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getParametero(mvParamEnum paramFlag,\
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
