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
#ifndef MVBENTRYTREENODE_H_INCLUDED
#define MVBENTRYTREENODE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include MV_ENUMS_HEADER_FILE_H_
#include "mvBEntryTimer.h"

/* TODO : implement functions tree node */

class mvBEntryTreeNode
{
   public:
      mvIndex bEntryNode;
      mvOptionEnum mode;
      mvTimer timer;
      mvBEntryTreeNode* prevNode;
      mvBEntryTreeNode* nextLevel;
      mvBEntryTreeNode* prevLevel;
      mvBEntryTreeNode* nextNode;
      mvFloat weight;

      mvBEntryTreeNode(mvIndex bEntryIndex = MV_NO_CURRENT_INDEX,\
         mvOptionEnum bNodeMode = MV_WEIGHTED,\
         mvFloat bEWeight = 1.0,\
         mvFloat period = 1.0,\
         mvFloat elapsedTime = 0.0,
         mvBEntryTreeNode* beNextNode = NULL,\
         mvBEntryTreeNode* beNextLevel = NULL,
         mvBEntryTreeNode* bePrevNode = NULL,\
         mvBEntryTreeNode* bePrevLevel = NULL
         );

      mvIndex getEntryIndex();
      mvErrorEnum setMode(mvOptionEnum option);
      mvFloat getWeight() const;
      mvBEntryTimer* getTimer();
      mvErrorEnum setWeight(mvFloat bWeight);
      mvBEntryTreeNode* getNextNode();
      mvBEntryTreeNode* getNextLevel();
      mvBEntryTreeNode* getPrevNode();
      mvBEntryTreeNode* getPrevLevel();

      void setNextNode(mvBEntryTreeNode* node);
      void setNextLevel(mvBEntryTreeNode* node);
      void setPrevNode(mvBEntryTreeNode* node);
      void setPrevLevel(mvBEntryTreeNode* node);

      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      // helper functions
      void addNewNode(mvBEntryTreeNode* childNode);
      void addNewLevel(mvBEntryTreeNode* childNode);

     // ~mvBEntryTreeNode();
};

#endif // MVBENTRYTREENODE_H_INCLUDED
