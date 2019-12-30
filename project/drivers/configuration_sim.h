/**
 * @file configuration_sim.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef DRIVERS_CONFIGURATION_SIM_H
#define DRIVERS_CONFIGURATION_SIM_H

#include <iostream>
#include <string>

#include "src/config_manager.h"
#include "src/configuration_simulator.h"

using namespace std;  // NOLINT

class ConfigurationSim {
 public:
    /*
     * @brief Parses the first config file argument.
     * @param[in] arg1, the first input argument.
     * @param[in] default_val, the default input config file
     *
     * @return A string of the config filename to be used.
     */
    string parse_first_argument(string arg1, string default_val);
    /*
     * @brief Parses the second config file argument.
     * @param[in] arg2_[], the second input argument.
     * @param[in] default_val,
     * the default number of iterations the sim will run.
     *
     * @return An int of the number of iterations to be used.
     */
    int parse_second_argument(char arg2_[], int default_val);
    /*
     * @brief A helper function to determine if a string is a number.
     * @desc Code pulled from StackOverflow.
     * @param[in] number[], the input argument, expected to be a number.
     *
     * @return true if the input char[] is an int, false otherwise.
     */
    bool is_number(char number[]);
    /*
     * @brief The main function
     * @param[in] argc, the number of cmd-line arguments
     * @parm[in] agrv, the array of cmd-line arguments
     *
     * @return 0 if it runs successfully, 1 if it exits unnaturally.
     */
    int main(int argc, char**argv);
};
#endif  // DRIVERS_CONFIGURATION_SIM_H
