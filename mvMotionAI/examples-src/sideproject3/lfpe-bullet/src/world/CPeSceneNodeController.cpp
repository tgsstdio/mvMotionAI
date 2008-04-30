// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#include <lfpe-bullet/world/CPeSceneNodeController.h>
#include <lfpe-bullet/world/CPeSceneNodeControllerContainer.h>


namespace lf
{
namespace pe
{
namespace world
{
		//! default-constructor
		CPeSceneNodeController::CPeSceneNodeController(CPeSceneNodeControllerContainer* container)
		 : container(container), sceneNode(0),
			autoTranslatePos(true), autoTranslateRot(true), autoTranslateMoveChilds(true)
		{
			container->addSceneNodeControler(this);
		}

		//! destructor
		CPeSceneNodeController::~CPeSceneNodeController()
		{
			detachSceneNode();
			container->removeSceneNodeControler(this);
		}

		//! returns the world where the scene node controler belongs to
		CPeSceneNodeControllerContainer* CPeSceneNodeController::getContainer() const
		{
			return container;
		}

		//! Attaches the given scene node to this object
		//! \param sceneNode: scene node to attach or 0 to detach
		void CPeSceneNodeController::attachSceneNode( scene::CSceneNode *sceneNode )
		{
			if( this->sceneNode )
			{
				this->sceneNode->drop();
			}
			this->sceneNode = sceneNode;
			if( this->sceneNode )
			{
				this->sceneNode->grab();
			}
		}

		//! detaches the attached scene node
		void CPeSceneNodeController::detachSceneNode()
		{
			attachSceneNode( 0 );
		}

		//! assigns the position and translation to the attached scene node.
		void CPeSceneNodeController::assignTranslation()
		{
			if( sceneNode )
			{
				// todo: set global position/rotation of sceneNode, not local
				if( autoTranslatePos )
				{
					sceneNode->setPosition( getPosition() );
				}
				if( autoTranslateRot )
				{
					sceneNode->setRotation( getRotation() );
				}
				if( !autoTranslateMoveChilds )
				{
					assert( false );
					// not supported yet!
					// todo: undo movement for all childs
				}
			}
		}

		//! sets if the translation should be automatically assigned to the attached
		//! scene node by the world object. Default is true
		//! \param pos: translate position
		//! \param rot: translate rotation
		//! \param moveChilds: also move childs of scene node
		void CPeSceneNodeController::setAutoTranslateFlags( bool pos, bool rot, bool moveChilds )
		{
			autoTranslatePos = pos;
			autoTranslateRot = rot;
			autoTranslateMoveChilds = moveChilds;
		}

		//! returns if the translation should be automatically assigned to the attached
		//! scene node by the world object.
		//! \param pos: translate position
		//! \param rot: translate rotation
		//! \param moveChilds: also move childs of scene node
		void CPeSceneNodeController::getAutoTranslateFlags( bool& pos, bool& rot, bool& moveChilds ) const
		{
			pos = autoTranslatePos;
			rot = autoTranslateRot;
			moveChilds = autoTranslateMoveChilds;
		}

		//! Set the rotation of the object.
		//! \param rotation: a vector containing the x,y and z rotations in degrees
		void CPeSceneNodeController::setRotationDegrees(const core::vector3df& rotation)
		{
			core::quaternion q;
			q.setDegrees(rotation);
			setRotation(q);
		}

		//! Set the rotation of the object.
		//! \param rotation: a vector containing the x,y and z rotations in radians
		void CPeSceneNodeController::setRotation(const core::vector3df& rotation)
		{
			core::quaternion q;
			q.set(rotation);
			setRotation(q);
		}

		//! Set the rotation of the object.
		//! \param x: new local rotation around the x-axis in degrees
		//! \param y: new local rotation around the y-axis in degrees
		//! \param z: new local rotation around the z-axis in degrees
		void CPeSceneNodeController::setRotationDegrees(f32 x, f32 y, f32 z)
		{
			core::quaternion q;
			q.setDegrees(x, y, z);
			setRotation(q);
		}

		//! Set the rotation of the object.
		//! \param x: new local rotation around the x-axis in radians
		//! \param y: new local rotation around the y-axis in radians
		//! \param z: new local rotation around the z-axis in radians
		void CPeSceneNodeController::setRotation(f32 x, f32 y, f32 z)
		{
			core::quaternion q(x, y, z);
			setRotation(q);
		}

		//! set the local rotation from an axis and an angle, angle in degrees
		//! \param axis: axis around which to rotate
		//! \param angle: how many degrees to rotate around the axis
		void CPeSceneNodeController::setRotationDegrees(const core::vector3df& axis, f32 angle)
		{
			core::quaternion q;
			q.setDegrees(axis, angle);
			setRotation(q);
		}

		//! Set the rotation of the object.
		//! \param axis: axis around which to rotate
		//! \param angle: how many radians to rotate around the axis
		void CPeSceneNodeController::setRotation(const core::vector3df& axis, f32 angle)
		{
			core::quaternion q(axis, angle);
			setRotation(q);
		}

		//! coneverts an ode quaternion into an lf quaternion
		void CPeSceneNodeController::peQuaternionToLfQuaternion(const btQuaternion& peq, core::quaternion& lf ) const
		{
			lf.X = peq.getX();
			lf.Y = peq.getY();
			lf.Z = peq.getZ();
			lf.W = peq.getW();
		}

		//! coneverts an lf quaternion into an ode quaternion
		void CPeSceneNodeController::lfQuaternionToPeQuaternion(const core::quaternion& lf, btQuaternion& peq ) const
		{
			peq.setX((btScalar) lf.X);
			peq.setY((btScalar) lf.Y);
			peq.setZ((btScalar) lf.Z);
			peq.setW((btScalar) lf.W);
		}

} // end namespace world
} // end namespace pe
} // end namespace lf


