/**
 * \file TEMPLATE IMPLEMENTATION of mvPointerList.h
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
 *  using HPP file or template implementation
 */

#define MV_FIRST_POINTER_LIST_INDEX 1

/**
 * \brief offset value to index value in mvMotionAI
 *
 * first item in list is 1, last item is n
 * (unlike C, where first item is 0 and last item is n - 1 )
 */
static const mvIndex MV_OFFSET_TO_INDEX = -1;

template <class mvClass, class mvConstClass>
mvPointerList<mvClass,mvConstClass>::mvPointerList()
{
   maxNoOfItems = 0;
   currentIndex = MV_NULL;
   autoConverIndexFlag = false;
}

/**
 *  Auto convert index :
 *  when out of range indexes are passed to this list
 *  if true :
 *    they converted into either a positive index or MV_NULL.
 *  if false
 *    they will remain unusable until list is occupied with enough items.
 *  Also when negetive indexes are applied i.e. (-1 or the last item added)
 *  if true:
 *  classes and items will store the index value of the last item added AT THE
 *    TIME when it was called.
 *  if false:
 *  classes and items will store and retrieve the last item added in the list
 *    for the entire life of the system.
 */
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::setAutoConvertIndex(bool value)
{
   autoConverIndexFlag = value;
}

/**
 * \brief private function - C array bounds checking
 */
template <class mvClass, class mvConstClass>
bool mvPointerList<mvClass,mvConstClass>::isIndexValid(mvIndex index) const
{
   return (index < 0 || index > maxNoOfItems);
}

/**
 * \brief public function - negetive/positive mvIndex
 * to positive/invalid mvIndex
 */
template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::convertIndex(mvIndex index) const
{
   mvIndex finalIndex;

   // negetive index
   if (autoConverIndexFlag)
   {
      if (index < 0)
      {
         finalIndex = changeFromMvIndexToC(index);
         if (isIndexValid(finalIndex))
         {
            return MV_NULL;
         }

         // TODO : check for error
         finalIndex -= MV_OFFSET_TO_INDEX;
         return finalIndex;
      }
      else
      {
         // positive index
         finalIndex = changeFromMvIndexToC(index);
         if (isIndexValid(finalIndex))
         {
            return MV_NULL;
         }
         else
         {
            return index;
         }
      }
   }
   else
   {
      // no change
      return index;
   }
}

/**
 * \brief private function - positive mvIndex to C array
 */
template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::changeFromMvIndexToC(mvIndex i) const
{
   // not really need
   mvIndex convertedIndex;

   if (i < 0)
   {
      convertedIndex = maxNoOfItems;
      convertedIndex += i;
   }
   else
   {
      convertedIndex = i + MV_OFFSET_TO_INDEX;
   }

   return convertedIndex;
}

/**
 * \brief private function
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::checkIndex(mvIndex& i) const
{
   // conversion function
   mvIndex index = changeFromMvIndexToC(i);

   if (isIndexValid(index))
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   i = index;
   return MV_NO_ERROR;
}

/**
 * \brief private function
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::checkParamStringAndIndex(\
   mvIndex& i, const char* param, mvParamEnum* paramFlag) const
{
   mvIndex index;

   if (param == MV_NULL)
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   if(!mvCheckAllParamEnumsForString(param, paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   index = changeFromMvIndexToC(i);

   if (isIndexValid(index))
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   i = index;
   return MV_NO_ERROR;
}

/**
 * \brief add unique mvClass pointer to the list
 *
 * All newly inserted items are now pointed by the current index
 * Code taken from mvAddUniqueItemInVector in mvMotionAI-Utilities.h , 2006
 */
template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::addItem(mvClass itemPtr)
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::iterator i;
   typename std::vector<mvClass>::iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
#endif
   mvClass currentItem = MV_NULL;

   if (itemPtr == MV_NULL)
   {
      //return MV_ITEM_POINTER_IS_NULL;
      return MV_NULL;
   }

   for (i = listItems.begin(); i != listEnd; ++i)
   {
     currentItem = *i;
     if (itemPtr == currentItem)
     {
         //return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
         return MV_NULL;

     }
   }

   listItems.push_back(itemPtr);
   ++maxNoOfItems;
   currentIndex = maxNoOfItems;

   return currentIndex;
}

/**
 * \brief deletes item from list by index
 *
 * If rwmoved item has the same value as the current index
 * then the current index is set to MV_NULL or 0
 *
 * Code taken from mvMotionAI-Utilities.h, 2006
 * mvRemoveItemFromVectorByIndex
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::deleteItem(mvIndex index)
{
   mvClass tempClass = MV_NULL;
   mvIndex listIndex = index;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   tempClass = listItems[listIndex];
   if (tempClass == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   delete tempClass;
   listItems[listIndex] = MV_NULL;

   if (listIndex == currentIndex)
   {
      currentIndex = MV_NULL;
   }

   return MV_NO_ERROR;

}

/**
 * \brief deletes item from list by index
 *
 * Code taken from mvMotionAI-Utilities.h, 2006
 * mvRemoveAllItemsFromVector
 */
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::deleteAllItems()
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::iterator i;
   typename std::vector<mvClass>::iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
#endif
   mvClass temp = MV_NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      temp = *i;
      if (temp != MV_NULL)
      {
         delete temp;
         *i= MV_NULL;
      }
   }
   listItems.clear();
   currentIndex = MV_NULL;
   maxNoOfItems = 0;
}

template <class mvClass, class mvConstClass>
mvConstClass mvPointerList<mvClass,mvConstClass>::getCurrentConstClassPtr()\
   const
{
   return (mvConstClass) getCurrentClassPtr();
}

template <class mvClass, class mvConstClass>
mvConstClass mvPointerList<mvClass,mvConstClass>::getConstClassPtr(\
   mvIndex index) const
{
   return (mvConstClass) getClassPtr(index);
}

template <class mvClass, class mvConstClass>
mvClass mvPointerList<mvClass,mvConstClass>::getClassPtr(mvIndex index) const
{
   mvIndex listIndex = index;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return MV_NULL;
   }

   return listItems[listIndex];
}

template <class mvClass, class mvConstClass>
mvClass mvPointerList<mvClass,mvConstClass>::getCurrentClassPtr() const
{
   return getClassPtr(currentIndex);
}

template <class mvClass, class mvConstClass>
mvCount mvPointerList<mvClass,mvConstClass>::getNoOfItems() const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::const_iterator i;
   typename std::vector<mvClass>::const_iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::const_iterator i;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();
#endif

   mvCount totalItems = 0;
   mvClass temp = MV_NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      temp = (mvClass) *i;
      if (temp != MV_NULL)
         ++totalItems;
   }

   return totalItems;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::getCurrentIndex() const
{
   return currentIndex;
}

/**
 * \brief set the current index of the item list
 *
 * If index provided is valid, then current index is equal
 * to index else the new current index is  MV_NULL or 0
 */
template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::setCurrentIndex(mvIndex index)
{
   mvIndex listIndex = index;
   mvErrorEnum error = checkIndex(listIndex);

   if (error == MV_NO_ERROR)
   {
      currentIndex = listIndex;
   }
   else
   {
      currentIndex = MV_NULL;
   }

   return currentIndex;
}

/**
 * \brief apply a function, in the form of void someFunction(mvClass* itemPtr,
 * void* extraPtr), on all valid items in list
 *
 * Code taken from mvMotionAI-Utilities.h, 2006 function
 * mvApplyFunctionToAllItemsInListVector
 *
 * NOTE : empty slots (NULL) are ignored
*/
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItems(\
   void (someFunction)(mvClass, void*),void* extraPtr)
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::iterator i;
   typename std::vector<mvClass>::iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
#endif

   mvClass tempClass = MV_NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      tempClass = *i;

      if (tempClass != MV_NULL)
      {
         someFunction(tempClass,extraPtr);
      }
   }
}

/**
 * \brief apply a function in the form
 * void someFunction(mvIndex worldIndex, mvIndex itemIndex, void* extraPtr),
 * on all valid items in list
 *
 * someFunction's function signature is the same format as the C header
 * interface
 *
 * NOTE : empty slots (NULL) are ignored
 */
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItemsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex, mvIndex, void*),\
   void* extraPtr)
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::iterator i;
   typename std::vector<mvClass>::iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
#endif
   mvClass tempClass = MV_NULL;
   mvIndex listIndex = MV_FIRST_POINTER_LIST_INDEX;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      tempClass = *i;

      if (tempClass != MV_NULL)
      {
         someFunction(worldIndex, listIndex, extraPtr);
      }

      ++listIndex;
   }
}

/**
 * \brief frees list and the memory of dynamically allocated items
 * pointers held in this list
 */
template <class mvClass, class mvConstClass>
mvPointerList<mvClass,mvConstClass>::~mvPointerList()
{
   deleteAllItems();
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParametero(\
   mvIndex itemIndex,  mvParamEnum paramFlag, mvOptionEnum option)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParametero(paramFlag, option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameteri(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameteri(paramFlag, index);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameterf(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat num)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterf(paramFlag, num);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameterv(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat* array)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterv(paramFlag, array);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParametero(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParametero(paramFlag, option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameteri(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvIndex* index) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameteri(paramFlag, index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameterf(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat* num) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterf(paramFlag, num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameterv(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = MV_NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterv(paramFlag, array, noOfParameters);
}

/**
 * \brief set state parameter according to C string parameters
 *
 * Code taken from mvMotionAI-Utilities.h
 * template <class mvClass, class mvConstClass>
 * mvErrorEnum mvSetClassParametero_str(std::vector<mvClass*>& mvClassList,
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParametero_str(\
   mvIndex itemIndex, const char* param, const char* option)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // search for parameter string in mvEnums
   if(!mvCheckAllOptionEnumsForString(option,&optionFlag))
   {
      return MV_INVALID_OPTION_ENUM_STRING;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParametero(paramFlag,optionFlag);
}

/**
 * \brief set index parameter of the item in list according to C string
 * parameter and by the item's index
 *
 * Code taken from mvMotionAI-Utilities.h
 * template <class mvClass, class mvConstClass>
 * mvErrorEnum mvSetClassParameteri_str(std::vector<mvClass*>& mvClassList,
 * mvCount& noOfItems, mvIndex index, const char* paramFlag, mvIndex itemIndex)
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameteri_str(\
   mvIndex itemIndex, const char* param, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameteri(paramFlag,index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameterf_str(\
   mvIndex itemIndex, const char* param, mvFloat num)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterf(paramFlag,num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameterv_str(\
   mvIndex itemIndex, const char* param, mvFloat* array)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterv(paramFlag,array);
}

/**
 * \brief retrieve the state parameters of the item via C string & item index
 *
 *Code taken from mvMotionAI-Utilities.h, 2006
 *template <class mvClass, class mvConstClass>
 *mvErrorEnum mvGetClassParametero_str(std::vector<mvClass*>& mvClassList,
 *   mvCount& noOfItems, mvIndex index, const char* paramFlag,
 *   const char* optionFlag)
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParametero_str(\
   mvIndex itemIndex, const char* param, const char** option) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   error = classPtr->getParametero(paramFlag,&optionFlag);
   if(error == MV_NO_ERROR)
   {
      *option = mvGetOptionString(optionFlag);
   }
   else
   {
      // assume it's pointer based.
      *option = MV_NULL;
   }

   return error;
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameteri_str(\
   mvIndex itemIndex, const char* param, mvIndex* index) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameteri(paramFlag, index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameterf_str(\
   mvIndex itemIndex, const char* param, mvFloat* num) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterf(paramFlag, num);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameterv_str(\
   mvIndex itemIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = MV_NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == MV_NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterv(paramFlag,array,noOfParameters);
}

template <class mvClass, class mvConstClass>
mvClass mvPointerList<mvClass,mvConstClass>::findItemPtrInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::const_iterator i;
   typename std::vector<mvClass>::const_iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::const_iterator i;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();
#endif

   mvClass currentPtr = MV_NULL;


   for (i = listItems.begin(); i != listEnd; ++i)
   {
      currentPtr = *i;
      if (someFunction(currentPtr, extraPtr))
      {
         return currentPtr;
      }
   }
   // if failed
   return MV_NULL;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::findItemInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::const_iterator i;
   typename std::vector<mvClass>::const_iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::const_iterator i;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();
#endif

   mvClass currentPtr = MV_NULL;

   mvIndex count = MV_FIRST_POINTER_LIST_INDEX;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      currentPtr = *i;
      // if true
      if (someFunction(currentPtr, extraPtr))
      {
         return count;
      }
      ++count;
   }
   // if failed
   return MV_NULL;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::findItemInReverseInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::const_reverse_iterator i;
   typename std::vector<mvClass>::const_reverse_iterator listEnd = listItems.rend();
#else
   class std::vector<mvClass>::const_reverse_iterator i;
   class std::vector<mvClass>::const_reverse_iterator listEnd = listItems.rend();
#endif

   mvClass currentPtr = MV_NULL;

   mvIndex count = maxNoOfItems;

   for (i = listItems.rbegin(); i != listEnd; ++i)
   {
      currentPtr = *i;
      // if true
      if (someFunction(currentPtr, extraPtr))
      {
         return count;
      }
      ++count;
   }
   // if failed
   return MV_NULL;
}

/*
* \brief : empty slots (NULL) are ignored
*/
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItemsByItemIndex(\
   void (someFunction)(mvIndex,void*), void* extraPtr)
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename std::vector<mvClass>::iterator i;
   typename std::vector<mvClass>::iterator listEnd = listItems.end();
#else
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
#endif

   mvIndex itemIndex = MV_FIRST_POINTER_LIST_INDEX;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      someFunction(itemIndex, extraPtr);
      ++itemIndex;
   }
}

template <class mvClass, class mvConstClass>
mvCount mvPointerList<mvClass,mvConstClass>::getNoOfMaxSlots() const
{
   return maxNoOfItems;
}
