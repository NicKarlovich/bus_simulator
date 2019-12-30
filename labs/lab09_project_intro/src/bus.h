/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <list>

#include "src/passenger.h"

class Bus {
 public:
  /*  Replacing for testing  */
  //  Bus(int capacity, double speed, Route * out, Route * in);
  explicit Bus(int capacity = 60, double speed = 1);
  bool LoadPassenger(Passenger *);  //  returning revenue delta
 private:
  int passenger_max_capacity_;
  double speed_;  // could also be called "distance travelled in one time step"
};
#endif  // SRC_BUS_H_
