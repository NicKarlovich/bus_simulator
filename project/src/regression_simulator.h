/**
 * @file regression_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_REGRESSION_SIMULATOR_H_
#define SRC_REGRESSION_SIMULATOR_H_

#include <vector>
#include <string>
#include "src/simulator.h"

class RegressionSimulator : public Simulator {
 public:
  bool Start() override;
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_REGRESSION_SIMULATOR_H_