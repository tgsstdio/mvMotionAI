#ifndef MVBITFIELDSUNITTEST_H_INCLUDED
#define MVBITFIELDSUNITTEST_H_INCLUDED

#include <cppunit/extensions/HelperMacros.h>

#define TESTFIXTURE_CLASS_NAME mvBitFieldUnitTest

class TESTFIXTURE_CLASS_NAME : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( TESTFIXTURE_CLASS_NAME );
   CPPUNIT_TEST(testBody);
   CPPUNIT_TEST(testBehaviourResult);
   CPPUNIT_TEST(testForceResult);
   CPPUNIT_TEST(testForceStatus);
   CPPUNIT_TEST(testWorld);
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      void tearDown();

      void testBody();
      void testBehaviourResult();
      void testForceResult();
      void testForceStatus();
      void testWorld();
      void testGetParameter();
};

#undef TESTFIXTURE_CLASS_NAME

#endif // MVBITFIELDSUNITTEST_H_INCLUDED
