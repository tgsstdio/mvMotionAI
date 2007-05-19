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
 */
#ifndef MVGROUPBEHAVIOUR_V2_H_INCLUDED
#define MVGROUPBEHAVIOUR_V2_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvPointerList.h"
#include MV_BASE_BEHAVIOUR_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_


class mvGroupBehaviour_V2
{
   private:
      mvBaseBehaviourPtr defaultGBehaviour;
      mvPointerList<mvGroupBehaviourNodePtr, mvGroupBehaviourNodePtr> groupNodeList;
      bool behavEnabled;
   public:
      mvGroupBehaviour_V2(mvBaseBehaviourPtr groupBehPtr);
      ~mvGroupBehaviour_V2();
      // TODO : implement
      mvErrorEnum addGroup(mvIndex groupNo, mvBaseBehaviour* behavPtr);
      mvErrorEnum removeGroup(mvIndex groupNo);
      void removeAllGroups();
      mvGroupBehaviourNodePtr getGroupNodeByIndex(mvIndex index) const;
      mvGroupBehaviourNodePtr findGroupNode(mvIndex groupIndex) const;
      mvCount getNoOfGroups() const;
      //mvOptionEnum getType();
      // TODO : remove these functions
      bool isEnabled() const;
      void setEnabled(bool value);
      // TODO : get current node
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

      mvErrorEnum getGroupParametersi(mvIndex groupIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getGroupParameters(mvIndex groupIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getGroupParametersf(mvIndex groupIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getGroupParametersv(mvIndex groupIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setGroupParametersi(mvIndex groupIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setGroupParameters(mvIndex groupIndex, const char* param,\
         const char* option);
      mvErrorEnum setGroupParametersf(mvIndex groupIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParametersv(mvIndex groupIndex, const char* param,\
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

      mvErrorEnum getCurrentNodeParametersi(const char* param,\
         mvIndex* index) const;
      mvErrorEnum getCurrentNodeParameters(const char* param,\
         const char** option) const;
      mvErrorEnum getCurrentNodeParametersf(const char* param,\
         mvFloat* num) const;
      mvErrorEnum getCurrentNodeParametersv(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters) const;

      mvErrorEnum setCurrentNodeParametersi(const char* param,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameters(const char* param,\
         const char* option);
      mvErrorEnum setCurrentNodeParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParametersv(const char* param,\
         mvFloat* numArray);
};

#endif // MVGROUPBEHAVIOUR_V2_H_INCLUDED
