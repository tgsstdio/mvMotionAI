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
#include "mvEnum.h"
#include "mvVec3.h"
#include "mvMotionAI-Types.h"

mvCount mvBehaviour_GetIndexesArraySize(mvEnum type);
mvEnum mvBehaviour_InitialiseType(mvEnum type, mvEnum& bType, mvIndex* indexes,
                                  mvFloat* variables, mvEnum* states, mvVec3* points);

template<class mvType>
mvEnum mvBehaviour_CopyArrayContents(mvType* dstArray, mvType* srcArray, mvCount noOfElements)
{
   mvIndex i;

   if (dstArray != NULL && srcArray != NULL)
   {
      for (i = 0; i < noOfElements; ++i)
      {
         dstArray[i] = srcArray[i];
      }
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvCount mvBehaviour_GetPointsArraySize(mvEnum type);
mvCount mvBehaviour_GetVariablesArraySize(mvEnum type);
mvCount mvBehaviour_GetStateArraySize(mvEnum type);

mvEnum selectBodyToGroupEntryType(mvEnum type);
mvEnum selectGroupToBodyEntryType(mvEnum type);
#endif



