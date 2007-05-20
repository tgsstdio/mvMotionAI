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
#ifndef MV_VECTOR_LIST_H_
#define MV_VECTOR_LIST_H_

#include <vector>
#include MV_ENUMS_HEADER_FILE_H_
#include "mvMotionAI-Types.h"

//TODO : use negetive index as wrap around array index

template <class mvClass>
class mvItemList
{
   private:
      std::vector<mvClass*> listItems;
      mvCount maxNoOfItems;
      mvIndex currentIndex;
      bool autoConvertNegetiveIndex;
      mvErrorEnum checkIndex(mvIndex& i) const;
      mvErrorEnum checkParamStringAndIndex(mvIndex& i, const char* param,\
         mvParamEnum* paramFlag) const;

   public:
      mvItemList();
      ~mvItemList();
      void setAutoConvertIndex(bool value);
      mvErrorEnum addItem(mvClass* itemPtr);
      mvErrorEnum deleteItem(mvIndex index);
      mvErrorEnum deleteCurrentItem();
      void deleteAllItems();
      mvIndex convertIndex(mvIndex i) const;
      mvClass* getClassPtr(mvIndex index);
      mvClass* getCurrentClassPtr();
      mvCount getNoOfItems() const;
      mvIndex getCurrentIndex() const;
      mvIndex setCurrentIndex(mvIndex index);

      // TODO : implement this function
      void applyToAllItemsByItemIndex(void (someFunction)(mvIndex,void*),\
         void* extraPtr);

      mvClass* findItemPtrInList(bool (someFunction)(mvClass*, void*),\
         void* extraPtr);

      mvIndex findItemInList(bool (someFunction)(mvClass*, void*),\
         void* extraPtr);

      void applyToAllItems(void (someFunction)(mvClass*, void*),\
         void* extraPtr);
      void applyToAllItemsByIndex(mvIndex worldIndex,\
         void (someFunction)(mvIndex, mvIndex, void*), void* extraPtr);
      ~mvItemList();

      mvErrorEnum setItemParameter(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setItemParameteri(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setItemParameterf(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setItemParameterv(mvIndex itemIndex, mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getItemParameter(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getItemParameteri(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getItemParameterf(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getItemParameterv(mvIndex itemIndex,mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum setItemParameter_str(mvIndex itemIndex, const char* param,\
         const char* option);
      mvErrorEnum setItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex index);
      mvErrorEnum setItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat num);
      mvErrorEnum setItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array);

      mvErrorEnum getItemParameter_str(mvIndex itemIndex, const char* param,\
         const char** option);
      mvErrorEnum getItemParameteri_str(mvIndex itemIndex, const char* param,\
         mvIndex* index);
      mvErrorEnum getItemParameterf_str(mvIndex itemIndex, const char* param,\
         mvFloat* num);
      mvErrorEnum getItemParameterv_str(mvIndex itemIndex, const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum setCurrentItemParameter_str(const char* param,\
         const char* option);
      mvErrorEnum setCurrentItemParameteri_str(const char* param,\
         mvIndex index);
      mvErrorEnum setCurrentItemParameterf_str(const char* param,\
         mvFloat num);
      mvErrorEnum setCurrentItemParameterv_str(const char* param,\
         mvFloat* array);

      mvErrorEnum getCurrentItemParameter_str(const char* param,\
         const char** option);
      mvErrorEnum getCurrentItemParameteri_str(const char* param,\
         mvIndex* index);
      mvErrorEnum getCurrentItemParameterf_str(const char* param,\
         mvFloat* num);
      mvErrorEnum getCurrentItemParameterv_str(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum setCurrentItemParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentItemParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setCurrentItemParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentItemParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum getCurrentItemParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentItemParameteri(mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getCurrentItemParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentItemParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);
};

#ifndef MV_LIST_TEMPLATE_SOURCE_FILE
#define MV_LIST_TEMPLATE_SOURCE_FILE 1
// template functions need template implementation included
// with template declarations
#include "mvList.cpp"
#endif

#endif
