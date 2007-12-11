#ifndef MV_MATRIX_HEADER_H_
#define MV_MATRIX_HEADER_H_

#ifndef MV_MOTIONAI_TYPES_H_
#define MV_MOTIONAI_TYPES_H_ <mv/mvMotionAI-Types.h>
#include MV_MOTIONAI_TYPES_H_
#endif

#include MV_VEC3_HEADER_FILE_H_

#define MV_MATRIX_ARRAY_LENGTH (16)

class mvMatrix
{
	public:
		mvFloat m[MV_MATRIX_ARRAY_LENGTH];
	
		mvVec3 multiplyWithVec3(const mvVec3& vec):
		mvVec3 multiplyWithMatrix(const mvMatrix rhs);
		void setTranslation(mvVec3 vec);
		void setRotationOnXAxis(const mvVec3& vec);
		void setRotationOnYAxis(const mvVec3& vec);
		mvMatrix();
		mvMatrix(const mvMatrix& rhs);
		
		~mvMatrix();
};

#define MV_MASS_MATRIX_ARRAY_LENGTH (9)
class mvMassMatrix
{
	public:
		mvFloat m[MV_MASS_MATRIX_ARRAY_LENGTH];
	
		mvVec3 multiplyWithVec3(const mvVec3& vec):
		mvVec3 multiplyWithMatrix(const mvMassMatrix rhs);
		
		void setTranslation(mvVec3 vec);
		void setRotationOnXAxis(const mvVec3& vec);
		void setRotationOnYAxis(const mvVec3& vec);
		void setRotationOnZAxis(const mvVec3& vec);

		void initSphereMass(mvFloat radius, mvFloat mass);
		void initBoxMass(const mvVec3& boxDims);
		mvMatrix();
		mvMatrix(const mvMatrix& rhs);
		
		~mvMatrix();
};

#endif
