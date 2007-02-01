#ifndef MVSIMPLEFLOCK_H_INCLUDED
#define MVSIMPLEFLOCK_H_INCLUDED
#include "mvBaseBehaviour.h"

/**
 * \brief this class is goes into the behaviour list for
 * the body.
 *
 * SHARED BEHAVIOUR : main group behaviour & unique entry to a body
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
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
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
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
};

/*
 * \brief this class is main (top) group behaviour function
 *
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
	   virtual bool groupOp(mvGroupBehaviourResultPtr resultModule);
      virtual bool bodyOp(mvBehaviourResultPtr resultModule);
};
*/

class mvCreateSimpleFlock : public mvBaseBehaviourLoader
{
   public:
      mvCreateSimpleFlock();
      mvBaseBehaviourPtr operator()(mvBaseBehaviourPtr defaultBehaviour);
};

#endif // MVSIMPLEFLOCK_H_INCLUDED
