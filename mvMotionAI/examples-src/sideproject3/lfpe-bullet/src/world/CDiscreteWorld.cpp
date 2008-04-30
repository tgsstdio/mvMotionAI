#include <lfpe-bullet/world/CDiscreteWorld.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>

namespace lf
{
namespace pe
{
namespace world
{
	CDiscreteWorld::CDiscreteWorld(collision::CCollisionDispatcher* dispatcher,
				collision::CCollisionBroadphase* bPhase,
				rigid::CConstraintSolver* solver,
				collision::CCollisionConfiguration* cConfig)
		: CPeBulletWorld(dispatcher, bPhase, solver,cConfig,
			initialiseWorld(dispatcher,bPhase,solver,cConfig),
			ELFPE_BLT_PWT_DISCRETE_DYNAMICS_WORLD)
	{

	}

	btDynamicsWorld* CDiscreteWorld::initialiseWorld(
		collision::CCollisionDispatcher* dispatcher,
		collision::CCollisionBroadphase* bPhase,
		rigid::CConstraintSolver* solver,
		collision::CCollisionConfiguration* cConfig)
	{
		btCollisionConfiguration* internalConf = (cConfig) ?
			cConfig->getInternalObjectPtr() : NULL;
		btCollisionDispatcher* internalDisp = (dispatcher) ?
			dispatcher->getInternalObjectPtr() : NULL;
		btBroadphaseInterface* internalBInterface = (bPhase) ?
			bPhase->getInternalObjectPtr() : NULL;
		btConstraintSolver* internalSolver = (solver) ?
			solver->getInternalObjectPtr() : NULL;

		// TODO : ASSERTS
			return new btDiscreteDynamicsWorld(internalDisp,
				internalBInterface, internalSolver, internalConf);

	}
}
}

}
