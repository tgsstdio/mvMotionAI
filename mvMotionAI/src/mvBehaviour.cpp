#include "mvBehaviour.h"
//#include "mvBehaviour-Type.h"

void mvBehaviour::initDefault()
{
   behavData = NULL;
};

mvBehaviour::mvBehaviour(mvEnum type)
{
   initDefault();
   behavData = new mvBehaviourEntry(type);
};

mvBehaviour::mvBehaviour(const mvBehaviour& rhs)
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   behavData = new mvBehaviourEntry();
   *behavData = *rhs.behavData;
};

const mvBehaviour& mvBehaviour::operator=(const mvBehaviour& rhs)
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   behavData = new mvBehaviourEntry();
   *behavData = *rhs.behavData;
   return *this;
};

mvBehaviourEntry* mvBehaviour::getData() const
{
   return behavData;
};

mvEnum mvBehaviour::getType() const
{
   if (behavData == NULL)
   {
      return MV_INVALID_BEHAVIOUR_TYPE;
   }
   else
   {
      return behavData->getType();
   }
};

mvBehaviour::~mvBehaviour()
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }
};

mvEnum mvBehaviour::getParameteri(mvEnum paramFlag, mvIndex* index) const
{
   return MV_FALSE;
};

mvEnum mvBehaviour::getParameter(mvEnum paramFlag, mvEnum* option) const
{
   return MV_FALSE;
};

mvEnum mvBehaviour::getParameterf(mvEnum paramFlag, mvFloat* num) const
{
   return MV_FALSE;
};

mvEnum mvBehaviour::getParameterv(mvEnum paramFlag, mvFloat* numArray) const
{
   return MV_FALSE;
};

mvEnum mvBehaviour::setParameteri(mvEnum paramFlag, mvIndex index)
{
   if (behavData != NULL)
   {
      return behavData->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_FALSE;
   }
};

mvEnum mvBehaviour::setParameter(mvEnum paramFlag, mvEnum option)
{
   return MV_FALSE;
};

mvEnum mvBehaviour::setParameterf(mvEnum paramFlag, mvFloat num)
{
   return MV_FALSE;
};

mvEnum mvBehaviour::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
   return MV_FALSE;
};

//#include "mvBehaviour-Seek.h"

//mvIndex mvBehaviour_GetIndexesArraySize(mvEnum type);
//mvEnum mvBehaviour_CheckPathwayIndexIsValid(mvEnum type);

/**
mvEnum mvBehaviour::initialiseVectors(mvEnum type)
{
   Vec3 tempVectors[MV_MAX_BEHAVIOUR_VECTORS];

   return MV_FALSE;
};
**

mvBehaviour::~mvBehaviour()
{
   **
   if (behaviourName != NULL)
   {
      delete [] behaviourName;
      behaviourName = NULL;
   }
   **
   if (defaultVariables != NULL)
   {
      delete [] defaultVariables;
      defaultVariables = NULL;
   }

   if (indexes != NULL)
   {
      delete [] indexes;
      indexes = NULL;
   }
   *
   //removeAllGroups();
};

mvBehaviour::mvBehaviour(char* bName, mvEnum type)
{  *
   mvCount len;

   behaviourName = NULL;
   if (bName != NULL)
   {
      len = strlen(bName) + 1;
      behaviourName = new char[len];
      strcpy(behaviourName,bName);
      puts(behaviourName);
   }
   **
   //noOfGroups = 0;
   //bPaths = NULL;
   //bWaypoints = NULL;
   behavData = NULL;
   //indexes = NULL;
   //defaultVariables = NULL;
   //defaultVectors = NULL;
   bType = MV_INVALID_BEHAVIOUR_TYPE;
   //mvBehaviour_InitialiseType(type, bType, indexes);
};

char* mvBehaviour::getName()
{
   return behaviourName;
};

mvEnum mvBehaviour::getType() const
{
   return bType;
};

**
mvCount mvBehaviour::getNoOfGroups()
{
   return noOfGroups;
};

void mvBehaviour::removeAllGroups()
{
   std::vector<mvGroup*>::iterator i;
   mvGroup* tempGroup = NULL;

   for (i = groups.begin(); i != groups.end(); ++i)
   {
      tempGroup = *i;
      if (tempGroup != NULL)
      {
         *i = NULL;
      }
   }
   noOfGroups = 0;
};

mvEnum mvBehaviour::addGroup(mvGroup* bGroup)
{
   std::vector<mvGroup*>::iterator i;
   mvGroup* tempGroup = NULL;

   for (i = groups.begin(); i != groups.end(); ++i)
   {
      tempGroup = *i;
      if (tempGroup != NULL && bGroup == tempGroup)
      {
         return MV_FALSE;
      }
   }
   groups.push_back(bGroup);
   ++noOfGroups;
   return MV_TRUE;
};

mvEnum mvBehaviour::removeGroup(mvGroup* bGroup)
{
   std::vector<mvGroup*>::iterator i;
   mvGroup* tempGroup = NULL;

   for (i = groups.begin(); i != groups.end(); ++i)
   {
      tempGroup = *i;
      if (tempGroup != NULL && bGroup == tempGroup)
      {
         *i = NULL;
         --noOfGroups;
         return MV_TRUE;
      }
   }
   return MV_FALSE;
};
**

mvEnum mvBehaviour::setParameter(mvEnum paramFlag, mvEnum option)
{
   return MV_FALSE;
};

mvEnum mvBehaviour::setParameterf(mvEnum paramFlag, mvFloat num)
{
   return MV_FALSE;
};

mvEnum mvBehaviour::setParameterv(mvEnum paramFlag, mvFloat* numArray)
{
   return MV_FALSE;
};

//mvIndex getWaypointIndexAt(mvIndex num);
//mvIndex getPathwayIndexAt(mvIndex num);
//mvIndex mvBehaviour::getBodyIndexAt(mvIndex num);
**/

