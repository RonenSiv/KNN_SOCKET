/**
 * Util header file
 */
#ifndef ADVANCEDPROGRAMMINGR_O_UTIL_H
#define ADVANCEDPROGRAMMINGR_O_UTIL_H

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include "server/header/distance/Distance.h"

using namespace std;


/**
 * Util class with static methods to be used in the program to avoid code duplication, and to make the code more
 * readable and maintainable by using meaningful names for the methods instead of using the same code in different
 * places with different names. This class is used to perform operations on strings, vectors, distances and other
 * _data types. The methods are static, so they can be called without creating an instance of the class. The methods
 * are also const, so they can be called on const objects.
 */

class Util {
private:
    /**
     * Private constructor to prevent creating an instance of the class.
     */
    Util() = default;

    /**
     * Private method to convert a string to a vector of doubles.
     * @param str the string to convert
     * @param vec the vector to add the doubles to
     * @return true if the conversion was successful, false otherwise
     * @throws invalid_argument if the string contains invalid values
     */
    template<typename T>
    static void strToVec(const string &str, vector<T> &vec);

public:
    /**
     * Method to check validity of command line arguments that are intended to be sent to server.
     * @param filePath a relative or absolute path to the file of classified vectors
     * @param port a port number to be associated to the server
     * @param argc number of command line arguments
     * @return the port number if both inputs are valid, 0 otherwise.
     */
    static int validateServerInput(string filePath, string port, int argc);

    template<typename T>
    static bool is_number(const std::string &s);
    /**
     * Method to get a vector of doubles from the user.
     * @param
     * @return the vector of T
     */
    template<typename T>
    static vector<T> userCreateVector(string &str);

    /**
     * Method to get a vector of doubles from the user.
     * @return the vector of T
     */
    template<typename T>
    static vector<T> userCreateVector();

    /**
     * Private method to iterate over a string and add each word to a vector.
     * @param str the string to iterate over
     * @param vec the vector to add the words to
     */
    static void stringIterate(const string &str, vector<string> &vec);

    /**
     * Converts words of a string into a type t.
     * @param str the string to iterate over
     */
    template<typename T>
    static T convert_to(const std::string &str);

    /**
     * Finds the majority of the occurrences of the given type of vectors .
     * @param vec the vector of the types to determine the majority from
     */
    template<typename T>
    static T mostCommon(const vector<T> &vec);
};

template<typename T>
bool Util::is_number(const std::string &s) {
    T n;
    return ((std::istringstream(s) >> n >> std::ws).eof());
}

template<typename T>
vector<T> Util::userCreateVector() {
    string str;
    getline(cin, str);
    return Util::userCreateVector<T>(str);
}

template<typename T>
vector<T> Util::userCreateVector(string& str) {
    vector<T> vec;
    try {
        strToVec(str, vec);
    } catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
    return vec;
}

template<typename T>
void Util::strToVec(const string &str, vector<T> &vec) {
    vector<string> vecStr;
    stringIterate(str, vecStr);
    for (const string &s: vecStr) {
        if (std::is_arithmetic<T>::value) {
            if (!is_number<T>(s)) {
                throw std::invalid_argument("The input contains non-numeric values for a numeric vector.");
            }
        }
        vec.push_back(convert_to<T>(s));
    }
}

template<typename T>
T Util::convert_to(const string &str) {
    std::stringstream ss{str};
    T t;
    ss >> t;
    return t;
}

template<typename T>
T Util::mostCommon(const vector<T> &vec) {
    map<T, int> m;
    for (const T &t: vec) {
//        cout << t << endl;
        m[t]++;
    }
//    for (const auto &p: m) {
//        cout << p.first << " " << p.second << endl;
//    }
    int max = 0;
    T maxT;
    for (const auto &p: m) {
        if (p.second > max) {
            max = p.second;
            maxT = p.first;
        }
    }
    return maxT;
}

#endif


