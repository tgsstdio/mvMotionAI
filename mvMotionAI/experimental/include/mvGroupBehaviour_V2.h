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
//#include "mvList.h" chenged to pointer list
#include "mvPointerList.h"
#include MV_BASE_BEHAVIOUR_HEADER_FILE_H_
#include MV_GROUP_BEHAVIOUR_NODE_HEADER_FILE_H_

// TODO : add pointer to pointer (ptr**) to mvBehaviourFuncList

class mvGroupBehaviour_V2
{
   private:
      mvBaseBehaviourPtr defaultGBehaviour;
      mvPointerList<mvGroupBehaviourNodePtr> groupNodeList;
      bool behavEnabled;
   public:
      mvGroupBehaviour_V2(mvBaseBehaviourPtr groupBehPtr);
      ~mvGroupBehaviour_V2();
      mvErrorEnum addGroup(mvIndex groupNo);
      mvErrorEnum removeGroup(mvIndex groupNo);
      void removeAllGroups();
      mvGroupBehaviourNodePtr getGroupNodeByIndex(mvIndex index);
      mvGroupBehaviourNodePtr findGroupNode(mvIndex groupIndex);
      mvCount getNoOfGroups();
      //mvOptionEnum getType();
      bool isEnabled();
      void setEnabled(bool value);

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getGroupParameter(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setGroupParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setGroupParameter(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setGroupParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setGroupParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getGroupParametersi(mvIndex groupIndex, const char* param,\
         mvIndex* index);
      mvErrorEnum getGroupParameters(mvIndex groupIndex, const char* param,\
         const char** option);
      mvErrorEnum getGroupParametersf(mvIndex groupIndex, const char* param,\
         mvFloat* num);
      mvErrorEnum getGroupParametersv(mvIndex groupIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setGroupParametersi(mvIndex groupIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setGroupParameters(mvIndex groupIndex, const char* param,\
         const char* option);
      mvErrorEnum setGroupParametersf(mvIndex groupIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setGroupParametersv(mvIndex groupIndex, const char* param,\
         mvFloat* numArray);

      mvErrorEnum getCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setCurrentNodeParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setCurrentNodeParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentNodeParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentNodeParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getCurrentNodeParametersi(const char* param,\
         mvIndex* index);
      mvErrorEnum getCurrentNodeParameters(const char* param,\
         const char** option);
      mvErrorEnum getCurrentNodeParametersf(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentNodeParametersv(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters);

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
