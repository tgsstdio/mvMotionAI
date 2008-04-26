// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_CYLINDER_H_
#define _C_GEOM_CYLINDER_H_

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
	class CTrimeshData;
	
	using namespace lf;
	
	//! The cylinder is aligned along the geom’s local Z axis.
	class LFPE_DLL_EXPORT CGeomCylinder : 
		public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomCylinder(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param radius : radius of the Cylinder
		CGeomCylinder(CCollisionSystem* collisionSystem, CGeomSpace* space,
			f32 radius, f32 length);
		
		//! Destructor
		virtual ~CGeomCylinder();
	
		//! returns true if the alternative geom is needed for collision with the given geom
		virtual bool needAltGeom(CGeom* other) const;
		
		//! Set the parameters of the given capsule.
		//! \param radius: radius of the Cyliner
		//! \param length: length of the Cylinder without caps
		void setParams(f32 radius, f32 length);

		//! Return in radius and length the parameters of the given capsule.
		//! \param radius: radius of the Cylinder
		//! \param length: length of the Cylinder without caps
		void getParams(f32& radius, f32& length) const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth(const core::vector3df& pos) const;
	
	protected:
		//! creates the alternative geom
		void createAltGeom();
		
	protected:
		CTrimeshData* trimeshData;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_CYLINDER_H__
