#ifndef MV_VECTOR_LIST_H_
#define MV_VECTOR_LIST_H_

#include <vector>
#include "mvEnums.h"
#include "mvMotionAI-Types.h"

//TODO : use negetive index as wrap around array index

template
<class mvClass> mvList
{
   public:
      std::vector<mvClass*> listItems;
      mvCount maxNoOfItems;
      mvIndex currentIndex;

      mvList();
      mvErrorEnum addItem(mvClass* itemPtr);
      mvErrorEnum removeItem(mvIndex index);
      void removeAllItems();

      mvErrorEnum setCurrentItemParameteri(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentItemParameter(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentItemParameterf(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setCurrentItemParameterv(mvParamFlag paramFlag, mvOptionEnum option);

      mvErrorEnum setItemParameteri(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setItemParameter(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setItemParameterf(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum setItemParameterv(mvParamFlag paramFlag, mvOptionEnum option);

      mvErrorEnum getItemParameteri(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getItemParameter(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getItemParameterf(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getItemParameterv(mvParamFlag paramFlag, mvOptionEnum option);

      mvErrorEnum getCurrentItemParameteri(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getCurrentItemParameter(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getCurrentItemParameterf(mvParamFlag paramFlag, mvOptionEnum option);
      mvErrorEnum getCurrentItemParameterv(mvParamFlag paramFlag, mvOptionEnum option);

      mvClass* getClassPtr(mvIndex index);
      mvCount getNoOfItems() const;
      mvIndex getCurrentIndex() const;

      ~mvList();
};



#endif