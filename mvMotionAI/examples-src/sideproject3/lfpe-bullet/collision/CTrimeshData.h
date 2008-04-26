// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_TRIMESH_DATA_H_
#define _C_TRIMESH_DATA_H_

#include <lfpe/lfpeConfig.h>
#include <lf/Lightfeather.h>

#include <ode/ode.h>

namespace lf
{
namespace pe
{
namespace collision
{
	using namespace lf;
	
	struct STriMeshVertex
	{
		dReal v0, v1, v2;
	};
	
	struct STriMeshTri
	{
		s32 indices[3];
	};
	
	
	class LFPE_DLL_EXPORT CTrimeshData : public CRefCounted
	{
	public:
		//! Default Constructor
		//! \param mesh: mesh which is used to create trimesh
		CTrimeshData( res::CMesh *mesh );
		
		//! Destructor
		virtual ~CTrimeshData();
		
		//! returns the ode internal ID
		dTriMeshDataID getTrimeshDataID() const;
	
	protected:
		//! ode internal id of the trimesh data
		dTriMeshDataID triMeshDataID;
		
		//! vertices
		STriMeshVertex *vertices;
		
		//! triangles
		STriMeshTri *triangles;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // _C_TRIMESH_DATA_H_
