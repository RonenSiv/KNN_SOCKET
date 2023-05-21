/**
 * Distance Base Class Header File
 */

#ifndef ADVANCEDPROGRAMMINGR_O_DISTANCE_H
#define ADVANCEDPROGRAMMINGR_O_DISTANCE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

#define VEC_NOT_NUM_MSG "The vector contains non-numeric values."
#define VEC_1_2_ZERO_MSG "ERROR: Both vectors are empty"
#define VEC_DIFF_SIZE_MSG "ERROR: Problem with calculating Distance -- Make sure vectors are of the same size"
#define VEC_1_ZERO_MSG "ERROR: Problem with calculating Distance -- Vector 1 is empty"
#define VEC_2_ZERO_MSG "ERROR: Problem with calculating Distance -- Vector 2 is empty"

#define PRECISION 17

/**
 * This class represents the Distance Base Algorithm
 * It is an abstract class
 * It has a virtual method Calculate
 * It has a method that validates the vectors and throws an exception if they are empty or of different sizes
 */

template<typename T>
class Distance {
public:

    /**
     * Distance destructor
     */
    virtual ~Distance() = default;

    /**
     * This method calculates the distance between two vectors
     * @param vec1 - the first vector
     * @param vec2 - the second vector
     * @return the distance between the two vectors
     */
    virtual T Calculate(const vector<T> &vec1, const vector<T> &vec2) = 0;

    /**
     * This method validates the vectors and throws an exception if they are empty or of different sizes
     * @param vec1 - the first vector
     * @param vec2 - the second vector
     */
    virtual void validateVectors(const vector<T> &vec1, const vector<T> &vec2);

    /**
     * This method returns the name of the algorithm
     * @return the name of the algorithm
     */
    string getName() { return _name; }

protected:
    /**
     * This method returns the name of the algorithm
     */
    string _name;
};


template<typename T>
void Distance<T>::validateVectors(const vector<T> &vec1, const vector<T> &vec2) {
    if (!std::is_arithmetic<T>::value) throw VEC_NOT_NUM_MSG;
    if (vec1.empty() && vec2.empty()) throw VEC_1_2_ZERO_MSG;
    if (vec1.empty()) throw VEC_1_ZERO_MSG;
    if (vec2.empty()) throw VEC_2_ZERO_MSG;
    if (vec1.size() != vec2.size()) throw VEC_DIFF_SIZE_MSG;
}


#endif //ADVANCEDPROGRAMMINGR_O_DISTANCE_H