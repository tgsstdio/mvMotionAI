#ifndef MV_BLIST_CPP_UNIT_HEADER
#define MV_BLIST_CPP_UNIT_HEADER
#include <cppunit/extensions/HelperMacros.h>
#include <mv/mvMotionAI.h>

class mvBListCPPUnitTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( mvBListCPPUnitTest );
   CPPUNIT_TEST( testEntryUtility );
   CPPUNIT_TEST( testEntryConstructor);
   //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
   CPPUNIT_TEST_SUITE_END();


   public:
      mvBaseActionPtr testAction;

      void setUp();
      // TODO : test set/get parameterv
      void testEntryUtility();
      void testEntryConstructor();
      void tearDown();
};

#endif
