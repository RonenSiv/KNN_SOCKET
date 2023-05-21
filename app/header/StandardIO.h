//
// Created by ofirhelerman on 1/21/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_STANDARDIO_H
#define ADVANCEDPROGRAMMINGR_O_STANDARDIO_H


#include <string>
#include "app/header/DefaultIO.h"

using namespace std;

/**
 * This class is responsible for the standard input and output.
 * It implements the DefaultIO interface.
 * It is uses cin and cout, as the standard input and output.
 */
class StandardIO : public DefaultIO {
public:
    /**
     * Constructor of the class.
     */
    StandardIO() = default;

    /**
     * Read function. Reads from the user to the client side.
     * @return the string that was read.
     */
    std::string read() override;

    /**
     * Write function. Writes to the user from the client side.
     * @param string the text to be written.
     */
    void write(string text) override;

    /**
     * Destructor of the class.
     */
    ~StandardIO() override = default;
};


#endif //ADVANCEDPROGRAMMINGR_O_STANDARDIO_H
