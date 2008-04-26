// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_HEIGHTFIELDDATA_EVENT_H_
#define _C_HEIGHTFIELDDATA_EVENT_H_

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

	class CHeightFieldData;

	class LFPE_DLL_EXPORT CHeightFieldDataEvent :
		public core::CEvent
	{
	public:
		CHeightFieldDataEvent(CHeightFieldData *source);
		~CHeightFieldDataEvent();

		virtual CHeightFieldData* getSource() const;
		
	protected:
		CHeightFieldData* source;
	};

} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _C_HEIGHTFIELDDATA_EVENT_H_


