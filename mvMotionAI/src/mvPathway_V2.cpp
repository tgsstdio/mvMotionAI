/**
 * \file mvPathway_V2.cpp
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

#include <mv/mvPathway_V2.h>

bool findNodeByIndexValue(mvPathwayNodePtr* nodePtr, void* extraPtr);

mvPathwayNode::mvPathwayNode(mvIndex pwNodeIndex)
{
   nodeIndex = pwNodeIndex;
   pathwayIndex = MV_NULL;
   additionalPoints = MV_NULL;
}

mvPathwayNode::~mvPathwayNode()
{
   if (additionalPoints != MV_NULL)
   {
      delete [] additionalPoints;
   }
}

mvIndex mvPathwayNode::getNodeIndex() const
{
   return nodeIndex;
}

mvIndex mvPathwayNode::getPathwayIndex() const
{
   return pathwayIndex;
}

void mvPathwayNode::setPathwayIndex(mvIndex pNode)
{
   pathwayIndex = pNode;
}

mvErrorEnum mvPathwayNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_INDEX:
         *index = nodeIndex;
         return MV_NO_ERROR;
      default:
         return  MV_INVALID_PATHWAY_NODE_PARAMETER;
   }
}

mvErrorEnum mvPathwayNode::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   return  MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return  MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      case MV_INDEX:
         nodeIndex = index;
         return MV_NO_ERROR;
      default:
         return  MV_INVALID_PATHWAY_NODE_PARAMETER;
   }
}

mvErrorEnum mvPathwayNode::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_NODE_PARAMETER;
}

// PATHWAY FUNCTIONS
/** \brief blah
 *
 */
mvPathway::mvPathway()
{
   isEnabled = true;
}

/** \brief blah
 *
 */
mvIndex mvPathway::addNode(mvIndex pWaypoint)
{
   mvIndex pathwayIndex;

   // null index not allowed
   if (pWaypoint == MV_NULL)
      return MV_NULL;

   mvPathwayNodePtr tempNode = new mvPathwayNode(pWaypoint);

   if (tempNode == MV_NULL)
      return MV_NULL;

   pathwayIndex = nodes.addItem(tempNode);
   tempNode->setPathwayIndex(pathwayIndex);
   return pathwayIndex;
}

/** \brief blah
 *
 */
bool findNodeByIndexValue(mvPathwayNodePtr nodePtr, void* extraPtr)
{
   if (nodePtr == MV_NULL)
      return false;

   int indexValue = *((int*) extraPtr);

   return (nodePtr->getNodeIndex() == indexValue);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::removeLastNodeInstance(mvIndex index)
{
   int indexValue = index;
   mvIndex foundItem = nodes.findItemInReverseInList(findNodeByIndexValue,\
      &indexValue);

   if (foundItem != MV_NULL)
   {
      return nodes.deleteItem(foundItem);
   }
   else
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::removeFirstNodeInstance(mvIndex index)
{
   int indexValue = index;
   mvIndex foundItem = nodes.findItemInList(findNodeByIndexValue,\
      &indexValue);

   if (foundItem != MV_NULL)
   {
      return nodes.deleteItem(foundItem);
   }
   else
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }
}

/** \brief blah
 *
 */
mvCount mvPathway::getNoOfNodes() const
{
   return nodes.getNoOfItems();
}

/** \brief blah
 *
 */
mvIndex mvPathway::setCurrentNode(mvIndex nIndex)
{
   return nodes.setCurrentIndex(nIndex);
}

/** \brief blah
 *
 */
mvIndex mvPathway::getCurrentNode() const
{
   return nodes.getCurrentIndex();
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      case MV_INDEX:
         setCurrentNode(index);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if(option == MV_FALSE)
         {
            isEnabled = true;
         }
         else
         {
            isEnabled = false;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_NO_OF_WAYPOINTS:
         *index = getNoOfNodes();
         return MV_NO_ERROR;
      case MV_INDEX:
         *index = getCurrentNode();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if(isEnabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }

}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameteri(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return nodes.setItemParameteri(wpIndex, paramFlag, index);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParametero(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return nodes.setItemParametero(wpIndex, paramFlag, option);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameterf(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return nodes.setItemParameterf(wpIndex, paramFlag, num);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameterv(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return nodes.setItemParameterv(wpIndex, paramFlag, numArray);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameteri(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return nodes.getItemParameteri(wpIndex, paramFlag, index);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParametero(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return nodes.getItemParametero(wpIndex, paramFlag, option);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameterf(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return nodes.getItemParameterf(wpIndex, paramFlag, num);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameterv(mvIndex wpIndex,\
   mvParamEnum paramFlag,  mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getItemParameterv(wpIndex, paramFlag, numArray, noOfParameters);
}

/** \brief blah
 *
 */
void mvPathway::removeAllNodes()
{
   nodes.deleteAllItems();
}

/** \brief blah
 *
 */
mvPathway::~mvPathway()
{
   removeAllNodes();
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameteri_str(mvIndex nodeIndex,\
   const char* param, mvIndex* index) const
{
   return nodes.getItemParameteri_str(nodeIndex, param,index);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParametero_str(mvIndex nodeIndex,\
   const char* param, const char** option) const
{
   return nodes.getItemParametero_str(nodeIndex, param,option);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameterf_str(mvIndex nodeIndex,\
   const char* param,  mvFloat* num) const
{
   return nodes.getItemParameterf_str(nodeIndex, param, num);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::getNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getItemParameterv_str(nodeIndex, param, numArray, noOfParameters);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameteri_str(mvIndex nodeIndex,\
   const char* param,  mvIndex index)
{
   return nodes.setItemParameteri_str(nodeIndex, param, index);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParametero_str(mvIndex nodeIndex,\
   const char* param, const char* option)
{
   return nodes.setItemParametero_str(nodeIndex, param, option);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameterf_str(mvIndex nodeIndex,\
   const char* param, mvFloat num)
{
   return nodes.setItemParameterf_str(nodeIndex, param, num);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::setNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray)
{
   return nodes.setItemParameterv_str(nodeIndex, param,numArray);
}

/** \brief blah
 *
 */
mvErrorEnum mvPathway::removeNodeAt(mvIndex nodeIndex)
{
   return nodes.deleteItem(nodeIndex);
}

#include <iostream>

bool mvPathway_GetNextNode(mvPathwayNodePtr node, void* extraPtr)
{
   mvIndex currentNode = *((mvIndex*) extraPtr);

   if (currentNode == MV_NULL)
   {
      return true;
   }

   return (node->getPathwayIndex() > currentNode);
}

bool mvPathway_GetPrevNode(mvPathwayNodePtr node, void* extraPtr)
{
   mvIndex currentNode = *((mvIndex*) extraPtr);

   if (currentNode == MV_NULL)
   {
      return true;
   }

   return (node->getPathwayIndex() < currentNode);
}

mvIndex mvPathway::getNextNode(mvIndex currentIndex) const
{
   mvIndex pastNode = nodes.convertIndex(currentIndex);

   return nodes.findItemInList(mvPathway_GetNextNode,&pastNode);
}

mvIndex mvPathway::getPrevNode(mvIndex currentIndex) const
{
   mvIndex pastNode = nodes.convertIndex(currentIndex);

   return nodes.findItemInReverseInList(mvPathway_GetPrevNode, &pastNode);
}

mvConstPathwayNodePtr mvPathway::getNodePtr(mvIndex nodeIndex) const
{
   return nodes.getConstClassPtr(nodeIndex);
}
