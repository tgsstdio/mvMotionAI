#ifndef MOTIONAI_MVGROUP_H_
#define MOTIONAI_MVGROUP_H_

#include <vector>
//#include <string>
#include "mvMotionAI-Types.h"
#include "mvEnum.h"
#include "mvBody.h"

/**
 * \class mvGroup
 *
 * \brief to create a group of bodies
 *
 * Log
 *
 *version     date  comments
 *
 *00-01-05  23/8/06  - types now declared by mvMotionAI-Types.h & mvVec3
 *
 *00-01-00  22/5/06  - initialised groups
 */
class mvGroup
{
   private:
     std::vector<mvBody*> members;
     //int noOfMembersSlots;
     mvCount noOfMembers;
     //char* groupID;
     char* groupID;

   public:
      mvGroup();
      mvGroup(char* mBodyGroupID);
      mvCount getNoOfMembers();
      void clearAllMembers();
     // void removeAllMembers();
      char* getID() const;
      mvBody* getMemberByIndex(mvIndex index);
      mvEnum addMember(mvBody* tempBody);
      mvEnum removeMember(mvBody* tempBody);
      mvEnum setParameter(mvEnum paramFlag, mvEnum option);
      mvEnum setParameterf(mvEnum paramFlag, mvFloat num);
      mvEnum setParameterv(mvEnum paramFlag, mvFloat* numArray);
      ~mvGroup();
};

#endif

