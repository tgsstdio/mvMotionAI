#ifndef MVSIMPLEFLOCK_H_INCLUDED
#define MVSIMPLEFLOCK_H_INCLUDED
#include "mvBaseBehaviour.h"

/**
 * \brief this class is goes into the behaviour list for
 * the body.
 */
class mvSimpleFlock : public mvBaseBehaviour
{
//   private:
   public:
      mvFloat alignment;
      mvFloat cohesion;
      mvFloat seperation;
      bool perceivedAlignment;
      bool perceivedCohesion;

      mvSimpleFlock();
	   virtual void groupOperation(mvWorld* world, mvGroup* groupPtr);
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
};

/**
 * \brief this class is unique to each group & behaviour instance
 */
class mvSimpleFlockGroup : public mvBaseBehaviour
{
//   private:

   public:
      mvVec3 totalVelocity;
      mvVec3 totalPosition;
      mvCount noOfMembers;
      mvFloat defaultAlignment;
      mvFloat defaultCohesion;
      mvFloat defaultSeperation;
      bool defaultPerceivedAlignment;
      bool defaultPerceivedCohesion;
      mvSimpleFlockGroup();
	   virtual void groupOperation(mvWorld* world, mvGroup* groupPtr);
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
};

/**
 * \brief this class is main (top) group behaviour function
 */
class mvSimpleFlockDefaultGroup : public mvBaseBehaviour
{
//   private:

   public:
      mvFloat defaultGroupAlignment;
      mvFloat defaultGroupCohesion;
      mvFloat defaultGroupSeperation;
      bool defaultGroupPerceivedAlignment;
      bool defaultGroupPerceivedCohesion;
      mvSimpleFlockDefaultGroup();
	   virtual void groupOperation(mvWorld* world, mvGroup* groupPtr);
	   virtual mvBehaviourReturnType bodyOperation(mvWorld* world, mvBody* b, mvBaseBehaviour* groupNodeBehaviour,
               mvVec3& forceVector, mvVec3& accelVector, mvVec3& velocity);
};

class mvCreateSimpleFlock : public mvBaseBehaviourLoader
{
   public:
      mvBaseBehaviour* operator()(mvBaseBehaviour* defaultBehaviour);
};

#endif // MVSIMPLEFLOCK_H_INCLUDED
