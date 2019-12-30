/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */

#include "src/config_manager.h"
#include <sstream>
#include <fstream>
#include <list>
#include <algorithm>
#include "src/route.h"
#include "src/stop.h"
#include "src/random_passenger_generator.h"

ConfigManager::ConfigManager() : routes_(std::vector<Route *>()) { }

ConfigManager::~ConfigManager() {
    for (int i = 0; i < static_cast<int>(routes_.size()); i++) {
        routes_[i] = nullptr;
    }
    routes_.clear();
}

void ConfigManager::ReadConfig(const std::string filename) {
    std::ifstream config_file("config/" + filename);
    std::list<Stop *> stops = std::list<Stop *>();
    std::list<double> distances = std::list<double>();
    double old_lat = 0;
    double old_lon = 0;
    std::list<double> curr_probabilities = std::list<double>();
    std::string curr_general_name = "";
    std::string curr_route_name = "";
    std::vector<std::string> stop_names = std::vector<std::string>();
    int stop_id = 10;
    std::string line;
    while (std::getline(config_file, line)) {
        std::istringstream string_stream(line);
        std::string chunk;
        if (!std::getline(string_stream, chunk, ',')) { continue; }
        if (chunk == "ROUTE_GENERAL") {
            curr_general_name = "";
            std::getline(string_stream, curr_general_name);
        } else if (chunk == "ROUTE") {
            // If we are coming to a route besides our first one, save all our
            // data and init variables for next route
            if (stops.size() > 0) {
                // Convert our variables into the necessary raw memory
                int num_stops = static_cast<int>(stops.size());
                Stop ** raw_stops = new Stop *[num_stops];
                int it = 0;
                for (auto* s : stops) {
                    raw_stops[it] = s;
                    it++;
                }
                int num_dists = static_cast<int>(distances.size());
                double * raw_dists = new double[num_dists];
                it = 0;
                for (const auto& d : distances) {
                    raw_dists[it] = d;
                    it++;
                }
                routes_.push_back(
                        new Route(
                            curr_general_name + " " + curr_route_name,
                            raw_stops,
                            raw_dists,
                            static_cast<int>(stops.size()),
                            new RandomPassengerGenerator(curr_probabilities,
                               stops)));
                stops.clear();
                distances.clear();
                curr_probabilities.clear();
            }
            old_lat = 0;  // Refresh our old values on a new route
            old_lon = 0;
            std::getline(string_stream, curr_route_name);
            curr_route_name.erase(std::remove(curr_route_name.begin(),
             curr_route_name.end(), ' '), curr_route_name.end());
        } else if (chunk == "STOP") {
            // Grab our comma seperated values
            std::string stop_name;
            std::getline(string_stream, stop_name, ',');
            stop_name.erase(std::remove(stop_name.begin(),
             stop_name.end(), ' '),
             stop_name.end());

            // Check if the stop already exists
            std::vector<std::string>::iterator it = std::find(stop_names.begin()
            , stop_names.end(), stop_name);
            if (it != stop_names.end()) {
                // We have already seen this stop
                int index = std::distance(stop_names.begin(), it);
                std::list<Stop *>::iterator iter = stops.begin();
                std::advance(iter, index);
                stops.push_back(*iter);
                continue;
            }
            // If we have not seen this stop, set it up
            int id = stop_id;
            stop_id++;
            std::string lat_string;
            std::getline(string_stream, lat_string, ',');
            double latitude = std::stod(lat_string);
            std::string lon_string;
            std::getline(string_stream, lon_string, ',');
            double longitude = std::stod(lon_string);
            stops.push_back(new Stop(id, latitude, longitude));

            // Need to turn these lat and long into real-world distances
            // This means moving 1 speed in a time click moves 1 mile.
            // That's a bit far, so I multiply * 2 so that a speed of
            // 1 moves 1/2 mile
            latitude *= 69 * 2;
            longitude *= 55 * 2;
            // Grabbing last element from list is hard, so cache position
            // instead
            if (stops.size() > 1) {
                double dist = sqrt((latitude-old_lat)*(latitude-old_lat)
                 + (longitude-old_lon)*(longitude-old_lon));
                distances.push_back(dist);
            }
            old_lat = latitude;
            old_lon = longitude;
            std::string prob_string;
            std::getline(string_stream, prob_string);
            double probability = std::stod(prob_string);
            curr_probabilities.push_back(probability);
        }
    }
    // Generatre our last route
    if (stops.size() > 0) {
        // Convert our variables into the necessary raw memory
        int num_stops = static_cast<int>(stops.size());
        Stop ** raw_stops = new Stop *[num_stops];
        int it = 0;
        for (auto* s : stops) {
            raw_stops[it] = s;
            it++;
        }

        int num_dists = static_cast<int>(distances.size());
        double * raw_dists = new double[num_dists];
        it = 0;
        for (const auto& d : distances) {
            raw_dists[it] = d;
            it++;
        }

        routes_.push_back(
                new Route(
                    curr_general_name + " " + curr_route_name,
                    raw_stops,
                    raw_dists,
                    static_cast<int>(stops.size()),
                    new RandomPassengerGenerator(curr_probabilities, stops)));
    }
    curr_probabilities.clear();
    stops.clear();
    distances.clear();
}
