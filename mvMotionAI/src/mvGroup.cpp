/**
 * \file mvGroup.cpp
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

#include "mvMotionAI-Utilities.h"
#include "mvGroup.h"

mvGroup::~mvGroup()
{
  //removeAllMembers();
  clearAllMembers();
  noOfMembers = 0;

  if (groupID != NULL)
  {
     delete [] groupID;
     groupID = NULL;
  }
}

mvCount mvGroup::getNoOfMembers()
{
  return noOfMembers;
}
/*
void mvGroup::removeAllMembers()
{
   std::vector<mvBodyPtr>::iterator i;
   mvBodyPtr tempBody = NULL;

   **
   for (i = members.begin(); i != members.end(); ++i)
   {
      members.erase(i);
      **
      if (tempBody != NULL)
      {
         delete tempBody;
         *i = NULL;
      }
      **
   }
   **
   members.clear();
   noOfMembers = 0;
};
*/

void mvGroup::clearAllMembers()
{
   std::vector<mvBodyPtr>::iterator i;
   mvBodyPtr tempBody = NULL;

   for (i = members.begin(); i != members.end(); ++i)
   {
      tempBody = *i;
      if (tempBody != NULL)
      {
         *i = NULL;
      }
   }
   members.clear();
   noOfMembers = 0;
}

mvGroup::mvGroup(const char* mBodyGroupID)
{
   mvCount strLen;

   if (mBodyGroupID != NULL)
   {
      strLen = strlen(mBodyGroupID) + 1;
      groupID  = new char[strLen];
      strcpy(groupID ,mBodyGroupID);
   }
   else
   {
      groupID = NULL;
   }
  noOfMembers = 0;
}

mvBodyPtr mvGroup::getMemberByIndex(mvIndex index)
{
   /*
  if (index > 1 && index <= noOfMembers)
  {
    return members[index - 1];
  }
  else
  {
    return NULL;
  }
  */
   return mvGetClassPtr<mvBody>(members,index, noOfMembers);
}

/**
 * adds members by mvBody pointers.
 */
mvErrorEnum mvGroup::addMember(mvBodyPtr tempBody)
{
   /*
   std::vector<mvBodyPtr>::iterator i;
   mvBodyPtr currentBody = NULL;

   if (tempBody == NULL)
     return MV_FALSE;

   for (i = members.begin(); i != members.end(); ++i)
   {
     currentBody = *i;
     if (currentBody != NULL)
        if (tempBody == currentBody)
           return MV_FALSE;
   }
   members.push_back(tempBody);
   noOfMembers++;
   return MV_TRUE;
   */
   return mvAddUniqueItemInVector<mvBody>(members,tempBody,noOfMembers);
}

mvErrorEnum mvGroup::removeMember(mvBodyPtr tempBody)
{
   /*
   std::vector<mvBodyPtr>::iterator i;
   mvBodyPtr currentBody = NULL;

   if (tempBody != NULL && noOfMembers <= 0)
      return MV_FALSE;

   for (i = members.begin(); i != members.end(); ++i)
   {
     currentBody = *i;
     if (currentBody != NULL)
        if (tempBody == currentBody)
        {
           *i = NULL;
           return MV_TRUE;
        }
   }
   --noOfMembers;
   return MV_FALSE;
   */
   return mvRemoveUniqueItemInVector<mvBody>(members,tempBody,noOfMembers);
}

mvErrorEnum mvGroup::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
  return MV_INVALID_GROUP_PARAMETER;
}

mvErrorEnum mvGroup::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
  return MV_INVALID_GROUP_PARAMETER;
}

mvErrorEnum mvGroup::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
  return MV_INVALID_GROUP_PARAMETER;
}

char* mvGroup::getID() const
{
   return groupID;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroup::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroup::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroup::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroup::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfParameters)
{
   return MV_INVALID_GROUP_PARAMETER;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
mvErrorEnum mvGroup::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   return MV_INVALID_GROUP_PARAMETER;
}

