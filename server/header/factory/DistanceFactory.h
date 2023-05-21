/**
 * Distance Factory class
 */

#ifndef ADVANCEDPROGRAMMINGR_O_DISTANCEFACTORY_H
#define ADVANCEDPROGRAMMINGR_O_DISTANCEFACTORY_H


#include "server/header/distance/Distance.h"
#include "server/header/distance/EuclideanDistance.h"
#include "server/header/distance/ManhattanDistance.h"
#include "server/header/distance/ChebyshevDistance.h"
#include "server/header/distance/CanberraDistance.h"
#include "server/header/distance/MinkowskiDistance.h"

template<typename T>
/**
 * This class implements the Factory design pattern, to create distance objects
 */
class DistanceFactory {
public:
    /**
     * Constructor
     */
    DistanceFactory() = default;

    /**
     * Destructor
     */
    ~DistanceFactory() = default;

    /**
     * create a distance object by the given name of the distance
     * @param algorithm - the name of the distance metric
     */
    Distance<T> *createDistanceAlgo(const std::string &algorithm);
};


template<typename T>
Distance<T> *DistanceFactory<T>::createDistanceAlgo(const std::string &algorithm) {
    if (algorithm == "AUC") {
        return new EuclideanDistance<T>();
    } else if (algorithm == "MAN") {
        return new ManhattanDistance<T>();
    } else if (algorithm == "CHB") {
        return new ChebyshevDistance<T>();
    } else if (algorithm == "CAN") {
        return new CanberraDistance<T>();
    } else if (algorithm == "MIN") {
        return new MinkowskiDistance<T>();
    } else {
        throw "Error: Invalid algorithm";
    }
}


#endif //ADVANCEDPROGRAMMINGR_O_DISTANCEFACTORY_H
