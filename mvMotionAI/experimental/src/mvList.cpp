template <class mvClass>
mvItemList<mvClass>::mvItemList()
{
   maxNoOfItems = 0;
   currentIndex = MV_NO_CURRENT_INDEX;
   autoConvertNegetiveIndex = false;
}

template <class mvClass>
mvIndex mvItemList<mvClass>::convertIndex(mvIndex i) const
{
   mvIndex convertedIndex = i + MV_OFFSET_TO_INDEX;

   if (convertedIndex < 0 || convertedIndex > maxNoOfItems)
   {
      convertedIndex = MV_NO_CURRENT_INDEX;
   }

   return convertedIndex;
}

template <class mvClass>
void mvItemList<mvClass>::setAutoConvertIndex(bool value)
{
   autoConvertNegetiveIndex = value;
}

template <class mvClass>
mvErrorEnum  mvItemList<mvClass>::checkIndex(mvIndex& i) const
{
   mvIndex index = i + MV_OFFSET_TO_INDEX;

   if (index < 0 || index > maxNoOfItems)
   {
      return MV_INDEX_VALUE_IS_INVALID;
   }

   i = index;
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::checkParamStringAndIndex(mvIndex& i,\
   const char* param, mvParamEnum* paramFlag) const

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
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::addItem(mvClass* itemPtr)
{
   class std::vector<mvClass*>::const_iterator i;
   const mvClass* currentItem = NULL;

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
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::deleteItem(mvIndex index)
{
   mvClass* tempClass = NULL;
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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::deleteCurrentItem()
{
   return deleteItem(currentIndex);
}

/**
 * \brief deletes item from list by index
 *
 * Code taken from mvMotionAI-Utilities.h, 2006
 * mvRemoveAllItemsFromVector
 */
template <class mvClass>
void mvItemList<mvClass>::deleteAllItems()
{
   class std::vector<mvClass*>::iterator i;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();
   mvClass* temp = NULL;

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

template <class mvClass>
mvClass* mvItemList<mvClass>::getClassPtr(mvIndex index)
{
   mvIndex listIndex = index;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return NULL;
   }

   return listItems[listIndex];
}

template <class mvClass>
mvClass* mvItemList<mvClass>::getCurrentClassPtr()
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);

   if (error != MV_NO_ERROR)
   {
      return NULL;
   }

   return listItems[listIndex];
}

template <class mvClass>
mvCount mvItemList<mvClass>::getNoOfItems() const
{
   class std::vector<mvClass*>::const_iterator i;
   class std::vector<mvClass*>::const_iterator listEnd = listItems.end();
   mvCount totalItems = 0;
   const mvClass* temp = NULL;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      temp = (mvClass*) *i;
      if (temp != NULL)
         ++totalItems;
   }

   return totalItems;
}

template <class mvClass>
mvIndex mvItemList<mvClass>::getCurrentIndex() const
{
   return currentIndex;
}

/**
 * \brief set the current index of the item list
 *
 * If index provided is valid, then current index is equal
 * to index else the new current index is  MV_NO_CURRENT_INDEX or 0
 */
template <class mvClass>
mvIndex mvItemList<mvClass>::setCurrentIndex(mvIndex index)
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
template <class mvClass>
void mvItemList<mvClass>::applyToAllItems(\
   void (someFunction)(mvClass*, void*),void* extraPtr)
{
   class std::vector<mvClass*>::iterator i;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();
   mvClass* tempClass = NULL;

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
template <class mvClass>
void mvItemList<mvClass>::applyToAllItemsByIndex(mvIndex worldIndex,\
   void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr)
{
   class std::vector<mvClass*>::iterator i;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();
   mvClass* tempClass = NULL;
   mvIndex listIndex = 1;

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
template <class mvClass>
mvItemList<mvClass>::~mvItemList()
{
   deleteAllItems();
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameter(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameteri(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameterf(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvFloat num)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameterv(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvFloat* array)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameter(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvOptionEnum* option)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameteri(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvIndex* index)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameterf(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvFloat* num)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameterv(mvIndex itemIndex,\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters)
{
   mvIndex listIndex = itemIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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
 * template <class mvClass>
 * mvErrorEnum mvSetClassParameter_str(std::vector<mvClass*>& mvClassList,
 */
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameter_str(mvIndex itemIndex,\
   const char* param, const char* option)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass* classPtr = NULL;

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
 * template <class mvClass>
 * mvErrorEnum mvSetClassParameteri_str(std::vector<mvClass*>& mvClassList,
 * mvCount& noOfItems, mvIndex index, const char* paramFlag, mvIndex itemIndex)
 */
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameteri_str(mvIndex itemIndex,\
   const char* param, mvIndex index)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameterf_str(mvIndex itemIndex,\
   const char* param, mvFloat num)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameterv_str(mvIndex itemIndex,\
   const char* param, mvFloat* array)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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
 *template <class mvClass>
 *mvErrorEnum mvGetClassParameter_str(std::vector<mvClass*>& mvClassList,
 *   mvCount& noOfItems, mvIndex index, const char* paramFlag,
 *   const char* optionFlag)
 */
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameter_str(mvIndex itemIndex,\
   const char* param, const char** option)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameteri_str(mvIndex itemIndex,\
   const char* param, mvIndex* index)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameterf_str(mvIndex itemIndex,\
   const char* param, mvFloat* num)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameterv_str(mvIndex itemIndex,\
   const char* param, mvFloat* array, mvCount* noOfParameters)
{
   mvIndex listIndex = itemIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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



template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameter_str(const char* param,\
   const char* option)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameteri_str(const char* param,\
   mvIndex index)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterf_str(const char* param,\
   mvFloat num)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterv_str(const char* param,\
   mvFloat* array)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameter_str(const char* param,\
   const char** option)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvOptionEnum optionFlag;
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameteri_str(const char* param,\
   mvIndex* index)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterf_str(const char* param,\
   mvFloat* num)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterv_str(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   mvIndex listIndex = currentIndex;
   mvParamEnum paramFlag;
   mvErrorEnum error = checkParamStringAndIndex(listIndex,param,&paramFlag);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameteri(\
   mvParamEnum paramFlag, mvIndex index)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   mvIndex listIndex = currentIndex;
   mvErrorEnum error = checkIndex(listIndex);
   mvClass* classPtr = NULL;

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

template <class mvClass>
mvClass* mvItemList<mvClass>::findItemPtrInList(bool (someFunction)(mvClass*, void*),\
   void* extraPtr)
{
   class std::vector<mvClass*>::iterator i;
   mvClass* currentPtr = NULL;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();

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

template <class mvClass>
mvIndex mvItemList<mvClass>::findItemInList(bool (someFunction)(mvClass*, void*),\
   void* extraPtr)
{
   class std::vector<mvClass*>::iterator i;
   mvClass* currentPtr = NULL;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();
   mvIndex count = 1;

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

template <class mvClass>
void mvItemList<mvClass>::applyToAllItemsByItemIndex(\
   void (someFunction)(mvIndex,void*), void* extraPtr)
{
   class std::vector<mvClass*>::iterator i;
   class std::vector<mvClass*>::iterator listEnd = listItems.end();
   mvIndex itemIndex = 1;

   for (i = listItems.begin(); i != listEnd; ++i)
   {
      someFunction(itemIndex, extraPtr);
      ++itemIndex;
   }
}
