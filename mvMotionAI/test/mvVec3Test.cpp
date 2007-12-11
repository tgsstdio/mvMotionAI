#include "mvVec3Test.h"
#include <mv/mvMotionAI.h>
#include <cppunit/extensions/HelperMacros.h>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( mvVec3Test );

void mvVec3Test::setUp()
{
}


void mvVec3Test::tearDown()
{
}

/**
 * \brief Testing mvVec3's constructor functions
 *
 *  A: mvVec3(void);
 *  B: mvVec3(const mvFloat& X, const mvFloat& Y, const mvFloat& Z);
 *  C: mvVec3(const mvFloat* array);
 *  D: mvVec3(const mvVec3& rhs);
 */
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

/**
 * \brief testing mvVec3 addition functions
 *
 * A : mvVec3 operator+ (const mvVec3& v) const;
 * B : const mvVec3& operator+= (const mvVec3& v);
 * C : const mvVec3& operator+= (const mvFloat& s);
 * D: void addVec3(const mvVec3& rhs);
 */
void mvVec3Test::testAdd()
{
//  Testing mvVec3 + mvVec3 : A
   mvFloat aX1 = 2.0;
   mvFloat aY1 = 5.0;
   mvFloat aZ1 = 11.0;

   mvFloat aX2 = -34.0;
   mvFloat aY2 = 200.2;
   mvFloat aZ2 = -34.0;

   mvVec3 a1(aX1, aY1, aZ1);
   mvVec3 a2(aX2, aY2, aZ2);

   mvVec3 aSum(aX1 + aX2, aY1 + aY2, aZ1 + aZ2);
   mvVec3 aTestResult = a1 + a2;

   CPPUNIT_ASSERT_EQUAL( aTestResult.getX(),  aSum.getX() );
   CPPUNIT_ASSERT_EQUAL( aTestResult.getY(),  aSum.getY() );
   CPPUNIT_ASSERT_EQUAL( aTestResult.getZ(),  aSum.getZ() );

//  Testing mvVec3 += mvVec3 : B
   mvVec3 bTestResult(a1);
   bTestResult += a2;

   CPPUNIT_ASSERT_EQUAL( bTestResult.getX(),  aSum.getX() );
   CPPUNIT_ASSERT_EQUAL( bTestResult.getY(),  aSum.getY() );
   CPPUNIT_ASSERT_EQUAL( bTestResult.getZ(),  aSum.getZ() );

// Testing mvVec3 += mvFloat : C
   mvVec3 cTestResult(a1);
   mvFloat offset = 3.41;
   cTestResult += offset;

   CPPUNIT_ASSERT_EQUAL( cTestResult.getX(),  a1.getX() + offset);
   CPPUNIT_ASSERT_EQUAL( cTestResult.getY(),  a1.getY() + offset);
   CPPUNIT_ASSERT_EQUAL( cTestResult.getZ(),  a1.getZ() + offset);

// Testing mvVec3.addVec(mvVec3) : D
   mvVec3 dTestResult(a1);
   //dTestResult.addVec3(a2);

   //CPPUNIT_ASSERT_EQUAL( dTestResult.getX(),  aSum.getX() );
   //CPPUNIT_ASSERT_EQUAL( dTestResult.getY(),  aSum.getY() );
   //CPPUNIT_ASSERT_EQUAL( dTestResult.getZ(),  aSum.getZ() );
}

/**
 * \brief testing subtraction functions
 *
 * A: mvVec3 operator- (const mvVec3& v) const;
 * B : const mvVec3& operator-= (const mvVec3& v);
 * C : const mvVec3& operator-= (const mvFloat& s);
 * D : void minusVec3(const mvVec3& rhs);
 */
void mvVec3Test::testSubtract()
{
   // CODE TAKEN FROM TEST ADD BUT ADAPTED
   //  Testing mvVec3 + mvVec3 : A
   mvFloat aX1 = 2.0;
   mvFloat aY1 = 5.0;
   mvFloat aZ1 = 11.0;

   mvFloat aX2 = -34.0;
   mvFloat aY2 = 200.2;
   mvFloat aZ2 = -34.0;

   mvVec3 a1(aX1, aY1, aZ1);
   mvVec3 a2(aX2, aY2, aZ2);

   mvVec3 aSum(aX1 - aX2, aY1 - aY2, aZ1 - aZ2);
   mvVec3 aTestResult = a1 - a2;

   CPPUNIT_ASSERT_EQUAL( aTestResult.getX(),  aSum.getX() );
   CPPUNIT_ASSERT_EQUAL( aTestResult.getY(),  aSum.getY() );
   CPPUNIT_ASSERT_EQUAL( aTestResult.getZ(),  aSum.getZ() );

   //  Testing mvVec3 += mvVec3 : B
   mvVec3 bTestResult(a1);
   bTestResult -= a2;

   CPPUNIT_ASSERT_EQUAL( bTestResult.getX(),  aSum.getX() );
   CPPUNIT_ASSERT_EQUAL( bTestResult.getY(),  aSum.getY() );
   CPPUNIT_ASSERT_EQUAL( bTestResult.getZ(),  aSum.getZ() );

   // Testing mvVec3 += mvFloat : C
   mvVec3 cTestResult(a1);
   mvFloat offset = 3.41;
   cTestResult -= offset;

   CPPUNIT_ASSERT_EQUAL( cTestResult.getX(),  a1.getX() - offset);
   CPPUNIT_ASSERT_EQUAL( cTestResult.getY(),  a1.getY() - offset);
   CPPUNIT_ASSERT_EQUAL( cTestResult.getZ(),  a1.getZ() - offset);

   // Testing mvVec3.addVec(mvVec3) : D
   mvVec3 dTestResult(a1);
   //dTestResult.minusVec3(a2);

   //CPPUNIT_ASSERT_EQUAL( dTestResult.getX(),  aSum.getX() );
   //CPPUNIT_ASSERT_EQUAL( dTestResult.getY(),  aSum.getY() );
   //CPPUNIT_ASSERT_EQUAL( dTestResult.getZ(),  aSum.getZ() );
}

/** \brief testing division functions
 *
 * NOTE : investigate divide by zero errors
 *
 * A : mvVec3 operator/ (const mvFloat s) const;
 * B : const mvVec3& operator/= (const mvFloat& s);
 * C : void divideVec3(const mvVec3& rhs);
 */
void mvVec3Test::testDivide()
{
   mvFloat vx = 3.40;
   mvFloat vy = 1999.0;
   mvFloat vz = -40.23;
   mvFloat positiveFactor = 2.54;
   mvFloat negetiveFactor = -23.0;
   mvFloat zero = 0;
   mvVec3 sample(vx,vy,vz);
   mvVec3 result1(vx / positiveFactor, vy / positiveFactor,
      vz / positiveFactor);
   mvVec3 result2(vx / negetiveFactor, vy / negetiveFactor,
      vz / negetiveFactor);
   mvVec3 result3(vx / zero, vy / zero, vz / zero);

   // TESTING A 1 : positive multiple
   mvVec3 a_1(sample / positiveFactor);

   CPPUNIT_ASSERT_EQUAL( result1.getX(),  a_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  a_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  a_1.getZ() );

   // TESTING A 2 : negetive multiple
   mvVec3 a_2(sample / negetiveFactor);

   CPPUNIT_ASSERT_EQUAL( result2.getX(),  a_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  a_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  a_2.getZ() );

   // TESTING A 3 : zero multiple
   mvVec3 a_3(sample / zero);

   CPPUNIT_ASSERT_EQUAL( result3.getX(),  a_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  a_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  a_3.getZ() );

   // TESTING FUNCTION B 1 : positive multiple
   mvVec3 b_1(sample);
   b_1 /= positiveFactor;

   CPPUNIT_ASSERT_EQUAL( result1.getX(),  b_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  b_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  b_1.getZ() );

   // TESTING FUNCTION  B 2 : negetive multiple
   mvVec3 b_2(sample);
   b_2 /= negetiveFactor;

   CPPUNIT_ASSERT_EQUAL( result2.getX(),  b_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  b_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  b_2.getZ() );

   // TESTING FUNCTION  B 3 : zero multiple
   mvVec3 b_3(sample);
   b_3 /= zero;

   CPPUNIT_ASSERT_EQUAL( result3.getX(),  b_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  b_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  b_3.getZ() );

	/*
   // TESTING C 1 : positive vector
   mvVec3 c_1(sample);
   mvVec3 c_1_2(positiveFactor, positiveFactor, positiveFactor);
   c_1.divideVec3(c_1_2);
   CPPUNIT_ASSERT_EQUAL( result1.getX(),  c_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  c_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  c_1.getZ() );

   // TESTING C 2 : negetive vector
   mvVec3 c_2(sample);
   mvVec3 c_2_2(negetiveFactor, negetiveFactor, negetiveFactor);
   c_2.divideVec3(c_2_2);
   CPPUNIT_ASSERT_EQUAL( result2.getX(),  c_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  c_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  c_2.getZ() );

   // TESTING C 3 : zero vector
   mvVec3 c_3(sample);
   mvVec3 c_3_2(zero, zero, zero);
   c_3.divideVec3(c_3_2);
   CPPUNIT_ASSERT_EQUAL( result3.getX(),  c_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  c_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  c_3.getZ() );
   */
}

/** \brief testing division functions
 *
 * NOTE : testing zero
 * A : mvVec3 operator* (const mvFloat s) const;
 * B : const mvVec3& operator*= (const mvFloat& s);
 * C : void timesVec3(const mvVec3& rhs);
 * D : friend mvVec3 operator* (float s, const mvVec3& v);
 */
void mvVec3Test::testMultiply()
{

   mvFloat vx = 3.40;
   mvFloat vy = 1999.0;
   mvFloat vz = -40.23;
   mvFloat positiveFactor = 2.54;
   mvFloat negetiveFactor = -23.0;
   mvFloat zero = 0;
   mvVec3 sample(vx,vy,vz);
   mvVec3 result1(vx * positiveFactor, vy * positiveFactor,
      vz * positiveFactor);
   mvVec3 result2(vx * negetiveFactor, vy * negetiveFactor,
      vz * negetiveFactor);
   mvVec3 result3(vx * zero, vy * zero, vz * zero);

   // TESTING A 1 : positive multiple
   mvVec3 a_1(sample * positiveFactor);

   CPPUNIT_ASSERT_EQUAL( result1.getX(),  a_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  a_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  a_1.getZ() );

   // TESTING A 2 : negetive multiple
   mvVec3 a_2(sample * negetiveFactor);

   CPPUNIT_ASSERT_EQUAL( result2.getX(),  a_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  a_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  a_2.getZ() );

   // TESTING A 3 : zero multiple
   mvVec3 a_3(sample * zero);

   CPPUNIT_ASSERT_EQUAL( result3.getX(),  a_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  a_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  a_3.getZ() );

   // TESTING FUNCTION B 1 : positive multiple
   mvVec3 b_1(sample);
   b_1 *= positiveFactor;

   CPPUNIT_ASSERT_EQUAL( result1.getX(),  b_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  b_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  b_1.getZ() );

   // TESTING FUNCTION  B 2 : negetive multiple
   mvVec3 b_2(sample);
   b_2 *= negetiveFactor;

   CPPUNIT_ASSERT_EQUAL( result2.getX(),  b_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  b_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  b_2.getZ() );

   // TESTING FUNCTION  B 3 : zero multiple
   mvVec3 b_3(sample);
   b_3 *= zero;

   CPPUNIT_ASSERT_EQUAL( result3.getX(),  b_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  b_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  b_3.getZ() );

   // TESTING C 1 : positive vector
   mvVec3 c_1(positiveFactor, positiveFactor, positiveFactor);
   /*
   c_1.timesVec3(sample);
   CPPUNIT_ASSERT_EQUAL( result1.getX(),  c_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  c_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  c_1.getZ() );

   // TESTING C 2 : negetive vector
   mvVec3 c_2(negetiveFactor, negetiveFactor, negetiveFactor);
   c_2.timesVec3(sample);
   CPPUNIT_ASSERT_EQUAL( result2.getX(),  c_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  c_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  c_2.getZ() );

   // TESTING C 3 : zero vector
   mvVec3 c_3(zero, zero, zero);
   c_3.timesVec3(sample);
   CPPUNIT_ASSERT_EQUAL( result3.getX(),  c_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  c_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  c_3.getZ() );
   */

   // TESTING D 1 : positive multiple
   mvVec3 d_1(positiveFactor * sample);

   CPPUNIT_ASSERT_EQUAL( result1.getX(),  d_1.getX() );
   CPPUNIT_ASSERT_EQUAL( result1.getY(),  d_1.getY() );
   CPPUNIT_ASSERT_EQUAL( result1.getZ(),  d_1.getZ() );

   // TESTING D 2 : negetive multiple
   mvVec3 d_2(negetiveFactor * sample);

   CPPUNIT_ASSERT_EQUAL( result2.getX(),  d_2.getX() );
   CPPUNIT_ASSERT_EQUAL( result2.getY(),  d_2.getY() );
   CPPUNIT_ASSERT_EQUAL( result2.getZ(),  d_2.getZ() );

   // TESTING D 3 : zero multiple
   mvVec3 d_3(zero * sample);

   CPPUNIT_ASSERT_EQUAL( result3.getX(),  d_3.getX() );
   CPPUNIT_ASSERT_EQUAL( result3.getY(),  d_3.getY() );
   CPPUNIT_ASSERT_EQUAL( result3.getZ(),  d_3.getZ() );
}

/** \brief testing signed operator
 *
 *  mvVec3 operator- (void) const;
 */
void mvVec3Test::testSigned()
{
   mvFloat positive = 4.0;
   mvFloat negetive = -0.2465;
   mvFloat zero = 0;

   // TEST A : positive to negetive
   mvFloat temp = positive;
   mvVec3 a(temp, temp, temp);
   mvVec3 a_Result(-temp, -temp, -temp);
   mvVec3 a_2(-a);

   CPPUNIT_ASSERT_EQUAL( a_Result.getX(),  a_2.getX() );
   CPPUNIT_ASSERT_EQUAL( a_Result.getY(),  a_2.getY() );
   CPPUNIT_ASSERT_EQUAL( a_Result.getZ(),  a_2.getZ() );

   // TEST B :  negetive to positive
   temp = negetive;
   mvVec3 b(temp, temp, temp);
   mvVec3 b_Result(-temp, -temp, -temp);
   mvVec3 b_2(-b);

   CPPUNIT_ASSERT_EQUAL( b_Result.getX(),  b_2.getX() );
   CPPUNIT_ASSERT_EQUAL( b_Result.getY(),  b_2.getY() );
   CPPUNIT_ASSERT_EQUAL( b_Result.getZ(),  b_2.getZ() );

   // TEST B :  zero to zero
   temp = zero;
   mvVec3 c(temp, temp, temp);
   mvVec3 c_Result(-temp, -temp, -temp);
   mvVec3 c_2(-c);

   CPPUNIT_ASSERT_EQUAL( c_Result.getX(),  c_2.getX() );
   CPPUNIT_ASSERT_EQUAL( c_Result.getY(),  c_2.getY() );
   CPPUNIT_ASSERT_EQUAL( c_Result.getZ(),  c_2.getZ() );
}

/** \brief testing signed operator
 *
 * A: bool operator== (const mvVec3& v) const;
 * B: bool operator!= (const mvVec3& v) const;
 */
void mvVec3Test::testEquality()
{
   mvFloat ax = 4.0;
   mvFloat ay = 1000.001;
   mvFloat az = -923.42;
   mvFloat zero = 0;
   mvVec3 sample(ax,ay,az);

   // == run 8 cases i.e 2 (binary) ^ 3 (components)

   // TESTING A 1 : case 0 all equal
   mvVec3 a_1(ax,ay,az);
   CPPUNIT_ASSERT_EQUAL(sample == a_1, true);

   // TESTING A 2 : partial equal case 1 i.e NOT TRUE
   mvVec3 a_2(ax,ay,zero);
   CPPUNIT_ASSERT_EQUAL(sample == a_2, false);

   // TESTING A 3 : partial equal case 2 i.e NOT TRUE
   mvVec3 a_3(ax, zero, az);
   CPPUNIT_ASSERT_EQUAL(sample == a_3, false);

   // TESTING A 4 : partial equal case 3 i.e NOT TRUE
   mvVec3 a_4(ax, zero, zero);
   CPPUNIT_ASSERT_EQUAL(sample == a_4, false);

   // TESTING A 5  : partial equal case 4 i.e NOT TRUE
   mvVec3 a_5(zero,ay,az);
   CPPUNIT_ASSERT_EQUAL(sample == a_5, false);

   // TESTING A 6 : partial equal case 5 i.e NOT TRUE
   mvVec3 a_6(zero,ay,zero);
   CPPUNIT_ASSERT_EQUAL(sample == a_6, false);

   // TESTING A 7 : partial equal case 6 i.e NOT TRUE
   mvVec3 a_7(zero, zero, az);
   CPPUNIT_ASSERT_EQUAL(sample == a_7, false);

   // TESTING A 8 : full error case 7 i.e NOT TRUE
   mvVec3 a_8(zero, zero, zero);
   CPPUNIT_ASSERT_EQUAL(sample == a_8, false);

   // TESTING  != run 8 cases i.e 2 (binary) ^ 3 (components)

   // TESTING b 1 : case 0 all equal FALSE
   mvVec3 b_1(ax,ay,az);
   CPPUNIT_ASSERT_EQUAL(sample != b_1, false);

   // TESTING A 2 : partial equal case 1 i.e TRUE
   mvVec3 b_2(ax,ay,zero);
   CPPUNIT_ASSERT_EQUAL(sample != b_2, true);

   // TESTING A 3 : partial equal case 2 i.e TRUE
   mvVec3 b_3(ax, zero, az);
   CPPUNIT_ASSERT_EQUAL(sample != b_3, true);

   // TESTING A 4 : partial equal case 3 i.e NOT TRUE
   mvVec3 b_4(ax, zero, zero);
   CPPUNIT_ASSERT_EQUAL(sample != b_4, true);

   // TESTING A 5  : partial equal case 4 i.e TRUE
   mvVec3 b_5(zero,ay,az);
   CPPUNIT_ASSERT_EQUAL(sample != b_5, true);

   // TESTING A 6 : partial equal case 5 i.e TRUE
   mvVec3 b_6(zero,ay,zero);
   CPPUNIT_ASSERT_EQUAL(sample != b_6, true);

   // TESTING A 7 : partial equal case 6 i.e TRUE
   mvVec3 b_7(zero, zero, az);
   CPPUNIT_ASSERT_EQUAL(sample != b_7, true);

   // TESTING A 8 : full error case 7 i.e TRUE
   mvVec3 b_8(zero, zero, zero);
   CPPUNIT_ASSERT_EQUAL(sample != b_8, true);
}
