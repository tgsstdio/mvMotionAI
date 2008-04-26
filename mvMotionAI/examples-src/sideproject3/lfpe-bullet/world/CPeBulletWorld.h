// 2008, Based off lpfe (Copyright 2007 by Lightfeather-Team - written by Reinhard Ostermeier)
// LFPE-Bullet

#ifndef _C_PE_WORLD_H_
#define _C_PE_WORLD_H_

#include <lfpe-bullet/lfpeConfig.h>
//#include <lfpe-bullet/collision/CGeomSpace.h>
#include <lfpe-bullet/world/CPeSceneNodeController.h>
#include <lf/Lightfeather.h>

#include <LinearMath/btScalar.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>

//! Bullet uses four major modules to handle both physics dynamics and collision
//! detection and resolution
namespace lf
{
namespace pe
{
namespace collision
{
	class CCollisionBroadphase;
	class CCollisionDispatcher;
	class CCollisionConfiguration;
	class CCollisionSystem;
}
namespace rigid
{
	class CRigidSystem;

}
namespace dynamics
{
	class CDynamicsSolver;
}
namespace world
{
	class CForceAffector;

	using namespace lf;


	class LFPE_DLL_EXPORT CPeBulletWorld
	{
	public:
		//! Default Constructor
		CPeBulletWorld(collision::CCollisionSystem* collisionSystem = 0,
			collision::CCollisionConfiguration* collisionConfig =0,
			collision::CBroadphase* collisionBPhase = 0,
			dynamics::CDynamicsSolver* dynamicSolver = 0,
			);

		//! Destructor
		~CPeBulletWorld();

		//! returns the Bullet internal worldID object
		btDynamicsWorld* getWorldID() const;

		//! return the collision system of the world
		collision::CCollisionSystem* getCollisionSystem() const;

		//! returns the rigid system of the world
		rigid::CRigidSystem* getRigidSystem() const;

		//! returns collision configuration

		//! collides all geoms
		void collideGeoms();

		//! translates all SceneNodes attached to scene node controler object
		void translateSceneNodes();

	protected:
		//! Bullet internal worldID
		btDynamicsWorld* m_worldID;

		//! collision system for world
		collision::CCollisionSystem* m_collisionSystem;

		//! true if collision system was created internally
		//! false for external collision system
		// TODO : use reference counting instead
		bool m_deleteCollisionSystem;

		//! rigid system for world
		rigid::CRigidSystem* m_rigidSystem;

		//! bullet collision configuration
		collision::CCollisionConfiguration* m_cConfig;
	};

} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // __C_PE_WORLD_H__
