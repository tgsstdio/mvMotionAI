// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_RIGID_SYSTEM_H_
#define _C_RIGID_SYSTEM_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/world/CPeSceneNodeControllerContainer.h>
#include <lf/Lightfeather.h>
#include <ode/ode.h>

namespace lf
{
namespace pe
{
namespace world
{
	class CPeWorld;
}
namespace collision
{
	class CGeom;
}
namespace rigid
{
	class CForceAffector;
	
	using namespace lf;
	
	//! 
	class LFPE_DLL_EXPORT CRigidSystem :
		public world::CPeSceneNodeControllerContainer
	{
	public:
		//! Default Constructor
		CRigidSystem(world::CPeWorld* world);
		
		//! Destructor
		virtual ~CRigidSystem();
	
		//! returns the world where this rigid system belongs to
		world::CPeWorld* getWorld() const;
	
		//! returns thge ode internal id of the world where this rigid system belongs to
		dWorldID getWorldID() const;
	
		//! returns the ode internal JointGroupID used for the collision joints
		dJointGroupID getCollisionJointGroupID() const;
		
		//! deletes all collision joints.
		//! this method should be called to prepare collision.
		void clearCollisionJoints();
		
		//! Set the world’s global gravity vector. 
		//! The units are m/s/s, so Earth’s gravity vector would be
		//! (0,0,-9.81), assuming that +z is up. The default is no gravity, i.e. (0,0,0).
		//! \param gravity: gravity of the world
		void setGravity(const core::vector3df& gravity);
		
		//! Get the world’s global gravity vector. 
		//! The units are m/s/s, so Earth’s gravity vector would be
		//! (0,0,-9.81), assuming that +z is up. The default is no gravity, i.e. (0,0,0).
		//! \param gravity: gravity of the world
		void getGravity(core::vector3df& gravity) const;
		
		//! Get the world’s global gravity vector. 
		//! The units are m/s/s, so Earth’s gravity vector would be
		//! (0,0,-9.81), assuming that +z is up. The default is no gravity, i.e. (0,0,0).
		core::vector3df getGravity() const;
	
		//! Set the global ERP value
		//! that controls how much error correction is performed in each time
		//! step. Typical values are in the range 0.1–0.8. The default is 0.2.
		//! \param erp: new erp value
		void setERP(f32 erp);

		//! Get the global ERP value
		//! that controls how much error correction is performed in each time
		//! step. Typical values are in the range 0.1–0.8. The default is 0.2.
		f32 getERP() const;
		
		//! Set the global CFM (constraint force mixing) value.
		//! Typical values are in the range 10^-9 – 1.
		//! The default is 10^-5 if single precision is being used, 
		//! or 10^-10 if double precision is being used.
		//! \param cfm: new cfm value
		void setCFM(f32 cfm);
		
		//! Get the global CFM (constraint force mixing) value.
		//! Typical values are in the range 10^-9 – 1.
		//! The default is 10^-5 if single precision is being used, 
		//! or 10^-10 if double precision is being used.
		f32 getCFM() const;
		
		//! Set the default auto-disable parameter AutoDisableFlag for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		//! \param do_auto_disable: new flag
		void setAutoDisableFlag(bool do_auto_disable);
		
		//! Get the default auto-disable parameter AutoDisableFlag for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		bool getAutoDisableFlag() const;
		
		//! Set the default auto-disable parameter AutoDisableLinearThreshold for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		//! \param linear_threshold: new value
		void setAutoDisableLinearThreshold(f32 linear_threshold);
		
		//! Get the default auto-disable parameter AutoDisableLinearThreshold for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		f32 getAutoDisableLinearThreshold() const;
		
		//! Set the default auto-disable parameter AutoDisableAngularThreshold for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		//! \param angular_threshold: new value
		void setAutoDisableAngularThreshold(f32 angular_threshold);
		
		//! Get the default auto-disable parameter AutoDisableAngularThreshold for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		f32 getAutoDisableAngularThreshold() const;
		
		//! Set the default auto-disable parameter AutoDisableSteps for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		//! \param steps: new value
		void setAutoDisableSteps(s32 steps);
		
		//! Get the default auto-disable parameter AutoDisableSteps for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		s32 getAutoDisableSteps() const;
		
		//! Set the default auto-disable parameter AutoDisableTime for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		//! \param time: new value
		void setAutoDisableTime(f32 time);
		
		//! Get the default auto-disable parameter AutoDisableTime for newly created bodies.
		//! See ODE documentation section 6.5 for a description of the auto-disable feature. 
		//! The default parameters is false
		f32 getAutoDisableTime() const;

		//! If you want to apply a linear or angular impulse to a rigid body, instead of a force or a torque, then
		//! you can use this function to convert the desired impulse into a force/torque vector before calling the
		//! dBodyAdd... function.
		//! This function is given the desired impulse as (ix,iy,iz) and puts the force vector in force. The
		//! current algorithm simply scales the impulse by 1/stepsize, where stepsize is the step size for
		//! the next step that will be taken.
		//! \param stepsize: stepsize used by the next step
		//! \param impulse: impulse to convert
		//! \param force: calculated force for the impulse
		void impulseToForce(f32 stepsize, const core::vector3df& impulse, core::vector3df& force) const;

		//! Step the world. This uses a "big matrix" method that takes time on the order of m^3and memory on the
		//! order of m^2, where m is the total number of constraint rows.
		//! For large systems this will use a lot of memory and can be very slow, but this is currently the most
		//! accurate method.
		//! \param stepsize: step size	
		void step(f32 stepsize);

		//! Step the world. This uses an iterative method that takes time on the order of m*N and memory on the
		//! order of m, where m is the total number of constraint rows and N is the number of iterations.
		//! For large systems this is a lot faster than step(), but it is less accurate.
		//! QuickStep is great for stacks of objects especially when the auto-disable feature is used as well. However,
		//! it has poor accuracy for near-singular systems. Near-singular systems can occur when using
		//! high-friction contacts, motors, or certain articulated structures. For example, a robot with multiple legs
		//! sitting on the ground may be near-singular.
		//! There are ways to help overcome QuickStep’s inaccuracy problems:
		//! - Increase CFM.
		//! - Reduce the number of contacts in your system (e.g. use the minimum number of contacts for the
		//!   feet of a robot or creature).
		//! - Don’t use excessive friction in the contacts.
		//! - Use contact slip if appropriate
		//! - Avoid kinematic loops (however, kinematic loops are inevitable in legged creatures).
		//! - Don’t use excessive motor strength.
		//! - Use force-based motors instead of velocity-based motors.
		//! Increasing the number of QuickStep iterations may help a little bit, but it is not going to help much if
		//! your system is really near singular.	
		//! \param stepsize: step size	
		void quickStep(f32 stepsize);

		//! Set the number of iterations that the QuickStep method performs per step. More iterations will
		//! give a more accurate solution, but will take longer to compute. The default is 20 iterations.
		//! \param num: number of iterators
		void setQuickStepNumIterations(s32 num);

		//! Get the number of iterations that the QuickStep method performs per step. More iterations will
		//! give a more accurate solution, but will take longer to compute. The default is 20 iterations.
		s32 getQuickStepNumIterations() const;

		//! Set the maximum correcting velocity that contacts are allowed to generate. The default value
		//! is infinity (i.e. no limit). Reducing this value can help prevent "popping" of deeply embedded objects.
		//! param vel: max correcting velocity
		void setContactMaxCorrectingVel(f32 vel);

		//! Get the maximum correcting velocity that contacts are allowed to generate. The default value
		//! is infinity (i.e. no limit). Reducing this value can help prevent "popping" of deeply embedded objects.
		f32 getContactMaxCorrectingVel() const;

		//! Set the depth of the surface layer around all geometry objects. Contacts are allowed to sink into
		//! the surface layer up to the given depth before coming to rest. The default value is zero. Increasing this
		//! to some small value (e.g. 0.001) can help prevent jittering problems due to contacts being repeatedly
		//! made and broken.
		// \patam depth: max penetration depth
		void setContactSurfaceLayer(f32 depth);

		//! Get the depth of the surface layer around all geometry objects. Contacts are allowed to sink into
		//! the surface layer up to the given depth before coming to rest. The default value is zero. Increasing this
		//! to some small value (e.g. 0.001) can help prevent jittering problems due to contacts being repeatedly
		//! made and broken.
		f32 getContactSurfaceLayer() const;

		//! calls CForceAffector::step() for all (global and local) force affectors
		void stepForceAffectors(f32 timeDiff);
		
		//! Adds a global force affector
		void addGlobalForceAffector(CForceAffector* affector);
		
		//! removes a global force affector
		void removeGlobalForceAffector(CForceAffector* affector);
		
		//! applies the forces of all global force affectors to all bodies
		void applyGlobalForceAffectors();
		
		//! Adds a local force affector
		void addLocalForceAffector(CForceAffector* affector);
		
		//! removes a local force affector
		void removeLocalForceAffector(CForceAffector* affector);
		
	protected:
		//! the world
		world::CPeWorld* world;

		//! ode ID of the jaoint group used for collision points
		dJointGroupID collisionJointGroup;

		//! list with all global force affectors
		core::list<CForceAffector*> globalForceAffectors;

		//! list with all local force affectors (attached to geoms)
		core::list<CForceAffector*> localForceAffectors;
	};

} // end namespace rigid
} // end namespace pe
} // end namespace lf

#endif // _C_RIGID_SYSTEM_H_
