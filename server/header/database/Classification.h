//
// Created by Ronen on 08/12/2022.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLASSIFICATION_H
#define ADVANCEDPROGRAMMINGR_O_CLASSIFICATION_H

#include <vector>
#include <algorithm>

#include "DataBase.h"
#include "server/header/util/Util.h"

/**
 * This class responsible for classification of data from type T, using different algorithms.
 * One of the algorithms is KNN.
 * @tparam T the type of the data to be classified
 */
template<typename T>
class Classification {
public:
    /**
     * Constructor for the Classification class.
     */
    Classification() = default;

    /**
     * Destructor for the Classification class.
     */
    ~Classification() = default;

    /**
     * The classify function gets a vector of features and a DataBase object and returns the classification of the
     * features.
     */
    static string KNN(pair<vector<T>, int> p, DataBase<T> &db, Distance<T> &distanceAlgorithm) noexcept(false);

    /**
     * The classify function gets a vector of features and a DataBase object and returns the classification of the
     * features.
     */
    static string KNN(int k, vector<T> vec, DataBase<T> &db, Distance<T> &distanceAlgorithm) noexcept(false);
};

template<typename T>
string
Classification<T>::KNN(pair<vector<T>, int> p, DataBase<T> &db, Distance<T> &distanceAlgorithm) {
    vector<T> distances;
    vector<std::pair<T, string>> vecDistances;
    // get the distances from the features to the data in the DataBase
    int size = db.getSize();
    if (p.second > size) {
        throw "Error in classification: k is bigger than the size of the DataBase";
    }
    for (auto &v: db) {
        try {
            distances.push_back(distanceAlgorithm.Calculate(p.first, v.first));
        } catch (const char *e) {
            throw e;
        }
        vecDistances.push_back(std::make_pair(distances[distances.size() - 1], v.second));
    }
    auto k = p.second;
    std::nth_element(vecDistances.begin(), vecDistances.begin() + k - 1, vecDistances.end());
    vector<string> kNearestNeighbors;
    for (int i = 0; i < k; i++) {
        kNearestNeighbors.push_back(vecDistances[i].second);
    }
    // Find the most common classification.
    string mostCommon = Util::mostCommon<string>(kNearestNeighbors);
    return mostCommon;
}

template<typename T>
string
Classification<T>::KNN(int k, vector<T> vec, DataBase<T> &db, Distance<T> &distanceAlgorithm) noexcept(false) {
    return KNN(std::make_pair(vec, k), db, distanceAlgorithm);
}

#endif //ADVANCEDPROGRAMMINGR_O_CLASSIFICATION_H