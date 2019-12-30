/**
 * @file configuration_sim.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <iostream>
#include <fstream>

#include "src/config_manager.h"
#include "src/configuration_simulator.h"
#include "drivers/configuration_sim.h"

using namespace std; // NOLINT

// Takes first argument (config file) and attempts to open it.
string parse_first_argument(string arg1, string default_val) {
  string config_file = default_val;
  cout << "First argument:" << endl;
  cout << "Attempting to open user-inputted config file" << endl;
  ifstream if_ptr("config/" + arg1);
  if_ptr.open("config/" + arg1);
  if (if_ptr.is_open()) {
    // If the supplied file opens we will use it.
    cout << "The config file " << arg1 << " is valid and is used!" << endl;
    if_ptr.close();
    config_file = arg1;
  } else {
    // If the supplied file doesn't open we will try to use default config.txt
    cout << "Error when opening config file: " << arg1 << endl;
    cout << "Attempting to use default Configuration File: " << config_file
    << " file found in project/config/" << endl;
    ifstream if_ptr("config/" + default_val);
    if_ptr.open("config/" + default_val);
    // checking to make sure that the default file will open.
    if (if_ptr.is_open()) {
      // default file opens and wil be used.
      cout << "The config file " << default_val << " is valid and is used!"
       << endl;
      if_ptr.close();
    } else {
      // default file also failed to open, program will exit
      cout << "Error when opening default config file: " << default_val
       << endl;
      cout << "Program will not continue!" << endl;
      config_file = "";
    }
  }
  return config_file;
}


// https://stackoverflow.com/questions/29248585/
// c-checking-command-line-argument-is-integer-or-not
// Taken from Stack Overflow
bool is_number(char number[]) {
  int i = 0;
  // checking for negative numbers
  if (number[0] == '-') {
    i = 1;
  }
  for (; number[i] != 0; i++) {
    // if (number[i] > '9' || number[i] < '0')
    if (!isdigit(number[i]))
      return false;
  }
  return true;
}

// takes the second argument (number of updates on simulation) and verifys it.
int parse_second_argument(char arg2_[], int default_val) {
  int number_of_iterations = default_val;
  // checking to make sure input is an integer.
  if (is_number(arg2_)) {
    int arg2 = stoi(arg2_);
    cout << "Second argument:" << endl;
    cout << "Determining if number of iterations is valid:" << endl;
    // check to make sure number of iterations is a positive.
    if (arg2 < 1) {
      cout << arg2 << " is not a valid simulation length" << endl;
      cout << "The number of simulations needs to be an "
      << "integer value greater than 0" << endl;
      cout << "Using default Number of Iterations: "
      << number_of_iterations << endl;
    } else {
      // if the input is not > 0, then use default.
      cout << arg2 << " is a valid simulation length and is used!" << endl;
      number_of_iterations = arg2;
    }
  } else {
    // if the input is not an integer then use default.
    string temp = arg2_;
    cout << temp << " is not a valid simulation length" << endl;
    cout << "The number of simulations needs to be an "
    << "integer value greater than 0" << endl;
    cout << "Using default Number of Iterations: "
    << number_of_iterations << endl;
  }
  return number_of_iterations;
}

/*
 Command line tests ran:
  No args
 ./build/bin/config_sim
  One invalid arg
 ./build/bin/config_sim conf.txt
  One valid arg
 ./build/bin/config_sim config_test.txt
  One arg which is default value
 ./build/bin/config_sim config.txt
  One invalid arg, default config used and default sim length used.
  My parameter parsing doesn't try to guess which varaibles are which args so
  it wont know/try to make 7 the simulation length.
 ./build/bin/config_sim 7
  Two args, file invalid, wrong type for sim length
 ./build/bin/config_sim conf.txt a
  Two args, file invalid, negative value for sim length
 ./build/bin/config_sim conf.txt -100
  Two args, file invalid, illegal float type for sim length
 ./build/bin/config_sim conf.txt 6.2
  Two args, file invalid, valid sim length
 ./build/bin/config_sim config.txt 55
  Two args, file valid, wrong type for sim length
 ./build/bin/config_sim config.txt a
  Two args, file valid, negative value for sim length
 ./build/bin/config_sim config.txt -100
  Two args, file valid, illegal float type for sim length
 ./build/bin/config_sim config.txt 6.2
  Two args, file valid, valid sim length
 ./build/bin/config_sim config.txt 55
  Three args, file valid, valid sim length
 ./build/bin/config_sim config.txt 55  asdf
*/

int main(int argc, char**argv) {
  // letting the user know how to use the executable.
  cout << "Usage from project/ directiory: ./build/bin/config_sim" <<
   " <config_filename> <length of simulation>" << endl;
  cout << "--------------------" << endl;
  // Default Values:
  string config_file = "config.txt";
  int number_of_iterations = 1;

  if (argc == 1) {
    cout << "No arguments passed:" << endl;
    cout << "Using default Configuration File: " << config_file
    << " file found in project/config/" << endl;
    cout << "Using default Number of Iterations: " << number_of_iterations
    << endl;
  } else if (argc == 2) {
    cout << "One argument supplied" << endl;
    config_file = parse_first_argument(argv[1], config_file);
    cout << "Second argument not supplied" << endl;
    cout << "Using default Number of Iterations: " << number_of_iterations
    << endl;
  } else if (argc == 3) {
    cout << "Two arguments supplied:" << endl;
    config_file = parse_first_argument(argv[1], config_file);
    number_of_iterations = parse_second_argument(argv[2],
    number_of_iterations);
  } else if (argc > 3) {
    // if they pass more than 2 arguments then we ignore the extra arguments.
    cout << "At least three arguments supplied:" << endl;
    config_file = parse_first_argument(argv[1], config_file);
    number_of_iterations = parse_second_argument(argv[2],
    number_of_iterations);
    cout << "Ignoring all remaining arguments" << endl;
  }
  // if both the user and defult config file fails, we exit without running.
  // this is the only case where the program exists and "fails"
  if (config_file == "") {
    return 1;
  }
  ConfigManager * config = new ConfigManager();
  config->ReadConfig(config_file);
  ConfigurationSimulator config_sim = ConfigurationSimulator(config);
  vector<int> default_bus_timings;
  // bus timings are defaulted to 10 apart.
  default_bus_timings.push_back(10);
  cout << "--------------------" << endl;
  config_sim.Start(default_bus_timings, number_of_iterations);
  for (int i = 0; i < number_of_iterations; i++) {
    config_sim.Update();
  }
  return 0;
}
