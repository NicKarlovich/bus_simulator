/**
 * @file stop.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */

#include "src/stop.h"

Stop::Stop(int id, double longitude, double latitude) : id_(id),
 longitude_(longitude), latitude_(latitude) {
  // Defaults to Westbound Coffman Union stop
  // no initialization of list of passengers necessary
}

int Stop::AddPassengers(Passenger * pass) {
  passengers_.push_back(pass);
  return 0;
}

void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

std::list<Passenger *> * Stop::GetPassengers() {
  return &passengers_;
}

int Stop::GetId() const {
  return id_;
}

Position Stop::GetPosStruct() {
  Position temp = Position();
  temp.x = longitude_;
  temp.y = latitude_;
  return temp;
}

void Stop::Report(std::ostream &out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " << passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
