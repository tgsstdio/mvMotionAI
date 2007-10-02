#include <mv/mvGroupCapsule.h>

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

mvGroupCapsule::mvGroupCapsule(mvGroupPtr group)
{
   encapsuledGroup = group;
   hasChanged = true;
}

mvGroupPtr mvGroupCapsule::getClassPtr() const
{
   return encapsuledGroup;
}

mvConstGroupPtr mvGroupCapsule::getConstClassPtr() const
{
   return (mvConstGroupPtr) encapsuledGroup;
}

mvErrorEnum mvGroupCapsule::getParameteri(mvParamEnum paramFlag, mvIndex* index) const
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->getParameteri(paramFlag, index);
}

mvErrorEnum mvGroupCapsule::getParametero(mvParamEnum paramFlag, mvOptionEnum* option)\
   const
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->getParametero(paramFlag, option);
}

mvErrorEnum mvGroupCapsule::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->getParameterf(paramFlag, num);
}

mvErrorEnum mvGroupCapsule::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->getParameterv(paramFlag, numArray, noOfParameters);
}

mvErrorEnum mvGroupCapsule::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->setParameteri(paramFlag, index);
}

mvErrorEnum mvGroupCapsule::setParametero(mvParamEnum paramFlag, mvOptionEnum option)
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->setParametero(paramFlag, option);
}
mvErrorEnum mvGroupCapsule::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->setParameterf(paramFlag, num);
}

mvErrorEnum mvGroupCapsule::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (encapsuledGroup == MV_NULL)
      return MV_ITEM_POINTER_IS_NULL;

   return encapsuledGroup->setParameterv(paramFlag, numArray);
}

mvGroupCapsule::~mvGroupCapsule()
{
   if (encapsuledGroup != MV_NULL)
   {
      delete encapsuledGroup;
      encapsuledGroup = MV_NULL;
   }
}
