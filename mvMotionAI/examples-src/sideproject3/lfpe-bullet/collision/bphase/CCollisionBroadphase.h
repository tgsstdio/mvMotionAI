#ifndef CCOLLISIONBROADPHASE_H_INCLUDED
#define CCOLLISIONBROADPHASE_H_INCLUDED

#include <lf/Lightfeather.h>

// TODO : need better name
namespace lf
{
namespace pe
{
namespace collision
{
	// TODO : check out broadphase objects
	enum ELFPE_BULLET_COLLISION_BROADPHASE_TYPE
	{
		ELFPE_BLT_CBPT_AXIS_3_SWEEP,
		ELFPE_BLT_CBPT_BIT_AXIS_3_SWEEP,
		ELFPE_BLT_CBPT_SIMPLE_SWEEP,
	};

	class CCollisionBroadphase : CRefCounted
	{
		public:
			ELFPE_BULLET_COLLISION_BROADPHASE_TYPE getType() const;
			btOverlappingPairCache* getInternalCachePtr() const;
			virtual ~CCollisionBroadphase();

		protected:
			btOverlappingPairCache* m_cacheObject;
			ELFPE_BULLET_COLLISION_BROADPHASE_TYPE m_cacheType;
			CCollisionBroadphase(btOverlappingPairCache* cachePtr,\
				ELFPE_BULLET_COLLISION_BROADPHASE_TYPE type);
	};
}
}
}

#endif // CCOLLISIONBROADPHASE_H_INCLUDED
