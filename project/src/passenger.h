
/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>

/**
 * @brief The main class for passengers.
 */
class Passenger {
 public:
   /**
    * @brief Constructor for a Passenger Object.
    *
    * @param[in] destination_stop_id The id of the stop the passenger is going
    * to, defaultly set to -1
    * @param[in] name The name of the passenger.
    *
    * @return Passenger Object
    */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
   * @brief Updates passenger, this will update the passengers time waiting.
   *
   * @return void
   */
  void Update();
  /**
   * @brief Tells the passenger to get on the bus, there is no get off bus
   * because once the passenger gets off the bus we don't care about them.
   *
   * @return void
   */
  void GetOnBus();
  /**
   * @brief Pasenger wait time.
   * @description Tells us how long the passenger has been waiting until they've
   * reached their destination, computed by wait_time + on_bus_time.
   *
   * @return integer representing the sum of time spent waiting.
   */
  int GetTotalWait() const;
  /**
   * @brief Tells us whether or not a passenger is currently riding a bus.
   *
   * @return boolean representing if a passenger is on the bus.
   */
  bool IsOnBus() const;
  /**
   * @brief The id of the destination stop.
   *
   * @return integer representing id of the passenger's destination stop.
   */
  int GetDestination() const;
  /**
   * @brief Writes out a report of the passenger object to the specific output.
   *
   * @param[in] out The output we'd like our report functions to output to.
   *
   * @return void
   */
  void Report(std::ostream &) const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  bool on_bus_;
  int id_;
  static int count_;   // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
