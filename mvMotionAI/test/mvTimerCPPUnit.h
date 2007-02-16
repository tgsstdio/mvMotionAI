#ifndef MVTIMERCPPUNIT_H_INCLUDED
#define MVTIMERCPPUNIT_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>

class mvTimerCPPUnit : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( mvTimerCPPUnit );
 //  CPPUNIT_TEST( testEqual );
//   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST( testConstructor );
   CPPUNIT_TEST( testSetAndGetValues );
   CPPUNIT_TEST( testUpdate);
   CPPUNIT_TEST(testGetParameteri);
//   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      void testConstructor();
      void testUpdate();
      void testSetAndGetValues();
////      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
      void testGetParameteri();
////      mvErrorEnum getParameter(mvParamEnum paramFlag, mvOptionEnum* option);
//      void testGetParameter();
////      mvErrorEnum getParameterf(mvParamEnum paramFlag, mvFloat* num);
//      void testGetParameterf();
////      mvErrorEnum getParameterv(mvParamEnum paramFlag, mvFloat* numArray,\
////         mvCount* noOfParameters);
//      void testGetParameterv();

//      mvErrorEnum setParameteri(mvParamEnum paramFlag, mvIndex index);
//      mvErrorEnum setParameter(mvParamEnum paramFlag, mvOptionEnum option);
//      mvErrorEnum setParameterf(mvParamEnum paramFlag, mvFloat num);
//      mvErrorEnum setParameterv(mvParamEnum paramFlag, mvFloat* numArray);
//      void testSetParameteri();
//      void testSetParameter();
//      void testSetParameterf();
//      void testSetParameterv();

      void tearDown();
};

#endif // MVTIMERCPPUNIT_H_INCLUDED
