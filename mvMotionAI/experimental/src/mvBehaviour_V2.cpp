#include "mvBehaviour_V2.h"
#include "mvMotionAI_V2-Central.h"

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBehaviour_V2::setParameter(mvParamEnum paramFlag,\
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
         if (behavPtr != NULL)
         {
            return behavPtr->setParameter(paramFlag, option);
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
mvSuperBehaviourPtr mvBehaviour_V2::getBehaviourPtr()
{
   return behavPtr;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void mvBehaviour_V2::setEnabled(bool value)
{
   behavEnabled = value;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool mvBehaviour_V2::isEnabled()
{
   return behavEnabled;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBehaviour_V2::mvBehaviour_V2(mvOptionEnum bType)
{
   behavPtr = mvMotionAI_V2_CREATENEWBEHAVIOUR(bType, NULL);
   behavEnabled = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBehaviour_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (behavPtr != NULL)
   {
      return behavPtr->setParameteri(paramFlag, index);
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
mvErrorEnum mvBehaviour_V2::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (behavPtr != NULL)
   {
      return behavPtr->setParameterf(paramFlag, num);
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
mvErrorEnum mvBehaviour_V2::setParameterv(mvParamEnum paramFlag, mvFloat* array)
{
   if (behavPtr != NULL)
   {
      return behavPtr->setParameterv(paramFlag, array);
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
mvErrorEnum mvBehaviour_V2::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
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
         if (behavPtr != NULL)
         {
            return behavPtr->getParameter(paramFlag, option);
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
mvErrorEnum mvBehaviour_V2::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   if (behavPtr != NULL)
   {
      return behavPtr->getParameteri(paramFlag, index);
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
mvErrorEnum mvBehaviour_V2::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   if (behavPtr != NULL)
   {
      return behavPtr->getParameterf(paramFlag, num);
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
mvErrorEnum mvBehaviour_V2::getParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   if (behavPtr != NULL)
   {
      return behavPtr->getParameterv(paramFlag, array, noOfParameters);
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
 mvBehaviour_V2::~mvBehaviour_V2()
{
   if (behavPtr != NULL)
   {
      delete behavPtr;
      behavPtr = NULL;
   }
}

