/*
 * Canberra Distance Algorithm - Header File
 */

#ifndef ADVANCEDPROGRAMMINGR_O_CANBERRADISTANCE_H
#define ADVANCEDPROGRAMMINGR_O_CANBERRADISTANCE_H

#include "Distance.h"

#define ZERO_ARG_MSG "ERROR: Canberra distance is undefined when both values are '0'"

/**
 * This class represents the Canberra Distance Algorithm
 * It inherits from the Distance class
 * It overrides the Calculate method and implements the Canberra Distance formula
 */
template<typename T>
class CanberraDistance : public Distance<T> {
    static_assert(std::is_arithmetic<T>::value, "Vector elements must be numeric values for Canberra Distance");
public:
    /**
     * CanberraDistance constructor
     * It calls the Distance constructor
     */
    CanberraDistance() : Distance<T>() { this->_name = "CAN"; };

    /**
     * Destructor
     */
    ~CanberraDistance() override = default;

    /**
     * This method calculates the Canberra Distance between two vectors
     * @param vec1 - the first vector
     * @param vec2 - the second vector
     * @return the Canberra Distance between the two vectors
     * @throws invalid_argument if the vectors are of different sizes
     * @throws invalid_argument if one or both vectors are empty
     * @throws logic_error if the denominator is 0
     */

    T Calculate(const vector<T> &vec1, const vector<T> &vec2) override;

};


template<typename T>
T CanberraDistance<T>::Calculate(const vector<T> &vec1, const vector<T> &vec2) {
    this->validateVectors(vec1, vec2);
    T sum = 0;
    for (int i = 0; i < min((int) vec1.size(), (int) vec2.size()); i++) {
        if (((abs(vec1[i]) + abs(vec2[i]))) == 0) {
            throw ZERO_ARG_MSG;
        }
        sum += (abs(vec1[i] - vec2[i])) / ((abs(vec1[i]) + abs(vec2[i])));
    }
    return sum;
}


#endif
