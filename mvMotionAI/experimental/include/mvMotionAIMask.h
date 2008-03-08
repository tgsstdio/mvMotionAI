#ifndef MVMOTIONAIMASK_H_INCLUDED
#define MVMOTIONAIMASK_H_INCLUDED

#ifdef MV_MOTIONAI_TYPES_HEADER_FILE_H_
#include MV_MOTIONAI_TYPES_HEADER_FILE_H_
#else
#include <mv/mvMotionAI-Types.h>
#endif

#include MV_TIMER_HEADER_FILE_H_

#ifdef MV_BUILD_DLL
#define MV_GLOBAL_FUNC_PREFIX __declspec(dllexport)
#else
#define MV_GLOBAL_FUNC_PREFIX //__declspec(dllimport)
#endif

#define MV_MOTIONAI_ONE_BIT_IN_LENGTH (1)

struct mvMotionAIStatus
{
	public:
		// 1
		bool isEnabled : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool applyCollisions : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool applyAllForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool applyAllDragForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool isRightHanded : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool omegaInDegrees : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool rotationInDegrees : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool applyVelocity : MV_MOTIONAI_ONE_BIT_IN_LENGTH;

		// 2
		bool integratePosition : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateRotation : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateVelocity : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateFinalVelocity : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateTorque : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateFinalTorque : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateForce : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
		bool integrateFinalForce : MV_MOTIONAI_ONE_BIT_IN_LENGTH;

		// 3
      bool applyTorque : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyOmega : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyDirection : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyQuaternion : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyRotation : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyDragForce : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyDragAccel : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyDragShift : MV_MOTIONAI_ONE_BIT_IN_LENGTH;

		// 4
      bool applyForce : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyAccel : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyShifts : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyGravity : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyAngularForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyGlobalForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyLocalForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
      bool applyDragAngularForces : MV_MOTIONAI_ONE_BIT_IN_LENGTH;
};

#define MV_NOTIONAI_MASK_NO_OF_FLAGS (32);

union mvMotionAIMask
{
	unsigned int numericFlag : MV_NOTIONAI_MASK_NO_OF_FLAGS;
	mvMotionAIStatus statusFlag;
};

void mvMotionAIMask_SetAllFlagsOn(mvMotionAIMask& mask)
{
	mask.numericFlag = 0xffffffff;
}

void mvMotionAIMask_SetAllFlagsOff(mvMotionAIMask& mask)
{
	mask.numericFlag = 0;
}

bool mvMotionAIMask_AnyFlagsOn(const mvMotionAIMask& mask)
{
	return (mask.numericFlag != 0);
}

bool mvMotionAIMask_AnyFlagsOff(const mvMotionAIMask& mask)
{
	return (mask.numericFlag != 0xffffffff);
}

bool mvMotionAIMask_AreAllFlagsOn(const mvMotionAIMask& mask)
{
	return (mask.numericFlag == 0xffffffff);
}

bool mvMotionAIMask_AreAllFlagsOff(const mvMotionAIMask& mask)
{
	return (mask.numericFlag == 0);
}

void mvMotionAIMask_Copy(mvMotionAIMask dest, const mvMotionAIMask& src)
{
	dest.numericFlag = src.numericFlag;
}

void mvMotionAI_FlowDown(mvMotionAIMask& dest, const mvMotionAIMask& master,\
	const mvMotionAIMask& child)
{
	// anything the master allows the child can do
	// bitwise operators

}

#endif // MVMOTIONAIMASK_H_INCLUDED
