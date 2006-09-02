#include "mvGroup.h"
#include "mvMotionAI-Utilities.h"

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
};

mvCount mvGroup::getNoOfMembers()
{
  return noOfMembers;
};
/**
void mvGroup::removeAllMembers()
{
   std::vector<mvBody*>::iterator i;
   mvBody* tempBody = NULL;

   /**
   for (i = members.begin(); i != members.end(); ++i)
   {
      members.erase(i);
      /**
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
**/

void mvGroup::clearAllMembers()
{
   std::vector<mvBody*>::iterator i;
   mvBody* tempBody = NULL;

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
};

mvGroup::mvGroup(char* mBodyGroupID)
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
};

mvBody* mvGroup::getMemberByIndex(mvIndex index)
{
/**
  if (index > 1 && index <= noOfMembers)
  {
    return members[index - 1];
  }
  else
  {
    return NULL;
  }
  **/
  return mvGetClassPtr<mvBody>(members,index, noOfMembers);
};

/** 
 * adds members by mvBody pointers. 
 */

mvEnum mvGroup::addMember(mvBody* tempBody)
{
   /**
   std::vector<mvBody*>::iterator i;
   mvBody* currentBody = NULL;

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
   **/
   return mvAddUniqueItemInVector<mvBody>(members,tempBody,noOfMembers);
};

mvEnum mvGroup::removeMember(mvBody* tempBody)
{
   /**
   std::vector<mvBody*>::iterator i;
   mvBody* currentBody = NULL;

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
   **/
   return mvRemoveUniqueItemInVector<mvBody>(members,tempBody,noOfMembers);
};

mvEnum mvGroup::setParameter(mvEnum paramFlag, mvEnum option)
{
  return MV_FALSE;
};

mvEnum mvGroup::setParameterf(mvEnum paramFlag, mvFloat num)
{
  return MV_FALSE;
};

mvEnum mvGroup::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
  return MV_FALSE;
};

char* mvGroup::getID() const
{
   return groupID;
};

