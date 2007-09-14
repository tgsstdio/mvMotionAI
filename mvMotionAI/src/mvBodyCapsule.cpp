#include <mv/mvBodyCapsule.h>

mvBodyCapsule::mvBodyCapsule(mvBodyPtr capsuleBody)
{
   bodyIndex = MV_NULL;
   encapsulatedBody = capsuleBody;
   performIntegration = true;
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
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameteri(paramFlag, index);
}

mvErrorEnum mvBodyCapsule::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameter(paramFlag, option);
}

mvErrorEnum mvBodyCapsule::getParameterf(mvParamEnum paramFlag, mvFloat* num)\
   const
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameterf(paramFlag, num);
}

mvErrorEnum mvBodyCapsule::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->getParameterv(paramFlag,\
      numArray, noOfParameters);
}

mvErrorEnum mvBodyCapsule::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameteri(paramFlag, index);
}
mvErrorEnum mvBodyCapsule::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameter(paramFlag,option);
}

mvErrorEnum mvBodyCapsule::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameterf(paramFlag, num);
}

mvErrorEnum mvBodyCapsule::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (encapsulatedBody == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsulatedBody->setParameterv(paramFlag,numArray);
}

mvBodyCapsule::~mvBodyCapsule()
{
   if (encapsulatedBody == MV_NULL)
   {
      delete encapsulatedBody;
      encapsulatedBody = MV_NULL;
   }
}
