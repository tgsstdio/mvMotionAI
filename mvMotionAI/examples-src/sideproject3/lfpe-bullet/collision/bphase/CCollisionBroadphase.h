#ifndef CCOLLISIONBROADPHASE_H_INCLUDED
#define CCOLLISIONBROADPHASE_H_INCLUDED

#include <lf/Lightfeather.h>
#include <BulletCollision/BroadphaseCollision/btOverlappingPairCache.h>

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
		ELFPE_BLT_CBPT_AXIS_SWEEP_3_PAIR_CACHE,
		ELFPE_BLT_CBPT_BIT_AXIS_3_SWEEP_PAIR_CACHE,
		ELFPE_BLT_CBPT_SIMPLE_SWEEP_PAIR_CACHE
	};

	class CCollisionBroadphase : public CRefCounted
	{
		public:
			ELFPE_BULLET_COLLISION_BROADPHASE_TYPE getType() const;
			btBroadphaseInterface* getInternalObjectPtr() const;
			virtual ~CCollisionBroadphase();

		protected:
			btBroadphaseInterface* m_cacheObject;
			ELFPE_BULLET_COLLISION_BROADPHASE_TYPE m_cacheType;
			CCollisionBroadphase(btBroadphaseInterface* cachePtr,\
				ELFPE_BULLET_COLLISION_BROADPHASE_TYPE type);
	};
}
}
}

#endif // CCOLLISIONBROADPHASE_H_INCLUDED
