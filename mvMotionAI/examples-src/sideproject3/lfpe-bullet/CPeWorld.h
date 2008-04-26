// 2008, Based off lpfe (Copyright 2007 by Lightfeather-Team - written by Reinhard Ostermeier)
// LFPE-Bullet

#ifndef _C_PE_WORLD_H_
#define _C_PE_WORLD_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/collision/CGeomSpace.h>
#include <lfpe/world/CPeSceneNodeController.h>
#include <lf/Lightfeather.h>

#include <ode/ode.h>


namespace lf
{
namespace pe
{
namespace collision
{
	class CCollisionSystem;
}
namespace rigid
{
	class CRigidSystem;
}
namespace world
{
	class CForceAffector;

	using namespace lf;

	//!
	class LFPE_DLL_EXPORT CPeWorld
	{
	public:
		//! Default Constructor
		CPeWorld(collision::CCollisionSystem* collisionSystem = 0);

		//! Destructor
		~CPeWorld();

		//! returns the ODE internal worldID
		dWorldID getWorldID() const;

		//! return the collision system of the world
		collision::CCollisionSystem* getCollisionSystem() const;

		//! returns the rigid system of the world
		rigid::CRigidSystem* getRigidSystem() const;

		//! collides all geoms
		void collideGeoms();

		//! translates all SceneNodes attached to scene node controler object
		void translateSceneNodes();

	protected:
		//! ODE internal worldID
		dWorldID worldID;

		//! collision system for world
		collision::CCollisionSystem* collisionSystem;

		//! true if collision system was created internally
		//! false for external collision system
		bool deleteCollisionSystem;

		//! rigid system for world
		rigid::CRigidSystem* rigidSystem;
	};

} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // __C_PE_WORLD_H__
