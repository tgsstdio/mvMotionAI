#ifndef MV_BEHAVIOUR_TYPE_INIT_H_
#define MV_BEHAVIOUR_TYPE_INIT_H_
#include "mvEnum.h"
#include "mvVec3.h"
#include "mvMotionAI-Types.h"

mvCount mvBehaviour_GetIndexesArraySize(mvEnum type);
mvEnum mvBehaviour_InitialiseType(mvEnum type, mvEnum& bType, mvIndex* indexes,
                                  mvFloat* variables, mvEnum* states, mvVec3* points);

template<class mvType>
mvEnum mvBehaviour_CopyArrayContents(mvType* dstArray, mvType* srcArray, mvCount noOfElements)
{
   mvIndex i;

   if (dstArray != NULL && srcArray != NULL)
   {
      for (i = 0; i < noOfElements; ++i)
      {
         dstArray[i] = srcArray[i];
      }
      return MV_TRUE;
   }
   else
   {
      return MV_FALSE;
   }
};

mvCount mvBehaviour_GetPointsArraySize(mvEnum type);
mvCount mvBehaviour_GetVariablesArraySize(mvEnum type);
mvCount mvBehaviour_GetStateArraySize(mvEnum type);

mvEnum selectBodyToGroupEntryType(mvEnum type);
mvEnum selectGroupToBodyEntryType(mvEnum type);
#endif



