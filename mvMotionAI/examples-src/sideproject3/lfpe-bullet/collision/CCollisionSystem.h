// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_COLLISION_SYSTEM_H_
#define _C_COLLISION_SYSTEM_H_

#include <lfpe-bullet/lfpeConfig.h>
#include <lfpe-bullet/world/CPeSceneNodeControllerContainer.h>
#include <lfpe-bullet/collision/CGeomSpace.h>
#include <lf/Lightfeather.h>
#include <lf/core/list.h>


namespace lf
{
namespace pe
{
namespace collision
{
	using namespace lf;

	//!
	class LFPE_DLL_EXPORT CCollisionSystem :
		public world::CPeSceneNodeControllerContainer
	{
	public:
		//! Default Constructor
		CCollisionSystem();

		//! Destructor
		~CCollisionSystem();

		//! retuns the main geom space
		collision::CGeomSpace* getMainGeomSpace() const;

		//! collides all geoms
		//! geom events canCollideWith() and doCollideWith() will get called for every
		//! pair of geoms where it is necessary
		void collideGeoms();

		//! collides the two geoms
		//! this method returns the number of contact points between the two geoms.
		//! if the number is 0, then no collision occured.
		//! optional an array of the typ dContactGeom can be provided to store more
		//! informations about the contacts.
		//! \param geom1: 1st geom
		//! \param geom2: 2nd geom
		//! \param contacts: array for contact info, can be null
		//! \param numContacts: number of maxumum entries in the contacts array
		s32 collideGeoms(CGeom* geom1, CGeom* geom2,
			dContactGeom* contacts = 0, s32 numContacts = 0);

		//! collide a geom with a geom space
		//! this method returns the number of contact points.
		//! if the number is 0, then no collision occured.
		//! optional an array of the typ dContactGeom can be provided to store more
		//! informations about the contacts.
		//! \param geom1: geom
		//! \param geom2: geom space
		//! \param contacts: array for contact info, can be null
		//! \param numContacts: number of maxumum entries in the contacts array
		s32 collideGeoms(CGeom* geom1, CGeomSpace* geom2,
			dContactGeom* contacts = 0, s32 numContacts = 0);

	protected:
		//! top level geom space
		collision::CGeomSpace*	mainSpace;
	};

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _C_COLLISION_SYSTEM_H_
