// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_CAPSULE_H_
#define _C_GEOM_CAPSULE_H_

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
	
	//! A capsule is like a normal cylinder except it has half-sphere caps at its ends. This feature
	//! makes the internal collision detection code particularly fast and accurate. The cylinder’s length, not
	//! counting the caps, is given by length. The cylinder is aligned along the geom’s local Z axis. The
	//! radius of the caps, and of the cylinder itself, is given by radius.
	class LFPE_DLL_EXPORT CGeomCapsule : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomCapsule(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Default Constructor
		//! \param space: parent space, can be null.
		//! \param radius: radius of the Capsule
		//! \param length: length of the capsule without caps
		CGeomCapsule(CCollisionSystem* collisionSystem, CGeomSpace* space, f32 radius, f32 length);
		
		//! Destructor
		virtual ~CGeomCapsule();
	
		//! Set the parameters of the given capsule.
		//! \param radius: radius of the Capsule
		//! \param length: length of the capsule without caps
		void setParams( f32 radius, f32 length );

		//! Return in radius and length the parameters of the given capsule.
		//! \param radius: radius of the Capsule
		//! \param length: length of the capsule without caps
		void getParams( f32& radius, f32& length ) const;
		
		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth( const core::vector3df& pos ) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // __C_GEOM_CAPSULE_H__
