#include "mvList.h"

template <class mvClass>
mvItemList<mvClass>::mvItemList()
{
   maxNoOfItems = 0;
   currentIndex = MV_NO_CURRENT_INDEX;
   autoConvertNegetiveIndex = false;
}

template <class mvClass>
void mvItemList<mvClass>::setAutoConvertIndex(bool value)
{
   autoConvertNegetiveIndex = value;
}

/**
 * \brief add unique mvClass pointer to the list
 *
 * Code taken from mvAddUniqueItemInVector in mvMotionAI-Utilities.h , 2006
 */
template <class mvClass>
mvErrorEnum mvItemList<mvClass>::addItem(mvClass* itemPtr)
{
   typename std::vector<mvClass*>::iterator i;
   mvClass* currentItem = NULL;

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

   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::deleteItem(mvIndex index)
{
   return MV_NO_ERROR;
}

template <class mvClass>
void mvItemList<mvClass>::deleteAllItems()
{

}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameter(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   return MV_NO_ERROR;
}


template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterf(mvParamEnum paramFlag,\
   mvFloat num)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setCurrentItemParameterv(mvParamEnum paramFlag,\
   mvFloat* array)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParameters(const char* param,\
   const char* option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParametersi(const char* param,\
   mvIndex index)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParametersf(const char* param,\
   mvFloat num)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::setItemParametersv(const char* param,\
   mvFloat* array)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParameters(const char* param,\
   const char* option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParametersi(const char* param,\
   mvOptionEnum option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParametersf(const char* param,\
   mvOptionEnum option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getItemParametersv(const char* param,\
   mvFloat* array, mvCount* noOfParameters)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameter(mvParamEnum paramFlag,\
   mvOptionEnum* option)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameteri(mvParamEnum paramFlag,\
   mvIndex* index)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterf(mvParamEnum paramFlag,\
   mvFloat* num)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvErrorEnum mvItemList<mvClass>::getCurrentItemParameterv(mvParamEnum paramFlag,\
   mvFloat* array, mvCount* noOfParameters)
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvClass* mvItemList<mvClass>::getClassPtr(mvIndex index)
{
   return NULL;
}

template <class mvClass>
mvCount mvItemList<mvClass>::getNoOfItems() const
{
   return MV_NO_ERROR;
}

template <class mvClass>
mvIndex mvItemList<mvClass>::getCurrentIndex() const
{
   return MV_NO_CURRENT_INDEX;
}

template <class mvClass>
void mvItemList<mvClass>::applyToAllItems(void (someFunction)(mvClass*, void*),\
   void* extraPtr)
{

}

template <class mvClass>
void mvItemList<mvClass>::applyToAllItemsByIndex(void (someFunction)(mvIndex, void*),\
   void* extraPtr)
{

}

template <class mvClass>
mvIndex mvItemList<mvClass>::setCurrentIndex(mvIndex index)
{

}

template <class mvClass>
mvItemList<mvClass>::~mvItemList()
{

}
