#include "mvGroupBNode_V2.h"
#include "mvMotionAI_V2-Central.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBNode_V2::~mvGroupBNode_V2()
{
   if (grpBehaviour != NULL)
   {
      delete grpBehaviour;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   if (noOfParameters == NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (array == NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (grpBehaviour  != NULL)
   {
      return grpBehaviour ->getParameterv(paramFlag, array, noOfParameters);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   if (num == NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (grpBehaviour  != NULL)
   {
      return grpBehaviour ->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* outIndex)
{
   if (outIndex == NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_GROUP:
         *outIndex = groupIndex;
         return MV_NO_ERROR;
      default:
         if (grpBehaviour != NULL)
         {
            return grpBehaviour ->getParameteri(paramFlag, outIndex);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   if (option == NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (behavEnabled)
         {
            *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         if (grpBehaviour  != NULL)
         {
            return grpBehaviour ->getParameter(paramFlag, option);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::setParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   if (array == NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (grpBehaviour  != NULL)
   {
      return grpBehaviour ->setParameterv(paramFlag, array);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::setParameterf( mvParamEnum paramFlag, mvFloat num)
{
   if (grpBehaviour != NULL)
   {
      return grpBehaviour->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (grpBehaviour  != NULL)
   {
      return grpBehaviour ->setParameteri(paramFlag, index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}
// TODO : function implementation later
/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroupBNode_V2::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            behavEnabled = false;
         }
         else
         {
            behavEnabled = true;
         }
         return MV_NO_ERROR;
      default:
         if (grpBehaviour  != NULL)
         {
            return grpBehaviour->setParameter(paramFlag, option);
         }
         else
         {
            return MV_BEHAVIOUR_IS_NOT_INITIALISED;
         }
   }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvBaseBehaviour * mvGroupBNode_V2::getBehaviourPtr()
{
   return grpBehaviour;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvGroupBNode_V2::setEnabled(bool value)
{
   behavEnabled = value;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvGroupBNode_V2::isEnabled()
{
   return behavEnabled;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvGroupBNode_V2::mvGroupBNode_V2(mvOptionEnum gbType,\
   mvBaseBehaviour* mainBehaviour, mvIndex grpIndex)
{
   grpBehaviour = mvMotionAI_V2_CREATENEWBEHAVIOUR(gbType, mainBehaviour);
   groupIndex = grpIndex;
}

mvIndex  mvGroupBNode_V2::getGroup()
{
   return groupIndex;
}
