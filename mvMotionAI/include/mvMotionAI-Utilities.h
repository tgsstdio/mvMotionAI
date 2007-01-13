/**
 *\file mvMotionAI-Utilities.h
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
 * Log        Date      Comments
 *
 *00-01-21  22/11/06    - added arc cos/tan/tan to mvMotionAI-Utilities
 *
 *00-01-16  22/05/06    - edit functions to include new enumerations of mvEnums.h
 *
 *00-01-00  22/05/06    - Headers file : Template functions are hard to split
 *
 */
#ifndef MV_MOTIONAI_UTILITIES_H_
#define MV_MOTIONAI_UTILITIES_H_
#include <vector>
#include "mvEnums.h"
#include "mvMotionAI-Types.h"
#include <cmath>



template<class mvClass>
mvErrorEnum removeItemFromVectorByIndex(std::vector<mvClass*>& mvClassList, mvIndex index, int& currentIndex, int& noOfItems)
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
       return MV_NO_ERROR;
    }
    else
    {
       return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
    }
  }
  return MV_INDEX_VALUE_IS_INVALID;
}
/*
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
*/

template<class mvClass>
mvClass* mvGetClassPtr(std::vector<mvClass*>& mvClassList, mvIndex index, mvCount& noOfItems)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      return mvClassList.at(classIndex);
   }
   else
   {
      return NULL;
   }
}

template<class mvClass>
mvErrorEnum mvGetClassParameter(std::vector<mvClass*>& mvClassList, mvIndex index, mvCount& noOfItems, mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvClass* tempClass = NULL;
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      return tempClass->getParameter(paramFlag,option);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvErrorEnum mvSetClassParameter(std::vector<mvClass*>& mvClassList, mvIndex index, mvCount& noOfItems, mvParamEnum paramFlag, mvOptionEnum option)
{
   mvClass* tempClass = NULL;
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      return tempClass->setParameter(paramFlag,option);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
void mvRemoveAllClassObjectsFromList(std::vector<mvClass*>& mvClassList, mvIndex& currentIndex, mvCount& noOfItems)
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
}

template<class mvClass>
mvErrorEnum mvGetClassParameterf(std::vector<mvClass*>& mvClassList, mvCount& noOfItems, mvIndex index, mvParamEnum paramFlag, mvFloat* num)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;

      return tempClass->getParameterf(paramFlag,num);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvErrorEnum mvSetClassParameterf(std::vector<mvClass*>& mvClassList, mvCount& noOfItems, mvIndex index, mvParamEnum paramFlag, mvFloat num)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;

      return tempClass->setParameterf(paramFlag,num);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvErrorEnum mvGetClassParameterv(std::vector<mvClass*>& mvClassList, mvCount& noOfItems,
         mvIndex index, mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      return tempClass->getParameterv(paramFlag,array,noOfParameters);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvErrorEnum mvSetClassParameterv(std::vector<mvClass*>& mvClassList, mvCount& noOfItems,mvIndex index, mvParamEnum paramFlag, mvFloat* array)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      return tempClass->setParameterv(paramFlag,array);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvIndex mvSetCurrentIndexOfClassList(std::vector<mvClass*>& mvClassList, mvIndex index, mvIndex& currentIndex, mvCount& noOfItems)
{
     mvIndex classIndex = index + MV_OFFSET_TO_INDEX;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      if (mvClassList[classIndex] == NULL)
      {
        classIndex = MV_NO_CURRENT_INDEX;
        return MV_NO_CURRENT_INDEX;
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
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

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
}
/*
template <class mvClass>
void mvApplyFunctionToAllItemsInListVectorByIndex(std::vector<mvClass*>& mvClassList,void (someFunction)(mvIndex, void*), void* extraPtr)
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
*/

template<class mvClass>
mvErrorEnum mvAddUniqueItemInVector(std::vector<mvClass*>& itemVector, mvClass* itemPtr, mvCount& noOfItems)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* currentItem = NULL;

   if (itemPtr == NULL)
     return MV_ITEM_POINTER_IS_NULL;

   for (i = itemVector.begin(); i != itemVector.end(); ++i)
   {
     currentItem = *i;
     if (currentItem != NULL && itemPtr == currentItem)
     {
         return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
     }
   }
   itemVector.push_back(itemPtr);
   ++noOfItems;
   return MV_NO_ERROR;
}

template<class mvClass>
mvErrorEnum mvRemoveUniqueItemInVector(std::vector<mvClass*>& itemVector, mvClass* itemPtr, mvCount& noOfItems)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* currentItem = NULL;

   if (itemPtr != NULL)
      return MV_ITEM_POINTER_IS_NULL;

   if (noOfItems <= 0)
      return MV_ITEM_LIST_IS_EMPTY;

   for (i = itemVector.begin(); i != itemVector.end(); ++i)
   {
     currentItem = *i;
     if (currentItem != NULL)
        if (itemPtr == currentItem)
        {
           *i = NULL;
          // --noOfItems;
           itemVector.erase(i);
           return MV_NO_ERROR;
        }
   }
   return MV_ITEM_NOT_FOUND_IN_LIST;
}

template<class mvClass>
mvErrorEnum mvGetClassParameteri(std::vector<mvClass*>& mvClassList, mvCount& noOfItems, mvIndex index, mvParamEnum paramFlag, mvIndex* itemIndex)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;

      return tempClass->getParameteri(paramFlag,itemIndex);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template<class mvClass>
mvErrorEnum mvSetClassParameteri(std::vector<mvClass*>& mvClassList, mvCount& noOfItems, mvIndex index, mvParamEnum paramFlag, mvIndex itemIndex)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;

      return tempClass->setParameteri(paramFlag,itemIndex);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

//default get/set parameters
template <class mvClass>
mvErrorEnum mvSetClassParameters(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag,
   const char* optionFlag)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvOptionEnum option = MV_FALSE;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      if(!mvCheckAllOptionEnumsForString(optionFlag,&option))
      {
         return MV_INVALID_OPTION_ENUM_STRING;
      }

      return tempClass->setParameter(param,option);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvGetClassParameters(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag,
   const char* optionFlag)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvOptionEnum option = MV_FALSE;
   mvParamEnum param = MV_NO_PARAMETER;
   mvErrorEnum error = MV_NO_ERROR;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      error = tempClass->getParameter(param,&option);
      if(error == MV_NO_ERROR)
      {
         optionFlag = mvGetOptionString(option);
      }
      else
      {
         // assume it's pointer based.
         optionFlag = NULL;
      }

      return error;
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvSetClassParametersi(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvIndex itemIndex)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->setParameteri(param,itemIndex);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvGetClassParametersi(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvIndex* itemIndex)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->getParameteri(param,itemIndex);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvSetClassParametersf(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvFloat num)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->setParameterf(param,num);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvGetClassParametersf(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvFloat* num)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->getParameterf(param,num);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvSetClassParametersv(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvFloat* array)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->setParameterv(param,array);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

template <class mvClass>
mvErrorEnum mvGetClassParametersv(std::vector<mvClass*>& mvClassList,
   mvCount& noOfItems, mvIndex index, const char* paramFlag, mvFloat* array,
   mvCount* noOfParameters)
{
   mvIndex classIndex = index + MV_OFFSET_TO_INDEX;
   mvClass* tempClass = NULL;
   mvParamEnum param = MV_NO_PARAMETER;

   if (paramFlag == NULL)
   {
      return MV_INPUT_PARAM_STRING_IS_NULL;
   }

   if (classIndex >= 0 && classIndex < noOfItems)
   {
      tempClass = mvClassList[classIndex];
      if (tempClass == NULL)
      {
         return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
      }

      if(!mvCheckAllParamEnumsForString(paramFlag,&param))
      {
         return MV_INVALID_PARAM_ENUM_STRING;
      }

      return tempClass->getParameterv(param,array,noOfParameters);
   }
   else
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }
}

/*
 * Math functions
 */
inline mvFloat mvFloor (mvFloat x);
inline mvFloat mvSqrt (mvFloat x);
inline mvFloat mvSin (mvFloat x);
inline mvFloat mvCos (mvFloat x);
inline mvFloat mvAbs (mvFloat x);
//inline int   mvAbs (int x);
inline mvFloat mvMax (mvFloat x, mvFloat y);
inline mvFloat mvMin (mvFloat x, mvFloat y);

inline mvFloat mvArcCos(mvFloat theta);
inline mvFloat mvArcSin(mvFloat theta);
inline mvFloat mvArcTan(mvFloat theta);
inline mvFloat mvFMod(mvFloat num, mvFloat denom);
inline mvFloat mvModf(mvFloat x, mvFloat* intPart);

#endif
