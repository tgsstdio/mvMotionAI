/**
 * \file mvLuaScript-Utilities.cpp
 *
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
 */

#include "mvLuaScript-Utilities.h"
#include <cstdlib>
#include <cstring>

int binarySearch(const char* key, char** array, int noOfItems)
{
   int mid = noOfItems / 2;
   int left = 0;
   int right = noOfItems - 1;
   int result = -1;
   int compare;
   int index;

   while (left < right)
   {
      index = mid;
      compare = strcmp(key,array[index]);
      if (compare == 0)
         return index;
      else if (compare < 0)
      {
         right = mid - 1;
      }
      else
      {
         left = mid + 1;
      }
   }
   return -1;
};

int iterativeSearch(const char* key, const char** array, int noOfItems)
{
   int i;

   for (i = 0; i < noOfItems; i++)
   {
      if (strcmp(key,array[i]) == 0)
      {
         return i;
      }
   }
   return -1;
};
