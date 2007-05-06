#include "mvPathway_v2.h"
#include <cstdlib>
#include <new>

bool findNodeByIndexValue(mvPathwayNodePtr* nodePtr, void* extraPtr);

mvPathwayNode::mvPathwayNode(mvIndex pwNodeIndex)
{
   nodeIndex = pwNodeIndex;
   additionalPoints = NULL;
}

mvPathwayNode::~mvPathwayNode()
{
   if (additionalPoints != NULL)
   {
      delete [] additionalPoints;
   }
}

mvIndex mvPathwayNode::getNodeIndex() const
{
   return nodeIndex;
}

mvErrorEnum mvPathwayNode::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == NULL)
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

mvErrorEnum mvPathwayNode::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   return  MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return  MV_INVALID_PATHWAY_NODE_PARAMETER;
}

mvErrorEnum mvPathwayNode::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
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

mvErrorEnum mvPathwayNode::setParameter(mvParamEnum paramFlag,\
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
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_NODE_PARAMETER;
}

// PATHWAY FUNCTIONS
mvPathway_V2::mvPathway_V2()
{

}

mvIndex mvPathway_V2::addNode(mvIndex pWaypoint)
{
   // null index not allowed
   if (pWaypoint == MV_NO_CURRENT_INDEX)
      return MV_NO_CURRENT_INDEX;

   mvPathwayNodePtr tempNode = new (std::nothrow) mvPathwayNode(pWaypoint);

   if (tempNode == NULL)
      return MV_NO_CURRENT_INDEX;

   return nodes.addItem(tempNode);
}

bool findNodeByIndexValue(mvPathwayNodePtr nodePtr, void* extraPtr)
{
   if (nodePtr == NULL)
      return false;

   int indexValue = *((int*) extraPtr);

   return (nodePtr->getNodeIndex() == indexValue);
}

mvErrorEnum mvPathway_V2::removeLastNodeInstance(mvIndex index)
{
   int indexValue = index;
   mvIndex foundItem = nodes.findItemInReverseInList(findNodeByIndexValue,\
      &indexValue);

   if (foundItem != MV_NO_CURRENT_INDEX)
   {
      return nodes.deleteItem(foundItem);
   }
   else
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }
}

mvErrorEnum mvPathway_V2::removeFirstNodeInstance(mvIndex index)
{
   int indexValue = index;
   mvIndex foundItem = nodes.findItemInList(findNodeByIndexValue,\
      &indexValue);

   if (foundItem != MV_NO_CURRENT_INDEX)
   {
      return nodes.deleteItem(foundItem);
   }
   else
   {
      return MV_ITEM_NOT_FOUND_IN_LIST;
   }
}

mvCount mvPathway_V2::getNoOfNodes() const
{
   return nodes.getNoOfItems();
}

mvIndex mvPathway_V2::setCurrentNode(mvIndex nIndex)
{
   return nodes.setCurrentIndex(nIndex);
}

mvIndex mvPathway_V2::getCurrentNode() const
{
   return nodes.getCurrentIndex();
}

mvErrorEnum mvPathway_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      case MV_INDEX:
         // TODO: check error function
         setCurrentNode(index);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }
}

mvErrorEnum mvPathway_V2::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   if (index == NULL)
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

mvErrorEnum mvPathway_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   // TODO : implement these functions
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
      // TODO : implement these functions
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::setNodeParameteri(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return nodes.setItemParameteri(wpIndex, paramFlag, index);
}

mvErrorEnum mvPathway_V2::setNodeParameter(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return nodes.setItemParameter(wpIndex, paramFlag, option);
}

mvErrorEnum mvPathway_V2::setNodeParameterf(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   return nodes.setItemParameterf(wpIndex, paramFlag, num);
}

mvErrorEnum mvPathway_V2::setNodeParameterv(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat* numArray)
{
   return nodes.setItemParameterv(wpIndex, paramFlag, numArray);
}

mvErrorEnum mvPathway_V2::getNodeParameteri(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return nodes.getItemParameteri(wpIndex, paramFlag, index);
}

mvErrorEnum mvPathway_V2::getNodeParameter(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return nodes.getItemParameter(wpIndex, paramFlag, option);
}

mvErrorEnum mvPathway_V2::getNodeParameterf(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return nodes.getItemParameterf(wpIndex, paramFlag, num);
}

mvErrorEnum mvPathway_V2::getNodeParameterv(mvIndex wpIndex,\
   mvParamEnum paramFlag,  mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getItemParameterv(wpIndex, paramFlag, numArray, noOfParameters);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   return nodes.setCurrentItemParameteri(paramFlag, index);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return nodes.setCurrentItemParameter(paramFlag, option);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return nodes.setCurrentItemParameterf(paramFlag, num);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   return nodes.setCurrentItemParameterv(paramFlag, numArray);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   return nodes.getCurrentItemParameteri(paramFlag, index);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   return nodes.getCurrentItemParameter(paramFlag, option);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   return nodes.getCurrentItemParameterf(paramFlag, num);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getCurrentItemParameterv(paramFlag, numArray, noOfParameters);
}

void mvPathway_V2::removeAllNodes()
{
   nodes.deleteAllItems();
}

mvPathway_V2::~mvPathway_V2()
{
   removeAllNodes();
}

mvErrorEnum mvPathway_V2::getCurrentNodeParametersi(const char* param,\
   mvIndex* index) const
{
   return nodes.getCurrentItemParametersi(param, index);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParameters(const char* param,\
   const char** option) const
{
   return nodes.getCurrentItemParameters(param, option);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParametersf(const char* param,\
   mvFloat* num) const
{
   return nodes.getCurrentItemParametersf(param, num);
}

mvErrorEnum mvPathway_V2::getCurrentNodeParametersv(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getCurrentItemParametersv(param,numArray, noOfParameters);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParametersi(const char* param,\
   mvIndex index)
{
   return nodes.setCurrentItemParametersi(param,index);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParameters(const char* param,\
   const char* option)
{
   return nodes.setCurrentItemParameters(param, option);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParametersf(const char* param,\
   mvFloat num)
{
   return nodes.setCurrentItemParametersf(param, num);
}

mvErrorEnum mvPathway_V2::setCurrentNodeParametersv(const char* param,\
   mvFloat* numArray)
{
   return nodes.setCurrentItemParametersv(param, numArray);
}

mvErrorEnum mvPathway_V2::getNodeParametersi(mvIndex nodeIndex,\
   const char* param, mvIndex* index) const
{
   return nodes.getItemParametersi(nodeIndex, param,index);
}

mvErrorEnum mvPathway_V2::getNodeParameters(mvIndex nodeIndex,\
   const char* param, const char** option) const
{
   return nodes.getItemParameters(nodeIndex, param,option);
}

mvErrorEnum mvPathway_V2::getNodeParametersf(mvIndex nodeIndex,\
   const char* param,  mvFloat* num) const
{
   return nodes.getItemParametersf(nodeIndex, param, num);
}
mvErrorEnum mvPathway_V2::getNodeParametersv(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getItemParametersv(nodeIndex, param, numArray, noOfParameters);
}

mvErrorEnum mvPathway_V2::setNodeParametersi(mvIndex nodeIndex,\
   const char* param,  mvIndex index)
{
   return nodes.setItemParametersi(nodeIndex, param, index);
}

mvErrorEnum mvPathway_V2::setNodeParameters(mvIndex nodeIndex,\
   const char* param, const char* option)
{
   return nodes.setItemParameters(nodeIndex, param, option);
}

mvErrorEnum mvPathway_V2::setNodeParametersf(mvIndex nodeIndex,\
   const char* param, mvFloat num)
{
   return nodes.setItemParametersf(nodeIndex, param, num);
}

mvErrorEnum mvPathway_V2::setNodeParametersv(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray)
{
   return nodes.setItemParametersv(nodeIndex, param,numArray);
}

mvErrorEnum mvPathway_V2::removeNodeAt(mvIndex nodeIndex)
{
   return nodes.deleteItem(nodeIndex);
}

mvErrorEnum mvPathway_V2::removeCurrentNode()
{
   return nodes.deleteCurrentItem();
}
