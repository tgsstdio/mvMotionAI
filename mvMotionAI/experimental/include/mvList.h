#ifndef MV_VECTOR_LIST_H_
#define MV_VECTOR_LIST_H_

#include <vector>
#include "mvEnums.h"
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

   public:
      mvItemList();
      void setAutoConvertIndex(bool value);
      mvErrorEnum addItem(mvClass* itemPtr);
      mvErrorEnum deleteItem(mvIndex index);
      void deleteAllItems();

      mvErrorEnum setCurrentItemParameter(mvParamEnum paramFlag,\
         mvOptionEnum option);
      mvErrorEnum setCurrentItemParameteri(mvParamEnum paramFlag,\
         mvIndex index);
      mvErrorEnum setCurrentItemParameterf(mvParamEnum paramFlag,\
         mvFloat num);
      mvErrorEnum setCurrentItemParameterv(mvParamEnum paramFlag,\
         mvFloat* array);

      mvErrorEnum setItemParameters(const char* param,\
         const char* option);
      mvErrorEnum setItemParametersi(const char* param,\
         mvIndex index);
      mvErrorEnum setItemParametersf(const char* param,\
         mvFloat num);
      mvErrorEnum setItemParametersv(const char* param,\
         mvFloat* array);

      mvErrorEnum getItemParameters(const char* param,\
         const char* option);
      mvErrorEnum getItemParametersi(const char* param,\
         mvOptionEnum option);
      mvErrorEnum getItemParametersf(const char* param,\
         mvOptionEnum option);
      mvErrorEnum getItemParametersv(const char* param,\
         mvFloat* array, mvCount* noOfParameters);

      mvErrorEnum getCurrentItemParameter(mvParamEnum paramFlag,\
         mvOptionEnum* option);
      mvErrorEnum getCurrentItemParameteri(mvParamEnum paramFlag,\
         mvIndex* index);
      mvErrorEnum getCurrentItemParameterf(mvParamEnum paramFlag,\
         mvFloat* num);
      mvErrorEnum getCurrentItemParameterv(mvParamEnum paramFlag,\
         mvFloat* array, mvCount* noOfParameters);

      mvClass* getClassPtr(mvIndex index);
      mvCount getNoOfItems() const;
      mvIndex getCurrentIndex() const;
      mvIndex setCurrentIndex(mvIndex index);
      void applyToAllItems(void (someFunction)(mvClass*, void*),\
         void* extraPtr);
      void applyToAllItemsByIndex(void (someFunction)(mvIndex, void*),\
         void* extraPtr);
      ~mvItemList();
};



#endif
