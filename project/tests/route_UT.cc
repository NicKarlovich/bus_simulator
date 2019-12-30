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

class RouteTests : public ::testing::Test {

	protected:

		Route* route;
		Route* route2;
  	Stop* stop;
		Stop* stop2;
		Stop* stop3;
		Passenger* passenger1;
		Passenger* passenger2;
		Passenger* passenger3;
		Stop ** stopList;
		double * distances;
		std::list<double> probs;
		std::list<Stop *> stops;
		RandomPassengerGenerator * pg;

	virtual void SetUp() {

			stopList = new Stop *[3];

			distances = new double[2];
			distances[0] = 5;
			distances[1] = 3;

			probs.push_back(0.99999);
			probs.push_back(0);

    	stop = new Stop(1);
			stop2 = new Stop(2);
			stop3 = new Stop(3);

			stops.push_back(stop);
			stops.push_back(stop2);
			stops.push_back(stop3);
			pg = new RandomPassengerGenerator(probs,stops);//dont care about generation, just null to fill constructor

			stopList[0] = stop;
			stopList[1] = stop2;
			stopList[2] = stop3;

			passenger1 = new Passenger(2, "Two");
			passenger2 = new Passenger(3, "dave");
			passenger3 = new Passenger(2, "done");

			stop->AddPassengers(passenger1);
			stop2->AddPassengers(passenger2);
			stop->AddPassengers(passenger3);

			route = new Route("my Route", stopList, distances, 3, pg);
			route2 = route->Clone();

  	}

  	virtual void TearDown() {
			delete distances;
			delete route;
			delete route2;
			delete pg;
			delete stopList;
    	delete stop;
			delete stop2;
			delete stop3;
			delete passenger1;
			delete passenger2;
			delete passenger3;
  	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RouteTests, GetTotalRouteDistance) {
	EXPECT_EQ(route->GetTotalRouteDistance(), 8);
}

TEST_F(RouteTests, GetDestinationStop) {
	EXPECT_EQ(route->GetDestinationStop()->GetId(),stop->GetId());
	route->NextStop();
	EXPECT_EQ(route->GetDestinationStop()->GetId(),stop2->GetId());
	route->NextStop();
	EXPECT_EQ(route->GetDestinationStop()->GetId(),stop3->GetId());
}

TEST_F(RouteTests, GetNextStopDistance) {
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 5);
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 3);
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 0);
	// Testing that going over the end of the route doesn't error, just keeps
	// distance to next route to be 0, ie it's safe.
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 0);
	route->NextStop();
	route->NextStop();
	route->NextStop();
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 0);
}

TEST_F(RouteTests, IsAtEnd) {
	EXPECT_EQ(route->IsAtEnd(), false);
	route->NextStop();
	EXPECT_EQ(route->IsAtEnd(), false);
	route->NextStop();
	EXPECT_EQ(route->IsAtEnd(), false);
	route->NextStop();
	EXPECT_EQ(route->IsAtEnd(), true);
}

TEST_F(RouteTests, Clone) {
	route2 = route->Clone();

	EXPECT_EQ(route2->GetTotalRouteDistance(), route->GetTotalRouteDistance());
	EXPECT_EQ(route2->IsAtEnd(), route->IsAtEnd());
	route->NextStop();
	EXPECT_EQ(route->GetNextStopDistance(), 5);
	EXPECT_EQ(route->GetDestinationStop()->GetId(),stop2->GetId());
	EXPECT_EQ(route2->GetNextStopDistance(), 0);
	route2->NextStop();
	route->NextStop();
	EXPECT_EQ(route2->GetNextStopDistance(), 5);
	EXPECT_EQ(route->GetDestinationStop()->GetId(),stop3->GetId());
  EXPECT_EQ(route2->GetDestinationStop()->GetId(),stop2->GetId());
	route->NextStop();
	EXPECT_EQ(route->IsAtEnd(), true);
	EXPECT_EQ(route2->IsAtEnd(), false);
	route2->NextStop();
	route2->NextStop();
	EXPECT_EQ(route2->IsAtEnd(), true);
}

TEST_F(RouteTests, GetName) {
	EXPECT_EQ(route->GetName(), "my Route");
	EXPECT_EQ(route2->GetName(), "my Route");
}

TEST_F(RouteTests, GetStops) {
	EXPECT_EQ(route->GetStops(), stops);
}

TEST_F(RouteTests, GetRouteData) {
	RouteData temp = route->GetRouteData();
	EXPECT_EQ(temp.id, "my Route");
	int i = 0;
	std::list<Stop *> stop_lst = route->GetStops();
	for(std::list<Stop *>::iterator it = stop_lst.begin();
	it != stop_lst.end(); i++, it++) {
		EXPECT_EQ((*it)->GetId(), std::stoi(temp.stops[i].id));
		Position tempPos = (*it)->GetPosStruct();
		EXPECT_EQ(tempPos.x, temp.stops[i].position.x);
		EXPECT_EQ(tempPos.y, temp.stops[i].position.y);
		EXPECT_EQ((*it)->GetPassengers()->size(), temp.stops[i].num_people);
	}
}

TEST_F(RouteTests, UpdateRouteData) {
	RouteData temp = route->GetRouteData();
	int i = 0;
	for(std::list<Stop *>::iterator it = stops.begin();
	it != stops.end(); i++, it++) {
		EXPECT_EQ((*it)->GetId(), std::stoi(temp.stops[i].id));
		Position tempPos = (*it)->GetPosStruct();
		EXPECT_EQ(tempPos.x, temp.stops[i].position.x);
		EXPECT_EQ(tempPos.y, temp.stops[i].position.y);
		EXPECT_EQ((*it)->GetPassengers()->size(), temp.stops[i].num_people);
	}
	(*(route->GetStops().begin()))->AddPassengers(passenger1);
	EXPECT_EQ(2, temp.stops[0].num_people);
	route->UpdateRouteData();
	temp = route->GetRouteData();
	EXPECT_EQ(3, temp.stops[0].num_people);
	EXPECT_EQ((*(route->GetStops().begin()))->GetPassengers()->size(), temp.stops[0].num_people);
}




















//
