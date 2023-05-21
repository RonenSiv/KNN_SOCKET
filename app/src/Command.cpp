
#include "app/header/Command.h"

#include <utility>

void Command::setCommandDescription(std::string commandDescription) {
    this->_commandDescription = std::move(commandDescription);
}

std::string Command::getCommandDescription() {
    return this->_commandDescription;
}

void Command::setDio(DefaultIO *dio) {
    this->_dio = dio;
}

DefaultIO *Command::getDio() {
    return this->_dio;
}
