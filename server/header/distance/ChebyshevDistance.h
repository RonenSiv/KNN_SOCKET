/**
 * Chebyshev Distance Algorithm - Header File
 */

#ifndef ADVANCEDPROGRAMMINGR_O_CHEBYSHEVDISTANC_H
#define ADVANCEDPROGRAMMINGR_O_CHEBYSHEVDISTANC_H

#include "Distance.h"

/**
 * This class represents the Chebyshev Distance Algorithm
 * It inherits from the Distance class
 * It overrides the Calculate method and implements the Chebyshev Distance formula
 */
template<typename T>
class ChebyshevDistance : public Distance<T> {
    static_assert(std::is_arithmetic<T>::value, "Vector elements must be numeric values for Chebyshev Distance");
public:

    /**
    * CanberraDistance constructor
    * It calls the Distance constructor
    */
    ChebyshevDistance() : Distance<T>() { this->_name = "CHB"; };

    /**
     * Destructor
     */
    ~ChebyshevDistance() override = default;

    /**
     * This method calculates the Chebyshev Distance between two vectors
     * @param vec1 - the first vector
     * @param vec2 - the second vector
     * @return the Chebyshev Distance between the two vectors
     * @throws invalid_argument if the vectors are of different sizes
     * @throws invalid_argument if one or both vectors are empty
     */
    T Calculate(const vector<T> &vec1, const vector<T> &vec2) override;

};

template<typename T>
T ChebyshevDistance<T>::Calculate(const vector<T> &vec1, const vector<T> &vec2) {
    this->validateVectors(vec1, vec2);
    int start = 0;
    T max = abs((vec1.at(start) - vec2.at(start)));
    for (int i = 1; i < (int) vec1.size(); i++) {
        double temp = abs((vec1.at(i) - vec2.at(i)));
        if (temp > max) {
            max = temp;
        }
    }
    return max;
}

#endif
