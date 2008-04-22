#ifndef MVLFQUATERNION_H_INCLUDED
#define MVLFQUATERNION_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_VEC_3_HEADER_FILE_H_
#include <lf/lightfeather.h>

class mvLFQuaternion
{
	private:
		mvLFQuaternion(const lf::core::quaternion& rhs);

	public:
		lf::core::quaternion m_qtr;
		mvLFQuaternion();
		mvLFQuaternion(const mvVec3& rhs);
		mvLFQuaternion(const mvLFQuaternion& rhs);
		mvLFQuaternion(const mvVec3& origin, const mvVec3& finalDir);
		mvLFQuaternion multiply(const mvLFQuaternion& rhs);
		mvLFQuaternion interpolate(mvFloat factor) const;
		mvLFQuaternion inBetweenAngles(const mvLFQuaternion& dest, mvFloat factor) const;
		void inBetweenAngles(const mvLFQuaternion& start, const mvLFQuaternion& end, mvFloat factor);
		void invert();
		void composeProduct(const mvLFQuaternion& rhs);
		void setEulerAnglesInDegrees(const mvVec3& angles);
		void setEulerAngles(const mvVec3& angles);
		void setDelta(const mvLFQuaternion& lhs, const mvLFQuaternion& rhs);
		mvVec3 getEulerAnglesInDegrees() const;
		mvVec3 getEulerAngles() const;
		void getEulerAnglesInDegrees(mvVec3& dest) const;
		void getEulerAngles(mvVec3& dest) const;
};


#endif // MVLFQUATERNION_H_INCLUDED
