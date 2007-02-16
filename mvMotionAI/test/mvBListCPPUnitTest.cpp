#include "mvBListCPPUnitTest.h"
#include <cppunit/extensions/HelperMacros.h>

#include "mvBEntryUtility.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( mvBListCPPUnitTest );

void mvBListCPPUnitTest::setUp()
{

}

void mvBListCPPUnitTest::tearDown()
{

}

void mvBListCPPUnitTest::testBaseBehaviours()
{
   mvBEntryUtility beUtility;
   mvTimerPtr nullTimerPtr = NULL;
   mvParamEnum noParameter = MV_NO_PARAMETER;
   mvOptionEnum* nullOptionPtr = NULL;
   mvFloat* nullFloatPtr = NULL;
   mvIndex* nullIndexPtr = NULL;
   mvCount* nullCountPtr = NULL;
   mvOptionEnum optionDest;
   mvFloat floatDest;
   mvFloat floatDestArray[10];
   mvCount countDest;
   mvIndex indexDest;

   /**
    * CASE B : Get parameter Implementation tests
    */

   mvErrorEnum errorValue = MV_FUNCTION_NOT_IMPLEMENTED;
   // TEST A1 check the get parameter with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 FUNCTION NOT IMPLEMENTED = GETPARAMETER",\
      errorValue, beUtility.getParameter(noParameter,nullOptionPtr));

   // TEST A2 check the get parameter with valid option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 FUNCTION NOT IMPLEMENTED = GETPARAMETER",\
      errorValue, beUtility.getParameter(noParameter,&optionDest));

   // TEST A3 check the get parameteri with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A3 FUNCTION NOT IMPLEMENTED = GETPARAMETERi",\
      errorValue, beUtility.getParameteri(noParameter,nullIndexPtr));

   // TEST A4 check the get parameteri with valid option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A4 FUNCTION NOT IMPLEMENTED = GETPARAMETERi",\
      errorValue, beUtility.getParameteri(noParameter,&indexDest));

   // TEST A5 check the get parameteri with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5 FUNCTION NOT IMPLEMENTED = GETPARAMETERf",\
      errorValue, beUtility.getParameterf(noParameter,nullFloatPtr));

   // TEST A6 check the get parameterf with valid option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A6 FUNCTION NOT IMPLEMENTED = GETPARAMETERf",\
      errorValue, beUtility.getParameterf(noParameter,&floatDest));

   // TEST A7 check the get parameteri with 2 null options
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A7 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, beUtility.getParameterv(noParameter,nullFloatPtr,\
      nullCountPtr));

   // TEST A8 check the get parameteri with null float
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A8 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, beUtility.getParameterv(noParameter,nullFloatPtr,\
      &countDest));

   // TEST A9 check the get parameteri with null count
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A9 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, beUtility.getParameterv(noParameter,&floatDestArray[0],\
      nullCountPtr));

   // TEST A10 check the get parameteri with valid inputs
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A11 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, beUtility.getParameterv(noParameter,&floatDestArray[0],\
      &countDest));

   /**
    * CASE B : Set parameter Implementation tests
    */

   mvErrorEnum errorValue = MV_FUNCTION_NOT_IMPLEMENTED;
   // TEST B1 check the get parameter with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 FUNCTION NOT IMPLEMENTED = SETPARAMETER",\
      errorValue, beUtility.setParameter(noParameter,optionDest));

   // TEST B2 check the get parameteri with valid option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 FUNCTION NOT IMPLEMENTED = SETPARAMETERi",\
      errorValue, beUtility.setParameteri(noParameter,indexDest));

   // TEST B3 check the get parameterf with valid option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 FUNCTION NOT IMPLEMENTED = SETPARAMETERf",\
      errorValue, beUtility.setParameterf(noParameter,floatDest));

   // TEST B4 check the get parameteri with valid inputs
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 FUNCTION NOT IMPLEMENTED = SETPARAMETERv",\
      errorValue, beUtility.setParameterv(noParameter,&floatDestArray[0]));

   // TEST B4 check the get parameteri with null float array pointer
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 FUNCTION NOT IMPLEMENTED = SETPARAMETERv",\
      errorValue, beUtility.setParameterv(noParameter,nullFloatPtr));

   // TEST C1 check the timer pointer
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C1 NULL Pointer returned", &beUtility.bTimer,
      beUtility.getTimerPtr());

   // TEST D1 check default confined flag
   CPPUNIT_ASSERT_EQUAL_MESSAGE("D1 CONFINED is not TRUE",true,
      beUtility->confined);

   // TEST E1 check default enabled flag
   CPPUNIT_ASSERT_EQUAL_MESSAGE("E1 ENABLED is not TRUE", true,
      beUtility->enabled);

   // TEST F1 check default weight
   // TODO : more tests here continue

}
