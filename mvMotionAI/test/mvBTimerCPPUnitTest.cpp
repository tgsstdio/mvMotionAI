#include "mvBTimerCPPUnitTest.h"
#include <cppunit/extensions/HelperMacros.h>
#include "mvVec3.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( mvTimerCPPUnit );

void mvTimerCPPUnitTest::setUp()
{

}

void mvTimerCPPUnitTest::tearDown()
{

}

void mvTimerCPPUnitTest::testEqual()
{
   CPPUNIT_ASSERT_EQUAL(1,1);
}

void mvVec3Test::testConstructor()
{
   // checking default vec3 constructor A i.e x,y,z = 0.0;
   mvVec3 a;
   mvFloat zero = 0.0;

   CPPUNIT_ASSERT_EQUAL( zero,  a.getX() );
   CPPUNIT_ASSERT_EQUAL( zero,  a.getY() );
   CPPUNIT_ASSERT_EQUAL( zero,  a.getZ() );

   // check supplied X,Y,Z constructor B
   mvFloat bX = 2.30;
   mvFloat bY = -9.13;
   mvFloat bZ = 1000.001;
   mvVec3 b(bX,bY,bZ);

   CPPUNIT_ASSERT_EQUAL( bX,  b.getX() );
   CPPUNIT_ASSERT_EQUAL( bY,  b.getY() );
   CPPUNIT_ASSERT_EQUAL( bZ,  b.getZ() );

   // check supplied mvFloat array pointer constructor C
   // TODO : sizeof check in mvVec3
   mvFloat cArray1[3];
   cArray1[0] = 4.0;
   cArray1[1] = 4.56;
   cArray1[2] = -4.0;
   mvVec3 c(&cArray1[0]);

   CPPUNIT_ASSERT_EQUAL( cArray1[0],  c.getX() );
   CPPUNIT_ASSERT_EQUAL( cArray1[1],  c.getY() );
   CPPUNIT_ASSERT_EQUAL( cArray1[2],  c.getZ() );

   // check supplied mvVec3 constructor D
   mvVec3 d(b);
   CPPUNIT_ASSERT_EQUAL( bX,  d.getX() );
   CPPUNIT_ASSERT_EQUAL( bY,  d.getY() );
   CPPUNIT_ASSERT_EQUAL( bZ,  d.getZ() );
}
