// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_FORCE_AFFECTOR_H_
#define _C_FORCE_AFFECTOR_H_

#include <lfpe/lfpeConfig.h>
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
	class CBody;
	class CRigidSystem;
	
	using namespace lf;
	
	//! A force affector can be used to automatically apply forces to bodies.
	//! An affector can be made global (by adding it to the world) or local
	//! (by adding it to an geom). If a geom has an affector attached, then
	//! it does not collide with other geoms anymore. If the geom intersects with an other
	//! geom, and the other geom has an attached body, then the force is applied to this body.
	class LFPE_DLL_EXPORT CForceAffector :
		public CRefCounted,
		public collision::IGeomAttacher,
		public collision::IGeomListener
	{
	public:
		//! Default Constructor
		CForceAffector(CRigidSystem* rigidSystem);
		
		//! Destructor
		virtual ~CForceAffector();
	
		//! Returns the rigid system where the force affector belongs to
		CRigidSystem* getRigidSystem() const;
		
		//! returns the type of the geom attacher
		virtual collision::E_GEOM_ATTACHER_TYPE getGeomAttacherType() const;
		
		//! attaches a geom to this affector
		//! a attached geom is moved and rotated automatically with the body
		//! if the geom was attached to an other body before, then it gets detached from it
		//! \param geom: the geom to attach
		virtual void attachGeom(collision::CGeom* geom);
		
		//! detaches a geom from this affector
		//! returns true if the geom was successfully detached
		//! \param geom: the geom to detach
		virtual bool detachGeom(collision::CGeom* geom);
		
		//! returns if the geom is attached to this affector
		//! \param geom: geom to check
		virtual bool isGeomAttached(collision::CGeom* geom) const;
		
		//! detaches all geoms from this affector
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

		//! can be used to compute force for the next step
		virtual void step(f32 timeDiff);

		//! Applies the force to the center of mass of the given body.
		//! Must be implememnted in derivied class
		virtual void applyForce(CBody *body);

		//! Applies the force to the given global (world) position of the given body.
		//! Must be implememnted in derivied class
		virtual void applyForce(CBody* body, core::vector3df pos) = 0;

	protected:
		//! the rigid system
		CRigidSystem* rigidSystem;

		//! list with attached geoms
		core::list<collision::CGeom*> attachedGeoms;
	};
	
} // end namespace rigid
} // end namespace pe
} // end namespace lf


#endif // _C_FORCE_AFFECTOR_H_
