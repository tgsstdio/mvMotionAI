#include "mvLFQuaternion.h"

/** @brief mvLFQuaternion
  *
  * @todo: document this function
  */
mvLFQuaternion::mvLFQuaternion(const mvVec3& rhs)
{
	lf::core::vector3df temp = rhs.components;
	m_qtr.toEulerDegrees(temp);
}

/** @brief convertToVec3
  *
  * @todo: document this function
  */
mvVec3 mvLFQuaternion::convertToVec3() const
{
	mvVec3 temp;
	temp.components = m_qtr.toEuler();
	return temp;
}

mvLFQuaternion mvLFQuaternion::interpolate(mvFloat factor) const
{
	return mvLFQuaternion(m_qtr * factor);
}

void mvLFQuaternion::invert()
{
	m_qtr.makeInverse();
}

void mvLFQuaternion::composeProduct(const mvLFQuaternion& rhs)
{
	m_qtr *= rhs.m_qtr;
}

void mvLFQuaternion::setDelta(const mvLFQuaternion& lhs, const mvLFQuaternion& rhs)
{
	m_qtr = lhs.m_qtr;
	m_qtr.makeInverse();
	m_qtr *= rhs.m_qtr;
}

mvLFQuaternion::mvLFQuaternion(const lf::core::quaternion& rhs)
{
	m_qtr = rhs;
}

mvLFQuaternion::mvLFQuaternion()
{

}
