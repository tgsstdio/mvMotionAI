// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_TRIMESH_H_
#define _C_GEOM_TRIMESH_H_

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
	class CTrimeshData;
	
	using namespace lf;
	
	
	//! A triangle mesh (TriMesh) represents an arbitrary collection of triangles. The triangle mesh collision system
	//! has the following features:
	//! - Any triangle "soup" can be represented — i.e. the triangles are not required to have any particular
	//!  strip, fan or grid structure.
	//! - Triangle meshes can interact with spheres, boxes, rays and other triangle meshes.
	//! - It works well for relatively large triangles.
	//! - It uses temporal coherence to speed up collision tests. When a geom has its collision checked with
	//!   a trimesh once, data is stored inside the trimesh. This data can be cleared with the dGeomTriMesh-
	//!   ClearTCCache() function. In the future it will be possible to disable this functionality.
	//!   Trimesh/Trimesh collisions, perform quite well, but there are three minor caveats:
	//! - The stepsize you use will, in general, have to be reduced for accurate collision resolution. Non-convex
	//!   shape collision is much more dependent on the collision geometry than primitive collisions. Further,
	//!   the local contact geometry will change more rapidly (and in a more complex fashion) for non-convex
	//!   polytopes than it does for simple, convex polytopes such as spheres and cubes.
	//! - In order to efficiently resolve collisions, dCollideTTL needs the positions of the colliding trimeshes
	//!   in the previous timestep. This is used to calculate an estimated velocity of each colliding triangle,
	//!   which is used to find the direction of impact, contact normals, etc. This requires the user to update
	//!   these variables at every timestep. This update is performed outside of ODE, so it is not included in
	//!   ODE itself. The code to do this looks something like this:
	//!   const double *DoubleArrayPtr = Bodies[BodyIndex].TransformationMatrix->GetArray();
	//!   dGeomTriMeshDataSet( TriMeshData, TRIMESH_LAST_TRANSFORMATION, (void *)DoubleArrayPtr );
	//!   The transformation matrix is the standard 4x4 homogeneous transform matrix, and the "DoubleArray"
	//!   is the standard flattened array of the 16 matrix values.
	class LFPE_DLL_EXPORT CGeomTrimesh : public CGeom
	{
	public:
		//! Default Constructor
		//! \param world: the world in which the geom is located
		//! \param space: parent space, can be null.
		//! \param data: trimesh data to use
		CGeomTrimesh(CCollisionSystem* collisionSystem, CGeomSpace* space, CTrimeshData *data);
		
		//! Destructor
		virtual ~CGeomTrimesh();
	
		//! Return the depth of the point in the given geom. Points inside the geom will have positive
		//! depth, points outside it will have negative depth, and points on the surface will have zero depth.
		//! \param pos: point of interrest
		virtual f32 pointDepth(const core::vector3df& pos) const;
		
		CTrimeshData *getData() const;
		
	protected:
		//! trimesh data
		CTrimeshData *data;
	};		

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_TRIMESH_H__
