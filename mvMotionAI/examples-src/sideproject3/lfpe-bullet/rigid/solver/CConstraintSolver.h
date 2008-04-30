#ifndef CDYNAMICSOLVER_H_INCLUDED
#define CDYNAMICSOLVER_H_INCLUDED

#include <lf/Lightfeather.h>
#include <BulletDynamics/ConstraintSolver/btConstraintSolver.h>

namespace lf
{

namespace pe
{

namespace rigid
{

	enum LFPE_BULLET_DYNAMIC_SOLVER_TYPE
	{
		ELPFE_BLT_DST_SEQUENCIAL_IMPULSE_SOLVER
	};

	class CConstraintSolver : public CRefCounted
	{
		public:
			LFPE_BULLET_DYNAMIC_SOLVER_TYPE getType() const;
			btConstraintSolver* getInternalObjectPtr() const;
			virtual ~CConstraintSolver();
		protected:
			btConstraintSolver* m_cSolver;
			LFPE_BULLET_DYNAMIC_SOLVER_TYPE m_solverType;
			CConstraintSolver(btConstraintSolver* contraintSolver,
				LFPE_BULLET_DYNAMIC_SOLVER_TYPE type);
	};

}

}

}


#endif // CDYNAMICSOLVER_H_INCLUDED
