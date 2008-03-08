#include <mvMatrix.h>

mvVec3 mvMatrix4x4::vectorMultiply(const mvVec3& vec)
{
	return mvVec3();
}

void mvMatrix4x4::multiply(const mvMatrix4x4& lhs, const mvMatrix4x4& rhs)
{

}

void mvMatrix4x4::addition(const mvMatrix4x4& rhs)
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		m[i] += rhs.m[i];
	}
}

void mvMatrix4x4::subtraction(const mvMatrix4x4& rhs)
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		m[i] -= rhs.m[i];
	}
}

void mvMatrix4x4::scalarMultiply(mvFloat variable)
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		m[i] *= variable;
	}
}
void mvMatrix4x4::inverseMatrix()
{

}

#define MV_MATRIX_VEC_X_INDEX (3)
#define MV_MATRIX_VEC_Y_INDEX (7)
#define MV_MATRIX_VEC_Z_INDEX (11)

void mvMatrix4x4::setTranslation(const mvVec3& vec)
{
	m[MV_MATRIX_VEC_X_INDEX] = vec.getX();
	m[MV_MATRIX_VEC_Y_INDEX] = vec.getY();
	m[MV_MATRIX_VEC_Z_INDEX] = vec.getZ();
}

void mvMatrix4x4::addTranslation(const mvVec3& vec)
{
	m[MV_MATRIX_VEC_X_INDEX] += vec.getX();
	m[MV_MATRIX_VEC_Y_INDEX] += vec.getY();
	m[MV_MATRIX_VEC_Z_INDEX] += vec.getZ();
}

void mvMatrix4x4::setToIdentity()
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		if (i % 5 == 0)
		{
			m[i] = 1;
		}
		else
		{
			m[i] = 0;
		}
	}
}
void mvMatrix4x4::setToAllZeros()
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		m[i] = 0;
	}
}

void mvMatrix4x4::setRotationOnXAxis(mvFloat angleInDegrees)
{

}
void mvMatrix4x4::setRotationOnYAxis(mvFloat angleInDegrees)
{

}
void mvMatrix4x4::setRotationOnZAxis(mvFloat angleInDegrees)
{

}

void mvMatrix4x4::setRadiansOnXAxis(mvFloat radians)
{

}
void mvMatrix4x4::setRadiansOnYAxis(mvFloat radians)
{

}
void mvMatrix4x4::setRadiansOnZAxis(mvFloat radians)
{

}

mvMatrix4x4::mvMatrix4x4()
{
	setToIdentity();
}

mvMatrix4x4::mvMatrix4x4(const mvMatrix4x4& rhs)
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		m[i] = rhs.m[i];
	}
}

const mvMatrix4x4& mvMatrix4x4::operator=(const mvMatrix4x4& rhs)
{
	return (*this);
}

bool mvMatrix4x4::operator!=(const mvMatrix4x4& rhs)
{
	return !(*this == rhs);
}

bool mvMatrix4x4::operator==(const mvMatrix4x4& rhs)
{
	for (mvCount i = 0; i < MV_MATRIX_ARRAY_LENGTH; i++)
	{
		if(m[i] != rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

mvMatrix4x4::~mvMatrix4x4()
{

}

const mvFloat* mvMatrix4x4::getPointer() const
{
	return (const mvFloat*) &m[0];
}
