/**
 * CPPUnit Template Test Suite
 */
#ifndef MVVEC3_HEADER_H
#define MVVEC3_HEADER_H
#include <cppunit/extensions/HelperMacros.h>

class mvVec3Test : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( mvVec3Test );
   CPPUNIT_TEST(  testConstructor );
   //CPPUNIT_TEST( testEqual );
   CPPUNIT_TEST( testAdd );
   CPPUNIT_TEST( testSubtract );
   CPPUNIT_TEST( testMultiply );
   CPPUNIT_TEST( testDivide );
   CPPUNIT_TEST( testSigned );
   CPPUNIT_TEST( testEquality );
   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      void testConstructor();

      void testAdd();
      void testSubtract();
      void testDivide();
      void testMultiply();
      void testSigned();
      void testEquality();

      // TODO: new tests to do
      void testLength();
      void testNormalise();
      void testDotProduct();
      void testCosineMeasure();
      void testCrossProduct();
      void testAssigned();
      void testSetAndReset();

      void tearDown();
};

#endif
