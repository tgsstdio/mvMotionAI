#include <lfpe-bullet/collision/config/CCollisionConfiguration.h>

namespace lf
{
namespace pe
{
namespace collision
{
btCollisionConfiguration* CCollisionConfiguration::getInternalConfig() const
{
	return m_collInternalConfig;
}

CCollisionConfiguration::~CCollisionConfiguration()
{
	if (m_collInternalConfig)
	{
		delete m_collInternalConfig;
	}
}

CCollisionConfiguration::CCollisionConfiguration(\
	btCollisionConfiguration* config, ELFPE_BULLET_CONFIGURATION_TYPE type)
	: m_collInternalConfig(config), m_configType(type)
{

}


}
} // pe
} // lf
