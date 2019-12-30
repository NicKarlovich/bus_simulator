/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_

#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

class Stop;  // forward declaration

/**
 * @brief Abstract interface to create passenger generators from.
 */
class PassengerGenerator {
 public:
  /*
   * @brief The constructor to create PassengerGenerator objects.
   * @param[in] std::list<double> The list of generation probabilities.
   * @param[in] std::list<Stop *> The list of stops to generate passengers at.
   *
   * @return A PassengerGenerator object.
   */
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  /*
   * @brief A purely virtual function to generate passengers
   * @desc This virtual function makes PassengerGenerator abstract.
   *
   * @return an int, presumably the number of generated passengers,not defined.
   */
  virtual int GeneratePassengers() = 0;
  /*
   * @brief A getter to rturn the generation probabilities,
   * @desc Implemented in order to ensure last stop probability is always zero.
   *
   * @return A pointer to generation_probabilities_ used by the class
   */
  std::list<double> * GetGenerationProbs();

 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
