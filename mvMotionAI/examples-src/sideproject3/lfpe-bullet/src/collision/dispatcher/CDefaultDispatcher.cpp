#include <lfpe-bullet/collision/dispatcher/CDefaultDispatcher.h>
#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>

namespace lf
{
namespace pe
{
namespace collision
{
	CDefaultDispatcher::CDefaultDispatcher(CCollisionConfiguration* config)
	 : CCollisionDispatcher(config, new btCollisionDispatcher(config->getInternalObjectPtr()),
		ELFPE_BLT_DT_DEFAULT_DISPATCHER)
	{

	}
}
}
}
