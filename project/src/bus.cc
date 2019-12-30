/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */
#include "src/bus.h"

Bus::Bus(std::string name, Route * out, Route * in,
   int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
  num_passengers_ = 0;
  curr_route_ = out;
  is_at_stop_ = false;
  UpdateBusData();
}

bool Bus::IsTripComplete() {
  return (curr_route_ == incoming_route_ && curr_route_->IsAtEnd());
}

bool Bus::Move() {
  distance_remaining_ = distance_remaining_ - speed_;
  return true;
}

void Bus::ReloadPassengers() {
  curr_route_->NextStop();
  if (!(curr_route_->IsAtEnd())) {
    std::list<Passenger *> * lst_passengers =
     GetPreviousStop()->GetPassengers();
    for (std::list<Passenger *>::iterator it = (*lst_passengers).begin();
    it != (*lst_passengers).end();) {
      if (LoadPassenger(*(it))) {  // if there is room on the bus to load.
        it = (*lst_passengers).erase(it);  // remove passenger from stop lst.
      } else {
        it++;  // If LoadPassenger fails, increment iterator.
      }
    }  // once we're done adding passengers set routes next stop.
    // curr_route_->NextStop();
  } else if (curr_route_ != incoming_route_) {
    // If we've hit the end of the route and we want to go back on the
    // incoming route then we force unload all passengers and set the route's
    // current route to the incoming route.
    for (std::list<Passenger *>::iterator it = passengers_.begin();
    it != passengers_.end();) {
      it = passengers_.erase(it);
      num_passengers_--;  // manually keeping track of passengers.
    }
    curr_route_ = incoming_route_;
  } else {
  // TBD If the bus is at the end of the incoming route (ie it has
  // traversed the entireity of the outgoing and incoming route it should
  // do something, not defined yet.
  }
}

void Bus::UnloadPassengers() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end();) {
    int dest = (*it)->GetDestination();
    if (dest == curr_route_->GetDestinationStop()->GetId()) {
      num_passengers_--;  // manually keeping track of the num of passengers.
      it = passengers_.erase(it);  // remove passenger from bus.
    } else {
      (*it)->Update();  // if this isn't the passengers stop, update it.
      it++;
    }
  }
}

// A helper function.
void Bus::ToggleAtStopFlag() {
  is_at_stop_ = !is_at_stop_;
}

bool Bus::GetAtStop() {
  return is_at_stop_;
}

void Bus::Update() {
  if (is_at_stop_) {
    ToggleAtStopFlag();
  }
  Move();
  // if the distance to the next stop is not 0
  // then update the passengers on the bus.
  if (distance_remaining_ > 0) {
    for (std::list<Passenger *>::iterator it = passengers_.begin();
    it != passengers_.end(); it++) {
      (*it)->Update();
    }
  } else {
    UnloadPassengers();
    // If it is not the last stop in the route then we should add passengers
    // at this stop.  Theoretically there should never be passengers at the
    // last stop in the route.  ReloadPassengers handles this logic fo rus.
    ReloadPassengers();
    // Assuming we unloaded/loaded passengers or switched routes (in the case
    // where we hit the end of the route), we need to update the distance
    // to the next stop.
    distance_remaining_ = curr_route_->GetNextStopDistance();
    ToggleAtStopFlag();
  }
  UpdateBusData();
}

bool Bus::GetBusFull() {
  return !(num_passengers_ < passenger_max_capacity_);
}

bool Bus::LoadPassenger(Passenger * new_passenger) {
  if (!GetBusFull()) {  // if the bus is full we do nothing and return false.
    new_passenger->GetOnBus();
    passengers_.push_back(new_passenger);
    num_passengers_++;  // manually keeping track of add/rm passengers.
    return true;
  } else {
    return false;
  }
}

Stop * Bus::GetPreviousStop() {
  int curr_stop_id = curr_route_->GetDestinationStop()->GetId();
  std::list<Stop *> route_stops = curr_route_->GetStops();
  Stop * prev_ptr = (*(curr_route_->GetStops().begin()));
  for (std::list<Stop *>::iterator it = route_stops.begin();
  it != route_stops.end(); it++) {
    if ((*it)->GetId() == curr_stop_id) {
      return prev_ptr;
    } else {
      prev_ptr = (*it);
    }
  }
  /* not sure how to handle not finding previous stop.
     currently it just returns the first stop in the route if
     it fails.
     */
  return (*(curr_route_->GetStops().begin()));
}

Position Bus::DetermineLongLat(Stop * prev, Stop * curr) {
  if (is_at_stop_) {
    return prev->GetPosStruct();
  } else {
    return CalcAverageLongLat(prev, curr);
  }
}

Position Bus::CalcAverageLongLat(Stop * prev, Stop * curr) {
  Position temp = Position();
  Position prev_pos = prev->GetPosStruct();
  Position curr_pos = curr->GetPosStruct();
  temp.x = (prev_pos.x + curr_pos.x) / 2;
  temp.y = (prev_pos.y + curr_pos.y) / 2;
  return temp;
}

void Bus::UpdateBusData() {
  bus_data_.id = name_;
  bus_data_.position = DetermineLongLat(GetPreviousStop(),
   curr_route_->GetDestinationStop());
  bus_data_.num_passengers = num_passengers_;
  bus_data_.capacity = passenger_max_capacity_;
}

BusData Bus::GetBusData() {
  return bus_data_;
}

std::string Bus::GetName() const {
  return name_;
}

Stop * Bus::GetNextStop() {
  return curr_route_->GetDestinationStop();
}

size_t Bus::GetNumPassengers() {
  return num_passengers_;
}

int Bus::GetCapacity() {
  return passenger_max_capacity_;
}

// bool Refuel() {
//  //This may become more complex in the future
//  fuel_ = max_fuel_;
// }

void Bus::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
