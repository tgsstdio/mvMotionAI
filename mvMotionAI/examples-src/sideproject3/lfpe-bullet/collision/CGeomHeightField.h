// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_HEIGHTFIELD_H_
#define _C_GEOM_HEIGHTFIELD_H_

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
	class CHeightFieldData;
	
	using namespace lf;
	
	
	//! Collision geom for height fields
	//! It supports several formats of data as well as a callback funtion
	class LFPE_DLL_EXPORT CGeomHeightField : public CGeom
	{
	public:
		//! Default Constructor
		//! \param world: the world in which the geom is located
		//! \param space: parent space, can be null.
		//! \param data: heightField data to use
		CGeomHeightField(CCollisionSystem* collisionSystem, CGeomSpace* space, CHeightFieldData *data);
		
		//! Destructor
		virtual ~CGeomHeightField();
	
		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth(const core::vector3df& pos) const;
		
		CHeightFieldData *getData() const;
		
	protected:
		//! heightField data
		CHeightFieldData *data;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // _C_GEOM_HEIGHTFIELD_H_
