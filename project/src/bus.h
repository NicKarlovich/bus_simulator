/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/data_structs.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/**
 * @brief The main class for buses.
 */
class Bus {
 public:
 /**
  * @brief Constructor for a Bus Object.
  *
  * @param[in] name Name of bus, can by any string.
  * @param[in] out outgoing route of bus, the route the bus.
  * is originally going on when its initialized.
  * @param[in] in Incoming route of bus, the route the bus.
  * is put on after completing the outgoing route.
  * @param[in] capacity The max capacity of the bus.
  * @param[in] speed The number of "distance units" the bus.
  * moves after one Update() call.
  *
  * @return Bus Object
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  /**
   * @brief Puts a passenger onto the bus.
   *
   * @param[in] new_passenger The passenger we're going to load onto the bus.
   *
   * @return A boolean reporting whether or not the loading was successful.
   */
  bool LoadPassenger(Passenger *);
  /**
   * @brief Determines if a bus is full.
   *
   * @return Returns a boolean reporting if the bus is at max capacity.
   */
  bool GetBusFull();
  /**
   * @brief Moves the bus forward at it's speed towards the next stop.
   *
   * @return Returns a boolean reporting if the move was successful.
   */
  bool Move();
  /**
   * @brief Updates the bus's location, loads and unloads passengers
   *
   * @description Updates the bus' distance to the next stop, unloads
   * passengers at correct stop, picks up passengers from stops, if the
   * bus reaches the end of the route it will unload all passengers.
   *
   * @return void
   */
  void Update();
  /**
   * @brief Writes out a report of the bus object to the specific output.
   *
   * @param[in] out The output we'd like our report functions to output to.
   *
   * @return void
   */
  void Report(std::ostream &);
  /**
   * @brief Performs the unloading of passengers when a bus reaches a stop.
   *
   * @return void
   */
  void UnloadPassengers();
  /**
   * @brief Performs the reloading of passengers when a bus reaches a stop.
   * It will also force unload all passengers if the bus has reached
   * the end of the route, after force unloading if it still has it's
   * incoming_route_ to travel it will begin traveling on that route.
   * Otherwise it will do nothing.
   *
   * @return void
   */
  void ReloadPassengers();
  /**
   * @brief Reports back if the bus has traversed both routes.
   *
   * @return Returns if the bus is at the end of either of its routes.
   */
  bool IsTripComplete();
  /**
   * @brief A Getter to return the bus' BusData struct for vis_sim.
   *
   * @return The buses BusData struct, bus_data_.
   */
  BusData GetBusData();
  /**
   * @brief Updates the Bus' Data which includes position and num of passengers.
   */
  void UpdateBusData();
  /**
   * @brief A Getter to return the bus' name.
   *
   * @return The buses private name variable, name_.
   */
  std::string GetName() const;
  /**
   * @brief A Getter to return a pointer to the bus' next stop.
   *
   * @return The a pointer to the next stop the bus is going to.
   */
  Stop * GetNextStop();
  /**
   * @brief A Getter to return a pointer to the bus' previous stop.
   *
   * @return The a pointer to the stop the bus just visited.
   */
  Stop * GetPreviousStop();
  /**
   * @brief A Getter to return the bus' number of passengers.
   *
   * @return The buses number of passengers.
   */
  size_t GetNumPassengers();
  /**
   * @brief A Getter to return the bus' capacity.
   *
   * @return The buses max capacity.
   */
  int GetCapacity();
  /**
   * @brief Calculates the average longitude and latitude of between two stops.
   * @param[in] prev A pointer to the stop the bus just visited.
   * @param[in] curr A pointer to the stop the bus is gong to.
   *
   * @return A position struct with the average of the two input stop's coords.
   */
  Position CalcAverageLongLat(Stop * prev, Stop * curr);
  /**
   * @brief Calculates where the bus should be shown on the map.
   *
   * @desc If the bus is currently at a stop, it will return the position
   * of the stop that the bus is at.  If the bus has left the stop and is
   * in transit to the next stop, then the bus will be visualized at the
   * average coordinates of the previous and next stop.
   *
   * @param[in] prev A pointer to the stop the bus just visited.
   * @param[in] curr A pointer to the stop the bus is gong to.
   *
   * @return A position struct with the buses current 'visual' position.
   */
  Position DetermineLongLat(Stop * prev, Stop * curr);
  /**
   * @brief Toggles a private variable to determine if bus is at stop or not.
   */
  void ToggleAtStopFlag();
  /*
   * @brief A getter to return if a bus is at a stop
   *
   * @return the private variable is_at_stop_
   */
  bool GetAtStop();

 private:
  int num_passengers_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  Route * curr_route_;
  BusData bus_data_;
  bool is_at_stop_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                               // AND next stop set
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
};
#endif  // SRC_BUS_H_
