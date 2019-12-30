#include <iostream>
#include <vector>

#include "stop.h"

Stop::Stop(int id, double longitude, double latitude) { //Defaults to Westbound Coffman Union stop
	  // no initialization of list of passengers necessary
}


void Stop::LoadPassengers(Bus * bus) {
	  //loading some passengers onto a bus
		//passengers_
		while(!passengers_.empty()) {
			bus->LoadPassenger(passengers_.front());
			passengers_.pop_front();
		}
}


void Stop::AddPassengers(Passenger * pass) {
	  //add the passenger to the stop
		passengers_.push_back(pass);
}


int Stop::GetId() const{
	  return id_;
}


void Stop::Report() const {
	  std::cout << "ID: " << id_ << std::endl;
	  std::cout << "Passengers waiting: " << passengers_.size() << std::endl;
	  for(std::list<Passenger *>::const_iterator it = passengers_.begin(); it != passengers_.end(); it++) {
	    (*it)->Report();
	  }
}
