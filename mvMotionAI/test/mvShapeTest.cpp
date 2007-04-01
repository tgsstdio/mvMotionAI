#include "mvShapeTest.h"
#include <mvShape.h>
#include <cppunit/extensions/HelperMacros.h>

#define TESTFIXTURE_CLASS_NAME mvShapeTest

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TESTFIXTURE_CLASS_NAME );

void TESTFIXTURE_CLASS_NAME::setUp()
{
}


void TESTFIXTURE_CLASS_NAME::tearDown()
{

}


void TESTFIXTURE_CLASS_NAME::testConstructor()
{
   const int MAX_BUFFER_SIZE = 1024;
   const int NO_OF_POSSIBLE_SHAPES = 9;
   mvOptionEnum possibleShapes[NO_OF_POSSIBLE_SHAPES] =
   {
      MV_AABOX,
      MV_SPHERE,
      MV_X_AXIS_AA_CYLINDER,
      MV_Y_AXIS_AA_CYLINDER,
      MV_Z_AXIS_AA_CYLINDER,
      MV_XY_PLANE,
      MV_XZ_PLANE,
      MV_YZ_PLANE,
      MV_ANY_PLANE,
   };

   mvIndex noOfDimensions[NO_OF_POSSIBLE_SHAPES] =
   {
      3,// MV_AABOX,
      1,// MV_SPHERE,
      2, //MV_X_AXIS_AA_CYLINDER,
      2, //MV_Y_AXIS_AA_CYLINDER,
      2, //MV_Z_AXIS_AA_CYLINDER,
      0, //MV_XY_PLANE,
      0, //MV_XZ_PLANE,
      0, //MV_YZ_PLANE,
      3, //MV_ANY_PLANE,
   };
   char buffer[MAX_BUFFER_SIZE];
   int i, expectedCount;

   mvOptionEnum aType = MV_AABOX;

   for (i = 0; i < NO_OF_POSSIBLE_SHAPES; i++)
   {
      aType = possibleShapes[i];
      mvShape a(aType);
      sprintf(buffer,"A%d - SHAPE", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(buffer, aType, a.getType());
      expectedCount = noOfDimensions[i];
      sprintf(buffer,"B%d - No Of Dimensions", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(buffer, expectedCount, a.getNoOfDimensions());
   }

}

void TESTFIXTURE_CLASS_NAME::testSetParameter()
{
   mvErrorEnum notExpectedError = MV_FUNCTION_NOT_IMPLEMENTED;
   mvParamEnum anyParameterEnum = MV_NO_PARAMETER;
   mvOptionEnum option = MV_NON_OPTION_ENUM;
   mvFloat zero = 0;
   mvIndex index = 0;
   mvFloat array[10];

   mvShape a(MV_AABOX);
   // test if functions are implemented
   CPPUNIT_ASSERT_MESSAGE("A1 Function SetParameter", a.setParameter(\
      anyParameterEnum, option) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A2 Function SetParameteri", a.setParameteri(\
      anyParameterEnum, index) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A3 Function SetParameterf", a.setParameterf(\
      anyParameterEnum, zero) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A4 Function SetParameterv", a.setParameterv(\
      anyParameterEnum, &array[0]) != notExpectedError);

   mvErrorEnum expectedError = MV_PARAMETER_ARRAY_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 Function setParameterv(NULL,...)",\
      expectedError, a.setParameterv(anyParameterEnum, NULL));
}

void TESTFIXTURE_CLASS_NAME::testGetParameter()
{
   mvErrorEnum notExpectedError = MV_FUNCTION_NOT_IMPLEMENTED;
   mvErrorEnum expectedError;
   mvParamEnum anyParameterEnum = MV_NO_PARAMETER;
   mvOptionEnum option = MV_NON_OPTION_ENUM;
   mvFloat zero = 0;
   mvIndex index = 0;
   mvFloat array[10];
   mvCount count = 5;

   mvShape a(MV_AABOX);
   // test if functions are implemented
   CPPUNIT_ASSERT_MESSAGE("A1 Function getParameter", a.getParameter(\
      anyParameterEnum, &option) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A2 Function getParameteri", a.getParameteri(\
      anyParameterEnum, &index) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A3 Function getParameterf", a.getParameterf(\
      anyParameterEnum, &zero) != notExpectedError);
   CPPUNIT_ASSERT_MESSAGE("A4 Function getParameterv", a.getParameterv(\
      anyParameterEnum, &array[0], &count) != notExpectedError);

   //test for null pointer
   expectedError = MV_OPTION_ENUM_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 Function getParameter", expectedError,\
      a.getParameter(anyParameterEnum, NULL));
   expectedError = MV_INDEX_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 Function getParameteri", expectedError,\
      a.getParameteri(anyParameterEnum, NULL));
   expectedError = MV_FLOAT_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 Function getParameterf", expectedError,\
      a.getParameterf(anyParameterEnum, NULL));
   expectedError = MV_COUNT_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 Function getParameterv(NULL,NULL)", expectedError,\
      a.getParameterv(anyParameterEnum, NULL,NULL));
   expectedError = MV_PARAMETER_ARRAY_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 Function getParameterv(NULL,...)", expectedError,\
      a.getParameterv(anyParameterEnum, NULL,&count));
   mvCount expectedCount = 0;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B6 Retured count", expectedCount, count);
   expectedError = MV_COUNT_DEST_IS_NULL;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B7 Function getParameterv(...,NULL)", expectedError,\
      a.getParameterv(anyParameterEnum, &array[0],NULL));

}
