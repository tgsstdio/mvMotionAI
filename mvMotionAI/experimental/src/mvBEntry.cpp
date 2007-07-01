#include "mvBEntry.h"
// TODO: implement later
mvBEntry::mvBEntry(mvOptionEnum type, mvIndex bIndex, mvIndex gIndex,\
   mvBaseActionPtr dBehaviour)
{
   entryType = type;
   behaviourIndex = bIndex;
   groupIndex = gIndex;
   actionDataPtr = dBehaviour;
}

void mvBEntry::setActionPtr(mvBaseActionPtr behavPtr)
{
   actionDataPtr = behavPtr;
}

mvBaseActionPtr mvBEntry::getActionPtr() const
{
   return actionDataPtr;
}

mvOptionEnum mvBEntry::getEntryType() const
{
   return entryType;
}

mvIndex mvBEntry::getGroup() const
{
   return groupIndex;
}

mvIndex mvBEntry::getBehaviour() const
{
   return behaviourIndex;
}

void mvBEntry::setBehaviour(mvIndex index)
{
   behaviourIndex = index;
}

void mvBEntry::setGroup(mvIndex index)
{
   groupIndex = index;
}

mvErrorEnum mvBEntry::getParameteri(mvParamEnum paramFlag, mvIndex* index) const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      default:
         if (actionDataPtr != MV_NULL)
         {
            return actionDataPtr->getParameteri(paramFlag, index);
         }
         else
         {
            return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
         }
      case MV_GROUP:
         *index = getGroup();
         return MV_NO_ERROR;
      case MV_BEHAVIOUR:
         *index = getBehaviour();
         return MV_NO_ERROR;
   }
}

mvErrorEnum mvBEntry::getParameter(mvParamEnum paramFlag, mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_ENTRY_TYPE:
         *option = getEntryType();
         return MV_NO_ERROR;
      default:
         if (actionDataPtr != MV_NULL)
         {
            return actionDataPtr->getParameter(paramFlag, option);
         }
         else
         {
            return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
         }
   }
}

mvErrorEnum mvBEntry::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   if (actionDataPtr != MV_NULL)
   {
      return actionDataPtr->getParameterf(paramFlag, num);
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
   }
}

mvErrorEnum mvBEntry::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (actionDataPtr != MV_NULL)
   {
      return actionDataPtr->getParameterv(paramFlag, numArray, noOfParameters);
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
   }
}


mvErrorEnum mvBEntry::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   switch(paramFlag)
   {
      default:
         if (actionDataPtr != MV_NULL)
         {
            return actionDataPtr->setParameteri(paramFlag, index);
         }
         else
         {
            return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
         }
      case MV_GROUP:
         setGroup(index);
         return MV_NO_ERROR;
      case MV_BEHAVIOUR:
         setBehaviour(index);
         return MV_NO_ERROR;
   }
}

mvErrorEnum mvBEntry::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   if (actionDataPtr != MV_NULL)
   {
      return actionDataPtr->setParameter(paramFlag, option);
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
   }
}

mvErrorEnum mvBEntry::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   if (actionDataPtr != MV_NULL)
   {
      return actionDataPtr->setParameterf(paramFlag, num);
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
   }
}

mvErrorEnum mvBEntry::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   if (actionDataPtr != MV_NULL)
   {
      return actionDataPtr->setParameterv(paramFlag, numArray);
   }
   else
   {
      return MV_INVALID_BEHAVIOUR_ENTRY_PARAMETER;
   }
}

mvBEntry::~mvBEntry()
{
   if (actionDataPtr != MV_NULL)
   {
      delete actionDataPtr;
   }
}
