#ifndef CCOLLISIONDISPATCHER_H_INCLUDED
#define CCOLLISIONDISPATCHER_H_INCLUDED

#include <lf/LightFeather.h>
#include <btDynamics/


namespace lf
{
namespace collision
{
	enum ELFPE_BULLET_DISPATCHER_TYPE
	{
		ELFPE_BLTDT_DEFAULT_DISPATCHER,
		ELFPE_BLTDT_MULTI_SPU_DISPATCHER, // more detail required
	};

	class CCollisionDispatcher : public CRefCounted
	{
		public:
			ELFPE_BULLET_DISPATCHER_TYPE getType() const;

		protected:
			ELFPE_BULLET_DISPATCHER_TYPE m_dpType;
			btCollisionDispatcher* m_cColDispatcher;

			CCollisionDispatcher(btCollisionDispatcher* cColDispatcher,\
				ELFPE_BULLET_DISPATCHER_TYPE type);

	};

} // namespace collision
} // namespace lf

#endif // CCOLLISIONDISPATCHER_H_INCLUDED
