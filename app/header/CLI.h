
#ifndef ADVANCEDPROGRAMMINGR_O_CLI_H
#define ADVANCEDPROGRAMMINGR_O_CLI_H

#include <iostream>
#include "app/header/DefaultIO.h"
#include "app/header/Command.h"

/**
 * This class is responsible for the CLI. It is responsible for the communication between the user and the server.
 * It is also responsible for the communication between the server and the commands.
 * It is also responsible for the communication between the client and the commands.
 */
class CLI {
private:
    Command *_command{};                /// the command to be executed
    DefaultIO *_dio{};                  /// the default IO
    std::string _commandDescription;    /// the description of the command
public:
    /**
     * Constructor of the class - creates a new CLI.
     */
    CLI();

    /**
     * Constructor of the class - creates a new CLI.
     * @param dio the default IO
     */
    explicit CLI(DefaultIO *dio);

    /**
     * Destructor of the class.
     */
    ~CLI() = default;

    /**
     * Gets the default IO.
     * @return the default IO
     */
    DefaultIO *getDio() const;

    /**
     * Sets the default IO.
     * @param dio the default IO
     */
    void setDio(DefaultIO *dio);

    /**
     * Sets the command.
     * @param Command the command
     */
    void setCommand(Command *command);

    /**
     * Sets the command description.
     * @param string the command description
     */
    void setCommandDescription(std::string commandDescription);

    /**
     * Gets the command description.
     * @return string the command description
     */
    std::string getCommandDescription();

    /**
     * This function is responsible for starting the CLI.
     * It calls the command's execute function.
     */
    void start();

    /**
     * This function is responsible for reading the buffer in the default IO.
     * @return string the buffer
     */
    std::string getBuffer();

    /**
     * This function is responsible for calling the write function in the default IO.
     * @return string the text to be written
     */
    std::string read();

    /**
     * This function is responsible for calling the write function in the default IO.
     * @param string the text to be written
     */
    void write(std::string text);

    /**
     * This function is responsible for calling the emptyBuffer function in the default IO.
     */
    void emptyBuffer();
};


#endif //ADVANCEDPROGRAMMINGR_O_CLI_H
