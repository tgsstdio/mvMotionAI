#include "mvTimerCPPUnit.h"
#include <mv/mvMotionAI.h>
#include <cmath>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION( mvTimerCPPUnit );

mvParamEnum paramArray[] =
{
   MV_NO_PARAMETER,
   MV_SPEED,
   MV_MAX_SPEED,
   MV_ACCELERATION,
   MV_DECELERATION,
   MV_MASS,
//   MV_STATE,
   MV_SHAPE,
   MV_TYPE,
   MV_DOMAIN,
   MV_FORCE_VECTOR,

   MV_VELOCITY,
   MV_ACCELERATION_VECTOR,
   MV_FORCE_QUANTITY,
   //MV_GRAVITIONAL_MASS,  duplicate
   MV_CONSTANT, // renamed
   MV_POSITION,
   MV_LENGTH,
   MV_RADIUS,
   MV_X_WIDTH,
//   MV_Y_LENGTH,
   MV_Z_DEPTH,
   MV_DIRECTION,
   MV_WAYPOINT,
   MV_BODY,
   MV_PATHWAY,
//   MV_PERCEIVED_COHESION_FLAG, // remove flag
//   MV_PERCEIVED_ALIGNMENT_FLAG, // remove flag
   MV_COHESION_FACTOR,
   MV_SEPARATION_FACTOR,
   MV_ALIGNMENT_FACTOR,
   // new enums
   MV_SHAPE_DIMENSIONS,
   MV_IS_ENABLED,
   MV_DOMAIN_VARIABLES,
   MV_NO_OF_BODIES,
   MV_NO_OF_GROUPS,
   MV_NO_OF_FORCES,
   MV_NO_OF_WAYPOINTS,
   MV_NO_OF_OBSTACLES,
   MV_NO_OF_GROUP_BEHAVIOURS,
   MV_NO_OF_BEHAVIOURS,
   MV_WIDTH,
   MV_DEPTH,
   // new enums behaviour list
   MV_MODE,
   MV_CURRENT_INDEX,
   MV_WEIGHT,
   MV_FINAL_VELOCITY,
   MV_FINAL_SPEED,
   MV_FINAL_DIRECTION,
   MV_PLANE_NORMAL,
   MV_LINE_VECTOR,
   MV_ELAPSED_TIME,
   MV_PERIOD,
   MV_IS_TIMED,
   MV_INDEX,

   // tree movement functions
   MV_NEW_NODE,
   MV_NEW_LEVEL,
   MV_NEXT_NODE,
   MV_PREV_NODE,
   MV_UP_LEVEL,
   MV_DOWN_LEVEL,
   MV_IS_CONFINED,
   MV_GROUP,
   MV_AUTO_CONVERT_INDEX,
   MV_RIGHT_HANDED,

   // user defined parameters
   MV_USER_PARAM_0,
   MV_USER_PARAM_1,
   MV_USER_PARAM_2,
   MV_USER_PARAM_3,
//   MV_USER_PARAM_5,

   MV_NO_OF_PARAM_ENUMS,
};

void mvTimerCPPUnit::tearDown()
{

}

void mvTimerCPPUnit::setUp()
{

}

void mvTimerCPPUnit::testGetParameteri()
{
   mvIndex* indexPtr = NULL;
   mvIndex paramIndex;
   mvParamEnum param;
   mvErrorEnum error;
   mvTimer a;
   int i;

   // TEST A1 : check all parameters with invalid index ptr
   for (i = MV_NO_PARAMETER; i <= MV_NO_OF_PARAM_ENUMS; i++)
   {
      error = a.getParameteri(paramArray[i],indexPtr);
      CPPUNIT_ASSERT_EQUAL(MV_INDEX_DEST_IS_NULL, error);
   }

   // TEST A2 : check all parameters with index
   for (i = MV_NO_PARAMETER; i <= MV_NO_OF_PARAM_ENUMS; i++)
   {
      error = a.getParameteri(paramArray[i],&paramIndex);
      CPPUNIT_ASSERT_EQUAL(MV_INVALID_TIMER_PARAMETER, error);
   }
}

void mvTimerCPPUnit::testSetAndGetValues()
{
   mvFloat defaultPeriod = 1.0;
   mvFloat defaultElapsedTime = 0.0;
   mvFloat negetive = -4.5;
   mvFloat small = 1.4;
   mvFloat big = 23.0;
   mvFloat massive = 1000;
   mvFloat zero = 0.0;
   mvErrorEnum error;

   // CASE A : default constructor, no parameters
   mvTimer a;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A (a) Default (1.0) not returned", defaultPeriod,\
      a.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A (b) Default (0.0) not returned",\
      defaultElapsedTime, a.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A (c) Not TIMED MODE (FALSE)", false, a.isTimed);

   // TEST A1 : set new period small = OK
   error = a.setPeriod(small);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (a) MV_NO_ERROR not returned", MV_NO_ERROR,\
      error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (b) Small not returned", small,\
      a.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (c) Default (0.0) not returned",\
      defaultElapsedTime, a.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (d) Not TIMED MODE (FALSE)", false, a.isTimed);

   // TEST A2 : set new period = NOT OK (negetive) should be small
   error = a.setPeriod(negetive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (a) MV_FLOAT_VALUE_IS_NOT_POSITIVE not returned",\
      MV_FLOAT_VALUE_IS_NOT_POSITIVE, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (b) Small not returned", small,\
      a.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (c) Default (0.0) not returned",\
      defaultElapsedTime, a.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (d) Not TIMED MODE (FALSE)", false, a.isTimed);

   // CASE B : using period of zero
   mvTimer b(zero);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B (a) Zero not returned", zero,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B (b) Default Elapsed Time (0.0) not returned",\
      defaultElapsedTime, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B (c) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B1  change the elapsed time to big first, error elapsed time = 0.0
   error = b.setElapsedTime(big);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (b) Zero Period not returned", zero,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (c) Zero Elapsed Time not returned",\
      zero, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B2  change the period to big first, no error
   error = b.setPeriod(big);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (b) Big Period not returned", big,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (c) Zero Elapsed Time not returned",\
      zero, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B3  change the elapsed time to big, no error
   error = b.setElapsedTime(big);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 (b) Big Period not returned", big,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 (c) Big Elapsed Time not returned",\
      big, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B3 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B4  change the elapsed time to negetive, NO_ERROR but no change
   error = b.setElapsedTime(negetive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 (a) MV_FLOAT_VALUE_IS_NOT_POSITIVE not returned",\
      MV_FLOAT_VALUE_IS_NOT_POSITIVE, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 (b) Big Period not returned", big,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 (c) Big Elapsed Time not returned",\
      big, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B4 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B5 : change period to massive, no changes to elapsed time
   error = b.setPeriod(massive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 (b) Massive Period not returned", massive,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 (c) Big Elapsed Time not returned",\
      big, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B5 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B6 : change ELAPSED TIME to massive, no errors
   error = b.setElapsedTime(massive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B6 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B6 (b) Massive Period not returned", massive,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B6 (c) Massive Elapsed Time not returned",\
      massive, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B6 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // TEST B7 : change ELAPSED TIME to big, no errors
   error = b.setElapsedTime(big);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B7 (a) MV_NO_ERROR not returned",\
      MV_NO_ERROR, error);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B7 (b) Massive Period not returned", massive,\
      b.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B7 (c) Big Elapsed Time not returned",\
      big, b.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B7 (d) Not TIMED MODE (FALSE)", false, b.isTimed);

   // CASE C :
   mvTimer c;

   // check default
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C (a) Not TIMED MODE (FALSE)", false, c.isTimed);

   // TEST C1 : set to always
   c.toAlways();
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C1 (a) Not TIMED MODE (FALSE)", false, c.isTimed);

   // TEST C2 : set to timed
   c.toTimed();
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C2 (a) TIMED MODE (TRUE)", true, c.isTimed);

   // TEST C3 : set to always
   c.toAlways();
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C3 (a) Not TIMED MODE (FALSE)", false, c.isTimed);
}

void mvTimerCPPUnit::testUpdate()
{
   mvFloat defaultPeriod = 1.0;
   mvFloat defaultElapsedTime = 0.0;
   mvFloat negetive = -4.5;
   mvFloat tiny = 0.2;
   mvFloat small = 1.4;
   mvFloat big = 23.0;
//   mvFloat massive = 1000;
   mvFloat zero = 0.0;
   mvFloat noOfTimes;
   mvFloat once = 1;
   mvFloat noOfIterations = 0;
   mvFloat negetiveStep = -1;
//   int predicted;
//   mvFloat temp, h;
   int i;
   int MAX_NO_OF_TIMES = 20;
   int MAX_CHAR_BUFFER_SIZE = 256;
   char message[MAX_CHAR_BUFFER_SIZE];

   // CASE A : default constructor, no parameters
   mvTimer a;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Default (1.0) not returned", defaultPeriod,\
      a.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Default (0.0) not returned",\
      defaultElapsedTime, a.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Not TIMED MODE (FALSE)", false, a.isTimed);

   // TEST A1 : update with default(always)
   noOfTimes = a.update(tiny);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Not once per update",once, noOfTimes);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Default (1.0) not returned", defaultPeriod,\
      a.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Default (0.0) not returned",\
      defaultElapsedTime, a.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("Not TIMED MODE (FALSE)", false, a.isTimed);

   // TEST A2 : update with always
   a.toAlways();
   for (i = 1; i <= MAX_NO_OF_TIMES; i++)
   {
      noOfTimes = a.update(tiny);
      sprintf(message, "A2 : Not once per update (%i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message,once, noOfTimes);
      sprintf(message, "A2 : Default (1.0) not returned (%i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, defaultPeriod,\
         a.getPeriod());
      sprintf(message, "A2 : Default (0.0) not returned (%i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message,\
         defaultElapsedTime, a.getElapsedTime());
      sprintf(message, "A2 : Not ALWAYS (FALSE) %i", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, false, a.isTimed);
   }

   // TEST A3 : set to timed, fixed time in secs = tiny
   a.toTimed();
   mvFloat tempArray[2][MAX_NO_OF_TIMES];
   // tempArray[0] is returned update value
   tempArray[0][0] = 0;
   tempArray[0][1] = 0;
   tempArray[0][2] = 0;
   tempArray[0][3] = 0;
   tempArray[0][4] = 1;
   tempArray[0][5] = 0;
   tempArray[0][6] = 0;
   tempArray[0][7] = 0;
   tempArray[0][8] = 0;
   tempArray[0][9] = 1;
   tempArray[0][10] = 0;
   tempArray[0][11] = 0;
   tempArray[0][12] = 0;
   tempArray[0][13] = 0;
   tempArray[0][14] = 1;
   tempArray[0][15] = 0;
   tempArray[0][16] = 0;
   tempArray[0][17] = 0;
   tempArray[0][18] = 0;
   tempArray[0][19] = 1;

   // tempArray[1] is elaspedTime on timer
   tempArray[1][0] = 0.2;
   tempArray[1][1] = 0.4;
   tempArray[1][2] = 0.6;
   tempArray[1][3] = 0.8;
   tempArray[1][4] = 0.0;
   tempArray[1][5] = 0.2;
   tempArray[1][6] = 0.4;
   tempArray[1][7] = 0.6;
   tempArray[1][8] = 0.8;
   tempArray[1][9] = 0.0;
   tempArray[1][10] = 0.2;
   tempArray[1][11] = 0.4;
   tempArray[1][12] = 0.6;
   tempArray[1][13] = 0.8;
   tempArray[1][14] = 0.0;
   tempArray[1][15] = 0.2;
   tempArray[1][16] = 0.4;
   tempArray[1][17] = 0.6;
   tempArray[1][18] = 0.8;
   tempArray[1][19] = 0.0;
	// post update
   for (i = 0; i < MAX_NO_OF_TIMES; i++)
   {
      noOfTimes = a.update(tiny);
      sprintf(message, "A3 : tempArray[0][%i] not returned", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message,tempArray[0][i], noOfTimes);
      sprintf(message, "A3 : Default (1.0) not returned (i = %i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, defaultPeriod,\
         a.getPeriod());
      sprintf(message, "A3 : tempArray[1][%i] not returned", i);
      CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(message,tempArray[1][i],\
         a.getElapsedTime(), 0.00001f);
      sprintf(message, "A3 : Not TIMED MODE (TRUE) (i = %i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, true, a.isTimed);
   }

   // TEST B : variable time i.e i * tiny, manual calc = 20 values,
   // small period.
   mvTimer b(small);
   tempArray[0][0] = 0;
   tempArray[0][1] = 0;
   tempArray[0][2] = 0;
   tempArray[0][3] = 0;
   tempArray[0][4] = 1;
   tempArray[0][5] = 1;
   tempArray[0][6] = 1;
   tempArray[0][7] = 1;
   tempArray[0][8] = 1;
   tempArray[0][9] = 1;
   tempArray[0][10] = 1;
   tempArray[0][11] = 2;
   tempArray[0][12] = 2;
   tempArray[0][13] = 2;
   tempArray[0][14] = 2;
   tempArray[0][15] = 2;
   tempArray[0][16] = 2;
   tempArray[0][17] = 2;
   tempArray[0][18] = 3;
   tempArray[0][19] = 3;

   tempArray[1][0] = 0;
   tempArray[1][1] = 0.2;
   tempArray[1][2] = 0.6;
   tempArray[1][3] = 1.2;
   tempArray[1][4] = 0.6;
   tempArray[1][5] = 0.2;
   tempArray[1][6] = 0;
   tempArray[1][7] = 0;
   tempArray[1][8] = 0.2;
   tempArray[1][9] = 0.6;
   tempArray[1][10] = 1.2;
   tempArray[1][11] = 0.6;
   tempArray[1][12] = 0.2;
   tempArray[1][13] = 0;
   tempArray[1][14] = 0;
   tempArray[1][15] = 0.2;
   tempArray[1][16] = 0.6;
   tempArray[1][17] = 1.2;
   tempArray[1][18] = 0.6;
   tempArray[1][19] = 0.2;

   b.toTimed();
   for (i = 0; i < MAX_NO_OF_TIMES; i++)
   {
      noOfTimes = b.update(tiny * i);
      sprintf(message, "A3 : tempArray[0][%i] not returned", i);
      CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(message,tempArray[0][i], noOfTimes,\
         0.001f);
      sprintf(message, "A3 : Small not returned (i = %i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, small,\
         b.getPeriod());
      sprintf(message, "A3 : tempArray[1][%i] not returned", i);
      CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(message,tempArray[1][i],\
         b.getElapsedTime(), 0.001f);
      sprintf(message, "A3 : Not TIMED MODE (TRUE) (i = %i)", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, true, b.isTimed);
   }

   // TODO : TEST C for always, changing period between

   // TODO : TEST D for timed, changing period between

   // TEST D: negetive regression for always
   mvTimer d;
   d.toAlways();
   for (i = 0; i < MAX_NO_OF_TIMES; i++)
   {
      noOfTimes = d.update(negetiveStep);
      sprintf(message, "D : Negetive Step not Returned not returned i = %i", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, negetiveStep,\
         noOfTimes);
   }

   // TEST E: negetive regression for always
   mvTimer e;
   e.toTimed();
   for (i = 0; i < MAX_NO_OF_TIMES; i++)
   {
      noOfTimes = d.update(negetiveStep);
      sprintf(message, "D : Negetive Step not Returned not returned i = %i", i);
      CPPUNIT_ASSERT_EQUAL_MESSAGE(message, negetiveStep,\
         noOfTimes);
   }
}

void mvTimerCPPUnit::testConstructor()
{
   // checking default vec3 constructor A i.e x,y,z = 0.0;
   /* TODO (White 2#1#): TODO : really weird error - detected as Trojan BEKU
   BY Avant Virus Scanner : must compile with Vec3
   */
   mvVec3 v;
   mvFloat defaultPeriod = 1.0;
   mvFloat defaultElapsedTime = 0.0;
   mvFloat negetive = -4.5;
   mvFloat small = 1.4;
   mvFloat big = 23.0;
   mvFloat massive = 1000;
   mvFloat zero = 0.0;

   // TEST A1: check two parameters non-negetive numbers are returned
   mvTimer a1(zero,zero);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (a) Zero not returned",zero, a1.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (b) Zero not returned",zero, a1.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A1 (c) Not TIMED MODE (FALSE)",false, a1.isTimed);

   // TEST A2 : check two parameters if just negetive period is not stored
   mvTimer a2(negetive,zero);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (a) Default (1.0) not returned", defaultPeriod,\
      a2.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (b) Zero not returned",zero, a2.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A2 (c) Not TIMED MODE (FALSE)", false, a2.isTimed);

   // TEST A3 : check two parameters if negetive period & negetive elapsed
   // time is not stored
   mvTimer a3(negetive,negetive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A3 (a) Default (1.0) not returned", a3.getPeriod(),\
      defaultPeriod);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A3 (b) Default (0.0) not returned",\
      a3.getElapsedTime(),defaultElapsedTime);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A3 (c) Not TIMED MODE (FALSE)", a3.isTimed,false);

   // TEST A4 : check two parameters if just negetive elapsed
   // time is not stored
   mvTimer a4(small,negetive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A4 (a) Small not returned", small, a4.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A4 (b) Default (0.0) not returned",\
      defaultElapsedTime, a4.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A4 (c) Not TIMED MODE (FALSE)",false,a4.isTimed);

   // TEST A5 : period > elapsed Test 1
   mvTimer a5(big,small);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5 (a) Big not returned", big, a5.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5 (b) Small not returned",small,\
      a5.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A5 (c) Not TIMED MODE (FALSE)",false, a5.isTimed);

   // TEST A6 : period > elapsed Test 2
   mvTimer a6(massive,small);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A6 (a) Massive not returned", massive,\
      a6.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A6 (b) Small not returned", small,\
      a6.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A6 (c) Not TIMED MODE (FALSE)",false, a6.isTimed);

   // TEST A7 : check two parameters if elapsed time given is greater thmn
   // period, result should be elapsedTime = big % small
   mvTimer a7(small,big);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A7 (a) Small not returned", small, a7.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A7 (b) big % small not returned",\
      fmodf(big,small), a7.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A7 (c) Not TIMED MODE (FALSE)",false, a7.isTimed);

   // TEST A8 : check two parameters if elapsed time given is greater thmn
   // period, result should be elapsedTime = massive % small
   mvTimer a8(small,massive);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A8 (a) Small not returned", small, a8.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A8 (b) massive % small not returned",\
      std::fmod(massive,small), a8.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A8 (c) Not TIMED MODE (FALSE)", false, a8.isTimed);

   // TEST A9 : check two parameters if elapsed time given is greater thmn
   // period, result should be elapsedTime = massive % big
   mvTimer a9(big,massive);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A9 (a) Small not returned", big, a9.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A9 (b) massive % small not returned",\
      std::fmod(massive,big), a9.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A9 (c) Not TIMED MODE (FALSE)", false, a9.isTimed);

   // TEST A10 : period > elapsed Test 3
   mvTimer a10(massive,big);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A10 (a) Massive not returned", massive,\
      a10.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A10 (b) Big not returned", big,\
      a10.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A10 (c) Not TIMED MODE (FALSE)",false, a10.isTimed);

   // TEST A11 : period > elapsed Test 4
   mvTimer a11(massive,zero);

   CPPUNIT_ASSERT_EQUAL_MESSAGE("A11 (a) Massive not returned", massive,\
      a11.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A11 (b) Zero not returned", zero,\
      a11.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("A11 (c) Not TIMED MODE (FALSE)",false, a11.isTimed);

   // TEST B1 : check one parameter non-negetive numbers are returned
   mvTimer b1(small);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (a) Small not returned", small, b1.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (b) Default (0.0) not returned",\
      defaultElapsedTime, b1.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B1 (c) Not TIMED MODE (FALSE)", false, b1.isTimed);

   // TEST B2 : error check negetive parameter is not returned
   mvTimer b2(negetive);
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (a) Default (1.0) not returned", defaultPeriod,\
      b2.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (b) Default (0.0) not returned",\
      defaultElapsedTime, b2.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("B2 (c) Not TIMED MODE (FALSE)", false, b2.isTimed);

   // TEST C : check no parameter defaults are returned.
   mvTimer c;
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C (a) Default (1.0) not returned",\
     defaultPeriod, c.getPeriod());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C (b) Default (0.0) not returned",\
     defaultElapsedTime,c.getElapsedTime());
   CPPUNIT_ASSERT_EQUAL_MESSAGE("C (c) Not TIMED MODE (FALSE)", false, c.isTimed);
}
