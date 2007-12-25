#include "mvBitFieldsUnitTest.h"
#include <cstdio>

#include <mv/mvMotionAI.h>
#define TESTFIXTURE_CLASS_NAME mvBitFieldUnitTest

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TESTFIXTURE_CLASS_NAME );

void TESTFIXTURE_CLASS_NAME::setUp()
{

}

void TESTFIXTURE_CLASS_NAME::tearDown()
{

}

class mvBodyStatus
{
	public:
		bool enabled : 1;
		bool applyForces : 1;
		bool applyShifts : 1;
		bool applyAccelerations : 1;
		bool applyGravity : 1;
		bool applyCollisions : 1;
		bool applyAllForces : 1;
		bool applyAllDragForces : 1;
};


class mvBody_V3
{
	private:
		mvBodyStatus status;
   public:
		mvVec3 finalVelocity;
		mvShape bodyShape;
      void* bodyUserDataPtr;
      mvFloat bodyMass;
      mvVec3 bodyPosition;
      mvVec3 finalForceVector;
      mvVec3 bodysForceVector;
      mvVec3 finalTorque;
      mvVec3 bodysTorque;
      mvVec3 finalOmega;
      mvVec3 bodysOmega;
      mvVec3 bodysRotation;
      mvVec3 faceDirection;
      mvVec3 faceUp;
      mvFloat bodyAccel;
      mvFloat bodyDeaccel;
      mvFloat bodyMaxSpeed;
      mvVec3 bodyVelocity;
      mvOptionEnum bodyType;
      mvOptionEnum bodyDomain;
      mvFloat* bodyDomainVariables;
};

class mvBody_V4
{
   public:
		mvVec3 finalVelocity;
		mvShape bodyShape;
      void* bodyUserDataPtr;
      mvFloat bodyMass;
      mvVec3 bodyPosition;
      mvVec3 finalForceVector;
      mvVec3 bodysForceVector;
      mvVec3 finalTorque;
      mvVec3 bodysTorque;
      mvVec3 finalOmega;
      mvVec3 bodysOmega;
      mvVec3 bodysRotation;
      mvVec3 faceDirection;
      mvVec3 faceUp;
      mvFloat bodyAccel;
      mvFloat bodyDeaccel;
      mvFloat bodyMaxSpeed;
      mvVec3 bodyVelocity;
      mvOptionEnum bodyType;
      mvOptionEnum bodyDomain;
      mvFloat* bodyDomainVariables;
};

class mvBody_V5
{
	mvBody_V4 sum;
	mvBodyStatus status;
};


void TESTFIXTURE_CLASS_NAME::testBody()
{
	size_t oldBodySize = sizeof(mvBody) + sizeof(mvVec3);
	size_t newBodySize = sizeof(mvBody_V3);
	mvBodyStatus status;

	std::cout << "Old size : " << oldBodySize
		<< " New body size : " << newBodySize
		<< " Status : " << sizeof(mvBodyStatus)
		<< " Bool : " << sizeof(bool)
		<< " Body V5 : " << sizeof(mvBody_V5) << std::endl;
	CPPUNIT_ASSERT_MESSAGE("1 Is not less than old body",newBodySize < oldBodySize);
	status.enabled = true;
	CPPUNIT_ASSERT_MESSAGE("2 Is not less than old body",status.enabled);
	status.applyForces = true;
	CPPUNIT_ASSERT_MESSAGE("3 Is not less than old body",status.applyForces);
	status.enabled = false;
	CPPUNIT_ASSERT_MESSAGE("4 Is not less than old body",!status.enabled);
	CPPUNIT_ASSERT_MESSAGE("5 Is not less than old body",status.applyForces);
}

class mvBehaviourResult_V2
{
   public:
      bool isDefaultMotionSteering : 1;
      bool isDefaultEffectGlobal  : 1;
      bool applyAccel : 1;
      bool applyVelocity : 1;
      bool applyDirection : 1;
      bool applyForce : 1;
      bool applyTorque : 1;
      bool applyOmega : 1;

      bool applyQuaternion : 1;
      bool omegaInDegrees : 1;
      bool rotationInDegrees : 1;
      bool applyRotation : 1;
      unsigned accelMotionType : 2;
		unsigned velocityMotionType : 2;

		unsigned directionMotionType : 2;
		unsigned forceMotionType : 2;
		unsigned torqueMotionType : 2;
		unsigned omegaMotionType : 2;

		unsigned rotationMotionType : 2;
		unsigned quaternionMotionType : 2;
		unsigned accelEffectType : 2;
		unsigned velocityEffectType : 2;

		unsigned directionEffectType : 2;
		unsigned forceEffectType : 2;
		unsigned torqueEffectType : 2;
		unsigned rotationEffectType : 2;

		unsigned omegaEffectType : 2;
		unsigned quaternionEffectType : 2;

      mvVec3 force;
      mvVec3 acceleration;
      mvVec3 velocity;
      mvVec3 direction;
      mvVec3 torque;
      mvVec3 omega;
      mvVec3 rotation;
      mvFloat quaternion[MV_QUATERNION_LENGTH];

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;

      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;
      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;
      mvBaseActionPtr currentGroupBehNode;
      mvIndex behaviourIndex;
      mvIndex groupIndex;
};

void TESTFIXTURE_CLASS_NAME::testBehaviourResult()
{
	size_t oldBodySize = sizeof(mvBehaviourResult);
	size_t newBodySize = sizeof(mvBehaviourResult_V2);

	std::cout << "Old size : " << oldBodySize
		<< " New body size : " << newBodySize
		//<< " Status : " << sizeof(mvBodyStatus)
		<< " Bool : " << sizeof(bool)
		//<< " Body V5 : " << sizeof(mvBody_V5)
		 << std::endl;
	CPPUNIT_ASSERT_MESSAGE("1 Is not less than old body",newBodySize < oldBodySize);
}

class mvForceResult_V2
{
   public:
		bool omegaInDegrees : 1;
      bool rotationInDegrees : 1;
      bool isDefaultMotionSteering : 1;
      bool isDefaultEffectGlobal : 1;
      bool applyForce : 1;
      bool applyAccel : 1;
      bool applyShift : 1;
      bool applyGravity : 1;
      bool applyTorque : 1;
      bool applyOmega : 1;
      bool applyDirection : 1;
      bool applyQuaternion : 1;
      bool applyRotation : 1;
      bool applyDragForce : 1;
      bool applyDragAccel : 1;
      bool applyDragShift : 1;

		unsigned forceMotion : 2;
		unsigned accelMotion : 2;
		unsigned shiftMotion : 2;
		unsigned gravityMotion : 2;
		unsigned torqueMotion : 2;
		unsigned omegaMotion : 2;
		unsigned directionMotion : 2;
		unsigned quaternionMotion : 2;
		unsigned rotationMotion : 2;

		unsigned forceEffect : 2;
		unsigned accelEffect : 2;
		unsigned shiftEffect : 2;
		unsigned gravityEffect : 2;
		unsigned torqueEffect : 2;
		unsigned omegaEffect : 2;
		unsigned directionEffect : 2;
		unsigned quaternionEffect : 2;
		unsigned rotationEffect : 2;

      mvConstWorldPtr currentWorld;
      mvConstBodyPtr currentBody;
      mvVec3 force;
      mvVec3 gravity;
      mvVec3 acceleration;
      mvVec3 shiftVec;
      mvFloat dragForce;
      mvFloat dragAcceleration;
      mvFloat dragShift;
      mvVec3 torque;
      mvVec3 omega;
      mvVec3 rotation;
      mvVec3 direction;
      mvFloat quaternion[MV_FORCE_QUATERNION_LENGTH];

      // predicted items.
      mvVec3 brFuturePosition;
      mvVec3 brFutureFinalPosition;
      mvVec3 brFutureVelocity;
      mvVec3 brFutureFinalVelocity;

      mvFloat currentTimeStep;
      mvFloat elapsedSystemTime;
};

void TESTFIXTURE_CLASS_NAME::testForceResult()
{
	size_t oldBodySize = sizeof(mvForceResult);
	size_t newBodySize = sizeof(mvForceResult_V2);

	std::cout << "Old size : " << oldBodySize
		<< " New body size : " << newBodySize
		//<< " Status : " << sizeof(mvBodyStatus)
		<< " Bool : " << sizeof(bool)
		//<< " Body V5 : " << sizeof(mvBody_V5)
		 << std::endl;
	CPPUNIT_ASSERT_MESSAGE("1 Is not less than old body",newBodySize < oldBodySize);
}
