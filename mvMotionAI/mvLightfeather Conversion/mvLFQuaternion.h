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
		mvLFQuaternion multiply(const mvLFQuaternion& rhs);
		mvLFQuaternion interpolate(mvFloat factor) const;
		void invert();
		void composeProduct(const mvLFQuaternion& rhs);
		void setDelta(const mvLFQuaternion& lhs, const mvLFQuaternion& rhs);
		mvVec3 convertToVec3() const;
};


#endif // MVLFQUATERNION_H_INCLUDED
