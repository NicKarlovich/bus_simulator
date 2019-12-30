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
#include "../src/stop.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class StopTests : public ::testing::Test {

	protected:

  	Stop* stop;
		Stop* stop2;
		Stop* stop3;
		Stop* stop4;
		Passenger* passenger1;
		Passenger* passenger2;
		Passenger* passenger3;

	virtual void SetUp() {
    	stop = new Stop(1);
			stop2 = new Stop(2);
			stop3 = new Stop(3);
			stop4 = new Stop(4, 55, 25);
			passenger1 = new Passenger(2, "Two");
			passenger2 = new Passenger(3, "dave");
			passenger3 = new Passenger(2, "done");

			stop->AddPassengers(passenger1);
			stop2->AddPassengers(passenger2);
			stop->AddPassengers(passenger3);

  	}

  	virtual void TearDown() {
    	delete stop;
			delete stop2;
			delete stop3;
			delete stop4;
			delete passenger1;
			delete passenger2;
			delete passenger3;
  	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(StopTests, GetId) {
	EXPECT_EQ(stop->GetId(), 1);
	EXPECT_EQ(stop2->GetId(), 2);
	EXPECT_EQ(stop3->GetId(), 3);
}

TEST_F(StopTests, AddPassengers) {
	testing::internal::CaptureStdout();
	std::string ex_stop_output = "ID: 1\nPassengers waiting: 2\nName: Two\nDestination: 2\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\nName: done\nDestination: 2\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\n";
	std::string ex_stop2_output = "ID: 2\nPassengers waiting: 1\nName: dave\nDestination: 3\nTotal Wait: 0\n\tWait at Stop: 0\n\tTime on bus: 0\n";
	stop->Report(std::cout);
	std::string stop_output = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	stop2->Report(std::cout);
	std::string stop2_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(ex_stop_output, stop_output);
	EXPECT_EQ(ex_stop2_output, stop2_output);
}

TEST_F(StopTests, Update) {
	testing::internal::CaptureStdout();
	stop->Update();
	stop2->Update();
	std::string ex_stop_output = "ID: 1\nPassengers waiting: 2\nName: Two\nDestination: 2\nTotal Wait: 1\n\tWait at Stop: 1\n\tTime on bus: 0\nName: done\nDestination: 2\nTotal Wait: 1\n\tWait at Stop: 1\n\tTime on bus: 0\n";
	std::string ex_stop2_output = "ID: 2\nPassengers waiting: 1\nName: dave\nDestination: 3\nTotal Wait: 1\n\tWait at Stop: 1\n\tTime on bus: 0\n";
	stop->Report(std::cout);
	std::string u_stop_output = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	stop2->Report(std::cout);
	std::string u_stop2_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(ex_stop_output, u_stop_output);
	EXPECT_EQ(ex_stop2_output, u_stop2_output);
}

TEST_F(StopTests, PosStruct) {
	Position temp = stop4->GetPosStruct();
	EXPECT_EQ(temp.x, 55);
	EXPECT_EQ(temp.y, 25);
}





















//
