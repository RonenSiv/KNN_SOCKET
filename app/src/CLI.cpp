
#include "app/header/CLI.h"

#include <utility>

CLI::CLI() {
    this->_command = nullptr;
}

void CLI::setCommand(Command *command) {
    delete this->_command;
    this->_command = command;
}

void CLI::setCommandDescription(std::string commandDescription) {
    this->_command->setCommandDescription(std::move(commandDescription));
}

std::string CLI::getCommandDescription() {
    return this->_command->getCommandDescription();
}

void CLI::start() {
    try {
        this->_command->execute();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

std::string CLI::getBuffer() {
    return this->_command->getDio()->getBuffer();
}

std::string CLI::read() {
    return this->getDio()->read();
}

void CLI::write(std::string text) {
    this->getDio()->write(std::move(text));
}

DefaultIO *CLI::getDio() const {
    return this->_dio;
}

void CLI::setDio(DefaultIO *dio) {
    this->_dio = dio;
}

void CLI::emptyBuffer() {
    this->_command->getDio()->emptyBuffer();
}

CLI::CLI(DefaultIO *dio) {
    this->_dio = dio;
}
