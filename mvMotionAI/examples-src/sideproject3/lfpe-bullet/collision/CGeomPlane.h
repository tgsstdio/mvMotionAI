// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_PLANE_H_
#define _C_GEOM_PLANE_H_

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
	
	//! The plane’s normal vector is, and it must have length 1. Planes are non-placeable geoms. This
	//! means that, unlike placeable geoms, planes do not have an assigned position and rotation. This means
	//! that the parameters are always in global coordinates. In other words it is assumed that the
	//! plane is always part of the static environment and not tied to any movable object.
	class LFPE_DLL_EXPORT CGeomPlane : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomPlane(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param normal: new normal vector
		//! \param d: Height at origin
		CGeomPlane(CCollisionSystem* collisionSystem, CGeomSpace* space, core::vector3df normal, f32 d);
		
		//! Destructor
		virtual ~CGeomPlane();
	
		//! Set the parameters of the given plane.
		//! \param normal: new normal vector
		//! \param d: Height at origin
		void setParams( core::vector3df normal, f32 d );

		//! Return in the parameters of the given plane.
		//! \param normal: new normal vector
		//! \param d: Height at origin
		void getParams( core::vector3df& normal, f32& d ) const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth( const core::vector3df& pos ) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // __C_GEOM_PLANE_H__
