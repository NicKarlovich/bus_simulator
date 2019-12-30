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
#include "../src/route.h"
#include "../src/passenger_generator.h"
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include "../src/random_passenger_generator.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class BusTests : public ::testing::Test {

	protected:

		Route* route;
		Route* route2;
  	Stop* stop;
		Stop* stop2;
		Stop* stop3;
		Stop* stop4;
		Passenger* passenger1;
		Passenger* passenger2;
		Passenger* passenger3;
		Passenger* passenger4;
		Passenger* passenger5;
		Stop ** stopList;
		Stop ** stopList2;
		double * distances;
		std::list<double> probs;
		std::list<Stop *> stops;
		RandomPassengerGenerator * pg;

		Bus * bus;

	virtual void SetUp() {

			stopList = new Stop *[3];
			stopList2 = new Stop *[3];

			distances = new double[2];
			distances[0] = 5;
			distances[1] = 3;

			probs.push_back(0);
			probs.push_back(0);

    	stop = new Stop(1, 10, 100);
			stop2 = new Stop(2, 20, 200);
			stop3 = new Stop(3, 30, 300);
			stop4 = new Stop(4);

			stops.push_back(stop);
			stops.push_back(stop2);
			stops.push_back(stop3);
			pg = new RandomPassengerGenerator(probs,stops);//dont care about generation, just null to fill constructor

			stopList[0] = stop;
			stopList[1] = stop2;
			stopList[2] = stop3;

			stopList2[0] = stop;
			stopList2[1] = stop2;
			stopList2[2] = stop4;

			passenger1 = new Passenger(2, "Two");
			passenger2 = new Passenger(3, "dave");
			passenger3 = new Passenger(3, "done");
			passenger4 = new Passenger(4, "oob");
			passenger5 = new Passenger(1, "first");

			route = new Route("my Route", stopList, distances, 3, pg);
			route2 = route->Clone();
			stop->AddPassengers(passenger1);
			stop2->AddPassengers(passenger2);
			stop->AddPassengers(passenger3);

			route = new Route("my Route", stopList, distances, 3, pg);
			route2 = route->Clone();
			bus = new Bus("speed", route, route2, 60, 1);

  	}

  	virtual void TearDown() {
			delete distances;
			//delete distances[1];
			delete route;
			delete route2;
			delete pg;

			delete stopList;
			delete stopList2;
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

TEST_F(BusTests, Report) {
	std::string expected_output = "Name: speed\nSpeed: 1\nDistance to next stop: 0\n\tPassengers (0): \n";
	testing::internal::CaptureStdout();
	bus->Report(std::cout);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, expected_output);
}

TEST_F(BusTests, GetBusFull) {
	delete bus;
	bus = new Bus("speed", route, route2, 1, 1);
	EXPECT_EQ(bus->GetBusFull(), false);
	bus->LoadPassenger(passenger1);
	EXPECT_EQ(bus->GetBusFull(), true);
}

TEST_F(BusTests, LoadPassenger) {
	bus->LoadPassenger(passenger1);
	std::string expected_output = "Name: speed\nSpeed: 1\nDistance to next stop: 0\n\tPassengers (1): \nName: Two\nDestination: 2\nTotal Wait: 1\n\tWait at Stop: 0\n\tTime on bus: 1\n";
	testing::internal::CaptureStdout();
	bus->Report(std::cout);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, expected_output);
}

TEST_F(BusTests, LoadPassengerFull) {
	delete bus;
	bus = new Bus("speed", route, route2, 1, 1);
	EXPECT_EQ(bus->LoadPassenger(passenger1), true);
	EXPECT_EQ(bus->LoadPassenger(passenger2), false);
}

//Checks that Update picks up passengers and removes them from 1 stop
TEST_F(BusTests, Update) {
	bus->Update();
	route->Update();
	std::string expected_r_output = "Name: my Route\nNum stops: 3\nID: 1\nPassengers waiting: 0\nID: 2\nPassengers waiting: 1\nName: dave\nDestination: 3\nTotal Wait: 1\n\tWait at Stop: 1\n\tTime on bus: 0\nID: 3\nPassengers waiting: 0\n";
	testing::internal::CaptureStdout();
	route->Report(std::cout);
	std::string r_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(r_output, expected_r_output);

	std::string expected_b_output = "Name: speed\nSpeed: 1\nDistance to next stop: 5\n\tPassengers (2): \nName: Two\nDestination: 2\nTotal Wait: 1\n\tWait at Stop: 0\n\tTime on bus: 1\nName: done\nDestination: 3\nTotal Wait: 1\n\tWait at Stop: 0\n\tTime on bus: 1\n";
	testing::internal::CaptureStdout();
	bus->Report(std::cout);
	std::string b_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(b_output, expected_b_output);
}

TEST_F(BusTests, TravelTime) {
	bus->Update();
	route->Update();
	bus->Update();
	route->Update();

	std::string expected_r_output = "Name: my Route\nNum stops: 3\nID: 1\nPassengers waiting: 0\nID: 2\nPassengers waiting: 1\nName: dave\nDestination: 3\nTotal Wait: 2\n\tWait at Stop: 2\n\tTime on bus: 0\nID: 3\nPassengers waiting: 0\n";
	testing::internal::CaptureStdout();
	route->Report(std::cout);
	std::string r_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(r_output, expected_r_output);

	std::string expected_b_output = "Name: speed\nSpeed: 1\nDistance to next stop: 4\n\tPassengers (2): \nName: Two\nDestination: 2\nTotal Wait: 2\n\tWait at Stop: 0\n\tTime on bus: 2\nName: done\nDestination: 3\nTotal Wait: 2\n\tWait at Stop: 0\n\tTime on bus: 2\n";
	testing::internal::CaptureStdout();
	bus->Report(std::cout);
	std::string b_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(b_output, expected_b_output);
	bus->Update();
	route->Update();
	bus->Update();
	route->Update();
	bus->Update();
	route->Update();
	bus->Update();
	route->Update();
	std::string expected_r2_output = "Name: my Route\nNum stops: 3\nID: 1\nPassengers waiting: 0\nID: 2\nPassengers waiting: 0\nID: 3\nPassengers waiting: 0\n";
	testing::internal::CaptureStdout();
	route->Report(std::cout);
	std::string r2_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(r2_output, expected_r2_output);

	std::string expected_b2_output = "Name: speed\nSpeed: 1\nDistance to next stop: 3\n\tPassengers (2): \nName: done\nDestination: 3\nTotal Wait: 6\n\tWait at Stop: 0\n\tTime on bus: 6\nName: dave\nDestination: 3\nTotal Wait: 6\n\tWait at Stop: 5\n\tTime on bus: 1\n";
	testing::internal::CaptureStdout();
	bus->Report(std::cout);
	std::string b2_output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(b2_output, expected_b2_output);
}


TEST_F(BusTests, GetName) {
	EXPECT_EQ(bus->GetName(), "speed");
	EXPECT_NE(bus->GetName(), "");
	EXPECT_NE(bus->GetName(), "spood");
}

TEST_F(BusTests, GetNextStop) {
	EXPECT_EQ(bus->GetNextStop(), *(route->GetStops().begin()));
	bus->Update();
	EXPECT_EQ(bus->GetNextStop(), (*(std::next((route->GetStops().begin()),1))));
}

TEST_F(BusTests, GetNumPassengers) {
	EXPECT_EQ(bus->GetNumPassengers(), 0);
	bus->LoadPassenger(passenger1);
	EXPECT_EQ(bus->GetNumPassengers(), 1);
}

TEST_F(BusTests, GetCapacity) {
	EXPECT_EQ(bus->GetCapacity(), 60);
	delete bus;
	bus = new Bus("speed", route, route2, 3, 1);
	EXPECT_EQ(bus->GetCapacity(), 3);
}

TEST_F(BusTests, GetPreviousStop) {
	bus->Update();
	bus->Update();
	EXPECT_EQ(bus->GetPreviousStop(), stop);
	bus->Update();
	bus->Update();
	bus->Update();
	EXPECT_EQ(bus->GetPreviousStop(), stop);
	bus->Update();
	EXPECT_EQ(bus->GetPreviousStop(), stop2);
	bus->Update();
	EXPECT_EQ(bus->GetPreviousStop(), stop2);
}

TEST_F(BusTests, GetPreviousStopError) {
	/* When the bus doens't have a previous stop(it's at the beginning of a route)
	 it should just return the first stop in the list. */
	EXPECT_EQ(bus->GetPreviousStop(), stop);
}

TEST_F(BusTests, CalcAverageLongLat) {
	bus->Update();
	Position output = bus->CalcAverageLongLat(stop, stop2);
	EXPECT_EQ(output.x, 15);
	EXPECT_EQ(output.y, 150);
}

TEST_F(BusTests, DetermineLongLat) {
	bus->Update();
	Position output = bus->DetermineLongLat(bus->GetPreviousStop(), bus->GetNextStop());
	EXPECT_EQ(output.x, 10);
	EXPECT_EQ(output.y, 100);
	bus->Update();
	output = bus->DetermineLongLat(bus->GetPreviousStop(), bus->GetNextStop());
	EXPECT_EQ(output.x, 15);
	EXPECT_EQ(output.y, 150);
	bus->Update();
	bus->Update();
	bus->Update();
	output = bus->DetermineLongLat(bus->GetPreviousStop(), bus->GetNextStop());
	EXPECT_EQ(output.x, 15);
	EXPECT_EQ(output.y, 150);
	bus->Update();
	output = bus->DetermineLongLat(bus->GetPreviousStop(), bus->GetNextStop());
	EXPECT_EQ(output.x, 20);
	EXPECT_EQ(output.y, 200);
	bus->Update();
	output = bus->DetermineLongLat(bus->GetPreviousStop(), bus->GetNextStop());
	EXPECT_EQ(output.x, 25);
	EXPECT_EQ(output.y, 250);
}

TEST_F(BusTests, GetBusData) {
	BusData temp = bus->GetBusData();
	EXPECT_EQ(temp.id, bus->GetName());
	EXPECT_EQ(temp.num_passengers, bus->GetNumPassengers());
	EXPECT_EQ(temp.capacity, bus->GetCapacity());
	EXPECT_EQ(temp.position.x, 10);
	EXPECT_EQ(temp.position.y, 100);
	temp = bus->GetBusData();
}

TEST_F(BusTests, GetAtStop) {
	EXPECT_EQ(bus->GetAtStop(), false);
	bus->Update();
	EXPECT_EQ(bus->GetAtStop(), true);
}

TEST_F(BusTests, ToggleAtStopFlag) {
	EXPECT_NE(bus->GetAtStop(), true);
	bus->ToggleAtStopFlag();
	EXPECT_EQ(bus->GetAtStop(), true);
	bus->ToggleAtStopFlag();
	EXPECT_NE(bus->GetAtStop(), true);
}

TEST_F(BusTests, UpdateBusData) {
	BusData temp = bus->GetBusData();
	EXPECT_EQ(temp.position.x, 10);
	EXPECT_EQ(temp.position.y, 100);
	bus->Update();
	EXPECT_EQ(temp.position.x, 10);
	EXPECT_EQ(temp.position.y, 100);
	bus->UpdateBusData();
	temp = bus->GetBusData();
	EXPECT_EQ(temp.position.x, 10);
	EXPECT_EQ(temp.position.y, 100);
	bus->Update();
	temp = bus->GetBusData();
	EXPECT_EQ(temp.position.x, 15);
	EXPECT_EQ(temp.position.y, 150);
	EXPECT_EQ(temp.num_passengers, 2);
	bus->Update();
	bus->Update();
	bus->Update();
	bus->Update();
	bus->UpdateBusData();
	temp = bus->GetBusData();
	EXPECT_EQ(temp.position.x, 20);
	EXPECT_EQ(temp.position.y, 200);
	bus->Update();
	bus->UpdateBusData();
	temp = bus->GetBusData();
	EXPECT_EQ(temp.position.x, 25);
	EXPECT_EQ(temp.position.y, 250);
	EXPECT_EQ(temp.num_passengers, 2);
}

TEST_F(BusTests, ReloadPassengers) {
	bus->Update();
	EXPECT_EQ(bus->GetNumPassengers(), 2);
	stop->AddPassengers(passenger2);
	bus->ReloadPassengers();
	EXPECT_EQ(bus->GetNumPassengers(), 3);
}

TEST_F(BusTests, UnloadPassengers) {
	/* UnloadPassengers has some weird effects
	 * but basically, when we call Update() at first it tells the
	 * route that the next place to unload is stop2 (2nd stop).  So
	 * We can add a passenger who's destination is behind us and add a
	 * passenger who's destination is at stop 3 and show that when we
	 * call unload passengers it only unloads passengers that are supposed
	 * to get off at that stop.  As it was never given, the UnloadPassengers
	 * doens't check to make sure it's at at stop as I don't know what the
	 * output should be if it is.
	 */
	bus->Update();
	bus->LoadPassenger(passenger5);
	EXPECT_EQ(bus->GetNumPassengers(), 3); // passengers going to stop 1, 2 and 3.
	bus->UnloadPassengers();
	EXPECT_NE(bus->GetNumPassengers(), 3); // some passengers were unloaded.
	// passengers with destinations at 1 and 3 are left, but 2 is removed.
	EXPECT_EQ(bus->GetNumPassengers(), 2);
}

TEST_F(BusTests, EndOfTheLineKickoff) {
	stop2->AddPassengers(passenger4);
	bus->Update();
	// 5 from stop 2
	bus->Update();
	bus->Update();
	bus->Update();
	bus->Update();
	bus->Update();
	// 3 from stop 3
	bus->Update();
	bus->Update();
	EXPECT_EQ(bus->GetNumPassengers(), 3);
	bus->Update();
	EXPECT_EQ(bus->GetNumPassengers(), 0);
}





















//
