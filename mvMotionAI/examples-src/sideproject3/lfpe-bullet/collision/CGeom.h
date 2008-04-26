// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_H_
#define _C_GEOM_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/collision/IGeomListener.h>
#include <lfpe/collision/IGeomAttacher.h>
#include <lfpe/world/CPeSceneNodeController.h>
#include <lf/Lightfeather.h>
#include <lf/core/list.h>

#include <ode/ode.h>

namespace lf
{
namespace pe
{
namespace collision
{
	class CGeomSpace;
	class CCollisionSystem;
	
	using namespace lf;
	
	//! Geometry objects (or "geoms" for short) are the fundamental objects in the collision system. A geom can
	//! represents a single rigid shape (such as a sphere or box), or it can represents a group of other geoms - this is
	//! a special kind of geom called a "space".
	//! Any geom can be collided against any other geom to yield zero or more contact points. Spaces have the
	//! extra capability of being able to collide their contained geoms together to yield internal contact points.
	//! Geoms can be placeable or non-placeable. A placeable geom has a position vector and a 3*3 rotation
	//! matrix, just like a rigid body, that can be changed during the simulation. A non-placeable geom does not
	//! have this capability - for example, it may represent some static feature of the environment that can not be
	//! moved. Spaces are non-placeable geoms, because each contained geom may have its own position and
	//! orientation but it does not make sense for the space itself to have a position and orientation.
	//! To use the collision engine in a rigid body simulation, placeable geoms are associated with rigid body
	//! objects. This allows the collision engine to get the position and orientation of the geoms from the bodies.
	//! Note that geoms are distinct from rigid bodies in that a geom has geometrical properties (size, shape, position
	//! and orientation) but no dynamical properties (such as velocity or mass). A body and a geom together
	//! represent all the properties of the simulated object.
	//! Every geom is an instance of a class, such as sphere, plane, or box. There are a number of built-in
	//! classes, described below, and you can define your own classes as well.
	//! The point of reference of a placeable geoms is the point that is controlled by its position vector. The point
	//! of reference for the standard classes usually corresponds to the geom’s center of mass. This feature allows
	//! the standard classes to be easily connected to dynamics bodies. If other points of reference are required, a
	//! transformation object can be used to encapsulate a geom.
	//! The concepts and functions that apply to all geoms will be described below, followed by the various
	//! geometry classes and the functions that manipulate them.
	class LFPE_DLL_EXPORT CGeom : public world::CPeSceneNodeController
	{
	public:
		//! default-constructor
		//! \collisionSystem: owner of geom
		//! \param space: parent space. Musbe null if this geom is ofsetted by a transform geom
		//!               In all other cases space must not be null!
		CGeom(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Destructor
		virtual ~CGeom();
	
		//! returns the collision system where this geom belongs to
		CCollisionSystem* getCollisionSystem() const;
		
		//! returns the ODE internal geomID
		dGeomID getGeomID() const;
		
		//! returns if the geom is placeable
		virtual bool isPlaceable() const;
		
		//! returns the ode internal geom ID of the alternative geom
		virtual dGeomID getGeomIDalt() const;
		
		//! updates the translation of the alternative geom
		virtual void updateAltGeomTranslation();
		
		//! returns true if the alternative geom is needed for collision with the given geom
		virtual bool needAltGeom(CGeom* other) const;
		
		//! returns the parent GeomSpace
		CGeomSpace* getParentSpace() const;

		//! Sets the geomattacher to this geom.
		//! This function must not be used from external.
		//! \param geomAttacher: geom attacher where this geom is attached to
		void _setGeomAttacher(IGeomAttacher* geomAttacher);

		////! returns the geoms attacher where this geom is attached to
		IGeomAttacher* getGeomAttacher() const;

		//! Set the position of a geom. These functions are analogous. If the geom is attached
		//! to a body, the body’s position / rotation / quaternion will also be changed.
		//! \param pos: new position
		virtual void setPosition(const core::vector3df& pos);

		//! returns the position of the geom
		virtual core::vector3df getPosition() const;

		//! returns the position of the geom
		//! \param pos: position of geom
		virtual void getPosition(core::vector3df& pos) const;

		//! Set the rotation as quaternion of a geom. If the geom is attached
		//! to a body, the body’s position / rotation / quaternion will also be changed.
		//! \param rot: new rotation
		virtual void setRotation( const core::quaternion& rot );

		//! returns the rotation as an quaternion of the geom
		virtual core::quaternion getRotation() const;

		//! returns the rotation as an quaternion of the geom
		//! \param rot: rotation of geom
		virtual void getRotation(core::quaternion& rot) const;

/*		Return in aabb an axis aligned bounding box that surrounds the given geom. The aabb array has
		elements (minx,maxx, miny, maxy, minz, maxz). If the geom is a space, a bounding box that
		surrounds all contained geoms is returned.
		This function may return a pre-computed cached bounding box, if it can determine that the geom has
		not moved since the last time the bounding box was computed.
		void dGeomGetAABB (dGeomID, dReal aabb[6]);
*/
/*		Return 1 if the given geom is a space, or 0 if not.
		dSpaceID dGeomGetSpace (dGeomID);
		Return the space that the given geometry is contained in, or return 0 if it is not contained in any space.
		int dGeomIsSpace (dGeomID);
*/

/*		Given a geom, this returns its class number. The standard class numbers are:
		dSphereClass Sphere
		dBoxClass Box
		dCCylinderClass Capped cylinder
		dCylinderClass Regular flat-ended cylinder
		dPlaneClass Infinite plane (non-placeable)
		dGeomTransformClass Geometry transform
		dRayClass Ray
		dTriMeshClass Triangle mesh
		dSimpleSpaceClass Simple space
		dHashSpaceClass Hash table based space
		User defined classes will return their own numbers.
		int dGeomGetClass (dGeomID);
*/
		//! Set the "category" bitfields for the given geom. These bitfields are use by spaces
		//! to govern which geoms will interact with each other. The bit fields are guaranteed to be at least 32 bits
		//! wide. The default category values for newly created geoms have all bits set.
		//! \param bits: bits
		void setCategoryBits(u32 bits);

		//! Get the "category" bitfields for the given geom. These bitfields are use by spaces
		//! to govern which geoms will interact with each other. The bit fields are guaranteed to be at least 32 bits
		//! wide. The default category values for newly created geoms have all bits set.
		u32 getCategoryBits() const;

		//! Set the "collide" bitfields for the given geom. These bitfields are use by spaces
		//! to govern which geoms will interact with each other. The bit fields are guaranteed to be at least 32 bits
		//! wide. The default collide values for newly created geoms have all bits set.
		//! \param bits: bits
		void setCollideBits(u32 bits);

		//! Get the "collide" bitfields for the given geom. These bitfields are use by spaces
		//! to govern which geoms will interact with each other. The bit fields are guaranteed to be at least 32 bits
		//! wide. The default collide values for newly created geoms have all bits set.
		u32 getCollideBits() const;

		//! Enable a geom. Disabled geoms are completely ignored by spaceCollide() and spaceCollide2(),
		//! although they can still be members of a space.
		//! New geoms are created in the enabled state.
		void geomEnable();

		//! Disable a geom. Disabled geoms are completely ignored by spaceCollide() and spaceCollide2(),
		//! although they can still be members of a space.
		//! New geoms are created in the enabled state.
		void geomDisable();

		//! geomIsEnabled() returns true if a geom is enabled or false if it is disabled. 
		//! New geoms are created in the enabled state.
		bool geomIsEnabled() const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth(const core::vector3df& pos) const = 0;

		//! returns true if this geom can collide with the other
		//! This function is called if the two geoms can collide, but before the collision points
		//! are computed. If the two geoms should never collide it's good to return false to save time.
		//! the default implementation returns always true with one exception:
		//! If the two geoms have attached bodies which are connected directly by a joint
		//! then it rezurns false.
		virtual bool canCollideWith(CGeom* other);

		//! this function is called if this geom collides with the other
		//! \param other: other geom
		//! \param contacts: array with contact information
		//! \param numContacts: number of contacts in the array
		virtual void doCollideWith(CGeom* other, dContactGeom* contacts, s32 numContacts);

		//! add a geom-listener
		//! \param listener: listener
		void addGeomListener(IGeomListener *listener);

		//! remove a geom-listener
		//! \param listener: listener
		void removeGeomListener(IGeomListener *listener);

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
		bool fireCanCollide(CGeom* other, bool& can);

		//! notifies all listeners
		bool fireDoCollide(CGeom* other, dContactGeom* contacts, s32 numContacts);

	protected:
		//! the collision system where this geom belongs to
		CCollisionSystem* collisionSystem;
		
		//! pointer to parent geom, can be null
		CGeomSpace*			parentSpace;
		
		//! ODE internal geomID
		dGeomID				geomID;
		
		//! alternative geom, if there are not all collision to other geoms are provided
		dGeomID				geomIDalt;
		
		//! list with geom listeners
		core::list<IGeomListener *> geomListeners;
		
		//! user defined tag info
		s32					tag;
		
		//! user defined data
		void* data;
		
		//! geom attacher
		IGeomAttacher* geomAttacher;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _C_GEOM_H_
