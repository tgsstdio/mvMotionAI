// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _I_HEIGHTFIELDDATA_LISTENER_H_
#define _I_HEIGHTFIELDDATA_LISTENER_H_

#include <lfpe/collision/CHeightFieldDataEvent.h>
#include <lf/Lightfeather.h>

namespace lf
{
namespace pe
{
namespace collision
{
	//! interface for height field data listeners
	class LFPE_DLL_EXPORT IHeightFieldDataListener
	{
	public:
		//! Used by the heightfield data to sample a height for a
		//! given cell position.
		//! 
		//! @param x The index of a sample in the local x axis. It is a value
		//! in the range zero to ( nWidthSamples - 1 ).
		//! @param x The index of a sample in the local z axis. It is a value
		//! in the range zero to ( nDepthSamples - 1 ).
		//! 
		//! @return The sample height which is then scaled and offset using the
		//! values specified when the heightfield data was created.
		virtual f32 getHeight(collision::CHeightFieldDataEvent& event, s32 x, s32 z) {return 0.0f;};

		virtual ~IHeightFieldDataListener() {};
	};
	
} // end namespace collision
} // end namespace pe
} // end namespace lf

#endif // _I_HEIGHTFIELDDATA_LISTENER_H_
