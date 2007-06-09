#ifndef MVGROUPBEHAVIOUR_V2_H_INCLUDED
#define MVGROUPBEHAVIOUR_V2_H_INCLUDED

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

#include "mvPointerList.h"
#include MV_BASE_ACTION_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_


class mvGroupBehaviour_V2
{
   private:
      mvBaseActionPtr defaultGBehaviour;
      mvPointerList<mvGroupBehaviourNodePtr, mvGroupBehaviourNodePtr> groupNodeList;
   public:
      bool isEnabled;
      mvGroupBehaviour_V2(mvBaseActionPtr groupBehPtr);
      ~mvGroupBehaviour_V2();
      mvIndex addGroup(mvIndex groupNo, mvBaseAction* behavPtr);
      mvErrorEnum removeGroup(mvIndex groupNo);
      void removeAllGroups();
      mvGroupBehaviourNodePtr getGroupNodeByIndex(mvIndex index) const;
      mvGroupBehaviourNodePtr findGroupNode(mvIndex groupIndex) const;
      mvCount getNoOfGroups() const;

      mvIndex getCurrentGroupBehaviourNode() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index) const;
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option)\
         const;
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters) const;

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getGroupParameter(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setGroupParameter(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getGroupParameteri_str(mvIndex groupIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getGroupParameter_str(mvIndex groupIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParameterf_str(mvIndex groupIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParameterv_str(mvIndex groupIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setGroupParameteri_str(mvIndex groupIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setGroupParameter_str(mvIndex groupIndex, const char* param,\
         const char* option);
      mvErrorEnum setGroupParameterf_str(mvIndex groupIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParameterv_str(mvIndex groupIndex, const char* param,\
         mvFloat* numArray);

      mvErrorEnum getCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getCurrentNodeParameteri_str(const char* param,\
         mvIndex* index) const;
      mvErrorEnum getCurrentNodeParameter_str(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentNodeParameterf_str(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentNodeParameterv_str(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setCurrentNodeParameteri_str(const char* param,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentNodeParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParameterv_str(const char* param,\
         mvFloat* numArray);
};

#endif // MVGROUPBEHAVIOUR_V2_H_INCLUDED
