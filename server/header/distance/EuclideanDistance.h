/**
 * Euclidean Distance Algorithm - Header File
 */


#ifndef ADVANCEDPROGRAMMINGR_O_EUCLIDEANDISTANC_H
#define ADVANCEDPROGRAMMINGR_O_EUCLIDEANDISTANC_H

#include "Distance.h"

/**
 * This class represents the Euclidean Distance Algorithm
 * It inherits from the Distance class
 * It overrides the Calculate method and implements the Euclidean Distance formula
 */
template<typename T>
class EuclideanDistance : public Distance<T> {
    static_assert(std::is_arithmetic<T>::value, "Vector elements must be numeric values for Euclidean Distance");
public:

    /**
     * CanberraDistance constructor
     * It calls the Distance constructor
     */
    EuclideanDistance() : Distance<T>() { this->_name = "AUC"; };

    /**
     * Destructor
     */
    ~EuclideanDistance() override = default;

    /**
    * This method calculates the Euclidean Distance between two vectors
    * @param vec1 - the first vector
    * @param vec2 - the second vector
    * @return the Chebyshev Distance between the two vectors
    * @throws invalid_argument if the vectors are of different sizes
    * @throws invalid_argument if one or both vectors are empty
    */
    T Calculate(const vector<T> &vec1, const vector<T> &vec2) override;
};

template<typename T>
T EuclideanDistance<T>::Calculate(const vector<T> &vec1, const vector<T> &vec2) {
    this->validateVectors(vec1, vec2);
    double squares = 0;
    T distance;
    int power = 2;
    for (int i = 0; i < (int) vec1.size(); i++) {
        squares += pow((vec1.at(i) - vec2.at(i)), power);
    }

    distance = sqrt(squares);
    return distance;
}

#endif

