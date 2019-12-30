/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>

#include "src/bus.h"
#include "src/passenger.h"

class Stop {
 public:
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Removing passengers from stop and onto a bus
  void LoadPassengers(Bus *);
  // Adding passengers to the stop (from the generator)
  void AddPassengers(Passenger *);
  int GetId() const;
  void Report() const;
 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  // int passengers_present_;  // derived information - not needed?
  double longitude_;
  double latitude_;  // are we using long/lat coords?
};
#endif  // SRC_STOP_H_
