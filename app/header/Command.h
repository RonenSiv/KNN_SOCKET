#ifndef ADVANCEDPROGRAMMINGR_O_COMMAND_H
#define ADVANCEDPROGRAMMINGR_O_COMMAND_H


#include <string>
#include <vector>
#include <fstream>
#include "app/header/DefaultIO.h"

/**
 * This class is responsible for the commands.
 * It is an abstract class.
 * It has a description of the command, a pointer to the DefaultIO object.
 */
class Command {
protected:
    std::string _commandDescription{};  /// description of the command
    DefaultIO *_dio{};                  /// pointer to the DefaultIO object

public:
    /**
     * calls the execute function of the command. This function is implemented in the derived classes.
     */
    virtual void execute() = 0;

    /**
     * Destructor of the class.
     */
    virtual ~Command() = default;

    /**
     * This function is responsible for setting the description of the command.
     * @param commandDescription the description of the command.
     */
    void setCommandDescription(std::string commandDescription);

    /**
     * This function is responsible for getting the description of the command.
     * @return string the description of the command.
     */
    std::string getCommandDescription();

    /**
     * This function is responsible for setting the pointer to the DefaultIO object.
     * @param dio pointer to the DefaultIO object.
     */
    void setDio(DefaultIO *dio);

    /**
     * This function is responsible for getting the pointer to the DefaultIO object.
     * @return DefaultIO* pointer to the DefaultIO object.
     */
    DefaultIO* getDio();
};


#endif //ADVANCEDPROGRAMMINGR_O_COMMAND_H
