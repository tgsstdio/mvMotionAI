#include "mvLFQuaternion.h"

/** @brief mvLFQuaternion
  *
  * @todo: document this function
  */
mvLFQuaternion::mvLFQuaternion()
{

}

mvLFQuaternion::mvLFQuaternion(const mvLFQuaternion& rhs)
{
	m_qtr = rhs.m_qtr;
}

mvLFQuaternion::mvLFQuaternion(const mvVec3& rhs)
{
	lf::core::vector3df temp = rhs.components;
	m_qtr.toEulerDegrees(temp);
}

/** @brief convertToVec3
  *
  * @todo: document this function
  */
mvVec3 mvLFQuaternion::getEulerAngles() const
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

mvLFQuaternion::mvLFQuaternion(const mvVec3& origin, const mvVec3& finalDir)
{
	mvVec3 left = origin;
	left.normalize();
	mvVec3 right = finalDir;
	right.normalize();
	mvVec3 axis = left.cross(right);
	axis.normalize();
	// shortest angle
	mvFloat angle = left.dot(right);
	m_qtr.set(axis.components, angle);
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

void mvLFQuaternion::operator*=(const mvFloat& rhs)
{
	m_qtr *= rhs;
}

void mvLFQuaternion::setEulerAnglesInDegrees(const mvVec3& angles)
{
	m_qtr.setDegrees(angles.components);
}

void mvLFQuaternion::setEulerAngles(const mvVec3& angles)
{
	m_qtr.set(angles.components);
}
