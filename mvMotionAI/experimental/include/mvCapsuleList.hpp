template<class mvClass>
mvConverter<mvClass>::mvConverter(void (*func)(mvClass,void*), void* itemPtr)
{
   someFunction = func;
   extraPtr = itemPtr;
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::mvCapsuleList()
{
   //TODO : implement this function
}

template <class mvClass, class mvConstClass, class mvCapsulePtr,
   class mvConstCapsulePtr>
mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::~mvCapsuleList()
{
   //TODO : implement this function
}

template <class mvClass, class mvConstClass, class mvCapsulePtr,
   class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setAutoConvertIndex(bool value)
{
   itemList.setAutoConvertIndex(value);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::addItem(\
   mvCapsulePtr capsulePtr)
{
   return itemList.addItem(capsulePtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::deleteItem(mvIndex index)
{
   return itemList.deleteItem(index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::deleteCurrentItem()
{
   return itemList.deleteCurrentItem();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::deleteAllItems()
{
   itemList.deleteAllItems();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::convertIndex(mvIndex i) const
{
   return itemList.convertIndex(i);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getClassPtr(mvIndex index) const
{
   mvCapsulePtr tempCapsule = itemList.getClassPtr(index);

   if (tempCapsule != NULL)
   {
      return tempCapsule->getClassPtr();
   }
   else
   {
      return NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentClassPtr() const
{
   mvCapsulePtr tempCapsule = itemList.getCurrentClassPtr();

   if (tempCapsule != NULL)
   {
      return tempCapsule->getClassPtr();
   }
   else
   {
      return NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentConstClassPtr()\
   const
{
   const mvCapsulePtr tempCapsule = itemList.getCurrentConstClassPtr();

   if (tempCapsule != NULL)
   {
      return tempCapsule->getConstClassPtr();
   }
   else
   {
      return NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getConstClassPtr(\
   mvIndex index) const
{
   mvConstCapsulePtr tempCapsule = itemList.getConstClassPtr(index);

   if (tempCapsule != NULL)
   {
      return tempCapsule->getConstClassPtr();
   }
   else
   {
      return NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCount mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getNoOfItems() const
{
   return itemList.getNoOfItems();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentIndex() const
{
   return itemList.getCurrentIndex();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentIndex(mvIndex index)
{
   return itemList.setCurrentIndex(index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllItemsByItemIndex(\
   void (someFunction)(mvIndex,void*),  void* extraPtr)
{
   //TODO : implement this function
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findItemPtrInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);

   return itemList.findItemPtrInList(\
      CapsuledConverterFunction<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>, loopConversion);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findItemInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);

   return itemList.findItemInList(\
      CapsuledConverterFunction<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>, loopConversion);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllItems(\
   void (someFunction)(mvClass, void*), void* extraPtr)
{
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);

   itemList.applyToAllItems(CapsuledConverterFunction<mvClass,mvCapsulePtr>,&loopConversion);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllItemsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex, mvIndex, void*),\
   void* extraPtr)
{
   return itemList.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameter(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   return itemList.setItemParameter(itemIndex,paramFlag, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameteri(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvIndex index)
{
   return itemList.setItemParameteri(itemIndex, paramFlag, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameterf(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat num)
{
   return itemList.setItemParameterf(itemIndex, paramFlag, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameterv(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvFloat* array)
{
   return itemList.setItemParameterv(itemIndex, paramFlag, array);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameter(\
   mvIndex itemIndex,mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return itemList.getItemParameter(itemIndex, paramFlag, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameteri(\
   mvIndex itemIndex,mvParamEnum paramFlag, mvIndex* index) const
{
   return itemList.getItemParameteri(itemIndex, paramFlag, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameterf(\
   mvIndex itemIndex,mvParamEnum paramFlag, mvFloat* num) const
{
   return itemList.getItemParameterf(itemIndex, paramFlag, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameterv(\
   mvIndex itemIndex,mvParamEnum paramFlag, mvFloat* array,
   mvCount* noOfParameters) const
{
   return itemList.getItemParameterv(itemIndex, paramFlag, array,\
      noOfParameters);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameters(\
   mvIndex itemIndex, const char* param, const char* option)
{
   return itemList.setItemParameters(itemIndex, param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParametersi(\
   mvIndex itemIndex, const char* param, mvIndex index)
{
   return itemList.setItemParametersi(itemIndex, param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParametersf(\
   mvIndex itemIndex, const char* param, mvFloat num)
{
   return itemList.setItemParametersf(itemIndex, param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParametersv(\
   mvIndex itemIndex, const char* param, mvFloat* array)
{
   return itemList.setItemParametersv(itemIndex, param, array);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameters(\
   mvIndex itemIndex, const char* param, const char** option) const
{
   return itemList.getItemParameters(itemIndex, param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParametersi(\
   mvIndex itemIndex, const char* param, mvIndex* index) const
{
   return itemList.getItemParametersi(itemIndex, param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParametersf(\
   mvIndex itemIndex, const char* param, mvFloat* num) const
{
   return itemList.getItemParametersf(itemIndex, param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParametersv(\
   mvIndex itemIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   return itemList.getItemParametersv(itemIndex, param, array, noOfParameters);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParameters(\
   const char* param, const char* option)
{
   return itemList.setCurrentItemParameters(param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParametersi(\
   const char* param, mvIndex index)
{
   return itemList.setCurrentItemParametersi(param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParametersf(\
   const char* param, mvFloat num)
{
   return itemList.setCurrentItemParametersf(param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParametersv(\
   const char* param, mvFloat* array)
{
   return itemList.setCurrentItemParametersv(param, array);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParameters(\
   const char* param, const char** option) const
{
   return itemList.getCurrentItemParameters(param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParametersi(\
   const char* param, mvIndex* index) const
{
   return itemList.getCurrentItemParametersi(param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParametersf(\
   const char* param, mvFloat* num) const
{
   return itemList.getCurrentItemParametersf(param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParametersv(\
   const char* param, mvFloat* array, mvCount* noOfParameters) const
{
   return itemList.getCurrentItemParametersv(param, array, noOfParameters);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParameter(\
   mvParamEnum paramFlag, mvOptionEnum option)
{
   return itemList.setCurrentItemParameter(paramFlag, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParameteri(\
   mvParamEnum paramFlag, mvIndex index)
{
   return itemList.setCurrentItemParameteri(paramFlag, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParameterf(\
   mvParamEnum paramFlag, mvFloat num)
{
   return itemList.setCurrentItemParameterf(paramFlag, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setCurrentItemParameterv(\
   mvParamEnum paramFlag, mvFloat* array)
{
   return itemList.setCurrentItemParameterv(paramFlag, array);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParameter(\
   mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return itemList.getCurrentItemParameter(paramFlag, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParameteri(\
   mvParamEnum paramFlag, mvIndex* index) const
{
   return itemList.getCurrentItemParameteri(paramFlag, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParameterf(\
   mvParamEnum paramFlag, mvFloat* num) const
{
   return itemList.getCurrentItemParameterf(paramFlag, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentItemParameterv(\
   mvParamEnum paramFlag, mvFloat* array, mvCount* noOfParameters) const
{
   return itemList.getCurrentItemParameterv(paramFlag, array, noOfParameters);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllCapsules(\
   void (someFunction)(mvCapsulePtr, void*),void* extraPtr)
{
   itemList.applyToAllItems(someFunction, extraPtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCapsulePtr mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findItemPtrInList(\
   bool (someFunction)(mvCapsulePtr, void*),void* extraPtr) const
{
   return itemList.findItemPtrInList(someFunction,extraPtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findCapsuleInList(\
   bool (someFunction)(mvCapsulePtr, void*),void* extraPtr) const
{
   return itemList.findIteminList(someFunction,extraPtr);
}
