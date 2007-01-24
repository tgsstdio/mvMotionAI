#include "mvGroupBehaviour_V2.h"
#include "mvMotionAI_V2-Central.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBehaviour_V2::mvGroupBehaviour_V2(mvOptionEnum gbType)
{
   defaultGBehaviour = mvMotionAI_V2_CREATENEWBEHAVIOUR(gbType, NULL);
   behavEnabled = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBehaviour_V2::~mvGroupBehaviour_V2()
{
   removeAllGroups();
   if (defaultGBehaviour == NULL)
   {
      delete defaultGBehaviour;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::addGroup(mvIndex groupNo)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::removeGroup(mvIndex groupNo)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvGroupBehaviour_V2::removeAllGroups()
{
   groupNodeList.deleteAllItems();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBNode_V2 * mvGroupBehaviour_V2::getGroupNodeByIndex(mvIndex index)
{
   return groupNodeList.getClassPtr(index);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvGroupBNode_V2 * mvGroupBehaviour_V2::findGroupNode(mvIndex groupIndex)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvCount mvGroupBehaviour_V2::getNoOfGroups()
{
   return groupNodeList.getNoOfItems();
}

// ** @brief (one liner)
//  *
//  * (documentation goes here)
//  */
//mvOptionEnum mvGroupBehaviour_V2::getType()
//{
//
//}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvGroupBehaviour_V2::isEnabled()
{
   return behavEnabled;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvGroupBehaviour_V2::setEnabled(bool value)
{
   behavEnabled = value;
}

/** @brief (one liner)
  *
  * automatically calls the behaviour's default template version of
  * getParameteri
  */
mvErrorEnum mvGroupBehaviour_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   if (outIndex == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_CURRENT_INDEX:
         *outIndex = groupNodeList.getCurrentIndex();
         return MV_NO_ERROR;
      case MV_NO_OF_GROUPS:
         *outIndex = getNoOfGroups();
         return MV_NO_ERROR;
      default:
         if (defaultGBehaviour == NULL)
         {
            return defaultGBehaviour->getParameter(paramFlag, outIndex);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * automatically calls the behaviour's default template version of
  * getParameter
  */
mvErrorEnum mvGroupBehaviour_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }
/* TODO (White 2#1#): implement later */

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\ mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\ mvIndex* index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParameter(mvIndex groupIndex, mvParamEnum paramFlag,\ mvOptionEnum* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\ mvFloat* num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\ mvFloat* numArray, mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParameteri(mvIndex groupIndex, mvParamEnum paramFlag,\ mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParameter(mvIndex groupIndex, mvParamEnum paramFlag,\ mvOptionEnum option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParameterf(mvIndex groupIndex, mvParamEnum paramFlag,\ mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParameterv(mvIndex groupIndex, mvParamEnum paramFlag,\ mvFloat* numArray)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParametersi(mvIndex groupIndex, const char* param,\
   mvIndex* index)
{

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParameters(mvIndex groupIndex, const char* param,\
   const char** option)
{

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParametersf(mvIndex groupIndex, const char* param,\
   mvFloat* num)
{

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getNodeParametersv(mvIndex groupIndex, const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParametersi(mvIndex groupIndex, const char* param,\
   mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParameters(mvIndex groupIndex, const char* param,\
   const char* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParametersf(mvIndex groupIndex, const char* param,\
   mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setNodeParametersv(mvIndex groupIndex, const char* param,\
   mvFloat* numArray)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */

mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersi(const char* param,\
   mvIndex* index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParameters(const char* param,\
   const char** option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersf(const char* param,\
   mvFloat* num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::getCurrentNodeParametersv(const char* param,\
   mvFloat* numArray, mvCount* noOfParameters)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersi(const char* param,\
   mvIndex index)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParameters(const char* param,\
   const char* option)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersf(const char* param,\
   mvFloat num)
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBehaviour_V2::setCurrentNodeParametersv(const char* param,\
   mvFloat* numArray)
{

}
