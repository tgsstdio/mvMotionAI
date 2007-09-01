/**
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
 */
#ifndef MVPOINTERLIST_H_INCLUDED
#define MVPOINTERLIST_H_INCLUDED
#include <vector>
#include MV_ENUMS_HEADER_FILE_H_
#include "mvMotionAI-Types.h"

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

template <class mvClass, class mvConstClass>
class MV_GLOBAL_FUNC_PREFIX mvPointerList
{
   private:
      mvIndex currentIndex;
      mvCount maxNoOfItems;
      bool autoConverIndexFlag;
      mvIndex changeFromMvIndexToC(mvIndex i) const;
      bool isIndexValid(mvIndex index) const;
      mvErrorEnum checkIndex(mvIndex& i) const;
      mvErrorEnum checkParamStringAndIndex(mvIndex& i, const char* param,\
         mvParamEnum* paramFlag) const;

   public:
      std::vector<mvClass> listItems;
      mvPointerList();
      ~mvPointerList();
      void setAutoConvertIndex(bool value);
      mvIndex addItem(mvClass itemPtr);
      mvErrorEnum deleteItem(mvIndex index);
      void deleteAllItems();

      mvClass getClassPtr(mvIndex index) const;
      mvClass getCurrentClassPtr() const;
      mvConstClass getCurrentConstClassPtr() const;
      mvConstClass getConstClassPtr(mvIndex index) const;
      mvCount getNoOfItems() const;
      mvCount getNoOfMaxSlots() const;

      mvIndex convertIndex(mvIndex index) const;

      mvIndex getCurrentIndex() const;
      mvIndex setCurrentIndex(mvIndex index);

      void applyToAllItemsByItemIndex(void (someFunction)(mvIndex,void*),\
         void* extraPtr);

      mvClass findItemPtrInList(bool (someFunction)(mvClass, void*),\
         void* extraPtr) const;

      mvIndex findItemInList(bool (someFunction)(mvClass, void*),\
         void* extraPtr) const;

      mvIndex findItemInReverseInList(bool (someFunction)(mvClass, void*),\
         void* extraPtr) const;

      void applyToAllItems(void (someFunction)(mvClass, void*),\
         void* extraPtr);
      void applyToAllItemsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);

      mvErrorEnum setItemParameter(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setItemParameteri(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setItemParameterf(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setItemParameterv(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getItemParameter(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvOptionEnum* option) const;
      mvErrorEnum getItemParameteri(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvIndex* index) const;
      mvErrorEnum getItemParameterf(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* num) const;
      mvErrorEnum getItemParameterv(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters) const;

      mvErrorEnum setItemParameter_str(mvIndex itemIndex, const char* param,\
         const char* option);
      mvErrorEnum setItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array);

      mvErrorEnum getItemParameter_str(mvIndex itemIndex, const char* param,\
         const char** option) const;
      mvErrorEnum getItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex* index) const;
      mvErrorEnum getItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat* num) const;
      mvErrorEnum getItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array, mvCount* noOfParameters) const;

};

// template implementation
#include "mvPointerList.hpp"

#endif // MVPOINTERLIST_H_INCLUDED
