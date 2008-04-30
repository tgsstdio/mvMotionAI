#ifndef CCOLLISIONDISPATCHER_H_INCLUDED
#define CCOLLISIONDISPATCHER_H_INCLUDED

#include <lfpe-bullet/lfpeConfig.h>
#include <lf/LightFeather.h>
#include <lfpe-bullet/collision/config/CCollisionConfiguration.h>
#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>

namespace lf
{
namespace pe
{
namespace collision
{

	enum ELFPE_BULLET_DISPATCHER_TYPE
	{
		ELFPE_BLT_DT_DEFAULT_DISPATCHER,
		ELFPE_BLT_DT_MULTI_SPU_DISPATCHER, // more detail required
	};

	class CCollisionDispatcher : public CRefCounted
	{
		public:
			ELFPE_BULLET_DISPATCHER_TYPE getType() const;
			virtual ~CCollisionDispatcher();
			btCollisionDispatcher* getInternalObjectPtr() const;

		protected:
			ELFPE_BULLET_DISPATCHER_TYPE m_dpType;
			btCollisionDispatcher* m_cColDispatcher;
			CCollisionConfiguration* m_currentConfig;

			CCollisionDispatcher(CCollisionConfiguration* config,\
				btCollisionDispatcher* cColDispatcher,\
				ELFPE_BULLET_DISPATCHER_TYPE type);

	};

} // namespace collision
} // ns pe
} // namespace lf

#endif // CCOLLISIONDISPATCHER_H_INCLUDED
