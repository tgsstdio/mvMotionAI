#include "mvPathway_v2.h"
#include <cstdlib>

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
   if (count == NULL)
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

   mvPathwayNodePtr tempNode = mvPathwayNode(pWaypoint);
   return nodes.addItem(tempNode);
}

bool findNodeByIndexValue(mvPathwayNodePtr* nodePtr, void* extraPtr)
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

mvErrorEnum mvPathway_V2::setCurrentNode(mvIndex nIndex)
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
         return setCurrentNode(index);
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

// TODO : implement these functions
mvErrorEnum mvPathway_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{

}

mvErrorEnum mvPathway_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{

}
mvErrorEnum mvPathway_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num) const;
mvErrorEnum mvPathway_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const;

mvErrorEnum mvPathway_V2::setNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvIndex index);
mvErrorEnum mvPathway_V2::setNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvOptionEnum option);
mvErrorEnum mvPathway_V2::setNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvFloat num);
mvErrorEnum mvPathway_V2::setNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvFloat* numArray);

mvErrorEnum mvPathway_V2::getNodeParameteri(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvIndex* index) const;
mvErrorEnum mvPathway_V2::getNodeParameter(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvOptionEnum* option) const;
mvErrorEnum mvPathway_V2::getNodeParameterf(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvFloat* num) const;
mvErrorEnum mvPathway_V2::getNodeParameterv(mvIndex wpIndex, mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const;

mvErrorEnum mvPathway_V2::setCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex index);
mvErrorEnum mvPathway_V2::setCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum option);
mvErrorEnum mvPathway_V2::setCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat num);
mvErrorEnum mvPathway_V2::setCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray);

mvErrorEnum mvPathway_V2::getCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const;
mvErrorEnum mvPathway_V2::getCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const;
mvErrorEnum mvPathway_V2::getCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const;
mvErrorEnum mvPathway_V2::getCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const;

void mvPathway_V2::removeAllNodes();
mvPathway_V2::~mvPathway_V2();
