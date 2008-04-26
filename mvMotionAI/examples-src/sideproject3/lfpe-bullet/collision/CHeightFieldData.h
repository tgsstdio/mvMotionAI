// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_HEIGHTFIELD_DATA_H_
#define _C_HEIGHTFIELD_DATA_H_

#include <lfpe/lfpeConfig.h>
#include <lfpe/collision/IHeightFieldDataListener.h>
#include <lf/Lightfeather.h>

#include <ode/ode.h>

namespace lf
{
namespace pe
{
namespace collision
{
	using namespace lf;
	
	//! The data for the CGeomHeightField geom.
	class LFPE_DLL_EXPORT CHeightFieldData : public CRefCounted
	{
	public:
		//! Default Constructor
		CHeightFieldData();
		
		//! Destructor
		virtual ~CHeightFieldData();
		
		//! Configures the heightfield data to use a callback to retrieve height data.
		//!
		//! This call specifies that the heightfield data is computed by
		//! the user and it should use the given callback when determining
		//! the height of a given element of it's shape.
		//! To receive the callback you have to register an HeightFieldDataListener.
		//! You should call setBounds() after calling initCallback() and before
		//! the CGeomHeightField object is created!
		//!
		//! @param width Specifies the total 'width' of the heightfield along
		//! the geom's local x axis.
		//! @param depth Specifies the total 'depth' of the heightfield along
		//! the geom's local z axis.
		//!
		//! @param widthSamples Specifies the number of vertices to sample
		//! along the width of the heightfield. Each vertex has a corresponding
		//! height value which forms the overall shape.
		//! Naturally this value must be at least two or more.
		//! @param depthSamples Specifies the number of vertices to sample
		//! along the depth of the heightfield.
		//!
		//! @param scale A uniform scale applied to all raw height data.
		//! @param offset An offset applied to the scaled height data.
		//!
		//! @param thickness A value subtracted from the lowest height
		//! value which in effect adds an additional cuboid to the base of the
		//! heightfield. This is used to prevent geoms from looping under the
		//! desired terrain and not registering as a collision. Note that the
		//! thickness is not affected by the scale or offset parameters.
		//!
		//! @param bWrap If true the heightfield will infinitely tile in both
		//! directions along the local x and z axes. If zero the heightfield is
		//! bounded from false to width in the local x axis, and zero to depth in
		//! the local z axis.
		void initCallback(f32 width, f32 depth, s32 widthSamples, s32 depthSamples,
				f32 scale, f32 offset, f32 thickness, bool bWrap);
		
		//! Configures the height fieldData to use height data in u8 format.
		//! 
		//! This call specifies that the heightfield data is stored as a rectangular
		//! array of bytes (8 bit unsigned) representing the height at each sample point.
		//! 
		//! @param pHeightData A pointer to the height data.
		//! @param bCopyHeightData When true the height data is copied to an
		//! internal store. When false the height data is accessed by reference and
		//! so must persist throughout the lifetime of the heightfield.
		//! 
		//! @param width Specifies the total 'width' of the heightfield along
		//! the geom's local x axis.
		//! @param depth Specifies the total 'depth' of the heightfield along
		//! the geom's local z axis.
		//! 
		//! @param widthSamples Specifies the number of vertices to sample
		//! along the width of the heightfield. Each vertex has a corresponding
		//! height value which forms the overall shape.
		//! Naturally this value must be at least two or more.
		//! @param depthSamples Specifies the number of vertices to sample
		//! along the depth of the heightfield.
		//! 
		//! @param scale A uniform scale applied to all raw height data.
		//! @param offset An offset applied to the scaled height data.
		//! 
		//! @param thickness A value subtracted from the lowest height
		//! value which in effect adds an additional cuboid to the base of the
		//! heightfield. This is used to prevent geoms from looping under the
		//! desired terrain and not registering as a collision. Note that the
		//! thickness is not affected by the scale or offset parameters.
		//! 
		//! @param bWrap If true the heightfield will infinitely tile in both
		//! directions along the local x and z axes. If zero the heightfield is
		//! bounded from false to width in the local x axis, and zero to depth in
		//! the local z axis.
		void init_u8Array(const u8* pHeightData, bool bCopyHeightData,
						f32 width, f32 depth, s32 widthSamples, s32 depthSamples,
						f32 scale, f32 offset, f32 thickness, bool bWrap);

		
		//! Configures the height field data to use height data in s16 format.
		//! 
		//! This call specifies that the heightfield data is stored as a rectangular
		//! array of shorts (16 bit signed) representing the height at each sample point.
		//! 
		//! @param pHeightData A pointer to the height data.
		//! @param bCopyHeightData When true the height data is copied to an
		//! internal store. When false the height data is accessed by reference and
		//! so must persist throughout the lifetime of the heightfield.
		//! 
		//! @param width Specifies the total 'width' of the heightfield along
		//! the geom's local x axis.
		//! @param depth Specifies the total 'depth' of the heightfield along
		//! the geom's local z axis.
		//! 
		//! @param widthSamples Specifies the number of vertices to sample
		//! along the width of the heightfield. Each vertex has a corresponding
		//! height value which forms the overall shape.
		//! Naturally this value must be at least two or more.
		//! @param depthSamples Specifies the number of vertices to sample
		//! along the depth of the heightfield.
		//! 
		//! @param scale A uniform scale applied to all raw height data.
		//! @param offset An offset applied to the scaled height data.
		//! 
		//! @param thickness A value subtracted from the lowest height
		//! value which in effect adds an additional cuboid to the base of the
		//! heightfield. This is used to prevent geoms from looping under the
		//! desired terrain and not registering as a collision. Note that the
		//! thickness is not affected by the scale or offset parameters.
		//! 
		//! @param bWrap If true the heightfield will infinitely tile in both
		//! directions along the local x and z axes. If false the heightfield is
		//! bounded from zero to width in the local x axis, and zero to depth in
		//! the local z axis.
		void Init_s16Array(const s16* pHeightData, bool bCopyHeightData,
						f32 width, f32 depth, s32 widthSamples, s32 depthSamples,
						f32 scale, f32 offset, f32 thickness, bool bWrap);

		
		//! Configures the height field data to use height data in f32 format.
		//! 
		//! This call specifies that the heightfield data is stored as a rectangular
		//! array of single precision floats representing the height at each
		//! sample point.
		//! 
		//! @param pHeightData A pointer to the height data.
		//! @param bCopyHeightData When true the height data is copied to an
		//! internal store. When false the height data is accessed by reference and
		//! so must persist throughout the lifetime of the heightfield.
		//! 
		//! @param width Specifies the total 'width' of the heightfield along
		//! the geom's local x axis.
		//! @param depth Specifies the total 'depth' of the heightfield along
		//! the geom's local z axis.
		//! 
		//! @param widthSamples Specifies the number of vertices to sample
		//! along the width of the heightfield. Each vertex has a corresponding
		//! height value which forms the overall shape.
		//! Naturally this value must be at least two or more.
		//! @param depthSamples Specifies the number of vertices to sample
		//! along the depth of the heightfield.
		//! 
		//! @param scale A uniform scale applied to all raw height data.
		//! @param offset An offset applied to the scaled height data.
		//! 
		//! @param thickness A value subtracted from the lowest height
		//! value which in effect adds an additional cuboid to the base of the
		//! heightfield. This is used to prevent geoms from looping under the
		//! desired terrain and not registering as a collision. Note that the
		//! thickness is not affected by the scale or offset parameters.
		//! 
		//! @param bWrap If true the heightfield will infinitely tile in both
		//! directions along the local x and z axes. If zero the heightfield is
		//! bounded from false to width in the local x axis, and zero to depth in
		//! the local z axis.
		void init_f32Array(const f32* pHeightData, bool bCopyHeightData,
						f32 width, f32 depth, s32 widthSamples, s32 depthSamples,
						f32 scale, f32 offset, f32 thickness, bool bWrap);

		
		//! Configures the height field to use height data in f64 format.
		//! 
		//! This call specifies that the heightfield data is stored as a rectangular
		//! array of double precision floats representing the height at each
		//! sample point.
		//! 
		//! @param pHeightData A pointer to the height data.
		//! @param bCopyHeightData When true the height data is copied to an
		//! internal store. When false the height data is accessed by reference and
		//! so must persist throughout the lifetime of the heightfield.
		//! 
		//! @param width Specifies the total 'width' of the heightfield along
		//! the geom's local x axis.
		//! @param depth Specifies the total 'depth' of the heightfield along
		//! the geom's local z axis.
		//! 
		//! @param widthSamples Specifies the number of vertices to sample
		//! along the width of the heightfield. Each vertex has a corresponding
		//! height value which forms the overall shape.
		//! Naturally this value must be at least two or more.
		//! @param depthSamples Specifies the number of vertices to sample
		//! along the depth of the heightfield.
		//! 
		//! @param scale A uniform scale applied to all raw height data.
		//! @param offset An offset applied to the scaled height data.
		//! 
		//! @param thickness A value subtracted from the lowest height
		//! value which in effect adds an additional cuboid to the base of the
		//! heightfield. This is used to prevent geoms from looping under the
		//! desired terrain and not registering as a collision. Note that the
		//! thickness is not affected by the scale or offset parameters.
		//! 
		//! @param bWrap If true the heightfield will infinitely tile in both
		//! directions along the local x and z axes. If zero the heightfield is
		//! bounded from false to width in the local x axis, and zero to depth in
		//! the local z axis.
		void init_f64Array(const f64* pHeightData, bool bCopyHeightData,
						f32 width, f32 depth, s32 widthSamples, s32 depthSamples,
						f32 scale, f32 offset, f32 thickness, bool bWrap );

		//! Manually set the minimum and maximum height bounds.
		//! 
		//! This call allows you to set explicit min / max values after initial
		//! creation typically for callback heightfields which default to +/- infinity,
		//! or those whose data has changed. This must be set prior to binding with a
		//! geom, as the the AABB is not recomputed after it's first generation.
		//! 
		//! @remarks The minimum and maximum values are used to compute the AABB
		//! for the heightfield which is used for early rejection of collisions.
		//! A close fit will yield a more efficient collision check.
		//! 
		//! @param min_height The new minimum height value. Scale, offset and thickness is then applied.
		//! @param max_height The new maximum height value. Scale and offset is then applied.
		void setBounds(f32 minHeight, f32 maxHeight );

		//! returns the ode internal ID
		dHeightfieldDataID getHeightFieldDataID() const;
	
		//! add a height field data-listener
		//! \param listener: listener
		void addHeightFieldDataListener(IHeightFieldDataListener *listener);

		//! remove a height field data-listener
		//! \param listener: listener
		void removeHeightFieldDataListener(IHeightFieldDataListener *listener);

		//! Internal callback to handle ODE getHeight callbacks.
		//! Don't call this method directly!
		f32 _getHeight(s32 x, s32 z);

	protected:
		//! ode internal id of the trimesh data
		dHeightfieldDataID heightFieldDataID;

		//! list with height field data listeners
		core::list<IHeightFieldDataListener *> listeners;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // _C_HEIGHTFIELD_DATA_H_
