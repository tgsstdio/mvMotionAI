// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _I_GEOM_LISTENER_H_
#define _I_GEOM_LISTENER_H_

#include <lfpe/collision/CGeomEvent.h>
#include <lf/Lightfeather.h>

namespace lf
{
namespace pe
{
namespace collision
{
	//! interface for geom listeners
	class LFPE_DLL_EXPORT IGeomListener
	{
	public:
	//! gets called by a geom that is verry likely to collide with an other geom
	//! the 1st geom is the source of the event. the 2nd geom is other.
	//! can must be set to true if the geoms can collide, else set it to false.
	//! the preset of can is true
	//! if the event gets consumed, then no more listeners will receive the event
	//! if no listener does consume the event, the event is also called for the other geom.
		virtual void canCollide(collision::CGeomEvent& event, 
			collision::CGeom* other, bool& can) {};

		//! gets called if the sorce geom collides with the other geom
		virtual void doCollide(collision::CGeomEvent& event, collision::CGeom* other, 
			dContactGeom* contacts, s32 numContacts) {};

		virtual ~IGeomListener() {};
	};
	
} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _I_GEOM_LISTENER_H_
