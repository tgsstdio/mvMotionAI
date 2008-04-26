// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _I_GEOM_ATTACHER_H_
#define _I_GEOM_ATTACHER_H_

#include <lfpe/lfpeConfig.h>

namespace lf
{
namespace pe
{
namespace collision
{
	class CGeom;

	enum E_GEOM_ATTACHER_TYPE
	{
		EGAT_BODY					= 0,
		EGAT_FORCE_AFFECTOR,
		EGAT_USER					= 100
	};

	//! 
	class LFPE_DLL_EXPORT IGeomAttacher
	{
	public:
		//! returns the type of the geom attacher
		virtual E_GEOM_ATTACHER_TYPE getGeomAttacherType() const = 0;
	
		//! attaches a geom
		//! if the geom was attached to an other geomAttacher before, then it gets detached from it
		//! \param geom: the geom to attach
		virtual void attachGeom(collision::CGeom* geom) = 0;
		
		//! detaches a geom
		//! returns true if the geom was successfully detached
		//! \param geom: the geom to detach
		virtual bool detachGeom(collision::CGeom* geom) = 0;
		
		//! returns if the geom is attached to this geomAttacher
		//! \param geom: geom to check
		virtual bool isGeomAttached(collision::CGeom* geom) const = 0;
		
		//! detaches all geoms
		virtual void detachAllGeoms() = 0;
	};
	
} // end namespace world
} // end namespace pe
} // end namespace lf


#endif // _I_GEOM_ATTACHER_H_
