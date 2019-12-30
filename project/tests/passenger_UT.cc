/* STUDENTS: YOU MUST ADD YOUR PASSENGER UNIT TESTS TO THIS FILE. FORMAT YOUR
 * TESTS TO FIT THE SPECIFICATIONS GIVEN BY THE TESTS PROVIDED IN THIS FILE.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/passenger.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class PassengerTests : public ::testing::Test {

	protected:

  	Passenger* passenger;

	virtual void SetUp() {
    	passenger = new Passenger();
  	}

  	virtual void TearDown() {
    	delete passenger;
  	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

 TEST_F(PassengerTests, IsOnBus) {
   	EXPECT_EQ(passenger->IsOnBus(), false);
   	passenger->GetOnBus();
   	EXPECT_EQ(passenger->IsOnBus(), true);
 };

 TEST_F(PassengerTests, MyConstructor) {
     Passenger test1 = Passenger(5,"john cena");
     EXPECT_EQ(test1.GetDestination(), 5);
     EXPECT_EQ(test1.GetTotalWait(), 0);
 }

 TEST_F(PassengerTests, UpdateTest) {
     Passenger hello = Passenger(17, "dog");
     hello.Update();
     EXPECT_EQ(hello.GetTotalWait(), 1);
     hello.GetOnBus();//get on bus does an update
     EXPECT_EQ(hello.GetTotalWait(), 2);
     hello.Update();
     EXPECT_EQ(hello.GetTotalWait(), 3);
 }

 TEST_F(PassengerTests, Report) {
   Passenger testReport = Passenger(3, "reporter");
   std::string expected_output = "Name: reporter\nDestination: 3\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\n";
   testing::internal::CaptureStdout();
   testReport.Report(std::cout);
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, expected_output);
 }
