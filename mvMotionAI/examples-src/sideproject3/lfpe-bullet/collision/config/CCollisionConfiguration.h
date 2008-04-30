#ifndef CCOLLISIONCONFIGURATION_H_INCLUDED
#define CCOLLISIONCONFIGURATION_H_INCLUDED

#include <lf/Lightfeather.h>
#include <BulletCollision\CollisionDispatch\btCollisionConfiguration.h>

namespace lf
{
namespace pe
{
namespace collision
{
	enum ELFPE_BULLET_CONFIGURATION_TYPE
	{
		ELFPE_BLT_CT_DEFAULT_CONFIGURATION,
	};

	class CCollisionConfiguration : public CRefCounted
	{
		public:
			btCollisionConfiguration* getInternalObjectPtr() const;
			ELFPE_BULLET_CONFIGURATION_TYPE getType() const;
			virtual ~CCollisionConfiguration();
		protected:
			ELFPE_BULLET_CONFIGURATION_TYPE m_configType;
			btCollisionConfiguration* m_collInternalConfig;
			CCollisionConfiguration(btCollisionConfiguration* config,\
				ELFPE_BULLET_CONFIGURATION_TYPE type);
	};
}
}
} // namespace lf
#endif // CCOLLISIONCONFIGURATION_H_INCLUDED
