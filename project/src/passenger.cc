/**
 * @file passenger.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */

#include "src/passenger.h"

#include <iostream>
#include <string>


int Passenger::count_ = 0;

Passenger::Passenger(int destination_stop_id, std::string name): name_(name),
        destination_stop_id_(destination_stop_id), wait_at_stop_(0),
        time_on_bus_(0), on_bus_(false), id_(count_) {
  count_++;
}

void Passenger::Update() {
  if (on_bus_) {
    time_on_bus_++;
  } else {
    wait_at_stop_++;
  }
}

// Bus relies on GetOnBus calling to ensure that Update is called on the
// passenger when its appropriate.
// Ex: The "Frame" when the passenger gets on bus should be attribted to the
// bus's wait time so we let GetOnBus make sure the passenger knows it's on
// the bus before we call Update().
void Passenger::GetOnBus() {
  on_bus_ = true;
  Update();
}

// Get total wait as defined in the iteration 1 document.
int Passenger::GetTotalWait() const {
  return wait_at_stop_ + time_on_bus_;
}

bool Passenger::IsOnBus() const {
  return (on_bus_);
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

void Passenger::Report(std::ostream &out) const {
  out << "Name: " << name_ << std::endl;
  out << "Destination: " << destination_stop_id_ << std::endl;
  out << "Total Wait: " << GetTotalWait() << std::endl;
  out << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  out << "\tTime on bus: " << time_on_bus_ << std::endl;
}
