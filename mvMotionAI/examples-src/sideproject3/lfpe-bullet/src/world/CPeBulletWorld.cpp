// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#include <lfpe-bullet/world/CPeBulletWorld.h>
//#include <lfpe-bullet/collision/CCollisionSystem.h>
//#include <lfpe-bullet/rigid/CRigidSystem.h>


namespace lf
{
namespace pe
{
namespace world
{
		//! default-constructor
		CPeBulletWorld::CPeBulletWorld(collision::CCollisionDispatcher* cDispatcher,
			collision::CCollisionBroadphase* collisionBPhase,
			rigid::CConstraintSolver* constraintSolver,
			collision::CCollisionConfiguration* collisionConfig,
			btDynamicsWorld* worldPtr,
			LPFE_BULLET_PHYSICS_WORLD_TYPE type)
			: m_cDispatcher(cDispatcher), m_collisionBPhase(collisionBPhase),
			m_collisionConfig(collisionConfig), m_constraintSolver(constraintSolver),
			m_worldID(worldPtr), m_worldType(type)
		{
			if (m_cDispatcher)
			{
				m_cDispatcher->grab();
			}

			if (m_collisionBPhase)
			{
				m_collisionBPhase->grab();
			}

			if (m_collisionConfig)
			{
				m_collisionConfig->grab();
			}

			if(m_constraintSolver)
			{
				m_constraintSolver->grab();
			}
		}

		//! destructor
		CPeBulletWorld::~CPeBulletWorld()
		{
			if (m_cDispatcher)
			{
				m_cDispatcher->drop();
			}

			if (m_collisionBPhase)
			{
				m_collisionBPhase->drop();
			}

			if (m_collisionConfig)
			{
				m_collisionConfig->drop();
			}

			if(m_constraintSolver)
			{
				m_constraintSolver->drop();
			}

			if (m_worldID)
			{
				delete m_worldID;
			}
		}

		//! returns the ODE internal worldID
		btDynamicsWorld* CPeBulletWorld::getWorldID() const
		{
			return m_worldID;
		}

		//! return the collision system of the world
		collision::CCollisionDispatcher* CPeBulletWorld::getCollisionDispatcher() const
		{
			return m_cDispatcher;
		}

		//! returns the rigid system of the world
		rigid::CConstraintSolver* CPeBulletWorld::getConstraintSolver() const
		{
			return m_constraintSolver;
		}

		//! collides all geoms
		void CPeBulletWorld::collideGeoms()
		{
			//rigidSystem->clearCollisionJoints();
			//collisionSystem->collideGeoms();
		}

		//! translates all SceneNodes attached to scene node controler object
		void CPeBulletWorld::translateSceneNodes()
		{
			//collisionSystem->translateSceneNodes();
			//rigidSystem->translateSceneNodes();
		}

} // end namespace world
} // end namespace pe
} // end namespace lf
