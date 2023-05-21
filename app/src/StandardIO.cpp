
#include <iostream>

#include "app/header/StandardIO.h"

string StandardIO::read() {
    string line;
    getline(std::cin, line);
    return line;
}
void StandardIO::write(string text) {
    std::cout << text << std::endl;
}

