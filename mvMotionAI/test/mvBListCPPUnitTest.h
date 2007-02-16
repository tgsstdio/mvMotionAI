#ifndef MV_BLIST_CPP_UNIT_HEADER
#define MV_BLIST_CPP_UNIT_HEADER

#include <cppunit/extensions/HelperMacros.h>

class mvBListCPPUnitTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( mvBListCPPUnitTest );
   CPPUNIT_TEST( testBaseBehaviours );
   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST_SUITE_END();

   public:
      void setUp();
      void testBaseBehaviours();
      void tearDown();
};

#endif
