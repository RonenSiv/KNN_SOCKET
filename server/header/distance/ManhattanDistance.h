/**
 * Manhattan Distance Algorithm - Header File
 */

#ifndef ADVANCEDPROGRAMMINGR_O_MANHATTANDISTANC_H
#define ADVANCEDPROGRAMMINGR_O_MANHATTANDISTANC_H

#include "Distance.h"

/**
 * This class represents the Manhattan Distance Algorithm
 * It inherits from the Distance class
 * It overrides the Calculate method and implements the Manhattan Distance formula
 */
template<typename T>
class ManhattanDistance : public Distance<T> {
public:
    static_assert(std::is_arithmetic<T>::value, "Vector elements must be numeric values for Manhattan Distance");

    /**
    * CanberraDistance constructor
    * It calls the Distance constructor
    */
    ManhattanDistance() : Distance<T>() { this->_name = "MAN"; };

    /**
     * Destructor
     */
    ~ManhattanDistance() override = default;

    /**
    * This method calculates the Manhattan Distance between two vectors
    * @param vec1 - the first vector
    * @param vec2 - the second vector
    * @return the Manhattan Distance between the two vectors
    * @throws invalid_argument if the vectors are of different sizes
    * @throws invalid_argument if one or both vectors are empty
    */
    T Calculate(const vector<T> &vec1, const vector<T> &vec2) override;
};

template<typename T>
T ManhattanDistance<T>::Calculate(const vector<T> &vec1, const vector<T> &vec2) {
    this->validateVectors(vec1, vec2);
    T distance = 0;
    for (int i = 0; i < (int) vec1.size(); i++) {
        distance += abs(vec1.at(i) - vec2.at(i));
    }
    return distance;
}

#endif

