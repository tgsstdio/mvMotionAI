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
#include MV_ENUMS_HEADER_FILE_H_
#include "mvBEntryTreeNode.h"
#include "mvBEntryTimer.h"

typedef class entryTreeBucketNode* mvEntryTreeBucketNodePtr;

typedef class entryTreeNode 
{	
	mvEntryTreeBucketNodePtr lowerDirectory;
}mvEntryTreeNode;


#define MV_MAX_NO_OF_ENTRY_TREE_NODE_IN_ARRAY (7)

typedef class entryTreeBucketNode
{
	public:
		mvEntryTreeBucketNodePtr prevBucket;
		mvEntryTreeBucketNodePtr nextBucket;
		mvEntryTreeBucketNodePtr higherDirectory;
		mvEntryTreeNode	treeNodes[MV_MAX_NO_OF_ENTRY_TREE_NODE_IN_ARRAY]
} mvEntryTreeBucketNode;


class mvBEntryTree
{
   private:
      mvCount noOfNodes;
      mvBEntryTreeNode* root;
      mvBEntryTreeNode* currentNode;
      void createRootTreeNode(mvIndex entryIndex,\
         mvOptionEnum beMode, mvFloat weight, mvTimerPtr timer);
      bool isRootEmpty();

   public:
      mvBEntryTree();
      mvErrorEnum addNewNode(mvIndex entryIndex = MV_NO_CURRENT_INDEX,\
         mvOptionEnum beMode = MV_WEIGHTED,
         mvFloat weight = 1.0, mvBEntryTimer* timer = NULL);
      mvErrorEnum addNewLevel(mvIndex entryIndex = MV_NO_CURRENT_INDEX,\
         mvOptionEnum beMode = MV_WEIGHTED,\
         mvFloat weight = 1.0, mvBEntryTimer* timer = NULL);

      // does current node after
      mvBEntryTreeNode* getCurrentNode();
      mvBEntryTreeNode* getRoot();

      mvErrorEnum moveCurrentNodeUp(mvCount moves);
      mvErrorEnum moveCurrentNodeDown(mvCount moves);
      mvErrorEnum moveCurrentNodeBack(mvCount moves);
      mvErrorEnum moveCurrentNodeForward(mvCount moves);

      mvCount countLevelsAbove();
      mvCount countLevelBelow();
      mvCount countNextNodes();
      mvCount countPreviousNodes();

      mvErrorEnum deleteCurrentNode();

      void deleteAllNodes();
      ~mvBEntryTree();
};

#endif // MVBENTRYTREE_H_INCLUDED
