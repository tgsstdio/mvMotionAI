// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_TRANSFORM_H_
#define _C_GEOM_TRANSFORM_H_

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
	class LFPE_DLL_EXPORT CGeomTransform : public CGeom
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomTransform(CCollisionSystem* collisionSystem, CGeomSpace* space);
		
		//! Destructor
		virtual ~CGeomTransform();

		//! returns the ode internal geom ID of the alternative geom
		virtual dGeomID getGeomIDalt() const;
		
		//! updates the translation of the alternative geom
		virtual void updateAltGeomTranslation();
		
		//! returns true if the alternative geom is needed for collision with the given geom
		virtual bool needAltGeom(CGeom* other) const;

		//! Set the geom that the geometry transform g encapsulates. The object obj must not be inserted into
		//! any space, and must not be associated with any body.
		//! If g has its clean-up mode turned on, and it already encapsulates an object, the old object will be
		//! destroyed before it is replaced with the new one.
		void setGeom(CGeom* geom);

		//! Get the geom that the geometry transform g encapsulates.
		CGeom* getGeom() const;

		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth(const core::vector3df& pos) const;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_TRANSFORM_H__
