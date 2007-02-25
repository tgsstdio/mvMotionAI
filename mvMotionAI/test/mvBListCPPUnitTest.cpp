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
//   mvTimerPtr nullTimerPtr = NULL;
   mvParamEnum noParameter = MV_NO_PARAMETER;
   mvParamEnum anyParameter;
   mvOptionEnum* nullOptionPtr = NULL;
   mvFloat* nullFloatPtr = NULL;
   mvIndex* nullIndexPtr = NULL;
   mvCount* nullCountPtr = NULL;
   mvOptionEnum optionDest;
   mvFloat floatDest;
   mvFloat floatDestArray[10];
   mvCount countDest;
   mvIndex indexDest;
   mvOptionEnum endState;

   /**
    * CASE A : Get parameter Implementation tests
    */
   mvBEntryUtility aUtility;
   mvErrorEnum errorValue = MV_OPTION_ENUM_DEST_IS_NULL;
   // TEST A1 check the get parameter with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 !OPTION_DEST is null = GETPARAMETER",\
      errorValue, aUtility.getParameter(noParameter,nullOptionPtr));

   // TEST A2 check confined
   errorValue = MV_NO_ERROR;
   anyParameter = MV_IS_CONFINED;
   endState = (aUtility.confined) ? MV_TRUE : MV_FALSE;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2a !MV_NO_ERROR = GETPARAMETER",\
      errorValue, aUtility.getParameter(anyParameter,&optionDest));
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2b !MV_TRUE", endState, optionDest);

   // TEST A2 check enabled
   errorValue = MV_NO_ERROR;
   anyParameter = MV_IS_ENABLED;
   endState = (aUtility.enabled) ? MV_TRUE : MV_FALSE;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2a !MV_NO_ERROR = GETPARAMETER",\
      errorValue, aUtility.getParameter(anyParameter,&optionDest));
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2b !MV_TRUE", endState, optionDest);

   // TEST A2 check is timed
   errorValue = MV_NO_ERROR;
   anyParameter = MV_IS_TIMED;
   endState = (aUtility.bTimer.isTimed) ? MV_TRUE : MV_FALSE;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2a !MV_NO_ERROR = GETPARAMETER",\
      errorValue, aUtility.getParameter(anyParameter,&optionDest));
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2b !MV_TRUE", endState, optionDest);

   // TEST A3 check the get parameteri with null option
   errorValue = MV_INDEX_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A3 !MV_INDEX_DEST_IS_NULL from GETPARAMETERi",\
      errorValue, aUtility.getParameteri(noParameter,nullIndexPtr));

   // TEST A4 check the get parameteri with valid option
   errorValue = MV_INVALID_BEHAVIOUR_PARAMETER;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A4 !MV_INVALID_BEHAV_PARAMETER GETPARAMETERi",\
      errorValue, aUtility.getParameteri(noParameter,&indexDest));

   // TEST A5a check the get parameteri with null option
   errorValue = MV_FLOAT_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5a !FLOAT_DEST_IS_NULL from GETPARAMETERf",\
      errorValue, aUtility.getParameterf(noParameter,nullFloatPtr));

   mvFloat dWeight = 1.0;
   // A5 b & c weight
   errorValue = MV_NO_ERROR;
   anyParameter = MV_WEIGHT;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5b !NO_ERROR from GETPARAMETERf",\
      errorValue, aUtility.getParameterf(anyParameter,&floatDest));
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("A5c !Default Weight", dWeight,
      floatDest,0.0001);

   // A5 d & e period
   errorValue = MV_NO_ERROR;
   anyParameter = MV_PERIOD;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5d !NO_ERROR from GETPARAMETERf",\
      errorValue, aUtility.getParameterf(anyParameter,&floatDest));
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("A5e !Default Period",\
      aUtility.bTimer.getPeriod(), floatDest,0.0001);

   // A5 f & g elapsed time
   errorValue = MV_NO_ERROR;
   anyParameter = MV_ELAPSED_TIME;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5f !NO_ERROR from GETPARAMETERf",\
      errorValue, aUtility.getParameterf(anyParameter,&floatDest));
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("A5g !Default Elapsed Time",\
      aUtility.bTimer.getElapsedTime(), floatDest,0.0001);

   // TEST A6 check the get parameterf with valid option
   errorValue = MV_INVALID_BEHAVIOUR_PARAMETER;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A6 FUNCTION NOT IMPLEMENTED = GETPARAMETERf",\
      errorValue, aUtility.getParameterf(noParameter,&floatDest));

   // TEST A7 check the get parameteri with 2 null options
   errorValue = MV_FUNCTION_NOT_IMPLEMENTED;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A7 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, aUtility.getParameterv(noParameter,nullFloatPtr,\
      nullCountPtr));

   // TEST A8 check the get parameteri with null float
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A8 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, aUtility.getParameterv(noParameter,nullFloatPtr,\
      &countDest));

   // TEST A9 check the get parameteri with null count
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A9 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, aUtility.getParameterv(noParameter,&floatDestArray[0],\
      nullCountPtr));

   // TEST A10 check the get parameteri with valid inputs
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A11 FUNCTION NOT IMPLEMENTED = GETPARAMETERv",\
      errorValue, aUtility.getParameterv(noParameter,&floatDestArray[0],\
      &countDest));

   /**
    * CASE B : Set parameter Implementation tests
    */
   mvBEntryUtility bUtility;

   errorValue = MV_FUNCTION_NOT_IMPLEMENTED;
   // TEST B1 check the get parameter with null option
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 FUNCTION NOT IMPLEMENTED = SETPARAMETER",\
      errorValue, bUtility.setParameter(noParameter,optionDest));

   // TEST B2 check the get parameteri with valid option
   errorValue = MV_INVALID_BEHAVIOUR_PARAMETER;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 !MV_INVALID_BEHAV_PARAMETER from SETPARAMETERi",\
      errorValue, bUtility.setParameteri(noParameter,indexDest));

   // TEST B3a check the get parameterf with valid option
   errorValue = MV_INVALID_BEHAVIOUR_PARAMETER;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3a !MV_INVALID_BEHAV_PARAMETER from SETPARAMETERf",\
      errorValue, bUtility.setParameterf(noParameter,floatDest));

   // TEST B3b: set weight and getting no error
   // later tests check valid values
   errorValue = MV_NO_ERROR;
   anyParameter = MV_WEIGHT;
   floatDest = 5.0;
   mvFloat deltaDefault = 0.0001;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3b !MV_NO_ERROR from SETPARAMETERf",\
      errorValue, bUtility.setParameterf(anyParameter,floatDest));

   // B3c check return value
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("B3c != FLOAT RETRIEVED from SETPARAMETERf",\
      floatDest, bUtility.getWeight(), deltaDefault);

   // B3d check timer elasped mode using zero
   anyParameter = MV_ELAPSED_TIME;
   floatDest = 0.0;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3d !MV_NO_ERROR from SETPARAMETERf",\
      errorValue, bUtility.setParameterf(anyParameter,floatDest));

   // B3e check return value
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("B3e != FLOAT (0) from SETPARAMETERf",\
      floatDest, bUtility.getTimerPtr()->getElapsedTime(), deltaDefault);

   // B3f check timer period using 1.5
   anyParameter = MV_PERIOD;
   floatDest = 1.5;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3f !MV_NO_ERROR from SETPARAMETERf",\
      errorValue, bUtility.setParameterf(anyParameter,floatDest));

   // B3g check return value
   CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("B3g != FLOAT (0) from SETPARAMETERf",\
      floatDest, bUtility.getTimerPtr()->getPeriod(), deltaDefault);

   // TEST B4 check the get parameteri with valid inputs
   errorValue = MV_FUNCTION_NOT_IMPLEMENTED;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 FUNCTION NOT IMPLEMENTED = SETPARAMETERv",\
      errorValue, bUtility.setParameterv(noParameter,&floatDestArray[0]));

   // TEST B4 check the get parameteri with null float array pointer
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 FUNCTION NOT IMPLEMENTED = SETPARAMETERv",\
      errorValue, bUtility.setParameterv(noParameter,nullFloatPtr));

   // TEST C1 check the timer pointer
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C1 NULL Pointer returned", &bUtility.bTimer,
      bUtility.getTimerPtr());

   // TEST D1 check default confined flag
   CPPUNIT_ASSERT_EQUAL_MESSAGE("D1 CONFINED is not TRUE",true,
      bUtility.confined);

   // TEST E1 check default enabled flag
   CPPUNIT_ASSERT_EQUAL_MESSAGE("E1 ENABLED is not TRUE", true,
      bUtility.enabled);

   // TEST F1 check default weight
   mvBEntryUtility fUtility;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("f1 default weight is not 1.0", dWeight,\
      fUtility.getWeight());

   mvFloat negetive = -5.45;
   mvFloat zero = 0.0;

   // TEST F2 check zero change goes through
   errorValue = MV_NO_ERROR;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("f2 not MV_NO_ERROR",\
      errorValue, fUtility.setWeight(zero));
   CPPUNIT_ASSERT_EQUAL_MESSAGE("f3 returned weight is not 0.0", zero,\
      fUtility.getWeight());

   // TEST F3 check zero change goes through
   errorValue = MV_FLOAT_VALUE_IS_NOT_POSITIVE;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("f4 not MV_FLOAT_VALUE_IS_NOT_POSITIVE",\
   errorValue, fUtility.setWeight(negetive));
   CPPUNIT_ASSERT_EQUAL_MESSAGE("f5 returned weight is not zero", zero,\
      fUtility.getWeight());
   // TODO : more tests here continue

}
