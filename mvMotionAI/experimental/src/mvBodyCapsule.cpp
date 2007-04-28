#include "mvBodyCapsule.h"

mvBodyCapsule::mvBodyCapsule(mvBodyPtr capsuleBody)
{
   encapsulatedBody = capsuleBody;
}

mvConstBodyPtr mvBodyCapsule::getConstClassPtr() const
{
   return (mvBody*) encapsulatedBody;
}

mvBodyPtr mvBodyCapsule::getClassPtr() const
{
   return encapsulatedBody;
}

mvErrorEnum mvBodyCapsule::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameteri(paramFlag, index);
}

mvErrorEnum mvBodyCapsule::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameter(paramFlag, option);
}

mvErrorEnum mvBodyCapsule::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameterf(paramFlag, num);
}

mvErrorEnum mvBodyCapsule::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameterv(paramFlag,\
      numArray, noOfParameters);
}

mvErrorEnum mvBodyCapsule::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameteri(paramFlag, index);
}
mvErrorEnum mvBodyCapsule::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameter(paramFlag,option);
}

mvErrorEnum mvBodyCapsule::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameterf(paramFlag, num);
}

mvErrorEnum mvBodyCapsule::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (encapsulatedBody == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameterv(paramFlag,numArray);
}

mvBodyCapsule::~mvBodyCapsule()
{
   if (encapsulatedBody == NULL)
   {
      delete encapsulatedBody;
      encapsulatedBody = NULL;
   }
}
