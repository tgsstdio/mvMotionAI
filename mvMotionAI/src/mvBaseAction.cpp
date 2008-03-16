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
#include <mv/mvBaseAction.h>

/** \brief blah blah
 *
 */
mvBaseAction::mvBaseAction(mvOptionEnum type)
{
   bType = type;
}

/** \brief blah blah
 *
 */
mvOptionEnum mvBaseAction::getType() const
{
   return bType;
}

mvErrorEnum mvBaseAction::getNotFoundEnum()
{
	return MV_INVALID_BEHAVIOUR_PARAMETER;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch (paramFlag)
   {
      case MV_TYPE:
         *option = getType();
         return MV_NO_ERROR;
      default:
         return getNotFoundEnum();
   }
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::getParameteri(mvParamEnum paramFlag,\
   mvIndex* index) const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::getParameterf(mvParamEnum paramFlag,\
   mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::getParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray, mvCount* noOfElements) const
{
   if (noOfElements == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfElements = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::setParametero(mvParamEnum paramFlag,\
   mvOptionEnum option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::setParameteri(mvParamEnum paramFlag,\
   mvIndex index)
{
   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvErrorEnum mvBaseAction::setParameterv(mvParamEnum paramFlag,\
   mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return getNotFoundEnum();
}

/** \brief blah blah
 *
 */
mvBaseAction::~mvBaseAction()
{
   // empty code
}

/**
 * \brief mvBaseActionLoader constructor
 */
mvBaseActionLoader::mvBaseActionLoader()
{
   // empty code
}

/** \brief blah blah
 *
 */
mvNewBaseActionInfo::mvNewBaseActionInfo(mvOptionEnum loaderKey,\
   mvNewBaseActionInfo::mvNewBaseActionOperationEnum operation,
   mvBaseActionPtr mainGroupNodePtr, mvBaseActionPtr groupNodePtr)
   : actionKey(loaderKey)
{
   opType = operation;

   gbMainNodePtr = MV_NULL;
   gbGroupNodePtr = MV_NULL;

   if (opType == mvNewBaseActionInfo::MV_NEW_GB_GROUP_NODE_OP)
   {
      gbMainNodePtr = mainGroupNodePtr;
   }
   else if (opType == mvNewBaseActionInfo::MV_NEW_GB_GROUP_MEMBER_OP
		|| opType == mvNewBaseActionInfo::MV_GROUP_MEMBER_LOOKUP_OP)
   {
      gbMainNodePtr = mainGroupNodePtr;
      gbGroupNodePtr = groupNodePtr;
   }
}

/** \brief blah blah
 *
 */
mvOptionEnum mvNewBaseActionInfo::getActionLoaderKey() const
{
   return actionKey;
}

/** \brief blah blah
 *
 */
mvBaseActionPtr mvNewBaseActionInfo::getGroupBehaviourPtr() const
{
   return gbMainNodePtr;
}

/** \brief blah blah
 *
 */
mvBaseActionPtr mvNewBaseActionInfo::getGetGroupNodePtr() const
{
   return gbGroupNodePtr;
}

bool mvNewBaseActionInfo::isGroupMemberNodeLookup() const
{
	return (opType == mvNewBaseActionInfo::MV_GROUP_MEMBER_LOOKUP_OP);
}

/** \brief blah blah
 *
 */
bool mvNewBaseActionInfo::isNewMainGroupBehaviour() const
{
   return (opType == mvNewBaseActionInfo::MV_NEW_GB_MAIN_NODE_OP);
}

/** \brief blah blah
 *
 */
bool mvNewBaseActionInfo::isNewGroupBehaviourGroupNode() const
{
   return (opType == mvNewBaseActionInfo::MV_NEW_GB_GROUP_NODE_OP);
}

/** \brief blah blah
 *
 */
bool mvNewBaseActionInfo::isNewGroupMemberNode() const
{
   return (opType == mvNewBaseActionInfo::MV_NEW_GB_GROUP_MEMBER_OP);
}

/** \brief blah blah
 *
 */
bool mvNewBaseActionInfo::isNewGlobalBehaviour() const
{
   return (opType == mvNewBaseActionInfo::MV_NEW_GLOBAL_BEHAVIOUR_OP);
}

/** \brief blah blah
 *
 */
bool mvNewBaseActionInfo::isNewPrivateBehaviour() const
{
   return (opType == mvNewBaseActionInfo::MV_NEW_PRIVATE_BEHAVIOUR_OP);
}
