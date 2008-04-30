#ifndef CAXIS3SWEEP_H_INCLUDED
#define CAXIS3SWEEP_H_INCLUDED

#include <lfpe-bullet/collision/bphase/CCollisionBroadphase.h>
#include <LinearMath/btVector3.h>

namespace lf
{
namespace pe
{
	static btVector3 FromPEVector(const lf::core::vector3df& lf);
	static lf::core::vector3df FromLFVector(const btVector3& pe);

namespace collision
{
	class CAxisSweep3 : public CCollisionBroadphase
	{
		public:
			CAxisSweep3(const lf::core::vector3df& worldMin,\
				const lf::core::vector3df& worldMax, lf::s32 noOfProxies);
	};
}

}
}

#endif // CAXIS3SWEEP_H_INCLUDED
