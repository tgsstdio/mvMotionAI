// Copyright 2007 by Lightfeather-Team
// Written by Reinhard Ostermeier
// This file is part of the Lightfeather 3D-Engine.
// The license under which this code is distributed can be found in the file COPYING

#ifndef _C_GEOM_SPACE_H_
#define _C_GEOM_SPACE_H_

#include <lfpe-bullet/lfpeConfig.h>
#include <lf/Lightfeather.h>

#include <ode/ode.h>


namespace lf
{
namespace pe
{
//namespace world
//{
//	class CPeWorld;
//}
namespace collision
{
	class CGeom;
	class CCollisionSystem;

	using namespace lf;

	//! A space is a non-placeable geom that can contain other geoms. It is similar to the rigid body concept of the
	//! "world", except that it applies to collision instead of dynamics.
	//! Space objects exist to make collision detection go faster. Without spaces, you might generate contacts
	//! in your simulation by calling dCollide() to get contact points for every single pair of geoms. For N geoms
	//! this is O(N2) tests, which is too computationally expensive if your environment has many objects.
	//! A better approach is to insert the geoms into a space and call dSpaceCollide(). The space will then
	//! perform collision culling, which means that it will quickly identify which pairs of geoms are potentially
	//! intersecting. Those pairs will be passed to a callback function, which can in turn call dCollide() on them.
	//! This saves a lot of time that would have been spent in useless dCollide() tests, because the number of pairs
	//! passed to the callback function will be a small fraction of every possible object-object pair.
	//! Spaces can contain other spaces. This is useful for dividing a collision environment into several hierarchies
	//! to further optimize collision detection speed. This will be described in more detail below.
	//!
	//! There are several kinds of spaces. Each kind uses different internal data structures to store the geoms, and
	//! different algorithms to perform the collision culling:
	//! - Simple space. This does not do any collision culling - it simply checks every possible pair of geoms
	//!   for intersection, and reports the pairs whose AABBs overlap. The time required to do intersection
	//!   testing for n objects is O(n2). This should not be used for large numbers of objects, but it can be
	//!   the preferred algorithm for a small number of objects. This is also useful for debugging potential
	//!   problems with the collision system.
	//! - Multi-resolution hash table space. This uses an internal data structure that records how each geom
	//!   overlaps cells in one of several three dimensional grids. Each grid has cubical cells of side lengths
	//!   2i, where i is an integer that ranges from a minimum to a maximum value. The time required to
	//!   do intersection testing for n objects is O(n) (as long as those objects are not clustered together too
	//!   closely), as each object can be quickly paired with the objects around it.
	//!   (not supported so far)
	//! - Quadtree space. This uses a pre-allocated hierarchical grid-based AABB tree to quickly cull collision
	//!   checks. It’s exceptionally quick for large amounts of objects in landscape-shaped worlds. The
	//!   amount of memory used is 4ˆ.depth * 32 bytes. Currently dSpaceGetGeom() is not implemented for
	//!   the quadtree space.
	//!   (not supported so far)
	class LFPE_DLL_EXPORT CGeomSpace : public CRefCounted
	{
	public:
		//! Default Constructor
		//! \param space: parent space, can be null.
		CGeomSpace(CCollisionSystem* collisionSystem, CGeomSpace* space);

		//! Destructor
		~CGeomSpace();

		//! returns the collisionSystem where the space belongs to
		CCollisionSystem* getCollisionSystem() const;

		//! returns the ODE internal spaceID
		dSpaceID getSpaceID() const;

		//! returns the parent GeomSpace
		CGeomSpace* getParentSpace() const;

/*		Sets and get some parameters for a multi-resolution hash table space. The smallest and largest cell
		sizes used in the hash table will be 2ˆ.minlevel and 2ˆ.maxlevel respectively. minlevel must be
		less than or equal to maxlevel.
		In dHashSpaceGetLevels() the minimum and maximum levels are returned through pointers. If a
		pointer is zero then it is ignored and no argument is returned.
		void dHashSpaceSetLevels (dSpaceID space, int minlevel, int maxlevel);
		void dHashSpaceGetLevels (dSpaceID space, int *minlevel, int *maxlevel);
*/
		//! Set the clean-up mode of the space. If the clean-up mode is true, then the contained geoms will
		//! be destroyed when the space is destroyed. If the clean-up mode is false this does not happen. The default
		//! clean-up mode for new spaces is true.
		//! \param mode: true or false
		void setCleanup( bool mode );

		//! Get the clean-up mode of the space. If the clean-up mode is true, then the contained geoms will
		//! be destroyed when the space is destroyed. If the clean-up mode is false this does not happen. The default
		//! clean-up mode for new spaces is true.
		bool getCleanup() const;

		//! Add a geom to a space. This does nothing if the geom is already in the space. This function can be
		//! called automatically if a space argument is given to a geom creation function.
		//! \param geom: geom to add
		void add( const CGeom* geom );

		//! Add a geomSpace to a space. This does nothing if the geomSpace is already in the space. This function can be
		//! called automatically if a space argument is given to a geomSpace creation function.
		//! \param geomSpace: geomSpace to add
		void add( const CGeomSpace* geomSpace );

		//! Remove a geom from a space. This does nothing if the geom is not actually in the space. This function
		//! is called automatically by dGeomDestroy() if the geom is in a space.
		//! \param geom: geom to remove
		void remove( const CGeom* geom );

		//! Remove a geomSpace from a space. This does nothing if the geomSpace is not actually in the space. This function
		//! is called automatically by dGeomDestroy() if the geomSpace is in a space.
		//! \param geom: geom to remove
		void remove( const CGeomSpace* geomSpace );

		//! Return true if the given geom is in the given space, or return false if it is not.
		//! \param geom: geom to check
		bool query( const CGeom* geom );

		//! Return the number of geoms contained within a space.
		s32 getNumGeoms() const;

		//! returns if the geom at the given index is a geomspace or not
		//! \param idx : index of the geom
		bool isGeomSpace( s32 idx ) const;

		//! Return the i’th geom contained within the space. i must range from 0 to getNumGeoms()-1.
		//! If any change is made to the space (including adding and deleting geoms) then no guarantee can be
		//! made about how the index number of any particular geom will change. Thus no space changes should
		//! be made while enumerating the geoms.
		//! This function is guaranteed to be fastest when the geoms are accessed in the order 0,1,2,etc. Other
		//! non-sequential orders may result in slower access, depending on the internal implementation.
		//! You have to check if the geom at the given index is geom first. To do so use isGeomSpace( idx ).
		//! \param idx: index of the geom
		CGeom* getGeom( s32 idx ) const;

		//! Return the i’th geom contained within the space. i must range from 0 to getNumGeoms()-1.
		//! If any change is made to the space (including adding and deleting geoms) then no guarantee can be
		//! made about how the index number of any particular geom will change. Thus no space changes should
		//! be made while enumerating the geoms.
		//! This function is guaranteed to be fastest when the geoms are accessed in the order 0,1,2,etc. Other
		//! non-sequential orders may result in slower access, depending on the internal implementation.
		//! You have to check if the geom at the given index is geomSpace first. To do so use isGeomSpace( idx ).
		//! \param idx: index of the geom
		CGeomSpace* getGeomSpace( s32 idx ) const;

	protected:
		//! collision system where the space belongs to
		CCollisionSystem* collisionSystem;

		//! pointer to parent geom, can be null
		CGeomSpace*			parentSpace;

		//! ODE internal spaceID
		dSpaceID				spaceID;
	};

} // end namespace collision
} // end namespace pe
} // end namespace lf


#endif // __C_GEOM_SPACE_H__
