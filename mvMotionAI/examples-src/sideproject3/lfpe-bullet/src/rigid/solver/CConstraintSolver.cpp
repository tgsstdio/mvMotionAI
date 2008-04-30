#include <lfpe-bullet/rigid/solver/CConstraintSolver.h>

namespace lf
{

namespace pe
{

namespace rigid
{

	LFPE_BULLET_DYNAMIC_SOLVER_TYPE CConstraintSolver::getType() const
	{
		return m_solverType;
	}

	btConstraintSolver* CConstraintSolver::getInternalObjectPtr() const
	{
		return m_cSolver;
	}

	CConstraintSolver::~CConstraintSolver()
	{
		if (m_cSolver)
		{
			delete m_cSolver;
		}
	}

	CConstraintSolver::CConstraintSolver(btConstraintSolver* contraintSolver,
		LFPE_BULLET_DYNAMIC_SOLVER_TYPE type)
		: m_cSolver(contraintSolver), m_solverType(type)
	{

	}

}
}
}

