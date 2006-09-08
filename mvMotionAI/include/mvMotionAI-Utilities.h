#ifndef MV_MOTIONAI_UTILITIES_H_
#define MV_MOTIONAI_UTILITIES_H_
#include <vector>
#include "mvEnum.h"
#include "mvMotionAI-Types.h"
#include <cmath>

/**
 * Log        Date      Comments
 *
 *00-01-00  22/05/06    - Headers file : Template functions are hard to split
 *
 */

//static const mvIndex MV_OFFSET_TO_INDEX = -1;

template<class mvClass> mvEnum removeItemFromVectorByIndex(std::vector<mvClass*>& mvClassList, mvIndex index, int& currentIndex, int& noOfItems)
{
  mvClass* tempClass = NULL;
  mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

  if (classIndex >= 0 && classIndex < noOfItems)
  {
    tempClass = mvClassList[classIndex];
    if (tempClass != NULL)
    {
       delete tempClass;
       mvClassList[classIndex] = NULL;
       if (classIndex == currentIndex)
       {
         currentIndex = MV_NO_CURRENT_INDEX;
       }
       //--noOfItems;
       return MV_TRUE;
    }
  }
  return MV_FALSE;
};
/**
template<class mvClass>
mvEnum removeCurrentItemFromList(std::vector<mvClass*>& mvClassList, mvIndex& currentIndex, mvCount& noOfItems)
{
  mvClass* tempClass = NULL;

  if (currentIndex != MV_NO_CURRENT_INDEX)
  {
     tempClass = mvClassList[currentIndex];
     if (tempClass != NULL)
     {
        delete tempClass;
        mvClassList[currentIndex] = NULL;
        --noOfItems;
        return MV_TRUE;
     }
  }
  return MV_FALSE;
};
**/

template<class mvClass> mvClass* mvGetClassPtr(std::vector<mvClass*>& mvClassList, mvIndex index, mvCount& noOfItems)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      return mvClassList[classIndex];
   }
   else
   {
      return NULL;
   }
};

template<class mvClass> mvEnum mvSetClassParameterByIndex(std::vector<mvClass*>& mvClassList, mvIndex index, mvCount& noOfItems, mvEnum paramFlag, mvEnum option)
{
   mvClass* tempClass = NULL;
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_FALSE;

      return tempClass->setParameter(paramFlag,option);
   }
   else
   {
      return MV_FALSE;
   }
};

template<class mvClass> void mvRemoveAllClassObjectsFromList(std::vector<mvClass*>& mvClassList, mvIndex& currentIndex, mvCount& noOfItems)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* temp = NULL;

   for (i = mvClassList.begin(); i != mvClassList.end(); ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         delete temp;
         *i= NULL;
      }
   }
   currentIndex = MV_NO_CURRENT_INDEX;
   noOfItems = 0;
};

template<class mvClass> mvEnum mvSetClassParameterf(std::vector<mvClass*>& mvClassList, mvCount& noOfItems, mvIndex index, mvEnum paramFlag, float num)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_FALSE;

      return tempClass->setParameterf(paramFlag,num);
   }
   else
   {
      return MV_FALSE;
   }
};

template<class mvClass> mvEnum mvSetClassParameterv(std::vector<mvClass*>& mvClassList, mvCount& noOfItems,mvIndex index, mvEnum paramFlag, float* array)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_FALSE;

      return tempClass->setParameterv(paramFlag,array);
   }
   else
   {
      return MV_FALSE;
   }
};

template<class mvClass> mvIndex mvSetCurrentIndexOfClassList(std::vector<mvClass*>& mvClassList, mvIndex index, mvIndex& currentIndex, mvCount& noOfItems)
{
  mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

  if (classIndex >= 0 && classIndex < noOfItems)
  {
     if (mvClassList[classIndex] == NULL)
     {
        classIndex = MV_NO_CURRENT_INDEX;
        return MV_FALSE;
     }
     else
     {
        currentIndex = index;
        return currentIndex;
     }
  }
  else
  {
     currentIndex = MV_NO_CURRENT_INDEX;
     return MV_FALSE;
  }
};

template <class mvClass>
void mvApplyFunctionToAllItemsInListVector(std::vector<mvClass*>& mvClassList,void (someFunction)(mvClass*, void*), void* extraPtr)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* tempClass = NULL;

   for (i = mvClassList.begin(); i != mvClassList.end(); ++i)
   {
      tempClass = *i;
      if (tempClass != NULL)
      {
         someFunction(tempClass,extraPtr);
      }
   }
};

template<class mvClass>
mvEnum mvAddUniqueItemInVector(std::vector<mvClass*>& itemVector, mvClass* itemPtr, mvCount& noOfItems)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* currentItem = NULL;

   if (itemPtr == NULL)
     return MV_FALSE;

   for (i = itemVector.begin(); i != itemVector.end(); ++i)
   {
     currentItem = *i;
     if (currentItem != NULL)
        if (itemPtr == currentItem)
           return MV_FALSE;
   }
   itemVector.push_back(itemPtr);
   ++noOfItems;
   return MV_TRUE;
};

template<class mvClass>
mvEnum mvRemoveUniqueItemInVector(std::vector<mvClass*>& itemVector, mvClass* itemPtr, mvCount& noOfItems)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* currentItem = NULL;

   if (itemPtr != NULL && noOfItems <= 0)
      return MV_FALSE;

   for (i = itemVector.begin(); i != itemVector.end(); ++i)
   {
     currentItem = *i;
     if (currentItem != NULL)
        if (itemPtr == currentItem)
        {
           *i = NULL;
          // --noOfItems;
           itemVector.erase(i);
           return MV_TRUE;
        }
   }
   return MV_FALSE;
};

/**
 * Code taken from OpenSteer Utilities.h (2002-2004)
 * on the 20/06/2006
 * ----------------------------------------------------------------------------
 * Functions to encapsulate cross-platform differences for several <cmath>
 * functions.  Specifically, the C++ standard says that these functions are
 * in the std namespace (std::sqrt, etc.)  Apparently the MS VC6 compiler (or
 * its header files) do not implement this correctly and the function names
 * are in the global namespace.  We hope these -XXX versions are a temporary
 * expedient, to be removed later.
 */

#ifdef _WIN32
inline float mvFloor (mvFloat x)          {return floor (x);}
inline float mvSqrt (mvFloat x)           {return sqrt (x);}
inline float mvSin (mvFloat x)          {return sin (x);}
inline float mvCos (mvFloat x)           {return cos (x);}
//inline float mvAbs (mvFloat x)           {return abs (x);}
inline int   mvAbs (int x)            {return abs (x);}
inline float mvMax (mvFloat x, mvFloat y) {if (x > y) return x; else return y;}
inline float mvMin (mvFloat x, mvFloat y) {if (x < y) return x; else return y;}

#else
inline float mvFloor (mvFloat x)         {return std::floor (x);}
inline float mvSqrt (mvFloat x)           {return std::sqrt (x);}
inline float mvSin (mvFloat x)         {return std::sin (x);}
inline float mvCos (mvFloat x)          {return std::cos (x);}
inline float mvAbs (mvFloat x)          {return std::abs (x);}
inline int   mvAbs (int x)            {return std::abs (x);}
inline float mvMax (mvFloat x, mvFloat y) {return std::max (x, y);}
inline float mvMin (mvFloat x, mvFloat y) {return std::min (x, y);}
#endif

#endif
