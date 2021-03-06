// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_BOX_H_
#define _C_GEOM_BOX_H_

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
	
	//! The point of reference for a box is its center. 
	class LFPE_DLL_EXPORT CGeomBox : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomBox(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param size : size of the box
		CGeomBox(CCollisionSystem* collisionSystem, CGeomSpace* space, const core::vector3df& size);
		
		//! Destructor
		virtual ~CGeomBox();

		//! Set the side lengths of the given box.
		//! \param size: new size of the box
		void setSize( const core::vector3df& size );

		//! Return in result the side lengths of the given box.
		core::vector3df getSize() const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth( const core::vector3df& pos ) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // __C_GEOM_BOX_H__
