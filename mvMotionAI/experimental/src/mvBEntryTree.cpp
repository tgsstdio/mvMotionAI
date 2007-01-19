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
#include "mvBEntryTree.h"
/**
 * \brief mvBehaviour entry tree constructor
 */
mvBEntryTree::mvBEntryTree()
{
   currentNode = NULL;
   root = NULL;
   noOfNodes = 0;
}

/**
 * \brief checks if the root has defined
 */
bool mvBEntryTree::isRootEmpty()
{
   return (root == NULL);
}

/**
 * \brief creates behaviour entry tree root node
 *
 * If timer is supplied, the timer's period is set to the
 * root node. The elapsed time is set to zero.
 */
void mvBEntryTree::createRootTreeNode(mvIndex entryIndex,\
   mvOptionEnum beMode, mvFloat weight, mvBEntryTimer* timer)
{

//      mvBEntryTreeNode(mvIndex bEntryIndex = MV_NO_CURRENT_INDEX,\
//         mvOptionEnum bNodeMode = MV_WEIGHTED,\
//         mvFloat bEWeight = 1.0,\
//         mvBEntryTreeNode* beNextNode = NULL,\
//         mvBEntryTreeNode* beNextLevel = NULL,
//         mvBEntryTreeNode* bePrevNode = NULL,\
//         mvBEntryTreeNode* bePrevLevel = NULL,\
//         mvFloat period = 1.0,\
//         mvFloat elapsedTime = 0.0
//         );
   // if root is empty
   if (isRootEmpty())
   {
      if ( timer != NULL)
      {
         root = new mvBEntryTreeNode(entryIndex, beMode, weight, timer->getPeriod());
      }
      else
      {
         root = new mvBEntryTreeNode(entryIndex, beMode, weight);
      }
      currentNode = root;
      ++noOfNodes;
   }


}

/**
 * \brief add new node to the current node
 */
mvErrorEnum mvBEntryTree::addNewNode(mvIndex entryIndex,mvOptionEnum beMode,\
   mvFloat weight, mvBEntryTimer* timer)
{
   mvBEntryTreeNode* newNode = NULL;

   /* check new root node */
   if (isRootEmpty())
   {
      createRootTreeNode(entryIndex, beMode, weight, timer);
      return MV_NO_ERROR;
   }

   // now check that the next node pointer is NULL
   if (currentNode->getNextNode() != NULL)
   {
      return MV_NEW_ENTRY_TREE_POSITION_IS_NOT_NULL;
   }

   // create new node
   if (timer != NULL)
   {
      newNode = new mvBEntryTreeNode(entryIndex, beNode, weight, timer->getPeriod());
   }
   else
   {
      newNode = new mvBEntryTree(entryIndex, beNode, weight);
   }

   if (newNode == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }

   //add node to current node
   currentNode->addNewNode(newNode);

   // set new current node to new node
   currentNode = newNode;

   return MV_NO_ERROR;
}

/**
 * \brief add new level to the current node
 */
mvErrorEnum mvBEntryTree::addNewLevel(mvOptionEnum beMode, mvIndex entryIndex,\
   mvFloat weight, mvBEntryTimer* timer)
{
   mvBEntryTreeNode* newNode = NULL;

   if (isRootEmpty())
   {
      createRootTreeNode(entryIndex, beMode, weight, timer);
      return MV_NO_ERROR;
   }

   // now check that the next level pointer is NULL
   if (currentNode->getNextLevel() != NULL)
   {
      return MV_NEW_ENTRY_TREE_POSITION_IS_NOT_NULL;
   }

   // create new node
   if (timer != NULL)
   {
      newNode = new mvBEntryTreeNode(entryIndex, beNode, weight, timer->getPeriod());
   }
   else
   {
      newNode = new mvBEntryTree(entryIndex, beNode, weight);
   }

   if (newNode == NULL)
   {
      return MV_INVALID_MEMORY_ALLOCATION;
   }

   //add new level to current node
   currentNode->addNewLevel(newNode);

   // set new current node to new node
   currentNode = newNode;

   return MV_NO_ERROR;
}

/**
 * \brief moves current node up levels
 */
mvErrorEnum mvBEntryTree::moveCurrentNodeUp(mvCount moves)
{
   //TODO : add negetive index to move to the farthest
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   if (moves < 0)
   {
      return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
   }

   // return when count is reached
   // abort is NULL is reached
   while(temp != NULL)
   {
      if (possibleMoves >= moves)
      {
         currentNode = temp;
         return MV_NO_ERROR;
      }
      temp = temp->getPrevLevel();
      ++possibleMoves;
   }

   return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
}

/**
 * \brief moves current node down levels
 */
mvErrorEnum mvBEntryTree::moveCurrentNodeDown(mvCount moves)
{
   //TODO : add negetive index to move to the farthest
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   if (moves < 0)
   {
      return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
   }

   // return when count is reached
   // abort is NULL is reached
   while(temp != NULL)
   {
      if (possibleMoves >= moves)
      {
         currentNode = temp;
         return MV_NO_ERROR;
      }
      temp = temp->getNextLevel();
      ++possibleMoves;
   }

   return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
}

mvErrorEnum mvBEntryTree::moveCurrentNodeBack(mvCount moves)
{
   //TODO : add negetive index to move to the farthest
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   if (moves < 0)
   {
      return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
   }

   // return when count is reached
   // abort is NULL is reached
   while(temp != NULL)
   {
      if (possibleMoves >= moves)
      {
         currentNode = temp;
         return MV_NO_ERROR;
      }
      temp = temp->getPrevNode();
      ++possibleMoves;
   }

   return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
}

mvErrorEnum mvBEntryTree::moveCurrentNodeForward(mvCount moves)
{
   //TODO : add negetive index to move to the farthest
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   if (moves < 0)
   {
      return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
   }

   // return when count is reached
   // abort is NULL is reached
   while(temp != NULL)
   {
      if (possibleMoves >= moves)
      {
         currentNode = temp;
         return MV_NO_ERROR;
      }
      temp = temp->getNextNode();
      ++possibleMoves;
   }

   return MV_INVALID_NO_OF_MOVES_INSIDE_TREE;
}

/**
 * \brief deletes the current node and its lower levels as well
 *
 * NOTE 1 : if tree is empty (i.e root contains no nodes)
 *
 * NOTE 2 : when a node is deleted, the next node is takes the position,
 * and the lower levels are deleted as well.
 */
mvErrorEnum mvBEntryTree::deleteCurrentNode()
{
 /* TODO (White 2#1#): Implement this function */
   mvBEntryTreeNode* nextPtr = NULL;
   mvBEntryTreeNode* prevPtr = NULL;
   mvBEntryTreeNode* levelAbovePtr = NULL;
   mvBEntryTreeNode* levelBelowPtr = NULL;
   mvBEntryTreeNode* temp = NULL;

   // if tree is empty, no problem
   if (isRootEmpty())
   {
      return MV_NO_ERROR;
   }

   nextPtr = currentNode->getNextNode();
   prevPtr = currentNode->getPrevNode();
   levelAbovePtr = currentNode->getPrevLevel();
   levelBelowPtr = currentNode->getNextLevel();

   // if front node in level connect to  temp (new node)

   // if next node exist, connect both nodes (+ previous node) with in level

   // delete all node from level below this node


   // if the current node is root
   if (root == currentNode)
   {

   }

   return MV_NO_ERROR;
}

void mvBEntryTree::deleteAllNodes()
{
 /* TODO (White 2#1#): Implement this function */
}

mvBEntryTree::~mvBEntryTree()
{
   deleteAllNodes();
}

mvCount mvBEntryTree::countLevelsAbove()
{
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   while(temp != NULL)
   {
      temp = temp->getPrevLevel();
      ++possibleMoves;
   }

   return possibleMoves;
}

mvCount mvBEntryTree::countLevelBelow()
{
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   while(temp != NULL)
   {
      temp = temp->getNextLevel();
      ++possibleMoves;
   }

   return possibleMoves;
}

mvCount mvBEntryTree::countNextNodes()
{
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   while(temp != NULL)
   {
      temp = temp->getNextNode();
      ++possibleMoves;
   }

   return possibleMoves;
}

mvCount mvBEntryTree::countPreviousNodes()
{
   mvCount possibleMoves = 0;
   mvBEntryTreeNode* temp = currentNode;

   while(temp != NULL)
   {
      temp = temp->getPrevNode();
      ++possibleMoves;
   }

   return possibleMoves;
}
