//
// Created by Ronen on 14/12/2022.
//

#ifndef ADVANCEDPROGRAMMINGR_O_DATABASE_H
#define ADVANCEDPROGRAMMINGR_O_DATABASE_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template<typename T>
/**
 * DataBase class
 * this class is a template class that can be used to save any type of data from any type of file
 */
class DataBase {
public:

    DataBase() = default;

    /**
     * DataBase constructor
     * @param file_name - the name of the file to read from
     */
    explicit DataBase(const string &filename, bool isTrain = true);

    /**
     * DataBase destructor
     */
    ~DataBase() = default;

    /**
     * This method returns the data from the file
     * @return the data from the file
     */
    vector<pair<vector<T>, string>> getData() const {
        return _data;
    }

    /**
     * This method returns the size of the data
     */
    int getSize() const {
        return _size;
    }


    void setType(string &type, int index);

    /**
     * Iterator class for the DataBase class
     * this class is a template class that can be used to iterate over any type of data from any type of file
     */
    class iterator {
    public:
        /**
         * iterator constructor
         * @param data - the data to iterate over
         * @param index - the index of the data to start iterating from
         */
        explicit iterator(typename vector<pair<vector<T>, string>>::iterator it) : it(it) {}

        /**
         * iterator destructor
         * @return the data at the current index
         */
        iterator &operator++() {
            ++it;
            return *this;
        }

        /**
         * This method returns the data at the current index
         * @return the data at the current index
         */
        bool operator!=(const iterator &other) { return it != other.it; }

        /**
         * This method returns the data at the current index
         * @return the data at the current index
         */
        const std::pair<vector<T>, string> &operator*() const { return *it; }

    private:
        /**
         * the data to iterate over
         */
        typename vector<pair<vector<T>, string>>::iterator it;
    };

    /**
     * This method returns an iterator to the beginning of the data
     * @return an iterator to the beginning of the data
     */
    iterator begin() { return iterator(_data.begin()); }

    /**
     * This method returns an iterator to the end of the data
     * @return an iterator to the end of the data
     */
    iterator end() { return iterator(_data.end()); }

private:
    /**
     * the data
     */
    vector<pair<vector<T>, string>> _data;
    /**
     * the size of the data
     */
    int _size;

    /**
     * a flag that indicates if the data was initialized
     */
    bool _isInit;

    void init(const string &filename, bool isTrain = true);
};


template<typename T>
DataBase<T>::DataBase(const string &filename, bool isTrain) {
    init(filename, isTrain);
    _isInit = true;
}


template<typename T>
void DataBase<T>::init(const string &filename, bool isTrain) {
    ifstream file(filename);
    if (!file.is_open()) {

        throw "Could not open the file: " + filename;
    }
    /**./
     * read the file line by line
     * each line is a different data
     * each data is a vector of type T
     */
    string line;
    while (getline(file, line)) {
        vector<T> lineData;
        istringstream iss(line);
        string type; //might make bugs if it's an unclassified data
        while (getline(iss, line, ',')) {
            T value;
            stringstream(line) >> value;
            lineData.push_back(value);
            type = line;
        }
        if (isTrain) {
            lineData.pop_back();
        } else {
            type = "unclassified";
        }
        pair<vector<T>, string> p(lineData, type);
        _data.push_back(p);
    }
    _size = _data.size();
}

template<typename T>
void DataBase<T>::setType(string &type, int index) {
    if (index < 0 || index >= _size) {
        throw "Index out of range";
    }
    _data[index].second = type;
}

#endif //ADVANCEDPROGRAMMINGR_O_DATABASE_H