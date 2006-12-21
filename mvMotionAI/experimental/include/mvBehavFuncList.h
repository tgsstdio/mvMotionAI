#ifndef MVBEHAVFUNCLIST_H_INCLUDED
#define MVBEHAVFUNCLIST_H_INCLUDED
#include <map>
#include "mvBaseBehaviour.h"
#include "mvEnums.h"

class mvBehavFuncList
{
   public:
      mvCount noOfValidFunctions;
      std::map<mvOptionEnum,mvBaseBehaviourLoader*> bFunctions;

      mvBehavFuncList();
      mvErrorEnum addBehaviourFunction(mvOptionEnum key, mvBaseBehaviourLoader* bFunc);
      void freeAllBehaviourFunctions();
      mvBaseBehaviour* createBehaviour(mvOptionEnum key, mvBaseBehaviour* defaultBehav);
      ~mvBehavFuncList();
};

#endif // MVBEHAVFUNCLIST_H_INCLUDED
