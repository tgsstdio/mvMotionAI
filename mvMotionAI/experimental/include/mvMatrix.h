#ifndef MV_MATRIX_HEADER_H_
#define MV_MATRIX_HEADER_H_

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_VEC_3_HEADER_FILE_H_

#define MV_MATRIX_ARRAY_LENGTH (16)

class mvMatrix4x4
{
	public:
		mvFloat m[MV_MATRIX_ARRAY_LENGTH];

		mvVec3 vectorMultiply(const mvVec3& vec);

		void multiply(const mvMatrix4x4& lhs, const mvMatrix4x4& rhs);
		void addition(const mvMatrix4x4& rhs);
		void subtraction(const mvMatrix4x4& rhs);
		void scalarMultiply(mvFloat variable);
		void inverseMatrix();
		void transposeMatrix();

		void setTranslation(const mvVec3& vec);
		void addTranslation(const mvVec3& vec);
		void setToIdentity();
		void setToAllZeros();

		void setRotationOnXAxis(mvFloat angleInDegrees);
		void setRotationOnYAxis(mvFloat angleInDegrees);
		void setRotationOnZAxis(mvFloat angleInDegrees);

		void setRadiansOnXAxis(mvFloat radians);
		void setRadiansOnYAxis(mvFloat radians);
		void setRadiansOnZAxis(mvFloat radians);

		const mvFloat* getPointer() const;
		mvMatrix4x4();
		mvMatrix4x4(const mvMatrix4x4& rhs);
		const mvMatrix4x4& operator=(const mvMatrix4x4& rhs);
		bool operator!=(const mvMatrix4x4& rhs);
		bool operator==(const mvMatrix4x4& rhs);
		~mvMatrix4x4();
};

#define MV_MASS_MATRIX_ARRAY_LENGTH (9)

class mvMassMatrix
{
	public:
		mvFloat m[MV_MASS_MATRIX_ARRAY_LENGTH];

		mvVec3 vectorMultiply(const mvVec3& vec);
		mvVec3 matrixMultiply(const mvMatrix4x4& rhs);
		void scalarMultiply(mvFloat variable);
		void inverseMatrix();

		void setRotationOnXAxis(const mvVec3& vec);
		void setRotationOnYAxis(const mvVec3& vec);
		void setRotationOnZAxis(const mvVec3& vec);

		void initSphereMass(mvFloat radius, mvFloat mass);
		void initBoxMass(const mvVec3& boxDims);
		void initCylinderMass(mvFloat radius, mvFloat length);

		mvMassMatrix();
		mvMassMatrix(const mvMassMatrix& rhs);

		~mvMassMatrix();
};

#endif
