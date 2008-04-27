#include <lfpe-bullet/collision/dispatcher/CCollisionDispatcher.h>

namespace lf
{
namespace pe
{
namespace collision
{

ELFPE_BULLET_DISPATCHER_TYPE CCollisionDispatcher::getType() const
{
	return m_dpType;
}

CCollisionDispatcher::~CCollisionDispatcher()
{
	if (m_cColDispatcher)
	{
		delete m_cColDispatcher;
	}

	if (m_currentConfig)
	{
		m_currentConfig->drop();
	}
}

CCollisionConfiguration* CCollisionDispatcher::getConfiguration() const
{
	return m_currentConfig;
}

CCollisionDispatcher::CCollisionDispatcher(CCollisionConfiguration* config,\
	btCollisionDispatcher* cColDispatcher, ELFPE_BULLET_DISPATCHER_TYPE type)
	: m_cColDispatcher(cColDispatcher), m_currentConfig(config), m_dpType(type)
{
	if (m_currentConfig)
	{
		m_currentConfig->grab();
	}
}

} // collision
} //pe
} //lf
