#include <mv/mvPathway_V2.h>

bool findNodeByIndexValue(mvPathwayNodePtr* nodePtr, void* extraPtr);

mvPathwayNode::mvPathwayNode(mvIndex pwNodeIndex)
{
   nodeIndex = pwNodeIndex;
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
mvPathway_V2::mvPathway_V2()
{
   isEnabled = true;
}

mvIndex mvPathway_V2::addNode(mvIndex pWaypoint)
{
   // null index not allowed
   if (pWaypoint == MV_NULL)
      return MV_NULL;

   mvPathwayNodePtr tempNode = new mvPathwayNode(pWaypoint);

   if (tempNode == MV_NULL)
      return MV_NULL;

   return nodes.addItem(tempNode);
}

bool findNodeByIndexValue(mvPathwayNodePtr nodePtr, void* extraPtr)
{
   if (nodePtr == MV_NULL)
      return false;

   int indexValue = *((int*) extraPtr);

   return (nodePtr->getNodeIndex() == indexValue);
}

mvErrorEnum mvPathway_V2::removeLastNodeInstance(mvIndex index)
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

mvErrorEnum mvPathway_V2::removeFirstNodeInstance(mvIndex index)
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
         setCurrentNode(index);
         return MV_NO_ERROR;
      default:
         return MV_INVALID_PATHWAY_PARAMETER;
   }
}

mvErrorEnum mvPathway_V2::setParametero(mvParamEnum paramFlag,\
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

mvErrorEnum mvPathway_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
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

mvErrorEnum mvPathway_V2::getParametero(mvParamEnum paramFlag,\
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

mvErrorEnum mvPathway_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_PATHWAY_PARAMETER;
}

mvErrorEnum mvPathway_V2::getParameterv(mvParamEnum paramFlag,\
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

mvErrorEnum mvPathway_V2::setNodeParameteri(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   return nodes.setItemParameteri(wpIndex, paramFlag, index);
}

mvErrorEnum mvPathway_V2::setNodeParametero(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return nodes.setItemParametero(wpIndex, paramFlag, option);
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

mvErrorEnum mvPathway_V2::getNodeParametero(mvIndex wpIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return nodes.getItemParametero(wpIndex, paramFlag, option);
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

void mvPathway_V2::removeAllNodes()
{
   nodes.deleteAllItems();
}

mvPathway_V2::~mvPathway_V2()
{
   removeAllNodes();
}

mvErrorEnum mvPathway_V2::getNodeParameteri_str(mvIndex nodeIndex,\
   const char* param, mvIndex* index) const
{
   return nodes.getItemParameteri_str(nodeIndex, param,index);
}

mvErrorEnum mvPathway_V2::getNodeParametero_str(mvIndex nodeIndex,\
   const char* param, const char** option) const
{
   return nodes.getItemParametero_str(nodeIndex, param,option);
}

mvErrorEnum mvPathway_V2::getNodeParameterf_str(mvIndex nodeIndex,\
   const char* param,  mvFloat* num) const
{
   return nodes.getItemParameterf_str(nodeIndex, param, num);
}
mvErrorEnum mvPathway_V2::getNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray, mvCount* noOfParameters) const
{
   return nodes.getItemParameterv_str(nodeIndex, param, numArray, noOfParameters);
}

mvErrorEnum mvPathway_V2::setNodeParameteri_str(mvIndex nodeIndex,\
   const char* param,  mvIndex index)
{
   return nodes.setItemParameteri_str(nodeIndex, param, index);
}

mvErrorEnum mvPathway_V2::setNodeParametero_str(mvIndex nodeIndex,\
   const char* param, const char* option)
{
   return nodes.setItemParametero_str(nodeIndex, param, option);
}

mvErrorEnum mvPathway_V2::setNodeParameterf_str(mvIndex nodeIndex,\
   const char* param, mvFloat num)
{
   return nodes.setItemParameterf_str(nodeIndex, param, num);
}

mvErrorEnum mvPathway_V2::setNodeParameterv_str(mvIndex nodeIndex,\
   const char* param, mvFloat* numArray)
{
   return nodes.setItemParameterv_str(nodeIndex, param,numArray);
}

mvErrorEnum mvPathway_V2::removeNodeAt(mvIndex nodeIndex)
{
   return nodes.deleteItem(nodeIndex);
}
