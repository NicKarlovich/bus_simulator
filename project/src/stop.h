/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"
#include "src/data_structs.h"

class Bus;

/**
 * @brief The main class for stops.
 */
class Stop {
 public:
  /**
   * @brief Constructor for a Stop Object.
   *
   * @param[in] id The identifier of the stop.
   * @param[in] longitude The GPS longitude coordinate, not currently used.
   * @param[in] latitude The GPS latitude coordinate, not currently used.
   *
   * @return Stop Object
   */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  /**
   * @brief Gets the identifier of the stop.
   *
   * @return An integer representing the id of the stop.
   */
  int GetId() const;
  /**
   * @brief Adds a Passenger to the stop.
   *
   * @param[in] pass The passenger we're going to add to the stop.
   *
   * @return An integer, value not defined yet.
   */
  int AddPassengers(Passenger *);
  /**
   * @brief Updates the Stop.
   *
   * @description Calls Update() on all the passenger's at the stop effectively
   * increasing all the passengers time_at_stop by 1.
   *
   * @return void
   */
  void Update();
  /**
   * @brief Writes out a report of the Stop object to the specific output.
   *
   * @param[in] out The output we'd like our report functions to output to.
   *
   * @return void
   */
  void Report(std::ostream &) const;
  /**
   * @brief Gets the list of passengers currently at the stop.
   *
   * @return A pointer to a list of Passenger pointers which is the list of
   * passengers that are currently at the stop.
   */
  std::list<Passenger *> * GetPassengers();
  /**
   * @brief A Getter to return the stop's Position struct.
   *
   * @return A position struct with the stop's latitude-longitude coordiantes.
   */
  Position GetPosStruct();

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
