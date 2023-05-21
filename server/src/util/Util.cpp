/*
 * Util class implementation file
 */
#include "server/header/util/Util.h"

void Util::stringIterate(const string &str, vector<string> &vec) {
    string buff;
    stringstream ss(str);
    while (ss >> buff) {
        vec.push_back(buff);
    }
}
