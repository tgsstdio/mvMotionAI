#ifndef LFPE_CSEQUENTIAL_IMPULSE_SOLVER_H_
#define LFPE_CSEQUENTIAL_IMPULSE_SOLVER_H_
#include <lfpe-bullet/rigid/solver/CConstraintSolver.h>

namespace lf
{

namespace pe
{

namespace rigid
{
	class CSequentialImpulseSolver : public CConstraintSolver
	{
		public:
			CSequentialImpulseSolver();
	};
}

}

}

#endif
