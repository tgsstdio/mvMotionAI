#include "mvForceCapsule.h"

#ifdef MV_FILE_HEADER_TAG_
/**
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
#endif

mvForceCapsule::mvForceCapsule(mvForcePtr forcePtr)
{
   encappedForce = forcePtr;
}

mvErrorEnum mvForceCapsule::addWaypoint(mvIndex index)
{
   return linkedWaypoints.addIndex(index);
}

mvErrorEnum mvForceCapsule::removeWaypoint(mvIndex index)
{
   return linkedWaypoints.removeIndex(index);
}

void mvForceCapsule::clearAllWaypoints()
{
   linkedWaypoints.clearAll();
}

mvForcePtr mvForceCapsule::getForcePtr() const
{
   return encappedForce;
}

mvConstForcePtr mvForceCapsule::getConstForcePtr() const
{
   return (mvConstForcePtr) encappedForce;
}

mvErrorEnum mvForceCapsule::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->getParameteri(paramFlag, index);
}

mvErrorEnum mvForceCapsule::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->getParameter(paramFlag, option);
}

mvErrorEnum mvForceCapsule::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->getParameterf(paramFlag, num);
}

mvErrorEnum mvForceCapsule::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfParameters) const
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->getParameterv(paramFlag,\
      numArray, noOfParameters);
}

mvErrorEnum mvForceCapsule::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->setParameteri(paramFlag, index);
}
mvErrorEnum mvForceCapsule::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->setParameter(paramFlag,option);
}

mvErrorEnum mvForceCapsule::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->setParameterf(paramFlag, num);
}

mvErrorEnum mvForceCapsule::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (encappedForce == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encappedForce->setParameterv(paramFlag,numArray);
}

mvForceCapsule::~mvForceCapsule()
{
   clearAllWaypoints();
   if (encappedForce != NULL)
   {
      delete encappedForce;
      encappedForce = NULL;
   }
}