
#ifndef DATA_STRUCTS_H_
#define DATA_STRUCTS_H_

#include <string>
#include <vector>


struct Position {
    Position() : x(0), y(0) {}
    float x;
    float y;
};

struct BusData {
    BusData() : id(""), pos(Position()), numPassengers(0), capacity(0) {}
    std::string id; // some unique identifier for the bus
    Position pos; // long lat position of bus
    int numPassengers;
    int capacity;
};

struct StopData {
    StopData() : id(""), pos(Position()), numPeople(0) {}
    std::string id; // some unique identifier for the stop
    Position pos; // long lat position of bus
    int numPeople;
};

struct RouteData {
    RouteData() : id(""), stops(std::vector<StopData>(0)) {}
    std::string id; // some unique identifier for the route
    std::vector<StopData> stops;
};

#endif // DATA_STRUCTS_H_
