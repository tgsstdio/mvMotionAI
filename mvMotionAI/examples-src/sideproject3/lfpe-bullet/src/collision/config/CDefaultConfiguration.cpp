#include <lfpe-bullet\collision\config\CDefaultConfiguration.h>
#include <BulletCollision\CollisionDispatch\btDefaultCollisionConfiguration.h>

namespace lf
{
namespace pe
{
namespace collision
{
	CDefaultConfiguration::CDefaultConfiguration()
		: CCollisionConfiguration(new btDefaultCollisionConfiguration(),\
			ELFPE_BLT_CT_DEFAULT_CONFIGURATION)
	{

	}
}
}
}
