/**
 * \file mvBehaviour.cpp
 *
 * Copyright (c) 2006 David Young.
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

#include "mvBehaviour.h"
//#include "mvBehaviour-Type.h"

void mvBehaviour::initDefault()
{
   behavData = NULL;
}

mvBehaviour::mvBehaviour(mvOptionEnum type)
{
   initDefault();
   behavData = new mvBehaviourEntry(type);
}

mvBehaviour::mvBehaviour(const mvBehaviour& rhs)
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }

   behavData = new mvBehaviourEntry();
   *behavData = *rhs.behavData;
}

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
}

mvBehaviourEntry* mvBehaviour::getData() const
{
   return behavData;
}

mvOptionEnum mvBehaviour::getType() const
{
   if (behavData == NULL)
   {
      return MV_NON_BEHAVIOUR_TYPE;
   }
   else
   {
      return behavData->getType();
   }
}

mvBehaviour::~mvBehaviour()
{
   if (behavData != NULL)
   {
      delete behavData;
      behavData = NULL;
   }
}

mvErrorEnum mvBehaviour::getParameteri(mvParamEnum paramFlag, mvIndex* index)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::getParameter(mvParamEnum paramFlag, mvOptionEnum* option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::getParameterf(mvParamEnum paramFlag, mvFloat* num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::getParameterv(mvParamEnum paramFlag, mvFloat* numArray, mvCount* noOfElements)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::setParameteri(mvParamEnum paramFlag, mvIndex index)
{
   if (behavData != NULL)
   {
      return behavData->setParameteri(paramFlag,index);
   }
   else
   {
      return MV_BEHAVIOUR_IS_NOT_INITIALISED;
   }
}

mvErrorEnum mvBehaviour::setParameter(mvParamEnum paramFlag, mvOptionEnum option)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::setParameterf(mvParamEnum paramFlag, mvFloat num)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

mvErrorEnum mvBehaviour::setParameterv(mvParamEnum paramFlag, mvFloat* numArray)
{
   return MV_INVALID_BEHAVIOUR_PARAMETER;
}

//#include "mvBehaviour-Seek.h"

//mvIndex mvBehaviour_GetIndexesArraySize(mvEnum type);
//mvEnum mvBehaviour_CheckPathwayIndexIsValid(mvEnum type);

/*
mvEnum mvBehaviour::initialiseVectors(mvEnum type)
{
   Vec3 tempVectors[MV_MAX_BEHAVIOUR_VECTORS];

   return MV_FALSE;
};
*

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
*/

