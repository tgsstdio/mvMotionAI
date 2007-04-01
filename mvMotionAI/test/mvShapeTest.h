#ifndef MVSHAPETEST_H_INCLUDED
#define MVSHAPETEST_H_INCLUDED
#include <cppunit/extensions/HelperMacros.h>

#define TESTFIXTURE_CLASS_NAME mvShapeTest

class TESTFIXTURE_CLASS_NAME : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( TESTFIXTURE_CLASS_NAME );
   CPPUNIT_TEST(testConstructor);
   CPPUNIT_TEST(testSetParameter);
   CPPUNIT_TEST(testGetParameter);
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      void tearDown();

      void testConstructor();
      void testSetParameter();
      void testGetParameter();
};

#undef TESTFIXTURE_CLASS_NAME

#endif // MVSHAPETEST_H_INCLUDED
