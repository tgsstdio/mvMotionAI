#ifndef CDISCRETEWORLD_H_INCLUDED
#define CDISCRETEWORLD_H_INCLUDED

#include <lfpe-bullet\world\CPeBulletWorld.h>

namespace lf
{
namespace pe
{
namespace world
{
	class CDiscreteWorld : public CPeBulletWorld
	{
		public:
			CDiscreteWorld(collision::CCollisionDispatcher* dispatcher,
				collision::CCollisionBroadphase* bPhase,
				rigid::CConstraintSolver* solver,
				collision::CCollisionConfiguration* cConfig);

		protected:
			btDynamicsWorld* initialiseWorld(
				collision::CCollisionDispatcher* dispatcher,
				collision::CCollisionBroadphase* bPhase,
				rigid::CConstraintSolver* solver,
				collision::CCollisionConfiguration* cConfig);
	};

}
}
}



#endif // CDISCRETEWORLD_H_INCLUDED
