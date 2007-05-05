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

// TODO : rename all functions to pointerlist
template <class mvClass, class mvConstClass>
mvPointerList<mvClass,mvConstClass>::mvPointerList()
{
   maxNoOfItems = 0;
   currentIndex = MV_NO_CURRENT_INDEX;
   autoConvertNegetiveIndex = false;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::convertIndex(mvIndex i) const
{
   mvIndex convertedIndex = i + MV_OFFSET_TO_INDEX;

   if (convertedIndex < 0 || convertedIndex > maxNoOfItems)
   {
      convertedIndex = MV_NO_CURRENT_INDEX;
   }

   return convertedIndex;
}

template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::setAutoConvertIndex(bool value)
{
   autoConvertNegetiveIndex = value;
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::checkIndex(mvIndex& i) const
{
   mvIndex index = i + MV_OFFSET_TO_INDEX;

   if (index < 0 || index > maxNoOfItems)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   i = index;
   return MV_NO_ERROR;
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::checkParamStringAndIndex(\
   mvIndex& i, const char* param, mvParamEnum* paramFlag) const
{
   mvIndex index;

   if(!mvCheckAllParamEnumsForString(param, paramFlag))
   {
      return MV_INVALID_PARAM_ENUM_STRING;
   }

   index = i + MV_OFFSET_TO_INDEX;

   if (index < 0 || index > maxNoOfItems)
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
mvErrorEnum mvPointerList<mvClass,mvConstClass>::addItem(mvClass itemPtr)
{
   class std::vector<mvClass>::const_iterator i;
   mvClass currentItem = NULL;

   if (itemPtr == NULL)
      return MV_ITEM_POINTER_IS_NULL;

   for (i =listItems.begin(); i != listItems.end(); ++i)
   {
     currentItem = *i;
     if (currentItem != NULL && itemPtr == currentItem)
     {
         return MV_UNIQUE_ITEM_ALREADY_IN_LIST;
     }
   }

   listItems.push_back(itemPtr);
   ++maxNoOfItems;
   currentIndex = maxNoOfItems;

   return MV_NO_ERROR;
}

/**
 * \brief deletes item from list by index
 *
 * If rwmoved item has the same value as the current index
 * then the current index is set to MV_NO_CURRENT_INDEX or 0
 *
 * Code taken from mvMotionAI-Utilities.h, 2006
 * mvRemoveItemFromVectorByIndex
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::deleteItem(mvIndex index)
{
   mvClass tempClass = NULL;
   mvIndex listIndex = index;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   tempClass = listItems[listIndex];
   if (tempClass == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   delete tempClass;
   listItems[listIndex] = NULL;

   if (listIndex == currentIndex)
   {
      currentIndex = MV_NO_CURRENT_INDEX;
   }

   return MV_NO_ERROR;

}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::deleteCurrentItem()
{
   return deleteItem(currentIndex);
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
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
   mvClass temp = NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      temp = *i;
      if (temp != NULL)
      {
         delete temp;
         *i= NULL;
      }
   }
   listItems.clear();
   currentIndex = MV_NO_CURRENT_INDEX;
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
      return NULL;
   }

   return listItems[listIndex];
}

template <class mvClass, class mvConstClass>
mvClass mvPointerList<mvClass,mvConstClass>::getCurrentClassPtr() const
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return NULL;
   }

   return listItems[listIndex];
}

template <class mvClass, class mvConstClass>
mvCount mvPointerList<mvClass,mvConstClass>::getNoOfItems() const
{
   class std::vector<mvClass>::const_iterator i;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();
   mvCount totalItems = 0;
   mvClass temp = NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      temp = (mvClass) *i;
      if (temp != NULL)
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
 * to index else the new current index is  MV_NO_CURRENT_INDEX or 0
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
      currentIndex = MV_NO_CURRENT_INDEX;
   }

   return currentIndex;
}

/**
 * \brief apply a function, in the form of void someFunction(mvClass* itemPtr,
 * void* extraPtr), on all valid items in list
 *
 * Code taken from mvMotionAI-Utilities.h, 2006 function
 * mvApplyFunctionToAllItemsInListVector
 */
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItems(\
   void (someFunction)(mvClass, void*),void* extraPtr)
{
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
   mvClass tempClass = NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      tempClass = *i;

      if (tempClass != NULL)
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
 */
template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItemsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex, mvIndex, void*),\
   void* extraPtr)
{
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
   mvClass tempClass = NULL;
   mvIndex listIndex = MV_FIRST_POINTER_LIST_INDEX;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      tempClass = *i;

      if (tempClass != NULL)
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
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameter(\
   mvIndex itemIndex,  mvParamEnum paramFlag, mvOptionEnum option)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameter(paramFlag, option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameteri(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterv(paramFlag, array);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameter(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameter(paramFlag, option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameteri(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvIndex* index) const
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
   mvClass classPtr = NULL;

   if (error != MV_NO_ERROR)
   {
      return error;
   }

   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
 * mvErrorEnum mvSetClassParameters(std::vector<mvClass*>& mvClassList,
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParameters(\
   mvIndex itemIndex, const char* param, const char* option)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = NULL;

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
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameter(paramFlag,optionFlag);
}

/**
 * \brief set index parameter of the item in list according to C string
 * parameter and by the item's index
 *
 * Code taken from mvMotionAI-Utilities.h
 * template <class mvClass, class mvConstClass>
 * mvErrorEnum mvSetClassParametersi(std::vector<mvClass*>& mvClassList,
 * mvCount& noOfItems, mvIndex index, const char* paramFlag, mvIndex itemIndex)
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParametersi(\
   mvIndex itemIndex, const char* param, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameteri(paramFlag,index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParametersf(\
   mvIndex itemIndex, const char* param, mvFloat num)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterf(paramFlag,num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setItemParametersv(\
   mvIndex itemIndex, const char* param, mvFloat* array)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
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
 *mvErrorEnum mvGetClassParameters(std::vector<mvClass*>& mvClassList,
 *   mvCount& noOfItems, mvIndex index, const char* paramFlag,
 *   const char* optionFlag)
 */
template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParameters(\
   mvIndex itemIndex, const char* param, const char** option) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   error = classPtr->getParameter(paramFlag,&optionFlag);
   if(error == MV_NO_ERROR)
   {
      *option = mvGetOptionString(optionFlag);
   }
   else
   {
      // assume it's pointer based.
      *option = NULL;
   }

   return error;
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParametersi(\
   mvIndex itemIndex, const char* param, mvIndex* index) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameteri(paramFlag, index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParametersf(\
   mvIndex itemIndex, const char* param, mvFloat* num) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterf(paramFlag, num);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getItemParametersv(\
   mvIndex itemIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterv(paramFlag,array,noOfParameters);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParameters(\
   const char* param, const char* option)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = NULL;

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
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameter(paramFlag, optionFlag);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParametersi(\
   const char* param, mvIndex index)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameteri(paramFlag,index);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParametersf(\
   const char* param, mvFloat num)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterf(paramFlag,num);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParametersv(\
   const char* param, mvFloat* array)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterv(paramFlag,array);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParameters(\
   const char* param, const char** option) const
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   error = classPtr->getParameter(paramFlag,&optionFlag);
   if(error == MV_NO_ERROR)
   {
      *option = mvGetOptionString(optionFlag);
   }
   else
   {
      // assume it's pointer based.
      option = NULL;
   }
   return error;
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParametersi(\
   const char* param, mvIndex* index) const
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameteri(paramFlag,index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParametersf(\
   const char* param, mvFloat* num) const
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterf(paramFlag,num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParametersv(\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterv(paramFlag,array,noOfParameters);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParameter(\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameter(paramFlag,option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParameteri(\
   mvParamEnum paramFlag, mvIndex index)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameteri(paramFlag,index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParameterf(\
   mvParamEnum paramFlag, mvFloat num)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterf(paramFlag,num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::setCurrentItemParameterv(\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->setParameterv(paramFlag,array);
}


template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParameter(\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameter(paramFlag,option);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParameteri(\
   mvParamEnum paramFlag, mvIndex* index) const
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameteri(paramFlag,index);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParameterf(\
   mvParamEnum paramFlag, mvFloat* num) const
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterf(paramFlag,num);
}

template <class mvClass, class mvConstClass>
mvErrorEnum mvPointerList<mvClass,mvConstClass>::getCurrentItemParameterv(\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass classPtr = NULL;

   // check if index is valid
   if (error != MV_NO_ERROR)
   {
      return error;
   }

   // check if class at list index is not null
   classPtr = listItems[listIndex];
   if (classPtr == NULL)
   {
      return MV_ITEM_AT_INDEX_NO_LONGER_EXISTS;
   }

   return classPtr->getParameterv(paramFlag,array,noOfParameters);
}

template <class mvClass, class mvConstClass>
mvClass mvPointerList<mvClass,mvConstClass>::findItemPtrInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
   class std::vector<mvClass>::const_iterator i;
   mvClass currentPtr = NULL;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      currentPtr = *i;
      if (someFunction(currentPtr, extraPtr))
      {
         return currentPtr;
      }
   }
   // if failed
   return NULL;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::findItemInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
   class std::vector<mvClass>::const_iterator i;
   mvClass currentPtr = NULL;
   class std::vector<mvClass>::const_iterator listEnd = listItems.end();
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
   return MV_NO_CURRENT_INDEX;
}

template <class mvClass, class mvConstClass>
mvIndex mvPointerList<mvClass,mvConstClass>::findItemInReverseInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
   class std::vector<mvClass>::const_reverse_iterator i;
   mvClass currentPtr = NULL;
   class std::vector<mvClass>::const_reverse_iterator listEnd = listItems.rend();
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
   return MV_NO_CURRENT_INDEX;
}


template <class mvClass, class mvConstClass>
void mvPointerList<mvClass,mvConstClass>::applyToAllItemsByItemIndex(\
   void (someFunction)(mvIndex,void*), void* extraPtr)
{
   class std::vector<mvClass>::iterator i;
   class std::vector<mvClass>::iterator listEnd = listItems.end();
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
