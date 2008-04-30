// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_PE_SCENE_NODE_CONTROLLER_H_
#define _C_PE_SCENE_NODE_CONTROLLER_H_

#include <lfpe-bullet/lfpeConfig.h>
#include <lf/Lightfeather.h>
#include <LinearMath/btQuaternion.h>

namespace lf
{
namespace pe
{
namespace world
{
	using namespace lf;

	class CPeSceneNodeControllerContainer;

	//!
	class LFPE_DLL_EXPORT CPeSceneNodeController : public CRefCounted
	{
	public:
		//! Default Constructor
		CPeSceneNodeController(CPeSceneNodeControllerContainer* container);

		//! Destructor
		virtual ~CPeSceneNodeController();

		//! returns the container where the scene node controler belongs to
		CPeSceneNodeControllerContainer* getContainer() const;

		//! Attaches the given scene node to this object
		//! \param sceneNode: scene node to attach or 0 to detach
		void attachSceneNode( scene::CSceneNode *sceneNode );

		//! detaches the attached scene node
		void detachSceneNode();

		//! assigns the position and translation to the attached scene node.
		//! if pos is false, no position is assigned
		//! if rot is false, no rattion is assigned
		//! if moveChilds is false, the worldTranslation of the scene node childs
		//! will stay the same
		void assignTranslation();

		//! sets if the translation should be automatically assigned to the attached
		//! scene node by the world object. Default is true
		//! \param pos: translate position
		//! \param rot: translate rotation
		//! \param moveChilds: also move childs of scene node
		void setAutoTranslateFlags( bool pos, bool rot, bool moveChilds );

		//! returns if the translation should be automatically assigned to the attached
		//! scene node by the world object.
		//! \param pos: translate position
		//! \param rot: translate rotation
		//! \param moveChilds: also move childs of scene node
		void getAutoTranslateFlags( bool& pos, bool& rot, bool& moveChilds ) const;

		//! Set the position of the object.
		//! \param pos: new position
		virtual void setPosition( const core::vector3df& pos ) = 0;

		//! Get the position of the object.
		virtual core::vector3df getPosition() const = 0;

		//! Get the position of the object.
		//! \param pos: position
		virtual void getPosition( core::vector3df& pos ) const = 0;

		//! Set the rotation of the object.
		//! \param rotation: a vector containing the x,y and z rotations in degrees
		virtual void setRotationDegrees(const core::vector3df& rotation);

		//! Set the rotation of the object.
		//! \param rotation: a vector containing the x,y and z rotations in radians
		virtual void setRotation(const core::vector3df& rotation);

		//! Set the rotation of the object.
		//! \param x: new local rotation around the x-axis in degrees
		//! \param y: new local rotation around the y-axis in degrees
		//! \param z: new local rotation around the z-axis in degrees
		virtual void setRotationDegrees(f32 x, f32 y, f32 z);

		//! Set the rotation of the object.
		//! \param x: new local rotation around the x-axis in radians
		//! \param y: new local rotation around the y-axis in radians
		//! \param z: new local rotation around the z-axis in radians
		virtual void setRotation(f32 x, f32 y, f32 z);

		//! set the local rotation from an axis and an angle, angle in degrees
		//! \param axis: axis around which to rotate
		//! \param angle: how many degrees to rotate around the axis
		virtual void setRotationDegrees(const core::vector3df& axis, f32 angle);

		//! Set the rotation of the object.
		//! \param axis: axis around which to rotate
		//! \param angle: how many radians to rotate around the axis
		virtual void setRotation(const core::vector3df& axis, f32 angle);

		//! Set the rotation of the object.
		//! \param rot: new rotation as quaternion
		virtual void setRotation( const core::quaternion& rot ) = 0;

		//! Get the rotation of the object.
		virtual core::quaternion getRotation() const = 0;

		//! Get the rotation of the object.
		//! \param rot: rotation as quaternion
		virtual void getRotation( core::quaternion& rot ) const = 0;

		//! coneverts an ode quaternion into an lf quaternion
		void peQuaternionToLfQuaternion( const btQuaternion& peq, core::quaternion& lf ) const;

		//! coneverts an lf quaternion into an ode quaternion
		void lfQuaternionToPeQuaternion( const core::quaternion& lf, btQuaternion& peq ) const;

	protected:
		CPeSceneNodeControllerContainer* container;
		scene::CSceneNode	*sceneNode;

		bool autoTranslatePos;
		bool autoTranslateRot;
		bool autoTranslateMoveChilds;
	};

} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // _C_PE_SCENE_NODE_CONTROLLER_H_
