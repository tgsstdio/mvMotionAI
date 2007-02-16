#ifndef MV_BTIMER_CPPUNIT_HEADER
#define MV_BTIMER_CPPUNIT_HEADER

#include <cppunit/extensions/HelperMacros.h>

class mvTimerCPPUnitTest : public CppUnit::TestFixture
{
CPPUNIT_TEST_SUITE( mvTimerCPPUnitTest );
   CPPUNIT_TEST( testEqual );
//   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
//   CPPUNIT_TEST( testConstructor );
//   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      //mvBEntryTimer(mvFloat periodInSecs = 1.0, mvFloat eTime = 0.0);
      void testConstructor();
      void testEqual();
////      mvCount update(mvFloat timeInSecs);
//      void testUpdate();
////      mvFloat getElaspedTime() const;
////      mvFloat getPeriod() const;
////      mvErrorEnum setPeriod(mvFloat timeInSecs);
////      mvErrorEnum setElapsedTime(mvFloat timeInSecs);
//      void testSetAndGetValues();
////      void toAlways();
////      void toTimed();
//      void testTimedAndAlways();
////      mvErrorEnum getParameteri(mvParamEnum paramFlag, mvIndex* index);
//      void testGetParameteri();
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

#endif
