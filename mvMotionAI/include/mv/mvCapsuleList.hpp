template<class mvClass>
mvConverter<mvClass>::mvConverter(mvClassFunction *func, void* itemPtr)
{
   someFunction = func;
   extraPtr = itemPtr;
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::mvCapsuleList()
{

}

template <class mvClass, class mvConstClass, class mvCapsulePtr,
   class mvConstCapsulePtr>
mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::~mvCapsuleList()
{

}

template <class mvClass, class mvConstClass, class mvCapsulePtr,
   class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setAutoConvertIndex(bool value)
{
   itemList.setAutoConvertIndex(value);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::addItem(\
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

   if (tempCapsule != MV_NULL)
   {
      return tempCapsule->getClassPtr();
   }
   else
   {
      return MV_NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentClassPtr() const
{
   mvCapsulePtr tempCapsule = itemList.getCurrentClassPtr();

   if (tempCapsule != MV_NULL)
   {
      return tempCapsule->getClassPtr();
   }
   else
   {
      return MV_NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentConstClassPtr()\
   const
{
   mvConstCapsulePtr tempCapsule = itemList.getCurrentConstClassPtr();

   if (tempCapsule != MV_NULL)
   {
      return tempCapsule->getConstClassPtr();
   }
   else
   {
      return MV_NULL;
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getConstClassPtr(\
   mvIndex index) const
{
   mvConstCapsulePtr tempCapsule = itemList.getConstClassPtr(index);

   if (tempCapsule != MV_NULL)
   {
      return tempCapsule->getConstClassPtr();
   }
   else
   {
      return MV_NULL;
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
   // TODO : check for errors
   applyToAllItemsByItemIndex(someFunction, extraPtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvClass mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findItemPtrInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#else
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#endif

   return itemList.findItemPtrInList(\
      CapsuledConverterFunction<mvClass,mvConstClass>, loopConversion);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvIndex mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::findItemInList(\
   bool (someFunction)(mvClass, void*), void* extraPtr) const
{
#if defined(VISUAL_C_VER_6) || defined(VISUAL_C_VER_8)
   typename mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#else
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#endif

   return itemList.findItemInList(\
      CapsuledConverterFunction<mvClass,mvConstClass>, loopConversion);
}

#ifdef VISUAL_C_VER_6
template <typename mvClass, typename mvCapsulePtr>
void CapsuledConverterFunction_VC6(mvCapsulePtr itemPtr, void* extraPtr)
{
   mvConverter<mvClass>* converter = (mvConverter<mvClass>*) extraPtr;

   if (itemPtr != MV_NULL && converter != MV_NULL)
   {
      converter->someFunction(itemPtr->getClassPtr(), converter->extraPtr);
   }
}
#endif

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllItems(\
   void (someFunction)(mvClass, void*), void* extraPtr)
{
#if defined VISUAL_C_VER_6
   // rewrite function - no argument passing of function template instance in VC6
   typename std::vector<mvCapsulePtr>::iterator i;
   typename std::vector<mvCapsulePtr>::iterator listEnd = itemList.listItems.end();
#elif defined VISUAL_C_VER_8
   typename mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#else
   class mvConverter<mvClass> loopConversion(someFunction, extraPtr);
#endif

#ifdef VISUAL_C_VER_6
   mvCapsulePtr tempClass = MV_NULL;

   for (i = itemList.listItems.begin(); i != listEnd; ++i)
   {
      tempClass = *i;

      if (tempClass != MV_NULL && tempClass->getClassPtr() != MV_NULL)
      {
         someFunction(tempClass->getClassPtr(),extraPtr);
      }
   }
#else
   itemList.applyToAllItems(CapsuledConverterFunction<mvClass,mvCapsulePtr>,&loopConversion);
#endif


}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
void mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::applyToAllItemsByIndex(\
   mvIndex worldIndex, void (someFunction)(mvIndex, mvIndex, void*),\
   void* extraPtr)
{
   itemList.applyToAllItemsByIndex(worldIndex, someFunction, extraPtr);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParametero(\
   mvIndex itemIndex, mvParamEnum paramFlag, mvOptionEnum option)
{
   return itemList.setItemParametero(itemIndex,paramFlag, option);
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
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParametero(\
   mvIndex itemIndex,mvParamEnum paramFlag, mvOptionEnum* option) const
{
   return itemList.getItemParametero(itemIndex, paramFlag, option);
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
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParametero_str(\
   mvIndex itemIndex, const char* param, const char* option)
{
   return itemList.setItemParametero_str(itemIndex, param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameteri_str(\
   mvIndex itemIndex, const char* param, mvIndex index)
{
   return itemList.setItemParameteri_str(itemIndex, param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameterf_str(\
   mvIndex itemIndex, const char* param, mvFloat num)
{
   return itemList.setItemParameterf_str(itemIndex, param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::setItemParameterv_str(\
   mvIndex itemIndex, const char* param, mvFloat* array)
{
   return itemList.setItemParameterv_str(itemIndex, param, array);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParametero_str(\
   mvIndex itemIndex, const char* param, const char** option) const
{
   return itemList.getItemParametero_str(itemIndex, param, option);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameteri_str(\
   mvIndex itemIndex, const char* param, mvIndex* index) const
{
   return itemList.getItemParameteri_str(itemIndex, param, index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameterf_str(\
   mvIndex itemIndex, const char* param, mvFloat* num) const
{
   return itemList.getItemParameterf_str(itemIndex, param, num);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvErrorEnum mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getItemParameterv_str(\
   mvIndex itemIndex, const char* param, mvFloat* array,\
   mvCount* noOfParameters) const
{
   return itemList.getItemParameterv_str(itemIndex, param, array, noOfParameters);
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

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCapsulePtr mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCapsulePtr(mvIndex index) const
{
   return itemList.getClassPtr(index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvCapsulePtr mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentCapsulePtr() const
{
   return itemList.getCurrentClassPtr();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstCapsulePtr mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getCurrentConstCapsulePtr() const
{
   return itemList.getCurrentConstClassPtr();
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
mvConstCapsulePtr mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getConstCapsulePtr(mvIndex index) const
{
   return itemList.getConstClassPtr(index);
}

template <class mvClass, class mvConstClass, class mvCapsulePtr, class mvConstCapsulePtr>
bool mvCapsuleList<mvClass,mvConstClass, mvCapsulePtr,mvConstCapsulePtr>::getAutoConvertFlag() const
{
   return itemList.getAutoConvertFlag();
}
