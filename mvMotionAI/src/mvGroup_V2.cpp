/**
 * \file mvGroup_V2.cpp
 * \class mvGroup mv/mvGroup_V2.h
 *
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
#include <mv/mvGroup_V2.h>

/** \brief blah
 *
 */
mvGroup::mvGroup()
{
   isEnabled = true;
}

/** \brief blah
 *
 */
mvGroup::~mvGroup()
{
   clearAll();
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::addMember(mvIndex memberIndex)
{
   return members.addIndex(memberIndex);
}

/** \brief blah
 *
 */
bool mvGroup::findMember(mvIndex memberIndex) const
{
   return members.containsIndex(memberIndex);
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::removeMember(mvIndex memberIndex)
{
   return members.removeIndex(memberIndex);
}

/** \brief blah
 *
 */
mvCount mvGroup::getNoOfMembers() const
{
   return members.getNoOfIndexes();
}

/** \brief blah
 *
 */
void mvGroup::clearAll()
{
   members.clearAll();
}

/** \brief blah
 *
 */
void mvGroup::setToFirstMember()
{
   members.beginLoop();
}

/** \brief blah
 *
 */
bool mvGroup::areMembersFinished() const
{
   return members.isLoopFinished();
}

/** \brief blah
 *
 */
mvIndex mvGroup::getCurrentMember() const
{
   return members.getCurrentIndex();
}

/** \brief blah
 *
 */
void mvGroup::toNextMember()
{
   members.nextIndex();
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::getParameteri(mvParamEnum paramFlag, mvIndex* index)\
   const
{
   if (index == MV_NULL)
   {
      return MV_INDEX_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_NO_OF_BODIES:
      case MV_NO_OF_BEHAVIOURS:
      case MV_NO_OF_FORCES:
      case MV_NO_OF_OBSTACLES:
      case MV_NO_OF_WAYPOINTS:
      case MV_NO_OF_PATHWAYS:
      case MV_NO_OF_GROUPS:
      case MV_NO_OF_GROUP_BEHAVIOURS:
         *index = getNoOfMembers();
         return MV_NO_ERROR;
      default:
         return MV_INVALID_GROUP_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::getParametero(mvParamEnum paramFlag,\
   mvOptionEnum* option) const
{
   if (option == MV_NULL)
   {
      return MV_OPTION_ENUM_DEST_IS_NULL;
   }

   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (isEnabled)
         {
           *option = MV_TRUE;
         }
         else
         {
            *option = MV_FALSE;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_GROUP_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::getParameterf(mvParamEnum paramFlag, mvFloat* num) const
{
   if (num == MV_NULL)
   {
      return MV_FLOAT_DEST_IS_NULL;
   }

   return MV_INVALID_GROUP_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
   mvCount* noOfParameters) const
{
   if (noOfParameters == MV_NULL)
   {
      return MV_COUNT_DEST_IS_NULL;
   }

   if (numArray == MV_NULL)
   {
      *noOfParameters = 0;
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_GROUP_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::setParametero(mvParamEnum paramFlag, mvOptionEnum option)
{
   switch(paramFlag)
   {
      case MV_IS_ENABLED:
         if (option == MV_FALSE)
         {
            isEnabled = false;
         }
         else
         {
            isEnabled = true;
         }
         return MV_NO_ERROR;
      default:
         return MV_INVALID_GROUP_PARAMETER;
   }
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** \brief blah
 *
 */
mvErrorEnum mvGroup::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   if (numArray == MV_NULL)
   {
      return MV_PARAMETER_ARRAY_IS_NULL;
   }

   return MV_INVALID_GROUP_PARAMETER;
}

/** \brief blah
 *
 */
mvGroupIterator mvGroup::getGroupIterator() const
{
   return members.getUniqueSetIterator();
}

