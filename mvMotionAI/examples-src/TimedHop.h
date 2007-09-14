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
 * customable mvAction class.
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
 * 3. virtual mvBaseActionPtr operator()(mvBaseActionPtr higherNode) of the
 *    derived mvBaseActionLoader class:
 *
 *    - This function acts a factory creating new instance of any action
 *   as long as the instance is returning as a mvBaseAction pointer.
 *   The parameter higherNode is used to specialise the new object
 *   for various purposes, by passing mvBaseActionPtr with a different type
 *   enum i.e. MV_SEEK or MV_PURSUIT or even a NULL pointer.
 *
 *   For example, you can create different type of classes
 *   when creating a new action for an individual body, a global behaviour,
 *   a group behaviour node, or a group member of a grouped behaviour.
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
      virtual mvBaseActionPtr operator()(mvBaseActionPtr higherNode);
      ~TimedHopLoader();
};

#endif // TIMEDHOP_H_INCLUDED
