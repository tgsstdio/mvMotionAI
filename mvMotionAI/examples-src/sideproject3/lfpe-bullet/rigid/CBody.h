// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_BODY_H_
#define _C_BODY_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/world/CPeSceneNodeController.h>
#include <lfpe/collision/IGeomAttacher.h>
#include <lfpe/collision/IGeomListener.h>
#include <lf/Lightfeather.h>

#include <ode/ode.h>


namespace lf
{
namespace pe
{
namespace collision
{
	class CGeom;
}
namespace rigid
{
	class IBodyListener;
	class CRigidSystem;
	class CMass;
	
	using namespace lf;

	//! 
	class LFPE_DLL_EXPORT CBody :
		public world::CPeSceneNodeController,
		public collision::IGeomAttacher,
		public collision::IGeomListener
	{
	public:
		//! Default Constructor
		CBody(CRigidSystem* rigidSystem);
		
		//! Destructor
		virtual ~CBody();
	
		//! returns the ODE internal bodyID
		dBodyID getBodyID() const;
		
		//! returns the rigid system the body belongs to
		CRigidSystem* getRigidSystem() const;
		
		//! returns the type of the geom attacher
		virtual collision::E_GEOM_ATTACHER_TYPE getGeomAttacherType() const;
		
		//! attaches a geom to this body
		//! a attached geom is moved and rotated automatically with the body
		//! if the geom was attached to an other body before, then it gets detached from it
		//! \param geom: the geom to attach
		virtual void attachGeom(collision::CGeom* geom);
		
		//! detaches a geom from this body
		//! returns true if the geom was successfully detached
		//! \param geom: the geom to detach
		virtual bool detachGeom(collision::CGeom* geom);
		
		//! returns if the geom is attached to this body
		//! \param geom: geom to check
		virtual bool isGeomAttached(collision::CGeom* geom) const;
		
		//! detaches all geoms from this body
		virtual void detachAllGeoms();
		
		//! gets called by a geom that is verry likely to collide with an other geom
		//! the 1st geom is the source of the event. the 2nd geom is other.
		//! can must be set to true if the geoms can collide, else set it to false.
		//! the preset of can is true
		//! if the event gets consumed, then no more listeners will receive the event
		//! if no listener does consume the event, the event is also called for the other geom.
		virtual void canCollide(collision::CGeomEvent& event, 
			collision::CGeom* other, bool& can);

		//! gets called if the sorce geom collides with the other geom
		virtual void doCollide(collision::CGeomEvent& event, collision::CGeom* other, 
			dContactGeom* contacts, s32 numContacts);

		//! Set the position of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param pos: new position
		virtual void setPosition(const core::vector3df& pos);

		//! Get the position of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param :
		virtual core::vector3df getPosition() const;
		
		//! Get the position of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param pos: position
		virtual void getPosition(core::vector3df& pos) const;

		//! Set the rotation of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param rot: new rotation as quaternion
		virtual void setRotation(const core::quaternion& rot);

		//! Get the rotation of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		virtual core::quaternion getRotation() const;
		
		//! Get the rotation of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param rot: rotation as quaternion
		virtual void getRotation(core::quaternion& rot) const;

		//! Set the linear velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param vel: new linear velocity
		void setLinearVel(const core::vector3df& vel);

		//! Get the linear velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		core::vector3df getLinearVel() const;
		
		//! Get the linear velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param vel: linear velocity
		void getLinearVel(core::vector3df& vel) const;

		//! Set the angular velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param vel: new angular velocity
		void setAngularVel(const core::vector3df& vel);

		//! Get the angular velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param : 
		core::vector3df getAngularVel() const;

		//! Get the angular velocity of the body. After setting
		//! a group of bodies, the outcome of the simulation is undefined if the new configuration is inconsistent
		//! with the joints/constraints that are present. When getting, the returned values are pointers to internal
		//! data structures, so the vectors are valid until any changes are made to the rigid body system structure.
		//! \param vel: angular velocity
		void getAngularVel(core::vector3df& vel) const;

		//! Set the mass of the body.
		//! \param mass: new mass
		void setMass(CMass* mass);

		//! Get the mass of the body.
		//! \param mass: mass
		void getMass(CMass* mass) const;

		//! Adds force to the body. 
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! Applies the force at the center of mass.
		//! \param force: force to apply
		void addForce(const core::vector3df& force);

		//! Adds torque to the body.
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! Applies the torque at the center of mass.
		//! \param torque: torque to apply
		void addTorque(const core::vector3df& torque);

		//! Adds force to the body.
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! The force vectors is relative to the body’s own frame of reference.
		//! Applies the force at the center of mass.
		//! \param : 
		void addRelForce(const core::vector3df& force);

		//! Adds torque to the body.
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! The torque vectors is relative to the body’s own frame of reference.
		//! Applies the torque at the center of mass.
		//! \param torque: torque to apply
		void addRelTorque(const core::vector3df& torque);

		//! Adds force to the body. 
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! Applies the force at the given position.
		//! \param force: force to apply
		void addForceAtPos(const core::vector3df& force, const core::vector3df& pos);

		//! Adds force to the body. 
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! Applies the force at the given position relative to the body.
		//! \param force: force to apply
		void addForceAtRelPos(const core::vector3df& force, const core::vector3df& pos);

		//! Adds force to the body. 
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! The force vectors is relative to the body’s own frame of reference.
		//! Applies the force at the given position.
		//! \param force: force to apply
		void addRelForceAtPos(const core::vector3df& force, const core::vector3df& pos);

		//! Adds force to the body. 
		//! The forces are accumulated on to each body, and the accumulators are zeroed after each time step.
		//! The force vectors is relative to the body’s own frame of reference.
		//! Applies the force at the given position relative to the body.
		//! \param force: force to apply
		void addRelForceAtRelPos(const core::vector3df& force, const core::vector3df& pos);

		//! Return the current accumulated force vector.
		//! The returned values are pointers to internal data structures, so the vectors are only valid until
		//! any changes are made to the rigid body system.
		core::vector3df getForce() const;

		//! Return the current accumulated torque vector. 
		//! The returned values are pointers to internal data structures, so the vectors are only valid until
		//! any changes are made to the rigid body system.
		core::vector3df getTorque() const;

		//! Set the body force accumulation vectors. This is mostly useful to zero the force and torque
		//! for deactivated bodies before they are reactivated, in the case where the force-adding functions were
		//! called on them while they were deactivated.
		//! \param force: new force
		void setForce(const core::vector3df& force);

		//! Set the body torque accumulation vectors. This is mostly useful to zero the force and torque
		//! for deactivated bodies before they are reactivated, in the case where the force-adding functions were
		//! called on them while they were deactivated.
		//! \param force: new force
		void setTorque(const core::vector3df& torque);

		//! Utility functions that take a point on a body and return that point’s position 
		//! in global coordinates (in result).
		//! \param pos: body relative position
		//! \param result: position in global space
		void getRelPointPos(const core::vector3df& pos, core::vector3df& result) const;

		//! Utility functions that take a point on a body and return that point’s velocity 
		//! in global coordinates (in result).
		//! \param pos: body relative position
		//! \param result: velocity in global space
		void getRelPointVel(const core::vector3df& pos, core::vector3df& result) const;

		//! Utility functions that take a point and return that point’s velocity 
		//! in global coordinates (in result).
		//! \param pos: position
		//! \param result: velocity in global space
		void getPointVel(const core::vector3df& pos, core::vector3df& result) const;
		
		//! This is the inverse of getRelPointPos(). It takes a point in global coordinates and returns
		//! the point’s position in body-relative coordinates (result).
		//! \param pos: position
		//! \param result: position in body space
		void getPosRelPoint(const core::vector3df& pos, core::vector3df& result) const;
		
		//! Given a vector expressed in the body coordinate system, rotate it to the world
		//! coordinate system (result).
		//! \param v: vector in body space
		//! \param result: result in world space
		void bodyVectorToWorld(const core::vector3df& v, core::vector3df& result) const;

		//! Given a vector expressed in the world coordinate system, rotate it to the
		//! body coordinate system (result).
		//! \param v: vector in world space
		//! \param result: result in body space
		void bodyVectorFromWorld(const core::vector3df& v, core::vector3df& result) const;

		//! Manually enable a body. Note that a disabled body that is connected through a joint to an
		//! enabled body will be automatically re-enabled at the next simulation step.
		void enable();

		//! Manually disable a body. Note that a disabled body that is connected through a joint to an
		//! enabled body will be automatically re-enabled at the next simulation step.
		void disable();

		//! Return true if a body is currently enabled or false if it is disabled.
		bool isEnabled() const;

		//! Set the auto-disable flag of a body. If the do auto disable is nonzero the body will be
		//! automatically disabled when it has been idle for long enough.
		//! \param do_auto_disable: 
		void setAutoDisableFlag(bool do_auto_disable);

		//! Get the auto-disable flag of a body. If the do auto disable is nonzero the body will be
		//! automatically disabled when it has been idle for long enough.
		bool getAutoDisableFlag() const;

		//! Set a body’s linear velocity threshold for automatic disabling. The body’s linear velocity
		//! magnitude must be less than this threshold for it to be considered idle. Set the threshold to dInfinity
		//! to prevent the linear velocity from being considered.
		//! \param linear_threshold: new linear threshold
		void setAutoDisableLinearThreshold(f32 linear_threshold);

		//! Get a body’s linear velocity threshold for automatic disabling. The body’s linear velocity
		//! magnitude must be less than this threshold for it to be considered idle. Set the threshold to dInfinity
		//! to prevent the linear velocity from being considered.
		f32 getAutoDisableLinearThreshold() const;

		//! Set a body’s angular velocity threshold for automatic disabling. The body’s linear angular
		//! magnitude must be less than this threshold for it to be considered idle. Set the threshold to dInfinity
		//! to prevent the angular velocity from being considered.
		//! \param angular_threshold: new angulat threshold
		void setAutoDisableAngularThreshold(f32 angular_threshold);

		//! Get a body’s angular velocity threshold for automatic disabling. The body’s linear angular
		//! magnitude must be less than this threshold for it to be considered idle. Set the threshold to dInfinity
		//! to prevent the angular velocity from being considered.
		//! \param angular_threshold: new angulat threshold
		f32 getAutoDisableAngularThreshold() const;

		//! Set the number of simulation steps that a body must be idle before it is automatically disabled.
		//! Set this to zero to disable consideration of the number of steps.
		//! \param steps: number of steps
		void setAutoDisableSteps(dBodyID, s32 steps);

		//! Get the number of simulation steps that a body must be idle before it is automatically disabled.
		//! Set this to zero to disable consideration of the number of steps.
		s32 getAutoDisableSteps() const;

		//! Set the amount of simulation time that a body must be idle before it is automatically disabled.
		//! Set this to zero to disable consideration of the amount of simulation time.
		//! \param time: time
		void setAutoDisableTime(f32 time);

		//! Get the amount of simulation time that a body must be idle before it is automatically disabled.
		//! Set this to zero to disable consideration of the amount of simulation time.
		//! \param time: time
		f32 getAutoDisableTime() const;

		//! Set the auto-disable parameters of the body to the default parameters that have been set on the world.
		void setAutoDisableDefaults();

		//! This function controls the way a body’s orientation is updated at each time step.
		//! The mode argument can be:
		//! - false: An "infinitesimal" orientation update is used. This is fast to compute, but it can occasionally
		//!   cause inaccuracies for bodies that are rotating at high speed, especially when those bodies are
		//!   joined to other bodies. This is the default for every new body that is created.
		//! - true: A "finite" orientation update is used. This is more costly to compute, but will be more accurate
		//!   for high speed rotations. Note however that high speed rotations can result in many types of error
		//!   in a simulation, and this mode will only fix one of those sources of error.
		//! \param finite: true if finite, else false
		void setFiniteRotationMode(bool finite);

		//! Return the current finite rotation mode of a body.
		bool getFiniteRotationMode() const;

		//! This sets the finite rotation axis for a body. This is axis only has meaning when the finite rotation mode
		//! is set (see dBodySetFiniteRotationMode()).
		//! If this axis is zero (0,0,0), full finite rotations are performed on the body.
		//! If this axis is nonzero, the body is rotated by performing a partial finite rotation along the axis direction
		//! followed by an infinitesimal rotation along an orthogonal direction.
		//! This can be useful to alleviate certain sources of error caused by quickly spinning bodies. For example,
		//! if a car wheel is rotating at high speed you can call this function with the wheel’s hinge axis as the
		//! argument to try and improve its behavior.
		//! \param axis: new axis
		void setFiniteRotationAxis(const core::vector3df& axis);

		//! Return the current finite rotation axis of a body.
		//! \param result: axis
		void getFiniteRotationAxis(core::vector3df& result) const;

		//! Return the number of joints that are attached to this body.
		s32 getNumJoints() const;
		
/*		Return a joint attached to this body, given by index. Valid indexes are 0 to n?1 where n is the value
		returned by dBodyGetNumJoints().
		dJointID dBodyGetJoint (dBodyID, int index);
		dJointID dBodyGetJoint (dBodyID, int index);
*/
		//! Set whether the body is influenced by the world’s gravity or not. If mode is nonzero it is, if mode
		//! is zero, it isn’t. Newly created bodies are always influenced by the world’s gravity.
		//! \param mode: true if influenced, else false
		void setGravityMode(bool mode);

		//! Get whether the body is influenced by the world’s gravity or not. If mode is nonzero it is, if mode
		//! is zero, it isn’t. Newly created bodies are always influenced by the world’s gravity.
		bool getGravityMode() const;

		//! add a body-listener
		//! \param listener: listener
		void addBodyListener(IBodyListener* listener);

		//! remove a body-listener
		//! \param listener: listener
		void removeBodyListener(IBodyListener* listener);

		//! Set user defined tag info
		//! \param t: tag
		void setTag(s32 t);
		
		//! Get user defined tag info
		s32 getTag() const;
		
		//! Set user defined data
		//! \param data: data
		void setData(void* data);
		
		//! Get user defined data
		void* getData() const;

	protected:
		//! notifies all listeners
		bool fireGetGeomContactParams(
			collision::CGeom* geom1, collision::CGeom* geom2, dContact* contact);

	protected:
		//! the rigid system where this body belongs to
		CRigidSystem* rigidSystem;
		
		//! ODE internal bodyID
		dBodyID bodyID;
		
		//! list with attached geoms
		core::list<collision::CGeom*> attachedGeoms;

		//! list with body listeners
		core::list<IBodyListener*> bodyListeners;

		//! user defined tag info
		s32					tag;
		
		//! user defined data
		void* data;
	};

} // end namespace rigid
} // end namespace pe
} // end namespace lf

#endif // __C_BODY_H__
