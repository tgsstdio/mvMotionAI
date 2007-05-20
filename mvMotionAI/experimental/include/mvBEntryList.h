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
#ifndef MVBENTRYLIST_H_INCLUDED
#define MVBENTRYLIST_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include "mvBaseBehaviour.h"
#include "mvList.h"
#include "mvBEntryListNode.h"
#include "mvBEntryTreeNode.h"
#include "mvBEntryTree.h"
/* TODO (White 2#1#): Implement all these functions */

class mvBEntryList
{
   private:
      mvItemList<mvBEntryListNode> entryList;
      mvOptionEnum integrationMode;
      mvFloat defaultWeight;
      mvIndex defaultBody;
      mvIndex defaultWaypoint;
      mvIndex defaultPathway;
      mvBEntryTree entryNodeTree;

   public:
      mvBEntryList(mvFloat dWeight, mvIndex dBody, mvIndex dWaypoint,\
         mvIndex dPathway);

      mvBEntryListNode* findExistingGroupEntry(mvIndex bIndex,\
         mvIndex gIndex);
      mvBEntryListNode* getEntry(mvIndex index);

      mvErrorEnum setMode(mvOptionEnum option);
      mvOptionEnum getMode() const;

      void setDefaultBody(mvIndex bodyIndex);
      void setDefaultWaypoint(mvIndex wpIndex);
      void setDefaultPathway(mvIndex pwIndex);
      mvErrorEnum setDefaultWeight(mvFloat factor);

      mvErrorEnum addExistingGroupBehaviourEntry(mvIndex behaviourIndex,\
         mvIndex groupIndex, mvBaseBehaviour* dBehaviour);
      mvErrorEnum addExistingBehaviourEntry(mvIndex behaviourIndex);
      mvErrorEnum addNewBehaviourEntry(mvOptionEnum behaviourType);
      mvErrorEnum addNewEntry(mvOptionEnum bType, mvIndex behaviourIndex,\
         mvIndex groupIndex, mvBaseBehaviour* dBehaviour);

      mvIndex getDefaultBody() const;
      mvIndex getDefaultWaypoint() const;
      mvIndex getDefaultPathway() const;
      mvFloat getDefaultWeight() const;

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum getEntryParameteri(mvIndex entryIndex, mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getEntryParameter(mvIndex entryIndex, mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getEntryParameterf(mvIndex entryIndex, mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getEntryParameterv(mvIndex entryIndex, mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setEntryParameteri(mvIndex entryIndex,mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setEntryParameter(mvIndex entryIndex,mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setEntryParameterf(mvIndex entryIndex,mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setEntryParameterv(mvIndex entryIndex,mvParamEnum paramFlag,\
         mvFloat* numArray);

      mvErrorEnum getCurrentEntryParameteri(mvParamEnum paramFlag,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentEntryParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentEntryParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentEntryParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setCurrentEntryParameteri(mvParamEnum paramFlag,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentEntryParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentEntryParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentEntryParameterv(mvParamEnum paramFlag,\
         mvFloat* numArray);

      // string functions
      mvErrorEnum getEntryParameteri_str(mvIndex entryIndex, const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getEntryParameter_str(mvIndex entryIndex, const char* param,\
         const char** option);
      mvErrorEnum getEntryParameterf_str(mvIndex entryIndex, const char* param,\
         mvFloat* num);
      mvErrorEnum getEntryParameterv_str(mvIndex entryIndex, const char* param,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setEntryParameteri_str(mvIndex entryIndex,const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setEntryParameter_str(mvIndex entryIndex,const char* param,\
         const char* option);
      mvErrorEnum setEntryParameterf_str(mvIndex entryIndex,const char* param,\
         mvFloat num);
      mvErrorEnum setEntryParameterv_str(mvIndex entryIndex,const char* param,\
         mvFloat* numArray);

      mvErrorEnum getCurrentEntryParameteri_str(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentEntryParameter_str(const char* param,\
         const char** option);
      mvErrorEnum getCurrentEntryParameterf_str(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentEntryParameterv_str(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setCurrentEntryParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentEntryParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentEntryParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentEntryParameterv_str(const char* param,\
         mvFloat* numArray);

      // TODO : tree functions
      mvErrorEnum addNewTreeNode(mvOptionEnum tMode, mvIndex entryIndex);
      mvErrorEnum addNewTreeLevel(mvOptionEnum tMode, mvIndex entryIndex);
      void deleteEntryTree();
      mvBEntryTree* getEntryTree();
      mvBEntryTreeNode* getCurrentNode();

      mvErrorEnum setCurrentTreeEntryParameter(mvParamEnum param,\
         mvOptionEnum option);
      mvErrorEnum setCurrentTreeEntryParameteri(mvParamEnum param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentTreeEntryParameterf(mvParamEnum param,\
         mvFloat num);
      mvErrorEnum setCurrentTreeEntryParameterv(mvParamEnum param,\
         mvFloat* numArray);

      mvErrorEnum getCurrentTreeEntryParameter(mvParamEnum param,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentTreeEntryParameteri(mvParamEnum param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentTreeEntryParameterf(mvParamEnum param,\
         mvFloat* num);
      mvErrorEnum getCurrentTreeEntryParameterv(mvParamEnum param,\
         mvFloat* numArray, mvCount* noOfParameters);

      mvErrorEnum setCurrentTreeEntryParameter_str(const char* param,\
         mvOptionEnum option);
      mvErrorEnum setCurrentTreeEntryParameteri_str(const char* param,\
         mvIndex paramIndex);
      mvErrorEnum setCurrentTreeEntryParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentTreeEntryParameterv_str(const char* param,\
         mvFloat* numArray);

      mvErrorEnum getCurrentTreeEntryParameter_str(const char* param,\
         const char** option);
      mvErrorEnum getCurrentTreeEntryParameteri_str(const char* param,\
         mvIndex* outIndex);
      mvErrorEnum getCurrentTreeEntryParameterf_str(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentTreeEntryParameterv_str(const char* param,\
         mvFloat* numArray, mvCount* noOfParameters);

      ~mvBEntryList();

};

#endif // MVBENTRYLIST_H_INCLUDED
