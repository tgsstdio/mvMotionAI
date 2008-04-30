#include <lfpe-bullet/rigid/solver/CSequentialImpulseSolver.h>
#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>

namespace lf
{

namespace pe
{

namespace rigid
{
	CSequentialImpulseSolver::CSequentialImpulseSolver()
		: CConstraintSolver(new btSequentialImpulseConstraintSolver(),\
			ELPFE_BLT_DST_SEQUENCIAL_IMPULSE_SOLVER)
	{

	}

}

}
}
