#ifndef MONEYTEST_H
#define MONEYTEST_H
#include "Money.h"
#include <cppunit/extensions/HelperMacros.h>

class MoneyTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( MoneyTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testEqual );
  CPPUNIT_TEST( testAdd );
  CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();
  void testAddThrow();
  void testEqual();
  void testAdd();
  void testConstructor();
};

#endif  // MONEYTEST_H

