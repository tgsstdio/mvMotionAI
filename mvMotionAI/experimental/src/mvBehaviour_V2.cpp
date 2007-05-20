#include "mvBehaviour_V2.h"

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
         if (behavPtr != MV_NULL)
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
mvBaseBehaviourPtr mvBehaviour_V2::getBehaviourPtr()
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
bool mvBehaviour_V2::isEnabled() const
{
   return behavEnabled;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
 mvBehaviour_V2::mvBehaviour_V2(mvBaseBehaviourPtr bPtr)
{
   behavPtr = bPtr;
   behavEnabled = true;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvBehaviour_V2::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (behavPtr != MV_NULL)
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
   if (behavPtr != MV_NULL)
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
   if (behavPtr != MV_NULL)
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
   mvOptionEnum* option) const
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
         if (behavPtr != MV_NULL)
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
   mvIndex* index) const
{
   if (behavPtr != MV_NULL)
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
   mvFloat* num) const
{
   if (behavPtr != MV_NULL)
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
   mvFloat* array, mvCount* noOfParameters) const
{
   if (behavPtr != MV_NULL)
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
   if (behavPtr != MV_NULL)
   {
      delete behavPtr;
      behavPtr = MV_NULL;
   }
}

