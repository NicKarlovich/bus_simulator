/**
 * @file config_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_

#include <vector>
#include <string>

class Route;

/**
 * @brief The class that contains the ConfigManager.
 */
class ConfigManager {
 public:
   /*
    * @brief Default constructor.
    *
    * @return ConfigManager object.
    */
  ConfigManager();
  /*
   * @brief Overriding the default destructor.
   */
  ~ConfigManager();
  /*
   * @brief Reads and parses config file
   * @param filename, a string representing the filepath to the config file.
   */
  void ReadConfig(const std::string filename);
  /*
   * @brief A getter to return the routes.
   *
   * @return A vector of route pointers.
   */
  std::vector<Route *> GetRoutes() const { return routes_; }

 private:
  std::vector<Route *> routes_;
};

#endif  // SRC_CONFIG_MANAGER_H_
