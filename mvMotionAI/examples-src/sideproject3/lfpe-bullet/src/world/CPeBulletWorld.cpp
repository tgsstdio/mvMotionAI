// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#include <lfpe-bullet/world/CPeBulletWorld.h>
#include <lfpe-bullet/collision/CCollisionSystem.h>
#include <lfpe-bullet/rigid/CRigidSystem.h>



{
namespace pe
{
namespace world
{
		//! default-constructor
		CPeBulletWorld::CPeBulletWorld(collision::CCollisionSystem* collisionSystem /*= 0*/)
		{
			worldID = dWorldCreate();
			assert( worldID );

			if(collisionSystem == 0)
			{
				deleteCollisionSystem = true;
				this->collisionSystem = new collision::CCollisionSystem();
			}
			else
			{
				deleteCollisionSystem = false;
				this->collisionSystem = collisionSystem;
			}

			rigidSystem = new rigid::CRigidSystem(this);
		}

		//! destructor
		CPeBulletWorld::~CPeBulletWorld()
		{
			if(deleteCollisionSystem && collisionSystem)
			{
				delete collisionSystem;
			}

			delete rigidSystem;

			dWorldDestroy( worldID );
			dCloseODE();
		}

		//! returns the ODE internal worldID
		dWorldID CPeBulletWorld::getWorldID() const
		{
			return worldID;
		}

		//! return the collision system of the world
		collision::CCollisionSystem* CPeBulletWorld::getCollisionSystem() const
		{
			return collisionSystem;
		}

		//! returns the rigid system of the world
		rigid::CRigidSystem* CPeBulletWorld::getRigidSystem() const
		{
			return rigidSystem;
		}

		//! collides all geoms
		void CPeBulletWorld::collideGeoms()
		{
			rigidSystem->clearCollisionJoints();
			collisionSystem->collideGeoms();
		}

		//! translates all SceneNodes attached to scene node controler object
		void CPeBulletWorld::translateSceneNodes()
		{
			collisionSystem->translateSceneNodes();
			rigidSystem->translateSceneNodes();
		}

} // end namespace world
} // end namespace pe
} // end namespace lf
