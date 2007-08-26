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
 */
#include "mvBaseAction.h"

mvBaseAction::mvBaseAction(mvOptionEnum type)
{
   bType = type;
}

mvOptionEnum mvBaseAction::getType() const
{
   return bType;
}

mvErrorEnum mvBaseAction::getParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_TYPE:
         *option = getType();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_BEHAVIOUR_PARAMETER;
   }
}

mvErrorEnum mvBaseAction::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfElements) const
{
   if (noOfElements == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfElements = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::setParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBaseAction::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvBaseAction::~mvBaseAction()
{
   // empty code
}

/**
 * \brief mvBaseActionLoader constructor
 */
mvBaseActionLoader::mvBaseActionLoader()
{
   // empty code
}
