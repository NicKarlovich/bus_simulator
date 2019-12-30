/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

#include <list>
#include <iostream>
#include <string>

#include "./passenger_generator.h"
#include "./stop.h"
#include "src/data_structs.h"

class PassengerGenerator;
class Stop;

/**
 * @brief The main class for routes.
 */
class Route {
 public:
   /**
    * @brief Constructor for a Route Object.
    *
    * @param[in] name Name of route, can by any string.
    * @param[in] stops A list of stops that makes up the route. size: num_stops
    * @param[in] distances A list of doubles representing the distance between
    * all of the stops.  Distance to first stop is always 0.  Length will be
    * equal to: num_stops - 1
    * @param[in] num_stops The number of stops that exists on the route.
    * @param[in] pg The Passenger Generator that will be used when running
    * the simulation to simulate passengers arriving at the stops along the
    * routes.
    *
    * @return Route Object.
    */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
  /**
   * @brief Clones a stop, but keeps references to stops and distances arrays.
   *
   * @description Doesn't do a deep copy ie, a Route cretaed by the clone
   * clone function will point to the same stops as the Route it was created
   * from.  It will not copy the routes private variables over to the clone.
   *
   * @return A Route object that is an duplicate of it's creator.
   */
  Route * Clone();
  /**
   * @brief Updates the Route's stops and generates passengers.
   *
   * @description Calls Update() on it's passengers then after the passengers
   * have been updated more passengers are generated and place on the route.
   *
   * @return void
   */
  void Update();
  /**
   * @brief Writes out a report of the Route object to the specific output.
   *
   * @param[in] out The output we'd like our report functions to output to.
   *
   * @return void
   */
  void Report(std::ostream&);
  /**
   * @brief Tells us if the bus following this route is at the end.
   *
   * @return A boolean telling us if the route has any more stops to traverse.
   */
  bool IsAtEnd() const;
  /**
   * @brief Updates destination_stop_ of the route so the bus following this
   * route knows where to go.
   *
   * @return void
   */
  void NextStop();
  /**
   * @brief Gets the next stop.
   *
   * @return A stop pointer pointing at the stop the route is currently on
   * destination to.
   */
  Stop * GetDestinationStop() const;
  /**
   * @brief Gets the total distance of the route ignoring the current position.
   *
   * @return A sum of all the values in the distances_between_ array.
   */
  double GetTotalRouteDistance() const;
  /**
   * @brief The distance (as a decimal) to the current destination stop.
   *
   * @return A double representing the distance to the next stop.  Doesn't take
   * into consideration where the bus is along it's path to the next stop, only
   * looks at the distance from the most recently visited stop to the nxt stop.
   */
  double GetNextStopDistance() const;
  /**
   * @brief A Getter to Return the name of the route.
   *
   * @return The private name_ variable of the route.
   */
  std::string GetName();
  /**
   * @brief A Getter to return the list of stops.
   *
   * @return The private stops_ list of the stops on the route.
   */
  std::list<Stop *> GetStops();
  /**
   * @brief A Getter to return the RouteData struct used by the vis_sim
   *
   * @return The route's RouteData struct.
   */
  RouteData GetRouteData();
  /**
   * @brief Updates the route's RouteData struct, which updates StopData of all
   * the stops along the route.
   */
  void UpdateRouteData();
  /**
   * @brief A Getter to return the generator used by the route.
   *
   * @return The route's private generator_ variable.
   */
  PassengerGenerator * GetGenerator();

 private:
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  RouteData route_data_;
  // double trip_time_; // derived data - total distance travelled on route
};
#endif  // SRC_ROUTE_H_
