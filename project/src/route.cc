/**
 * @file route.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */
#include "src/route.h"
#include "src/stop.h"

Route::Route(std::string name, Stop ** stops, double * distances,
   int num_stops, PassengerGenerator * pg) {
  // Converting from arrays to lists
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }
  // Private member varible assignment
  name_ = name;
  num_stops_ = num_stops;
  destination_stop_index_ = 0;  // redundant but put here for clarity.
  destination_stop_ = *(stops_.begin());  // the stop the route needs to go to.
  generator_ = pg;
  UpdateRouteData();
}

// To match the example output given we generate passengers then update
void Route::Update() {
  GenerateNewPassengers();
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Update();
  }
  UpdateRouteData();
}

int Route::GenerateNewPassengers() {
  return generator_->GeneratePassengers();
}

void Route::NextStop() {
  destination_stop_index_++;
  int i = 0;
  for (std::list<Stop *>::iterator it = stops_.begin();
  (it != stops_.end()) && (i <= destination_stop_index_); it++) {
    if (i == destination_stop_index_) {
      destination_stop_ = *it;
    }
      i++;
  }
}

double Route::GetNextStopDistance() const {
  int i = 0;
  for (std::list<double>::const_iterator it = distances_between_.begin();
  (it != distances_between_.end()) && (i < destination_stop_index_); it++) {
    if (i + 1 == destination_stop_index_) {
      return *it;
    } else {
      i++;
    }
  }
  return 0.0;
}

bool Route::IsAtEnd() const {
  return (destination_stop_index_ == stops_.size());
}

double Route::GetTotalRouteDistance() const {
  double sum = 0.0;
  for (std::list<double>::const_iterator it = distances_between_.begin();
  it != distances_between_.end(); it++) {
    sum = sum + *it;
  }
  return sum;
}

/**
 * Creates a copy of the current route.  Keeps pointers to the routes'
 * stops and distance values.  Clone() doesn't track private variables
 * so they are initalized to default values.
 */
Route * Route::Clone() {
  Stop ** temp_stops = new Stop *[num_stops_];  // TODO(a_user): memory leak.
  int i = 0;
  // creating an array to pass into the Route constructor.
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    temp_stops[i] = *(it);
    i++;
  }
  // creating an array to pass into the Route constructor.
  double * temp_dist = new double[num_stops_ - 1];
  i = 0;
  for (std::list<double>::iterator it = distances_between_.begin();
  it != distances_between_.end(); it++) {
    temp_dist[i] = *(it);
    i++;
  }
  Route * temp = new Route(name_, temp_stops,
     temp_dist, num_stops_, generator_);
  // put deletes for memory leak issue here.
  return temp;
}

Stop * Route::GetDestinationStop() const {
  return destination_stop_;
}

std::string Route::GetName() {
  return name_;
}

std::list<Stop *> Route::GetStops() {
  return stops_;
}

void Route::UpdateRouteData() {
  route_data_.id = name_;
  std::vector<StopData> temp_vec;
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    StopData temp = StopData();
    temp.id = std::to_string((*it)->GetId());
    temp.position = (*it)->GetPosStruct();
    temp.num_people = (*it)->GetPassengers()->size();
    temp_vec.push_back(temp);
  }
  route_data_.stops = temp_vec;
}

RouteData Route::GetRouteData() {
  return route_data_;
}

PassengerGenerator * Route::GetGenerator() {
  return generator_;
}

void Route::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Report(out);
    stop_counter++;
  }
}
