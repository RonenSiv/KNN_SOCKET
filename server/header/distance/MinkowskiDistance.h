/**
 * Minkowski Distance Algorithm - Header File
 */

#ifndef ADVANCEDPROGRAMMINGR_O_MINKOWSKIDISTANCE_H
#define ADVANCEDPROGRAMMINGR_O_MINKOWSKIDISTANCE_H

#include "Distance.h"

#define POWER 2 // The power of the Minkowski distance (2 = Euclidean distance)

/**
 * This class represents the Minkowski Distance Algorithm
 * It inherits from the Distance class
 * It overrides the Calculate method and implements the Minkowski Distance formula
 */
template<typename T>
class MinkowskiDistance : public Distance<T> {
    static_assert(std::is_arithmetic<T>::value, "Vector elements must be numeric values for Minkowski Distance");
public:
    /**
     * MinkowskiDistance constructor
     * It calls the Distance constructor
     */
    MinkowskiDistance() : Distance<T>() { this->_name = "MIN"; };

    /**
     * Destructor
     */

    ~MinkowskiDistance() override = default;

    /**
     * This method calculates the Minkowski Distance between two vectors
     * @param vec1 - the first vector
     * @param vec2 - the second vector
     * @return the Minkowski Distance between the two vectors
     * @throws invalid_argument if the vectors are of different sizes
     * @throws invalid_argument if one or both vectors are empty
     */
    T Calculate(const vector<T> &vec1, const vector<T> &vec2) override;
};

template<typename T>
T MinkowskiDistance<T>::Calculate(const vector<T> &vec1, const vector<T> &vec2) {
    this->validateVectors(vec1, vec2);
    double sum = 0;
    for (int i = 0; i < min((int) vec1.size(), (int) vec2.size()); i++) {
        sum += pow(abs(vec1[i] - vec2[i]), POWER);
    }
    return pow(sum, 1.0 / POWER);
}

#endif
