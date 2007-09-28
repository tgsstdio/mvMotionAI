#ifndef TIMEDHOP_H_INCLUDED
#define TIMEDHOP_H_INCLUDED

/**
 * \brief How to add a custom action into mvWorld system
 *
 * To add new classes describing how bodies should behave or act, we build a sub
 * class of mvBaseAction and its corresponding loader (factory),
 * mvBaseActionLoader.
 *
 * The programmer must implement three virtual functions if he/she wants to use
 * customable mvAction class. To retrive variables from your custom
 * action class via the mvMotionAI library, implement the superclass
 * set/getParameter(ifv)() functions that are needed.
 *
 * 1. virtual bool bodyOp(mvBehaviourResultPtr resultMod) of the derived
 *    mvBaseAction class:
 *
 * - Via the parameter resultMod, we can set the possible future velocity or a
 *   steering force to the body. More importantly EVERY pointers and references
 *   is READ-ONLY (const), expect for mvBaseActionPtr & mvBehaviourResultPtr.
 *   This is to keep the changes within the system isolated. This function is
 *   called for every action instance within the system per mvWorldStep,
 *   i.e. if 5 mvBodies have the 7 copies of same mvBaseAction, then this
 *   function might be called up to 35 times.
 *
 * 2. virtual bool groupOp(mvGroupBehaviourResultPtr groupBehMod) of the derived
 *    mvBaseAction class:
 *
 * - This is the user defined method for group interactions (mvGroupBehaviours)
 *   with other mvBody within mvWorld system. The big difference between the
 *   bodyOp & groupOp is the latter has READ and WRITE access to mvWorld objects
 *   in the system. Therefore this function can create new objects & change
 *   variables of other classes.
 *   This function is used together with the mvGroupBehaviour object.
 *   mvGroupBehaviours provide a shared variable area to all multiple bodies
 *   using a top-down approach. Types of behaviours suitable for group
 *   behaviours are boids, squadarons and a game of tag between many bodies.
 *
 *   However, this function is called far less, i.e. for a mvGroupBehaviour's
 *   associated group node per a mvWorldStep, so once for a group per every
 *   instance of mvGroupBehaviour in an instance of mvWorld.
 *
 * 3. virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& actionQuery) of the
 *    derived mvBaseActionLoader class:
 *
 *    - This function acts a factory creating new instance of any action
 *   as long as the instance is returning as a mvBaseAction pointer.
 *   The parameter actionQuery is used to specialise the new object
 *   for various purposes. Through querying the actionQery instance,
 *   we can create different objects for every given situation;
 *   we can use the same 'key' to create different behaviours.
 *
 *   The situations when an action is created:
 *   1. for an individual body or private action instance
 *     -  bool isNewPrivateBehaviour() const
 *   2. a global behaviour which can be used by any body in the system
 *     -  bool isNewGlobalBehaviour() const
 *   3. a starter/(main node) group behaviour (has many groups, has many members
 *   (indirectly), 1 default action)
 *     -  bool isNewGroupBehaviour() const
 *   4. a group behaviour group node (belongs to 1 group behavour, has 1 group,
 *   has many members, has 1 action)
 *     -  bool isNewGroupBehaviourGroupNode() const
 *   5. a group member of a group node. (has 1 member, belong to 1 group)
 *     -  bool isNewGroupMemberNode() const
 *
 *   Note that situation 4 & 5 are different as they have access to other
 *   mvBaseAction pointers. The programmer can use the values
 *   of the main node's or a group node's action classes for initialisation,
 *   updating node values, etc.
 */

#include <mv/mvMotionAI.h>

class TimedHop : public mvBaseAction
{
   public:
      TimedHop();

      /**
       * \brief this is user defined method for a single body
       * interacting with the mvWorld system objects such as mvBody, mvObstacle,
       * and mvWaypoints.
       */
      virtual bool bodyOp(mvBehaviourResultPtr resultMod);

      /**
       * \brief this is user defined method for group interaction with other
       * mvBody mvWorld system.
       */
      virtual bool groupOp(mvGroupBehaviourResultPtr groupBehMod);
      ~TimedHop();
};

class TimedHopLoader : public mvBaseActionLoader
{
   public:
      TimedHopLoader();
      virtual mvBaseActionPtr operator()(mvNewBaseActionInfo& actionQuery);
      ~TimedHopLoader();
};

#endif // TIMEDHOP_H_INCLUDED
