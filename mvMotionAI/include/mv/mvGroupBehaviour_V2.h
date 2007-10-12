/**
 * \file mvGroupBehaviour_V2.h
 *
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

#ifndef MVGROUPBEHAVIOUR_V2_H_INCLUDED
#define MVGROUPBEHAVIOUR_V2_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include "mvPointerList.h"
#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

/** \class mvGroupBehaviour
 * \brief A cooperative behaviour between groups of objects
 */

class MV_GLOBAL_FUNC_PREFIX mvGroupBehaviour
{
   private:
      mvBaseActionPtr defaultGBehaviour;
   public:
      mvPointerList<mvGroupBehaviourGroupNodePtr,\
         mvConstGroupBehaviourGroupNodePtr> groupNodeList;
      bool isEnabled;
      mvGroupBehaviour(mvBaseActionPtr groupBehPtr);
      ~mvGroupBehaviour();
      mvErrorEnum addGroup(mvIndex groupNo, mvBaseActionPtr behavPtr);
      mvErrorEnum removeGroup(mvIndex groupNo);
      void removeAllGroups();
      mvGroupBehaviourGroupNodePtr getGroupNodeByIndex(mvIndex index) const;
      mvGroupBehaviourGroupNodePtr findGroupNode(mvIndex groupIndex) const;
      mvCount getNoOfGroups() const;

      mvIndex getCurrentGroupBehaviourNode() const;
      mvBaseActionPtr getDefaultActionPtr() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParametero(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParametero(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getGroupParametero(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setGroupParametero(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getGroupParameteri_str(mvIndex groupIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getGroupParametero_str(mvIndex groupIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParameterf_str(mvIndex groupIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv_str(mvIndex groupIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setGroupParameteri_str(mvIndex groupIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setGroupParametero_str(mvIndex groupIndex, const char* param,\
         const char* option);
      mvErrorEnum setGroupParameterf_str(mvIndex groupIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParameterv_str(mvIndex groupIndex, const char* param,\
         mvFloat* numArray);
};

#endif // MVGROUPBEHAVIOUR_V2_H_INCLUDED
