#ifndef MVCAPSULELIST_H_INCLUDED
#define MVCAPSULELIST_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#ifdef MV_FILE_HEADER_TAG_
/**
 * \file mvCapsuleList.h
 *
 * Copyright (c) 2006 , 2007 David Young.
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
#endif

#include MV_ENUMS_HEADER_FILE_H_
#include "mvPointerList.h"

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

template<class mvClass>
class MV_GLOBAL_FUNC_PREFIX mvConverter
{
   public:
      typedef void mvClassFunction(mvClass,void*);

      void* extraPtr;
      mvClassFunction* someFunction;

      mvConverter(mvClassFunction* func, void* itemPtr);
};

template <class mvClass, class mvCapsulePtr>
void CapsuledConverterFunction(mvCapsulePtr itemPtr, void* extraPtr)
{
   mvConverter<mvClass>* converter = (mvConverter<mvClass>*) extraPtr;

   if (itemPtr != MV_NULL && converter != MV_NULL)
   {
      converter->someFunction(itemPtr->getClassPtr(), converter->extraPtr);
   }
}

template <class mvClass, class mvConstClass, class mvCapsulePtr,
   class mvConstCapsulePtr>
class MV_GLOBAL_FUNC_PREFIX mvCapsuleList
{
   public:
      mvPointerList<mvCapsulePtr,mvConstCapsulePtr> itemList;

      mvCapsuleList();
      ~mvCapsuleList();
      void setAutoConvertIndex(bool value);
      bool getAutoConvertFlag() const;
      mvIndex addItem(mvCapsulePtr capsulePtr);
      mvErrorEnum deleteItem(mvIndex index);
      //mvErrorEnum deleteCurrentItem();
      void deleteAllItems();

      mvIndex convertIndex(mvIndex i) const;

      mvClass getClassPtr(mvIndex index) const;
      mvClass getCurrentClassPtr() const;

      mvConstClass getCurrentConstClassPtr() const;
      mvConstClass getConstClassPtr(mvIndex index) const;

      mvCount getNoOfItems() const;
      mvIndex getCurrentIndex() const;
      mvIndex setCurrentIndex(mvIndex index);

      void applyToAllItemsByItemIndex(void (someFunction)(mvIndex,void*),\
         void* extraPtr);

      mvClass findItemPtrInList(bool (someFunction)(mvClass, void*),\
         void* extraPtr) const;

      mvIndex findItemInList(bool (someFunction)(mvClass, void*),\
         void* extraPtr) const;

      void applyToAllItems(void (someFunction)(mvClass, void*),\
         void* extraPtr);

      void applyToAllItemsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setItemParametero(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setItemParameteri(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setItemParameterf(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setItemParameterv(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getItemParametero(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getItemParameteri(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getItemParameterf(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getItemParameterv(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum setItemParametero_str(mvIndex itemIndex, const char* param,\
         const char* option);
      mvErrorEnum setItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array);

      mvErrorEnum getItemParametero_str(mvIndex itemIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvCapsulePtr getCapsulePtr(mvIndex index) const;
      mvCapsulePtr getCurrentCapsulePtr() const;

      mvConstCapsulePtr getCurrentConstCapsulePtr() const;
      mvConstCapsulePtr getConstCapsulePtr(mvIndex index) const;

      void applyToAllCapsules(void (someFunction)(mvCapsulePtr, void*),\
         void* extraPtr);
      mvCapsulePtr findItemPtrInList(bool (someFunction)(mvCapsulePtr, void*),\
         void* extraPtr) const;
      mvIndex findCapsuleInList(bool (someFunction)(mvCapsulePtr, void*),\
         void* extraPtr) const;
};

#include "mvCapsuleList.hpp"

#endif // MVCAPSULELIST_H_INCLUDED
