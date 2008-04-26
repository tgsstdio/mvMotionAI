// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_RAY_H_
#define _C_GEOM_RAY_H_

#include <lfpe/lfpeConfig.h>
#include <lf/Lightfeather.h>
#include <lfpe/collision/CGeom.h>

#include <ode/ode.h>

namespace lf
{
namespace pe
{
namespace collision
{
	class CGeomSpace;
	using namespace lf;
	
	//! A ray is different from all the other geom classes in that it does not represent a solid object. It is an infinitely
	//! thin line that starts from the geom’s position and extends in the direction of the geom’s local Z-axis.
	//! Calling collide() between a ray and another geom will result in at most one contact point. Rays have
	//! their own conventions for the contact information in the dContactGeom structure (thus it is not useful to
	//! create contact joints from this information):
	//! - pos - This is the point at which the ray intersects the surface of the other geom, regardless of whether
	//!   the ray starts from inside or outside the geom.
	//! - normal - This is the surface normal of the other geom at the contact point. if dCollide() is passed
	//!   the ray as its first geom then the normal will be oriented correctly for ray reflection from that surface
	//!   (otherwise it will have the opposite sign).
	//! - depth - This is the distance from the start of the ray to the contact point.
	//!   Rays are useful for things like visibility testing, determining the path of projectiles or light rays, and for
	//!   object placement.
	class LFPE_DLL_EXPORT CGeomRay : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomRay(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param length : length of the Ray
		CGeomRay(CCollisionSystem* collisionSystem, CGeomSpace* space, f32 length);
		
		//! Destructor
		virtual ~CGeomRay();
	
		//! Set the length of the given Ray.
		//! \param radius: new length
		void setLength( f32 length );

		//! Return the length of the given Ray.
		f32 getLength() const;

		//! Set the starting position (px,py,pz) and direction (dx,dy,dz) of the given ray. The ray’s rotation
		//! matrix will be adjusted so that the local Z-axis is aligned with the direction. Note that this does not
		//! adjust the ray’s length.
		//! \param start: start position of the ray
		//! \param dir: direction of the ray
		void setParams( const core::vector3df& start, const core::vector3df& dir );

		//! Get the starting position (start) and direction (dir) of the ray. The returned direction will be a unit
		//! length vector.
		//! \param start: start position of the ray
		//! \param dir: direction of the ray
		void getParams( core::vector3df& start, core::vector3df& dir ) const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth( const core::vector3df& pos ) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_RAY_H__
