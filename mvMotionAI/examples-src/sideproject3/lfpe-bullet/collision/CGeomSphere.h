// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_SPHERE_H_
#define _C_GEOM_SPHERE_H_

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
	
	//! The point of reference for a sphere is its center.
	class LFPE_DLL_EXPORT CGeomSphere : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomSphere(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param radius : radius of the sphere
		CGeomSphere(CCollisionSystem* collisionSystem, CGeomSpace* space, f32 radius);
		
		//! Destructor
		virtual ~CGeomSphere();
	
		//! Set the radius of the given sphere.
		//! \param radius: new radius
		void setRadius( f32 radius );

		//! Return the radius of the given sphere.
		f32 getRadius() const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth( const core::vector3df& pos ) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_SPHERE_H__
