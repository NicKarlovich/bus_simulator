#include <ctime>
#include <iostream>
#include <random>
#include <fstream>

#include "local_simulator.h"

int main(int argc, char * argv[]) {
  using namespace std;  // NOLINT
  if (argc == 1) { cout << "1 arg" << argv[0] << endl;}
  if (argc == 2) { cout << "2 args " << argv[0] << " " << argv[1] << endl;}

  ofstream out(NULL);
  out.open(argv[1]);

  int rounds = 2; // Number of rounds of generation to simulate in test

  srand((long)time(NULL)); // Seed the random number generator...

  LocalSimulator my_sim(out);

  out << "/*************************" << endl << endl;
  out << "         STARTING" << endl;
  out << "        SIMULATION" << endl;
  out << "*************************/" << endl;

  my_sim.Start();

  out << "/*************************" << endl << endl;
  out << "           BEGIN" << endl;
  out << "          UPDATING" << endl;
  out << "*************************/" << endl;

  for (int i = 0; i < rounds; i++) {
	  my_sim.Update();
  }

  out << "/*************************" << endl << endl;
  out << "        SIMULATION" << endl;
  out << "         COMPLETE" << endl;
  out << "*************************/" << endl;


  return 0;
}
