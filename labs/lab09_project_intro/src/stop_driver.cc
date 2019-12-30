/**
 * @file stop_driver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <vector>

#include "src/bus.h"
#include "src/passenger.h"
#include "src/stop.h"


int main() {
  std::vector<Passenger *> passengers;
  passengers.push_back(new Passenger(33, "Zoe"));
  passengers.push_back(new Passenger(42, "Kaylee"));
  passengers.push_back(new Passenger(50, "Wash"));
  passengers.push_back(new Passenger(10, "Mal"));
  passengers.push_back(new Passenger(23, "Jayne"));

  Stop stop1(1);  //  student union station
  Stop stop2(2, 44.973820, -93.227117);  //  Oak St & Washington Ave
  Bus * bus1 = new Bus();

  stop1.AddPassengers(passengers[0]);
  stop2.AddPassengers(passengers[1]);
  stop2.AddPassengers(passengers[2]);

  passengers[0]->Update();
  passengers[1]->Update();
  passengers[2]->Update();

  std::cout << "/*\n *\n * Initial Report\n *\n*/" << std::endl;

  stop1.Report();
  stop2.Report();

  std::cout << "/*\n *\n * Loading passengers onto Bus1\n *\n*/" << std::endl;

  stop1.LoadPassengers(bus1);
  passengers[0]->GetOnBus();

  passengers[0]->Update();
  passengers[1]->Update();
  passengers[2]->Update();

  std::cout << "/*\n *\n * Second Report\n *\n*/" << std::endl;

  stop1.Report();
  stop2.Report();

  std::cout << "/*\n *\n * Adding additional passengers to stop\n *\n*/";
  std::cout << std::endl;

  stop2.AddPassengers(passengers[3]);
  stop1.AddPassengers(passengers[4]);

  passengers[0]->Update();
  passengers[1]->Update();
  passengers[2]->Update();
  passengers[3]->Update();
  passengers[4]->Update();

  std::cout << "/*\n *\n * Third Report\n *\n*/" << std::endl;

  stop1.Report();
  stop2.Report();

  std::cout << "/*\n *\n * Loading passengers from both stops to Bus1\n *\n*/";
  std::cout << std::endl;

  stop1.LoadPassengers(bus1);
  stop2.LoadPassengers(bus1);

  passengers[1]->GetOnBus();
  passengers[2]->GetOnBus();
  passengers[3]->GetOnBus();
  passengers[4]->GetOnBus();

  passengers[0]->Update();
  passengers[1]->Update();
  passengers[2]->Update();
  passengers[3]->Update();
  passengers[4]->Update();

  std::cout << "/*\n *\n * Final Report\n *\n*/" << std::endl;

  stop1.Report();
  stop2.Report();

  std::cout << "/*----------------\n";
  std::cout << " *\n";
  std::cout << " * Post-mortem Passenger Reports\n";
  std::cout << " *\n";
  std::cout << " *---------------*/" << std::endl;

  passengers[0]->Report();
  passengers[1]->Report();
  passengers[2]->Report();
  passengers[3]->Report();
  passengers[4]->Report();

  return 0;
}
