// 2008, Based off lpfe (Copyright 2007 by Lightfeather-Team - written by Reinhard Ostermeier)
// LFPE-Bullet

#ifndef _C_PE_WORLD_H_
#define _C_PE_WORLD_H_

#include <lfpe-bullet/lfpeConfig.h>
#include <lfpe-bullet/collision/config/CCollisionConfiguration.h>
#include <lfpe-bullet/collision/bphase/CCollisionBroadphase.h>
#include <lfpe-bullet/collision/dispatcher/CCollisionDispatcher.h>
#include <lfpe-bullet/rigid/solver/CConstraintSolver.h>
#include <lfpe-bullet/world/CPeSceneNodeController.h>
#include <lf/Lightfeather.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>

//! Bullet uses four major modules to handle both physics dynamics and collision
//! detection and resolution
namespace lf
{
namespace pe
{

namespace world
{
	class CForceAffector;

	using namespace lf;

	enum LPFE_BULLET_PHYSICS_WORLD_TYPE
	{
		ELFPE_BLT_PWT_DISCRETE_DYNAMICS_WORLD,
		ELFPE_BLT_PWT_SIMPLE__DYNAMICS_WORLD,
		ELFPE_BLT_PWT_CONTINUOUS_DYNAMICS_WORLD,
	};

	class LFPE_DLL_EXPORT CPeBulletWorld : public CRefCounted
	{
	public:
		//! Destructor
		virtual ~CPeBulletWorld();

		//! returns the Bullet internal worldID object
		btDynamicsWorld* getWorldID() const;

		//! return the collision system of the world
		collision::CCollisionDispatcher* getCollisionDispatcher() const;

		//! returns collision configuration
		collision::CCollisionConfiguration* getCollisionConfiguration() const;

		collision::CCollisionBroadphase* getCollisionBroadphase() const;

		rigid::CConstraintSolver* getConstraintSolver() const;

		//! collides all geoms
		void collideGeoms();

		//! translates all SceneNodes attached to scene node controler object
		void translateSceneNodes();

		LPFE_BULLET_PHYSICS_WORLD_TYPE getType() const;

	protected:
		//! collision system for world
		collision::CCollisionDispatcher* m_cDispatcher;

		collision::CCollisionBroadphase* m_collisionBPhase;

		collision::CCollisionConfiguration* m_collisionConfig;

		rigid::CConstraintSolver* m_constraintSolver;

		//! Bullet internal worldID
		btDynamicsWorld* m_worldID;

		LPFE_BULLET_PHYSICS_WORLD_TYPE m_worldType;

		//! Default Constructor
		CPeBulletWorld(collision::CCollisionDispatcher* cDispatcher,
			collision::CCollisionBroadphase* collisionBPhase,
			rigid::CConstraintSolver* constraintSolver,
			collision::CCollisionConfiguration* collisionConfig,
			btDynamicsWorld* worldPtr,	LPFE_BULLET_PHYSICS_WORLD_TYPE type);

	};

} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // __C_PE_WORLD_H__
