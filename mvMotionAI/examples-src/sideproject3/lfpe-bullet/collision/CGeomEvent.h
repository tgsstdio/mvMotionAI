// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_EVENT_H_
#define _C_GEOM_EVENT_H_

#include <lfpe/lfpeConfig.h>
#include <lf/core/CEvent.h>

#include <ode/ode.h>


namespace lf
{
namespace pe
{
namespace collision
{
	using namespace lf;

	class CGeom;

	class LFPE_DLL_EXPORT CGeomEvent :
		public core::CEvent
	{
	public:
		CGeomEvent(CGeom *source);
		~CGeomEvent();

		virtual CGeom* getSource() const;
		
	protected:
		CGeom* source;
	};

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _C_GEOM_EVENT_H_


