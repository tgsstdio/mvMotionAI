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
#ifndef MVBENTRYTREE_H_INCLUDED
#define MVBENTRYTREE_H_INCLUDED

#include "mvMotionAI-Types.h"
#include "mvEnums.h"
#include "mvBEntryTreeNode.h"
#include "mvBEntryTimer.h"

class mvBEntryTree
{
   private:
      mvCount noOfNodes;
      mvBEntryTreeNode* root;
      mvBEntryTreeNode* currentNode;

   public:
      mvBEntryTree();
      mvErrorEnum addNewNode(mvOptionEnum beMode, mvIndex entryIndex,\
         mvFloat weight, mvBEntryTimer* timer);
      mvErrorEnum addNewLevel(mvOptionEnum beMode, mvIndex entryIndex,\
         mvFloat weight, mvBEntryTimer* timer);

      // does current node after
      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
         mvCount* noOfParameters);

      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);

      mvErrorEnum moveCurrentNodeUp(mvCount moves);
      mvErrorEnum moveCurrentNodeDown(mvCount moves);
      mvErrorEnum moveCurrentNodeBack(mvCount moves);
      mvErrorEnum moveCurrentNodeForward(mvCount moves);

      mvErrorEnum deleteCurrentNode();

      void deleteAllNodes();
      ~mvBEntryTree();
};

#endif // MVBENTRYTREE_H_INCLUDED
