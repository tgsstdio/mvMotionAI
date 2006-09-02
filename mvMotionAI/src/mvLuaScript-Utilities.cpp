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