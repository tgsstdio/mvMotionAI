/**
 * \file mvBehaviour-Type.h
 * Copyright (c) 2006 David Young.
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

#ifndef MV_BEHAVIOUR_TYPE_INIT_H_
#define MV_BEHAVIOUR_TYPE_INIT_H_
#include "mvEnums.h"
#include "mvVec3.h"
#include "mvMotionAI-Types.h"

mvCount mvBehaviour_GetIndexesArraySize(mvOptionEnum type);
mvErrorEnum mvBehaviour_InitialiseType(mvOptionEnum type, mvOptionEnum& bType, mvIndex* indexes,
                                  mvFloat* variables, mvOptionEnum* states, mvVec3* points);

template<class mvType>
mvErrorEnum mvBehaviour_CopyArrayContents(mvType* dstArray, mvType* srcArray, mvCount noOfElements)
{
   mvIndex i;

   if (dstArray == NULL)
   {
      return MV_DST_ARRAY_IS_NULL;
   }

   if (srcArray == NULL)
   {
      return MV_SRC_ARRAY_IS_NULL;
   }

   for (i = 0; i < noOfElements; ++i)
   {
         dstArray[i] = srcArray[i];
   }
   return MV_NO_ERROR;
}

mvCount mvBehaviour_GetPointsArraySize(mvOptionEnum type);
mvCount mvBehaviour_GetVariablesArraySize(mvOptionEnum type);
mvCount mvBehaviour_GetStateArraySize(mvOptionEnum type);

mvOptionEnum selectBodyToGroupEntryType(mvOptionEnum type);
mvOptionEnum selectGroupToBodyEntryType(mvOptionEnum type);
#endif



